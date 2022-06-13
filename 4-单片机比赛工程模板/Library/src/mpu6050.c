//
// Created by Jay on 2022/6/11.
//

#include "mpu6050.h"
void  SeriPushSend(uchar send_data)
{
    SBUF=send_data;
    while(!TI);TI=0;
}
//****************************************
//��ʱ
//****************************************
/*void delay(unsigned int k)
{
    unsigned int i,j;
    for(i=0;i<k;i++)
    {
        for(j=0;j<121;j++);
    }
}*/

//**************************************
//��ʱ5΢��(STC90C52RC@12M)
//��ͬ�Ĺ�������,��Ҫ�����˺���
//������1T��MCUʱ,���������ʱ����
//**************************************

//**************************************
//I2C��ʼ�ź�
//**************************************
void I2C_Start()
{
    SDA = 1;                    //����������
    SCL = 1;                    //����ʱ����
    Delay_Us(5);                 //��ʱ
    SDA = 0;                    //�����½���
    Delay_Us(5);                //��ʱ
    SCL = 0;                    //����ʱ����
}
//**************************************
//I2Cֹͣ�ź�
//**************************************
void I2C_Stop()
{
    SDA = 0;                    //����������
    SCL = 1;                    //����ʱ����
    Delay_Us(5);                 //��ʱ
    SDA = 1;                    //����������
    Delay_Us(5);                 //��ʱ
}
//**************************************
//I2C����Ӧ���ź�
//��ڲ���:ack (0:ACK 1:NAK)
//**************************************
void I2C_SendACK(bit ack)
{
    SDA = ack;                  //дӦ���ź�
    SCL = 1;                    //����ʱ����
    Delay_Us(5);                 //��ʱ
    SCL = 0;                    //����ʱ����
    Delay_Us(5);                  //��ʱ
}
//**************************************
//I2C����Ӧ���ź�
//**************************************
bit I2C_RecvACK()
{
    SCL = 1;                    //����ʱ����
    Delay_Us(5);                  //��ʱ
    CY = SDA;                   //��Ӧ���ź�
    SCL = 0;                    //����ʱ����
    Delay_Us(5);                  //��ʱ
    return CY;
}
//**************************************
//��I2C���߷���һ���ֽ�����
//**************************************
void I2C_SendByte(uchar dat)
{
    uchar i;
    for (i=0; i<8; i++)         //8λ������
    {
        dat <<= 1;              //�Ƴ����ݵ����λ
        SDA = CY;               //�����ݿ�
        SCL = 1;                //����ʱ����
        Delay_Us(5);              //��ʱ
        SCL = 0;                //����ʱ����
        Delay_Us(5);             //��ʱ
    }
    I2C_RecvACK();
}
//**************************************
//��I2C���߽���һ���ֽ�����
//**************************************
uchar I2C_RecvByte()
{
    uchar i;
    uchar dat = 0;
    SDA = 1;                    //ʹ���ڲ�����,׼����ȡ����,
    for (i=0; i<8; i++)         //8λ������
    {
        dat <<= 1;
        SCL = 1;                //����ʱ����
        Delay_Us(5);              //��ʱ
        dat |= SDA;             //������
        SCL = 0;                //����ʱ����
        Delay_Us(5);              //��ʱ
    }
    return dat;
}
//**************************************
//��I2C�豸д��һ���ֽ�����
//**************************************
void Single_WriteI2C(uchar REG_Address,uchar REG_data)
{
    I2C_Start();                  //��ʼ�ź�
    I2C_SendByte(SlaveAddress);   //�����豸��ַ+д�ź�
    I2C_SendByte(REG_Address);    //�ڲ��Ĵ�����ַ��
    I2C_SendByte(REG_data);       //�ڲ��Ĵ������ݣ�
    I2C_Stop();                   //����ֹͣ�ź�
}
//**************************************
//��I2C�豸��ȡһ���ֽ�����
//**************************************
uchar Single_ReadI2C(uchar REG_Address)
{
    uchar REG_data;
    I2C_Start();                   //��ʼ�ź�
    I2C_SendByte(SlaveAddress);    //�����豸��ַ+д�ź�
    I2C_SendByte(REG_Address);     //���ʹ洢��Ԫ��ַ����0��ʼ
    I2C_Start();                   //��ʼ�ź�
    I2C_SendByte(SlaveAddress+1);  //�����豸��ַ+���ź�
    REG_data=I2C_RecvByte();       //�����Ĵ�������
    I2C_SendACK(1);                //����Ӧ���ź�
    I2C_Stop();                    //ֹͣ�ź�
    return REG_data;
}
//**************************************
//��ʼ��MPU6050
//**************************************
void InitMPU6050()
{
    Single_WriteI2C(PWR_MGMT_1, 0x00);	//�������״̬
    Single_WriteI2C(SMPLRT_DIV, 0x07);
    Single_WriteI2C(CONFIG, 0x06);
    Single_WriteI2C(GYRO_CONFIG, 0x18);
    Single_WriteI2C(ACCEL_CONFIG, 0x01);
}
//**************************************
//�ϳ�����
//**************************************
int GetData(uchar REG_Address)
{
    uchar H,L;
    H=Single_ReadI2C(REG_Address);
    L=Single_ReadI2C(REG_Address+1);
    return (H<<8)+L;   //�ϳ�����
}


/*void init_uart()
{
    TMOD=0x21;
    TH1=0xfd;
    TL1=0xfd;

    SCON=0x50;
    PS=1;      //�����ж���Ϊ�����ȼ���
    TR0=1;	   //������ʱ��
    TR1=1;
    ET0=1;     //�򿪶�ʱ��0�ж�
    ES=1;
    EA=1;
}*/

//*********************************************************
//������
//*********************************************************
/*
void main()
{
    delay(500);		//�ϵ���ʱ
//	InitLcd();		//Һ����ʼ��
    init_uart();
    InitMPU6050();	//��ʼ��MPU6050
    delay(150);
    while(1)
    {

        Display10BitData(GetData(ACCEL_XOUT_H),2,0);	//��ʾX����ٶ�
        Display10BitData(GetData(ACCEL_YOUT_H),7,0);	//��ʾY����ٶ�
        Display10BitData(GetData(ACCEL_ZOUT_H),12,0);	//��ʾZ����ٶ�
        Display10BitData(GetData(GYRO_XOUT_H),2,1);	//��ʾX����ٶ�
        Display10BitData(GetData(GYRO_YOUT_H),7,1);	//��ʾY����ٶ�
        Display10BitData(GetData(GYRO_ZOUT_H),12,1);	//��ʾZ����ٶ�

        SeriPushSend(0x0d);
        SeriPushSend(0x0a);//���У��س�
        delay(100);
    }
}*/
