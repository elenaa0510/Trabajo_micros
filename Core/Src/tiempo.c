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
static uint32_t tiempo_empleado = 0; //tiempo en ganar


void iniciar_contador(void){
	tiempo_inicial =HAL_GetTick();
	tiempo_empleado=0;
}

uint32_t obtener_tiempo_empleado(void){
	return HAL_GetTick()-tiempo_inicial;
}
