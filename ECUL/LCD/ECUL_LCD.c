/* 
 * File:   ECUL_LCD.h
 * Author: sayr3
 *
 * Created on March 2, 2024, 10:52 AM
 */


/*section:*********includes*******************************/
#include "ECUL_LCD.h"
/*section:*********static helper function*******************************/

static Std_ReturnType lcd_send_4bit(const cha_lcd_4bit_t*lcd, uint_8 data_command);
static Std_ReturnType lcd_4bit_send_enable_signal(const cha_lcd_4bit_t*lcd);
static Std_ReturnType lcd_8bit_send_enable_signal(const cha_lcd_8bit_t*lcd);
static Std_ReturnType lcd_8bit_set_cursor(const cha_lcd_8bit_t*lcd, uint_8 row, uint_8 column);
static Std_ReturnType lcd_4bit_set_cursor(const cha_lcd_4bit_t*lcd, uint_8 row, uint_8 column);

/*section:*********function definition*******************************/

/**
 * 
 * @param lcd
 * @return  
 */
Std_ReturnType lcd_4bit_initalize(const cha_lcd_4bit_t*lcd) {
    Std_ReturnType ret = E_OK;

    if (NULL == lcd) {
        ret = E_NOT_OK;

    } else {

        DIO_voidSetPinDirection(lcd->lcd_E_port, lcd->lcd_E_pin, DIO_PIN_OUTPUT);
        DIO_voidSetPinDirection(lcd->lcd_RS_port, lcd->lcd_RS_pin, DIO_PIN_OUTPUT);
        DIO_voidSetPinDirection(lcd->lcd_R_W_port, lcd->lcd_R_W_pin, DIO_PIN_OUTPUT);
        DIO_voidSetPinDirection(lcd->lcd_dat_port0, lcd->lcd_dat_pin0, DIO_PIN_OUTPUT);
        DIO_voidSetPinDirection(lcd->lcd_dat_port1, lcd->lcd_dat_pin1, DIO_PIN_OUTPUT);
        DIO_voidSetPinDirection(lcd->lcd_dat_port2, lcd->lcd_dat_pin2, DIO_PIN_OUTPUT);
        DIO_voidSetPinDirection(lcd->lcd_dat_port3, lcd->lcd_dat_pin3, DIO_PIN_OUTPUT);


        _delay_ms(20);
        ret = lcd_4bit_send_command(lcd, function_set_8bit_mode_2_line_font_8_5);
        _delay_ms(20);
        ret = lcd_4bit_send_command(lcd, function_set_8bit_mode_2_line_font_8_5);

        _delay_ms(20);
        ret = lcd_4bit_send_command(lcd, function_set_8bit_mode_2_line_font_8_5);


        ret = lcd_4bit_send_command(lcd, clear_display);
        ret = lcd_4bit_send_command(lcd, return_home);
        ret = lcd_4bit_send_command(lcd, entery_mode_set_increment_display_shift_OFF);
        ret = lcd_4bit_send_command(lcd, display_on_underline_cursor_off_blinking_cursor_off);
        ret = lcd_4bit_send_command(lcd, function_set_4bit_mode_2_line_font_8_5);
        ret = lcd_4bit_send_command(lcd, start_address_of_DDRAM);







    }




    return ret;




}

/**
 * 
 * @param lcd
 * @param command
 * @return 
 */

Std_ReturnType lcd_4bit_send_command(const cha_lcd_4bit_t*lcd, uint_8 command) {
    Std_ReturnType ret = E_OK;

    if (NULL == lcd) {
        ret = E_NOT_OK;

    } else {

        DIO_voidSetPinValue(lcd->lcd_RS_port, lcd->lcd_RS_pin, DIO_PIN_LOW);

        DIO_voidSetPinValue(lcd->lcd_R_W_port, lcd->lcd_R_W_pin, DIO_PIN_LOW);

        ret = lcd_send_4bit(lcd, command >> 4);
        ret = lcd_4bit_send_enable_signal(lcd);
        ret = lcd_send_4bit(lcd, command);
        ret = lcd_4bit_send_enable_signal(lcd);
    }




    return ret;



}

/**
 * 
 * @param lcd
 * @param data
 * @return 
 */
Std_ReturnType lcd_4bit_send_char_data(const cha_lcd_4bit_t*lcd, uint_8 data) {
    Std_ReturnType ret = E_OK;

    if (NULL == lcd) {
        ret = E_NOT_OK;

    } else {


        DIO_voidSetPinValue(lcd->lcd_RS_port, lcd->lcd_RS_pin, DIO_PIN_HIGH);

        DIO_voidSetPinValue(lcd->lcd_R_W_port, lcd->lcd_R_W_pin, DIO_PIN_LOW);
        ret = lcd_send_4bit(lcd, data >> 4);
        ret = lcd_4bit_send_enable_signal(lcd);
        ret = lcd_send_4bit(lcd, data);
        ret = lcd_4bit_send_enable_signal(lcd);







    }




    return ret;





}

/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param data
 * @return 
 */
Std_ReturnType lcd_4bit_send_char_data_pos(const cha_lcd_4bit_t*lcd, uint_8 row, uint_8 column, uint_8 data) {
    Std_ReturnType ret = E_OK;

    if (NULL == lcd) {
        ret = E_NOT_OK;

    } else {


        lcd_4bit_set_cursor(lcd, row, column);
        lcd_4bit_send_char_data(lcd, data);




    }




    return ret;





}

/**
 * 
 * @param lcd
 * @param str
 * @return 
 */

Std_ReturnType lcd_4bit_send_string(const cha_lcd_4bit_t*lcd, uint_8 *str) {
    Std_ReturnType ret = E_OK;

    if (NULL == lcd || NULL == str) {
        ret = E_NOT_OK;

    } else {


        while (*str) {


            lcd_4bit_send_char_data(lcd, *str++);

        }




    }




    return ret;





}

/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param str
 * @return 
 */

Std_ReturnType lcd_4bit_send_string_pos(const cha_lcd_4bit_t*lcd, uint_8 row, uint_8 column, uint_8 *str) {
    Std_ReturnType ret = E_OK;
    if (NULL == lcd || NULL == str) {
        ret = E_NOT_OK;

    } else {



        lcd_4bit_set_cursor(lcd, row, column);
        lcd_4bit_send_string(lcd, str);




    }




    return ret;



}

/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param _cha
 * @param mem_pos
 * @return 
 */
Std_ReturnType lcd_4bit_send_custom_char_pos(const cha_lcd_4bit_t*lcd, uint_8 row, uint_8 column, const uint_8 _cha[], uint_8 mem_pos) {
    Std_ReturnType ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;

    } else {



        lcd_4bit_send_command(lcd, start_address_of_CGRAM + 8 * mem_pos);

        for (int i = 0; i < 8; i++) {


            lcd_4bit_send_char_data(lcd, _cha[i]);


        }

        lcd_4bit_send_char_data_pos(lcd, row, column, mem_pos);



    }




    return ret;


}

/**
 * 
 * @param lcd
 * @return 
 */
Std_ReturnType lcd_8bit_initalize(const cha_lcd_8bit_t*lcd) {

    Std_ReturnType ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;

    } else {



        DIO_voidSetPinDirection(lcd->lcd_E_port, lcd->lcd_E_pin, DIO_PIN_OUTPUT);
        DIO_voidSetPinDirection(lcd->lcd_RS_port, lcd->lcd_RS_pin, DIO_PIN_OUTPUT);
        DIO_voidSetPinDirection(lcd->lcd_R_W_port, lcd->lcd_R_W_pin, DIO_PIN_OUTPUT);
        DIO_voidSetPinDirection(lcd->lcd_dat_port0, lcd->lcd_dat_pin0, DIO_PIN_OUTPUT);
        DIO_voidSetPinDirection(lcd->lcd_dat_port1, lcd->lcd_dat_pin1, DIO_PIN_OUTPUT);
        DIO_voidSetPinDirection(lcd->lcd_dat_port2, lcd->lcd_dat_pin2, DIO_PIN_OUTPUT);
        DIO_voidSetPinDirection(lcd->lcd_dat_port3, lcd->lcd_dat_pin3, DIO_PIN_OUTPUT);

        DIO_voidSetPinDirection(lcd->lcd_dat_port4, lcd->lcd_dat_pin4, DIO_PIN_OUTPUT);
        DIO_voidSetPinDirection(lcd->lcd_dat_port5, lcd->lcd_dat_pin5, DIO_PIN_OUTPUT);
        DIO_voidSetPinDirection(lcd->lcd_dat_port6, lcd->lcd_dat_pin6, DIO_PIN_OUTPUT);
        DIO_voidSetPinDirection(lcd->lcd_dat_port7, lcd->lcd_dat_pin7, DIO_PIN_OUTPUT);


        _delay_ms(20);
        ret = lcd_8bit_send_command(lcd, function_set_8bit_mode_2_line_font_8_5);
        _delay_ms(20);
        ret = lcd_8bit_send_command(lcd, function_set_8bit_mode_2_line_font_8_5);

        _delay_ms(20);
        ret = lcd_8bit_send_command(lcd, function_set_8bit_mode_2_line_font_8_5);


        ret = lcd_8bit_send_command(lcd, clear_display);
        ret = lcd_8bit_send_command(lcd, return_home);
        ret = lcd_8bit_send_command(lcd, entery_mode_set_increment_display_shift_OFF);
        ret = lcd_8bit_send_command(lcd, display_on_underline_cursor_off_blinking_cursor_off);
        ret = lcd_8bit_send_command(lcd, start_address_of_DDRAM);




    }




    return ret;





}

/**
 * 
 * @param lcd
 * @param command
 * @return 
 */
Std_ReturnType lcd_8bit_send_command(const cha_lcd_8bit_t*lcd, uint_8 command) {
    Std_ReturnType ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;

    } else {

        DIO_voidSetPinValue(lcd->lcd_RS_port, lcd->lcd_RS_pin, DIO_PIN_LOW);

        DIO_voidSetPinValue(lcd->lcd_R_W_port, lcd->lcd_R_W_pin, DIO_PIN_LOW);

        DIO_voidSetPinValue(lcd->lcd_dat_port0, lcd->lcd_dat_pin0, (command >> 0)&1);
        DIO_voidSetPinValue(lcd->lcd_dat_port1, lcd->lcd_dat_pin1, (command >> 1)&1);
        DIO_voidSetPinValue(lcd->lcd_dat_port2, lcd->lcd_dat_pin2, (command >> 2)&1);
        DIO_voidSetPinValue(lcd->lcd_dat_port3, lcd->lcd_dat_pin3, (command >> 3)&1);
        DIO_voidSetPinValue(lcd->lcd_dat_port4, lcd->lcd_dat_pin4, (command >> 4)&1);
        DIO_voidSetPinValue(lcd->lcd_dat_port5, lcd->lcd_dat_pin5, (command >> 5)&1);
        DIO_voidSetPinValue(lcd->lcd_dat_port6, lcd->lcd_dat_pin6, (command >> 6)&1);
        DIO_voidSetPinValue(lcd->lcd_dat_port7, lcd->lcd_dat_pin7, (command >> 7)&1);

        lcd_8bit_send_enable_signal(lcd);

    }




    return ret;






}

/**
 * 
 * @param lcd
 * @param data
 * @return 
 */
Std_ReturnType lcd_8bit_send_char_data(const cha_lcd_8bit_t*lcd, uint_8 data) {
    Std_ReturnType ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;

    } else {


        DIO_voidSetPinValue(lcd->lcd_RS_port, lcd->lcd_RS_pin, DIO_PIN_HIGH);

        DIO_voidSetPinValue(lcd->lcd_R_W_port, lcd->lcd_R_W_pin, DIO_PIN_LOW);


        DIO_voidSetPinValue(lcd->lcd_dat_port0, lcd->lcd_dat_pin0, (data >> 0)&1);
        DIO_voidSetPinValue(lcd->lcd_dat_port1, lcd->lcd_dat_pin1, (data >> 1)&1);
        DIO_voidSetPinValue(lcd->lcd_dat_port2, lcd->lcd_dat_pin2, (data >> 2)&1);
        DIO_voidSetPinValue(lcd->lcd_dat_port3, lcd->lcd_dat_pin3, (data >> 3)&1);
        DIO_voidSetPinValue(lcd->lcd_dat_port4, lcd->lcd_dat_pin4, (data >> 4)&1);
        DIO_voidSetPinValue(lcd->lcd_dat_port5, lcd->lcd_dat_pin5, (data >> 5)&1);
        DIO_voidSetPinValue(lcd->lcd_dat_port6, lcd->lcd_dat_pin6, (data >> 6)&1);
        DIO_voidSetPinValue(lcd->lcd_dat_port7, lcd->lcd_dat_pin7, (data >> 7)&1);

        lcd_8bit_send_enable_signal(lcd);






    }




    return ret;



}

/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param data
 * @return 
 */

Std_ReturnType lcd_8bit_send_char_data_pos(const cha_lcd_8bit_t*lcd, uint_8 row, uint_8 column, uint_8 data) {

    Std_ReturnType ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;

    } else {



        lcd_8bit_set_cursor(lcd, row, column);

        lcd_8bit_send_char_data(lcd, data);



    }




    return ret;


}

/**
 * 
 * @param lcd
 * @param str
 * @return 
 */
Std_ReturnType lcd_8bit_send_string(const cha_lcd_8bit_t*lcd, uint_8 *str) {
    Std_ReturnType ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;

    } else {




        while (*str) {

            lcd_8bit_send_char_data(lcd, *str++);


        }




    }




    return ret;



}

/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param str
 * @return 
 */

Std_ReturnType lcd_8bit_send_string_pos(const cha_lcd_8bit_t*lcd, uint_8 row, uint_8 column, uint_8 *str) {

    Std_ReturnType ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;

    } else {

        lcd_8bit_set_cursor(lcd, row, column);

        lcd_8bit_send_string(lcd, str);

    }




    return ret;


}

/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param _cha
 * @param mem_pos
 * @return 
 */

Std_ReturnType lcd_8bit_send_custom_char_pos(const cha_lcd_8bit_t*lcd, uint_8 row, uint_8 column, const uint_8 _cha[], uint_8 mem_pos) {
    Std_ReturnType ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;

    } else {


        lcd_8bit_send_command(lcd, start_address_of_CGRAM + 8 * mem_pos);
        for (int i = 0; i < 8; i++) {


            lcd_8bit_send_char_data(lcd, _cha[i]);


        }

        lcd_8bit_send_char_data_pos(lcd, row, column, mem_pos);






    }




    return ret;


}

/**
 * 
 * @param lcd
 * @param data_command
 * @return 
 */

static Std_ReturnType lcd_send_4bit(const cha_lcd_4bit_t*lcd, uint_8 data_command) {

    Std_ReturnType ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;

    } else {


        DIO_voidSetPinValue(lcd->lcd_dat_port0, lcd->lcd_dat_pin0, (data_command >> 0)& 1);
        DIO_voidSetPinValue(lcd->lcd_dat_port1, lcd->lcd_dat_pin1, (data_command >> 1)& 1);
        DIO_voidSetPinValue(lcd->lcd_dat_port2, lcd->lcd_dat_pin2, (data_command >> 2)& 1);
        DIO_voidSetPinValue(lcd->lcd_dat_port3, lcd->lcd_dat_pin3, (data_command >> 3)& 1);

    }




    return ret;



}

/**
 * 
 * @param lcd
 * @return 
 */
static Std_ReturnType lcd_4bit_send_enable_signal(const cha_lcd_4bit_t*lcd) {
    Std_ReturnType ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;

    } else {

        DIO_voidSetPinValue(lcd->lcd_E_port, lcd->lcd_E_pin, DIO_PIN_HIGH);
        _delay_us(5);
        DIO_voidSetPinValue(lcd->lcd_E_port, lcd->lcd_E_pin, DIO_PORT_LOW);




    }




    return ret;



}

/**
 * 
 * @param lcd
 * @return 
 */
static Std_ReturnType lcd_8bit_send_enable_signal(const cha_lcd_8bit_t*lcd) {
    Std_ReturnType ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;

    } else {

        DIO_voidSetPinValue(lcd->lcd_E_port, lcd->lcd_E_pin, DIO_PIN_HIGH);
        _delay_us(5);
        DIO_voidSetPinValue(lcd->lcd_E_port, lcd->lcd_E_pin, DIO_PORT_LOW);


    }




    return ret;



}

/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @return 
 */
static Std_ReturnType lcd_8bit_set_cursor(const cha_lcd_8bit_t*lcd, uint_8 row, uint_8 column) {
    Std_ReturnType ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;

    } else {



        column--;

        switch (row) {

            case ROW1:
                lcd_8bit_send_command(lcd, 0x80 + column);
                break;

            case ROW2:lcd_8bit_send_command(lcd, 0xC0 + column);
                break;

            case ROW3: lcd_8bit_send_command(lcd, 0x94 + column);
                break;

            case ROW4: lcd_8bit_send_command(lcd, 0xD4 + column);
                break;

            default:

                break;




        }


    }




    return ret;



}

/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @return 
 */
static Std_ReturnType lcd_4bit_set_cursor(const cha_lcd_4bit_t*lcd, uint_8 row, uint_8 column) {

    Std_ReturnType ret = E_OK;

    if (NULL == lcd) {
        ret = E_NOT_OK;

    } else {

        column--;

        switch (row) {

            case ROW1:
                lcd_4bit_send_command(lcd, 0x80 + column);
                break;

            case ROW2:lcd_4bit_send_command(lcd, 0xC0 + column);
                break;

            case ROW3: lcd_4bit_send_command(lcd, 0x94 + column);
                break;

            case ROW4: lcd_4bit_send_command(lcd, 0xD4 + column);
                break;

            default:

                break;



        }






    }




    return ret;






}

/**
 * 
 * @param value
 * @param str
 * @return 
 */
Std_ReturnType convert_uint_8_to_string(uint_8 value, uint_8*str) {

    Std_ReturnType ret = E_OK;
    if (NULL == str) {
        ret = E_NOT_OK;

    } else {
        uint_8 temp_arr[4] = {0};
        uint_8 counter = 0;
        memset(str, ' ', 3);
        str[3] = '\0';
        sprintf(temp_arr, "%u", value); // specifier for unsigned
        while (temp_arr[counter] != '\0') {

            str[counter] = temp_arr[counter];

            counter++;

        }
        counter = 0;


    }




    return ret;


}

/**
 * 
 * @param value
 * @param str
 * @return 
 */
Std_ReturnType convert_uint_16_to_string(uint_16 value, uint_8*str) {

    Std_ReturnType ret = E_OK;
    if (NULL == str) {
        ret = E_NOT_OK;

    } else {

        uint_8 STR_TEMP[6];
        uint_8 counter = 0;
        memset(str, ' ', 5);
        str[5] = '\0';
        sprintf(STR_TEMP, "%u", value);

        while (STR_TEMP[counter] != '\0') {
            str[counter] = STR_TEMP[counter];

            counter++;

        }
        counter = 0;


    }
    return ret;

}

/**
 * 
 * @param value
 * @param str
 * @return 
 */
Std_ReturnType convert_uint_32_to_string(uint_32 value, uint_8*str) {
    Std_ReturnType ret = E_OK;
    if (NULL == str) {
        ret = E_NOT_OK;

    } else {
        uint_8 STR_TEMP[11];
        uint_8 counter = 0;
        memset(str, ' ', 10);
        str[10] = '\0';
        sprintf(STR_TEMP, "%lu", value); // specifer for unsigned long

        while (STR_TEMP[counter] != '\0') {
            str[counter] = STR_TEMP[counter];

            counter++;

        }
        counter = 0;

    }




    return ret;


}

Std_ReturnType convert_sint_8_to_string(sint_8 value, uint_8*str) {

    Std_ReturnType ret = E_OK;
    if (NULL == str) {
        ret = E_NOT_OK;

    } else {

        uint_8 STR_TEMP[5];
        uint_8 counter = 0;
        memset(str, ' ', 4);
        str[4] = '\0';
        sprintf(STR_TEMP, "%d", value);

        while (STR_TEMP[counter] != '\0') {
            str[counter] = STR_TEMP[counter];

            counter++;

        }
        counter = 0;


    }




    return ret;

}

/**
 * 
 * @param value
 * @param str
 * @return 
 */
Std_ReturnType convert_sint_16_to_string(sint_16 value, uint_8*str) {

    Std_ReturnType ret = E_OK;
    if (NULL == str) {
        ret = E_NOT_OK;

    } else {
        uint_8 STR_TEMP[7];
        uint_8 counter = 0;

        memset(str, ' ', 6);
        str[6] = '\0';
        sprintf(STR_TEMP, "%i", value);

        while (STR_TEMP[counter] != '\0') {
            str[counter] = STR_TEMP[counter];

            counter++;

        }
        counter = 0;

    }




    return ret;

}

/**
 * 
 * @param value
 * @param str
 * @return 
 */
Std_ReturnType convert_sint_32_to_string(sint_32 value, uint_8*str) {
    Std_ReturnType ret = E_OK;
    if (NULL == str) {
        ret = E_NOT_OK;

    } else {
        uint_8 STR_TEMP[12];
        uint_8 counter = 0;
        memset(str, ' ', 11);
        str[11] = '\0';
        sprintf(STR_TEMP, "%ld", value); // specifer for signed long 

        while (STR_TEMP[counter] != '\0') {
            str[counter] = STR_TEMP[counter];

            counter++;

        }
        counter = 0;


    }




    return ret;


}
