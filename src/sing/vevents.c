
#ifndef _vevents_c
#define _vevents_c
#include <stdio.h>
#include "visual.h"

private struct accept_events_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	value_NoCreate;
	int	value_NoShow;
	int	value_NoGet;
	int	value_NoEvent;
	int	value_NoLose;
	int	value_NoHide;
	int	value_NoRemove;
	char	signature[8];
	} _Context;
private int on_Accept_event() {
	return(13);
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}

private	int	accept_events_create( char * pptr0,char * pptr1,char * pptr2,char * pptr3,char * pptr4,char * pptr5,char * pptr6)
{
	_Context.keycode=0;
	_Context.focus_item=1;
	_Context.focus_items=16;
	if ( _Context.keycode != 27 ) {
		strcpy(_Context.signature,"WWWWWWW");
		transferXsignature(_Context.signature,_Context.signature);
		transferin((void *) 0, 0, pptr0);
		if (!( pptr0 )) _Context.value_NoCreate=0;
		else	_Context.value_NoCreate = *((int *)pptr0);
		transferin((void *) 0, 0, pptr1);
		if (!( pptr1 )) _Context.value_NoShow=0;
		else	_Context.value_NoShow = *((int *)pptr1);
		transferin((void *) 0, 0, pptr2);
		if (!( pptr2 )) _Context.value_NoGet=0;
		else	_Context.value_NoGet = *((int *)pptr2);
		transferin((void *) 0, 0, pptr3);
		if (!( pptr3 )) _Context.value_NoEvent=0;
		else	_Context.value_NoEvent = *((int *)pptr3);
		transferin((void *) 0, 0, pptr4);
		if (!( pptr4 )) _Context.value_NoLose=0;
		else	_Context.value_NoLose = *((int *)pptr4);
		transferin((void *) 0, 0, pptr5);
		if (!( pptr5 )) _Context.value_NoHide=0;
		else	_Context.value_NoHide = *((int *)pptr5);
		transferin((void *) 0, 0, pptr6);
		if (!( pptr6 )) _Context.value_NoRemove=0;
		else	_Context.value_NoRemove = *((int *)pptr6);
		}
	return(0);
}

private	int	accept_events_remove( char * pptr0,char * pptr1,char * pptr2,char * pptr3,char * pptr4,char * pptr5,char * pptr6)
{
	if ( _Context.keycode != 27 ) {
		strcpy(_Context.signature,"WWWWWWW");
		transferXsignature(_Context.signature,_Context.signature);
		transferout((void *) 0, 0, pptr0);
		if ( pptr0 != (char *) 0)
			*((int*)pptr0) = _Context.value_NoCreate;
		transferout((void *) 0, 0, pptr1);
		if ( pptr1 != (char *) 0)
			*((int*)pptr1) = _Context.value_NoShow;
		transferout((void *) 0, 0, pptr2);
		if ( pptr2 != (char *) 0)
			*((int*)pptr2) = _Context.value_NoGet;
		transferout((void *) 0, 0, pptr3);
		if ( pptr3 != (char *) 0)
			*((int*)pptr3) = _Context.value_NoEvent;
		transferout((void *) 0, 0, pptr4);
		if ( pptr4 != (char *) 0)
			*((int*)pptr4) = _Context.value_NoLose;
		transferout((void *) 0, 0, pptr5);
		if ( pptr5 != (char *) 0)
			*((int*)pptr5) = _Context.value_NoHide;
		transferout((void *) 0, 0, pptr6);
		if ( pptr6 != (char *) 0)
			*((int*)pptr6) = _Context.value_NoRemove;
		}

	return(0);
}

private	int	accept_events_show()
{
	window(70,80,460,360,2,"Sing : Version 1.0a",19,3);
	frame(80,110,440,320,4);
	text(90,120,210,20,2,26,0,"Event Methods  ",15,0);
	text(260,120,238,16,2,26,0,"Event Behaviour",15,0);
	frame(255,150,255,210,2);
	button(90,150,160,32,2,26,0,"OnCreate",8,0);
	button(90,180,160,32,2,26,0,"OnShow",6,0);
	button(90,210,160,32,2,26,0,"OnGetFocus",10,0);
	button(90,240,160,32,2,26,0,"OnEvent",7,0);
	button(90,270,160,32,2,26,0,"OnLoseFocus",11,0);
	button(90,300,160,32,2,26,0,"OnHide",6,0);
	button(90,330,160,32,2,26,0,"OnRemove",8,0);
	select(260,155,240,64,1,26,0,parse_selection(EventControlList,&_Context.value_NoCreate),0);
	select(260,186,240,64,1,26,0,parse_selection(EventControlList,&_Context.value_NoShow),0);
	select(260,215,240,64,1,26,0,parse_selection(EventControlList,&_Context.value_NoGet),0);
	select(260,245,240,64,1,26,0,parse_selection(EventControlList,&_Context.value_NoEvent),0);
	select(260,275,240,64,1,26,0,parse_selection(EventControlList,&_Context.value_NoLose),0);
	select(260,305,240,64,1,26,0,parse_selection(EventControlList,&_Context.value_NoHide),0);
	select(260,335,240,64,1,26,0,parse_selection(EventControlList,&_Context.value_NoRemove),0);
	button(90,390,120,30,2,26,0,"Accept",6,0);
	button(390,390,120,30,2,26,0,"Cancel",6,0);

	return(0);
}


private	int	accept_events_event()
{
	int	mx,my,mt,mb;
	if ((mt = get_mimo_type()) != _MIMO_UP) return(-1); 
	mx = get_mimo_column();
	my = get_mimo_row();
	if (( mx >= 90 ) 
	&&  ( my >= 150 ) 
	&&  ( mx <= 250 ) 
	&&  ( my <= 182 )) 
		return(1); /* auto637 */
	if (( mx >= 90 ) 
	&&  ( my >= 180 ) 
	&&  ( mx <= 250 ) 
	&&  ( my <= 212 )) 
		return(2); /* auto638 */
	if (( mx >= 90 ) 
	&&  ( my >= 210 ) 
	&&  ( mx <= 250 ) 
	&&  ( my <= 242 )) 
		return(3); /* auto639 */
	if (( mx >= 90 ) 
	&&  ( my >= 240 ) 
	&&  ( mx <= 250 ) 
	&&  ( my <= 272 )) 
		return(4); /* auto640 */
	if (( mx >= 90 ) 
	&&  ( my >= 270 ) 
	&&  ( mx <= 250 ) 
	&&  ( my <= 302 )) 
		return(5); /* auto641 */
	if (( mx >= 90 ) 
	&&  ( my >= 300 ) 
	&&  ( mx <= 250 ) 
	&&  ( my <= 332 )) 
		return(6); /* auto642 */
	if (( mx >= 90 ) 
	&&  ( my >= 330 ) 
	&&  ( mx <= 250 ) 
	&&  ( my <= 362 )) 
		return(7); /* auto643 */
	if (( mx >= 260 ) 
	&&  ( my >= 155 ) 
	&&  ( mx <= 500 ) 
	&&  ( my <= 219 )) 
		return(8); /* NoCreate */
	if (( mx >= 260 ) 
	&&  ( my >= 186 ) 
	&&  ( mx <= 500 ) 
	&&  ( my <= 250 )) 
		return(9); /* NoShow */
	if (( mx >= 260 ) 
	&&  ( my >= 215 ) 
	&&  ( mx <= 500 ) 
	&&  ( my <= 279 )) 
		return(10); /* NoGet */
	if (( mx >= 260 ) 
	&&  ( my >= 245 ) 
	&&  ( mx <= 500 ) 
	&&  ( my <= 309 )) 
		return(11); /* NoEvent */
	if (( mx >= 260 ) 
	&&  ( my >= 275 ) 
	&&  ( mx <= 500 ) 
	&&  ( my <= 339 )) 
		return(12); /* NoLose */
	if (( mx >= 260 ) 
	&&  ( my >= 305 ) 
	&&  ( mx <= 500 ) 
	&&  ( my <= 369 )) 
		return(13); /* NoHide */
	if (( mx >= 260 ) 
	&&  ( my >= 335 ) 
	&&  ( mx <= 500 ) 
	&&  ( my <= 399 )) 
		return(14); /* NoRemove */
	if (( mx >= 90 ) 
	&&  ( my >= 390 ) 
	&&  ( mx <= 210 ) 
	&&  ( my <= 420 )) 
		return(15); /* Accept */
	if (( mx >= 390 ) 
	&&  ( my >= 390 ) 
	&&  ( mx <= 510 ) 
	&&  ( my <= 420 )) 
		return(16); /* Cancel */

	return(-1);
}


private	int	accept_events_focus()
{
	while( mimo_kbhit() ) (void) mimo_getch();
	while(1) {
		switch ( _Context.focus_item ) {
			case	1 :
				button(90,150,160,32,2,26,0,"OnCreate",8,2);
				_Context.keycode = mimo_getch();
				button(90,150,160,32,2,26,0,"OnCreate",8,0);
				break;
			case	2 :
				button(90,180,160,32,2,26,0,"OnShow",6,2);
				_Context.keycode = mimo_getch();
				button(90,180,160,32,2,26,0,"OnShow",6,0);
				break;
			case	3 :
				button(90,210,160,32,2,26,0,"OnGetFocus",10,2);
				_Context.keycode = mimo_getch();
				button(90,210,160,32,2,26,0,"OnGetFocus",10,0);
				break;
			case	4 :
				button(90,240,160,32,2,26,0,"OnEvent",7,2);
				_Context.keycode = mimo_getch();
				button(90,240,160,32,2,26,0,"OnEvent",7,0);
				break;
			case	5 :
				button(90,270,160,32,2,26,0,"OnLoseFocus",11,2);
				_Context.keycode = mimo_getch();
				button(90,270,160,32,2,26,0,"OnLoseFocus",11,0);
				break;
			case	6 :
				button(90,300,160,32,2,26,0,"OnHide",6,2);
				_Context.keycode = mimo_getch();
				button(90,300,160,32,2,26,0,"OnHide",6,0);
				break;
			case	7 :
				button(90,330,160,32,2,26,0,"OnRemove",8,2);
				_Context.keycode = mimo_getch();
				button(90,330,160,32,2,26,0,"OnRemove",8,0);
				break;
			case	8 :
				_Context.keycode = select(260,155,240,64,1,26,0,parse_selection(EventControlList,&_Context.value_NoCreate),2);
				break;
			case	9 :
				_Context.keycode = select(260,186,240,64,1,26,0,parse_selection(EventControlList,&_Context.value_NoShow),2);
				break;
			case	10 :
				_Context.keycode = select(260,215,240,64,1,26,0,parse_selection(EventControlList,&_Context.value_NoGet),2);
				break;
			case	11 :
				_Context.keycode = select(260,245,240,64,1,26,0,parse_selection(EventControlList,&_Context.value_NoEvent),2);
				break;
			case	12 :
				_Context.keycode = select(260,275,240,64,1,26,0,parse_selection(EventControlList,&_Context.value_NoLose),2);
				break;
			case	13 :
				_Context.keycode = select(260,305,240,64,1,26,0,parse_selection(EventControlList,&_Context.value_NoHide),2);
				break;
			case	14 :
				_Context.keycode = select(260,335,240,64,1,26,0,parse_selection(EventControlList,&_Context.value_NoRemove),2);
				break;
			case	15 :
				button(90,390,120,30,2,26,0,"Accept",6,2);
				_Context.keycode = mimo_getch();
				button(90,390,120,30,2,26,0,"Accept",6,0);
				break;
			case	16 :
				button(390,390,120,30,2,26,0,"Cancel",6,2);
				_Context.keycode = mimo_getch();
				button(390,390,120,30,2,26,0,"Cancel",6,0);
				break;

			}
		switch ( _Context.keycode ) {
		case	12 :
			_Context.focus_item=1;
			accept_events_show();
			continue;
		case	2 :
			_Context.focus_item=16;
			accept_events_show();
			continue;
			case	256 :
				switch ((_Context.focus_item = accept_events_event())) {
					case	1 :
						continue;
					case	2 :
						continue;
					case	3 :
						continue;
					case	4 :
						continue;
					case	5 :
						continue;
					case	6 :
						continue;
					case	7 :
						continue;
					case	8 :
						continue;
					case	9 :
						continue;
					case	10 :
						continue;
					case	11 :
						continue;
					case	12 :
						continue;
					case	13 :
						continue;
					case	14 :
						continue;
					case	15 :
		if ((_Context.keycode = on_Accept_event()) != -1) break;
						continue;
					case	16 :
		if ((_Context.keycode = on_Cancel_event()) != -1) break;
						continue;
					case	-1 :
					default :
						_Context.focus_item=1;
					continue;
					}
				break;
			case	27 :
			case	13 :
				break;
			case	9 :
			case	5 :
			if ( _Context.focus_item < _Context.focus_items ) {
				_Context.focus_item++; 
			} else {
				_Context.focus_item=1; 
			}
			continue;
			case	11 :
			if ( _Context.focus_item > 1 ) {
				_Context.focus_item--; 
			} else {
				_Context.focus_item=16;
			}
			continue;

			}
		break;
		}
	return(0);

}

public	int	accept_events( char * pptr0,char * pptr1,char * pptr2,char * pptr3,char * pptr4,char * pptr5,char * pptr6)
{
	accept_events_create(pptr0,pptr1,pptr2,pptr3,pptr4,pptr5,pptr6);
	accept_events_show();
	accept_events_focus();
	accept_events_remove(pptr0,pptr1,pptr2,pptr3,pptr4,pptr5,pptr6);
	return(_Context.keycode);
}
/* End of File */

#endif /* _vevents_c */
