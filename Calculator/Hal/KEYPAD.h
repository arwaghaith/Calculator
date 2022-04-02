/*
 * KEYPAD.h
 *
 *  Created on: Aug 4, 2021
 */
#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "KEYPAD_CONFIG.h"
#include "LCD.h"

UINT8 ARR_KEYPADVALUE[row][col];
UINT8 KEYPAD_GETPRESSED(void);
void GPIO_init();
void calc();

#endif /* KEYPAD_H_ */
