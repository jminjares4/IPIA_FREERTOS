# **Intelligent Portable Infrasound Array (IPIA)** :zap:

## **Description**
This is the source code of our capstone project for Electrical and Computer Engineering department at `University of Texas at El Paso` *`(UTEP)`*. 

## **Team Members**
- [Erick A Baca](https://github.com/eabaca2419)
  - Hardware testing and system integration
- [Jesus Minjares](https://github.com/jminjares4)
  - Embedded software and firmware testing
- Cynthia Oaxaca
  - Power System
- Mariano Urbina
  - Hardware design  

## **Table of Contents**
* [Firmware](https://github.com/jminjares4/IPIA_FREERTOS/tree/main/Firmware)
  * drivers
  * inc
  * ipia.c
  * main_freertos.c
* [Hardware](https://github.com/jminjares4/IPIA_FREERTOS/tree/main/Hardware)
  * schematic1.0.sch
  * images
* [Media](https://github.com/jminjares4/IPIA_FREERTOS/tree/main/media)
  * gif
  * images
  * video
* Readme

## **Requirements**
- [x] Firmware running at real-time 
- [x] Read pressure sensor at 100hertz
- [x] Wireless communication between two MCUs 
- [x] Capture system location using a GPS
- [x] Time stamp capture data
- [x] Solar tracker to find optimal postion for the battery charger 

## **IPIA Data Capture**
To visualize the data that was being capture, a python script was develop that reads the data being transmitted via the wireless communication. 
The script uses `pyserial` and `matplotlib` packages to send the capture data from the `HC-05 Module` and store it into a csv file. Here is small demostration.

<img src="media/gif/ipia_reading.gif">

* [Jesus Minjares Python Script](https://github.com/jminjares4/Plotting-Sensor-Data)
## **Solar Tracker**
<img src="media/gif/solarTracker.gif" height="750" width="500">

## **Software**
![](https://img.shields.io/badge/Code-C-informational?style=flat&logo=C&color=003B57)
![](https://img.shields.io/badge/Code-Python-informational?style=flat&logo=Python&color=764ABC)

## **Microcontroller**
![Texas Instruments](https://img.shields.io/static/v1?label=&message=MSP432&color=696969&logoWidth=30&logo=data:image/png;base64,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)

## **Software Development**
![Texas Instruments](https://img.shields.io/static/v1?label=Software&message=Code%20Composer%20Studio&color=red&logoWidth=30&logo=data:image/png;base64,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)

## **Acknowledgements**
- **Dr. Hector Erives** :zap:
  - Senior project I & II Sponsor
- ECE Department (UTEP) :zap:

## **Authors**
- [Jesus Minjares](https://github.com/jminjares4)
  - Bachelor of Science in Electrical Engineering

### **License**
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

### *Latest Version*
[![version](https://img.shields.io/badge/release-v1.0.0--ipia--fall--2020-red)](https://github.com/jminjares4/IPIA_FREERTOS/releases)



