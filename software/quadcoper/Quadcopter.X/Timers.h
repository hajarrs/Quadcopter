/* 
 * File:   CB_Timer1.h
 * Author: Raul
 *
 * Created on 24 de agosto de 2013, 21:25
 */

#ifndef CB_TIMER1_H
#define	CB_TIMER1_H
#include "Defines.h"
#define interrupcion	__attribute__((interrupt,no_auto_psv))
void Delay1msT1(unsigned char _Interrupcion);
void DelayXmsT1(int _msg);
void Delay_Nop(unsigned int _contador);
void SetupT3ForXmsPID(int _tiempo);
void StartInterrup3();
void StopInterrup3();
void Bucle_Principal();
void interrupcion _T1Interrupt(void);
void interrupcion _T3Interrupt(void);
void interrupcion _T5Interrupt(void);


#endif	/* CB_TIMER1_H */

