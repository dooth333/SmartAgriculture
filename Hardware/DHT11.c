// 单片机头文件
#include "stm32f10x.h"
#include "DHT11.h"
#include "Delay.h"

uint8_t DHT_Buffer[5];
uint8_t humidityH, humidityL, temperatureH, temperatureL;

/**
 * @brief  DHT11_GPIO初始化函数
 * @param  Mode：指定输入或输出模式
 * @return None
 */
void DHT_GPIO_Init(GPIOMode_TypeDef Mode)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(DHT_RCC_PORT, ENABLE);

    GPIO_SetBits(DHT_GPIO_PORT, DHT_GPIO_PIN);

    GPIO_InitStructure.GPIO_Mode = Mode;
    GPIO_InitStructure.GPIO_Pin = DHT_GPIO_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(DHT_GPIO_PORT, &GPIO_InitStructure);
}