/* 
 * File:   calibrado_filtro.h
 * Author: pablo
 *
 * Created on 20 de diciembre de 2013, 0:25
 */

#ifndef CALIBRADO_FILTRO_H
#define	CALIBRADO_FILTRO_H

#include "CA_SetGetMPU6050.h"
#include "CB_Bluetooth.h"
void get_calibrado_acelerometro(int milis,int n, int *_calibra_ax, int *_calibra_ay, int *_calibra_az, int *_calibra_gx, int *_calibra_gy, int *_calibra_gz);
#endif	/* CALIBRADO_FILTRO_H */

