#ifndef VGRHOLD_H
#define VGRHOLD_H

#include"zint.h"


typedef struct{
    struct link*    head;                       //pointer on next string
    TI_POINT        origin;                     //current text position
    TI_SIZE         size;                       //number of text columns and lines
}TI_SCREENHOLDER, FAR PTR PTI_SCREENHOLDER;

void initialise_letter_size(int awidth,int aheight);

void set_transparent_output(); 
void set_normal_output();

PTI_SCREENHOLDER allocate_screenholder(PTI_RECTANGLE TxCoo);
PTI_SCREENHOLDER free_screenholder(PTI_SCREENHOLDER a);

int is_holder_compatible(PTI_SCREENHOLDER a, PTI_RECTANGLE b);

void capture_screen_at(PTI_POINT Tx,PTI_SCREENHOLDER a);
PTI_SCREENHOLDER capture_screen(PTI_RECTANGLE TxCoo);
void recapture_screen(PTI_SCREENHOLDER a);

void refresh_screen_at(PTI_POINT Tx,PTI_SCREENHOLDER a);
void refresh_screen(PTI_SCREENHOLDER a);
void move_screen_at(PTI_POINT point,PTI_SCREENHOLDER a);

//   Bad functions  VAP 2.7.01
// Succesfull limit refresh is possible at limit recapture only :((
void refresh_limit_screen_at(PTI_POINT Tx,PTI_SCREENHOLDER a,WORD lenght);
void capture_limit_screen_at(PTI_POINT Tx,PTI_SCREENHOLDER a,WORD lenght);
//

int refresh_string(PTI_SCREENHOLDER a,int strnum);
int recapture_string(PTI_SCREENHOLDER a,int strnum);
int scroll_screenholder(PTI_POINT p,PTI_RECTANGLE source,PTI_RECTANGLE clip);


typedef struct{
	PTI_SCREENHOLDER 	window;
	char*				buffer;			
}TI_WINDOWHOLDER,FAR PTR PTI_WINDOWHOLDER;

PTI_WINDOWHOLDER allocate_windowholder(PTI_RECTANGLE TxCoo);
PTI_WINDOWHOLDER free_windowholder(PTI_WINDOWHOLDER a);
void capture_window_at(PTI_POINT Tx,PTI_WINDOWHOLDER a);
PTI_WINDOWHOLDER capture_window(PTI_RECTANGLE TxCoo);
void recapture_window(PTI_WINDOWHOLDER a);

void refresh_window_at(PTI_POINT Tx,PTI_WINDOWHOLDER a);
void refresh_window(PTI_WINDOWHOLDER a);
void move_window_at(PTI_POINT point,PTI_WINDOWHOLDER a);
void window_plank_exchange(PTI_WINDOWHOLDER a);

void on_screenholder_visual();
void off_screenholder_visual();

#endif
