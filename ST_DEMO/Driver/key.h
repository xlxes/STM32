#ifndef __KEY_H
#define __KEY_H	

#include "sys.h"
#include "delay.h"

#define key_on 0
#define key_off 1

#define key1 GPIO_Pin_3
#define key0 GPIO_Pin_4

void key_init(void);		//���������ʼ��
u8 key_scan(GPIO_TypeDef* GPIOx,u16 GPIO_pin);	//�������

#endif

