/*
 * led_controller.c
 *
 *  Created on: 12 nov. 2020
 *      Author: Adrien
 */

#include "main.h"
#include "led_controller.h"

static led_controller_config config[CONF_MAX];

static led_controller_config test_config; //EX -> décl sous main
//static led_controller_config* p_config = &test_config; // pointe vers main

static int Set;

void led_controller_init() {
	config[0] = (led_controller_config) {
	.mode = 0,
	.delay = 200,
	.pattern = {LED1, DELAY, LED1, LED2, DELAY, LED2, LED3, DELAY, LED3, LED4, DELAY, LED4, STOP}
	};

	config[1] = (led_controller_config) {
	.mode = 0,
	.delay = 200,
	.pattern = {LED1, DELAY, LED2, DELAY, LED3, DELAY, LED4, DELAY, LED1, LED2, LED3, LED4, STOP}
	};

	config[2] = (led_controller_config) {
	.mode = 0,
	.delay = 200,
	.pattern = {LED1, LED2, LED3, LED4, DELAY, LED1, DELAY, LED2, DELAY, LED3, DELAY, LED4, STOP}};

	config[3] = (led_controller_config) {
	.mode = 0,
	.delay = 200,
	.pattern = {LED1, DELAY, LED2, DELAY, LED1, LED3, DELAY, LED2, LED4, DELAY, LED3, LED1, DELAY, LED4, DELAY, LED1, STOP}
	};
};


void led_controller_Config() {
	Set = 3;
};

void change_set (void) {
	Set++;
		if (Set > 3)
			Set = 0;
};

void led_controller_run() {

	change_set();

	int i = 0;

		while (config[Set].pattern[i] != STOP) {
			switch (config[Set].pattern[i]) { //!taille du tableau dans les para de la fonction -> dépassement du tableau!!
				case DELAY:
				//HAL_Delay(config[Set].delay);
				//HAL_Delay(p_config->toto);
				HAL_Delay(config[Set].delay);//compter nb d'appels de func()

				default:
				HAL_GPIO_TogglePin(GPIOC, config[Set].pattern[i]);
			}
		i++;
		}
};
