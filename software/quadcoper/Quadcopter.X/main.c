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
    acelerometro();
    cargar_datos_ajuste();
    SetupT3ForXmsPID(5); //configuramos  la interrupcion principal
    StartInterrup3(); //incializamos la interrupcion
    enviar_mensaje("------------------------------------------------------");
    //***************************************************************************************//

    ACT_MOTORS = 1;
    while (1) {

    }

}

void Bucle_Principal() {

    LED_AZUL_INF = 1;
    int angulo_zx = 0;
    int angulo_zy = 0;
    int angulo_xy = 0;
    //------------------------------------------------------------------------------------------//
    //  funcionando un eje
    //  double accXangle_zx = (atan2((get_az() - calibra_az), (get_ax() - calibra_ax)) * RAD_TO_DEG);
    //  double gyroXrate_zx = (double) (get_gx() - calibra_gx) / 131.0;
    //   angulo_zx = (signed int) getAngleStruct_zx(accXangle_zx, gyroXrate_zx, 0.059);
    //     angulo_zx=(signed int)Complementary2(accXangle_zx, gyroXrate_zx,5)+90;

    //    angulo_zy=(***********signed int)Complementary2(accXangle_zy, gyroXrate_zy,1)+90;
    //   double accXangle_xy = (atan2((get_ax() - calibra_ax), (get_ay() - calibra_ay)) * RAD_TO_DEG);
    //   double gyroXrate_xy = (double) (get_gz() - calibra_gz) / 131.0;
    //   angulo_xy = (signed int) getAngleStruct_xy(accXangle_xy, gyroXrate_xy, 0.04);

    //           int salida_zx = mod_zx(0, angulo_zx,Tsample,KP_zx,KI_zx,KD_zx,5000,-5000,4,-4);
    //         GetPwm1(BIAS1_zx+salida_zx);
    //         GetPwm3(BIAS2_zx-salida_zx);
   #define BRAZO_CORTO
#ifdef BRAZO_CORTO
    double accXangle_zy = (atan2(get_ay(), -get_az()) * RAD_TO_DEG/2 );
    double gyroXrate_zy = (double) (get_gx() - calibra_gx) / 131.0;
    angulo_zy = (signed int) Complementary2_zy(accXangle_zy, gyroXrate_zy,5);

    double accXangle_zx = (atan2(get_ax() ,-get_az()) * RAD_TO_DEG);
    double gyroXrate_zx = (double) (get_gy() - calibra_gy) / 131.0;
    angulo_zx = ((signed int) Complementary2_zx(accXangle_zx, gyroXrate_zx, 5));

    int salida_zx = pid_zx(0, angulo_zx, 5, KP_zx, KI_zx, KD_zx, 5000, -5000, 200, -200);
    int salida_zy = pid_zy(0, angulo_zy, 5, KP_zy, KI_zy, KD_zy, 5000, -5000, 200, -200);

    GetPwm2(BIAS1_zy + salida_zy);
    GetPwm4(BIAS2_zy - salida_zy);
    GetPwm1(BIAS1_zx + salida_zx);
    GetPwm3(BIAS1_zx - salida_zx);
plot4(angulo_zy,angulo_zx,salida_zy,salida_zx);
#endif

    //    GetPwm2(BIAS1_xy + salida_xy);
    //    GetPwm4(BIAS1_xy + salida_xy);

    //    enviar_valor("s=",salida_zy);
    // plot3(angulo_zy,accXangle_zy+90,PWM4);


    //     if (angulo_zy>0){LED_ROJO_SUP=0;}
    //     else {LED_ROJO_SUP=1;}
    //     if (salida_zy>0){LED_AZUL_SUP=1;}
    //     else {LED_AZUL_SUP=0;}
    //          if (salida_zy<0){LED_VERDE_SUP=1;}
    //     else {LED_VERDE_SUP=0;}
}




int pid_zy(int _referencia, int _PosicionActual, int Tmuestreo, float _kp, float _ki, float _kd, int _Maximo, int _Minimo, int _MaximoI, int _MinimoI) {
    float salida, ITerm;
    int ErrorP = _referencia - _PosicionActual;
    float ErrorDT = ErrorP - error_anterior_zy;

    //-----calculate P component
    float PTerm = ErrorP * _kp;

    //-----calculate I component
    ErrorI_zy = ErrorI_zy + ErrorP * Tmuestreo * _ki;

    //-----calculate D component
    float DTerm = ErrorDT * _kd * 1000 / Tmuestreo;

    //-----calculate anti-windup
    if (ErrorI_zy >= _MaximoI) ErrorI_zy = _MaximoI;
    else if (ErrorI_zy <= _MinimoI) ErrorI_zy = _MinimoI;
    ITerm = ErrorI_zy;


    //-----calculate PID
    salida = PTerm + DTerm + ITerm;

    if (salida >= _Maximo) salida = _Maximo;
    if (salida <= _Minimo) salida = _Minimo;

    error_anterior_zy = ErrorP;


    return (int)salida;
}
int pid_zx(int _referencia, int _PosicionActual, int Tmuestreo, float _kp, float _ki, float _kd, int _Maximo, int _Minimo, int _MaximoI, int _MinimoI) {
    float salida, ITerm;
    int ErrorP = _referencia - _PosicionActual;
    float ErrorDT = ErrorP - error_anterior_zx;

    //-----calculate P component
    float PTerm = ErrorP * _kp;

    //-----calculate I component
    ErrorI_zx = ErrorI_zx + ErrorP * Tmuestreo * _ki;

    //-----calculate D component
    float DTerm = ErrorDT * _kd * 1000 / Tmuestreo;

    //-----calculate anti-windup
    if (ErrorI_zx >= _MaximoI) ErrorI_zx = _MaximoI;
    else if (ErrorI_zx <= _MinimoI) ErrorI_zx = _MinimoI;
    ITerm = ErrorI_zx;


    //-----calculate PID
    salida = PTerm + DTerm + ITerm;

    if (salida >= _Maximo) salida = _Maximo;
    if (salida <= _Minimo) salida = _Minimo;

    error_anterior_zx = ErrorP;


    return (int)salida;
}
int pid_xy(int _referencia, int _PosicionActual, int Tmuestreo, float _kp, float _ki, float _kd, int _Maximo, int _Minimo, int _MaximoI, int _MinimoI) {
    float salida, ITerm;
    int ErrorP = _referencia - _PosicionActual;
    float ErrorDT = ErrorP - error_anterior_xy;

    //-----calculate P component
    float PTerm = ErrorP * _kp;

    //-----calculate I component
    ErrorI_xy = ErrorI_xy + ErrorP * Tmuestreo * _ki;

    //-----calculate D component

    float DTerm = ErrorDT * _kd * 1000 / Tmuestreo;

    //-----calculate anti-windup

    if (ErrorI_xy >= _MaximoI) ErrorI_xy = _MaximoI;
    else if (ErrorI_xy <= _MinimoI) ErrorI_xy = _MinimoI;
    ITerm = ErrorI_zy;


    //-----calculate PID

    salida = PTerm + DTerm + ITerm;

    if (salida >= _Maximo) salida = _Maximo;
    if (salida <= _Minimo) salida = _Minimo;

    error_anterior_xy = ErrorP;


    return (int)salida;
}


void getAngle_init() {

    zy.P[0][0] = 0; // Since we assume that the bias is 0 and we know the starting angle (use setAngle), the error covariance matrix is set like so - see: http://en.wikipedia.org/wiki/Kalman_filter#Example_application.2C_technical
    zy.P[0][1] = 0;
    zy.P[1][0] = 0;
    zy.P[1][1] = 0;
    zy.Q_angle = 0.03; //0.01 // Process noise variance for the accelerometer
    zy.Q_bias = 0.001; //0.03  Process noise variance for the gyro bias
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
    zx.Q_angle = 0.02; //0.03; //0.01 // Process noise variance for the accelerometer
    zx.Q_bias = 0.03; //0.03; //0.03  Process noise variance for the gyro bias
    zx.R_measure = 0.002; //0.002; //0.03 Measurement noise variance - this is actually the variance of the measurement noise
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
    xy.Q_angle = 0.1; //0.01 // Process noise variance for the accelerometer
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

void GetPwm1(int velocidad) {
    if (velocidad < 0)
        PWM1 = 0;
    else
        PWM1 = velocidad;
}

void GetPwm2(int velocidad) {
    if (velocidad < 0)
        PWM2 = 0;
    else
        PWM2 = velocidad;
}

void GetPwm3(int velocidad) {
    if (velocidad < 0)
        PWM3 = 0;
    else
        PWM3 = velocidad;
}

void GetPwm4(int velocidad) {
    if (velocidad < 0)
        PWM4 = 0;
    else
        PWM4 = velocidad;
}

float Complementary2_zx(float newAngle, float newRate, int looptime) {
    float dtc2 = 0, x1 = 0, y1 = 0, x2 = 0;
    dtc2 = (float) (looptime) / 1000.0;
    x1 = (newAngle - angle2C_zx) * k_zx*k_zx;
    y1 = dtc2 * x1 + y1;
    x2 = y1 + (newAngle - angle2C_zx)*2 * k_zx + newRate;
    angle2C_zx = dtc2 * x2 + angle2C_zx;
    return angle2C_zx;
}

float Complementary2_zy(float newAngle, float newRate, int looptime) {
    float dtc2 = 0, x1 = 0, y1 = 0, x2 = 0;
    dtc2 = (float) (looptime) / 1000.0;
    x1 = (newAngle - angle2C_zy) * k_zy*k_zy;
    y1 = dtc2 * x1 + y1;
    x2 = y1 + (newAngle - angle2C_zy)*2 * k_zy+ newRate;
    angle2C_zy = dtc2 * x2 + angle2C_zy;
    return angle2C_zy;
}

float Complementary2_xy(float newAngle, float newRate, int looptime) {
    float dtc2 = 0, x1 = 0, y1 = 0, x2 = 0;
    dtc2 = (float) (looptime) / 1000.0;
    x1 = (newAngle - angle2C_xy) * k_xy*k_xy;
    y1 = dtc2 * x1 + y1;
    x2 = y1 + (newAngle - angle2C_xy)*2 * k_xy + newRate;
    angle2C_xy = dtc2 * x2 + angle2C_xy;
    return angle2C_xy;
}


void cargar_datos_ajuste() {
    if (Eeprom_ReadWord(0) == 6969) {

        enviar_mensaje("datos encontrados en la eeprom");

        KP_zx = Eeprom_ReadWord(2)/10;
        KI_zx = Eeprom_ReadWord(4)/10;
        KD_zx = Eeprom_ReadWord(6)/10;
        BIAS1_zx = Eeprom_ReadWord(8);
        BIAS2_zx = Eeprom_ReadWord(10);
        k_zx = (float)Eeprom_ReadWord(12);

        KP_zy = Eeprom_ReadWord(14)/10;
        KI_zy = Eeprom_ReadWord(16)/10;
        KD_zy = Eeprom_ReadWord(18)/10;
        BIAS1_zy = Eeprom_ReadWord(20);
        BIAS2_zy = Eeprom_ReadWord(22);
        k_zy = (float)Eeprom_ReadWord(24);

        KP_xy = Eeprom_ReadWord(26)/10;
        KI_xy = Eeprom_ReadWord(28)/10;
        KD_xy = Eeprom_ReadWord(30)/10;
        BIAS1_xy = Eeprom_ReadWord(32);
        BIAS2_xy = Eeprom_ReadWord(34);
        k_xy = (float)Eeprom_ReadWord(36);

        filtro =(float)Eeprom_ReadWord(38);
        Tsample =  Eeprom_ReadWord(40);

        }
    else {
        enviar_mensaje("datos no  encontrados en la eeprom, cargando datos seguros");
        KP_zx = 7;
        KD_zx = 9;
        KI_zx = 0;
        BIAS1_zx = 1000;
        BIAS2_zx = 1000;
        k_zx=5;
        KP_zy = 7;
        KD_zy = 9;
        KI_zy = 0;
        BIAS1_zy = 1000;
        BIAS2_zy = 1000;
        k_zy=5;
        KP_xy = 7;
        KD_xy = 9;
        KI_xy = 0;
        BIAS1_xy = 1000;
        BIAS2_xy = 1000;
        k_xy=5;
        Tsample = 5;
        filtro =6;
    }
    //------------------CARGADO LOS DATOS DESDE  LA EEPROM--------------------------//

    enviar_valor_NOCR("KP_zx=", KP_zx*10);
    enviar_valor_NOCR(" , KD_zx=", KD_zx*10);
    enviar_valor_NOCR(" , KI_zx=", KI_zx*10);
    enviar_valor_NOCR("BIAS1_zx=", BIAS1_zx);
    enviar_valor_NOCR(" , BIAS2_zx=", BIAS2_zx);
    enviar_valor(" , k_zx=", (float)k_zx);
  
    enviar_valor_NOCR("KP_zy=", KP_zy*10);
    enviar_valor_NOCR(" , KD_zy=", KD_zy*10);
    enviar_valor_NOCR(" , KI_zy=", KI_zy*10);
    enviar_valor_NOCR("BIAS1_zy=", BIAS1_zy);
    enviar_valor_NOCR(" , BIAS2_zy=", BIAS2_zy);
    enviar_valor(" , k_zy=", (float)k_zy);

     enviar_valor_NOCR("KP_xy=", KP_xy*10);
    enviar_valor_NOCR(" , KD_xy=", KD_xy*10);
    enviar_valor_NOCR(" , KI_xy=", KI_xy*10);
    enviar_valor_NOCR("BIAS1_xy=", BIAS1_xy);
    enviar_valor_NOCR(" , BIAS2_x=", BIAS2_xy);
    enviar_valor(" , k_xy=", (float)k_xy);

    enviar_valor_NOCR("Tsample=", Tsample);
    enviar_valor(" , filtro=", filtro );

    //        delayT4_msg(1000);
    //        enviar_mensaje("Tres segundos para arrancar");
    //        delayT4_msg(1000);
    //        enviar_mensaje("dos segundos para arrancar");
    //        delayT4_msg(1000);
    //        enviar_mensaje("un segundos para arrancar");
    //        delayT4_msg(1000);
    //        enviar_mensaje("arrancamos");





}