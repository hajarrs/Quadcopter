/* 
 * File:   CA_funciones_control.h
 * Author: pablo
 *
 * Created on 23 de enero de 2014, 23:40
 */
#ifndef CA_FUNCIONES_CONTROL_H
#define	CA_FUNCIONES_CONTROL_H
#include <math.h>
#include "CB_Bluetooth.h"
extern int KP;
extern int KD;
extern int KI;
extern int BIAS1;
extern int BIAS2;
extern int Tmuestreo;
extern int abs(int);
int Pid_Posicion(int _setpoint,int _posicion_actual);
int PID(int _Bias, int _PosicionActual, int Tmuestreo, int _kp, int _kd, int _ki, int* _PosicionAnterior, int _Maximo, int _Minimo );
#endif	/* CA_FUNCIONES_CONTROL_H */

