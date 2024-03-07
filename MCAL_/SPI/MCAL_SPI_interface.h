/* 
 * File:   MCAL_SPI_interface.h
 * Author: sayr3
 *
 * Created on March 5, 2024, 11:40 AM
 */

#ifndef MCAL_SPI_INTERFACE_H
#define	MCAL_SPI_INTERFACE_H

#include "MCAL_SPI_registers.h"

#define MASTER_MODE         0
#define SLAVE_MODE          1 



#define INTERRUPT_ENABLE    1
#define INTERRUPT_DISABLE   0


typedef struct {
    
  uint_8 tr_value ;
  uint_8 master_slave_mode :1 ;
  uint_8 Interrupt_Enable  : 1 ;
  void(*CALL_BACK_FU)(void) ;
  
  
}SPI_t;

void SPI_voidintialize( SPI_t*_SPI_ob) ; 
void SPI_voidDintialize( SPI_t*_SPI_ob) ; 
void SPI_voidTransmit_Recive_BYTE_BLocking( SPI_t*_SPI_ob ,uint_8*value) ; 
void SPI_VoidTransmit_Byte(SPI_t*_SPI_ob ) ;
void SPI_VoidRecive_Byte(uint_8*value ) ;





#endif	/* MCAL_SPI_INTERFACE_H */

