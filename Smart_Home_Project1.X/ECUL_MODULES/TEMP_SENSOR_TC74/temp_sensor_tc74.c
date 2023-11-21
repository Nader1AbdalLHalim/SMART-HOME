/* 
 * File:   temp_sensor_tc74.c
 * Author: Nader
 *
 * Created on November 20, 2023, 4:06 PM
 */

#include"temp_sensor_tc74.h"

uint8_t Temp_Sensor_Tc74_ReadByte( uint8_t temp_sensor_address )
{
         uint8_t temp_value= 0;
         temp_value= I2C_Read1ByteRegister(temp_sensor_address, 0x00 );
         return temp_value;
}