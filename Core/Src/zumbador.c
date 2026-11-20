/*
 * zumbador.c
 *
 *  Created on: 20 nov 2026
 *      Author: sofia
 */
#include "zumbador.h"
#include "main.h"
//genera la onda que indica el tiempo y ciclo que sonara el zumbador
static void suena_zumbador(uint32_t semiperiodo_ms, uint32_t ciclos)//recibe los semipoeriodos y los ciclos que queremos
{
    for (uint32_t i = 0; i < ciclos; i++)
    {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
        HAL_Delay(semiperiodo_ms);

        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
        HAL_Delay(semiperiodo_ms);
    }
}

void zumbador_correcto(void)//cuando los numeros coinciden
{
    suena_zumbador(1, 100);
    HAL_Delay(150);

}
void zumbador_incorrecto(void)//cuando algun numero no coincide
{
	suena_zumbador(2,150);
	HAL_Delay(150);
}
