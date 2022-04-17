/*
 * UtnInputOutput.c
 *
 *  Created on: Apr 16, 2022
 *      Author: random
 */

#ifndef UTNINPUTOUTPUT_C_
#define UTNINPUTOUTPUT_C_
#include <stdio.h>
#include <stdlib.h>
#include "UtnInputOutput.h"

#define DESCUENTO_DEBITO -0.10
#define INTERES_CREDITO 0.25
#define VALOR_BTC 5990000.0
#define KM_FORZADO 7090
#define PRECIO_LATAM_FORZADO 162965
#define PRECIO_AEROLINEAS_FORZADO 159339
#define REINTENTOS 3

void printMenuppal(){

	printf("# 1   Ingresar Kilómetros.\n");
	printf("# 2   Ingresar Precio de Vuelos.\n");
	printf("# 3   Calcular todos los costos:\n");
	printf("# 4   Informar resultados:\n");
	printf("# 5   Carga forzada de datos:\n");
	printf("# 6   Salir:\n");
}

void printResultados(char *nombre, float precioDebito, float precioCredito, float precioBTC, float precioPorKm){

    printf("%s:\n", nombre);
    printf("a) Precio con tarjeta de débito: $ %.2f\n", precioDebito);
    printf("b) Precio con tarjeta de crédito: $ %.2f\n", precioCredito);
    printf("c) Precio pagando con bitcoin: %f BTC\n", precioBTC);
    printf("d) Precio por KM: $ %.2f\n\n", precioPorKm);

}

int utn_getFloat( float *pInput, char *message, float minimo, float maximo, int reintentos){
    //Ocurre algo muy extraño. Cuando ingreso un dato por primera vez, e ingreso letras lo acepta y no se rompe.
    // A la segunda iteracion ya no lo hace.

    int exitCode = -1;
    float auxInput=-1;//Esto evita que en la primera iteracion, el programa continue.
    reintentos++;

    if(pInput != NULL && message != NULL && reintentos >= 0 && maximo >= minimo){
        do{

            printf("%s", message);
            scanf("%f", &auxInput);
            while(getchar()!='\n');

            if(auxInput >= minimo && auxInput <= maximo){
                *pInput = auxInput;
                exitCode = 0;
                break;

            }else{
                reintentos--;

                if(reintentos > 0){
                    printf("El valor ingresado no es valido. Reintentos: %d\n\n\n", reintentos);

                }else{
                    exitCode = -1;
                    printf("\nEl valor ingresado no es valido.\nAgotaste todos los intentos permitidos.\nVuelva a intentarlo mas tarde.\n\n\n");
                    //systemPause();
                }

		    }
        }while(reintentos != 0);
    }

    return exitCode;
}

int utn_getInt( int *pInput, char *message, int minimo, int maximo, int reintentos){

    int exitCode = -1;
    int auxInput;
    reintentos++;

    if(pInput != NULL && message != NULL && reintentos >= 0 && maximo >= minimo){
        do{

            printf("%s ", message);
            scanf("%d", &auxInput);
            while(getchar()!='\n');

            if(auxInput >= minimo && auxInput <= maximo){
                *pInput = auxInput;
                exitCode = 0;
                break;

            }else{
                reintentos--;

                if(reintentos > 0){
                    printf("El valor ingresado no es valido. Reintentos: %d\n\n\n", reintentos);

                }else{
                    exitCode = -1;
                    printf("\nEl valor ingresado no es valido.\nAgotaste todos los intentos permitidos.\nVuelva a intentarlo mas tarde.\n\n\n");
                    //systemPause();
                }

		    }
        }while(reintentos != 0);
    }

    return exitCode;
}

void setKilometros(float *km, int *flagKM){

    int returnFuntion;
    int option;

    if(*flagKM == 0){
        returnFuntion = utn_getFloat(km, "Ingrese los Km: ",0,1000000,REINTENTOS);
        if(returnFuntion == 0){

            *flagKM = 1;
            printf("Se guardo correctamente.\n");
        }
        systemPause();

    }else{

        printf("KM actuales: %.2f\n\n# 1 Modificar\n# 2 Volver al menu Principal\n\n", *km);
        returnFuntion = utn_getInt(&option, "Ingrese el nro de opcion: ", 1, 2, REINTENTOS);

        if(returnFuntion == 0){
            system("clear");
            printTitleChoice(option);

            switch(option){
                case 1:
                    printf("KM actuales: %.2f\n\n", *km);
                    returnFuntion = utn_getFloat(km, "Ingrese nuevo valor: ", 0, 1000000, REINTENTOS);
                    if(returnFuntion == 0){
                        *flagKM = 1;
                        printf("Se Actualizo correctamente.\n");
                    }else{
                        printf("No se pudo modificar el valor. Por favor intente mas tarde.");
                    }
                    systemPause();
                    break;
                case 2:
                    break;
            }
        }

    }

}



void setPrecios(int *flagAerolineas, int *flagLatam, float *importeAerolineas, float *importeLatam){

    int returnFuntion;
    int option;

    if(*flagAerolineas == 0 && *flagLatam == 0){

        returnFuntion = utn_getFloat(importeAerolineas, "Ingrese precio Aerolineas: ", 0, 10000000, REINTENTOS);
        if(returnFuntion == 0){

            returnFuntion = utn_getFloat(importeLatam, "Ingrese precio Latam: ", 0, 10000000, REINTENTOS);
            if(returnFuntion == 0){

                *flagLatam = 1;
                *flagAerolineas = 1;

                printf("Se guardo con exito los valores ingresados.\n\n");
            }
        }
        systemPause();

    }else{

        do{
            printf("Valores actuales\nAerolineas: %.2f\nLatam: %.2f\n\n# 1 Modificar precio Aerolineas\n# 2 Modificar precio Latam\n# 3 Volver al menu Principal\n\n", *importeAerolineas, *importeLatam);
            returnFuntion = utn_getInt(&option, "Ingrese el nro de opcion para continuar: ", 1, 3, REINTENTOS);

            if(returnFuntion == 0){
                system("clear");
                printTitleChoice(option);

                switch(option){
                    case 1:
                        printf("Precio actual Aerolineas: $%.2f\n\n", *importeAerolineas);
                        returnFuntion = utn_getFloat(importeAerolineas, "Ingrese nuevo valor para Aerolineas: ", 0, 10000000, REINTENTOS);
                        if(returnFuntion == 0){
                            printf("Se guardo correctamente.\n");
                        }else{
                            printf("No se pudo modificar el valor.\n");
                        }
                        break;
                    case 2:
                        printf("Precio actual Latam: $%.2f\n\n", *importeLatam);
                        returnFuntion = utn_getFloat(importeLatam, "Ingrese nuevo valor para Latam: ", 0, 10000000, REINTENTOS);
                        if(returnFuntion == 0){
                            printf("Se guardo correctamente.\n");
                        }else{
                            printf("No se pudo modificar el valor. \n");
                        }
                        break;
                    case 3:
                        break;
                }
            }
            systemPause();

        }while(option != 3 && returnFuntion != -1);

    }
}

void printTitleChoice(int numOption){
	printf("\t#####################\n\t# Elegiste Opcion %d #\n\t#####################\n\n", numOption);

}

void systemPause(){
    printf("Presione enter para volver al Menu principal");
    while(getchar()!='\n');
}


#endif /* UTNINPUTOUTPUT_C_ */
