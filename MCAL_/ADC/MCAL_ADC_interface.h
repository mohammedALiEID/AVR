/* 
 * File:   MCAL_ADC_interface.h
 * Author: sayr3
 *
 * Created on March 4, 2024, 11:35 AM
 */

#ifndef MCAL_ADC_INTERFACE_H
#define	MCAL_ADC_INTERFACE_H

#include "mcal_ADC_regisrter.h" 
#include "../DIO/MCAL_DIO.h"
#include "../STD_libraries.h"
typedef enum {
 ADC0 =0 , 
 ADC1 =1 , 
 ADC2 =2 , 
 ADC3 =3 ,
 ADC4=4  ,
 ADC5  ,
 ADC6   ,
 ADC7        
}ADC_Chaneel_SE_t;

typedef enum {
 AREF =0 , 
 AVCC  , 
 Reserved  , 
 Internal_2_56V =3 ,
       
}ADC_Vref_t;






typedef struct {
  ADC_Chaneel_SE_t channel_select ;
  ADC_Vref_t ADC_vref   ;
 
}ADC_t;



void ADC_voidIntialize( ADC_t*ADC_) ;

void ADC_voidGetDigitalValue( ADC_t*ADC_ ,uint_16 *get_value ) ;







#endif	/* MCAL_ADC_INTERFACE_H */

