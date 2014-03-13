/* 
 * File:   CA_funciones_control.c
 * Author: pablo
 *
 * Created on 23 de enero de 2014, 23:41
 */
#include "CA_funciones_control.h"
int errorAnt = 0;

int Pid_Posicion(int _setpoint, int _posicion_actual)
{
    int valorPID, _error;
    _error = _setpoint - _posicion_actual;
    valorPID = KP * (_error) + KD * (_error - errorAnt);

    errorAnt = _error;
    return (valorPID);
}

/*working variables*/
unsigned long lastTime;
double Input, Output, Setpoint;
double ITerm, lastInput;

// SetPoint = BIAS

int PID(int _referencia, int _PosicionActual, int Tmuestreo, int _kp, int _ki, int _kd, int* _PosicionAnterior, int _Maximo, int _Minimo)
{
    int error = _referencia - _PosicionActual;
    ITerm += (_ki * error);

    if (ITerm > 2000) ITerm = 2000;
    if (ITerm < -2000) ITerm = -2000;


    int dInput = (_PosicionActual - (*_PosicionAnterior));
    Output = _kp * error - _kd * dInput + ITerm;
    if (Output >= _Maximo) Output = _Maximo;
    if (Output <= _Minimo) Output = _Minimo;

    (*_PosicionAnterior) = _PosicionActual;

    PWM1 = BIAS1 + Output;
    PWM4 = BIAS2 - Output;

    //    enviar_valor_NOCR("valorAux = ",_referencia);
    //    enviar_valor_NOCR(" valorAuxAnterior = ",_PosicionActual);
    //    enviar_valor_NOCR("pid = ",(*_PosicionAnterior));
    //    enviar_valor_NOCR(" Ep = ",error);
    //    enviar_valor_NOCR(" Ed = ",dInput);
    //    enviar_valor(" Ei = ",ITerm);



    return Output;
}

void getAngle_init()
{
    P[0][0] = 0; // Since we assume that the bias is 0 and we know the starting angle (use setAngle), the error covariance matrix is set like so - see: http://en.wikipedia.org/wiki/Kalman_filter#Example_application.2C_technical
    P[0][1] = 0;
    P[1][0] = 0;
    P[1][1] = 0;
}

double getAngle(double newAngle, double newRate, double dt)
{
    // KasBot V2 - Kalman filter module - http://www.x-firm.com/?page_id=145
    // Modified by Kristian Lauszus
    // See my blog post for more information: http://blog.tkjelectronics.dk/2012/09/a-practical-approach-to-kalman-filter-and-how-to-implement-it

    // Discrete Kalman filter time update equations - Time Update ("Predict")
    // Update xhat - Project the state ahead
    /* Step 1 */
    rate = newRate - bias;
    angle += dt * rate;
#ifdef DEBUG
    enviar_valor_NOCR("rate=", rate);
    enviar_valor_NOCR(" angle=", angle);
    enviar_valor("newangle=", newAngle);
#endif
    // Update estimation error covariance - Project the error covariance ahead
    /* Step 2 */
    P[0][0] += dt * (dt * P[1][1] - P[0][1] - P[1][0] + Q_angle);
    P[0][1] -= dt * P[1][1];
    P[1][0] -= dt * P[1][1];
    P[1][1] += Q_bias * dt;
#ifdef DEBUG
    enviar_valor_NOCR(" P[0][0]=", P[0][0]);
    enviar_valor_NOCR(" P[0][1]=", P[0][1]);
    enviar_valor_NOCR(" P[1][0]=", P[1][0]);
    enviar_valor(" P[1][1]", P[1][1]);
#endif
    // Discrete Kalman filter measurement update equations - Measurement Update ("Correct")
    // Calculate Kalman gain - Compute the Kalman gain
    /* Step 4 */
#ifdef DEBUG
    enviar_valor_NOCR("s=", S);
#endif
    S = P[0][0] + R_measure;
#ifdef DEBUG
    enviar_valor("s_", S);
#endif

    /* Step 5 */
    K[0] = P[0][0] / S;
    K[1] = P[1][0] / S;
#ifdef DEBUG
    enviar_valor_NOCR("k[0]=", K[0]);
    enviar_valor(" k[1]", K[1]);
#endif
    // Calculate angle and bias - Update estimate with measurement zk (newAngle)
    /* Step 3 */
    y = newAngle - angle;
    /* Step 6 */
    angle += K[0] * y;
    bias += K[1] * y;
#ifdef DEBUG
    enviar_valor_NOCR("Y=", y);
    enviar_valor_NOCR(" angle=", angle);
    enviar_valor(" bias=", bias);
#endif
    // Calculate estimation error covariance - Update the error covariance
    /* Step 7 */
    P[0][0] -= K[0] * P[0][0];
    P[0][1] -= K[0] * P[0][1];
    P[1][0] -= K[1] * P[0][0];
    P[1][1] -= K[1] * P[0][1];
#ifdef DEBUG
    enviar_valor_NOCR("P[0][0]=", P[0][0]);
    enviar_valor_NOCR(" P[0][1]=", P[0][1]);
    enviar_valor_NOCR(" P[1][0]=", P[1][0]);
    enviar_valor_NOCR(" P[1][1]=", P[1][1]);
    enviar_valor(" angle=", angle);
#endif
    return angle;
};
// newAngle = angle measured with atan2 using the accelerometer
// newRate = angle measured using the gyro
// looptime = loop time in millis()

float Complementary2(float newAngle, float newRate, int looptime)
{
    float k = 10;
    float dtc2 = 0, x1 = 0, y1 = 0, x2 = 0;
    dtc2 = (float) (looptime) / 1000.0;

    x1 = (newAngle - x_angle2C) * k*k;
    y1 = dtc2 * x1 + y1;
    x2 = y1 + (newAngle - x_angle2C)*2 * k + newRate;
    x_angle2C = dtc2 * x2 + x_angle2C;
#ifdef DEBUG
    enviar_valor_NOCR(" x1=", x1);
    enviar_valor_NOCR(" y1=", y1);
    enviar_valor_NOCR(" x2=", x2);
    enviar_valor(" x_angle2C=", x_angle2C);
#endif
    return x_angle2C;
}

void get_calibrado_acelerometro(int milis, int n, int *_calibra_ax, int *_calibra_ay, int *_calibra_az, int *_calibra_gx, int *_calibra_gy, int *_calibra_gz)
{
    DelayXmsT1(milis);
    int i;
    double calibra_ax_double = (*_calibra_ax);
    double calibra_ay_double = (*_calibra_ay);
    double calibra_az_double = (*_calibra_az);
    double calibra_gx_double = (*_calibra_gx);
    double calibra_gy_double = (*_calibra_gy);
    double calibra_gz_double = (*_calibra_gz);

    for (i = 0; i < n; i++)
    {
        calibra_ax_double = get_ax() + calibra_gx_double;
        calibra_ay_double = get_ay() + calibra_gy_double;
        calibra_az_double = get_az() + calibra_gz_double;
        calibra_gx_double = get_gx() + calibra_gx_double;
        calibra_gy_double = get_gy() + calibra_gy_double;
        calibra_gz_double = get_gz() + calibra_gz_double;
    }

    *_calibra_ax = calibra_ax_double / n;
    *_calibra_ay = calibra_ay_double / n;
    *_calibra_az = calibra_az_double / n;
    *_calibra_gx = calibra_gx_double / n;
    *_calibra_gy = calibra_gy_double / n;
    *_calibra_gz = calibra_gz_double / n;



}