/* 
 * File:   CA_funciones_control.h
 * Author: pablo
 *
 * Created on 23 de enero de 2014, 23:40
 */
#ifndef CA_FUNCIONES_CONTROL_H
#define	CA_FUNCIONES_CONTROL_H

//extern StructKalman zx,zy,xy;

#include <math.h>
#include <dsp.h>
#include <libq.h>
#include "variables_globales.h"
#include "CB_Bluetooth.h"



//***********************structura kalman*******************//



//-----------kalman----------//
_Q15 _Q15ftoi(float);
//extern double Q_angle ; // Process noise variance for the accelerometer
//extern double Q_bias ; // Process noise variance for the gyro bias
//extern double R_measure ; // Measurement noise variance - this is actually the variance of the measurement noise
//
//extern double angle ; // Reset the angle // The angle calculated by the Kalman filter - part of the 2x1 state vector
//extern double bias ; // The gyro bias calculated by the Kalman filter - part of the 2x1 state vector
//extern double rate; // Unbiased rate calculated from the rate and the calculated bias - you have to call getAngle to update the rate
//
//extern double P[2][2]; // Error covariance matrix - This is a 2x2 matrix
//extern double K[2]; // Kalman gain - This is a 2x1 vector
//extern double y; // Angle difference
//extern double S; // Estimate error
//extern float x_angle2C;

//************** Variable Kalman Structura*******************


//-------------------------Pid variables-----------------//

extern int KP;
extern int KD;
extern int KI;
extern int BIAS1;
extern int BIAS2;
extern int Tmuestreo;
extern int valorAuxAnterior;
extern int abs(int);

//***********************varibles de calibrado*************//

extern double calibra_ax;
extern double calibra_ay;
extern double calibra_az;
extern double calibra_gx;
extern double calibra_gy;
extern double calibra_gz;

//***********************varibles de pid*************//

tPID fooPID;
fractional abcCoefficient[3] __attribute__((section(".xbss, bss, xmemory")));
fractional controlHistory[3] __attribute__((section(".ybss, bss, ymemory")));
fractional kCoeffs[] = {0, 0, 0};

void getAngle_init_xz();
void pid_dsp_configuracion();



#endif	/* CA_FUNCIONES_CONTROL_H */

