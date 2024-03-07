/* 
 * File:   main_app.c
 * Author: mohammed yasser
 *
 * Created on February 29, 2024, 12:09 PM
 */
/*section:*********includes*******************************/
#include "main_app.h"
#include "ECUL/KEYPAD/ECUL_Keybad.h"
#include <util/delay.h>

uint_8 wrriten_value = 0 ;
Std_ReturnType ret = 0 ;

Keypad_t keypad1= {.ROW0_PORT0 =DIO_PORTC ,.ROW0_PIN0 =DIO_PIN5 ,
                   .ROW1_PORT1 =DIO_PORTC ,.ROW1_PIN1 =DIO_PIN4 ,
                   .ROW2_PORT2 =DIO_PORTC ,.ROW2_PIN2 =DIO_PIN3 ,
                   .ROW3_PORT3 =DIO_PORTC ,.ROW3_PIN3 =DIO_PIN2 ,
                   .COL0_PORT0 =DIO_PORTD , .COL0_PIN0 =DIO_PIN7 ,
                   .COL1_PORT1 =DIO_PORTD , .COL1_PIN1 =DIO_PIN6 ,
                   .COL2_PORT2 =DIO_PORTD , .COL2_PIN2 =DIO_PIN5 ,
                   .COL3_PORT3 =DIO_PORTD , .COL3_PIN3 =DIO_PIN3 ,} ;

int main() {
    
    
    
    ret = keypad_STDIntialization(&keypad1) ;
    DIO_voidSetPinDirection(DIO_PORTB ,DIO_PIN7 ,DIO_PIN_OUTPUT) ;
   
    
    
    while (1){
        
        
        
        keypad_STDGet_written_value(&keypad1 ,&wrriten_value) ;
        
        if (wrriten_value =='7'){
            
            DIO_voidTogglePinValue(DIO_PORTB ,DIO_PIN7 ) ;
            _delay_ms(1500) ;
            
        }
        else if (wrriten_value =='3'){
            
             DIO_voidSetPinValue(DIO_PORTB ,DIO_PIN7  ,DIO_PIN_LOW) ;
            
            
        }
        
        
        
    }
    
    
    
    
    
    
    return (EXIT_SUCCESS);
}


