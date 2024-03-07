/* 
 * File:   main_app.c
 * Author: mohammed yasser
 *
 * Created on February 29, 2024, 12:09 PM
 */
/*section:*********includes*******************************/
#include "main_app.h"
#include <util/delay.h>


seven_segment_t sev1 ={.port0=DIO_PORTB ,.pin0=DIO_PIN0 ,
                       .port1=DIO_PORTB ,.pin1=DIO_PIN1 ,
                       .port2=DIO_PORTB ,.pin2=DIO_PIN2 ,
                       .port3=DIO_PORTB ,.pin3=DIO_PIN4 ,
                       .segment_type =SEGMENT_COMMON_anod};


int main() {

  
  
   seven_segment_initialization(&sev1) ;
   DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_OUTPUT) ;
   DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN1,DIO_PIN_OUTPUT) ;
   DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN2,DIO_PIN_OUTPUT) ;
   DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT) ;
   DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT) ;
   
   while(1){
       
   DIO_voidSetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW) ;
   DIO_voidSetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW) ;
   DIO_voidSetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW) ;
   DIO_voidSetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW) ;
   DIO_voidSetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW) ;
    DIO_voidSetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW) ;
       
        DIO_voidSetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
        seven_segment_write_number (&sev1 ,6) ;
        _delay_ms(3) ;
        DIO_voidSetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
       DIO_voidSetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_HIGH);
       seven_segment_write_number (&sev1 ,5) ;
       _delay_ms(3) ;
       DIO_voidSetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
        DIO_voidSetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
        seven_segment_write_number (&sev1 ,4) ;
       _delay_ms(3) ;
       DIO_voidSetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
        DIO_voidSetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
         seven_segment_write_number (&sev1 ,3) ;
       _delay_ms(3) ;
       DIO_voidSetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
        DIO_voidSetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
         seven_segment_write_number (&sev1 ,2) ;
       _delay_ms(3) ;
        DIO_voidSetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
        DIO_voidSetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
         seven_segment_write_number (&sev1 ,1) ;
       _delay_ms(3) ;
       
       
   }

  


    return (EXIT_SUCCESS);
}

