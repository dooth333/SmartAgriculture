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

/**
 * @brief  DHT11模块起始信号函数
 * @param  None
 * @return 1或0，标志起动信号成功与否
 */
uint8_t DHT_Start(void)
{
    DHT_GPIO_Init(GPIO_Mode_Out_PP); // 输出模式

    GPIO_ResetBits(DHT_GPIO_PORT, DHT_GPIO_PIN); // 输出20ms低电平后拉高
    Delay_ms(20);
    // delay_ms(20);
    GPIO_SetBits(DHT_GPIO_PORT, DHT_GPIO_PIN);

    DHT_GPIO_Init(GPIO_Mode_IN_FLOATING); // 输入模式
    Delay_us(20);
    //	delay_us(20);

    if (!GPIO_ReadInputDataBit(DHT_GPIO_PORT, DHT_GPIO_PIN))
    {
        while (!GPIO_ReadInputDataBit(DHT_GPIO_PORT, DHT_GPIO_PIN))
            ;
        while (GPIO_ReadInputDataBit(DHT_GPIO_PORT, DHT_GPIO_PIN))
            ;
        return 1;
    }
    return 0;
}

/**
 * @brief  接收DHT11发送来8位的数据
 * @param  None
 * @return 返回接收到的8位数据
 */
uint8_t DHT_Get_Byte_Data(void)
{
    uint8_t temp;
    for (int i = 0; i < 8; i++)
    {
        temp <<= 1;
        while (!GPIO_ReadInputDataBit(DHT_GPIO_PORT, DHT_GPIO_PIN))
            ;
        Delay_us(28);
        GPIO_ReadInputDataBit(DHT_GPIO_PORT, DHT_GPIO_PIN) ? (temp |= 0x01) : (temp &= ~0x01);
        while (GPIO_ReadInputDataBit(DHT_GPIO_PORT, DHT_GPIO_PIN))
            ;
    }
    return temp;
}