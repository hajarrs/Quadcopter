#include "CB_Timer5.h"

void interrupcion _T5Interrupt(void)
{
    IFS1bits.T5IF = 0;
    //accion
}
