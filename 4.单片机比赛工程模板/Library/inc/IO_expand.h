



#ifndef _IO_EXPAND_H_
#define _IO_EXPAND_H_

#include "STC12C5A60S2.H"      //����ͷ�ļ�

  #ifndef uchar
	#define uchar unsigned char
  #endif

  #ifndef uint
	#define uint  unsigned int
  #endif


//74HC595 ���Ŷ���
sbit SH_CP=P1^5;  //ʱ��        
sbit ST_CP=P1^6;  //�����ظ�������       
sbit DS=P1^7;	  //����

//74HC138 ���Ŷ���
sbit HC138_A=P1^0;       
sbit HC138_B=P1^1;        
sbit HC138_C=P1^2; 
sbit HC138_EN=P1^3;


extern void delay(uint time); 

//**************************************************************************************************
//��74HC595дһ�ֽ�����
//**************************************************************************************************
extern void wbyte_595(uchar temp);

//**************************************************************************************************
//��74HC138дλѡ���� 0��7  ����7�ر�
//**************************************************************************************************
extern void wbyte_138(uchar temp);

#endif