#include <stdlib.h>
#include <stdint.h>
#include<stdio.h>
#include "scratch_pad.h"
#include "windows.h"



const size_t font_w=30; // do not change this value 
const size_t font_h=40; // do not change this value 


const uint32_t font_color=UINT32_MAX;

uint32_t* frame_bufffer=NULL;




void renderer_init(){
    //checking if scratch-pad has been setup
    if(head==NULL){
        printf("Renderer Init Error: Cannot initialize renderer without initializing scratch-pad");
        abort();
    }
    frame_bufffer= calloc(get_window_w_or_h(true)*get_window_w_or_h(false),sizeof(uint32_t));
}

void render(){
size_t col=10;
size_t row=10;
size_t win_h=get_window_w_or_h(false);
size_t win_w=get_window_w_or_h(true);    
memset(frame_bufffer,0,win_h*win_w*sizeof(uint32_t));    
uint32_t (*frame)[win_w]=(uint32_t(*)[win_w])frame_bufffer;


PadItem* current=head;

while(current!=NULL){
    
bool (*pixel_data)[font_w]=(bool (*)[font_w])current->pixel_data;
size_t inner_col=col;

for (size_t i = 0; i < font_h; i++)
{
    size_t inner_r=row;

    for (size_t a = 0; a < font_w; a++)
    {   
        if(pixel_data[i][a]){
            frame[inner_col][inner_r]=font_color;
        }
        
        inner_r++;
    }
    inner_col++;
}

if((row+font_w)>win_w){
row=0;
col+=font_h;
}
else{
row+=font_w;
}

current=current->next;
}





}

