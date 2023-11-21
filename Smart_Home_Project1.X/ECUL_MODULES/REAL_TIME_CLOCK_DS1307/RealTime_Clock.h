/* 
 * File:   RealTime_Clock.h
 * Author: Nader
 *
 * Created on November 19, 2023, 2:05 PM
 */

#ifndef REALTIME_CLOCK_H
#define	REALTIME_CLOCK_H

#include"../../mcc_generated_files/mcc.h"
#include"../../mcc_generated_files/examples/i2c_master_example.h"
#include"../UART_LOGGING/uart_logging.h"
typedef struct
{
    uint8_t SECONDS;
    uint8_t MINUTES;
    uint8_t HOURS;
    uint8_t DAYS;
    uint8_t MONTHES;
    uint8_t YEARS;
}RealTime_Clock_t;

void DS1307_GET_TIME_DATE_VIA_I2C(RealTime_Clock_t *_object);
void DS1307_PRINT_STRING_VIA_UART(RealTime_Clock_t *_object, uint8_t *TimeString, uint8_t *DateString);

#endif	/* REALTIME_CLOCK_H */

