
/* 
 * File:   MCAL_DIO.c
 * Author: sayr3
 *
 * Created on February 29, 2024, 12:23 PM
 */

/*section:*********includes*******************************/
#include "MCAL_DIO.h"
/*section:*********implementation*******************************/

volatile uint_8*DDR_regisrers[4] = {DDRA, DDRB, DDRC, DDRD};
volatile uint_8*port_regisrers[4] = {PORTA, PORTB, PORTC, PORTD};
volatile uint_8*pin_regisrers[4] = {PINA, PINB, PINC, PIND};

/************************** Pin Apis ***************************************************/

/**
 * 
 * @param copy_u8PortId
 * @param copy_u8PinId
 * @param copy_u8PinDirection
 */
void DIO_voidSetPinDirection(uint_8 copy_u8PortId, uint_8 copy_u8PinId, uint_8 copy_u8PinDirection) {

    switch (copy_u8PinDirection) {
        case DIO_PIN_INPUT:
            clear_bit(*DDR_regisrers[copy_u8PortId], copy_u8PinId);

            break;

        case DIO_PIN_OUTPUT:

            set_bit(*DDR_regisrers[copy_u8PortId], copy_u8PinId);

            break;

        default:


            break;


    }





}
/**
 * 
 * @param copy_u8PortId
 * @param copy_u8PinId
 * @param copy_u8PinValue
 */
void DIO_voidSetPinValue(uint_8 copy_u8PortId, uint_8 copy_u8PinId, uint_8 copy_u8PinValue) {

    switch (copy_u8PinValue) {
        case DIO_PIN_LOW:

            clear_bit(*port_regisrers[copy_u8PortId], copy_u8PinId);

            break;

        case DIO_PIN_HIGH:

            set_bit(*port_regisrers[copy_u8PortId], copy_u8PinId);

            break;

        default:

            break;


    }



}
/**
 * 
 * @param copy_u8PortId
 * @param copy_u8PinId
 * @param copy_pu8PinValue
 */

void DIO_voidGetPinValue(uint_8 copy_u8PortId, uint_8 copy_u8PinId, uint_8* copy_pu8PinValue) {


 *copy_pu8PinValue=read_bit(*pin_regisrers[copy_u8PortId] ,copy_u8PinId) ;
    
    
}


/**
 * 
 * @param copy_u8PortId
 * @param copy_u8PinId
 */
void DIO_voidTogglePinValue(uint_8 copy_u8PortId, uint_8 copy_u8PinId) {

    
    toggle_bit(*port_regisrers[copy_u8PortId] ,copy_u8PinId) ;

}
/**
 * 
 * @param copy_u8PortId
 * @param copy_u8PinId
 */
void DIO_voidActivePinInPullUpResistance(uint_8 copy_u8PortId, uint_8 copy_u8PinId) {

    clear_bit(*DDR_regisrers[copy_u8PortId], copy_u8PinId);
    set_bit(*port_regisrers[copy_u8PortId], copy_u8PinId);
    

}

/* ********************Port Apis ***********************************************/

/**
 * 
 * @param copy_u8PortId
 * @param copy_u8PortDirection
 */
void DIO_voidSetPortDirection(uint_8 copy_u8PortId, uint_8 copy_u8PortDirection) {

*DDR_regisrers[copy_u8PortId] = copy_u8PortDirection ;
    


}
/**
 * 
 * @param copy_u8PortId
 * @param copy_u8PortValue
 */
void DIO_voidSetPortValue(uint_8 copy_u8PortId, uint_8 copy_u8PortValue) {

*port_regisrers[copy_u8PortId] =copy_u8PortValue ;
}
/**
 * 
 * @param copy_u8PortId
 * @param copy_pu8PortValue
 */

void DIO_voidGetPortValue(uint_8 copy_u8PortId, uint_8* copy_pu8PortValue) {
    
* copy_pu8PortValue =*pin_regisrers[copy_u8PortId] ;

}
/**
 * 
 * @param copy_u8PortId
 */
void DIO_voidTogglePortValue(uint_8 copy_u8PortId) {

    (*port_regisrers[copy_u8PortId])^=PORTC_MASK ;

}
/**
 * 
 * @param copy_u8PortId
 */
void DIO_voidActivePortInPullUpResistance(uint_8 copy_u8PortId) {

    *DDR_regisrers[copy_u8PortId]=0x0 ;
    *port_regisrers[copy_u8PortId]=0xFF ;
    

}