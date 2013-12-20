/* 
 * File:   Pruebas.h
 * Author: Raul
 *
 * Created on 22 de agosto de 2013, 20:04
 */

#ifndef PRUEBAS_H
#define	PRUEBAS_H

extern int AccX, AccY, AccZ, GyroX, GyroY, GyroZ, Temp;
extern double accXangle, accYangle; // Angle calculate using the accelerometer
extern double gyroXangle, gyroYangle; // Angle calculate using the gyro
extern double compAngleX, compAngleY; // Calculate the angle using a complementary filter
extern double kalAngleX, kalAngleY; // Calculate the angle using a Kalman filter

extern char str_blue[40];

void Prueba2_PWM(void);
void Prueba_PWM(void);
void Prueba_Bluetooth(void);
void Prueba_I2C(void);
void Prueba_LED();
void enviarDatosFiltro(void);
void EjecutarPID(void);


#endif	/* PRUEBAS_H */

