/*
 * clave.cpp
 *
 *  Created on: 18 nov 2026
 *      Author: silvi
 */

#include <stdlib.h>
#include "clave.h"

void generar_clave(uint8_t clave[4]) {
    for(int i = 0; i < 4; i++) {
        clave[i] = rand() % 10; //EMPLEEAR NUMEROS DEL 0 A 9
    }
}
