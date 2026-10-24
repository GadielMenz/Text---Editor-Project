cmake_minimum_required(VERSION 3.21)
project(text-editor C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED)

add_executable(text-editor
    src/main.c
    src/components/windows.c
    src/components/cursor.c
    src/components/scratch_pad.c
    src/components/renderer.c

    )

target_include_directories(text-editor PRIVATE include)


target_link_libraries(text-editor PRIVATE SDL3::SDL3)

# Replace 'your_binary_name' with your actual target
target_compile_options(text-editor PRIVATE -g)