/*
 ============================================================================
 Name        : TP_1.c
 Author      : Alcides Algarin  1-E
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Manipular consola linux:

	system("clear");Limpia terminal en linux

 Vaciar buffer
 while(getchar()!='\n');


	getchar();
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define DESCUENTO_DEBITO -0.10
#define INTERES_CREDITO 0.25
#define VALOR_BTC 5990000.0
#define KM_FORZADO 7090
#define PRECIO_LATAM_FORZADO 162965
#define PRECIO_AEROLINEAS_FORZADO 159339
#define REINTENTOS 3


int utn_getFloat(float *pInput, char *message, float minimo, float maximo, int reintentos);
int utn_getInt(int *pInput, char *message, int minimo, int maximo, int reintentos);
int costoFinal(float importe, float adicional, float *pImporteFinal);
int costoEnBTC(float importe, float valorBTC, float *pImporteFinalBTC);
int costoPorKM(float importe, float km, float *precioPorKM);
int diffPrecios(float importeLatam, float importeAerolineas, float *diferenciaPrecios);
void printResultados(char *nombre, float precioDebito, float precioCredito, float precioBTC, float precioPorKm);
void printMenuppal();
void systemPause();
void printTitleChoice(int);
void setKilometros(float *km, int *flagKM);
void setPrecios(int *flagAerolineas, int *flagLatam, float *importeAerolineas, float *importeLatam);
int calculaCostos(int km, float importe, float *importeDebito, float *importeCredito, float *importeBTC, float *importePorKM);


// ####################### MAIN #######################
int main(void) {

    
	
	int resultFuntion;
    int option;
	int minimo = 1;
	int maximo = 6;
	int reintentos = 1;

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

		resultFuntion = utn_getInt(&option, "Ingrese el nro de opcion: ", minimo, maximo, REINTENTOS);

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


// ####################### FUNCIONES #######################

// ###### getFloat ######
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

// ###### getInt ######
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
// ################ Calcular Costos #######################


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

// ###### printMenu ######

void printMenuppal(){

	printf("# 1   Ingresar Kilómetros.\n");
	printf("# 2   Ingresar Precio de Vuelos.\n");
	printf("# 3   Calcular todos los costos:\n");
	printf("# 4   Informar resultados:\n");
	printf("# 5   Carga forzada de datos:\n");
	printf("# 6   Salir:\n");
}
// ################ Style function #######################

void printTitleChoice(int numOption){
	printf("\t#####################\n\t# Elegiste Opcion %d #\n\t#####################\n\n", numOption);

}

void systemPause(){
    printf("Presione enter para volver al Menu principal");
    while(getchar()!='\n');
}

// ################ Mostrar resultados: #######################

void printResultados(char *nombre, float precioDebito, float precioCredito, float precioBTC, float precioPorKm){

    printf("%s:\n", nombre);
    printf("a) Precio con tarjeta de débito: $ %.2f\n", precioDebito);
    printf("b) Precio con tarjeta de crédito: $ %.2f\n", precioCredito);
    printf("c) Precio pagando con bitcoin: %f BTC\n", precioBTC);
    printf("d) Precio por KM: $ %.2f\n\n", precioPorKm);

}



// 
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