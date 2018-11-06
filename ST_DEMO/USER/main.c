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
	delay_init();	    //延时函数初始化	  
	LED_Init();		  	//初始化与LED连接的硬件接口
	key_init();
	
	LED0 = led_off;		//左侧红灯
	LED1 = led_off; 	//右侧绿灯
	
	
	while(1)
	{
		key_flag = key_scan(GPIOE,key0);
		key_flag2 = key_scan(GPIOE,key1);
		if(key_flag == key_on)		//按下去了
		{
			LED0 = led_on;	
		}
		else 
			LED0 = led_off;
		if(key_flag2 == key_on)		//按下去了
		{
			LED1 = led_on;	
		}
		else 
			LED1 = led_off;
	}
}

