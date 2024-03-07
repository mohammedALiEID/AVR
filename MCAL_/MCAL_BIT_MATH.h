/* 
 * File:   MCAL_BIT_MATH.h
 * Author: sayr3
 *
 * Created on March 4, 2024, 3:34 AM
 */

#ifndef MCAL_BIT_MATH_H
#define	MCAL_BIT_MATH_H





#define set_bit(reg,bit_pos)              (reg|=(1<<bit_pos))    
#define clear_bit(reg,bit_pos)            (reg&=~(1<<bit_pos))
#define toggle_bit(reg,bit_pos)           (reg^=(1<<bit_pos))
#define read_bit(reg , bit_pos)           ((reg>>bit_pos)&1 )








#endif	/* MCAL_BIT_MATH_H */

