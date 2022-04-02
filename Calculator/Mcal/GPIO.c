/*
 * GPIO.c
 *
 *  Created on: Jul 23, 2021
 *      Author: 
 */


#include "GPIO.h"

void GPIO_INIT_PORT_DIRECTION(UINT8 PORT , UINT8 DIRECTION)
{
	if(DIRECTION==INPUT)
	{
		switch(PORT)
		{
			case PORT_A :
			DDRA=0;
			break;
			case PORT_B :
			DDRB=0;
			break;
			case PORT_C :
			DDRC=0;
			break;
			case PORT_D :
			DDRD=0;
			break;
		}

	}
	else if(DIRECTION==OUTPUT)
	{
		switch(PORT)
		{
			case PORT_A :
			DDRA=0XFF;
			break;
			case PORT_B :
			DDRB=0XFF;
			break;
			case PORT_C :
			DDRC=0XFF;
			break;
			case PORT_D :
			DDRD=0XFF;
			break;
		}

	}

}

void GPIO_WRITE_PORT_VALUE(UINT8 PORT , UINT8 VALUE)
{
switch(PORT)
{
	case PORT_A :
	PORTA=VALUE;
	break;
	case PORT_B :
	PORTB=VALUE;
	break;
	case PORT_C :
	PORTC=VALUE;
	break;
	case PORT_D :
	PORTD=VALUE;
	break;
}
}

UINT8 GPIO_READ_PORT_VALUE(UINT8 PORT)
{
	UINT8 VALUE;
	switch(PORT)
	{
		case PORT_A :
		VALUE=PINA;
		break;
		case PORT_B :
		VALUE=PINB;
		break;
		case PORT_C :
		VALUE=PINC;
		break;
		case PORT_D :
		VALUE=PIND;
		break;
	}
	return VALUE;
}

void GPIO_INIT_PIN_DIRECTION(UINT8 PORT ,UINT8 PINno, UINT8 DIRECTION)
{
if(DIRECTION==INPUT)
{
	switch(PORT)
	{
		case PORT_A :
		CLRBIT(DDRA,PINno);
		SETBIT(PORTA,PINno);
		break;
		case PORT_B :
		CLRBIT(DDRB,PINno);
		SETBIT(PORTB,PINno);
		break;
		case PORT_C :
	    CLRBIT(DDRC,PINno);
		SETBIT(PORTC,PINno);
	    break;
		case PORT_D :
	    CLRBIT(DDRD,PINno);
		SETBIT(PORTD,PINno);
	    break;
	}

}
else if(DIRECTION==OUTPUT)
{
	switch(PORT)
	{
		case PORT_A :
	   SETBIT(DDRA,PINno);
	   break;
		case PORT_B :
	   SETBIT(DDRB,PINno);
	   break;
		case PORT_C :
		break;
	   SETBIT(DDRC,PINno);
	   break;
		case PORT_D :
	   SETBIT(DDRD,PINno);
	   break;
	}

}
}

void GPIO_WRITE_PIN_VALUE(UINT8 PORT ,UINT8 PINno , UINT8 VALUE)
{
	if(VALUE==1)
	{
 switch(PORT)
 {
	 case PORT_A :
	SETBIT(PORTA,PINno);
	break;
	 case PORT_B :
	SETBIT(PORTB,PINno);
	break;
	 case PORT_C :
	SETBIT(PORTC,PINno);
	break;
	 case PORT_D :
	SETBIT(PORTD,PINno);
	break;
 }
}
else if(VALUE==0)
{
	switch(PORT)
	{
		case PORT_A :
		CLRBIT(PORTA,PINno);
		break;
		case PORT_B :
		CLRBIT(PORTB,PINno);
		break;
		case PORT_C :
		CLRBIT(PORTC,PINno);
		break;
		case PORT_D :
	  CLRBIT(PORTD,PINno);
	  break;
	}
}
}

UINT8 GPIO_READ_PIN_VALUE(UINT8 PORT ,UINT8 PINno)
{
	
	UINT8 PIN;
	switch(PORT)
	{
		case PORT_A :
		PIN=GETBIT(PINA,PINno);
		break;
		case PORT_B :
		PIN=GETBIT(PINB,PINno);
		break;
		case PORT_C :
		PIN=GETBIT(PINC,PINno);
		break;
		case PORT_D :
     	PIN=GETBIT(PIND,PINno);
     	break;
	}
	return PIN;
}
