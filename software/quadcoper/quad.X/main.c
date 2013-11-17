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

    int i;
    char mycadena[50];

    for(i=0;i<40;i++)
    {
        LEDAMARILLO =1;


        Delay1msT1(0);
        Delay1msT1(0);
        Delay1msT1(0);
        Delay1msT1(0);
        Delay1msT1(0);
        Delay1msT1(0);
        Delay1msT1(0);
        Delay1msT1(0);
        Delay1msT1(0);
        Delay1msT1(0);

        if(i == 30)
        {
            clockSwitch(NOSC_PLLOSC);
        }

        if(i > 30)
        {
            LEDAZUL =1;
        }

    }

    
    LEDAMARILLO=0;

//  for(i=0;i<3000;i++)Delay1msT1(0);
//    EnviarCR();
//    strcpy(mycadena,"Iniciando");
//    enviar_datos_NOCR(mycadena,strlen(mycadena));
//    for(j=0;j<5;j++)
//    {
//        strcpy(mycadena,".");
//        enviar_datos_NOCR(mycadena,strlen(mycadena));
//        for(i=0;i<200;i++)
//                Delay1msT1(0);
//    }
//    EnviarCR();


//          Prueba_Bluetooth();

    

    while(1)
    {
     //   prueba2_I2C();
        Delay_Nop(500);
        LEDROJO=!LEDROJO;
//        Prueba_Bluetooth();
//        EnviarDatos_Acc_Gyro(COM_ACC_X | COM_ACC_Y | COM_ACC_Z);
//        Delay_Nop(5000);
//        Delay_Nop(5000);
//        LED1 = !LED1;
    }

    return 0;
}
