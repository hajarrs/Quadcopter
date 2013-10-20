/*
 * File:   Var_Globales.h
 * Author: Raul
 *
 * Created on 24 de agosto de 2013, 22:04
 */

#ifndef VAR_GLOBALES_C
#define	VAR_GLOBALES_C
#include <p30F4013.h>
#include "Defines.h"




// MACROS


void LED_ALL_ON()
{
    LED1 = ON;
    LED2 = ON;
    LED3 = ON;
    LED5 = ON;
    LED6 = ON;
}

void LED_ALL_OFF()
{
    LED1 = OFF;
    LED2 = OFF;
    LED3 = OFF;
    LED5 = OFF;
    LED6 = OFF;
}


#endif	/* VAR_GLOBALES_H */

