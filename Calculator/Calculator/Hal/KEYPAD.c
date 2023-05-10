/*
 * KEYPAD.c
 *
 *  Created on: Aug 4, 2021
 */
#include "GPIO_LOCAL.h"
#include "GPIO_CONFIG.h"
#include "GPIO.h"
#include "KEYPAD_CONFIG.h"
#include "KEYPAD.h"
#include "util/delay.h"

UINT8 ARR_KEYPADVALUE[row][col]= {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'C','0','=','+'}};


UINT8 KEYPAD_GETPRESSED(void)
{


    GPIO_WRITE_PORT_VALUE(KEYPAD_ROWS, 255);

    UINT8 Rcount, Ccount, result=DEFAULT_Key;
    for(Rcount=0; Rcount<4; Rcount++)
    {
        GPIO_WRITE_PIN_VALUE(KEYPAD_ROWS,Rcount+R0,0);
        for(Ccount=0; Ccount<4; Ccount++)
        {
            if(GPIO_READ_PIN_VALUE(KEYPAD_PORT,Ccount+C0)==0)

            {
                result=ARR_KEYPADVALUE[Rcount][Ccount];



                // to avoid debouncing
                
                _delay_ms(30);

            }
        }

        GPIO_WRITE_PIN_VALUE(KEYPAD_ROWS,Rcount+R0,1);
    }
    return result;

}









//SAMA

void GPIO_init()
{
    GPIO_INIT_PORT_DIRECTION(LCD_PORT,OUTPUT);
    GPIO_INIT_PORT_DIRECTION(CONTROL_PORT,OUTPUT);

    GPIO_INIT_PIN_DIRECTION(KEYPAD_ROWS,R0, OUTPUT);
    GPIO_INIT_PIN_DIRECTION(KEYPAD_ROWS,R1, OUTPUT);
    GPIO_INIT_PIN_DIRECTION(KEYPAD_ROWS,R2, OUTPUT);
    GPIO_INIT_PIN_DIRECTION(KEYPAD_ROWS,R3, OUTPUT);

    GPIO_INIT_PIN_DIRECTION(KEYPAD_PORT,C0, INPUT);
    GPIO_INIT_PIN_DIRECTION(KEYPAD_PORT,C1, INPUT);
    GPIO_INIT_PIN_DIRECTION(KEYPAD_PORT,C2, INPUT);
    GPIO_INIT_PIN_DIRECTION(KEYPAD_PORT,C3, INPUT);

}



//ARWA
void calc()
{
    UINT16 x=DEFAULT_Key,y=DEFAULT_Key;
	UINT8 flag1,flag2,flag3,flag4,flag5,flag6;
    SINT32 l= 0,m=0,n=0,rem=0;
    

    while(1)
    {



        l= 0,m=0,n=0,rem=0;
        flag1=0;
        flag2=0;
        flag3=0;
        flag4=0;
        flag5=0;
        flag6=0;
		
		
//flag1 is used to check if the first number entered is negative
//flag2 is used to check if the second number entered is negative
//flag3 is used to check if the entered number is less or equal 5 digits
//flag4 is used to check for undefined values
//flag5 is used to check for errors
//flag6 is used to check for equal sign after entering first number




//making sure that the lcd is clear
        LCD_CLEAR();
//getting the first number
        x=KEYPAD_GETPRESSED();
        while(x==DEFAULT_Key)
            x=KEYPAD_GETPRESSED();
        _delay_ms(300);
//flag1 is used for checking if the first number is negative
        if(x!=DEFAULT_Key)
        {


            LCD_GoTo(0,0);
            if(x=='-')
            {

                flag1=1;
                LCD_CHAR(x);
                x=KEYPAD_GETPRESSED();
                while(x==DEFAULT_Key)
                    x=KEYPAD_GETPRESSED();
                _delay_ms(300);
            }
	//checking if the first number is starting with plus sign
            else if(x=='+')
            {


                LCD_CHAR(x);
                x=KEYPAD_GETPRESSED();
                while(x==DEFAULT_Key)
                    x=KEYPAD_GETPRESSED();
                _delay_ms(300);
            }


            if (x>='0' &&x<='9' )
            {
                do
                {
					//flag3  is used to make sure that the number of digits less than 5
                    if(flag3<4)
                    {


                        LCD_CHAR(x);
                        l=(l*10)+x-'0';
                        _delay_ms(300);
                        x=KEYPAD_GETPRESSED();
                        while(x==DEFAULT_Key)
                            x=KEYPAD_GETPRESSED();
                    }
                    else
                    {
                        _delay_ms(300);
                        x=KEYPAD_GETPRESSED();
                        while(x==DEFAULT_Key)
                            x=KEYPAD_GETPRESSED();
                    }

                    flag3++;

                }
                while(x>='0' &&x<='9' );

            }
	//getting error if the number starts with *,/,=

            else if (x=='*' ||x=='/'  ||x=='=')
            {


                flag5=1;

            }
            if(flag1==1)
                l=l*-1;
            n=l;
	//if the user entered clear
            if(x=='C')
            {
                _delay_ms(300);
                LCD_CLEAR();
                continue;

            }
	//writing error if the user 
            if(flag5==1)
            {
                LCD_CLEAR();
                LCD_GoTo(1,1);
                LCD_STRING("ERROR");


                x=KEYPAD_GETPRESSED();
                while(x==DEFAULT_Key)
                    x=KEYPAD_GETPRESSED();
                _delay_ms(300);
//the calculator wouldn't restart until the user press c
                while(x!='C' )
                {

                    x=KEYPAD_GETPRESSED();



                }
                _delay_ms(30);
                x=DEFAULT_Key;

                continue;



            }


//making sure that the entered character is sign not a number
            while(x>='0'&&x<='9')
                x=KEYPAD_GETPRESSED();
                 _delay_ms(300);
            LCD_CHAR(x);
           

            while(1)
            {

//if the user entered clear
                if(x=='C')
                {

                    x=DEFAULT_Key;
                    break;

                }
//if the user entered = after entering the first number
                if(x=='=')
                {


                    flag6=1;
                    break;

                }


                rem=0;
                m=0;
                flag2=0;
				//entering the second number
                y=KEYPAD_GETPRESSED();
                flag3=0;

                while(y==DEFAULT_Key)
                    y=KEYPAD_GETPRESSED();
					   _delay_ms(300);
               //flag2 is used for checking if the second number is negative
                if(y=='-')
                {
                    flag2=1;
                    LCD_CHAR(y);
                    _delay_ms(300);
                    y=KEYPAD_GETPRESSED();
                    while(y==DEFAULT_Key)
                        y=KEYPAD_GETPRESSED();
                    _delay_ms(300);
                }
				//checking if the second number start with positive just print it
                else if(y=='+')
                {


                    LCD_CHAR(y);
                    _delay_ms(300);
                    y=KEYPAD_GETPRESSED();
                    while(y==DEFAULT_Key)
                        y=KEYPAD_GETPRESSED();
                    _delay_ms(300);
                }
		//getting the second number

                if (y>='0' && y<='9')
                {

                    do
                    {
						//checking if the second number is more than four digits
                        if(flag3<4)
                        {

                            LCD_CHAR(y);
                            m=(m*10)+y-'0';
                          
                            y=KEYPAD_GETPRESSED();
							  _delay_ms(300);
                            while(y==DEFAULT_Key)
                                y=KEYPAD_GETPRESSED();
								  _delay_ms(300);
                        }
                        else
                        {
                            _delay_ms(300);
                            y=KEYPAD_GETPRESSED();
                            while(y==DEFAULT_Key)
                                y=KEYPAD_GETPRESSED();
                        }
                        flag3++;


                    }
                    while(y>='0' && y<='9');
                }
				//checking if the second number starts with *,/,=
                else if (y=='*' ||y=='/'||y=='=' )
                {

                    flag5=1;

                }
				//if the user entered clear
                if(y=='C')
                {
                    _delay_ms(300);

                    break;

                }


            //if the second number is negative
                if(flag2==1)
                    m=m*-1;
          //if the user entered the second number then entered +,-,/,* do nothing just wait for the equal sign
                 while(y>='0'&&y<='9')
                    y=KEYPAD_GETPRESSED();
                _delay_ms(300);
                if(y=='=')
                {
					
                    LCD_CHAR(y);
					//adding
                    if(x=='+')
                        n=n+m;
					//subtracting
                    if(x=='-')
                        n=n-m;
					//multiplying
                    if(x=='*')
                        n=n*m;
					//dividing
                    if(x=='/')
                    {
						//checking which number is negative to return it positive and apply modulus
                        if(flag1==1&&flag2==0)
                            n=n*-1;
                        if(flag1==0&&flag2==1)
                            m=m*-1;
                        rem=n%m;
						//returning the number to its initial state for division
                        if(flag1==1&&flag2==0)
                            n=n*-1;
                        if(flag1==0&&flag2==1)
                            m=m*-1;
                        n=n/m;



         //flag4 for checking if the second number is zero
                        if(m==0)
                            flag4=1;
                    }
                    LCD_GoTo(1,0);


                }
                if(flag4==1)
                {
                   //if the second number is zero print undefined and just wait for clear to reset
                    LCD_STRING("UNDEFINED");

                    x=DEFAULT_Key;

                    x=KEYPAD_GETPRESSED();
                    while(x==DEFAULT_Key)
                        x=KEYPAD_GETPRESSED();
                    _delay_ms(300);
			
                    while(x!='C' )
                    {

                        x=KEYPAD_GETPRESSED();



                    }
                    _delay_ms(300);


                    break;
                }
		//if there is error print error and just wait for clear to reset
                if(flag5==1)
                {
                    LCD_CLEAR();
                    LCD_GoTo(1,1);
                    LCD_STRING("ERROR");

                    x=DEFAULT_Key;
                    x=KEYPAD_GETPRESSED();
                    while(x==DEFAULT_Key)
                        x=KEYPAD_GETPRESSED();
                    _delay_ms(300);
                    while(x!='C' )
                    {

                        x=KEYPAD_GETPRESSED();



                    }
                    _delay_ms(30);



                    break;



                }
				//if the integer result of division is zero
                if(n==0)
                {
                    if(flag1==0 &&flag2==1)
                        LCD_CHAR('-');
                    if(flag2==0 &&flag1==1)
                        LCD_CHAR('-');
                }
				//if the result of division is float
                LCD_WRITE_NUM(n);
                if(rem!=0)
                {

                    UINT16  a,b,c;
                    LCD_CHAR('.');


                    if(flag2==1)
                        m=m*-1;

                    a=rem*10/m;

                    b=rem*100/m;

                    b=b%10;


                    c=rem*1000/m;

                    c=c%10;

//writing the numbers after the '.' precisely
//
                    if(c==0)
                    {
                        if(b==0)
                            LCD_CHAR(a+'0');

                        else
                        {


                            LCD_CHAR(a+'0');
                            LCD_CHAR(b+'0');


                        }
                    }
                    else
                    {
                        LCD_CHAR(a+'0');
                        LCD_CHAR(b+'0');
                        LCD_CHAR(c+'0');



                    }
                }

//if the user entered clear

                x=KEYPAD_GETPRESSED();
                while(x==DEFAULT_Key)
                    x=KEYPAD_GETPRESSED();
                _delay_ms(300);
                if(x=='C')
                {

                    _delay_ms(30);
                    x=DEFAULT_Key;
                    break;

                }
		//if the user wants to enter another operation after entering the first

                else if(x=='-' || x=='+' ||x=='*' ||x=='/')
                {

                    LCD_CLEAR();
                    LCD_GoTo(0,0);
                    LCD_WRITE_NUM(n);
                    LCD_CHAR(x);
                    _delay_ms(300);
                }
            }

        }
//to check if the user entered = after entering the first number
        if(flag6==1)
        {
            LCD_GoTo(1,0);
            LCD_WRITE_NUM(n);
            x=DEFAULT_Key;
            x=KEYPAD_GETPRESSED();
            while(x==DEFAULT_Key)
                x=KEYPAD_GETPRESSED();


            while(x!='C' )
            {

                x=KEYPAD_GETPRESSED();



            }
            _delay_ms(30);
            x=DEFAULT_Key;
            continue;

        }
    }
    LCD_CLEAR();
}

