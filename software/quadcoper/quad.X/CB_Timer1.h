/* 
 * File:   CB_Timer1.h
 * Author: Raul
 *
 * Created on 24 de agosto de 2013, 21:25
 */

#ifndef CB_TIMER1_H
#define	CB_TIMER1_H
#include "Defines.h"
#include "Pruebas.h"
#include "CB_Bluetooth.h"
#define interrupcion	__attribute__((interrupt,no_auto_psv))

void Delay1msT1(unsigned char _Interrupcion);
void DelayXmsT1(int _msg);
void interrupcion _T1Interrupt(void);

#endif	/* CB_TIMER1_H */

