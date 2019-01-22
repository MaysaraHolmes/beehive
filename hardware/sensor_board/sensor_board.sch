EESchema Schematic File Version 4
LIBS:sensor_board-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Beehive Sensor board"
Date "2019-01-22"
Rev "v1.0"
Comp "University of Glasgow"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L honeywell:HIHxx3x-021 U0
U 1 1 5C472AC6
P 4250 3700
F 0 "U0" H 4250 4065 50  0000 C CNN
F 1 "HIHxx3x-021" H 4250 3974 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 4300 4100 50  0001 C CNN
F 3 "https://sensing.honeywell.com/honeywell-sensing-humidicon-hih6100-series-product-sheet-009059-6-en.pdf" H 4550 4450 50  0001 C CNN
	1    4250 3700
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J0
U 1 1 5C472B69
P 4500 4300
F 0 "J0" H 4580 4292 50  0000 L CNN
F 1 "Conn_01x04" H 4580 4201 50  0000 L CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-04A_1x04_P2.54mm_Vertical" H 4500 4300 50  0001 C CNN
F 3 "~" H 4500 4300 50  0001 C CNN
	1    4500 4300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5C472C56
P 4300 4500
F 0 "#PWR0101" H 4300 4250 50  0001 C CNN
F 1 "GND" H 4305 4327 50  0000 C CNN
F 2 "" H 4300 4500 50  0001 C CNN
F 3 "" H 4300 4500 50  0001 C CNN
	1    4300 4500
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5C472C83
P 3850 3800
F 0 "#PWR0102" H 3850 3550 50  0001 C CNN
F 1 "GND" V 3855 3672 50  0000 R CNN
F 2 "" H 3850 3800 50  0001 C CNN
F 3 "" H 3850 3800 50  0001 C CNN
	1    3850 3800
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR0104
U 1 1 5C472D00
P 3850 3600
F 0 "#PWR0104" H 3850 3450 50  0001 C CNN
F 1 "+3.3V" V 3865 3728 50  0000 L CNN
F 2 "" H 3850 3600 50  0001 C CNN
F 3 "" H 3850 3600 50  0001 C CNN
	1    3850 3600
	0    -1   -1   0   
$EndComp
Text Label 4100 4400 0    50   ~ 0
SDA
Text Label 4100 4300 0    50   ~ 0
SCL
Wire Wire Line
	4300 4400 4100 4400
Wire Wire Line
	4300 4300 4100 4300
Text Label 4650 3600 0    50   ~ 0
SCL
Wire Wire Line
	4850 3600 4650 3600
Text Label 4650 3700 0    50   ~ 0
SDA
Wire Wire Line
	4850 3700 4650 3700
$Comp
L Device:C C0
U 1 1 5C473BF9
P 4450 2900
F 0 "C0" H 4565 2946 50  0000 L CNN
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
L power:+3.3V #PWR0105
U 1 1 5C473DB5
P 4450 2750
F 0 "#PWR0105" H 4450 2600 50  0001 C CNN
F 1 "+3.3V" H 4350 2900 50  0000 L CNN
F 2 "" H 4450 2750 50  0001 C CNN
F 3 "" H 4450 2750 50  0001 C CNN
	1    4450 2750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5C474071
P 4450 3050
F 0 "#PWR0107" H 4450 2800 50  0001 C CNN
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
L power:GND #PWR0106
U 1 1 5C474CCF
P 4050 3050
F 0 "#PWR0106" H 4050 2800 50  0001 C CNN
F 1 "GND" V 4055 2922 50  0000 R CNN
F 2 "" H 4050 3050 50  0001 C CNN
F 3 "" H 4050 3050 50  0001 C CNN
	1    4050 3050
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5C4785CE
P 4300 4200
F 0 "#PWR?" H 4300 4050 50  0001 C CNN
F 1 "+3.3V" H 4200 4350 50  0000 L CNN
F 2 "" H 4300 4200 50  0001 C CNN
F 3 "" H 4300 4200 50  0001 C CNN
	1    4300 4200
	1    0    0    -1  
$EndComp
$EndSCHEMATC
