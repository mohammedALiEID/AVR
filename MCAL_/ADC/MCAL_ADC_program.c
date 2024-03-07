
/* 
 * File:   MCAL_ADC_program.c
 * Author: sayr3
 *
 * Created on March 4, 2024, 11:35 AM
 */

#include "MCAL_ADC_interface.h" 


void ADC_voidIntialize( ADC_t*ADC_) {
    
    
     clear_bit(ADCSRA_RGE ,ADEN) ;
     
    switch (ADC_->ADC_vref) {
        
        case AREF : clear_bit(ADMUX_RGE ,REFS0)  ;  clear_bit(ADMUX_RGE ,REFS1)  ;  break ;   
        case AVCC : set_bit(ADMUX_RGE ,REFS0)  ;  clear_bit(ADMUX_RGE ,REFS1)  ; break ;  
        case Reserved :   break ;
        case Internal_2_56V :  set_bit(ADMUX_RGE ,REFS0)  ; set_bit(ADMUX_RGE ,REFS1) ;break ; 
            
        
        
    }
    
    
     
     clear_bit(ADMUX_RGE ,ADLAR) ;
     set_bit(ADCSRA_RGE ,ADPS0) ;
     set_bit(ADCSRA_RGE ,ADPS1) ;        
     set_bit(ADCSRA_RGE ,ADPS2) ;
     clear_bit(ADCSRA_RGE ,ADIE) ;
     clear_bit(ADCSRA_RGE ,ADATE) ;
     set_bit(ADCSRA_RGE ,ADEN) ;
    
}

void ADC_voidGetDigitalValue( ADC_t*ADC_ ,uint_16 *get_value ) {
  
    
    
    ADMUX_RGE &=(0xE0) ;
    ADMUX_RGE|=(ADC_->channel_select)  ;
        
    
    set_bit(ADCSRA_RGE ,ADSC) ;
    
    
    while((read_bit(ADCSRA_RGE ,ADIF)==0)) ;
    
    
    set_bit(ADCSRA_RGE ,ADIF) ;
    
    
    *get_value=(ADC_GET_Value );
    
    
    
    
}

