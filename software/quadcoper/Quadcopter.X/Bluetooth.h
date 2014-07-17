/* 
 * File:   CB_Bluetooth.h
 * Author: Raul
 *
 * Created on 22 de agosto de 2013, 20:09
 */

#ifndef CB_BLUETOOTH_H
#define	CB_BLUETOOTH_H
#include <xc.h>
#include <stdlib.h>
#include <string.h>
#include "Timers.h"
extern int chanel1;
extern int chanel2;
extern int chanel3;
extern int chanel4;
extern int chanel5;


extern int BIAS1_xy;
extern int BIAS2_xy;
extern int BIAS1_zx;
extern int BIAS2_zx;
extern int BIAS1_zy;
extern int BIAS2_zy;

void EnviarCR();
void enviar_datos_NOCR(char cadena[50], int longitud);
void enviar_datos(char cadena[50], int longitud);
void enviar_Udatos_NOCR(unsigned char cadena[50], int longitud);
void enviar_Udatos(unsigned char cadena[50], int longitud);
void EnviarSensores(int numero);
void EnviarDatos_Acc_Gyro(unsigned int _mascara);
void enviar_valor(char nombre[], int valor);
void enviar_mensaje(char nombre[]);

void ProcesarCadenaPid(char *cadena);
void StopPID();
void interrupcion _U2RXInterrupt(void);
void enviar_datos_int_NOCR(int cadena[50], int _longitud);
void enviar_valor_NOCR(char nombre[], int valor);

void plot1(int valor1);
void plot2(int valor1, int valor2);
void plot3(int valor1, int valor2,int valor3);
void plot4(int valor1, int valor2,int valor3,int valor4);
#endif	/* CB_BLUETOOTH_H */

