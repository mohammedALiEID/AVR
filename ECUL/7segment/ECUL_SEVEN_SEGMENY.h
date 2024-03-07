/* 
 * File:   ECUL_SEVEN_SEGMENY.h
 * Author: sayr3
 *
 * Created on March 1, 2024, 1:23 PM
 */

#ifndef ECUL_SEVEN_SEGMENY_H
#define	ECUL_SEVEN_SEGMENY_H

/*section:*********includes*******************************/
#include "../../MCAL/DIO/MCAL_DIO.h"


/*section:*********data types ***************************/
typedef enum{
    SEGMENT_COMMON_cathod ,
    SEGMENT_COMMON_anod 

}segment_type_t;
typedef struct {
    
    uint_8 port0 ;
    uint_8 pin0 ;
    uint_8 port1 ;
    uint_8 pin1 ;
    uint_8 port2 ;
    uint_8 pin2 ;
    uint_8 port3 ;
    uint_8 pin3 ;
    
    segment_type_t segment_type ;
    
}seven_segment_t;
/*section:*********macro declaration*********************/

/*section:*********macro functions declaration **********/


/*section:*********functions declaration*****************/

void seven_segment_initialization (const seven_segment_t*s_segment ) ;
void seven_segment_write_number (const seven_segment_t*s_segment  , uint_8 number) ;



/*section:*********macro declaration*********************/


/*section:*********macro functions declaration **********/


/*section:*********functions declaration*****************/





























#endif	/* ECUL_SEVEN_SEGMENY_H */

