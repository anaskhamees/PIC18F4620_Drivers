/* 
 * File:   MCAL_Layer_Initialization.c
 * Author: Anas
 *
 * Created on June 17, 2023, 6:55 PM
 */
#include "MCAL_Layer_Initialization.h"
#include "MCAL_Std_Types.h"
#include "../ECU_LAYER/ECU_Layer_Initialization.h"

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

