#include <p30F4013.h>


#include "Pruebas.h"
#include "Defines.h"
#include "CB_Timer2.h"
#include "CB_Bluetooth.h"
#include "CA_kalman.h"


void Prueba2_PWM(void)
{
       PWM1 = 65000;
       PWM2 = 65000;
       PWM3 = 65000;
       PWM4 = 65000;
}


void Prueba_PWM(void)
{
    int Stop = 0;
    while(Stop == 0)
    {
       PWM4+=100;
       PWM3+=100;
       Delay_Nop(5000);

       if(PWM4 >= 0x0FFC)
       {
           PWM4 = 0x0FFF;
           PWM3 = 0x0FFF;
           LED3 = 1;
           Stop = 1;
       }
    }
    while(Stop == 1)
    {

       PWM4-=100;
       PWM3-=100;
       Delay_Nop(5000);

       if(PWM4 <= 0x0070)
       {
           PWM4 = 0;
           PWM3 = 0;
           LED3 = 0;
           Stop = 0;
       }
    }
}

void Prueba_Bluetooth(void)
{
//    U2BRG++;

    itoa(str_blue,U2BRG, 10);
    enviar_datos(str_blue, strlen(str_blue));
    itoa(str_blue,U2BRG, 10);
    enviar_datos(str_blue, strlen(str_blue));
    itoa(str_blue,U2BRG, 10);
    enviar_datos(str_blue, strlen(str_blue));
    itoa(str_blue,U2BRG, 10);
    enviar_datos(str_blue, strlen(str_blue));
    strcpy(str_blue,"HOLA QUE TAL ESTAS yo estoy muy bien y tu que tal");
    enviar_datos(str_blue, strlen(str_blue));
    Delay_Nop(5000);
    enviar_datos(str_blue, strlen(str_blue));
    Delay_Nop(5000);
    enviar_datos(str_blue, strlen(str_blue));
    Delay_Nop(5000);
    enviar_datos(str_blue, strlen(str_blue));
    Delay_Nop(5000);
    enviar_datos(str_blue, strlen(str_blue));
    Delay_Nop(5000);
    enviar_datos(str_blue, strlen(str_blue));
    Delay_Nop(5000);
    enviar_datos(str_blue, strlen(str_blue));
    Delay_Nop(5000);
    enviar_datos(str_blue, strlen(str_blue));
    Delay_Nop(5000);
    LED3 = !LED3;
}



void Prueba_I2C(void)
{
    char data;
    int delay = 1000;
    char mycadena[50];

    data = ByteRead(MPU6050_RA_WHO_AM_I);

    strcpy(mycadena,"WHO_AM_I: ");
    enviar_datos_NOCR(mycadena,strlen(mycadena));
    itoa(str_blue,data, 10);
    enviar_datos_NOCR(str_blue,strlen(str_blue));
    Delay_Nop(delay);


    strcpy(mycadena,"      ");
    enviar_datos_NOCR(mycadena,strlen(mycadena));

    data = ByteRead(MPU6050_RA_ACCEL_XOUT_H);
    AccX = data;
    data = ByteRead(MPU6050_RA_ACCEL_XOUT_L);
    AccX = AccX << 8;
    AccX = AccX + data;

    data = ByteRead(MPU6050_RA_ACCEL_YOUT_H);
    AccY = data;
    data = ByteRead(MPU6050_RA_ACCEL_YOUT_L);
    AccY = AccY << 8;
    AccY = AccY + data;

    data = ByteRead(MPU6050_RA_ACCEL_ZOUT_H);
    AccZ = data;
    data = ByteRead(MPU6050_RA_ACCEL_ZOUT_L);
    AccZ = AccZ << 8;
    AccZ = AccZ + data;

    data = ByteRead(MPU6050_RA_GYRO_XOUT_H);
    GyroX = data;
    data = ByteRead(MPU6050_RA_GYRO_XOUT_L);
    GyroX = GyroX << 8;
    GyroX = GyroX + data;

    data = ByteRead(MPU6050_RA_GYRO_YOUT_H);
    GyroY = data;
    data = ByteRead(MPU6050_RA_GYRO_YOUT_L);
    GyroY = GyroY << 8;
    GyroY = GyroY + data;

    data = ByteRead(MPU6050_RA_GYRO_ZOUT_H);
    GyroZ = data;
    data = ByteRead(MPU6050_RA_GYRO_ZOUT_L);
    GyroZ = GyroZ << 8;
    GyroZ = GyroZ + data;

    data = ByteRead(MPU6050_RA_TEMP_OUT_H);
    Temp = data;
    data = ByteRead(MPU6050_RA_TEMP_OUT_L);
    Temp = Temp << 8;
    Temp = Temp + data;
}


void Prueba_LED()
{
/*    LED1 = 1;
    DelayXms_T3(500);
    LED2 = 1;
    DelayXms_T3(500);
    LED3 = 1;
    DelayXms_T3(500);
    DelayXms_T3(500);*/
    LED3 = BOTON_A;

}

void enviarDatosFiltro(void)
{
    int _accXangle;
    int _accYangle;
    int _gyroXangle;
    int _gyroYangle;
    int _compAngleX;
    int _compAngleY;
    int _kalAngleX;

    _accXangle = accXangle;
    _accYangle = accYangle;
    _gyroXangle = gyroXangle;
    _gyroYangle = gyroYangle;
    _compAngleX = compAngleX;
    _compAngleY = compAngleY;
    _kalAngleX = kalAngleX;

    itoa(str_blue,_accXangle, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));

    strcpy(str_blue,"    ");
    enviar_datos_NOCR(str_blue, strlen(str_blue));


    itoa(str_blue,accYangle, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));

    strcpy(str_blue,"    ");
    enviar_datos_NOCR(str_blue, strlen(str_blue));


    itoa(str_blue,gyroXangle, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));

    strcpy(str_blue,"    ");
    enviar_datos_NOCR(str_blue, strlen(str_blue));


    itoa(str_blue,gyroYangle, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));

    strcpy(str_blue,"    ");
    enviar_datos_NOCR(str_blue, strlen(str_blue));


    itoa(str_blue,compAngleX, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));

    strcpy(str_blue,"    ");
    enviar_datos_NOCR(str_blue, strlen(str_blue));


    itoa(str_blue,compAngleY, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));

    strcpy(str_blue,"    ");
    enviar_datos_NOCR(str_blue, strlen(str_blue));


    itoa(str_blue,kalAngleX, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));

    strcpy(str_blue,"    ");
    enviar_datos(str_blue, strlen(str_blue));
}

void EjecutarPID(void)
{
    Prueba_I2C();
    Filter();
    enviarDatosFiltro();
}
