/* 
 * File:   peticionesMPU6050.c
 * Author: pablo
 *
 * Created on 20 de diciembre de 2013, 0:32
 */
#include "CA_SetGetMPU6050.h"


void set_inicial()
{   WriteAddress(MPU6050_RA_SMPLRT_DIV ,MPU6050_CLOCK_DIV_364);
    WriteAddress( MPU6050_RA_PWR_MGMT_1,MPU6050_CLOCK_PLL_XGYRO);   // setClockSource(MPU6050_CLOCK_PLL_XGYRO);
    WriteAddress( MPU6050_RA_GYRO_CONFIG, MPU6050_GYRO_FS_2000);     // setFullScaleGyroRange(MPU6050_GYRO_FS_250);
    WriteAddress( MPU6050_RA_ACCEL_CONFIG,MPU6050_ACCEL_FS_16);      //   setFullScaleAccelRange(MPU6050_ACCEL_FS_2);
    WriteAddress(MPU6050_RA_CONFIG  ,0x06);
}
int get_ax()
{
    int LowPart = 0;
    int HighPart = 0;

    HighPart= ReadAddress(MPU6050_RA_ACCEL_XOUT_H);
    LowPart= ReadAddress(MPU6050_RA_ACCEL_XOUT_L);
    return( (HighPart << 8) + LowPart);
}
int get_ay(void)
{
    int LowPart = 0;
    int HighPart = 0;

    HighPart= ReadAddress(MPU6050_RA_ACCEL_YOUT_H);
    LowPart= ReadAddress(MPU6050_RA_ACCEL_YOUT_L);
    return( (HighPart << 8) + LowPart);
}
int get_az(void)
{
    int LowPart = 0;
    int HighPart = 0;

    HighPart= ReadAddress(MPU6050_RA_ACCEL_ZOUT_H);
    LowPart= ReadAddress(MPU6050_RA_ACCEL_ZOUT_L);
    return( (HighPart << 8) + LowPart);
}
int get_gx(void)
{
    int LowPart = 0;
    int HighPart = 0;

    HighPart= ReadAddress(MPU6050_RA_GYRO_XOUT_H);
    LowPart= ReadAddress(MPU6050_RA_GYRO_XOUT_L);
    return( (HighPart << 8) + LowPart);
}

int get_gy(void)
{
    int LowPart = 0;
    int HighPart = 0;

    HighPart= ReadAddress(MPU6050_RA_GYRO_YOUT_H);
    LowPart= ReadAddress(MPU6050_RA_GYRO_YOUT_L);
    return( (HighPart << 8) + LowPart);
}
int get_gz(void)
{
    int LowPart = 0;
    int HighPart = 0;

    HighPart= ReadAddress(MPU6050_RA_GYRO_ZOUT_H);
    LowPart= ReadAddress(MPU6050_RA_GYRO_ZOUT_L);
    return( (HighPart << 8) + LowPart);
}

int get_temp(void)
{
    int LowPart = 0;
    int HighPart = 0;

    HighPart= ReadAddress(MPU6050_RA_TEMP_OUT_H);
    LowPart= ReadAddress(MPU6050_RA_TEMP_OUT_L);
    return( (HighPart << 8) + LowPart);
}

int get_who_I_AM(void)
{
    return( ReadAddress(MPU6050_RA_WHO_AM_I));
}

void plot1(int valor1)
{
        int encabezado[3];
        encabezado[0]=0xCDAB;
        encabezado[1]= 2*sizeof(int);
        encabezado[2]=valor1;
        int pktSize = 2 + 2 + (1*sizeof(int));
        enviar_datos_NOCR((int * )encabezado, pktSize);

}
void plot2(int valor1, int valor2)
{
        int encabezado[4];
        encabezado[0]=0xCDAB;
        encabezado[1]= 2*sizeof(int);
        encabezado[2]=valor1;
        encabezado[3]=valor2;
        int pktSize = 2 + 2 + (2*sizeof(int));
        enviar_datos_NOCR((int * )encabezado, pktSize);

}
void plot3(int valor1, int valor2,int valor3)
{
        int encabezado[5];
        encabezado[0]=0xCDAB;
        encabezado[1]= 3*sizeof(int);
        encabezado[2]=valor1;
        encabezado[3]=valor2;
        encabezado[4]=valor3;
        int pktSize = 2 + 2 + (3*sizeof(int));
        enviar_datos_NOCR((int * )encabezado, pktSize);

}
void plot4(int valor1, int valor2,int valor3,int valor4)
{
        int encabezado[6];
        encabezado[0]=0xCDAB;
        encabezado[1]= 4*sizeof(int);
        encabezado[2]=valor1;
        encabezado[3]=valor2;
        encabezado[4]=valor3;
        encabezado[5]=valor4;
        int pktSize = 2 + 2 + (4*sizeof(int));
        enviar_datos_NOCR((int * )encabezado, pktSize);

}

void get_acelerometro(int *_ax,int *_ay,int *_az, int *_gx,int *_gy,int *_gz)
{
    (*_ax) = get_ax();
    (*_ay) = get_ay();
    (*_az) = get_az();
    (*_gx) = get_gx();
    (*_gy) = get_gy();
    (*_gz) = get_gz();
}
