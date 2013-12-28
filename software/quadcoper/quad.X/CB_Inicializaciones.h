/* 
 * File:   CB_Inicializaciones.h
 * Author: Raul
 *
 * Created on 22 de agosto de 2013, 19:28
 */

#ifndef CB_INICIALIZACIONES_H
#define	CB_INICIALIZACIONES_H
#include <i2c.h>
#include "Defines.h"
#include "CB_Timer1.h"
#include "CB_Timer2.h"
#include "CB_I2C.h"
#include "CA_SetGetMPU6050.h"
void Init_Hw(void);
void Init_I2C(void);
void Init_PWM();
void Init_Bluetooh(void);
void LED_ALL_ON();
void LED_ALL_OFF();
void clockSwitch (unsigned int newNOSCCode);
void Init_Pll(void);

#endif	/* CB_INICIALIZACIONES_H */

