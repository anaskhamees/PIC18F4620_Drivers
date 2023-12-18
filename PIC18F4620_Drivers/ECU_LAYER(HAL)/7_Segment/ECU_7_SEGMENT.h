/* 
 * File:   ECU_7_SEGMENT.h
 * Author: PC
 *
 * Created on May 28, 2023, 5:02 PM
 */

#ifndef ECU_7_SEGMENT_H
#define	ECU_7_SEGMENT_H

/* Includes  Section */
#include "../../MCAL_LAYER/GPIO/GPIO.h"

/* Macro Declarations Section */
#define _7_SEGMENT_PIN0  (0)
#define _7_SEGMENT_PIN1  (1)
#define _7_SEGMENT_PIN2  (2)
#define _7_SEGMENT_PIN3  (3)

/* Macro Functions Declarations Section*/

/* Data Types Declarations Section*/
typedef enum{
    _7_SEGMENT_COMMON_ANODE=0,
    _7_SEGMENT_COMMON_CATHODE
}Segment_Type_t;

typedef struct{
pin_config_t _7_Seg_Pin[4];
Segment_Type_t SegType;
}_7_segment_t;

/* Functions Declarations Section*/
Std_ReturnType _7_segment_pins_intialize(_7_segment_t *segment);
Std_ReturnType _7_segment_write_number(_7_segment_t *segment,uint8 number);
#endif	/* ECU_7_SEGMENT_H */

