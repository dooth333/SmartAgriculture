// 单片机头文件
#include "stm32f10x.h"
#include "DHT11.h"
#include "Delay.h"

uint8_t DHT_Buffer[5];
uint8_t humidityH, humidityL, temperatureH, temperatureL;