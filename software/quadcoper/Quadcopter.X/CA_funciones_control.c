/* 
 * File:   CA_funciones_control.c
 * Author: pablo
 *
 * Created on 23 de enero de 2014, 23:41
 */
#include "CA_funciones_control.h"
int errorAnt = 0;

int _Pid_Posicion(int _setpoint, int _posicion_actual)
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

int _PID(int _referencia, int _PosicionActual, int Tmuestreo, int _kp, int _ki, int _kd, int _Maximo, int _Minimo)
{

//    ITerm += (_ki * error);
//
//    if (ITerm > 2000) ITerm = 2000;
//    if (ITerm < -2000) ITerm = -2000;

    int Error = _referencia - _PosicionActual;
    int dError = (_PosicionActual - ( valorAuxAnterior));
    Output = _kp * Error - _kd * dError ;//+ ITerm;
   // if (Output >= _Maximo) Output = _Maximo;
   // if (Output <= _Minimo) Output = _Minimo;
return Output;
    ( valorAuxAnterior) = _PosicionActual;

    PWM1 = /*BIAS1 +*/ Output;
    PWM4 = /*BIAS2 +*/  Output;

    //    enviar_valor_NOCR("valorAux = ",_referencia);
    //    enviar_valor_NOCR(" valorAuxAnterior = ",_PosicionActual);
    //   enviar_valor_NOCR("pid = ",Output);
    //    enviar_valor_NOCR(" Ep = ",error);
    //    enviar_valor_NOCR(" Ed = ",dInput);
    //    enviar_valor(" Ei = ",ITerm);



    
}
void getAngle_init() {

    zy.P[0][0] = 0; // Since we assume that the bias is 0 and we know the starting angle (use setAngle), the error covariance matrix is set like so - see: http://en.wikipedia.org/wiki/Kalman_filter#Example_application.2C_technical
    zy.P[0][1] = 0;
    zy.P[1][0] = 0;
    zy.P[1][1] = 0;
    zy.Q_angle = 0.03; //0.01 // Process noise variance for the accelerometer
    zy.Q_bias = 0.03; //0.03  Process noise variance for the gyro bias
    zy.R_measure = 0.002; //0.03 Measurement noise variance - this is actually the variance of the measurement noise
    zy.angle = 1; // Reset the angle // The angle calculated by the Kalman filter - part of the 2x1 state vector
    zy.bias = 0; // The gyro bias calculated by the Kalman filter - part of the 2x1 state vector
    zy.rate = 0; // Unbiased rate calculated from the rate and the calculated bias - you have to call getAngle to update the rate
    zy.K[2] = 0; // Kalman gain - This is a 2x1 vector
    zy.y = 1; // Angle difference
    zy.S = 100; // Estimate error

    zx.P[0][0] = 0; // Since we assume that the bias is 0 and we know the starting angle (use setAngle), the error covariance matrix is set like so - see: http://en.wikipedia.org/wiki/Kalman_filter#Example_application.2C_technical
    zx.P[0][1] = 0;
    zx.P[1][0] = 0;
    zx.P[1][1] = 0;
    zx.Q_angle = 0.03; //0.01 // Process noise variance for the accelerometer
    zx.Q_bias = 0.03; //0.03  Process noise variance for the gyro bias
    zx.R_measure = 0.002; //0.03 Measurement noise variance - this is actually the variance of the measurement noise
    zx.angle = 1; // Reset the angle // The angle calculated by the Kalman filter - part of the 2x1 state vector
    zx.bias = 0; // The gyro bias calculated by the Kalman filter - part of the 2x1 state vector
    zx.rate = 0; // Unbiased rate calculated from the rate and the calculated bias - you have to call getAngle to update the rate
    zx.K[2] = 0; // Kalman gain - This is a 2x1 vector
    zx.y = 1; // Angle difference
    zx.S = 100; // Estimate error

    xy.P[0][0] = 0; // Since we assume that the bias is 0 and we know the starting angle (use setAngle), the error covariance matrix is set like so - see: http://en.wikipedia.org/wiki/Kalman_filter#Example_application.2C_technical
    xy.P[0][1] = 0;
    xy.P[1][0] = 0;
    xy.P[1][1] = 0;
    xy.Q_angle = 0.03; //0.01 // Process noise variance for the accelerometer
    xy.Q_bias = 0.03; //0.03  Process noise variance for the gyro bias
    xy.R_measure = 0.002; //0.03 Measurement noise variance - this is actually the variance of the measurement noise
    xy.angle = 1; // Reset the angle // The angle calculated by the Kalman filter - part of the 2x1 state vector
    xy.bias = 0; // The gyro bias calculated by the Kalman filter - part of the 2x1 state vector
    xy.rate = 0; // Unbiased rate calculated from the rate and the calculated bias - you have to call getAngle to update the rate
    xy.K[2] = 0; // Kalman gain - This is a 2x1 vector
    xy.y = 1; // Angle difference
    xy.S = 100; // Estimate error
}

double getAngleStruct_xy(double newAngle, double newRate, double dt)
{
    xy.rate = newRate - xy.bias;//lectura mas sesgo
    xy.angle += dt * xy.rate;//angulo  con el modelo (newton)
    xy.P[0][0] += dt * (dt * xy.P[1][1] - xy.P[0][1] - xy.P[1][0] + xy.Q_angle);
    xy.P[0][1] -= dt * xy.P[1][1];
    xy.P[1][0] -= dt * xy.P[1][1];
    xy.P[1][1] += xy.Q_bias * dt;
    xy.S = xy.P[0][0] + xy.R_measure;//suma la varianza del ruido(aclculo intertermedio  para obtener L)
    xy.K[0] = xy.P[0][0] / xy.S;
    xy.K[1] = xy.P[1][0] / xy.S;
    xy.y = newAngle - xy.angle;
    xy.angle += xy.K[0] * xy.y;//y angulo medido //angle=estimado
    xy.bias += xy.K[1] * xy.y;//
    xy.P[0][0] -= xy.K[0] * xy.P[0][0];
    xy.P[0][1] -= xy.K[0] * xy.P[0][1];
    xy.P[1][0] -= xy.K[1] * xy.P[0][0];
    xy.P[1][1] -= xy.K[1] * xy.P[0][1];
    return xy.angle;
}

double getAngleStruct_zy(double newAngle, double newRate, double dt)
{
    zy.rate = newRate - zy.bias;//lectura mas sesgo
    zy.angle += dt * zy.rate;//angulo  con el modelo (newton)
    zy.P[0][0] += dt * (dt * zy.P[1][1] - zy.P[0][1] - zy.P[1][0] + zy.Q_angle);
    zy.P[0][1] -= dt * zy.P[1][1];
    zy.P[1][0] -= dt * zy.P[1][1];
    zy.P[1][1] += zy.Q_bias * dt;
    zy.S = zy.P[0][0] + zy.R_measure;//suma la varianza del ruido(aclculo intertermedio  para obtener L)
    zy.K[0] = zy.P[0][0] / zy.S;
    zy.K[1] = zy.P[1][0] / zy.S;
    zy.y = newAngle - zy.angle;
    zy.angle += zy.K[0] * zy.y;//y angulo medido //angle=estimado
    zy.bias += zy.K[1] * zy.y;//
    zy.P[0][0] -= zy.K[0] * zy.P[0][0];
    zy.P[0][1] -= zy.K[0] * zy.P[0][1];
    zy.P[1][0] -= zy.K[1] * zy.P[0][0];
    zy.P[1][1] -= zy.K[1] * zy.P[0][1];
    return zy.angle;
}
double getAngleStruct_zx(double newAngle, double newRate, double dt)
{
    zx.rate = newRate - zx.bias;//lectura mas sesgo
    zx.angle += dt * zx.rate;//angulo  con el modelo (newton)
    zx.P[0][0] += dt * (dt * zx.P[1][1] - zx.P[0][1] - zx.P[1][0] + zx.Q_angle);
    zx.P[0][1] -= dt * zx.P[1][1];
    zx.P[1][0] -= dt * zx.P[1][1];
    zx.P[1][1] += zx.Q_bias * dt;
    zx.S = zx.P[0][0] + zx.R_measure;//suma la varianza del ruido(aclculo intertermedio  para obtener L)
    zx.K[0] = zx.P[0][0] / zx.S;
    zx.K[1] = zx.P[1][0] / zx.S;
    zx.y = newAngle - zx.angle;
    zx.angle += zx.K[0] * zx.y;//y angulo medido //angle=estimado
    zx.bias += zx.K[1] * zx.y;//
    zx.P[0][0] -= zx.K[0] * zx.P[0][0];
    zx.P[0][1] -= zx.K[0] * zx.P[0][1];
    zx.P[1][0] -= zx.K[1] * zx.P[0][0];
    zx.P[1][1] -= zx.K[1] * zx.P[0][1];
    return zx.angle;
}

//double getAngle(double newAngle, double newRate, double dt)
//{
//    // KasBot V2 - Kalman filter module - http://www.x-firm.com/?page_id=145
//    // Modified by Kristian Lauszus
//    // See my blog post for more information: http://blog.tkjelectronics.dk/2012/09/a-practical-approach-to-kalman-filter-and-how-to-implement-it
//
//    // Discrete Kalman filter time update equations - Time Update ("Predict")
//    // Update xhat - Project the state ahead
//    /* Step 1 */
//    xz.rate = newRate - xz.bias;//lectura mas sesgo
//    xz.angle += dt * xz.rate;//angulo  con el modelo (newton)
//    // Update estimation error covariance - Project the error covariance ahead
//    /* Step 2 */
//    //operacion a*p*a(traspuesta)+q
//    xz.P[0][0] += dt * (dt * xz.P[1][1] - xz.P[0][1] - xz.P[1][0] + xz.Q_angle);
//    xz.P[0][1] -= dt * xz.P[1][1];
//    xz.P[1][0] -= dt * xz.P[1][1];
//    xz.P[1][1] += xz.Q_bias * dt;
//
//    // Discrete Kalman filter measurement update equations - Measurement Update ("Correct")
//    // Calculate Kalman gain - Compute the Kalman gain
//    /* Step 4 */
//
//    xz.S = xz.P[0][0] + xz.R_measure;//suma la varianza del ruido(aclculo intertermedio  para obtener L)
//
//    /* Step 5 */
//    //Kla funcion optimizada
//    xz.K[0] = xz.P[0][0] / xz.S;
//    xz.K[1] = xz.P[1][0] / xz.S;
//    // Calculate angle and bias - Update estimate with measurement zk (newAngle)
//    /* Step 3 */
//    xz.y = newAngle - xz.angle;
//    /* Step 6 */
//    xz.angle += xz.K[0] * xz.y;//y angulo medido //angle=estimado
//    xz.bias += xz.K[1] * xz.y;//
//
//    // Calculate estimation error covariance - Update the error covariance
//    /* Step 7 */
//    xz.P[0][0] -= xz.K[0] * xz.P[0][0];
//    xz.P[0][1] -= xz.K[0] * xz.P[0][1];
//    xz.P[1][0] -= xz.K[1] * xz.P[0][0];
//    xz.P[1][1] -= xz.K[1] * xz.P[0][1];
//
//    return xz.angle;
//}



float Complementary2(float newAngle, float newRate, int looptime)
{

//    float k = 10;
//    float dtc2 = 0, x1 = 0, y1 = 0, x2 = 0;
//    dtc2 = (float) (looptime) / 1000.0;
//    x1 = (newAngle - x_angle2C) * k*k;
//    y1 = dtc2 * x1 + y1;
//    x2 = y1 + (newAngle - x_angle2C)*2 * k + newRate;
//    x_angle2C = dtc2 * x2 + x_angle2C;
//    return x_angle2C;
    return 0; //  A birrar cuando se haga la funcion
}

void get_calibrado_acelerometro(int milis, int n)
{
    DelayXmsT1(milis);
    int i;

    for (i = 0; i < n; i++)
    {
        calibra_ax = get_ax() + calibra_gx;
        calibra_ay = get_ay() + calibra_gy;
        calibra_az = get_az() + calibra_gz;
        calibra_gx = get_gx() + calibra_gx;
        calibra_gy = get_gy() + calibra_gy;
        calibra_gz = get_gz() + calibra_gz;
    }
    calibra_ax = calibra_ax / n;
    calibra_ay = calibra_ay / n;
    calibra_az = calibra_az / n;
    calibra_gx = calibra_gx / n;
    calibra_gy = calibra_gy / n;
    calibra_gz = calibra_gz / n;
}

void pid_dsp_configuracion() {
    fooPID.abcCoefficients = &abcCoefficient[0]; /*Set up pointer to derived coefficients */
    fooPID.controlHistory = &controlHistory[0]; /*Set up pointer to controller history samples */
    PIDInit(&fooPID); /*Clear the controler history and the controller output */
    kCoeffs[0] = Q15(1); // Kp   0.7
    kCoeffs[1] = Q15(0); // Ki 0.2
    kCoeffs[2] = Q15(1); // Kd   0.07
    PIDCoeffCalc(&kCoeffs[0], &fooPID); /*Derive the a,b, & c coefficients from the Kp, Ki & Kd */
}

int pid_dsp(int entrada) {
    fooPID.controlReference = Q15(0); /*Set the Reference Input for your controller */
    fooPID.measuredOutput = Q15(_Q15ftoi((float)entrada));
    fooPID.measuredOutput = Q15(entrada);
    PID(&fooPID);
    enviar_valor_NOCR("foo=",fooPID.controlOutput);
    enviar_valor("conver=",fooPID.controlOutput);
    return (_itofQ15(fooPID.controlOutput));
}