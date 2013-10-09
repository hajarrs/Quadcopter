/* 
 * File:   Var_Globales.h
 * Author: Raul
 *
 * Created on 24 de agosto de 2013, 22:04
 */

#ifndef VAR_GLOBALES_H
#define	VAR_GLOBALES_H

int LSD[12];
int AccX, AccY, AccZ, GyroX, GyroY, GyroZ, Temp;
double accXangle, accYangle; // Angle calculate using the accelerometer
double temp; // Temperature
double gyroXangle, gyroYangle; // Angle calculate using the gyro
double compAngleX, compAngleY; // Calculate the angle using a complementary filter
double kalAngleX, kalAngleY; // Calculate the angle using a Kalman filter

char str_blue[40];
char str_aux[40];



// MACROS


void LED_ALL_ON()
{
    LED1 = ON;
    LED2 = ON;
    LED3 = ON;
    LED5 = ON;
    LED6 = ON;
}

void LED_ALL_OFF()
{
    LED1 = OFF;
    LED2 = OFF;
    LED3 = OFF;
    LED5 = OFF;
    LED6 = OFF;
}


#endif	/* VAR_GLOBALES_H */

