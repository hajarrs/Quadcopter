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

    DelayXmsT1(10);
    LEDVERDE = 1;
    set_inicial();

    LEDROJO = 1;
    set_inicial();
    getAngle_init();
    int valorAux = 0;
    int valorAuxAnterior = 0;

    while (1)
    {
        double accXangle = (atan2(get_ay(), get_az()) + PI) * RAD_TO_DEG;
        double gyroXrate = (double)get_gx() / 131.0;
        valorAux = get_ax();
        int angulo =(int)getAngle(accXangle, gyroXrate,0.02);
        //plot3(gyroXrate,accXangle,angulo); // Calculate the angle using a Kalman filter
        enviar_valor("",angulo);
       // int devuelto = PID(0, valorAux, 1, 10, 1, 1, &valorAuxAnterior, 31000, -31000);
       // plot2(valorAux, devuelto);

    }


}


