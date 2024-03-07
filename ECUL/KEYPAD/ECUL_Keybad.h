/* 
 * File:   ECUL_Keybad.h
 * Author: sayr3
 *
 * Created on March 4, 2024, 3:30 AM
 */

#ifndef ECUL_KEYBAD_H
#define	ECUL_KEYBAD_H


/*section:*********includes*******************************/

#include "../../MCAL/DIO/MCAL_DIO.h"


/*section:*********data types ***************************/
typedef struct {
  uint_8 ROW0_PORT0 ;
  uint_8 ROW0_PIN0  ;
  uint_8 ROW1_PORT1 ;
  uint_8 ROW1_PIN1 ; 
  uint_8 ROW2_PORT2 ;
  uint_8 ROW2_PIN2 ; 
  uint_8 ROW3_PORT3 ;
  uint_8 ROW3_PIN3 ; 
  
  uint_8 COL0_PORT0 ;
  uint_8 COL0_PIN0  ;
  uint_8 COL1_PORT1 ;
  uint_8 COL1_PIN1 ; 
  uint_8 COL2_PORT2 ;
  uint_8 COL2_PIN2 ; 
  uint_8 COL3_PORT3 ;
  uint_8 COL3_PIN3 ; 
    
    
    
}Keypad_t;

/*section:*********macro declaration*********************/


/*section:*********macro functions declaration **********/


/*section:*********functions declaration*****************/






Std_ReturnType keypad_STDIntialization (const Keypad_t *keypad);
Std_ReturnType keypad_STDGet_written_value (const Keypad_t *keypad , uint_8 * value);







#endif	/* ECUL_KEYBAD_H */

