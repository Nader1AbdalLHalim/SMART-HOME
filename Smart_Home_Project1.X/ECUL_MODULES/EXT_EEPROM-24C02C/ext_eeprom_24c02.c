/* 
 * File:   ext_eeprom_24c02c.c
 * Author: Nader
 *
 * Created on November 20, 2023, 1:52 PM
 */
#include"ext_eeprom_24c02c.h"

void External_Eeprom_24c02c_WriteByte( uint8_t eeprom_address, uint8_t byte_address, uint8_t data )
{
         I2C_Write1ByteRegister( eeprom_address , byte_address,data );
}

uint8_t External_Eeprom_24c02c_ReadByte( uint8_t eeprom_address, uint8_t byte_address )
{
         uint8_t memory_read_val=0;
         memory_read_val=I2C_Read1ByteRegister(eeprom_address,byte_address );
         return memory_read_val;
}