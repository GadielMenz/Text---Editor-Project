#include "cursor.h"
#include "scratch_pad.h"
#include "renderer.h"
#include <stdlib.h>
#include <stdio.h>






static PadItem cursor={.data='\0',.next=NULL,.prev=NULL};

void set_up_cursor(){
cursor.pixel_data=calloc(font_w*font_h,sizeof(bool));
bool (*cursor_pixel)[font_w]=(bool (*)[font_w])cursor.pixel_data;
for (size_t i = 0; i < font_h; i++)
{
    for (size_t a = 0; a < (font_w/2); a++)
    {
        cursor_pixel[i][a]=true;
    }
    
}

}

PadItem* get_cursor(){
return &cursor;
}



void move_cursor(CursorDir direction){
   
    switch (direction)
    {
    case LEFT:
        if(cursor.prev!=NULL){
            PadItem* prev=cursor.prev;
            prev->next=cursor.next;
            cursor.next=prev;
            cursor.prev=prev->prev;
            prev->prev=&cursor;
            
            if(cursor.prev==NULL){
                // update scatch_pad head to cursor
            }

        }

        break;

    case RIGHT:
        if(cursor.next!=NULL){
            PadItem* next=cursor.next;
            next->prev=cursor.prev;
            cursor.prev=next;
            cursor.next=next->next;
            if(cursor.next==NULL){
                // update scatch_pad tail to cursor
            }
            next->next=&cursor;
        }    
        else{
            add_item_to_pad(' ');
        }
        break;

    case TOP:
        printf("Top cursor movement not impl");
        break;    
    default:
        printf("Down cursor movement not impl");
        break;
    }


}
