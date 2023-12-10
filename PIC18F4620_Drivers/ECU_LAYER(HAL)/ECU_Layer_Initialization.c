/* 
 * File:   ECU_Layer_Initialization.c
 * Author: Anas Khamees
 *
 * Created on June 4, 2023, 10:26 AM
 */
#include "ECU_Layer_Initialization.h"
Std_ReturnType ret=E_NOT_OK;

led_t Led1={
    .led.port=PORTD_INDEX,
    .led.pin=GPIO_PIN4,
    .led.pin_direction=GPIO_DIRECTION_OUTPUT,
    .led.pin_logic=GPIO_LOW
};
led_t Led2={
    .led.port=PORTD_INDEX,
    .led.pin=GPIO_PIN5,
    .led.pin_direction=GPIO_DIRECTION_OUTPUT,
    .led.pin_logic=GPIO_LOW
};
led_t Led3={
    .led.port=PORTD_INDEX,
    .led.pin=GPIO_PIN6,
    .led.pin_direction=GPIO_DIRECTION_OUTPUT,
    .led.pin_logic=GPIO_LOW
};

led_t Led4={
    .led.port=PORTD_INDEX,
    .led.pin=GPIO_PIN7,
    .led.pin_direction=GPIO_DIRECTION_OUTPUT,
    .led.pin_logic=GPIO_LOW
};

button_t Button1={
    .button.port=PORTC_INDEX,
    .button.pin=GPIO_PIN0,
    .button.pin_direction=GPIO_DIRECTION_INPUT,
    .btn_connection=BUTTON_ACTIVE_HIGH,
    .btn_state=BUTTON_RELEASED
};
button_t Button2={
    .button.port=PORTD_INDEX,
    .button.pin=GPIO_PIN0,
    .button.pin_direction=GPIO_DIRECTION_INPUT,
    .btn_connection=BUTTON_ACTIVE_LOW,
    .btn_state=BUTTON_RELEASED
};

relay_t relay1={
  .relay.port=PORTC_INDEX,
  .relay.pin=GPIO_PIN1,
  .relay.pin_direction=GPIO_DIRECTION_OUTPUT,
  .relay.pin_logic=RELAY_OFF    /*GPIO_LOW*/
};
dc_motor_t motor1={
  .dc_motor[0].port=PORTC_INDEX,
  .dc_motor[0].pin=GPIO_PIN2,
  .dc_motor[0].pin_direction=GPIO_DIRECTION_OUTPUT,
  .dc_motor[0].pin_logic=GPIO_LOW,
          
  .dc_motor[1].port=PORTC_INDEX,
  .dc_motor[1].pin=GPIO_PIN3,
  .dc_motor[1].pin_direction=GPIO_DIRECTION_OUTPUT,
  .dc_motor[1].pin_logic=GPIO_LOW
};

keypad_t keypad1={
  .row_pins[0].port=PORTC_INDEX,
  .row_pins[0].pin=GPIO_PIN0,
  .row_pins[0].pin_direction=GPIO_DIRECTION_OUTPUT,
  .row_pins[0].pin_logic=GPIO_LOW,
  
  .row_pins[1].port=PORTC_INDEX,
  .row_pins[1].pin=GPIO_PIN1,
  .row_pins[1].pin_direction=GPIO_DIRECTION_OUTPUT,
  .row_pins[1].pin_logic=GPIO_LOW,
 
  .row_pins[2].port=PORTC_INDEX,
  .row_pins[2].pin=GPIO_PIN2,
  .row_pins[2].pin_direction=GPIO_DIRECTION_OUTPUT,
  .row_pins[2].pin_logic=GPIO_LOW,
 
  .row_pins[3].port=PORTC_INDEX,
  .row_pins[3].pin=GPIO_PIN3,
  .row_pins[3].pin_direction=GPIO_DIRECTION_OUTPUT,
  .row_pins[3].pin_logic=GPIO_LOW,
  
  .column_pins[0].port=PORTC_INDEX,
  .column_pins[0].pin=GPIO_PIN4,
  .column_pins[0].pin_direction=GPIO_DIRECTION_INPUT,
 
  .column_pins[1].port=PORTC_INDEX,
  .column_pins[1].pin=GPIO_PIN5,
  .column_pins[1].pin_direction=GPIO_DIRECTION_INPUT,
  
  .column_pins[2].port=PORTC_INDEX,
  .column_pins[2].pin=GPIO_PIN6,
  .column_pins[2].pin_direction=GPIO_DIRECTION_INPUT,
 
  .column_pins[3].port=PORTC_INDEX,
  .column_pins[3].pin=GPIO_PIN7,
  .column_pins[3].pin_direction=GPIO_DIRECTION_INPUT,
 
};

lcd_4bit_t lcd_4bit_1={
  .lcd_rs.port=PORTC_INDEX,
  .lcd_rs.pin=GPIO_PIN0,
  .lcd_rs.pin_direction=GPIO_DIRECTION_OUTPUT,
  .lcd_rs.pin_logic=GPIO_LOW,
  
  .lcd_en.port=PORTC_INDEX,
  .lcd_en.pin=GPIO_PIN1,
  .lcd_en.pin_direction=GPIO_DIRECTION_OUTPUT,
  .lcd_en.pin_logic=GPIO_LOW,
  
  .lcd_data[0].port=PORTC_INDEX,
  .lcd_data[0].pin=GPIO_PIN2,
  .lcd_data[0].pin_direction=GPIO_DIRECTION_OUTPUT,
  .lcd_data[0].pin_logic=GPIO_LOW,
  
  .lcd_data[1].port=PORTC_INDEX,
  .lcd_data[1].pin=GPIO_PIN3,
  .lcd_data[1].pin_direction=GPIO_DIRECTION_OUTPUT,
  .lcd_data[1].pin_logic=GPIO_LOW,
  
  .lcd_data[2].port=PORTC_INDEX,
  .lcd_data[2].pin=GPIO_PIN4,
  .lcd_data[2].pin_direction=GPIO_DIRECTION_OUTPUT,
  .lcd_data[2].pin_logic=GPIO_LOW,
  
  .lcd_data[3].port=PORTC_INDEX,
  .lcd_data[3].pin=GPIO_PIN5,
  .lcd_data[3].pin_direction=GPIO_DIRECTION_OUTPUT,
  .lcd_data[3].pin_logic=GPIO_LOW
  
};

lcd_8bit_t lcd_8bit_1={
  .lcd_rs.port=PORTC_INDEX,
  .lcd_rs.pin=GPIO_PIN6,
  .lcd_rs.pin_direction=GPIO_DIRECTION_OUTPUT,
  .lcd_rs.pin_logic=GPIO_LOW,
  
  .lcd_en.port=PORTC_INDEX,
  .lcd_en.pin=GPIO_PIN7,
  .lcd_en.pin_direction=GPIO_DIRECTION_OUTPUT,
  .lcd_en.pin_logic=GPIO_LOW,
  
  .lcd_data[0].port=PORTD_INDEX,
  .lcd_data[0].pin=GPIO_PIN0,
  .lcd_data[0].pin_direction=GPIO_DIRECTION_OUTPUT,
  .lcd_data[0].pin_logic=GPIO_LOW,
  
  .lcd_data[1].port=PORTD_INDEX,
  .lcd_data[1].pin=GPIO_PIN1,
  .lcd_data[1].pin_direction=GPIO_DIRECTION_OUTPUT,
  .lcd_data[1].pin_logic=GPIO_LOW,
  
  .lcd_data[2].port=PORTD_INDEX,
  .lcd_data[2].pin=GPIO_PIN2,
  .lcd_data[2].pin_direction=GPIO_DIRECTION_OUTPUT,
  .lcd_data[2].pin_logic=GPIO_LOW,
  
  .lcd_data[3].port=PORTD_INDEX,
  .lcd_data[3].pin=GPIO_PIN3,
  .lcd_data[3].pin_direction=GPIO_DIRECTION_OUTPUT,
  .lcd_data[3].pin_logic=GPIO_LOW,
  
  .lcd_data[4].port=PORTD_INDEX,
  .lcd_data[4].pin=GPIO_PIN4,
  .lcd_data[4].pin_direction=GPIO_DIRECTION_OUTPUT,
  .lcd_data[4].pin_logic=GPIO_LOW,
  
  .lcd_data[5].port=PORTD_INDEX,
  .lcd_data[5].pin=GPIO_PIN5,
  .lcd_data[5].pin_direction=GPIO_DIRECTION_OUTPUT,
  .lcd_data[5].pin_logic=GPIO_LOW,
  
  .lcd_data[6].port=PORTD_INDEX,
  .lcd_data[6].pin=GPIO_PIN6,
  .lcd_data[6].pin_direction=GPIO_DIRECTION_OUTPUT,
  .lcd_data[6].pin_logic=GPIO_LOW,
  
  .lcd_data[7].port=PORTD_INDEX,
  .lcd_data[7].pin=GPIO_PIN7,
  .lcd_data[7].pin_direction=GPIO_DIRECTION_OUTPUT,
  .lcd_data[7].pin_logic=GPIO_LOW
};

/**
 * @brief   the function initializes all modules
 * @param   Void
 * @return  Void
 */
void application_initialization(void)
{
 ret=led_initialization(&Led1);
 ret=led_initialization(&Led2);
 ret=led_initialization(&Led3);
 ret=led_initialization(&Led4);

/* ret=button_initialization(&Button1);
 ret=button_initialization(&Button2);
 ret=relay_initialization(&relay1);
 ret=dc_motor_initialization(&motor1);
 ret=keypad_pins_initialization(&keypad1);
 ret=lcd_8bit_initialization(&lcd_8bit_1);*/
ret=lcd_4bit_initialization(&lcd_4bit_1);

}
