/* 
 * File:   CA_funciones_control.c
 * Author: pablo
 *
 * Created on 23 de enero de 2014, 23:41
 */
#include "CA_funciones_control.h"

int KP=10;
int KD=2;
int errorAnt=0;


int Pid_Posicion(int _setpoint,int _posicion_actual)
{
    int valorPID,_error;
    _error=_setpoint - _posicion_actual;
    valorPID = KP*(_error) + KD*(_error - errorAnt);

    errorAnt = _error;
    return(valorPID);
}

