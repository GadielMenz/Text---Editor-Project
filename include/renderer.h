#ifndef RENDERER
#define RENDERER
#include <stdlib.h>
#include <stdint.h>





extern size_t font_h;
extern size_t font_w;


extern uint32_t font_color;
extern uint32_t* frame_bufffer;
void renderer_init();
void render();

#endif