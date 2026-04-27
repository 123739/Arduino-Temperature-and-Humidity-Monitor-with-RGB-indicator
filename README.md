# Arduino Temperature & Humidity Monitor with RGB Indicator

This project uses an **Arduino Uno**, **DHT11 sensor**, and a **16x2 I2C LCD display** to measure and display real-time temperature and humidity. An **RGB LED** provides a visual indication of temperature ranges.

---

## Features

* Real-time temperature and humidity monitoring
* Display readings on 16x2 LCD (I2C)
* RGB LED temperature indication:

  * Red → Temperature > 40°C
  * Blue → Temperature between 30°C and 40°C
  * Green → Temperature < 30°C
* Serial Monitor output for debugging
* Error handling for sensor failures

---

## Components Required

* Arduino Uno
* DHT11 Temperature & Humidity Sensor
* 16x2 LCD Display with I2C module
* RGB LED
* 3 × 220Ω resistors (for RGB LED)
* Jumper wires
* Breadboard

---

## Circuit Connections

### DHT11 Sensor

| Pin  | Connection    |
| ---- | ------------- |
| VCC  | 5V            |
| GND  | GND           |
| DATA | Digital Pin 2 |

---

### LCD (I2C)

| Pin | Connection |
| --- | ---------- |
| VCC | 5V         |
| GND | GND        |
| SDA | A4         |
| SCL | A5         |

---

### RGB LED

| Color | Arduino Pin |
| ----- | ----------- |
| Red   | Pin 8       |
| Green | Pin 9       |
| Blue  | Pin 10      |

> Use 220Ω resistors for each LED pin to prevent damage.

---

## Libraries Used

Install the following libraries via Arduino IDE:

* DHT sensor library by Adafruit
* Adafruit Unified Sensor
* LiquidCrystal_I2C

---

## How It Works

1. The DHT11 sensor reads temperature and humidity.
2. Values are:

   * Displayed on the LCD
   * Printed to the Serial Monitor
3. Based on temperature:

   * RGB LED changes color:

     * High → Red
     * Medium → Blue
     * Low → Green

---

## Logic for RGB LED

```cpp
if (temperature > 40) {
  // Red ON
}
else if (temperature >= 30 && temperature <= 40) {
  // Blue ON
}
else {
  // Green ON
}
```

---

## Troubleshooting

* LCD not displaying?

  * Try changing I2C address (0x27 → 0x3F)
  *  If you're using a I2C converter, the conventional LiquidCrystal libraries available on Arduino IDE might fail to work. In that case, kindly install the library provided in the drivelink.
  *  Also, upload the i2c_scanner file first, before uploading the code for humidity_temp for lcd display to work.

* Sensor error?

  * Check wiring
  * Ensure correct libraries installed
  
* LED not working?

  * Check resistor connections
  * Verify if LED is common anode/cathode

---

## Future Scope

* IoT integration (upload data to cloud)
* Mobile app monitoring
* Temperature alert system (buzzer/notifications)
* Data logging and analytics
* Energy-efficient smart environment systems

---

## Output

* LCD shows:

  ```
  Temp: XX C
  Hum: XX %
  ```
* RGB LED changes color based on temperature range

## Author

Anwesha Rath
