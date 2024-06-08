#include "stm32f10x.h" // Device header
#include "stdio.h"
#include <string.h>
#include "Delay.h"
// 硬件驱动
#include "Key.h"
#include "LED.h"
#include "usart.h"

#include "OLED.h"

struct Keys_Struct Keys[4];

char text[30];

struct KEY_MSG key_msg = {0, false};

/**
 * @brief  按键初始化，按键一端接单片机引脚，一端接GND
 * @param  None
 * @retval None
 */
void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	for (uint8_t j = 0; j < 4; j++)
	{
		Keys[j].Step = 0;

		Keys[j].Key_Single_Flag = 0;

		Keys[j].Key_Double_Flag = 0;

		Keys[j].Key_Long_Flag = 0;

		Keys[j].Time_Count_Flag = 0;

		Keys[j].Press_Time_Count = 0;
	}
}




