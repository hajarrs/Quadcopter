/* 
 * File:   CB_I2C.h
 * Author: Raul
 *
 * Created on 22 de agosto de 2013, 20:07
 */

#ifndef CB_I2C_H
#define	CB_I2C_H

void Write_I2C(unsigned char byte)
{
    I2CTRN = byte;					//Load byte to I2C Transmit buffer
    while (I2CSTATbits.TBF);		//wait for data transmission
}

void ByteWrite(unsigned char address, unsigned char data)
{
    unsigned int tmp_delay = 15;
    unsigned char write = 0xD0;		// Byte de Control del ACC

    IdleI2C();						//Ensure Module is Idle
    StartI2C();						//Generate Start COndition
    Delay_Nop(tmp_delay);  // Necesario!!!!!

    Write_I2C(write);				//Write Control byte
    IdleI2C();
    Delay_Nop(tmp_delay);  // Necesario!!!!!

    Write_I2C(address);				//Write High Address
    IdleI2C();
    Delay_Nop(tmp_delay);  // Necesario!!!!!

    Write_I2C(data);					//Write Data
    IdleI2C();
    StopI2C();						//Initiate Stop Condition
}

unsigned char ByteRead(unsigned char Address)
{
    unsigned int tmp_delay = 15;
    IdleI2C();					//wait for bus Idle
    StartI2C();					//Generate Start Condition
    while(I2CCONbits.SEN );

    Write_I2C(0xD0);		//Write Control Byte
    while(I2CSTATbits.ACKSTAT);
    IdleI2C();			//wait for bus Idle


    Write_I2C(Address);		//Write start address
    while(I2CSTATbits.ACKSTAT);
    IdleI2C();			//wait for bus Idle


    RestartI2C();			//Generate restart condition
    Delay_Nop(tmp_delay);  // Necesario!!!!!

    Write_I2C(0xD1);                //Write control byte for read
    while(I2CSTATbits.ACKSTAT);
    Delay_Nop(2);   // No es necesario

    IdleI2C();			//wait for bus Idle

    I2CCONbits.RCEN = 1;			//Enable Master receive

    while(!I2CSTATbits.RBF);		//Wait for receive bufer to be full
    Delay_Nop(2);   // No es necesario

    NotAckI2C();			//Send Not Ack
    Delay_Nop(tmp_delay);  // Necesario!!!!!

    StopI2C();			//Generate Stop
    while(I2CCONbits.PEN);

    return(I2CRCV);				//Return data in buffer
}


#endif	/* CB_I2C_H */

