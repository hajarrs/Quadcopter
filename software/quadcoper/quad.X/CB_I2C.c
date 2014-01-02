
#include "CB_I2C.h"




#define PRINTI2C 1
void my_Write_I2C(unsigned char byte)
{
    I2CTRN = byte;					//Load byte to I2C Transmit buffer
    while (I2CSTATbits.TBF);		//wait for data transmission
}

#ifdef PRINTI2C
void InitTimer3(void)
{
    T3CON = 0b0000000000100000; // Preescala 1:x
    PR3 = 0x0570;         // PR3 = 0x0570;       // 3 msg
    TMR3 = 0;
    IFS0bits.T3IF = 0;
    T3CONbits.TON = 0;
    _T3IE = 0;
    T3CONbits.TON = 1;
}
#endif

unsigned int my_StartI2C(void)
{
    I2CCONbits.SEN = 1;
    
#ifdef PRINTI2C
    InitTimer3();
#endif
    _T3IF = 0;
    while (I2CCONbits.SEN && !_T3IF);

    T3CONbits.TON = 0;
#ifdef PRINTI2C
    if(_T3IF)
         enviar_mensaje("Salgo de MyStart por Timer");
        
#endif
    return 0;
}

unsigned int my_RestartI2C(void)
{
    I2CCONbits.RSEN = 1;

#ifdef PRINTI2C
    InitTimer3();
#endif
    _T3IF = 0;
    while (I2CCONbits.RSEN && !_T3IF);

#ifdef PRINTI2C
    T3CONbits.TON = 0;
    if(_T3IF)
        enviar_mensaje("Salgo de MyRestart por Timer");
    
#endif
    return 0;
}

unsigned int my_StopI2C(void)
{
    I2CCONbits.PEN = 1;		//Generate Stop Condition

#ifdef PRINTI2C
    InitTimer3();
#endif
    
    _T3IF = 0;
    while (I2CCONbits.PEN && !_T3IF);	//Wait for Stop

#ifdef PRINTI2C
    T3CONbits.TON = 0;
    if(_T3IF)
        enviar_mensaje("Salgo de my_Stop por Timer");
        
#endif
    return 0;
}

unsigned int my_WriteI2C(unsigned char byte)
{
    I2CTRN = byte;					//Load byte to I2C1 Transmit buffer

#ifdef PRINTI2C
    InitTimer3();
#endif

    _T3IF = 0;
    while (I2CSTATbits.TBF && !_T3IF);		//wait for data transmission
#ifdef PRINTI2C
    T3CONbits.TON = 0;
    if(_T3IF)
       enviar_mensaje("Salgo de my_Write por Timer");
        
#endif
    return 0;
}

unsigned int my_IdleI2C(void)
{
#ifdef PRINTI2C
    InitTimer3();
#endif
    _T3IF = 0;
    while (I2CSTATbits.TRSTAT && !_T3IF);		//Wait for bus Idle
#ifdef PRINTI2C
    T3CONbits.TON = 0;
    if(_T3IF)
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
        my_WriteI2C(0xD2);		//Write Control Byte
        my_IdleI2C();					//wait for bus Idle
        my_WriteI2C(Address);			//Write start address
        my_IdleI2C();					//wait for bus Idle
	my_RestartI2C();				//Generate restart condition
        my_WriteI2C(0xD2+1);	//Write control byte for read
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



    my_WriteI2C(0xD2);
    my_IdleI2C();

    my_WriteI2C(address);
    my_IdleI2C();
    
    my_WriteI2C(data);

    my_IdleI2C();
    my_StopI2C();

/*
    IdleI2C();					//wait for bus Idle
    my_StartI2C();					//Generate Start Condition
    
    my_Write_I2C(0xD0);		//Write Control Byte
    while(I2CSTATbits.ACKSTAT);
    IdleI2C();			//wait for bus Idle

    my_Write_I2C(MPU6050_RA_PWR_MGMT_1);		//Write start address
    while(I2CSTATbits.ACKSTAT);
    IdleI2C();			//wait for bus Idle
   
    my_Write_I2C(data);                //Write control byte for read
    while(I2CSTATbits.ACKSTAT);
    IdleI2C();			//wait for bus Idle

    StopI2C();			//Generate Stop
    while(I2CCONbits.PEN);
    */
}