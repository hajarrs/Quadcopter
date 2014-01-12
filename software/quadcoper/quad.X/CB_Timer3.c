#include "CB_Timer3.h"



/**********************************************************
 *                                                        *
 *                                                        *
 *          UTILIZADO PARA EL PID --> 2/3 msg             *
 *                                                        *
 *                                                        *
***********************************************************/

void SetupT3For2_3msPID(int _tiempo)
{
    T3CON = 0b0000000000100000; // Preescala 1:x
    if(_tiempo == 3)
        PR3 = 0x03A0;         // PR3 = 0x03A0;       // 2 msg
    else
        PR3 = 0x0570;         // PR3 = 0x0570;       // 3 msg
    TMR3 = 0;
    IFS0bits.T3IF = 0;
    T3CONbits.TON = 0;
    _T3IE = 1;
}

void StartPID()
{
    T3CONbits.TON = 1;
}
void StopPID()
{
    T3CONbits.TON = 0;
}
void interrupcion _T3Interrupt(void)
{
    IFS0bits.T3IF = 0;
    EjecutarPID();
}
