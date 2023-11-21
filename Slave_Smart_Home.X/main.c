#include "mcc_generated_files/mcc.h"

static void I2C_Custom_SlaveReadHandler() ;
uint8_t receive_temp_val=0;

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();


    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
     
    I2C_Open() ;
    I2C_SlaveSetReadIntHandler(I2C_Custom_SlaveReadHandler);
    

    while (1)
    {
         if( receive_temp_val > 35  )
         {
                 MOTOR1_SetHigh();
                 MOTOR2_SetLow();
         }
         else
         {
                 MOTOR1_SetLow();
                 MOTOR2_SetLow();     
         }
    }
}

static void I2C_Custom_SlaveReadHandler() 
{
    receive_temp_val =SSPBUF;
}
/**
 End of File
*/