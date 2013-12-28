/* 
 * File:   calibrado_filtro.c
 * Author: pablo
 *
 * Created on 20 de diciembre de 2013, 0:25
 */
#include "CA_calibrado_y_filtros.h"
#include "CB_Bluetooth.h"
// variables globales para filtros
int  tau=0.075;
int  a=0.0;
int  x_angleC;

int  dtC;
int  k=10;
float  dtc2;
float  x_angle2C;
float x1=0;
float y1=0;
float x2=0;
float y2=0;

int  Q_angle  =  0.01; //0.001
int  Q_gyro   =  0.0003;  //0.003
int  R_angle  =  0.01;  //0.03
int  x_bias = 0;
int  P_00 = 0, P_01 = 0, P_10 = 0, P_11 = 0;
int   y, S;
int  K_0, K_1;
int  x_angle;
int  dt;

void calibrado_inicial(int *calibra_ax,int *calibra_ay,int *calibra_az,int *calibra_gx,int *calibra_gy,int *calibra_gz)
//int &calibra_ax,int &calibra_ay,int &calibra_az,int &calibra_gx,int &calibra_gy,int &calibra_ax
{
    enviar_datos("inicializado...calibrado",20);
int ax,ay,az,gx,gy,gz,a;
char str_blue[40];
int  temp_calibra_ax=0;
ax=ay=az=gx=gy=gz=a=0;
int i = 0;
    strcpy(str_blue,"empezando calibracion");
    enviar_datos_NOCR(str_blue, strlen(str_blue));
  //for de calibracion
  for (i = 0; i < 20; i++){
    itoa(str_blue,temp_calibra_ax, 10);
    enviar_datos(str_blue, strlen(str_blue));
    temp_calibra_ax=get_ax()+temp_calibra_ax;

   }
    strcpy(str_blue,"valor salida = ");
    enviar_datos_NOCR(str_blue, strlen(str_blue));
    itoa(str_blue,temp_calibra_ax, 10);
    enviar_datos(str_blue, strlen(str_blue));

   a =0;
   a=temp_calibra_ax/20;

      strcpy(str_blue,"terminado calibracion");
    enviar_datos_NOCR(str_blue, strlen(str_blue));
        itoa(str_blue,temp_calibra_ax, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));
          strcpy(str_blue," entre 20 = ");
    enviar_datos_NOCR(str_blue, strlen(str_blue));
       itoa(str_blue,a, 10);
    enviar_datos(str_blue, strlen(str_blue));
}


// a=tau / (tau + loop time)
// newAngle = angle measured with atan2 using the accelerometer
// newRate = angle measured using the gyro
// looptime = loop time in millis()


int  Complementary(int  newAngle, int  newRate,int looptime) {
dtC = looptime/1000;
a=tau/(tau+dtC);
x_angleC= a* (x_angleC + newRate * dtC) + (1-a) * (newAngle);
return x_angleC;
}

// newAngle = angle measured with atan2 using the accelerometer
// newRate = angle measured using the gyro
// looptime = loop time in millis()

int  Complementary2(int  newAngle, int  newRate,int looptime) {
enviar_valor("newAngle= ",newAngle);
enviar_valor("newRate= ",newRate);
enviar_valor("looptime= ",looptime);
dtc2=1000/1000.0;
enviar_valor("dtc2= ",(int)dtc2);
x1 = ((float)newAngle -   x_angle2C)*k*k;
enviar_valor("x1= ",(int)x1);
y1 = dtc2*x1 + y1;
enviar_valor("y1= ",(int)y1);
x2 = y1 + (newAngle -   x_angle2C)*2*k + newRate;
enviar_valor("x2= ",(int)x2);
x_angle2C = dtc2*x2 + x_angle2C;
enviar_valor("x_angle2C= ",(int)x_angle2C);


return (int) x_angle2C;
}


// KasBot V1 - Kalman filter module

// newAngle = angle measured with atan2 using the accelerometer
// newRate = angle measured using the gyro
// looptime = loop time in millis()

int  kalmanCalculate(int  newAngle, int  newRate,int looptime)
{
dt = looptime/1000;
x_angle += dt * (newRate - x_bias);
P_00 +=  - dt * (P_10 + P_01) + Q_angle * dt;
P_01 +=  - dt * P_11;
P_10 +=  - dt * P_11;
P_11 +=  + Q_gyro * dt;

y = newAngle - x_angle;
S = P_00 + R_angle;
K_0 = P_00 / S;
K_1 = P_10 / S;

x_angle +=  K_0 * y;
x_bias  +=  K_1 * y;
P_00 -= K_0 * P_00;
P_01 -= K_0 * P_01;
P_10 -= K_1 * P_00;
P_11 -= K_1 * P_01;

return x_angle;
}
