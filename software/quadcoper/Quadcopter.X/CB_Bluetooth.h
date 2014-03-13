/* 
 * File:   CB_Bluetooth.h
 * Author: Raul
 *
 * Created on 22 de agosto de 2013, 20:09
 */

#ifndef CB_BLUETOOTH_H
#define	CB_BLUETOOTH_H

#include <stdlib.h>
#include <string.h>
#include "CB_Timer1.h"
#include "CB_Timer2.h"
#include "CB_Timer3.h"
 extern int chanel1;
     extern   int chanel2;
     extern   int chanel3;
     extern   int chanel4;
     extern   int chanel5;
     extern int KP;
     extern int KD;
     extern int KI;
     extern int BIAS1;
     extern int BIAS2;
     extern int Tmuestreo;
void EnviarCR();
void enviar_datos_NOCR(char cadena[50], int longitud);
void enviar_datos(char cadena[50], int longitud);
void enviar_Udatos_NOCR(unsigned char cadena[50], int longitud);
void enviar_Udatos(unsigned char cadena[50], int longitud);
void EnviarSensores(int numero);
void EnviarDatos_Acc_Gyro(unsigned int _mascara);
void enviar_valor(char nombre[],int valor);
void enviar_mensaje(char nombre[]);

void ProcesarCadenaPid(char *cadena);
void StopPID();
void interrupcion _U2RXInterrupt(void) ;
void enviar_datos_int_NOCR(int cadena[50], int _longitud);
void enviar_valor_NOCR(char nombre[], int valor);
#endif	/* CB_BLUETOOTH_H */
