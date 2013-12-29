/* 
 * File:   CB_I2C.h
 * Author: Raul
 *
 * Created on 22 de agosto de 2013, 20:07
 */

#ifndef CB_I2C_H
#define	CB_I2C_H
#include <i2c.h>
#include "CB_Bluetooth.h"
#include "Defines.h"
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
unsigned int my_masterreceiveI2C(void);
void my_Write_I2C(unsigned char byte);
unsigned int my_NotAckI2C(void);
void WriteAddress(unsigned char address, unsigned char data);
unsigned int ReadAddress(unsigned char Address);

#endif	/* CB_I2C_H */

