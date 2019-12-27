#!/usr/bin/env python3
from PyQt5 import QtWidgets, uic, QtCore, QtGui
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

class MainWindow(QtWidgets.QMainWindow):

    def send_cmd(self, cmd, val):
        fmt = "BB"
        logging.info("sending %s %d" % (cmd, val))

        self.ser.write(struct.pack(fmt, cmd, int(val)))
        logging.info(self.ser.readline())

    def map_cmd(self, widget):
        logging.info("%s %d" % (widget['cmd'], widget['widget'].value()))
        # map the number
        mult = 255 / widget['max'] 
        self.send_cmd(widget['cmd'], widget['widget'].value() * mult)

    def __init__(self):
        super(self.__class__, self).__init__()
        self.ser = serial.Serial("/dev/ttyACM0", 9600, timeout = 2, write_timeout = 2)

        self.knob_config = [
            { 'tip': 'delay time l',   'cmd': Cmd.DEL_L_TIME,   'min': 0, 'max':2000, 'widget': None },
            { 'tip': 'delay time r',   'cmd': Cmd.DEL_R_TIME,   'min': 0, 'max':2000, 'widget': None },
            { 'tip': 'delay mix',      'cmd': Cmd.MIX_DEL,      'min': 0, 'max':255,  'widget': None },
            { 'tip': 'reverb mix',     'cmd': Cmd.MIX_REV,      'min': 0, 'max':255,  'widget': None },
            { 'tip': 'filt freq',      'cmd': Cmd.DEL_FB_FILT_FREQ,      'min': 0, 'max':255,  'widget': None },
            { 'tip': 'filt q',         'cmd': Cmd.DEL_FB_FILT_RES,      'min': 0, 'max':255,  'widget': None },
            { 'tip': 'delay feedback', 'cmd': Cmd.DEL_FB,       'min': 0, 'max':255,  'widget': None },
            ]

        uic.loadUi('fx-control/mainwindow.ui', self)
        #self.dial_time_r.valueChanged.connect(lambda: self.send_cmd(Cmd.DEL_L_TIME, self.dial_time_r.value()))
        self.widgets = []

        for w in self.knob_config:
            w['widget'] = QtWidgets.QDial()
            w['widget'].setMinimum(w['min'])
            w['widget'].setMaximum(w['max'])
            w['widget'].setToolTip(w['tip'])
            logging.info("%s %s %d %d %s" % (w['tip'], w['cmd'], w['min'], w['max'], w['widget']))
            w['widget'].valueChanged.connect(lambda state, cmd=w['cmd'], w=w: self.map_cmd(w))
            self.gridLayout.addWidget(w['widget'])

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

        self.statusBar.showMessage("ready")

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
