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
/**
 * @brief  根据按键按下情况实行操作，放在主函数While循环中即可
 * @param  None
 * @retval None
 */
void Key_Execute()
{
	for (uint8_t j = 0; j < 4; j++)
	{
		if (Keys[j].Key_Single_Flag == 1)
		{
			Keys[j].Key_Single_Flag = 0;
			sprintf(text, "Key%dDown\r\n", j + 1);
			UsartPrintf(USART_DEBUG, text);
			// 根据单击键值进行操作
			switch (j + 1)
			{
			// 按键1
			case 1:
			{
				key_msg.id = 0;
				key_msg.pressed = true;
			}
			break;
			// 按键2
			case 2:
			{
				key_msg.id = 1;
				key_msg.pressed = true;
			}
			break;
			// 按键3
			case 3:
			{
				key_msg.id = 2;
				key_msg.pressed = true;
			}
			break;
			// 按键4
			case 4:
			{
				// Control_SetThresholds(value1);
			}
			break;
			}
		}
		if (Keys[j].Key_Double_Flag == 1)
		{
			Keys[j].Key_Double_Flag = 0;
			sprintf(text, "Key%dDoubleDown\r\n", j + 1);
			UsartPrintf(USART_DEBUG, text);
			// 根据双击键值进行操作
			switch (j + 1)
			{
			// 按键1
			case 1:
			{
			}
			break;
			// 按键2
			case 2:
			{
			}
			break;
			// 按键3
			case 3:
			{
			}
			break;
			// 按键4
			case 4:
			{
			}
			break;
			}
		}
		if (Keys[j].Key_Long_Flag == 1)
		{
			Keys[j].Key_Long_Flag = 0;
			sprintf(text, "Key%dLongDown\r\n", j + 1);
			UsartPrintf(USART_DEBUG, text);
			// 根据长按键值进行操作
			switch (j + 1)
			{
			// 按键1
			case 1:
			{
				LED2_Turn();
				lightControl.ENV_free = Free_Value;
			}
			break;
			// 按键2
			case 2:
			{
				Servo_Turn();
				Co2Control.ENV_free = Free_Value;
			}
			break;
			// 按键3
			case 3:
			{
				relay1_Turn();
				Co2Control.ENV_free = Free_Value;
			}
			break;
			// 按键4
			case 4:
			{
				relay2_Turn();
				soilHumControl.ENV_free = Free_Value;
			}
			break;
			}
		}
	}
}
