#ifndef __IR_REMOTE_H__
#define __IR_REMOTE_H__

void ir_set_pin(uint8_t pin);

void ir_set_frequency(uint16_t frequency);

void ir_mark(uint16_t time);

void ir_space(uint16_t time);

void ir_send_raw(uint16_t buffer[], uint16_t bufferSize, uint16_t frequency);

#endif
