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

import serial, time
ser = serial.Serial("/dev/ttyACM0", 9600, timeout = 2, write_timeout = 2)
import struct
fmt = "BB"

def send_cmd(cmd, val):
    ser.write(struct.pack(fmt, cmd, val))
    print(ser.readline())

bpms = (60 / 120) * 1000
delay_l = bpms * 0.15
delay_r = bpms * 0.16

send_cmd(Cmd.MIX_SIG, 200)
send_cmd(Cmd.MIX_DEL, 100)
send_cmd(Cmd.MIX_REV, 250)
send_cmd(Cmd.MIX_REV_IN, 30)
send_cmd(Cmd.REV_DAMP, 100)
send_cmd(Cmd.REV_SIZE, 200)
send_cmd(Cmd.DEL_L_TIME, int(delay_l/4))
send_cmd(Cmd.DEL_R_TIME, int(delay_r/4))
send_cmd(Cmd.DEL_FB, 140)
send_cmd(Cmd.DEL_FB_FILT_FREQ, 140)
send_cmd(Cmd.DEL_FB_FILT_RES, 100)
