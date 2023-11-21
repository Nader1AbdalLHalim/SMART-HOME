/* 
 * File:   temp_sensor_tc74.h
 * Author: Nader
 *
 * Created on November 20, 2023, 4:06 PM
 */

#ifndef TEMP_SENSOR_TC74_H
#define	TEMP_SENSOR_TC74_H

#include"../../mcc_generated_files/mcc.h"
#include"../../mcc_generated_files/examples/i2c_master_example.h"

#define TEMP_SENSOR_ADDRESS_A7              0x9E

uint8_t Temp_Sensor_Tc74_ReadByte( uint8_t temp_sensor_address );

#endif	/* TEMP_SENSOR_TC74_H */

