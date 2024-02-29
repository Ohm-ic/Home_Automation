
# ESP32 Home Automation System

This project utilizes an ESP32 microcontroller to automate home tasks such as regulating LED brightness and buzzing an alarm clock based on time. The microcontroller connects to Wi-Fi, retrieves time information from an NTP server, and performs actions accordingly.

## Features

- Regulates LED brightness based on the time of day (evening dimming).
- Turns off LED after a certain time.
- Buzzes an alarm at a specified time.
- Connects to Wi-Fi to fetch time from an NTP server.

## Requirements

- ESP32 microcontroller
- LED and appropriate resistor
- Buzzer
- Wi-Fi connection
- Arduino IDE or PlatformIO with ESP32 support
- Libraries:
  - WiFi.h
  - NTPClient.h
  - WiFiUdp.h

## Installation

1. Set up your ESP32 development environment.
2. Connect the LED to GPIO 2 and the buzzer to GPIO 4.
3. Install the required libraries: WiFi.h, NTPClient.h, and WiFiUdp.h.
4. Update the Wi-Fi credentials in the code.
5. Upload the code to your ESP32 board.

## Usage

1. The system automatically connects to Wi-Fi upon startup.
2. It retrieves time information from an NTP server.
3. LED brightness is adjusted based on the time of day (5 pm to 9 pm).
4. The LED turns off after 9 pm.
5. The alarm buzzes at 6 am.

## Configuration

- You can adjust the GPIO pins for the LED and buzzer by modifying the `LED_PIN` and `BUZZER_PIN` constants in the code.
- Change the timezone offset in seconds in the `utcOffsetInSeconds` constant if necessary.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Inspired by home automation projects and ESP32 capabilities.
- Thanks to the contributors of the WiFi and NTPClient libraries.

---
