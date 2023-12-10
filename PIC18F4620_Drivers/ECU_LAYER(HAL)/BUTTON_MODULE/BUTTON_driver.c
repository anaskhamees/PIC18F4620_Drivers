/* 
 * File:   BUTTON_driver.c
 * Author: Anas Khamees
 *
 * Created on June 4, 2023, 11:28 AM
 */
#include "BUTTON_driver.h"
/**
 * @brief   the function initializes the pin which assigned with button to be INPUT. 
 * @param   btn_obj, is a pointer points to pin configuration object which assigned with button.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
#if BUTTON_MODULE_CONFIGUTATION==CONFIG_ENABLE
Std_ReturnType button_initialization(const button_t *btn_obj)
{
    Std_ReturnType ret=E_OK;
    if(NULL !=btn_obj)
    {
        ret=gpio_pin_direction_initialization(&(btn_obj->button));
    }
    else
    {
        ret=E_NOT_OK;
    }
    
    return ret;
}
#endif

/**
 * @brief   the function reads the button status (PRESSED or RELEASED). 
 * @param   btn_obj, is a pointer points to pin configuration object which assigned with button.
 * @param   btn_state, is a pointer points to button state.
 * @return   status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
#if BUTTON_MODULE_CONFIGUTATION ==CONFIG_ENABLE
Std_ReturnType button_read_status(const button_t *btn_obj,btn_state_t *btn_state)
{
    Std_ReturnType ret=E_OK;
    logic_t logic_state=GPIO_LOW;
    if((NULL !=btn_obj)&&(NULL !=btn_state))
    {
        ret=gpio_pin_read_logic(&(btn_obj->button),&logic_state);
        
       /* if(btn_obj->btn_connection ==BUTTON_ACTIVE_HIGH)  
        {
            if(logic_state==GPIO_HIGH)
                   {
                       *btn_state=BUTTON_PRESSED;
                   }
                   else
                   {
                       *btn_state=BUTTON_RELEASED;
                   }
        }
        else if(btn_obj->btn_connection ==BUTTON_ACTIVE_LOW)
        {
             if(logic_state==GPIO_LOW)
                {
                    *btn_state=BUTTON_PRESSED;
                }
            else
                {
                    *btn_state=BUTTON_RELEASED;
                }
        }*/
        switch(btn_obj->btn_connection)
        {
            case BUTTON_ACTIVE_HIGH:{
                if(logic_state==GPIO_HIGH)
                {
                    *btn_state=BUTTON_PRESSED;
                }
                else
                {
                    *btn_state=BUTTON_RELEASED;
                }}
                break;
            case BUTTON_ACTIVE_LOW:{
                if(logic_state==GPIO_LOW)
                {
                    *btn_state=BUTTON_PRESSED;
                }
                else
                {
                    *btn_state=BUTTON_RELEASED;
                }}
                break;
                
            default:ret=E_NOT_OK;
        }
        
    }
    else
    {
        ret=E_NOT_OK;
    }
    
    return ret;
}
#endif

