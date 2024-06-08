
#ifndef __Key_H
#define __Key_H
#include "stdbool.h"

void Key_Init(void);
struct Keys_Struct
{
    uint8_t Step;
    uint8_t Key_State;
    uint8_t Key_Single_Flag;  // 单击标志位
    uint8_t Key_Long_Flag;    // 长按标志位
    uint8_t Key_Double_Flag;  // 长按标志位
    uint8_t Time_Count_Flag;  // 计时标志位
    uint8_t Press_Time_Count; // 按下时间计数
};

// 按键信息
struct KEY_MSG
{
    uint8_t id;
    bool pressed;
};

extern struct KEY_MSG key_msg;

extern struct Keys_Struct Keys[4];
#endif
