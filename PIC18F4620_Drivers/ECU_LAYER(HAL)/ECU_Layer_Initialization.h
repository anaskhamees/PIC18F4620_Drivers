/* 
 * File:   ECU_Layer_Initialization.h
 * Author: Anas Khamees
 *
 * Created on June 4, 2023, 10:26 AM
 */

#ifndef ECU_LAYER_INITIALIZATION_H
#define	ECU_LAYER_INITIALIZATION_H

/*------------------------- Includes Section--------------------------------*/
#include "LED_MODULE/LED_driver.h"
#include "BUTTON_MODULE/BUTTON_driver.h"
#include "RELAY_MODULE/RELAY_driver.h"
#include "DC_MOTOR_MODULE/DC_MOTOR_driver.h"
#include "KEYPAD_MODULE/KEYPAD_driver.h"
#include "LCD_MODULE/LCD_driver.h"
/*------------------------- Macro(s) Declaration----------------------------*/
/*------------------------- Macro Functions Declaration-------------------- */
/*------------------------- Data Types Declaration--------------------------*/
/*------------------------- Functions Declaration---------------------------*/
void application_initialization(void);
#endif	/* ECU_LAYER_INITIALIZATION_H */

