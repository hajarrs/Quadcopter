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
void getAngle_init()
{
 P[0][0] = 0; // Since we assume that the bias is 0 and we know the starting angle (use setAngle), the error covariance matrix is set like so - see: http://en.wikipedia.org/wiki/Kalman_filter#Example_application.2C_technical
 P[0][1] = 0;
 P[1][0] = 0;
 P[1][1] = 0;
}
    double getAngle(double newAngle, double newRate, double dt) {
        // KasBot V2 - Kalman filter module - http://www.x-firm.com/?page_id=145
        // Modified by Kristian Lauszus
        // See my blog post for more information: http://blog.tkjelectronics.dk/2012/09/a-practical-approach-to-kalman-filter-and-how-to-implement-it

        // Discrete Kalman filter time update equations - Time Update ("Predict")
        // Update xhat - Project the state ahead
        /* Step 1 */
        rate = newRate - bias;
        angle += dt * rate;
        // Update estimation error covariance - Project the error covariance ahead
        /* Step 2 */
        P[0][0] += dt * (dt*P[1][1] - P[0][1] - P[1][0] + Q_angle);
        P[0][1] -= dt * P[1][1];
        P[1][0] -= dt * P[1][1];
        P[1][1] += Q_bias * dt;
        // Discrete Kalman filter measurement update equations - Measurement Update ("Correct")
        // Calculate Kalman gain - Compute the Kalman gain
        /* Step 4 */
        S = P[0][0] + R_measure;
        /* Step 5 */
        K[0] = P[0][0] / S;
        K[1] = P[1][0] / S;
        // Calculate angle and bias - Update estimate with measurement zk (newAngle)
        /* Step 3 */
        y = newAngle - angle;
        /* Step 6 */
        angle += K[0] * y;
        bias += K[1] * y;
        // Calculate estimation error covariance - Update the error covariance
        /* Step 7 */
        P[0][0] -= K[0] * P[0][0];
        P[0][1] -= K[0] * P[0][1];
        P[1][0] -= K[1] * P[0][0];
        P[1][1] -= K[1] * P[0][1];
        return angle;
    };

