#include <p30F4013.h>

#include <i2c.h>
#include "CB_I2C.h"
#include "Pruebas.h"
#include "Defines.h"
#include "CB_Timer2.h"
#include "CB_Bluetooth.h"
#include "CA_kalman.h"
#include "CB_Inicializaciones.h"


void Prueba2_PWM(void)
{
       PWM1 = 32500;
       PWM2 = 32500;
       PWM3 = 32500;
       PWM4 = 32500;
}

void PWM_prueba(void)
{
 int Stop = 0;
    while(Stop == 0)
    {
       PWM4+=1;
       PWM3+=1;
       PWM2+=1;
       PWM1+=1;
       Delay_Nop(5000);


       if(PWM4 >= 0x0FFC)
       {
           PWM4 = 0x0FFF;
           PWM3 = 0x0FFF;
           PWM2 = 0x0FFF;
           PWM1 = 0x0FFF;
      // LEDROJO = 1;
           Stop = 1;
       }
    }
    while(Stop == 1)
    {

       PWM4-=1;
       PWM3-=1;
      PWM2-=1;
       PWM1-=1;
       Delay_Nop(5000);



       if(PWM4 <= 0x0070)
       {
           PWM4 = 0;
           PWM3 = 0;
           PWM2 = 0;
           PWM1 = 0;
// LEDROJO = 0;
           Stop = 0;
       }
    }
}

void Prueba_PWM(void)
{
    int i;

    for (i=0;i>0xffff;i++)
    {
       PWM4=i;
       PWM3=i;
       PWM2=i;
       PWM1=i;
       Delay_Nop(5000);
          LEDVERDE=0;

    }
          for (i=0xffff;i<0x0001;i--)
    {
              LEDVERDE=1;
       PWM4=i;
       PWM3=i;
       PWM2=i;
       PWM1=i;
       Delay_Nop(5000);
}
}
void Prueba_Bluetooth_2(char *cadena)
{
    strcpy(str_blue,cadena);
    enviar_datos(str_blue, strlen(str_blue));
    Delay_Nop(5000);
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
}





void Prueba_I2C(void)
{
    
    IdleI2C();					//wait for bus Idle
    StartI2C();					//Generate Start Condition
    while(I2CCONbits.SEN );

    Write_I2C(0xD0);		//Write Control Byte
    while(I2CSTATbits.ACKSTAT);

    IdleI2C();			//wait for bus Idle

    Write_I2C(0x75);		//Write start address
    while(I2CSTATbits.ACKSTAT);
    IdleI2C();			//wait for bus Idle

    //RestartI2C();			//Generate restart condition

    I2CCONbits.RSEN=1;
    Nop();
    while(I2CCONbits.RSEN);



    my_Write_I2C(0xD1);                //Write control byte for read
    while(I2CSTATbits.ACKSTAT);

    IdleI2C();			//wait for bus Idle


    //    getsi2cdatalaunch()
    I2CCONbits.RCEN = 1;			//Enable Master receive

    while(!I2CSTATbits.RBF);		//Wait for receive bufer to be full

    NotAckI2C();			//Send Not Ack

    StopI2C();			//Generate Stop
    while(I2CCONbits.PEN);


   return;

}


void Prueba_LED_BOTON()
{
                int i;
                if (BOTONEXTERNO==1)
                {
                     LED_ALL_OFF();
                    for(i=0;i<300;i++)Delay1msT1(0);
                    LEDNARANJA=1;
                    for(i=0;i<300;i++)Delay1msT1(0);
                    LEDAZUL=1;
                    for(i=0;i<300;i++)Delay1msT1(0);
                    LEDAMARILLO=1;
                    for(i=0;i<300;i++) Delay1msT1(0);
                    LEDVERDE=1;
                    for(i=0;i<300;i++)Delay1msT1(0);
                    LEDROJO=1;
                    for(i=0;i<300;i++)Delay1msT1(0);
                }
                else if (BOTONINTERNO==1)
                {
                    LED_ALL_OFF();
                    for(i=0;i<300;i++)Delay1msT1(0);
                    LEDROJO=1;
                    for(i=0;i<300;i++)Delay1msT1(0);
                    LEDVERDE=1;
                    for(i=0;i<300;i++)Delay1msT1(0);
                    LEDAMARILLO=1;
                    for(i=0;i<300;i++) Delay1msT1(0);
                    LEDAZUL=1;
                    for(i=0;i<300;i++)Delay1msT1(0);
                    LEDNARANJA=1;
                    for(i=0;i<300;i++)Delay1msT1(0);

                }
                else
                {
                    LED_ALL_OFF();
                    for(i=0;i<300;i++)Delay1msT1(0);
                    LED_ALL_ON();
                    for(i=0;i<300;i++)Delay1msT1(0);
                }

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

        int z=0;
        int ini=60;
unsigned int Peticion_Acelerometro(unsigned char  datos)
{
        my_IdleI2C();					//wait for bus Idle
	my_StartI2C();					//Generate Start Condition
        my_WriteI2C(0xD2);		//Write Control Byte
        my_IdleI2C();					//wait for bus Idle
        my_WriteI2C(datos);			//Write start address
        my_IdleI2C();					//wait for bus Idle
	my_RestartI2C();				//Generate restart condition
        my_WriteI2C(0xD2+1);	//Write control byte for read
        my_IdleI2C();
        my_masterreceiveI2C();
	my_NotAckI2C();				//Send Not Ack
	my_StopI2C();
        return (I2CRCV);
    }
void prueba2_I2C()
{
    int data;
    data = Peticion_Acelerometro(MPU6050_RA_ACCEL_XOUT_H);
    AccX = data;
    data = Peticion_Acelerometro(MPU6050_RA_ACCEL_XOUT_L);
    AccX = AccX << 8;
    AccX = AccX + data;

    itoa(str_blue,data, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    strcpy(str_blue,";");
    enviar_datos_NOCR(str_blue, strlen(str_blue));

    data = Peticion_Acelerometro(MPU6050_RA_ACCEL_YOUT_H);
    AccY = data;
    data = Peticion_Acelerometro(MPU6050_RA_ACCEL_YOUT_L);
    AccY = AccY << 8;
    AccY = AccY + data;

    itoa(str_blue,data, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    strcpy(str_blue,";");
    enviar_datos_NOCR(str_blue, strlen(str_blue));

    data = Peticion_Acelerometro(MPU6050_RA_ACCEL_ZOUT_H);
    AccZ = data;
    data = Peticion_Acelerometro(MPU6050_RA_ACCEL_ZOUT_L);
    AccZ = AccZ << 8;
    AccZ = AccZ + data;

    itoa(str_blue,data, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    strcpy(str_blue,";");
    enviar_datos_NOCR(str_blue, strlen(str_blue));

    data = Peticion_Acelerometro(MPU6050_RA_GYRO_XOUT_H);
    GyroX = data;
    data = Peticion_Acelerometro(MPU6050_RA_GYRO_XOUT_L);
    GyroX = GyroX << 8;
    GyroX = GyroX + data;


    itoa(str_blue,data, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    strcpy(str_blue,";");
    enviar_datos_NOCR(str_blue, strlen(str_blue));

    data = Peticion_Acelerometro(MPU6050_RA_GYRO_YOUT_H);
    GyroY = data;
    data = Peticion_Acelerometro(MPU6050_RA_GYRO_YOUT_L);
    GyroY = GyroY << 8;
    GyroY = GyroY + data;

    itoa(str_blue,data, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    strcpy(str_blue,";");
    enviar_datos_NOCR(str_blue, strlen(str_blue));

    data = Peticion_Acelerometro(MPU6050_RA_GYRO_ZOUT_H);
    GyroZ = data;
    data = Peticion_Acelerometro(MPU6050_RA_GYRO_ZOUT_L);

    GyroZ = GyroZ << 8;
    GyroZ = GyroZ + data;

    itoa(str_blue,data, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    strcpy(str_blue,";");
    enviar_datos_NOCR(str_blue, strlen(str_blue));

    data = Peticion_Acelerometro(MPU6050_RA_TEMP_OUT_H);
    Temp = data;
    data = Peticion_Acelerometro(MPU6050_RA_TEMP_OUT_L);
    Temp = Temp << 8;
    Temp = Temp + data;

    itoa(str_blue,data, 10);
    enviar_datos(str_blue, strlen(str_blue));




    }




