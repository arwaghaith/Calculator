/*
 * LCD.h
 *
 * Created: 8/7/2021 6:58:39 PM
 *  Author: iT-User
 */ 

/*
 * LCD.h
 *
 * Created: 8/7/2021 2:04:01 PM
 *  Author: iT-User
 */ 
/*
 * LCD.h
 *
 *  Created on: Aug 4, 2021
 *      Author: noran
 */

#ifndef LCD_H_
#define LCD_H_

#include "STD_TYPES.h"
#include "UTILES.h"
#include "GPIO_CONFIG.h"
#include "util/delay.h"
#include "GPIO_CONFIG.h"
#include "GPIO.h"
#include "LCD_CONFIG.h"

void LCD_8BIT_INIT (void);

void LCD_SEND_DATA (UINT8 DATA);

void LCD_SEND_COMMAND (UINT8 COMMAND);


void LCD_STRING(UINT8 *STR );

void LCD_CHAR(UINT8 CHAR);

UINT8 GET_NUM(UINT32 NUM,UINT8 i);

void LCD_CLEAR();

void LCD_WRITE_NUM(SINT32 NUM);

#endif /* LCD_H_ */

