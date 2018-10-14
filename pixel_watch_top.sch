EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:LEDS
LIBS:IMU
LIBS:BATT
LIBS:REGULATORS
LIBS:MCU_ST_STM32
LIBS:stm32
LIBS:mpu-9250
LIBS:switches
LIBS:usb
LIBS:pixel_watch-cache
EELAYER 25 0
EELAYER END
$Descr A2 23386 16535
encoding utf-8
Sheet 2 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L C C23
U 1 1 5AB1744A
P 9245 1715
F 0 "C23" H 9270 1815 50  0000 L CNN
F 1 "10uF" H 9270 1615 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 9283 1565 50  0001 C CNN
F 3 "" H 9245 1715 50  0001 C CNN
	1    9245 1715
	1    0    0    -1  
$EndComp
$Comp
L C C25
U 1 1 5AB17687
P 9995 1665
F 0 "C25" H 10020 1765 50  0000 L CNN
F 1 "10uF" H 10020 1565 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 10033 1515 50  0001 C CNN
F 3 "" H 9995 1665 50  0001 C CNN
	1    9995 1665
	1    0    0    -1  
$EndComp
$Comp
L C C19
U 1 1 5AB17722
P 7895 1665
F 0 "C19" H 7920 1765 50  0000 L CNN
F 1 "10uF" H 7920 1565 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7933 1515 50  0001 C CNN
F 3 "" H 7895 1665 50  0001 C CNN
	1    7895 1665
	1    0    0    -1  
$EndComp
$Comp
L C C21
U 1 1 5AB1794E
P 8545 1665
F 0 "C21" H 8570 1765 50  0000 L CNN
F 1 "10uF" H 8570 1565 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 8583 1515 50  0001 C CNN
F 3 "" H 8545 1665 50  0001 C CNN
	1    8545 1665
	1    0    0    -1  
$EndComp
$Comp
L C C24
U 1 1 5AB17B37
P 9645 1715
F 0 "C24" H 9670 1815 50  0000 L CNN
F 1 "10uF" H 9670 1615 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 9683 1565 50  0001 C CNN
F 3 "" H 9645 1715 50  0001 C CNN
	1    9645 1715
	1    0    0    -1  
$EndComp
$Comp
L C C26
U 1 1 5AB17BEE
P 10395 1665
F 0 "C26" H 10420 1765 50  0000 L CNN
F 1 "10uF" H 10420 1565 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 10433 1515 50  0001 C CNN
F 3 "" H 10395 1665 50  0001 C CNN
	1    10395 1665
	1    0    0    -1  
$EndComp
$Comp
L C C20
U 1 1 5AB17CBD
P 8295 1665
F 0 "C20" H 8320 1765 50  0000 L CNN
F 1 "10uF" H 8320 1565 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 8333 1515 50  0001 C CNN
F 3 "" H 8295 1665 50  0001 C CNN
	1    8295 1665
	1    0    0    -1  
$EndComp
$Comp
L C C22
U 1 1 5AB17D70
P 8945 1665
F 0 "C22" H 8970 1765 50  0000 L CNN
F 1 "10uF" H 8970 1565 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 8983 1515 50  0001 C CNN
F 3 "" H 8945 1665 50  0001 C CNN
	1    8945 1665
	1    0    0    -1  
$EndComp
Text Label 7695 1415 2    60   ~ 0
VCC_TOP
Text Label 10200 3290 0    60   ~ 0
BATT_TOP
Text Label 10250 3690 0    60   ~ 0
MOSI
Text Label 10250 3590 0    60   ~ 0
CLK
$Comp
L CONN_01X02 J5
U 1 1 5AFE0DBF
P 9985 2640
F 0 "J5" H 9985 2790 50  0000 C CNN
F 1 "CONN_01X02" V 10085 2640 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.00mm" H 9985 2640 50  0001 C CNN
F 3 "" H 9985 2640 50  0001 C CNN
	1    9985 2640
	-1   0    0    -1  
$EndComp
$Comp
L Q_PMOS_GDS Q1
U 1 1 5AFE1FD0
P 7645 2825
F 0 "Q1" H 7845 2875 50  0000 L CNN
F 1 "Q_PMOS_GDS" H 7845 2775 50  0000 L CNN
F 2 "transistor:SC-70-6-P-CH" H 7845 2925 50  0001 C CNN
F 3 "" H 7645 2825 50  0001 C CNN
	1    7645 2825
	0    1    -1   0   
$EndComp
$Comp
L Q_NPN_BEC Q2
U 1 1 5AFE2546
P 7745 3370
F 0 "Q2" H 7945 3420 50  0000 L CNN
F 1 "Q_NPN_BEC" H 7945 3320 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 7945 3470 50  0001 C CNN
F 3 "" H 7745 3370 50  0001 C CNN
	1    7745 3370
	-1   0    0    -1  
$EndComp
$Comp
L R R21
U 1 1 5AFE8595
P 7275 2965
F 0 "R21" V 7355 2965 50  0000 C CNN
F 1 "10K" V 7275 2965 50  0000 C CNN
F 2 "RES:R_0603" V 7205 2965 50  0001 C CNN
F 3 "" H 7275 2965 50  0001 C CNN
	1    7275 2965
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR01
U 1 1 5AFEAD1E
P 7645 3650
F 0 "#PWR01" H 7645 3400 50  0001 C CNN
F 1 "GNDD" H 7645 3500 50  0000 C CNN
F 2 "" H 7645 3650 50  0001 C CNN
F 3 "" H 7645 3650 50  0001 C CNN
	1    7645 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	9245 1915 9245 1865
Wire Wire Line
	9995 1915 9995 1815
Wire Wire Line
	10395 1915 10395 1815
Wire Wire Line
	8295 1915 8295 1815
Wire Wire Line
	7895 1915 7895 1815
Wire Wire Line
	8545 1915 8545 1815
Wire Wire Line
	8945 1915 8945 1815
Wire Wire Line
	9245 1415 9245 1565
Wire Wire Line
	7695 1415 10395 1415
Wire Wire Line
	9645 1415 9645 1565
Wire Wire Line
	9995 1415 9995 1515
Wire Wire Line
	10395 1415 10395 1515
Wire Wire Line
	7895 1515 7895 1415
Wire Wire Line
	8295 1415 8295 1515
Wire Wire Line
	8545 1415 8545 1515
Wire Wire Line
	8945 1415 8945 1515
Wire Wire Line
	8095 1965 8095 1915
Connection ~ 8095 1915
Connection ~ 8545 1415
Connection ~ 8295 1415
Connection ~ 9245 1415
Connection ~ 8945 1415
Connection ~ 9995 1415
Connection ~ 9645 1415
Connection ~ 9995 1915
Connection ~ 9245 1915
Connection ~ 8945 1915
Connection ~ 8545 1915
Connection ~ 8295 1915
Wire Wire Line
	7895 1915 10395 1915
Wire Wire Line
	9645 1865 9645 1915
Connection ~ 9645 1915
Connection ~ 7895 1415
Wire Wire Line
	10200 3390 10200 3290
Wire Wire Line
	10025 3390 10200 3390
Wire Wire Line
	10025 3590 10250 3590
Wire Wire Line
	10025 3690 10250 3690
Wire Wire Line
	10025 3790 10200 3790
Wire Wire Line
	10200 3790 10200 3970
Connection ~ 10395 1415
Connection ~ 10395 1915
Wire Wire Line
	7645 3025 7645 3170
Wire Wire Line
	7445 2725 7275 2725
Wire Wire Line
	7275 2725 7275 2815
Wire Wire Line
	7275 3115 7275 3140
Wire Wire Line
	7275 3140 7645 3140
Wire Wire Line
	7645 3140 7645 3135
Connection ~ 7645 3135
Wire Wire Line
	7645 3570 7645 3650
Text Label 10250 3490 0    60   ~ 0
RGB_EN_TOP
Wire Wire Line
	10025 3490 10250 3490
$Comp
L GNDD #PWR02
U 1 1 5AFEE7FE
P 10200 3970
F 0 "#PWR02" H 10200 3720 50  0001 C CNN
F 1 "GNDD" H 10200 3820 50  0000 C CNN
F 2 "" H 10200 3970 50  0001 C CNN
F 3 "" H 10200 3970 50  0001 C CNN
	1    10200 3970
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR03
U 1 1 5AFF50C1
P 8095 1965
F 0 "#PWR03" H 8095 1715 50  0001 C CNN
F 1 "GNDD" H 8095 1815 50  0000 C CNN
F 2 "" H 8095 1965 50  0001 C CNN
F 3 "" H 8095 1965 50  0001 C CNN
	1    8095 1965
	1    0    0    -1  
$EndComp
Text Label 10270 2590 0    60   ~ 0
BATT_TOP
$Comp
L GNDD #PWR04
U 1 1 5AFFFFA1
P 10275 2705
F 0 "#PWR04" H 10275 2455 50  0001 C CNN
F 1 "GNDD" H 10275 2555 50  0000 C CNN
F 2 "" H 10275 2705 50  0001 C CNN
F 3 "" H 10275 2705 50  0001 C CNN
	1    10275 2705
	1    0    0    -1  
$EndComp
Wire Wire Line
	10185 2690 10275 2690
Wire Wire Line
	10275 2690 10275 2705
Wire Wire Line
	10185 2590 10270 2590
Text Label 8555 3370 0    60   ~ 0
RGB_EN_TOP
Wire Wire Line
	7945 3370 8120 3370
Text Label 7955 2725 0    60   ~ 0
VCC_TOP
Wire Wire Line
	7845 2725 7955 2725
Text Label 7275 2725 2    60   ~ 0
BATT_TOP
$Comp
L CONN_01X04 J3
U 1 1 5B81E7D1
P 9425 2675
F 0 "J3" H 9425 2925 50  0000 C CNN
F 1 "CONN_01X04" V 9525 2675 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 9425 2675 50  0001 C CNN
F 3 "" H 9425 2675 50  0001 C CNN
	1    9425 2675
	1    0    0    -1  
$EndComp
Text Label 9120 2525 2    60   ~ 0
VCC_TOP
$Comp
L GNDD #PWR05
U 1 1 5B81F5BC
P 8840 2625
F 0 "#PWR05" H 8840 2375 50  0001 C CNN
F 1 "GNDD" H 8840 2475 50  0000 C CNN
F 2 "" H 8840 2625 50  0001 C CNN
F 3 "" H 8840 2625 50  0001 C CNN
	1    8840 2625
	0    1    1    0   
$EndComp
Text Label 9120 2725 2    60   ~ 0
MOSI
Text Label 9120 2825 2    60   ~ 0
CLK
Wire Wire Line
	9120 2525 9225 2525
Wire Wire Line
	9120 2725 9225 2725
Wire Wire Line
	9120 2825 9225 2825
Wire Wire Line
	9225 2625 8840 2625
$Comp
L R R1
U 1 1 5B875203
P 8270 3370
F 0 "R1" V 8350 3370 50  0000 C CNN
F 1 "10K" V 8270 3370 50  0000 C CNN
F 2 "RES:R_0603" V 8200 3370 50  0001 C CNN
F 3 "" H 8270 3370 50  0001 C CNN
	1    8270 3370
	0    1    1    0   
$EndComp
Wire Wire Line
	8420 3370 8555 3370
Text HLabel 10025 3390 0    60   Input ~ 0
BATT_TOP_sh
Text HLabel 10025 3490 0    60   Input ~ 0
RGB_EN_TOP_sh
Text HLabel 10025 3590 0    60   Input ~ 0
CLK_sh
Text HLabel 10025 3690 0    60   Input ~ 0
MOSI_sh
Text HLabel 10025 3790 0    60   Input ~ 0
GND_sh
$EndSCHEMATC
