
/***************************************************************************************************    
�������ƣ�	smg_scan
����������	���������8λ��̬ɨ����ʾ01234567 
Ӳ�����ӣ�  ��8λ�Ű��߽�J8��J12���ӣ�2λ�Ű��߷ֱ�J11_0��J15_DS1��J11_1��J15_DS2���ӡ�
ά����¼��  2011-8-22
***************************************************************************************************/
#ifndef _DIGITAL_TUBE_H_
#define _DIGITAL_TUBE_H_
#include "STC12C5A60S2.H" 


#ifndef uchar
	#define uchar unsigned char
#endif
#ifndef uint
	#define uint  unsigned int
#endif


#define SMG P1
sbit LE1=P2^0;           //λѡ573������ʹ��
sbit LE2=P2^1;           //��ѡ573������ʹ��
extern uchar wei;
extern void Delay(uint time);
extern void scan(void); //��ʾ1-8
#endif
