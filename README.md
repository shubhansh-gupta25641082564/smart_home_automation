# Smart Home Automation

Welcome to the *Smart Home Automation* project! This innovative IoT solution aims to bring convenience and efficiency to home management through advanced automation and real-time monitoring. Our project allows users to control home appliances both manually and remotely, enhancing comfort and security.

## Project Overview

The Smart Home Automation system enables users to control lights, fans, and doors using both physical push buttons and a custom-built website. The system also provides real-time monitoring capabilities via the website, ensuring that users can manage their home environment from anywhere.

## Features

### 1. *Remotely Controlled Lights and Fans*
Control lights and fans from anywhere using our user-friendly website. This feature ensures convenience and energy efficiency by allowing remote access to home appliances.

### 2. *Automatic Door*
An ultrasonic sensor and a servo motor automate the door, providing hands-free access and enhanced security.

### 3. *Real-Time Monitoring*
Monitor the status of lights, fans, and doors in real-time using our website. This feature keeps users informed about their home environment at all times.

## Components Used

- *Node MCU ESP8266:* Main microcontroller for managing the automation system.
- *8-Channel Relay:* Controls the power to lights and fans.
- *Push Buttons:* Simulate manual switches for lights and fans.
- *Ultrasonic Sensor:* Detects proximity to automate the door.
- *Servo Motor:* Operates the automatic door.
- *Jumper Wires:* Connect components.
- *Breadboard:* Prototype the circuit.
- *Arduino IDE:* Develop and upload code to the microcontroller.
- *Visual Studio Code:* Develop the web interface.

## Technologies Used

- *HTML*
- *CSS*
- *JavaScript*
- *Sketch*

## Installation

### Hardware Setup
1. Connect the Node MCU ESP8266 to the 8-channel relay, push buttons, ultrasonic sensor, and servo motor using jumper wires and a breadboard.
2. Power the Node MCU ESP8266 and other components as needed.

### Software Setup
1. Install the Arduino IDE from the [official website](https://www.arduino.cc/en/Main/Software).
2. Download or clone this repository to your local machine.
3. Open the project file in the Arduino IDE.
4. Upload the code to the Node MCU ESP8266.

## Usage

1. *Manual Control:* Use the push buttons connected to the system to manually control the lights and fans.
2. *Remote Control:* Access the website to remotely control the lights and fans. The website provides an intuitive interface for easy management.
3. *Automatic Door:* The door will automatically open or close based on the ultrasonic sensor's readings.
4. *Real-Time Monitoring:* View the current status of lights, fans, and the door on the website.
