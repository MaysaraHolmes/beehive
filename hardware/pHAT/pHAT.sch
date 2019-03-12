EESchema Schematic File Version 4
LIBS:pHAT-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Beehive pHAT"
Date "2019-03-12"
Rev "v3.3"
Comp "University of Glasgow"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:GND #PWR02
U 1 1 580C1D11
P 3100 3000
F 0 "#PWR02" H 3100 2750 50  0001 C CNN
F 1 "GND" H 3100 2850 50  0000 C CNN
F 2 "" H 3100 3000 50  0000 C CNN
F 3 "" H 3100 3000 50  0000 C CNN
	1    3100 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 1300 3100 1700
Wire Wire Line
	3100 2700 2900 2700
Wire Wire Line
	3100 2500 2900 2500
Connection ~ 3100 2700
Wire Wire Line
	3100 2000 2900 2000
Connection ~ 3100 2500
Wire Wire Line
	3100 1700 2900 1700
Connection ~ 3100 2000
$Comp
L power:GND #PWR03
U 1 1 580C1E01
P 2100 3000
F 0 "#PWR03" H 2100 2750 50  0001 C CNN
F 1 "GND" H 2100 2850 50  0000 C CNN
F 2 "" H 2100 3000 50  0000 C CNN
F 3 "" H 2100 3000 50  0000 C CNN
	1    2100 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 3000 2400 3000
Wire Wire Line
	2100 1500 2100 2300
Wire Wire Line
	2100 2300 2400 2300
Connection ~ 2200 1100
Wire Wire Line
	2200 1900 2400 1900
Wire Wire Line
	2200 1100 2400 1100
Wire Wire Line
	2200 950  2200 1100
$Comp
L power:+3.3V #PWR04
U 1 1 580C1BC1
P 2200 950
F 0 "#PWR04" H 2200 800 50  0001 C CNN
F 1 "+3.3V" H 2200 1090 50  0000 C CNN
F 2 "" H 2200 950 50  0000 C CNN
F 3 "" H 2200 950 50  0000 C CNN
	1    2200 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 1500 2400 1500
Connection ~ 2100 2300
Text Label 2250 1200 0    50   ~ 0
SDA0
Text Label 2250 1300 0    50   ~ 0
SCL0
Wire Wire Line
	3100 1300 2900 1300
Connection ~ 3100 1700
Text Notes 650  7600 0    50   ~ 0
ID_SD and ID_SC PINS:\nThese pins are reserved for HAT ID EEPROM.\n\nAt boot time this I2C interface will be\ninterrogated to look for an EEPROM\nthat identifes the attached board and\nallows automagic setup of the GPIOs\n(and optionally, Linux drivers).\n\nDO NOT USE these pins for anything other\nthan attaching an I2C ID EEPROM. Leave\nunconnected if ID EEPROM not required.
$Comp
L pHAT-rescue:Mounting_Hole-Mechanical MK1
U 1 1 5834FB2E
P 3000 7200
F 0 "MK1" H 3100 7246 50  0000 L CNN
F 1 "M2.5" H 3100 7155 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.7mm_M2.5" H 3000 7200 60  0001 C CNN
F 3 "" H 3000 7200 60  0001 C CNN
	1    3000 7200
	1    0    0    -1  
$EndComp
$Comp
L pHAT-rescue:Mounting_Hole-Mechanical MK3
U 1 1 5834FBEF
P 3450 7200
F 0 "MK3" H 3550 7246 50  0000 L CNN
F 1 "M2.5" H 3550 7155 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.7mm_M2.5" H 3450 7200 60  0001 C CNN
F 3 "" H 3450 7200 60  0001 C CNN
	1    3450 7200
	1    0    0    -1  
$EndComp
$Comp
L pHAT-rescue:Mounting_Hole-Mechanical MK2
U 1 1 5834FC19
P 3000 7400
F 0 "MK2" H 3100 7446 50  0000 L CNN
F 1 "M2.5" H 3100 7355 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.7mm_M2.5" H 3000 7400 60  0001 C CNN
F 3 "" H 3000 7400 60  0001 C CNN
	1    3000 7400
	1    0    0    -1  
$EndComp
$Comp
L pHAT-rescue:Mounting_Hole-Mechanical MK4
U 1 1 5834FC4F
P 3450 7400
F 0 "MK4" H 3550 7446 50  0000 L CNN
F 1 "M2.5" H 3550 7355 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.7mm_M2.5" H 3450 7400 60  0001 C CNN
F 3 "" H 3450 7400 60  0001 C CNN
	1    3450 7400
	1    0    0    -1  
$EndComp
Text Notes 3000 7050 0    50   ~ 0
Mounting Holes
$Comp
L Connector_Generic:Conn_02x20_Odd_Even P1
U 1 1 59AD464A
P 2600 2000
F 0 "P1" H 2650 3117 50  0000 C CNN
F 1 "Conn_02x20_Odd_Even" H 2650 3026 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x20_P2.54mm_Vertical" H -2250 1050 50  0001 C CNN
F 3 "" H -2250 1050 50  0001 C CNN
	1    2600 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 2700 3100 3000
Wire Wire Line
	3100 2500 3100 2700
Wire Wire Line
	3100 2000 3100 2500
Wire Wire Line
	2200 1100 2200 1900
Wire Wire Line
	2100 2300 2100 3000
Wire Wire Line
	3100 1700 3100 2000
$Comp
L Device:R R3
U 1 1 5C45F9EB
P 2300 3950
F 0 "R3" H 2370 3996 50  0000 L CNN
F 1 "5K" H 2370 3905 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2230 3950 50  0001 C CNN
F 3 "~" H 2300 3950 50  0001 C CNN
	1    2300 3950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5C45F9F2
P 2550 3950
F 0 "R4" H 2620 3996 50  0000 L CNN
F 1 "5K" H 2620 3905 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2480 3950 50  0001 C CNN
F 3 "~" H 2550 3950 50  0001 C CNN
	1    2550 3950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5C45FC34
P 2800 3950
F 0 "R5" H 2870 3996 50  0000 L CNN
F 1 "5K" H 2870 3905 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2730 3950 50  0001 C CNN
F 3 "~" H 2800 3950 50  0001 C CNN
	1    2800 3950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5C45FC3B
P 3050 3950
F 0 "R6" H 3120 3996 50  0000 L CNN
F 1 "5K" H 3120 3905 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2980 3950 50  0001 C CNN
F 3 "~" H 3050 3950 50  0001 C CNN
	1    3050 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 1200 2250 1200
Wire Wire Line
	2400 1300 2250 1300
Wire Wire Line
	2300 4100 2300 4200
Text Label 2100 4200 0    50   ~ 0
SDA0
Wire Wire Line
	2100 4200 2300 4200
Wire Wire Line
	2550 4100 2550 4200
Text Label 2350 4200 0    50   ~ 0
SCL0
Wire Wire Line
	2350 4200 2550 4200
Wire Wire Line
	2800 4100 2800 4200
Text Label 2600 4200 0    50   ~ 0
SDA1
Wire Wire Line
	2600 4200 2800 4200
Wire Wire Line
	3050 4100 3050 4200
Text Label 2850 4200 0    50   ~ 0
SCL1
Wire Wire Line
	2850 4200 3050 4200
$Comp
L power:+3V3 #PWR0109
U 1 1 5C46C519
P 2300 3800
F 0 "#PWR0109" H 2300 3650 50  0001 C CNN
F 1 "+3V3" H 2315 3973 50  0000 C CNN
F 2 "" H 2300 3800 50  0001 C CNN
F 3 "" H 2300 3800 50  0001 C CNN
	1    2300 3800
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0110
U 1 1 5C46C55F
P 2550 3800
F 0 "#PWR0110" H 2550 3650 50  0001 C CNN
F 1 "+3V3" H 2565 3973 50  0000 C CNN
F 2 "" H 2550 3800 50  0001 C CNN
F 3 "" H 2550 3800 50  0001 C CNN
	1    2550 3800
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0111
U 1 1 5C46C5A5
P 2800 3800
F 0 "#PWR0111" H 2800 3650 50  0001 C CNN
F 1 "+3V3" H 2815 3973 50  0000 C CNN
F 2 "" H 2800 3800 50  0001 C CNN
F 3 "" H 2800 3800 50  0001 C CNN
	1    2800 3800
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0112
U 1 1 5C46C631
P 3050 3800
F 0 "#PWR0112" H 3050 3650 50  0001 C CNN
F 1 "+3V3" H 3065 3973 50  0000 C CNN
F 2 "" H 3050 3800 50  0001 C CNN
F 3 "" H 3050 3800 50  0001 C CNN
	1    3050 3800
	1    0    0    -1  
$EndComp
Text Label 7600 2600 0    50   ~ 0
SDAA
Wire Wire Line
	7600 2600 7800 2600
Text Label 7600 2700 0    50   ~ 0
SCLA
Wire Wire Line
	7600 2700 7800 2700
$Comp
L power:+3V3 #PWR0118
U 1 1 5C47656D
P 7800 2800
F 0 "#PWR0118" H 7800 2650 50  0001 C CNN
F 1 "+3V3" V 7815 2928 50  0000 L CNN
F 2 "" H 7800 2800 50  0001 C CNN
F 3 "" H 7800 2800 50  0001 C CNN
	1    7800 2800
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0121
U 1 1 5C4780F6
P 7800 2500
F 0 "#PWR0121" H 7800 2250 50  0001 C CNN
F 1 "GND" V 7805 2372 50  0000 R CNN
F 2 "" H 7800 2500 50  0001 C CNN
F 3 "" H 7800 2500 50  0001 C CNN
	1    7800 2500
	0    1    1    0   
$EndComp
Text Label 2250 1600 0    50   ~ 0
SDA1
Text Label 2250 1700 0    50   ~ 0
SCL1
Wire Wire Line
	2400 1600 2250 1600
Wire Wire Line
	2400 1700 2250 1700
Connection ~ 2100 3000
$Comp
L Interface_Expansion:P82B96 U3
U 1 1 5C48E452
P 5050 3350
F 0 "U3" H 5050 3967 50  0000 C CNN
F 1 "P82B96" H 5050 3876 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 5050 3350 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/P82B96.pdf" H 5050 3350 50  0001 C CNN
	1    5050 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 3050 5650 3250
Wire Wire Line
	5650 3450 5650 3650
Text Label 4300 3250 0    50   ~ 0
SDA1
Text Label 4300 3450 0    50   ~ 0
SCL1
Wire Wire Line
	4450 3250 4300 3250
Wire Wire Line
	4450 3450 4300 3450
Text Label 5650 3050 0    50   ~ 0
SDAA
Wire Wire Line
	5650 3050 5850 3050
Text Label 5650 3450 0    50   ~ 0
SCLA
Wire Wire Line
	5650 3450 5850 3450
Connection ~ 5650 3050
Connection ~ 5650 3450
$Comp
L Device:R R2
U 1 1 5C49901B
P 3300 3950
F 0 "R2" H 3370 3996 50  0000 L CNN
F 1 "5K" H 3370 3905 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3230 3950 50  0001 C CNN
F 3 "~" H 3300 3950 50  0001 C CNN
	1    3300 3950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5C499022
P 3550 3950
F 0 "R1" H 3620 3996 50  0000 L CNN
F 1 "5K" H 3620 3905 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3480 3950 50  0001 C CNN
F 3 "~" H 3550 3950 50  0001 C CNN
	1    3550 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 4100 3300 4200
Text Label 3100 4200 0    50   ~ 0
SDAA
Wire Wire Line
	3100 4200 3300 4200
Wire Wire Line
	3550 4100 3550 4200
Text Label 3350 4200 0    50   ~ 0
SCLA
Wire Wire Line
	3350 4200 3550 4200
$Comp
L power:+3V3 #PWR0108
U 1 1 5C499041
P 3300 3800
F 0 "#PWR0108" H 3300 3650 50  0001 C CNN
F 1 "+3V3" H 3315 3973 50  0000 C CNN
F 2 "" H 3300 3800 50  0001 C CNN
F 3 "" H 3300 3800 50  0001 C CNN
	1    3300 3800
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0115
U 1 1 5C499047
P 3550 3800
F 0 "#PWR0115" H 3550 3650 50  0001 C CNN
F 1 "+3V3" H 3565 3973 50  0000 C CNN
F 2 "" H 3550 3800 50  0001 C CNN
F 3 "" H 3550 3800 50  0001 C CNN
	1    3550 3800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0122
U 1 1 5C49D27C
P 4450 3650
F 0 "#PWR0122" H 4450 3400 50  0001 C CNN
F 1 "GND" H 4455 3477 50  0000 C CNN
F 2 "" H 4450 3650 50  0001 C CNN
F 3 "" H 4450 3650 50  0001 C CNN
	1    4450 3650
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0125
U 1 1 5C49D3A3
P 4450 3050
F 0 "#PWR0125" H 4450 2900 50  0001 C CNN
F 1 "+3V3" H 4465 3223 50  0000 C CNN
F 2 "" H 4450 3050 50  0001 C CNN
F 3 "" H 4450 3050 50  0001 C CNN
	1    4450 3050
	1    0    0    -1  
$EndComp
Text Label 2000 1400 0    50   ~ 0
alarm_hive
Wire Wire Line
	2400 1400 2000 1400
$Comp
L honeywell:HIHxx3x-021 U2
U 1 1 5C630BFF
P 4950 2150
F 0 "U2" H 4950 2515 50  0000 C CNN
F 1 "HIH6131-021" H 4950 2424 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 5000 2550 50  0001 C CNN
F 3 "https://sensing.honeywell.com/honeywell-sensing-humidicon-hih6100-series-product-sheet-009059-6-en.pdf" H 5250 2900 50  0001 C CNN
	1    4950 2150
	1    0    0    -1  
$EndComp
Text Label 5350 2350 0    50   ~ 0
alarm_hive
Wire Wire Line
	5750 2350 5350 2350
$Comp
L power:GND #PWR0104
U 1 1 5C632697
P 4550 2250
F 0 "#PWR0104" H 4550 2000 50  0001 C CNN
F 1 "GND" V 4555 2122 50  0000 R CNN
F 2 "" H 4550 2250 50  0001 C CNN
F 3 "" H 4550 2250 50  0001 C CNN
	1    4550 2250
	0    1    1    0   
$EndComp
$Comp
L power:+3V3 #PWR0107
U 1 1 5C63270D
P 4550 2050
F 0 "#PWR0107" H 4550 1900 50  0001 C CNN
F 1 "+3V3" V 4565 2178 50  0000 L CNN
F 2 "" H 4550 2050 50  0001 C CNN
F 3 "" H 4550 2050 50  0001 C CNN
	1    4550 2050
	0    -1   -1   0   
$EndComp
Text Label 5350 2150 0    50   ~ 0
SDA0
Text Label 5350 2050 0    50   ~ 0
SCL0
Wire Wire Line
	5500 2150 5350 2150
Wire Wire Line
	5500 2050 5350 2050
Text Label 4300 2150 0    50   ~ 0
Vcore
Wire Wire Line
	4550 2150 4300 2150
$Comp
L Device:C C2
U 1 1 5C63900E
P 3550 2300
F 0 "C2" H 3665 2346 50  0000 L CNN
F 1 "0.1µ" H 3665 2255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3588 2150 50  0001 C CNN
F 3 "~" H 3550 2300 50  0001 C CNN
	1    3550 2300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 5C639015
P 3900 2300
F 0 "C3" H 4015 2346 50  0000 L CNN
F 1 "0.22µ" H 4015 2255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3938 2150 50  0001 C CNN
F 3 "~" H 3900 2300 50  0001 C CNN
	1    3900 2300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0119
U 1 1 5C63901C
P 3550 2450
F 0 "#PWR0119" H 3550 2200 50  0001 C CNN
F 1 "GND" H 3555 2277 50  0000 C CNN
F 2 "" H 3550 2450 50  0001 C CNN
F 3 "" H 3550 2450 50  0001 C CNN
	1    3550 2450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0120
U 1 1 5C639022
P 3900 2450
F 0 "#PWR0120" H 3900 2200 50  0001 C CNN
F 1 "GND" H 3905 2277 50  0000 C CNN
F 2 "" H 3900 2450 50  0001 C CNN
F 3 "" H 3900 2450 50  0001 C CNN
	1    3900 2450
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0123
U 1 1 5C63902E
P 3900 2150
F 0 "#PWR0123" H 3900 2000 50  0001 C CNN
F 1 "+3V3" H 3915 2323 50  0000 C CNN
F 2 "" H 3900 2150 50  0001 C CNN
F 3 "" H 3900 2150 50  0001 C CNN
	1    3900 2150
	1    0    0    -1  
$EndComp
Text Label 3300 2150 0    50   ~ 0
Vcore
Wire Wire Line
	3550 2150 3300 2150
$Comp
L Connector_Generic:Conn_01x04 J0
U 1 1 5C646ECB
P 8000 2600
F 0 "J0" H 8080 2592 50  0000 L CNN
F 1 "Conn_01x04" H 8080 2501 50  0000 L CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-04A_1x04_P2.54mm_Vertical" H 8000 2600 50  0001 C CNN
F 3 "~" H 8000 2600 50  0001 C CNN
	1    8000 2600
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 5C648B5C
P 8000 2100
F 0 "J1" H 8080 2092 50  0000 L CNN
F 1 "Conn_01x02" H 8080 2001 50  0000 L CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-02A_1x02_P2.54mm_Vertical" H 8000 2100 50  0001 C CNN
F 3 "~" H 8000 2100 50  0001 C CNN
	1    8000 2100
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0101
U 1 1 5C648C36
P 7650 2000
F 0 "#PWR0101" H 7650 1850 50  0001 C CNN
F 1 "+5V" H 7665 2173 50  0000 C CNN
F 2 "" H 7650 2000 50  0001 C CNN
F 3 "" H 7650 2000 50  0001 C CNN
	1    7650 2000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0102
U 1 1 5C648D8A
P 2900 1100
F 0 "#PWR0102" H 2900 950 50  0001 C CNN
F 1 "+5V" V 2915 1228 50  0000 L CNN
F 2 "" H 2900 1100 50  0001 C CNN
F 3 "" H 2900 1100 50  0001 C CNN
	1    2900 1100
	0    1    1    0   
$EndComp
Wire Wire Line
	2900 1200 2900 1100
Connection ~ 2900 1100
Text Label 7300 2300 0    50   ~ 0
fan_cmd
Wire Wire Line
	7650 2300 7300 2300
Text Label 2900 1600 0    50   ~ 0
cmd
Wire Wire Line
	3050 1600 2900 1600
$Comp
L Device:R R7
U 1 1 5C66B531
P 3800 3950
F 0 "R7" H 3870 3996 50  0000 L CNN
F 1 "5K" H 3870 3905 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3730 3950 50  0001 C CNN
F 3 "~" H 3800 3950 50  0001 C CNN
	1    3800 3950
	1    0    0    -1  
$EndComp
Text Label 3650 3800 0    50   ~ 0
cmd
Wire Wire Line
	3800 3800 3650 3800
$Comp
L power:GND #PWR0103
U 1 1 5C6704A6
P 3800 4100
F 0 "#PWR0103" H 3800 3850 50  0001 C CNN
F 1 "GND" H 3805 3927 50  0000 C CNN
F 2 "" H 3800 4100 50  0001 C CNN
F 3 "" H 3800 4100 50  0001 C CNN
	1    3800 4100
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7002 Q1
U 1 1 5C6AACFD
P 6500 2250
F 0 "Q1" H 6705 2296 50  0000 L CNN
F 1 "2N7002" H 6705 2205 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 6700 2175 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7002.pdf" H 6500 2250 50  0001 L CNN
	1    6500 2250
	1    0    0    -1  
$EndComp
Text Label 6150 2250 0    50   ~ 0
cmd
Wire Wire Line
	6300 2250 6150 2250
$Comp
L power:GND #PWR0105
U 1 1 5C6ABD61
P 6600 2450
F 0 "#PWR0105" H 6600 2200 50  0001 C CNN
F 1 "GND" V 6605 2322 50  0000 R CNN
F 2 "" H 6600 2450 50  0001 C CNN
F 3 "" H 6600 2450 50  0001 C CNN
	1    6600 2450
	1    0    0    -1  
$EndComp
Text Label 6250 2050 0    50   ~ 0
fan_cmd
Wire Wire Line
	6600 2050 6250 2050
$Comp
L Diode:1N4007 D1
U 1 1 5C6AF374
P 7650 2150
F 0 "D1" V 7550 2000 50  0000 L CNN
F 1 "1N4007" V 7650 1800 50  0000 L CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 7650 1975 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 7650 2150 50  0001 C CNN
	1    7650 2150
	0    1    1    0   
$EndComp
Wire Wire Line
	7800 2000 7650 2000
Wire Wire Line
	7800 2000 7800 2100
Connection ~ 7650 2000
Wire Wire Line
	7800 2200 7800 2300
Wire Wire Line
	7800 2300 7650 2300
Connection ~ 7650 2300
$EndSCHEMATC
