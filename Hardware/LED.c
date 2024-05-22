#include "stm32f10x.h" // Device header
#include "LED.h"

/**
 * @brief  LED初始化
 * @param  None
 * @retval None
 */
void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_LED2 | GPIO_LED1 | GPIO_LED3;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_SetBits(GPIOA, GPIO_LED2 | GPIO_LED1 | GPIO_LED3);
}

/**
 * @brief  LED1开,LED警报灯
 * @param  None
 * @retval None
 */
void LED1_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_LED1);
}

/**
 * @brief  LED1关
 * @param  None
 * @retval None
 */
void LED1_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_LED1);
}

/**
 * @brief  LED1状态转换
 * @param  None
 * @retval None
 */
void LED1_Turn(void)
{
	if (GPIO_ReadInputDataBit(GPIOA, GPIO_LED1) == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_LED1);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_LED1);
	}
}

/**
 * @brief  LED2开，照明灯
 * @param  None
 * @retval None
 */
void LED2_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_LED2);
}

/**
 * @brief  LED2关
 * @param  None
 * @retval None
 */
void LED2_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_LED2);
}

/**
 * @brief  LED2状态转换
 * @param  None
 * @retval None
 */
void LED2_Turn(void)
{
	if (GPIO_ReadInputDataBit(GPIOA, GPIO_LED2) == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_LED2);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_LED2);
	}
}

/**
 * @brief  LED3开，警报灯
 * @param  None
 * @retval None
 */
void LED3_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_LED3);
}

/**
 * @brief  LED3关
 * @param  None
 * @retval None
 */
void LED3_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_LED3);
}

/**
 * @brief  LED3状态转换
 * @param  None
 * @retval None
 */
void LED3_Turn(void)
{
	if (GPIO_ReadInputDataBit(GPIOA, GPIO_LED3) == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_LED3);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_LED3);
	}
}
