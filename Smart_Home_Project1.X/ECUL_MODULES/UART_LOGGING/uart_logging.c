/* 
 * File:   uart_logging.c
 * Author: Nader
 *
 * Created on November 19, 2023, 4:24 PM
 */

#include"uart_logging.h"

void UART_WRITE_STRING( uint8_t *string, uint16_t string_length)
{
    uint8_t l_counter=0;
    for( l_counter=0 ;  l_counter < string_length; l_counter++ )
    {
         EUSART_Write( *string++ );
    }
}