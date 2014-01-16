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
#define CALIBRADO
    int calibra_ax, calibra_ay, calibra_az, calibra_gx, calibra_gy, calibra_gz, ax, ay, az, gx, gy, gz;
    calibra_ax = calibra_ay = calibra_az = calibra_gx = calibra_gy = calibra_gz = ax = ay = az = gx = gy = gz = 0;
    int dtC;
    int k = 10;
    float dtc2;
    float x_angle2C;
    float x1 = 0;
    float y1 = 0;

    float x2 = 0;
    float y2 = 0;
#define DEBUG
    Init_Hw();
    Init_Pll();
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
#ifdef ARRANQUE
    enviar_mensaje("I2C inicializado...");
#endif
    Delay1msT1(0);
#ifdef ARRANQUE
    enviar_mensaje("Iniciando el PWM...");
#endif
    Delay1msT1(0);
    Init_PWM();
#ifdef ARRANQUE
    enviar_mensaje("PWM inicializado...");
#endif
    //  SetupT3FormsPID(4);
    // StartPID();
    while (1);
    while (1)
    {
          if (get_who_I_AM() != 104)
        {
        LEDROJO_1=0;
        LEDVERDE_1=1;

        //enviar_mensaje("hola que tal estas");
        //  EjecutarPID();
        get_acelerometro(&ax, &ay, &az, &gx, &gy, &gz);
        enviar_valor("ax=", ax);
        plot4(ax,ay,az,gz);
//        signed int errorLeido = 0;
//        signed int resultado = 0;
//        errorLeido = az - 17300;
//        resultado = errorLeido * 10; //Parte proporcional
//        resultado = resultado + (errorLeido - errorAnt)*10; //Anadido parte derivativa
//        errorAnt = errorLeido;
//        // if (resultado>32000)resultado=32000;
//
//        PWM1_ = 1000 + resultado;
//        PWM3_ = 1000 - resultado;
        //plot4(PWM1_, PWM3_, az, resultado);
        DelayXmsT1(2);
//        enviar_valor("pwm1_=", PWM1_);
//        enviar_valor("pwm1_=", PWM1_);
//        enviar_valor("az=", az);
//        enviar_valor("resultado=", resultado);

          }
    else{
        LEDROJO_1=1;
        LEDVERDE_1=0;

    }
    }

    DelayXmsT1(200);
    while (1)
    {
        if (get_who_I_AM() != 104)
        {
#ifdef DEBUG
            enviar_valor("esperando who i am correcto actualente = ", get_who_I_AM());
            reset();
#endif

        } else
        {
#ifdef DEBUG
            enviar_mensaje("empezando a calibrar");
#endif

#ifdef CALIBRADO

            get_calibrado_acelerometro(50, 50, &calibra_ax, &calibra_ay, &calibra_az, &calibra_gx, &calibra_gy, &calibra_gz); //get_calibrado_acelerometro((espera en milis),(numero de lecturas),&calibra_ax, &calibra_ay, &calibra_az, &calibra_gx, &calibra_gy, &calibra_gz);

#endif

            while (1)
            {

                get_acelerometro(&ax, &ay, &az, &gx, &gy, &gz);

            }
            while(1);
        }
    }

    return 0;
}