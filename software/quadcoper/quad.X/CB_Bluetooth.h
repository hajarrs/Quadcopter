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

#include "Defines.h"
#include "CB_Timer1.h"
#include "CB_Timer2.h"
#include "CB_Timer3.h"


void EnviarCR();
void enviar_datos_NOCR(char cadena[50], int longitud);
void enviar_datos(char cadena[50], int longitud);
void enviar_Udatos_NOCR(unsigned char cadena[50], int longitud);
void enviar_Udatos(unsigned char cadena[50], int longitud);
void EnviarSensores(int numero);
void EnviarDatos_Acc_Gyro(unsigned int _mascara);
void interrupcion _U1RXInterrupt(void);
void ProcesarCadena(char *cadena);


#endif	/* CB_BLUETOOTH_H */

