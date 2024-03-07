
/* 
 * File:   MCAL_SPI_interface.c
 * Author: sayr3
 *
 * Created on March 5, 2024, 11:40 AM
 */

#include "MCAL_SPI_interface.h"
#include <util/delay.h>
#include "AVR/io.h"


void(*Interrupt_handler)(void);
/**
 * 
 * @param _SPI_ob
 */
void SPI_voidintialize(SPI_t*_SPI_ob) {

//select master slave 

    switch (_SPI_ob->master_slave_mode) {

        case MASTER_MODE:
            set_bit(SPI_REGS->SPCR_REG, MSTR);
            set_bit(SPI_REGS->SPCR_REG, SPR0);
            set_bit(SPI_REGS->SPCR_REG, SPR1);
            clear_bit(SPI_REGS->SPSR_REG, SPI2X);


            break;

        case SLAVE_MODE:
            clear_bit(SPI_REGS->SPCR_REG, MSTR);

            break;


    }
// enable disable SPI interrupt 
    
    switch (_SPI_ob->Interrupt_Enable) {

        case INTERRUPT_ENABLE:

            set_bit(SPI_REGS->SPCR_REG, SPIE);
            Interrupt_handler=_SPI_ob->CALL_BACK_FU ;

            break;

        case INTERRUPT_DISABLE:

            clear_bit(SPI_REGS->SPCR_REG, SPIE);
            break;


    }

        //Data Order
    set_bit(SPI_REGS->SPCR_REG, DORD);

    // clock synchronization 
    clear_bit(SPI_REGS->SPCR_REG, CPOL);
    set_bit(SPI_REGS->SPCR_REG, CPHA);

      // SPI MODULE ENABLE 
    set_bit(SPI_REGS->SPCR_REG, SPE);



}
/**
 * 
 * @param _SPI_ob
 */
void SPI_voidDintialize( SPI_t*_SPI_ob) {
    
        // SPI MODULE DISABLE
    clear_bit(SPI_REGS->SPCR_REG, SPE);
    // disable interrupt
    clear_bit(SPI_REGS->SPCR_REG, SPIE);
}
/**
 * 
 * @param _SPI_ob
 * @param value
 */
void SPI_voidTransmit_Recive_BYTE(SPI_t*_SPI_ob, uint_8*value) {



    SPI_REGS->SPDR_REG = _SPI_ob->tr_value;


    while (read_bit(SPI_REGS->SPSR_REG, SPIF) == 0);


    *value = SPI_REGS->SPDR_REG;




}
/**
 * 
 * @param _SPI_ob
 */
void SPI_VoidTransmit_Byte(SPI_t*_SPI_ob) {

 SPI_REGS->SPDR_REG = _SPI_ob->tr_value;

}

void SPI_VoidRecive_Byte(uint_8*value) {

    *value = SPI_REGS->SPDR_REG;

}

void __vector_12(void) __attribute__((signal));

void __vector_12(void) {

    if (Interrupt_handler) {

        Interrupt_handler();

    }

}