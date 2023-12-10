/* 
 * File:   DC_MOTOR_driver.c
 * Author: Anas Khamees
 *
 * Created on June 5, 2023, 2:42 PM
 */

#include "DC_MOTOR_driver.h"
/**
 * @brief   the function initializes the 2 pins which assigned to motor to be OUTPUT pins and have initial value LOGIC LOW.
 * @param   motor_obj,is a pointer points to pins configuration object which assigned with motor.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType dc_motor_initialization(const dc_motor_t *motor_obj)
{
    Std_ReturnType ret=E_OK;
    if(NULL != motor_obj)
    {
        ret=gpio_pin_initialization(&(motor_obj->dc_motor[0]));
        ret=gpio_pin_initialization(&(motor_obj->dc_motor[1]));

    }
    else
    {
        ret=E_NOT_OK;
    }
    
    return ret;
}
/**
 * @brief   the function turn on the motor to move forward.
 * @param   motor_obj,is a pointer points to pins configuration object which assigned with motor.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType dc_motor_move_forward(const dc_motor_t *motor_obj)
{
    Std_ReturnType ret=E_OK;
    if(NULL != motor_obj)
    {
        ret=gpio_pin_write_logic(&(motor_obj->dc_motor[0]),GPIO_HIGH);
        ret=gpio_pin_write_logic(&(motor_obj->dc_motor[1]),GPIO_LOW);

    }
    else
    {
        ret=E_NOT_OK;
    }
    
    return ret;
} 
/**
 * @brief   the function turn on the motor to move reverse.
 * @param   motor_obj,is a pointer points to pins configuration object which assigned with motor.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType dc_motor_move_reverse(const dc_motor_t *motor_obj)
{
    Std_ReturnType ret=E_OK;
    if(NULL != motor_obj)
    {
        ret=gpio_pin_write_logic(&(motor_obj->dc_motor[0]),GPIO_LOW);
        ret=gpio_pin_write_logic(&(motor_obj->dc_motor[1]),GPIO_HIGH);

    }
    else
    {
        ret=E_NOT_OK;
    }
    
    return ret;
}
/**
 * @brief   the function stop the motor.
 * @param   motor_obj,is a pointer points to pins configuration object which assigned with motor.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType dc_motor_stop(const dc_motor_t *motor_obj)
{
    Std_ReturnType ret=E_OK;
    if(NULL != motor_obj)
    {
        ret=gpio_pin_write_logic(&(motor_obj->dc_motor[0]),GPIO_LOW);
        ret=gpio_pin_write_logic(&(motor_obj->dc_motor[1]),GPIO_LOW);

    }
    else
    {
        ret=E_NOT_OK;
    }
    
    return ret;
}

