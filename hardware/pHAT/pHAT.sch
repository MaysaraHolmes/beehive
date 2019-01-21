EESchema Schematic File Version 4
LIBS:pHAT-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Beehive pHAT"
Date "2019-01-21"
Rev "v1.1"
Comp "University of Glasgow"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:GND #PWR02
U 1 1 580C1D11
P 3000 3150
F 0 "#PWR02" H 3000 2900 50  0001 C CNN
F 1 "GND" H 3000 3000 50  0000 C CNN
F 2 "" H 3000 3150 50  0000 C CNN
F 3 "" H 3000 3150 50  0000 C CNN
	1    3000 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 1300 3000 1700
Wire Wire Line
	3000 2700 2900 2700
Wire Wire Line
	3000 2500 2900 2500
Connection ~ 3000 2700
Wire Wire Line
	3000 2000 2900 2000
Connection ~ 3000 2500
Wire Wire Line
	3000 1700 2900 1700
Connection ~ 3000 2000
$Comp
L power:GND #PWR03
U 1 1 580C1E01
P 2300 3150
F 0 "#PWR03" H 2300 2900 50  0001 C CNN
F 1 "GND" H 2300 3000 50  0000 C CNN
F 2 "" H 2300 3150 50  0000 C CNN
F 3 "" H 2300 3150 50  0000 C CNN
	1    2300 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 3000 2400 3000
Wire Wire Line
	2300 1500 2300 2300
Wire Wire Line
	2300 2300 2400 2300
Connection ~ 2300 3000
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
	2300 1500 2400 1500
Connection ~ 2300 2300
Text Label 2250 1200 0    50   ~ 0
SDA
Text Label 2250 1300 0    50   ~ 0
SCL
Wire Wire Line
	3000 1300 2900 1300
Connection ~ 3000 1700
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
	3000 2700 3000 3150
Wire Wire Line
	3000 2500 3000 2700
Wire Wire Line
	3000 2000 3000 2500
Wire Wire Line
	2300 3000 2300 3150
Wire Wire Line
	2200 1100 2200 1900
Wire Wire Line
	2300 2300 2300 3000
Wire Wire Line
	3000 1700 3000 2000
$Comp
L Analog_ADC:ADC101C021CIMK U1
U 1 1 5C45F314
P 5000 1300
F 0 "U1" H 5000 1667 50  0000 C CNN
F 1 "ADC101C021CIMK" H 5000 1576 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 5800 950 50  0001 C CNN
F 3 "" H 5000 1400 50  0001 C CNN
	1    5000 1300
	1    0    0    -1  
$EndComp
$Comp
L Interface_Expansion:PCA9540B U0
U 1 1 5C45F476
P 3750 2150
F 0 "U0" H 4900 2325 50  0000 C CNN
F 1 "PCA9540B" H 4900 2234 50  0000 C CNN
F 2 "Package_SO:TSSOP-8_3x3mm_P0.65mm" H 4950 1650 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/PCA9540B.pdf" H 6100 1500 50  0001 C CNN
	1    3750 2150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R0
U 1 1 5C45F4DE
P 5650 1400
F 0 "R0" V 5857 1400 50  0000 C CNN
F 1 "5K" V 5766 1400 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5580 1400 50  0001 C CNN
F 3 "~" H 5650 1400 50  0001 C CNN
	1    5650 1400
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C0
U 1 1 5C45F5A4
P 3600 1300
F 0 "C0" H 3715 1346 50  0000 L CNN
F 1 "0.1µ" H 3715 1255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3638 1150 50  0001 C CNN
F 3 "~" H 3600 1300 50  0001 C CNN
	1    3600 1300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5C45F777
P 6950 1200
F 0 "R2" H 7020 1246 50  0000 L CNN
F 1 "5K" H 7020 1155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6880 1200 50  0001 C CNN
F 3 "~" H 6950 1200 50  0001 C CNN
	1    6950 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5C45F9EB
P 7200 1200
F 0 "R3" H 7270 1246 50  0000 L CNN
F 1 "5K" H 7270 1155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 7130 1200 50  0001 C CNN
F 3 "~" H 7200 1200 50  0001 C CNN
	1    7200 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5C45F9F2
P 7450 1200
F 0 "R4" H 7520 1246 50  0000 L CNN
F 1 "5K" H 7520 1155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 7380 1200 50  0001 C CNN
F 3 "~" H 7450 1200 50  0001 C CNN
	1    7450 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5C45FC34
P 7700 1200
F 0 "R5" H 7770 1246 50  0000 L CNN
F 1 "5K" H 7770 1155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 7630 1200 50  0001 C CNN
F 3 "~" H 7700 1200 50  0001 C CNN
	1    7700 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5C45FC3B
P 7950 1200
F 0 "R6" H 8020 1246 50  0000 L CNN
F 1 "5K" H 8020 1155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 7880 1200 50  0001 C CNN
F 3 "~" H 7950 1200 50  0001 C CNN
	1    7950 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 5C45FEE1
P 6450 2200
F 0 "R7" H 6520 2246 50  0000 L CNN
F 1 "5K" H 6520 2155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6380 2200 50  0001 C CNN
F 3 "~" H 6450 2200 50  0001 C CNN
	1    6450 2200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 5C45FEE8
P 6450 2500
F 0 "R8" H 6520 2546 50  0000 L CNN
F 1 "5K" H 6520 2455 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6380 2500 50  0001 C CNN
F 3 "~" H 6450 2500 50  0001 C CNN
	1    6450 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5C460159
P 6700 1200
F 0 "R1" H 6770 1246 50  0000 L CNN
F 1 "5K" H 6770 1155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6630 1200 50  0001 C CNN
F 3 "~" H 6700 1200 50  0001 C CNN
	1    6700 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5C460C0C
P 3950 1300
F 0 "C1" H 4065 1346 50  0000 L CNN
F 1 "4.7µ" H 4065 1255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3988 1150 50  0001 C CNN
F 3 "~" H 3950 1300 50  0001 C CNN
	1    3950 1300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5C461228
P 3600 1450
F 0 "#PWR0101" H 3600 1200 50  0001 C CNN
F 1 "GND" H 3605 1277 50  0000 C CNN
F 2 "" H 3600 1450 50  0001 C CNN
F 3 "" H 3600 1450 50  0001 C CNN
	1    3600 1450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5C461275
P 3950 1450
F 0 "#PWR0102" H 3950 1200 50  0001 C CNN
F 1 "GND" H 3955 1277 50  0000 C CNN
F 2 "" H 3950 1450 50  0001 C CNN
F 3 "" H 3950 1450 50  0001 C CNN
	1    3950 1450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5C461352
P 4600 1300
F 0 "#PWR0103" H 4600 1050 50  0001 C CNN
F 1 "GND" V 4605 1172 50  0000 R CNN
F 2 "" H 4600 1300 50  0001 C CNN
F 3 "" H 4600 1300 50  0001 C CNN
	1    4600 1300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5C4613F2
P 4400 2500
F 0 "#PWR0104" H 4400 2250 50  0001 C CNN
F 1 "GND" V 4405 2372 50  0000 R CNN
F 2 "" H 4400 2500 50  0001 C CNN
F 3 "" H 4400 2500 50  0001 C CNN
	1    4400 2500
	0    1    1    0   
$EndComp
Wire Wire Line
	2400 1200 2250 1200
Wire Wire Line
	2400 1300 2250 1300
Text Label 5400 1200 0    50   ~ 0
SDA
Text Label 5400 1300 0    50   ~ 0
SCL
Wire Wire Line
	5550 1200 5400 1200
Wire Wire Line
	5550 1300 5400 1300
Text Label 4250 2400 0    50   ~ 0
SDA
Text Label 4250 2300 0    50   ~ 0
SCL
Wire Wire Line
	4400 2400 4250 2400
Wire Wire Line
	4400 2300 4250 2300
Wire Wire Line
	5400 1400 5500 1400
Text Label 6550 1450 0    50   ~ 0
SDA
Text Label 6800 1450 0    50   ~ 0
SCL
Wire Wire Line
	6700 1450 6550 1450
Wire Wire Line
	6950 1450 6800 1450
Wire Wire Line
	6700 1350 6700 1450
Wire Wire Line
	6950 1350 6950 1450
Wire Wire Line
	7200 1350 7200 1450
Text Label 7000 1450 0    50   ~ 0
SDA0
Wire Wire Line
	7000 1450 7200 1450
Wire Wire Line
	7450 1350 7450 1450
Text Label 7250 1450 0    50   ~ 0
SCL0
Wire Wire Line
	7250 1450 7450 1450
Wire Wire Line
	7700 1350 7700 1450
Text Label 7500 1450 0    50   ~ 0
SDA1
Wire Wire Line
	7500 1450 7700 1450
Wire Wire Line
	7950 1350 7950 1450
Text Label 7750 1450 0    50   ~ 0
SCL1
Wire Wire Line
	7750 1450 7950 1450
Text Label 4250 1200 0    50   ~ 0
AnalogIn
Wire Wire Line
	4600 1200 4250 1200
$Comp
L power:+3V3 #PWR0105
U 1 1 5C46C401
P 3600 1150
F 0 "#PWR0105" H 3600 1000 50  0001 C CNN
F 1 "+3V3" H 3615 1323 50  0000 C CNN
F 2 "" H 3600 1150 50  0001 C CNN
F 3 "" H 3600 1150 50  0001 C CNN
	1    3600 1150
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0106
U 1 1 5C46C447
P 3950 1150
F 0 "#PWR0106" H 3950 1000 50  0001 C CNN
F 1 "+3V3" H 3965 1323 50  0000 C CNN
F 2 "" H 3950 1150 50  0001 C CNN
F 3 "" H 3950 1150 50  0001 C CNN
	1    3950 1150
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0107
U 1 1 5C46C48D
P 6700 1050
F 0 "#PWR0107" H 6700 900 50  0001 C CNN
F 1 "+3V3" H 6715 1223 50  0000 C CNN
F 2 "" H 6700 1050 50  0001 C CNN
F 3 "" H 6700 1050 50  0001 C CNN
	1    6700 1050
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0108
U 1 1 5C46C4D3
P 6950 1050
F 0 "#PWR0108" H 6950 900 50  0001 C CNN
F 1 "+3V3" H 6965 1223 50  0000 C CNN
F 2 "" H 6950 1050 50  0001 C CNN
F 3 "" H 6950 1050 50  0001 C CNN
	1    6950 1050
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0109
U 1 1 5C46C519
P 7200 1050
F 0 "#PWR0109" H 7200 900 50  0001 C CNN
F 1 "+3V3" H 7215 1223 50  0000 C CNN
F 2 "" H 7200 1050 50  0001 C CNN
F 3 "" H 7200 1050 50  0001 C CNN
	1    7200 1050
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0110
U 1 1 5C46C55F
P 7450 1050
F 0 "#PWR0110" H 7450 900 50  0001 C CNN
F 1 "+3V3" H 7465 1223 50  0000 C CNN
F 2 "" H 7450 1050 50  0001 C CNN
F 3 "" H 7450 1050 50  0001 C CNN
	1    7450 1050
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0111
U 1 1 5C46C5A5
P 7700 1050
F 0 "#PWR0111" H 7700 900 50  0001 C CNN
F 1 "+3V3" H 7715 1223 50  0000 C CNN
F 2 "" H 7700 1050 50  0001 C CNN
F 3 "" H 7700 1050 50  0001 C CNN
	1    7700 1050
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0112
U 1 1 5C46C631
P 7950 1050
F 0 "#PWR0112" H 7950 900 50  0001 C CNN
F 1 "+3V3" H 7965 1223 50  0000 C CNN
F 2 "" H 7950 1050 50  0001 C CNN
F 3 "" H 7950 1050 50  0001 C CNN
	1    7950 1050
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0113
U 1 1 5C46C665
P 5800 1400
F 0 "#PWR0113" H 5800 1250 50  0001 C CNN
F 1 "+3V3" H 5815 1573 50  0000 C CNN
F 2 "" H 5800 1400 50  0001 C CNN
F 3 "" H 5800 1400 50  0001 C CNN
	1    5800 1400
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0114
U 1 1 5C46C699
P 4600 1400
F 0 "#PWR0114" H 4600 1250 50  0001 C CNN
F 1 "+3V3" V 4615 1528 50  0000 L CNN
F 2 "" H 4600 1400 50  0001 C CNN
F 3 "" H 4600 1400 50  0001 C CNN
	1    4600 1400
	0    -1   -1   0   
$EndComp
$Comp
L power:+3V3 #PWR0115
U 1 1 5C46C6DF
P 4400 2200
F 0 "#PWR0115" H 4400 2050 50  0001 C CNN
F 1 "+3V3" V 4415 2328 50  0000 L CNN
F 2 "" H 4400 2200 50  0001 C CNN
F 3 "" H 4400 2200 50  0001 C CNN
	1    4400 2200
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0116
U 1 1 5C46D8F5
P 6450 2650
F 0 "#PWR0116" H 6450 2400 50  0001 C CNN
F 1 "GND" H 6455 2477 50  0000 C CNN
F 2 "" H 6450 2650 50  0001 C CNN
F 3 "" H 6450 2650 50  0001 C CNN
	1    6450 2650
	1    0    0    -1  
$EndComp
Text Label 5400 2200 0    50   ~ 0
SDA0
Wire Wire Line
	5400 2200 5600 2200
Text Label 5400 2300 0    50   ~ 0
SCL0
Wire Wire Line
	5400 2300 5600 2300
Text Label 5400 2400 0    50   ~ 0
SDA1
Wire Wire Line
	5400 2400 5600 2400
Text Label 5400 2500 0    50   ~ 0
SCL1
Wire Wire Line
	5400 2500 5600 2500
$Comp
L Connector_Generic:Conn_01x04 J_Air1
U 1 1 5C4706C5
P 8000 2050
F 0 "J_Air1" H 8080 2042 50  0000 L CNN
F 1 "Conn_01x04" H 8080 1951 50  0000 L CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-04A_1x04_P2.54mm_Vertical" H 8000 2050 50  0001 C CNN
F 3 "~" H 8000 2050 50  0001 C CNN
	1    8000 2050
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J_Hive1
U 1 1 5C470742
P 8000 2600
F 0 "J_Hive1" H 8080 2592 50  0000 L CNN
F 1 "Conn_01x04" H 8080 2501 50  0000 L CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-04A_1x04_P2.54mm_Vertical" H 8000 2600 50  0001 C CNN
F 3 "~" H 8000 2600 50  0001 C CNN
	1    8000 2600
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J_Weight1
U 1 1 5C4707D9
P 6650 1950
F 0 "J_Weight1" H 6730 1942 50  0000 L CNN
F 1 "Conn_01x02" H 6730 1851 50  0000 L CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-02A_1x02_P2.54mm_Vertical" H 6650 1950 50  0001 C CNN
F 3 "~" H 6650 1950 50  0001 C CNN
	1    6650 1950
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0117
U 1 1 5C4712F2
P 6450 1950
F 0 "#PWR0117" H 6450 1800 50  0001 C CNN
F 1 "+3V3" V 6465 2078 50  0000 L CNN
F 2 "" H 6450 1950 50  0001 C CNN
F 3 "" H 6450 1950 50  0001 C CNN
	1    6450 1950
	0    -1   -1   0   
$EndComp
Text Label 7600 2050 0    50   ~ 0
SDA0
Wire Wire Line
	7600 2050 7800 2050
Text Label 7600 2150 0    50   ~ 0
SCL0
Wire Wire Line
	7600 2150 7800 2150
Text Label 7600 2600 0    50   ~ 0
SDA1
Wire Wire Line
	7600 2600 7800 2600
Text Label 7600 2700 0    50   ~ 0
SCL1
Wire Wire Line
	7600 2700 7800 2700
$Comp
L power:+3V3 #PWR0118
U 1 1 5C47656D
P 7800 2500
F 0 "#PWR0118" H 7800 2350 50  0001 C CNN
F 1 "+3V3" V 7815 2628 50  0000 L CNN
F 2 "" H 7800 2500 50  0001 C CNN
F 3 "" H 7800 2500 50  0001 C CNN
	1    7800 2500
	0    -1   -1   0   
$EndComp
$Comp
L power:+3V3 #PWR0119
U 1 1 5C476E14
P 7800 1950
F 0 "#PWR0119" H 7800 1800 50  0001 C CNN
F 1 "+3V3" V 7815 2078 50  0000 L CNN
F 2 "" H 7800 1950 50  0001 C CNN
F 3 "" H 7800 1950 50  0001 C CNN
	1    7800 1950
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0120
U 1 1 5C47784F
P 7800 2250
F 0 "#PWR0120" H 7800 2000 50  0001 C CNN
F 1 "GND" V 7805 2122 50  0000 R CNN
F 2 "" H 7800 2250 50  0001 C CNN
F 3 "" H 7800 2250 50  0001 C CNN
	1    7800 2250
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0121
U 1 1 5C4780F6
P 7800 2800
F 0 "#PWR0121" H 7800 2550 50  0001 C CNN
F 1 "GND" V 7805 2672 50  0000 R CNN
F 2 "" H 7800 2800 50  0001 C CNN
F 3 "" H 7800 2800 50  0001 C CNN
	1    7800 2800
	0    1    1    0   
$EndComp
Text Label 6100 2050 0    50   ~ 0
AnalogIn
Wire Wire Line
	6450 2050 6100 2050
Connection ~ 6450 2050
$EndSCHEMATC
