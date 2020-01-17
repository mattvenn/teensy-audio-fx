#!/usr/bin/env python3
from PyQt5 import QtWidgets, uic, QtCore, QtGui
import pickle
from unittest.mock import Mock
import logging, argparse, os, time, sys
import serial, time
import struct
from enum import IntEnum

# make sure these match the enum in src/fx.ino
class Cmd(IntEnum):
    REV_SIZE = 0
    REV_DAMP = 1
    MIX_DEL = 2
    MIX_SIG = 3
    MIX_REV = 4
    DEL_L_TIME = 5
    DEL_R_TIME = 6
    DEL_FB = 7
    DEL_FB_FILT_FREQ = 8
    DEL_FB_FILT_RES = 9
    MIX_REV_IN = 10
    MIX_NOISE = 11
    AUDIO_PROC = 12
    AUDIO_MEM = 13

class MainWindow(QtWidgets.QMainWindow):

    SEQ_STEPS = 32

    def __init__(self):
        super(self.__class__, self).__init__()
        if args.mock_serial:
            self.ser = Mock()
            self.ser.readline = Mock(return_value="mock".encode('utf-8'))
            self.ser.write = Mock(return_value=0)
        else:
            self.ser = serial.Serial(args.serial_port, 9600, timeout = 2, write_timeout = 2)
        self.record = False
        self.play = True
    
        # configuration for all the sliders
        self.widget_config = [
            { 'tip': 'del time l',   'cmd': Cmd.DEL_L_TIME,   'min': 0, 'max':2000 },
            { 'tip': 'del time r',   'cmd': Cmd.DEL_R_TIME,   'min': 0, 'max':2000 },
            { 'tip': 'del mix',      'cmd': Cmd.MIX_DEL,      'min': 0, 'max':255},
            { 'tip': 'sig mix',      'cmd': Cmd.MIX_SIG,      'min': 0, 'max':255},
            { 'tip': 'rev mix',      'cmd': Cmd.MIX_REV_IN,   'min': 0, 'max':255},
            { 'tip': 'noiz mix',     'cmd': Cmd.MIX_NOISE,    'min': 0, 'max':255 },
            { 'tip': 'rev size',     'cmd': Cmd.REV_SIZE,     'min': 0, 'max':255},
            { 'tip': 'rev damp',     'cmd': Cmd.REV_DAMP,     'min': 0, 'max':255},
            { 'tip': 'fil freq',     'cmd': Cmd.DEL_FB_FILT_FREQ,      'min': 0, 'max':255},
            { 'tip': 'fil q',        'cmd': Cmd.DEL_FB_FILT_RES,      'min': 0, 'max':255},
            { 'tip': 'del fb',       'cmd': Cmd.DEL_FB,       'min': 0, 'max':255 },
            ]

        # setup UI
        uic.loadUi('fx-control/mainwindow.ui', self)
        self.button_reset.pressed.connect(lambda: self.reset_seq())
        self.progressBar_beats.setMaximum(MainWindow.SEQ_STEPS)
        self.button_seq_reset.pressed.connect(lambda: self.reset_beat())
        self.lineEdit_bpm.textChanged.connect(lambda: self.update_bpm())
        self.timer = QtCore.QTimer(self)
        self.timer.timeout.connect(self.update_beat)
        self.timer.start(self.get_ms_from_bpm())
        self.beat = 0

        self.setWindowTitle("Teensy FX controller")
        self.widgets = []

        try:
            with open("settings.pkl", 'rb') as fh:
                last_values = pickle.load(fh)
        except FileNotFoundError:
            last_values = None

        # create all the widgets
        for index, w in enumerate(self.widget_config):
            w['pressed'] = False
            w['widget'] = QtWidgets.QSlider()
            w['disp'] = QtWidgets.QProgressBar()
            w['disp'].setOrientation(QtCore.Qt.Vertical)
            w['mem_a'] = 0
            w['mem_b'] = 0
            w['widget'].setMinimum(w['min'])
            w['widget'].setMaximum(w['max'])
            w['disp'].setMinimum(w['min'])
            w['disp'].setMaximum(w['max'])
            w['widget'].setToolTip(w['tip'])
            logging.info("creating widget: [%-12s] cmd [%-22s] min/max [%4d/%4d]" % (w['tip'], w['cmd'], w['min'], w['max']))
            w['disp'].valueChanged.connect(lambda state, w=w: self.map_cmd(w))
            w['widget'].sliderMoved.connect(lambda state, w=w: self.slider_moved(w))
            w['widget'].sliderPressed.connect(lambda w=w: self.pressed(w))
            w['widget'].sliderReleased.connect(lambda w=w: self.released(w))
            label = QtWidgets.QLabel()
            label.setText(w['tip'])
            self.layout.addWidget(label)
            self.layout.addWidget(w['widget'])
            self.layout.addWidget(w['disp'])

            if last_values is not None:
                w['widget'].setValue(last_values[index]['value'])
                w['seq'] = last_values[index]['seq']
            else:
                w['seq'] = [w['widget'].value()] * MainWindow.SEQ_STEPS

    def map_cmd(self, widget):
        logging.debug("%s %d" % (widget['cmd'], widget['disp'].value()))
        # map the number
        mult = 255 / widget['max'] 
        self.send_cmd(widget['cmd'], widget['disp'].value() * mult)

    def send_cmd(self, cmd, val, verbose=False):
        fmt = "BB"
        self.ser.write(struct.pack(fmt, cmd, int(val)))
        result = self.ser.readline().decode("utf-8").strip()
        log_msg = "tx [%s %d] rx [%s]" % (cmd, val, result)
        if verbose:
            logging.info(log_msg)
        else:
            logging.debug(log_msg)
        self.statusBar.showMessage(log_msg)

    def pressed(self, widget):
        logging.debug("pressed %s %d" % (widget['cmd'], widget['widget'].value()))
        widget['pressed'] = True

    def released(self, widget):
        logging.debug("released %s %d" % (widget['cmd'], widget['widget'].value()))
        widget['pressed'] = False

    def slider_moved(self, widget):
        if not self.record:
            logging.debug("setting %s for all = %d" % (widget['tip'], widget['widget'].value()))
            widget['seq'] = [ widget['widget'].value() ] * MainWindow.SEQ_STEPS
        widget['disp'].setValue(widget['widget'].value())

    def get_ms_from_bpm(self):
        bpm = int(self.lineEdit_bpm.text())
        ms = (60000*16/MainWindow.SEQ_STEPS)/bpm
        logging.info("%d bpm is %d ms with %d steps" % (bpm, ms, MainWindow.SEQ_STEPS))
        return ms

    def update_bpm(self):
        self.timer.start(self.get_ms_from_bpm())

    def update_beat(self):
        self.progressBar_beats.setValue(self.beat)
        self.beat += 1
        if self.beat == MainWindow.SEQ_STEPS:
            self.beat = 0
            if args.perf_stats:
                self.send_cmd(Cmd.AUDIO_PROC,0, verbose=True)
        if self.beat == MainWindow.SEQ_STEPS / 2:
            if args.perf_stats:
                self.send_cmd(Cmd.AUDIO_MEM,0, verbose=True)
        if self.record:
            for w in self.widget_config:
                if w['pressed']:
                    logging.debug("setting %s for beat %d = %d" % (w['tip'], self.beat, w['widget'].value()))
                    w['seq'][self.beat] = w['widget'].value()

        if self.play:
            for w in self.widget_config:
                if not w['pressed']:
                    w['disp'].setValue(w['seq'][self.beat])

    def reset_seq(self):
        for w in self.widget_config:
            w['seq'] = [w['widget'].value()] * MainWindow.SEQ_STEPS

    def reset_beat(self):
        self.beat = 0
        self.progressBar_beats.setValue(self.beat)
        self.timer.start(self.get_ms_from_bpm())

    def keyPressEvent(self, e):
        if e.key() == QtCore.Qt.Key_R and not e.isAutoRepeat():
            self.record = True 
            self.button_rec.setChecked(True)
            logging.info('recording')

    def keyReleaseEvent(self, e):
        if e.key() == QtCore.Qt.Key_R and not e.isAutoRepeat():
            self.record = False 
            self.button_rec.setChecked(False)
            logging.info('stop recording')

    def closeEvent(self, event):
        logging.info("save settings")
        last_settings = []
        for w in self.widget_config:
            last_settings.append({'value': w['widget'].value(), 'seq': w['seq']})

        with open("settings.pkl", 'wb') as fh:
            pickle.dump(last_settings, fh)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="control fx")
    parser.add_argument('--perf-stats', help="log performance stats", action="store_const", const=True)
    parser.add_argument('--debug', help="debug logging", action="store_const", const=True)
    parser.add_argument('--mock-serial', help="show gui even if don't have teensy connected", action="store_const", const=True)
    parser.add_argument('--serial-port', help="what port", action="store", default='/dev/ttyACM0')
    args = parser.parse_args()

    # setup log
    log_format = logging.Formatter('%(asctime)s - %(module)-15s - %(levelname)-8s - %(message)s')
    # configure the client logging
    log = logging.getLogger('')
    # has to be set to debug as is the root logger
    if args.debug:
        log.setLevel(logging.DEBUG)
    else:
        log.setLevel(logging.INFO)

    # create console handler and set level to info
    ch = logging.StreamHandler()
    # create formatter for console
    ch.setFormatter(log_format)
    log.addHandler(ch)

    app = QtWidgets.QApplication(sys.argv)
    main = MainWindow()
    main.show()
    sys.exit(app.exec_())
