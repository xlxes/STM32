#include "key.h"
#include "led.h"
//初始化按键KEY0 PE4 KEY1 PE3 KEY1
void key_init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = key0|key1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	
	GPIO_Init(GPIOE,&GPIO_InitStructure);
}

u8 key_scan(GPIO_TypeDef* GPIOx,u16 GPIO_pin)
{
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_pin) == key_on)
	{
		delay_ms(100);
		if(GPIO_ReadInputDataBit(GPIOx,GPIO_pin) == key_on)
		{
			while(GPIO_ReadInputDataBit(GPIOx,GPIO_pin) == key_on)
				return key_on;
		}
		else 
			return key_off;
	}
	return key_off;
}
/*
static void NVIC_Configuration()
{
	NVIC_InitTypeDef NVIC_Initstructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	NVIC_Initstructure.NVIC_IRQChannel = EXTI3_IRQn;
	NVIC_Initstructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_Initstructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_Initstructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_Initstructure);
	
}

void EXIT_KEY1_Config()		//key1 PE3
{
	
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_Initstructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_AFIO,ENABLE);
	
	NVIC_Configuration();
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Pin = key1;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource3);
	EXTI_Initstructure.EXTI_Line = EXTI_Line3;		//线路
	EXTI_Initstructure.EXTI_Mode = EXTI_Mode_Interrupt;		//方式
	EXTI_Initstructure.EXTI_Trigger = EXTI_Trigger_Falling;	//下降沿触发中断

	EXTI_Initstructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_Initstructure);
}

void EXTI3_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line3) != RESET)
	{
		LED1 = ~LED1;
		EXTI_ClearITPendingBit(EXTI_Line3);
	}
}
*/
