# VL6180X SPI Interface

This library provides an SPI interface for the VL6180X time-of-flight sensor. It includes functions to initialize the sensor, read the range, and check sensor status.

## Features

* SPI communication protocol
* Read distance in millimeters
* Check sensor status

## Hardware Connections

* VCC → 3.3V/5V
* GND → GND
* MISO → MISO (Arduino)
* MOSI → MOSI (Arduino)
* SCK → SCK (Arduino)
* CS → Digital Pin (User-defined)

## Usage

1. Include the header file:

   ```cpp
   #include "VL6180X_SPI.h"
   ```
2. Create an instance and initialize:

   ```cpp
   VL6180X_SPI sensor(10);
   sensor.begin();
   sensor.configureSensor();
   ```
3. Read distance:

   ```cpp
   uint8_t distance = sensor.readRange();
   ```

## Dependencies

* SPI.h

## License

MIT License
