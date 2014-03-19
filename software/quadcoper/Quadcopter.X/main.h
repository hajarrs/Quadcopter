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
#include <dsp.h>
#include "define_comet_code.h"
#include "variables_globales.h"
#include "Defines.h"
#include "variables_globales.h"
#include "CB_Inicializaciones.h"
#include "CA_SetGetMPU6050.h"
#include "CB_Timer1.h"
#include "CB_Timer2.h"
#include "CB_Bluetooth.h"
#include "Pruebas.h"
#include "CA_calibrado_filtro.h"
#include "CA_funciones_control.h"


int LSD[12];
char str_blue[40];
char str_aux[40];





#endif	/* MAIN_H */

