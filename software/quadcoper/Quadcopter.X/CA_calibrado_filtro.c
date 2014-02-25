/* 
 * File:   calibrado_filtro.c
 * Author: pablo
 *
 * Created on 20 de diciembre de 2013, 0:25
 */
#include "CA_calibrado_filtro.h"
#include "CB_Bluetooth.h"


void calibrado_inicial(int *calibra_ax,int *calibra_ay,int *calibra_az,int *calibra_gx,int *calibra_gy,int *calibra_gz)
//int &calibra_ax,int &calibra_ay,int &calibra_az,int &calibra_gx,int &calibra_gy,int &calibra_ax
{
    enviar_datos("inicializado...calibrado",20);
int ax,ay,az,gx,gy,gz,a;
char str_blue[40];
float temp_calibra_ax=0;
ax=ay=az=gx=gy=gz=a=0;
int i = 0;

  //for de calibracion
  for (i = 0; i < 20; i++){


   }

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
