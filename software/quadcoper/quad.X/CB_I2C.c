#include <p30F4013.h>
#include "CB_I2C.h"
#include <i2c.h>

void my_Write_I2C(unsigned char byte)
{
    I2CTRN = byte;					//Load byte to I2C Transmit buffer
    while (I2CSTATbits.TBF);		//wait for data transmission
}

void Write_I2C(unsigned char byte)
{
    I2CTRN = byte;					//Load byte to I2C Transmit buffer
    while (I2CSTATbits.TBF);		//wait for data transmission
}

void ByteWrite(unsigned char address, unsigned char data)
{
    unsigned int tmp_delay = 15;
    unsigned char write =0xD0;

    IdleI2C();
    StartI2C();
    Delay_Nop(tmp_delay);

    Write_I2C(write);
    IdleI2C();
    Delay_Nop(tmp_delay);

    Write_I2C(address);
    IdleI2C();
    Delay_Nop(tmp_delay);

    Write_I2C(data);
    IdleI2C();
    StopI2C();



}

unsigned int my_StartI2C(void)
{
	//This function generates an I2C start condition and returns status
	//of the Start.

	I2CCONbits.SEN = 1;		//Generate Start Condition
	Nop();
	while (I2CCONbits.SEN);	//Wait for Start Condition
	//return(I2C1STATbits.S);	//Optionally return status
        return 0;
}

unsigned int my_RestartI2C(void)
{
	//This function generates an I2C Restart condition and returns status
	//of the Restart.

	I2CCONbits.RSEN = 1;		//Generate Restart
	Nop();
	while (I2CCONbits.RSEN);	//Wait for restart
	//return(I2C1STATbits.S);	//Optional - return status
        return 0;
}

unsigned int my_StopI2C(void)
{
	//This function generates an I2C stop condition and returns status
	//of the Stop.

	I2CCONbits.PEN = 1;		//Generate Stop Condition
	Nop();
	while (I2CCONbits.PEN);	//Wait for Stop
	//return(I2C1STATbits.P);	//Optional - return status
        return 0;
}

unsigned int my_WriteI2C(unsigned char byte)
{
	//This function transmits the byte passed to the function
	//while (I2C1STATbits.TRSTAT);	//Wait for bus to be idle
	I2CTRN = byte;					//Load byte to I2C1 Transmit buffer
	Nop();
	while (I2CSTATbits.TBF);		//wait for data transmission
        return 0;
}

unsigned int my_IdleI2C(void)
{
	while (I2CSTATbits.TRSTAT);		//Wait for bus Idle
        Delay_Nop(1);
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
	Nop();
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


unsigned int LDByteReadI2C(unsigned char ControlByte, unsigned char Address, unsigned char *Data, unsigned char Length)
{
	my_IdleI2C();					//wait for bus Idle
	my_StartI2C();					//Generate Start Condition
	my_WriteI2C(ControlByte);		//Write Control Byte
	my_IdleI2C();					//wait for bus Idle
	my_WriteI2C(Address);			//Write start address
	my_IdleI2C();					//wait for bus Idle

	my_RestartI2C();				//Generate restart condition
	my_WriteI2C(ControlByte | 0x01);	//Write control byte for read
	my_IdleI2C();					//wait for bus Idle

	my_getsI2C(Data, Length);		//read Length number of bytes
	my_NotAckI2C();				//Send Not Ack
	my_StopI2C();					//Generate Stop

        return 0;
}


unsigned int LDByteWriteI2C(unsigned char LowAdd, unsigned char data)
{
	unsigned int ErrorCode1;
	unsigned int ErrorCode2;

	my_IdleI2C();						//Ensure Module is Idle
	my_StartI2C();						//Generate Start COndition
	my_WriteI2C(0xD0);			//Write Control byte
	my_IdleI2C();

	ErrorCode1 = my_ACKStatus();		//Return ACK Status

	my_WriteI2C(LowAdd);				//Write Low Address
	my_IdleI2C();

	ErrorCode2 = my_ACKStatus();		//Return ACK Status

	my_WriteI2C(data);					//Write Data
	my_IdleI2C();

	my_StopI2C();						//Initiate Stop Condition

        return 0;
	//return(ErrorCode);
}
