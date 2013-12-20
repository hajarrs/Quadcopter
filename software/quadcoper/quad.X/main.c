#include <p30F4013.h>

/*
 * File:   main.c
 * Author: rbpkirow
 *
 * Created on 29 de junio de 2013, 19:05
 */

#include <p30F4013.h>
#include "main.h"
#include "CA_SetGetMPU6050.h"
#include <math.h>

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
    Init_Pll();
    LED_ALL_OFF();

    Init_Bluetooh();
    enviar_datos("Bluetooth inicializado...",26);
    Delay1msT1(0);
    
    enviar_datos("Iniciando el I2C...",20);
    Delay1msT1(0);

    Init_I2C();

    enviar_datos("I2C inicializado...",20);
    Delay1msT1(0);

    enviar_datos("Iniciando el PWM...",20);
    Delay1msT1(0);

    Init_PWM();

    enviar_datos("PWM inicializado...",20);
    Delay1msT1(0);
    

    LED_ALL_ON();

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



    while(1)
    {
        if(get_who_I_AM() == 104)
        {
        int calibra_ax,calibra_ay,calibra_az,calibra_gx,calibra_gy,calibra_gz,ax,ay,az,gx,gy,gz;
        calibra_ax=calibra_ay=calibra_az=calibra_gx=calibra_gy=calibra_gz=ax=ay=az=gx=gy=gz=0;
        int i = 0;

  //for de calibracion
  for (i = 0; i > 100; i++){
//    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    ax=get_ax()+calibra_ax;
    ay=get_ay()+calibra_ay;
    az=get_az()+calibra_az;
    gx=get_gx()+calibra_gx;
    gy=get_gy()+calibra_gy;
    gz=get_gz()+calibra_gz;
   }
  calibra_ax=calibra_ax/100;
  calibra_ay=calibra_ay/100;
  calibra_az=calibra_az/100;
  calibra_gx=calibra_gx/100;
  calibra_gy=calibra_gy/100;
  calibra_gz=calibra_gz/100;

            while(1)
            {

                

  accXangle = (atan2(ay-calibra_ay,az-calibra_az)+PI)*RAD_TO_DEG;
  accYangle = (atan2(ax-calibra_ax,az-calibra_az)+PI)*RAD_TO_DEG;

  double gyroXrate = ((double)gx-calibra_gx)/131.0;
  double gyroYrate = -(((double)gy-calibra_gy)/131.0);
  gyroXangle += gyroXrate; // Calculate gyro angle without any filter
  gyroYangle += gyroYrate;
// gyroXangle += kalmanX.getRate()*((double)(micros()-timer)/1000000); // Calculate gyro angle using the unbiased rate
// gyroYangle += kalmanY.getRate()*((double)(micros()-timer)/1000000);

  compAngleX = (0.93*(compAngleX+(gyroXrate)))+(0.07*accXangle); // Calculate the angle using a Complimentary filter
  compAngleY = (0.93*(compAngleY+(gyroYrate)))+(0.07*accYangle);

  kalAngleX = getAngle(accXangle, gyroXrate) ; // Calculate the angle using a Kalman filter
  kalAngleY = getAngle(accYangle, gyroYrate);


            }
        }
    }

    return 0;
}
