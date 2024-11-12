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
        for (j = 0; j < 255; j++); // ����ѭ�������������ʱ����
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