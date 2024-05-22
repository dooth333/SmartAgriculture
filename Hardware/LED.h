#ifndef __LED_H
#define __LED_H

#define GPIO_LED1 GPIO_Pin_0
#define GPIO_LED2 GPIO_Pin_6
#define GPIO_LED3 GPIO_Pin_15

void LED_Init(void);
void LED1_OFF(void);
void LED1_ON(void);
void LED1_Turn(void);
void LED2_Turn(void);
void LED2_OFF(void);
void LED2_ON(void);
void LED3_Turn(void);
void LED3_OFF(void);
void LED3_ON(void);

#endif
