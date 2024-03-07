
/* 
 * File:   external_IT.h
 * Author: sayr3
 *
 * Created on March 3, 2024, 1:01 PM
 */

#include "external_IT.h" 
#include "external_regesters.h"
#include "../MCAL_BIT_MATH.h"
#include "../STD_libraries.h"
#include "../STD_data_types.h"

void(*interrupt_hundler_INT0_)(void);
void(*interrupt_hundler_INT1_)(void);
void(*interrupt_hundler_INT2_)(void);
/**
 * 
 * @param _EXTI
 */
void EXTI_VoidEnableE(const EXTI_t*_EXTI) {

    switch (_EXTI->InterruptSource) {

        case EXTI_INT0:
            
            switch (_EXTI->SenseControl) {
                case EXTI_RISING_EDGE:

                    set_bit(MCUCR_REG, ISC00);
                    set_bit(MCUCR_REG, ISC01);
                    break;

                case EXTI_FALLING_EDGE:

                    clear_bit(MCUCR_REG, ISC00);
                    set_bit(MCUCR_REG, ISC01);
                    break;


                case EXTI_LOW_LEVEL:

                    clear_bit(MCUCR_REG, ISC00);
                    clear_bit(MCUCR_REG, ISC01);
                    break;


                case EXTI_ANY_LOGICAL_CHANGE:
                    set_bit(MCUCR_REG, ISC00);
                    clear_bit(MCUCR_REG, ISC01);

                    break;



            }
            
            set_bit(GICR_REG, INT0);
            interrupt_hundler_INT0_=_EXTI->interrupt_handler_INT0 ;

            break;

        case EXTI_INT1:

            switch (_EXTI->SenseControl) {
                case EXTI_RISING_EDGE:

                    set_bit(MCUCR_REG, ISC10);
                    set_bit(MCUCR_REG, ISC11);
                    break;

                case EXTI_FALLING_EDGE:

                    clear_bit(MCUCR_REG, ISC10);
                    set_bit(MCUCR_REG, ISC11);
                    break;


                case EXTI_LOW_LEVEL:

                    clear_bit(MCUCR_REG, ISC10);
                    clear_bit(MCUCR_REG, ISC11);
                    break;


                case EXTI_ANY_LOGICAL_CHANGE:
                    set_bit(MCUCR_REG, ISC10);
                    clear_bit(MCUCR_REG, ISC11);

                    break;



            }
            set_bit(GICR_REG, INT1);
            interrupt_hundler_INT1_=_EXTI->interrupt_handler_INT1 ;

            break;


        case EXTI_INT2:

            switch (_EXTI->SenseControl) {
                case EXTI_RISING_EDGE :

                    set_bit(MCUCSR_REG,ISC2);
                   
                    break;

                case EXTI_FALLING_EDGE:

                    clear_bit(MCUCSR_REG,ISC2) ;
                   
                    break;
            
            
            }
            
            
            set_bit(GICR_REG, INT2);
            
            interrupt_hundler_INT2_=_EXTI->interrupt_handler_INT2 ;
            
            break;

           default: break;

            
    }


}
/**
 * 
 * @param _EXTI
 */
void EXTI_VOidDisable(const EXTI_t*_EXTI) {

    switch (_EXTI->InterruptSource) {

        case EXTI_INT0:
            clear_bit(GICR_REG, INT0);
            break;

        case EXTI_INT1:
            clear_bit(GICR_REG, INT1);
            break;

        case EXTI_INT2:
            clear_bit(GICR_REG, INT2);
            break;


    }



}



void __vector_1(void) __attribute__((signal)); // INT0

void __vector_1(void) {

    if (interrupt_hundler_INT0_) {

        interrupt_hundler_INT0_();
    }

}



void __vector_2(void) __attribute__((signal)); // INT1

void __vector_2(void) {

    if (interrupt_hundler_INT1_) {

        interrupt_hundler_INT1_();
    }

}


void __vector_3(void) __attribute__((signal)); // INT2

void __vector_3(void) {

    if (interrupt_hundler_INT2_) {

        interrupt_hundler_INT2_();
    }

}