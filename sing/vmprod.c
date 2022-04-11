
#ifndef _vmprod_c
#define _vmprod_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vmprod.sng  */
/* Target         : vmprod.c  */
/* Identification : 0.0-1065019114-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_production_properties_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_ModelName[71];
	char	buffer_TargetFile[56];
	int	value_NoConfirm;
	int	value_Build;
	int	value_Verbose;
	int	value_TargetType;
	int	value_IsDocument;
	int	value_ProdLang;
	char	buffer_DocumentFile[56];
	int	value_Makefile;
	char	buffer_MakefileName[56];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[12];
	} * _Context;

private	int	accept_production_properties_create(
	char * pModelName,
	char * pTargetFile,
	char * pNoConfirm,
	char * pBuild,
	char * pVerbose,
	char * pTargetType,
	char * pIsDocument,
	char * pProdLang,
	char * pDocumentFile,
	char * pMakefile,
	char * pMakefileName)
{

	if (!(_Context = allocate( sizeof( struct accept_production_properties_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=20;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWWWWSWS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_ModelName, 70, pModelName);
		visual_transferin(_Context->buffer_TargetFile, 55, pTargetFile);
		visual_transferin((void *) 0, 0, pNoConfirm);
		if (!( pNoConfirm )) _Context->value_NoConfirm=0;
		else	_Context->value_NoConfirm = *((int *)pNoConfirm);
		visual_transferin((void *) 0, 0, pBuild);
		if (!( pBuild )) _Context->value_Build=0;
		else	_Context->value_Build = *((int *)pBuild);
		visual_transferin((void *) 0, 0, pVerbose);
		if (!( pVerbose )) _Context->value_Verbose=0;
		else	_Context->value_Verbose = *((int *)pVerbose);
		visual_transferin((void *) 0, 0, pTargetType);
		if (!( pTargetType )) _Context->value_TargetType=0;
		else	_Context->value_TargetType = *((int *)pTargetType);
		visual_transferin((void *) 0, 0, pIsDocument);
		if (!( pIsDocument )) _Context->value_IsDocument=0;
		else	_Context->value_IsDocument = *((int *)pIsDocument);
		visual_transferin((void *) 0, 0, pProdLang);
		if (!( pProdLang )) _Context->value_ProdLang=0;
		else	_Context->value_ProdLang = *((int *)pProdLang);
		visual_transferin(_Context->buffer_DocumentFile, 55, pDocumentFile);
		visual_transferin((void *) 0, 0, pMakefile);
		if (!( pMakefile )) _Context->value_Makefile=0;
		else	_Context->value_Makefile = *((int *)pMakefile);
		visual_transferin(_Context->buffer_MakefileName, 55, pMakefileName);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(100,116,600+10,367+10);
	return(0);
}

private	int	accept_production_properties_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,100,116);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_production_properties_remove(
	char * pModelName,
	char * pTargetFile,
	char * pNoConfirm,
	char * pBuild,
	char * pVerbose,
	char * pTargetType,
	char * pIsDocument,
	char * pProdLang,
	char * pDocumentFile,
	char * pMakefile,
	char * pMakefileName)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWWWWSWS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_ModelName, 70, pModelName);
		visual_transferout(_Context->buffer_TargetFile, 55, pTargetFile);
		visual_transferout((void *) 0, 0, pNoConfirm);
		if ( pNoConfirm != (char *) 0)
			*((int*)pNoConfirm) = _Context->value_NoConfirm;
		visual_transferout((void *) 0, 0, pBuild);
		if ( pBuild != (char *) 0)
			*((int*)pBuild) = _Context->value_Build;
		visual_transferout((void *) 0, 0, pVerbose);
		if ( pVerbose != (char *) 0)
			*((int*)pVerbose) = _Context->value_Verbose;
		visual_transferout((void *) 0, 0, pTargetType);
		if ( pTargetType != (char *) 0)
			*((int*)pTargetType) = _Context->value_TargetType;
		visual_transferout((void *) 0, 0, pIsDocument);
		if ( pIsDocument != (char *) 0)
			*((int*)pIsDocument) = _Context->value_IsDocument;
		visual_transferout((void *) 0, 0, pProdLang);
		if ( pProdLang != (char *) 0)
			*((int*)pProdLang) = _Context->value_ProdLang;
		visual_transferout(_Context->buffer_DocumentFile, 55, pDocumentFile);
		visual_transferout((void *) 0, 0, pMakefile);
		if ( pMakefile != (char *) 0)
			*((int*)pMakefile) = _Context->value_Makefile;
		visual_transferout(_Context->buffer_MakefileName, 55, pMakefileName);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_production_properties_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,100,116);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(100,116,600,367,2,"Sing : Version 1.0a",19,0x403);
	visual_image(103,138,592,340,"skin.gif",4);
	visual_frame(114,371,562,29,2);
	visual_image(368,404,60,60,"fileicon.gif",0);
	visual_button(250,416,90,30,2,27,0,"&Edit",5,0);
	visual_button(450,416,90,30,2,27,0,"&View",5,0);
	visual_text(120,146,560,32,3,34,0,"Production Parameters of Application Model",42,1538);
	visual_text(120,256,119,18,2,27,0,"Target",6,3);
	visual_text(380,256,128,19,2,27,0,"Language",8,3);
	visual_frame(120,186,560+2,16+2,5);
	visual_text(120+1,186+1,560,16,1,34,0,_Context->buffer_ModelName,70,0);
	visual_text(120,226,120,20,2,34,0,"Filename",8,3);
	visual_frame(240,226,440+2,16+2,5);
	visual_text(240+1,226+1,440,16,1,34,0,_Context->buffer_TargetFile,55,0);
	visual_check(260,376,112,16,2,34,0,"A&utomatic",10,_Context->value_NoConfirm|0);
	visual_check(450,376,112,16,2,34,0,"&Force Build",12,_Context->value_Build|0);
	visual_button(120,416,120,30,2,34,0,"&Accept",7,0);
	visual_button(550,416,120,30,2,34,0,"&Cancel",7,0);
	visual_check(130,376,112,16,2,34,0,"V&isualise",10,_Context->value_Verbose|0);
	visual_select(240,256,120,64,1,27,0,parse_selection("none|module|program|overlay|library",&_Context->value_TargetType),0);
	visual_check(120,306,112,16,2,27,0,"&Document",9,_Context->value_IsDocument|0);
	visual_select(510,256,168,64,1,27,0,parse_selection(ProductionLanguageList,&_Context->value_ProdLang),0);
	visual_text(240,286,440,20,2,27,0,"Application Document Filename",29,3);
	visual_frame(240,306,440+2,16+2,5);
	visual_text(240+1,306+1,440,16,1,27,0,_Context->buffer_DocumentFile,55,0);
	visual_check(120,336,112,16,2,16,28,"&Makefile",9,_Context->value_Makefile|0);
	visual_frame(240,336,440+2,16+2,5);
	visual_text(240+1,336+1,440,16,1,0,0,_Context->buffer_MakefileName,55,0);
	visual_thaw(100,116,600,367);

	return(0);
}
private int on_UseAed_event() {
	accept_production_properties_hide();
	if(_Context->value_Makefile){
	use_editor(_Context->buffer_MakefileName);
	}
	else if(_Context->value_IsDocument){
	use_editor(_Context->buffer_DocumentFile);
	}
	else{
	use_editor(_Context->buffer_TargetFile);
	}
	accept_production_properties_show();
	return(-1);
}
private int on_View_event() {
	use_navigator(_Context->buffer_TargetFile);
	accept_production_properties_show();
	return(-1);
}
private int on_Accept_event() {
	return(13);
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}


private	int	accept_production_properties_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x1031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 679 )  
	&&  (my >= 120 )  
	&&  (mx <= 695 )  
	&&  (my <= 136 )) {
		return(1);	/* auto2 */

		}
	if ((mx >= 663 )  
	&&  (my >= 120 )  
	&&  (mx <= 679 )  
	&&  (my <= 136 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vmprod.htm");
			};
		return(-1);	/* auto2 */

		}
	if (( mx >= 368 ) 
	&&  ( my >= 404 ) 
	&&  ( mx <= 428 ) 
	&&  ( my <= 464 )) {
		return(2); /* auto96 */
		}
	if (( mx >= 250 ) 
	&&  ( my >= 416 ) 
	&&  ( mx <= 340 ) 
	&&  ( my <= 446 )) {
		return(3); /* UseAed */
		}
	if (( mx >= 450 ) 
	&&  ( my >= 416 ) 
	&&  ( mx <= 540 ) 
	&&  ( my <= 446 )) {
		return(4); /* View */
		}
	if (( mx >= 120 ) 
	&&  ( my >= 186 ) 
	&&  ( mx <= 680 ) 
	&&  ( my <= 202 )) {
		return(6); /* ModelName */
		}
	if (( mx >= 240 ) 
	&&  ( my >= 226 ) 
	&&  ( mx <= 680 ) 
	&&  ( my <= 242 )) {
		return(8); /* TargetFile */
		}
	if (( mx >= 260 ) 
	&&  ( my >= 376 ) 
	&&  ( mx <= 372 ) 
	&&  ( my <= 392 )) {
		return(9); /* NoConfirm */
		}
	if (( mx >= 450 ) 
	&&  ( my >= 376 ) 
	&&  ( mx <= 562 ) 
	&&  ( my <= 392 )) {
		return(10); /* Build */
		}
	if (( mx >= 120 ) 
	&&  ( my >= 416 ) 
	&&  ( mx <= 240 ) 
	&&  ( my <= 446 )) {
		return(11); /* Accept */
		}
	if (( mx >= 550 ) 
	&&  ( my >= 416 ) 
	&&  ( mx <= 670 ) 
	&&  ( my <= 446 )) {
		return(12); /* Cancel */
		}
	if (( mx >= 130 ) 
	&&  ( my >= 376 ) 
	&&  ( mx <= 242 ) 
	&&  ( my <= 392 )) {
		return(13); /* Verbose */
		}
	if ((mx >= 240 ) 
	&&  (my >= 256 ) 
	&&  (mx <= 360 ) 
	&&  (my <= 272 )) {
		return(14); /* TargetType */
		}
	if (( mx >= 120 ) 
	&&  ( my >= 306 ) 
	&&  ( mx <= 232 ) 
	&&  ( my <= 322 )) {
		return(15); /* IsDocument */
		}
	if ((mx >= 510 ) 
	&&  (my >= 256 ) 
	&&  (mx <= 678 ) 
	&&  (my <= 272 )) {
		return(16); /* ProdLang */
		}
	if (( mx >= 240 ) 
	&&  ( my >= 306 ) 
	&&  ( mx <= 680 ) 
	&&  ( my <= 322 )) {
		return(18); /* DocumentFile */
		}
	if (( mx >= 120 ) 
	&&  ( my >= 336 ) 
	&&  ( mx <= 232 ) 
	&&  ( my <= 352 )) {
		return(19); /* Makefile */
		}
	if (( mx >= 240 ) 
	&&  ( my >= 336 ) 
	&&  ( mx <= 680 ) 
	&&  ( my <= 352 )) {
		return(20); /* MakefileName */
		}

	return(-1);
}


private	int	accept_production_properties_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x3 :
				/* UseAed */
				visual_button(250,416,90,30,2,27,0,"&Edit",5,2);
				_Context->keycode = visual_getch();
				visual_button(250,416,90,30,2,27,0,"&Edit",5,0);
				break;
			case	0x4 :
				/* View */
				visual_button(450,416,90,30,2,27,0,"&View",5,2);
				_Context->keycode = visual_getch();
				visual_button(450,416,90,30,2,27,0,"&View",5,0);
				break;
			case	0x6 :
				/* ModelName */
				_Context->keycode = visual_edit(120+1,186+1,560,16,1,_Context->buffer_ModelName,70);
				break;
			case	0x8 :
				/* TargetFile */
				_Context->keycode = visual_edit(240+1,226+1,440,16,1,_Context->buffer_TargetFile,55);
				break;
			case	0x9 :
				/* NoConfirm */
				visual_check(260,376,112,16,2,34,0,"A&utomatic",10,(_Context->value_NoConfirm |2));
				_Context->keycode = visual_getch();
				visual_check(260,376,112,16,2,34,0,"A&utomatic",10,(_Context->value_NoConfirm |0));
				break;
			case	0xa :
				/* Build */
				visual_check(450,376,112,16,2,34,0,"&Force Build",12,(_Context->value_Build |2));
				_Context->keycode = visual_getch();
				visual_check(450,376,112,16,2,34,0,"&Force Build",12,(_Context->value_Build |0));
				break;
			case	0xb :
				/* Accept */
				visual_button(120,416,120,30,2,34,0,"&Accept",7,2);
				_Context->keycode = visual_getch();
				visual_button(120,416,120,30,2,34,0,"&Accept",7,0);
				break;
			case	0xc :
				/* Cancel */
				visual_button(550,416,120,30,2,34,0,"&Cancel",7,2);
				_Context->keycode = visual_getch();
				visual_button(550,416,120,30,2,34,0,"&Cancel",7,0);
				break;
			case	0xd :
				/* Verbose */
				visual_check(130,376,112,16,2,34,0,"V&isualise",10,(_Context->value_Verbose |2));
				_Context->keycode = visual_getch();
				visual_check(130,376,112,16,2,34,0,"V&isualise",10,(_Context->value_Verbose |0));
				break;
			case	0xe :
				/* TargetType */
				_Context->keycode = visual_select(240,256,120,64,1,27,0,parse_selection("none|module|program|overlay|library",&_Context->value_TargetType),2);
				break;
			case	0xf :
				/* IsDocument */
				visual_check(120,306,112,16,2,27,0,"&Document",9,(_Context->value_IsDocument |2));
				_Context->keycode = visual_getch();
				visual_check(120,306,112,16,2,27,0,"&Document",9,(_Context->value_IsDocument |0));
				break;
			case	0x10 :
				/* ProdLang */
				_Context->keycode = visual_select(510,256,168,64,1,27,0,parse_selection(ProductionLanguageList,&_Context->value_ProdLang),2);
				break;
			case	0x12 :
				/* DocumentFile */
				_Context->keycode = visual_edit(240+1,306+1,440,16,1,_Context->buffer_DocumentFile,55);
				break;
			case	0x13 :
				/* Makefile */
				visual_check(120,336,112,16,2,16,28,"&Makefile",9,(_Context->value_Makefile |2));
				_Context->keycode = visual_getch();
				visual_check(120,336,112,16,2,16,28,"&Makefile",9,(_Context->value_Makefile |0));
				break;
			case	0x14 :
				/* MakefileName */
				_Context->keycode = visual_edit(240+1,336+1,440,16,1,_Context->buffer_MakefileName,55);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_production_properties_show();
			continue;
		case	0x2 :
			_Context->focus_item=20;
			accept_production_properties_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_production_properties_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* auto2 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x3 :
						/* UseAed */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(250,416,90,30,2,27,0,"&Edit",5,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(250,416,90,30,2,27,0,"&Edit",5,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_UseAed_event()) != -1) break;

							}
						continue;
					case	0x4 :
						/* View */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(450,416,90,30,2,27,0,"&View",5,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(450,416,90,30,2,27,0,"&View",5,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_View_event()) != -1) break;

							}
						continue;
					case	0x6 :
						/* ModelName */
						continue;
					case	0x8 :
						/* TargetFile */
						continue;
					case	0x9 :
						/* NoConfirm */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_NoConfirm += 1;
							_Context->value_NoConfirm &= 1;
							}
						continue;
					case	0xa :
						/* Build */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Build += 1;
							_Context->value_Build &= 1;
							}
						continue;
					case	0xb :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(120,416,120,30,2,34,0,"&Accept",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(120,416,120,30,2,34,0,"&Accept",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0xc :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(550,416,120,30,2,34,0,"&Cancel",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(550,416,120,30,2,34,0,"&Cancel",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

							}
						continue;
					case	0xd :
						/* Verbose */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Verbose += 1;
							_Context->value_Verbose &= 1;
							}
						continue;
					case	0xe :
						/* TargetType */
						continue;
					case	0xf :
						/* IsDocument */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsDocument += 1;
							_Context->value_IsDocument &= 1;
							}
						continue;
					case	0x10 :
						/* ProdLang */
						continue;
					case	0x12 :
						/* DocumentFile */
						continue;
					case	0x13 :
						/* Makefile */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Makefile += 1;
							_Context->value_Makefile &= 1;
							}
						continue;
					case	0x14 :
						/* MakefileName */
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
				_Context->focus_item=20;
			}
			continue;
		case 0x845 : 
		case 0x865 : 
		/* UseAed */
		visual_button(250,416,90,30,2,27,0,"&Edit",5,8);
		visual_button(250,416,90,30,2,27,0,"&Edit",5,0);
		_Context->focus_item=3;
		if ((_Context->keycode = on_UseAed_event()) != -1) break;
		continue;
		case 0x856 : 
		case 0x876 : 
		/* View */
		visual_button(450,416,90,30,2,27,0,"&View",5,8);
		visual_button(450,416,90,30,2,27,0,"&View",5,0);
		_Context->focus_item=4;
		if ((_Context->keycode = on_View_event()) != -1) break;
		continue;
		case 0x875 : 
		case 0x895 : 
		/* NoConfirm */
		_Context->value_NoConfirm += 1;
		_Context->value_NoConfirm &= 1;
		_Context->focus_item=9;
		continue;
		case 0x846 : 
		case 0x866 : 
		/* Build */
		_Context->value_Build += 1;
		_Context->value_Build &= 1;
		_Context->focus_item=10;
		continue;
		case 0x841 : 
		case 0x861 : 
		/* Accept */
		visual_button(120,416,120,30,2,34,0,"&Accept",7,8);
		visual_button(120,416,120,30,2,34,0,"&Accept",7,0);
		_Context->focus_item=11;
		if ((_Context->keycode = on_Accept_event()) != -1) break;
		continue;
		case 0x843 : 
		case 0x863 : 
		/* Cancel */
		visual_button(550,416,120,30,2,34,0,"&Cancel",7,8);
		visual_button(550,416,120,30,2,34,0,"&Cancel",7,0);
		_Context->focus_item=12;
		if ((_Context->keycode = on_Cancel_event()) != -1) break;
		continue;
		case 0x869 : 
		case 0x889 : 
		/* Verbose */
		_Context->value_Verbose += 1;
		_Context->value_Verbose &= 1;
		_Context->focus_item=13;
		continue;
		case 0x844 : 
		case 0x864 : 
		/* IsDocument */
		_Context->value_IsDocument += 1;
		_Context->value_IsDocument &= 1;
		_Context->focus_item=15;
		continue;
		case 0x84d : 
		case 0x86d : 
		/* Makefile */
		_Context->value_Makefile += 1;
		_Context->value_Makefile &= 1;
		_Context->focus_item=19;
		continue;
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_production_properties(
	char * pModelName,
	char * pTargetFile,
	char * pNoConfirm,
	char * pBuild,
	char * pVerbose,
	char * pTargetType,
	char * pIsDocument,
	char * pProdLang,
	char * pDocumentFile,
	char * pMakefile,
	char * pMakefileName)
{
	int	status=0;
	status = accept_production_properties_create(
	 pModelName,
	 pTargetFile,
	 pNoConfirm,
	 pBuild,
	 pVerbose,
	 pTargetType,
	 pIsDocument,
	 pProdLang,
	 pDocumentFile,
	 pMakefile,
	 pMakefileName);
	if ( status != 0) return(status);
	status = accept_production_properties_show();
		enter_modal();
	status = accept_production_properties_focus();
		leave_modal();
	status = accept_production_properties_hide();
	status = accept_production_properties_remove(
	 pModelName,
	 pTargetFile,
	 pNoConfirm,
	 pBuild,
	 pVerbose,
	 pTargetType,
	 pIsDocument,
	 pProdLang,
	 pDocumentFile,
	 pMakefile,
	 pMakefileName);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vmprod_c */
