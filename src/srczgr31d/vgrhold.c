#include "jguipix.h"
#include "vlink.h"
#include "zint.h"
#include "zglobal.h"

#include <stdlib.h>

#include "vgrhold.h"
#include "ztrace.h"
#include "ztools.h"

#define  CI_MODULE_ID   0x0040
SWORD letterheight=24;//cellheight;
SWORD letterwidth=10;//cellwidth;
int is_mixzone=0;


void mdelay(){
  int i,j;
  for(i=0;i<1000;i++)
  for(j=0;j<3000;j++){};
}
int screenholder_visu=0;

void on_screenholder_visual()
{
	screenholder_visu=1;
}

void off_screenholder_visual()
{
	screenholder_visu=0;
}
WORD TxXToGrX(WORD x)
{
	if ( x ) 	 
 		return (x-1)*letterwidth;
	else	return( x );
}

WORD TxYToGrY(WORD y)
{
	if ( y )
		return (y-1)*letterheight;
	else	return( y );
}
void initialise_letter_size(int awidth,int aheight)
{
    letterheight=aheight;
    letterwidth=awidth;    
}

void set_transparent_output(){
    is_mixzone=1;
}
void set_normal_output(){
    is_mixzone=0;
}

//no tested
PTI_SCREENHOLDER allocate_screenholder(PTI_RECTANGLE TxCoo){
    WORD lin;
    struct link* tail=0;
    struct link* saved_tail=0;
    PTI_SCREENHOLDER a=(PTI_SCREENHOLDER)allocate(sizeof(TI_SCREENHOLDER));
    if(!a) return 0;
    a->origin.x=TxCoo->x1;
    a->origin.y=TxCoo->y1;
    a->size.cx=TxCoo->x2-TxCoo->x1+1;
    a->size.cy=TxCoo->y2-TxCoo->y1+1;
    a->head=0;
    for(lin=0;lin<a->size.cy;lin++){
        char* str=(char*)callocate(a->size.cx*letterwidth*letterheight,sizeof(char));
        if(!str){
        	a->head=get_head(tail);
        	free_screenholder(a);
        	return 0;
        	}
        saved_tail=tail;
        tail=tail_link(tail,str);
        if(!tail){
        	a->head=get_head(saved_tail);
        	free_screenholder(a);
        	return 0;
        }
    }
    a->head=get_head(tail);
    return a;
}

PTI_SCREENHOLDER free_screenholder(PTI_SCREENHOLDER a){
    if(!a) return 0;
    if(a->head){
        struct link* next_link=get_head(a->head);
        while(next_link){
            liberate((char*)next_link->data);
            next_link=next_link->succ;
        }
        destroy_all_links(a->head);
    }
    a->head=0;
    liberate(a);
    return 0;
}

void capture_limit_screen_at(PTI_POINT Tx,PTI_SCREENHOLDER a,WORD lenght){
    if(!a)return;
    if(lenght>a->size.cx) return;
    else{
        struct link* next_link=get_head(a->head);
        int gratcol=lenght*letterwidth;
	int	grx=TxXToGrX(Tx->x);
	int	gry=TxYToGrY(Tx->y);
        a->origin.x=Tx->x;
        a->origin.y=Tx->y;
        while(next_link){
	    getzone(grx,gry,gratcol,letterheight,(char*)(next_link->data));
            if(screenholder_visu){
            	filzone( grx,gry,gratcol,letterheight,1);
            	filzone( grx+1,gry+1,gratcol-2,letterheight-2,4);
            	mdelay();
            }
            gry+=letterheight;
            next_link=next_link->succ;
        }
    }
}
void capture_screen_at(PTI_POINT Tx,PTI_SCREENHOLDER a){
	if(!a)return;
	capture_limit_screen_at(Tx,a,a->size.cx);
}


void refresh_limit_screen_at(PTI_POINT Tx,PTI_SCREENHOLDER a,WORD lenght){
    if(!a)return;
    if(lenght>a->size.cx) return;
    else{
        struct link* next_link=get_head(a->head);
        int gratcol=lenght*letterwidth;
        int grx=TxXToGrX(Tx->x);
        int gry=TxYToGrY(Tx->y);
        while(next_link){
            if(screenholder_visu){
            	filzone( grx,gry,gratcol,letterheight,4);
            	filzone( grx+1,gry+1,gratcol-2,letterheight-2,1);
            	mdelay();
            }
            if(is_mixzone)
                mixzone(grx,gry,gratcol,letterheight,(char*)(next_link->data));
            else
                putzone(grx,gry,gratcol,letterheight,(char*)(next_link->data));
            gry+=letterheight;
            next_link=next_link->succ;
        }
    }
}
void refresh_screen_at(PTI_POINT Tx,PTI_SCREENHOLDER a){
    if(!a)return;
	refresh_limit_screen_at(Tx,a,a->size.cx);
}

//no tested
int scroll_screenholder(PTI_POINT p,PTI_RECTANGLE source,PTI_RECTANGLE clip){
    TI_RECTANGLE a,copy;
    TI_POINT z;
    PTI_SCREENHOLDER sss;
    copy=*source;
    ToolsMoveRectangle(p,&copy);
	if(copy.x1>clip->x2 || copy.y1>clip->y2){
		return 0;
	}    	
	if(copy.x1<clip->x1) a.x1=clip->x1; else a.x1=copy.x1;
	if(copy.y1<clip->y1) a.y1=clip->y1; else a.y1=copy.y1;
	if(copy.x2<clip->x2) a.x2=copy.x2; else a.x2=clip->x2;
	if(copy.y2<clip->y2) a.y2=copy.y2; else a.y2=clip->y2;
	p->x=a.x1;
	p->y=a.y1;
	z.x=source->x1+a.x1-copy.x1;
	z.y=source->y1+a.y1-copy.y1;
	ToolsMoveRectangle(&z,&a);
	sss=capture_screen(&a);
	if(!sss) return 0;
	refresh_screen_at(p,sss);
	free_screenholder(sss);
	return 1;
}

PTI_SCREENHOLDER capture_screen(PTI_RECTANGLE TxCoo){
    PTI_SCREENHOLDER a=allocate_screenholder(TxCoo);
    if(a) capture_screen_at(&a->origin,a);
    return a;
}

void recapture_screen(PTI_SCREENHOLDER a){
    if(!a)return;
    capture_screen_at(&a->origin,a);
}



void refresh_screen(PTI_SCREENHOLDER a){
    if(!a) return;
    refresh_screen_at(&a->origin,a);
}

void    move_screen_at(PTI_POINT point,PTI_SCREENHOLDER a){
    refresh_screen_at(point,a);
    a->origin.x=point->x;
    a->origin.y=point->y;
}


int refresh_string(PTI_SCREENHOLDER a,int strnum){
    if(!a)return 0;
    if(strnum>(int)a->size.cy) return 0;
    else{
        struct link* next_link=shift_to_tail(a->head,strnum);
        int grx=TxXToGrX(a->origin.x);
        int gry=TxYToGrY(a->origin.y+strnum);
        int gratcol=a->size.cx*letterwidth;
        if(!next_link) return 0;
        if(is_mixzone)
            mixzone(grx,gry,gratcol,letterheight,(char*)(next_link->data));
        else
            putzone(grx,gry,gratcol,letterheight,(char*)(next_link->data));
    }
    return 1;
}

int recapture_string(PTI_SCREENHOLDER a,int strnum){
    if(!a)return 0;
    if(strnum>(int)a->size.cy) return 0;
    else{
        struct link* next_link=shift_to_tail(a->head,strnum);
        int grx=TxXToGrX(a->origin.x);
        int gry=TxYToGrY(a->origin.y+strnum);
        int gratcol=a->size.cx*letterwidth;
        getzone(grx,gry,gratcol,letterheight,(char*)(next_link->data));
    }
    return 1;
}

int copy_holders(PTI_SCREENHOLDER dest,PTI_SCREENHOLDER sorc,PTI_RECTANGLE tx){
    return 0;
}

int is_holder_compatible(PTI_SCREENHOLDER a, PTI_RECTANGLE TxCoo){
	if(!a) return 0;
	if(!TxCoo) return 0;
	return( (a->size.cx==TxCoo->x2-TxCoo->x1+1) && (a->size.cy==TxCoo->y2-TxCoo->y1+1));
}


////////////////////////////////////////////////////////////////////////
//          WINDOW HOLDER PART
//
//	Especially created for window images operations(zWinSetStack)
//  We allocate memory +1 buffer string to exchange window's Fore/BackGrounds
//  The window_plank_exchange is the core of structure
//  Swap string pointers between buffer & PTI_SCREENHOLDER 
//
////////////////////////////////////////////////////////////////////////
PTI_WINDOWHOLDER allocate_windowholder(PTI_RECTANGLE TxCoo){
	PTI_WINDOWHOLDER a=(PTI_WINDOWHOLDER)allocate(sizeof(TI_WINDOWHOLDER));
	if(!a) return 0;
	else{
		WORD lenght=TxCoo->x2-TxCoo->x1+1;
		a->buffer=(char*)callocate(lenght*letterwidth*letterheight,sizeof(char));
		if(!a->buffer){
			liberate(a);
			return 0;
		}
		a->window=allocate_screenholder(TxCoo);
		if(!a->window){
			liberate(a->buffer);
			liberate(a);
			return 0;
		}
		return a;
	}
}

PTI_WINDOWHOLDER free_windowholder(PTI_WINDOWHOLDER a){
	if(!a) return 0;
	liberate(a->buffer);
	free_screenholder(a->window);
	liberate(a);
   return 0;
}

void capture_window_at(PTI_POINT Tx,PTI_WINDOWHOLDER a){
	if(!a)return;
	capture_screen_at(Tx,a->window);
}

PTI_WINDOWHOLDER capture_window(PTI_RECTANGLE TxCoo){
	PTI_WINDOWHOLDER a=allocate_windowholder(TxCoo);
	if(!a) return 0;
	recapture_screen(a->window);
	return a;
}

void recapture_window(PTI_WINDOWHOLDER a){
	if(!a) return;
	recapture_screen(a->window);
}

void refresh_window_at(PTI_POINT Tx,PTI_WINDOWHOLDER a){
	if(!a) return;
	refresh_screen_at(Tx,a->window);
}

void refresh_window(PTI_WINDOWHOLDER a){
	if(!a) return;
	refresh_screen(a->window);
}

void move_window_at(PTI_POINT point,PTI_WINDOWHOLDER a){
	if(!a) return;
	move_screen_at(point,a->window);
}

void window_plank_exchange(PTI_WINDOWHOLDER a){
	if(!a) return;
	else{
		struct link* next_link=get_head(a->window->head);
		int gratcol=a->window->size.cx*letterwidth;
        int grx=TxXToGrX(a->window->origin.x);
        int gry=TxYToGrY(a->window->origin.y);
        char* exchange;
		while(next_link){
			getzone(grx,gry,gratcol,letterheight,(char*)a->buffer);
			putzone(grx,gry,gratcol,letterheight,(char*)(next_link->data));
			exchange=a->buffer;
			a->buffer=(char*)(next_link->data);
			next_link->data=(void*)exchange;
			gry+=letterheight;
			next_link=next_link->succ;
		}
	}
}
