/* 
 * File:   main.h
 * Author: Raul
 *
 * Created on 20 de octubre de 2013, 23:39
 */

#ifndef MAIN_H
#define	MAIN_H

void Bucle_Principal();

#include <xc.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <libq.h>
#include "define_comet_code.h"
#include "variables_globales.h"
#include "Defines.h"
#include "CB_Inicializaciones.h"
#include "CA_SetGetMPU6050.h"
#include "CB_Timer1.h"
#include "CB_Timer2.h"
#include "CB_Bluetooth.h"
#include "Pruebas.h"
#include "CA_calibrado_filtro.h"

int LSD[12];
char str_blue[40];
char str_aux[40];
extern int valorAuxAnterior;
//extern StructKalman xz;

void get_calibrado_acelerometro(int milis, int n);


#endif	/* MAIN_H */

