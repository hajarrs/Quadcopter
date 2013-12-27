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

//DEFINES DE DEBUG



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
//#define DATO_KALMAN
//#define ARRANQUE
//#define CALIBRADO
#define DEBUG
        Init_Hw();
    Init_Pll();
    LED_ALL_OFF();
   int i=0;
      int j=0;
    Init_Bluetooh();
    #ifdef ARRANQUE
    enviar_datos("Bluetooth inicializado...",26);
      #endif
    Delay1msT1(0);
        #ifdef ARRANQUE
    enviar_datos("Iniciando el I2C...",20);
        #endif
    Delay1msT1(0);

    Init_I2C();
    #ifdef ARRANQUE
    enviar_datos("I2C inicializado...",20);
        #endif
    Delay1msT1(0);
    #ifdef ARRANQUE
    enviar_datos("Iniciando el PWM...",20);
        #endif
    Delay1msT1(0);

    Init_PWM();
    #ifdef ARRANQUE
    enviar_datos("PWM inicializado...",20);
        #endif
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
         #ifdef DEBUG
    strcpy(str_blue,"esperando who i am correcto");
    enviar_datos(str_blue, strlen(str_blue));
        #endif
        if(get_who_I_AM() == 104)
        {
         #ifdef DEBUG
        strcpy(str_blue,"empezando a calibrar");
        enviar_datos_NOCR(str_blue, strlen(str_blue));
        #endif

       long calibra_ax,calibra_ay,calibra_az,calibra_gx,calibra_gy,calibra_gz,ax,ay,az,gx,gy,gz;
        calibra_ax=calibra_ay=calibra_az=calibra_gx=calibra_gy=calibra_gz=ax=ay=az=gx=gy=gz=0;

        int compAngleX_ini,compAngleY_ini,a;
     
        a=0;
        
                            for (i = 0; i < 50; i++){

                            calibra_ax=get_ax()+calibra_ax;
                            calibra_ay=get_ay()+calibra_ay;
                            calibra_az=get_az()+calibra_az;
                            calibra_gx=get_gx()+calibra_gx;
                            calibra_gy=get_gy()+calibra_gy;
                            calibra_gz=get_gz()+calibra_gz;
                           }

                           calibra_ax=calibra_ax/50;
                           calibra_ay=calibra_ay/50;
                           calibra_az=calibra_az/50;
                           calibra_gx=calibra_gx/50;
                           calibra_gy=calibra_gy/50;
                           calibra_gz=calibra_gz/50;

    #ifdef CALIBRADO

    strcpy(str_blue,"ax=");
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    itoa(str_blue,calibra_ax, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    strcpy(str_blue,"-");
    enviar_datos_NOCR(str_blue, strlen(str_blue));


    strcpy(str_blue,"ay=");
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    itoa(str_blue,calibra_ay, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    strcpy(str_blue,"-");
    enviar_datos_NOCR(str_blue, strlen(str_blue));

    strcpy(str_blue,"az=");
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    itoa(str_blue,calibra_az, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    strcpy(str_blue,"-");
    enviar_datos_NOCR(str_blue, strlen(str_blue));

    strcpy(str_blue,"gx=");
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    itoa(str_blue,calibra_gx, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    strcpy(str_blue,"-");
    enviar_datos_NOCR(str_blue, strlen(str_blue));

    strcpy(str_blue,"gy=");
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    itoa(str_blue,calibra_gy, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    strcpy(str_blue,"-");
    enviar_datos_NOCR(str_blue, strlen(str_blue));

    strcpy(str_blue,"gz=");
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    itoa(str_blue,calibra_gx, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    strcpy(str_blue,"-");
    enviar_datos(str_blue, strlen(str_blue));






    #endif


    
    //   while(1){
    //    calibrado_inicial(&calibra_ax,&calibra_ay,&calibra_az,&calibra_gx,&calibra_gy,&calibra_ax);
    //
    //
    //    itoa(str_blue,calibra_ax, 10);
    //    enviar_datos_NOCR(str_blue, strlen(str_blue));
    //    strcpy(str_blue,"-");
    //    enviar_datos_NOCR(str_blue, strlen(str_blue));
    //    itoa(str_blue,calibra_ay, 10);
    //    enviar_datos(str_blue, strlen(str_blue));
    //        }
        while(1)
            {
                
            ax=get_ax();
            ay=get_ay();
            az=get_az();
            gx=get_gx();
            gy=get_gy();
            gz=get_gz();

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

  plot4(ax,ay,compAngleX*10,compAngleY*10);
  //for (i = 0; i < 5000; i++)    Delay1msT1(1000);
#ifdef DATO_KALMAN

     itoa(str_blue,kalAngleX, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    strcpy(str_blue,"-");
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    itoa(str_blue,kalAngleY, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    strcpy(str_blue,"-");
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    itoa(str_blue,(compAngleX-compAngleX_ini), 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    strcpy(str_blue,"-");
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    itoa(str_blue,compAngleY-compAngleY_ini, 10);
    enviar_datos(str_blue, strlen(str_blue));
    #endif
            }
        }
    }

    return 0;
}
