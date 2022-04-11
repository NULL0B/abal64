
#ifndef _vcube_c
#define _vcube_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.14  */
/* Production     : C  */
/* Project        : vcube.sng  */
/* Target         : vcube.c  */
/* Identification : 0.0-1070991220-11407.8613 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_cube_properties_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char	buffer_Identity[58];
	char	buffer_Position[8];
	char	buffer_tly[8];
	char	buffer_tlz[8];
	char	buffer_Dimensions[8];
	char	buffer_bry[8];
	char	buffer_brz[8];
	char	buffer_Class[58];
	int	value_AutoSize;
	int	value_InhibitGif;
	char	buffer_Back[8];
	char	buffer_Front[8];
	char	buffer_Left[8];
	char	buffer_Right[8];
	char	buffer_Upper[8];
	char	buffer_Lower[8];
	char	buffer_Light[8];
	char	buffer_Dark[8];
	char	signature[19];
	} * _Context;

private	int	accept_cube_properties_create(
	char * pIdentity,
	char * pPosition,
	char * ptly,
	char * ptlz,
	char * pDimensions,
	char * pbry,
	char * pbrz,
	char * pClass,
	char * pAutoSize,
	char * pInhibitGif,
	char * pBack,
	char * pFront,
	char * pLeft,
	char * pRight,
	char * pUpper,
	char * pLower,
	char * pLight,
	char * pDark)
{

	int i;
	if (!(_Context = allocate( sizeof( struct accept_cube_properties_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=21;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWWWWWKWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Identity, 57, pIdentity);
		visual_transferin(_Context->buffer_Position, 7, pPosition);
		visual_transferin(_Context->buffer_tly, 7, ptly);
		visual_transferin(_Context->buffer_tlz, 7, ptlz);
		visual_transferin(_Context->buffer_Dimensions, 7, pDimensions);
		visual_transferin(_Context->buffer_bry, 7, pbry);
		visual_transferin(_Context->buffer_brz, 7, pbrz);
		visual_transferin(_Context->buffer_Class, 57, pClass);
		visual_transferin((void *) 0, 0, pAutoSize);
		if (!( pAutoSize )) _Context->value_AutoSize=0;
		else	_Context->value_AutoSize = *((int *)pAutoSize);
		visual_transferin((void *) 0, 0, pInhibitGif);
		if (!( pInhibitGif )) _Context->value_InhibitGif=0;
		else	_Context->value_InhibitGif = *((int *)pInhibitGif);
		visual_transferin(_Context->buffer_Back, 7, pBack);
		visual_transferin(_Context->buffer_Front, 7, pFront);
		visual_transferin(_Context->buffer_Left, 7, pLeft);
		visual_transferin(_Context->buffer_Right, 7, pRight);
		visual_transferin(_Context->buffer_Upper, 7, pUpper);
		visual_transferin(_Context->buffer_Lower, 7, pLower);
		visual_transferin(_Context->buffer_Light, 7, pLight);
		visual_transferin(_Context->buffer_Dark, 7, pDark);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	return(0);
}

private	int	accept_cube_properties_hide()
{

	return(0);
}

private	int	accept_cube_properties_remove(
	char * pIdentity,
	char * pPosition,
	char * ptly,
	char * ptlz,
	char * pDimensions,
	char * pbry,
	char * pbrz,
	char * pClass,
	char * pAutoSize,
	char * pInhibitGif,
	char * pBack,
	char * pFront,
	char * pLeft,
	char * pRight,
	char * pUpper,
	char * pLower,
	char * pLight,
	char * pDark)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWWWWWKWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Identity, 57, pIdentity);
		visual_transferout(_Context->buffer_Position, 7, pPosition);
		visual_transferout(_Context->buffer_tly, 7, ptly);
		visual_transferout(_Context->buffer_tlz, 7, ptlz);
		visual_transferout(_Context->buffer_Dimensions, 7, pDimensions);
		visual_transferout(_Context->buffer_bry, 7, pbry);
		visual_transferout(_Context->buffer_brz, 7, pbrz);
		visual_transferout(_Context->buffer_Class, 57, pClass);
		visual_transferout((void *) 0, 0, pAutoSize);
		if ( pAutoSize != (char *) 0)
			*((int*)pAutoSize) = _Context->value_AutoSize;
		visual_transferout((void *) 0, 0, pInhibitGif);
		if ( pInhibitGif != (char *) 0)
			*((int*)pInhibitGif) = _Context->value_InhibitGif;
		visual_transferout(_Context->buffer_Back, 7, pBack);
		visual_transferout(_Context->buffer_Front, 7, pFront);
		visual_transferout(_Context->buffer_Left, 7, pLeft);
		visual_transferout(_Context->buffer_Right, 7, pRight);
		visual_transferout(_Context->buffer_Upper, 7, pUpper);
		visual_transferout(_Context->buffer_Lower, 7, pLower);
		visual_transferout(_Context->buffer_Light, 7, pLight);
		visual_transferout(_Context->buffer_Dark, 7, pDark);
		}
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_cube_properties_show()
{
	visual_freeze();
	visual_window(95,155,610,290,2,"Sing : Version 1.0a",strlen("Sing : Version 1.0a"),0x403);
	visual_image(98,177,604,264,"\0",4);
	visual_text(115,335,570,16,2,0,0,"Couleurs des faces du Cube",strlen("Couleurs des faces du Cube"),258);
	visual_frame(115,351,570,44,3);
	visual_text(185,355,70,16,2,16,0,"Arriere",strlen("Arriere"),259);
	visual_text(185,375,70,16,2,16,0,"Avant",strlen("Avant"),259);
	visual_text(315,355,56,16,2,16,0,"Gauche",strlen("Gauche"),259);
	visual_text(315,375,56,16,2,16,0,"Droite",strlen("Droite"),259);
	visual_text(435,355,56,16,2,16,0,"Haut",strlen("Haut"),259);
	visual_text(435,375,56,16,2,16,0,"Bas",strlen("Bas"),259);
	visual_text(555,355,56,16,2,16,0,"Clair",strlen("Clair"),259);
	visual_text(555,375,56,16,2,16,0,"Sombre",strlen("Sombre"),259);
	visual_text(115,185,575,20,3,16,0,"Propert‚s de l'objet 3d",strlen("Propert‚s de l'objet 3d"),1282);
	visual_text(115,265,570,16,2,0,0,"D‚finition du Cube",strlen("D‚finition du Cube"),258);
	visual_frame(115,281,570,44,3);
	visual_text(115,215,100,20,2,16,0,"Identit‚",strlen("Identit‚"),258);
	visual_text(125,285,80,20,2,16,0,"Position",strlen("Position"),258);
	visual_text(125,305,100,20,2,16,0,"Dimensions",strlen("Dimensions"),258);
	visual_frame(225,215,456+2,16+2,5);
	visual_text(225+1,215+1,456,16,1,26,0,_Context->buffer_Identity,57,0);
	visual_frame(225,285,56+2,16+2,5);
	visual_text(225+1,285+1,56,16,1,26,0,_Context->buffer_Position,7,0);
	visual_frame(305,285,56+2,16+2,5);
	visual_text(305+1,285+1,56,16,1,26,0,_Context->buffer_tly,7,0);
	visual_frame(385,285,56+2,16+2,5);
	visual_text(385+1,285+1,56,16,1,26,0,_Context->buffer_tlz,7,0);
	visual_frame(225,305,56+2,16+2,5);
	visual_text(225+1,305+1,56,16,1,26,0,_Context->buffer_Dimensions,7,0);
	visual_frame(305,305,56+2,16+2,5);
	visual_text(305+1,305+1,56,16,1,26,0,_Context->buffer_bry,7,0);
	visual_frame(385,305,56+2,16+2,5);
	visual_text(385+1,305+1,56,16,1,26,0,_Context->buffer_brz,7,0);
	visual_text(205,295,14,16,2,16,0,"X",strlen("X"),259);
	visual_text(285,295,14,16,2,16,0,"Y",strlen("Y"),259);
	visual_text(365,295,14,16,2,16,0,"Z",strlen("Z"),259);
	visual_button(115,405,120,32,2,34,0,"&Valider",strlen("&Valider"),0);
	visual_button(325,405,140,32,2,27,28,"&Choisir",strlen("&Choisir"),0);
	visual_button(565,405,120,32,2,34,0,"&Annuler",strlen("&Annuler"),0);
	visual_text(115,235,100,20,2,16,0,"Class",strlen("Class"),258);
	visual_frame(225,235,456+2,16+2,5);
	visual_text(225+1,235+1,456,16,1,26,0,_Context->buffer_Class,57,2);
	visual_check(485,285,196,16,2,26,0,"Dimension Auto",strlen("Dimension Auto"),_Context->value_AutoSize|0);
	visual_check(485,305,182,16,2,0,0,"Inhiber Gif",strlen("Inhiber Gif"),_Context->value_InhibitGif|0);
	visual_frame(255,355,56+2,16+2,5);
	visual_text(255+1,355+1,56,16,1,0,0,_Context->buffer_Back,7,0);
	visual_frame(255,375,56+2,16+2,5);
	visual_text(255+1,375+1,56,16,1,0,0,_Context->buffer_Front,7,0);
	visual_frame(375,355,56+2,16+2,5);
	visual_text(375+1,355+1,56,16,1,0,0,_Context->buffer_Left,7,0);
	visual_frame(375,375,56+2,16+2,5);
	visual_text(375+1,375+1,56,16,1,0,0,_Context->buffer_Right,7,0);
	visual_frame(495,355,56+2,16+2,5);
	visual_text(495+1,355+1,56,16,1,0,0,_Context->buffer_Upper,7,0);
	visual_frame(495,375,56+2,16+2,5);
	visual_text(495+1,375+1,56,16,1,0,0,_Context->buffer_Lower,7,0);
	visual_frame(615,355,56+2,16+2,5);
	visual_text(615+1,355+1,56,16,1,0,0,_Context->buffer_Light,7,0);
	visual_frame(615,375,56+2,16+2,5);
	visual_text(615+1,375+1,56,16,1,0,0,_Context->buffer_Dark,7,0);
	visual_thaw(95,155,610,290);

	return(0);
}
private int on_Accept_event() {
	return(13);
	return(-1);
}
private int on_Select_event() {
	use_file_selector(_Context->buffer_Identity,WIDGET_FILE_ANY);
	accept_cube_properties_show();
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}


private	int	accept_cube_properties_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (mt & _MIMO_UP) {
	if ((mx >= 684 )  
	&&  (my >= 159 )  
	&&  (mx <= 700 )  
	&&  (my <= 175 )) {
		return(1);	/* auto1 */

		}
	if ((mx >= 668 )  
	&&  (my >= 159 )  
	&&  (mx <= 684 )  
	&&  (my <= 175 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vcube.htm");
			};
		return(-1);	/* auto1 */

		}
		}
	if (( mx >= 225 ) 
	&&  ( my >= 215 ) 
	&&  ( mx <= 681 ) 
	&&  ( my <= 231 )) {
		return(2); /* Identity */
		}
	if (( mx >= 225 ) 
	&&  ( my >= 285 ) 
	&&  ( mx <= 281 ) 
	&&  ( my <= 301 )) {
		return(3); /* Position */
		}
	if (( mx >= 305 ) 
	&&  ( my >= 285 ) 
	&&  ( mx <= 361 ) 
	&&  ( my <= 301 )) {
		return(4); /* tly */
		}
	if (( mx >= 385 ) 
	&&  ( my >= 285 ) 
	&&  ( mx <= 441 ) 
	&&  ( my <= 301 )) {
		return(5); /* tlz */
		}
	if (( mx >= 225 ) 
	&&  ( my >= 305 ) 
	&&  ( mx <= 281 ) 
	&&  ( my <= 321 )) {
		return(6); /* Dimensions */
		}
	if (( mx >= 305 ) 
	&&  ( my >= 305 ) 
	&&  ( mx <= 361 ) 
	&&  ( my <= 321 )) {
		return(7); /* bry */
		}
	if (( mx >= 385 ) 
	&&  ( my >= 305 ) 
	&&  ( mx <= 441 ) 
	&&  ( my <= 321 )) {
		return(8); /* brz */
		}
	if (( mx >= 115 ) 
	&&  ( my >= 405 ) 
	&&  ( mx <= 235 ) 
	&&  ( my <= 437 )) {
		return(9); /* Accept */
		}
	if (( mx >= 325 ) 
	&&  ( my >= 405 ) 
	&&  ( mx <= 465 ) 
	&&  ( my <= 437 )) {
		return(10); /* Select */
		}
	if (( mx >= 565 ) 
	&&  ( my >= 405 ) 
	&&  ( mx <= 685 ) 
	&&  ( my <= 437 )) {
		return(11); /* Cancel */
		}
	if (( mx >= 485 ) 
	&&  ( my >= 285 ) 
	&&  ( mx <= 681 ) 
	&&  ( my <= 301 )) {
		return(12); /* AutoSize */
		}
	if (( mx >= 485 ) 
	&&  ( my >= 305 ) 
	&&  ( mx <= 667 ) 
	&&  ( my <= 321 )) {
		return(13); /* InhibitGif */
		}
	if (( mx >= 255 ) 
	&&  ( my >= 355 ) 
	&&  ( mx <= 311 ) 
	&&  ( my <= 371 )) {
		return(14); /* Back */
		}
	if (( mx >= 255 ) 
	&&  ( my >= 375 ) 
	&&  ( mx <= 311 ) 
	&&  ( my <= 391 )) {
		return(15); /* Front */
		}
	if (( mx >= 375 ) 
	&&  ( my >= 355 ) 
	&&  ( mx <= 431 ) 
	&&  ( my <= 371 )) {
		return(16); /* Left */
		}
	if (( mx >= 375 ) 
	&&  ( my >= 375 ) 
	&&  ( mx <= 431 ) 
	&&  ( my <= 391 )) {
		return(17); /* Right */
		}
	if (( mx >= 495 ) 
	&&  ( my >= 355 ) 
	&&  ( mx <= 551 ) 
	&&  ( my <= 371 )) {
		return(18); /* Upper */
		}
	if (( mx >= 495 ) 
	&&  ( my >= 375 ) 
	&&  ( mx <= 551 ) 
	&&  ( my <= 391 )) {
		return(19); /* Lower */
		}
	if (( mx >= 615 ) 
	&&  ( my >= 355 ) 
	&&  ( mx <= 671 ) 
	&&  ( my <= 371 )) {
		return(20); /* Light */
		}
	if (( mx >= 615 ) 
	&&  ( my >= 375 ) 
	&&  ( mx <= 671 ) 
	&&  ( my <= 391 )) {
		return(21); /* Dark */
		}

	return(-1);
}


private	int	accept_cube_properties_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Identity */
				_Context->keycode = visual_edit(225+1,215+1,456,16,1,_Context->buffer_Identity,57);
				break;
			case	0x3 :
				/* Position */
				_Context->keycode = visual_edit(225+1,285+1,56,16,1,_Context->buffer_Position,7);
				break;
			case	0x4 :
				/* tly */
				_Context->keycode = visual_edit(305+1,285+1,56,16,1,_Context->buffer_tly,7);
				break;
			case	0x5 :
				/* tlz */
				_Context->keycode = visual_edit(385+1,285+1,56,16,1,_Context->buffer_tlz,7);
				break;
			case	0x6 :
				/* Dimensions */
				_Context->keycode = visual_edit(225+1,305+1,56,16,1,_Context->buffer_Dimensions,7);
				break;
			case	0x7 :
				/* bry */
				_Context->keycode = visual_edit(305+1,305+1,56,16,1,_Context->buffer_bry,7);
				break;
			case	0x8 :
				/* brz */
				_Context->keycode = visual_edit(385+1,305+1,56,16,1,_Context->buffer_brz,7);
				break;
			case	0x9 :
				/* Accept */
				visual_button(115,405,120,32,2,34,0,"&Valider",strlen("&Valider"),2);
				_Context->keycode = visual_getch();
				visual_button(115,405,120,32,2,34,0,"&Valider",strlen("&Valider"),0);
				break;
			case	0xa :
				/* Select */
				visual_button(325,405,140,32,2,27,28,"&Choisir",strlen("&Choisir"),2);
				_Context->keycode = visual_getch();
				visual_button(325,405,140,32,2,27,28,"&Choisir",strlen("&Choisir"),0);
				break;
			case	0xb :
				/* Cancel */
				visual_button(565,405,120,32,2,34,0,"&Annuler",strlen("&Annuler"),2);
				_Context->keycode = visual_getch();
				visual_button(565,405,120,32,2,34,0,"&Annuler",strlen("&Annuler"),0);
				break;
			case	0xc :
				/* AutoSize */
				visual_check(485,285,196,16,2,26,0,"Dimension Auto",strlen("Dimension Auto"),(_Context->value_AutoSize |2));
				_Context->keycode = visual_getch();
				visual_check(485,285,196,16,2,26,0,"Dimension Auto",strlen("Dimension Auto"),(_Context->value_AutoSize |0));
				break;
			case	0xd :
				/* InhibitGif */
				visual_check(485,305,182,16,2,0,0,"Inhiber Gif",strlen("Inhiber Gif"),(_Context->value_InhibitGif |2));
				_Context->keycode = visual_getch();
				visual_check(485,305,182,16,2,0,0,"Inhiber Gif",strlen("Inhiber Gif"),(_Context->value_InhibitGif |0));
				break;
			case	0xe :
				/* Back */
				_Context->keycode = visual_edit(255+1,355+1,56,16,1,_Context->buffer_Back,7);
				break;
			case	0xf :
				/* Front */
				_Context->keycode = visual_edit(255+1,375+1,56,16,1,_Context->buffer_Front,7);
				break;
			case	0x10 :
				/* Left */
				_Context->keycode = visual_edit(375+1,355+1,56,16,1,_Context->buffer_Left,7);
				break;
			case	0x11 :
				/* Right */
				_Context->keycode = visual_edit(375+1,375+1,56,16,1,_Context->buffer_Right,7);
				break;
			case	0x12 :
				/* Upper */
				_Context->keycode = visual_edit(495+1,355+1,56,16,1,_Context->buffer_Upper,7);
				break;
			case	0x13 :
				/* Lower */
				_Context->keycode = visual_edit(495+1,375+1,56,16,1,_Context->buffer_Lower,7);
				break;
			case	0x14 :
				/* Light */
				_Context->keycode = visual_edit(615+1,355+1,56,16,1,_Context->buffer_Light,7);
				break;
			case	0x15 :
				/* Dark */
				_Context->keycode = visual_edit(615+1,375+1,56,16,1,_Context->buffer_Dark,7);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_cube_properties_show();
			continue;
		case	0x2 :
			_Context->focus_item=21;
			accept_cube_properties_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_cube_properties_event()) == -1)
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
						/* Identity */
						continue;
					case	0x3 :
						/* Position */
						continue;
					case	0x4 :
						/* tly */
						continue;
					case	0x5 :
						/* tlz */
						continue;
					case	0x6 :
						/* Dimensions */
						continue;
					case	0x7 :
						/* bry */
						continue;
					case	0x8 :
						/* brz */
						continue;
					case	0x9 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(115,405,120,32,2,34,0,"&Valider",strlen("&Valider"),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(115,405,120,32,2,34,0,"&Valider",strlen("&Valider"),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0xa :
						/* Select */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(325,405,140,32,2,27,28,"&Choisir",strlen("&Choisir"),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(325,405,140,32,2,27,28,"&Choisir",strlen("&Choisir"),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Select_event()) != -1) break;

							}
						continue;
					case	0xb :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(565,405,120,32,2,34,0,"&Annuler",strlen("&Annuler"),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(565,405,120,32,2,34,0,"&Annuler",strlen("&Annuler"),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

							}
						continue;
					case	0xc :
						/* AutoSize */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_AutoSize += 1;
							_Context->value_AutoSize &= 1;
							}
						continue;
					case	0xd :
						/* InhibitGif */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_InhibitGif += 1;
							_Context->value_InhibitGif &= 1;
							}
						continue;
					case	0xe :
						/* Back */
						continue;
					case	0xf :
						/* Front */
						continue;
					case	0x10 :
						/* Left */
						continue;
					case	0x11 :
						/* Right */
						continue;
					case	0x12 :
						/* Upper */
						continue;
					case	0x13 :
						/* Lower */
						continue;
					case	0x14 :
						/* Light */
						continue;
					case	0x15 :
						/* Dark */
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
				_Context->focus_item=21;
			}
			continue;
		case 0x856 : 
		case 0x876 : 
		/* Accept */
		visual_button(115,405,120,32,2,34,0,"&Valider",strlen("&Valider"),8);
		visual_button(115,405,120,32,2,34,0,"&Valider",strlen("&Valider"),0);
		_Context->focus_item=9;
		if ((_Context->keycode = on_Accept_event()) != -1) break;
		continue;
		case 0x843 : 
		case 0x863 : 
		/* Select */
		visual_button(325,405,140,32,2,27,28,"&Choisir",strlen("&Choisir"),8);
		visual_button(325,405,140,32,2,27,28,"&Choisir",strlen("&Choisir"),0);
		_Context->focus_item=10;
		if ((_Context->keycode = on_Select_event()) != -1) break;
		continue;
		case 0x841 : 
		case 0x861 : 
		/* Cancel */
		visual_button(565,405,120,32,2,34,0,"&Annuler",strlen("&Annuler"),8);
		visual_button(565,405,120,32,2,34,0,"&Annuler",strlen("&Annuler"),0);
		_Context->focus_item=11;
		if ((_Context->keycode = on_Cancel_event()) != -1) break;
		continue;
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_cube_properties(
	char * pIdentity,
	char * pPosition,
	char * ptly,
	char * ptlz,
	char * pDimensions,
	char * pbry,
	char * pbrz,
	char * pClass,
	char * pAutoSize,
	char * pInhibitGif,
	char * pBack,
	char * pFront,
	char * pLeft,
	char * pRight,
	char * pUpper,
	char * pLower,
	char * pLight,
	char * pDark)
{
	int	status=0;
	status = accept_cube_properties_create(
	 pIdentity,
	 pPosition,
	 ptly,
	 ptlz,
	 pDimensions,
	 pbry,
	 pbrz,
	 pClass,
	 pAutoSize,
	 pInhibitGif,
	 pBack,
	 pFront,
	 pLeft,
	 pRight,
	 pUpper,
	 pLower,
	 pLight,
	 pDark);
	if ( status != 0) return(status);
	status = accept_cube_properties_show();
		enter_modal();
	status = accept_cube_properties_focus();
		leave_modal();
	status = accept_cube_properties_hide();
	status = accept_cube_properties_remove(
	 pIdentity,
	 pPosition,
	 ptly,
	 ptlz,
	 pDimensions,
	 pbry,
	 pbrz,
	 pClass,
	 pAutoSize,
	 pInhibitGif,
	 pBack,
	 pFront,
	 pLeft,
	 pRight,
	 pUpper,
	 pLower,
	 pLight,
	 pDark);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcube_c */
