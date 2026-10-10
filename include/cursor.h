#ifndef CURSOR
#define CURSOR


typedef struct PadItem PadItem;

typedef enum CursorDir{
TOP,
DOWN,
RIGHT,
LEFT
}CursorDir;

PadItem* get_cursor();

#endif