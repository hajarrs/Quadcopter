#include <p30F4013.h>
#include <i2c.h>
#include "CB_Inicializaciones.h"
#include "Defines.h"
#include "CB_Timer1.h"
#include "CB_Timer2.h"
#include "CB_I2C.h"


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
    TRISA = 0xFFFF;                 Delay_Nop(10);
    TRISB = 0xF9F8;                 Delay_Nop(10);
    TRISC = 0b1011111111111111;     Delay_Nop(10);
    TRISD = 0b1111111011110000;     Delay_Nop(10);
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
    unsigned int config2 = 269;      // 50
    /* Configure I2C for 7 bit address mode */
    unsigned int config1 = (I2C_ON & I2C_IDLE_CON & I2C_CLK_HLD &
             I2C_IPMI_DIS & I2C_7BIT_ADD &
             I2C_SLW_DIS & I2C_SM_DIS &
             I2C_GCALL_DIS & I2C_STR_DIS &
             I2C_NACK & I2C_ACK_DIS & I2C_RCV_DIS &
             I2C_STOP_DIS & I2C_RESTART_DIS &
             I2C_START_DIS);
    OpenI2C(config1,config2);
    Delay1msT1(0);

    ByteWrite( MPU6050_I2C_MST_CLK_BIT ,13);
    Delay1msT1(0);
    ByteWrite( MPU6050_RA_PWR_MGMT_1,0x01);	// setFullScaleGyroRange(MPU6050_GYRO_FS_250);
    Delay1msT1(0);
    ByteWrite( MPU6050_RA_GYRO_CONFIG, 0x18);	// setFullScaleGyroRange(MPU6050_GYRO_FS_250);
    Delay1msT1(0);
    ByteWrite( MPU6050_RA_ACCEL_CONFIG,0x18); //   setFullScaleAccelRange(MPU6050_ACCEL_FS_2);
    Delay1msT1(0);
    ByteWrite( MPU6050_RA_FIFO_EN,0xFF);
    Delay1msT1(0);
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

    PR1 = 0x0FFF;
    OC1RS = 0x0500;	// DUCTY CICLE

    PR2 = 0x0FFF;
    OC2RS = 0x0500;	// DUCTY CICLE

    PR3 = 0x0FFF;
    OC3RS = 0x0500;	// DUCTY CICLE

    PR4 = 0x0FFF;
    OC4RS = 0x0500;	// DUCTY CICLE

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
}

void Init_Bluetooh(void)
{
    // Init_Bluetooh();
        U2MODEbits.UARTEN = 1;  Nop();  Nop();  Nop();
        U2STAbits.UTXISEL = 0;  Nop();
        U2MODEbits.PDSEL = 0;   Nop();
        U2MODEbits.STSEL = 0;   Nop();
        U2MODEbits.ABAUD = 0;   Nop();

        U2BRG = 15;              Nop();

        U2STAbits.UTXEN = 1;    Nop();
        IFS1bits.U2RXIF = 0;    Nop();
        IFS1bits.U2TXIF = 0;    Nop();
        IEC1bits.U2RXIE = 0;    Nop();
        IEC1bits.U2TXIE = 0;    Nop();
    // FIN - Init_Bluetooh();
}


void LED_ALL_ON()
{
    LED1 = ON;
    LED2 = ON;
    LED3 = ON;
    LED5 = ON;
    LED6 = ON;
}

void LED_ALL_OFF()
{
    LED1 = OFF;
    LED2 = OFF;
    LED3 = OFF;
    LED5 = OFF;
    LED6 = OFF;
}



