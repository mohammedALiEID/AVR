/* 
 * File:   MCAL_DIO.h
 * Author: sayr3
 *
 * Created on February 29, 2024, 12:23 PM
 */

#ifndef MCAL_DIO_H
#define	MCAL_DIO_H
/*section:*********includes*******************************/

#include "../STD_libraries.h"
#include "MCAL_DIO_REGISTERS.h"

/*section:*********data types ***************************/


/*section:*********macro declaration*********************/

                             /*************** MACROS FOR PORT ***************/
/* macros for port id */
#define DIO_PORTA			    0
#define DIO_PORTB			    1
#define DIO_PORTC			    2
#define DIO_PORTD			    3

/* macros for port direction */
#define DIO_PORT_INPUT          0x00
#define DIO_PORT_OUTPUT			0xff

/* macros for port value */
#define DIO_PORT_LOW            0x00
#define DIO_PORT_HIGH			0xff

                             /*************** MACROS FOR PIN ***************/
/* macros for pin id */
#define DIO_PIN0			    0
#define DIO_PIN1			    1
#define DIO_PIN2			    2
#define DIO_PIN3			    3
#define DIO_PIN4			    4
#define DIO_PIN5			    5
#define DIO_PIN6			    6
#define DIO_PIN7			    7

/* macros for pin direction */
#define DIO_PIN_INPUT           0
#define DIO_PIN_OUTPUT			1

/* macros for pin value */
#define DIO_PIN_LOW             0
#define DIO_PIN_HIGH			1


                             /*************** APIS PROTO TYPES ***************/
/* Pin Apis */							
void DIO_voidSetPinDirection            (uint_8 copy_u8PortId, uint_8 copy_u8PinId, uint_8 copy_u8PinDirection);
void DIO_voidSetPinValue                (uint_8 copy_u8PortId, uint_8 copy_u8PinId, uint_8 copy_u8PinValue);
void DIO_voidGetPinValue                (uint_8 copy_u8PortId, uint_8 copy_u8PinId, uint_8* copy_pu8PinValue);
void DIO_voidTogglePinValue             (uint_8 copy_u8PortId, uint_8 copy_u8PinId);
void DIO_voidActivePinInPullUpResistance(uint_8 copy_u8PortId, uint_8 copy_u8PinId);

/* Port Apis */	
void DIO_voidSetPortDirection            (uint_8 copy_u8PortId, uint_8 copy_u8PortDirection);
void DIO_voidSetPortValue                (uint_8 copy_u8PortId, uint_8 copy_u8PortValue);
void DIO_voidGetPortValue                (uint_8 copy_u8PortId, uint_8* copy_pu8PortValue);
void DIO_voidTogglePortValue             (uint_8 copy_u8PortId);
void DIO_voidActivePortInPullUpResistance(uint_8 copy_u8PortId);



/*section:*********macro functions declaration **********/


/*section:*********functions declaration*****************/









#endif	/* MCAL_DIO_H */

