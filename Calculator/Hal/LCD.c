/*
 * LCD.c
 *
 *  Created on: Aug 4, 2021
 */
#include "STD_TYPES.h"
#include "UTILES.h"
#include "GPIO_CONFIG.h"
#include "avr/delay.h"
#include "GPIO_CONFIG.h"
#include "GPIO.h"
#include "LCD.h"

void LCD_SEND_COMMAND (UINT8 COMMAND)
{
 GPIO_WRITE_PIN_VALUE(CONTROL_PORT, RS , 0);
 GPIO_WRITE_PIN_VALUE(CONTROL_PORT, RW , 0);

 GPIO_WRITE_PORT_VALUE(LCD_PORT, COMMAND);

 GPIO_WRITE_PIN_VALUE(CONTROL_PORT, E , 1);
 _delay_ms(1);
 GPIO_WRITE_PIN_VALUE(CONTROL_PORT, E , 0);
 _delay_ms(1);
 //GPIO_WRITE_PIN_VALUE(CONTROL_PORT, E , 1);
}

void LCD_SEND_DATA (UINT8 DATA)
{
 GPIO_WRITE_PIN_VALUE(CONTROL_PORT, RS , 1);
 GPIO_WRITE_PIN_VALUE(CONTROL_PORT, RW , 0);

 GPIO_WRITE_PORT_VALUE(LCD_PORT, DATA);

 GPIO_WRITE_PIN_VALUE(CONTROL_PORT, E ,1);
 _delay_ms(1);
 GPIO_WRITE_PIN_VALUE(CONTROL_PORT, E ,0);
 _delay_ms(1);
 //GPIO_WRITE_PIN_VALUE(CONTROL_PORT, E , LOW);
}

void LCD_8BIT_INIT (void)
{
 _delay_ms (50);
 LCD_SEND_COMMAND (FUNCTION_SET);
 _delay_ms (1);
 LCD_SEND_COMMAND (DISPLAY_ON_CONTROL);
 _delay_ms (1);
 LCD_SEND_COMMAND (DISPLAY_CLEAR);
 _delay_ms (2);
 LCD_SEND_COMMAND (ENTRY_MODE_SET);
 _delay_ms (1);
}

//Noran Emad
//sends char by char till reaches null
void LCD_STRING(UINT8 *STR )
{
	UINT8 i;
	for (i=0;STR[i]!='\0';i++)
	{
		LCD_SEND_DATA(STR[i]);
	}
}

//Noran Emad
void LCD_CHAR(UINT8 CH)
{
	LCD_SEND_DATA(CH);
}

void LCD_CLEAR()
{
	LCD_SEND_COMMAND(DISPLAY_CLEAR);

}

//Arwa
void LCD_WRITE_NUM(SINT32 NUM)
{
	if(NUM==0)
		LCD_SEND_DATA('0') ;
		if(NUM<0)
		{
			LCD_SEND_DATA('-');
			NUM=(-1)*NUM;
		}
		UINT32 x=NUM;
		UINT8 y,flag=0;
		while(x>0)
		{x=x/10;
			flag++;
		}
		

		while(flag)
		{
			y=GET_NUM(NUM,flag);
			LCD_SEND_DATA(y) ;

			flag--;
		}

	}

//Noran Emad
UINT8 GET_NUM(UINT32 NUM,UINT8 i)
 {   UINT32 n=1;
	while(i>0)
	{
		n=n*10;
	    i--;
	}
	return (((NUM%n)/(n/10))+48);             //acsii '0' = 48
 }

void LCD_GoTo(UINT8 LINE,UINT8 COL)
{  //line for horizontal
	//col for vertical
	UINT8 command =0x80;
	//writing in first line
	if(LINE==0)
	command+=COL;
	//writing in second line
	else if(LINE==1)
	command+=(0x40+COL);
	LCD_SEND_COMMAND(command);
}
