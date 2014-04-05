/*
 * File:   main.c
 * Author: Pablo
 *
 * Created on 29 de junio de 2013, 19:05
 */
#include "main.h"

#define MY_FRC                  0xF9E3
// FUSES
// -----------------------------------------------------------

_FOSC(MY_FRC & CSW_FSCM_ON) //   0xF9E3 & 0x3FFF --> Arranca sin PLL (8MHz) y se habilita el clockSwitch
_FGS(GWRP_OFF & CODE_PROT_OFF)
_FICD(ICS_PGD1)
_FWDT(WDT_OFF)
_FBORPOR(PWRT_OFF & BORV27 & PBOR_OFF & MCLR_DIS)
// FIN FUSES

int main(void) {

    //***************************************************************************************//
    //*****************ARRANCAMOS LA CONFIGURACION DEL PIC **********************************//
    //***************************************************************************************//
    Init_Hw();
    Delay1msT1(0); //Configuramos el puertos y quitamos analogicos
    Init_Pll();
    Delay1msT1(0); //configuramos el pll que abiasmos arracamos sin �l
    Init_PWM();
    Delay1msT1(0); //configuramos el PWM
    Init_Bluetooh();
    Delay1msT1(0); //Configuramos el serial-Bluetooth
    Init_I2C();
    Delay1msT1(0); //incializamos el I2c
    set_inicial();
    Delay1msT1(0); //Configuramos la incialicacion de sensor
    getAngle_init();
    Delay1msT1(0); //Incializamos el filtro kalman
    set_inicial();
    Delay1msT1(0); //Incializamos el acelerometro
    //***************************************************************************************//
    //***************************************************************************************//

    //*****************CALIBRAMOS EL ACELEROMETRO Y GIROSCOPO *******************************//
    get_calibrado_acelerometro(5, 50); //cojemos los valres por defecto del  giroscopo y aceletometro
    LED_ALL_OFF();
    //***************************************************************************************//

    //*****************INICIALIZAMOS EL PID  Y LAS VARIABLES ********************************//

    // pid_dsp_configuracion();

    //***************************************************************************************//


    //*****************ARRANCAMOS INTERRUPCION  DEL BUCLE PRINCIPAL *************************//
    SetupT3ForXmsPID(10); //configuramos  la interrupcion principal
    StartInterrup3(); //incializamos la interrupcion
    enviar_mensaje("------------------------------------------------------");
    //***************************************************************************************//
    acelerometro();
    ACT_MOTORS=1;
    while (1) {
    }

}

void Bucle_Principal() {
    LED_AZUL_INF=1;
    int angulo_zx = 0;
    int angulo_zy = 0;
    int angulo_xy = 0;
    //------------------------------------------------------------------------------------------//
    double accXangle_zx = (atan2((get_az() - calibra_az), (get_ax() - calibra_ax)) * RAD_TO_DEG);
    double gyroXrate_zx = (double) (get_gx() - calibra_gx) / 131.0;
    angulo_zx = (signed int) getAngleStruct_zx(accXangle_zx, gyroXrate_zx, 0.01)+90;

    double accXangle_zy = (atan2((get_az() - calibra_az), (get_ay() - calibra_ay)) * RAD_TO_DEG);
    double gyroXrate_zy = (double) (get_gy() - calibra_gy) / 131.0;
    angulo_zy = (signed int) getAngleStruct_zy(accXangle_zy, gyroXrate_zy, 0.01)+90;

     double accXangle_xy = (atan2((get_ax() - calibra_ax), (get_ay() - calibra_ay)) * RAD_TO_DEG);
    double gyroXrate_xy = (double) (get_gz() - calibra_gz) / 131.0;
    angulo_xy = (signed int) getAngleStruct_xy(accXangle_xy, gyroXrate_xy, 0.01)+90;

 
    //angulo = (signed int) Complementary2(accXangle, gyroXrate, 10);
    int salida = _PID(0, angulo_zx, 1,20, 3, 10, 31000, -31000);
    //pon_motores(0,0,4000,0,100);
    pon_motores(-salida,0 , +salida, 0,100);
    plot2(angulo_zx,salida);
   // enviar_valor("angu=", angulo_zx);
    //enviar_valor("angulo1=", angulo_zy);

  LED_AZUL_INF=0;
}


/*working variables*/

// SetPoint = BIAS

int _PID(int _referencia, int _PosicionActual, int Tmuestreo, int _kp, int _ki, int _kd, int _Maximo, int _Minimo) {
    int Output;

    //    ITerm += (_ki * error);
    //
    //    if (ITerm > 2000) ITerm = 2000;
    //    if (ITerm < -2000) ITerm = -2000;

    int Error = _referencia - _PosicionActual;
    int dError = (_PosicionActual - (valorAuxAnterior));
    Output = _kp * Error - _kd * dError; //+ ITerm;
    // if (Output >= _Maximo) Output = _Maximo;
    // if (Output <= _Minimo) Output = _Minimo;
    
    (valorAuxAnterior) = _PosicionActual;
    

        enviar_valor_NOCR("valorAux = ",_referencia);
        enviar_valor_NOCR(" valorAuxAnterior = ",_PosicionActual);
       enviar_valor_NOCR("pid = ",Output);
        enviar_valor_NOCR(" Ep = ",Error);
        enviar_valor(" Ed = ",dError);
    //    enviar_valor(" Ei = ",ITerm);

return Output;


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

double getAngleStruct_xy(double newAngle, double newRate, double dt) {
    xy.rate = newRate - xy.bias; //lectura mas sesgo
    xy.angle += dt * xy.rate; //angulo  con el modelo (newton)
    xy.P[0][0] += dt * (dt * xy.P[1][1] - xy.P[0][1] - xy.P[1][0] + xy.Q_angle);
    xy.P[0][1] -= dt * xy.P[1][1];
    xy.P[1][0] -= dt * xy.P[1][1];
    xy.P[1][1] += xy.Q_bias * dt;
    xy.S = xy.P[0][0] + xy.R_measure; //suma la varianza del ruido(aclculo intertermedio  para obtener L)
    xy.K[0] = xy.P[0][0] / xy.S;
    xy.K[1] = xy.P[1][0] / xy.S;
    xy.y = newAngle - xy.angle;
    xy.angle += xy.K[0] * xy.y; //y angulo medido //angle=estimado
    xy.bias += xy.K[1] * xy.y; //
    xy.P[0][0] -= xy.K[0] * xy.P[0][0];
    xy.P[0][1] -= xy.K[0] * xy.P[0][1];
    xy.P[1][0] -= xy.K[1] * xy.P[0][0];
    xy.P[1][1] -= xy.K[1] * xy.P[0][1];
    return xy.angle;
}

double getAngleStruct_zy(double newAngle, double newRate, double dt) {
    zy.rate = newRate - zy.bias; //lectura mas sesgo
    zy.angle += dt * zy.rate; //angulo  con el modelo (newton)
    zy.P[0][0] += dt * (dt * zy.P[1][1] - zy.P[0][1] - zy.P[1][0] + zy.Q_angle);
    zy.P[0][1] -= dt * zy.P[1][1];
    zy.P[1][0] -= dt * zy.P[1][1];
    zy.P[1][1] += zy.Q_bias * dt;
    zy.S = zy.P[0][0] + zy.R_measure; //suma la varianza del ruido(aclculo intertermedio  para obtener L)
    zy.K[0] = zy.P[0][0] / zy.S;
    zy.K[1] = zy.P[1][0] / zy.S;
    zy.y = newAngle - zy.angle;
    zy.angle += zy.K[0] * zy.y; //y angulo medido //angle=estimado
    zy.bias += zy.K[1] * zy.y; //
    zy.P[0][0] -= zy.K[0] * zy.P[0][0];
    zy.P[0][1] -= zy.K[0] * zy.P[0][1];
    zy.P[1][0] -= zy.K[1] * zy.P[0][0];
    zy.P[1][1] -= zy.K[1] * zy.P[0][1];
    return zy.angle;
}

double getAngleStruct_zx(double newAngle, double newRate, double dt) {
    zx.rate = newRate - zx.bias; //lectura mas sesgo
    zx.angle += dt * zx.rate; //angulo  con el modelo (newton)
    zx.P[0][0] += dt * (dt * zx.P[1][1] - zx.P[0][1] - zx.P[1][0] + zx.Q_angle);
    zx.P[0][1] -= dt * zx.P[1][1];
    zx.P[1][0] -= dt * zx.P[1][1];
    zx.P[1][1] += zx.Q_bias * dt;
    zx.S = zx.P[0][0] + zx.R_measure; //suma la varianza del ruido(aclculo intertermedio  para obtener L)
    zx.K[0] = zx.P[0][0] / zx.S;
    zx.K[1] = zx.P[1][0] / zx.S;
    zx.y = newAngle - zx.angle;
    zx.angle += zx.K[0] * zx.y; //y angulo medido //angle=estimado
    zx.bias += zx.K[1] * zx.y; //
    zx.P[0][0] -= zx.K[0] * zx.P[0][0];
    zx.P[0][1] -= zx.K[0] * zx.P[0][1];
    zx.P[1][0] -= zx.K[1] * zx.P[0][0];
    zx.P[1][1] -= zx.K[1] * zx.P[0][1];
    return zx.angle;
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
    fooPID.measuredOutput = Q15(_Q15ftoi((float) entrada));
    fooPID.measuredOutput = Q15(entrada);
    PID(&fooPID);
    enviar_valor_NOCR("foo=", fooPID.controlOutput);
    enviar_valor("conver=", fooPID.controlOutput);
    return (_itofQ15(fooPID.controlOutput));
}

void pon_motores(int M1, int M2, int M3, int M4,int incremento) {
    if (PWM1 > M1)PWM1=PWM1-incremento;
    else if (PWM1 < M1)PWM1=PWM1+incremento;

    if (PWM2 > M2)PWM2=PWM2-incremento;
    else if (PWM2 < M2)PWM2=PWM2+incremento;

    if (PWM3 > M3)PWM3=PWM3-incremento;
    else if (PWM3 < M3)PWM3=PWM3+incremento;

    if (PWM4 > M4)PWM4=PWM4-incremento;
    else if (PWM4 < M4)PWM4=PWM4+incremento;


}