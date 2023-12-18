/* 
 * File:   ECU_7_SEGMENT.c
 * Author: PC
 *
 * Created on May 28, 2023, 5:02 PM
 */

#include "ECU_7_SEGMENT.h"

/**
 * 
 * @param segment
 * @return 
 */
Std_ReturnType _7_segment_pins_intialize(_7_segment_t *segment)
{
    Std_ReturnType ret=E_OK;
    if(NULL !=segment)
    {
        ret=gpio_pin_intialize(&(segment->_7_Seg_Pin[_7_SEGMENT_PIN0]));
        ret=gpio_pin_intialize(&(segment->_7_Seg_Pin[_7_SEGMENT_PIN1]));
        ret=gpio_pin_intialize(&(segment->_7_Seg_Pin[_7_SEGMENT_PIN2]));
        ret=gpio_pin_intialize(&(segment->_7_Seg_Pin[_7_SEGMENT_PIN3]));
        
    }
    else
    {
        ret=E_NOT_OK;
    }
    return ret;
}
/**
 * 
 * @param segment
 * @param number
 * @return 
 */
Std_ReturnType _7_segment_write_number(_7_segment_t *segment,uint8 number)
{
    Std_ReturnType ret=E_OK;
    if((NULL !=segment)||(number<=9))
    {
        ret=gpio_pin_logic_write(&(segment->_7_Seg_Pin[_7_SEGMENT_PIN0]),(uint8)(number&0x01));
        ret=gpio_pin_logic_write(&(segment->_7_Seg_Pin[_7_SEGMENT_PIN1]),(uint8)(number>>1)&0x01);
        ret=gpio_pin_logic_write(&(segment->_7_Seg_Pin[_7_SEGMENT_PIN2]),(uint8)(number>>2)&0x01);
        ret=gpio_pin_logic_write(&(segment->_7_Seg_Pin[_7_SEGMENT_PIN3]),(uint8)(number>>3)&0x01);
    }
    else
    {
        ret=E_NOT_OK;
    }
    return ret;
}
