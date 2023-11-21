/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F46K20
        Driver Version    :  2.00
*/
#include "mcc_generated_files/mcc.h"

#include"ECUL_MODULES/REAL_TIME_CLOCK_DS1307/RealTime_Clock.h"
#include"ECUL_MODULES/UART_LOGGING/uart_logging.h"
#include"ECUL_MODULES/EXT_EEPROM-24C02C/ext_eeprom_24c02c.h"
#include"ECUL_MODULES/TEMP_SENSOR_TC74/temp_sensor_tc74.h"

 RealTime_Clock_t rtc_object;
uint8_t Array_Time[9];
uint8_t Array_Date[9];
uint8_t memory_val_1=0;
uint8_t memory_val_2=0;
uint8_t read_temp=0;

 void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    // Disable the Peripheral Interrupts
    
    
    External_Eeprom_24c02c_WriteByte(EEPROM_ADDRESS_1,0x00, 0x06);
    __delay_us(500);
    External_Eeprom_24c02c_WriteByte(EEPROM_ADDRESS_2,0x00, 0x06);
    __delay_us(500);
    
    memory_val_1=External_Eeprom_24c02c_ReadByte(EEPROM_ADDRESS_1,0x00);
    memory_val_2=External_Eeprom_24c02c_ReadByte(EEPROM_ADDRESS_2,0x00);
    
    while (1)
    {
        
                 

         DS1307_GET_TIME_DATE_VIA_I2C(&rtc_object);
         DS1307_PRINT_STRING_VIA_UART( &rtc_object, Array_Time,Array_Date );
         read_temp= Temp_Sensor_Tc74_ReadByte( TEMP_SENSOR_ADDRESS_A7 );
 
         I2C_Write1ByteRegister( 0x70, 0x00, read_temp);
         
         __delay_ms(100);
    }
}
