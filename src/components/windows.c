#include "windows.h"



// these win sizes are in pixels
static size_t win_w=1100;
static size_t win_h=1000;
static SDL_Window* window=NULL;

size_t get_window_w_or_h(bool is_w){
    if(is_w) return win_w;
    return win_h;
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
    
    SDL_GetWindowSizeInPixels(window,(int*)&win_w,(int*)&win_h);
    printf("New sizes w=%lu and h=%lu\n",win_w,win_h);
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

