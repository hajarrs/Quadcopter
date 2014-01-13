#include "CB_Bluetooth.h"

extern int LSD[12];
extern char str_blue[40];
extern char str_aux[40];
#define MAX_BLUE    50
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

void enviar_datos(char cadena[50], int longitud)
{
#ifdef DEF_BLUE
    enviar_datos_NOCR(cadena, longitud);
    EnviarCR();
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
void enviar_mensaje(char nombre[])
{
enviar_datos(nombre, strlen(nombre));
}


// Variables globales
char DatoRecibido[50];
int IndiceBluetooth;

// Funcion de interrupcion de recepcion de datos

void interrupcion _U2RXInterrupt(void) {
    int i;
    unsigned char index;
    DatoRecibido[IndiceBluetooth] = U2RXREG; // Leemos el valor

    if (IndiceBluetooth < (MAX_BLUE - 1))IndiceBluetooth++;
    if (IndiceBluetooth==MAX_BLUE-1)IndiceBluetooth=0;
    if ((DatoRecibido[IndiceBluetooth ] == 0x00) && (DatoRecibido[IndiceBluetooth - 1] == 0x00))// && (DatoRecibido[IndiceBluetooth - 1] == 0xFF  )) // Si recibimos intro, procesamos la cadena
        {

            for(index=0; index<IndiceBluetooth; index++)
            {
                U2TXREG = DatoRecibido[index];
                while(!U2STAbits.TRMT);
            }
            IndiceBluetooth=0;
            for (i = 0; i < MAX_BLUE; i++)
                DatoRecibido[i] = ' ';
            IndiceBluetooth = 0;
        } 
 
 
  
    IFS1bits.U2RXIF = 0; // clear TX interrupt flag
    U2STAbits.OERR = 0;
}


// Funcion para procear los datos recibidos
void ProcesarCadena(char *cadena)
{
#ifdef DEF_BLUE
    if(strncmp(cadena,"@GO",3) == 0)
    {
        StartPID(); // Arrancamos el PID
        return;
    }
    if(strncmp(cadena,"@STOP",3) == 0)
    {
        StopPID();  // Paramos el PID
        // PARAR_MOTORES
        return;
    }
    if(strncmp(cadena,"@CR",3) == 0)   // Peticion de envio de Retorno de carro
    {
        EnviarCR();
        return;
    }

    strcpy(str_blue,"Recibido: ");
   // enviar_datos_NOCR(str_blue, strlen(str_blue));
    strcpy(str_blue,cadena);
    enviar_datos(str_blue, strlen(str_blue));

#endif
}