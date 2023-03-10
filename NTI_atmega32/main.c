/*
 * NTI_atmega32.c
 *
 * Created: 3/3/2023 10:08:32 AM
 * Author : ncm
 */ 

#include "../MCAL/USART/uart_interface.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/LED/led.h"
#include "../MCAL/SPI/spi_interface.h"
#include "../MCAL/DIO/dio.h"
#include "../HAL/KEYPAD//keyPad.h"
#include "./MCAL/TWI/twi_interface.h"

#include "../HAL/External_EEPROM/exEEPROM.h"

#define F_CPU 16000000U
#include "util/delay.h"

#if 1
volatile u8 d ='A'  ;

int main()
{
	u8 data='Z';
   
	TWI_Master_voidInit(40000);
	UART_Init();
	LCD_Init();
		
    while (1) 
    {
		TWI_enuStartCond();
		TWI_enuSelectSlave(0x10,READ_OP);
		TWI_enuReceiveByte(&data,ACK);
		 
		 
		 _delay_ms(1000);
		 
		 UART_TransmitBusyWait(data);
		 
		 _delay_ms(1000);
		 
		
		
    }
}

#endif

