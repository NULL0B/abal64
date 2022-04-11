
#ifndef _vrelate_c
#define _vrelate_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vrelate.xml                                              */
/* Target         : vrelate.c                                                */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en__Auto3631   ""
#define fr__Auto3631   ""
#define it__Auto3631   ""
#define es__Auto3631   ""
#define de__Auto3631   ""
#define nl__Auto3631   ""
#define pt__Auto3631   ""
#define xx__Auto3631   ""
#define en_Auto3632   "Database File Relations"
#define fr_Auto3632   "Relations entre fichiers de la base"
#define it_Auto3632   "Database File Relation"
#define es_Auto3632   "Database File Relation"
#define de_Auto3632   "Database File Relation"
#define nl_Auto3632   "Database File Relation"
#define pt_Auto3632   "Database File Relation"
#define xx_Auto3632   "Database File Relation"
#define en__Auto3632   ""
#define fr__Auto3632   ""
#define it__Auto3632   ""
#define es__Auto3632   ""
#define de__Auto3632   ""
#define nl__Auto3632   ""
#define pt__Auto3632   ""
#define xx__Auto3632   ""
#define en_Auto3634   "Relation Name"
#define fr_Auto3634   "Nom de la relation"
#define it_Auto3634   "Relation Name"
#define es_Auto3634   "Relation Name"
#define de_Auto3634   "Relation Name"
#define nl_Auto3634   "Relation Name"
#define pt_Auto3634   "Relation Name"
#define xx_Auto3634   "Relation Name"
#define en__Auto3634   ""
#define fr__Auto3634   ""
#define it__Auto3634   ""
#define es__Auto3634   ""
#define de__Auto3634   ""
#define nl__Auto3634   ""
#define pt__Auto3634   ""
#define xx__Auto3634   ""
#define en_Auto3635   "Jointure Name"
#define fr_Auto3635   "Nom du Jointure"
#define it_Auto3635   "Jointure Name"
#define es_Auto3635   "Jointure Name"
#define de_Auto3635   "Jointure Name"
#define nl_Auto3635   "Jointure Name"
#define pt_Auto3635   "Jointure Name"
#define xx_Auto3635   "Jointure Name"
#define en__Auto3635   ""
#define fr__Auto3635   ""
#define it__Auto3635   ""
#define es__Auto3635   ""
#define de__Auto3635   ""
#define nl__Auto3635   ""
#define pt__Auto3635   ""
#define xx__Auto3635   ""
#define en_Auto3636   "Nature"
#define fr_Auto3636   "Nature"
#define it_Auto3636   "Nature"
#define es_Auto3636   "Nature"
#define de_Auto3636   "Nature"
#define nl_Auto3636   "Nature"
#define pt_Auto3636   "Nature"
#define xx_Auto3636   "Nature"
#define en__Auto3636   ""
#define fr__Auto3636   ""
#define it__Auto3636   ""
#define es__Auto3636   ""
#define de__Auto3636   ""
#define nl__Auto3636   ""
#define pt__Auto3636   ""
#define xx__Auto3636   ""
#define en_Auto3637   "Nature"
#define fr_Auto3637   "Nature"
#define it_Auto3637   "Nature"
#define es_Auto3637   "Nature"
#define de_Auto3637   "Nature"
#define nl_Auto3637   "Nature"
#define pt_Auto3637   "Nature"
#define xx_Auto3637   "Nature"
#define en__Auto3637   ""
#define fr__Auto3637   ""
#define it__Auto3637   ""
#define es__Auto3637   ""
#define de__Auto3637   ""
#define nl__Auto3637   ""
#define pt__Auto3637   ""
#define xx__Auto3637   ""
#define en_Auto3638   "Source Class"
#define fr_Auto3638   "Classe source"
#define it_Auto3638   "Source Class"
#define es_Auto3638   "Source Class"
#define de_Auto3638   "Source Class"
#define nl_Auto3638   "Source Class"
#define pt_Auto3638   "Source Class"
#define xx_Auto3638   "Source Class"
#define en__Auto3638   ""
#define fr__Auto3638   ""
#define it__Auto3638   ""
#define es__Auto3638   ""
#define de__Auto3638   ""
#define nl__Auto3638   ""
#define pt__Auto3638   ""
#define xx__Auto3638   ""
#define en_Auto3639   "Member"
#define fr_Auto3639   "Membre"
#define it_Auto3639   "Member"
#define es_Auto3639   "Member"
#define de_Auto3639   "Member"
#define nl_Auto3639   "Member"
#define pt_Auto3639   "Member"
#define xx_Auto3639   "Member"
#define en__Auto3639   ""
#define fr__Auto3639   ""
#define it__Auto3639   ""
#define es__Auto3639   ""
#define de__Auto3639   ""
#define nl__Auto3639   ""
#define pt__Auto3639   ""
#define xx__Auto3639   ""
#define en_Auto3640   "Target Class"
#define fr_Auto3640   "Classe cible"
#define it_Auto3640   "Target Class"
#define es_Auto3640   "Target Class"
#define de_Auto3640   "Target Class"
#define nl_Auto3640   "Target Class"
#define pt_Auto3640   "Target Class"
#define xx_Auto3640   "Target Class"
#define en__Auto3640   ""
#define fr__Auto3640   ""
#define it__Auto3640   ""
#define es__Auto3640   ""
#define de__Auto3640   ""
#define nl__Auto3640   ""
#define pt__Auto3640   ""
#define xx__Auto3640   ""
#define en_Auto3641   "Member"
#define fr_Auto3641   "Membre"
#define it_Auto3641   "Member"
#define es_Auto3641   "Member"
#define de_Auto3641   "Member"
#define nl_Auto3641   "Member"
#define pt_Auto3641   "Member"
#define xx_Auto3641   "Member"
#define en__Auto3641   ""
#define fr__Auto3641   ""
#define it__Auto3641   ""
#define es__Auto3641   ""
#define de__Auto3641   ""
#define nl__Auto3641   ""
#define pt__Auto3641   ""
#define xx__Auto3641   ""
#define en_Name   ""
#define en__Name   ""
#define en_Jointure   ""
#define en__Jointure   ""
#define en_sNature   "0/1|1/1|0/N|1/N"
#define fr_sNature   "0/1|1/1|0/N|1/N"
#define it_sNature   "0/1|1/1|0/N|1/N"
#define es_sNature   "0/1|1/1|0/N|1/N"
#define de_sNature   "0/1|1/1|0/N|1/N"
#define nl_sNature   "0/1|1/1|0/N|1/N"
#define pt_sNature   "0/1|1/1|0/N|1/N"
#define xx_sNature   "0/1|1/1|0/N|1/N"
#define en__sNature   ""
#define fr__sNature   ""
#define it__sNature   ""
#define es__sNature   ""
#define de__sNature   ""
#define nl__sNature   ""
#define pt__sNature   ""
#define xx__sNature   ""
#define en_tNature   "0/1|1/1|0/N|1/N"
#define fr_tNature   "0/1|1/1|0/N|1/N"
#define it_tNature   "0/1|1/1|0/N|1/N"
#define es_tNature   "0/1|1/1|0/N|1/N"
#define de_tNature   "0/1|1/1|0/N|1/N"
#define nl_tNature   "0/1|1/1|0/N|1/N"
#define pt_tNature   "0/1|1/1|0/N|1/N"
#define xx_tNature   "0/1|1/1|0/N|1/N"
#define en__tNature   ""
#define fr__tNature   ""
#define it__tNature   ""
#define es__tNature   ""
#define de__tNature   ""
#define nl__tNature   ""
#define pt__tNature   ""
#define xx__tNature   ""
#define en_SourceClass   ""
#define en__SourceClass   ""
#define en_SourceMember   ""
#define en__SourceMember   ""
#define en_NoJoin   "Information Only ( no jointure )"
#define en__NoJoin   ""
#define en_TargetClass   ""
#define en__TargetClass   ""
#define en_TargetMember   ""
#define en__TargetMember   ""
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

private struct accept_database_relation_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3631[8];
	char * hint_Auto3631[8];
	int	x_Auto3631;
	int	y_Auto3631;
	int	w_Auto3631;
	int	h_Auto3631;
	char * msg_Auto3632[8];
	char * hint_Auto3632[8];
	char * hint_Auto3633[8];
	char * msg_Auto3634[8];
	char * hint_Auto3634[8];
	char * msg_Auto3635[8];
	char * hint_Auto3635[8];
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
	char * hint_Name[8];
	char	buffer_Name[46];
	char * hint_Jointure[8];
	char	buffer_Jointure[46];
	char * msg_sNature[8];
	char * hint_sNature[8];
	int	value_sNature;
	char * msg_tNature[8];
	char * hint_tNature[8];
	int	value_tNature;
	char * hint_SourceClass[8];
	char	buffer_SourceClass[46];
	char * hint_SourceMember[8];
	char	buffer_SourceMember[46];
	char * msg_NoJoin[8];
	int	trigger_NoJoin;
	char * hint_NoJoin[8];
	int	value_NoJoin;
	char * hint_TargetClass[8];
	char	buffer_TargetClass[46];
	char * hint_TargetMember[8];
	char	buffer_TargetMember[46];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[10];
	};
static int	vfh[16];
private int on_Name_losefocus(struct accept_database_relation_context * _Context);
private int on_Accept_event(struct accept_database_relation_context * _Context);
private int on_Cancel_event(struct accept_database_relation_context * _Context);

public	int	accept_database_relation_create(
	struct accept_database_relation_context ** cptr,
	char * pName,
	char * pJointure,
	char * psNature,
	char * ptNature,
	char * pSourceClass,
	char * pSourceMember,
	char * pNoJoin,
	char * pTargetClass,
	char * pTargetMember)
{

	int i;
	struct accept_database_relation_context * _Context=(struct accept_database_relation_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_database_relation_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=12;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWSSWSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Name, 45, pName);
		visual_transferin(_Context->buffer_Jointure, 45, pJointure);
		visual_transferin((void *) 0, 0, psNature);
		if (!( psNature )) _Context->value_sNature=0;
		else	_Context->value_sNature = *((int *)psNature);
		visual_transferin((void *) 0, 0, ptNature);
		if (!( ptNature )) _Context->value_tNature=0;
		else	_Context->value_tNature = *((int *)ptNature);
		visual_transferin(_Context->buffer_SourceClass, 45, pSourceClass);
		visual_transferin(_Context->buffer_SourceMember, 45, pSourceMember);
		visual_transferin((void *) 0, 0, pNoJoin);
		if (!( pNoJoin )) _Context->value_NoJoin=0;
		else	_Context->value_NoJoin = *((int *)pNoJoin);
		visual_transferin(_Context->buffer_TargetClass, 45, pTargetClass);
		visual_transferin(_Context->buffer_TargetMember, 45, pTargetMember);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3631[i]=" ";
	_Context->hint_Auto3631[0]=en__Auto3631;
	_Context->hint_Auto3631[1]=fr__Auto3631;
	_Context->hint_Auto3631[2]=it__Auto3631;
	_Context->hint_Auto3631[3]=es__Auto3631;
	_Context->hint_Auto3631[4]=de__Auto3631;
	_Context->hint_Auto3631[5]=nl__Auto3631;
	_Context->hint_Auto3631[6]=pt__Auto3631;
	_Context->hint_Auto3631[7]=xx__Auto3631;
	_Context->x_Auto3631=0;
	_Context->y_Auto3631=0;
	_Context->w_Auto3631=680;
	_Context->h_Auto3631=260;
	_Context->window_col=0;
	_Context->window_row=0;
	if(((_Context->y_Auto3631=visual_event(6))+260)>hardrows())
	_Context->y_Auto3631=(hardrows()-260);
	if(((_Context->x_Auto3631=visual_event(7))+680)>hardcolumns())
	_Context->x_Auto3631=(hardcolumns()-680);
	for (i=0; i < 8; i++)_Context->msg_Auto3632[i]=" ";
	_Context->msg_Auto3632[0]=en_Auto3632;
	_Context->msg_Auto3632[1]=fr_Auto3632;
	_Context->msg_Auto3632[2]=it_Auto3632;
	_Context->msg_Auto3632[3]=es_Auto3632;
	_Context->msg_Auto3632[4]=de_Auto3632;
	_Context->msg_Auto3632[5]=nl_Auto3632;
	_Context->msg_Auto3632[6]=pt_Auto3632;
	_Context->msg_Auto3632[7]=xx_Auto3632;
	_Context->hint_Auto3632[0]=en__Auto3632;
	_Context->hint_Auto3632[1]=fr__Auto3632;
	_Context->hint_Auto3632[2]=it__Auto3632;
	_Context->hint_Auto3632[3]=es__Auto3632;
	_Context->hint_Auto3632[4]=de__Auto3632;
	_Context->hint_Auto3632[5]=nl__Auto3632;
	_Context->hint_Auto3632[6]=pt__Auto3632;
	_Context->hint_Auto3632[7]=xx__Auto3632;
	for (i=0; i < 8; i++)_Context->msg_Auto3634[i]=" ";
	_Context->msg_Auto3634[0]=en_Auto3634;
	_Context->msg_Auto3634[1]=fr_Auto3634;
	_Context->msg_Auto3634[2]=it_Auto3634;
	_Context->msg_Auto3634[3]=es_Auto3634;
	_Context->msg_Auto3634[4]=de_Auto3634;
	_Context->msg_Auto3634[5]=nl_Auto3634;
	_Context->msg_Auto3634[6]=pt_Auto3634;
	_Context->msg_Auto3634[7]=xx_Auto3634;
	_Context->hint_Auto3634[0]=en__Auto3634;
	_Context->hint_Auto3634[1]=fr__Auto3634;
	_Context->hint_Auto3634[2]=it__Auto3634;
	_Context->hint_Auto3634[3]=es__Auto3634;
	_Context->hint_Auto3634[4]=de__Auto3634;
	_Context->hint_Auto3634[5]=nl__Auto3634;
	_Context->hint_Auto3634[6]=pt__Auto3634;
	_Context->hint_Auto3634[7]=xx__Auto3634;
	for (i=0; i < 8; i++)_Context->msg_Auto3635[i]=" ";
	_Context->msg_Auto3635[0]=en_Auto3635;
	_Context->msg_Auto3635[1]=fr_Auto3635;
	_Context->msg_Auto3635[2]=it_Auto3635;
	_Context->msg_Auto3635[3]=es_Auto3635;
	_Context->msg_Auto3635[4]=de_Auto3635;
	_Context->msg_Auto3635[5]=nl_Auto3635;
	_Context->msg_Auto3635[6]=pt_Auto3635;
	_Context->msg_Auto3635[7]=xx_Auto3635;
	_Context->hint_Auto3635[0]=en__Auto3635;
	_Context->hint_Auto3635[1]=fr__Auto3635;
	_Context->hint_Auto3635[2]=it__Auto3635;
	_Context->hint_Auto3635[3]=es__Auto3635;
	_Context->hint_Auto3635[4]=de__Auto3635;
	_Context->hint_Auto3635[5]=nl__Auto3635;
	_Context->hint_Auto3635[6]=pt__Auto3635;
	_Context->hint_Auto3635[7]=xx__Auto3635;
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
	_Context->msg_Auto3637[2]=it_Auto3637;
	_Context->msg_Auto3637[3]=es_Auto3637;
	_Context->msg_Auto3637[4]=de_Auto3637;
	_Context->msg_Auto3637[5]=nl_Auto3637;
	_Context->msg_Auto3637[6]=pt_Auto3637;
	_Context->msg_Auto3637[7]=xx_Auto3637;
	_Context->hint_Auto3637[0]=en__Auto3637;
	_Context->hint_Auto3637[1]=fr__Auto3637;
	_Context->hint_Auto3637[2]=it__Auto3637;
	_Context->hint_Auto3637[3]=es__Auto3637;
	_Context->hint_Auto3637[4]=de__Auto3637;
	_Context->hint_Auto3637[5]=nl__Auto3637;
	_Context->hint_Auto3637[6]=pt__Auto3637;
	_Context->hint_Auto3637[7]=xx__Auto3637;
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
	_Context->hint_Name[0]=en__Name;
	_Context->hint_Jointure[0]=en__Jointure;
	for (i=0; i < 8; i++)_Context->msg_sNature[i]=" ";
	_Context->msg_sNature[0]=en_sNature;
	_Context->msg_sNature[1]=fr_sNature;
	_Context->msg_sNature[2]=it_sNature;
	_Context->msg_sNature[3]=es_sNature;
	_Context->msg_sNature[4]=de_sNature;
	_Context->msg_sNature[5]=nl_sNature;
	_Context->msg_sNature[6]=pt_sNature;
	_Context->msg_sNature[7]=xx_sNature;
	_Context->hint_sNature[0]=en__sNature;
	_Context->hint_sNature[1]=fr__sNature;
	_Context->hint_sNature[2]=it__sNature;
	_Context->hint_sNature[3]=es__sNature;
	_Context->hint_sNature[4]=de__sNature;
	_Context->hint_sNature[5]=nl__sNature;
	_Context->hint_sNature[6]=pt__sNature;
	_Context->hint_sNature[7]=xx__sNature;
	for (i=0; i < 8; i++)_Context->msg_tNature[i]=" ";
	_Context->msg_tNature[0]=en_tNature;
	_Context->msg_tNature[1]=fr_tNature;
	_Context->msg_tNature[2]=it_tNature;
	_Context->msg_tNature[3]=es_tNature;
	_Context->msg_tNature[4]=de_tNature;
	_Context->msg_tNature[5]=nl_tNature;
	_Context->msg_tNature[6]=pt_tNature;
	_Context->msg_tNature[7]=xx_tNature;
	_Context->hint_tNature[0]=en__tNature;
	_Context->hint_tNature[1]=fr__tNature;
	_Context->hint_tNature[2]=it__tNature;
	_Context->hint_tNature[3]=es__tNature;
	_Context->hint_tNature[4]=de__tNature;
	_Context->hint_tNature[5]=nl__tNature;
	_Context->hint_tNature[6]=pt__tNature;
	_Context->hint_tNature[7]=xx__tNature;
	_Context->hint_SourceClass[0]=en__SourceClass;
	_Context->hint_SourceMember[0]=en__SourceMember;
	for (i=0; i < 8; i++)_Context->msg_NoJoin[i]=" ";
	_Context->msg_NoJoin[0]=en_NoJoin;
	_Context->hint_NoJoin[0]=en__NoJoin;
	_Context->hint_TargetClass[0]=en__TargetClass;
	_Context->hint_TargetMember[0]=en__TargetMember;
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
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3631,_Context->y_Auto3631,680+10,260+10);
	return(0);
}

public 	int	accept_database_relation_hide(struct accept_database_relation_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3631,_Context->y_Auto3631);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_database_relation_remove(
	struct accept_database_relation_context * _Context,
	char * pName,
	char * pJointure,
	char * psNature,
	char * ptNature,
	char * pSourceClass,
	char * pSourceMember,
	char * pNoJoin,
	char * pTargetClass,
	char * pTargetMember)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWSSWSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Name, 45, pName);
		visual_transferout(_Context->buffer_Jointure, 45, pJointure);
		visual_transferout((void *) 0, 0, psNature);
		if ( psNature != (char *) 0)
			*((int*)psNature) = _Context->value_sNature;
		visual_transferout((void *) 0, 0, ptNature);
		if ( ptNature != (char *) 0)
			*((int*)ptNature) = _Context->value_tNature;
		visual_transferout(_Context->buffer_SourceClass, 45, pSourceClass);
		visual_transferout(_Context->buffer_SourceMember, 45, pSourceMember);
		visual_transferout((void *) 0, 0, pNoJoin);
		if ( pNoJoin != (char *) 0)
			*((int*)pNoJoin) = _Context->value_NoJoin;
		visual_transferout(_Context->buffer_TargetClass, 45, pTargetClass);
		visual_transferout(_Context->buffer_TargetMember, 45, pTargetMember);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_database_relation_show(struct accept_database_relation_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3631,_Context->y_Auto3631);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3631,_Context->y_Auto3631,680,260,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3631,_Context->y_Auto3631,680,260,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto3631+10,_Context->y_Auto3631+30,667,20,vfh[3],16,0,_Context->msg_Auto3632[_Context->language],strlen(_Context->msg_Auto3632[_Context->language]),1283);
	visual_frame(_Context->x_Auto3631+10,_Context->y_Auto3631+50,660,190,4);
	visual_text(_Context->x_Auto3631+20,_Context->y_Auto3631+70,126,16,vfh[2],16,0,_Context->msg_Auto3634[_Context->language],strlen(_Context->msg_Auto3634[_Context->language]),257);
	visual_text(_Context->x_Auto3631+20,_Context->y_Auto3631+90,126,16,vfh[2],16,0,_Context->msg_Auto3635[_Context->language],strlen(_Context->msg_Auto3635[_Context->language]),257);
	visual_text(_Context->x_Auto3631+530,_Context->y_Auto3631+100,56,16,vfh[2],16,0,_Context->msg_Auto3636[_Context->language],strlen(_Context->msg_Auto3636[_Context->language]),257);
	visual_text(_Context->x_Auto3631+530,_Context->y_Auto3631+170,56,16,vfh[2],16,0,_Context->msg_Auto3637[_Context->language],strlen(_Context->msg_Auto3637[_Context->language]),257);
	visual_text(_Context->x_Auto3631+20,_Context->y_Auto3631+120,126,16,vfh[2],16,0,_Context->msg_Auto3638[_Context->language],strlen(_Context->msg_Auto3638[_Context->language]),257);
	visual_text(_Context->x_Auto3631+20,_Context->y_Auto3631+140,126,16,vfh[2],16,0,_Context->msg_Auto3639[_Context->language],strlen(_Context->msg_Auto3639[_Context->language]),257);
	visual_text(_Context->x_Auto3631+20,_Context->y_Auto3631+190,126,16,vfh[2],16,0,_Context->msg_Auto3640[_Context->language],strlen(_Context->msg_Auto3640[_Context->language]),257);
	visual_text(_Context->x_Auto3631+20,_Context->y_Auto3631+210,126,16,vfh[2],16,0,_Context->msg_Auto3641[_Context->language],strlen(_Context->msg_Auto3641[_Context->language]),257);
	visual_frame(_Context->x_Auto3631+160,_Context->y_Auto3631+70,360+2,16+2,5);
	visual_text(_Context->x_Auto3631+160+1,_Context->y_Auto3631+70+1,360,16,vfh[1],16,22,_Context->buffer_Name,45,0);
	visual_frame(_Context->x_Auto3631+160,_Context->y_Auto3631+90,360+2,16+2,5);
	visual_text(_Context->x_Auto3631+160+1,_Context->y_Auto3631+90+1,360,16,vfh[1],16,22,_Context->buffer_Jointure,45,0);
	visual_select(_Context->x_Auto3631+530,_Context->y_Auto3631+120,56,64,vfh[2],27,28,parse_selection(_Context->msg_sNature[_Context->language],&_Context->value_sNature),768);
	visual_select(_Context->x_Auto3631+530,_Context->y_Auto3631+190,56,64,vfh[2],27,28,parse_selection(_Context->msg_tNature[_Context->language],&_Context->value_tNature),768);
	visual_frame(_Context->x_Auto3631+160,_Context->y_Auto3631+120,360+2,16+2,5);
	visual_text(_Context->x_Auto3631+160+1,_Context->y_Auto3631+120+1,360,16,vfh[1],16,22,_Context->buffer_SourceClass,45,0);
	visual_frame(_Context->x_Auto3631+160,_Context->y_Auto3631+140,360+2,16+2,5);
	visual_text(_Context->x_Auto3631+160+1,_Context->y_Auto3631+140+1,360,16,vfh[1],16,22,_Context->buffer_SourceMember,45,0);
	_Context->trigger_NoJoin=visual_trigger_code(_Context->msg_NoJoin[_Context->language],strlen(_Context->msg_NoJoin[_Context->language]));
	visual_check(_Context->x_Auto3631+160,_Context->y_Auto3631+160,360,16,vfh[2],16,28,_Context->msg_NoJoin[_Context->language],strlen(_Context->msg_NoJoin[_Context->language]),_Context->value_NoJoin|0);
	visual_frame(_Context->x_Auto3631+160,_Context->y_Auto3631+190,360+2,16+2,5);
	visual_text(_Context->x_Auto3631+160+1,_Context->y_Auto3631+190+1,360,16,vfh[1],27,22,_Context->buffer_TargetClass,45,0);
	visual_frame(_Context->x_Auto3631+160,_Context->y_Auto3631+210,360+2,16+2,5);
	visual_text(_Context->x_Auto3631+160+1,_Context->y_Auto3631+210+1,360,16,vfh[1],16,22,_Context->buffer_TargetMember,45,0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3631+610,_Context->y_Auto3631+80,48,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3631+610,_Context->y_Auto3631+150,48,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	visual_thaw(_Context->x_Auto3631,_Context->y_Auto3631,680,260);

	return(0);
}

private int Auto3631action(struct accept_database_relation_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_database_relation_hide(_Context);

		_Context->x_Auto3631 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3631 < 0) { _Context->x_Auto3631=0; }
		_Context->y_Auto3631 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3631 < 0) { _Context->y_Auto3631=0; }
			accept_database_relation_show(_Context);

		visual_thaw(_Context->x_Auto3631,_Context->y_Auto3631,680,260);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_database_relation_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_database_relation_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_database_relation_event(
struct accept_database_relation_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_NoJoin == mb ) return(8);
		if (_Context->trigger_Accept == mb ) return(11);
		if (_Context->trigger_Cancel == mb ) return(12);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3631+659) )  
	&&  (my >= (_Context->y_Auto3631+4) )  
	&&  (mx <= (_Context->x_Auto3631+676) )  
	&&  (my <= (_Context->y_Auto3631+20) )) {
		return(1);	/* Auto3631 */

		}
	if ((mx >= (_Context->x_Auto3631+643) )  
	&&  (my >= (_Context->y_Auto3631+4) )  
	&&  (mx <= (_Context->x_Auto3631+660) )  
	&&  (my <= (_Context->y_Auto3631+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vrelate.htm");
			};
		return(-1);	/* Auto3631 */

		}
	if ((mx >= (_Context->x_Auto3631+627) )  
	&&  (my >= (_Context->y_Auto3631+4) )  
	&&  (mx <= (_Context->x_Auto3631+644) )  
	&&  (my <= (_Context->y_Auto3631+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_database_relation_show(_Context);
		return(-1);	/* Auto3631 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3631+4) )  
		&&  (my >= (_Context->y_Auto3631+4) )  
		&&  (mx <= (_Context->x_Auto3631+612) )  
		&&  (my <= (_Context->y_Auto3631+20) )) {
			return( Auto3631action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3631+160) ) 
	&&  ( my >= (_Context->y_Auto3631+70) ) 
	&&  ( mx <= (_Context->x_Auto3631+160+360) ) 
	&&  ( my <= (_Context->y_Auto3631+70+16))) {
		return(2); /* Name */
		}
	if (( mx >= (_Context->x_Auto3631+160) ) 
	&&  ( my >= (_Context->y_Auto3631+90) ) 
	&&  ( mx <= (_Context->x_Auto3631+160+360) ) 
	&&  ( my <= (_Context->y_Auto3631+90+16))) {
		return(3); /* Jointure */
		}
	if (( mx >= (_Context->x_Auto3631+530+0) ) 
	&&  ( my >= (_Context->y_Auto3631+120) ) 
	&&  ( mx <= (_Context->x_Auto3631+530+56) ) 
	&&  ( my <= (_Context->y_Auto3631+120+16))) {
		return(4); /* sNature */
		}
	if (( mx >= (_Context->x_Auto3631+530+0) ) 
	&&  ( my >= (_Context->y_Auto3631+190) ) 
	&&  ( mx <= (_Context->x_Auto3631+530+56) ) 
	&&  ( my <= (_Context->y_Auto3631+190+16))) {
		return(5); /* tNature */
		}
	if (( mx >= (_Context->x_Auto3631+160) ) 
	&&  ( my >= (_Context->y_Auto3631+120) ) 
	&&  ( mx <= (_Context->x_Auto3631+160+360) ) 
	&&  ( my <= (_Context->y_Auto3631+120+16))) {
		return(6); /* SourceClass */
		}
	if (( mx >= (_Context->x_Auto3631+160) ) 
	&&  ( my >= (_Context->y_Auto3631+140) ) 
	&&  ( mx <= (_Context->x_Auto3631+160+360) ) 
	&&  ( my <= (_Context->y_Auto3631+140+16))) {
		return(7); /* SourceMember */
		}
	if (( mx >= (_Context->x_Auto3631+160) ) 
	&&  ( my >= (_Context->y_Auto3631+160) ) 
	&&  ( mx <= (_Context->x_Auto3631+160+360) ) 
	&&  ( my <= (_Context->y_Auto3631+160+16))) {
		return(8); /* NoJoin */
		}
	if (( mx >= (_Context->x_Auto3631+160) ) 
	&&  ( my >= (_Context->y_Auto3631+190) ) 
	&&  ( mx <= (_Context->x_Auto3631+160+360) ) 
	&&  ( my <= (_Context->y_Auto3631+190+16))) {
		return(9); /* TargetClass */
		}
	if (( mx >= (_Context->x_Auto3631+160) ) 
	&&  ( my >= (_Context->y_Auto3631+210) ) 
	&&  ( mx <= (_Context->x_Auto3631+160+360) ) 
	&&  ( my <= (_Context->y_Auto3631+210+16))) {
		return(10); /* TargetMember */
		}
	if (( mx >= (_Context->x_Auto3631+610) ) 
	&&  ( my >= (_Context->y_Auto3631+80) ) 
	&&  ( mx <= (_Context->x_Auto3631+610+48) ) 
	&&  ( my <= (_Context->y_Auto3631+80+48))) {
		return(11); /* Accept */
		}
	if (( mx >= (_Context->x_Auto3631+610) ) 
	&&  ( my >= (_Context->y_Auto3631+150) ) 
	&&  ( mx <= (_Context->x_Auto3631+610+48) ) 
	&&  ( my <= (_Context->y_Auto3631+150+48))) {
		return(12); /* Cancel */
		}

	return(-1);
}
private int on_Name_losefocus(struct accept_database_relation_context * _Context) {
	visual_frame(_Context->x_Auto3631+160,_Context->y_Auto3631+70,360+2,16+2,5);
visual_text(_Context->x_Auto3631+160+1,_Context->y_Auto3631+70+1,360,16,vfh[1],16,22,_Context->buffer_Name,45,0);
;
	return(-1);
}


public	int	accept_database_relation_focus(struct accept_database_relation_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Name */
				_Context->keycode = visual_edit(_Context->x_Auto3631+160+1,_Context->y_Auto3631+70+1,360,16,vfh[1],_Context->buffer_Name,45);
				(void) on_Name_losefocus(_Context);
			break;
			case	0x3 :
				/* Jointure */
				_Context->keycode = visual_edit(_Context->x_Auto3631+160+1,_Context->y_Auto3631+90+1,360,16,vfh[1],_Context->buffer_Jointure,45);
			break;
			case	0x4 :
				/* sNature */
				_Context->keycode = visual_select(_Context->x_Auto3631+530,_Context->y_Auto3631+120,56,64,vfh[2],27,28,parse_selection(_Context->msg_sNature[_Context->language],&_Context->value_sNature),770);
				break;
			case	0x5 :
				/* tNature */
				_Context->keycode = visual_select(_Context->x_Auto3631+530,_Context->y_Auto3631+190,56,64,vfh[2],27,28,parse_selection(_Context->msg_tNature[_Context->language],&_Context->value_tNature),770);
				break;
			case	0x8 :
				/* NoJoin */
				visual_check(_Context->x_Auto3631+160,_Context->y_Auto3631+160,360,16,vfh[2],16,28,_Context->msg_NoJoin[_Context->language],strlen(_Context->msg_NoJoin[_Context->language]),(_Context->value_NoJoin |2));
				_Context->keycode = visual_getch();
				_Context->trigger_NoJoin=visual_trigger_code(_Context->msg_NoJoin[_Context->language],strlen(_Context->msg_NoJoin[_Context->language]));
	visual_check(_Context->x_Auto3631+160,_Context->y_Auto3631+160,360,16,vfh[2],16,28,_Context->msg_NoJoin[_Context->language],strlen(_Context->msg_NoJoin[_Context->language]),_Context->value_NoJoin|0);
				break;
			case	0xb :
				/* Accept */
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
				visual_button(_Context->x_Auto3631+610,_Context->y_Auto3631+80,48,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3631+610,_Context->y_Auto3631+80,48,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
				break;
			case	0xc :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(_Context->x_Auto3631+610,_Context->y_Auto3631+150,48,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3631+610,_Context->y_Auto3631+150,48,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_database_relation_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=12;
			accept_database_relation_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  _Context->x_Auto3631 )
				|| ( visual_event(6) < _Context->y_Auto3631  )
				|| ( visual_event(7) > (_Context->x_Auto3631+_Context->w_Auto3631))
				|| ( visual_event(6) >  (_Context->y_Auto3631+_Context->h_Auto3631))) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=accept_database_relation_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3631 */
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
					/* Jointure */
					continue;
				case	0x4 :
					/* sNature */
					continue;
				case	0x5 :
					/* tNature */
					continue;
				case	0x6 :
					/* SourceClass */
					continue;
				case	0x7 :
					/* SourceMember */
					continue;
				case	0x8 :
					/* NoJoin */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_NoJoin += 1;
						_Context->value_NoJoin &= 1;
						}
					continue;
				case	0x9 :
					/* TargetClass */
					continue;
				case	0xa :
					/* TargetMember */
					continue;
				case	0xb :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(_Context->x_Auto3631+610,_Context->y_Auto3631+80,48,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3631+610,_Context->y_Auto3631+80,48,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0xc :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(_Context->x_Auto3631+610,_Context->y_Auto3631+150,48,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3631+610,_Context->y_Auto3631+150,48,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
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
				_Context->focus_item=12;
			}
			continue;
		case	0x0 :
			
			continue;
		case	0xffffffff :
			
			continue;

			}
		break;
		}

	return( _Context->keycode );
}

public	int	accept_database_relation(
	char * pName,
	char * pJointure,
	char * psNature,
	char * ptNature,
	char * pSourceClass,
	char * pSourceMember,
	char * pNoJoin,
	char * pTargetClass,
	char * pTargetMember)
{
	int	status=0;
	struct accept_database_relation_context * _Context=(struct accept_database_relation_context*) 0;
	status = accept_database_relation_create(
	&_Context,
	 pName,
	 pJointure,
	 psNature,
	 ptNature,
	 pSourceClass,
	 pSourceMember,
	 pNoJoin,
	 pTargetClass,
	 pTargetMember);
	if ( status != 0) return(status);
	status = accept_database_relation_show(_Context);
		enter_modal();
	status = accept_database_relation_focus(_Context);
		leave_modal();
	status = accept_database_relation_hide(_Context);
	status = accept_database_relation_remove(
	_Context,
	 pName,
	 pJointure,
	 psNature,
	 ptNature,
	 pSourceClass,
	 pSourceMember,
	 pNoJoin,
	 pTargetClass,
	 pTargetMember);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vrelate_c */
