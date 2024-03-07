/* 
 * File:   mcal_ADC_regisrter.h
 * Author: sayr3
 *
 * Created on March 4, 2024, 11:36 AM
 */
#include "../STD_data_types.h"

#ifndef MCAL_ADC_REGISRTER_H
#define	MCAL_ADC_REGISRTER_H

#define ADMUX_RGE         (*(volatile uint_8 *)0x27)   //ADMUX ? ADC Multiplexer Selection Register

#define REFS0           6
#define REFS1           7
#define ADLAR           5
#define MUX0            0
#define MUX1            1
#define MUX2            2
#define MUX3            3
#define MUX4            4



#define ADCSRA_RGE         (*(volatile uint_8 *)0x26)  //ADC Control and Status Register A


#define ADEN                 7           
#define ADSC                 6           
#define ADATE                5           
#define ADIF                 4            
#define ADIE                 3            
#define ADPS0                0
#define ADPS1                1
#define ADPS2                2

#define ADC_GET_Value        (*(volatile uint_16*)0x24)


#define SFIOR_RGE           (*(volatile uint_8 *)0x50)   //? Special FunctionIO Register


#define ADCL_REG            (*(volatile uint_8 *)0x24)
#define ADCH_REG            (*(volatile uint_8 *)0x25)





#endif	/* MCAL_ADC_REGISRTER_H */

