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
        for (j = 0; j < 255; j++); 
}

 void Delay_10us(u16 time)
 {
	while(time--);
 }
 
void main()
{
	u8 i = 0;
	u16 t = 0;
	P2 = 0xff;    //8个灯全部灭
	while(1)
	{
		for(i = 0; i < 8; i++)
		{
			P2 = ~(0x1 << i); 
			Delay_10us(50000); 
		}
		delay_ms(100);
	}		
}

