
#ifndef _vcompare_c
#define _vcompare_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vcompare.xml                                             */
/* Target         : vcompare.c                                               */
/* Identification : 0.0-1177511934-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "avnfile.h"
#include "singprot.h"
#define en__Auto2711   ""
#define fr__Auto2711   ""
#define it__Auto2711   ""
#define es__Auto2711   ""
#define de__Auto2711   ""
#define nl__Auto2711   ""
#define pt__Auto2711   ""
#define xx__Auto2711   ""
#define en_FileNames   "Files"
#define fr_FileNames   "Fichiers"
#define it_FileNames   "Files"
#define es_FileNames   "Files"
#define de_FileNames   "Files"
#define nl_FileNames   "Files"
#define pt_FileNames   "Files"
#define xx_FileNames   "Files"
#define en__FileNames   ""
#define fr__FileNames   ""
#define it__FileNames   ""
#define es__FileNames   ""
#define de__FileNames   ""
#define nl__FileNames   ""
#define pt__FileNames   ""
#define xx__FileNames   ""
#define en_Auto2712   "File Compare"
#define fr_Auto2712   "Comparaison de fichiers"
#define it_Auto2712   "File Compare"
#define es_Auto2712   "File Compare"
#define de_Auto2712   "File Compare"
#define nl_Auto2712   "File Compare"
#define pt_Auto2712   "File Compare"
#define xx_Auto2712   "File Compare"
#define en__Auto2712   ""
#define fr__Auto2712   ""
#define it__Auto2712   ""
#define es__Auto2712   ""
#define de__Auto2712   ""
#define nl__Auto2712   ""
#define pt__Auto2712   ""
#define xx__Auto2712   ""
#define en_Auto2714   "First Filename for compare"
#define fr_Auto2714   "Nom du premier fichier"
#define it_Auto2714   "First Filename for compare"
#define es_Auto2714   "First Filename for compare"
#define de_Auto2714   "First Filename for compare"
#define nl_Auto2714   "First Filename for compare"
#define pt_Auto2714   "First Filename for compare"
#define xx_Auto2714   "First Filename for compare"
#define en__Auto2714   ""
#define fr__Auto2714   ""
#define it__Auto2714   ""
#define es__Auto2714   ""
#define de__Auto2714   ""
#define nl__Auto2714   ""
#define pt__Auto2714   ""
#define xx__Auto2714   ""
#define en_Auto2715   "Second Filename for compare"
#define fr_Auto2715   "Nom du second fichier"
#define it_Auto2715   "Second Filename for compare"
#define es_Auto2715   "Second Filename for compare"
#define de_Auto2715   "Second Filename for compare"
#define nl_Auto2715   "Second Filename for compare"
#define pt_Auto2715   "Second Filename for compare"
#define xx_Auto2715   "Second Filename for compare"
#define en__Auto2715   ""
#define fr__Auto2715   ""
#define it__Auto2715   ""
#define es__Auto2715   ""
#define de__Auto2715   ""
#define nl__Auto2715   ""
#define pt__Auto2715   ""
#define xx__Auto2715   ""
#define en_Auto2716   "Differences"
#define fr_Auto2716   "Diff‚rences"
#define it_Auto2716   "Differences"
#define es_Auto2716   "Differences"
#define de_Auto2716   "Differences"
#define nl_Auto2716   "Differences"
#define pt_Auto2716   "Differences"
#define xx_Auto2716   "Differences"
#define en__Auto2716   ""
#define fr__Auto2716   ""
#define it__Auto2716   ""
#define es__Auto2716   ""
#define de__Auto2716   ""
#define nl__Auto2716   ""
#define pt__Auto2716   ""
#define xx__Auto2716   ""
#define en_FileOne   ""
#define en_SelectOne   "&>>>"
#define fr_SelectOne   "&S‚lection"
#define it_SelectOne   "&>>>"
#define es_SelectOne   "&>>>"
#define de_SelectOne   "&>>>"
#define nl_SelectOne   "&>>>"
#define pt_SelectOne   "&>>>"
#define xx_SelectOne   "&>>>"
#define en_SelectTwo   "&>>>"
#define fr_SelectTwo   "&S‚lection"
#define it_SelectTwo   "&>>>"
#define es_SelectTwo   "&>>>"
#define de_SelectTwo   "&>>>"
#define nl_SelectTwo   "&>>>"
#define pt_SelectTwo   "&>>>"
#define xx_SelectTwo   "&>>>"
#define en_FileTwo   ""
#define en_Invertor   "Inversion of compare information"
#define fr_Invertor   "Inverser les fichiers … comparer"
#define it_Invertor   "Inversion of compare information"
#define es_Invertor   "Inversion of compare information"
#define de_Invertor   "Inversion of compare information"
#define nl_Invertor   "Inversion of compare information"
#define pt_Invertor   "Inversion of compare information"
#define xx_Invertor   "Inversion of compare information"
#define en__Invertor   ""
#define fr__Invertor   ""
#define it__Invertor   ""
#define es__Invertor   ""
#define de__Invertor   ""
#define nl__Invertor   ""
#define pt__Invertor   ""
#define xx__Invertor   ""
#define en_Differences   ""
#define en_DoCompare   "Compare Files"
#define fr_DoCompare   "Comparer"
#define it_DoCompare   "Compare Files"
#define es_DoCompare   "Compare Files"
#define de_DoCompare   "Compare Files"
#define nl_DoCompare   "Compare Files"
#define pt_DoCompare   "Compare Files"
#define xx_DoCompare   "Compare Files"
#define en__DoCompare   ""
#define fr__DoCompare   ""
#define it__DoCompare   ""
#define es__DoCompare   ""
#define de__DoCompare   ""
#define nl__DoCompare   ""
#define pt__DoCompare   ""
#define xx__DoCompare   ""
#define en_Auto2717   "ok.gif"
#define fr_Auto2717   "ok.gif"
#define it_Auto2717   "ok.gif"
#define es_Auto2717   "ok.gif"
#define de_Auto2717   "ok.gif"
#define nl_Auto2717   "ok.gif"
#define pt_Auto2717   "ok.gif"
#define xx_Auto2717   "ok.gif"
#define en_Auto2718   "cancel.gif"
#define fr_Auto2718   "cancel.gif"
#define it_Auto2718   "cancel.gif"
#define es_Auto2718   "cancel.gif"
#define de_Auto2718   "cancel.gif"
#define nl_Auto2718   "cancel.gif"
#define pt_Auto2718   "cancel.gif"
#define xx_Auto2718   "cancel.gif"
#define en_Results   "Differences"
#define fr_Results   "Diff‚rences"
#define it_Results   "Differences"
#define es_Results   "Differences"
#define de_Results   "Differences"
#define nl_Results   "Differences"
#define pt_Results   "Differences"
#define xx_Results   "Differences"
#define en__Results   ""
#define fr__Results   ""
#define it__Results   ""
#define es__Results   ""
#define de__Results   ""
#define nl__Results   ""
#define pt__Results   ""
#define xx__Results   ""
#define en_lFile   ""
#define en_Auto2719   ""
#define en_Auto2720   ""
#define en_rFile   ""
#define en_First   "First"
#define fr_First   "P&remiŠre"
#define it_First   "First"
#define es_First   "First"
#define de_First   "First"
#define nl_First   "First"
#define pt_First   "First"
#define xx_First   "First"
#define en__First   ""
#define fr__First   ""
#define it__First   ""
#define es__First   ""
#define de__First   ""
#define nl__First   ""
#define pt__First   ""
#define xx__First   ""
#define en_Previous   "Previous"
#define fr_Previous   "&Pr‚c‚dente"
#define it_Previous   "Previous"
#define es_Previous   "Previous"
#define de_Previous   "Previous"
#define nl_Previous   "Previous"
#define pt_Previous   "Previous"
#define xx_Previous   "Previous"
#define en__Previous   ""
#define fr__Previous   ""
#define it__Previous   ""
#define es__Previous   ""
#define de__Previous   ""
#define nl__Previous   ""
#define pt__Previous   ""
#define xx__Previous   ""
#define en_Next   "Next"
#define fr_Next   "&Suivante"
#define it_Next   "Next"
#define es_Next   "Next"
#define de_Next   "Next"
#define nl_Next   "Next"
#define pt_Next   "Next"
#define xx_Next   "Next"
#define en__Next   ""
#define fr__Next   ""
#define it__Next   ""
#define es__Next   ""
#define de__Next   ""
#define nl__Next   ""
#define pt__Next   ""
#define xx__Next   ""
#define en_Last   "Last"
#define fr_Last   "&DerniŠre"
#define it_Last   "Last"
#define es_Last   "Last"
#define de_Last   "Last"
#define nl_Last   "Last"
#define pt_Last   "Last"
#define xx_Last   "Last"
#define en__Last   ""
#define fr__Last   ""
#define it__Last   ""
#define es__Last   ""
#define de__Last   ""
#define nl__Last   ""
#define pt__Last   ""
#define xx__Last   ""

private struct visual_file_compare_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[2+1];
	char * msg_Auto2711[8];
	char * hint_Auto2711[8];
	int	x_Auto2711;
	int	y_Auto2711;
	int	w_Auto2711;
	int	h_Auto2711;
	char * msg_FileNames[8];
	int	trigger_FileNames;
	char * hint_FileNames[8];
	int	page_number;
	char * msg_Auto2712[8];
	char * hint_Auto2712[8];
	char * hint_Auto2713[8];
	char * msg_Auto2714[8];
	char * hint_Auto2714[8];
	char * msg_Auto2715[8];
	char * hint_Auto2715[8];
	char * msg_Auto2716[8];
	char * hint_Auto2716[8];
	char * hint_FileOne[8];
	char	buffer_FileOne[256];
	char * msg_SelectOne[8];
	int	trigger_SelectOne;
	char * hint_SelectOne[8];
	char * msg_SelectTwo[8];
	int	trigger_SelectTwo;
	char * hint_SelectTwo[8];
	char * hint_FileTwo[8];
	char	buffer_FileTwo[256];
	char * msg_Invertor[8];
	int	trigger_Invertor;
	char * hint_Invertor[8];
	int	value_Invertor;
	char * hint_Differences[8];
	char	buffer_Differences[18];
	char * msg_DoCompare[8];
	int	trigger_DoCompare;
	char * hint_DoCompare[8];
	char * msg_Auto2717[8];
	int	trigger_Auto2717;
	char * hint_Auto2717[8];
	char * msg_Auto2718[8];
	int	trigger_Auto2718;
	char * hint_Auto2718[8];
	char * msg_Results[8];
	int	trigger_Results;
	char * hint_Results[8];
	char * hint_lFile[8];
	char	buffer_lFile[5761];
	char * hint_Auto2719[8];
	char	buffer_Auto2719[13];
	char * hint_Auto2720[8];
	char	buffer_Auto2720[13];
	char * hint_rFile[8];
	char	buffer_rFile[5761];
	char * hint_Auto2721[8];
	char * msg_First[8];
	int	trigger_First;
	char * hint_First[8];
	char * msg_Previous[8];
	int	trigger_Previous;
	char * hint_Previous[8];
	char * msg_Next[8];
	int	trigger_Next;
	char * hint_Next[8];
	char * msg_Last[8];
	int	trigger_Last;
	char * hint_Last[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};
static int	vfh[16];

public	int	visual_file_compare_create(
	struct visual_file_compare_context ** cptr,
	char * pFileOne,
	char * pFileTwo)
{

	int i;
	struct visual_file_compare_context * _Context=(struct visual_file_compare_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct visual_file_compare_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=20;
	_Context->page_number=1;
		_Context->value_Invertor=0;
		for (i=0; i < 17; i++)  *(_Context->buffer_Differences+i)=' ';
		for (i=0; i < 5760; i++)  *(_Context->buffer_lFile+i)=' ';
		for (i=0; i < 12; i++)  *(_Context->buffer_Auto2719+i)=' ';
		for (i=0; i < 12; i++)  *(_Context->buffer_Auto2720+i)=' ';
		for (i=0; i < 5760; i++)  *(_Context->buffer_rFile+i)=' ';
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileOne, 255, pFileOne);
		visual_transferin(_Context->buffer_FileTwo, 255, pFileTwo);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto2711[i]=" ";
	_Context->hint_Auto2711[0]=en__Auto2711;
	_Context->hint_Auto2711[1]=fr__Auto2711;
	_Context->hint_Auto2711[2]=it__Auto2711;
	_Context->hint_Auto2711[3]=es__Auto2711;
	_Context->hint_Auto2711[4]=de__Auto2711;
	_Context->hint_Auto2711[5]=nl__Auto2711;
	_Context->hint_Auto2711[6]=pt__Auto2711;
	_Context->hint_Auto2711[7]=xx__Auto2711;
	_Context->x_Auto2711=112;
	_Context->y_Auto2711=84;
	_Context->w_Auto2711=800;
	_Context->h_Auto2711=600;
	_Context->window_col=8;
	_Context->window_row=10;
	for (i=0; i < 8; i++)_Context->msg_FileNames[i]=" ";
	_Context->msg_FileNames[0]=en_FileNames;
	_Context->msg_FileNames[1]=fr_FileNames;
	_Context->msg_FileNames[2]=it_FileNames;
	_Context->msg_FileNames[3]=es_FileNames;
	_Context->msg_FileNames[4]=de_FileNames;
	_Context->msg_FileNames[5]=nl_FileNames;
	_Context->msg_FileNames[6]=pt_FileNames;
	_Context->msg_FileNames[7]=xx_FileNames;
	_Context->hint_FileNames[0]=en__FileNames;
	_Context->hint_FileNames[1]=fr__FileNames;
	_Context->hint_FileNames[2]=it__FileNames;
	_Context->hint_FileNames[3]=es__FileNames;
	_Context->hint_FileNames[4]=de__FileNames;
	_Context->hint_FileNames[5]=nl__FileNames;
	_Context->hint_FileNames[6]=pt__FileNames;
	_Context->hint_FileNames[7]=xx__FileNames;
	_Context->focus_pages[1]=2;
	for (i=0; i < 8; i++)_Context->msg_Auto2712[i]=" ";
	_Context->msg_Auto2712[0]=en_Auto2712;
	_Context->msg_Auto2712[1]=fr_Auto2712;
	_Context->msg_Auto2712[2]=it_Auto2712;
	_Context->msg_Auto2712[3]=es_Auto2712;
	_Context->msg_Auto2712[4]=de_Auto2712;
	_Context->msg_Auto2712[5]=nl_Auto2712;
	_Context->msg_Auto2712[6]=pt_Auto2712;
	_Context->msg_Auto2712[7]=xx_Auto2712;
	_Context->hint_Auto2712[0]=en__Auto2712;
	_Context->hint_Auto2712[1]=fr__Auto2712;
	_Context->hint_Auto2712[2]=it__Auto2712;
	_Context->hint_Auto2712[3]=es__Auto2712;
	_Context->hint_Auto2712[4]=de__Auto2712;
	_Context->hint_Auto2712[5]=nl__Auto2712;
	_Context->hint_Auto2712[6]=pt__Auto2712;
	_Context->hint_Auto2712[7]=xx__Auto2712;
	for (i=0; i < 8; i++)_Context->msg_Auto2714[i]=" ";
	_Context->msg_Auto2714[0]=en_Auto2714;
	_Context->msg_Auto2714[1]=fr_Auto2714;
	_Context->msg_Auto2714[2]=it_Auto2714;
	_Context->msg_Auto2714[3]=es_Auto2714;
	_Context->msg_Auto2714[4]=de_Auto2714;
	_Context->msg_Auto2714[5]=nl_Auto2714;
	_Context->msg_Auto2714[6]=pt_Auto2714;
	_Context->msg_Auto2714[7]=xx_Auto2714;
	_Context->hint_Auto2714[0]=en__Auto2714;
	_Context->hint_Auto2714[1]=fr__Auto2714;
	_Context->hint_Auto2714[2]=it__Auto2714;
	_Context->hint_Auto2714[3]=es__Auto2714;
	_Context->hint_Auto2714[4]=de__Auto2714;
	_Context->hint_Auto2714[5]=nl__Auto2714;
	_Context->hint_Auto2714[6]=pt__Auto2714;
	_Context->hint_Auto2714[7]=xx__Auto2714;
	for (i=0; i < 8; i++)_Context->msg_Auto2715[i]=" ";
	_Context->msg_Auto2715[0]=en_Auto2715;
	_Context->msg_Auto2715[1]=fr_Auto2715;
	_Context->msg_Auto2715[2]=it_Auto2715;
	_Context->msg_Auto2715[3]=es_Auto2715;
	_Context->msg_Auto2715[4]=de_Auto2715;
	_Context->msg_Auto2715[5]=nl_Auto2715;
	_Context->msg_Auto2715[6]=pt_Auto2715;
	_Context->msg_Auto2715[7]=xx_Auto2715;
	_Context->hint_Auto2715[0]=en__Auto2715;
	_Context->hint_Auto2715[1]=fr__Auto2715;
	_Context->hint_Auto2715[2]=it__Auto2715;
	_Context->hint_Auto2715[3]=es__Auto2715;
	_Context->hint_Auto2715[4]=de__Auto2715;
	_Context->hint_Auto2715[5]=nl__Auto2715;
	_Context->hint_Auto2715[6]=pt__Auto2715;
	_Context->hint_Auto2715[7]=xx__Auto2715;
	for (i=0; i < 8; i++)_Context->msg_Auto2716[i]=" ";
	_Context->msg_Auto2716[0]=en_Auto2716;
	_Context->msg_Auto2716[1]=fr_Auto2716;
	_Context->msg_Auto2716[2]=it_Auto2716;
	_Context->msg_Auto2716[3]=es_Auto2716;
	_Context->msg_Auto2716[4]=de_Auto2716;
	_Context->msg_Auto2716[5]=nl_Auto2716;
	_Context->msg_Auto2716[6]=pt_Auto2716;
	_Context->msg_Auto2716[7]=xx_Auto2716;
	_Context->hint_Auto2716[0]=en__Auto2716;
	_Context->hint_Auto2716[1]=fr__Auto2716;
	_Context->hint_Auto2716[2]=it__Auto2716;
	_Context->hint_Auto2716[3]=es__Auto2716;
	_Context->hint_Auto2716[4]=de__Auto2716;
	_Context->hint_Auto2716[5]=nl__Auto2716;
	_Context->hint_Auto2716[6]=pt__Auto2716;
	_Context->hint_Auto2716[7]=xx__Auto2716;
	for (i=0; i < 8; i++)_Context->msg_SelectOne[i]=" ";
	_Context->msg_SelectOne[0]=en_SelectOne;
	_Context->msg_SelectOne[1]=fr_SelectOne;
	_Context->msg_SelectOne[2]=it_SelectOne;
	_Context->msg_SelectOne[3]=es_SelectOne;
	_Context->msg_SelectOne[4]=de_SelectOne;
	_Context->msg_SelectOne[5]=nl_SelectOne;
	_Context->msg_SelectOne[6]=pt_SelectOne;
	_Context->msg_SelectOne[7]=xx_SelectOne;
	for (i=0; i < 8; i++)_Context->msg_SelectTwo[i]=" ";
	_Context->msg_SelectTwo[0]=en_SelectTwo;
	_Context->msg_SelectTwo[1]=fr_SelectTwo;
	_Context->msg_SelectTwo[2]=it_SelectTwo;
	_Context->msg_SelectTwo[3]=es_SelectTwo;
	_Context->msg_SelectTwo[4]=de_SelectTwo;
	_Context->msg_SelectTwo[5]=nl_SelectTwo;
	_Context->msg_SelectTwo[6]=pt_SelectTwo;
	_Context->msg_SelectTwo[7]=xx_SelectTwo;
	for (i=0; i < 8; i++)_Context->msg_Invertor[i]=" ";
	_Context->msg_Invertor[0]=en_Invertor;
	_Context->msg_Invertor[1]=fr_Invertor;
	_Context->msg_Invertor[2]=it_Invertor;
	_Context->msg_Invertor[3]=es_Invertor;
	_Context->msg_Invertor[4]=de_Invertor;
	_Context->msg_Invertor[5]=nl_Invertor;
	_Context->msg_Invertor[6]=pt_Invertor;
	_Context->msg_Invertor[7]=xx_Invertor;
	_Context->hint_Invertor[0]=en__Invertor;
	_Context->hint_Invertor[1]=fr__Invertor;
	_Context->hint_Invertor[2]=it__Invertor;
	_Context->hint_Invertor[3]=es__Invertor;
	_Context->hint_Invertor[4]=de__Invertor;
	_Context->hint_Invertor[5]=nl__Invertor;
	_Context->hint_Invertor[6]=pt__Invertor;
	_Context->hint_Invertor[7]=xx__Invertor;
	strcpy(_Context->buffer_Differences,"0");
	for (i=0; i < 8; i++)_Context->msg_DoCompare[i]=" ";
	_Context->msg_DoCompare[0]=en_DoCompare;
	_Context->msg_DoCompare[1]=fr_DoCompare;
	_Context->msg_DoCompare[2]=it_DoCompare;
	_Context->msg_DoCompare[3]=es_DoCompare;
	_Context->msg_DoCompare[4]=de_DoCompare;
	_Context->msg_DoCompare[5]=nl_DoCompare;
	_Context->msg_DoCompare[6]=pt_DoCompare;
	_Context->msg_DoCompare[7]=xx_DoCompare;
	_Context->hint_DoCompare[0]=en__DoCompare;
	_Context->hint_DoCompare[1]=fr__DoCompare;
	_Context->hint_DoCompare[2]=it__DoCompare;
	_Context->hint_DoCompare[3]=es__DoCompare;
	_Context->hint_DoCompare[4]=de__DoCompare;
	_Context->hint_DoCompare[5]=nl__DoCompare;
	_Context->hint_DoCompare[6]=pt__DoCompare;
	_Context->hint_DoCompare[7]=xx__DoCompare;
	for (i=0; i < 8; i++)_Context->msg_Auto2717[i]=" ";
	_Context->msg_Auto2717[0]=en_Auto2717;
	_Context->msg_Auto2717[1]=fr_Auto2717;
	_Context->msg_Auto2717[2]=it_Auto2717;
	_Context->msg_Auto2717[3]=es_Auto2717;
	_Context->msg_Auto2717[4]=de_Auto2717;
	_Context->msg_Auto2717[5]=nl_Auto2717;
	_Context->msg_Auto2717[6]=pt_Auto2717;
	_Context->msg_Auto2717[7]=xx_Auto2717;
	for (i=0; i < 8; i++)_Context->msg_Auto2718[i]=" ";
	_Context->msg_Auto2718[0]=en_Auto2718;
	_Context->msg_Auto2718[1]=fr_Auto2718;
	_Context->msg_Auto2718[2]=it_Auto2718;
	_Context->msg_Auto2718[3]=es_Auto2718;
	_Context->msg_Auto2718[4]=de_Auto2718;
	_Context->msg_Auto2718[5]=nl_Auto2718;
	_Context->msg_Auto2718[6]=pt_Auto2718;
	_Context->msg_Auto2718[7]=xx_Auto2718;
	for (i=0; i < 8; i++)_Context->msg_Results[i]=" ";
	_Context->msg_Results[0]=en_Results;
	_Context->msg_Results[1]=fr_Results;
	_Context->msg_Results[2]=it_Results;
	_Context->msg_Results[3]=es_Results;
	_Context->msg_Results[4]=de_Results;
	_Context->msg_Results[5]=nl_Results;
	_Context->msg_Results[6]=pt_Results;
	_Context->msg_Results[7]=xx_Results;
	_Context->hint_Results[0]=en__Results;
	_Context->hint_Results[1]=fr__Results;
	_Context->hint_Results[2]=it__Results;
	_Context->hint_Results[3]=es__Results;
	_Context->hint_Results[4]=de__Results;
	_Context->hint_Results[5]=nl__Results;
	_Context->hint_Results[6]=pt__Results;
	_Context->hint_Results[7]=xx__Results;
	_Context->focus_pages[2]=12;
	for (i=0; i < 8; i++)_Context->msg_First[i]=" ";
	_Context->msg_First[0]=en_First;
	_Context->msg_First[1]=fr_First;
	_Context->msg_First[2]=it_First;
	_Context->msg_First[3]=es_First;
	_Context->msg_First[4]=de_First;
	_Context->msg_First[5]=nl_First;
	_Context->msg_First[6]=pt_First;
	_Context->msg_First[7]=xx_First;
	_Context->hint_First[0]=en__First;
	_Context->hint_First[1]=fr__First;
	_Context->hint_First[2]=it__First;
	_Context->hint_First[3]=es__First;
	_Context->hint_First[4]=de__First;
	_Context->hint_First[5]=nl__First;
	_Context->hint_First[6]=pt__First;
	_Context->hint_First[7]=xx__First;
	for (i=0; i < 8; i++)_Context->msg_Previous[i]=" ";
	_Context->msg_Previous[0]=en_Previous;
	_Context->msg_Previous[1]=fr_Previous;
	_Context->msg_Previous[2]=it_Previous;
	_Context->msg_Previous[3]=es_Previous;
	_Context->msg_Previous[4]=de_Previous;
	_Context->msg_Previous[5]=nl_Previous;
	_Context->msg_Previous[6]=pt_Previous;
	_Context->msg_Previous[7]=xx_Previous;
	_Context->hint_Previous[0]=en__Previous;
	_Context->hint_Previous[1]=fr__Previous;
	_Context->hint_Previous[2]=it__Previous;
	_Context->hint_Previous[3]=es__Previous;
	_Context->hint_Previous[4]=de__Previous;
	_Context->hint_Previous[5]=nl__Previous;
	_Context->hint_Previous[6]=pt__Previous;
	_Context->hint_Previous[7]=xx__Previous;
	for (i=0; i < 8; i++)_Context->msg_Next[i]=" ";
	_Context->msg_Next[0]=en_Next;
	_Context->msg_Next[1]=fr_Next;
	_Context->msg_Next[2]=it_Next;
	_Context->msg_Next[3]=es_Next;
	_Context->msg_Next[4]=de_Next;
	_Context->msg_Next[5]=nl_Next;
	_Context->msg_Next[6]=pt_Next;
	_Context->msg_Next[7]=xx_Next;
	_Context->hint_Next[0]=en__Next;
	_Context->hint_Next[1]=fr__Next;
	_Context->hint_Next[2]=it__Next;
	_Context->hint_Next[3]=es__Next;
	_Context->hint_Next[4]=de__Next;
	_Context->hint_Next[5]=nl__Next;
	_Context->hint_Next[6]=pt__Next;
	_Context->hint_Next[7]=xx__Next;
	for (i=0; i < 8; i++)_Context->msg_Last[i]=" ";
	_Context->msg_Last[0]=en_Last;
	_Context->msg_Last[1]=fr_Last;
	_Context->msg_Last[2]=it_Last;
	_Context->msg_Last[3]=es_Last;
	_Context->msg_Last[4]=de_Last;
	_Context->msg_Last[5]=nl_Last;
	_Context->msg_Last[6]=pt_Last;
	_Context->msg_Last[7]=xx_Last;
	_Context->hint_Last[0]=en__Last;
	_Context->hint_Last[1]=fr__Last;
	_Context->hint_Last[2]=it__Last;
	_Context->hint_Last[3]=es__Last;
	_Context->hint_Last[4]=de__Last;
	_Context->hint_Last[5]=nl__Last;
	_Context->hint_Last[6]=pt__Last;
	_Context->hint_Last[7]=xx__Last;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto2711,_Context->y_Auto2711,800,600);
	return(0);
}

public 	int	visual_file_compare_hide(struct visual_file_compare_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto2711,_Context->y_Auto2711);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	visual_file_compare_remove(
	struct visual_file_compare_context * _Context,
	char * pFileOne,
	char * pFileTwo)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileOne, 255, pFileOne);
		visual_transferout(_Context->buffer_FileTwo, 255, pFileTwo);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_lFile_show(struct visual_file_compare_context * _Context) {
	struct avnor_diff*dptr;
	drop_window_editor();
	open_window_editor(_Context->x_Auto2711+14,_Context->y_Auto2711+58,384,480,_Context->buffer_FileOne);
	visual_frame(_Context->x_Auto2711+14,_Context->y_Auto2711+58,384+2,480+2,5);
visual_text(_Context->x_Auto2711+14+1,_Context->y_Auto2711+58+1,384,480,vfh[8],27,28,_Context->buffer_lFile,5760,0);
;
	dptr=select_difference(0);
	if(dptr){
	editorOnSeek(0,dptr->lline);
	if(_Context->value_Invertor==0){
	switch(dptr->type){
	case 2:/*deleted fro left*/
	editorOnHigh(dptr->lline,dptr->lines);
	break;
	case 1:/*inserted in left*/
	editorOnHigh(dptr->lline,dptr->lines);
	break;
	case 3:/*modified*/
	editorOnHigh(dptr->lline,dptr->lines);
	break;
	}
	}
	else{
	switch(dptr->type){
	case 2:/*deleted fro left*/
	editorOnHigh(dptr->lline,1);
	break;
	case 1:/*inserted in left*/
	editorOnHigh(dptr->lline,1);
	break;
	case 3:/*modified*/
	editorOnHigh(dptr->lline,dptr->lines);
	break;
	}
	}
	}
	else{
	show_window_editor();
	}
	return(-1);
}
private int on_Auto2719_show(struct visual_file_compare_context * _Context) {
	struct avnor_diff*dptr;
	if(!(dptr=select_difference(0)))
	strcpy(_Context->buffer_Auto2719,"\0");
	else sprintf(_Context->buffer_Auto2719,"%u",dptr->lline);
	visual_frame(_Context->x_Auto2711+24,_Context->y_Auto2711+554,96+2,16+2,5);
visual_text(_Context->x_Auto2711+24+1,_Context->y_Auto2711+554+1,96,16,vfh[1],0,0,_Context->buffer_Auto2719,12,0);
;
	return(-1);
}
private int on_Auto2720_show(struct visual_file_compare_context * _Context) {
	struct avnor_diff*dptr;
	if(!(dptr=select_difference(0)))
	strcpy(_Context->buffer_Auto2720,"\0");
	else sprintf(_Context->buffer_Auto2720,"%u",dptr->rline);
	visual_frame(_Context->x_Auto2711+680,_Context->y_Auto2711+556,96+2,16+2,5);
visual_text(_Context->x_Auto2711+680+1,_Context->y_Auto2711+556+1,96,16,vfh[1],0,0,_Context->buffer_Auto2720,12,0);
;
	return(-1);
}
private int on_rFile_show(struct visual_file_compare_context * _Context) {
	struct avnor_diff*dptr;
	drop_window_editor();
	open_window_editor(_Context->x_Auto2711+402,_Context->y_Auto2711+58,384,480,_Context->buffer_FileTwo);
	visual_frame(_Context->x_Auto2711+402,_Context->y_Auto2711+58,384+2,480+2,5);
visual_text(_Context->x_Auto2711+402+1,_Context->y_Auto2711+58+1,384,480,vfh[8],27,28,_Context->buffer_rFile,5760,0);
;
	dptr=select_difference(0);
	if(dptr){
	editorOnSeek(0,dptr->rline);
	if(_Context->value_Invertor==0){
	switch(dptr->type){
	case 2:/*deleted fro left*/
	editorOnHigh(dptr->lline,1);
	break;
	case 1:/*inserted in left*/
	editorOnHigh(dptr->lline,1);
	break;
	case 3:/*modified*/
	editorOnHigh(dptr->lline,dptr->lines);
	break;
	}
	}
	else{
	switch(dptr->type){
	case 2:/*deleted fro left*/
	editorOnHigh(dptr->lline,dptr->lines);
	break;
	case 1:/*inserted in left*/
	editorOnHigh(dptr->lline,dptr->lines);
	break;
	case 3:/*modified*/
	editorOnHigh(dptr->lline,dptr->lines);
	break;
	}
	}
	}
	else{
	show_window_editor();
	}
	return(-1);
}

public	int	visual_file_compare_show(struct visual_file_compare_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto2711,_Context->y_Auto2711);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto2711,_Context->y_Auto2711,800,600,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto2711,_Context->y_Auto2711,800,600,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x7);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_FileNames=visual_trigger_code(_Context->msg_FileNames[_Context->language],strlen(_Context->msg_FileNames[_Context->language]));
	visual_tabpage(_Context->x_Auto2711+10,_Context->y_Auto2711+30,784,560,vfh[2],_Context->msg_FileNames[_Context->language],strlen(_Context->msg_FileNames[_Context->language]),0,2);
	} else {
		visual_tabpage(_Context->x_Auto2711+10,_Context->y_Auto2711+30,784,560,vfh[2],_Context->msg_FileNames[_Context->language],strlen(_Context->msg_FileNames[_Context->language]),0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto2711+30,_Context->y_Auto2711+100,740,20,vfh[3],16,0,_Context->msg_Auto2712[_Context->language],strlen(_Context->msg_Auto2712[_Context->language]),1282);
	visual_frame(_Context->x_Auto2711+30,_Context->y_Auto2711+120,740,310,4);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto2711+160,_Context->y_Auto2711+350,470,50,2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto2711+40,_Context->y_Auto2711+150,270,20,vfh[2],16,0,_Context->msg_Auto2714[_Context->language],strlen(_Context->msg_Auto2714[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto2711+40,_Context->y_Auto2711+240,266,16,vfh[2],16,0,_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto2711+370,_Context->y_Auto2711+370,98,16,vfh[2],16,0,_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto2711+40,_Context->y_Auto2711+180,688+2,16+2,5);
	visual_text(_Context->x_Auto2711+40+1,_Context->y_Auto2711+180+1,688,16,vfh[1],16,0,_Context->buffer_FileOne,255,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_SelectOne=visual_trigger_code(_Context->msg_SelectOne[_Context->language],strlen(_Context->msg_SelectOne[_Context->language]));
	visual_button(_Context->x_Auto2711+732,_Context->y_Auto2711+180,20,16,vfh[8],27,24,_Context->msg_SelectOne[_Context->language],strlen(_Context->msg_SelectOne[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_SelectTwo=visual_trigger_code(_Context->msg_SelectTwo[_Context->language],strlen(_Context->msg_SelectTwo[_Context->language]));
	visual_button(_Context->x_Auto2711+732,_Context->y_Auto2711+260,20,16,vfh[8],27,24,_Context->msg_SelectTwo[_Context->language],strlen(_Context->msg_SelectTwo[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto2711+40,_Context->y_Auto2711+260,688+2,16+2,5);
	visual_text(_Context->x_Auto2711+40+1,_Context->y_Auto2711+260+1,688,16,vfh[1],16,0,_Context->buffer_FileTwo,255,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Invertor=visual_trigger_code(_Context->msg_Invertor[_Context->language],strlen(_Context->msg_Invertor[_Context->language]));
	visual_check(_Context->x_Auto2711+162,_Context->y_Auto2711+318,462,16,vfh[2],27,28,_Context->msg_Invertor[_Context->language],strlen(_Context->msg_Invertor[_Context->language]),_Context->value_Invertor|0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto2711+480,_Context->y_Auto2711+370,136+2,16+2,5);
	visual_text(_Context->x_Auto2711+480+1,_Context->y_Auto2711+370+1,136,16,vfh[1],16,0,_Context->buffer_Differences,17,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_DoCompare=visual_trigger_code(_Context->msg_DoCompare[_Context->language],strlen(_Context->msg_DoCompare[_Context->language]));
	visual_button(_Context->x_Auto2711+170,_Context->y_Auto2711+360,130,32,vfh[2],16,0,_Context->msg_DoCompare[_Context->language],strlen(_Context->msg_DoCompare[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Auto2717=visual_trigger_code(_Context->msg_Auto2717[_Context->language],strlen(_Context->msg_Auto2717[_Context->language]));
	visual_button(_Context->x_Auto2711+36,_Context->y_Auto2711+466,56,48,vfh[2],34,0,_Context->msg_Auto2717[_Context->language],strlen(_Context->msg_Auto2717[_Context->language]),1040);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Auto2718=visual_trigger_code(_Context->msg_Auto2718[_Context->language],strlen(_Context->msg_Auto2718[_Context->language]));
	visual_button(_Context->x_Auto2711+104,_Context->y_Auto2711+466,56,48,vfh[2],34,0,_Context->msg_Auto2718[_Context->language],strlen(_Context->msg_Auto2718[_Context->language]),1040);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Results=visual_trigger_code(_Context->msg_Results[_Context->language],strlen(_Context->msg_Results[_Context->language]));
	visual_tabpage(_Context->x_Auto2711+10,_Context->y_Auto2711+30,784,560,vfh[2],_Context->msg_Results[_Context->language],strlen(_Context->msg_Results[_Context->language]),76,2);
	} else {
		visual_tabpage(_Context->x_Auto2711+10,_Context->y_Auto2711+30,784,560,vfh[2],_Context->msg_Results[_Context->language],strlen(_Context->msg_Results[_Context->language]),76,0);
		}
	if (_Context->page_number == 2 ) {
	(void) on_lFile_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	(void) on_Auto2719_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	(void) on_Auto2720_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	(void) on_rFile_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto2711+136,_Context->y_Auto2711+548,532,38,2);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_First=visual_trigger_code(_Context->msg_First[_Context->language],strlen(_Context->msg_First[_Context->language]));
	visual_button(_Context->x_Auto2711+138,_Context->y_Auto2711+550,130,32,vfh[2],16,0,_Context->msg_First[_Context->language],strlen(_Context->msg_First[_Context->language]),1280);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Previous=visual_trigger_code(_Context->msg_Previous[_Context->language],strlen(_Context->msg_Previous[_Context->language]));
	visual_button(_Context->x_Auto2711+270,_Context->y_Auto2711+550,130,32,vfh[2],16,0,_Context->msg_Previous[_Context->language],strlen(_Context->msg_Previous[_Context->language]),1280);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Next=visual_trigger_code(_Context->msg_Next[_Context->language],strlen(_Context->msg_Next[_Context->language]));
	visual_button(_Context->x_Auto2711+402,_Context->y_Auto2711+550,130,32,vfh[2],16,0,_Context->msg_Next[_Context->language],strlen(_Context->msg_Next[_Context->language]),1280);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Last=visual_trigger_code(_Context->msg_Last[_Context->language],strlen(_Context->msg_Last[_Context->language]));
	visual_button(_Context->x_Auto2711+534,_Context->y_Auto2711+550,130,32,vfh[2],16,0,_Context->msg_Last[_Context->language],strlen(_Context->msg_Last[_Context->language]),1280);
		}
	visual_thaw(_Context->x_Auto2711,_Context->y_Auto2711,800,600);

	return(0);
}

private int FileNames_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This tab page allows the various file names to be determined for the ";
			mptr[1]="compare operation.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FileOne_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Specify the full path and name of the source file with which the second ";
			mptr[1]="file  is to be compared.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SelectOne_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "The Select button gives access  to the  ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SelectTwo_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "The Select button gives access  to the  ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FileTwo_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Specify the full path and name of the source file with which the first ";
			mptr[1]="file  is to be compared.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Invertor_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "If this is checked then the files will be inverted left and right ";
			mptr[1]="in the compare result window.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Differences_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field simply shows the number of differences detected during ";
			mptr[1]="the compare operation.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DoCompare_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Press this button to perform the compare operation and present the ";
			mptr[1]="results in the compare result window.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2717_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the ACCEPT button any changes made to the various    parameters ";
			mptr[1]="will take effect.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2718_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the CANCEL button any modifications performed will be ";
			mptr[1]="   discarded.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Results_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This tab page presents the results of the compare operation for inspection. ";
			mptr[1]="  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int lFile_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit frame presents the source region of the  first file involved ";
			mptr[1]="in the compare operation   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int rFile_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit frame presents the source region of the  second file involved ";
			mptr[1]="in the compare operation   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int First_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "Click on this button to position to the first difference.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Previous_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Click on this button to move back to position to the previous difference. ";
			mptr[1]="  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Next_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Click on this button to move forward and position to the next difference. ";
			mptr[1]="  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Last_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "Click on this button to position to the last difference.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2711action(struct visual_file_compare_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			visual_file_compare_hide(_Context);

		_Context->x_Auto2711 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto2711 < 0) { _Context->x_Auto2711=0; }
		_Context->y_Auto2711 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto2711 < 0) { _Context->y_Auto2711=0; }
			visual_file_compare_show(_Context);

		visual_thaw(_Context->x_Auto2711,_Context->y_Auto2711,800,600);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_SelectOne_event(struct visual_file_compare_context * _Context) {
	use_file_selector(_Context->buffer_FileOne,WIDGET_FILE_AS);
	visual_frame(_Context->x_Auto2711+40,_Context->y_Auto2711+180,688+2,16+2,5);
visual_text(_Context->x_Auto2711+40+1,_Context->y_Auto2711+180+1,688,16,vfh[1],16,0,_Context->buffer_FileOne,255,0);
;
	return(-1);
}
private int on_SelectTwo_event(struct visual_file_compare_context * _Context) {
	use_file_selector(_Context->buffer_FileTwo,WIDGET_FILE_AS);
	visual_frame(_Context->x_Auto2711+40,_Context->y_Auto2711+260,688+2,16+2,5);
visual_text(_Context->x_Auto2711+40+1,_Context->y_Auto2711+260+1,688,16,vfh[1],16,0,_Context->buffer_FileTwo,255,0);
;
	return(-1);
}
private int on_DoCompare_event(struct visual_file_compare_context * _Context) {
	int nombre;
	release_differences();
	nombre=calculate_differences(_Context->buffer_FileOne,255,_Context->buffer_FileTwo,255,0);
	sprintf(_Context->buffer_Differences,"%u",nombre);
	if(nombre!=0){
		/* Results */
	visual_file_compare_losefocus(_Context);
	_Context->page_number = 2;
	visual_file_compare_show(_Context);
	_Context->focus_item=12;
;
	}
	return(-1);
}
private int on_Auto2717_event(struct visual_file_compare_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto2718_event(struct visual_file_compare_context * _Context) {
	return(27);
	return(-1);
}
private int on_First_event(struct visual_file_compare_context * _Context) {
	select_difference(12);
		visual_file_compare_show(_Context);
;
	return(-1);
}
private int on_Previous_event(struct visual_file_compare_context * _Context) {
	select_difference(11);
		visual_file_compare_show(_Context);
;
	return(-1);
}
private int on_Next_event(struct visual_file_compare_context * _Context) {
	select_difference(5);
		visual_file_compare_show(_Context);
;
	return(-1);
}
private int on_Last_event(struct visual_file_compare_context * _Context) {
	select_difference(2);
		visual_file_compare_show(_Context);
;
	return(-1);
}


public	int	visual_file_compare_event(
struct visual_file_compare_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_FileNames == mb ) return(2);
		if (_Context->trigger_SelectOne == mb ) return(4);
		if (_Context->trigger_SelectTwo == mb ) return(5);
		if (_Context->trigger_Invertor == mb ) return(7);
		if (_Context->trigger_DoCompare == mb ) return(9);
		if (_Context->trigger_Auto2717 == mb ) return(10);
		if (_Context->trigger_Auto2718 == mb ) return(11);
		if (_Context->trigger_Results == mb ) return(12);
		if (_Context->trigger_First == mb ) return(17);
		if (_Context->trigger_Previous == mb ) return(18);
		if (_Context->trigger_Next == mb ) return(19);
		if (_Context->trigger_Last == mb ) return(20);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto2711+779) )  
	&&  (my >= (_Context->y_Auto2711+4) )  
	&&  (mx <= (_Context->x_Auto2711+796) )  
	&&  (my <= (_Context->y_Auto2711+20) )) {
		return(1);	/* Auto2711 */

		}
	if ((mx >= (_Context->x_Auto2711+763) )  
	&&  (my >= (_Context->y_Auto2711+4) )  
	&&  (mx <= (_Context->x_Auto2711+780) )  
	&&  (my <= (_Context->y_Auto2711+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vcompare.htm");
			};
		return(-1);	/* Auto2711 */

		}
	if ((mx >= (_Context->x_Auto2711+747) )  
	&&  (my >= (_Context->y_Auto2711+4) )  
	&&  (mx <= (_Context->x_Auto2711+764) )  
	&&  (my <= (_Context->y_Auto2711+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		visual_file_compare_show(_Context);
		return(-1);	/* Auto2711 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto2711+4) )  
		&&  (my >= (_Context->y_Auto2711+4) )  
		&&  (mx <= (_Context->x_Auto2711+732) )  
		&&  (my <= (_Context->y_Auto2711+20) )) {
			return( Auto2711action(_Context) );
			}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if (( mx >= (_Context->x_Auto2711+10+0) ) 
		&&  ( my >= (_Context->y_Auto2711+30) ) 
		&&  ( mx <= (_Context->x_Auto2711+10+75) ) 
		&&  ( my <= (_Context->y_Auto2711+30+24))) {
			return(2); /* FileNames */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto2711+40) ) 
		&&  ( my >= (_Context->y_Auto2711+180) ) 
		&&  ( mx <= (_Context->x_Auto2711+40+688) ) 
		&&  ( my <= (_Context->y_Auto2711+180+16))) {
			return(3); /* FileOne */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto2711+732) ) 
		&&  ( my >= (_Context->y_Auto2711+180) ) 
		&&  ( mx <= (_Context->x_Auto2711+732+20) ) 
		&&  ( my <= (_Context->y_Auto2711+180+16))) {
			return(4); /* SelectOne */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto2711+732) ) 
		&&  ( my >= (_Context->y_Auto2711+260) ) 
		&&  ( mx <= (_Context->x_Auto2711+732+20) ) 
		&&  ( my <= (_Context->y_Auto2711+260+16))) {
			return(5); /* SelectTwo */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto2711+40) ) 
		&&  ( my >= (_Context->y_Auto2711+260) ) 
		&&  ( mx <= (_Context->x_Auto2711+40+688) ) 
		&&  ( my <= (_Context->y_Auto2711+260+16))) {
			return(6); /* FileTwo */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto2711+162) ) 
		&&  ( my >= (_Context->y_Auto2711+318) ) 
		&&  ( mx <= (_Context->x_Auto2711+162+462) ) 
		&&  ( my <= (_Context->y_Auto2711+318+16))) {
			return(7); /* Invertor */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto2711+480) ) 
		&&  ( my >= (_Context->y_Auto2711+370) ) 
		&&  ( mx <= (_Context->x_Auto2711+480+136) ) 
		&&  ( my <= (_Context->y_Auto2711+370+16))) {
			return(8); /* Differences */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto2711+170) ) 
		&&  ( my >= (_Context->y_Auto2711+360) ) 
		&&  ( mx <= (_Context->x_Auto2711+170+130) ) 
		&&  ( my <= (_Context->y_Auto2711+360+32))) {
			return(9); /* DoCompare */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto2711+36) ) 
		&&  ( my >= (_Context->y_Auto2711+466) ) 
		&&  ( mx <= (_Context->x_Auto2711+36+56) ) 
		&&  ( my <= (_Context->y_Auto2711+466+48))) {
			return(10); /* Auto2717 */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto2711+104) ) 
		&&  ( my >= (_Context->y_Auto2711+466) ) 
		&&  ( mx <= (_Context->x_Auto2711+104+56) ) 
		&&  ( my <= (_Context->y_Auto2711+466+48))) {
			return(11); /* Auto2718 */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_Auto2711+10+76) ) 
		&&  ( my >= (_Context->y_Auto2711+30) ) 
		&&  ( mx <= (_Context->x_Auto2711+10+175) ) 
		&&  ( my <= (_Context->y_Auto2711+30+24))) {
			return(12); /* Results */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto2711+14) ) 
		&&  ( my >= (_Context->y_Auto2711+58) ) 
		&&  ( mx <= (_Context->x_Auto2711+14+384) ) 
		&&  ( my <= (_Context->y_Auto2711+58+480))) {
			return(13); /* lFile */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto2711+24) ) 
		&&  ( my >= (_Context->y_Auto2711+554) ) 
		&&  ( mx <= (_Context->x_Auto2711+24+96) ) 
		&&  ( my <= (_Context->y_Auto2711+554+16))) {
			return(14); /* Auto2719 */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto2711+680) ) 
		&&  ( my >= (_Context->y_Auto2711+556) ) 
		&&  ( mx <= (_Context->x_Auto2711+680+96) ) 
		&&  ( my <= (_Context->y_Auto2711+556+16))) {
			return(15); /* Auto2720 */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto2711+402) ) 
		&&  ( my >= (_Context->y_Auto2711+58) ) 
		&&  ( mx <= (_Context->x_Auto2711+402+384) ) 
		&&  ( my <= (_Context->y_Auto2711+58+480))) {
			return(16); /* rFile */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto2711+138) ) 
		&&  ( my >= (_Context->y_Auto2711+550) ) 
		&&  ( mx <= (_Context->x_Auto2711+138+130) ) 
		&&  ( my <= (_Context->y_Auto2711+550+32))) {
			return(17); /* First */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto2711+270) ) 
		&&  ( my >= (_Context->y_Auto2711+550) ) 
		&&  ( mx <= (_Context->x_Auto2711+270+130) ) 
		&&  ( my <= (_Context->y_Auto2711+550+32))) {
			return(18); /* Previous */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto2711+402) ) 
		&&  ( my >= (_Context->y_Auto2711+550) ) 
		&&  ( mx <= (_Context->x_Auto2711+402+130) ) 
		&&  ( my <= (_Context->y_Auto2711+550+32))) {
			return(19); /* Next */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto2711+534) ) 
		&&  ( my >= (_Context->y_Auto2711+550) ) 
		&&  ( mx <= (_Context->x_Auto2711+534+130) ) 
		&&  ( my <= (_Context->y_Auto2711+550+32))) {
			return(20); /* Last */
			}
		}

	return(-1);
}


public	int	visual_file_compare_losefocus(struct visual_file_compare_context * _Context)
{
	switch (_Context->page_number) {
		case 1 : 
			break;
		case 2 : 
			break;

		}
	return(0);

}
private int on_lFile_getfocus(struct visual_file_compare_context * _Context) {
	on_lFile_show(_Context);
	return(focus_window_editor());
	return(-1);
}
private int on_rFile_getfocus(struct visual_file_compare_context * _Context) {
	on_rFile_show(_Context);
	return(focus_window_editor());
	return(-1);
}


public	int	visual_file_compare_focus(struct visual_file_compare_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FileNames */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x3 :
				/* FileOne */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto2711+40+1,_Context->y_Auto2711+180+1,688,16,vfh[1],_Context->buffer_FileOne,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4 :
				/* SelectOne */
				if (_Context->page_number == 1 ) {
					_Context->trigger_SelectOne=visual_trigger_code(_Context->msg_SelectOne[_Context->language],strlen(_Context->msg_SelectOne[_Context->language]));
					visual_button(_Context->x_Auto2711+732,_Context->y_Auto2711+180,20,16,vfh[8],27,24,_Context->msg_SelectOne[_Context->language],strlen(_Context->msg_SelectOne[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_SelectOne=visual_trigger_code(_Context->msg_SelectOne[_Context->language],strlen(_Context->msg_SelectOne[_Context->language]));
	visual_button(_Context->x_Auto2711+732,_Context->y_Auto2711+180,20,16,vfh[8],27,24,_Context->msg_SelectOne[_Context->language],strlen(_Context->msg_SelectOne[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x5 :
				/* SelectTwo */
				if (_Context->page_number == 1 ) {
					_Context->trigger_SelectTwo=visual_trigger_code(_Context->msg_SelectTwo[_Context->language],strlen(_Context->msg_SelectTwo[_Context->language]));
					visual_button(_Context->x_Auto2711+732,_Context->y_Auto2711+260,20,16,vfh[8],27,24,_Context->msg_SelectTwo[_Context->language],strlen(_Context->msg_SelectTwo[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_SelectTwo=visual_trigger_code(_Context->msg_SelectTwo[_Context->language],strlen(_Context->msg_SelectTwo[_Context->language]));
	visual_button(_Context->x_Auto2711+732,_Context->y_Auto2711+260,20,16,vfh[8],27,24,_Context->msg_SelectTwo[_Context->language],strlen(_Context->msg_SelectTwo[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* FileTwo */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto2711+40+1,_Context->y_Auto2711+260+1,688,16,vfh[1],_Context->buffer_FileTwo,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* Invertor */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto2711+162,_Context->y_Auto2711+318,462,16,vfh[2],27,28,_Context->msg_Invertor[_Context->language],strlen(_Context->msg_Invertor[_Context->language]),(_Context->value_Invertor |2));
					_Context->keycode = visual_getch();
					_Context->trigger_Invertor=visual_trigger_code(_Context->msg_Invertor[_Context->language],strlen(_Context->msg_Invertor[_Context->language]));
	visual_check(_Context->x_Auto2711+162,_Context->y_Auto2711+318,462,16,vfh[2],27,28,_Context->msg_Invertor[_Context->language],strlen(_Context->msg_Invertor[_Context->language]),_Context->value_Invertor|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* Differences */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto2711+480+1,_Context->y_Auto2711+370+1,136,16,vfh[1],_Context->buffer_Differences,17);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* DoCompare */
				if (_Context->page_number == 1 ) {
					_Context->trigger_DoCompare=visual_trigger_code(_Context->msg_DoCompare[_Context->language],strlen(_Context->msg_DoCompare[_Context->language]));
					visual_button(_Context->x_Auto2711+170,_Context->y_Auto2711+360,130,32,vfh[2],16,0,_Context->msg_DoCompare[_Context->language],strlen(_Context->msg_DoCompare[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_DoCompare=visual_trigger_code(_Context->msg_DoCompare[_Context->language],strlen(_Context->msg_DoCompare[_Context->language]));
	visual_button(_Context->x_Auto2711+170,_Context->y_Auto2711+360,130,32,vfh[2],16,0,_Context->msg_DoCompare[_Context->language],strlen(_Context->msg_DoCompare[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* Auto2717 */
				if (_Context->page_number == 1 ) {
					_Context->trigger_Auto2717=visual_trigger_code(_Context->msg_Auto2717[_Context->language],strlen(_Context->msg_Auto2717[_Context->language]));
					visual_button(_Context->x_Auto2711+36,_Context->y_Auto2711+466,56,48,vfh[2],34,0,_Context->msg_Auto2717[_Context->language],strlen(_Context->msg_Auto2717[_Context->language]),1042);
					_Context->keycode = visual_getch();
					_Context->trigger_Auto2717=visual_trigger_code(_Context->msg_Auto2717[_Context->language],strlen(_Context->msg_Auto2717[_Context->language]));
	visual_button(_Context->x_Auto2711+36,_Context->y_Auto2711+466,56,48,vfh[2],34,0,_Context->msg_Auto2717[_Context->language],strlen(_Context->msg_Auto2717[_Context->language]),1040);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* Auto2718 */
				if (_Context->page_number == 1 ) {
					_Context->trigger_Auto2718=visual_trigger_code(_Context->msg_Auto2718[_Context->language],strlen(_Context->msg_Auto2718[_Context->language]));
					visual_button(_Context->x_Auto2711+104,_Context->y_Auto2711+466,56,48,vfh[2],34,0,_Context->msg_Auto2718[_Context->language],strlen(_Context->msg_Auto2718[_Context->language]),1042);
					_Context->keycode = visual_getch();
					_Context->trigger_Auto2718=visual_trigger_code(_Context->msg_Auto2718[_Context->language],strlen(_Context->msg_Auto2718[_Context->language]));
	visual_button(_Context->x_Auto2711+104,_Context->y_Auto2711+466,56,48,vfh[2],34,0,_Context->msg_Auto2718[_Context->language],strlen(_Context->msg_Auto2718[_Context->language]),1040);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* Results */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xd :
				/* lFile */
				if (_Context->page_number == 2 ) {
					if ((_Context->keycode = on_lFile_getfocus(_Context)) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* rFile */
				if (_Context->page_number == 2 ) {
					if ((_Context->keycode = on_rFile_getfocus(_Context)) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* First */
				if (_Context->page_number == 2 ) {
					_Context->trigger_First=visual_trigger_code(_Context->msg_First[_Context->language],strlen(_Context->msg_First[_Context->language]));
					visual_button(_Context->x_Auto2711+138,_Context->y_Auto2711+550,130,32,vfh[2],16,0,_Context->msg_First[_Context->language],strlen(_Context->msg_First[_Context->language]),1282);
					_Context->keycode = visual_getch();
					_Context->trigger_First=visual_trigger_code(_Context->msg_First[_Context->language],strlen(_Context->msg_First[_Context->language]));
	visual_button(_Context->x_Auto2711+138,_Context->y_Auto2711+550,130,32,vfh[2],16,0,_Context->msg_First[_Context->language],strlen(_Context->msg_First[_Context->language]),1280);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x12 :
				/* Previous */
				if (_Context->page_number == 2 ) {
					_Context->trigger_Previous=visual_trigger_code(_Context->msg_Previous[_Context->language],strlen(_Context->msg_Previous[_Context->language]));
					visual_button(_Context->x_Auto2711+270,_Context->y_Auto2711+550,130,32,vfh[2],16,0,_Context->msg_Previous[_Context->language],strlen(_Context->msg_Previous[_Context->language]),1282);
					_Context->keycode = visual_getch();
					_Context->trigger_Previous=visual_trigger_code(_Context->msg_Previous[_Context->language],strlen(_Context->msg_Previous[_Context->language]));
	visual_button(_Context->x_Auto2711+270,_Context->y_Auto2711+550,130,32,vfh[2],16,0,_Context->msg_Previous[_Context->language],strlen(_Context->msg_Previous[_Context->language]),1280);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x13 :
				/* Next */
				if (_Context->page_number == 2 ) {
					_Context->trigger_Next=visual_trigger_code(_Context->msg_Next[_Context->language],strlen(_Context->msg_Next[_Context->language]));
					visual_button(_Context->x_Auto2711+402,_Context->y_Auto2711+550,130,32,vfh[2],16,0,_Context->msg_Next[_Context->language],strlen(_Context->msg_Next[_Context->language]),1282);
					_Context->keycode = visual_getch();
					_Context->trigger_Next=visual_trigger_code(_Context->msg_Next[_Context->language],strlen(_Context->msg_Next[_Context->language]));
	visual_button(_Context->x_Auto2711+402,_Context->y_Auto2711+550,130,32,vfh[2],16,0,_Context->msg_Next[_Context->language],strlen(_Context->msg_Next[_Context->language]),1280);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* Last */
				if (_Context->page_number == 2 ) {
					_Context->trigger_Last=visual_trigger_code(_Context->msg_Last[_Context->language],strlen(_Context->msg_Last[_Context->language]));
					visual_button(_Context->x_Auto2711+534,_Context->y_Auto2711+550,130,32,vfh[2],16,0,_Context->msg_Last[_Context->language],strlen(_Context->msg_Last[_Context->language]),1282);
					_Context->keycode = visual_getch();
					_Context->trigger_Last=visual_trigger_code(_Context->msg_Last[_Context->language],strlen(_Context->msg_Last[_Context->language]));
	visual_button(_Context->x_Auto2711+534,_Context->y_Auto2711+550,130,32,vfh[2],16,0,_Context->msg_Last[_Context->language],strlen(_Context->msg_Last[_Context->language]),1280);
				} else {
				_Context->keycode = 5;
					}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			visual_file_compare_losefocus(_Context);
			_Context->page_number=1;
			_Context->focus_item=1;
			visual_file_compare_show(_Context);
			continue;
		case	0x2 :
			visual_file_compare_losefocus(_Context);
			_Context->page_number=2;
			_Context->focus_item=20;
			visual_file_compare_show(_Context);
			continue;
		case	0x3 :
			visual_file_compare_losefocus(_Context);
			if ( _Context->page_number < 2 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			visual_file_compare_show(_Context);
			continue;
		case	0x12 :
			visual_file_compare_losefocus(_Context);
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			visual_file_compare_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=visual_file_compare_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (FileNames_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (FileOne_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (SelectOne_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (SelectTwo_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (FileTwo_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (Invertor_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (Differences_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (DoCompare_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (Auto2717_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (Auto2718_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (Results_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (lFile_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (rFile_help(_Context) != 0) { continue; }
						else { break; }
					case	0x11 :
						if (First_help(_Context) != 0) { continue; }
						else { break; }
					case	0x12 :
						if (Previous_help(_Context) != 0) { continue; }
						else { break; }
					case	0x13 :
						if (Next_help(_Context) != 0) { continue; }
						else { break; }
					case	0x14 :
						if (Last_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto2711 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* FileNames */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_file_compare_losefocus(_Context);
						_Context->page_number = 1;
						visual_file_compare_show(_Context);
						}
					continue;
				case	0x3 :
					/* FileOne */
					continue;
				case	0x4 :
					/* SelectOne */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_SelectOne=visual_trigger_code(_Context->msg_SelectOne[_Context->language],strlen(_Context->msg_SelectOne[_Context->language]));
						visual_button(_Context->x_Auto2711+732,_Context->y_Auto2711+180,20,16,vfh[8],27,24,_Context->msg_SelectOne[_Context->language],strlen(_Context->msg_SelectOne[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_SelectOne=visual_trigger_code(_Context->msg_SelectOne[_Context->language],strlen(_Context->msg_SelectOne[_Context->language]));
	visual_button(_Context->x_Auto2711+732,_Context->y_Auto2711+180,20,16,vfh[8],27,24,_Context->msg_SelectOne[_Context->language],strlen(_Context->msg_SelectOne[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_SelectOne_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* SelectTwo */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_SelectTwo=visual_trigger_code(_Context->msg_SelectTwo[_Context->language],strlen(_Context->msg_SelectTwo[_Context->language]));
						visual_button(_Context->x_Auto2711+732,_Context->y_Auto2711+260,20,16,vfh[8],27,24,_Context->msg_SelectTwo[_Context->language],strlen(_Context->msg_SelectTwo[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_SelectTwo=visual_trigger_code(_Context->msg_SelectTwo[_Context->language],strlen(_Context->msg_SelectTwo[_Context->language]));
	visual_button(_Context->x_Auto2711+732,_Context->y_Auto2711+260,20,16,vfh[8],27,24,_Context->msg_SelectTwo[_Context->language],strlen(_Context->msg_SelectTwo[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_SelectTwo_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* FileTwo */
					continue;
				case	0x7 :
					/* Invertor */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Invertor += 1;
						_Context->value_Invertor &= 1;
						}
					continue;
				case	0x8 :
					/* Differences */
					continue;
				case	0x9 :
					/* DoCompare */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_DoCompare=visual_trigger_code(_Context->msg_DoCompare[_Context->language],strlen(_Context->msg_DoCompare[_Context->language]));
						visual_button(_Context->x_Auto2711+170,_Context->y_Auto2711+360,130,32,vfh[2],16,0,_Context->msg_DoCompare[_Context->language],strlen(_Context->msg_DoCompare[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_DoCompare=visual_trigger_code(_Context->msg_DoCompare[_Context->language],strlen(_Context->msg_DoCompare[_Context->language]));
	visual_button(_Context->x_Auto2711+170,_Context->y_Auto2711+360,130,32,vfh[2],16,0,_Context->msg_DoCompare[_Context->language],strlen(_Context->msg_DoCompare[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_DoCompare_event(_Context)) != -1) break;

						}
					continue;
				case	0xa :
					/* Auto2717 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2717=visual_trigger_code(_Context->msg_Auto2717[_Context->language],strlen(_Context->msg_Auto2717[_Context->language]));
						visual_button(_Context->x_Auto2711+36,_Context->y_Auto2711+466,56,48,vfh[2],34,0,_Context->msg_Auto2717[_Context->language],strlen(_Context->msg_Auto2717[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2717=visual_trigger_code(_Context->msg_Auto2717[_Context->language],strlen(_Context->msg_Auto2717[_Context->language]));
	visual_button(_Context->x_Auto2711+36,_Context->y_Auto2711+466,56,48,vfh[2],34,0,_Context->msg_Auto2717[_Context->language],strlen(_Context->msg_Auto2717[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2717_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* Auto2718 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2718=visual_trigger_code(_Context->msg_Auto2718[_Context->language],strlen(_Context->msg_Auto2718[_Context->language]));
						visual_button(_Context->x_Auto2711+104,_Context->y_Auto2711+466,56,48,vfh[2],34,0,_Context->msg_Auto2718[_Context->language],strlen(_Context->msg_Auto2718[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2718=visual_trigger_code(_Context->msg_Auto2718[_Context->language],strlen(_Context->msg_Auto2718[_Context->language]));
	visual_button(_Context->x_Auto2711+104,_Context->y_Auto2711+466,56,48,vfh[2],34,0,_Context->msg_Auto2718[_Context->language],strlen(_Context->msg_Auto2718[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2718_event(_Context)) != -1) break;

						}
					continue;
				case	0xd :
					/* lFile */
					continue;
				case	0xe :
					/* Auto2719 */
					continue;
				case	0xf :
					/* Auto2720 */
					continue;
				case	0x10 :
					/* rFile */
					continue;
				case	0x11 :
					/* First */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_First=visual_trigger_code(_Context->msg_First[_Context->language],strlen(_Context->msg_First[_Context->language]));
						visual_button(_Context->x_Auto2711+138,_Context->y_Auto2711+550,130,32,vfh[2],16,0,_Context->msg_First[_Context->language],strlen(_Context->msg_First[_Context->language]),1282);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_First=visual_trigger_code(_Context->msg_First[_Context->language],strlen(_Context->msg_First[_Context->language]));
	visual_button(_Context->x_Auto2711+138,_Context->y_Auto2711+550,130,32,vfh[2],16,0,_Context->msg_First[_Context->language],strlen(_Context->msg_First[_Context->language]),1280);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_First_event(_Context)) != -1) break;

						}
					continue;
				case	0x12 :
					/* Previous */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Previous=visual_trigger_code(_Context->msg_Previous[_Context->language],strlen(_Context->msg_Previous[_Context->language]));
						visual_button(_Context->x_Auto2711+270,_Context->y_Auto2711+550,130,32,vfh[2],16,0,_Context->msg_Previous[_Context->language],strlen(_Context->msg_Previous[_Context->language]),1282);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Previous=visual_trigger_code(_Context->msg_Previous[_Context->language],strlen(_Context->msg_Previous[_Context->language]));
	visual_button(_Context->x_Auto2711+270,_Context->y_Auto2711+550,130,32,vfh[2],16,0,_Context->msg_Previous[_Context->language],strlen(_Context->msg_Previous[_Context->language]),1280);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Previous_event(_Context)) != -1) break;

						}
					continue;
				case	0x13 :
					/* Next */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Next=visual_trigger_code(_Context->msg_Next[_Context->language],strlen(_Context->msg_Next[_Context->language]));
						visual_button(_Context->x_Auto2711+402,_Context->y_Auto2711+550,130,32,vfh[2],16,0,_Context->msg_Next[_Context->language],strlen(_Context->msg_Next[_Context->language]),1282);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Next=visual_trigger_code(_Context->msg_Next[_Context->language],strlen(_Context->msg_Next[_Context->language]));
	visual_button(_Context->x_Auto2711+402,_Context->y_Auto2711+550,130,32,vfh[2],16,0,_Context->msg_Next[_Context->language],strlen(_Context->msg_Next[_Context->language]),1280);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Next_event(_Context)) != -1) break;

						}
					continue;
				case	0x14 :
					/* Last */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Last=visual_trigger_code(_Context->msg_Last[_Context->language],strlen(_Context->msg_Last[_Context->language]));
						visual_button(_Context->x_Auto2711+534,_Context->y_Auto2711+550,130,32,vfh[2],16,0,_Context->msg_Last[_Context->language],strlen(_Context->msg_Last[_Context->language]),1282);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Last=visual_trigger_code(_Context->msg_Last[_Context->language],strlen(_Context->msg_Last[_Context->language]));
	visual_button(_Context->x_Auto2711+534,_Context->y_Auto2711+550,130,32,vfh[2],16,0,_Context->msg_Last[_Context->language],strlen(_Context->msg_Last[_Context->language]),1280);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Last_event(_Context)) != -1) break;

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
				_Context->focus_item=20;
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

public	int	visual_file_compare(
	char * pFileOne,
	char * pFileTwo)
{
	int	status=0;
	struct visual_file_compare_context * _Context=(struct visual_file_compare_context*) 0;
	status = visual_file_compare_create(
	&_Context,
	 pFileOne,
	 pFileTwo);
	if ( status != 0) return(status);
	status = visual_file_compare_show(_Context);
		enter_modal();
	status = visual_file_compare_focus(_Context);
		leave_modal();
	status = visual_file_compare_hide(_Context);
	status = visual_file_compare_remove(
	_Context,
	 pFileOne,
	 pFileTwo);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcompare_c */
