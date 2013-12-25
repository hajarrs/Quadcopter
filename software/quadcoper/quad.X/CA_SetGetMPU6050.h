/* 
 * File:   CA_peticionenesMPU6050.h
 * Author: pablo
 *
 * Created on 20 de diciembre de 2013, 0:41
 */

#ifndef CA_SetGetMPU6050_H
#define	CA_SetGetMPU6050_H
#include "Defines.h"
#include "CB_I2C.h"

void set_inicial(void);
int get_ax(void);
int get_ay(void);
int get_az(void);
int get_gx(void);
int get_gy(void);
int get_gz(void);
int get_who_I_AM(void);
void plot1(int valor1);
void plot2(int valor1, int valor2);
void plot3(int valor1, int valor2,int valor3);
void plot4(int valor1, int valor2,int valor3,int valor4);





#endif	/* CA_PETICIONENESMPU6050_H */

