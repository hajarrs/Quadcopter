/* 
 * File:   CB_I2C.h
 * Author: Raul
 *
 * Created on 22 de agosto de 2013, 20:07
 */

#ifndef CB_I2C_H
#define	CB_I2C_H
#include <i2c.h>
#include "Bluetooth.h"
#include "Timers.h"


void set_inicial(void);

extern double calibra_ax;
extern double calibra_ay;
extern double calibra_az;
extern double calibra_gx;
extern double calibra_gy;
extern double calibra_gz;

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

int get_ax(void);
int get_ay(void);
int get_az(void);
int get_gx(void);
int get_gy(void);
int get_gz(void);
int get_who_I_AM(void);
void get_acelerometro(int *_ax,int *_ay,int *_az, int *_gx,int *_gy,int *_gz);
#endif	/* CB_I2C_H */

