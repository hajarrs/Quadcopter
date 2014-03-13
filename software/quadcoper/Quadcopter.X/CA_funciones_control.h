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
void get_calibrado_acelerometro(int milis,int n, int *_calibra_ax, int *_calibra_ay, int *_calibra_az, int *_calibra_gx, int *_calibra_gy, int *_calibra_gz);
int Pid_Posicion(int _setpoint,int _posicion_actual);
int PID(int _Bias, int _PosicionActual, int Tmuestreo, int _kp, int _kd, int _ki, int* _PosicionAnterior, int _Maximo, int _Minimo );
void getAngle_init();
double getAngle(double newAngle, double newRate, double dt) ;
float Complementary2(float newAngle, float newRate,int looptime) ;
//-----------kalman----------//

extern double Q_angle ; // Process noise variance for the accelerometer
extern double Q_bias ; // Process noise variance for the gyro bias
extern double R_measure ; // Measurement noise variance - this is actually the variance of the measurement noise

extern double angle ; // Reset the angle // The angle calculated by the Kalman filter - part of the 2x1 state vector
extern double bias ; // The gyro bias calculated by the Kalman filter - part of the 2x1 state vector
extern double rate; // Unbiased rate calculated from the rate and the calculated bias - you have to call getAngle to update the rate

extern double P[2][2]; // Error covariance matrix - This is a 2x2 matrix
extern double K[2]; // Kalman gain - This is a 2x1 vector
extern double y; // Angle difference
extern double S; // Estimate error
extern float x_angle2C;



//-------------------------Pid variables-----------------//

extern int KP;
extern int KD;
extern int KI;
extern int BIAS1;
extern int BIAS2;
extern int Tmuestreo;
extern int abs(int);

#endif	/* CA_FUNCIONES_CONTROL_H */
