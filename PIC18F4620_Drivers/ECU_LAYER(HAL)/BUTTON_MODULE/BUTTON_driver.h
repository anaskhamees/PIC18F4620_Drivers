/* 
 * File:   BUTTON_driver.h
 * Author: Anas Khamees
 *
 * Created on June 4, 2023, 11:28 AM
 */
#ifndef BUTTON_DRIVER_H
#define	BUTTON_DRIVER_H

/*------------------------- Includes Section--------------------------------*/
#include "../../MCAL_LAYER/GPIO_MODULE/HAL_GPIO.h"
/*------------------------- Macro(s) Declaration----------------------------*/
#define BUTTON_MODULE_CONFIGUTATION     CONFIG_ENABLE
/*------------------------- Macro Functions Declaration-------------------- */
/*------------------------- Data Types Declaration--------------------------*/
typedef enum{
    BUTTON_PRESSED,
    BUTTON_RELEASED
}btn_state_t;
typedef enum{
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW
}btn_active_t;

typedef struct{
    pin_config_t button;
    btn_state_t  btn_state;
    btn_active_t btn_connection;
}button_t;
/*------------------------- Functions Declaration---------------------------*/
/**
 * @brief   the function initializes the pin which assigned with button to be INPUT. 
 * @param   btn_obj, is a pointer points to pin configuration object which assigned with button.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */

Std_ReturnType button_initialization(const button_t *btn_obj);
/**
 * @brief   the function reads the button status (PRESSED or RELEASED). 
 * @param   btn_obj, is a pointer points to pin configuration object which assigned with button.
 * @param   btn_state, is a pointer points to button state.
 * @return   status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType button_read_status(const button_t *btn_obj,btn_state_t *btn_state);
#endif	/* BUTTON_DRIVER_H */

