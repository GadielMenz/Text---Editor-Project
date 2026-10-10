#ifndef SCARTCHPAD
#define SCARTCHPAD


typedef struct PadItem PadItem;

typedef struct PadItem
{
   char data; 
   PadItem* prev;
   PadItem* next;

} PadItem;



extern PadItem* head;
extern PadItem* tail;

void scratch_pad_init();

PadItem* add_item_to_pad(char data);


#endif