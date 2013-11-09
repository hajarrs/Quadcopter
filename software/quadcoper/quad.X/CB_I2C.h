/* 
 * File:   CB_I2C.h
 * Author: Raul
 *
 * Created on 22 de agosto de 2013, 20:07
 */

#ifndef CB_I2C_H
#define	CB_I2C_H

#include "CB_Timer2.h"

unsigned int my_IdleI2C(void);
unsigned int my_AckI2C(void);
unsigned int my_getI2C(void);
unsigned int my_getsI2C(unsigned char *rdptr, unsigned char Length);
unsigned int my_StartI2C(void);
unsigned int my_RestartI2C(void);
unsigned int my_StopI2C(void);
unsigned int my_WriteI2C(unsigned char byte);
unsigned int my_ACKStatus(void);
void my_Write_I2C(unsigned char byte);
unsigned int LDByteWriteI2C(unsigned char LowAdd, unsigned char data);
unsigned int my_NotAckI2C(void);
void ByteWrite(unsigned char address, unsigned char data);

#endif	/* CB_I2C_H */

