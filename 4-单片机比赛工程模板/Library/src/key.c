
/***************************************************************************************************    
�����ƣ�	key
���ߣ� Jun
���ڣ�  2023-4-21
***************************************************************************************************/
#include "key.h"      //����ͷ�ļ�
uchar KeyValue = 16;



//**************************************************************************************************
//�������ɨ�躯��
//**************************************************************************************************
void KeyDown(void){
	char a=0;
	GPIO_KEY=0x0f;
	if(GPIO_KEY!=0x0f){ //��ȡ�����Ƿ���     
		Delay_Ms(10);//��ʱ10ms��������
		if(GPIO_KEY!=0x0f){//�ٴμ������Ƿ���
			//������
			GPIO_KEY=0X0F;
			switch(GPIO_KEY){
				case(0X07):	KeyValue=0;break;
				case(0X0b):	KeyValue=1;break;
				case(0X0d): KeyValue=2;break;
				case(0X0e):	KeyValue=3;break;
			}
			//������
			GPIO_KEY=0XF0;
			switch(GPIO_KEY){
				case(0X70):	KeyValue=KeyValue;break;
				case(0Xb0):	KeyValue=KeyValue+4;break;
				case(0Xd0): KeyValue=KeyValue+8;break;
				case(0Xe0):	KeyValue=KeyValue+12;break;
			}
			while((a<50)&&(GPIO_KEY!=0xf0)){	 //��ⰴ�����ּ��
				Delay_Ms(10);
				a++;
			}
		}
	}
} 
/**
  * @brief  ��ȡ������������
  * @param  ��
  * @retval ���°����ļ��룬��Χ��0~4���ް�������ʱ����ֵΪ0
  */
unsigned char KeyScan(){
	unsigned char KeyNumber=0;
	if(key1==0){Delay_Ms(20);while(key1==0);Delay_Ms(20);KeyNumber=1;}
	if(key2==0){Delay_Ms(20);while(key2==0);Delay_Ms(20);KeyNumber=2;}
	if(key3==0){Delay_Ms(20);while(key3==0);Delay_Ms(20);KeyNumber=3;}
	if(key4==0){Delay_Ms(20);while(key4==0);Delay_Ms(20);KeyNumber=4;}
	return KeyNumber;
}
                         

