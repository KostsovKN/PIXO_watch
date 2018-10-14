#ifndef FRAMES_H_
#define FRAMES_H_

#include <stdint.h>
#include "ledmatrix.h"
extern uint8_t mask_G[6][12];

extern uint8_t mask_R[6][12];

extern uint8_t mask_U[6][12];

extern uint8_t mask_P[6][12];

extern uint8_t mask_E[6][12];

extern uint8_t mask_T[6][12];

extern volatile uint8_t b_w_frame[ROWS][COLMS];

extern volatile uint8_t b_frame[ROWS][COLMS];

extern volatile uint8_t w_frame[ROWS][COLMS];

extern volatile uint8_t frame_sent_flag;

extern volatile uint8_t rgb_frame[ROWS][COLMS][RGB];

extern volatile uint8_t num_all[10][3][3];

extern volatile uint8_t num_0[3][3];

extern volatile uint8_t num_1[3][3];

extern volatile uint8_t num_2[3][3];

extern volatile uint8_t num_3[3][3];

extern volatile uint8_t num_4[3][3];

extern volatile uint8_t num_5[3][3];
	
extern volatile uint8_t num_6[3][3];

extern volatile uint8_t num_7[3][3];
	
extern volatile uint8_t num_8[3][3];
		
extern volatile uint8_t num_9[3][3];

#endif /*FRAMES_H_*/

