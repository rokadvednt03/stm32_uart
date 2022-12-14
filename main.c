#include "stm32f1030xx_gpio_driver.h"
#include "stm32f103xx_uart_driver.h"
#include <string.h>
#include <stdio.h>
#include <stdint.h>
//void USART_GPIO(void);
//void USART_SETTING(void);
int main()
{
	
	//USART_GPIO();
	GPIO_Handle_t tx ;
	tx.pGPIOx = GPIOA ;
	tx.GPIO_PinConfig.GPIO_ModeInOut = GPIO_OUT_10MHZ ;
	tx.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN_OUT_PP;
	tx.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_9 ;
	
	GPIO_PeriClockControl(GPIOA , ENABLE );
	GPIO_Init(&tx);
	
	tx.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_10 ;
	GPIO_Init(&tx);
	//USART_SETTING();
	
	USART_Handle_t trans;
	trans.pUSARTx = USART1;
	trans.USART_Config.USART_Baud = USART_STD_BAUD_9600 ;
	trans.USART_Config.USART_Mode = USART_MODE_ONLY_TX;
	trans.USART_Config.USART_NoOfStopBits = USART_STOPBITS_1 ; 
	trans.USART_Config.USART_ParityControl = USART_PARITY_DISABLE;
	trans.USART_Config.USART_WordLength = USART_WORDLEN_8BITS;
	
	USART_PeriClockControl(USART1 , ENABLE);
	USART_Init(&trans);


	uint8_t data = 2;
	//int delay;
	
	
	USART_Enable(USART1,ENABLE);	
	for( data = 0 ; data < 255 ; data ++ )
	{
	//for(delay = 0 ; delay < 500000 ; delay ++);
	USART_SendData(&trans,&data , sizeof(data));
	
}	
	
	USART_Enable(USART1,DISABLE);
}
/*
void USART_GPIO(void)
{
	
}

void USART_SETTING(void)
{
	
}

*/