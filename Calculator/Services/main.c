/*
 * SHEET.c
 *
 * Created: 9/18/2020 12:54:25 AM
 * Author :Arwa
 */
#define F_CPU 1000000
#include "util/delay.h"
#include "UTILES.h"
#include "STD_TYPES.h"
#include "GPIO.h"
#include "LCD.h"
#include "KEYPAD.h"




int main(void)
{



     GPIO_init();
     LCD_8BIT_INIT();
     calc();


}




