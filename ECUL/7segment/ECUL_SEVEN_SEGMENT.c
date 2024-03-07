
/* 
 * File:   ECUL_SEVEN_SEGMENY.c
 * Author: sayr3
 *
 * Created on March 1, 2024, 1:23 PM
 */
#include "ECUL_SEVEN_SEGMENY.h" 
/**
 * 
 * @param s_segment
 */

void seven_segment_initialization(const seven_segment_t*s_segment) {

    DIO_voidSetPinDirection(s_segment->port0, s_segment->pin0, DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(s_segment->port1, s_segment->pin1, DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(s_segment->port2, s_segment->pin2, DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(s_segment->port3, s_segment->pin3, DIO_PIN_OUTPUT);
    
    
}
/**
 * 
 * @param s_segment
 * @param number
 */
void seven_segment_write_number(const seven_segment_t*s_segment, uint_8 number) {


    DIO_voidSetPinValue(s_segment->port0, s_segment->pin0, (number >> 0)&0x1);
    DIO_voidSetPinValue(s_segment->port1, s_segment->pin1, (number >> 1)&0x1);
    DIO_voidSetPinValue(s_segment->port2, s_segment->pin2, (number >> 2)&0x1);
    DIO_voidSetPinValue(s_segment->port3, s_segment->pin3, (number >> 3)&0x1);
}
