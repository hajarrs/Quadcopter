/* 
 * File:   main.h
 * Author: Raul
 *
 * Created on 20 de octubre de 2013, 23:39
 */

#ifndef MAIN_H
#define	MAIN_H

typedef struct {
double Q_angle ; // Process noise variance for the accelerometer
double Q_bias ; // Process noise variance for the gyro bias
double R_measure ; // Measurement noise variance - this is actually the variance of the measurement noise

double angle ; // Reset the angle // The angle calculated by the Kalman filter - part of the 2x1 state vector
double bias ; // The gyro bias calculated by the Kalman filter - part of the 2x1 state vector
double rate; // Unbiased rate calculated from the rate and the calculated bias - you have to call getAngle to update the rate

double P[2][2]; // Error covariance matrix - This is a 2x2 matrix
double K[2]; // Kalman gain - This is a 2x1 vector
double y; // Angle difference
double S; // Estimate error
float x_angle2C;
} StructKalman;

#include <xc.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <libq.h>
#include <dsp.h>
#include "define_comet_code.h"
#include "variables_globales.h"
#include "Defines.h"
#include "Init.h"
#include "Timers.h"
#include "Bluetooth.h"
#include "Pruebas.h"


_Q15 _Q15ftoi(float);

tPID fooPID;
fractional abcCoefficient[3] __attribute__((section(".xbss, bss, xmemory")));
fractional controlHistory[3] __attribute__((section(".ybss, bss, ymemory")));
fractional kCoeffs[] = {0, 0, 0};

int LSD[12];
char str_blue[40];
char str_aux[40];
extern int valorAuxAnterior;

void Bucle_Principal();
void get_calibrado_acelerometro(int milis, int n);
void getAngle_init();
int _PID(int _referencia, int _PosicionActual, int Tmuestreo, int _kp, int _ki, int _kd, int _Maximo, int _Minimo);


StructKalman zx,zy,xy;

//-------------------------Pid variables-----------------//

int errorAnt=0;
StructKalman zx,zy,xy;

//***********************varibles de calibrado*************//



//***********************varibles de pid*************//


void getAngle_init_xz();
//void pid_dsp_configuracion();


#endif	/* MAIN_H */

