/**************************************************************************************
*		              �������ʵ��												  *
ʵ���������س���󣬰��չ����ڲ�����Ƶ���ߣ����������ת
ע�������																				  
***************************************************************************************/

#ifndef _STEPPER_MOTOR_H_
#define _STEPPER_MOTOR_H_

#include "STC12C5A60S2.H"      //����ͷ�ļ�

  #ifndef uchar
	#define uchar unsigned char
  #endif

  #ifndef uint
	#define uint  unsigned int
  #endif

sbit MOTOA = P1^0;
sbit MOTOB = P1^1;
sbit MOTOC = P1^2;
sbit MOTOD = P1^3; 	


extern void stepper_motor(uchar Dir);


#endif
