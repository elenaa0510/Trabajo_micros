/*
 * maquina_estados.h
 *
 *  Created on: 18 nov 2026
 *      Author: silvi
 */

#ifndef INC_MAQUINA_ESTADOS_H_
#define INC_MAQUINA_ESTADOS_H_


extern volatile uint8_t flag_boton_validar;
extern volatile uint8_t flag_boton_start;
extern volatile uint8_t flag_boton_onoff;

void actualizar_estados(void);

#endif /* INC_MAQUINA_ESTADOS_H_ */
