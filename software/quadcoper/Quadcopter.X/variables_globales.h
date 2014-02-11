/* 
 * File:   variables_globales.h
 * Author: pablo
 *
 * Created on 24 de enero de 2014, 1:37
 */

#ifndef VARIABLES_GLOBALES_H
#define	VARIABLES_GLOBALES_H

//*************************************************************
//*********************VARIABLES GLOBALES**********************
//*************************************************************

extern int chanell;
extern int chanel2;
extern int chanel3;
extern int chanel4;
extern int chanel5;



        int chanel1 = 0;
        int chanel2 = 0;
        int chanel3 = 0;
        int chanel4 = 0;
        int chanel5 = 0;


//***********variables del pid********************//

        int KP=1;
        int KD=1;
        int KI=1;
        int BIAS1=1;
        int BIAS2=1;
        int Tmuestreo=1;

//-------------------------------------------------------------
//necesarias por que las inperrupciones no permiten parametros
//-------------------------------------------------------------

#endif	/* VARIABLES_GLOBALES_H */

