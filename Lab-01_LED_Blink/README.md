# 💡 Lab 01 - LED Blink

## 📌 Overview

This project is the first experiment in my Embedded Systems Lab using the **Arduino Nano 33 BLE Sense**. The objective is to understand the basic structure of an Arduino program by blinking the onboard LED at a fixed interval.

---

## 🎯 Objective

- Learn the Arduino programming structure (`setup()` and `loop()`).
- Understand how to configure digital output pins.
- Blink the onboard LED using the `digitalWrite()` function.
- Upload and test a program on the Arduino Nano 33 BLE Sense.

---

## 🛠 Hardware Used

- Arduino Nano 33 BLE Sense
- USB Cable
- Arduino IDE

---

## 📂 Project Structure

```
Lab-01_LED_Blink/
│── LED_Blink.ino
└── README.md
```

---

## ⚙️ Working Principle

The Arduino initializes the onboard LED pin as an output in the `setup()` function.

Inside the `loop()` function:
1. The LED is turned ON.
2. The program waits for one second.
3. The LED is turned OFF.
4. The program waits for another second.
5. The cycle repeats continuously.

---

## 📋 Code Summary

- `pinMode()` → Configures the LED pin as an output.
- `digitalWrite()` → Turns the LED ON or OFF.
- `delay()` → Creates a time delay between LED state changes.

---

## ▶️ How to Run

1. Connect the Arduino Nano 33 BLE Sense to your computer.
2. Open the Arduino IDE.
3. Select:
   - **Board:** Arduino Nano 33 BLE
   - **Port:** Your connected COM port
4. Open the `LED_Blink.ino` sketch.
5. Click **Upload**.
6. Observe the onboard LED blinking every second.

---

## 📖 Learning Outcomes

After completing this experiment, I learned:

- Arduino program structure
- Uploading code to the board
- Digital output control
- LED blinking using software delays
- Basic embedded programming workflow

---

## 🚀 Future Improvements

- Blink the LED with different patterns.
- Control blinking speed using user input.
- Replace software delays with timers.
- Control multiple LEDs simultaneously.

---

## 👨‍💻 Author

**Sagar Shah**

Embedded Systems Laboratory