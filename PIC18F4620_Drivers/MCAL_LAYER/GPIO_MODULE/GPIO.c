/* 
 * File:   HAL_GPIO.c
 * Author: Anas Khamees
 *
 * Created on June 2, 2023, 8:10 PM
 */
#include "HAL_GPIO.h"


volatile uint8 *GPIO_tris_registers[]={&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
volatile uint8 *GPIO_port_registers[]={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};
volatile uint8 *GPIO_lat_registers[]={&LATA,&LATB,&LATC,&LATD,&LATE};

/**
 * @brief   initialize Pins of GPIO_module to be INPUT or OUTPUT.
 * @param   pin_configuration, is a pointer point to pin configuration > @ref: pin_config_t.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
#if GPIO_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType  gpio_pin_direction_initialization(const pin_config_t *pin_configuration)
{
    Std_ReturnType  ret=E_OK;
    if((NULL !=pin_configuration)&&((pin_configuration->pin)<=PIN_MAX_NUMBER-1)&&((pin_configuration->port)<=PORT_MAX_NUMBER-1))
    {
        switch(pin_configuration->pin_direction)
        {
            case GPIO_DIRECTION_OUTPUT:  CLEAR_BIT(*GPIO_tris_registers[pin_configuration->port],pin_configuration->pin); break;
            case GPIO_DIRECTION_INPUT :  SET_BIT(*GPIO_tris_registers[pin_configuration->port],pin_configuration->pin);break;
            default                   :  ret=E_NOT_OK;
        }
    }
    else
    {
        ret=E_NOT_OK;
    }
    
    
    return ret;
    
}
#endif

/**
 * @brief   the function get the pin_direction status, Is it INPUT or OUTPUT.
 * @param   pin_configuration, is a pointer points to pin configuration   > @ref: pin_config_t.
 * @param   direction_status, is a pointer points to pin direction status > @ref: direction_t.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
#if GPIO_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType  gpio_pin_get_direction_status(const pin_config_t *pin_configuration,direction_t *direction_status)
{
    Std_ReturnType  ret=E_OK;
    
    if((NULL !=pin_configuration)&&(NULL !=direction_status)&&
       ((pin_configuration->pin)<=PIN_MAX_NUMBER-1)&&((pin_configuration->port)<=PORT_MAX_NUMBER-1))
     {
       *direction_status =READ_BIT(*GPIO_tris_registers[pin_configuration->port],pin_configuration->pin); 
     }
    else
    {
        ret=E_NOT_OK;
    }
    
    return ret;
}
#endif

/**
 * @brief   the function write logic HIGH or LOW on the microcontroller pins. 
 * @param   pin_configuration, is a pointer points to pin configuration > @ref: pin_config_t.
 * @param   logic, is a variable type of logic_t contains two state logic HIGH or logic LOW >@ref: logic_t.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
#if GPIO_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType  gpio_pin_write_logic(const pin_config_t *pin_configuration,logic_t logic)
{
    Std_ReturnType  ret=E_OK;
    if((NULL !=pin_configuration)&&((pin_configuration->pin)<=PIN_MAX_NUMBER-1)&&((pin_configuration->port)<=PORT_MAX_NUMBER-1))
    {
        switch(logic)
        {
            case GPIO_HIGH: SET_BIT(*GPIO_lat_registers[pin_configuration->port],pin_configuration->pin);break;
            case GPIO_LOW : CLEAR_BIT(*GPIO_lat_registers[pin_configuration->port],pin_configuration->pin);break;
            default       : ret=E_NOT_OK;
        }
    }
    else
    {
        ret=E_NOT_OK;
    }

    
    return ret;
}
#endif

/**
 * @brief   the function initialize the I/O pins of microcontroller and set the pins LOW as a initial value(IF OUTPUT PIN ONLY!).
 * @param   pin_configuration, is a pointer points to pin configuration > @ref: pin_config_t.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
#if GPIO_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType  gpio_pin_initialization(const pin_config_t *pin_configuration)
{
    Std_ReturnType  ret=E_OK;
    if((NULL !=pin_configuration)&&((pin_configuration->pin)<=PIN_MAX_NUMBER-1)&&((pin_configuration->port)<=PORT_MAX_NUMBER-1))
    {
        CLEAR_BIT(*GPIO_tris_registers[pin_configuration->port],pin_configuration->pin); // make the pin OUTPUT.
        CLEAR_BIT(*GPIO_lat_registers[pin_configuration->port],pin_configuration->pin); // make the logic of the pin is LOW.
    }
    else
    {
        ret=E_NOT_OK;
    }

    return ret;
}
#endif

/**
 * @breif   the function reads the logic of the pins is LOW or HIGH.
 * @param   pin_configuration, is a pointer points to pin configuration > @ref: pin_config_t.
 * @param   logic, is a pointer points to variable type of logic_t contains two state HIGH or LOW.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
#if GPIO_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType  gpio_pin_read_logic(const pin_config_t *pin_configuration,logic_t *logic)
{
    Std_ReturnType  ret=E_OK;
    if((NULL !=pin_configuration)&&(NULL !=logic)&&
       ((pin_configuration->pin)<=PIN_MAX_NUMBER-1)&&((pin_configuration->port)<=PORT_MAX_NUMBER-1))
    {
        *logic=READ_BIT(*GPIO_lat_registers[pin_configuration->port],pin_configuration->pin);
    }
    else
    {
        ret=E_NOT_OK;
    }
    return ret;
}
#endif
/**
 * @brief   the function toggle the logic of the pins, if logic HIGH toggle it to LOW, and vice versa. 
 * @param   pin_configuration, is a pointer points to pin configuration > @ref: pin_config_t.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
#if GPIO_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType  gpio_pin_toggle(const pin_config_t *pin_configuration)
{
    Std_ReturnType  ret=E_OK;
    if((NULL !=pin_configuration)&&((pin_configuration->pin)<=PIN_MAX_NUMBER-1)&&((pin_configuration->port)<=PORT_MAX_NUMBER-1))
    {
        TOGGLE_BIT(*GPIO_lat_registers[pin_configuration->port],pin_configuration->pin);
    }
    else
    {
        ret=E_NOT_OK;
    }
    
    return ret;
}
#endif

/**
 * @brief   the function initializes the PORTS of Microcontroller at once rather than pin by pin.
 * @param   port, is a variable type of port_index_t which determines the port number.
 * @param   direction, is a variable type of uint8 contains the initialization value.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE   
Std_ReturnType  gpio_port_direction_initialization(port_index_t port,uint8 direction)
{
    Std_ReturnType ret=E_OK;
    if(port<=PORT_MAX_NUMBER)
    {
        *GPIO_tris_registers[port]=direction;
    }
    else
    {
        ret=E_NOT_OK;
    }
    
    
    return ret;
}
#endif
/**
 * @brief   the function get direction status of the Port.
 * @param   port, is a variable type of port_index_t contains Port number.
 * @param   direction, is a pointer point to direction status. 
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE   
Std_ReturnType  gpio_port_get_direction_status(port_index_t port,uint8 *direction)
{
    Std_ReturnType ret=E_OK;
    if(port<=PORT_MAX_NUMBER)
    {
        *direction= *GPIO_tris_registers[port];
    }
    else
    {
        ret=E_NOT_OK;
    }
    
    return ret;  
}
#endif

/**
 * @brief   the function write logic HIGH or LOW on the all port rather than pin by pin.
 * @param   port,is a variable type of port_index_t which determines the port number
 * @param   logic, is a variable type of uint8 contains the logic value which writes on the port pins. 
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE   
Std_ReturnType  gpio_port_write_logic(port_index_t port,uint8 logic)
{
     Std_ReturnType ret=E_OK;
    if(port<=PORT_MAX_NUMBER)
    {
        *GPIO_lat_registers[port]=logic;
    }
    else
    {
        ret=E_NOT_OK;
    }
    
    return ret;  
}
#endif

/**
 * @brief   the function initializes the all pins of port in the same time to be OUTPUT and set them LOW at initial.        
 * @param   port,is a variable type of port_index_t which determines the port number.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE   
Std_ReturnType  gpio_port_initialization(port_index_t port)
{
     Std_ReturnType ret=E_OK;
    if(port<=PORT_MAX_NUMBER)
    {
        *GPIO_tris_registers[port]=0x00;
        *GPIO_lat_registers[port]=0x00;
    }
    else
    {
        ret=E_NOT_OK;
    }
    
    return ret;  
}
#endif

/**
 * @brief   the function reads the logic value of all pins (one port) at the same time.
 * @param   port,is a variable type of port_index_t which determines the port number.
 * @param   logic, is a pointer points to the logic value of the port.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE   
Std_ReturnType  gpio_port_read_logic(port_index_t port,uint8 *logic)
{
    Std_ReturnType ret=E_OK;
    if(port<=PORT_MAX_NUMBER)
    {
       *logic=*GPIO_lat_registers[port];
    }
    else
    {
        ret=E_NOT_OK;
    }
    
    return ret;  
}
#endif
/**
 * @brief   the function toggles the logic value on the all pins of one port at same time.
 * @param   port,is a variable type of port_index_t which determines the port number.
 * @return  status of the function
 *  `       (E_OK)    : the function done successfully.
 *          (E_NOT_OK): the function failed.
 */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE   
Std_ReturnType  gpio_port_toggle(port_index_t port)
{
    Std_ReturnType ret=E_OK;
    if(port<=PORT_MAX_NUMBER)
    {
        *GPIO_lat_registers[port]^=PORT_TOGGLE_MASK;
    }
    else
    {
        ret=E_NOT_OK;
    }
    
    return ret;
}
#endif
