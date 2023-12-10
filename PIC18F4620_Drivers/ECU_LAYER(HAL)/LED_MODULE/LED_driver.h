/* 
 * File:   LED_driver.h
 * Author: Anas Khamees
 *
 * Created on June 4, 2023, 8:48 AM
 */

#ifndef LED_DRIVER_H
#define	LED_DRIVER_H

/*------------------------- Includes Section--------------------------------*/
#include "../../MCAL_LAYER/GPIO_MODULE/HAL_GPIO.h"
/*------------------------- Macro(s) Declaration----------------------------*/
#define LED_MODULE_CONFIGURATION      CONFIG_ENABLE

/*------------------------- Macro Functions Declaration-------------------- */
/*------------------------- Data Types Declaration--------------------------*/
typedef enum{
    LED_OFF=0,
    LED_ON
}led_logic_t;
typedef struct{
   pin_config_t led;
    
}led_t;
/*------------------------- Functions Declaration---------------------------*/
/**
 * @brief   the function initializes the assigned pin which connected to led to be OUTPUT,and set it initially LOGIC LOW.
 * @param   led_obj,is a pointer points to pin configuration object which assigned with led.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType led_initialization(const led_t *led_obj);
/**
 * @brief   the function turns on the LED
 * @param   led_obj,is a pointer points to pin configuration object which assigned with led.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 * @return 
 */
Std_ReturnType led_turn_on(const led_t *led_obj);
/**
 * @brief   the function turns off the LED
 * @param   led_obj,is a pointer points to pin configuration object which assigned with led.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 * @return 
 */
Std_ReturnType led_turn_off(const led_t *led_obj);
/**
 * @brief   the function reverses the logic of the led.
 * @param   led_obj,is a pointer points to pin configuration object which assigned with led.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType led_toggle(const led_t *led_obj);
#endif	/* LED_DRIVER_H */

