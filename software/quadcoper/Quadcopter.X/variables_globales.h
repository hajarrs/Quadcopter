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

int chanel1 = 0;
int chanel2 = 0;
int chanel3 = 0;
int chanel4 = 0;
int chanel5 = 0;


//***********variables del pid********************//

int KP_zx = 13;
int KD_zx = 1000;
int KI_zx = 1;
int BIAS1_zx = 400;
int BIAS2_zx = 400;

int KP_zy = 13;
int KD_zy = 1000;
int KI_zy = 1;
int BIAS1_zy = 400;
int BIAS2_zy = 400;

int KP_xy = 10;
int KD_xy = 10;
int KI_xy = 1;
int BIAS1_xy = 0;
int BIAS2_xy = 0;

int Tmuestreo = 8;
int error_anterior_zx=0;
int ErrorI_zx=0;
int error_anterior_zy=0;
int ErrorI_zy=0;
int error_anterior_xy=0;
int ErrorI_xy=0;







//************************* VARIABLES DE KALMAN ****************//

double Q_angle = 0.03;//0.01 // Process noise variance for the accelerometer
double Q_bias = 0.03; //0.03  Process noise variance for the gyro bias
double R_measure= 0.002; //0.03 Measurement noise variance - this is actually the variance of the measurement noise

double angle = 1; // Reset the angle // The angle calculated by the Kalman filter - part of the 2x1 state vector
double bias = 0; // The gyro bias calculated by the Kalman filter - part of the 2x1 state vector
double rate=0; // Unbiased rate calculated from the rate and the calculated bias - you have to call getAngle to update the rate

double P[2][2]; // Error covariance matrix - This is a 2x2 matrix
double K[2]; // Kalman gain - This is a 2x1 vector
double y=1; // Angle difference
double S=100; // Estimate error
//************************* VARIABLES DE COMPLEMENTARY ****************//
float x_angle2C=0;
int i=0;




//************************* VARIBLES DE CALIBRADO ****************//
double calibra_ax=0;
double calibra_ay=0;
double calibra_az=0;
double calibra_gx=0;
double calibra_gy=0;
double calibra_gz=0;

//-------------------------------------------------------------
//necesarias por que las inperrupciones no permiten parametros
//-------------------------------------------------------------

#endif	/* VARIABLES_GLOBALES_H */

