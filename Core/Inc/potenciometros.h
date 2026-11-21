/*
 * potenciometros.h
 *
 *  Created on: 18 nov 2026
 *      Author: elewo
 */

#ifndef INC_POTENCIOMETROS_H_
#define INC_POTENCIOMETROS_H_

#include "main.h"

int POT_MapearValor(uint32_t valor_adc);
void POT_ObtenerValores(ADC_HandleTypeDef *hadc, int *array_destino, int cantidad);

//ELENA LO QUE DEVULEVE EL POT GUARDALO EN LA VARIABLE JUGADOR ES UN ARRAY DECLARADO EN CLAVE.H
//QUE ME DABA MUCHO ERROR DEJAR

#endif /* INC_POTENCIOMETROS_H_ */
