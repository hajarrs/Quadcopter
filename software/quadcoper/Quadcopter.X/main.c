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
    getAngle_init(); Delay1msT1(0);     //Incializamos el filtro kalman
    set_inicial();   Delay1msT1(0);     //Incializamos el acelerometro
    //***************************************************************************************//
    //***************************************************************************************//

    //*****************CALIBRAMOS EL ACELEROMETRO Y GIROSCOPO *******************************//
    get_calibrado_acelerometro(5, 50);//cojemos los valres por defecto del  giroscopo y aceletometro
    LED_ALL_OFF();
    //***************************************************************************************//

   //*****************INICIALIZAMOS EL PID  Y LAS VARIABLES ********************************//

    //pid_dsp_configuracion();

    //***************************************************************************************//
  

    //*****************ARRANCAMOS INTERRUPCION  DEL BUCLE PRINCIPAL *************************//
    //SetupT3ForXmsPID(10);//configuramos  la interrupcion principal
   // StartInterrup3();//incializamos la interrupcion
    enviar_mensaje("------------------------------------------------------");
    //***************************************************************************************//

    while(1)
    {acelerometro();
    }

}
void Bucle_Principal()
{

//    int angulo = 0;
    int angulo1 = 0;
    double accXangle = (atan2((get_az() - calibra_az), (get_ax() - calibra_ax)) * RAD_TO_DEG);
    double gyroXrate = (double) (get_gx() - calibra_gx) / 131.0;
    angulo1 = (signed int) getAngle(accXangle, gyroXrate, 0.01);
//    angulo = (signed int) Complementary2(accXangle, gyroXrate, 10);
//    plot3(angulo, angulo1, accXangle);



}

