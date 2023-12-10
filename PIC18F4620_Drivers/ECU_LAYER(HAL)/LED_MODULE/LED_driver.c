/* 
 * File:   LED_driver.c
 * Author: Anas Khamees
 *
 * Created on June 4, 2023, 8:48 AM
 */
#include "LED_driver.h"
/**
 * @brief   the function initializes the assigned pin which connected to led to be OUTPUT,and set it initially LOGIC LOW.
 * @param   led_obj,is a pointer points to pin configuration object which assigned with led.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
#if LED_MODULE_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType led_initialization(const led_t *led_obj)
{
    Std_ReturnType ret=E_OK;
    if(NULL !=led_obj)
    {
        ret=gpio_pin_initialization(&(led_obj->led));
    }
    else
    {
        ret=E_NOT_OK;
    }
    
    return ret;
}
#endif

/**
 * @brief   the function turns on the LED
 * @param   led_obj,is a pointer points to pin configuration object which assigned with led.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 * @return 
 */
#if LED_MODULE_CONFIGURATION ==CONFIG_ENABLE    
Std_ReturnType led_turn_on(const led_t *led_obj)
{
    Std_ReturnType ret=E_OK;
    if(NULL !=led_obj)
    {
        ret=gpio_pin_write_logic(&(led_obj->led),GPIO_HIGH);
    }
    else
    {
        ret=E_NOT_OK;
    }
    
    return ret;
    
}
#endif

/**
 * @brief   the function turn off the led
 * @param   led_obj, is a pointer points to pin configuration object which assigned with led.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
#if LED_MODULE_CONFIGURATION ==CONFIG_ENABLE
Std_ReturnType led_turn_off(const led_t *led_obj)
{
    Std_ReturnType ret=E_OK;
    if(NULL !=led_obj)
    {
        ret=gpio_pin_write_logic(&(led_obj->led),GPIO_LOW);
    }
    else
    {
        ret=E_NOT_OK;
    }
    
    return ret;
}
#endif
/**
 * @brief   the function reverses the logic of the led.
 * @param   led_obj,is a pointer points to pin configuration object which assigned with led.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */

#if LED_MODULE_CONFIGURATION ==CONFIG_ENABLE 
Std_ReturnType led_toggle(const led_t *led_obj)
{
    Std_ReturnType ret=E_OK;
    if(NULL !=led_obj)
    {
        ret=gpio_pin_toggle(&(led_obj->led));
    }
    else
    {
        ret=E_NOT_OK;
    }
    
    return ret;
}
#endif

