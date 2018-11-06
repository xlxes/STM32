#include "stm32f10x.h"
#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
 
u8 key_flag = 0;
u8 key_flag2 = 0;

int main(void)
{	
	delay_init();	    //��ʱ������ʼ��	  
	LED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�
	key_init();
	
	LED0 = led_off;		//�����
	LED1 = led_off; 	//�Ҳ��̵�
	
	
	while(1)
	{
		key_flag = key_scan(GPIOE,key0);
		key_flag2 = key_scan(GPIOE,key1);
		if(key_flag == key_on)		//����ȥ��
		{
			LED0 = led_on;	
		}
		else 
			LED0 = led_off;
		if(key_flag2 == key_on)		//����ȥ��
		{
			LED1 = led_on;	
		}
		else 
			LED1 = led_off;
	}
}

