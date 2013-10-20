/* 
 * File:   CB_I2C.h
 * Author: Raul
 *
 * Created on 22 de agosto de 2013, 20:07
 */

#ifndef CB_I2C_H
#define	CB_I2C_H

#include "CB_Timer2.h"

void Write_I2C(unsigned char byte);
void ByteWrite(unsigned char address, unsigned char data);
unsigned char ByteRead(unsigned char Address);


#endif	/* CB_I2C_H */

