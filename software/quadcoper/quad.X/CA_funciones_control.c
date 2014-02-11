/* 
 * File:   CA_funciones_control.c
 * Author: pablo
 *
 * Created on 23 de enero de 2014, 23:41
 */
#include "CA_funciones_control.h"
int errorAnt=0;
int Pid_Posicion(int _setpoint,int _posicion_actual)
{
    int valorPID,_error;
    _error=_setpoint - _posicion_actual;
    valorPID = KP*(_error) + KD*(_error - errorAnt);

    errorAnt = _error;
    return(valorPID);
}

<<<<<<< HEAD
=======
/*working variables*/
unsigned long lastTime;
double Input, Output, Setpoint;
double ITerm, lastInput;

// SetPoint = BIAS

int PID(int _referencia, int _PosicionActual, int Tmuestreo, int _kp,int _ki, int _kd, int* _PosicionAnterior, int _Maximo, int _Minimo )
{
    int error = _referencia - _PosicionActual;
    ITerm += (_ki * error);

    if(ITerm > 2000)    ITerm = 2000;
    if(ITerm < -2000)   ITerm = -2000;


    int dInput = (_PosicionActual - (*_PosicionAnterior));
    Output = _kp * error - _kd * dInput + ITerm;
    if(Output >= _Maximo)   Output = _Maximo;
    if(Output <= _Minimo)   Output = _Minimo;

    (*_PosicionAnterior) = _PosicionActual;

     PWM1 = BIAS1+Output;
     PWM4 = BIAS2-Output;

    enviar_valor_NOCR("valorAux = ",_referencia);
    enviar_valor_NOCR(" valorAuxAnterior = ",_PosicionActual);
    enviar_valor_NOCR("pid = ",(*_PosicionAnterior));
    enviar_valor_NOCR(" Ep = ",error);
    enviar_valor_NOCR(" Ed = ",dInput);
    enviar_valor(" Ei = ",ITerm);



    return Output;
}

>>>>>>> origin/intento-reparacion-de-problemas-de-alimentacion
