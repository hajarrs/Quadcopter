/* 
 * File:   CB_Timer2.h
 * Author: Raul
 *
 * Created on 28 de agosto de 2013, 11:40
 */

#ifndef CB_TIMER2_H
#define	CB_TIMER2_H

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

#endif	/* CB_TIMER2_H */

