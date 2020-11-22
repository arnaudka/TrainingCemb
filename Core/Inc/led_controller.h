/*
 * led_controller.h
 *
 *  Created on: 12 nov. 2020
 *      Author: Adrien
 */

#ifndef SRC_LED_CONTROLLER_H_
#define SRC_LED_CONTROLLER_H_

#define CONF_MAX 4 //NOMBRE DE CONFIG
#define MODE_MAX 4 //NOMBRE DE MODES
#define PAT_MAX 20 //PATTERN MAX
#define SQ_MAX 20  //NOMBRE DE SEQUENCES
#define NB_SPEED 4 //NOMBRE DE VITESSES

enum {
	MODE_CHENILLE   = 0,
	MODE_LOADING    = 1,
	MODE_UNLOADING  = 2,
	MODE_ROUND_TRIP = 3,
};

enum {
	CLOCKWISE         = 1,
	COUNTER_CLOCKWISE =-1,
};

enum {
	STOP = 0,
	DELAY = 1,
	LED1 = 0x40UL,
	LED2 = 0x200UL,
	LED3 = 0x80UL,
	LED4 = 0x100UL,
};

typedef struct { //EX -> décl. sous main /OK
	int mode;
	int delay;
	int patSize; //.patSize = sizeof(config[i].pattern)/sizeof(int)
	int pattern[PAT_MAX];
} led_controller_config;

void led_controller_init();
void led_controller_Config(int* l_Set);
void led_controller_run(led_controller_config* l_config, int* l_Set, int* l_pos, int* lg_delay);
void led_controller_stop();
void change_set (int* l_Set);
void long_press (int* longPress, led_controller_config* l_config);

#endif /* SRC_LED_CONTROLLER_H_ */
