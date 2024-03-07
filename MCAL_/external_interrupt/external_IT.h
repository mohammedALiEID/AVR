/* 
 * File:   external_IT.h
 * Author: sayr3
 *
 * Created on March 3, 2024, 1:01 PM
 */

#ifndef EXTERNAL_IT_H
#define	EXTERNAL_IT_H






typedef enum{
    
    EXTI_INT0 = 0 ,
    EXTI_INT1  ,
    EXTI_INT2  ,
            
    
    
}EXTI_source_t;


typedef enum{
    
  EXTI_RISING_EDGE = 0 ,
  EXTI_FALLING_EDGE  ,
  EXTI_LOW_LEVEL ,
  EXTI_ANY_LOGICAL_CHANGE         
    
    
}EXTI_senseControl_t;

typedef struct {
    
    EXTI_source_t InterruptSource ;
    EXTI_senseControl_t SenseControl ;
    void(*interrupt_handler_INT0)(void) ;
    void(*interrupt_handler_INT1)(void) ;
    void(*interrupt_handler_INT2)(void) ;
    
}EXTI_t;


//enable and initialize
void EXTI_VoidEnableE(const EXTI_t*_EXTI) ;
void EXTI_VOidDisable(const EXTI_t*_EXTI) ;





#endif	/* EXTERNAL_IT_H */
