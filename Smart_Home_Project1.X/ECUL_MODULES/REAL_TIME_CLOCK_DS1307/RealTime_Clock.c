/* 
 * File:   RealTime_Clock.c
 * Author: Nader
 *
 * Created on November 19, 2023, 2:05 PM
 */

#include"RealTime_Clock.h"



void DS1307_GET_TIME_DATE_VIA_I2C(RealTime_Clock_t *_object)
{
   _object->SECONDS=I2C_Read1ByteRegister(0xD0, 0x00);
   _object->MINUTES=I2C_Read1ByteRegister(0xD0, 0x01);
   _object->HOURS=I2C_Read1ByteRegister(0xD0, 0x02);
   _object->DAYS=I2C_Read1ByteRegister(0xD0, 0x04);
   _object->MONTHES=I2C_Read1ByteRegister(0xD0, 0x05);
   _object->YEARS=I2C_Read1ByteRegister(0xD0, 0x06);
}

void DS1307_PRINT_STRING_VIA_UART(RealTime_Clock_t *_object, uint8_t *TimeString, uint8_t *DateString)
{
         UART_WRITE_STRING("TIME: ",7);
         TimeString[0]= ((_object->HOURS >> 4 )+0x30);
         TimeString[1]= ((_object->HOURS & 0x0F )+0x30);
         TimeString[2]=':';
         TimeString[3]= ((_object->MINUTES >> 4 )+0x30);
         TimeString[4]= ((_object->MINUTES & 0x0F )+0x30);
         TimeString[5]=':';
         TimeString[6]= ((_object->SECONDS >> 4 )+0x30);
         TimeString[7]= ((_object->SECONDS & 0x0F )+0x30);
         TimeString[8]='\r' ;
         UART_WRITE_STRING(TimeString, 9);
         
         UART_WRITE_STRING("DATE: ",7);
         DateString[0]= ((_object->DAYS >> 4 )+0x30);
         DateString[1]= ((_object->DAYS & 0x0F )+0x30);
         DateString[2]=':';
         DateString[3]= ((_object->MONTHES >> 4 )+0x30);
         DateString[4]= ((_object->MONTHES & 0x0F )+0x30);
         DateString[5]=':';
         DateString[6]= ((_object->YEARS >> 4 )+0x30);
         DateString[7]= ((_object->YEARS & 0x0F )+0x30);
         DateString[8]='\r' ;
         UART_WRITE_STRING(DateString, 9);
}