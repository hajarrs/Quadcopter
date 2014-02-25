/* 
 * File:   calibrado_filtro.c
 * Author: pablo
 *
 * Created on 20 de diciembre de 2013, 0:25
 */
#include "CA_calibrado_y_filtros.h"

// variables globales para filtros

#define ACCELEROMETER_SENSITIVITY 8192.0
#define GYROSCOPE_SENSITIVITY 65.536

#define M_PI 3.14159265359

#define dt 0.011



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

    *_calibra_ax = calibra_ax_double / n;
    *_calibra_ay = calibra_ay_double / n;
    *_calibra_az = calibra_az_double / n;
    *_calibra_gx = calibra_gx_double / n;
    *_calibra_gy = calibra_gy_double / n;
    *_calibra_gz = calibra_gz_double / n;


    return(0);


}


					// 10 ms sample rate!

void ComplementaryFilter(int ax,int ay,int az,int gx,int gy,int gz)
{
    float pitchAcc, rollAcc;
        float roll=0 ,pitch=0;
 //    Integrate the gyroscope data -> int(angularSpeed) = angle
    pitch += ((float)gx / GYROSCOPE_SENSITIVITY) * dt; // Angle around the X-axis
    roll -= ((float)gy / GYROSCOPE_SENSITIVITY) * dt;    // Angle around the Y-axis

     //Compensate for drift with accelerometer data if !bullshit
    // Sensitivity = -2 to 2 G at 16Bit -> 2G = 32768 && 0.5G = 8192
    int forceMagnitudeApprox = abs(ax) + abs(ay) + abs(az);
    if (forceMagnitudeApprox > 8192 && forceMagnitudeApprox < 32768)
    {
	// Turning around the X axis results in a vector on the Y-axis
        pitchAcc = atan2f((float)ay, (float)az) * 180 / M_PI;
        pitch = pitch * 0.98 + pitchAcc * 0.02;

	// Turning around the Y axis results in a vector on the X-axis
        rollAcc = atan2f((float)ax, (float)az) * 180 / M_PI;
        roll = roll * 0.98 + rollAcc * 0.02;
        plot2(gx,roll);
        enviar_valor("roll = ",roll);
    }
}
