/* 
 * File:   MCAL_Std_Types.h
 * Author: Anas
 *
 * Created on June 2, 2023, 8:11 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/*------------------------- Includes Section--------------------------------*/
#include "MCAL_Std_libararies.h"
#include "compiler.h"
/*------------------------- Macro(s) Declaration----------------------------*/
#define ZERO        0x00
#define ZERO_INIT   0x00
#define HIGH        0x01
#define LOW         0x00
#define E_OK        0x01
#define E_NOT_OK    0x00
#define ACTIVE      0x01
#define IDLE        0x00
/*------------------------- Macro Functions Declaration-------------------- */
/*--------------------------------NOTHING-----------------------------------*/
/*------------------------- Data Types Declaration--------------------------*/
typedef unsigned char   uint8;
typedef unsigned short  uint16;
typedef unsigned long   uint32;
typedef signed char     sint8;
typedef signed short    sint16;
typedef signed long     sint32;

typedef uint8 Std_ReturnType;
/*------------------------- Functions Declaration---------------------------*/
/*--------------------------------NOTHING-----------------------------------*/


#endif	/* MCAL_STD_TYPES_H */

