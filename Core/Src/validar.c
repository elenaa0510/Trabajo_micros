/*
 * validar.cpp
 *
 *  Created on: 18 nov 2026
 *      Author: silvi
 */


#include "validar.h"
#include "zumbador.h"
#include "ledRGB.h"
#include "main.h"

uint8_t validar_clave(uint8_t clave_correcta[4],uint8_t usuario[4])
{

	for (int i=0;i<4;i++)
	{
		//se hace la logica de frio y caliente, sea o no correcto para que se encinedan leds correspondientes
		logica_frio_caliente(clave_correcta, usuario);

		//se hace la logica de verificar si suena o no y que devuleve la funcion
		if (clave_correcta[i]==usuario[i])
		{

			//hacemos llamada al zumbador con sonido de correcto
					zumbador_correcto();
			        HAL_Delay(1000);
			return 1; //CORRECTO
		}

		else
		{
			//hacemis llamada al zubador con sonido de incorrecto
				zumbador_incorrecto();
		        HAL_Delay(1000);
			return 0; //INCORRECTO
		}

	}
}

