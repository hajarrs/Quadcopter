/* 
 * File:   variables_globales.h
 * Author: pablo
 *
 * Created on 24 de enero de 2014, 1:37
 */

#ifndef VARIABLES_GLOBALES_H
#define	VARIABLES_GLOBALES_H

//*************************************************************
//*********************VARIABLES GLOBALES**********************
//*************************************************************

extern int chanell;
extern int chanel2;
extern int chanel3;
extern int chanel4;
extern int chanel5;



int chanel1 = 0;
int chanel2 = 0;
int chanel3 = 0;
int chanel4 = 0;
int chanel5 = 0;


//***********variables del pid********************//

int KP = 1;
int KD = 1;
int KI = 1;
int BIAS1 = 1;
int BIAS2 = 1;
int Tmuestreo = 1;



//************************* VARIABLES DE KALMAN ****************//

double Q_angle = 0.001; // Process noise variance for the accelerometer
double Q_bias = 0.003; // Process noise variance for the gyro bias
double R_measure= 0.03; // Measurement noise variance - this is actually the variance of the measurement noise

double angle = 0; // Reset the angle // The angle calculated by the Kalman filter - part of the 2x1 state vector
double bias = 0; // The gyro bias calculated by the Kalman filter - part of the 2x1 state vector
double rate; // Unbiased rate calculated from the rate and the calculated bias - you have to call getAngle to update the rate

double P[2][2]; // Error covariance matrix - This is a 2x2 matrix
double K[2]; // Kalman gain - This is a 2x1 vector
double y; // Angle difference
double S; // Estimate error


// P[0][0] = 0; // Since we assume that the bias is 0 and we know the starting angle (use setAngle), the error covariance matrix is set like so - see: http://en.wikipedia.org/wiki/Kalman_filter#Example_application.2C_technical
// P[0][1] = 0;
// P[1][0] = 0;
// P[1][1] = 0;
//-------------------------------------------------------------
//necesarias por que las inperrupciones no permiten parametros
//-------------------------------------------------------------

#endif	/* VARIABLES_GLOBALES_H */

