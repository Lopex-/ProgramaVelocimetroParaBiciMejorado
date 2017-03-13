/*
 * main.c
 *
 * Prueba 01 del programa para la placa Vlocimetro para bicicleta mejorado
 * Primer test del ICSP de la placa
 * Simpe parpadeo de leds
 *
 * Created: 12/03/2017 15:02:42 
 *  Author: Lopex_
 */ 


#define F_CPU 1000000L				//Reloj interno RC a 1Mhz
 
#include <avr/io.h>
#include <util/delay.h>


// ------------------------------- Dfiniciones ------------------------------------

 #define mask_LED1	0
 #define mask_LED2	1

 #define conf_LED1	DDRB
 #define conf_LED2	DDRB

 #define port_LED1	PORTB
 #define port_LED2	PORTB

 #define init_LED1	conf_LED1 |= 1<<mask_LED1
 #define init_LED2	conf_LED2 |= 1<<mask_LED2

 #define LED1_ON	port_LED1 &= 0<<mask_LED1
 #define LED2_ON	port_LED2 &= 0<<mask_LED2

 #define LED1_OFF	port_LED1 |= 1<<mask_LED1
 #define LED2_OFF	port_LED2 |= 1<<mask_LED2

 #define LED1_SWAP	port_LED1 ^= 1<<mask_LED1
 #define LED2_SWAP	port_LED2 ^= 1<<mask_LED2

// ---------------------------- Programa principal --------------------------------

int main(void)
{
	init_LED1;						//Inicializa los puertos como salidas
	init_LED2;

	LED1_OFF;						//Los leds comenzaran la secencia uno encendido y uno apagado
	LED2_OFF;

    while(1)
    {
        LED1_SWAP;					//Los leds cambiaran de estado infinitmente cada medio segundo
        _delay_ms(500);
        LED2_SWAP;
    }
}