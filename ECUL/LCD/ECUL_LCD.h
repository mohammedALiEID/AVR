/* 
 * File:   ECUL_LCD.h
 * Author: sayr3
 *
 * Created on March 2, 2024, 10:52 AM
 */

#ifndef ECUL_LCD_H
#define	ECUL_LCD_H



/*section:*********includes*******************************/
#include "../../MCAL/DIO/MCAL_DIO.h"
#include <util/delay.h>


/*section:*********data types ***************************/
#define clear_display                                              0x1 
#define return_home                                                0x2
#define entery_mode_set_increment_display_shift_OFF                0x6
#define entery_mode_set_increment_display_shift_ON                 0x7 
#define entery_mode_set_decrement_display_shift_OFF                0x4 
#define entery_mode_set_decrement_display_shift_ON                 0x5
#define display_off_underline_cursor_off_blinking_cursor_off       0x8
#define display_off_underline_cursor_off_blinking_cursor_on        0x9
#define display_off_underline_cursor_on_blinking_cursor_on         0xB
#define display_off_underline_cursor_on_blinking_cursor_off        0xA
#define display_on_underline_cursor_off_blinking_cursor_off        0xC
#define display_on_underline_cursor_on_blinking_cursor_off         0xE
#define display_on_underline_cursor_off_blinking_cursor_on         0xD 
#define display_on_underline_cursor_on_blinking_cursor_on          0xF 
#define move_cursor_left                                           0x10
#define move_cursor_right                                          0x14
#define shift_display_left                                         0x18
#define shift_display_right                                        0x1c
#define function_set_8bit_mode_2_line_font_8_5                     0x38
#define function_set_4bit_mode_2_line_font_8_5                     0x28
#define start_address_of_CGRAM                                     0x40
#define start_address_of_DDRAM                                     0x80

#define ROW1                                                       1
#define ROW2                                                       2
#define ROW3                                                       3
#define ROW4                                                       4

/*section:*********macro functions declaration **********/



/*section:*********data types ***************************/
typedef struct {
    uint_8 lcd_RS_port  ;
    uint_8 lcd_RS_pin ;
    uint_8 lcd_E_port  ;
    uint_8 lcd_E_pin  ;
    uint_8 lcd_R_W_port  ;
    uint_8 lcd_R_W_pin  ;
    uint_8 lcd_dat_port0  ;
    uint_8 lcd_dat_pin0  ;
    uint_8 lcd_dat_port1  ;
    uint_8 lcd_dat_pin1  ;
    uint_8 lcd_dat_port2  ;
    uint_8 lcd_dat_pin2  ;
    uint_8 lcd_dat_port3  ;
    uint_8 lcd_dat_pin3  ;
    uint_8 lcd_dat_port4  ;
    uint_8 lcd_dat_pin4  ;
    uint_8 lcd_dat_port5  ;
    uint_8 lcd_dat_pin5  ;
    uint_8 lcd_dat_port6  ;
    uint_8 lcd_dat_pin6  ;
    uint_8 lcd_dat_port7  ;
    uint_8 lcd_dat_pin7  ;
    
    
}cha_lcd_8bit_t;

typedef struct {
    uint_8 lcd_RS_port  ;
    uint_8 lcd_RS_pin ;
    uint_8 lcd_E_port  ;
    uint_8 lcd_E_pin  ;
    uint_8 lcd_R_W_port  ;
    uint_8 lcd_R_W_pin  ;
    uint_8 lcd_dat_port0  ;
    uint_8 lcd_dat_pin0  ;
    uint_8 lcd_dat_port1  ;
    uint_8 lcd_dat_pin1  ;
    uint_8 lcd_dat_port2  ;
    uint_8 lcd_dat_pin2  ;
    uint_8 lcd_dat_port3  ;
    uint_8 lcd_dat_pin3  ;
    
}cha_lcd_4bit_t;




/*section:*********functions declaration*****************/

Std_ReturnType lcd_4bit_initalize (const cha_lcd_4bit_t*lcd ) ;
Std_ReturnType lcd_4bit_send_command (const cha_lcd_4bit_t*lcd , uint_8 command) ;
Std_ReturnType lcd_4bit_send_char_data (const cha_lcd_4bit_t*lcd , uint_8 data) ;
Std_ReturnType lcd_4bit_send_char_data_pos (const cha_lcd_4bit_t*lcd ,uint_8 row , uint_8 column , uint_8 data) ;
Std_ReturnType lcd_4bit_send_string (const cha_lcd_4bit_t*lcd , uint_8 *str) ;
Std_ReturnType lcd_4bit_send_string_pos (const cha_lcd_4bit_t*lcd ,uint_8 row , uint_8 column , uint_8 *str) ;
Std_ReturnType lcd_4bit_send_custom_char_pos (const cha_lcd_4bit_t*lcd ,uint_8 row , uint_8 column ,const uint_8 _cha[] ,uint_8 mem_pos) ;




Std_ReturnType lcd_8bit_initalize (const cha_lcd_8bit_t*lcd ) ;
Std_ReturnType lcd_8bit_send_command (const cha_lcd_8bit_t*lcd , uint_8 command) ;
Std_ReturnType lcd_8bit_send_char_data (const cha_lcd_8bit_t*lcd , uint_8 data) ;
Std_ReturnType lcd_8bit_send_char_data_pos (const cha_lcd_8bit_t*lcd ,uint_8 row , uint_8 column , uint_8 data) ;
Std_ReturnType lcd_8bit_send_string (const cha_lcd_8bit_t*lcd , uint_8 *str) ;
Std_ReturnType lcd_8bit_send_string_pos (const cha_lcd_8bit_t*lcd ,uint_8 row , uint_8 column , uint_8 *str) ;
Std_ReturnType lcd_8bit_send_custom_char_pos (const cha_lcd_8bit_t*lcd ,uint_8 row , uint_8 column ,const uint_8 _cha[] ,uint_8 mem_pos) ;


Std_ReturnType convert_uint_8_to_string(uint_8 value  , uint_8*str);
Std_ReturnType convert_uint_16_to_string(uint_16 value ,uint_8*str);
Std_ReturnType convert_uint_32_to_string(uint_32 value , uint_8*str);
Std_ReturnType convert_sint_8_to_string(sint_8 value  , uint_8*str) ;
Std_ReturnType convert_sint_16_to_string(sint_16 value ,uint_8*str) ;
Std_ReturnType convert_sint_32_to_string(sint_32 value , uint_8*str) ;




/*section:*********macro declaration*********************/


/*section:*********macro functions declaration **********/


/*section:*********functions declaration*****************/















#endif	/* ECUL_LCD_H */

