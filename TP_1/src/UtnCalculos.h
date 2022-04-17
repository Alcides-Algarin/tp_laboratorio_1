/*
 * UtnCalculos.h
 *
 *  Created on: Apr 16, 2022
 *      Author: random
 */

#ifndef UTNCALCULOS_H_
#define UTNCALCULOS_H_

/// @brief
/// Recibe un importe, un porcentaje de descuento o recargo y calcula el precio final.
/// @param importe base sobre el cual calcular el costo final.
/// @param adicional Porcentaje a aplicar. Si es descuento, debe ser negativo. Si es un recargo, debe ser positivo
/// @param pImporteFinal Costo final luego de aplicar el adiccional(Descuento o recargo)
/// @return 0 para OK y -1 en caso de error
int costoFinal(float importe, float adicional, float *pImporteFinal);


/**
 * @brief
 * Conviente a BTC el importe ingresado
 * @param importe base sobre el cual calcular el costo final.
 * @param valorBTC Precio en pesos ARG  del Bitcoin
 * @param pPrecioLatamBTC  Costo en BTC del importe ingresado
 * @return 0 para OK y -1 en caso de error
 */
int costoEnBTC(float importe, float valorBTC, float *pPrecioLatamBTC );


/**
 * @brief
 * Calcula el costo por Km del viaje.
 * @param importe Precio del vieje
 * @param km KM totales
 * @param precioPorKM Precio por KM
 * @return 0 para OK y -1 en caso de error
 */
int costoPorKM(float importe, float km, float *precioPorKM);


/**
 * @brief
 *  Calcula diferencia de precio de los pasajes.
 * @param importeLatam primer importe
 * @param importeAerolineas Segundo importe
 * @param diferenciaPrecios Diferencia neta entre ambos
 * @return 0 para OK y -1 en caso de error
 */
int diffPrecios(float importeLatam, float importeAerolineas, float *diferenciaPrecios);


/**
 * @brief
 *  Realiza los calculos solicitados para informar al usuario.
 * @param km
 * @param importe
 * @param importeDebito
 * @param importeCredito
 * @param importeBTC
 * @param importePorKM
 * @return 0 para OK y -1 en caso de error
 */
int calculaCostos(int km, float importe, float *importeDebito, float *importeCredito, float *importeBTC, float *importePorKM);


#endif /* UTNCALCULOS_H_ */
