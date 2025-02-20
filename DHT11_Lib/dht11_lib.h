#ifndef DHT11_LIB_H_
#define DHT11_LIB_H_

#include "stm32f1xx_hal.h"

void delay_us(uint32_t us);
void delay_ms(uint32_t ms);
void gpio_output();
void gpio_input();
void dht11_rst();
uint8_t check_dht11();
uint8_t read_bit_dht11();
uint8_t read_byte_dht11();
void read_data_dht11();
uint8_t dht11_init();
uint8_t char_to_num(uint8_t num);

#endif /* DHT11_LIB_H_ */
