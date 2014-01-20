

#include "CB_Inicializaciones.h"
//#define RECEP


/** Funcion Init_Hw
 * Input: void
 * Output: void
 * Desciption: Inicializa los valores de los registros basicos del PIC:
 * OSCTUN, ANSEL, ADPCFG, TRISx, PORTx,
 */
void Init_Hw(void)
{
    OSCTUN = 0b0000;    Delay_Nop(10);  // 118 MHz

    // ANSELx
    ADPCFG = 0xFFFF;    Delay_Nop(10);  // Digital

    // TRISx
    TRISA = 0x1111011111111111;     Delay_Nop(10);
    TRISB = 0xF9F8;                 Delay_Nop(10);
    TRISC = 0b1011111111111111;     Delay_Nop(10);
    TRISD = 0b1011111011110000;     Delay_Nop(10);
    TRISF = 0b1111111110011100;     Delay_Nop(10);


    // PORTx
    PORTA = 0;      Delay_Nop(10);
    PORTB = 0;      Delay_Nop(10);
    PORTC = 0;      Delay_Nop(10);
    PORTD = 0;      Delay_Nop(10);
    PORTF = 0;      Delay_Nop(10);
}



void Init_I2C(void)
{
    Delay_Nop(50000);

    /* Baud rate is set for 400 kHz */
//    unsigned int config2 =74;      // 74//269      // 186 son 400 khz
    /* Configure I2C for 7 bit address mode */
//    unsigned int config1 = (I2C_ON & I2C_IDLE_CON & I2C_CLK_HLD &
//             I2C_IPMI_DIS & I2C_7BIT_ADD &
//             I2C_SLW_DIS & I2C_SM_DIS &
//             I2C_GCALL_DIS & I2C_STR_DIS &
//             I2C_NACK & I2C_ACK_DIS & I2C_RCV_DIS &
//             I2C_STOP_DIS & I2C_RESTART_DIS &
//             I2C_START_DIS);
//    OpenI2C(config1,config2);
    Delay1msT1(0);

    I2CBRG = 283;//correcto 283//otra 60

    I2CCONbits.I2CSIDL = 0; Nop();
    I2CCONbits.SCLREL = 1; Nop();
    I2CCONbits.IPMIEN = 0; Nop();
    I2CCONbits.A10M = 0; Nop();
    I2CCONbits.DISSLW = 0; Nop();
    I2CCONbits.SMEN = 0; Nop();
    I2CCONbits.GCEN = 0; Nop();
    I2CCONbits.STREN = 0; Nop();
    I2CCONbits.ACKDT = 0; Nop();
    I2CCONbits.ACKEN = 0; Nop();
    I2CCONbits.RCEN = 0; Nop();
    I2CCONbits.PEN = 0; Nop();
    I2CCONbits.RSEN = 0; Nop();
    I2CCONbits.SEN = 0; Nop();


    Delay1msT1(0);

    I2CCONbits.I2CEN = 1;


    
    set_inicial();

}



// Config OK - Check con osciloscopio.
void Init_PWM()
{
    OC1CONbits.OCM0 = 0;    Nop();
    OC1CONbits.OCM1 = 0;    Nop();
    OC1CONbits.OCM2 = 0;    Nop();
    OC1CONbits.OCTSEL =0;   Nop();	// TIMER2

    OC2CONbits.OCM0 = 0;    Nop();
    OC2CONbits.OCM1 = 0;    Nop();
    OC2CONbits.OCM2 = 0;    Nop();
    OC2CONbits.OCTSEL =0;   Nop();	// TIMER2

    OC3CONbits.OCM0 = 0;    Nop();
    OC3CONbits.OCM1 = 0;    Nop();
    OC3CONbits.OCM2 = 0;    Nop();
    OC3CONbits.OCTSEL =0;   Nop();	// TIMER2

    OC4CONbits.OCM0 = 0;    Nop();
    OC4CONbits.OCM1 = 0;    Nop();
    OC4CONbits.OCM2 = 0;    Nop();
    OC4CONbits.OCTSEL =0;   Nop();	// TIMER2

    T2CONbits.TON = 0;      Nop();
    T2CONbits.TSIDL = 0;    Nop();
    T2CONbits.TGATE = 0;    Nop();
    T2CONbits.TCS = 0;      Nop();
    T2CONbits.T32 = 0;      Nop();      // TIMER2 --> 16 Bits
    IFS0bits.T2IF = 0;      Nop();

    PR1 =0xf000;
    OC1RS = 0x0000;	// DUCTY CICLE

    PR2 = 0xf000;
    OC2RS = 0x0000;	// DUCTY CICLE

    PR3 = 0xf000;
    OC3RS = 0x0000;	// DUCTY CICLE

    PR4 = 0xf000;
    OC4RS = 0x0000;	// DUCTY CICLE

    OC1CONbits.OCM0 = 0;    Nop();
    OC1CONbits.OCM1 = 1;    Nop();
    OC1CONbits.OCM2 = 1;    Nop();

    OC2CONbits.OCM0 = 0;    Nop();
    OC2CONbits.OCM1 = 1;    Nop();
    OC2CONbits.OCM2 = 1;    Nop();

    OC3CONbits.OCM0 = 0;    Nop();
    OC3CONbits.OCM1 = 1;    Nop();
    OC3CONbits.OCM2 = 1;    Nop();

    OC4CONbits.OCM0 = 0;    Nop();
    OC4CONbits.OCM1 = 1;    Nop();
    OC4CONbits.OCM2 = 1;    Nop();


    T2CONbits.TCKPS = 0b00; Nop();
    T2CONbits.TON = 1;


    PWM1 = 0;
    PWM2 = 0;
    PWM3 = 0;
    PWM4 = 0;
}

void Init_Bluetooh(void)
{

        U2MODEbits.UARTEN = 1;  Nop();  Nop();  Nop();
        U2STAbits.UTXISEL = 0;  Nop();
        U2STAbits.URXISEL = 0;  Nop();
        U2MODEbits.PDSEL = 0;   Nop();
        U2MODEbits.STSEL = 0;   Nop();
        U2MODEbits.ABAUD = 0;   Nop();

        U2BRG = 15;              Nop();

        U2STAbits.UTXEN = 1;    Nop();
        IFS1bits.U2RXIF = 0;    Nop();
        IFS1bits.U2TXIF = 0;    Nop();
#ifdef  RECEP
    IEC1bits.U2RXIE = 1;    Nop();
#else
        IEC1bits.U2RXIE = 0;    Nop();
#endif
        IEC1bits.U2TXIE = 0;    Nop();
    // FIN - Init_Bluetooh();
}


void LED_ALL_ON()
{
    LEDROJO = ON;

    
    LEDAZUL= ON;

}

void LED_ALL_OFF()
{
    LEDROJO = OFF;

    LEDAZUL= OFF;


}
void clockSwitch (unsigned int newNOSCCode)
{
        int current_cpu_ipl;                            /* Declare temp variable for storing CPU IPL */
        int newOSCCONHCode;
        char a, b, c, *p;

        newOSCCONHCode = OSCCON;
        newOSCCONHCode = newOSCCONHCode & ZERO_MASK_FOR_NOSC_IN_OSCCON;
        newOSCCONHCode = newOSCCONHCode >> 8;

        switch (newNOSCCode)
        {
                case NOSC_LP: newOSCCONHCode = newOSCCONHCode | newNOSCCode ;
                        	  break;
                case NOSC_FRC: newOSCCONHCode = newOSCCONHCode | newNOSCCode ;
                          	   break;
                case NOSC_LPRC: newOSCCONHCode = newOSCCONHCode | newNOSCCode ;
                        	    break;
                case NOSC_EXTOSC: newOSCCONHCode = newOSCCONHCode | newNOSCCode ;
                        	      break;
                case NOSC_PLLOSC: newOSCCONHCode = newOSCCONHCode | newNOSCCode ;
                        	  	  break;
                default: return;
        }

        b = OSCCONH_UNLOCK_CODE1;                       /* Load OSCCONH unlock sequence parameters */
        c = OSCCONH_UNLOCK_CODE2;
        p = (char *)&OSCCON + 1;

        SET_AND_SAVE_CPU_IPL(current_cpu_ipl, 7);       /* Disable interrupts for unlock sequence below */

        /* Perform OSCCONH unlock sequence and write the new oscillator value to the NOSC bits */
        asm volatile ("mov.b %1,[%0] \n"
                  "mov.b %2,[%0] \n"
                  "mov.b %3,[%0] \n" : /* no outputs */ : "r"(p), "r"(b), "r"(c),
                                                          "r"(newOSCCONHCode));

        b = OSCCONL_UNLOCK_CODE1;                       /* Load OSCCONL unlock sequence parameters */
        c = OSCCONL_UNLOCK_CODE2;
        p = (char *)&OSCCON;
        a = OSCCON | 0x01;

        /* Perform OSCCONL unlock sequence and request an Oscillator switch by setting OSWEN bit */
        asm volatile ("mov.b %1,[%0] \n"
                  "mov.b %2,[%0] \n"
                  "mov.b %3,[%0] \n" : /* no outputs */ : "r"(p), "r"(b), "r"(c),
                                                          "r"(a));
        while (OSCCONbits.OSWEN);                       /* Wait until OSWEN has been cleared by hardware */

        RESTORE_CPU_IPL(current_cpu_ipl);               /* Restore CPU IPL value after executing unlock sequence */
}
void Init_Pll(void)
{
    int i;
    //    char mycadena[50];

    for (i = 0; i < 50; i++);
    Delay1msT1(0);

    clockSwitch(NOSC_PLLOSC);
    Delay_Nop(1500);
}

