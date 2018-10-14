#ifndef LEDMATRIX_H_
#define LEDMATRIX_H_

#include <stdint.h>

#define RED 0
#define BLUE 1
#define GREEN 2
#define ROWS 8
#define COLMS 8
#define CHAR_ROWS 8
#define CHAR_COLMS 8
#define RGB 3

extern uint8_t color;

void draw_char_matrix_frame(char letter);
void send_start_frame(void);
void send_end_frame(void);
void draw_matrix_frame(void);
void make_date_frame(void);
void draw_rgb_frame(void);


#endif /*LEDMATRIX_H_*/
