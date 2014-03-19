/*
 * File:   CB_Timer5.h
 * Author: Pablo
 *
 * Created on 28 de agosto de 2013, 11:43
 */

#ifndef CB_TIMER5_H
#define	CB_TIMER5_H

#include "CB_I2C.h"

#define interrupcion	__attribute__((interrupt,no_auto_psv))

void interrupcion _T5Interrupt(void);


#endif	/* CB_TIMER5_H */

