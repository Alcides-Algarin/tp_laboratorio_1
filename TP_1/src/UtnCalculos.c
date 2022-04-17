/*
 * UtnCalculos.c
 *
 *  Created on: Apr 16, 2022
 *      Author: random
 */

#ifndef UTNCALCULOS_C_
#define UTNCALCULOS_C_
#include <stdio.h>
#include <stdlib.h>
#include "UtnCalculos.h"

#define DESCUENTO_DEBITO -0.10
#define INTERES_CREDITO 0.25
#define VALOR_BTC 5990000.0
#define KM_FORZADO 7090
#define PRECIO_LATAM_FORZADO 162965
#define PRECIO_AEROLINEAS_FORZADO 159339
#define REINTENTOS 3


int costoFinal(float importe, float adicional, float *pImporteFinal){

    int exitCode = -1;

    if (pImporteFinal != NULL){
        *pImporteFinal = importe + (importe * adicional);
        exitCode = 0;
    }

    return exitCode;
}


int costoEnBTC(float importe, float valorBTC, float *pPrecioLatamBTC ){

    int exitCode = -1;

    if(pPrecioLatamBTC != NULL){

        *pPrecioLatamBTC = importe / valorBTC;
        exitCode = 0;
    }

    return exitCode;
}


int costoPorKM(float importe, float km, float *precioPorKM){

    int exitCode = -1;

    if(precioPorKM != NULL){
        *precioPorKM = importe / km;
        exitCode = 0;
    }

    return exitCode;
}


int diffPrecios(float importeLatam, float importeAerolineas, float *diferenciaPrecios){

    int exitCode = -1;

    if(diferenciaPrecios != NULL){

        if(importeLatam > importeAerolineas){
            *diferenciaPrecios = importeLatam - importeAerolineas;

        }else{
            *diferenciaPrecios = importeAerolineas - importeLatam;

        }
        exitCode = 0;

    }

    return exitCode;
}


int calculaCostos(int km, float importe, float *importeDebito, float *importeCredito, float *importeBTC, float *importePorKM){

    int exitCode = -1;
    int contadorErrores = 0;

    if(importeDebito != NULL && importeCredito != NULL && importeBTC != NULL && importePorKM != NULL){
        contadorErrores = costoFinal(importe, DESCUENTO_DEBITO, importeDebito);
        contadorErrores += costoFinal(importe, INTERES_CREDITO, importeCredito);
        contadorErrores += costoEnBTC(importe, VALOR_BTC, importeBTC);
        contadorErrores += costoPorKM(importe, km, importePorKM);

        if(contadorErrores == 0){
            exitCode = 0;
        }
    }

    return exitCode;
}

#endif /* UTNCALCULOS_C_ */
