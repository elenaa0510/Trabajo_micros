/*
 * display_pot.c
 *
 *  Created on: 20 nov 2026
 *      Author: elewo
 */
#include "display_pot.h"
static const uint8_t TABLA_DIGITOS[10]={
		0x3F, // 0
		0x06, // 1
		0x5B, // 2
		0x4F, // 3
		0x66, // 4
		0x6D, // 5
		0x7D, // 6
		0x07, // 7
		0x7F, // 8
		0x6F  // 9
};
static uint8_t brillo_cmd = 0x8F;
//pequeña pausa para que le de tiempo al chip a leer los pines
static void retardo(void){
	for(volatile int i=0;i<60;i++){
		__NOP();
	}
}
//pone el pin de reloj a nivel alto
static void clk_high(void){
	HAL_GPIO_WritePin(GPIOB, TM_CLK_Pin, GPIO_PIN_SET);
	retardo();
}
//pone el pin de reloj a nivel bajo
static void clk_low(void){
	HAL_GPIO_WritePin(GPIOB, TM_CLK_Pin, GPIO_PIN_RESET);
	retardo();
}
//pone el pin de datos a nivel alto
static void dio_high(void){
	HAL_GPIO_WritePin(GPIOB, TM_DIO_Pin, GPIO_PIN_SET);
	retardo();
}
//pone el pin de datos a nivel bajo
static void dio_low(void){
	HAL_GPIO_WritePin(GPIOB, TM_DIO_Pin, GPIO_PIN_RESET);
	retardo();
}
static void start(void){
	dio_high();
	clk_high();
	dio_low();
	clk_low();
}
static void stop(void){
	clk_low();
	dio_low();
	clk_high();
	dio_high();
}
static void escribir_byte(uint8_t dato){
	for(uint8_t i=0; i<8;i++){
		clk_low();//se baja el reloj antes de cambiar el valor del dato
		if (dato & 0x01) {
			dio_high();
		} else {
			dio_low();
		}

		retardo();
		clk_high();
		dato >>=1;
	}
	clk_low();
	dio_high();
	retardo();
	clk_high();
	retardo();
	clk_low();
}
void TM1637_Init(uint8_t brillo) {
    if (brillo > 7) {
        brillo = 7;
    }
    brillo_cmd = 0x88 | brillo; // 0x88 = display encendido + nivel de brillo (0..7)

    dio_high();
    clk_high();

    start();
    escribir_byte(0x40); // Modo de escritura automática de dirección
    stop();

    start();
    escribir_byte(brillo_cmd); // Aplica el brillo y enciende la pantalla
    stop();
}
void TM1637_MostrarDigitos(const uint8_t digitos[4]) {
    start();
    escribir_byte(0x40); // Escritura automática
    stop();

    start();
    escribir_byte(0xC0); // Empieza en el primer dígito (posición 0)
    for (int i = 0; i < 4; i++) {
        uint8_t val = digitos[i];
        if (val > 9) {
            val = 9; // Evita leer fuera de TABLA_DIGITOS
        }
        escribir_byte(TABLA_DIGITOS[val]);
    }
    stop();

    start();
    escribir_byte(brillo_cmd); // Mantiene el display encendido con su brillo
    stop();
}
