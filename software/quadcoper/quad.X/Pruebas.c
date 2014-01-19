#include <p30F4013.h>


#include "Pruebas.h"

void Prueba2_PWM(void)
{
       PWM1 = 32500;
       PWM2 = 32500;
       PWM3 = 32500;
       PWM4 = 32500;
}

void PWM_prueba(void)
{
 int Stop = 0;
    while(Stop == 0)
    {
       PWM4+=1;
       PWM3+=1;
       PWM2+=1;
       PWM1+=1;
       Delay_Nop(5000);


       if(PWM4 >= 0x0FFC)
       {
           PWM4 = 0x0FFF;
           PWM3 = 0x0FFF;
           PWM2 = 0x0FFF;
           PWM1 = 0x0FFF;
      // LEDROJO = 1;
           Stop = 1;
       }
    }
    while(Stop == 1)
    {

       PWM4-=1;
       PWM3-=1;
      PWM2-=1;
       PWM1-=1;
       Delay_Nop(5000);



       if(PWM4 <= 0x0070)
       {
           PWM4 = 0;
           PWM3 = 0;
           PWM2 = 0;
           PWM1 = 0;
// LEDROJO = 0;
           Stop = 0;
       }
    }
}

void Prueba_PWM(void)
{
    int i;

    for (i=0;i>0xffff;i++)
    {
       PWM4=i;
       PWM3=i;
       PWM2=i;
       PWM1=i;
       Delay_Nop(5000);

    }
          for (i=0xffff;i<0x0001;i--)
    {
       PWM4=i;
       PWM3=i;
       PWM2=i;
       PWM1=i;
       Delay_Nop(5000);
}
}
void Prueba_Bluetooth_2(char *cadena)
{
    strcpy(str_blue,cadena);
    enviar_datos(str_blue, strlen(str_blue));
    Delay_Nop(5000);
}


void Prueba_Bluetooth(void)
{
//    U2BRG++;

    itoa(str_blue,U2BRG, 10);
    enviar_datos(str_blue, strlen(str_blue));
    itoa(str_blue,U2BRG, 10);
    enviar_datos(str_blue, strlen(str_blue));
    itoa(str_blue,U2BRG, 10);
    enviar_datos(str_blue, strlen(str_blue));
    itoa(str_blue,U2BRG, 10);
    enviar_datos(str_blue, strlen(str_blue));
    strcpy(str_blue,"HOLA QUE TAL ESTAS yo estoy muy bien y tu que tal");
    enviar_datos(str_blue, strlen(str_blue));
    Delay_Nop(5000);
    enviar_datos(str_blue, strlen(str_blue));
    Delay_Nop(5000);
    enviar_datos(str_blue, strlen(str_blue));
    Delay_Nop(5000);
    enviar_datos(str_blue, strlen(str_blue));
    Delay_Nop(5000);
    enviar_datos(str_blue, strlen(str_blue));
    Delay_Nop(5000);
    enviar_datos(str_blue, strlen(str_blue));
    Delay_Nop(5000);
    enviar_datos(str_blue, strlen(str_blue));
    Delay_Nop(5000);
    enviar_datos(str_blue, strlen(str_blue));
    Delay_Nop(5000);
}





void Prueba_I2C(void)
{
    
    IdleI2C();					//wait for bus Idle
    StartI2C();					//Generate Start Condition
    while(I2CCONbits.SEN );

    my_Write_I2C(0xD0);		//Write Control Byte
    while(I2CSTATbits.ACKSTAT);

    IdleI2C();			//wait for bus Idle

    my_Write_I2C(0x75);		//Write start address
    while(I2CSTATbits.ACKSTAT);
    IdleI2C();			//wait for bus Idle

    //RestartI2C();			//Generate restart condition

    I2CCONbits.RSEN=1;
    Nop();
    while(I2CCONbits.RSEN);



    my_Write_I2C(0xD1);                //Write control byte for read
    while(I2CSTATbits.ACKSTAT);

    IdleI2C();			//wait for bus Idle


    //    getsi2cdatalaunch()
    I2CCONbits.RCEN = 1;			//Enable Master receive

    while(!I2CSTATbits.RBF);		//Wait for receive bufer to be full

    NotAckI2C();			//Send Not Ack

    StopI2C();			//Generate Stop
    while(I2CCONbits.PEN);


   return;

}

void my_ftoa(float Value, char* Buffer)
 {
     union
     {
         float f;

         struct
         {
             unsigned int    mantissa_lo : 16;
             unsigned int    mantissa_hi : 7;
             unsigned int     exponent : 8;
             unsigned int     sign : 1;
         };
     } helper;

     unsigned long mantissa;
     signed char exponent;
     unsigned int int_part;
     char frac_part[3];
     int i, count = 0;

     helper.f = Value;
     //mantissa is LS 23 bits
     mantissa = helper.mantissa_lo;
     mantissa += ((unsigned long) helper.mantissa_hi << 16);
     //add the 24th bit to get 1.mmmm^eeee format
     mantissa += 0x00800000;
     //exponent is biased by 127
     exponent = (signed char) helper.exponent - 127;

     //too big to shove into 8 chars
     if (exponent > 18)
     {
         Buffer[0] = 'I';
         Buffer[1] = 'n';
         Buffer[2] = 'f';
         Buffer[3] = '\0';
         return;
     }

     //too small to resolve (resolution of 1/8)
     if (exponent < -3)
     {
         Buffer[0] = '0';
         Buffer[1] = '\0';
         return;
     }

     count = 0;

     //add negative sign (if applicable)
     if (helper.sign)
     {
         Buffer[0] = '-';
         count++;
     }

     //get the integer part
     int_part = mantissa >> (23 - exponent);
     //convert to string
     my_itoa(int_part, &Buffer[count]);

     //find the end of the integer
     for (i = 0; i < 8; i++)
         if (Buffer[i] == '\0')
         {
             count = i;
             break;
         }

     //not enough room in the buffer for the frac part
     if (count > 5)
         return;

     //add the decimal point
     Buffer[count++] = '.';

     //use switch to resolve the fractional part
     switch (0x7 & (mantissa  >> (20 - exponent)))
     {
         case 0:
             frac_part[0] = '0';
             frac_part[1] = '0';
             frac_part[2] = '0';
             break;
         case 1:
             frac_part[0] = '1';
             frac_part[1] = '2';
             frac_part[2] = '5';
             break;
         case 2:
             frac_part[0] = '2';
             frac_part[1] = '5';
             frac_part[2] = '0';
             break;
         case 3:
             frac_part[0] = '3';
             frac_part[1] = '7';
             frac_part[2] = '5';
             break;
         case 4:
             frac_part[0] = '5';
             frac_part[1] = '0';
             frac_part[2] = '0';
             break;
         case 5:
             frac_part[0] = '6';
             frac_part[1] = '2';
             frac_part[2] = '5';
             break;
         case 6:
             frac_part[0] = '7';
             frac_part[1] = '5';
             frac_part[2] = '0';
             break;
         case 7:
             frac_part[0] = '8';
             frac_part[1] = '7';
             frac_part[2] = '5';
             break;
     }

     //add the fractional part to the output string
     for (i = 0; i < 3; i++)
         if (count < 7)
             Buffer[count++] = frac_part[i];

     //make sure the output is terminated
     Buffer[count] = '\0';
 }


/* itoa:  convert n to characters in s */
void my_itoa(long n, char s[])
{
     int i;
	 long sign;

     if ((sign = n) < 0)  /* record sign */
         n = -n;          /* make n positive */
     i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0';   /* get next digit */
     } while ((n /= 10) > 0);     /* delete it */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
}


/* reverse:  reverse string s in place */
void reverse(char s[])
{
     int i, j;
     char c;

     for (i = 0, j = strlen(s)-1; i<j; i++, j--)
	 {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
}

void EjecutarPID(void)
{

}

void prueba_who_i_am(void)
{
    ACT_ACE=1;
    int i=0;
    DelayXmsT1(50);
        int WhoIAm=get_who_I_AM();
        if (WhoIAm == 104)
        {
            LEDAZUL=1;
            LEDROJO=0;
            enviar_valor("correcto", i);

        }
        else
        {
            enviar_valor("who i am =", WhoIAm);
            i++;
            enviar_valor("error", i);
            if (i==5)
            {
                i =0;
            ACT_ACE=0;
            LEDROJO=1;
            LEDAZUL=0;
            DelayXmsT1(1000);
            ACT_ACE=1;
            }

        }
    }






