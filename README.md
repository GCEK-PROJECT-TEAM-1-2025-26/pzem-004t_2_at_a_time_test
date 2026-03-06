# PZEM-004T 
2 PZEM-004T used where the 2 split coils are in parallel. Due to which the first pzem-004t show the power equal to the sum of the power outputs from both the loads and the second pzem-004t shows only power output of second load
```
230vc----split_coil_1----|----load-----neutral
                         |
                         ----split_coil_2-----load-----neutral

```
# Solid State Relay (SSR-25DA)
A Solid state realy which is in series with the second load turns on after 10 second from the time when the microcontroller (ESP8266) turns on
-It is coded in such a was there is no sufficient pins for placing any switch in esp8266 microcontroller (A simple issue which will be solved after using esp32 Board)

# Dual AC Power Monitoring & Control System

This project provides a robust solution for monitoring two independent AC loads using a single ESP8266 microcontroller and two PZEM-004T v3.0 power monitoring modules. By utilizing a clever series-coil configuration, the system can derive power consumption for individual loads even when they are on the same supply line.

## Project Overview

### The Problem
Monitoring multiple loads often requires a dedicated sensor per circuit. This project optimizes hardware usage by placing two current transformers (CTs) in series, allowing for the calculation of aggregate and individual load data.

### Verification Methodology
The system architecture uses a strategic series-coil arrangement to validate data precision:
* **Sensor 1 (Aggregate):** Positioned to measure the total combined current of both Load 1 and Load 2.
* **Sensor 2 (Individual):** Positioned to measure only the current of the second load.
* **Accuracy Verification:** This parallel configuration allows for a direct comparison of readings, enabling real-time assessment of sensor consistency and measurement accuracy across both modules.


## SSR Logic & Automation
The system incorporates an **SSR-25DA** to manage the power state of the second load.
* **Initialization:** Upon power-up, the ESP8266 initiates a boot sequence.
* **Delayed Activation:** To ensure stability, the SSR is programmed to toggle "ON" 10 seconds after boot.
* **Hardware Limitations:** Currently, the GPIO constraints of the ESP8266 restrict the ability to add manual user-input switches. Future iterations will utilize an **ESP32** to expand I/O capabilities and add local control functionality.

## Hardware Pinout
| Component | ESP8266 Pin (GPIO) | Logic |
| :--- | :--- | :--- |
| **PZEM-004T #1** | D5 (14) / D6 (12) | RX/TX Communication |
| **PZEM-004T #2** | D1 (5) / D2 (4) | RX/TX Communication |
| **SSR-25DA** | D7 (13) | Output Control |

## Data Output
The system generates telemetry data, which is formatted for serial debugging. Below is the interpretation of the results:

```text
--- Reading Sensor 1 ---
V: 236.0V | A: 0.116A | W: 25.3W | E: 0.004kWh | F: 49.9Hz | PF: 0.92
--- Reading Sensor 2 ---
V: 236.3V | A: 0.195A | W: 38.4W | E: 0.008kWh | F: 49.9Hz | PF: 0.83
----------------------------------------------
