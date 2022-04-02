
/*
 * GPIO_LOCAL.h
 *
 * Created: 8/7/2021 2:01:23 PM
 *  Author: 
 */ 

#ifndef GPIO_LOCAL_H_
#define GPIO_LOCAL_H_

#define PORTA *((volatile UINT8*)(0X3B))
#define DDRA *((volatile UINT8*)(0X3A))
#define PINA *((volatile UINT8*)(0X39))

#define PORTB *((volatile UINT8*)(0X38))
#define DDRB *((volatile UINT8*)(0X37))
#define PINB *((volatile UINT8*)(0X36))

#define PORTC *((volatile UINT8*)(0X35))
#define DDRC *((volatile UINT8*)(0X34))
#define PINC *((volatile UINT8*)(0X33))

#define PORTD *((volatile UINT8*)(0X32))
#define DDRD *((volatile UINT8*)(0X31))
#define PIND *((volatile UINT8*)(0X30))

#endif /* GPIO_LOCAL_H_ */
