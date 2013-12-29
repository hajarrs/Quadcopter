#include "CB_Timer2.h"

/**********************************************************
 *                                                        *
 *                                                        *
 *          NO UTILIZAR --> SE USA PARA EL PWM            *
 *                                                        *
 *                                                        *
***********************************************************/

void Delay_Nop(unsigned int _contador)
{
    while(_contador>0)
    {
        Nop();
        _contador--;
    }
}
