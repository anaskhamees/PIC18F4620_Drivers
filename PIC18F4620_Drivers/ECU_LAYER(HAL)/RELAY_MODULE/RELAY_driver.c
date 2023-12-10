/* 
 * File:   RELAY_driver.c
 * Author: Anas Khamees
 *
 * Created on June 5, 2023, 1:25 PM
 */
#include "RELAY_driver.h"
/**
 * @brief   the function initializes the pins which assigned to relay to be OUTPUT pin and has initial value LOGIC ZERO.    
 * @param   relay_obj,is a pointer points to pin configuration object which assigned with relay.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType  relay_initialization(const relay_t *relay_obj)
{   
    Std_ReturnType  ret=E_OK;
    if(NULL !=relay_obj)
    {
        ret=gpio_pin_initialization(&(relay_obj->relay));
    }
    else
    {
        ret=E_NOT_OK;
    }
    
    return ret;
}
/**
 * @brief   the function turn on the relay.    
 * @param   relay_obj,is a pointer points to pin configuration object which assigned with relay.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType  relay_turn_on(const relay_t *relay_obj)
{
    Std_ReturnType  ret=E_OK;
    if(NULL !=relay_obj)
    {
        ret=gpio_pin_write_logic(&(relay_obj->relay),RELAY_ON);
    }
    else
    {
        ret=E_NOT_OK;
    }
    
    return ret;
}
/**
 * @brief   the function turn off the relay.    
 * @param   relay_obj,is a pointer points to pin configuration object which assigned with relay.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType  relay_turn_off(const relay_t *relay_obj)
{
    Std_ReturnType  ret=E_OK;
    if(NULL !=relay_obj)
    {
        ret=gpio_pin_write_logic(&(relay_obj->relay),RELAY_OFF);
    }
    else
    {
        ret=E_NOT_OK;
    }
    
    return ret;
}
