//
// Created by Jay on 2022/6/11.
//
#ifndef __DHT11_H
#define __DHT11_H
#include"intrins.h"
#include "STC12C5A60S2.H"
#include "delay.h"

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint  unsigned int
#endif

uchar dat_r[4];          //���ڴ�Ŵ�DHT11��ȡ������ֵ
sbit DATA=P3^3;   //����������,DHT11��2�ţ�2��Ҫ����5.1K����

#endif //__DHT11_H
