/*
 * maquina_estados.h
 *
 *  Created on: 18 nov 2026
 *      Author: silvi
 */

#ifndef INC_MAQUINA_ESTADOS_H_
#define INC_MAQUINA_ESTADOS_H_

#include <stdint.h>

//VARIABLES GLOBAL -> FLAGS
extern volatile uint8_t flag_boton_validar;
extern volatile uint8_t flag_boton_start;
extern volatile uint8_t flag_boton_onoff;

//MAQUINA ESTADOS, RESPONSABLE DE LA CORDINACION DEL JUEGO
void actualizar_estados(void);

void iniciar_partida(void);
void finalizar_partida(void);

void sumar_intento(void);

void escribir_ranking(void);

#endif /* INC_MAQUINA_ESTADOS_H_ */
