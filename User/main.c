#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "DS18B20.h"
#include <stdio.h>
#include "usart.h"

float wendu;
char  Wendu_Buf[20];
int main(void)
{
	OLED_Init();
	DS18B20_Init();
	Usart1_Init(115200);//debug´®¿Ú
	OLED_ShowString(2, 1, "wendu:");	
	while (1)
	{
		wendu = DS18B20_Get_Temp();
		sprintf(Wendu_Buf,"wendu:%4.2f\r\n",wendu);
		UsartPrintf(USART_DEBUG, Wendu_Buf);
		OLED_ShowNum(1,1,wendu,4);
		Delay_ms(500);
	}
}
