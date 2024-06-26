/*******************************************************************************
 *
 * @file    main.c
 * @brief   智慧农业大棚整个程序的入口
 * @author  王文超
 * @version 0.0.1
 * @date    2024-03-29
 *
 * -----------------------------------------------------------------------------
 * 备注：
 *
 * 参考资料：
 *
 * -----------------------------------------------------------------------------
 * 文件修改历史：
 * <时间>       | <版本>    | <作者>    | <描述>
 * 2024-03-29   | v0.0.1    |  王文超   | 创建文件
 * -----------------------------------------------------------------------------
 ******************************************************************************/
 
 /*=============================== 头文件包含 =================================*/
/* 系统级头文件 */
#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "DS18B20.h"
#include "AD.h"
#include <stdio.h>
#include "usart.h"
/*============================= 宏定义/重定义 ================================*/

/*================================ 全局变量 ==================================*/
float wendu;
char  Wendu_Buf[20];
/*================================ 接口函数 ==================================*/

/*******************************************************************************
 * @brief   主函数入口
 *
 * @param   无
 *
 * @return  无
 ******************************************************************************/
int main(void)
{
	OLED_Init();
	AD_Init();
	Usart1_Init(115200);//debug串口
	OLED_ShowString(2, 1, "wendu:");	
	while (1)
	{
		Light = (4000-AD_Value[0])/40;	/**> 获取光照强度 */
		soilHumidity = (3000 - AD_Value[1])/12;	/**> 获取土壤湿度 */
		OLED_ShowNum(2, 3, Light, 4);
		OLED_ShowNum(2, 5, soilHumidity, 4);
	}
}
