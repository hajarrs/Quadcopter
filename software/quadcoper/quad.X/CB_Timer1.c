#include <p30F4013.h>

#include "CB_Timer1.h"



void Delay1msT1(unsigned char _Interrupcion)
{
    T1CON = 0b0000000000010000; // Preescala 1:8
    PR1 = 0x0E60;       // 0x0E30 segun excel
    TMR1 = 0;
    IFS0bits.T1IF = 0;
    T1CONbits.TON = 1;
    _T1IE = _Interrupcion;
    if(!_Interrupcion)
    {
        while(IFS0bits.T1IF == 0);
        T1CONbits.TON = 0;
    }
}


void interrupcion _T1Interrupt(void)
{
    Delay1msT1(1);
}


void DelayXmsT1(int _msg)
{
    do
    {
        Delay1msT1(0);
        _msg--;
    }while(_msg >=0);
}
