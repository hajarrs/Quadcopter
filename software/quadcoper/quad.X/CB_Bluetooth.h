/* 
 * File:   CB_Bluetooth.h
 * Author: Raul
 *
 * Created on 22 de agosto de 2013, 20:09
 */

#ifndef CB_BLUETOOTH_H
#define	CB_BLUETOOTH_H

#include "Var_Globales.h"


#define DEF_BLUE

void EnviarCR()
{
#ifdef DEF_BLUE
    U2TXREG = '\r';
    while(!U2STAbits.TRMT);
    U2TXREG = '\n';
    while(!U2STAbits.TRMT);
#endif
}


void enviar_datos_NOCR(char cadena[50], int longitud)
{
#ifdef DEF_BLUE
    unsigned char index;
    for(index=0; index<longitud; index++)
    {
        U2TXREG = cadena[index];
        while(!U2STAbits.TRMT);
    }
#endif
}

void enviar_datos(char cadena[50], int longitud)
{
#ifdef DEF_BLUE
    enviar_datos_NOCR(cadena, longitud);
    EnviarCR();
#endif
}



void enviar_Udatos_NOCR(unsigned char cadena[50], int longitud)
{
#ifdef DEF_BLUE
    unsigned char index;
    for(index=0; index<longitud; index++)
    {
        U2TXREG = cadena[index];
        while(!U2STAbits.TRMT);
    }
#endif
}

void enviar_Udatos(unsigned char cadena[50], int longitud)
{
#ifdef DEF_BLUE
    enviar_Udatos_NOCR(cadena, longitud);
    EnviarCR();
#endif
}

void EnviarSensores(int numero)
{
    int i;

    for(i=(numero-1); i>=0; i--)
    {
        itoa(str_blue,LSD[i], 10);
        enviar_datos_NOCR(str_blue, strlen(str_blue));
        strcpy(str_blue," ");
        enviar_datos_NOCR(str_blue, strlen(str_blue));
    }
    EnviarCR();
    
}

void EnviarDatos_Acc_Gyro(unsigned int _mascara)
{
    if(_mascara & COM_ACC_X)
    {
        strcpy(str_blue, "AccX: ");
        enviar_datos_NOCR(str_blue,strlen(str_blue));

        utoa(str_blue,AccX,10);
        enviar_datos_NOCR(str_blue,strlen(str_blue));
        strcpy(str_blue, " ");
        enviar_datos_NOCR(str_blue,strlen(str_blue));
    }
    if(_mascara & COM_ACC_Y)
    {
        strcpy(str_blue, "AccY: ");
        enviar_datos_NOCR(str_blue,strlen(str_blue));

        utoa(str_blue,AccY,10);
        enviar_datos_NOCR(str_blue,strlen(str_blue));
        strcpy(str_blue, " ");
        enviar_datos_NOCR(str_blue,strlen(str_blue));
    }
    if(_mascara & COM_ACC_Z)
    {
        strcpy(str_blue, "AccZ: ");
        enviar_datos_NOCR(str_blue,strlen(str_blue));

        utoa(str_blue,AccZ,10);
        enviar_datos_NOCR(str_blue,strlen(str_blue));
        strcpy(str_blue, " ");
        enviar_datos_NOCR(str_blue,strlen(str_blue));
    }
    if(_mascara & COM_GYRO_X)
    {
        strcpy(str_blue, "GyroX: ");
        enviar_datos_NOCR(str_blue,strlen(str_blue));

        utoa(str_blue,GyroX,10);
        enviar_datos_NOCR(str_blue,strlen(str_blue));
        strcpy(str_blue, " ");
        enviar_datos_NOCR(str_blue,strlen(str_blue));
    }
    if(_mascara & COM_GYRO_Y)
    {
        strcpy(str_blue, "GyroY: ");
        enviar_datos_NOCR(str_blue,strlen(str_blue));

        utoa(str_blue,GyroY,10);
        enviar_datos_NOCR(str_blue,strlen(str_blue));
        strcpy(str_blue, " ");
        enviar_datos_NOCR(str_blue,strlen(str_blue));
    }
    if(_mascara & COM_GYRO_Z)
    {
        strcpy(str_blue, "GyroZ: ");
        enviar_datos_NOCR(str_blue,strlen(str_blue));
        
        utoa(str_blue,GyroZ,10);
        enviar_datos_NOCR(str_blue,strlen(str_blue));
        strcpy(str_blue, " ");
        enviar_datos_NOCR(str_blue,strlen(str_blue));
    }

    if(_mascara & COM_TEMP_G)
    {
        strcpy(str_blue, "Temp: ");
        enviar_datos_NOCR(str_blue,strlen(str_blue));

        utoa(str_blue,Temp,10);
        enviar_datos_NOCR(str_blue,strlen(str_blue));
        strcpy(str_blue, " ");
        enviar_datos_NOCR(str_blue,strlen(str_blue));
    }

    EnviarCR();
}


#endif	/* CB_BLUETOOTH_H */

