/*
 ============================================================================
 Name        : TP_1.c
 Author      : Alcides Algarin  1-E
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int getInt(int *, char *,char *, int, int, int);
void printMenuppal();
void ejecutarOpcionIngresada(int *);

// ####################### Comandos del sistema #######################

//system("clear");Limpia terminal en linux


// ####################### MAIN #######################
int main(void) {

	int option;
	//char mensaje[255];
	//char mensajeError[255];
	//int minimo;
	//int maximo;
	//int reintentos;
	int resultFuntion;

	do{

		printMenuppal();
		resultFuntion = getInt(&option, "Ingrese una opcion: ", "El valor ingresado no es valido. Intente nuevamente: ", 6,  1,  3);

		if (resultFuntion != -1) {
			ejecutarOpcionIngresada(&option);
			system("clear");
		}else{
			printf("Ocurrio un error al validar el dato ingresado. ");
		}


	}while(option != 6);

	return EXIT_SUCCESS;
}


// ####################### FUNCIONES #######################

// ###### getInt ######
int getInt(int *pInput,char * mensaje,char * mensajeError,int maximo, int minimo, int reintentos){

	int auxInput;
	int output;
	output = -1;

	if(pInput != NULL && maximo >= minimo && reintentos>= 0){
		do{
			//while(getchar()!='\n');
			printf("%s", mensaje);
			scanf("%d", &auxInput);
			scanf("%*[^\n]");
			//printf("%d\n", auxInput);
			reintentos--;

			if(auxInput >= minimo && auxInput <= maximo){
				*pInput = auxInput;
				output = 0;
				break;
			}else{
				printf("%s", mensajeError);
			}

		}while(reintentos > 0);
	}

	return output;
}

// ###### printMenu ######

void printMenuppal(){
	printf("1. Ingresar Kilómetros: ( km=x)\n");
	printf("2. Ingresar Precio de Vuelos:\n\t- Precio vuelo Aerolíneas:\n\t- Precio vuelo Latam:\n");
	printf("3. Calcular todos los costos:\n");
	printf("4. Informar resultados:\n");
	printf("5. Carga forzada de datos:\n");
	printf("6. Salir:\n");
}

// ###### Llamada afuncion seleccionada ######

void ejecutarOpcionIngresada(int *valor){

	system("clear");
	switch (*valor) {

	case 1:
		printf("\t#####################\n\t# Elegiste Opcion 1 #\n\t#####################\n");
		scanf("%*[^\n]");
		getchar();
		getchar();//Con un solo getchar no  se detiene el programa. Buscar como hacer para pausar el programa

		break;
	case 2:
		printf("Opcion 2\n");
		break;
	case 3:
		printf("Opcion 3\n");
		break;
	case 4:
		printf("Opcion 4\n");
		break;
	case 5:
		printf("Opcion 5\n");
		break;
	case 6:
		printf("Opcion 6\n");
		break;
	default:
		break;
	}
}
