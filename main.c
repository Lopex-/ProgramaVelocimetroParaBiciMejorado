/*
 * main.c
 *
 * Prueba 1 del programa para la placa Velocimetro para bicicleta mejorado
 * Primer test del ICSP de la placa
 * Simpe parpadeo de leds
 *
 * Prueba 2. Se añadieron las definiciones para los botones
 * correcion en las definiciones para apagar los leds
 *
 * Created: 12/03/2017 15:02:42 
 *  Author: Lopex_
 */ 


#define F_CPU 1000000L				//Reloj interno RC a 1Mhz
 
#include <avr/io.h>
#include <util/delay.h>


// ------------------------------- Dfiniciones ------------------------------------

// LEDS

 #define mask_LED1	0
 #define mask_LED2	1

 #define conf_LED1	DDRB
 #define conf_LED2	DDRB

 #define port_LED1	PORTB
 #define port_LED2	PORTB

 #define init_LED1	conf_LED1 |= 1<<mask_LED1
 #define init_LED2	conf_LED2 |= 1<<mask_LED2

 #define LED1_OFF	port_LED1 &= ~(1<<mask_LED1)
 #define LED2_OFF	port_LED2 &= ~(1<<mask_LED2)

 #define LED1_ON	port_LED1 |= 1<<mask_LED1
 #define LED2_ON	port_LED2 |= 1<<mask_LED2

 #define LED1_SWAP	port_LED1 ^= 1<<mask_LED1
 #define LED2_SWAP	port_LED2 ^= 1<<mask_LED2


// BOTONES

 #define mask_BTN1          2
 #define mask_BTN2          3
 #define mask_BTN3          4

 #define conf_BTN1          DDRC
 #define conf_BTN2          DDRC
 #define conf_BTN3          DDRC

 #define port_BTN1          PINC
 #define port_BTN2          PINC
 #define port_BTN3          PINC

 #define pullup_BTN1        PORTC
 #define pullup_BTN2        PORTC
 #define pullup_BTN3        PORTC    

 #define init_BTN1          conf_BTN1 &= 0<<mask_BTN1
 #define init_BTN2          conf_BTN2 &= 0<<mask_BTN2
 #define init_BTN3          conf_BTN3 &= 0<<mask_BTN3

 #define enable_pullup_BTN1 pullup_BTN1 |= 1<<mask_BTN1
 #define enable_pullup_BTN2 pullup_BTN2 |= 1<<mask_BTN2
 #define enable_pullup_BTN3 pullup_BTN3 |= 1<<mask_BTN3

 #define BTN1_PRESS         ~(port_BTN1>>mask_BTN1)&1
 #define BTN2_PRESS         ~(port_BTN2>>mask_BTN2)&1
 #define BTN3_PRESS         ~(port_BTN3>>mask_BTN3)&1



// ---------------------------- Programa principal --------------------------------

int main(void)
{
	init_LED1;						//Inicializa los puertos como salidas
	init_LED2;

    init_BTN1;                      //Configura los pines como entradas
    init_BTN2;
    init_BTN3;

    enable_pullup_BTN1;             //Habilita las resistencias internas de los pines
    enable_pullup_BTN2;
    enable_pullup_BTN3;

	LED1_OFF;						//Los leds comenzaran la secencia uno encendido y uno apagado
	LED2_OFF;

    while(1){                       //Dependiendo el boton presionado se iluminaran los leds
        if(BTN1_PRESS){
            LED1_ON;
            LED2_OFF;
        }
        else if(BTN2_PRESS){
            LED1_OFF;
            LED2_ON;
        }
        else if(BTN3_PRESS){
            LED1_ON;
            LED2_ON;
        }
        else{
            LED1_OFF;
            LED2_OFF;
        }
        _delay_ms(100);
    }
}