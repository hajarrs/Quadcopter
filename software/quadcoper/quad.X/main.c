#include <p30F4013.h>

/*
 * File:   main.c
 * Author: rbpkirow
 *
 * Created on 29 de junio de 2013, 19:05
 */

#include <p30F4013.h>
#include "main.h"



#define MY_FRC                  0xF9E3

// FUSES
// -----------------------------------------------------------
    _FOSC( MY_FRC & CSW_FSCM_ON ) //   0xF9E3 & 0x3FFF --> Arranca sin PLL (8MHz) y se habilita el clockSwitch
    _FGS( GWRP_OFF & CODE_PROT_OFF )
    _FICD( ICS_PGD1)
    _FWDT(WDT_OFF)
    _FBORPOR( PWRT_OFF & BORV27 & PBOR_OFF & MCLR_DIS )
// FIN FUSES
int main(void)
{
    Init_Hw();
    Init_I2C();
    Init_Bluetooh();
    Init_PWM();
    Init_Pll();

    while(1)
    {
    //   PWM_prueba();
 //  prueba2_I2C();
    unsigned int aux;
//   aux= Peticion_Acelerometro(0x75);
//    itoa(str_blue,aux, 10);
//    enviar_datos(str_blue, strlen(str_blue));

    aux= Peticion_Acelerometro(MPU6050_RA_WHO_AM_I);
    itoa(str_blue,aux, 16);
    enviar_datos(str_blue, strlen(str_blue));
        aux= Peticion_Acelerometro(MPU6050_RA_TEMP_OUT_L);
    itoa(str_blue,aux, 10);
    enviar_datos(str_blue, strlen(str_blue));
        LEDROJO=!LEDROJO;
//        Prueba_Bluetooth();
//        EnviarDatos_Acc_Gyro(COM_ACC_X | COM_ACC_Y | COM_ACC_Z);
//        Delay_Nop(5000);
//        Delay_Nop(5000);
//        LED1 = !LED1;
    }

    return 0;
}
