/* 
 * File:   ECUL_Keybad.c
 * Author: sayr3
 *
 * Created on March 4, 2024, 3:30 AM
 */
#include "ECUL_Keybad.h"

uint_8 arr[4][4]={{'1','2','3','4'},
                  {'5','6','7','8'},
                  {'9','10','11','12'},
                  {'13','14','15','16'}} ;

Std_ReturnType keypad_STDIntialization (const Keypad_t *keypad){
    
    Std_ReturnType ret = E_OK;

    if (NULL == keypad) {
        ret = E_NOT_OK;

    } else
    
    {

        DIO_voidSetPinDirection(keypad->COL0_PORT0 ,keypad->COL0_PIN0 ,DIO_PIN_INPUT) ;
        DIO_voidSetPinDirection(keypad->COL1_PORT1 ,keypad->COL1_PIN1 ,DIO_PIN_INPUT) ;
        DIO_voidSetPinDirection(keypad->COL2_PORT2 ,keypad->COL2_PIN2 ,DIO_PIN_INPUT) ;
        DIO_voidSetPinDirection(keypad->COL3_PORT3 ,keypad->COL3_PIN3 ,DIO_PIN_INPUT) ;
        
        DIO_voidSetPinDirection(keypad->ROW0_PORT0 ,keypad->ROW0_PIN0 ,DIO_PIN_OUTPUT) ;
        DIO_voidSetPinDirection(keypad->ROW1_PORT1 ,keypad->ROW1_PIN1 ,DIO_PIN_OUTPUT) ;
        DIO_voidSetPinDirection(keypad->ROW2_PORT2 ,keypad->ROW2_PIN2 ,DIO_PIN_OUTPUT) ;
        DIO_voidSetPinDirection(keypad->ROW3_PORT3 ,keypad->ROW3_PIN3 ,DIO_PIN_OUTPUT) ;
        
    }




    return ret;



    
    
    
    
    
}
Std_ReturnType keypad_STDGet_written_value (const Keypad_t *keypad , uint_8 * value){
    
     Std_ReturnType ret = E_OK;
     uint_8 get_value = 0 ;

    if (NULL == keypad) {
        ret = E_NOT_OK;

    } else{
    
        for (int i = 0 ; i<4 ; i++){
            
            DIO_voidSetPinValue(keypad->ROW0_PORT0 ,keypad->ROW0_PIN0 ,DIO_PIN_HIGH) ;
            DIO_voidSetPinValue(keypad->ROW1_PORT1 ,keypad->ROW1_PIN1 ,DIO_PIN_HIGH) ;
            DIO_voidSetPinValue(keypad->ROW2_PORT2 ,keypad->ROW2_PIN2 ,DIO_PIN_HIGH) ;
            DIO_voidSetPinValue(keypad->ROW3_PORT3 ,keypad->ROW3_PIN3 ,DIO_PIN_HIGH) ;
        
            switch(i){
                
                case 0 :
                    DIO_voidSetPinValue(keypad->ROW0_PORT0 ,keypad->ROW0_PIN0 ,DIO_PIN_LOW) ;
                    break ;
                case 1:
                    DIO_voidSetPinValue(keypad->ROW1_PORT1 ,keypad->ROW1_PIN1 ,DIO_PIN_LOW) ;
                    break ;
                
                case 2 :
                    DIO_voidSetPinValue(keypad->ROW2_PORT2 ,keypad->ROW2_PIN2 ,DIO_PIN_LOW) ;
                    break ;
                case 3:
                    DIO_voidSetPinValue(keypad->ROW3_PORT3 ,keypad->ROW3_PIN3 ,DIO_PIN_LOW) ;
                    break ;
                default :
                    break ;
                
            }
       
         
         
         for (int j = 0 ; j<4 ; j++){
             
               switch(j){
                
                case 0 :
                  DIO_voidGetPinValue(keypad->COL0_PORT0 ,keypad->COL0_PIN0 ,&get_value) ;
                  if (0==get_value){
                      
                      *value=arr[i][j] ;
                      
                  }
                  else {}
                      
                    break ;
                case 1:
                  DIO_voidGetPinValue(keypad->COL1_PORT1 ,keypad->COL1_PIN1 ,&get_value) ;
                  if (0==get_value){
                      
                      *value=arr[i][j] ;
                      
                  }
                 else {}
                  
                    break ;
                
                case 2 :
                  DIO_voidGetPinValue(keypad->COL2_PORT2 ,keypad->COL2_PIN2 ,&get_value) ;
                  if (0==get_value){
                      
                      *value=arr[i][j] ;
                      
                  }
                 else {}
                  
                    break ;
                case 3:
                  DIO_voidGetPinValue(keypad->COL3_PORT3 ,keypad->COL3_PIN3 ,&get_value) ;
                  if (0==get_value){
                      
                      *value=arr[i][j] ;
                      
                  }
                 else {}
                  
                    break ;
                    
                default :
                    
                    break ;
                
            }
             
             
         }
         
        
        
         
         
         
        }
       
   
     
     
    }
        
     
  



    return ret;


    
    
    
    
}