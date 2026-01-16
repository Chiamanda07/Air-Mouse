# Air-Mouse
It is just like your casual computer mouse, except it doesn't actually need a USB cord and is wireless. It's connected to your laptop using Bluetooth and pretends to be a normal mouse using HID (Human Interface Device). It's connected to your laptop using Bluetooth and pretends to be a normal mouse using HID (Human Interface Device). It has 1 button and can be used to scroll, and .

---
## Components
- ESP32
- MPU6050
- 1 Push Button
- LiPo Battery (3.7V)
- TP4056 Charger
- Power Switch
- Wires + Breadboard

---

## TinkerCad
Before fleshing out the circuit, I made a [TinkerCad circuit](https://www.tinkercad.com/things/fCuXMns8fIN-air-mouse-simulation?sharecode=EPAM1r4ufd7JlZj-CBQMTo9suULBRHwCPn_ASLRwwXA). Instead of using and ESP32 for this I used an arduino and instead of a MPU6050(which would contol cursor movement), I used potentiometers. 

---

## Code 
[Sample code]
The main libraries that I used before I started are: 
- ESP32 BLE Mouse by T-vK (From [this github](https://github.com/T-vK/ESP32-BLE-Mouse?))
- MPU6050 by Electronic Cats
