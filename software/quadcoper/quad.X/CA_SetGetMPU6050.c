/* 
 * File:   peticionesMPU6050.c
 * Author: pablo
 *
 * Created on 20 de diciembre de 2013, 0:32
 */
#include "CA_SetGetMPU6050.h"

void set_inicial()
{
    WriteAddress( MPU6050_RA_PWR_MGMT_1,MPU6050_CLOCK_PLL_XGYRO);   // setClockSource(MPU6050_CLOCK_PLL_XGYRO);
    WriteAddress( MPU6050_RA_GYRO_CONFIG, MPU6050_GYRO_FS_250);     // setFullScaleGyroRange(MPU6050_GYRO_FS_250);
    WriteAddress( MPU6050_RA_ACCEL_CONFIG,MPU6050_ACCEL_FS_2);      //   setFullScaleAccelRange(MPU6050_ACCEL_FS_2);
}
unsigned int get_ax()
{
    int LowPart = 0;
    int HighPart = 0;

    HighPart= ReadAddress(MPU6050_RA_ACCEL_XOUT_H);
    LowPart= ReadAddress(MPU6050_RA_ACCEL_XOUT_L);
    return( (HighPart << 8) + LowPart);
}
unsigned int get_ay(void)
{
    int LowPart = 0;
    int HighPart = 0;

    HighPart= ReadAddress(MPU6050_RA_ACCEL_YOUT_H);
    LowPart= ReadAddress(MPU6050_RA_ACCEL_YOUT_L);
    return( (HighPart << 8) + LowPart);
}
unsigned int get_az(void)
{
    int LowPart = 0;
    int HighPart = 0;

    HighPart= ReadAddress(MPU6050_RA_ACCEL_ZOUT_H);
    LowPart= ReadAddress(MPU6050_RA_ACCEL_ZOUT_L);
    return( (HighPart << 8) + LowPart);
}
unsigned int get_gx(void)
{
    int LowPart = 0;
    int HighPart = 0;

    HighPart= ReadAddress(MPU6050_RA_GYRO_XOUT_H);
    LowPart= ReadAddress(MPU6050_RA_GYRO_XOUT_L);
    return( (HighPart << 8) + LowPart);
}

unsigned int get_gy(void)
{
    int LowPart = 0;
    int HighPart = 0;

    HighPart= ReadAddress(MPU6050_RA_GYRO_YOUT_H);
    LowPart= ReadAddress(MPU6050_RA_GYRO_YOUT_L);
    return( (HighPart << 8) + LowPart);
}
unsigned int get_gz(void)
{
    int LowPart = 0;
    int HighPart = 0;

    HighPart= ReadAddress(MPU6050_RA_GYRO_ZOUT_H);
    LowPart= ReadAddress(MPU6050_RA_GYRO_ZOUT_L);
    return( (HighPart << 8) + LowPart);
}

unsigned int get_temp(void)
{
    int LowPart = 0;
    int HighPart = 0;

    HighPart= ReadAddress(MPU6050_RA_TEMP_OUT_H);
    LowPart= ReadAddress(MPU6050_RA_TEMP_OUT_L);
    return( (HighPart << 8) + LowPart);
}

unsigned int get_who_I_AM(void)
{
    return( ReadAddress(MPU6050_RA_WHO_AM_I));
}