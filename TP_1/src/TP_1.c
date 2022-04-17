/*
 ============================================================================
 Name        : TP_1.c
 Author      : Alcides Algarin  1-E
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 ============================================================================
 */



#define DESCUENTO_DEBITO -0.10
#define INTERES_CREDITO 0.25
#define VALOR_BTC 5990000.0
#define KM_FORZADO 7090
#define PRECIO_LATAM_FORZADO 162965
#define PRECIO_AEROLINEAS_FORZADO 159339
#define REINTENTOS 3

#include <stdio.h>
#include <stdlib.h>
#include "UtnCalculos.h"
#include "UtnInputOutput.h"
// ####################### MAIN #######################
int main(void) {

    
	
	int resultFuntion;
    int option;

    float km;

    float precioAerolineasArg;
    float precioAerolineasCredito;
    float precioAerolineasDebito;
    float precioAerolineasBTC;
    float precioAerolineasPorKm;

    float precioLatam;
    float precioLatamDebito;
    float precioLatamCredito;
    float precioLatamBTC;
    float precioLatamPorKm;

    float diferenciaPrecios;

    int calculosOk=0;
    int flagKM = 0;
    int flagPrecioLatam = 0;
    int flagPrecioAerolineas = 0;


	do{

		system("clear");
		printMenuppal();

		resultFuntion = utn_getInt(&option, "Ingrese el nro de opcion: ", 1, 6, REINTENTOS);

        system("clear");
        switch (option) {
            
            case 1:
                printTitleChoice(option);
                setKilometros(&km, &flagKM);
                break;

            case 2:
                printTitleChoice(option);
                setPrecios(&flagPrecioAerolineas, &flagPrecioLatam, &precioAerolineasArg, &precioLatam);
                break;

            case 3:
                printTitleChoice(option);
                if(flagKM && flagPrecioLatam && flagPrecioAerolineas){

                    resultFuntion = calculaCostos(km, precioAerolineasArg, &precioAerolineasDebito, &precioAerolineasCredito, &precioAerolineasBTC, &precioAerolineasPorKm);
                    resultFuntion += calculaCostos(km, precioLatam, &precioLatamDebito, &precioLatamCredito, &precioLatamBTC, &precioLatamPorKm);
                    resultFuntion = diffPrecios(precioLatam, precioAerolineasArg, &diferenciaPrecios);

                    if(!resultFuntion){
                        printf("Calcular todos los costos se ejecuto con exito.\n\n");
                        calculosOk = 1;
                    }else{
                        printf("Hubo un error inesperado al intentar calcular costo\n\n");
                    }
                }else{
                    printf("No es posible calcular costos si no se ingresan datos.\nPor favor vuelva al menu principal y seleccione las opciones 1 y 2.\n\n");
                }
                
                systemPause();
                break;

            case 4:
                printTitleChoice(option);
                if(calculosOk){
                    printResultados("Latam", precioLatamDebito, precioLatamCredito, precioLatamBTC, precioLatamPorKm);
                    printResultados("Aerolineas", precioAerolineasDebito, precioAerolineasCredito, precioAerolineasBTC, precioAerolineasPorKm);


                    printf("La diferencia de precio es: $ %.2f\n", diferenciaPrecios);
                    
                }else{
                    printf("No hay resultados para mostar.\nPor favor vuelva al menu principal y ejecute la opcion 3.\n\n");
                }
                systemPause();

                break;

            case 5:
                printTitleChoice(option);

                resultFuntion = calculaCostos(KM_FORZADO, PRECIO_AEROLINEAS_FORZADO, &precioAerolineasDebito, &precioAerolineasCredito, &precioAerolineasBTC, &precioAerolineasPorKm);
                resultFuntion += calculaCostos(KM_FORZADO, PRECIO_LATAM_FORZADO, &precioLatamDebito, &precioLatamCredito, &precioLatamBTC, &precioLatamPorKm);

                resultFuntion += diffPrecios(PRECIO_LATAM_FORZADO, PRECIO_AEROLINEAS_FORZADO, &diferenciaPrecios);


                printResultados("Latam", precioLatamDebito, precioLatamCredito, precioLatamBTC, precioLatamPorKm);
                printResultados("Aerolineas", precioAerolineasDebito, precioAerolineasCredito, precioAerolineasBTC, precioAerolineasPorKm);

                printf("La diferencia de precio es: $ %.2f\n", diferenciaPrecios);

                systemPause();
                break;

            case 6:
                break;
        }


	}while(option != 6);

	return EXIT_SUCCESS;
}










