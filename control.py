#!/usr/bin/env python3
from PyQt5 import QtWidgets, uic, QtCore, QtGui

import pickle
import logging, argparse, os, time, sys
import serial, time
import struct
from enum import IntEnum

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


    def map_cmd(self, widget):
        logging.debug("%s %d" % (widget['cmd'], widget['disp'].value()))
        # map the number
        mult = 255 / widget['max'] 
        self.send_cmd(widget['cmd'], widget['disp'].value() * mult)

    def get_ms_from_bpm(self):
        bpm = int(self.lineEdit_bpm.text())
        return (60000*16/MainWindow.SEQ_STEPS)/bpm

    def update_bpm(self):
        self.timer.start(self.get_ms_from_bpm())

    def update_beat(self):
        self.progressBar_beats.setValue(self.beat)
        self.beat += 1
        if self.beat == MainWindow.SEQ_STEPS:
            self.beat = 0
            self.send_cmd(Cmd.AUDIO_PROC,0, verbose=True)
        if self.beat == MainWindow.SEQ_STEPS / 2:
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

    SEQ_STEPS = 160

    def __init__(self):
        super(self.__class__, self).__init__()
        self.ser = serial.Serial("/dev/ttyACM0", 9600, timeout = 2, write_timeout = 2)
        self.record = False
        self.play = True
    
#        try:
#            with open("settings.pkl") as fh:
#                self.widget_config = pickle.load(fh)
#        except FileNotFoundError:
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

        uic.loadUi('fx-control/mainwindow.ui', self)
        #self.dial_time_r.valueChanged.connect(lambda: self.send_cmd(Cmd.DEL_L_TIME, self.dial_time_r.value()))
        self.button_mema.pressed.connect(lambda: self.store_mem('mem_a'))
        self.button_mema.hide()
        self.button_memb.hide()
        self.button_reset.pressed.connect(lambda: self.reset_seq())
        self.progressBar_beats.setMaximum(MainWindow.SEQ_STEPS)
        self.button_memb.pressed.connect(lambda: self.store_mem('mem_b'))
        self.button_seq_reset.pressed.connect(lambda: self.reset_beat())
        self.slider_ab.valueChanged.connect(lambda: self.cross_fade_mem())
        self.slider_ab.hide()
        self.lineEdit_bpm.textChanged.connect(lambda: self.update_bpm())
        self.timer = QtCore.QTimer(self)
        self.timer.timeout.connect(self.update_beat)
        self.timer.start(self.get_ms_from_bpm())
        self.beat = 0

        self.setWindowTitle("Teensy FX controller")
        self.widgets = []

        for w in self.widget_config:
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

        self.reset_seq()

        """
        bpms = (60 / 120) * 1000
        delay_l = bpms * 0.15
        delay_r = bpms * 0.16

        self.send_cmd(Cmd.MIX_SIG, 200)
        self.send_cmd(Cmd.MIX_DEL, 100)
        self.send_cmd(Cmd.MIX_REV, 250)
        self.send_cmd(Cmd.MIX_REV_IN, 30)
        self.send_cmd(Cmd.REV_DAMP, 100)
        self.send_cmd(Cmd.REV_SIZE, 200)
        self.send_cmd(Cmd.DEL_L_TIME, int(delay_l/4))
        self.send_cmd(Cmd.DEL_R_TIME, int(delay_r/4))
        self.send_cmd(Cmd.DEL_FB, 140)
        self.send_cmd(Cmd.DEL_FB_FILT_FREQ, 140)
        self.send_cmd(Cmd.DEL_FB_FILT_RES, 100)
        """

    def store_mem(self, mem):
        for w in self.widget_config:
            w[mem] = w['widget'].value()

    def closeEvent(self, event):
        logging.info("save settings")
        with open("settings.pkl", 'w') as fh:
            pickle.dump(self.widget_config, fh)
    """
    slider for fx
    0  25  50  75 100
       a
                b

    ab slider
    0  25  50  75 100
    25             75 

    """
    def cross_fade_mem(self):
        logging.info("cross fade %d" % self.slider_ab.value())
        for w in self.widget_config:
            val_per_step = (w['mem_a'] - w['mem_b']) / 100 # will be positive if mem_a > mem_b
            if val_per_step > 0:
                new_val = w['mem_a'] - val_per_step * (self.slider_ab.value())
            else:
                new_val = w['mem_b'] + val_per_step * (100-self.slider_ab.value())
            logging.debug("%s %d %d" % (w['tip'], val_per_step, new_val))
            w['widget'].setValue(new_val)


if __name__ == '__main__':
    """
    parser = argparse.ArgumentParser(description="View Events")
    parser.add_argument('--listing', help="load a listing", action='store')
    parser.add_argument('--channels', help="comma separated list of 4 channels: R1,R2,L1,L2", action='store')
    parser.add_argument('--widths', help="comma separated list left and right width: RW,LW", action='store')
    parser.add_argument('--calibrate', help="run calibrate at start", action="store_const", const=True)
    parser.add_argument('--locate', help="run locate at start", action="store_const", const=True)
    parser.add_argument('--tab', help="switch to this tab after startup", action="store")
    args = parser.parse_args()
    """

    # setup log
    log_format = logging.Formatter('%(asctime)s - %(module)-15s - %(levelname)-8s - %(message)s')
    # configure the client logging
    log = logging.getLogger('')
    # has to be set to debug as is the root logger
    log.setLevel(logging.DEBUG)

    # create console handler and set level to info
    ch = logging.StreamHandler()
    # create formatter for console
    ch.setFormatter(log_format)
    log.addHandler(ch)

    app = QtWidgets.QApplication(sys.argv)
    main = MainWindow()
    main.show()
    sys.exit(app.exec_())
