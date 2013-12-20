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
unsigned int get_ax(void);
unsigned int get_ay(void);
unsigned int get_az(void);
unsigned int get_gx(void);
unsigned int get_gy(void);
unsigned int get_gz(void);
unsigned int get_who_I_AM(void);




#endif	/* CA_PETICIONENESMPU6050_H */

