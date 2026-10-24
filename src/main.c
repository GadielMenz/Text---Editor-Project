#include <stdio.h>
#include "windows.h"
#include "scratch_pad.h"
#include "renderer.h"



int main(){
scratch_pad_init();   
renderer_init();    
create_window();
return 0;
}