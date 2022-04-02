/*
 * LCD_CONFIG.h
 *
 *  Created on: Aug 3, 2021
 */
#include "GPIO_LOCAL.h"

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define RW 0
#define RS 1
#define E 2

#define CONTROL_PORT PORT_A
#define LCD_PORT PORT_C

#define FUNCTION_SET 0b00111000
#define DISPLAY_ON_CONTROL 0b00001111
#define DISPLAY_OFF_CONTROL 0b00001011
#define DISPLAY_CLEAR 0b00000001
#define ENTRY_MODE_SET 0b00000110

typedef enum
{
 LOW =0,
 HIGH,
}control;
#endif /* LCD_CONFIG_H_ */
