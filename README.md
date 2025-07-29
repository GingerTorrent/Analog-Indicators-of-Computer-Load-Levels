
# Analog Computer Load Indicators
This project demonstrates how to display the current computer load on vintage analog voltmeters with a custom scale. The voltmeters are retrofitted to show CPU load levels, and their backlighting changes color using an RGB diode depending on the load intensity.

## Overview

The system reads the CPU load from the computer and converts it into analog signals that drive the old voltmeters. The scale of the meters is modified to correspond with load percentages. Additionally, an RGB lamp provides color-coded feedback to visually indicate the level of CPU usage.

## Hardware Used
- Vintage analog voltmeters
- Arduino board for signal generation
- RGB LED diode for backlighting
- Necessary wiring and power supply

## Software
- Arduino sketch that receives CPU load data and controls voltmeters and RGB lighting
- A PC-side program/script (not included) that measures CPU load and sends the data to the Arduino

## Features
- Real-time analog indication of computer load
- Custom scaling on voltmeters for better readability
- RGB backlighting that changes color based on load level

## Usage
Connect the Arduino to your PC and upload the provided Arduino sketch. Use a compatible program on your computer to send CPU load data to the Arduino, which then updates the meters and lighting accordingly.

## Reference
This project is based on the article published on Habr: [Analog computer load indicators](https://habr.com/en/articles/429582/).

--
