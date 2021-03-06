EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
Title "teensy-fx"
Date "2020-02-10"
Rev "v2"
Comp "mattvenn"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:R_POT RV1
U 1 1 5E177D39
P 1650 4900
F 0 "RV1" H 1581 4946 50  0000 R CNN
F 1 "R_POT" H 1581 4855 50  0000 R CNN
F 2 "audio-fx:Potentiometer_Alps_RK09L_Single_Vertical" H 1650 4900 50  0001 C CNN
F 3 "https://docs.rs-online.com/06f8/0900766b80f4c571.pdf" H 1650 4900 50  0001 C CNN
F 4 "" H 1650 4900 50  0001 C CNN "farnell #"
F 5 "729-3600" H 1650 4900 50  0001 C CNN "rs"
	1    1650 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5E17A27D
P 3450 2300
F 0 "R4" V 3243 2300 50  0000 C CNN
F 1 "10k" V 3334 2300 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3380 2300 50  0001 C CNN
F 3 "~" H 3450 2300 50  0001 C CNN
F 4 "1469856" H 3450 2300 50  0001 C CNN "farnell #"
	1    3450 2300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0121
U 1 1 5E17AA89
P 3300 2300
F 0 "#PWR0121" H 3300 2050 50  0001 C CNN
F 1 "GND" H 3305 2127 50  0000 C CNN
F 2 "" H 3300 2300 50  0001 C CNN
F 3 "" H 3300 2300 50  0001 C CNN
	1    3300 2300
	1    0    0    -1  
$EndComp
Text GLabel 3600 3400 0    50   Input ~ 0
pot_multiplex
Text GLabel 3600 2700 0    50   Input ~ 0
pot_b0
Text GLabel 3600 2800 0    50   Input ~ 0
pot_b1
Text GLabel 3600 2900 0    50   Input ~ 0
pot_b2
Text GLabel 3600 3000 0    50   Input ~ 0
pot_b3
$Comp
L power:GND #PWR0123
U 1 1 5E17B5D6
P 1650 5050
F 0 "#PWR0123" H 1650 4800 50  0001 C CNN
F 1 "GND" H 1655 4877 50  0000 C CNN
F 2 "" H 1650 5050 50  0001 C CNN
F 3 "" H 1650 5050 50  0001 C CNN
	1    1650 5050
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0124
U 1 1 5E17BA88
P 1650 4750
F 0 "#PWR0124" H 1650 4600 50  0001 C CNN
F 1 "+3.3V" H 1665 4923 50  0000 C CNN
F 2 "" H 1650 4750 50  0001 C CNN
F 3 "" H 1650 4750 50  0001 C CNN
	1    1650 4750
	1    0    0    -1  
$EndComp
Text Label 1800 4900 0    50   ~ 0
a0
Text Label 4800 2100 0    50   ~ 0
a0
Text Label 4800 2200 0    50   ~ 0
a1
Text Label 4800 2300 0    50   ~ 0
a2
Text Label 4800 2400 0    50   ~ 0
a3
Text Label 4800 2500 0    50   ~ 0
a4
Text Label 4800 2600 0    50   ~ 0
a5
Text Label 4800 2700 0    50   ~ 0
a6
Text Label 4800 2800 0    50   ~ 0
a7
Text Label 4800 2900 0    50   ~ 0
a8
Text Label 4800 3000 0    50   ~ 0
a9
Text Label 4800 3100 0    50   ~ 0
a10
Text Label 4800 3200 0    50   ~ 0
a11
$Comp
L Device:R_POT RV4
U 1 1 5E17E291
P 2400 4900
F 0 "RV4" H 2331 4946 50  0000 R CNN
F 1 "R_POT" H 2331 4855 50  0000 R CNN
F 2 "audio-fx:Potentiometer_Alps_RK09L_Single_Vertical" H 2400 4900 50  0001 C CNN
F 3 "~" H 2400 4900 50  0001 C CNN
F 4 "729-3600" H 2400 4900 50  0001 C CNN "rs"
	1    2400 4900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0125
U 1 1 5E17E29B
P 2400 5050
F 0 "#PWR0125" H 2400 4800 50  0001 C CNN
F 1 "GND" H 2405 4877 50  0000 C CNN
F 2 "" H 2400 5050 50  0001 C CNN
F 3 "" H 2400 5050 50  0001 C CNN
	1    2400 5050
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0126
U 1 1 5E17E2A5
P 2400 4750
F 0 "#PWR0126" H 2400 4600 50  0001 C CNN
F 1 "+3.3V" H 2415 4923 50  0000 C CNN
F 2 "" H 2400 4750 50  0001 C CNN
F 3 "" H 2400 4750 50  0001 C CNN
	1    2400 4750
	1    0    0    -1  
$EndComp
Text Label 2550 4900 0    50   ~ 0
a1
$Comp
L Device:R_POT RV7
U 1 1 5E18054E
P 3150 4900
F 0 "RV7" H 3081 4946 50  0000 R CNN
F 1 "R_POT" H 3081 4855 50  0000 R CNN
F 2 "audio-fx:Potentiometer_Alps_RK09L_Single_Vertical" H 3150 4900 50  0001 C CNN
F 3 "~" H 3150 4900 50  0001 C CNN
F 4 "729-3600" H 3150 4900 50  0001 C CNN "rs"
	1    3150 4900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0127
U 1 1 5E180558
P 3150 5050
F 0 "#PWR0127" H 3150 4800 50  0001 C CNN
F 1 "GND" H 3155 4877 50  0000 C CNN
F 2 "" H 3150 5050 50  0001 C CNN
F 3 "" H 3150 5050 50  0001 C CNN
	1    3150 5050
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0128
U 1 1 5E180562
P 3150 4750
F 0 "#PWR0128" H 3150 4600 50  0001 C CNN
F 1 "+3.3V" H 3165 4923 50  0000 C CNN
F 2 "" H 3150 4750 50  0001 C CNN
F 3 "" H 3150 4750 50  0001 C CNN
	1    3150 4750
	1    0    0    -1  
$EndComp
Text Label 3300 4900 0    50   ~ 0
a2
$Comp
L Device:R_POT RV10
U 1 1 5E18056D
P 3900 4900
F 0 "RV10" H 3831 4946 50  0000 R CNN
F 1 "R_POT" H 3831 4855 50  0000 R CNN
F 2 "audio-fx:Potentiometer_Alps_RK09L_Single_Vertical" H 3900 4900 50  0001 C CNN
F 3 "~" H 3900 4900 50  0001 C CNN
F 4 "729-3600" H 3900 4900 50  0001 C CNN "rs"
	1    3900 4900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0129
U 1 1 5E180577
P 3900 5050
F 0 "#PWR0129" H 3900 4800 50  0001 C CNN
F 1 "GND" H 3905 4877 50  0000 C CNN
F 2 "" H 3900 5050 50  0001 C CNN
F 3 "" H 3900 5050 50  0001 C CNN
	1    3900 5050
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0130
U 1 1 5E180581
P 3900 4750
F 0 "#PWR0130" H 3900 4600 50  0001 C CNN
F 1 "+3.3V" H 3915 4923 50  0000 C CNN
F 2 "" H 3900 4750 50  0001 C CNN
F 3 "" H 3900 4750 50  0001 C CNN
	1    3900 4750
	1    0    0    -1  
$EndComp
Text Label 4050 4900 0    50   ~ 0
a3
$Comp
L Device:R_POT RV2
U 1 1 5E185256
P 1650 5800
F 0 "RV2" H 1581 5846 50  0000 R CNN
F 1 "R_POT" H 1581 5755 50  0000 R CNN
F 2 "audio-fx:Potentiometer_Alps_RK09L_Single_Vertical" H 1650 5800 50  0001 C CNN
F 3 "~" H 1650 5800 50  0001 C CNN
F 4 "729-3600" H 1650 5800 50  0001 C CNN "rs"
	1    1650 5800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0131
U 1 1 5E185260
P 1650 5950
F 0 "#PWR0131" H 1650 5700 50  0001 C CNN
F 1 "GND" H 1655 5777 50  0000 C CNN
F 2 "" H 1650 5950 50  0001 C CNN
F 3 "" H 1650 5950 50  0001 C CNN
	1    1650 5950
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0132
U 1 1 5E18526A
P 1650 5650
F 0 "#PWR0132" H 1650 5500 50  0001 C CNN
F 1 "+3.3V" H 1665 5823 50  0000 C CNN
F 2 "" H 1650 5650 50  0001 C CNN
F 3 "" H 1650 5650 50  0001 C CNN
	1    1650 5650
	1    0    0    -1  
$EndComp
Text Label 1800 5800 0    50   ~ 0
a4
$Comp
L Device:R_POT RV5
U 1 1 5E185275
P 2400 5800
F 0 "RV5" H 2331 5846 50  0000 R CNN
F 1 "R_POT" H 2331 5755 50  0000 R CNN
F 2 "audio-fx:Potentiometer_Alps_RK09L_Single_Vertical" H 2400 5800 50  0001 C CNN
F 3 "~" H 2400 5800 50  0001 C CNN
F 4 "729-3600" H 2400 5800 50  0001 C CNN "rs"
	1    2400 5800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0133
U 1 1 5E18527F
P 2400 5950
F 0 "#PWR0133" H 2400 5700 50  0001 C CNN
F 1 "GND" H 2405 5777 50  0000 C CNN
F 2 "" H 2400 5950 50  0001 C CNN
F 3 "" H 2400 5950 50  0001 C CNN
	1    2400 5950
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0134
U 1 1 5E185289
P 2400 5650
F 0 "#PWR0134" H 2400 5500 50  0001 C CNN
F 1 "+3.3V" H 2415 5823 50  0000 C CNN
F 2 "" H 2400 5650 50  0001 C CNN
F 3 "" H 2400 5650 50  0001 C CNN
	1    2400 5650
	1    0    0    -1  
$EndComp
Text Label 2550 5800 0    50   ~ 0
a5
$Comp
L Device:R_POT RV8
U 1 1 5E185294
P 3150 5800
F 0 "RV8" H 3081 5846 50  0000 R CNN
F 1 "R_POT" H 3081 5755 50  0000 R CNN
F 2 "audio-fx:Potentiometer_Alps_RK09L_Single_Vertical" H 3150 5800 50  0001 C CNN
F 3 "~" H 3150 5800 50  0001 C CNN
F 4 "729-3600" H 3150 5800 50  0001 C CNN "rs"
	1    3150 5800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0135
U 1 1 5E18529E
P 3150 5950
F 0 "#PWR0135" H 3150 5700 50  0001 C CNN
F 1 "GND" H 3155 5777 50  0000 C CNN
F 2 "" H 3150 5950 50  0001 C CNN
F 3 "" H 3150 5950 50  0001 C CNN
	1    3150 5950
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0136
U 1 1 5E1852A8
P 3150 5650
F 0 "#PWR0136" H 3150 5500 50  0001 C CNN
F 1 "+3.3V" H 3165 5823 50  0000 C CNN
F 2 "" H 3150 5650 50  0001 C CNN
F 3 "" H 3150 5650 50  0001 C CNN
	1    3150 5650
	1    0    0    -1  
$EndComp
Text Label 3300 5800 0    50   ~ 0
a6
$Comp
L Device:R_POT RV11
U 1 1 5E1852B3
P 3900 5800
F 0 "RV11" H 3831 5846 50  0000 R CNN
F 1 "R_POT" H 3831 5755 50  0000 R CNN
F 2 "audio-fx:Potentiometer_Alps_RK09L_Single_Vertical" H 3900 5800 50  0001 C CNN
F 3 "~" H 3900 5800 50  0001 C CNN
F 4 "729-3600" H 3900 5800 50  0001 C CNN "rs"
	1    3900 5800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0137
U 1 1 5E1852BD
P 3900 5950
F 0 "#PWR0137" H 3900 5700 50  0001 C CNN
F 1 "GND" H 3905 5777 50  0000 C CNN
F 2 "" H 3900 5950 50  0001 C CNN
F 3 "" H 3900 5950 50  0001 C CNN
	1    3900 5950
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0138
U 1 1 5E1852C7
P 3900 5650
F 0 "#PWR0138" H 3900 5500 50  0001 C CNN
F 1 "+3.3V" H 3915 5823 50  0000 C CNN
F 2 "" H 3900 5650 50  0001 C CNN
F 3 "" H 3900 5650 50  0001 C CNN
	1    3900 5650
	1    0    0    -1  
$EndComp
Text Label 4050 5800 0    50   ~ 0
a7
$Comp
L Device:R_POT RV3
U 1 1 5E18861A
P 1650 6750
F 0 "RV3" H 1581 6796 50  0000 R CNN
F 1 "R_POT" H 1581 6705 50  0000 R CNN
F 2 "audio-fx:Potentiometer_Alps_RK09L_Single_Vertical" H 1650 6750 50  0001 C CNN
F 3 "~" H 1650 6750 50  0001 C CNN
F 4 "729-3600" H 1650 6750 50  0001 C CNN "rs"
	1    1650 6750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0139
U 1 1 5E188624
P 1650 6900
F 0 "#PWR0139" H 1650 6650 50  0001 C CNN
F 1 "GND" H 1655 6727 50  0000 C CNN
F 2 "" H 1650 6900 50  0001 C CNN
F 3 "" H 1650 6900 50  0001 C CNN
	1    1650 6900
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0140
U 1 1 5E18862E
P 1650 6600
F 0 "#PWR0140" H 1650 6450 50  0001 C CNN
F 1 "+3.3V" H 1665 6773 50  0000 C CNN
F 2 "" H 1650 6600 50  0001 C CNN
F 3 "" H 1650 6600 50  0001 C CNN
	1    1650 6600
	1    0    0    -1  
$EndComp
Text Label 1800 6750 0    50   ~ 0
a8
$Comp
L Device:R_POT RV6
U 1 1 5E188639
P 2400 6750
F 0 "RV6" H 2331 6796 50  0000 R CNN
F 1 "R_POT" H 2331 6705 50  0000 R CNN
F 2 "audio-fx:Potentiometer_Alps_RK09L_Single_Vertical" H 2400 6750 50  0001 C CNN
F 3 "~" H 2400 6750 50  0001 C CNN
F 4 "729-3600" H 2400 6750 50  0001 C CNN "rs"
	1    2400 6750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0141
U 1 1 5E188643
P 2400 6900
F 0 "#PWR0141" H 2400 6650 50  0001 C CNN
F 1 "GND" H 2405 6727 50  0000 C CNN
F 2 "" H 2400 6900 50  0001 C CNN
F 3 "" H 2400 6900 50  0001 C CNN
	1    2400 6900
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0142
U 1 1 5E18864D
P 2400 6600
F 0 "#PWR0142" H 2400 6450 50  0001 C CNN
F 1 "+3.3V" H 2415 6773 50  0000 C CNN
F 2 "" H 2400 6600 50  0001 C CNN
F 3 "" H 2400 6600 50  0001 C CNN
	1    2400 6600
	1    0    0    -1  
$EndComp
Text Label 2550 6750 0    50   ~ 0
a9
$Comp
L Device:R_POT RV9
U 1 1 5E188658
P 3150 6750
F 0 "RV9" H 3081 6796 50  0000 R CNN
F 1 "R_POT" H 3081 6705 50  0000 R CNN
F 2 "audio-fx:Potentiometer_Alps_RK09L_Single_Vertical" H 3150 6750 50  0001 C CNN
F 3 "~" H 3150 6750 50  0001 C CNN
F 4 "729-3600" H 3150 6750 50  0001 C CNN "rs"
	1    3150 6750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0143
U 1 1 5E188662
P 3150 6900
F 0 "#PWR0143" H 3150 6650 50  0001 C CNN
F 1 "GND" H 3155 6727 50  0000 C CNN
F 2 "" H 3150 6900 50  0001 C CNN
F 3 "" H 3150 6900 50  0001 C CNN
	1    3150 6900
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0144
U 1 1 5E18866C
P 3150 6600
F 0 "#PWR0144" H 3150 6450 50  0001 C CNN
F 1 "+3.3V" H 3165 6773 50  0000 C CNN
F 2 "" H 3150 6600 50  0001 C CNN
F 3 "" H 3150 6600 50  0001 C CNN
	1    3150 6600
	1    0    0    -1  
$EndComp
Text Label 3300 6750 0    50   ~ 0
a10
$Comp
L Device:R_POT RV12
U 1 1 5E188677
P 3900 6750
F 0 "RV12" H 3831 6796 50  0000 R CNN
F 1 "R_POT" H 3831 6705 50  0000 R CNN
F 2 "audio-fx:Potentiometer_Alps_RK09L_Single_Vertical" H 3900 6750 50  0001 C CNN
F 3 "~" H 3900 6750 50  0001 C CNN
F 4 "729-3600" H 3900 6750 50  0001 C CNN "rs"
	1    3900 6750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0145
U 1 1 5E188681
P 3900 6900
F 0 "#PWR0145" H 3900 6650 50  0001 C CNN
F 1 "GND" H 3905 6727 50  0000 C CNN
F 2 "" H 3900 6900 50  0001 C CNN
F 3 "" H 3900 6900 50  0001 C CNN
	1    3900 6900
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0146
U 1 1 5E18868B
P 3900 6600
F 0 "#PWR0146" H 3900 6450 50  0001 C CNN
F 1 "+3.3V" H 3915 6773 50  0000 C CNN
F 2 "" H 3900 6600 50  0001 C CNN
F 3 "" H 3900 6600 50  0001 C CNN
	1    3900 6600
	1    0    0    -1  
$EndComp
Text Label 4050 6750 0    50   ~ 0
a11
$Comp
L power:GND #PWR0147
U 1 1 5E1946A6
P 4200 3650
F 0 "#PWR0147" H 4200 3400 50  0001 C CNN
F 1 "GND" H 4205 3477 50  0000 C CNN
F 2 "" H 4200 3650 50  0001 C CNN
F 3 "" H 4200 3650 50  0001 C CNN
	1    4200 3650
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0148
U 1 1 5E194A9C
P 4200 2050
F 0 "#PWR0148" H 4200 1900 50  0001 C CNN
F 1 "+3.3V" H 4200 2250 50  0000 C CNN
F 2 "" H 4200 2050 50  0001 C CNN
F 3 "" H 4200 2050 50  0001 C CNN
	1    4200 2050
	1    0    0    -1  
$EndComp
$Comp
L teensy-fx:4067-teensy_beats-cache U4
U 1 1 5E1AC48F
P 4200 2850
AR Path="/5E1AC48F" Ref="U4"  Part="1" 
AR Path="/5E177B2B/5E1AC48F" Ref="U4"  Part="1" 
F 0 "U4" H 4500 3850 50  0000 C CNN
F 1 "4067" H 4500 3750 50  0000 C CNN
F 2 "Package_SO:SSOP-24_5.3x8.2mm_P0.65mm" H 4200 2850 50  0001 C CNN
F 3 "https://www.ti.com/lit/ds/symlink/cd74hc4067.pdf" H 4200 2850 50  0001 C CNN
F 4 "3124957" H 4200 2850 50  0001 C CNN "farnell #"
	1    4200 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C10
U 1 1 5E1AEABA
P 3600 1700
F 0 "C10" H 3715 1746 50  0000 L CNN
F 1 "2.2uF" H 3715 1655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 3638 1550 50  0001 C CNN
F 3 "~" H 3600 1700 50  0001 C CNN
F 4 "1759424" H 3600 1700 50  0001 C CNN "farnell #"
	1    3600 1700
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0149
U 1 1 5E1AF1C5
P 3600 1550
F 0 "#PWR0149" H 3600 1400 50  0001 C CNN
F 1 "+3.3V" H 3615 1723 50  0000 C CNN
F 2 "" H 3600 1550 50  0001 C CNN
F 3 "" H 3600 1550 50  0001 C CNN
	1    3600 1550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0150
U 1 1 5E1AF422
P 3600 1850
F 0 "#PWR0150" H 3600 1600 50  0001 C CNN
F 1 "GND" H 3605 1677 50  0000 C CNN
F 2 "" H 3600 1850 50  0001 C CNN
F 3 "" H 3600 1850 50  0001 C CNN
	1    3600 1850
	1    0    0    -1  
$EndComp
Text GLabel 6250 3400 0    50   Input ~ 0
led_oe
Text GLabel 6250 3600 0    50   Input ~ 0
SCLK
Text GLabel 6250 3700 0    50   Input ~ 0
MOSI
Text GLabel 6250 3500 0    50   Input ~ 0
led_latch
$Comp
L power:+3.3V #PWR0153
U 1 1 5E1B72C8
P 7150 2100
F 0 "#PWR0153" H 7150 1950 50  0001 C CNN
F 1 "+3.3V" V 7165 2228 50  0000 L CNN
F 2 "" H 7150 2100 50  0001 C CNN
F 3 "" H 7150 2100 50  0001 C CNN
	1    7150 2100
	1    0    0    -1  
$EndComp
$Comp
L teensy-fx:Switch_SW_Push-teensy_beats-cache SW1
U 1 1 5E252246
P 1600 2150
AR Path="/5E252246" Ref="SW1"  Part="1" 
AR Path="/5E177B2B/5E252246" Ref="SW1"  Part="1" 
F 0 "SW1" H 1600 2435 50  0000 C CNN
F 1 "Switch_SW_Push" H 1600 2344 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 1600 2350 50  0001 C CNN
F 3 "" H 1600 2350 50  0001 C CNN
F 4 "1608274" H 1600 2150 50  0001 C CNN "farnell #"
	1    1600 2150
	1    0    0    -1  
$EndComp
$Comp
L teensy-fx:Switch_SW_Push-teensy_beats-cache SW2
U 1 1 5E252D7C
P 1600 2600
AR Path="/5E252D7C" Ref="SW2"  Part="1" 
AR Path="/5E177B2B/5E252D7C" Ref="SW2"  Part="1" 
F 0 "SW2" H 1600 2885 50  0000 C CNN
F 1 "Switch_SW_Push" H 1600 2794 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 1600 2800 50  0001 C CNN
F 3 "" H 1600 2800 50  0001 C CNN
F 4 "1608274" H 1600 2600 50  0001 C CNN "farnell #"
	1    1600 2600
	1    0    0    -1  
$EndComp
$Comp
L teensy-fx:Switch_SW_Push-teensy_beats-cache SW3
U 1 1 5E2538C8
P 1600 3000
AR Path="/5E2538C8" Ref="SW3"  Part="1" 
AR Path="/5E177B2B/5E2538C8" Ref="SW3"  Part="1" 
F 0 "SW3" H 1600 3285 50  0000 C CNN
F 1 "Switch_SW_Push" H 1600 3194 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 1600 3200 50  0001 C CNN
F 3 "" H 1600 3200 50  0001 C CNN
F 4 "1608274" H 1600 3000 50  0001 C CNN "farnell #"
	1    1600 3000
	1    0    0    -1  
$EndComp
$Comp
L teensy-fx:Switch_SW_Push-teensy_beats-cache SW4
U 1 1 5E253CCE
P 1600 3400
AR Path="/5E253CCE" Ref="SW4"  Part="1" 
AR Path="/5E177B2B/5E253CCE" Ref="SW4"  Part="1" 
F 0 "SW4" H 1600 3685 50  0000 C CNN
F 1 "Switch_SW_Push" H 1600 3594 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 1600 3600 50  0001 C CNN
F 3 "" H 1600 3600 50  0001 C CNN
F 4 "1608274" H 1600 3400 50  0001 C CNN "farnell #"
	1    1600 3400
	1    0    0    -1  
$EndComp
Text GLabel 1400 2150 0    50   Input ~ 0
sw_1
Text GLabel 1400 2600 0    50   Input ~ 0
sw_2
Text GLabel 1400 3000 0    50   Input ~ 0
sw_3
Text GLabel 1400 3400 0    50   Input ~ 0
sw_4
$Comp
L power:GND #PWR0169
U 1 1 5E255B34
P 1800 2150
F 0 "#PWR0169" H 1800 1900 50  0001 C CNN
F 1 "GND" H 1805 1977 50  0000 C CNN
F 2 "" H 1800 2150 50  0001 C CNN
F 3 "" H 1800 2150 50  0001 C CNN
	1    1800 2150
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0170
U 1 1 5E256487
P 1800 2600
F 0 "#PWR0170" H 1800 2350 50  0001 C CNN
F 1 "GND" H 1805 2427 50  0000 C CNN
F 2 "" H 1800 2600 50  0001 C CNN
F 3 "" H 1800 2600 50  0001 C CNN
	1    1800 2600
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0171
U 1 1 5E256705
P 1800 3000
F 0 "#PWR0171" H 1800 2750 50  0001 C CNN
F 1 "GND" H 1805 2827 50  0000 C CNN
F 2 "" H 1800 3000 50  0001 C CNN
F 3 "" H 1800 3000 50  0001 C CNN
	1    1800 3000
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0172
U 1 1 5E256B16
P 1800 3400
F 0 "#PWR0172" H 1800 3150 50  0001 C CNN
F 1 "GND" H 1805 3227 50  0000 C CNN
F 2 "" H 1800 3400 50  0001 C CNN
F 3 "" H 1800 3400 50  0001 C CNN
	1    1800 3400
	0    -1   -1   0   
$EndComp
NoConn ~ 4800 3300
NoConn ~ 4800 3400
NoConn ~ 4800 3500
NoConn ~ 4800 3600
$Comp
L Device:LED D7
U 1 1 5E1F1148
P 9400 3000
F 0 "D7" H 9393 2745 50  0000 C CNN
F 1 "LED" H 9393 2836 50  0000 C CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 9400 3000 50  0001 C CNN
F 3 "~" H 9400 3000 50  0001 C CNN
F 4 "2099236" H 9400 3000 50  0001 C CNN "farnell #"
	1    9400 3000
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D6
U 1 1 5E1F1128
P 8800 2900
F 0 "D6" H 8793 2645 50  0000 C CNN
F 1 "LED" H 8793 2736 50  0000 C CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 8800 2900 50  0001 C CNN
F 3 "~" H 8800 2900 50  0001 C CNN
F 4 "2099236" H 8800 2900 50  0001 C CNN "farnell #"
	1    8800 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D5
U 1 1 5E1F110A
P 8250 2800
F 0 "D5" H 8243 2545 50  0000 C CNN
F 1 "LED" H 8243 2636 50  0000 C CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 8250 2800 50  0001 C CNN
F 3 "~" H 8250 2800 50  0001 C CNN
F 4 "2099236" H 8250 2800 50  0001 C CNN "farnell #"
	1    8250 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D4
U 1 1 5E1E6FF0
P 10000 2700
F 0 "D4" H 9993 2445 50  0000 C CNN
F 1 "LED" H 9993 2536 50  0000 C CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 10000 2700 50  0001 C CNN
F 3 "~" H 10000 2700 50  0001 C CNN
F 4 "2099236" H 10000 2700 50  0001 C CNN "farnell #"
	1    10000 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D3
U 1 1 5E1E6FD2
P 9400 2600
F 0 "D3" H 9393 2345 50  0000 C CNN
F 1 "LED" H 9393 2436 50  0000 C CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 9400 2600 50  0001 C CNN
F 3 "~" H 9400 2600 50  0001 C CNN
F 4 "2099236" H 9400 2600 50  0001 C CNN "farnell #"
	1    9400 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D2
U 1 1 5E1BB39E
P 8800 2500
F 0 "D2" H 8793 2245 50  0000 C CNN
F 1 "LED" H 8793 2336 50  0000 C CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 8800 2500 50  0001 C CNN
F 3 "~" H 8800 2500 50  0001 C CNN
F 4 "2099236" H 8800 2500 50  0001 C CNN "farnell #"
	1    8800 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 5E1B9CCC
P 8250 2400
F 0 "D1" H 8243 2145 50  0000 C CNN
F 1 "LED" H 8243 2236 50  0000 C CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 8250 2400 50  0001 C CNN
F 3 "~" H 8250 2400 50  0001 C CNN
F 4 "2099236" H 8250 2400 50  0001 C CNN "farnell #"
	1    8250 2400
	1    0    0    -1  
$EndComp
$Comp
L Driver_LED:TLC5947DAP U5
U 1 1 5E0F221D
P 6950 3600
F 0 "U5" H 6850 5300 50  0000 C CNN
F 1 "TLC5947DAP" H 6850 5200 50  0000 C CNN
F 2 "Package_SO:HTSSOP-32-1EP_6.1x11mm_P0.65mm_EP5.2x11mm_Mask4.11x4.36mm" H 6400 5200 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/tlc5947.pdf" H 6950 3600 50  0001 C CNN
F 4 "1755259" H 6950 3600 50  0001 C CNN "farnell #"
	1    6950 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 2400 8100 2400
Wire Wire Line
	7650 2500 8650 2500
Wire Wire Line
	7650 2600 9250 2600
Wire Wire Line
	7650 2700 9850 2700
Wire Wire Line
	7650 2800 8100 2800
Wire Wire Line
	8650 2900 7650 2900
Wire Wire Line
	7650 3000 9250 3000
Wire Wire Line
	9850 3100 7650 3100
Wire Wire Line
	10150 2400 8400 2400
Connection ~ 10150 2700
Wire Wire Line
	10150 2700 10150 2600
Connection ~ 10150 2500
Wire Wire Line
	10150 2500 10150 2400
Wire Wire Line
	9550 2600 10150 2600
Connection ~ 10150 2600
Wire Wire Line
	10150 2600 10150 2500
Wire Wire Line
	8950 2500 10150 2500
Wire Wire Line
	8400 2800 10150 2800
Connection ~ 10150 2800
Wire Wire Line
	10150 2800 10150 2700
Wire Wire Line
	8950 2900 10150 2900
Connection ~ 10150 2900
Wire Wire Line
	10150 2900 10150 2800
Wire Wire Line
	9550 3000 10150 3000
Connection ~ 10150 3000
Wire Wire Line
	10150 3000 10150 2900
$Comp
L Device:LED D8
U 1 1 5E1F1166
P 10000 3100
F 0 "D8" H 9993 2845 50  0000 C CNN
F 1 "LED" H 9993 2936 50  0000 C CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 10000 3100 50  0001 C CNN
F 3 "~" H 10000 3100 50  0001 C CNN
F 4 "2099236" H 10000 3100 50  0001 C CNN "farnell #"
	1    10000 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D15
U 1 1 5E166977
P 9400 3800
F 0 "D15" H 9393 3545 50  0000 C CNN
F 1 "LED" H 9393 3636 50  0000 C CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 9400 3800 50  0001 C CNN
F 3 "~" H 9400 3800 50  0001 C CNN
F 4 "2099236" H 9400 3800 50  0001 C CNN "farnell #"
	1    9400 3800
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D14
U 1 1 5E166981
P 8800 3700
F 0 "D14" H 8793 3445 50  0000 C CNN
F 1 "LED" H 8793 3536 50  0000 C CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 8800 3700 50  0001 C CNN
F 3 "~" H 8800 3700 50  0001 C CNN
F 4 "2099236" H 8800 3700 50  0001 C CNN "farnell #"
	1    8800 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D13
U 1 1 5E16698B
P 8250 3600
F 0 "D13" H 8243 3345 50  0000 C CNN
F 1 "LED" H 8243 3436 50  0000 C CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 8250 3600 50  0001 C CNN
F 3 "~" H 8250 3600 50  0001 C CNN
F 4 "2099236" H 8250 3600 50  0001 C CNN "farnell #"
	1    8250 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D12
U 1 1 5E166995
P 10000 3500
F 0 "D12" H 9993 3245 50  0000 C CNN
F 1 "LED" H 9993 3336 50  0000 C CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 10000 3500 50  0001 C CNN
F 3 "~" H 10000 3500 50  0001 C CNN
F 4 "2099236" H 10000 3500 50  0001 C CNN "farnell #"
	1    10000 3500
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D11
U 1 1 5E16699F
P 9400 3400
F 0 "D11" H 9393 3145 50  0000 C CNN
F 1 "LED" H 9393 3236 50  0000 C CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 9400 3400 50  0001 C CNN
F 3 "~" H 9400 3400 50  0001 C CNN
F 4 "2099236" H 9400 3400 50  0001 C CNN "farnell #"
	1    9400 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D10
U 1 1 5E1669A9
P 8800 3300
F 0 "D10" H 8793 3045 50  0000 C CNN
F 1 "LED" H 8793 3136 50  0000 C CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 8800 3300 50  0001 C CNN
F 3 "~" H 8800 3300 50  0001 C CNN
F 4 "2099236" H 8800 3300 50  0001 C CNN "farnell #"
	1    8800 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D9
U 1 1 5E1669B3
P 8250 3200
F 0 "D9" H 8243 2945 50  0000 C CNN
F 1 "LED" H 8243 3036 50  0000 C CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 8250 3200 50  0001 C CNN
F 3 "~" H 8250 3200 50  0001 C CNN
F 4 "2099236" H 8250 3200 50  0001 C CNN "farnell #"
	1    8250 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 3200 8100 3200
Wire Wire Line
	7650 3300 8650 3300
Wire Wire Line
	7650 3400 9250 3400
Wire Wire Line
	7650 3500 9850 3500
Wire Wire Line
	7650 3600 8100 3600
Wire Wire Line
	8650 3700 7650 3700
Wire Wire Line
	7650 3800 9250 3800
Wire Wire Line
	9850 3900 7650 3900
Wire Wire Line
	10150 3900 10150 3800
Wire Wire Line
	10150 3200 8400 3200
Connection ~ 10150 3500
Wire Wire Line
	10150 3500 10150 3400
Connection ~ 10150 3300
Wire Wire Line
	10150 3300 10150 3200
Wire Wire Line
	9550 3400 10150 3400
Connection ~ 10150 3400
Wire Wire Line
	10150 3400 10150 3300
Wire Wire Line
	8950 3300 10150 3300
Wire Wire Line
	8400 3600 10150 3600
Connection ~ 10150 3600
Wire Wire Line
	10150 3600 10150 3500
Wire Wire Line
	8950 3700 10150 3700
Connection ~ 10150 3700
Wire Wire Line
	10150 3700 10150 3600
Wire Wire Line
	9550 3800 10150 3800
Connection ~ 10150 3800
Wire Wire Line
	10150 3800 10150 3700
$Comp
L Device:LED D16
U 1 1 5E1669E3
P 10000 3900
F 0 "D16" H 9993 3645 50  0000 C CNN
F 1 "LED" H 9993 3736 50  0000 C CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 10000 3900 50  0001 C CNN
F 3 "~" H 10000 3900 50  0001 C CNN
F 4 "2099236" H 10000 3900 50  0001 C CNN "farnell #"
	1    10000 3900
	1    0    0    -1  
$EndComp
NoConn ~ 7650 4400
NoConn ~ 7650 4500
NoConn ~ 7650 4600
NoConn ~ 7650 4700
$Comp
L power:GND #PWR0154
U 1 1 5E18EF8F
P 6850 5000
F 0 "#PWR0154" H 6850 4750 50  0001 C CNN
F 1 "GND" H 6855 4827 50  0000 C CNN
F 2 "" H 6850 5000 50  0001 C CNN
F 3 "" H 6850 5000 50  0001 C CNN
	1    6850 5000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0155
U 1 1 5E190828
P 7050 5000
F 0 "#PWR0155" H 7050 4750 50  0001 C CNN
F 1 "GND" H 7055 4827 50  0000 C CNN
F 2 "" H 7050 5000 50  0001 C CNN
F 3 "" H 7050 5000 50  0001 C CNN
	1    7050 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5E1937A8
P 6100 3300
F 0 "R5" V 5893 3300 50  0000 C CNN
F 1 "4.7k" V 5984 3300 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 6030 3300 50  0001 C CNN
F 3 "~" H 6100 3300 50  0001 C CNN
F 4 "1469923" H 6100 3300 50  0001 C CNN "farnell #"
	1    6100 3300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0156
U 1 1 5E193E1C
P 5950 3300
F 0 "#PWR0156" H 5950 3050 50  0001 C CNN
F 1 "GND" H 5955 3127 50  0000 C CNN
F 2 "" H 5950 3300 50  0001 C CNN
F 3 "" H 5950 3300 50  0001 C CNN
	1    5950 3300
	0    1    1    0   
$EndComp
$Comp
L Device:C C11
U 1 1 5E19BB80
P 5850 2100
F 0 "C11" H 5965 2146 50  0000 L CNN
F 1 "2.2uF" H 5965 2055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5888 1950 50  0001 C CNN
F 3 "~" H 5850 2100 50  0001 C CNN
F 4 "1759424" H 5850 2100 50  0001 C CNN "farnell #"
	1    5850 2100
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0157
U 1 1 5E19BB8A
P 5850 1950
F 0 "#PWR0157" H 5850 1800 50  0001 C CNN
F 1 "+3.3V" H 5865 2123 50  0000 C CNN
F 2 "" H 5850 1950 50  0001 C CNN
F 3 "" H 5850 1950 50  0001 C CNN
	1    5850 1950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0158
U 1 1 5E19BB94
P 5850 2250
F 0 "#PWR0158" H 5850 2000 50  0001 C CNN
F 1 "GND" H 5855 2077 50  0000 C CNN
F 2 "" H 5850 2250 50  0001 C CNN
F 3 "" H 5850 2250 50  0001 C CNN
	1    5850 2250
	1    0    0    -1  
$EndComp
NoConn ~ 6250 3800
$Comp
L Device:C C12
U 1 1 5E1B9834
P 9450 5100
F 0 "C12" H 9565 5146 50  0000 L CNN
F 1 "2.2uF" H 9565 5055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 9488 4950 50  0001 C CNN
F 3 "~" H 9450 5100 50  0001 C CNN
F 4 "1759424" H 9450 5100 50  0001 C CNN "farnell #"
	1    9450 5100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0161
U 1 1 5E1B9E49
P 9450 5250
F 0 "#PWR0161" H 9450 5000 50  0001 C CNN
F 1 "GND" H 9455 5077 50  0000 C CNN
F 2 "" H 9450 5250 50  0001 C CNN
F 3 "" H 9450 5250 50  0001 C CNN
	1    9450 5250
	1    0    0    -1  
$EndComp
$Comp
L Device:Ferrite_Bead_Small L?
U 1 1 5E1BD3FD
P 9250 4950
AR Path="/5E1BD3FD" Ref="L?"  Part="1" 
AR Path="/5BAC34FB/5E1BD3FD" Ref="L?"  Part="1" 
AR Path="/5E0E3867/5E1BD3FD" Ref="L?"  Part="1" 
AR Path="/5E177B2B/5E1BD3FD" Ref="L2"  Part="1" 
F 0 "L2" V 9487 4950 50  0000 C CNN
F 1 "600R" V 9396 4950 50  0000 C CNN
F 2 "Inductor_SMD:L_0805_2012Metric" V 9180 4950 50  0001 C CNN
F 3 "~" H 9250 4950 50  0001 C CNN
F 4 "2215655" H 9250 4950 50  0001 C CNN "farnell #"
	1    9250 4950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9350 4950 9450 4950
Wire Wire Line
	9050 4950 9150 4950
$Comp
L power:PWR_FLAG #FLG0103
U 1 1 5E1C09DF
P 9450 4950
F 0 "#FLG0103" H 9450 5025 50  0001 C CNN
F 1 "PWR_FLAG" V 9450 5078 50  0000 L CNN
F 2 "" H 9450 4950 50  0001 C CNN
F 3 "~" H 9450 4950 50  0001 C CNN
	1    9450 4950
	0    1    1    0   
$EndComp
Connection ~ 9450 4950
Text Notes 7850 900  0    118  Italic 24
PWM LED driver
Text Notes 1300 900  0    118  Italic 24
Buttons
Text Notes 3650 900  0    118  Italic 24
Pot MUX
Wire Notes Line
	5500 800  5500 7500
Wire Notes Line
	2600 650  2600 3900
Wire Notes Line
	2600 3900 800  3900
$Comp
L Device:LED D19
U 1 1 5E0F956E
P 9400 4200
F 0 "D19" H 9393 3945 50  0000 C CNN
F 1 "LED" H 9393 4036 50  0000 C CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 9400 4200 50  0001 C CNN
F 3 "~" H 9400 4200 50  0001 C CNN
F 4 "2099236" H 9400 4200 50  0001 C CNN "farnell #"
	1    9400 4200
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D18
U 1 1 5E0F9578
P 8800 4100
F 0 "D18" H 8793 3845 50  0000 C CNN
F 1 "LED" H 8793 3936 50  0000 C CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 8800 4100 50  0001 C CNN
F 3 "~" H 8800 4100 50  0001 C CNN
F 4 "2099236" H 8800 4100 50  0001 C CNN "farnell #"
	1    8800 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D17
U 1 1 5E0F9582
P 8250 4000
F 0 "D17" H 8243 3745 50  0000 C CNN
F 1 "LED" H 8243 3836 50  0000 C CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 8250 4000 50  0001 C CNN
F 3 "~" H 8250 4000 50  0001 C CNN
F 4 "2099236" H 8250 4000 50  0001 C CNN "farnell #"
	1    8250 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 4000 8100 4000
Wire Wire Line
	8650 4100 7650 4100
Wire Wire Line
	7650 4200 9250 4200
Wire Wire Line
	9850 4300 7650 4300
Wire Wire Line
	8400 4000 10150 4000
Wire Wire Line
	8950 4100 10150 4100
Wire Wire Line
	9550 4200 10150 4200
$Comp
L Device:LED D20
U 1 1 5E0F959D
P 10000 4300
F 0 "D20" H 9993 4045 50  0000 C CNN
F 1 "LED" H 9993 4136 50  0000 C CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 10000 4300 50  0001 C CNN
F 3 "~" H 10000 4300 50  0001 C CNN
F 4 "2099236" H 10000 4300 50  0001 C CNN "farnell #"
	1    10000 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	10150 4300 10150 4200
Connection ~ 10150 3900
Connection ~ 10150 4000
Wire Wire Line
	10150 4000 10150 3900
Connection ~ 10150 4100
Wire Wire Line
	10150 4100 10150 4000
Connection ~ 10150 4200
Wire Wire Line
	10150 4200 10150 4100
Text Notes 2200 7300 0    50   ~ 0
all pots 10k, taper 1b (linear)\nRK09K1130AP5
Text Notes 2300 7450 0    50   ~ 0
all pots together = 4mA
Text Notes 7850 1350 0    50   ~ 0
R5 is 5k to set LED current to 10mA\nVLED > LED VF + 0.4v
$Comp
L power:+5VA #PWR0151
U 1 1 5E1803EC
P 9450 4950
F 0 "#PWR0151" H 9450 4800 50  0001 C CNN
F 1 "+5VA" H 9465 5123 50  0000 C CNN
F 2 "" H 9450 4950 50  0001 C CNN
F 3 "" H 9450 4950 50  0001 C CNN
	1    9450 4950
	1    0    0    -1  
$EndComp
$Comp
L power:+5VA #PWR0152
U 1 1 5E181433
P 10150 2400
F 0 "#PWR0152" H 10150 2250 50  0001 C CNN
F 1 "+5VA" V 10165 2528 50  0000 L CNN
F 2 "" H 10150 2400 50  0001 C CNN
F 3 "" H 10150 2400 50  0001 C CNN
	1    10150 2400
	0    1    1    0   
$EndComp
Connection ~ 10150 2400
Wire Wire Line
	10150 3000 10150 3100
Connection ~ 10150 3200
Connection ~ 10150 3100
Wire Wire Line
	10150 3100 10150 3200
$Comp
L power:+5V #PWR0159
U 1 1 5E1903A9
P 9050 4950
F 0 "#PWR0159" H 9050 4800 50  0001 C CNN
F 1 "+5V" H 9065 5123 50  0000 C CNN
F 2 "" H 9050 4950 50  0001 C CNN
F 3 "" H 9050 4950 50  0001 C CNN
	1    9050 4950
	1    0    0    -1  
$EndComp
$EndSCHEMATC
