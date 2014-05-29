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
    Delay1msT1(0); //configuramos el pll que abiasmos arracamos sin él
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
    LED_ALL_ON();
    for (i = 0; i < 2500; i++) Delay_Nop(2000);
    LED_ALL_OFF();  
    //***************************************************************************************//
    //***************************************************************************************//

    //*****************CALIBRAMOS EL ACELEROMETRO Y GIROSCOPO *******************************//
    get_calibrado_acelerometro(5, 50); //cojemos los valres por defecto del  giroscopo y aceletometro
    LED_ALL_OFF();
    //***************************************************************************************//

    //*****************INICIALIZAMOS EL PID  Y LAS VARIABLES ********************************//

//     pid_dsp_configuracion();

    //***************************************************************************************//


    //*****************ARRANCAMOS INTERRUPCION  DEL BUCLE PRINCIPAL *************************//
    SetupT3ForXmsPID(6); //configuramos  la interrupcion principal
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
 //  funcionando un eje
/*   double accXangle_zx = (atan2((get_az() - calibra_az), (get_ax() - calibra_ax)) * RAD_TO_DEG);
   double gyroXrate_zx = (double) (get_gx() - calibra_gx) / 131.0;
   angulo_zx = (signed int) getAngleStruct_zx(accXangle_zx, gyroXrate_zx, 0.05)+90;

   double accXangle_zy = (atan2((get_az() - calibra_az), (get_ay() - calibra_ay)) * RAD_TO_DEG);
   double gyroXrate_zy = (double) (get_gy() - calibra_gy) / 131.0;
   angulo_zy = (signed int) getAngleStruct_zy(accXangle_zy, gyroXrate_zy, 0.04)+90;
*/
    double accXangle_xy = (atan2((get_ax() - calibra_ax), (get_ay() - calibra_ay)) * RAD_TO_DEG);
   double gyroXrate_xy = (double) (get_gz() - calibra_gz) / 131.0;
   angulo_xy = (signed int) getAngleStruct_xy(accXangle_xy, gyroXrate_xy, 0.04);
/*
   int salida_zx = mod_zx(0, angulo_zx,1,KP,KD,KD,5000,-5000,4,-4);
     GetPwm1(BIAS1+salida_zx);
     GetPwm3(BIAS1-salida_zx);
   int salida_zy = mod_zy(0, angulo_zy,1,11,KD,KD,5000,-5000,4,-4);
     GetPwm2(BIAS1+salida_zy);
     GetPwm4(BIAS1-salida_zy);
 */  int salida_xy = mod_zy(0, angulo_xy,1,KP_xy,KI_xy,KD_xy,5000,-5000,4,-4);
    GetPwm2(BIAS1_xy + salida_xy);
    GetPwm4(BIAS1_xy + salida_xy);
    GetPwm1(BIAS1_xy - salida_xy);
    GetPwm3(BIAS1_xy - salida_xy);
    enviar_valor("",angulo_xy);

  LED_AZUL_INF=0;
}


/*working variables*/

// SetPoint = BIAS

int mod_zy(int _referencia, int _PosicionActual, int Tmuestreo, int _kp, int _ki, int _kd, int _Maximo, int _Minimo, int _MaximoI, int _MinimoI) {
    int salida, ITerm;

    int ErrorP = _referencia - _PosicionActual;
    int ErrorDT = ErrorP - error_anterior_zy;
    ErrorI_zy += ErrorP * Tmuestreo * _ki;

    //-----calculate P component
    int PTerm = ErrorP * _kp;
    //-----calculate I component
    if (ErrorI_zy >= _Maximo) ErrorI_zy = _Maximo;
    else if (ErrorI_zy <= _Minimo) ErrorI_zy = _Minimo;
    ITerm = ErrorI_zy;
    //-----calculate D component
    int DTerm = ErrorDT * _kd / Tmuestreo;
    //-----calculate PID
    salida = PTerm + DTerm;

    if (salida >= _Maximo) salida = _Maximo;
    if (salida <= _Minimo) salida = _Minimo;

    error_anterior_zy = ErrorP;

    return salida;
}


int mod_zx(int _referencia, int _PosicionActual, int Tmuestreo, int _kp, int _ki, int _kd, int _Maximo, int _Minimo, int _MaximoI, int _MinimoI) {
    int salida, ITerm;

    int ErrorP = _referencia - _PosicionActual;
    int ErrorDT = ErrorP - error_anterior_zx;
    ErrorI_zx += ErrorP * Tmuestreo * _ki;

    //-----calculate P component
    int PTerm = ErrorP * _kp;
    //-----calculate I component
    if (ErrorI_zx >= _Maximo) ErrorI_zx = _Maximo;
    else if (ErrorI_zx <= _Minimo) ErrorI_zx = _Minimo;
    ITerm = ErrorI_zx;
    //-----calculate D component
    int DTerm = ErrorDT * _kd / Tmuestreo;
    //-----calculate PID
    salida = PTerm + DTerm;

    if (salida >= _Maximo) salida = _Maximo;
    if (salida <= _Minimo) salida = _Minimo;

    error_anterior_zx = ErrorP;

    return salida;
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
    zx.Q_angle = 0.02;//0.03; //0.01 // Process noise variance for the accelerometer
    zx.Q_bias = 0.03;//0.03; //0.03  Process noise variance for the gyro bias
    zx.R_measure = 0.002;//0.002; //0.03 Measurement noise variance - this is actually the variance of the measurement noise
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
void GetPwm1(int velocidad){
       if(velocidad <0)
        PWM1=0;
    else
        PWM1=velocidad;
}
void GetPwm2(int velocidad){
       if(velocidad <0)
        PWM2=0;
    else
        PWM2=velocidad;
}
void GetPwm3(int velocidad){
       if(velocidad <0)
        PWM3=0;
    else
        PWM3=velocidad;
}
void GetPwm4(int velocidad){
       if(velocidad <0)
        PWM4=0;
    else
        PWM4=velocidad;
}