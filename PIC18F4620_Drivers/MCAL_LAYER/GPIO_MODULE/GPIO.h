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
#include "pic18f46k20.h"
/*------------------------- Macro(s) Declaration----------------------------*/
#define PIN_MAX_NUMBER              8
#define PORT_MAX_NUMBER             5
#define PORT_TOGGLE_MASK            0xFF
#define BIT_MASK                    0x01

#define CONFIG_ENABLE              0x01
#define CONFIG_DISABLE             0x00

#define GPIO_PIN_CONFIGURATION      CONFIG_ENABLE
#define GPIO_PORT_CONFIGURATION      CONFIG_ENABLE

/*------------------------- Macro Functions Declaration-------------------- */
#define SET_BIT(REG,BIT_POSN)       (REG|=(BIT_MASK<<BIT_POSN))
#define CLEAR_BIT(REG,BIT_POSN)     (REG&=~(BIT_MASK<<BIT_POSN))
#define TOGGLE_BIT(REG,BIT_POSN)    (REG^=(BIT_MASK<<BIT_POSN))
#define READ_BIT(REG,BIT_POSN)      (BIT_MASK&(REG>>BIT_POSN))

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
Std_ReturnType  gpio_pin_direction_initialization(const pin_config_t *pin_configuration);
Std_ReturnType  gpio_pin_get_direction_status    (const pin_config_t *pin_configuration,direction_t *direction_status);
Std_ReturnType  gpio_pin_write_logic             (const pin_config_t *pin_configuration,logic_t logic);
Std_ReturnType  gpio_pin_initialization          (const pin_config_t *pin_configuration);
Std_ReturnType  gpio_pin_read_logic              (const pin_config_t *pin_configuration,logic_t *logic);
Std_ReturnType  gpio_pin_toggle                  (const pin_config_t *pin_configuration);

Std_ReturnType  gpio_port_direction_initialization(port_index_t port,uint8 direction);
Std_ReturnType  gpio_port_get_direction_status    (port_index_t port,uint8 *direction);
Std_ReturnType  gpio_port_write_logic             (port_index_t port,uint8 logic);
Std_ReturnType  gpio_port_initialization          (port_index_t port);
Std_ReturnType  gpio_port_read_logic              (port_index_t port,uint8 *logic);
Std_ReturnType  gpio_port_toggle                  (port_index_t port);



#endif	/* HAL_GPIO_H */

