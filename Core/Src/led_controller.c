/*
 * led_controller.c
 *
 *  Created on: 12 nov. 2020
 *      Author: Adrien
 */

#include "main.h"
#include "led_controller.h"

void led_controller_init(void) {
HAL_GPIO_WritePin (GPIOC, LED1, GPIO_PIN_RESET);
HAL_GPIO_WritePin (GPIOC, LED2, GPIO_PIN_RESET);
HAL_GPIO_WritePin (GPIOC, LED3, GPIO_PIN_RESET);
HAL_GPIO_WritePin (GPIOC, LED4, GPIO_PIN_RESET);

};

void led_controller_Config(int* l_Set) {
	*l_Set = 0;
};

void change_set (int* l_Set) {
	(*l_Set)++;
		if (*l_Set > 3)
			*l_Set = 0;
};

void long_press (int* l_longPress, led_controller_config* l_config) {
	if (HAL_GPIO_ReadPin(GPIOA, B1_Pin)) {
		(*l_longPress)++;
	}
	else {
		*l_longPress = 0;
	}

	switch (*l_longPress) {
		case 25:
			l_config[0].delay /= 2;
			l_config[1].delay /= 2;
			l_config[2].delay /= 2;
			l_config[3].delay /= 2;
			break;

		case 50:
			led_controller_init();
			while(1) {
				HAL_GPIO_TogglePin(GPIOC, LED1);
				HAL_Delay (25);
			}
	}

};

void led_controller_run(led_controller_config* l_config, int* l_Set, int* l_pos, int* lg_delay) {

	if ((*l_pos) <= -1) {
	*l_pos = 0;
	led_controller_init();
	return;
	};


	switch (l_config[*l_Set].pattern[*l_pos]) { //!taille du tableau dans les para de la fonction -> dépassement du tableau!!/OK
		case STOP:
		*l_pos = 0;
		*lg_delay = 0;
		break;

		case DELAY:
		//HAL_Delay(l_config[*l_Set].delay);//compter nb d'appels de func() /OK
		(*lg_delay)++;

		if ((*lg_delay) == l_config[*l_Set].delay) {
			(*l_pos)++;
			*lg_delay = 0;
		}
		break;

		default:
		HAL_GPIO_TogglePin(GPIOC, l_config[*l_Set].pattern[*l_pos]);
		(*l_pos)++;
		break;
	}
};
