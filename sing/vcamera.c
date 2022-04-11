
#ifndef _vcamera_c
#define _vcamera_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vcamera.sng  */
/* Target         : vcamera.c  */
/* Identification : 0.0-1065019113-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_camera_properties_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_Name[58];
	char	buffer_AtX[11];
	char	buffer_AtY[11];
	char	buffer_AtZ[10];
	char	buffer_ToX[11];
	char	buffer_ToY[11];
	int	value_Direction;
	char	buffer_Timer[26];
	char	buffer_Step[11];
	char	buffer_NbX[11];
	char	buffer_nbY[11];
	char	buffer_NbZ[11];
	char	buffer_StepX[11];
	char	buffer_StepY[11];
	char	buffer_StepZ[11];
	int	value_DynamicSize;
	int	value_SaveForms;
	int	value_SaveImages;
	char	buffer_ImageName[58];
	int	value_Auto3394;
	char	buffer_Colour[11];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[22];
	} * _Context;

private	int	accept_camera_properties_create(
	char * pName,
	char * pAtX,
	char * pAtY,
	char * pAtZ,
	char * pToX,
	char * pToY,
	char * pDirection,
	char * pTimer,
	char * pStep,
	char * pNbX,
	char * pnbY,
	char * pNbZ,
	char * pStepX,
	char * pStepY,
	char * pStepZ,
	char * pDynamicSize,
	char * pSaveForms,
	char * pSaveImages,
	char * pImageName,
	char * pAuto3394,
	char * pColour)
{

	if (!(_Context = allocate( sizeof( struct accept_camera_properties_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=25;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWWWWWSWWWWWWWWWWSWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Name, 57, pName);
		visual_transferin(_Context->buffer_AtX, 10, pAtX);
		visual_transferin(_Context->buffer_AtY, 10, pAtY);
		visual_transferin(_Context->buffer_AtZ, 9, pAtZ);
		visual_transferin(_Context->buffer_ToX, 10, pToX);
		visual_transferin(_Context->buffer_ToY, 10, pToY);
		visual_transferin((void *) 0, 0, pDirection);
		if (!( pDirection )) _Context->value_Direction=0;
		else	_Context->value_Direction = *((int *)pDirection);
		visual_transferin(_Context->buffer_Timer, 25, pTimer);
		visual_transferin(_Context->buffer_Step, 10, pStep);
		visual_transferin(_Context->buffer_NbX, 10, pNbX);
		visual_transferin(_Context->buffer_nbY, 10, pnbY);
		visual_transferin(_Context->buffer_NbZ, 10, pNbZ);
		visual_transferin(_Context->buffer_StepX, 10, pStepX);
		visual_transferin(_Context->buffer_StepY, 10, pStepY);
		visual_transferin(_Context->buffer_StepZ, 10, pStepZ);
		visual_transferin((void *) 0, 0, pDynamicSize);
		if (!( pDynamicSize )) _Context->value_DynamicSize=0;
		else	_Context->value_DynamicSize = *((int *)pDynamicSize);
		visual_transferin((void *) 0, 0, pSaveForms);
		if (!( pSaveForms )) _Context->value_SaveForms=0;
		else	_Context->value_SaveForms = *((int *)pSaveForms);
		visual_transferin((void *) 0, 0, pSaveImages);
		if (!( pSaveImages )) _Context->value_SaveImages=0;
		else	_Context->value_SaveImages = *((int *)pSaveImages);
		visual_transferin(_Context->buffer_ImageName, 57, pImageName);
		visual_transferin((void *) 0, 0, pAuto3394);
		if (!( pAuto3394 )) _Context->value_Auto3394=0;
		else	_Context->value_Auto3394 = *((int *)pAuto3394);
		visual_transferin(_Context->buffer_Colour, 10, pColour);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(95,100,610+10,400+10);
	return(0);
}

private	int	accept_camera_properties_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,95,100);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_camera_properties_remove(
	char * pName,
	char * pAtX,
	char * pAtY,
	char * pAtZ,
	char * pToX,
	char * pToY,
	char * pDirection,
	char * pTimer,
	char * pStep,
	char * pNbX,
	char * pnbY,
	char * pNbZ,
	char * pStepX,
	char * pStepY,
	char * pStepZ,
	char * pDynamicSize,
	char * pSaveForms,
	char * pSaveImages,
	char * pImageName,
	char * pAuto3394,
	char * pColour)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWWWWWSWWWWWWWWWWSWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Name, 57, pName);
		visual_transferout(_Context->buffer_AtX, 10, pAtX);
		visual_transferout(_Context->buffer_AtY, 10, pAtY);
		visual_transferout(_Context->buffer_AtZ, 9, pAtZ);
		visual_transferout(_Context->buffer_ToX, 10, pToX);
		visual_transferout(_Context->buffer_ToY, 10, pToY);
		visual_transferout((void *) 0, 0, pDirection);
		if ( pDirection != (char *) 0)
			*((int*)pDirection) = _Context->value_Direction;
		visual_transferout(_Context->buffer_Timer, 25, pTimer);
		visual_transferout(_Context->buffer_Step, 10, pStep);
		visual_transferout(_Context->buffer_NbX, 10, pNbX);
		visual_transferout(_Context->buffer_nbY, 10, pnbY);
		visual_transferout(_Context->buffer_NbZ, 10, pNbZ);
		visual_transferout(_Context->buffer_StepX, 10, pStepX);
		visual_transferout(_Context->buffer_StepY, 10, pStepY);
		visual_transferout(_Context->buffer_StepZ, 10, pStepZ);
		visual_transferout((void *) 0, 0, pDynamicSize);
		if ( pDynamicSize != (char *) 0)
			*((int*)pDynamicSize) = _Context->value_DynamicSize;
		visual_transferout((void *) 0, 0, pSaveForms);
		if ( pSaveForms != (char *) 0)
			*((int*)pSaveForms) = _Context->value_SaveForms;
		visual_transferout((void *) 0, 0, pSaveImages);
		if ( pSaveImages != (char *) 0)
			*((int*)pSaveImages) = _Context->value_SaveImages;
		visual_transferout(_Context->buffer_ImageName, 57, pImageName);
		visual_transferout((void *) 0, 0, pAuto3394);
		if ( pAuto3394 != (char *) 0)
			*((int*)pAuto3394) = _Context->value_Auto3394;
		visual_transferout(_Context->buffer_Colour, 10, pColour);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_camera_properties_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,95,100);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(95,100,610,400,2,"Sing : Version 1.0a",19,0x403);
	visual_image(97,120,604,375,"skin.gif",4);
	visual_text(115,130,560,20,3,27,0,"Project 3D Camera Properties",28,770);
	visual_text(115,160,110,20,2,27,0,"Name",4,2);
	visual_text(115,190,110,20,2,27,0,"Position",8,2);
	visual_text(115,220,100,20,2,27,0,"Focus",5,2);
	visual_text(115,250,110,20,2,27,0,"Direction",9,2);
	visual_text(115,280,110,20,2,27,0,"Configuration",13,2);
	visual_text(435,280,28,16,2,27,0,"Step",4,2);
	visual_frame(225,160,456+2,16+2,5);
	visual_text(225+1,160+1,456,16,1,26,0,_Context->buffer_Name,57,0);
	visual_frame(225,190,80+2,16+2,5);
	visual_text(225+1,190+1,80,16,1,26,0,_Context->buffer_AtX,10,0);
	visual_frame(345,190,80+2,16+2,5);
	visual_text(345+1,190+1,80,16,1,26,0,_Context->buffer_AtY,10,0);
	visual_frame(465,190,72+2,16+2,5);
	visual_text(465+1,190+1,72,16,1,26,0,_Context->buffer_AtZ,9,0);
	visual_frame(225,220,80+2,16+2,5);
	visual_text(225+1,220+1,80,16,1,26,0,_Context->buffer_ToX,10,0);
	visual_frame(345,220,80+2,16+2,5);
	visual_text(345+1,220+1,80,16,1,26,0,_Context->buffer_ToY,10,0);
	visual_select(225,250,200,80,1,26,0,parse_selection("forward|backward|left|right|up|down",&_Context->value_Direction),512);
	visual_frame(225,280,200+2,16+2,5);
	visual_text(225+1,280+1,200,16,1,26,0,_Context->buffer_Timer,25,0);
	visual_frame(465,280,80+2,16+2,5);
	visual_text(465+1,280+1,80,16,1,26,0,_Context->buffer_Step,10,0);
	visual_text(211,190,20,20,2,27,0,"X",1,3);
	visual_text(329,190,20,20,2,27,0,"Y",1,3);
	visual_text(445,190,20,20,2,27,0,"Z",1,3);
	visual_text(215,220,10,20,2,27,0,"X",1,3);
	visual_text(335,220,10,20,2,27,0,"Y",1,3);
	visual_button(115,450,120,30,2,34,0,"&Accept",7,0);
	visual_button(565,450,120,30,2,34,0,"&Cancel",7,0);
	visual_text(115,310,100,20,2,27,0,"Sizes",5,0);
	visual_text(115,340,110,20,2,27,0,"Distance",8,2);
	visual_frame(225,310,80+2,16+2,5);
	visual_text(225+1,310+1,80,16,1,26,0,_Context->buffer_NbX,10,0);
	visual_frame(345,310,80+2,16+2,5);
	visual_text(345+1,310+1,80,16,1,0,0,_Context->buffer_nbY,10,0);
	visual_frame(465,310,80+2,16+2,5);
	visual_text(465+1,310+1,80,16,1,26,0,_Context->buffer_NbZ,10,0);
	visual_frame(225,340,80+2,16+2,5);
	visual_text(225+1,340+1,80,16,1,26,0,_Context->buffer_StepX,10,0);
	visual_frame(345,340,80+2,16+2,5);
	visual_text(345+1,340+1,80,16,1,26,0,_Context->buffer_StepY,10,0);
	visual_frame(465,340,80+2,16+2,5);
	visual_text(465+1,340+1,80,16,1,26,0,_Context->buffer_StepZ,10,0);
	visual_text(215,310,10,20,2,27,0,"X",1,3);
	visual_text(335,310,10,20,2,27,0,"Y",1,3);
	visual_text(455,310,10,20,2,27,0,"Z",1,3);
	visual_check(465,210,112,16,2,26,0,"Au&toSize",9,_Context->value_DynamicSize|0);
	visual_check(465,230,112,16,2,26,0,"Save &Forms",11,_Context->value_SaveForms|0);
	visual_check(465,250,126,16,2,26,0,"Save &Images",12,_Context->value_SaveImages|0);
	visual_text(115,370,110,20,2,27,0,"Image",5,2);
	visual_text(115,400,110,20,2,27,0,"Image Options",13,2);
	visual_text(405,400,60,20,2,27,0,"Colour",6,2);
	visual_frame(225,370,456+2,16+2,5);
	visual_text(225+1,370+1,456,16,1,26,0,_Context->buffer_ImageName,57,0);
	visual_select(225,400,140,90,1,0,0,parse_selection(WidgetImageList,&_Context->value_Auto3394),0);
	visual_frame(465,400,80+2,16+2,5);
	visual_text(465+1,400+1,80,16,1,26,0,_Context->buffer_Colour,10,0);
	visual_button(455,450,100,30,2,27,24,"&Select",7,0);
	visual_thaw(95,100,610,400);

	return(0);
}
private int on_Accept_event() {
	return(13);
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}
private int on_Auto3395_event() {
	use_file_selector(_Context->buffer_ImageName,WIDGET_FILE_GIF);
	accept_camera_properties_show();
	return(-1);
}


private	int	accept_camera_properties_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 684 )  
	&&  (my >= 104 )  
	&&  (mx <= 700 )  
	&&  (my <= 120 )) {
		return(1);	/* auto1 */

		}
	if ((mx >= 668 )  
	&&  (my >= 104 )  
	&&  (mx <= 684 )  
	&&  (my <= 120 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vcamera.htm");
			};
		return(-1);	/* auto1 */

		}
	if (( mx >= 225 ) 
	&&  ( my >= 160 ) 
	&&  ( mx <= 681 ) 
	&&  ( my <= 176 )) {
		return(2); /* Name */
		}
	if (( mx >= 225 ) 
	&&  ( my >= 190 ) 
	&&  ( mx <= 305 ) 
	&&  ( my <= 206 )) {
		return(3); /* AtX */
		}
	if (( mx >= 345 ) 
	&&  ( my >= 190 ) 
	&&  ( mx <= 425 ) 
	&&  ( my <= 206 )) {
		return(4); /* AtY */
		}
	if (( mx >= 465 ) 
	&&  ( my >= 190 ) 
	&&  ( mx <= 537 ) 
	&&  ( my <= 206 )) {
		return(5); /* AtZ */
		}
	if (( mx >= 225 ) 
	&&  ( my >= 220 ) 
	&&  ( mx <= 305 ) 
	&&  ( my <= 236 )) {
		return(6); /* ToX */
		}
	if (( mx >= 345 ) 
	&&  ( my >= 220 ) 
	&&  ( mx <= 425 ) 
	&&  ( my <= 236 )) {
		return(7); /* ToY */
		}
	if ((mx >= 225 ) 
	&&  (my >= 250 ) 
	&&  (mx <= 425 ) 
	&&  (my <= 266 )) {
		return(8); /* Direction */
		}
	if (( mx >= 225 ) 
	&&  ( my >= 280 ) 
	&&  ( mx <= 425 ) 
	&&  ( my <= 296 )) {
		return(9); /* Timer */
		}
	if (( mx >= 465 ) 
	&&  ( my >= 280 ) 
	&&  ( mx <= 545 ) 
	&&  ( my <= 296 )) {
		return(10); /* Step */
		}
	if (( mx >= 115 ) 
	&&  ( my >= 450 ) 
	&&  ( mx <= 235 ) 
	&&  ( my <= 480 )) {
		return(11); /* Accept */
		}
	if (( mx >= 565 ) 
	&&  ( my >= 450 ) 
	&&  ( mx <= 685 ) 
	&&  ( my <= 480 )) {
		return(12); /* Cancel */
		}
	if (( mx >= 225 ) 
	&&  ( my >= 310 ) 
	&&  ( mx <= 305 ) 
	&&  ( my <= 326 )) {
		return(13); /* NbX */
		}
	if (( mx >= 345 ) 
	&&  ( my >= 310 ) 
	&&  ( mx <= 425 ) 
	&&  ( my <= 326 )) {
		return(14); /* nbY */
		}
	if (( mx >= 465 ) 
	&&  ( my >= 310 ) 
	&&  ( mx <= 545 ) 
	&&  ( my <= 326 )) {
		return(15); /* NbZ */
		}
	if (( mx >= 225 ) 
	&&  ( my >= 340 ) 
	&&  ( mx <= 305 ) 
	&&  ( my <= 356 )) {
		return(16); /* StepX */
		}
	if (( mx >= 345 ) 
	&&  ( my >= 340 ) 
	&&  ( mx <= 425 ) 
	&&  ( my <= 356 )) {
		return(17); /* StepY */
		}
	if (( mx >= 465 ) 
	&&  ( my >= 340 ) 
	&&  ( mx <= 545 ) 
	&&  ( my <= 356 )) {
		return(18); /* StepZ */
		}
	if (( mx >= 465 ) 
	&&  ( my >= 210 ) 
	&&  ( mx <= 577 ) 
	&&  ( my <= 226 )) {
		return(19); /* DynamicSize */
		}
	if (( mx >= 465 ) 
	&&  ( my >= 230 ) 
	&&  ( mx <= 577 ) 
	&&  ( my <= 246 )) {
		return(20); /* SaveForms */
		}
	if (( mx >= 465 ) 
	&&  ( my >= 250 ) 
	&&  ( mx <= 591 ) 
	&&  ( my <= 266 )) {
		return(21); /* SaveImages */
		}
	if (( mx >= 225 ) 
	&&  ( my >= 370 ) 
	&&  ( mx <= 681 ) 
	&&  ( my <= 386 )) {
		return(22); /* ImageName */
		}
	if ((mx >= 225 ) 
	&&  (my >= 400 ) 
	&&  (mx <= 365 ) 
	&&  (my <= 416 )) {
		return(23); /* Auto3394 */
		}
	if (( mx >= 465 ) 
	&&  ( my >= 400 ) 
	&&  ( mx <= 545 ) 
	&&  ( my <= 416 )) {
		return(24); /* Colour */
		}
	if (( mx >= 455 ) 
	&&  ( my >= 450 ) 
	&&  ( mx <= 555 ) 
	&&  ( my <= 480 )) {
		return(25); /* Auto3395 */
		}

	return(-1);
}


private	int	accept_camera_properties_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Name */
				_Context->keycode = visual_edit(225+1,160+1,456,16,1,_Context->buffer_Name,57);
				break;
			case	0x3 :
				/* AtX */
				_Context->keycode = visual_edit(225+1,190+1,80,16,1,_Context->buffer_AtX,10);
				break;
			case	0x4 :
				/* AtY */
				_Context->keycode = visual_edit(345+1,190+1,80,16,1,_Context->buffer_AtY,10);
				break;
			case	0x5 :
				/* AtZ */
				_Context->keycode = visual_edit(465+1,190+1,72,16,1,_Context->buffer_AtZ,9);
				break;
			case	0x6 :
				/* ToX */
				_Context->keycode = visual_edit(225+1,220+1,80,16,1,_Context->buffer_ToX,10);
				break;
			case	0x7 :
				/* ToY */
				_Context->keycode = visual_edit(345+1,220+1,80,16,1,_Context->buffer_ToY,10);
				break;
			case	0x8 :
				/* Direction */
				_Context->keycode = visual_select(225,250,200,80,1,26,0,parse_selection("forward|backward|left|right|up|down",&_Context->value_Direction),514);
				break;
			case	0x9 :
				/* Timer */
				_Context->keycode = visual_edit(225+1,280+1,200,16,1,_Context->buffer_Timer,25);
				break;
			case	0xa :
				/* Step */
				_Context->keycode = visual_edit(465+1,280+1,80,16,1,_Context->buffer_Step,10);
				break;
			case	0xb :
				/* Accept */
				visual_button(115,450,120,30,2,34,0,"&Accept",7,2);
				_Context->keycode = visual_getch();
				visual_button(115,450,120,30,2,34,0,"&Accept",7,0);
				break;
			case	0xc :
				/* Cancel */
				visual_button(565,450,120,30,2,34,0,"&Cancel",7,2);
				_Context->keycode = visual_getch();
				visual_button(565,450,120,30,2,34,0,"&Cancel",7,0);
				break;
			case	0xd :
				/* NbX */
				_Context->keycode = visual_edit(225+1,310+1,80,16,1,_Context->buffer_NbX,10);
				break;
			case	0xe :
				/* nbY */
				_Context->keycode = visual_edit(345+1,310+1,80,16,1,_Context->buffer_nbY,10);
				break;
			case	0xf :
				/* NbZ */
				_Context->keycode = visual_edit(465+1,310+1,80,16,1,_Context->buffer_NbZ,10);
				break;
			case	0x10 :
				/* StepX */
				_Context->keycode = visual_edit(225+1,340+1,80,16,1,_Context->buffer_StepX,10);
				break;
			case	0x11 :
				/* StepY */
				_Context->keycode = visual_edit(345+1,340+1,80,16,1,_Context->buffer_StepY,10);
				break;
			case	0x12 :
				/* StepZ */
				_Context->keycode = visual_edit(465+1,340+1,80,16,1,_Context->buffer_StepZ,10);
				break;
			case	0x13 :
				/* DynamicSize */
				visual_check(465,210,112,16,2,26,0,"Au&toSize",9,(_Context->value_DynamicSize |2));
				_Context->keycode = visual_getch();
				visual_check(465,210,112,16,2,26,0,"Au&toSize",9,(_Context->value_DynamicSize |0));
				break;
			case	0x14 :
				/* SaveForms */
				visual_check(465,230,112,16,2,26,0,"Save &Forms",11,(_Context->value_SaveForms |2));
				_Context->keycode = visual_getch();
				visual_check(465,230,112,16,2,26,0,"Save &Forms",11,(_Context->value_SaveForms |0));
				break;
			case	0x15 :
				/* SaveImages */
				visual_check(465,250,126,16,2,26,0,"Save &Images",12,(_Context->value_SaveImages |2));
				_Context->keycode = visual_getch();
				visual_check(465,250,126,16,2,26,0,"Save &Images",12,(_Context->value_SaveImages |0));
				break;
			case	0x16 :
				/* ImageName */
				_Context->keycode = visual_edit(225+1,370+1,456,16,1,_Context->buffer_ImageName,57);
				break;
			case	0x17 :
				/* Auto3394 */
				_Context->keycode = visual_select(225,400,140,90,1,0,0,parse_selection(WidgetImageList,&_Context->value_Auto3394),2);
				break;
			case	0x18 :
				/* Colour */
				_Context->keycode = visual_edit(465+1,400+1,80,16,1,_Context->buffer_Colour,10);
				break;
			case	0x19 :
				/* Auto3395 */
				visual_button(455,450,100,30,2,27,24,"&Select",7,2);
				_Context->keycode = visual_getch();
				visual_button(455,450,100,30,2,27,24,"&Select",7,0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_camera_properties_show();
			continue;
		case	0x2 :
			_Context->focus_item=25;
			accept_camera_properties_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_camera_properties_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* auto1 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Name */
						continue;
					case	0x3 :
						/* AtX */
						continue;
					case	0x4 :
						/* AtY */
						continue;
					case	0x5 :
						/* AtZ */
						continue;
					case	0x6 :
						/* ToX */
						continue;
					case	0x7 :
						/* ToY */
						continue;
					case	0x8 :
						/* Direction */
						continue;
					case	0x9 :
						/* Timer */
						continue;
					case	0xa :
						/* Step */
						continue;
					case	0xb :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(115,450,120,30,2,34,0,"&Accept",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(115,450,120,30,2,34,0,"&Accept",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0xc :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(565,450,120,30,2,34,0,"&Cancel",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(565,450,120,30,2,34,0,"&Cancel",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

							}
						continue;
					case	0xd :
						/* NbX */
						continue;
					case	0xe :
						/* nbY */
						continue;
					case	0xf :
						/* NbZ */
						continue;
					case	0x10 :
						/* StepX */
						continue;
					case	0x11 :
						/* StepY */
						continue;
					case	0x12 :
						/* StepZ */
						continue;
					case	0x13 :
						/* DynamicSize */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_DynamicSize += 1;
							_Context->value_DynamicSize &= 1;
							}
						continue;
					case	0x14 :
						/* SaveForms */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SaveForms += 1;
							_Context->value_SaveForms &= 1;
							}
						continue;
					case	0x15 :
						/* SaveImages */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SaveImages += 1;
							_Context->value_SaveImages &= 1;
							}
						continue;
					case	0x16 :
						/* ImageName */
						continue;
					case	0x17 :
						/* Auto3394 */
						continue;
					case	0x18 :
						/* Colour */
						continue;
					case	0x19 :
						/* Auto3395 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(455,450,100,30,2,27,24,"&Select",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(455,450,100,30,2,27,24,"&Select",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto3395_event()) != -1) break;

							}
						continue;
					case	0xffffffff :
					default :
						_Context->focus_item=1;
					continue;
					}
				break;
			case	0x1b :
			case	0xd :
				break;
			case	0x9 :
			case	0x5 :
			if ( _Context->focus_item < _Context->focus_items ) {
				_Context->focus_item++;			} else {
				_Context->focus_item=1;
			}
			continue;
			case	0xb :
			if ( _Context->focus_item > 1 ) {
				_Context->focus_item--;
			} else {
				_Context->focus_item=25;
			}
			continue;
		case 0x841 : 
		case 0x861 : 
		/* Accept */
		visual_button(115,450,120,30,2,34,0,"&Accept",7,8);
		visual_button(115,450,120,30,2,34,0,"&Accept",7,0);
		_Context->focus_item=11;
		if ((_Context->keycode = on_Accept_event()) != -1) break;
		continue;
		case 0x843 : 
		case 0x863 : 
		/* Cancel */
		visual_button(565,450,120,30,2,34,0,"&Cancel",7,8);
		visual_button(565,450,120,30,2,34,0,"&Cancel",7,0);
		_Context->focus_item=12;
		if ((_Context->keycode = on_Cancel_event()) != -1) break;
		continue;
		case 0x874 : 
		case 0x894 : 
		/* DynamicSize */
		_Context->value_DynamicSize += 1;
		_Context->value_DynamicSize &= 1;
		_Context->focus_item=19;
		continue;
		case 0x846 : 
		case 0x866 : 
		/* SaveForms */
		_Context->value_SaveForms += 1;
		_Context->value_SaveForms &= 1;
		_Context->focus_item=20;
		continue;
		case 0x849 : 
		case 0x869 : 
		/* SaveImages */
		_Context->value_SaveImages += 1;
		_Context->value_SaveImages &= 1;
		_Context->focus_item=21;
		continue;
		case 0x853 : 
		case 0x873 : 
		/* Auto3395 */
		visual_button(455,450,100,30,2,27,24,"&Select",7,8);
		visual_button(455,450,100,30,2,27,24,"&Select",7,0);
		_Context->focus_item=25;
		if ((_Context->keycode = on_Auto3395_event()) != -1) break;
		continue;
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_camera_properties(
	char * pName,
	char * pAtX,
	char * pAtY,
	char * pAtZ,
	char * pToX,
	char * pToY,
	char * pDirection,
	char * pTimer,
	char * pStep,
	char * pNbX,
	char * pnbY,
	char * pNbZ,
	char * pStepX,
	char * pStepY,
	char * pStepZ,
	char * pDynamicSize,
	char * pSaveForms,
	char * pSaveImages,
	char * pImageName,
	char * pAuto3394,
	char * pColour)
{
	int	status=0;
	status = accept_camera_properties_create(
	 pName,
	 pAtX,
	 pAtY,
	 pAtZ,
	 pToX,
	 pToY,
	 pDirection,
	 pTimer,
	 pStep,
	 pNbX,
	 pnbY,
	 pNbZ,
	 pStepX,
	 pStepY,
	 pStepZ,
	 pDynamicSize,
	 pSaveForms,
	 pSaveImages,
	 pImageName,
	 pAuto3394,
	 pColour);
	if ( status != 0) return(status);
	status = accept_camera_properties_show();
		enter_modal();
	status = accept_camera_properties_focus();
		leave_modal();
	status = accept_camera_properties_hide();
	status = accept_camera_properties_remove(
	 pName,
	 pAtX,
	 pAtY,
	 pAtZ,
	 pToX,
	 pToY,
	 pDirection,
	 pTimer,
	 pStep,
	 pNbX,
	 pnbY,
	 pNbZ,
	 pStepX,
	 pStepY,
	 pStepZ,
	 pDynamicSize,
	 pSaveForms,
	 pSaveImages,
	 pImageName,
	 pAuto3394,
	 pColour);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcamera_c */
