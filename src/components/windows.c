#include "windows.h"
#include "renderer.h"



// these win sizes are in pixels
static int win_w=1100;
static int win_h=1000;
static SDL_Window* window=NULL;

size_t get_window_w_or_h(bool is_w){
    if(is_w) return win_w;
    return win_h;
}



// copies whatever is in the frame buffer onto the window
void update_window(){
    if(window==NULL || frame_bufffer==NULL){
        printf("Window Update Error: window or frame buffer not initialized\n");
        return;
    }

    SDL_Surface* win_surface=SDL_GetWindowSurface(window);
    if(win_surface==NULL){
        printf("Window Update Error:%s\n",SDL_GetError());
        return;
    }

    // wraps the frame buffer (no copy), each pixel is 0xXXRRGGBB
    SDL_Surface* frame_surface=SDL_CreateSurfaceFrom(win_w,win_h,SDL_PIXELFORMAT_XRGB8888,frame_bufffer,win_w*sizeof(uint32_t));
    if(frame_surface==NULL){
        printf("Window Update Error:%s\n",SDL_GetError());
        return;
    }

    SDL_BlitSurface(frame_surface,NULL,win_surface,NULL);
    SDL_DestroySurface(frame_surface);

    if(!SDL_UpdateWindowSurface(window)){
        printf("Window Update Error:%s\n",SDL_GetError());
    }
}

static bool event_handler(SDL_Event event){

switch (event.type)
{
case SDL_EVENT_KEY_DOWN:
    printf("A key was entered\n");
  
    break;

case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
    printf("Window is been destroyed\n");
    SDL_DestroyWindow(window);
    break;    

case SDL_EVENT_WINDOW_DESTROYED:
    printf("Window Destroyed\n");
    SDL_Quit();
    return false;     
case SDL_EVENT_WINDOW_RESIZED:
case SDL_EVENT_WINDOW_MAXIMIZED:
case SDL_EVENT_WINDOW_RESTORED:
    printf("Window size changing..\n");
    if (window==NULL)
    {
        printf("Window resize failed:Window Object Invalid\n");
        return false;
    }
    
    SDL_GetWindowSizeInPixels(window,&win_w,&win_h);
    free(frame_bufffer);
    renderer_init();
    printf("New sizes w=%i and h=%i\n",win_w,win_h);
    break;    

}
return true;
}

static  void setup_event_sys(){
SDL_Event events;
bool is_win_open=true;

while (is_win_open)
{
    if(SDL_PollEvent(&events)){
    
        is_win_open= event_handler(events);
        if(is_win_open){
        render();
        update_window();
        }
          
    }
}


}


void create_window(){

printf("Initialising SDL...\n");
if(!SDL_Init(SDL_INIT_VIDEO)){
    printf("SDL Init Failed:%s\n",SDL_GetError());
    abort();
}
printf("SDL initialized.\n");

printf("Creating a windows...\n");
SDL_WindowFlags win_flags=SDL_WINDOW_RESIZABLE | SDL_WINDOW_INPUT_FOCUS;
window=SDL_CreateWindow("Echo",win_w,win_h,win_flags);


if(window==NULL){
    printf("Window Creation failed:%s\n",SDL_GetError());
    abort();
}

setup_event_sys();
}

