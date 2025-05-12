#ifndef VL6180X_SPI_H
#define VL6180X_SPI_H

#include <SPI.h>

class VL6180X_SPI {
public:
    VL6180X_SPI(uint8_t csPin);
    void begin();
    uint8_t readRange();
    uint8_t readStatus();
    void configureSensor();

private:
    uint8_t chipSelectPin;
    void writeRegister(uint16_t reg, uint8_t value);
    uint8_t readRegister(uint16_t reg);
};

#endif // VL6180X_SPI_H
