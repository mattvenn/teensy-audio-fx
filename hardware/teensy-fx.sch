EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 6950 2350 2100 1450
U 5E0E3867
F0 "SGTL" 50
F1 "SGTL5000.sch" 50
$EndSheet
Text GLabel 2850 3550 0    50   Input ~ 0
SDA
Text GLabel 2850 3200 0    50   Input ~ 0
SCL
Text GLabel 3650 2450 0    50   Input ~ 0
MCLK
Text GLabel 3650 2550 0    50   Input ~ 0
BCLK
Text GLabel 3650 2650 0    50   Input ~ 0
LRCLK
Text GLabel 3650 2750 0    50   Input ~ 0
TX
Text GLabel 3650 2850 0    50   Input ~ 0
RX
$Comp
L teensy:Teensy4.0 U1
U 1 1 5E117CA6
P 5150 3550
F 0 "U1" H 5150 5165 50  0000 C CNN
F 1 "Teensy4.0" H 5150 5074 50  0000 C CNN
F 2 "teensy:Teensy40" H 4750 3750 50  0001 C CNN
F 3 "" H 4750 3750 50  0001 C CNN
	1    5150 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5E11F642
P 4050 2200
AR Path="/5E11F642" Ref="#PWR0101"  Part="1" 
AR Path="/5BAC34FB/5E11F642" Ref="#PWR?"  Part="1" 
AR Path="/5E0E3867/5E11F642" Ref="#PWR?"  Part="1" 
F 0 "#PWR0101" H 4050 1950 50  0001 C CNN
F 1 "GND" H 4055 2027 50  0000 C CNN
F 2 "" H 4050 2200 50  0001 C CNN
F 3 "" H 4050 2200 50  0001 C CNN
	1    4050 2200
	0    1    1    0   
$EndComp
Wire Wire Line
	1850 2600 1850 2550
$Comp
L power:+3V3 #PWR0102
U 1 1 5E11F64F
P 2650 1950
AR Path="/5E11F64F" Ref="#PWR0102"  Part="1" 
AR Path="/5BAC34FB/5E11F64F" Ref="#PWR?"  Part="1" 
AR Path="/5E0E3867/5E11F64F" Ref="#PWR?"  Part="1" 
F 0 "#PWR0102" H 2650 1800 50  0001 C CNN
F 1 "+3V3" H 2665 2123 50  0000 C CNN
F 2 "" H 2650 1950 50  0001 C CNN
F 3 "" H 2650 1950 50  0001 C CNN
	1    2650 1950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5E123E38
P 4050 3800
AR Path="/5E123E38" Ref="#PWR0103"  Part="1" 
AR Path="/5BAC34FB/5E123E38" Ref="#PWR?"  Part="1" 
AR Path="/5E0E3867/5E123E38" Ref="#PWR?"  Part="1" 
F 0 "#PWR0103" H 4050 3550 50  0001 C CNN
F 1 "GND" H 4055 3627 50  0000 C CNN
F 2 "" H 4050 3800 50  0001 C CNN
F 3 "" H 4050 3800 50  0001 C CNN
	1    4050 3800
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5E1242A7
P 6250 2900
AR Path="/5E1242A7" Ref="#PWR0104"  Part="1" 
AR Path="/5BAC34FB/5E1242A7" Ref="#PWR?"  Part="1" 
AR Path="/5E0E3867/5E1242A7" Ref="#PWR?"  Part="1" 
F 0 "#PWR0104" H 6250 2650 50  0001 C CNN
F 1 "GND" H 6255 2727 50  0000 C CNN
F 2 "" H 6250 2900 50  0001 C CNN
F 3 "" H 6250 2900 50  0001 C CNN
	1    6250 2900
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
