

/* 
 * File:   GINT.h
 * Author: sayr3
 *
 * Created on March 3, 2024, 1:59 PM
 */

#include "../DIO/MCAL_DIO.h"
#include "GINT.h"
void GI_VoidEnable(void) {
    
    set_bit(SREG_REG ,I) ;
    
}
void GI_VoidDiSable(void) {
    
    
     clear_bit(SREG_REG ,I) ;
    
}
