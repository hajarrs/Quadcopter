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
    LEDAZUL =1;

    Init_I2C();
    Init_Bluetooh();
    Init_PWM();

    int i;
//    char mycadena[50];

    for(i=0;i<50;i++);
        Delay1msT1(0);

    clockSwitch(NOSC_PLLOSC);
    Delay_Nop(1500);
    
    
    PWM1 = 0;
    PWM2 = 0;
    PWM3 = 0;
    PWM4 = 0;


    LEDAZUL = 0;
    LEDROJO=1;
    while(1)
    {
        for(i=0;i<36000;i++);
        {

        LEDAMARILLO = !LEDAMARILLO;
        PWM1++;
        PWM2++;
        PWM3++;
        PWM4++;
        Delay1msT1(0);
        Delay1msT1(0);
        Delay1msT1(0);
        Delay1msT1(0);
        }
                for(i=0;i<36000;i++);
        {

        LEDAMARILLO = !LEDAMARILLO;
        PWM1--;
        PWM2--;
        PWM3--;
        PWM4--;
        Delay1msT1(0);
        Delay1msT1(0);
        Delay1msT1(0);
        Delay1msT1(0);
        }

    PWM1 = 0;
    PWM2 = 0;
    PWM3 = 0;
    PWM4 = 0;

    }


    LEDAMARILLO=0;

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
