/* 
 * File:   calibrado_filtro.c
 * Author: pablo
 *
 * Created on 20 de diciembre de 2013, 0:25
 */
#include "CA_calibrado_y_filtros.h"

// variables globales para filtros
int tau = 0.075;
int a = 0.0;
int x_angleC;



int Q_angle = 0.01; //0.001
int Q_gyro = 0.0003; //0.003
int R_angle = 0.01; //0.03
int x_bias = 0;
int P_00 = 0, P_01 = 0, P_10 = 0, P_11 = 0;
int y, S;
int K_0, K_1;
int x_angle;
int dt;

void get_calibrado_acelerometro(int milis,int n, int *_calibra_ax, int *_calibra_ay, int *_calibra_az, int *_calibra_gx, int *_calibra_gy, int *_calibra_gz)
{
    DelayXmsT1(milis);
    int i;
    double calibra_ax_double = (*_calibra_ax);
    double calibra_ay_double = (*_calibra_ay);
    double calibra_az_double = (*_calibra_az);
    double calibra_gx_double = (*_calibra_gx);
    double calibra_gy_double = (*_calibra_gy);
    double calibra_gz_double = (*_calibra_gz);
    
    
            
    for (i = 0; i < n; i++)
    {
        calibra_ax_double = get_ax() + calibra_gx_double;
        calibra_ay_double = get_ay() + calibra_gy_double;
        calibra_az_double = get_az() + calibra_gz_double;
        calibra_gx_double = get_gx() + calibra_gx_double;
        calibra_gy_double = get_gy() + calibra_gy_double;
        calibra_gz_double = get_gz() + calibra_gz_double;
    }

    *_calibra_ax = calibra_ax_double / 50;
    *_calibra_ay = calibra_ax_double / 50;
    *_calibra_az = calibra_ax_double / 50;
    *_calibra_gx = calibra_ax_double / 50;
    *_calibra_gy = calibra_ax_double / 50;
    *_calibra_gz = calibra_ax_double / 50;

}

// a=tau / (tau + loop time)
// newAngle = angle measured with atan2 using the accelerometer
// newRate = angle measured using the gyro
// looptime = loop time in millis()


//int  Complementary(int  newAngle, int  newRate,int looptime) {
//dtC = looptime/1000;
//a=tau/(tau+dtC);
//x_angleC= a* (x_angleC + newRate * dtC) + (1-a) * (newAngle);
//return x_angleC;
//}

// newAngle = angle measured with atan2 using the accelerometer
// newRate = angle measured using the gyro
// looptime = loop time in millis()

//int  Complementary2(int  newAngle, int  newRate,int looptime) {
//enviar_valor("newAngle= ",newAngle);
//enviar_valor("newRate= ",newRate);
//enviar_valor("looptime= ",looptime);
//dtc2=1000/1000.0;
//enviar_valor("dtc2= ",(int)dtc2);
//x1 = ((float)newAngle -   x_angle2C)*k*k;
//enviar_valor("x1= ",(int)x1);
//y1 = dtc2*x1 + y1;
//enviar_valor("y1= ",(int)y1);
//x2 = y1 + (newAngle -   x_angle2C)*2*k + newRate;
//enviar_valor("x2= ",(int)x2);
//x_angle2C = dtc2*x2 + x_angle2C;
//enviar_valor("x_angle2C= ",(int)x_angle2C);
//
//
//return (int) x_angle2C;
//}
//

// KasBot V1 - Kalman filter module

// newAngle = angle measured with atan2 using the accelerometer
// newRate = angle measured using the gyro
// looptime = loop time in millis()

int kalmanCalculate(int newAngle, int newRate, int looptime)
{
    dt = looptime / 1000;
    x_angle += dt * (newRate - x_bias);
    P_00 += -dt * (P_10 + P_01) + Q_angle * dt;
    P_01 += -dt * P_11;
    P_10 += -dt * P_11;
    P_11 += +Q_gyro * dt;

    y = newAngle - x_angle;
    S = P_00 + R_angle;
    K_0 = P_00 / S;
    K_1 = P_10 / S;

    x_angle += K_0 * y;
    x_bias += K_1 * y;
    P_00 -= K_0 * P_00;
    P_01 -= K_0 * P_01;
    P_10 -= K_1 * P_00;
    P_11 -= K_1 * P_01;

    return x_angle;
}

#define ACCELEROMETER_SENSITIVITY 8192.0
#define GYROSCOPE_SENSITIVITY 65.536

#define M_PI 3.14159265359

#define dt 0.01							// 10 ms sample rate!

void ComplementaryFilter(int ax,int ay,int az,int gx,int gy,int gz, float *pitch, float *roll)
{
    float pitchAcc, rollAcc;

 //    Integrate the gyroscope data -> int(angularSpeed) = angle
    *pitch += ((float)gx / GYROSCOPE_SENSITIVITY) * dt; // Angle around the X-axis
    *roll -= ((float)gy / GYROSCOPE_SENSITIVITY) * dt;    // Angle around the Y-axis

     //Compensate for drift with accelerometer data if !bullshit
    // Sensitivity = -2 to 2 G at 16Bit -> 2G = 32768 && 0.5G = 8192
    int forceMagnitudeApprox = abs(ax) + abs(ay) + abs(az);
    if (forceMagnitudeApprox > 8192 && forceMagnitudeApprox < 32768)
    {
	// Turning around the X axis results in a vector on the Y-axis
        pitchAcc = atan2f((float)ay, (float)az) * 180 / M_PI;
        *pitch = *pitch * 0.98 + pitchAcc * 0.02;

	// Turning around the Y axis results in a vector on the X-axis
        rollAcc = atan2f((float)ax, (float)az) * 180 / M_PI;
        *roll = *roll * 0.98 + rollAcc * 0.02;
    }
}