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
    int calibra_ax, calibra_ay, calibra_az, calibra_gx, calibra_gy, calibra_gz, ax, ay, az, gx, gy, gz;
    //#define DATO_KALMAN
    //#define ARRANQUE
//#define CALIBRADO
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

  
    while(1);

    DelayXmsT1(200);
    while (1)
    {
        if (get_who_I_AM() != 104)
        {
#ifdef DEBUG
            enviar_valor("esperando who i am correcto actualente = ", get_who_I_AM());
            reset();
#endif

        }
        else
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
//                accXangle = (atan2(ay - calibra_ay, az - calibra_az) + PI) * RAD_TO_DEG;
//                accYangle = (atan2(ax - calibra_ax, az - calibra_az) + PI) * RAD_TO_DEG;
//                double gyroXrate = ((double) gx - calibra_gx) / 131.0;
//                double gyroYrate = -(((double) gy - calibra_gy) / 131.0);
//                dtc2 = 1000 / 1000;
//               // enviar_mensaje("------------------------------------------------------");
//               //  enviar_valor("gx= ", gx);
//               // enviar_valor("dtc2= ", dtc2);
//               // enviar_valor("gyroYrate= ", gyroYrate);
//              //  enviar_valor("x_angle2C= ", x_angle2C);
//                x1 = ((int)gyroXrate -(int) x_angle2C) * k*k;
//              //  enviar_valor("x1= ", x1);
//                y1 = dtc2 * x1 * + y1;
//              //  enviar_valor("y1= ", y1);
//                x2 = (int)y1 + ((int)gyroXrate - (int)x_angle2C)*2 * k + (int)accXangle;
//             //   enviar_valor("x2= ", x2);
//                x_angle2C = dtc2 * x2 + (int)x_angle2C;
//                enviar_valor("x_angle2C= ", x_angle2C);

                // plot4(gy,Complementary2(gyroYrate,accYangle,1000),Complementary2(gyroYrate,accYangle,1000),kalmanCalculate(gyroYrate,accYangle,1000));
                plot3(ax, ay, az);
                //Complementary2(gyroYrate,accYangle,a);
                // enviar_valor("hola",Complementary2(gyroYrate,accYangle,1000));
                  // plot2(gy,x_angle2C);
                   DelayXmsT1(10);

                
            }
        }
    }

    return 0;
}
