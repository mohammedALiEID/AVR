/* 
 * File:   MCAL_SPI_registers.h
 * Author: sayr3
 *
 * Created on March 5, 2024, 11:43 AM
 */

#ifndef MCAL_SPI_REGISTERS_H
#define	MCAL_SPI_REGISTERS_H

#include "../STD_data_types.h"
#include "../STD_libraries.h"
#include "../MCAL_BIT_MATH.h"

typedef struct {
    
  uint_8  SPCR_REG ;  
  uint_8  SPSR_REG ;   
  uint_8  SPDR_REG ;   
    
    
}SPI;

#define    SPI_REGS                             ((volatile SPI * )0x2D)



//SPCR ? SPI Control Register


#define  SPIE                         7
#define  SPE                          6
#define  DORD                         5
#define  MSTR                         4
#define  CPOL                         3
#define  CPHA                         2
#define  SPR1                         1
#define  SPR0                         0



//SPSR ? SPI Status Register


#define SPIF                             7
#define WCOL                             6
#define SPI2X                            0




//SPDR ? SPI Data Register








#endif	/* MCAL_SPI_REGISTERS_H */

