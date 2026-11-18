/*
 * potenciometros.c
 *
 *  Created on: 18 nov 2026
 *      Author: elewo
 */
#include "potenciometros.h"
static const uint32_t canales_adc[]={
		ADC_CHANNEL_10,
		ADC_CHANNEL_11,
		ADC_CHANNEL_12,
		ADC_CHANNEL_13
};
int POT_MapearValor(uint32_t valor_adc){
	//convertimos el valor del conversor (0 a 4095) a un entero del 0 al 9
	int digito = (int)((valor_adc * 10)/4096);
	if(digito>9){
		digito=9;
	}

	return digito;

}

void POT_ObtenerValores(ADC_HandleTypeDef *hadc, int *array_destino, int cantidad) {
    ADC_ChannelConfTypeDef sConfig = {0};

    for (int i = 0; i < cantidad; i++) {
        sConfig.Channel = canales_adc[i];
        sConfig.Rank = 1;
        sConfig.SamplingTime = ADC_SAMPLETIME_15CYCLES; // Un poco más de tiempo de muestreo para mayor estabilidad

        HAL_ADC_ConfigChannel(hadc, &sConfig);

        // Iniciamos, leemos y paramos de forma directa y limpia
        HAL_ADC_Start(hadc);

        // Si tarda más de 2 milisegundos, salimos sin bloquear la placa
        if (HAL_ADC_PollForConversion(hadc, 2) == HAL_OK) {
            uint32_t valor_bruto = HAL_ADC_GetValue(hadc);
            array_destino[i] = POT_MapearValor(valor_bruto);
        } else {
            array_destino[i] = 0; // Si falla la lectura puntualmente, ponemos 0 en vez de crashear
        }

        HAL_ADC_Stop(hadc);
    }
}
