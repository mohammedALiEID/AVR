/* 
 * File:   MCAL_DIO_REGISTERS.h
 * Author: sayr3
 *
 * Created on February 29, 2024, 1:16 PM
 */

#ifndef MCAL_DIO_REGISTERS_H
#define	MCAL_DIO_REGISTERS_H

/*section:*********includes*******************************/
#include "../STD_data_types.h"

/*section:*********data types ***************************/


/*section:*********macro declaration*********************/
#define DDRA        ((volatile uint_8 *)(0x3A)) 
#define DDRB        ((volatile uint_8 *)(0x37)) 
#define DDRC        ((volatile uint_8 *)(0x34)) 
#define DDRD        ((volatile uint_8 *)(0x31)) 

#define PORTA       ((volatile uint_8 *)(0x3B)) 
#define PORTB       ((volatile uint_8 *)(0x38)) 
#define PORTC       ((volatile uint_8 *)(0x35)) 
#define PORTD       ((volatile uint_8 *)(0x32)) 
 
#define PINA        ((volatile uint_8 *)(0x39)) 
#define PINB        ((volatile uint_8 *)(0x36)) 
#define PINC        ((volatile uint_8 *)(0x33)) 
#define PIND        ((volatile uint_8 *)(0x30)) 

#define BIT_MASK    0x1
#define PORTC_MASK  0xFF

/*section:*********macro functions declaration **********/
#define set_bit(reg,bit_pos)              (reg|=(BIT_MASK<<bit_pos))    
#define clear_bit(reg,bit_pos)            (reg&=~(BIT_MASK<<bit_pos))
#define toggle_bit(reg,bit_pos)           (reg^=(BIT_MASK<<bit_pos))
#define read_bit(reg , bit_pos)           ((reg>>bit_pos)&BIT_MASK )

/*section:*********functions declaration*****************/







#endif	/* MCAL_DIO_REGISTERS_H */

