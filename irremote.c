#include <esp8266.h>
#include <espressif/esp_common.h>
#include "irremote.h"

uint8_t ir_gpio_pin;
uint16_t frequency;

void ir_set_pin(uint8_t pin) {
  ir_gpio_pin = pin;
}

void ir_set_frequency(uint16_t khz) {
  frequency = 1000 / khz;
}

void ir_mark(uint16_t time) {
  uint32_t start = sdk_system_get_time();

  while(sdk_system_get_time() - start < time) {
    gpio_write(ir_gpio_pin, 1);
    sdk_os_delay_us(frequency);
    gpio_write(ir_gpio_pin, 0);
    sdk_os_delay_us(frequency);
  }
}

void ir_space(uint16_t time) {
  gpio_write(ir_gpio_pin, 0);

  if (time > 0) {
    sdk_os_delay_us(time);
  }
}

void ir_send_raw(uint16_t buffer[], uint16_t bufferSize, uint16_t hz) {
  ir_set_frequency(hz);

  uint16_t i;

  for (i = 0; i < bufferSize; i++) {
    if (i & 1) {
      ir_space(buffer[i]);
    } else {
      ir_mark(buffer[i]);
    }
  }

  ir_space(0);
}