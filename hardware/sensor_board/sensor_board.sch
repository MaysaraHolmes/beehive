EESchema Schematic File Version 4
LIBS:sensor_board-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Beehive Sensor board"
Date "2019-03-20"
Rev "v3.2"
Comp "University of Glasgow"
Comment1 "ENG5220-RTEP"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L honeywell:HIHxx3x-021 U1
U 1 1 5C472AC6
P 4250 3700
F 0 "U1" H 4250 4065 50  0000 C CNN
F 1 "HIHxx3x-021" H 4250 3974 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 4300 4100 50  0001 C CNN
F 3 "https://sensing.honeywell.com/honeywell-sensing-humidicon-hih6100-series-product-sheet-009059-6-en.pdf" H 4550 4450 50  0001 C CNN
	1    4250 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR022
U 1 1 5C472C56
P 8450 5700
F 0 "#PWR022" H 8450 5450 50  0001 C CNN
F 1 "GND" H 8455 5527 50  0000 C CNN
F 2 "" H 8450 5700 50  0001 C CNN
F 3 "" H 8450 5700 50  0001 C CNN
	1    8450 5700
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR04
U 1 1 5C472C83
P 3850 3800
F 0 "#PWR04" H 3850 3550 50  0001 C CNN
F 1 "GND" V 3855 3672 50  0000 R CNN
F 2 "" H 3850 3800 50  0001 C CNN
F 3 "" H 3850 3800 50  0001 C CNN
	1    3850 3800
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR03
U 1 1 5C472D00
P 3850 3600
F 0 "#PWR03" H 3850 3450 50  0001 C CNN
F 1 "+3.3V" V 3865 3728 50  0000 L CNN
F 2 "" H 3850 3600 50  0001 C CNN
F 3 "" H 3850 3600 50  0001 C CNN
	1    3850 3600
	0    -1   -1   0   
$EndComp
Text Label 8150 5600 0    50   ~ 0
SDA_ext
Text Label 8150 5500 0    50   ~ 0
SCL_ext
Text Label 4650 3600 0    50   ~ 0
SCL
Wire Wire Line
	4850 3600 4650 3600
Text Label 4650 3700 0    50   ~ 0
SDA
Wire Wire Line
	4850 3700 4650 3700
$Comp
L Device:C C2
U 1 1 5C473BF9
P 4450 2900
F 0 "C2" H 4565 2946 50  0000 L CNN
F 1 "0.22µ" H 4565 2855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4488 2750 50  0001 C CNN
F 3 "~" H 4450 2900 50  0001 C CNN
	1    4450 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5C473C59
P 4050 2900
F 0 "C1" H 4165 2946 50  0000 L CNN
F 1 "0.1µ" H 4165 2855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4088 2750 50  0001 C CNN
F 3 "~" H 4050 2900 50  0001 C CNN
	1    4050 2900
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR07
U 1 1 5C473DB5
P 4450 2750
F 0 "#PWR07" H 4450 2600 50  0001 C CNN
F 1 "+3.3V" H 4350 2900 50  0000 L CNN
F 2 "" H 4450 2750 50  0001 C CNN
F 3 "" H 4450 2750 50  0001 C CNN
	1    4450 2750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR08
U 1 1 5C474071
P 4450 3050
F 0 "#PWR08" H 4450 2800 50  0001 C CNN
F 1 "GND" V 4455 2922 50  0000 R CNN
F 2 "" H 4450 3050 50  0001 C CNN
F 3 "" H 4450 3050 50  0001 C CNN
	1    4450 3050
	1    0    0    -1  
$EndComp
Text Label 3600 3700 0    50   ~ 0
Vcore
Text Label 3800 2750 0    50   ~ 0
Vcore
Wire Wire Line
	3850 3700 3600 3700
Wire Wire Line
	4050 2750 3800 2750
$Comp
L power:GND #PWR05
U 1 1 5C474CCF
P 4050 3050
F 0 "#PWR05" H 4050 2800 50  0001 C CNN
F 1 "GND" V 4055 2922 50  0000 R CNN
F 2 "" H 4050 3050 50  0001 C CNN
F 3 "" H 4050 3050 50  0001 C CNN
	1    4050 3050
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR021
U 1 1 5C4785CE
P 8450 5400
F 0 "#PWR021" H 8450 5250 50  0001 C CNN
F 1 "+3.3V" H 8350 5550 50  0000 L CNN
F 2 "" H 8450 5400 50  0001 C CNN
F 3 "" H 8450 5400 50  0001 C CNN
	1    8450 5400
	1    0    0    -1  
$EndComp
$Comp
L Sensor_Pressure:MPL115A2 U3
U 1 1 5C48755E
P 6450 3400
F 0 "U3" H 6991 3446 50  0000 L CNN
F 1 "MPL115A2" H 6991 3355 50  0000 L CNN
F 2 "Package_LGA:LGA-8_3x5mm_P1.25mm" H 6600 2700 50  0001 C CNN
F 3 "http://www.nxp.com/assets/documents/data/en/data-sheets/MPL115A1.pdf" H 6450 3400 50  0001 C CNN
	1    6450 3400
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR014
U 1 1 5C487869
P 6450 2800
F 0 "#PWR014" H 6450 2650 50  0001 C CNN
F 1 "+3.3V" H 6350 2950 50  0000 L CNN
F 2 "" H 6450 2800 50  0001 C CNN
F 3 "" H 6450 2800 50  0001 C CNN
	1    6450 2800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR015
U 1 1 5C4878C6
P 6450 4000
F 0 "#PWR015" H 6450 3750 50  0001 C CNN
F 1 "GND" H 6500 3850 50  0000 R CNN
F 2 "" H 6450 4000 50  0001 C CNN
F 3 "" H 6450 4000 50  0001 C CNN
	1    6450 4000
	1    0    0    -1  
$EndComp
Text Label 5750 3200 0    50   ~ 0
SCL
Wire Wire Line
	5950 3200 5750 3200
Text Label 5750 3300 0    50   ~ 0
SDA
Wire Wire Line
	5950 3300 5750 3300
$Comp
L Device:C C3
U 1 1 5C487C0F
P 6950 3550
F 0 "C3" H 7065 3596 50  0000 L CNN
F 1 "1µ" H 7065 3505 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 6988 3400 50  0001 C CNN
F 3 "~" H 6950 3550 50  0001 C CNN
	1    6950 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 5C487C4B
P 7550 3550
F 0 "C4" H 7665 3596 50  0000 L CNN
F 1 "1µ" H 7665 3505 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 7588 3400 50  0001 C CNN
F 3 "~" H 7550 3550 50  0001 C CNN
	1    7550 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR016
U 1 1 5C487E59
P 6950 3700
F 0 "#PWR016" H 6950 3450 50  0001 C CNN
F 1 "GND" H 7000 3550 50  0000 R CNN
F 2 "" H 6950 3700 50  0001 C CNN
F 3 "" H 6950 3700 50  0001 C CNN
	1    6950 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR018
U 1 1 5C487ED5
P 7550 3700
F 0 "#PWR018" H 7550 3450 50  0001 C CNN
F 1 "GND" H 7650 3550 50  0000 R CNN
F 2 "" H 7550 3700 50  0001 C CNN
F 3 "" H 7550 3700 50  0001 C CNN
	1    7550 3700
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR017
U 1 1 5C487F9C
P 7550 3400
F 0 "#PWR017" H 7550 3250 50  0001 C CNN
F 1 "+3.3V" H 7450 3550 50  0000 L CNN
F 2 "" H 7550 3400 50  0001 C CNN
F 3 "" H 7550 3400 50  0001 C CNN
	1    7550 3400
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR013
U 1 1 5C488294
P 5650 3600
F 0 "#PWR013" H 5650 3450 50  0001 C CNN
F 1 "+3.3V" V 5650 3700 50  0000 L CNN
F 2 "" H 5650 3600 50  0001 C CNN
F 3 "" H 5650 3600 50  0001 C CNN
	1    5650 3600
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3V #PWR012
U 1 1 5C4884EB
P 5650 3500
F 0 "#PWR012" H 5650 3350 50  0001 C CNN
F 1 "+3.3V" V 5650 3600 50  0000 L CNN
F 2 "" H 5650 3500 50  0001 C CNN
F 3 "" H 5650 3500 50  0001 C CNN
	1    5650 3500
	0    -1   -1   0   
$EndComp
$Comp
L Interface_Expansion:P82B96 U2
U 1 1 5C4C662B
P 6200 5450
F 0 "U2" H 6200 6067 50  0000 C CNN
F 1 "P82B96" H 6200 5976 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 6200 5450 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/P82B96.pdf" H 6200 5450 50  0001 C CNN
	1    6200 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 5500 8150 5500
Wire Wire Line
	8450 5600 8150 5600
Text Label 6800 5550 0    50   ~ 0
SDA_ext
Text Label 6800 5150 0    50   ~ 0
SCL_ext
Wire Wire Line
	7100 5150 6800 5150
Wire Wire Line
	7100 5550 6800 5550
Wire Wire Line
	6800 5150 6800 5350
Connection ~ 6800 5150
Wire Wire Line
	6800 5550 6800 5750
Connection ~ 6800 5550
$Comp
L power:GND #PWR011
U 1 1 5C4C70EE
P 5600 5750
F 0 "#PWR011" H 5600 5500 50  0001 C CNN
F 1 "GND" V 5605 5577 50  0000 C CNN
F 2 "" H 5600 5750 50  0001 C CNN
F 3 "" H 5600 5750 50  0001 C CNN
	1    5600 5750
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR010
U 1 1 5C4C71BF
P 5600 5150
F 0 "#PWR010" H 5600 5000 50  0001 C CNN
F 1 "+3.3V" V 5600 5250 50  0000 L CNN
F 2 "" H 5600 5150 50  0001 C CNN
F 3 "" H 5600 5150 50  0001 C CNN
	1    5600 5150
	0    -1   -1   0   
$EndComp
Text Label 5400 5550 0    50   ~ 0
SCL
Wire Wire Line
	5600 5550 5400 5550
Text Label 5400 5350 0    50   ~ 0
SDA
Wire Wire Line
	5600 5350 5400 5350
$Comp
L Device:R R1
U 1 1 5C4C91BE
P 3550 5250
F 0 "R1" H 3500 5300 50  0000 L CNN
F 1 "R" H 3500 5200 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3480 5250 50  0001 C CNN
F 3 "~" H 3550 5250 50  0001 C CNN
	1    3550 5250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5C4C9224
P 3800 5250
F 0 "R2" H 3750 5300 50  0000 L CNN
F 1 "R" H 3750 5200 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3730 5250 50  0001 C CNN
F 3 "~" H 3800 5250 50  0001 C CNN
	1    3800 5250
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01
U 1 1 5C4C957B
P 3550 5100
F 0 "#PWR01" H 3550 4950 50  0001 C CNN
F 1 "+3.3V" H 3565 5273 50  0000 C CNN
F 2 "" H 3550 5100 50  0001 C CNN
F 3 "" H 3550 5100 50  0001 C CNN
	1    3550 5100
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR02
U 1 1 5C4C95B1
P 3800 5100
F 0 "#PWR02" H 3800 4950 50  0001 C CNN
F 1 "+3.3V" H 3815 5273 50  0000 C CNN
F 2 "" H 3800 5100 50  0001 C CNN
F 3 "" H 3800 5100 50  0001 C CNN
	1    3800 5100
	1    0    0    -1  
$EndComp
Text Label 3600 5400 0    50   ~ 0
SCL
Wire Wire Line
	3800 5400 3600 5400
Text Label 3350 5400 0    50   ~ 0
SDA
Wire Wire Line
	3550 5400 3350 5400
Wire Wire Line
	4650 3900 4950 3900
Text Label 4700 3900 0    50   ~ 0
alarm
$Comp
L Connector_Generic:Conn_01x04 J1
U 1 1 5C642F7D
P 8650 5500
F 0 "J1" H 8730 5492 50  0000 L CNN
F 1 "Conn_01x04" H 8730 5401 50  0000 L CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-04A_1x04_P2.54mm_Vertical" H 8650 5500 50  0001 C CNN
F 3 "~" H 8650 5500 50  0001 C CNN
	1    8650 5500
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5C80042A
P 5800 3500
F 0 "R5" V 5800 3500 50  0000 L CNN
F 1 "R" V 5800 3400 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5730 3500 50  0001 C CNN
F 3 "~" H 5800 3500 50  0001 C CNN
	1    5800 3500
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 5C800C90
P 5800 3600
F 0 "R6" V 5800 3600 50  0000 L CNN
F 1 "R" V 5800 3500 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5730 3600 50  0001 C CNN
F 3 "~" H 5800 3600 50  0001 C CNN
	1    5800 3600
	0    1    1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 5C8017F5
P 4250 5250
F 0 "R3" H 4200 5300 50  0000 L CNN
F 1 "R" H 4200 5200 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4180 5250 50  0001 C CNN
F 3 "~" H 4250 5250 50  0001 C CNN
	1    4250 5250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5C8017FC
P 4600 5250
F 0 "R4" H 4550 5300 50  0000 L CNN
F 1 "R" H 4550 5200 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4530 5250 50  0001 C CNN
F 3 "~" H 4600 5250 50  0001 C CNN
	1    4600 5250
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR06
U 1 1 5C801803
P 4250 5100
F 0 "#PWR06" H 4250 4950 50  0001 C CNN
F 1 "+3.3V" H 4265 5273 50  0000 C CNN
F 2 "" H 4250 5100 50  0001 C CNN
F 3 "" H 4250 5100 50  0001 C CNN
	1    4250 5100
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR09
U 1 1 5C801809
P 4600 5100
F 0 "#PWR09" H 4600 4950 50  0001 C CNN
F 1 "+3.3V" H 4615 5273 50  0000 C CNN
F 2 "" H 4600 5100 50  0001 C CNN
F 3 "" H 4600 5100 50  0001 C CNN
	1    4600 5100
	1    0    0    -1  
$EndComp
Text Label 4400 5400 0    50   ~ 0
SCL_ext
Wire Wire Line
	4600 5400 4400 5400
Text Label 4050 5400 0    50   ~ 0
SDA_ext
Wire Wire Line
	4250 5400 4050 5400
$Comp
L Device:C C5
U 1 1 5C8025F8
P 7550 5350
F 0 "C5" H 7665 5396 50  0000 L CNN
F 1 "100n" H 7665 5305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7588 5200 50  0001 C CNN
F 3 "~" H 7550 5350 50  0001 C CNN
	1    7550 5350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR020
U 1 1 5C8025FF
P 7550 5500
F 0 "#PWR020" H 7550 5250 50  0001 C CNN
F 1 "GND" H 7650 5350 50  0000 R CNN
F 2 "" H 7550 5500 50  0001 C CNN
F 3 "" H 7550 5500 50  0001 C CNN
	1    7550 5500
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR019
U 1 1 5C802605
P 7550 5200
F 0 "#PWR019" H 7550 5050 50  0001 C CNN
F 1 "+3.3V" H 7450 5350 50  0000 L CNN
F 2 "" H 7550 5200 50  0001 C CNN
F 3 "" H 7550 5200 50  0001 C CNN
	1    7550 5200
	1    0    0    -1  
$EndComp
$EndSCHEMATC
