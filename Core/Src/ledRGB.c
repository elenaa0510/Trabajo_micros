/*
 * ledRGB.c
 *
 *  Created on: 21 nov 2026
 *      Author: sofia
 */
#include <stdlib.h>
#include "main.h"
#include "ledRGB.h"

void color_correcto(uint8_t num_led)
{
    switch (num_led)
    {
        case 0:
            // LED 1:PC1, PC2, PC3
            HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
            break;

        case 1:
            // LED 2:PC4, PC5, PC6
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET);
            break;

        case 2:
        	// LED 3:PC7, PC8, PC9
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);
            break;

        case 3:
        	// LED 4:PC10, PC11, PC12
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET);
        	 break;
    }
}
void color_caliente(uint8_t num_led)
{
    switch (num_led)
    {
        case 0:
            // LED 1:PC1, PC2, PC3
            HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
            break;

        case 1:
            // LED 2:PC4, PC5, PC6
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET);
            break;
        case 2:
        	// LED 3:PC7, PC8, PC9
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);
            break;

        case 3:
        	// LED 4:PC10, PC11, PC12
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET);
        	 break;
    }
}

void color_templado(uint8_t num_led)
{
    switch (num_led)
    {
        case 0:
            // LED 1:PC1, PC2, PC3
            HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
            break;

        case 1:
            // LED 2:PC4, PC5, PC6
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);
            break;

        case 2:
        	// LED 3:PC7, PC8, PC9
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);
            break;

        case 3:
        	// LED 4:PC10, PC11, PC12
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET);
        	 break;
    }
}

void color_frio(uint8_t num_led)
{
    switch (num_led)
    {
        case 0:
            // LED 1:PC1, PC2, PC3
            HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
            break;

        case 1:
            // LED 2:PC4, PC5, PC6
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);
            break;

        case 2:
        	// LED 3:PC7, PC8, PC9
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);
            break;

        case 3:
        	// LED 4:PC10, PC11, PC12
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET);
        	 break;
    }
}


void logica_frio_caliente(const char correcto[4], const char usuario[4])
{
	for (int i=0;i<4;i++)
	{
		uint8_t posiciones;
		posiciones=abs(correcto[i]-usuario[i]);

	switch (posiciones)
		{
		case 0://llamar led correcto(verde) se quemo
			color_correcto(i);
			break;
		case 1: //llamar led caliente (rojo)
			color_caliente(i);
			break;
		case 2: //llamar led templado (naranja)
			color_templado(i);
			break;
		default: //llamar led frio(azul
			color_frio(i);
			break;
		}
	}
}

void apagar_leds(void)
{
	//llamada a todos los leds para que se apaguen
	 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET);
	 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_RESET);
	 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
	 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_RESET);
	 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET);
	 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET);
	 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET);
	 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);
	 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);
	 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET);
	 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET);
	 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET);

}
