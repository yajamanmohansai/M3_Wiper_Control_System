/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
#include "MyStm32f407xx.h"
#include <stdint.h>
#include <stdio.h>
#define But_PRESSED ENABLE

void delay(void);
void igniton_on(void);
void igniton_off(void);
void Clockwise(void);
void wiper_off(void);
int main(void)
{
	
	GPIO_Handle_t GpioL, GpioL1, GpioL2, GpioL3, GpioBut;

	
	GpioL.pGPIOx = GPIOD;
	GpioL.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioL.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioL.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioL.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioL);

	
	GpioL1.pGPIOx = GPIOD;
	GpioL1.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GpioL1.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioL1.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioL1.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioL1);

	
	GpioL2.pGPIOx = GPIOD;
	GpioL2.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	GpioL2.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioL2.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioL2.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioL2);

	
	GpioL3.pGPIOx = GPIOD;
	GpioL3.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
	GpioL3.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioL3.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioL3.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioL3);

	
	GpioBut.pGPIOx = GPIOA;
	GpioBut.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GpioBut.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GpioBut.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioBut.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GpioBut);

	uint32_t flag = 0;
	uint32_t key_pressed = 0;  /

	while (1)                                                           
	{
		GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_0, DISABLE);
		if (GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == ENABLE)
		{

			delay();
			flag++;
			if ((flag == 1) && (key_pressed != 1) && (key_pressed != 2) && key_pressed != 3)
			{
				igniton_on();
				key_pressed = flag;
				flag = 0;
			}
			else if ((flag == 2) && (key_pressed != 2) && key_pressed != 3)
			{
				igniton_off();
				key_pressed = flag;
				flag = 0;
			}
			else if ((flag == 3) && key_pressed != 3)
			{
				Clockwise();
				key_pressed = flag;
				flag = 0;
			}
			else if (flag == 4) 
			{
				wiper_off();
				key_pressed = flag;
				flag = 0;
			}
		}
	}
}
void delay(void)
{
	for (uint32_t i = 0; i < 50000000; i++)
		;
}

void igniton_on(void)
{
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
}

void wiper_on(void) 
{
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,0 );

	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,0 );

	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 0);

	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,0 );
}

void wiper_off(void) 
{
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, 0);

	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,0 );

	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 0);

	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, 0);
}
void igniton_off(void) 
{
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, 0);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, 0);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 0);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, 0);
}