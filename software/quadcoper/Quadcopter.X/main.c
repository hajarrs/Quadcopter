/*
 * File:   main.c
 * Author: Pablo
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
    //***************************************************************************************//
    //*****************ARRANCAMOS LA CONFIGURACION DEL PIC **********************************//
    //***************************************************************************************//
    Init_Hw();       Delay1msT1(0);     //Configuramos el puertos y quitamos analogicos
    Init_Pll();      Delay1msT1(0);     //configuramos el pll que abiasmos arracamos sin él
    Init_PWM();      Delay1msT1(0);     //configuramos el PWM
    Init_Bluetooh(); Delay1msT1(0);     //Configuramos el serial-Bluetooth
    Init_I2C();      Delay1msT1(0);     //incializamos el I2c
    set_inicial();   Delay1msT1(0);     //Configuramos la incialicacion de sensor
    getAngle_init(); Delay1msT1(0);  ACT_ACE = 1;     set_inicial();   //Incializamos el filtro kalman
    //***************************************************************************************//
    //***************************************************************************************//

    //*****************CALIBRAMOS EL ACELEROMETRO Y GIROSCOPO *******************************//
    get_calibrado_acelerometro(5, 50);//cojemos los valres por defecto del  giroscopo y aceletometro
    LED_ALL_OFF();
    //***************************************************************************************//


    //*****************ARRANCAMOS INTERRUPCION  DEL BUCLE PRINCIPAL *************************//
    SetupT3ForXmsPID(6);//configuramos  la interrupcion principal
    StartInterrup3();//incializamos la interrupcion
    
    enviar_mensaje("------------------------------------------------------");
    //***************************************************************************************//

    while(1);

}
void Bucle_Principal()
{
    LEDROJO=1;


int angulo=0;
int angulo1=0;
            double accXangle = (atan2((get_ay() - calibra_ay), (get_az() - calibra_az)))* RAD_TO_DEG;
           // double gyroXrate = (double) (get_gx() - calibra_gx) / 131.0;
            //angulo1 = (signed int) getAngle(accXangle, gyroXrate, 0.06);
            //angulo =(signed int)Complementary2(accXangle, gyroXrate,6);
             //   enviar_valor_NOCR("", angulo1);enviar_valor(",",angulo);
            plot4(get_ax(),accXangle*100,get_az(),get_gx());
          //  plot4(angulo1,angulo,accXangle,gyroXrate);
            //enviar_valor("anguloComplementary2 = ", angulo);
            // int devuelto = PID(250, angulo, 1, 100, 20, 1, &valorAuxAnterior, 31000, -31000);
            //plot3(100*(250-angulo),180*angulo,devuelto); // Calculate the angle using a Kalman filter

        
            LEDROJO=0;

}

