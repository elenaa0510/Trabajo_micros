/*
 * maquina_estados.cpp
 *
 *  Created on: 18 nov 2026
 *      Author: silvi
 */

#include <stdbool.h>
#include "maquina_estados.h"
#include "main.h"
#include "validar.h"
#include "tiempo.h"

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


//ESTADOS
typedef enum {
    ESTADO_APAGADO, //INICIO Y EN CUALQUIER ESTADO SE PULSA OFF
	ESTADO_ESPERA, //ESPERAR A PULSAR START
    ESTADO_INICIALIZAR, //GENERAR CLAVE Y INICIO TEMP A 0
    ESTADO_JUGANDO, //INTENTOS
    ESTADO_VALIDAR, //SE PULSA VALIDAR
	ESTADO_RANKING, //UNA VEZ SE GANE SE PERMITE GUARDAR UN RANKING SEGUN PUNTUACIONES
    ESTADO_DERROTA //TIEMPO SE ACABA
} EstadoJuego;


static EstadoJuego estado_actual = ESTADO_APAGADO;
static uint32_t n_intentos = 0;


//FUNCIONES DE CORDINACION
void iniciar_partida(void){
	n_intentos=0;
	iniciar_tiempo();
	generar_clave(clave);
}

void sumar_intento(void){
	n_intentos++;
}

void finalizar_partida(void){
	tiempo_final();
}

void escribir_ranking(void){ //SIN HACER

}



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
         iniciar_partida();
         estado_actual=ESTADO_JUGANDO;
         break;

      case ESTADO_JUGANDO:
          if (tiempo_agotado()) {
             estado_actual=ESTADO_DERROTA;
             flag_boton_validar=false;
          }
          else if (flag_boton_validar) {
        	  	  	  sumar_intento();
                       estado_actual=ESTADO_VALIDAR;
                       flag_boton_validar=false;
                    }
          break;

      case ESTADO_VALIDAR:
    	  //jugador leido por los pot
          if (validar_clave(clave,jugador)){
        	  finalizar_partida();
              estado_actual=ESTADO_RANKING;
          }
          else
              //SI FALLA SE SIGUE JUGANDO
              estado_actual=ESTADO_JUGANDO;
           break;

      case ESTADO_RANKING:
       	  escribir_ranking();
    	  estado_actual=ESTADO_ESPERA;
    	  break;

      case ESTADO_DERROTA:
       //ESCRIBIR MENSAJE PANTALLA
        if (flag_boton_start) {
          estado_actual=ESTADO_INICIALIZAR;
          flag_boton_start=false;
         }
        break;
    }
}
