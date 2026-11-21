/*
 * tiempo.c
 *
 *  Created on: 21 nov 2026
 *      Author: silvi
 */

#include "tiempo.h"
#include "main.h"

//VARIABLES GLOBALES
static uint32_t tiempo_inicial = 0; //inicio de partida
static uint32_t tiempo_ganar = 0; //tiempo en ganar


void iniciar_tiempo(void){
	tiempo_inicial =HAL_GetTick();
	tiempo_ganar=0;
}

uint32_t tiempo_empleado(void){
	return HAL_GetTick()-tiempo_inicial;
}

uint8_t tiempo_agotado(void){
	if (tiempo_empleado()>=TIEMPO_MAX)
		return 1;
	else
		return 0;
}

uint32_t tiempo_final(void){
	tiempo_ganar =tiempo_empleado();
	return tiempo_ganar;
}
