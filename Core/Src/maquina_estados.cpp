/*
 * maquina_estados.cpp
 *
 *  Created on: 18 nov 2026
 *      Author: silvi
 */


#include "maquina_estados.h"

//DE MOMENTO SOLO CON INTERRUPCIONES LOS BOTONES
volatile uint8_t flag_boton_validar = 0;
volatile uint8_t flag_boton_start = 0;
volatile uint8_t flag_boton_onoff = 0;


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin == BTN_VALIDAR_Pin) {
        flag_boton_validar = true;
    }
    else if (GPIO_Pin == BTN_START_Pin) {
        flag_boton_start = true;
    }
    else if (GPIO_Pin == BTN_ONOFF_Pin) {
            flag_boton_onoff = true;
        }
}



typedef enum {
    ESTADO_APAGADO, //INICIO Y EN CUALQUIER ESTADO SE PULSA OFF
	ESTADO_ESPERA, //ESPERAR A PULSAR START
    ESTADO_INICIALIZAR, //GENERAR CLAVE Y INICIO TEMP A 0
    ESTADO_JUGANDO, //INTENTOS
    ESTADO_VALIDAR, //SE PULSA VALIDAR
    ESTADO_VICTORIA, //CLAVE COINCIDE
	ESTADO_RANKING, //UNA VEZ SE GANE SE PERMITE GUARDAR UN RANKING SEGUN PUNTUACIONES
    ESTADO_DERROTA //TIEMPO SE ACABA
} EstadoJuego;


EstadoJuego estado_actual = ESTADO_APAGADO;

void actualizar_estados(void) {
    switch(estado_actual) {
    case ESTADO_AGAPAGADO:
    	if (flag_boton_onoff)
    	{
    	    flag_boton_onoff = false;

    	    if (estado_actual == ESTADO_APAGADO)
    	    {
    	        estado_actual = ESTADO_ENCENDIDO;
    	    }
    	    else
    	    {
    	        estado_actual = ESTADO_APAGADO;
    	    }

    	    return;
    	}

    case ESTADO_ESPERA:
        if (flag_boton_start) {
            flag_boton_start = false;
            estado_actual = ESTADO_INICIALIZAR;
        }
        break;

     case ESTADO_INICIALIZAR:
         generar_clave();
         iniciar_temporizador_partida(); //SIN HACER
         estado_actual = ESTADO_JUGANDO;
         break;

      case ESTADO_JUGANDO:
          if (flag_boton_validar) {
             flag_boton_validar = false;
             estado_actual = ESTADO_VALIDAR;
          }

          if (temporizador_fin()) { //SIN HACER
             estado_actual = ESTADO_DERROTA;
          }
          break;

      case ESTADO_VALIDAR:
          if (validar_clave(lectura_potenciometro())) {  //SIN HACER
              estado_actual = ESTADO_VICTORIA;
          } else {
              //SI FALLA SE SIGUE JUGANDO
              estado_actual = ESTADO_JUGANDO;
          }
          break;

      case ESTADO_VICTORIA:
       //ESCRIBIR MENSAJE PANTALLA Y GUARDAR EN RANKING
       if (flag_boton_start) {
    	   estado_actual = ESTADO_INICIALIZAR;
        	flag_boton_start = false;
       }
       break;

      case ESTADO_DERROTA:
       //ESCRIBIR MENSAJE PANTALLA Y ESPERAR A START DE NUEVO
        if (flag_boton_start) {
          estado_actual = ESTADO_INICIALIZAR;
          flag_boton_start = false;
         }
        break;
    }
}
