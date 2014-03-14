#include "CB_Timer3.h"



/**********************************************************
 *                                                        *
 *                                                        *
 *          UTILIZADO PARA EL PID --> 2/3 msg             *
 *                                                        *
 *                                                        *
***********************************************************/

void SetupT3ForXmsPID(int _tiempo)
{
    T3CON = 0b0000000000100000; // Preescala 1:x
    PR3 =_tiempo*464 ; // cada milisegundo es 0x1d0 asi que lo multiplico por el numero de ms
    TMR3 = 0;
    IFS0bits.T3IF = 0;
    T3CONbits.TON = 0;
     _T3IE = 1;
}

void StartInterrup3()
{
    T3CONbits.TON = 1;
}
void StopInterrup3()
{
    T3CONbits.TON = 0;
}


void interrupcion _T3Interrupt(void)
{
    //i++;
   // if (i == 30)StopInterrup3();

    IFS0bits.T3IF = 0;
    LEDVERDE = !LEDVERDE;
    Bucle_Principal();
}
