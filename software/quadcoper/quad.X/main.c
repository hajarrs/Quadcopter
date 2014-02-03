/*
 * File:   main.c
 * Author: rbpkirow
 *
 * Created on 29 de junio de 2013, 19:05
 */


#include "main.h"


#define MY_FRC                  0xF9E3

//DEFINES DE DEBUG


// FUSES
// -----------------------------------------------------------

_FOSC(MY_FRC & CSW_FSCM_ON) //   0xF9E3 & 0x3FFF --> Arranca sin PLL (8MHz) y se habilita el clockSwitch
_FGS(GWRP_OFF & CODE_PROT_OFF)
_FICD(ICS_PGD1)
_FWDT(WDT_OFF)
_FBORPOR(PWRT_OFF & BORV27 & PBOR_OFF & MCLR_DIS)
// FIN FUSES



int main(void)
{
    //#define DATO_KALMAN
    //#define ARRANQUE



    //#define CALIBRADO
    int calibra_ax, calibra_ay, calibra_az, calibra_gx, calibra_gy, calibra_gz, ax, ay, az, gx, gy, gz;
    calibra_ax = calibra_ay = calibra_az = calibra_gx = calibra_gy = calibra_gz = ax = ay = az = gx = gy = gz = 0;

    //#define DEBUG
    Init_Hw();
    Init_Pll();
#ifdef ARRANQUE
    enviar_mensaje("Iniciando el PWM...");
#endif
    Delay1msT1(0);
    Init_PWM();

    LED_ALL_OFF();

    Init_Bluetooh();
#ifdef ARRANQUE
    enviar_mensaje("Bluetooth inicializado...");
#endif
    Delay1msT1(0);
#ifdef ARRANQUE
    enviar_mensaje("Iniciando el I2C...");
#endif
    Delay1msT1(0);
    Init_I2C();
    DelayXmsT1(10);
     ACT_ACE = 1;
#ifdef ARRANQUE
    enviar_mensaje("I2C inicializado...");
#endif
    Delay1msT1(0);

#ifdef ARRANQUE
    enviar_mensaje("PWM inicializado...");
#endif
    //  SetupT3FormsPID(4);
    // StartPID();

    //    ACT_ACE=0;

    //    LEDROJO=0;
    //   DelayXmsT1(1000);
    //    LEDROJO=1;

 
//    DelayXmsT1(1000);
//
//       ACT_ACE = 1;
       DelayXmsT1(10);
           LEDAZUL = 1;
    int pid;
    set_inicial();
    while (1)
    {
        //enviar_mensaje("hola");
       // enviar_mensaje("hola que tal");
       // prueba_envio();
       // prueba_pwm();
       // prueba recep cometarlineas
      //  acelerometro();

        int i;
   for (i=0;i<20000;i=i+10)
   {
    PWM1=PWM2=PWM3=PWM4=i;
   prueba_who_i_am();
   enviar_valor("i", i);
   }
    for (i=2000;i>1;i=i-10)
    {
    PWM1=PWM2=PWM3=PWM4=i;
    prueba_who_i_am();
    enviar_valor("i", i);
    }


        }

        
    
    return 0;
}


