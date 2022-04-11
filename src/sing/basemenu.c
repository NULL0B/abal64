
#ifndef _basemenu_c
#define _basemenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.37                                                */
/* Production     : C                                                        */
/* Project        : basemenu.xml                                             */
/* Target         : basemenu.c                                               */
/* Identification : 0.0-1200312619-3114.3113                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#include "singdbed.h"
#define en_Auto339   "Sing Version 2.1a"
#define fr_Auto339   "Sing Version 2.1a"
#define it_Auto339   "Sing Version 2.1a"
#define es_Auto339   "Sing Version 2.1a"
#define de_Auto339   "Sing Version 2.1a"
#define nl_Auto339   "Sing Version 2.1a"
#define pt_Auto339   "Sing Version 2.1a"
#define xx_Auto339   "Sing Version 2.1a"
#define en__Auto339   ""
#define fr__Auto339   ""
#define it__Auto339   ""
#define es__Auto339   ""
#define de__Auto339   ""
#define nl__Auto339   ""
#define pt__Auto339   ""
#define xx__Auto339   ""
#define en_DefaultOption   "&Model Editor Properties and Options"
#define fr_DefaultOption   "&PropriŠt‚s et options de l'‚diteur de ModŠle"
#define it_DefaultOption   "&Model Editor Properties and Options"
#define es_DefaultOption   "&Model Editor Properties and Options"
#define de_DefaultOption   "&Model Editor Properties and Options"
#define nl_DefaultOption   "&Model Editor Properties and Options"
#define pt_DefaultOption   "&Model Editor Properties and Options"
#define xx_DefaultOption   "&Model Editor Properties and Options"
#define en__DefaultOption   ""
#define fr__DefaultOption   ""
#define it__DefaultOption   ""
#define es__DefaultOption   ""
#define de__DefaultOption   ""
#define nl__DefaultOption   ""
#define pt__DefaultOption   ""
#define xx__DefaultOption   ""
#define en_previous   "&Add New File Entity"
#define fr_previous   "&Ajout d'un fichier"
#define it_previous   "&Add File Member"
#define es_previous   "&Add File Member"
#define de_previous   "&Add File Member"
#define nl_previous   "&Add File Member"
#define pt_previous   "&Add File Member"
#define xx_previous   "&Add File Member"
#define en__previous   ""
#define fr__previous   ""
#define it__previous   ""
#define es__previous   ""
#define de__previous   ""
#define nl__previous   ""
#define pt__previous   ""
#define xx__previous   ""
#define en_Auto340   "&Paste the copied File / Entity"
#define fr_Auto340   "&Coller le fichier copi‚"
#define it_Auto340   "&Paste the copied File / Class"
#define es_Auto340   "&Paste the copied File / Class"
#define de_Auto340   "&Paste the copied File / Class"
#define nl_Auto340   "&Paste the copied File / Class"
#define pt_Auto340   "&Paste the copied File / Class"
#define xx_Auto340   "&Paste the copied File / Class"
#define en__Auto340   ""
#define fr__Auto340   ""
#define it__Auto340   ""
#define es__Auto340   ""
#define de__Auto340   ""
#define nl__Auto340   ""
#define pt__Auto340   ""
#define xx__Auto340   ""
#define en_Auto341   "&Reset and Recalculate Database Display"
#define fr_Auto341   "&Recalculation de l'affichage de la base de donn‚es"
#define it_Auto341   "&Reset and Recalculate Database Display"
#define es_Auto341   "&Reset and Recalculate Database Display"
#define de_Auto341   "&Reset and Recalculate Database Display"
#define nl_Auto341   "&Reset and Recalculate Database Display"
#define pt_Auto341   "&Reset and Recalculate Database Display"
#define xx_Auto341   "&Reset and Recalculate Database Display"
#define en__Auto341   ""
#define fr__Auto341   ""
#define it__Auto341   ""
#define es__Auto341   ""
#define de__Auto341   ""
#define nl__Auto341   ""
#define pt__Auto341   ""
#define xx__Auto341   ""
#define en__Auto342   ""
#define en_Auto343   "&Export the Database to an XML file"
#define fr_Auto343   "&Exporter la Base de Donn‚es"
#define it_Auto343   "&Export the Database to an XML file"
#define es_Auto343   "&Export the Database to an XML file"
#define de_Auto343   "&Export the Database to an XML file"
#define nl_Auto343   "&Export the Database to an XML file"
#define pt_Auto343   "&Export the Database to an XML file"
#define xx_Auto343   "&Export the Database to an XML file"
#define en__Auto343   ""
#define fr__Auto343   ""
#define it__Auto343   ""
#define es__Auto343   ""
#define de__Auto343   ""
#define nl__Auto343   ""
#define pt__Auto343   ""
#define xx__Auto343   ""
#define en_Auto344   "&Save to Image File"
#define fr_Auto344   "&Sauver un fichier d'image"
#define it_Auto344   "&Save to Image File"
#define es_Auto344   "&Save to Image File"
#define de_Auto344   "&Save to Image File"
#define nl_Auto344   "&Save to Image File"
#define pt_Auto344   "&Save to Image File"
#define xx_Auto344   "&Save to Image File"
#define en__Auto344   ""
#define fr__Auto344   ""
#define it__Auto344   ""
#define es__Auto344   ""
#define de__Auto344   ""
#define nl__Auto344   ""
#define pt__Auto344   ""
#define xx__Auto344   ""
#define en_Auto345   "&Import the Database from an XML file"
#define fr_Auto345   "&Importer la Base de Donn‚es"
#define it_Auto345   "&Import the Database from an XML file"
#define es_Auto345   "&Import the Database from an XML file"
#define de_Auto345   "&Import the Database from an XML file"
#define nl_Auto345   "&Import the Database from an XML file"
#define pt_Auto345   "&Import the Database from an XML file"
#define xx_Auto345   "&Import the Database from an XML file"
#define en__Auto345   ""
#define fr__Auto345   ""
#define it__Auto345   ""
#define es__Auto345   ""
#define de__Auto345   ""
#define nl__Auto345   ""
#define pt__Auto345   ""
#define xx__Auto345   ""
#define en_Auto346   "Rea&d Abal Source Declaration File"
#define fr_Auto346   "&Lire un fichier de d‚clarations Abal"
#define it_Auto346   "Imp&ort the Database from an XML file"
#define es_Auto346   "Imp&ort the Database from an XML file"
#define de_Auto346   "Imp&ort the Database from an XML file"
#define nl_Auto346   "Imp&ort the Database from an XML file"
#define pt_Auto346   "Imp&ort the Database from an XML file"
#define xx_Auto346   "Imp&ort the Database from an XML file"
#define en__Auto346   ""
#define fr__Auto346   ""
#define it__Auto346   ""
#define es__Auto346   ""
#define de__Auto346   ""
#define nl__Auto346   ""
#define pt__Auto346   ""
#define xx__Auto346   ""
#define en__Auto347   ""
#define en_Auto348   "&Toggle Relation Tracing : Direct/Routed"
#define fr_Auto348   "&Bascule le type de routage"
#define it_Auto348   "&Toggle Relation Tracing : Direct/Routed"
#define es_Auto348   "&Toggle Relation Tracing : Direct/Routed"
#define de_Auto348   "&Toggle Relation Tracing : Direct/Routed"
#define nl_Auto348   "&Toggle Relation Tracing : Direct/Routed"
#define pt_Auto348   "&Toggle Relation Tracing : Direct/Routed"
#define xx_Auto348   "&Toggle Relation Tracing : Direct/Routed"
#define en__Auto348   ""
#define fr__Auto348   ""
#define it__Auto348   ""
#define es__Auto348   ""
#define de__Auto348   ""
#define nl__Auto348   ""
#define pt__Auto348   ""
#define xx__Auto348   ""
#define en_Auto349   "T&oggle Database display : Project/Forms"
#define fr_Auto349   "Basc&uler l'affichage entre Project et Formulaire"
#define it_Auto349   "To&ggle Database display : Project/Forms"
#define es_Auto349   "To&ggle Database display : Project/Forms"
#define de_Auto349   "To&ggle Database display : Project/Forms"
#define nl_Auto349   "To&ggle Database display : Project/Forms"
#define pt_Auto349   "To&ggle Database display : Project/Forms"
#define xx_Auto349   "To&ggle Database display : Project/Forms"
#define en__Auto349   ""
#define fr__Auto349   ""
#define it__Auto349   ""
#define es__Auto349   ""
#define de__Auto349   ""
#define nl__Auto349   ""
#define pt__Auto349   ""
#define xx__Auto349   ""
#define en_Auto350   "To&ggle display of Help Bubble messages"
#define fr_Auto350   "Bascule l‚&tat des bulles d'aide"
#define it_Auto350   "Togg&le display of Help Bubble messages"
#define es_Auto350   "Togg&le display of Help Bubble messages"
#define de_Auto350   "Togg&le display of Help Bubble messages"
#define nl_Auto350   "Togg&le display of Help Bubble messages"
#define pt_Auto350   "Togg&le display of Help Bubble messages"
#define xx_Auto350   "Togg&le display of Help Bubble messages"
#define en__Auto350   ""
#define fr__Auto350   ""
#define it__Auto350   ""
#define es__Auto350   ""
#define de__Auto350   ""
#define nl__Auto350   ""
#define pt__Auto350   ""
#define xx__Auto350   ""
#define en_Auto351   "Togg&le Hyperspace Navigator"
#define fr_Auto351   "Basculer l&'‚tat du visioneur d'hyper-espace"
#define it_Auto351   "Toggle &Hyperspace Navigator"
#define es_Auto351   "Toggle &Hyperspace Navigator"
#define de_Auto351   "Toggle &Hyperspace Navigator"
#define nl_Auto351   "Toggle &Hyperspace Navigator"
#define pt_Auto351   "Toggle &Hyperspace Navigator"
#define xx_Auto351   "Toggle &Hyperspace Navigator"
#define en__Auto351   ""
#define fr__Auto351   ""
#define it__Auto351   ""
#define es__Auto351   ""
#define de__Auto351   ""
#define nl__Auto351   ""
#define pt__Auto351   ""
#define xx__Auto351   ""
#define en_Auto352   "Toggle Lo&ck / Unlock of all Entities"
#define fr_Auto352   "Bascule l'‚tat &de verouillage des ‚lements"
#define it_Auto352   "Paste the &copied File / Class"
#define es_Auto352   "Paste the &copied File / Class"
#define de_Auto352   "Paste the &copied File / Class"
#define nl_Auto352   "Paste the &copied File / Class"
#define pt_Auto352   "Paste the &copied File / Class"
#define xx_Auto352   "Paste the &copied File / Class"
#define en__Auto352   ""
#define fr__Auto352   ""
#define it__Auto352   ""
#define es__Auto352   ""
#define de__Auto352   ""
#define nl__Auto352   ""
#define pt__Auto352   ""
#define xx__Auto352   ""
#define en_Auto353   "Toggle Ope&n / Close of all Entities"
#define fr_Auto353   "Bascule l'‚tat d'&ouverture des ‚lements"
#define it_Auto353   "Toggle Ope&n / Close of all Entities"
#define es_Auto353   "Toggle Ope&n / Close of all Entities"
#define de_Auto353   "Toggle Ope&n / Close of all Entities"
#define nl_Auto353   "Toggle Ope&n / Close of all Entities"
#define pt_Auto353   "Toggle Ope&n / Close of all Entities"
#define xx_Auto353   "Toggle Ope&n / Close of all Entities"
#define en__Auto353   ""
#define fr__Auto353   ""
#define it__Auto353   ""
#define es__Auto353   ""
#define de__Auto353   ""
#define nl__Auto353   ""
#define pt__Auto353   ""
#define xx__Auto353   ""

private struct database_main_menu_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto339[8];
	char * hint_Auto339[8];
	int	s_Auto339;
	void *	p_Auto339;
	int	x_Auto339;
	int	y_Auto339;
	int	w_Auto339;
	int	h_Auto339;
	char * msg_DefaultOption[8];
	int	trigger_DefaultOption;
	char * hint_DefaultOption[8];
	char * msg_previous[8];
	int	trigger_previous;
	char * hint_previous[8];
	char * msg_Auto340[8];
	int	trigger_Auto340;
	char * hint_Auto340[8];
	int	s_Auto340;
	void *	p_Auto340;
	char * msg_Auto341[8];
	int	trigger_Auto341;
	char * hint_Auto341[8];
	char * hint_Auto342[8];
	char * msg_Auto343[8];
	int	trigger_Auto343;
	char * hint_Auto343[8];
	char * msg_Auto344[8];
	int	trigger_Auto344;
	char * hint_Auto344[8];
	char * msg_Auto345[8];
	int	trigger_Auto345;
	char * hint_Auto345[8];
	char * msg_Auto346[8];
	int	trigger_Auto346;
	char * hint_Auto346[8];
	char * hint_Auto347[8];
	char * msg_Auto348[8];
	int	trigger_Auto348;
	char * hint_Auto348[8];
	char * msg_Auto349[8];
	int	trigger_Auto349;
	char * hint_Auto349[8];
	char * msg_Auto350[8];
	int	trigger_Auto350;
	char * hint_Auto350[8];
	char * msg_Auto351[8];
	int	trigger_Auto351;
	char * hint_Auto351[8];
	char * msg_Auto352[8];
	int	trigger_Auto352;
	char * hint_Auto352[8];
	char * msg_Auto353[8];
	int	trigger_Auto353;
	char * hint_Auto353[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	};
static int	vfh[16];

static int stdinput(struct database_main_menu_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = database_main_menu_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}

private int on_Auto339_create(struct database_main_menu_context * _Context) {
	mouse_move_on();
	if(((_Context->y_Auto339=visual_event(6))+364)>hardrows())
	_Context->y_Auto339=(hardrows()-364);
	if(((_Context->x_Auto339=visual_event(7))+336)>hardcolumns())
	_Context->x_Auto339=(hardcolumns()-336);
	return(-1);
}

public	int	database_main_menu_create(struct database_main_menu_context **cptr)
{

	int i;
	struct database_main_menu_context * _Context=(struct database_main_menu_context*)0;
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
	if (!(_Context = allocate( sizeof( struct database_main_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=14;
	for (i=0; i < 8; i++)_Context->msg_Auto339[i]=" ";
	_Context->msg_Auto339[0]=en_Auto339;
	_Context->msg_Auto339[1]=fr_Auto339;
	_Context->msg_Auto339[2]=it_Auto339;
	_Context->msg_Auto339[3]=es_Auto339;
	_Context->msg_Auto339[4]=de_Auto339;
	_Context->msg_Auto339[5]=nl_Auto339;
	_Context->msg_Auto339[6]=pt_Auto339;
	_Context->msg_Auto339[7]=xx_Auto339;
	_Context->hint_Auto339[0]=en__Auto339;
	_Context->hint_Auto339[1]=fr__Auto339;
	_Context->hint_Auto339[2]=it__Auto339;
	_Context->hint_Auto339[3]=es__Auto339;
	_Context->hint_Auto339[4]=de__Auto339;
	_Context->hint_Auto339[5]=nl__Auto339;
	_Context->hint_Auto339[6]=pt__Auto339;
	_Context->hint_Auto339[7]=xx__Auto339;
	_Context->s_Auto339=0;
	_Context->p_Auto339=visual_buffer(_Context->x_Auto339,_Context->y_Auto339,336+2,364+2);
	_Context->x_Auto339=40;
	_Context->y_Auto339=36;
	_Context->w_Auto339=336;
	_Context->h_Auto339=364;
	_Context->window_col=40;
	_Context->window_row=36;
	(void) on_Auto339_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_DefaultOption[i]=" ";
	_Context->msg_DefaultOption[0]=en_DefaultOption;
	_Context->msg_DefaultOption[1]=fr_DefaultOption;
	_Context->msg_DefaultOption[2]=it_DefaultOption;
	_Context->msg_DefaultOption[3]=es_DefaultOption;
	_Context->msg_DefaultOption[4]=de_DefaultOption;
	_Context->msg_DefaultOption[5]=nl_DefaultOption;
	_Context->msg_DefaultOption[6]=pt_DefaultOption;
	_Context->msg_DefaultOption[7]=xx_DefaultOption;
	_Context->hint_DefaultOption[0]=en__DefaultOption;
	_Context->hint_DefaultOption[1]=fr__DefaultOption;
	_Context->hint_DefaultOption[2]=it__DefaultOption;
	_Context->hint_DefaultOption[3]=es__DefaultOption;
	_Context->hint_DefaultOption[4]=de__DefaultOption;
	_Context->hint_DefaultOption[5]=nl__DefaultOption;
	_Context->hint_DefaultOption[6]=pt__DefaultOption;
	_Context->hint_DefaultOption[7]=xx__DefaultOption;
	_Context->focus_item=4;
	for (i=0; i < 8; i++)_Context->msg_previous[i]=" ";
	_Context->msg_previous[0]=en_previous;
	_Context->msg_previous[1]=fr_previous;
	_Context->msg_previous[2]=it_previous;
	_Context->msg_previous[3]=es_previous;
	_Context->msg_previous[4]=de_previous;
	_Context->msg_previous[5]=nl_previous;
	_Context->msg_previous[6]=pt_previous;
	_Context->msg_previous[7]=xx_previous;
	_Context->hint_previous[0]=en__previous;
	_Context->hint_previous[1]=fr__previous;
	_Context->hint_previous[2]=it__previous;
	_Context->hint_previous[3]=es__previous;
	_Context->hint_previous[4]=de__previous;
	_Context->hint_previous[5]=nl__previous;
	_Context->hint_previous[6]=pt__previous;
	_Context->hint_previous[7]=xx__previous;
	for (i=0; i < 8; i++)_Context->msg_Auto340[i]=" ";
	_Context->msg_Auto340[0]=en_Auto340;
	_Context->msg_Auto340[1]=fr_Auto340;
	_Context->msg_Auto340[2]=it_Auto340;
	_Context->msg_Auto340[3]=es_Auto340;
	_Context->msg_Auto340[4]=de_Auto340;
	_Context->msg_Auto340[5]=nl_Auto340;
	_Context->msg_Auto340[6]=pt_Auto340;
	_Context->msg_Auto340[7]=xx_Auto340;
	_Context->hint_Auto340[0]=en__Auto340;
	_Context->hint_Auto340[1]=fr__Auto340;
	_Context->hint_Auto340[2]=it__Auto340;
	_Context->hint_Auto340[3]=es__Auto340;
	_Context->hint_Auto340[4]=de__Auto340;
	_Context->hint_Auto340[5]=nl__Auto340;
	_Context->hint_Auto340[6]=pt__Auto340;
	_Context->hint_Auto340[7]=xx__Auto340;
	_Context->s_Auto340=0;
	_Context->p_Auto340=visual_buffer(_Context->x_Auto339+16,_Context->y_Auto339+56,296+2,20+2);
	for (i=0; i < 8; i++)_Context->msg_Auto341[i]=" ";
	_Context->msg_Auto341[0]=en_Auto341;
	_Context->msg_Auto341[1]=fr_Auto341;
	_Context->msg_Auto341[2]=it_Auto341;
	_Context->msg_Auto341[3]=es_Auto341;
	_Context->msg_Auto341[4]=de_Auto341;
	_Context->msg_Auto341[5]=nl_Auto341;
	_Context->msg_Auto341[6]=pt_Auto341;
	_Context->msg_Auto341[7]=xx_Auto341;
	_Context->hint_Auto341[0]=en__Auto341;
	_Context->hint_Auto341[1]=fr__Auto341;
	_Context->hint_Auto341[2]=it__Auto341;
	_Context->hint_Auto341[3]=es__Auto341;
	_Context->hint_Auto341[4]=de__Auto341;
	_Context->hint_Auto341[5]=nl__Auto341;
	_Context->hint_Auto341[6]=pt__Auto341;
	_Context->hint_Auto341[7]=xx__Auto341;
	_Context->hint_Auto342[0]=en__Auto342;
	for (i=0; i < 8; i++)_Context->msg_Auto343[i]=" ";
	_Context->msg_Auto343[0]=en_Auto343;
	_Context->msg_Auto343[1]=fr_Auto343;
	_Context->msg_Auto343[2]=it_Auto343;
	_Context->msg_Auto343[3]=es_Auto343;
	_Context->msg_Auto343[4]=de_Auto343;
	_Context->msg_Auto343[5]=nl_Auto343;
	_Context->msg_Auto343[6]=pt_Auto343;
	_Context->msg_Auto343[7]=xx_Auto343;
	_Context->hint_Auto343[0]=en__Auto343;
	_Context->hint_Auto343[1]=fr__Auto343;
	_Context->hint_Auto343[2]=it__Auto343;
	_Context->hint_Auto343[3]=es__Auto343;
	_Context->hint_Auto343[4]=de__Auto343;
	_Context->hint_Auto343[5]=nl__Auto343;
	_Context->hint_Auto343[6]=pt__Auto343;
	_Context->hint_Auto343[7]=xx__Auto343;
	for (i=0; i < 8; i++)_Context->msg_Auto344[i]=" ";
	_Context->msg_Auto344[0]=en_Auto344;
	_Context->msg_Auto344[1]=fr_Auto344;
	_Context->msg_Auto344[2]=it_Auto344;
	_Context->msg_Auto344[3]=es_Auto344;
	_Context->msg_Auto344[4]=de_Auto344;
	_Context->msg_Auto344[5]=nl_Auto344;
	_Context->msg_Auto344[6]=pt_Auto344;
	_Context->msg_Auto344[7]=xx_Auto344;
	_Context->hint_Auto344[0]=en__Auto344;
	_Context->hint_Auto344[1]=fr__Auto344;
	_Context->hint_Auto344[2]=it__Auto344;
	_Context->hint_Auto344[3]=es__Auto344;
	_Context->hint_Auto344[4]=de__Auto344;
	_Context->hint_Auto344[5]=nl__Auto344;
	_Context->hint_Auto344[6]=pt__Auto344;
	_Context->hint_Auto344[7]=xx__Auto344;
	for (i=0; i < 8; i++)_Context->msg_Auto345[i]=" ";
	_Context->msg_Auto345[0]=en_Auto345;
	_Context->msg_Auto345[1]=fr_Auto345;
	_Context->msg_Auto345[2]=it_Auto345;
	_Context->msg_Auto345[3]=es_Auto345;
	_Context->msg_Auto345[4]=de_Auto345;
	_Context->msg_Auto345[5]=nl_Auto345;
	_Context->msg_Auto345[6]=pt_Auto345;
	_Context->msg_Auto345[7]=xx_Auto345;
	_Context->hint_Auto345[0]=en__Auto345;
	_Context->hint_Auto345[1]=fr__Auto345;
	_Context->hint_Auto345[2]=it__Auto345;
	_Context->hint_Auto345[3]=es__Auto345;
	_Context->hint_Auto345[4]=de__Auto345;
	_Context->hint_Auto345[5]=nl__Auto345;
	_Context->hint_Auto345[6]=pt__Auto345;
	_Context->hint_Auto345[7]=xx__Auto345;
	for (i=0; i < 8; i++)_Context->msg_Auto346[i]=" ";
	_Context->msg_Auto346[0]=en_Auto346;
	_Context->msg_Auto346[1]=fr_Auto346;
	_Context->msg_Auto346[2]=it_Auto346;
	_Context->msg_Auto346[3]=es_Auto346;
	_Context->msg_Auto346[4]=de_Auto346;
	_Context->msg_Auto346[5]=nl_Auto346;
	_Context->msg_Auto346[6]=pt_Auto346;
	_Context->msg_Auto346[7]=xx_Auto346;
	_Context->hint_Auto346[0]=en__Auto346;
	_Context->hint_Auto346[1]=fr__Auto346;
	_Context->hint_Auto346[2]=it__Auto346;
	_Context->hint_Auto346[3]=es__Auto346;
	_Context->hint_Auto346[4]=de__Auto346;
	_Context->hint_Auto346[5]=nl__Auto346;
	_Context->hint_Auto346[6]=pt__Auto346;
	_Context->hint_Auto346[7]=xx__Auto346;
	_Context->hint_Auto347[0]=en__Auto347;
	for (i=0; i < 8; i++)_Context->msg_Auto348[i]=" ";
	_Context->msg_Auto348[0]=en_Auto348;
	_Context->msg_Auto348[1]=fr_Auto348;
	_Context->msg_Auto348[2]=it_Auto348;
	_Context->msg_Auto348[3]=es_Auto348;
	_Context->msg_Auto348[4]=de_Auto348;
	_Context->msg_Auto348[5]=nl_Auto348;
	_Context->msg_Auto348[6]=pt_Auto348;
	_Context->msg_Auto348[7]=xx_Auto348;
	_Context->hint_Auto348[0]=en__Auto348;
	_Context->hint_Auto348[1]=fr__Auto348;
	_Context->hint_Auto348[2]=it__Auto348;
	_Context->hint_Auto348[3]=es__Auto348;
	_Context->hint_Auto348[4]=de__Auto348;
	_Context->hint_Auto348[5]=nl__Auto348;
	_Context->hint_Auto348[6]=pt__Auto348;
	_Context->hint_Auto348[7]=xx__Auto348;
	for (i=0; i < 8; i++)_Context->msg_Auto349[i]=" ";
	_Context->msg_Auto349[0]=en_Auto349;
	_Context->msg_Auto349[1]=fr_Auto349;
	_Context->msg_Auto349[2]=it_Auto349;
	_Context->msg_Auto349[3]=es_Auto349;
	_Context->msg_Auto349[4]=de_Auto349;
	_Context->msg_Auto349[5]=nl_Auto349;
	_Context->msg_Auto349[6]=pt_Auto349;
	_Context->msg_Auto349[7]=xx_Auto349;
	_Context->hint_Auto349[0]=en__Auto349;
	_Context->hint_Auto349[1]=fr__Auto349;
	_Context->hint_Auto349[2]=it__Auto349;
	_Context->hint_Auto349[3]=es__Auto349;
	_Context->hint_Auto349[4]=de__Auto349;
	_Context->hint_Auto349[5]=nl__Auto349;
	_Context->hint_Auto349[6]=pt__Auto349;
	_Context->hint_Auto349[7]=xx__Auto349;
	for (i=0; i < 8; i++)_Context->msg_Auto350[i]=" ";
	_Context->msg_Auto350[0]=en_Auto350;
	_Context->msg_Auto350[1]=fr_Auto350;
	_Context->msg_Auto350[2]=it_Auto350;
	_Context->msg_Auto350[3]=es_Auto350;
	_Context->msg_Auto350[4]=de_Auto350;
	_Context->msg_Auto350[5]=nl_Auto350;
	_Context->msg_Auto350[6]=pt_Auto350;
	_Context->msg_Auto350[7]=xx_Auto350;
	_Context->hint_Auto350[0]=en__Auto350;
	_Context->hint_Auto350[1]=fr__Auto350;
	_Context->hint_Auto350[2]=it__Auto350;
	_Context->hint_Auto350[3]=es__Auto350;
	_Context->hint_Auto350[4]=de__Auto350;
	_Context->hint_Auto350[5]=nl__Auto350;
	_Context->hint_Auto350[6]=pt__Auto350;
	_Context->hint_Auto350[7]=xx__Auto350;
	for (i=0; i < 8; i++)_Context->msg_Auto351[i]=" ";
	_Context->msg_Auto351[0]=en_Auto351;
	_Context->msg_Auto351[1]=fr_Auto351;
	_Context->msg_Auto351[2]=it_Auto351;
	_Context->msg_Auto351[3]=es_Auto351;
	_Context->msg_Auto351[4]=de_Auto351;
	_Context->msg_Auto351[5]=nl_Auto351;
	_Context->msg_Auto351[6]=pt_Auto351;
	_Context->msg_Auto351[7]=xx_Auto351;
	_Context->hint_Auto351[0]=en__Auto351;
	_Context->hint_Auto351[1]=fr__Auto351;
	_Context->hint_Auto351[2]=it__Auto351;
	_Context->hint_Auto351[3]=es__Auto351;
	_Context->hint_Auto351[4]=de__Auto351;
	_Context->hint_Auto351[5]=nl__Auto351;
	_Context->hint_Auto351[6]=pt__Auto351;
	_Context->hint_Auto351[7]=xx__Auto351;
	for (i=0; i < 8; i++)_Context->msg_Auto352[i]=" ";
	_Context->msg_Auto352[0]=en_Auto352;
	_Context->msg_Auto352[1]=fr_Auto352;
	_Context->msg_Auto352[2]=it_Auto352;
	_Context->msg_Auto352[3]=es_Auto352;
	_Context->msg_Auto352[4]=de_Auto352;
	_Context->msg_Auto352[5]=nl_Auto352;
	_Context->msg_Auto352[6]=pt_Auto352;
	_Context->msg_Auto352[7]=xx_Auto352;
	_Context->hint_Auto352[0]=en__Auto352;
	_Context->hint_Auto352[1]=fr__Auto352;
	_Context->hint_Auto352[2]=it__Auto352;
	_Context->hint_Auto352[3]=es__Auto352;
	_Context->hint_Auto352[4]=de__Auto352;
	_Context->hint_Auto352[5]=nl__Auto352;
	_Context->hint_Auto352[6]=pt__Auto352;
	_Context->hint_Auto352[7]=xx__Auto352;
	for (i=0; i < 8; i++)_Context->msg_Auto353[i]=" ";
	_Context->msg_Auto353[0]=en_Auto353;
	_Context->msg_Auto353[1]=fr_Auto353;
	_Context->msg_Auto353[2]=it_Auto353;
	_Context->msg_Auto353[3]=es_Auto353;
	_Context->msg_Auto353[4]=de_Auto353;
	_Context->msg_Auto353[5]=nl_Auto353;
	_Context->msg_Auto353[6]=pt_Auto353;
	_Context->msg_Auto353[7]=xx_Auto353;
	_Context->hint_Auto353[0]=en__Auto353;
	_Context->hint_Auto353[1]=fr__Auto353;
	_Context->hint_Auto353[2]=it__Auto353;
	_Context->hint_Auto353[3]=es__Auto353;
	_Context->hint_Auto353[4]=de__Auto353;
	_Context->hint_Auto353[5]=nl__Auto353;
	_Context->hint_Auto353[6]=pt__Auto353;
	_Context->hint_Auto353[7]=xx__Auto353;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto339,_Context->y_Auto339,336,364);
	return(0);
}

public 	int	database_main_menu_hide(struct database_main_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Auto340 != (void *) 0)
	&& (_Context->s_Auto340 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto340,_Context->x_Auto339+16,_Context->y_Auto339+56);
		_Context->s_Auto340=0;
		}
	if ((_Context->p_Auto339 != (void *) 0)
	&& (_Context->s_Auto339 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto339,_Context->x_Auto339,_Context->y_Auto339);
		_Context->s_Auto339=0;
		}
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto339,_Context->y_Auto339);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	database_main_menu_remove(struct database_main_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->p_Auto340 != (void *) 0)
		_Context->p_Auto340 = visual_drop(_Context->p_Auto340);
	mouse_move_off();
	if (_Context->p_Auto339 != (void *) 0)
		_Context->p_Auto339 = visual_drop(_Context->p_Auto339);
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_Auto340_show(struct database_main_menu_context * _Context) {
	if(database_copied_class()){
		if ((_Context->p_Auto340 != (void *) 0)
	&& (_Context->s_Auto340 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto340,_Context->x_Auto339+16,_Context->y_Auto339+56);
		_Context->s_Auto340=1;
		}
	if ((_Context->p_Auto340 != (void *) 0)
	&& (_Context->s_Auto340 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto340,_Context->x_Auto339+16,_Context->y_Auto339+56);
		_Context->s_Auto340=1;
		}
	_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+56,296,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+56,296,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
	}
;
	}
	else{
		if ((_Context->p_Auto340 != (void *) 0)
	&& (_Context->s_Auto340 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto340,_Context->x_Auto339+16,_Context->y_Auto339+56);
		_Context->s_Auto340=0;
		}
;
	}
		return(-1);
}

public	int	database_main_menu_show(struct database_main_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto339,_Context->y_Auto339);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if ((_Context->p_Auto339 != (void *) 0)
	&& (_Context->s_Auto339 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto339,_Context->x_Auto339,_Context->y_Auto339);
		_Context->s_Auto339=1;
		}
	if (((_Context->status = visual_styled_element(_Context->x_Auto339,_Context->y_Auto339,336,364,GetWidgetStyle(1),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
		visual_window(_Context->x_Auto339,_Context->y_Auto339,336,364,vfh[1],_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),0x4);
		}
	_Context->trigger_DefaultOption=visual_trigger_code(_Context->msg_DefaultOption[_Context->language],strlen(_Context->msg_DefaultOption[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+16,296,20,GetWidgetStyle(2),_Context->msg_DefaultOption[_Context->language],strlen(_Context->msg_DefaultOption[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+16,296,20,vfh[2],16,0,_Context->msg_DefaultOption[_Context->language],strlen(_Context->msg_DefaultOption[_Context->language]),32);
		}
	_Context->trigger_previous=visual_trigger_code(_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+36,296,20,GetWidgetStyle(2),_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+36,296,20,vfh[2],16,0,_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]),32);
		}
	if ((_Context->p_Auto340 != (void *) 0)
	&& (_Context->s_Auto340 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto340,_Context->x_Auto339+16,_Context->y_Auto339+56);
		_Context->s_Auto340=1;
		}
	(void) on_Auto340_show(_Context);
	_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+76,304,20,GetWidgetStyle(2),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+76,304,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),32);
		}
	visual_filzone(_Context->x_Auto339+8,_Context->y_Auto339+100,320,4,26,18);
	_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+116,304,20,GetWidgetStyle(2),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+116,304,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),32);
		}
	_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+136,296,20,GetWidgetStyle(2),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+136,296,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),32);
		}
	_Context->trigger_Auto345=visual_trigger_code(_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+156,296,20,GetWidgetStyle(2),_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+156,296,20,vfh[2],16,0,_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]),32);
		}
	_Context->trigger_Auto346=visual_trigger_code(_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+176,296,20,GetWidgetStyle(2),_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+176,296,20,vfh[2],16,0,_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]),32);
		}
	visual_filzone(_Context->x_Auto339+8,_Context->y_Auto339+204,320,4,26,18);
	_Context->trigger_Auto348=visual_trigger_code(_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+216,296,20,GetWidgetStyle(2),_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+216,296,20,vfh[2],16,0,_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]),32);
		}
	_Context->trigger_Auto349=visual_trigger_code(_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+240,296,20,GetWidgetStyle(2),_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+240,296,20,vfh[2],16,0,_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]),32);
		}
	_Context->trigger_Auto350=visual_trigger_code(_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+264,296,20,GetWidgetStyle(2),_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+264,296,20,vfh[2],16,0,_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]),32);
		}
	_Context->trigger_Auto351=visual_trigger_code(_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+288,296,20,GetWidgetStyle(2),_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+288,296,20,vfh[2],16,0,_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]),32);
		}
	_Context->trigger_Auto352=visual_trigger_code(_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+308,296,20,GetWidgetStyle(2),_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+308,296,20,vfh[2],16,0,_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]),32);
		}
	_Context->trigger_Auto353=visual_trigger_code(_Context->msg_Auto353[_Context->language],strlen(_Context->msg_Auto353[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+328,296,20,GetWidgetStyle(2),_Context->msg_Auto353[_Context->language],strlen(_Context->msg_Auto353[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+328,296,20,vfh[2],16,0,_Context->msg_Auto353[_Context->language],strlen(_Context->msg_Auto353[_Context->language]),32);
		}
	visual_thaw(_Context->x_Auto339,_Context->y_Auto339,336,364);

	return(0);
}
private int on_DefaultOption_event(struct database_main_menu_context * _Context) {
	return(_BASE_INFO);
	return(-1);
}
private int on_previous_event(struct database_main_menu_context * _Context) {
	return(_BASE_ADD);
	return(-1);
}
private int on_Auto340_event(struct database_main_menu_context * _Context) {
	if(database_copied_class()){
	switch(visual_event(1)){
	case _MIMO_UP:
	return(_MODEL_PASTE);
	default:
	return(-1);
	}
	}
	else{
		if ((_Context->p_Auto340 != (void *) 0)
	&& (_Context->s_Auto340 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto340,_Context->x_Auto339+16,_Context->y_Auto339+56);
		_Context->s_Auto340=0;
		}
;
		/* previous */
	database_main_menu_show(_Context);
	_Context->focus_item=2;
;
	return(-1);
	}
	return(-1);
}
private int on_Auto341_event(struct database_main_menu_context * _Context) {
	return(_BASE_RESET);
	return(-1);
}
private int on_Auto343_event(struct database_main_menu_context * _Context) {
	return(_BASE_EXPORT);
	return(-1);
}
private int on_Auto344_event(struct database_main_menu_context * _Context) {
	return(_BASE_IMAGE);
	return(-1);
}
private int on_Auto345_event(struct database_main_menu_context * _Context) {
	return(_BASE_IMPORT);
	return(-1);
}
private int on_Auto346_event(struct database_main_menu_context * _Context) {
	return(_BASE_READ);
	return(-1);
}
private int on_Auto348_event(struct database_main_menu_context * _Context) {
	return(_BASE_TRACE);
	return(-1);
}
private int on_Auto349_event(struct database_main_menu_context * _Context) {
	return(_BASE_INHIBIT);
	return(-1);
}
private int on_Auto350_event(struct database_main_menu_context * _Context) {
	return(_BASE_HELP);
	return(-1);
}
private int on_Auto351_event(struct database_main_menu_context * _Context) {
	return(_BASE_HYPER);
	return(-1);
}
private int on_Auto352_event(struct database_main_menu_context * _Context) {
	return(_BASE_LOCK);
	return(-1);
}
private int on_Auto353_event(struct database_main_menu_context * _Context) {
	return(_BASE_CLOSE);
	return(-1);
}


public	int	database_main_menu_event(
struct database_main_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_DefaultOption == mb ) return(1);
		if (_Context->trigger_previous == mb ) return(2);
		if (_Context->trigger_Auto340 == mb ) return(3);
		if (_Context->trigger_Auto341 == mb ) return(4);
		if (_Context->trigger_Auto343 == mb ) return(5);
		if (_Context->trigger_Auto344 == mb ) return(6);
		if (_Context->trigger_Auto345 == mb ) return(7);
		if (_Context->trigger_Auto346 == mb ) return(8);
		if (_Context->trigger_Auto348 == mb ) return(9);
		if (_Context->trigger_Auto349 == mb ) return(10);
		if (_Context->trigger_Auto350 == mb ) return(11);
		if (_Context->trigger_Auto351 == mb ) return(12);
		if (_Context->trigger_Auto352 == mb ) return(13);
		if (_Context->trigger_Auto353 == mb ) return(14);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= (_Context->x_Auto339+16) ) 
	&&  ( my >= (_Context->y_Auto339+16) ) 
	&&  ( mx <= (_Context->x_Auto339+16+296) ) 
	&&  ( my <= (_Context->y_Auto339+16+20))) {
		return(1); /* DefaultOption */
		}
	if (( mx >= (_Context->x_Auto339+16) ) 
	&&  ( my >= (_Context->y_Auto339+36) ) 
	&&  ( mx <= (_Context->x_Auto339+16+296) ) 
	&&  ( my <= (_Context->y_Auto339+36+20))) {
		return(2); /* previous */
		}
	if (( mx >= (_Context->x_Auto339+16) ) 
	&&  ( my >= (_Context->y_Auto339+56) ) 
	&&  ( mx <= (_Context->x_Auto339+16+296) ) 
	&&  ( my <= (_Context->y_Auto339+56+20))) {
		return(3); /* Auto340 */
		}
	if (( mx >= (_Context->x_Auto339+16) ) 
	&&  ( my >= (_Context->y_Auto339+76) ) 
	&&  ( mx <= (_Context->x_Auto339+16+304) ) 
	&&  ( my <= (_Context->y_Auto339+76+20))) {
		return(4); /* Auto341 */
		}
	if (( mx >= (_Context->x_Auto339+16) ) 
	&&  ( my >= (_Context->y_Auto339+116) ) 
	&&  ( mx <= (_Context->x_Auto339+16+304) ) 
	&&  ( my <= (_Context->y_Auto339+116+20))) {
		return(5); /* Auto343 */
		}
	if (( mx >= (_Context->x_Auto339+16) ) 
	&&  ( my >= (_Context->y_Auto339+136) ) 
	&&  ( mx <= (_Context->x_Auto339+16+296) ) 
	&&  ( my <= (_Context->y_Auto339+136+20))) {
		return(6); /* Auto344 */
		}
	if (( mx >= (_Context->x_Auto339+16) ) 
	&&  ( my >= (_Context->y_Auto339+156) ) 
	&&  ( mx <= (_Context->x_Auto339+16+296) ) 
	&&  ( my <= (_Context->y_Auto339+156+20))) {
		return(7); /* Auto345 */
		}
	if (( mx >= (_Context->x_Auto339+16) ) 
	&&  ( my >= (_Context->y_Auto339+176) ) 
	&&  ( mx <= (_Context->x_Auto339+16+296) ) 
	&&  ( my <= (_Context->y_Auto339+176+20))) {
		return(8); /* Auto346 */
		}
	if (( mx >= (_Context->x_Auto339+16) ) 
	&&  ( my >= (_Context->y_Auto339+216) ) 
	&&  ( mx <= (_Context->x_Auto339+16+296) ) 
	&&  ( my <= (_Context->y_Auto339+216+20))) {
		return(9); /* Auto348 */
		}
	if (( mx >= (_Context->x_Auto339+16) ) 
	&&  ( my >= (_Context->y_Auto339+240) ) 
	&&  ( mx <= (_Context->x_Auto339+16+296) ) 
	&&  ( my <= (_Context->y_Auto339+240+20))) {
		return(10); /* Auto349 */
		}
	if (( mx >= (_Context->x_Auto339+16) ) 
	&&  ( my >= (_Context->y_Auto339+264) ) 
	&&  ( mx <= (_Context->x_Auto339+16+296) ) 
	&&  ( my <= (_Context->y_Auto339+264+20))) {
		return(11); /* Auto350 */
		}
	if (( mx >= (_Context->x_Auto339+16) ) 
	&&  ( my >= (_Context->y_Auto339+288) ) 
	&&  ( mx <= (_Context->x_Auto339+16+296) ) 
	&&  ( my <= (_Context->y_Auto339+288+20))) {
		return(12); /* Auto351 */
		}
	if (( mx >= (_Context->x_Auto339+16) ) 
	&&  ( my >= (_Context->y_Auto339+308) ) 
	&&  ( mx <= (_Context->x_Auto339+16+296) ) 
	&&  ( my <= (_Context->y_Auto339+308+20))) {
		return(13); /* Auto352 */
		}
	if (( mx >= (_Context->x_Auto339+16) ) 
	&&  ( my >= (_Context->y_Auto339+328) ) 
	&&  ( mx <= (_Context->x_Auto339+16+296) ) 
	&&  ( my <= (_Context->y_Auto339+328+20))) {
		return(14); /* Auto353 */
		}

	return(-1);
}
private int on_Auto340_losefocus(struct database_main_menu_context * _Context) {
	if(!(database_copied_class())){
		if ((_Context->p_Auto340 != (void *) 0)
	&& (_Context->s_Auto340 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto340,_Context->x_Auto339+16,_Context->y_Auto339+56);
		_Context->s_Auto340=0;
		}
;
	}
	else{
		if ((_Context->p_Auto340 != (void *) 0)
	&& (_Context->s_Auto340 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto340,_Context->x_Auto339+16,_Context->y_Auto339+56);
		_Context->s_Auto340=1;
		}
	if ((_Context->p_Auto340 != (void *) 0)
	&& (_Context->s_Auto340 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto340,_Context->x_Auto339+16,_Context->y_Auto339+56);
		_Context->s_Auto340=1;
		}
	_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+56,296,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+56,296,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
	}
;
	}
	return(-1);
}
private int on_Auto340_getfocus(struct database_main_menu_context * _Context) {
	if(!(database_copied_class())){
	_Context->keycode=5;
	}
	else{
		if ((_Context->p_Auto340 != (void *) 0)
	&& (_Context->s_Auto340 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto340,_Context->x_Auto339+16,_Context->y_Auto339+56);
		_Context->s_Auto340=1;
		}
	_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+56,296,20,GetWidgetStyle(3),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
		visual_button(_Context->x_Auto339+16,_Context->y_Auto339+56,296,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),34);
	}
	_Context->keycode = stdinput(_Context);
	if ((_Context->p_Auto340 != (void *) 0)
	&& (_Context->s_Auto340 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto340,_Context->x_Auto339+16,_Context->y_Auto339+56);
		_Context->s_Auto340=1;
		}
	_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+56,296,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+56,296,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
	}
;
	}
	return(_Context->keycode);
	return(-1);
}


public	int	database_main_menu_focus(struct database_main_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* DefaultOption */
				_Context->trigger_DefaultOption=visual_trigger_code(_Context->msg_DefaultOption[_Context->language],strlen(_Context->msg_DefaultOption[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+16,296,20,GetWidgetStyle(3),_Context->msg_DefaultOption[_Context->language],strlen(_Context->msg_DefaultOption[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto339+16,_Context->y_Auto339+16,296,20,vfh[2],16,0,_Context->msg_DefaultOption[_Context->language],strlen(_Context->msg_DefaultOption[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_DefaultOption=visual_trigger_code(_Context->msg_DefaultOption[_Context->language],strlen(_Context->msg_DefaultOption[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+16,296,20,GetWidgetStyle(2),_Context->msg_DefaultOption[_Context->language],strlen(_Context->msg_DefaultOption[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+16,296,20,vfh[2],16,0,_Context->msg_DefaultOption[_Context->language],strlen(_Context->msg_DefaultOption[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* previous */
				_Context->trigger_previous=visual_trigger_code(_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+36,296,20,GetWidgetStyle(3),_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto339+16,_Context->y_Auto339+36,296,20,vfh[2],16,0,_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_previous=visual_trigger_code(_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+36,296,20,GetWidgetStyle(2),_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+36,296,20,vfh[2],16,0,_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto340 */
				_Context->keycode = on_Auto340_getfocus(_Context);
				(void) on_Auto340_losefocus(_Context);
				break;
			case	0x4 :
				/* Auto341 */
				_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+76,304,20,GetWidgetStyle(3),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto339+16,_Context->y_Auto339+76,304,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+76,304,20,GetWidgetStyle(2),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+76,304,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),32);
				}
				break;
			case	0x5 :
				/* Auto343 */
				_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+116,304,20,GetWidgetStyle(3),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto339+16,_Context->y_Auto339+116,304,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+116,304,20,GetWidgetStyle(2),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+116,304,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),32);
				}
				break;
			case	0x6 :
				/* Auto344 */
				_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+136,296,20,GetWidgetStyle(3),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto339+16,_Context->y_Auto339+136,296,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+136,296,20,GetWidgetStyle(2),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+136,296,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),32);
				}
				break;
			case	0x7 :
				/* Auto345 */
				_Context->trigger_Auto345=visual_trigger_code(_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+156,296,20,GetWidgetStyle(3),_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto339+16,_Context->y_Auto339+156,296,20,vfh[2],16,0,_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto345=visual_trigger_code(_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+156,296,20,GetWidgetStyle(2),_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+156,296,20,vfh[2],16,0,_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]),32);
				}
				break;
			case	0x8 :
				/* Auto346 */
				_Context->trigger_Auto346=visual_trigger_code(_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+176,296,20,GetWidgetStyle(3),_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto339+16,_Context->y_Auto339+176,296,20,vfh[2],16,0,_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto346=visual_trigger_code(_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+176,296,20,GetWidgetStyle(2),_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+176,296,20,vfh[2],16,0,_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]),32);
				}
				break;
			case	0x9 :
				/* Auto348 */
				_Context->trigger_Auto348=visual_trigger_code(_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+216,296,20,GetWidgetStyle(3),_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto339+16,_Context->y_Auto339+216,296,20,vfh[2],16,0,_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto348=visual_trigger_code(_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+216,296,20,GetWidgetStyle(2),_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+216,296,20,vfh[2],16,0,_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]),32);
				}
				break;
			case	0xa :
				/* Auto349 */
				_Context->trigger_Auto349=visual_trigger_code(_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+240,296,20,GetWidgetStyle(3),_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto339+16,_Context->y_Auto339+240,296,20,vfh[2],16,0,_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto349=visual_trigger_code(_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+240,296,20,GetWidgetStyle(2),_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+240,296,20,vfh[2],16,0,_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]),32);
				}
				break;
			case	0xb :
				/* Auto350 */
				_Context->trigger_Auto350=visual_trigger_code(_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+264,296,20,GetWidgetStyle(3),_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto339+16,_Context->y_Auto339+264,296,20,vfh[2],16,0,_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto350=visual_trigger_code(_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+264,296,20,GetWidgetStyle(2),_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+264,296,20,vfh[2],16,0,_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]),32);
				}
				break;
			case	0xc :
				/* Auto351 */
				_Context->trigger_Auto351=visual_trigger_code(_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+288,296,20,GetWidgetStyle(3),_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto339+16,_Context->y_Auto339+288,296,20,vfh[2],16,0,_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto351=visual_trigger_code(_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+288,296,20,GetWidgetStyle(2),_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+288,296,20,vfh[2],16,0,_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]),32);
				}
				break;
			case	0xd :
				/* Auto352 */
				_Context->trigger_Auto352=visual_trigger_code(_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+308,296,20,GetWidgetStyle(3),_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto339+16,_Context->y_Auto339+308,296,20,vfh[2],16,0,_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto352=visual_trigger_code(_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+308,296,20,GetWidgetStyle(2),_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+308,296,20,vfh[2],16,0,_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]),32);
				}
				break;
			case	0xe :
				/* Auto353 */
				_Context->trigger_Auto353=visual_trigger_code(_Context->msg_Auto353[_Context->language],strlen(_Context->msg_Auto353[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+328,296,20,GetWidgetStyle(3),_Context->msg_Auto353[_Context->language],strlen(_Context->msg_Auto353[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto339+16,_Context->y_Auto339+328,296,20,vfh[2],16,0,_Context->msg_Auto353[_Context->language],strlen(_Context->msg_Auto353[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto353=visual_trigger_code(_Context->msg_Auto353[_Context->language],strlen(_Context->msg_Auto353[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+328,296,20,GetWidgetStyle(2),_Context->msg_Auto353[_Context->language],strlen(_Context->msg_Auto353[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+328,296,20,vfh[2],16,0,_Context->msg_Auto353[_Context->language],strlen(_Context->msg_Auto353[_Context->language]),32);
				}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			database_main_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=14;
			database_main_menu_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  _Context->x_Auto339 )
				|| ( visual_event(6) < _Context->y_Auto339  )
				|| ( visual_event(7) > (_Context->x_Auto339+_Context->w_Auto339))
				|| ( visual_event(6) >  (_Context->y_Auto339+_Context->h_Auto339))) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=database_main_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* DefaultOption */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_DefaultOption=visual_trigger_code(_Context->msg_DefaultOption[_Context->language],strlen(_Context->msg_DefaultOption[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+16,296,20,GetWidgetStyle(3),_Context->msg_DefaultOption[_Context->language],strlen(_Context->msg_DefaultOption[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto339+16,_Context->y_Auto339+16,296,20,vfh[2],16,0,_Context->msg_DefaultOption[_Context->language],strlen(_Context->msg_DefaultOption[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_DefaultOption=visual_trigger_code(_Context->msg_DefaultOption[_Context->language],strlen(_Context->msg_DefaultOption[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+16,296,20,GetWidgetStyle(2),_Context->msg_DefaultOption[_Context->language],strlen(_Context->msg_DefaultOption[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+16,296,20,vfh[2],16,0,_Context->msg_DefaultOption[_Context->language],strlen(_Context->msg_DefaultOption[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_DefaultOption_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* previous */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_previous=visual_trigger_code(_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+36,296,20,GetWidgetStyle(3),_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto339+16,_Context->y_Auto339+36,296,20,vfh[2],16,0,_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_previous=visual_trigger_code(_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+36,296,20,GetWidgetStyle(2),_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+36,296,20,vfh[2],16,0,_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_previous_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto340 */
					if (visual_event(1) & _MIMO_DOWN) {
						if ((_Context->p_Auto340 != (void *) 0)
						&& (_Context->s_Auto340 == 0)) {
							(void)visual_buffer_get(_Context->p_Auto340,_Context->x_Auto339+16,_Context->y_Auto339+56);
							_Context->s_Auto340=1;
							}
						_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+56,296,20,GetWidgetStyle(3),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto339+16,_Context->y_Auto339+56,296,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						if ((_Context->p_Auto340 != (void *) 0)
						&& (_Context->s_Auto340 == 0)) {
							(void)visual_buffer_get(_Context->p_Auto340,_Context->x_Auto339+16,_Context->y_Auto339+56);
							_Context->s_Auto340=1;
							}
						_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+56,296,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+56,296,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x130 ) {
					if ((_Context->keycode = on_Auto340_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto341 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+76,304,20,GetWidgetStyle(3),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto339+16,_Context->y_Auto339+76,304,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+76,304,20,GetWidgetStyle(2),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+76,304,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto341_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto343 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+116,304,20,GetWidgetStyle(3),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto339+16,_Context->y_Auto339+116,304,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+116,304,20,GetWidgetStyle(2),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+116,304,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto343_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Auto344 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+136,296,20,GetWidgetStyle(3),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto339+16,_Context->y_Auto339+136,296,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+136,296,20,GetWidgetStyle(2),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+136,296,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto344_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* Auto345 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto345=visual_trigger_code(_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+156,296,20,GetWidgetStyle(3),_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto339+16,_Context->y_Auto339+156,296,20,vfh[2],16,0,_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto345=visual_trigger_code(_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+156,296,20,GetWidgetStyle(2),_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+156,296,20,vfh[2],16,0,_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto345_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Auto346 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto346=visual_trigger_code(_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+176,296,20,GetWidgetStyle(3),_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto339+16,_Context->y_Auto339+176,296,20,vfh[2],16,0,_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto346=visual_trigger_code(_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+176,296,20,GetWidgetStyle(2),_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+176,296,20,vfh[2],16,0,_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto346_event(_Context)) != -1) break;

						}
					continue;
				case	0x9 :
					/* Auto348 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto348=visual_trigger_code(_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+216,296,20,GetWidgetStyle(3),_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto339+16,_Context->y_Auto339+216,296,20,vfh[2],16,0,_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto348=visual_trigger_code(_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+216,296,20,GetWidgetStyle(2),_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+216,296,20,vfh[2],16,0,_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto348_event(_Context)) != -1) break;

						}
					continue;
				case	0xa :
					/* Auto349 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto349=visual_trigger_code(_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+240,296,20,GetWidgetStyle(3),_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto339+16,_Context->y_Auto339+240,296,20,vfh[2],16,0,_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto349=visual_trigger_code(_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+240,296,20,GetWidgetStyle(2),_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+240,296,20,vfh[2],16,0,_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto349_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* Auto350 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto350=visual_trigger_code(_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+264,296,20,GetWidgetStyle(3),_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto339+16,_Context->y_Auto339+264,296,20,vfh[2],16,0,_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto350=visual_trigger_code(_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+264,296,20,GetWidgetStyle(2),_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+264,296,20,vfh[2],16,0,_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto350_event(_Context)) != -1) break;

						}
					continue;
				case	0xc :
					/* Auto351 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto351=visual_trigger_code(_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+288,296,20,GetWidgetStyle(3),_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto339+16,_Context->y_Auto339+288,296,20,vfh[2],16,0,_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto351=visual_trigger_code(_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+288,296,20,GetWidgetStyle(2),_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+288,296,20,vfh[2],16,0,_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto351_event(_Context)) != -1) break;

						}
					continue;
				case	0xd :
					/* Auto352 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto352=visual_trigger_code(_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+308,296,20,GetWidgetStyle(3),_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto339+16,_Context->y_Auto339+308,296,20,vfh[2],16,0,_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto352=visual_trigger_code(_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+308,296,20,GetWidgetStyle(2),_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+308,296,20,vfh[2],16,0,_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto352_event(_Context)) != -1) break;

						}
					continue;
				case	0xe :
					/* Auto353 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto353=visual_trigger_code(_Context->msg_Auto353[_Context->language],strlen(_Context->msg_Auto353[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+328,296,20,GetWidgetStyle(3),_Context->msg_Auto353[_Context->language],strlen(_Context->msg_Auto353[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto339+16,_Context->y_Auto339+328,296,20,vfh[2],16,0,_Context->msg_Auto353[_Context->language],strlen(_Context->msg_Auto353[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto353=visual_trigger_code(_Context->msg_Auto353[_Context->language],strlen(_Context->msg_Auto353[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+328,296,20,GetWidgetStyle(2),_Context->msg_Auto353[_Context->language],strlen(_Context->msg_Auto353[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+328,296,20,vfh[2],16,0,_Context->msg_Auto353[_Context->language],strlen(_Context->msg_Auto353[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto353_event(_Context)) != -1) break;

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
		case	0x0 :
			
			continue;
		case	0xffffffff :
			
			continue;

			}
		break;
		}

	return( _Context->keycode );
}

public	int	database_main_menu()
{
	int	status=0;
	struct database_main_menu_context * _Context=(struct database_main_menu_context*) 0;
	status = database_main_menu_create(&_Context);
	if ( status != 0) return(status);
	status = database_main_menu_show(_Context);
		enter_modal();
	status = database_main_menu_focus(_Context);
		leave_modal();
	status = database_main_menu_hide(_Context);
	status = database_main_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _basemenu_c */
