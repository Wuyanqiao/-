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
	u16 a = 10;
	while(a--)
	{
		P2 = 0x0A;  // 0000 1010
	}
	delay_ms(500);
	P2 = 0xA0;  // 1010 1010
	delay_ms(500);	
}