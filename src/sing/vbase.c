
#ifndef _vbase_c
#define _vbase_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vbase.xml                                                */
/* Target         : vbase.c                                                  */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en__Auto3632   ""
#define en_Auto3633   "Model Editor Options Configuration"
#define fr_Auto3633   "Configuration de l'Editeur de ModŠles"
#define en__Auto3633   ""
#define fr__Auto3633   ""
#define en_HyperSpace   "Hyperview Active"
#define fr_HyperSpace   "Hyperview Active"
#define it_HyperSpace   "Hyperview Active"
#define es_HyperSpace   "Hyperview Active"
#define de_HyperSpace   "Hyperview Active"
#define nl_HyperSpace   "Hyperview Active"
#define pt_HyperSpace   "Hyperview Active"
#define xx_HyperSpace   "Hyperview Active"
#define en__HyperSpace   ""
#define fr__HyperSpace   ""
#define it__HyperSpace   ""
#define es__HyperSpace   ""
#define de__HyperSpace   ""
#define nl__HyperSpace   ""
#define pt__HyperSpace   ""
#define xx__HyperSpace   ""
#define en_HelpBubble   "Help Bubbles Active"
#define fr_HelpBubble   "Bulles d'aide Actives"
#define it_HelpBubble   "Help Bubbles Active"
#define es_HelpBubble   "Help Bubbles Active"
#define de_HelpBubble   "Help Bubbles Active"
#define nl_HelpBubble   "Help Bubbles Active"
#define pt_HelpBubble   "Help Bubbles Active"
#define xx_HelpBubble   "Help Bubbles Active"
#define en__HelpBubble   ""
#define fr__HelpBubble   ""
#define it__HelpBubble   ""
#define es__HelpBubble   ""
#define de__HelpBubble   ""
#define nl__HelpBubble   ""
#define pt__HelpBubble   ""
#define xx__HelpBubble   ""
#define en_Bender   "Diagonal|Direct|Routed"
#define fr_Bender   "Diagonale|Directe|Rout‚"
#define it_Bender   "Diagonal|Direct|Routed"
#define es_Bender   "Diagonal|Direct|Routed"
#define de_Bender   "Diagonal|Direct|Routed"
#define nl_Bender   "Diagonal|Direct|Routed"
#define pt_Bender   "Diagonal|Direct|Routed"
#define xx_Bender   "Diagonal|Direct|Routed"
#define en__Bender   ""
#define fr__Bender   ""
#define it__Bender   ""
#define es__Bender   ""
#define de__Bender   ""
#define nl__Bender   ""
#define pt__Bender   ""
#define xx__Bender   ""
#define en_TraceWidth   ""
#define en__TraceWidth   ""
#define en_TraceColour   ""
#define en__TraceColour   ""
#define en_Depth   ""
#define en__Depth   ""
#define en_TracePadding   ""
#define en__TracePadding   ""
#define en_xPadding   ""
#define en__xPadding   ""
#define en_yPadding   ""
#define en__yPadding   ""
#define en_Fraction   ""
#define en__Fraction   ""
#define en_Schema   "None|Sing|Merise|Uml"
#define fr_Schema   "Sans|Sing|Merise|Uml"
#define it_Schema   "None|Sing|Merise|Uml"
#define es_Schema   "None|Sing|Merise|Uml"
#define de_Schema   "None|Sing|Merise|Uml"
#define nl_Schema   "None|Sing|Merise|Uml"
#define pt_Schema   "None|Sing|Merise|Uml"
#define xx_Schema   "None|Sing|Merise|Uml"
#define en__Schema   ""
#define fr__Schema   ""
#define it__Schema   ""
#define es__Schema   ""
#define de__Schema   ""
#define nl__Schema   ""
#define pt__Schema   ""
#define xx__Schema   ""
#define en_Accept   "ok.gif"
#define fr_Accept   "ok.gif"
#define it_Accept   "ok.gif"
#define es_Accept   "ok.gif"
#define de_Accept   "ok.gif"
#define nl_Accept   "ok.gif"
#define pt_Accept   "ok.gif"
#define xx_Accept   "ok.gif"
#define en__Accept   ""
#define fr__Accept   ""
#define it__Accept   ""
#define es__Accept   ""
#define de__Accept   ""
#define nl__Accept   ""
#define pt__Accept   ""
#define xx__Accept   ""
#define en_Cancel   "cancel.gif"
#define fr_Cancel   "cancel.gif"
#define it_Cancel   "cancel.gif"
#define es_Cancel   "cancel.gif"
#define de_Cancel   "cancel.gif"
#define nl_Cancel   "cancel.gif"
#define pt_Cancel   "cancel.gif"
#define xx_Cancel   "cancel.gif"
#define en__Cancel   ""
#define fr__Cancel   ""
#define it__Cancel   ""
#define es__Cancel   ""
#define de__Cancel   ""
#define nl__Cancel   ""
#define pt__Cancel   ""
#define xx__Cancel   ""
#define en_Auto3636   "Trace Links"
#define fr_Auto3636   "Traceer Liens"
#define it_Auto3636   "Trace Links"
#define es_Auto3636   "Trace Links"
#define de_Auto3636   "Trace Links"
#define nl_Auto3636   "Trace Links"
#define pt_Auto3636   "Trace Links"
#define xx_Auto3636   "Trace Links"
#define en__Auto3636   ""
#define fr__Auto3636   ""
#define it__Auto3636   ""
#define es__Auto3636   ""
#define de__Auto3636   ""
#define nl__Auto3636   ""
#define pt__Auto3636   ""
#define xx__Auto3636   ""
#define en_Auto3637   "Representation"
#define fr_Auto3637   "Representation"
#define en__Auto3637   ""
#define fr__Auto3637   ""
#define en_Auto3638   "Trace Width"
#define fr_Auto3638   "Largeur de trac‚"
#define it_Auto3638   "Trace Width"
#define es_Auto3638   "Trace Width"
#define de_Auto3638   "Trace Width"
#define nl_Auto3638   "Trace Width"
#define pt_Auto3638   "Trace Width"
#define xx_Auto3638   "Trace Width"
#define en__Auto3638   ""
#define fr__Auto3638   ""
#define it__Auto3638   ""
#define es__Auto3638   ""
#define de__Auto3638   ""
#define nl__Auto3638   ""
#define pt__Auto3638   ""
#define xx__Auto3638   ""
#define en_Auto3639   "Trace Colour"
#define fr_Auto3639   "Couleur de Trac‚"
#define it_Auto3639   "Trace Colour"
#define es_Auto3639   "Trace Colour"
#define de_Auto3639   "Trace Colour"
#define nl_Auto3639   "Trace Colour"
#define pt_Auto3639   "Trace Colour"
#define xx_Auto3639   "Trace Colour"
#define en__Auto3639   ""
#define fr__Auto3639   ""
#define it__Auto3639   ""
#define es__Auto3639   ""
#define de__Auto3639   ""
#define nl__Auto3639   ""
#define pt__Auto3639   ""
#define xx__Auto3639   ""
#define en_Auto3640   "Recursion Depth"
#define fr_Auto3640   "Profondeur R‚cursion"
#define it_Auto3640   "Recursion Depth"
#define es_Auto3640   "Recursion Depth"
#define de_Auto3640   "Recursion Depth"
#define nl_Auto3640   "Recursion Depth"
#define pt_Auto3640   "Recursion Depth"
#define xx_Auto3640   "Recursion Depth"
#define en__Auto3640   ""
#define fr__Auto3640   ""
#define it__Auto3640   ""
#define es__Auto3640   ""
#define de__Auto3640   ""
#define nl__Auto3640   ""
#define pt__Auto3640   ""
#define xx__Auto3640   ""
#define en_Auto3641   "Trace Padding"
#define fr_Auto3641   "Espacement de Trac‚"
#define it_Auto3641   "Trace Padding"
#define es_Auto3641   "Trace Padding"
#define de_Auto3641   "Trace Padding"
#define nl_Auto3641   "Trace Padding"
#define pt_Auto3641   "Trace Padding"
#define xx_Auto3641   "Trace Padding"
#define en__Auto3641   ""
#define fr__Auto3641   ""
#define it__Auto3641   ""
#define es__Auto3641   ""
#define de__Auto3641   ""
#define nl__Auto3641   ""
#define pt__Auto3641   ""
#define xx__Auto3641   ""
#define en_Auto3642   "Horizontal Model Padding"
#define fr_Auto3642   "Espacement Horizontale"
#define it_Auto3642   "Horizontal Model Padding"
#define es_Auto3642   "Horizontal Model Padding"
#define de_Auto3642   "Horizontal Model Padding"
#define nl_Auto3642   "Horizontal Model Padding"
#define pt_Auto3642   "Horizontal Model Padding"
#define xx_Auto3642   "Horizontal Model Padding"
#define en__Auto3642   ""
#define fr__Auto3642   ""
#define it__Auto3642   ""
#define es__Auto3642   ""
#define de__Auto3642   ""
#define nl__Auto3642   ""
#define pt__Auto3642   ""
#define xx__Auto3642   ""
#define en_Auto3643   "Vertical Model Padding"
#define fr_Auto3643   "Espacement verticale"
#define it_Auto3643   "Vertical Model Padding"
#define es_Auto3643   "Vertical Model Padding"
#define de_Auto3643   "Vertical Model Padding"
#define nl_Auto3643   "Vertical Model Padding"
#define pt_Auto3643   "Vertical Model Padding"
#define xx_Auto3643   "Vertical Model Padding"
#define en__Auto3643   ""
#define fr__Auto3643   ""
#define it__Auto3643   ""
#define es__Auto3643   ""
#define de__Auto3643   ""
#define nl__Auto3643   ""
#define pt__Auto3643   ""
#define xx__Auto3643   ""
#define en_Auto3644   "Hyperview Fraction  :   1 /"
#define fr_Auto3644   "Fraction Hyperview 1 /"
#define it_Auto3644   "Hyperview Fraction    1 /"
#define es_Auto3644   "Hyperview Fraction    1 /"
#define de_Auto3644   "Hyperview Fraction    1 /"
#define nl_Auto3644   "Hyperview Fraction    1 /"
#define pt_Auto3644   "Hyperview Fraction    1 /"
#define xx_Auto3644   "Hyperview Fraction    1 /"
#define en__Auto3644   ""
#define fr__Auto3644   ""
#define it__Auto3644   ""
#define es__Auto3644   ""
#define de__Auto3644   ""
#define nl__Auto3644   ""
#define pt__Auto3644   ""
#define xx__Auto3644   ""

private struct accept_database_control_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3632[8];
	char * hint_Auto3632[8];
	int	x_Auto3632;
	int	y_Auto3632;
	int	w_Auto3632;
	int	h_Auto3632;
	char * msg_Auto3633[8];
	char * hint_Auto3633[8];
	char * hint_Auto3634[8];
	char * hint_Auto3635[8];
	char * msg_HyperSpace[8];
	int	trigger_HyperSpace;
	char * hint_HyperSpace[8];
	int	value_HyperSpace;
	char * msg_HelpBubble[8];
	int	trigger_HelpBubble;
	char * hint_HelpBubble[8];
	int	value_HelpBubble;
	char * msg_Bender[8];
	char * hint_Bender[8];
	int	value_Bender;
	char * hint_TraceWidth[8];
	char	buffer_TraceWidth[8];
	char * hint_TraceColour[8];
	char	buffer_TraceColour[8];
	char * hint_Depth[8];
	char	buffer_Depth[8];
	char * hint_TracePadding[8];
	char	buffer_TracePadding[8];
	char * hint_xPadding[8];
	char	buffer_xPadding[8];
	char * hint_yPadding[8];
	char	buffer_yPadding[8];
	char * hint_Fraction[8];
	char	buffer_Fraction[8];
	char * msg_Schema[8];
	char * hint_Schema[8];
	int	value_Schema;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	char * msg_Auto3636[8];
	char * hint_Auto3636[8];
	char * msg_Auto3637[8];
	char * hint_Auto3637[8];
	char * msg_Auto3638[8];
	char * hint_Auto3638[8];
	char * msg_Auto3639[8];
	char * hint_Auto3639[8];
	char * msg_Auto3640[8];
	char * hint_Auto3640[8];
	char * msg_Auto3641[8];
	char * hint_Auto3641[8];
	char * msg_Auto3642[8];
	char * hint_Auto3642[8];
	char * msg_Auto3643[8];
	char * hint_Auto3643[8];
	char * msg_Auto3644[8];
	char * hint_Auto3644[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[12];
	};
static int	vfh[16];
private int on_Accept_event(struct accept_database_control_context * _Context);
private int on_Cancel_event(struct accept_database_control_context * _Context);

public	int	accept_database_control_create(
	struct accept_database_control_context ** cptr,
	char * pHyperSpace,
	char * pHelpBubble,
	char * pBender,
	char * pTraceWidth,
	char * pTraceColour,
	char * pDepth,
	char * pTracePadding,
	char * pxPadding,
	char * pyPadding,
	char * pFraction,
	char * pSchema)
{

	int i;
	struct accept_database_control_context * _Context=(struct accept_database_control_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("bmap0414.fmf",12);
	if (!(_Context = allocate( sizeof( struct accept_database_control_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=14;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pHyperSpace);
		if (!( pHyperSpace )) _Context->value_HyperSpace=0;
		else	_Context->value_HyperSpace = *((int *)pHyperSpace);
		visual_transferin((void *) 0, 0, pHelpBubble);
		if (!( pHelpBubble )) _Context->value_HelpBubble=0;
		else	_Context->value_HelpBubble = *((int *)pHelpBubble);
		visual_transferin((void *) 0, 0, pBender);
		if (!( pBender )) _Context->value_Bender=0;
		else	_Context->value_Bender = *((int *)pBender);
		visual_transferin(_Context->buffer_TraceWidth, 7, pTraceWidth);
		visual_transferin(_Context->buffer_TraceColour, 7, pTraceColour);
		visual_transferin(_Context->buffer_Depth, 7, pDepth);
		visual_transferin(_Context->buffer_TracePadding, 7, pTracePadding);
		visual_transferin(_Context->buffer_xPadding, 7, pxPadding);
		visual_transferin(_Context->buffer_yPadding, 7, pyPadding);
		visual_transferin(_Context->buffer_Fraction, 7, pFraction);
		visual_transferin((void *) 0, 0, pSchema);
		if (!( pSchema )) _Context->value_Schema=0;
		else	_Context->value_Schema = *((int *)pSchema);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3632[i]=" ";
	_Context->hint_Auto3632[0]=en__Auto3632;
	_Context->x_Auto3632=260;
	_Context->y_Auto3632=85;
	_Context->w_Auto3632=280;
	_Context->h_Auto3632=430;
	_Context->window_col=0;
	_Context->window_row=0;
	if(((_Context->y_Auto3632=visual_event(6))+430)>hardrows())
	_Context->y_Auto3632=(hardrows()-430);
	if(((_Context->x_Auto3632=visual_event(7))+280)>hardcolumns())
	_Context->x_Auto3632=(hardcolumns()-280);
	for (i=0; i < 8; i++)_Context->msg_Auto3633[i]=" ";
	_Context->msg_Auto3633[0]=en_Auto3633;
	_Context->msg_Auto3633[1]=fr_Auto3633;
	_Context->hint_Auto3633[0]=en__Auto3633;
	_Context->hint_Auto3633[1]=fr__Auto3633;
	for (i=0; i < 8; i++)_Context->msg_HyperSpace[i]=" ";
	_Context->msg_HyperSpace[0]=en_HyperSpace;
	_Context->msg_HyperSpace[1]=fr_HyperSpace;
	_Context->msg_HyperSpace[2]=it_HyperSpace;
	_Context->msg_HyperSpace[3]=es_HyperSpace;
	_Context->msg_HyperSpace[4]=de_HyperSpace;
	_Context->msg_HyperSpace[5]=nl_HyperSpace;
	_Context->msg_HyperSpace[6]=pt_HyperSpace;
	_Context->msg_HyperSpace[7]=xx_HyperSpace;
	_Context->hint_HyperSpace[0]=en__HyperSpace;
	_Context->hint_HyperSpace[1]=fr__HyperSpace;
	_Context->hint_HyperSpace[2]=it__HyperSpace;
	_Context->hint_HyperSpace[3]=es__HyperSpace;
	_Context->hint_HyperSpace[4]=de__HyperSpace;
	_Context->hint_HyperSpace[5]=nl__HyperSpace;
	_Context->hint_HyperSpace[6]=pt__HyperSpace;
	_Context->hint_HyperSpace[7]=xx__HyperSpace;
	for (i=0; i < 8; i++)_Context->msg_HelpBubble[i]=" ";
	_Context->msg_HelpBubble[0]=en_HelpBubble;
	_Context->msg_HelpBubble[1]=fr_HelpBubble;
	_Context->msg_HelpBubble[2]=it_HelpBubble;
	_Context->msg_HelpBubble[3]=es_HelpBubble;
	_Context->msg_HelpBubble[4]=de_HelpBubble;
	_Context->msg_HelpBubble[5]=nl_HelpBubble;
	_Context->msg_HelpBubble[6]=pt_HelpBubble;
	_Context->msg_HelpBubble[7]=xx_HelpBubble;
	_Context->hint_HelpBubble[0]=en__HelpBubble;
	_Context->hint_HelpBubble[1]=fr__HelpBubble;
	_Context->hint_HelpBubble[2]=it__HelpBubble;
	_Context->hint_HelpBubble[3]=es__HelpBubble;
	_Context->hint_HelpBubble[4]=de__HelpBubble;
	_Context->hint_HelpBubble[5]=nl__HelpBubble;
	_Context->hint_HelpBubble[6]=pt__HelpBubble;
	_Context->hint_HelpBubble[7]=xx__HelpBubble;
	for (i=0; i < 8; i++)_Context->msg_Bender[i]=" ";
	_Context->msg_Bender[0]=en_Bender;
	_Context->msg_Bender[1]=fr_Bender;
	_Context->msg_Bender[2]=it_Bender;
	_Context->msg_Bender[3]=es_Bender;
	_Context->msg_Bender[4]=de_Bender;
	_Context->msg_Bender[5]=nl_Bender;
	_Context->msg_Bender[6]=pt_Bender;
	_Context->msg_Bender[7]=xx_Bender;
	_Context->hint_Bender[0]=en__Bender;
	_Context->hint_Bender[1]=fr__Bender;
	_Context->hint_Bender[2]=it__Bender;
	_Context->hint_Bender[3]=es__Bender;
	_Context->hint_Bender[4]=de__Bender;
	_Context->hint_Bender[5]=nl__Bender;
	_Context->hint_Bender[6]=pt__Bender;
	_Context->hint_Bender[7]=xx__Bender;
	_Context->hint_TraceWidth[0]=en__TraceWidth;
	_Context->hint_TraceColour[0]=en__TraceColour;
	_Context->hint_Depth[0]=en__Depth;
	_Context->hint_TracePadding[0]=en__TracePadding;
	_Context->hint_xPadding[0]=en__xPadding;
	_Context->hint_yPadding[0]=en__yPadding;
	_Context->hint_Fraction[0]=en__Fraction;
	for (i=0; i < 8; i++)_Context->msg_Schema[i]=" ";
	_Context->msg_Schema[0]=en_Schema;
	_Context->msg_Schema[1]=fr_Schema;
	_Context->msg_Schema[2]=it_Schema;
	_Context->msg_Schema[3]=es_Schema;
	_Context->msg_Schema[4]=de_Schema;
	_Context->msg_Schema[5]=nl_Schema;
	_Context->msg_Schema[6]=pt_Schema;
	_Context->msg_Schema[7]=xx_Schema;
	_Context->hint_Schema[0]=en__Schema;
	_Context->hint_Schema[1]=fr__Schema;
	_Context->hint_Schema[2]=it__Schema;
	_Context->hint_Schema[3]=es__Schema;
	_Context->hint_Schema[4]=de__Schema;
	_Context->hint_Schema[5]=nl__Schema;
	_Context->hint_Schema[6]=pt__Schema;
	_Context->hint_Schema[7]=xx__Schema;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	_Context->msg_Accept[2]=it_Accept;
	_Context->msg_Accept[3]=es_Accept;
	_Context->msg_Accept[4]=de_Accept;
	_Context->msg_Accept[5]=nl_Accept;
	_Context->msg_Accept[6]=pt_Accept;
	_Context->msg_Accept[7]=xx_Accept;
	_Context->hint_Accept[0]=en__Accept;
	_Context->hint_Accept[1]=fr__Accept;
	_Context->hint_Accept[2]=it__Accept;
	_Context->hint_Accept[3]=es__Accept;
	_Context->hint_Accept[4]=de__Accept;
	_Context->hint_Accept[5]=nl__Accept;
	_Context->hint_Accept[6]=pt__Accept;
	_Context->hint_Accept[7]=xx__Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->msg_Cancel[2]=it_Cancel;
	_Context->msg_Cancel[3]=es_Cancel;
	_Context->msg_Cancel[4]=de_Cancel;
	_Context->msg_Cancel[5]=nl_Cancel;
	_Context->msg_Cancel[6]=pt_Cancel;
	_Context->msg_Cancel[7]=xx_Cancel;
	_Context->hint_Cancel[0]=en__Cancel;
	_Context->hint_Cancel[1]=fr__Cancel;
	_Context->hint_Cancel[2]=it__Cancel;
	_Context->hint_Cancel[3]=es__Cancel;
	_Context->hint_Cancel[4]=de__Cancel;
	_Context->hint_Cancel[5]=nl__Cancel;
	_Context->hint_Cancel[6]=pt__Cancel;
	_Context->hint_Cancel[7]=xx__Cancel;
	for (i=0; i < 8; i++)_Context->msg_Auto3636[i]=" ";
	_Context->msg_Auto3636[0]=en_Auto3636;
	_Context->msg_Auto3636[1]=fr_Auto3636;
	_Context->msg_Auto3636[2]=it_Auto3636;
	_Context->msg_Auto3636[3]=es_Auto3636;
	_Context->msg_Auto3636[4]=de_Auto3636;
	_Context->msg_Auto3636[5]=nl_Auto3636;
	_Context->msg_Auto3636[6]=pt_Auto3636;
	_Context->msg_Auto3636[7]=xx_Auto3636;
	_Context->hint_Auto3636[0]=en__Auto3636;
	_Context->hint_Auto3636[1]=fr__Auto3636;
	_Context->hint_Auto3636[2]=it__Auto3636;
	_Context->hint_Auto3636[3]=es__Auto3636;
	_Context->hint_Auto3636[4]=de__Auto3636;
	_Context->hint_Auto3636[5]=nl__Auto3636;
	_Context->hint_Auto3636[6]=pt__Auto3636;
	_Context->hint_Auto3636[7]=xx__Auto3636;
	for (i=0; i < 8; i++)_Context->msg_Auto3637[i]=" ";
	_Context->msg_Auto3637[0]=en_Auto3637;
	_Context->msg_Auto3637[1]=fr_Auto3637;
	_Context->hint_Auto3637[0]=en__Auto3637;
	_Context->hint_Auto3637[1]=fr__Auto3637;
	for (i=0; i < 8; i++)_Context->msg_Auto3638[i]=" ";
	_Context->msg_Auto3638[0]=en_Auto3638;
	_Context->msg_Auto3638[1]=fr_Auto3638;
	_Context->msg_Auto3638[2]=it_Auto3638;
	_Context->msg_Auto3638[3]=es_Auto3638;
	_Context->msg_Auto3638[4]=de_Auto3638;
	_Context->msg_Auto3638[5]=nl_Auto3638;
	_Context->msg_Auto3638[6]=pt_Auto3638;
	_Context->msg_Auto3638[7]=xx_Auto3638;
	_Context->hint_Auto3638[0]=en__Auto3638;
	_Context->hint_Auto3638[1]=fr__Auto3638;
	_Context->hint_Auto3638[2]=it__Auto3638;
	_Context->hint_Auto3638[3]=es__Auto3638;
	_Context->hint_Auto3638[4]=de__Auto3638;
	_Context->hint_Auto3638[5]=nl__Auto3638;
	_Context->hint_Auto3638[6]=pt__Auto3638;
	_Context->hint_Auto3638[7]=xx__Auto3638;
	for (i=0; i < 8; i++)_Context->msg_Auto3639[i]=" ";
	_Context->msg_Auto3639[0]=en_Auto3639;
	_Context->msg_Auto3639[1]=fr_Auto3639;
	_Context->msg_Auto3639[2]=it_Auto3639;
	_Context->msg_Auto3639[3]=es_Auto3639;
	_Context->msg_Auto3639[4]=de_Auto3639;
	_Context->msg_Auto3639[5]=nl_Auto3639;
	_Context->msg_Auto3639[6]=pt_Auto3639;
	_Context->msg_Auto3639[7]=xx_Auto3639;
	_Context->hint_Auto3639[0]=en__Auto3639;
	_Context->hint_Auto3639[1]=fr__Auto3639;
	_Context->hint_Auto3639[2]=it__Auto3639;
	_Context->hint_Auto3639[3]=es__Auto3639;
	_Context->hint_Auto3639[4]=de__Auto3639;
	_Context->hint_Auto3639[5]=nl__Auto3639;
	_Context->hint_Auto3639[6]=pt__Auto3639;
	_Context->hint_Auto3639[7]=xx__Auto3639;
	for (i=0; i < 8; i++)_Context->msg_Auto3640[i]=" ";
	_Context->msg_Auto3640[0]=en_Auto3640;
	_Context->msg_Auto3640[1]=fr_Auto3640;
	_Context->msg_Auto3640[2]=it_Auto3640;
	_Context->msg_Auto3640[3]=es_Auto3640;
	_Context->msg_Auto3640[4]=de_Auto3640;
	_Context->msg_Auto3640[5]=nl_Auto3640;
	_Context->msg_Auto3640[6]=pt_Auto3640;
	_Context->msg_Auto3640[7]=xx_Auto3640;
	_Context->hint_Auto3640[0]=en__Auto3640;
	_Context->hint_Auto3640[1]=fr__Auto3640;
	_Context->hint_Auto3640[2]=it__Auto3640;
	_Context->hint_Auto3640[3]=es__Auto3640;
	_Context->hint_Auto3640[4]=de__Auto3640;
	_Context->hint_Auto3640[5]=nl__Auto3640;
	_Context->hint_Auto3640[6]=pt__Auto3640;
	_Context->hint_Auto3640[7]=xx__Auto3640;
	for (i=0; i < 8; i++)_Context->msg_Auto3641[i]=" ";
	_Context->msg_Auto3641[0]=en_Auto3641;
	_Context->msg_Auto3641[1]=fr_Auto3641;
	_Context->msg_Auto3641[2]=it_Auto3641;
	_Context->msg_Auto3641[3]=es_Auto3641;
	_Context->msg_Auto3641[4]=de_Auto3641;
	_Context->msg_Auto3641[5]=nl_Auto3641;
	_Context->msg_Auto3641[6]=pt_Auto3641;
	_Context->msg_Auto3641[7]=xx_Auto3641;
	_Context->hint_Auto3641[0]=en__Auto3641;
	_Context->hint_Auto3641[1]=fr__Auto3641;
	_Context->hint_Auto3641[2]=it__Auto3641;
	_Context->hint_Auto3641[3]=es__Auto3641;
	_Context->hint_Auto3641[4]=de__Auto3641;
	_Context->hint_Auto3641[5]=nl__Auto3641;
	_Context->hint_Auto3641[6]=pt__Auto3641;
	_Context->hint_Auto3641[7]=xx__Auto3641;
	for (i=0; i < 8; i++)_Context->msg_Auto3642[i]=" ";
	_Context->msg_Auto3642[0]=en_Auto3642;
	_Context->msg_Auto3642[1]=fr_Auto3642;
	_Context->msg_Auto3642[2]=it_Auto3642;
	_Context->msg_Auto3642[3]=es_Auto3642;
	_Context->msg_Auto3642[4]=de_Auto3642;
	_Context->msg_Auto3642[5]=nl_Auto3642;
	_Context->msg_Auto3642[6]=pt_Auto3642;
	_Context->msg_Auto3642[7]=xx_Auto3642;
	_Context->hint_Auto3642[0]=en__Auto3642;
	_Context->hint_Auto3642[1]=fr__Auto3642;
	_Context->hint_Auto3642[2]=it__Auto3642;
	_Context->hint_Auto3642[3]=es__Auto3642;
	_Context->hint_Auto3642[4]=de__Auto3642;
	_Context->hint_Auto3642[5]=nl__Auto3642;
	_Context->hint_Auto3642[6]=pt__Auto3642;
	_Context->hint_Auto3642[7]=xx__Auto3642;
	for (i=0; i < 8; i++)_Context->msg_Auto3643[i]=" ";
	_Context->msg_Auto3643[0]=en_Auto3643;
	_Context->msg_Auto3643[1]=fr_Auto3643;
	_Context->msg_Auto3643[2]=it_Auto3643;
	_Context->msg_Auto3643[3]=es_Auto3643;
	_Context->msg_Auto3643[4]=de_Auto3643;
	_Context->msg_Auto3643[5]=nl_Auto3643;
	_Context->msg_Auto3643[6]=pt_Auto3643;
	_Context->msg_Auto3643[7]=xx_Auto3643;
	_Context->hint_Auto3643[0]=en__Auto3643;
	_Context->hint_Auto3643[1]=fr__Auto3643;
	_Context->hint_Auto3643[2]=it__Auto3643;
	_Context->hint_Auto3643[3]=es__Auto3643;
	_Context->hint_Auto3643[4]=de__Auto3643;
	_Context->hint_Auto3643[5]=nl__Auto3643;
	_Context->hint_Auto3643[6]=pt__Auto3643;
	_Context->hint_Auto3643[7]=xx__Auto3643;
	for (i=0; i < 8; i++)_Context->msg_Auto3644[i]=" ";
	_Context->msg_Auto3644[0]=en_Auto3644;
	_Context->msg_Auto3644[1]=fr_Auto3644;
	_Context->msg_Auto3644[2]=it_Auto3644;
	_Context->msg_Auto3644[3]=es_Auto3644;
	_Context->msg_Auto3644[4]=de_Auto3644;
	_Context->msg_Auto3644[5]=nl_Auto3644;
	_Context->msg_Auto3644[6]=pt_Auto3644;
	_Context->msg_Auto3644[7]=xx_Auto3644;
	_Context->hint_Auto3644[0]=en__Auto3644;
	_Context->hint_Auto3644[1]=fr__Auto3644;
	_Context->hint_Auto3644[2]=it__Auto3644;
	_Context->hint_Auto3644[3]=es__Auto3644;
	_Context->hint_Auto3644[4]=de__Auto3644;
	_Context->hint_Auto3644[5]=nl__Auto3644;
	_Context->hint_Auto3644[6]=pt__Auto3644;
	_Context->hint_Auto3644[7]=xx__Auto3644;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3632,_Context->y_Auto3632,280+10,430+10);
	return(0);
}

public 	int	accept_database_control_hide(struct accept_database_control_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3632,_Context->y_Auto3632);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_database_control_remove(
	struct accept_database_control_context * _Context,
	char * pHyperSpace,
	char * pHelpBubble,
	char * pBender,
	char * pTraceWidth,
	char * pTraceColour,
	char * pDepth,
	char * pTracePadding,
	char * pxPadding,
	char * pyPadding,
	char * pFraction,
	char * pSchema)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pHyperSpace);
		if ( pHyperSpace != (char *) 0)
			*((int*)pHyperSpace) = _Context->value_HyperSpace;
		visual_transferout((void *) 0, 0, pHelpBubble);
		if ( pHelpBubble != (char *) 0)
			*((int*)pHelpBubble) = _Context->value_HelpBubble;
		visual_transferout((void *) 0, 0, pBender);
		if ( pBender != (char *) 0)
			*((int*)pBender) = _Context->value_Bender;
		visual_transferout(_Context->buffer_TraceWidth, 7, pTraceWidth);
		visual_transferout(_Context->buffer_TraceColour, 7, pTraceColour);
		visual_transferout(_Context->buffer_Depth, 7, pDepth);
		visual_transferout(_Context->buffer_TracePadding, 7, pTracePadding);
		visual_transferout(_Context->buffer_xPadding, 7, pxPadding);
		visual_transferout(_Context->buffer_yPadding, 7, pyPadding);
		visual_transferout(_Context->buffer_Fraction, 7, pFraction);
		visual_transferout((void *) 0, 0, pSchema);
		if ( pSchema != (char *) 0)
			*((int*)pSchema) = _Context->value_Schema;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_database_control_show(struct accept_database_control_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3632,_Context->y_Auto3632);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3632,_Context->y_Auto3632,280,430,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3632,_Context->y_Auto3632,280,430,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto3632+20,_Context->y_Auto3632+30,238,32,vfh[2],16,0,_Context->msg_Auto3633[_Context->language],strlen(_Context->msg_Auto3633[_Context->language]),259);
	visual_frame(_Context->x_Auto3632+20,_Context->y_Auto3632+60,240,60,4);
	visual_frame(_Context->x_Auto3632+20,_Context->y_Auto3632+120,240,230,4);
	_Context->trigger_HyperSpace=visual_trigger_code(_Context->msg_HyperSpace[_Context->language],strlen(_Context->msg_HyperSpace[_Context->language]));
	visual_check(_Context->x_Auto3632+40,_Context->y_Auto3632+70,182,16,vfh[2],16,0,_Context->msg_HyperSpace[_Context->language],strlen(_Context->msg_HyperSpace[_Context->language]),_Context->value_HyperSpace|0);
	_Context->trigger_HelpBubble=visual_trigger_code(_Context->msg_HelpBubble[_Context->language],strlen(_Context->msg_HelpBubble[_Context->language]));
	visual_check(_Context->x_Auto3632+40,_Context->y_Auto3632+90,182,16,vfh[2],16,0,_Context->msg_HelpBubble[_Context->language],strlen(_Context->msg_HelpBubble[_Context->language]),_Context->value_HelpBubble|0);
	visual_select(_Context->x_Auto3632+140,_Context->y_Auto3632+140,110,80,vfh[2],16,0,parse_selection(_Context->msg_Bender[_Context->language],&_Context->value_Bender),768);
	visual_frame(_Context->x_Auto3632+190,_Context->y_Auto3632+200,56+2,16+2,5);
	visual_text(_Context->x_Auto3632+190+1,_Context->y_Auto3632+200+1,56,16,vfh[1],16,0,_Context->buffer_TraceWidth,7,0);
	visual_frame(_Context->x_Auto3632+190,_Context->y_Auto3632+220,56+2,16+2,5);
	visual_text(_Context->x_Auto3632+190+1,_Context->y_Auto3632+220+1,56,16,vfh[1],16,0,_Context->buffer_TraceColour,7,0);
	visual_frame(_Context->x_Auto3632+190,_Context->y_Auto3632+240,56+2,16+2,5);
	visual_text(_Context->x_Auto3632+190+1,_Context->y_Auto3632+240+1,56,16,vfh[1],16,0,_Context->buffer_Depth,7,0);
	visual_frame(_Context->x_Auto3632+190,_Context->y_Auto3632+260,56+2,16+2,5);
	visual_text(_Context->x_Auto3632+190+1,_Context->y_Auto3632+260+1,56,16,vfh[1],16,0,_Context->buffer_TracePadding,7,0);
	visual_frame(_Context->x_Auto3632+190,_Context->y_Auto3632+280,56+2,16+2,5);
	visual_text(_Context->x_Auto3632+190+1,_Context->y_Auto3632+280+1,56,16,vfh[1],16,0,_Context->buffer_xPadding,7,0);
	visual_frame(_Context->x_Auto3632+190,_Context->y_Auto3632+300,56+2,16+2,5);
	visual_text(_Context->x_Auto3632+190+1,_Context->y_Auto3632+300+1,56,16,vfh[1],16,0,_Context->buffer_yPadding,7,0);
	visual_frame(_Context->x_Auto3632+190,_Context->y_Auto3632+320,56+2,16+2,5);
	visual_text(_Context->x_Auto3632+190+1,_Context->y_Auto3632+320+1,56,16,vfh[1],16,0,_Context->buffer_Fraction,7,0);
	visual_select(_Context->x_Auto3632+140,_Context->y_Auto3632+170,110,70,vfh[2],0,0,parse_selection(_Context->msg_Schema[_Context->language],&_Context->value_Schema),768);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3632+20,_Context->y_Auto3632+360,56,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3632+200,_Context->y_Auto3632+360,56,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	visual_text(_Context->x_Auto3632+30,_Context->y_Auto3632+140,112,16,vfh[2],16,0,_Context->msg_Auto3636[_Context->language],strlen(_Context->msg_Auto3636[_Context->language]),2);
	visual_text(_Context->x_Auto3632+30,_Context->y_Auto3632+170,112,16,vfh[2],16,0,_Context->msg_Auto3637[_Context->language],strlen(_Context->msg_Auto3637[_Context->language]),2);
	visual_text(_Context->x_Auto3632+30,_Context->y_Auto3632+200,154,16,vfh[2],16,0,_Context->msg_Auto3638[_Context->language],strlen(_Context->msg_Auto3638[_Context->language]),2);
	visual_text(_Context->x_Auto3632+30,_Context->y_Auto3632+220,154,16,vfh[2],16,0,_Context->msg_Auto3639[_Context->language],strlen(_Context->msg_Auto3639[_Context->language]),2);
	visual_text(_Context->x_Auto3632+30,_Context->y_Auto3632+240,154,16,vfh[2],16,0,_Context->msg_Auto3640[_Context->language],strlen(_Context->msg_Auto3640[_Context->language]),2);
	visual_text(_Context->x_Auto3632+30,_Context->y_Auto3632+260,154,16,vfh[2],16,0,_Context->msg_Auto3641[_Context->language],strlen(_Context->msg_Auto3641[_Context->language]),2);
	visual_text(_Context->x_Auto3632+30,_Context->y_Auto3632+280,154,16,vfh[2],16,0,_Context->msg_Auto3642[_Context->language],strlen(_Context->msg_Auto3642[_Context->language]),2);
	visual_text(_Context->x_Auto3632+30,_Context->y_Auto3632+300,154,16,vfh[2],16,0,_Context->msg_Auto3643[_Context->language],strlen(_Context->msg_Auto3643[_Context->language]),2);
	visual_text(_Context->x_Auto3632+30,_Context->y_Auto3632+320,154,16,vfh[2],16,0,_Context->msg_Auto3644[_Context->language],strlen(_Context->msg_Auto3644[_Context->language]),2);
	visual_thaw(_Context->x_Auto3632,_Context->y_Auto3632,280,430);

	return(0);
}

private int Auto3632action(struct accept_database_control_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_database_control_hide(_Context);

		_Context->x_Auto3632 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3632 < 0) { _Context->x_Auto3632=0; }
		_Context->y_Auto3632 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3632 < 0) { _Context->y_Auto3632=0; }
			accept_database_control_show(_Context);

		visual_thaw(_Context->x_Auto3632,_Context->y_Auto3632,280,430);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_database_control_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_database_control_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_database_control_event(
struct accept_database_control_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_HyperSpace == mb ) return(2);
		if (_Context->trigger_HelpBubble == mb ) return(3);
		if (_Context->trigger_Accept == mb ) return(13);
		if (_Context->trigger_Cancel == mb ) return(14);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3632+259) )  
	&&  (my >= (_Context->y_Auto3632+4) )  
	&&  (mx <= (_Context->x_Auto3632+276) )  
	&&  (my <= (_Context->y_Auto3632+20) )) {
		return(1);	/* Auto3632 */

		}
	if ((mx >= (_Context->x_Auto3632+243) )  
	&&  (my >= (_Context->y_Auto3632+4) )  
	&&  (mx <= (_Context->x_Auto3632+260) )  
	&&  (my <= (_Context->y_Auto3632+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vbase.htm");
			};
		return(-1);	/* Auto3632 */

		}
	if ((mx >= (_Context->x_Auto3632+227) )  
	&&  (my >= (_Context->y_Auto3632+4) )  
	&&  (mx <= (_Context->x_Auto3632+244) )  
	&&  (my <= (_Context->y_Auto3632+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_database_control_show(_Context);
		return(-1);	/* Auto3632 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3632+4) )  
		&&  (my >= (_Context->y_Auto3632+4) )  
		&&  (mx <= (_Context->x_Auto3632+212) )  
		&&  (my <= (_Context->y_Auto3632+20) )) {
			return( Auto3632action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3632+40) ) 
	&&  ( my >= (_Context->y_Auto3632+70) ) 
	&&  ( mx <= (_Context->x_Auto3632+40+182) ) 
	&&  ( my <= (_Context->y_Auto3632+70+16))) {
		return(2); /* HyperSpace */
		}
	if (( mx >= (_Context->x_Auto3632+40) ) 
	&&  ( my >= (_Context->y_Auto3632+90) ) 
	&&  ( mx <= (_Context->x_Auto3632+40+182) ) 
	&&  ( my <= (_Context->y_Auto3632+90+16))) {
		return(3); /* HelpBubble */
		}
	if (( mx >= (_Context->x_Auto3632+140+0) ) 
	&&  ( my >= (_Context->y_Auto3632+140) ) 
	&&  ( mx <= (_Context->x_Auto3632+140+110) ) 
	&&  ( my <= (_Context->y_Auto3632+140+16))) {
		return(4); /* Bender */
		}
	if (( mx >= (_Context->x_Auto3632+190) ) 
	&&  ( my >= (_Context->y_Auto3632+200) ) 
	&&  ( mx <= (_Context->x_Auto3632+190+56) ) 
	&&  ( my <= (_Context->y_Auto3632+200+16))) {
		return(5); /* TraceWidth */
		}
	if (( mx >= (_Context->x_Auto3632+190) ) 
	&&  ( my >= (_Context->y_Auto3632+220) ) 
	&&  ( mx <= (_Context->x_Auto3632+190+56) ) 
	&&  ( my <= (_Context->y_Auto3632+220+16))) {
		return(6); /* TraceColour */
		}
	if (( mx >= (_Context->x_Auto3632+190) ) 
	&&  ( my >= (_Context->y_Auto3632+240) ) 
	&&  ( mx <= (_Context->x_Auto3632+190+56) ) 
	&&  ( my <= (_Context->y_Auto3632+240+16))) {
		return(7); /* Depth */
		}
	if (( mx >= (_Context->x_Auto3632+190) ) 
	&&  ( my >= (_Context->y_Auto3632+260) ) 
	&&  ( mx <= (_Context->x_Auto3632+190+56) ) 
	&&  ( my <= (_Context->y_Auto3632+260+16))) {
		return(8); /* TracePadding */
		}
	if (( mx >= (_Context->x_Auto3632+190) ) 
	&&  ( my >= (_Context->y_Auto3632+280) ) 
	&&  ( mx <= (_Context->x_Auto3632+190+56) ) 
	&&  ( my <= (_Context->y_Auto3632+280+16))) {
		return(9); /* xPadding */
		}
	if (( mx >= (_Context->x_Auto3632+190) ) 
	&&  ( my >= (_Context->y_Auto3632+300) ) 
	&&  ( mx <= (_Context->x_Auto3632+190+56) ) 
	&&  ( my <= (_Context->y_Auto3632+300+16))) {
		return(10); /* yPadding */
		}
	if (( mx >= (_Context->x_Auto3632+190) ) 
	&&  ( my >= (_Context->y_Auto3632+320) ) 
	&&  ( mx <= (_Context->x_Auto3632+190+56) ) 
	&&  ( my <= (_Context->y_Auto3632+320+16))) {
		return(11); /* Fraction */
		}
	if (( mx >= (_Context->x_Auto3632+140+0) ) 
	&&  ( my >= (_Context->y_Auto3632+170) ) 
	&&  ( mx <= (_Context->x_Auto3632+140+110) ) 
	&&  ( my <= (_Context->y_Auto3632+170+16))) {
		return(12); /* Schema */
		}
	if (( mx >= (_Context->x_Auto3632+20) ) 
	&&  ( my >= (_Context->y_Auto3632+360) ) 
	&&  ( mx <= (_Context->x_Auto3632+20+56) ) 
	&&  ( my <= (_Context->y_Auto3632+360+48))) {
		return(13); /* Accept */
		}
	if (( mx >= (_Context->x_Auto3632+200) ) 
	&&  ( my >= (_Context->y_Auto3632+360) ) 
	&&  ( mx <= (_Context->x_Auto3632+200+56) ) 
	&&  ( my <= (_Context->y_Auto3632+360+48))) {
		return(14); /* Cancel */
		}

	return(-1);
}


public	int	accept_database_control_focus(struct accept_database_control_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* HyperSpace */
				visual_check(_Context->x_Auto3632+40,_Context->y_Auto3632+70,182,16,vfh[2],16,0,_Context->msg_HyperSpace[_Context->language],strlen(_Context->msg_HyperSpace[_Context->language]),(_Context->value_HyperSpace |2));
				_Context->keycode = visual_getch();
				_Context->trigger_HyperSpace=visual_trigger_code(_Context->msg_HyperSpace[_Context->language],strlen(_Context->msg_HyperSpace[_Context->language]));
	visual_check(_Context->x_Auto3632+40,_Context->y_Auto3632+70,182,16,vfh[2],16,0,_Context->msg_HyperSpace[_Context->language],strlen(_Context->msg_HyperSpace[_Context->language]),_Context->value_HyperSpace|0);
				break;
			case	0x3 :
				/* HelpBubble */
				visual_check(_Context->x_Auto3632+40,_Context->y_Auto3632+90,182,16,vfh[2],16,0,_Context->msg_HelpBubble[_Context->language],strlen(_Context->msg_HelpBubble[_Context->language]),(_Context->value_HelpBubble |2));
				_Context->keycode = visual_getch();
				_Context->trigger_HelpBubble=visual_trigger_code(_Context->msg_HelpBubble[_Context->language],strlen(_Context->msg_HelpBubble[_Context->language]));
	visual_check(_Context->x_Auto3632+40,_Context->y_Auto3632+90,182,16,vfh[2],16,0,_Context->msg_HelpBubble[_Context->language],strlen(_Context->msg_HelpBubble[_Context->language]),_Context->value_HelpBubble|0);
				break;
			case	0x4 :
				/* Bender */
				_Context->keycode = visual_select(_Context->x_Auto3632+140,_Context->y_Auto3632+140,110,80,vfh[2],16,0,parse_selection(_Context->msg_Bender[_Context->language],&_Context->value_Bender),770);
				break;
			case	0x5 :
				/* TraceWidth */
				_Context->keycode = visual_edit(_Context->x_Auto3632+190+1,_Context->y_Auto3632+200+1,56,16,vfh[1],_Context->buffer_TraceWidth,7);
			break;
			case	0x6 :
				/* TraceColour */
				_Context->keycode = visual_edit(_Context->x_Auto3632+190+1,_Context->y_Auto3632+220+1,56,16,vfh[1],_Context->buffer_TraceColour,7);
			break;
			case	0x7 :
				/* Depth */
				_Context->keycode = visual_edit(_Context->x_Auto3632+190+1,_Context->y_Auto3632+240+1,56,16,vfh[1],_Context->buffer_Depth,7);
			break;
			case	0x8 :
				/* TracePadding */
				_Context->keycode = visual_edit(_Context->x_Auto3632+190+1,_Context->y_Auto3632+260+1,56,16,vfh[1],_Context->buffer_TracePadding,7);
			break;
			case	0x9 :
				/* xPadding */
				_Context->keycode = visual_edit(_Context->x_Auto3632+190+1,_Context->y_Auto3632+280+1,56,16,vfh[1],_Context->buffer_xPadding,7);
			break;
			case	0xa :
				/* yPadding */
				_Context->keycode = visual_edit(_Context->x_Auto3632+190+1,_Context->y_Auto3632+300+1,56,16,vfh[1],_Context->buffer_yPadding,7);
			break;
			case	0xb :
				/* Fraction */
				_Context->keycode = visual_edit(_Context->x_Auto3632+190+1,_Context->y_Auto3632+320+1,56,16,vfh[1],_Context->buffer_Fraction,7);
			break;
			case	0xc :
				/* Schema */
				_Context->keycode = visual_select(_Context->x_Auto3632+140,_Context->y_Auto3632+170,110,70,vfh[2],0,0,parse_selection(_Context->msg_Schema[_Context->language],&_Context->value_Schema),770);
				break;
			case	0xd :
				/* Accept */
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
				visual_button(_Context->x_Auto3632+20,_Context->y_Auto3632+360,56,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3632+20,_Context->y_Auto3632+360,56,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
				break;
			case	0xe :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(_Context->x_Auto3632+200,_Context->y_Auto3632+360,56,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3632+200,_Context->y_Auto3632+360,56,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_database_control_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=14;
			accept_database_control_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_database_control_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3632 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* HyperSpace */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_HyperSpace += 1;
						_Context->value_HyperSpace &= 1;
						}
					continue;
				case	0x3 :
					/* HelpBubble */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_HelpBubble += 1;
						_Context->value_HelpBubble &= 1;
						}
					continue;
				case	0x4 :
					/* Bender */
					continue;
				case	0x5 :
					/* TraceWidth */
					continue;
				case	0x6 :
					/* TraceColour */
					continue;
				case	0x7 :
					/* Depth */
					continue;
				case	0x8 :
					/* TracePadding */
					continue;
				case	0x9 :
					/* xPadding */
					continue;
				case	0xa :
					/* yPadding */
					continue;
				case	0xb :
					/* Fraction */
					continue;
				case	0xc :
					/* Schema */
					continue;
				case	0xd :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(_Context->x_Auto3632+20,_Context->y_Auto3632+360,56,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3632+20,_Context->y_Auto3632+360,56,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0xe :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(_Context->x_Auto3632+200,_Context->y_Auto3632+360,56,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3632+200,_Context->y_Auto3632+360,56,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

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
				_Context->focus_item=14;
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

public	int	accept_database_control(
	char * pHyperSpace,
	char * pHelpBubble,
	char * pBender,
	char * pTraceWidth,
	char * pTraceColour,
	char * pDepth,
	char * pTracePadding,
	char * pxPadding,
	char * pyPadding,
	char * pFraction,
	char * pSchema)
{
	int	status=0;
	struct accept_database_control_context * _Context=(struct accept_database_control_context*) 0;
	status = accept_database_control_create(
	&_Context,
	 pHyperSpace,
	 pHelpBubble,
	 pBender,
	 pTraceWidth,
	 pTraceColour,
	 pDepth,
	 pTracePadding,
	 pxPadding,
	 pyPadding,
	 pFraction,
	 pSchema);
	if ( status != 0) return(status);
	status = accept_database_control_show(_Context);
		enter_modal();
	status = accept_database_control_focus(_Context);
		leave_modal();
	status = accept_database_control_hide(_Context);
	status = accept_database_control_remove(
	_Context,
	 pHyperSpace,
	 pHelpBubble,
	 pBender,
	 pTraceWidth,
	 pTraceColour,
	 pDepth,
	 pTracePadding,
	 pxPadding,
	 pyPadding,
	 pFraction,
	 pSchema);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vbase_c */
