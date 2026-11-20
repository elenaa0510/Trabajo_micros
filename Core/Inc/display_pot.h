/*
 * display_pot.h
 *
 *  Created on: 20 nov 2026
 *      Author: elewo
 */

#ifndef INC_DISPLAY_POT_H_
#define INC_DISPLAY_POT_H_

#include "main.h"
#include <stdint.h>

void TM1637_Init(uint8_t brillo); //brillo del 0 al 7
void TM1637_MostrarDigitos(const uint8_t digitos[4]);



#endif /* INC_DISPLAY_POT_H_ */
