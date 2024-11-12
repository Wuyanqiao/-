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
	u16 a = 10;
	while(a--)
	{
		P2 = 0x0A;  // 0000 1010
	}
	delay_ms(500);
	P2 = 0xA0;  // 1010 1010
	delay_ms(500);	
}