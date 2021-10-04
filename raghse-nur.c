/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.3 Standard
Automatic Program Generator
© Copyright 1998-2011 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 1/19/2020
Author  : Windows User
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 1.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/

#include <mega16.h>
#include <delay.h>

// global variables
int count = -1 ;   //using for mod
int flag = 0 ;     //To turn on and off

// External Interrupt 0 service routine
interrupt [EXT_INT0] void ext_int0_isr(void)  // button for changing mode and turning on
{
// Place your code here
count++;

if(count==0)  
{
    flag=1;
}

}

// External Interrupt 1 service routine
interrupt [EXT_INT1] void ext_int1_isr(void)   //button for turning off
{
// Place your code here
flag=0;
count=-1;

}
// Declare your global variables here

void main(void)
{
// Declare your local variables here
  int ii;
// Input/Output Ports initialization
// Port A initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
PORTA=0x00;
DDRA=0xFF;

// Port B initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTB=0x00;
DDRB=0x00;

// Port C initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTC=0x00;
DDRC=0x00;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=P State2=P State1=T State0=T 
PORTD=0x0C;
DDRD=0x00;

// External Interrupt(s) initialization
// INT0: On
// INT0 Mode: Falling Edge
// INT1: On
// INT1 Mode: Falling Edge
// INT2: Off
GICR|=0xC0;
MCUCR=0x0A;
MCUCSR=0x00;
GIFR=0xC0;

// Global enable interrupts
#asm("sei")

while (1)
      {
        // Place your code here 
        if (flag)
        {  
            if(count % 3 == 0) //mode 1
            {
                while(count % 3 == 0)
                { 
                    if(flag==0) {break;}
            
                    PINA.0 = 1 ;
                    PINA.2 = 1 ;
                    PINA.4 = 1 ;
                    PINA.6 = 1 ; 
                    delay_ms(400);
                    PINA.0 = 0 ;
                    PINA.2 = 0 ;
                    PINA.4 = 0 ;
                    PINA.6 = 0 ;
            
                    PINA.1 = 1 ;
                    PINA.3 = 1 ;
                    PINA.5 = 1 ;
                    PINA.7 = 1 ;
                    delay_ms(400);
                    PINA.1 = 0 ;
                    PINA.3 = 0 ;
                    PINA.5 = 0 ;
                    PINA.7 = 0 ;
                }
            }  
        
        
            if(count % 3 == 1)  //mode2
            { 
                while(count % 3 == 1)
                { 
                    if(flag==0) {break;}
            
                    PINA.0 = 1 ;
                    PINA.1 = 1 ;
                    PINA.3 = 1 ;
                    PINA.2 = 1 ;
                    PINA.4 = 1 ;
                    PINA.5 = 1 ;
                    PINA.6 = 1 ;
                    PINA.7 = 1 ;
            
                    delay_ms(200); 
            
                    PINA.0 = 0 ;
                    PINA.1 = 0 ;
                    PINA.3 = 0 ;
                    PINA.2 = 0 ;
                    PINA.4 = 0 ;
                    PINA.5 = 0 ;
                    PINA.6 = 0 ;
                    PINA.7 = 0 ;  
            
                    delay_ms(200);
                }
            }
            
            
        
            if(count % 3 == 2)  //mode3
            { 
                while(count % 3 == 2)
                {
            
                    for(ii=0;ii<=7;ii++)
                    { 
                        if(flag==0) {break;}
            
                        PORTA |= 1<<ii;
                        delay_ms(100); 
                        PORTA &= ~(1<<ii);
                        delay_ms(100); 
                    }  
                    
            
                    for(ii=7;ii>=0;ii--)
                    {
                        if(flag==0) {break;} 
            
                        PORTA |= 1<<ii;
                        delay_ms(100); 
                        PORTA &= ~(1<<ii);
                        delay_ms(100); 
                    } 
                }
            } 

        } 
      
       for(ii=0;ii<=7;ii++)    //turning off
       {      
        PORTA &= ~(1<<ii); 
       }
      
      
    }

   
   
}
