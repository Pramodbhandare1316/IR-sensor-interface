# IR-sensor-interface with NodeMCU ESP8266

This project demonstrates how to interface an IR (Infrared) sensor with NodeMCU ESP8266 microcontroller board. 
The NodeMCU ESP8266 reads data from the IR sensor and send it to a web server for visualization and monitoring.

- [Overview](#overview)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Installation](#installation)
- [Connections](#connections)
- [Circuit Diagram](#circuit-diagram)
- [Project Flow](#project-flow)
- [Summary](#summary)



## Overview
In this project, an IR sensor is used to detect infrared radiation emitted by an object in its field of view. The NodeMCU ESP8266 captures the signal from the IR sensor and processes it to detect motion or any other relevant data. The captured data is then sent to a web server for further processing or visualization.

## Hardware Requirements

- NodeMCU ESP8266 development board
- IR sensor module (e.g., HC-SR501)
- Jumper wires
- Breadboard

## Software Requirements

- vscode (PlatformIO IDE )
- Proteus ( Proteus 8 Professional )
- NodeMCU board support for Arduino IDE
- Thinkspeak
- Required libraries (e.g., ESP8266WiFi, ESP8266HTTPClient ,Thinkspeak)

  ## Installation

  **i.Set Up Software Setup :**
 - Install the VScode from [vscode.cc](https://code.visualstudio.com/download).
 - Install PlatformIO Extension Or C and C++ Extension.
 - Creat the new project
 - select the ESP8266 NodeMCU board
 - Install  required librarie

#### ii.Thingspeak  Setup
 - open Thingspeak
 - Creat new channel
 - select  no of fields required
 - Add api key and and chnnel no in source code

  #### iii.Wifi Setup
 - Turn on the Wifi
 - Add SSID and passward in source code


  ## Connections
  
- Connect the VCC pin of the IR sensor to 3.3V (or 5V) on NodeMCU ESP8266.
- Connect the GND pin of the IR sensor to GND on NodeMCU ESP8266.
- Connect the OUT pin of the IR sensor to GPIO pin D1 (GPIO5) on NodeMCU ESP8266.

  ## Circuit Diagram
  ![Circuit Diagram](./Image/IRSensor.jpg)

## Project Flow

Start

1. Initialize NodeMCU ESP8266 and IR sensor
   - Power up NodeMCU ESP8266
   - Connect IR sensor to NodeMCU ESP8266

2. Connect to WiFi network
   - Attempt to connect to predefined WiFi network
   - If connection successful, proceed to next step
   - If connection fails, retry connection

3. Read data from IR sensor
   - Wait for motion detection signal from IR sensor
   - If motion detected, proceed to next step
   - If no motion detected, continue waiting

4. Send data to ThingSpeak
   - Format data (e.g., motion detected timestamp)
   - Establish HTTP connection to ThingSpeak server
   - Transmit data to ThingSpeak channel
   - If data sent successfully, proceed to next step
   - If data transmission fails, retry transmission

5. Check for acknowledgment
   - Receive acknowledgment from ThingSpeak server
   - If acknowledgment received, log success
   - If acknowledgment not received, log failure

6.  Repeat process
   - Return to step 3 to continue monitoring IR sensor

 7. Output
   thinkspeak link - (https://api.thingspeak.com/channels/2588151/feeds.json?api_key=AALE8S2V8Z18HHQZ&results=2)

## Summary

 Interface an IR sensor with NodeMCU ESP8266 to detect motion and send data to ThingSpeak for remote monitoring and analysis.Connect IR sensor VCC to 3.3V/5V, GND to ground, OUT to a digital pin on NodeMCU (e.g., D1).Initialize WiFi connection and continuously monitor IR sensor for motion detection.Format data (e.g., timestamp) for ThingSpeak.Send HTTP POST request to ThingSpeak API with data.The ThingSpeak Integration  is view and analyze data on ThingSpeak dashboard.Utilize ThingSpeak capabilities for real-time monitoring and historical analysis.
 
 

     

  
  
