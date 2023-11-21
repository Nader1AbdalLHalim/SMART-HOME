/* 
 * File:   ext_eeprom_24c02c.h
 * Author: Nader
 *
 * Created on November 20, 2023, 1:52 PM
 */

#ifndef EXT_EEPROM_24C02C_H
#define	EXT_EEPROM_24C02C_H

#include"../../mcc_generated_files/mcc.h"
#include"../../mcc_generated_files/examples/i2c_master_example.h"

/*
 Address can be changed by connecting each of theses pins A2, A1, A0
 to 5 volt or to ground in this form   1010 A2 A1 A0 R/W
 */
#define EEPROM_ADDRESS_1                             0xA2
#define EEPROM_ADDRESS_2                             0xA6

void External_Eeprom_24c02c_WriteByte( uint8_t eeprom_address, uint8_t byte_address, uint8_t data );
uint8_t External_Eeprom_24c02c_ReadByte( uint8_t eeprom_address, uint8_t byte_address );

#endif	/* EXT_EEPROM_24C02C_H */

