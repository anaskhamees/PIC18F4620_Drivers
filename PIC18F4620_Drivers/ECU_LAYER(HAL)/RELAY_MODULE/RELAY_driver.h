/* 
 * File:   RELAY_driver.h
 * Author: Anas Khamees
 *
 * Created on June 5, 2023, 1:25 PM
 */

#ifndef RELAY_DRIVER_H
#define	RELAY_DRIVER_H

/*------------------------- Includes Section--------------------------------*/
#include "../../MCAL_LAYER/GPIO_MODULE/HAL_GPIO.h"
/*------------------------- Macro(s) Declaration----------------------------*/
/*------------------------- Macro Functions Declaration-------------------- */
/*------------------------- Data Types Declaration--------------------------*/
typedef enum{
    RELAY_OFF=0,
    RELAY_ON
}relay_state_t;
typedef struct{
    pin_config_t relay;
    relay_state_t state;
    
}relay_t;
/*------------------------- Functions Declaration---------------------------*/
/**
 * @brief   the function initializes the pins which assigned to relay to be OUTPUT pin and has initial value LOGIC ZERO.    
 * @param   relay_obj,is a pointer points to pin configuration object which assigned with relay.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType  relay_initialization(const relay_t *relay_obj);
/**
 * @brief   the function turn on the relay.    
 * @param   relay_obj,is a pointer points to pin configuration object which assigned with relay.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType  relay_turn_on(const relay_t *relay_t);
/**
 * @brief   the function turn off the relay.    
 * @param   relay_obj,is a pointer points to pin configuration object which assigned with relay.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType  relay_turn_off(const relay_t *relay_t);

#endif	/* RELAY_DRIVER_H */

