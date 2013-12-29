#include "CB_Bluetooth.h"

extern int LSD[12];
extern char str_blue[40];
extern char str_aux[40];



#define DEF_BLUE    1

void EnviarCR()
{
#ifdef DEF_BLUE
    U2TXREG = '\r';
    while(!U2STAbits.TRMT);
    U2TXREG = '\n';
    while(!U2STAbits.TRMT);
#endif
}


void enviar_datos_NOCR(char cadena[50], int longitud)
{
#ifdef DEF_BLUE
    unsigned char index;
    for(index=0; index<longitud; index++)
    {
        U2TXREG = cadena[index];
        while(!U2STAbits.TRMT);
    }
#endif
}
void enviar_datos_NOCR_to_plot(int cadena[50], int longitud)
{
#ifdef DEF_BLUE
    unsigned char index;
    for(index=0; index<longitud; index++)
    {
        U2TXREG = cadena[index];
        while(!U2STAbits.TRMT);
    }
#endif
}





void enviar_Udatos_NOCR(unsigned char cadena[50], int longitud)
{
#ifdef DEF_BLUE
    unsigned char index;
    for(index=0; index<longitud; index++)
    {
        U2TXREG = cadena[index];
        while(!U2STAbits.TRMT);
    }
#endif
}

void enviar_Udatos(unsigned char cadena[50], int longitud)
{
#ifdef DEF_BLUE
    enviar_Udatos_NOCR(cadena, longitud);
    EnviarCR();
#endif
}

void EnviarSensores(int numero)
{
    int i;

    for(i=(numero-1); i>=0; i--)
    {
        itoa(str_blue,LSD[i], 10);
        enviar_datos_NOCR(str_blue, strlen(str_blue));
        strcpy(str_blue," ");
        enviar_datos_NOCR(str_blue, strlen(str_blue));
    }
    EnviarCR();

}


void enviar_valor(char nombre[],int valor)
{

enviar_datos_NOCR(nombre, strlen(nombre));
itoa(str_blue, valor, 10);
enviar_datos(str_blue, strlen(str_blue));

}
