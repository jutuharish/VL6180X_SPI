#include "VL6180X_SPI.h"
#include "pico/stdlib.h"
#include "hardware/spi.h"

#define SPI_PORT spi0
#define SCK_PIN 2
#define MOSI_PIN 3
#define MISO_PIN 4
#define CS_PIN 5

VL6180X_SPI sensor(CS_PIN);

int main() {
    stdio_init_all();
    spi_init(SPI_PORT, 100 * 1000);
    gpio_set_function(SCK_PIN, GPIO_FUNC_SPI);
    gpio_set_function(MOSI_PIN, GPIO_FUNC_SPI);
    gpio_set_function(MISO_PIN, GPIO_FUNC_SPI);
    gpio_init(CS_PIN);
    gpio_set_dir(CS_PIN, GPIO_OUT);
    gpio_put(CS_PIN, 1);

    printf("VL6180X SPI Example\n");

    sensor.begin();
    sensor.configureSensor();

    while (1) {
        uint8_t distance = sensor.readRange();
        uint8_t status = sensor.readStatus();
        printf("Distance: %d mm, Status: %d\n", distance, status);
        sleep_ms(500);
    }
}
