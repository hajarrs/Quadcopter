#include "Bluetooth.h"

extern int LSD[12];
extern char str_blue[40];
extern char str_aux[40];
#define MAX_BLUE    50
#define DEF_BLUE    1

void EnviarCR()
{
#ifdef DEF_BLUE
    U2TXREG = '\r';
    while (!U2STAbits.TRMT);
    U2TXREG = '\n';
    while (!U2STAbits.TRMT);
#endif
}

void enviar_datos_NOCR(char cadena[50], int longitud)
{
#ifdef DEF_BLUE
    unsigned char index;
    for (index = 0; index < longitud; index++)
    {
        U2TXREG = cadena[index];
        while (!U2STAbits.TRMT);
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
    for (index = 0; index < longitud; index++)
    {
        U2TXREG = cadena[index];
        while (!U2STAbits.TRMT);
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

    for (i = (numero - 1); i >= 0; i--)
    {
        itoa(str_blue, LSD[i], 10);
        enviar_datos_NOCR(str_blue, strlen(str_blue));
        strcpy(str_blue, " ");
        enviar_datos_NOCR(str_blue, strlen(str_blue));
    }
    EnviarCR();

}

void enviar_valor(char nombre[], int valor)
{

    enviar_datos_NOCR(nombre, strlen(nombre));
    itoa(str_blue, valor, 10);
    enviar_datos(str_blue, strlen(str_blue));

}

void enviar_valor_NOCR(char nombre[], int valor)
{

    enviar_datos_NOCR(nombre, strlen(nombre));
    itoa(str_blue, valor, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));

}

void enviar_mensaje(char nombre[])
{
    enviar_datos(nombre, strlen(nombre));
}

void enviar_mensaje_NOCR(char nombre[])
{
    enviar_datos_NOCR(nombre, strlen(nombre));
}

// Variables globales
char DatoRecibido[50];
int IndiceBluetooth;

// Funcion de interrupcion de recepcion de datos

void interrupcion _U2RXInterrupt(void)
{

#define AJUSTE_PID
#define DEBUG_PID

#ifdef  AJUSTE_PID

    //***********************ESTE CODIGO ES VALIDO PARA ENVIAR PARAMETROS DESDE PC ******************//
    int i;
    DatoRecibido[IndiceBluetooth] = U2RXREG; // Leemos el valor
    if (IndiceBluetooth < (MAX_BLUE - 1))IndiceBluetooth++;//cada dato qe nos entra le añadimos incrementando el incice

    if (DatoRecibido[IndiceBluetooth - 1] == 0x23) //almuadilla
    {
        //acabamos de recibir una trama completa con los parametros del pid
        IndiceBluetooth--;
        ProcesarCadenaPid(DatoRecibido);
        //la trama esta procesadara y con los parametros modificados.
        
        for (i = 0; i < MAX_BLUE; i++)DatoRecibido[i] = ' ';// Se borra la cadena completa
        IndiceBluetooth = 0;//se incializa la cadena indice

    }

#else

//***********************ESTE CODIGO ES VALIDO PARA ENVIAR JOYTICK ******************//
//*******************VALIDO PARA ANDROID Y PARA EMISORA RADIOCONTROL********************//
    int i;
    unsigned int IntRecibido[50];
    IntRecibido[IndiceBluetooth] = U2RXREG; // Leemos el valor

    if (IndiceBluetooth < (MAX_BLUE - 1))IndiceBluetooth++;
    if (IndiceBluetooth == MAX_BLUE - 1)IndiceBluetooth = 0;
    //comprobacion esta noche
    if ((IntRecibido[IndiceBluetooth ] == 0x15))// && (IntRecibido[IndiceBluetooth - 1 ] == 0xff))// && (IntRecibido[IndiceBluetooth - 1] == 0xFF  )) // Si recibimos intro, procesamos la cadena
    {
        //podemos multiplicar  y dividir  no multiolicar por float

        int chanel1;
        int chanel2;
        int chanel3;
        int chanel4;
        int chanel5;

        chanel1 = ((((IntRecibido[4] << 8) + IntRecibido[5]) - 153)*1.43);
        chanel2 = ((((IntRecibido[6] << 8) + IntRecibido[7]) - 1177)*1.428);
        chanel3 = ((((IntRecibido[8] << 8) + IntRecibido[9]) - 2200)*1.428);
        chanel4 = ((((IntRecibido[10] << 8) + IntRecibido[11]) - 3225)*1.428);
        chanel5 = ((((IntRecibido[12] << 8) + IntRecibido[12]) - 4112)*0.0025);



        chanel1 = ((((IntRecibido[4] << 8) + IntRecibido[5]) - 153)*1.43);
        chanel2 = ((((IntRecibido[6] << 8) + IntRecibido[7]) - 1176)*1.428);
        chanel3 = ((((IntRecibido[8] << 8) + IntRecibido[9]) - 2200)*1.428);
        chanel4 = ((((IntRecibido[10] << 8) + IntRecibido[11]) - 3224)*1.428);
        chanel5 = ((((IntRecibido[12] << 8) + IntRecibido[12]) - 4112)*0.0025);

        //*****************limitar rango ************************//

        enviar_valor("valor1=", (unsigned int) (chanel1));
        enviar_valor("valor2=", (unsigned int) (chanel2));
        enviar_valor("valor3=", (unsigned int) (chanel3));
        enviar_valor("valor4=", (unsigned int) (chanel4));
        enviar_valor("valor6=", (unsigned int) (chanel5));

        enviar_valor("ax", get_ax());
        enviar_valor("ax", get_ax());
        IndiceBluetooth = 0;
        for (i = 0; i < MAX_BLUE; i++)
            IntRecibido[i] = ' ';
        IndiceBluetooth = 0;
        plot4(chanel1, chanel2, chanel3, chanel4);

    }


#endif
    IFS1bits.U2RXIF = 0; // clear TX interrupt flag
    U2STAbits.OERR = 0;
}


// Funcion para procear los datos recibidos

void ProcesarCadenaPid(char *cadena)
{
#ifdef DEF_BLUE
    int i = 0;
    int indice_i = 0;
    int x = 0;
    char aux_P[6];
    char aux_I[6];
    char aux_D[6];
    char aux_BIAS1[6];
    char aux_BIAS2[6];

    do
    {

        if (i > 3)
        {
            if (cadena[i] != 0x26)//ampersan
            {
                if (x == 0)aux_P[indice_i] = cadena[i];
                if (x == 1)aux_I[indice_i] = cadena[i];
                if (x == 2)aux_D[indice_i] = cadena[i];
                if (x == 3)aux_BIAS1[indice_i] = cadena[i];
                if (x == 4)aux_BIAS2[indice_i] = cadena[i];
                indice_i++;
            }
            else
            {
                x++;
                indice_i = 0;
            }
        }
        i++;
    } while (cadena[i] != 0x23);

    //pasamos parametros aux a parametros globales

    KP = atoi(aux_P);
    KI = atoi(aux_I);
    KD = atoi(aux_D);
    BIAS1 = atoi(aux_BIAS1);
    BIAS2 = atoi(aux_BIAS2);
#ifdef  DEBUG_PID
    enviar_mensaje_NOCR("cambiando parametros:");
    enviar_valor_NOCR("p=", atoi(aux_P));
    enviar_valor_NOCR(",i=", atoi(aux_I));
    enviar_valor_NOCR(",d=", atoi(aux_D));
    enviar_valor_NOCR(",aux_BIAS1=", atoi(aux_BIAS1));
    enviar_valor(",aux_BIAS2=", atoi(aux_BIAS2));
#endif

}
#endif

void enviar_datos_int_NOCR(int cadena[50], int _longitud)
{
#ifdef DEF_BLUE
    unsigned char index;
    char aux[1];
    //    itoa(str_blue,_longitud,10);
    //    enviar_datos(str_blue,strlen(str_blue));

    for (index = 0; index < _longitud >> 1; index++)
    {
        aux[0] = cadena[index];
        U2TXREG = aux[0];
        while (!U2STAbits.TRMT);

        aux[0] = cadena[index] >> 8;

        U2TXREG = aux[0];
        while (!U2STAbits.TRMT);
    }
#endif
}
void plot1(int valor1)
{
        int encabezado[3];
        encabezado[0]=0xCDAB;
        encabezado[1]= 2*sizeof(int);
        encabezado[2]=valor1;
        int pktSize = 2 + 2 + (1*sizeof(int));
        enviar_datos_NOCR((int * )encabezado, pktSize);

}
void plot2(int valor1, int valor2)
{
        int encabezado[4];
        encabezado[0]=0xCDAB;
        encabezado[1]= 2*sizeof(int);
        encabezado[2]=valor1;
        encabezado[3]=valor2;
        int pktSize = 2 + 2 + (2*sizeof(int));
        enviar_datos_NOCR((int * )encabezado, pktSize);

}
void plot3(int valor1, int valor2,int valor3)
{
        int encabezado[5];
        encabezado[0]=0xCDAB;
        encabezado[1]= 3*sizeof(int);
        encabezado[2]=valor1;
        encabezado[3]=valor2;
        encabezado[4]=valor3;
        int pktSize = 2 + 2 + (3*sizeof(int));
        enviar_datos_NOCR((int * )encabezado, pktSize);

}
void plot4(int valor1, int valor2,int valor3,int valor4)
{
        int encabezado[6];
        encabezado[0]=0xCDAB;
        encabezado[1]= 4*sizeof(int);
        encabezado[2]=valor1;
        encabezado[3]=valor2;
        encabezado[4]=valor3;
        encabezado[5]=valor4;
        int pktSize = 2 + 2 + (4*sizeof(int));
        enviar_datos_NOCR((int * )encabezado, pktSize);

}