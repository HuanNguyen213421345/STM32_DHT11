#include "dht11_lib.h"
#include "stm32f1xx_hal.h"

extern TIM_HandleTypeDef htim1;

#define pin_dht11_Pin GPIO_PIN_0
#define pin_dht11_GPIO_Port GPIOA

uint8_t chuc, dv;
uint8_t data_read[5] = {0,0,0,0,0};
void delay_us(uint32_t us)
{
	__HAL_TIM_SET_COUNTER(&htim1,0);
	HAL_TIM_Base_Start(&htim1);
	while(__HAL_TIM_GET_COUNTER(&htim1) < us);
	HAL_TIM_Base_Stop(&htim1);
}

void delay_ms(uint32_t ms)
{
	for(int i = 0; i< ms; i++)
	{
		delay_us(1000);
	}
}

void gpio_input()
{
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pin = pin_dht11_Pin;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(pin_dht11_GPIO_Port, &GPIO_InitStruct);
}

void gpio_output()
{
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pin = pin_dht11_Pin;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(pin_dht11_GPIO_Port, &GPIO_InitStruct);
}

void dht11_rst()
{
	gpio_output();
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
	delay_ms(20);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
	delay_us(30);
}

uint8_t check_dht11()
{

	uint8_t time = 0;
	gpio_input();
	while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1 && time < 100)
	{
		time++;
		delay_us(1);
	}
	if(time > 80) return 1;
	else time = 0;

	while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 0 && time < 100)
	{
		time++;
		delay_us(1);
	}
	if(time > 80) return 1;
	else return 0;
}

uint8_t read_bit_dht11()
{
	uint8_t time =0;
	while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1 && time < 100)
	{
		time++;
		delay_us(1);
	}
	time = 0;
	while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 0 && time < 100)
	{
		time++;
		delay_us(1);
	}
	delay_us(40);

	if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)) return 1;
	else return 0;
}

uint8_t read_byte_dht11()
{
	uint8_t i;
	uint8_t data =0;
	for(i = 0; i < 8; i++)
	{
		data = data << 1;
		data |= read_bit_dht11();
	}
	return data;
}

void read_data_dht11()
{
	uint8_t i;
	dht11_rst();

	if(check_dht11() == 0)
	{
		for(i=0;i<8;i++)
		{
			data_read[i] = read_byte_dht11();
		}
	}
}

uint8_t dht11_init()
{
	gpio_output();
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
	dht11_rst();
	return check_dht11();
}

uint8_t char_to_num(uint8_t num)
{
	chuc = (num%100)/10;
	dv = (num%100)%10;
}






