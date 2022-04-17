/*
 * UtnInputOutput.h
 *
 *  Created on: Apr 16, 2022
 *      Author: random
 */

#ifndef UTNINPUTOUTPUT_H_
#define UTNINPUTOUTPUT_H_
/**
 * @brief
 * Muestra por consola el menu ppal.
 */
void printMenuppal();

/**
 * @brief
 *  Muestar por consola el precio final para cada medio de pago.
 * @param nombre nombre de la Aerolinea
 * @param precioDebito Precio final para debito.
 * @param precioCredito Precio final para credito.
 * @param precioBTC Precio final para BTC.
 * @param precioPorKm Precio final por KM.
 */
void printResultados(char *nombre, float precioDebito, float precioCredito, float precioBTC, float precioPorKm);


/**
 * @brief
 *  Solicita al usuario que ingrese un nro flotante segun los rangos que reciba, valida que el mismo sea correcto.
 * @param pInput Direccion de memoria donde se almacenara el nro ingresado
 * @param message Mensaje para solicitar el dato al usuario
 * @param minimo Rango minimo del nro solicitado
 * @param maximo Rango maximo del nro solicitado
 * @param reintentos Cantidad maxima de reintentos en caso de ingrtesar un dato invalido
 * @return 0 para OK y -1 en caso de error
 */
int utn_getFloat( float *pInput, char *message, float minimo, float maximo, int reintentos);

/**
 * @brief
 *  Solicita al usuario que ingrese un nro entero segun los rangos que reciba, valida que el mismo sea correcto.
 * @param pInput Direccion de memoria donde se almacenara el nro ingresado
 * @param message Mensaje para solicitar el dato al usuario
 * @param minimo Rango minimo del nro solicitado
 * @param maximo Rango maximo del nro solicitado
 * @param reintentos Cantidad maxima de reintentos en caso de ingrtesar un dato invalido
 * @return 0 para OK y -1 en caso de error
 */
int utn_getInt( int *pInput, char *message, int minimo, int maximo, int reintentos);

/**
 * @brief
 * Valida si ya se ingresaron  los precios del pasaje. Si no se ingreso, los solicita. Si ya se ingresaron, los informa y ofrece la opcion de modificarlos.
 * @param flagAerolineas Controla si ya se ingreso el precio para Aerolineas.
 * @param flagLatam Controla si ya se ingreso el precio para Latam.
 * @param importeAerolineas Direccion para almacenar el importe para Aerolineas.
 * @param importeLatam Direccion para almacenar el importe para Latam.
 */
void setPrecios(int *flagAerolineas, int *flagLatam, float *importeAerolineas, float *importeLatam);

/**
 * @brief
 * Valida si ya se ingreso los KM. Solicita ingresarlos si aun no se ingreso. caso contrario muestar el valñor actual y ofrece opcion de modificar
 * @param km doreccion para almacenar el KM ingresado.
 * @param flagKM controla si ya se ingreso valor anteriomente.
 */
void setKilometros(float *km, int *flagKM);


/**
 * @brief
 *  Imprime un titulo con la leyenda de la opcion ingresada.
 * @param numOption
 */
void printTitleChoice(int numOption);


/**
 * @brief Detienen la ejecucion del programa hasta que el usuario precione la tecla ENTER.
 *
 */
void systemPause();



#endif /* UTNINPUTOUTPUT_H_ */
