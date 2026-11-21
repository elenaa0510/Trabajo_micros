/*
 * ledRGB.h
 *
 *  Created on: 21 nov 2026
 *      Author: sofia
 */

#ifndef INC_LEDRGB_H_
#define INC_LEDRGB_H_


//funicones individuales para enceder cada led
void color_correcto(uint8_t num_led);
void color_caliente(uint8_t num_led);
void color_templado(uint8_t num_led);
void color_frio(uint8_t num_led);

//funcion para el funcionamineto de los 4 leds
void logica_frio_caliente(const char correcto[4], const char usuario[4]);


//funcion para apagarlos
void apagar_leds(void);


#endif /* INC_LEDRGB_H_ */
