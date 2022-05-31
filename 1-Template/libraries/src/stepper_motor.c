


#include "stepper_motor.h"

/*******************************************************************************
* ��    ��       : Dir 1:��ת   0:��ת
* ��    ��    	 : ��
 ��ÿִ��һ��ת��һ���Ƕȣ�ִ�м��ʱ������ٶȣ��ɷ��ڶ�ʱ�жϣ��ı��ж�ʱ��

*******************************************************************************/
void stepper_motor(uchar Dir)
{	
	static uchar phase=0;

	switch(phase)
	{
	case(0):
		MOTOA = 1;
		MOTOB = 0;
		MOTOC = 0;
		MOTOD = 0;
		break;

	case(1):
		MOTOA = 0;
		MOTOB = 1;
		MOTOC = 0;
		MOTOD = 0;
		break;

	case(2):
		MOTOA = 0;
		MOTOB = 0;
		MOTOC = 1;
		MOTOD = 0;
		break;

	case(3):
		MOTOA = 0;
		MOTOB = 0;
		MOTOC = 0;
		MOTOD = 1;
		break;
	}

	if(Dir==1)
		phase++;
	else if(Dir==0)
		phase--;
	
	if(phase>3)
		phase=0;
	else if(phase<0)
		phase=3;
}


