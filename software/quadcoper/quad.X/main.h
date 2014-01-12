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
#include "Defines.h"
#include "CB_Inicializaciones.h"
#include "CA_SetGetMPU6050.h"
#include "CB_Timer1.h"
#include "CB_Timer2.h"
#include "CB_Bluetooth.h"
#include "Pruebas.h"
#include "CA_calibrado_filtro.h"

int LSD[12];
int AccX, AccY, AccZ, GyroX, GyroY, GyroZ, Temp;
double accXangle, accYangle; // Angle calculate using the accelerometer
double temp; // Temperature
double gyroXangle, gyroYangle; // Angle calculate using the gyro
double compAngleX, compAngleY; // Calculate the angle using a complementary filter
double kalAngleX, kalAngleY; // Calculate the angle using a Kalman filter

char str_blue[40];
char str_aux[40];





#endif	/* MAIN_H */

