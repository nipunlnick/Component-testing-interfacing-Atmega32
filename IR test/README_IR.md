# IR Sensor and LED Control with Atmega32

## Overview

This project demonstrates how to interface an IR sensor with an Atmega32 microcontroller to detect obstacles and control an LED based on the sensor's input. The IR sensor detects obstacles in its path, and when an obstacle is detected, the microcontroller turns on the LED. The code is designed to be simple, efficient, and easily understandable, making it suitable for beginners and those looking to implement basic sensor interfacing.

## Hardware Requirements

- **Atmega32 Microcontroller**
- **IR Sensor Module**
- **LED**
- **Resistors (as needed)**
- **Connecting Wires**
- **Breadboard or PCB**

## Circuit Diagram

- **IR Sensor:**
  - VCC to 5V
  - GND to GND
  - Output to PD3 (IR_SENSOR_PIN)
  
- **LED:**
  - Anode (+) to PD7 (LED_PIN)
  - Cathode (-) to GND (through a resistor)

## Code Explanation

The code initializes the IR sensor and LED pins and continuously checks the sensor input. If the sensor detects an obstacle, the LED is turned on; otherwise, it remains off.

### Code Breakdown

- **F_CPU**: Defines the CPU clock speed, which is set to 8MHz.
- **IR_SENSOR_PIN**: Defines the pin where the IR sensor is connected (PD3).
- **LED_PIN**: Defines the pin where the LED is connected (PD7).
- **initIRSensor()**: Initializes the IR sensor pin as input with a pull-up resistor enabled.
- **isObstacleDetected()**: Checks if an obstacle is detected by reading the sensor pin.
- **initLED()**: Initializes the LED pin as output.
- **main()**: The main loop continuously checks for obstacles and controls the LED accordingly.

## How to Run

1. **Set up the hardware** according to the circuit diagram.
2. **Flash the provided code** onto the Atmega32 microcontroller using an AVR programmer or any suitable method.
3. **Power up the circuit**. The LED will turn on when the IR sensor detects an obstacle.

## Future Improvements

- Add more sensors or modules to expand the project.
- Implement a more complex decision-making process based on multiple sensor inputs.

## License

This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for more details.

## Contact

For any queries or further assistance, feel free to reach out via [LinkedIn](https://www.linkedin.com/in/pvnipunlakshitha/).
