#include <REGX51.H>
#include <INTRINS.h>

// 写一个可以调用的函数
typedef unsigned int u16;
typedef unsigned char u8;

// 延时函数
void delay_ms(u16 ms)
{
    u16 i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 255; j++); // 增加循环次数以提高延时精度
}
 

int main()
{
	u8 led = 0x01;
	while(1)
	{
		P2 = ~led;
		led |= led <<1;
		delay_ms(500);
		if(led == 0xFF)
		{
			P2 = ~led;
			led = 0x01;
			delay_ms(500);
		}
	}
}