#include <REGX51.H>
#include <INTRINS.h>

// дһ�����Ե��õĺ���
typedef unsigned int u16;
typedef unsigned char u8;

// ��ʱ����
void delay_ms(u16 ms)
{
    u16 i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 255; j++); 
}

 void Delay_10us(unsigned int time)
 {
	while(time--);
 }
 
void main()
{
	unsigned char i = 0;
	unsigned int t = 0;
	P2 = 0xff;    //8����ȫ����
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

