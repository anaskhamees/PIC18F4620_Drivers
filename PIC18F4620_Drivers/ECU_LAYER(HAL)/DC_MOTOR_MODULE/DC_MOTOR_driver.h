/* 
 * File:   DC_MOTOR_driver.h
 * Author: Anas Khamees
 *
 * Created on June 5, 2023, 2:42 PM
 */

#ifndef DC_MOTOR_DRIVER_H
#define	DC_MOTOR_DRIVER_H

/*------------------------- Includes Section--------------------------------*/
#include "../../MCAL_LAYER/GPIO_MODULE/HAL_GPIO.h"
/*------------------------- Macro(s) Declaration----------------------------*/
/*------------------------- Macro Functions Declaration-------------------- */
/*------------------------- Data Types Declaration--------------------------*/
typedef struct{
    pin_config_t  dc_motor[2];
}dc_motor_t;
/*------------------------- Functions Declaration---------------------------*/
/**
 * @brief   the function initializes the 2 pins which assigned to motor to be OUTPUT pins and have initial value LOGIC LOW.
 * @param   motor_obj,is a pointer points to pins configuration object which assigned with motor.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType dc_motor_initialization(const dc_motor_t *motor_obj);
/**
 * @brief   the function turn on the motor to move forward.
 * @param   motor_obj,is a pointer points to pins configuration object which assigned with motor.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType dc_motor_move_forward(const dc_motor_t *motor_obj); 
/**
 * @brief   the function turn on the motor to move reverse.
 * @param   motor_obj,is a pointer points to pins configuration object which assigned with motor.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType dc_motor_move_reverse(const dc_motor_t *motor_obj);
/**
 * @brief   the function stop the motor.
 * @param   motor_obj,is a pointer points to pins configuration object which assigned with motor.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType dc_motor_stop(const dc_motor_t *motor_obj);


#endif	/* DC_MOTOR_DRIVER_H */

