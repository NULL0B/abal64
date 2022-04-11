
#ifndef _newmanifest_c
#define _newmanifest_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : newmanifest.xml                                          */
/* Target         : newmanifest.c                                            */
/* Identification : 0.0-1354199912-30353.30352                               */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "newmanifest.h"
static int	vfh[16];
private int on_Cancel_event(struct accept_new_manifest_context * _Context);
private int on_Accept_event(struct accept_new_manifest_context * _Context);

public	int	accept_new_manifest_attach()
{
	if ( visual_initialise(3|512) == -1 )
		return(56);

	else	{
		visual_palette("/home/abal3/images/standard.rgb",31);
		cicopalette(0,0);
		vfh[1] = visual_font("standard.fmf",12);
		vfh[2] = visual_font("arial2.fmf",10);
		vfh[3] = visual_font("arial3.fmf",10);
		vfh[4] = visual_font("arial4.fmf",10);
		vfh[5] = visual_font("arial5.fmf",10);
		vfh[6] = visual_font("arial6.fmf",10);
		vfh[7] = visual_font("font7.fmf",9);
		vfh[8] = visual_font("font8.fmf",9);
		vfh[9] = visual_font("font9.fmf",9);
		vfh[10] = visual_font("bmap0416.fmf",12);
		initialise_mouse();
		}
	return(0);
}

public	int	accept_new_manifest_attach_mode(int mode)
{
	if ( visual_initialise(3|mode) == -1 )
		return(56);

	else	{
		visual_palette("/home/abal3/images/standard.rgb",31);
		cicopalette(0,0);
		vfh[1] = visual_font("standard.fmf",12);
		vfh[2] = visual_font("arial2.fmf",10);
		vfh[3] = visual_font("arial3.fmf",10);
		vfh[4] = visual_font("arial4.fmf",10);
		vfh[5] = visual_font("arial5.fmf",10);
		vfh[6] = visual_font("arial6.fmf",10);
		vfh[7] = visual_font("font7.fmf",9);
		vfh[8] = visual_font("font8.fmf",9);
		vfh[9] = visual_font("font9.fmf",9);
		vfh[10] = visual_font("bmap0416.fmf",12);
		initialise_mouse();
		}
	return(0);
}

public	int	accept_new_manifest_detach()
{

	if ( visual_liberate() == -1 )
		return(56);

	return(0);
}

public	int	accept_new_manifest_create(
	struct accept_new_manifest_context ** cptr,
	char * pManifestName,
	char * pManifestSchema,
	char * pProductionFilename,
	char * pAccountName,
	char * pSecurityName,
	char * pSecurityLevel,
	char * pSecurityPolicy,
	char * pFixedPosition,
	char * pFastDrag)
{

	int i;
	struct accept_new_manifest_context * _Context=(struct accept_new_manifest_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("bmap0416.fmf",12);
	if (!(_Context = allocate( sizeof( struct accept_new_manifest_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=11;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_ManifestName, 59, pManifestName);
		visual_transferin(_Context->buffer_ManifestSchema, 59, pManifestSchema);
		visual_transferin(_Context->buffer_ProductionFilename, 59, pProductionFilename);
		visual_transferin(_Context->buffer_AccountName, 59, pAccountName);
		visual_transferin(_Context->buffer_SecurityName, 59, pSecurityName);
		visual_transferin((void *) 0, 0, pSecurityLevel);
		if (!( pSecurityLevel )) _Context->value_SecurityLevel=0;
		else	_Context->value_SecurityLevel = *((int *)pSecurityLevel);
		visual_transferin((void *) 0, 0, pSecurityPolicy);
		if (!( pSecurityPolicy )) _Context->value_SecurityPolicy=0;
		else	_Context->value_SecurityPolicy = *((int *)pSecurityPolicy);
		visual_transferin((void *) 0, 0, pFixedPosition);
		if (!( pFixedPosition )) _Context->value_FixedPosition=0;
		else	_Context->value_FixedPosition = *((int *)pFixedPosition);
		visual_transferin((void *) 0, 0, pFastDrag);
		if (!( pFastDrag )) _Context->value_FastDrag=0;
		else	_Context->value_FastDrag = *((int *)pFastDrag);
		}
	_Context->x_Auto39=155;
	_Context->y_Auto39=100;
	_Context->w_Auto39=490;
	_Context->h_Auto39=400;
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto39,_Context->y_Auto39,490+10,400+10);
	return(0);
}

public 	int	accept_new_manifest_hide(struct accept_new_manifest_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto39,_Context->y_Auto39);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_new_manifest_remove(
	struct accept_new_manifest_context * _Context,
	char * pManifestName,
	char * pManifestSchema,
	char * pProductionFilename,
	char * pAccountName,
	char * pSecurityName,
	char * pSecurityLevel,
	char * pSecurityPolicy,
	char * pFixedPosition,
	char * pFastDrag)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_ManifestName, 59, pManifestName);
		visual_transferout(_Context->buffer_ManifestSchema, 59, pManifestSchema);
		visual_transferout(_Context->buffer_ProductionFilename, 59, pProductionFilename);
		visual_transferout(_Context->buffer_AccountName, 59, pAccountName);
		visual_transferout(_Context->buffer_SecurityName, 59, pSecurityName);
		visual_transferout((void *) 0, 0, pSecurityLevel);
		if ( pSecurityLevel != (char *) 0)
			*((int*)pSecurityLevel) = _Context->value_SecurityLevel;
		visual_transferout((void *) 0, 0, pSecurityPolicy);
		if ( pSecurityPolicy != (char *) 0)
			*((int*)pSecurityPolicy) = _Context->value_SecurityPolicy;
		visual_transferout((void *) 0, 0, pFixedPosition);
		if ( pFixedPosition != (char *) 0)
			*((int*)pFixedPosition) = _Context->value_FixedPosition;
		visual_transferout((void *) 0, 0, pFastDrag);
		if ( pFastDrag != (char *) 0)
			*((int*)pFastDrag) = _Context->value_FastDrag;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_new_manifest_show(struct accept_new_manifest_context * _Context)
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto39,_Context->y_Auto39);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto39,_Context->y_Auto39,490,400,vfh[2],"Accords Manifest Editor: Define Manifest",strlen("Accords Manifest Editor: Define Manifest"),0x403);
	visual_frame(_Context->x_Auto39+120,_Context->y_Auto39+340,250,50,4);
	visual_text(_Context->x_Auto39+10,_Context->y_Auto39+30,462,16,vfh[2],16,0,"Manifest Name",strlen("Manifest Name"),2);
	visual_text(_Context->x_Auto39+10,_Context->y_Auto39+130,462,16,vfh[2],16,0,"Production Filename",strlen("Production Filename"),2);
	visual_text(_Context->x_Auto39+10,_Context->y_Auto39+180,462,16,vfh[2],16,0,"Account Name",strlen("Account Name"),2);
	visual_text(_Context->x_Auto39+10,_Context->y_Auto39+230,462,16,vfh[2],16,0,"Security Name",strlen("Security Name"),2);
	visual_text(_Context->x_Auto39+10,_Context->y_Auto39+280,112,16,vfh[2],16,0,"Security Level",strlen("Security Level"),2);
	visual_text(_Context->x_Auto39+360,_Context->y_Auto39+280,126,16,vfh[2],16,0,"Security Policy",strlen("Security Policy"),2);
	visual_text(_Context->x_Auto39+10,_Context->y_Auto39+80,462,16,vfh[2],16,0,"Manifest Schema",strlen("Manifest Schema"),2);
	visual_frame(_Context->x_Auto39+10,_Context->y_Auto39+50,472+2,16+2,5);
	visual_text(_Context->x_Auto39+10+1,_Context->y_Auto39+50+1,472,16,vfh[1],16,15,_Context->buffer_ManifestName,59,0);
	visual_frame(_Context->x_Auto39+10,_Context->y_Auto39+100,472+2,16+2,5);
	visual_text(_Context->x_Auto39+10+1,_Context->y_Auto39+100+1,472,16,vfh[1],16,15,_Context->buffer_ManifestSchema,59,0);
	visual_frame(_Context->x_Auto39+10,_Context->y_Auto39+150,472+2,16+2,5);
	visual_text(_Context->x_Auto39+10+1,_Context->y_Auto39+150+1,472,16,vfh[1],16,15,_Context->buffer_ProductionFilename,59,0);
	visual_frame(_Context->x_Auto39+10,_Context->y_Auto39+200,472+2,16+2,5);
	visual_text(_Context->x_Auto39+10+1,_Context->y_Auto39+200+1,472,16,vfh[1],16,15,_Context->buffer_AccountName,59,0);
	visual_frame(_Context->x_Auto39+10,_Context->y_Auto39+250,472+2,16+2,5);
	visual_text(_Context->x_Auto39+10+1,_Context->y_Auto39+250+1,472,16,vfh[1],16,15,_Context->buffer_SecurityName,59,0);
	visual_select(_Context->x_Auto39+10,_Context->y_Auto39+300,120,80,vfh[1],0,0,parse_selection("public|restricted|private",&_Context->value_SecurityLevel),0);
	visual_select(_Context->x_Auto39+360,_Context->y_Auto39+300,120,80,vfh[1],0,0,parse_selection("none|orbac|other",&_Context->value_SecurityPolicy),0);
	visual_check(_Context->x_Auto39+150,_Context->y_Auto39+280,200,16,vfh[2],16,28,"Auto Vertical Positioning",strlen("Auto Vertical Positioning"),_Context->value_FixedPosition|0);
	visual_check(_Context->x_Auto39+150,_Context->y_Auto39+300,200,16,vfh[2],16,28,"Fast Drag Positioning",strlen("Fast Drag Positioning"),_Context->value_FastDrag|0);
	visual_button(_Context->x_Auto39+260,_Context->y_Auto39+350,98,32,vfh[2],27,28,"Cancel",strlen("Cancel"),0);
	visual_button(_Context->x_Auto39+130,_Context->y_Auto39+350,98,32,vfh[2],27,28,"Accept",strlen("Accept"),0);
	visual_thaw(_Context->x_Auto39,_Context->y_Auto39,490,400);

	return(0);
}
private int on_Cancel_event(struct accept_new_manifest_context * _Context) {
	return(27);
	return(-1);
}
private int on_Accept_event(struct accept_new_manifest_context * _Context) {
	return(13);
	return(-1);
}


public	int	accept_new_manifest_event(
struct accept_new_manifest_context * _Context){
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= (_Context->x_Auto39+10) ) 
	&&  ( my >= (_Context->y_Auto39+50) ) 
	&&  ( mx <= (_Context->x_Auto39+10+472) ) 
	&&  ( my <= (_Context->y_Auto39+50+16))) {
		return(1); /* ManifestName */
		}
	if (( mx >= (_Context->x_Auto39+10) ) 
	&&  ( my >= (_Context->y_Auto39+100) ) 
	&&  ( mx <= (_Context->x_Auto39+10+472) ) 
	&&  ( my <= (_Context->y_Auto39+100+16))) {
		return(2); /* ManifestSchema */
		}
	if (( mx >= (_Context->x_Auto39+10) ) 
	&&  ( my >= (_Context->y_Auto39+150) ) 
	&&  ( mx <= (_Context->x_Auto39+10+472) ) 
	&&  ( my <= (_Context->y_Auto39+150+16))) {
		return(3); /* ProductionFilename */
		}
	if (( mx >= (_Context->x_Auto39+10) ) 
	&&  ( my >= (_Context->y_Auto39+200) ) 
	&&  ( mx <= (_Context->x_Auto39+10+472) ) 
	&&  ( my <= (_Context->y_Auto39+200+16))) {
		return(4); /* AccountName */
		}
	if (( mx >= (_Context->x_Auto39+10) ) 
	&&  ( my >= (_Context->y_Auto39+250) ) 
	&&  ( mx <= (_Context->x_Auto39+10+472) ) 
	&&  ( my <= (_Context->y_Auto39+250+16))) {
		return(5); /* SecurityName */
		}
	if (( mx >= (_Context->x_Auto39+10+0) ) 
	&&  ( my >= (_Context->y_Auto39+300) ) 
	&&  ( mx <= (_Context->x_Auto39+10+120) ) 
	&&  ( my <= (_Context->y_Auto39+300+16))) {
		return(6); /* SecurityLevel */
		}
	if (( mx >= (_Context->x_Auto39+360+0) ) 
	&&  ( my >= (_Context->y_Auto39+300) ) 
	&&  ( mx <= (_Context->x_Auto39+360+120) ) 
	&&  ( my <= (_Context->y_Auto39+300+16))) {
		return(7); /* SecurityPolicy */
		}
	if (( mx >= (_Context->x_Auto39+150) ) 
	&&  ( my >= (_Context->y_Auto39+280) ) 
	&&  ( mx <= (_Context->x_Auto39+150+200) ) 
	&&  ( my <= (_Context->y_Auto39+280+16))) {
		return(8); /* FixedPosition */
		}
	if (( mx >= (_Context->x_Auto39+150) ) 
	&&  ( my >= (_Context->y_Auto39+300) ) 
	&&  ( mx <= (_Context->x_Auto39+150+200) ) 
	&&  ( my <= (_Context->y_Auto39+300+16))) {
		return(9); /* FastDrag */
		}
	if (( mx >= (_Context->x_Auto39+260) ) 
	&&  ( my >= (_Context->y_Auto39+350) ) 
	&&  ( mx <= (_Context->x_Auto39+260+98) ) 
	&&  ( my <= (_Context->y_Auto39+350+32))) {
		return(10); /* Cancel */
		}
	if (( mx >= (_Context->x_Auto39+130) ) 
	&&  ( my >= (_Context->y_Auto39+350) ) 
	&&  ( mx <= (_Context->x_Auto39+130+98) ) 
	&&  ( my <= (_Context->y_Auto39+350+32))) {
		return(11); /* Accept */
		}

	return(-1);
}


public	int	accept_new_manifest_focus(struct accept_new_manifest_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* ManifestName */
				_Context->keycode = visual_edit(_Context->x_Auto39+10+1,_Context->y_Auto39+50+1,472,16,vfh[1],_Context->buffer_ManifestName,59);
			break;
			case	0x2 :
				/* ManifestSchema */
				_Context->keycode = visual_edit(_Context->x_Auto39+10+1,_Context->y_Auto39+100+1,472,16,vfh[1],_Context->buffer_ManifestSchema,59);
			break;
			case	0x3 :
				/* ProductionFilename */
				_Context->keycode = visual_edit(_Context->x_Auto39+10+1,_Context->y_Auto39+150+1,472,16,vfh[1],_Context->buffer_ProductionFilename,59);
			break;
			case	0x4 :
				/* AccountName */
				_Context->keycode = visual_edit(_Context->x_Auto39+10+1,_Context->y_Auto39+200+1,472,16,vfh[1],_Context->buffer_AccountName,59);
			break;
			case	0x5 :
				/* SecurityName */
				_Context->keycode = visual_edit(_Context->x_Auto39+10+1,_Context->y_Auto39+250+1,472,16,vfh[1],_Context->buffer_SecurityName,59);
			break;
			case	0x6 :
				/* SecurityLevel */
				_Context->keycode = visual_select(_Context->x_Auto39+10,_Context->y_Auto39+300,120,80,vfh[1],0,0,parse_selection("public|restricted|private",&_Context->value_SecurityLevel),2);
				break;
			case	0x7 :
				/* SecurityPolicy */
				_Context->keycode = visual_select(_Context->x_Auto39+360,_Context->y_Auto39+300,120,80,vfh[1],0,0,parse_selection("none|orbac|other",&_Context->value_SecurityPolicy),2);
				break;
			case	0x8 :
				/* FixedPosition */
				visual_check(_Context->x_Auto39+150,_Context->y_Auto39+280,200,16,vfh[2],16,28,"Auto Vertical Positioning",strlen("Auto Vertical Positioning"),(_Context->value_FixedPosition |2));
				_Context->keycode = visual_getch();
	visual_check(_Context->x_Auto39+150,_Context->y_Auto39+280,200,16,vfh[2],16,28,"Auto Vertical Positioning",strlen("Auto Vertical Positioning"),_Context->value_FixedPosition|0);
				break;
			case	0x9 :
				/* FastDrag */
				visual_check(_Context->x_Auto39+150,_Context->y_Auto39+300,200,16,vfh[2],16,28,"Fast Drag Positioning",strlen("Fast Drag Positioning"),(_Context->value_FastDrag |2));
				_Context->keycode = visual_getch();
	visual_check(_Context->x_Auto39+150,_Context->y_Auto39+300,200,16,vfh[2],16,28,"Fast Drag Positioning",strlen("Fast Drag Positioning"),_Context->value_FastDrag|0);
				break;
			case	0xa :
				/* Cancel */
				visual_button(_Context->x_Auto39+260,_Context->y_Auto39+350,98,32,vfh[2],27,28,"Cancel",strlen("Cancel"),2);
				_Context->keycode = visual_getch();
	visual_button(_Context->x_Auto39+260,_Context->y_Auto39+350,98,32,vfh[2],27,28,"Cancel",strlen("Cancel"),0);
				break;
			case	0xb :
				/* Accept */
				visual_button(_Context->x_Auto39+130,_Context->y_Auto39+350,98,32,vfh[2],27,28,"Accept",strlen("Accept"),2);
				_Context->keycode = visual_getch();
	visual_button(_Context->x_Auto39+130,_Context->y_Auto39+350,98,32,vfh[2],27,28,"Accept",strlen("Accept"),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_new_manifest_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=11;
			accept_new_manifest_show(_Context);
			continue;
		case	0x100 :
			if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
			if ((retcode=accept_new_manifest_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* ManifestName */
					continue;
				case	0x2 :
					/* ManifestSchema */
					continue;
				case	0x3 :
					/* ProductionFilename */
					continue;
				case	0x4 :
					/* AccountName */
					continue;
				case	0x5 :
					/* SecurityName */
					continue;
				case	0x6 :
					/* SecurityLevel */
					continue;
				case	0x7 :
					/* SecurityPolicy */
					continue;
				case	0x8 :
					/* FixedPosition */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_FixedPosition += 1;
						_Context->value_FixedPosition &= 1;
						}
					continue;
				case	0x9 :
					/* FastDrag */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_FastDrag += 1;
						_Context->value_FastDrag &= 1;
						}
					continue;
				case	0xa :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(_Context->x_Auto39+260,_Context->y_Auto39+350,98,32,vfh[2],27,28,"Cancel",strlen("Cancel"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(_Context->x_Auto39+260,_Context->y_Auto39+350,98,32,vfh[2],27,28,"Cancel",strlen("Cancel"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(_Context->x_Auto39+130,_Context->y_Auto39+350,98,32,vfh[2],27,28,"Accept",strlen("Accept"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(_Context->x_Auto39+130,_Context->y_Auto39+350,98,32,vfh[2],27,28,"Accept",strlen("Accept"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0xffffffff :
				default :
					_Context->focus_item=1;
				continue;
				}
				break;
		case	0x1b :
			break;
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
				_Context->focus_item=11;
			}
			continue;
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_new_manifest(
	char * pManifestName,
	char * pManifestSchema,
	char * pProductionFilename,
	char * pAccountName,
	char * pSecurityName,
	char * pSecurityLevel,
	char * pSecurityPolicy,
	char * pFixedPosition,
	char * pFastDrag)
{
	int	status=0;
	struct accept_new_manifest_context * _Context=(struct accept_new_manifest_context*) 0;
	status = accept_new_manifest_create(
	&_Context,
	 pManifestName,
	 pManifestSchema,
	 pProductionFilename,
	 pAccountName,
	 pSecurityName,
	 pSecurityLevel,
	 pSecurityPolicy,
	 pFixedPosition,
	 pFastDrag);
	if ( status != 0) return(status);
	status = accept_new_manifest_show(_Context);
		enter_modal();
	status = accept_new_manifest_focus(_Context);
		leave_modal();
	status = accept_new_manifest_hide(_Context);
	status = accept_new_manifest_remove(
	_Context,
	 pManifestName,
	 pManifestSchema,
	 pProductionFilename,
	 pAccountName,
	 pSecurityName,
	 pSecurityLevel,
	 pSecurityPolicy,
	 pFixedPosition,
	 pFastDrag);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _newmanifest_c */
