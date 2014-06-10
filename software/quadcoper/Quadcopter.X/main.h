/* 
 * File:   main.h
 * Author: Raul
 *
 * Created on 20 de octubre de 2013, 23:39
 */

#ifndef MAIN_H
#define	MAIN_H



#include <xc.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <libq.h>
#include <dsp.h>
#include "variables_globales.h"
#include "Defines.h"
#include "Init.h"
#include "Timers.h"
#include "Bluetooth.h"
#include "eeprom.h"
#include "Pruebas.h"

typedef struct {
double Q_angle ; // Process noise variance for the accelerometer
double Q_bias ; // Process noise variance for the gyro bias
double R_measure ; // Measurement noise variance - this is actually the variance of the measurement noise

double multi_Q_angle ; // Process noise variance for the accelerometer
double multi_Q_bias ; // Process noise variance for the gyro bias
double multi_R_measure ; // Measurement noise variance - this is actually the variance of the measurement noise

double angle ; // Reset the angle // The angle calculated by the Kalman filter - part of the 2x1 state vector
double bias ; // The gyro bias calculated by the Kalman filter - part of the 2x1 state vector
double rate; // Unbiased rate calculated from the rate and the calculated bias - you have to call getAngle to update the rate

double P[2][2]; // Error covariance matrix - This is a 2x2 matrix
double K[2]; // Kalman gain - This is a 2x1 vector
double y; // Angle difference
double S; // Estimate error
float x_angle2C;
} StructKalman;


_Q15 _Q15ftoi(float);

tPID fooPID;
fractional abcCoefficient[3] __attribute__((section(".xbss, bss, xmemory")));
fractional controlHistory[3] __attribute__((section(".ybss, bss, ymemory")));
fractional kCoeffs[] = {0, 0, 0};

char str_blue[40];
char str_aux[40];
extern int Tsample;
extern int error_anterior_zx;
extern int ErrorI_zx;
extern int error_anterior_zy;
extern int ErrorI_zy;
extern int error_anterior_xy;
extern int ErrorI_xy;

void Bucle_Principal();
void get_calibrado_acelerometro(int milis, int n);
void getAngle_init();
int PD(int _referencia, int _PosicionActual, int Tmuestreo, int _kp, int _ki, int _kd, int _Maximo, int _Minimo);
int mod_zx(int _referencia, int _PosicionActual, int Tmuestreo, int _kp, int _ki, int _kd, int _Maximo, int _Minimo, int _MaximoI, int _MinimoI) ;
int mod_zy(int _referencia, int _PosicionActual, int Tmuestreo, int _kp, int _ki, int _kd, int _Maximo, int _Minimo, int _MaximoI, int _MinimoI) ;
int mod_xy(int _referencia, int _PosicionActual, int Tmuestreo, int _kp, int _ki, int _kd, int _Maximo, int _Minimo, int _MaximoI, int _MinimoI) ;
float Complementary2(float newAngle, float newRate,int looptime) ;
void pon_motores(int M1, int M2, int M3, int M4,int incremento);
double getAngleStruct_zx(double newAngle, double newRate, double dt);
double getAngleStruct_zy(double newAngle, double newRate, double dt);
double getAngleStruct_xy(double newAngle, double newRate, double dt);

StructKalman zx,zy,xy;
int errorAnt=0;
void getAngle_init_xz();
void GetPwm1(int velocidad);
void GetPwm2(int velocidad);
void GetPwm3(int velocidad);
void GetPwm4(int velocidad);
void cargar_datos_ajuste(void);





#endif	/* MAIN_H */