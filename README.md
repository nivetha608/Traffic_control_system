# Density Based Traffic Control System

This project is an **intelligent traffic signal controller** that dynamically manages green light timing based on real-time traffic density.  
Using **ultrasonic sensors**, it detects the number of vehicles in each lane and gives priority to lanes with heavier traffic, reducing idle time and improving traffic flow efficiency.

---

## Components Used

- **Arduino Mega 2560** (Main Controller)  
- **4 Ultrasonic Sensors (HC-SR04)** – to detect vehicle presence  
- **8 LEDs** (4 Red, 4 Green) – representing the four traffic signals  
- **Resistors and Jumper Wires**  
- **Breadboard**

---

## Working Principle

Each lane has one ultrasonic sensor.  
When vehicles are detected within a set **threshold distance**, that lane gets the **green signal**, while others remain **red**.  
If no vehicles are detected on any lane, the controller automatically **cycles through all four lanes** to ensure equal signal distribution.

---

## Code Overview

The main logic is written in **`main.ino`**, which:
- Reads distance data from all four ultrasonic sensors  
- Determines which lane to activate based on traffic density  
- Switches LEDs to control red and green signals accordingly  
- Alternates signals when all lanes are clear  

---

## Pin Configuration

| Lane | Red LED | Green LED | Trig Pin | Echo Pin |
|------|----------|------------|-----------|-----------|
| 1 | 23 | 27 | 11 | 10 |
| 2 | 29 | 33 | 7 | 6 |
| 3 | 35 | 39 | 5 | 4 |
| 4 | 41 | 45 | 3 | 2 |

---

## How to Use

1. Connect the LEDs and ultrasonic sensors as per the pin configuration above.  
2. Upload **`main.ino`** to the **Arduino Mega** using the Arduino IDE.  
3. Open the **Serial Monitor** (baud rate: 115200) to view live sensor readings.  
4. Watch how the signal lights change dynamically based on detected vehicle density.


---

## Hardware Setup

All hardware setup and wiring connection images are available inside the **`/hardware`** folder.  

---

## Future Enhancements

- Replace LEDs with **actual traffic lights** controlled via relays  
- Integrate **RFID or camera modules** to detect emergency vehicles  
- Add **IoT capabilities** for cloud monitoring and smart city analytics  

---

## Author

Developed by **Nivetha N**  
Project: **Density Based Traffic Control System (Arduino Mega)**

