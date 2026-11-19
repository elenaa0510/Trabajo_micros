/*
 * validar.cpp
 *
 *  Created on: 18 nov 2026
 *      Author: silvi
 */


#include "validar.h"

uint8_t validar_clave(uint8_t clave_correcta[4],uint8_t usuario[4]){

	for (int i=0;i<4;i++){
		if (clave_correcta[i]==usuario[i])
			return 1; //CORRECTO
		else return 0; //INCORRECTO
	}
}

