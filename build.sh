# !/bin/bash

Run=$1

if [ "$Run" == "run" ]; then
    cmake --build build
    SDL_VIDEODRIVER=x11 build/text-editor

elif [ "$Run" == "setup" ]; then
    cmake -B build

    
fi
