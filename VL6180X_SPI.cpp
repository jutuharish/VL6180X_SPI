#include "VL6180X_SPI.h"

VL6180X_SPI::VL6180X_SPI(uint8_t csPin) : chipSelectPin(csPin) {
    pinMode(chipSelectPin, OUTPUT);
    digitalWrite(chipSelectPin, HIGH);
}

void VL6180X_SPI::begin() {
    SPI.begin();
}

void VL6180X_SPI::configureSensor() {
    // Example configuration (adjust as needed)
    writeRegister(0x0207, 0x01);
    writeRegister(0x0208, 0x01);
}

uint8_t VL6180X_SPI::readRange() {
    return readRegister(0x62);
}

uint8_t VL6180X_SPI::readStatus() {
    return readRegister(0x4F);
}

void VL6180X_SPI::writeRegister(uint16_t reg, uint8_t value) {
    digitalWrite(chipSelectPin, LOW);
    SPI.transfer((reg >> 8) & 0xFF);  // MSB
    SPI.transfer(reg & 0xFF);         // LSB
    SPI.transfer(value);
    digitalWrite(chipSelectPin, HIGH);
}

uint8_t VL6180X_SPI::readRegister(uint16_t reg) {
    digitalWrite(chipSelectPin, LOW);
    SPI.transfer((reg >> 8) & 0xFF);  // MSB
    SPI.transfer(reg & 0xFF);         // LSB
    uint8_t value = SPI.transfer(0);
    digitalWrite(chipSelectPin, HIGH);
    return value;
}
