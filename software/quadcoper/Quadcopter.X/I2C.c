
#include "I2C.h"


#define DISP 0xD0

#define PRINTI2C 1
void my_Write_I2C(unsigned char byte)
{
    I2CTRN = byte;					//Load byte to I2C Transmit buffer
    while (I2CSTATbits.TBF);		//wait for data transmission
}


#ifdef PRINTI2C
void InitTimer5(void)
{
    T5CON = 0b0000000000100000; // Preescala 1:x
    PR5 = 0x0570;         // PR5= 0x0570;       // 3 msg
    TMR5 = 0;
    IFS1bits.T5IF = 0;
    T5CONbits.TON = 0;
    _T5IE = 0;
    T5CONbits.TON = 1;
}
#endif

unsigned int my_StartI2C(void)
{
    I2CCONbits.SEN = 1;
    
#ifdef PRINTI2C
    InitTimer5();
#endif
    _T5IF = 0;
    while (I2CCONbits.SEN && !_T5IF);

    T5CONbits.TON = 0;
#ifdef PRINTI2C
    if(_T5IF)
         enviar_mensaje("Salgo de MyStart por Timer");
        
#endif
    return 0;
}

unsigned int my_RestartI2C(void)
{
    I2CCONbits.RSEN = 1;

#ifdef PRINTI2C
    InitTimer5();
#endif
    _T5IF = 0;
    while (I2CCONbits.RSEN && !_T5IF);

#ifdef PRINTI2C
    T5CONbits.TON = 0;
    if(_T5IF)
        enviar_mensaje("Salgo de MyRestart por Timer");
    
#endif
    return 0;
}

unsigned int my_StopI2C(void)
{
    I2CCONbits.PEN = 1;		//Generate Stop Condition

#ifdef PRINTI2C
    InitTimer5();
#endif
    
    _T5IF = 0;
    while (I2CCONbits.PEN && !_T5IF);	//Wait for Stop

#ifdef PRINTI2C
    T5CONbits.TON = 0;
    if(_T5IF)
        enviar_mensaje("Salgo de my_Stop por Timer");
        
#endif
    return 0;
}

unsigned int my_WriteI2C(unsigned char byte)
{
    I2CTRN = byte;					//Load byte to I2C1 Transmit buffer

#ifdef PRINTI2C
    InitTimer5();
#endif

    _T5IF = 0;
    while (I2CSTATbits.TBF && !_T5IF);		//wait for data transmission
#ifdef PRINTI2C
    T5CONbits.TON = 0;
    if(_T5IF)
       enviar_mensaje("Salgo de my_Write por Timer");
        
#endif
    return 0;
}

unsigned int my_IdleI2C(void)
{
#ifdef PRINTI2C
    InitTimer5();
#endif
    _T5IF = 0;
    while (I2CSTATbits.TRSTAT && !_T5IF);		//Wait for bus Idle
#ifdef PRINTI2C
    T5CONbits.TON = 0;
    if(_T5IF)
         enviar_mensaje("Salgo de my_Idle por Timer");
        
#endif
    return 0;
}

unsigned int my_ACKStatus(void)
{
    return (!I2CSTATbits.ACKSTAT);		//Return Ack Status
}

unsigned int my_NotAckI2C(void)
{
    I2CCONbits.ACKDT = 1;			//Set for NotACk
    I2CCONbits.ACKEN = 1;
    while(I2CCONbits.ACKEN);		//wait for ACK to complete
    I2CCONbits.ACKDT = 0;			//Set for NotACk
    return 0;
}

unsigned int my_AckI2C(void)
{
    I2CCONbits.ACKDT = 0;			//Set for ACk
    I2CCONbits.ACKEN = 1;
    while(I2CCONbits.ACKEN);		//wait for ACK to complete
    return 0;
}

unsigned int my_getI2C(void)
{
    I2CCONbits.RCEN = 1;			//Enable Master receive

    while(!I2CSTATbits.RBF);		//Wait for receive buffer to be full
    return(I2CRCV);				//Return data in buffer
}
unsigned int my_masterreceiveI2C(void)
{
    I2CCONbits.RCEN=1;Delay_Nop(1);
    while(I2CCONbits.RCEN);
    return(1);				//Return data in buffer
}

unsigned int my_getsI2C(unsigned char *rdptr, unsigned char Length)
{
	while (Length --)
	{
		*rdptr++ = my_getI2C();		//get a single byte

		if(I2CSTATbits.BCL)		//Test for Bus collision
		{
			return(-1);
		}

		if(Length)
		{
			my_AckI2C();				//Acknowledge until all read
		}
	}
	return(0);
}


unsigned int ReadAddress(unsigned char Address)
{
        my_IdleI2C();					//wait for bus Idle
	my_StartI2C();					//Generate Start Condition
        my_WriteI2C(DISP);		//Write Control Byte
        my_IdleI2C();					//wait for bus Idle
        my_WriteI2C(Address);			//Write start address
        my_IdleI2C();					//wait for bus Idle
	my_RestartI2C();				//Generate restart condition
        my_WriteI2C(DISP+1);	//Write control byte for read
        my_IdleI2C();
        my_masterreceiveI2C();
	my_NotAckI2C();				//Send Not Ack
	my_StopI2C();
        return (I2CRCV);
}

void LED_ALL_ON();

void WriteAddress(unsigned char address, unsigned char data)
{
    my_StartI2C();



    my_WriteI2C(DISP);
    my_IdleI2C();

    my_WriteI2C(address);
    my_IdleI2C();
    
    my_WriteI2C(data);

    my_IdleI2C();
    my_StopI2C();

}



void set_inicial()
{   WriteAddress(MPU6050_RA_SMPLRT_DIV ,MPU6050_CLOCK_DIV_364);
    WriteAddress( MPU6050_RA_PWR_MGMT_1,MPU6050_CLOCK_PLL_XGYRO);   // setClockSource(MPU6050_CLOCK_PLL_XGYRO);
    WriteAddress( MPU6050_RA_GYRO_CONFIG, MPU6050_GYRO_FS_500);     // setFullScaleGyroRange(MPU6050_GYRO_FS_250);
    WriteAddress( MPU6050_RA_ACCEL_CONFIG,MPU6050_ACCEL_FS_4);      //   setFullScaleAccelRange(MPU6050_ACCEL_FS_2);
    WriteAddress(MPU6050_RA_CONFIG  ,0x06);
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


void get_acelerometro(int *_ax,int *_ay,int *_az, int *_gx,int *_gy,int *_gz)
{
    (*_ax) = get_ax();
    (*_ay) = get_ay();
    (*_az) = get_az();
    (*_gx) = get_gx();
    (*_gy) = get_gy();
    (*_gz) = get_gz();
}
