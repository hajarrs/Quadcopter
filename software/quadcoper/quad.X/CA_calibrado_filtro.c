/* 
 * File:   calibrado_filtro.c
 * Author: pablo
 *
 * Created on 20 de diciembre de 2013, 0:25
 */
#include "CA_calibrado_filtro.h"


void calibrado_inicial()
//int &calibra_ax,int &calibra_ay,int &calibra_az,int &calibra_gx,int &calibra_gy,int &calibra_ax
{
int calibra_ax,calibra_ay,calibra_az,calibra_gx,calibra_gy,calibra_gz,ax,ay,az,gx,gy,gz;
calibra_ax=calibra_ay=calibra_az=calibra_gx=calibra_gy=calibra_gz=ax=ay=az=gx=gy=gz=0;
int i = 0;

  //for de calibracion
  for (i = 0; i > 100; i++){
//    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    ax=get_ax()+calibra_ax;
    ay=get_ay()+calibra_ay;
    az=get_az()+calibra_az;
    gx=get_gx()+calibra_gx;
    gy=get_gy()+calibra_gy;
    gz=get_gz()+calibra_gz;
   }
  calibra_ax=calibra_ax/100;
  calibra_ay=calibra_ay/100;
  calibra_az=calibra_az/100;
  calibra_gx=calibra_gx/100;
  calibra_gy=calibra_gy/100;
  calibra_gz=calibra_gz/100;

}
