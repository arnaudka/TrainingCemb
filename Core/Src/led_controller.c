/*
 * led_controller.c
 *
 *  Created on: 12 nov. 2020
 *      Author: Adrien
 */

#include "main.h"
#include "led_controller.h"

led_controller_config config[CONF_MAX];

led_controller_config test_config;
led_controller_config* p_config = &test_config;

int Set;

void led_controller_init() {

	//config[0].mode = 0;
	//j[2]=200;
	//p_config->toto = 200;
	//config[0] = (led_controller_config) {.delay= {200}};
	//config[0] = (led_controller_config) {.pattern = {LED1, DELAY, LED1, LED2, DELAY, LED2, LED3, DELAY, LED3, LED4, DELAY, LED4, STOP}};
	//config[1].mode = 1;
	//(*(p_config+1)).delay = 200;

	config[0] = (led_controller_config) {.pattern = {LED1, DELAY, LED1, LED2, DELAY, LED2, LED3, DELAY, LED3, LED4, DELAY, LED4, STOP}};

	config[1] = (led_controller_config) {.pattern = {LED1, DELAY, LED2, DELAY, LED3, DELAY, LED4, DELAY, LED1, LED2, LED3, LED4, STOP}};

	config[2] = (led_controller_config) {.pattern = {LED1, LED2, LED3, LED4, DELAY, LED1, DELAY, LED2, DELAY, LED3, DELAY, LED4, STOP}};

	config[3] = (led_controller_config) {.pattern = {LED1, DELAY, LED2, DELAY, LED1, LED3, DELAY, LED2, LED4, DELAY, LED3, LED1, DELAY, LED4, DELAY, LED1, STOP}};

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
			switch (config[Set].pattern[i]) {
				case DELAY:
				//HAL_Delay(config[Set].delay);
				//HAL_Delay(p_config->toto);
				HAL_Delay(500);

				default:
				HAL_GPIO_TogglePin(GPIOC, config[Set].pattern[i]);
			}
		i++;
		}
};
