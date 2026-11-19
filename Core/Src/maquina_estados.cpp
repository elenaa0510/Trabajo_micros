/*
 * maquina_estados.cpp
 *
 *  Created on: 18 nov 2026
 *      Author: silvi
 */


#include "maquina_estados.h"
#include "validar.h" //INCLUYE EL CALVE.H
#include <stdbool.h>

//DE MOMENTO SOLO CON INTERRUPCIONES LOS BOTONES
volatile uint8_t flag_boton_validar = 0;
volatile uint8_t flag_boton_start = 0;
volatile uint8_t flag_boton_onoff = 0;


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin == BTN_VALIDAR) {
        flag_boton_validar = true;
    }
    else if (GPIO_Pin == BTN_START) {
        flag_boton_start = true;
    }
    else if (GPIO_Pin == BTN_ONOFF) {
            flag_boton_onoff = true;
        }
}



typedef enum {
    ESTADO_APAGADO, //INICIO Y EN CUALQUIER ESTADO SE PULSA OFF
	ESTADO_ESPERA, //ESPERAR A PULSAR START
    ESTADO_INICIALIZAR, //GENERAR CLAVE Y INICIO TEMP A 0
    ESTADO_JUGANDO, //INTENTOS
    ESTADO_VALIDAR, //SE PULSA VALIDAR
	ESTADO_RANKING, //UNA VEZ SE GANE SE PERMITE GUARDAR UN RANKING SEGUN PUNTUACIONES
    ESTADO_DERROTA //TIEMPO SE ACABA
} EstadoJuego;


EstadoJuego estado_actual = ESTADO_APAGADO;

void actualizar_estados(void) {

	//FUERA DEL SWITCH EL ON/OFF PARA EVALUAR SIEMPRE
	if (flag_boton_onoff)
	    	{
	    	    flag_boton_onoff = false;

	    	    if (estado_actual ==ESTADO_APAGADO)
	    	        estado_actual=ESTADO_ESPERA;
	    	    else
	    	    {
	    	    	estado_actual= ESTADO_APAGADO;
	    	    	flag_boton_validar = false;
	    	    	flag_boton_start = false;
	    	    }

	    	    return;
	    	}

    switch(estado_actual) {

    case ESTADO_APAGADO:
    	//SI ESYA APAGADO NO HACER NADA
    	break;

    case ESTADO_ESPERA:
        if (flag_boton_start) {
           estado_actual=ESTADO_INICIALIZAR;
           flag_boton_start=false;
        }
        break;

     case ESTADO_INICIALIZAR:
         generar_clave(clave);
         reiniciar_temporizador(); //SIN HACER
         reiniciar_puntuacion(); //SIN HACER
         estado_actual=ESTADO_JUGANDO;
         break;

      case ESTADO_JUGANDO:
          if (temporizador_fin()) { //SIN HACER
             estado_actual=ESTADO_DERROTA;
             flag_boton_validar=false;
          }
          else if (flag_boton_validar) {
                       estado_actual=ESTADO_VALIDAR;
                       flag_boton_validar=false;
                    }
          break;

      case ESTADO_VALIDAR:
          if (validar_clave(clave,lectura_pot()))
              estado_actual=ESTADO_RANKING;
          else
              //SI FALLA SE SIGUE JUGANDO
              estado_actual=ESTADO_JUGANDO;
           break;

      case ESTADO_RANKING:
    	  //METER ESTO DENTRO DE LA FUNCION ESCRIBIR_RANKING
    	  //if (flag_boton_start) {
    	      	 //  estado_actual=ESTADO_INICIALIZAR;
    	      	 //  flag_boton_start=false;
    	        // }

    	  escribir_ranking();
    	  estado_actual=ESTADO_ESPERA;
    	  break;

      case ESTADO_DERROTA:
       //ESCRIBIR MENSAJE PANTALLA Y ESPERAR A START DE NUEVO
        if (flag_boton_start) {
          estado_actual=ESTADO_INICIALIZAR;
          flag_boton_start=false;
         }
        break;
    }
}
