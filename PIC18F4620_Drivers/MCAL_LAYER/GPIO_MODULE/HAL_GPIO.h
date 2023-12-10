/* 
 * File:   HAL_GPIO.h
 * Author: Anas Khamees
 *
 * Created on June 2, 2023, 8:10 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H
/*------------------------- Includes Section--------------------------------*/
#include "../MCAL_Std_Types.h"
#include "../device_config.h"
#include "pic18f4620.h"
/*------------------------- Macro(s) Declaration----------------------------*/
#define PIN_MAX_NUMBER              8
#define PORT_MAX_NUMBER             5
#define PORT_TOGGLE_MASK            0xFF
#define BIT_MASK                    0x01

#define CONFIG_ENABLE               0x01
#define CONFIG_DISABLE              0x00

#define GPIO_PIN_CONFIGURATION      CONFIG_ENABLE
#define GPIO_PORT_CONFIGURATION     CONFIG_ENABLE

#define BIT_MASK                    0x01
/*------------------------- Macro Functions Declaration-------------------- */
#define SET_BIT(REG,BIT_POSN)       (REG|=(BIT_MASK<<BIT_POSN))
#define CLEAR_BIT(REG,BIT_POSN)     (REG&=~(BIT_MASK<<BIT_POSN))
#define TOGGLE_BIT(REG,BIT_POSN)    (REG^=(BIT_MASK<<BIT_POSN))
#define READ_BIT(REG,BIT_POSN)      (BIT_MASK&(REG>>BIT_POSN))
//#define READ_BIT(REG,BIT_POSN)   ((REG>>BIT_POSN)&BIT_MASK)

/*------------------------- Data Types Declaration--------------------------*/

typedef enum{
    GPIO_LOW=0,
    GPIO_HIGH
}logic_t;

typedef enum{
    GPIO_DIRECTION_OUTPUT=0,
    GPIO_DIRECTION_INPUT
}direction_t;

typedef enum{
    PORTA_INDEX=0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index_t;

typedef enum{
    GPIO_PIN0=0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7
}pin_index_t;

typedef struct {
    uint8 port         :3;
    uint8 pin          :3;
    uint8 pin_direction:1;
    uint8 pin_logic    :1;
}pin_config_t;
/*------------------------- Functions Declaration(GPIO_MODULE_INTERFACES)---------------------------*/
/**
 * @brief   initialize Pins of GPIO_module to be INPUT or OUTPUT.
 * @param   pin_configuration, is a pointer point to pin configuration > @ref: pin_config_t.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType  gpio_pin_direction_initialization(const pin_config_t *pin_configuration);
/**
 * @brief   the function get the pin_direction status, Is it INPUT or OUTPUT.
 * @param   pin_configuration, is a pointer points to pin configuration   > @ref: pin_config_t.
 * @param   direction_status, is a pointer points to pin direction status > @ref: direction_t.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType  gpio_pin_get_direction_status    (const pin_config_t *pin_configuration,direction_t *direction_status);
/**
 * @brief   the function write logic HIGH or LOW on the microcontroller pins. 
 * @param   pin_configuration, is a pointer points to pin configuration > @ref: pin_config_t.
 * @param   logic, is a variable type of logic_t contains two state logic HIGH or logic LOW >@ref: logic_t.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType  gpio_pin_write_logic             (const pin_config_t *pin_configuration,logic_t logic);
/**
 * @brief   the function initialize the I/O pins of microcontroller and set the pins LOW as a initial value(IF OUTPUT PIN ONLY!).
 * @param   pin_configuration, is a pointer points to pin configuration > @ref: pin_config_t.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType  gpio_pin_initialization          (const pin_config_t *pin_configuration);
/**
 * @breif   the function reads the logic of the pins is LOW or HIGH.
 * @param   pin_configuration, is a pointer points to pin configuration > @ref: pin_config_t.
 * @param   logic, is a pointer points to variable type of logic_t contains two state HIGH or LOW.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType  gpio_pin_read_logic              (const pin_config_t *pin_configuration,logic_t *logic);
/**
 * @brief   the function toggle the logic of the pins, if logic HIGH toggle it to LOW, and vice versa. 
 * @param   pin_configuration, is a pointer points to pin configuration > @ref: pin_config_t.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType  gpio_pin_toggle                  (const pin_config_t *pin_configuration);

/**
 * @brief   the function initializes the PORTS of Microcontroller at once rather than pin by pin.
 * @param   port, is a variable type of port_index_t which determines the port number.
 * @param   direction, is a variable type of uint8 contains the initialization value.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType  gpio_port_direction_initialization(const port_index_t port,uint8 direction);
/**
 * @brief   the function get direction status of the Port.
 * @param   port, is a variable type of port_index_t contains Port number.
 * @param   direction, is a pointer point to direction status. 
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType  gpio_port_get_direction_status    (const port_index_t port,uint8 *direction);
/**
 * @brief   the function write logic HIGH or LOW on the all port rather than pin by pin.
 * @param   port,is a variable type of port_index_t which determines the port number
 * @param   logic, is a variable type of uint8 contains the logic value which writes on the port pins. 
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType  gpio_port_write_logic             (const port_index_t port,uint8 logic);
/**
 * @brief   the function initializes the all pins of port in the same time to be OUTPUT and set them LOW at initial.        
 * @param   port,is a variable type of port_index_t which determines the port number.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType  gpio_port_initialization          (const port_index_t port);
/**
 * @brief   the function reads the logic value of all pins (one port) at the same time.
 * @param   port,is a variable type of port_index_t which determines the port number.
 * @param   logic, is a pointer points to the logic value of the port.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType  gpio_port_read_logic              (const port_index_t port,uint8 *logic);
/**
 * @brief   the function toggles the logic value on the all pins of one port at same time.
 * @param   port,is a variable type of port_index_t which determines the port number.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
Std_ReturnType  gpio_port_toggle                  (const port_index_t port);

#endif	/* HAL_GPIO_H */

