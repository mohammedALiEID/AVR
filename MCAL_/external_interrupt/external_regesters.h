/* 
 * File:   external_regesters.h
 * Author: sayr3
 *
 * Created on March 3, 2024, 1:03 PM
 */

#ifndef EXTERNAL_REGESTERS_H
#define	EXTERNAL_REGESTERS_H

#define MCUCR_REG         (*((volatile uint_8 *)(0x55)))

#define ISC00              0
#define ISC01              1
#define ISC10              2
#define ISC11              3


#define MCUCSR_REG        (*((volatile uint_8 *)(0x54)))

#define  ISC2              6

#define GICR_REG          (*((volatile uint_8 *)(0x5B))) 

#define INT2                5

#define INT0                6
 
#define INT1                7
 


#define GIFR_REG          (*((volatile uint_8 *)(0x5A)))

#define INTF2               5

#define INTF0               6

#define INTF1               7




#endif	/* EXTERNAL_REGESTERS_H */

