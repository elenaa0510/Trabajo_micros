/*
 * tiempo.h
 *
 *  Created on: 21 nov 2026
 *      Author: silvi
 */

#ifndef INC_TIEMPO_H_
#define INC_TIEMPO_H_

#include <stdint.h>

#define TIEMPO_MAX 120000 //2min en ms

void iniciar_tiempo(void);
uint32_t tiempo_empleado(void);
uint8_t tiempo_agotado(void);
uint32_t tiempo_final(void);


#endif /* INC_TIEMPO_H_ */
