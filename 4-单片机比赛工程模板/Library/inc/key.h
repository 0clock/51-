
/***************************************************************************************************    
�������ƣ�	key

ά����¼��  2011-8-22
***************************************************************************************************/
#ifndef _KEY_H_
#define _KEY_H_

#include "STC12C5A60S2.H"      //����ͷ�ļ�
#ifndef uchar
	#define uchar unsigned char
#endif
#ifndef uint
	#define uint  unsigned int
#endif
#define GPIO_KEY P3

sbit key1=P3^0;
sbit key2=P3^1;
sbit key3=P3^2;
sbit key4=P3^3;

extern uchar KeyValue ; 
extern void Delay_Ms(uint time);
//**************************************************************************************************
//�������ɨ�躯��  ��Ҫdelayms()����
//**************************************************************************************************
extern void KeyDown(void);    
extern unsigned char KeyScan();               
#endif