#include "scratch_pad.h"
#include "cursor.h"
#include <stdlib.h>





PadItem* head=NULL;
PadItem* tail=NULL;


void scratch_pad_init(){
set_up_cursor();    
head=get_cursor();
tail=head;
}


PadItem* add_item_to_pad(char data){
PadItem* new_item=calloc(1,sizeof(PadItem));
new_item->data=data;

if(head==tail){
    head=new_item;
}

PadItem* last_item_prev=tail->prev;
tail->prev=new_item;
new_item->prev=last_item_prev;
new_item->next=tail;
last_item_prev->next=new_item;

// get pixel data of character



return new_item;
}



