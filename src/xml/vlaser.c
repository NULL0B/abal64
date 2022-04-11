
#ifndef _vlaser_c
#define _vlaser_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vlaser.xml                                               */
/* Target         : vlaser.c                                                 */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en__Auto3644   ""
#define fr__Auto3644   ""
#define it__Auto3644   ""
#define es__Auto3644   ""
#define de__Auto3644   ""
#define nl__Auto3644   ""
#define pt__Auto3644   ""
#define xx__Auto3644   ""
#define en_Auto3645   "LASeR   and   SVG     Source     Production     Parameters"
#define fr_Auto3645   "LASeR   and   SVG     Source     Production     Parameters"
#define it_Auto3645   "LASeR   and   SVG     Source     Production     Parameters"
#define es_Auto3645   "LASeR   and   SVG     Source     Production     Parameters"
#define de_Auto3645   "LASeR   and   SVG     Source     Production     Parameters"
#define nl_Auto3645   "LASeR   and   SVG     Source     Production     Parameters"
#define pt_Auto3645   "LASeR   and   SVG     Source     Production     Parameters"
#define xx_Auto3645   "LASeR   and   SVG     Source     Production     Parameters"
#define en__Auto3645   ""
#define fr__Auto3645   ""
#define it__Auto3645   ""
#define es__Auto3645   ""
#define de__Auto3645   ""
#define nl__Auto3645   ""
#define pt__Auto3645   ""
#define xx__Auto3645   ""
#define en__Auto3646   ""
#define en__Auto3647   ""
#define en_Auto3648   "LASeR : Source file name stub"
#define fr_Auto3648   "LASeR : Source file name stub"
#define it_Auto3648   "LASeR : Source file name stub"
#define es_Auto3648   "LASeR : Source file name stub"
#define de_Auto3648   "LASeR : Source file name stub"
#define nl_Auto3648   "LASeR : Source file name stub"
#define pt_Auto3648   "LASeR : Source file name stub"
#define xx_Auto3648   "LASeR : Source file name stub"
#define en__Auto3648   ""
#define fr__Auto3648   ""
#define it__Auto3648   ""
#define es__Auto3648   ""
#define de__Auto3648   ""
#define nl__Auto3648   ""
#define pt__Auto3648   ""
#define xx__Auto3648   ""
#define en_Auto3649   "LASeR : Component Identification"
#define fr_Auto3649   "LASeR : Component Identification"
#define it_Auto3649   "LASeR : Component Identification"
#define es_Auto3649   "LASeR : Component Identification"
#define de_Auto3649   "LASeR : Component Identification"
#define nl_Auto3649   "LASeR : Component Identification"
#define pt_Auto3649   "LASeR : Component Identification"
#define xx_Auto3649   "LASeR : Component Identification"
#define en__Auto3649   ""
#define fr__Auto3649   ""
#define it__Auto3649   ""
#define es__Auto3649   ""
#define de__Auto3649   ""
#define nl__Auto3649   ""
#define pt__Auto3649   ""
#define xx__Auto3649   ""
#define en_Auto3650   "SAF : Name Space Definition"
#define fr_Auto3650   "SAF : Name Space Definition"
#define it_Auto3650   "SAF : Name Space Definition"
#define es_Auto3650   "SAF : Name Space Definition"
#define de_Auto3650   "SAF : Name Space Definition"
#define nl_Auto3650   "SAF : Name Space Definition"
#define pt_Auto3650   "SAF : Name Space Definition"
#define xx_Auto3650   "SAF : Name Space Definition"
#define en__Auto3650   ""
#define fr__Auto3650   ""
#define it__Auto3650   ""
#define es__Auto3650   ""
#define de__Auto3650   ""
#define nl__Auto3650   ""
#define pt__Auto3650   ""
#define xx__Auto3650   ""
#define en_Auto3651   "Server Url"
#define fr_Auto3651   "Server Url"
#define it_Auto3651   "Server Url"
#define es_Auto3651   "Server Url"
#define de_Auto3651   "Server Url"
#define nl_Auto3651   "Server Url"
#define pt_Auto3651   "Server Url"
#define xx_Auto3651   "Server Url"
#define en__Auto3651   ""
#define fr__Auto3651   ""
#define it__Auto3651   ""
#define es__Auto3651   ""
#define de__Auto3651   ""
#define nl__Auto3651   ""
#define pt__Auto3651   ""
#define xx__Auto3651   ""
#define en_Auto3652   "LASeR : Name Space Definition"
#define fr_Auto3652   "LASeR : Name Space Definition"
#define it_Auto3652   "LASeR : Name Space Definition"
#define es_Auto3652   "LASeR : Name Space Definition"
#define de_Auto3652   "LASeR : Name Space Definition"
#define nl_Auto3652   "LASeR : Name Space Definition"
#define pt_Auto3652   "LASeR : Name Space Definition"
#define xx_Auto3652   "LASeR : Name Space Definition"
#define en__Auto3652   ""
#define fr__Auto3652   ""
#define it__Auto3652   ""
#define es__Auto3652   ""
#define de__Auto3652   ""
#define nl__Auto3652   ""
#define pt__Auto3652   ""
#define xx__Auto3652   ""
#define en_Auto3653   "SVG : Name Space Definition"
#define fr_Auto3653   "SVG : Name Space Definition"
#define it_Auto3653   "SVG : Name Space Definition"
#define es_Auto3653   "SVG : Name Space Definition"
#define de_Auto3653   "SVG : Name Space Definition"
#define nl_Auto3653   "SVG : Name Space Definition"
#define pt_Auto3653   "SVG : Name Space Definition"
#define xx_Auto3653   "SVG : Name Space Definition"
#define en__Auto3653   ""
#define fr__Auto3653   ""
#define it__Auto3653   ""
#define es__Auto3653   ""
#define de__Auto3653   ""
#define nl__Auto3653   ""
#define pt__Auto3653   ""
#define xx__Auto3653   ""
#define en_FileStub   ""
#define en__FileStub   ""
#define en_LaserId   ""
#define en__LaserId   ""
#define en_ServerUrl   ""
#define en__ServerUrl   ""
#define en_SafNs   ""
#define en__SafNs   ""
#define en_LaserNs   ""
#define en__LaserNs   ""
#define en_SvgNs   ""
#define en__SvgNs   ""
#define en_GenSaf   "Generate SAF Header Information"
#define fr_GenSaf   "Generate SAF Header Information"
#define it_GenSaf   "Generate SAF Header Information"
#define es_GenSaf   "Generate SAF Header Information"
#define de_GenSaf   "Generate SAF Header Information"
#define nl_GenSaf   "Generate SAF Header Information"
#define pt_GenSaf   "Generate SAF Header Information"
#define xx_GenSaf   "Generate SAF Header Information"
#define en__GenSaf   ""
#define fr__GenSaf   ""
#define it__GenSaf   ""
#define es__GenSaf   ""
#define de__GenSaf   ""
#define nl__GenSaf   ""
#define pt__GenSaf   ""
#define xx__GenSaf   ""
#define en_GenLaser   "Generate LASeR Instructions"
#define fr_GenLaser   "Generate LASeR Instructions"
#define it_GenLaser   "Generate LASeR Instructions"
#define es_GenLaser   "Generate LASeR Instructions"
#define de_GenLaser   "Generate LASeR Instructions"
#define nl_GenLaser   "Generate LASeR Instructions"
#define pt_GenLaser   "Generate LASeR Instructions"
#define xx_GenLaser   "Generate LASeR Instructions"
#define en__GenLaser   ""
#define fr__GenLaser   ""
#define it__GenLaser   ""
#define es__GenLaser   ""
#define de__GenLaser   ""
#define nl__GenLaser   ""
#define pt__GenLaser   ""
#define xx__GenLaser   ""
#define en_GenComment   "Debug and Trace Information"
#define fr_GenComment   "Debug and Trace Information"
#define it_GenComment   "Debug and Trace Information"
#define es_GenComment   "Debug and Trace Information"
#define de_GenComment   "Debug and Trace Information"
#define nl_GenComment   "Debug and Trace Information"
#define pt_GenComment   "Debug and Trace Information"
#define xx_GenComment   "Debug and Trace Information"
#define en__GenComment   ""
#define fr__GenComment   ""
#define it__GenComment   ""
#define es__GenComment   ""
#define de__GenComment   ""
#define nl__GenComment   ""
#define pt__GenComment   ""
#define xx__GenComment   ""
#define en_GenTestData   "Generate Test Data in Edit Fields"
#define fr_GenTestData   "Generate Test Data in Edit Fields"
#define it_GenTestData   "Generate Test Data in Edit Fields"
#define es_GenTestData   "Generate Test Data in Edit Fields"
#define de_GenTestData   "Generate Test Data in Edit Fields"
#define nl_GenTestData   "Generate Test Data in Edit Fields"
#define pt_GenTestData   "Generate Test Data in Edit Fields"
#define xx_GenTestData   "Generate Test Data in Edit Fields"
#define en__GenTestData   ""
#define fr__GenTestData   ""
#define it__GenTestData   ""
#define es__GenTestData   ""
#define de__GenTestData   ""
#define nl__GenTestData   ""
#define pt__GenTestData   ""
#define xx__GenTestData   ""
#define en_GenMP4   "Generate MP4"
#define fr_GenMP4   "Generate MP4"
#define it_GenMP4   "Generate MP4"
#define es_GenMP4   "Generate MP4"
#define de_GenMP4   "Generate MP4"
#define nl_GenMP4   "Generate MP4"
#define pt_GenMP4   "Generate MP4"
#define xx_GenMP4   "Generate MP4"
#define en__GenMP4   ""
#define fr__GenMP4   ""
#define it__GenMP4   ""
#define es__GenMP4   ""
#define de__GenMP4   ""
#define nl__GenMP4   ""
#define pt__GenMP4   ""
#define xx__GenMP4   ""
#define en_methodText   "Method Text"
#define fr_methodText   "Method Text"
#define it_methodText   "Method Text"
#define es_methodText   "Method Text"
#define de_methodText   "Method Text"
#define nl_methodText   "Method Text"
#define pt_methodText   "Method Text"
#define xx_methodText   "Method Text"
#define en__methodText   ""
#define fr__methodText   ""
#define it__methodText   ""
#define es__methodText   ""
#define de__methodText   ""
#define nl__methodText   ""
#define pt__methodText   ""
#define xx__methodText   ""
#define en_soapInterfcae   "Soap Interface"
#define fr_soapInterfcae   "Soap Interface"
#define it_soapInterfcae   "Soap Interface"
#define es_soapInterfcae   "Soap Interface"
#define de_soapInterfcae   "Soap Interface"
#define nl_soapInterfcae   "Soap Interface"
#define pt_soapInterfcae   "Soap Interface"
#define xx_soapInterfcae   "Soap Interface"
#define en__soapInterfcae   ""
#define fr__soapInterfcae   ""
#define it__soapInterfcae   ""
#define es__soapInterfcae   ""
#define de__soapInterfcae   ""
#define nl__soapInterfcae   ""
#define pt__soapInterfcae   ""
#define xx__soapInterfcae   ""
#define en_serverCommand   "Server Command"
#define fr_serverCommand   "Server Command"
#define it_serverCommand   "Server Command"
#define es_serverCommand   "Server Command"
#define de_serverCommand   "Server Command"
#define nl_serverCommand   "Server Command"
#define pt_serverCommand   "Server Command"
#define xx_serverCommand   "Server Command"
#define en__serverCommand   ""
#define fr__serverCommand   ""
#define it__serverCommand   ""
#define es__serverCommand   ""
#define de__serverCommand   ""
#define nl__serverCommand   ""
#define pt__serverCommand   ""
#define xx__serverCommand   ""
#define en_serverPhp   "Server Php"
#define fr_serverPhp   "Server Php"
#define it_serverPhp   "Server Php"
#define es_serverPhp   "Server Php"
#define de_serverPhp   "Server Php"
#define nl_serverPhp   "Server Php"
#define pt_serverPhp   "Server Php"
#define xx_serverPhp   "Server Php"
#define en__serverPhp   ""
#define fr__serverPhp   ""
#define it__serverPhp   ""
#define es__serverPhp   ""
#define de__serverPhp   ""
#define nl__serverPhp   ""
#define pt__serverPhp   ""
#define xx__serverPhp   ""
#define en_serverAbal   "Server Abal"
#define fr_serverAbal   "Server Abal"
#define it_serverAbal   "Server Abal"
#define es_serverAbal   "Server Abal"
#define de_serverAbal   "Server Abal"
#define nl_serverAbal   "Server Abal"
#define pt_serverAbal   "Server Abal"
#define xx_serverAbal   "Server Abal"
#define en__serverAbal   ""
#define fr__serverAbal   ""
#define it__serverAbal   ""
#define es__serverAbal   ""
#define de__serverAbal   ""
#define nl__serverAbal   ""
#define pt__serverAbal   ""
#define xx__serverAbal   ""
#define en_widgetPackaging   "Widget Packaging"
#define fr_widgetPackaging   "Widget Packaging"
#define it_widgetPackaging   "Widget Packaging"
#define es_widgetPackaging   "Widget Packaging"
#define de_widgetPackaging   "Widget Packaging"
#define nl_widgetPackaging   "Widget Packaging"
#define pt_widgetPackaging   "Widget Packaging"
#define xx_widgetPackaging   "Widget Packaging"
#define en__widgetPackaging   ""
#define fr__widgetPackaging   ""
#define it__widgetPackaging   ""
#define es__widgetPackaging   ""
#define de__widgetPackaging   ""
#define nl__widgetPackaging   ""
#define pt__widgetPackaging   ""
#define xx__widgetPackaging   ""
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

private struct laser_production_parameters_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3644[8];
	char * hint_Auto3644[8];
	int	x_Auto3644;
	int	y_Auto3644;
	int	w_Auto3644;
	int	h_Auto3644;
	char * msg_Auto3645[8];
	char * hint_Auto3645[8];
	char * hint_Auto3646[8];
	char * hint_Auto3647[8];
	char * msg_Auto3648[8];
	char * hint_Auto3648[8];
	char * msg_Auto3649[8];
	char * hint_Auto3649[8];
	char * msg_Auto3650[8];
	char * hint_Auto3650[8];
	char * msg_Auto3651[8];
	char * hint_Auto3651[8];
	char * msg_Auto3652[8];
	char * hint_Auto3652[8];
	char * msg_Auto3653[8];
	char * hint_Auto3653[8];
	char * hint_FileStub[8];
	char	buffer_FileStub[256];
	char * hint_LaserId[8];
	char	buffer_LaserId[256];
	char * hint_ServerUrl[8];
	char	buffer_ServerUrl[256];
	char * hint_SafNs[8];
	char	buffer_SafNs[256];
	char * hint_LaserNs[8];
	char	buffer_LaserNs[256];
	char * hint_SvgNs[8];
	char	buffer_SvgNs[256];
	char * msg_GenSaf[8];
	int	trigger_GenSaf;
	char * hint_GenSaf[8];
	int	value_GenSaf;
	char * msg_GenLaser[8];
	int	trigger_GenLaser;
	char * hint_GenLaser[8];
	int	value_GenLaser;
	char * msg_GenComment[8];
	int	trigger_GenComment;
	char * hint_GenComment[8];
	int	value_GenComment;
	char * msg_GenTestData[8];
	int	trigger_GenTestData;
	char * hint_GenTestData[8];
	int	value_GenTestData;
	char * msg_GenMP4[8];
	int	trigger_GenMP4;
	char * hint_GenMP4[8];
	int	value_GenMP4;
	char * msg_methodText[8];
	int	trigger_methodText;
	char * hint_methodText[8];
	int	value_methodText;
	char * msg_soapInterfcae[8];
	int	trigger_soapInterfcae;
	char * hint_soapInterfcae[8];
	int	value_soapInterfcae;
	char * msg_serverCommand[8];
	int	trigger_serverCommand;
	char * hint_serverCommand[8];
	int	value_serverCommand;
	char * msg_serverPhp[8];
	int	trigger_serverPhp;
	char * hint_serverPhp[8];
	int	value_serverPhp;
	char * msg_serverAbal[8];
	int	trigger_serverAbal;
	char * hint_serverAbal[8];
	int	value_serverAbal;
	char * msg_widgetPackaging[8];
	int	trigger_widgetPackaging;
	char * hint_widgetPackaging[8];
	int	value_widgetPackaging;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[18];
	};
static int	vfh[16];
private int on_Accept_event(struct laser_production_parameters_context * _Context);
private int on_Cancel_event(struct laser_production_parameters_context * _Context);

public	int	laser_production_parameters_create(
	struct laser_production_parameters_context ** cptr,
	char * pFileStub,
	char * pLaserId,
	char * pServerUrl,
	char * pSafNs,
	char * pLaserNs,
	char * pSvgNs,
	char * pGenSaf,
	char * pGenLaser,
	char * pGenComment,
	char * pGenTestData,
	char * pGenMP4,
	char * pmethodText,
	char * psoapInterfcae,
	char * pserverCommand,
	char * pserverPhp,
	char * pserverAbal,
	char * pwidgetPackaging)
{

	int i;
	struct laser_production_parameters_context * _Context=(struct laser_production_parameters_context*)0;
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
	if (!(_Context = allocate( sizeof( struct laser_production_parameters_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=20;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSWWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileStub, 255, pFileStub);
		visual_transferin(_Context->buffer_LaserId, 255, pLaserId);
		visual_transferin(_Context->buffer_ServerUrl, 255, pServerUrl);
		visual_transferin(_Context->buffer_SafNs, 255, pSafNs);
		visual_transferin(_Context->buffer_LaserNs, 255, pLaserNs);
		visual_transferin(_Context->buffer_SvgNs, 255, pSvgNs);
		visual_transferin((void *) 0, 0, pGenSaf);
		if (!( pGenSaf )) _Context->value_GenSaf=0;
		else	_Context->value_GenSaf = *((int *)pGenSaf);
		visual_transferin((void *) 0, 0, pGenLaser);
		if (!( pGenLaser )) _Context->value_GenLaser=0;
		else	_Context->value_GenLaser = *((int *)pGenLaser);
		visual_transferin((void *) 0, 0, pGenComment);
		if (!( pGenComment )) _Context->value_GenComment=0;
		else	_Context->value_GenComment = *((int *)pGenComment);
		visual_transferin((void *) 0, 0, pGenTestData);
		if (!( pGenTestData )) _Context->value_GenTestData=0;
		else	_Context->value_GenTestData = *((int *)pGenTestData);
		visual_transferin((void *) 0, 0, pGenMP4);
		if (!( pGenMP4 )) _Context->value_GenMP4=0;
		else	_Context->value_GenMP4 = *((int *)pGenMP4);
		visual_transferin((void *) 0, 0, pmethodText);
		if (!( pmethodText )) _Context->value_methodText=0;
		else	_Context->value_methodText = *((int *)pmethodText);
		visual_transferin((void *) 0, 0, psoapInterfcae);
		if (!( psoapInterfcae )) _Context->value_soapInterfcae=0;
		else	_Context->value_soapInterfcae = *((int *)psoapInterfcae);
		visual_transferin((void *) 0, 0, pserverCommand);
		if (!( pserverCommand )) _Context->value_serverCommand=0;
		else	_Context->value_serverCommand = *((int *)pserverCommand);
		visual_transferin((void *) 0, 0, pserverPhp);
		if (!( pserverPhp )) _Context->value_serverPhp=0;
		else	_Context->value_serverPhp = *((int *)pserverPhp);
		visual_transferin((void *) 0, 0, pserverAbal);
		if (!( pserverAbal )) _Context->value_serverAbal=0;
		else	_Context->value_serverAbal = *((int *)pserverAbal);
		visual_transferin((void *) 0, 0, pwidgetPackaging);
		if (!( pwidgetPackaging )) _Context->value_widgetPackaging=0;
		else	_Context->value_widgetPackaging = *((int *)pwidgetPackaging);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3644[i]=" ";
	_Context->hint_Auto3644[0]=en__Auto3644;
	_Context->hint_Auto3644[1]=fr__Auto3644;
	_Context->hint_Auto3644[2]=it__Auto3644;
	_Context->hint_Auto3644[3]=es__Auto3644;
	_Context->hint_Auto3644[4]=de__Auto3644;
	_Context->hint_Auto3644[5]=nl__Auto3644;
	_Context->hint_Auto3644[6]=pt__Auto3644;
	_Context->hint_Auto3644[7]=xx__Auto3644;
	_Context->x_Auto3644=70;
	_Context->y_Auto3644=0;
	_Context->w_Auto3644=660;
	_Context->h_Auto3644=600;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3645[i]=" ";
	_Context->msg_Auto3645[0]=en_Auto3645;
	_Context->msg_Auto3645[1]=fr_Auto3645;
	_Context->msg_Auto3645[2]=it_Auto3645;
	_Context->msg_Auto3645[3]=es_Auto3645;
	_Context->msg_Auto3645[4]=de_Auto3645;
	_Context->msg_Auto3645[5]=nl_Auto3645;
	_Context->msg_Auto3645[6]=pt_Auto3645;
	_Context->msg_Auto3645[7]=xx_Auto3645;
	_Context->hint_Auto3645[0]=en__Auto3645;
	_Context->hint_Auto3645[1]=fr__Auto3645;
	_Context->hint_Auto3645[2]=it__Auto3645;
	_Context->hint_Auto3645[3]=es__Auto3645;
	_Context->hint_Auto3645[4]=de__Auto3645;
	_Context->hint_Auto3645[5]=nl__Auto3645;
	_Context->hint_Auto3645[6]=pt__Auto3645;
	_Context->hint_Auto3645[7]=xx__Auto3645;
	_Context->hint_Auto3646[0]=en__Auto3646;
	_Context->hint_Auto3647[0]=en__Auto3647;
	for (i=0; i < 8; i++)_Context->msg_Auto3648[i]=" ";
	_Context->msg_Auto3648[0]=en_Auto3648;
	_Context->msg_Auto3648[1]=fr_Auto3648;
	_Context->msg_Auto3648[2]=it_Auto3648;
	_Context->msg_Auto3648[3]=es_Auto3648;
	_Context->msg_Auto3648[4]=de_Auto3648;
	_Context->msg_Auto3648[5]=nl_Auto3648;
	_Context->msg_Auto3648[6]=pt_Auto3648;
	_Context->msg_Auto3648[7]=xx_Auto3648;
	_Context->hint_Auto3648[0]=en__Auto3648;
	_Context->hint_Auto3648[1]=fr__Auto3648;
	_Context->hint_Auto3648[2]=it__Auto3648;
	_Context->hint_Auto3648[3]=es__Auto3648;
	_Context->hint_Auto3648[4]=de__Auto3648;
	_Context->hint_Auto3648[5]=nl__Auto3648;
	_Context->hint_Auto3648[6]=pt__Auto3648;
	_Context->hint_Auto3648[7]=xx__Auto3648;
	for (i=0; i < 8; i++)_Context->msg_Auto3649[i]=" ";
	_Context->msg_Auto3649[0]=en_Auto3649;
	_Context->msg_Auto3649[1]=fr_Auto3649;
	_Context->msg_Auto3649[2]=it_Auto3649;
	_Context->msg_Auto3649[3]=es_Auto3649;
	_Context->msg_Auto3649[4]=de_Auto3649;
	_Context->msg_Auto3649[5]=nl_Auto3649;
	_Context->msg_Auto3649[6]=pt_Auto3649;
	_Context->msg_Auto3649[7]=xx_Auto3649;
	_Context->hint_Auto3649[0]=en__Auto3649;
	_Context->hint_Auto3649[1]=fr__Auto3649;
	_Context->hint_Auto3649[2]=it__Auto3649;
	_Context->hint_Auto3649[3]=es__Auto3649;
	_Context->hint_Auto3649[4]=de__Auto3649;
	_Context->hint_Auto3649[5]=nl__Auto3649;
	_Context->hint_Auto3649[6]=pt__Auto3649;
	_Context->hint_Auto3649[7]=xx__Auto3649;
	for (i=0; i < 8; i++)_Context->msg_Auto3650[i]=" ";
	_Context->msg_Auto3650[0]=en_Auto3650;
	_Context->msg_Auto3650[1]=fr_Auto3650;
	_Context->msg_Auto3650[2]=it_Auto3650;
	_Context->msg_Auto3650[3]=es_Auto3650;
	_Context->msg_Auto3650[4]=de_Auto3650;
	_Context->msg_Auto3650[5]=nl_Auto3650;
	_Context->msg_Auto3650[6]=pt_Auto3650;
	_Context->msg_Auto3650[7]=xx_Auto3650;
	_Context->hint_Auto3650[0]=en__Auto3650;
	_Context->hint_Auto3650[1]=fr__Auto3650;
	_Context->hint_Auto3650[2]=it__Auto3650;
	_Context->hint_Auto3650[3]=es__Auto3650;
	_Context->hint_Auto3650[4]=de__Auto3650;
	_Context->hint_Auto3650[5]=nl__Auto3650;
	_Context->hint_Auto3650[6]=pt__Auto3650;
	_Context->hint_Auto3650[7]=xx__Auto3650;
	for (i=0; i < 8; i++)_Context->msg_Auto3651[i]=" ";
	_Context->msg_Auto3651[0]=en_Auto3651;
	_Context->msg_Auto3651[1]=fr_Auto3651;
	_Context->msg_Auto3651[2]=it_Auto3651;
	_Context->msg_Auto3651[3]=es_Auto3651;
	_Context->msg_Auto3651[4]=de_Auto3651;
	_Context->msg_Auto3651[5]=nl_Auto3651;
	_Context->msg_Auto3651[6]=pt_Auto3651;
	_Context->msg_Auto3651[7]=xx_Auto3651;
	_Context->hint_Auto3651[0]=en__Auto3651;
	_Context->hint_Auto3651[1]=fr__Auto3651;
	_Context->hint_Auto3651[2]=it__Auto3651;
	_Context->hint_Auto3651[3]=es__Auto3651;
	_Context->hint_Auto3651[4]=de__Auto3651;
	_Context->hint_Auto3651[5]=nl__Auto3651;
	_Context->hint_Auto3651[6]=pt__Auto3651;
	_Context->hint_Auto3651[7]=xx__Auto3651;
	for (i=0; i < 8; i++)_Context->msg_Auto3652[i]=" ";
	_Context->msg_Auto3652[0]=en_Auto3652;
	_Context->msg_Auto3652[1]=fr_Auto3652;
	_Context->msg_Auto3652[2]=it_Auto3652;
	_Context->msg_Auto3652[3]=es_Auto3652;
	_Context->msg_Auto3652[4]=de_Auto3652;
	_Context->msg_Auto3652[5]=nl_Auto3652;
	_Context->msg_Auto3652[6]=pt_Auto3652;
	_Context->msg_Auto3652[7]=xx_Auto3652;
	_Context->hint_Auto3652[0]=en__Auto3652;
	_Context->hint_Auto3652[1]=fr__Auto3652;
	_Context->hint_Auto3652[2]=it__Auto3652;
	_Context->hint_Auto3652[3]=es__Auto3652;
	_Context->hint_Auto3652[4]=de__Auto3652;
	_Context->hint_Auto3652[5]=nl__Auto3652;
	_Context->hint_Auto3652[6]=pt__Auto3652;
	_Context->hint_Auto3652[7]=xx__Auto3652;
	for (i=0; i < 8; i++)_Context->msg_Auto3653[i]=" ";
	_Context->msg_Auto3653[0]=en_Auto3653;
	_Context->msg_Auto3653[1]=fr_Auto3653;
	_Context->msg_Auto3653[2]=it_Auto3653;
	_Context->msg_Auto3653[3]=es_Auto3653;
	_Context->msg_Auto3653[4]=de_Auto3653;
	_Context->msg_Auto3653[5]=nl_Auto3653;
	_Context->msg_Auto3653[6]=pt_Auto3653;
	_Context->msg_Auto3653[7]=xx_Auto3653;
	_Context->hint_Auto3653[0]=en__Auto3653;
	_Context->hint_Auto3653[1]=fr__Auto3653;
	_Context->hint_Auto3653[2]=it__Auto3653;
	_Context->hint_Auto3653[3]=es__Auto3653;
	_Context->hint_Auto3653[4]=de__Auto3653;
	_Context->hint_Auto3653[5]=nl__Auto3653;
	_Context->hint_Auto3653[6]=pt__Auto3653;
	_Context->hint_Auto3653[7]=xx__Auto3653;
	_Context->hint_FileStub[0]=en__FileStub;
	_Context->hint_LaserId[0]=en__LaserId;
	_Context->hint_ServerUrl[0]=en__ServerUrl;
	_Context->hint_SafNs[0]=en__SafNs;
	_Context->hint_LaserNs[0]=en__LaserNs;
	_Context->hint_SvgNs[0]=en__SvgNs;
	for (i=0; i < 8; i++)_Context->msg_GenSaf[i]=" ";
	_Context->msg_GenSaf[0]=en_GenSaf;
	_Context->msg_GenSaf[1]=fr_GenSaf;
	_Context->msg_GenSaf[2]=it_GenSaf;
	_Context->msg_GenSaf[3]=es_GenSaf;
	_Context->msg_GenSaf[4]=de_GenSaf;
	_Context->msg_GenSaf[5]=nl_GenSaf;
	_Context->msg_GenSaf[6]=pt_GenSaf;
	_Context->msg_GenSaf[7]=xx_GenSaf;
	_Context->hint_GenSaf[0]=en__GenSaf;
	_Context->hint_GenSaf[1]=fr__GenSaf;
	_Context->hint_GenSaf[2]=it__GenSaf;
	_Context->hint_GenSaf[3]=es__GenSaf;
	_Context->hint_GenSaf[4]=de__GenSaf;
	_Context->hint_GenSaf[5]=nl__GenSaf;
	_Context->hint_GenSaf[6]=pt__GenSaf;
	_Context->hint_GenSaf[7]=xx__GenSaf;
	for (i=0; i < 8; i++)_Context->msg_GenLaser[i]=" ";
	_Context->msg_GenLaser[0]=en_GenLaser;
	_Context->msg_GenLaser[1]=fr_GenLaser;
	_Context->msg_GenLaser[2]=it_GenLaser;
	_Context->msg_GenLaser[3]=es_GenLaser;
	_Context->msg_GenLaser[4]=de_GenLaser;
	_Context->msg_GenLaser[5]=nl_GenLaser;
	_Context->msg_GenLaser[6]=pt_GenLaser;
	_Context->msg_GenLaser[7]=xx_GenLaser;
	_Context->hint_GenLaser[0]=en__GenLaser;
	_Context->hint_GenLaser[1]=fr__GenLaser;
	_Context->hint_GenLaser[2]=it__GenLaser;
	_Context->hint_GenLaser[3]=es__GenLaser;
	_Context->hint_GenLaser[4]=de__GenLaser;
	_Context->hint_GenLaser[5]=nl__GenLaser;
	_Context->hint_GenLaser[6]=pt__GenLaser;
	_Context->hint_GenLaser[7]=xx__GenLaser;
	for (i=0; i < 8; i++)_Context->msg_GenComment[i]=" ";
	_Context->msg_GenComment[0]=en_GenComment;
	_Context->msg_GenComment[1]=fr_GenComment;
	_Context->msg_GenComment[2]=it_GenComment;
	_Context->msg_GenComment[3]=es_GenComment;
	_Context->msg_GenComment[4]=de_GenComment;
	_Context->msg_GenComment[5]=nl_GenComment;
	_Context->msg_GenComment[6]=pt_GenComment;
	_Context->msg_GenComment[7]=xx_GenComment;
	_Context->hint_GenComment[0]=en__GenComment;
	_Context->hint_GenComment[1]=fr__GenComment;
	_Context->hint_GenComment[2]=it__GenComment;
	_Context->hint_GenComment[3]=es__GenComment;
	_Context->hint_GenComment[4]=de__GenComment;
	_Context->hint_GenComment[5]=nl__GenComment;
	_Context->hint_GenComment[6]=pt__GenComment;
	_Context->hint_GenComment[7]=xx__GenComment;
	for (i=0; i < 8; i++)_Context->msg_GenTestData[i]=" ";
	_Context->msg_GenTestData[0]=en_GenTestData;
	_Context->msg_GenTestData[1]=fr_GenTestData;
	_Context->msg_GenTestData[2]=it_GenTestData;
	_Context->msg_GenTestData[3]=es_GenTestData;
	_Context->msg_GenTestData[4]=de_GenTestData;
	_Context->msg_GenTestData[5]=nl_GenTestData;
	_Context->msg_GenTestData[6]=pt_GenTestData;
	_Context->msg_GenTestData[7]=xx_GenTestData;
	_Context->hint_GenTestData[0]=en__GenTestData;
	_Context->hint_GenTestData[1]=fr__GenTestData;
	_Context->hint_GenTestData[2]=it__GenTestData;
	_Context->hint_GenTestData[3]=es__GenTestData;
	_Context->hint_GenTestData[4]=de__GenTestData;
	_Context->hint_GenTestData[5]=nl__GenTestData;
	_Context->hint_GenTestData[6]=pt__GenTestData;
	_Context->hint_GenTestData[7]=xx__GenTestData;
	for (i=0; i < 8; i++)_Context->msg_GenMP4[i]=" ";
	_Context->msg_GenMP4[0]=en_GenMP4;
	_Context->msg_GenMP4[1]=fr_GenMP4;
	_Context->msg_GenMP4[2]=it_GenMP4;
	_Context->msg_GenMP4[3]=es_GenMP4;
	_Context->msg_GenMP4[4]=de_GenMP4;
	_Context->msg_GenMP4[5]=nl_GenMP4;
	_Context->msg_GenMP4[6]=pt_GenMP4;
	_Context->msg_GenMP4[7]=xx_GenMP4;
	_Context->hint_GenMP4[0]=en__GenMP4;
	_Context->hint_GenMP4[1]=fr__GenMP4;
	_Context->hint_GenMP4[2]=it__GenMP4;
	_Context->hint_GenMP4[3]=es__GenMP4;
	_Context->hint_GenMP4[4]=de__GenMP4;
	_Context->hint_GenMP4[5]=nl__GenMP4;
	_Context->hint_GenMP4[6]=pt__GenMP4;
	_Context->hint_GenMP4[7]=xx__GenMP4;
	for (i=0; i < 8; i++)_Context->msg_methodText[i]=" ";
	_Context->msg_methodText[0]=en_methodText;
	_Context->msg_methodText[1]=fr_methodText;
	_Context->msg_methodText[2]=it_methodText;
	_Context->msg_methodText[3]=es_methodText;
	_Context->msg_methodText[4]=de_methodText;
	_Context->msg_methodText[5]=nl_methodText;
	_Context->msg_methodText[6]=pt_methodText;
	_Context->msg_methodText[7]=xx_methodText;
	_Context->hint_methodText[0]=en__methodText;
	_Context->hint_methodText[1]=fr__methodText;
	_Context->hint_methodText[2]=it__methodText;
	_Context->hint_methodText[3]=es__methodText;
	_Context->hint_methodText[4]=de__methodText;
	_Context->hint_methodText[5]=nl__methodText;
	_Context->hint_methodText[6]=pt__methodText;
	_Context->hint_methodText[7]=xx__methodText;
	for (i=0; i < 8; i++)_Context->msg_soapInterfcae[i]=" ";
	_Context->msg_soapInterfcae[0]=en_soapInterfcae;
	_Context->msg_soapInterfcae[1]=fr_soapInterfcae;
	_Context->msg_soapInterfcae[2]=it_soapInterfcae;
	_Context->msg_soapInterfcae[3]=es_soapInterfcae;
	_Context->msg_soapInterfcae[4]=de_soapInterfcae;
	_Context->msg_soapInterfcae[5]=nl_soapInterfcae;
	_Context->msg_soapInterfcae[6]=pt_soapInterfcae;
	_Context->msg_soapInterfcae[7]=xx_soapInterfcae;
	_Context->hint_soapInterfcae[0]=en__soapInterfcae;
	_Context->hint_soapInterfcae[1]=fr__soapInterfcae;
	_Context->hint_soapInterfcae[2]=it__soapInterfcae;
	_Context->hint_soapInterfcae[3]=es__soapInterfcae;
	_Context->hint_soapInterfcae[4]=de__soapInterfcae;
	_Context->hint_soapInterfcae[5]=nl__soapInterfcae;
	_Context->hint_soapInterfcae[6]=pt__soapInterfcae;
	_Context->hint_soapInterfcae[7]=xx__soapInterfcae;
	for (i=0; i < 8; i++)_Context->msg_serverCommand[i]=" ";
	_Context->msg_serverCommand[0]=en_serverCommand;
	_Context->msg_serverCommand[1]=fr_serverCommand;
	_Context->msg_serverCommand[2]=it_serverCommand;
	_Context->msg_serverCommand[3]=es_serverCommand;
	_Context->msg_serverCommand[4]=de_serverCommand;
	_Context->msg_serverCommand[5]=nl_serverCommand;
	_Context->msg_serverCommand[6]=pt_serverCommand;
	_Context->msg_serverCommand[7]=xx_serverCommand;
	_Context->hint_serverCommand[0]=en__serverCommand;
	_Context->hint_serverCommand[1]=fr__serverCommand;
	_Context->hint_serverCommand[2]=it__serverCommand;
	_Context->hint_serverCommand[3]=es__serverCommand;
	_Context->hint_serverCommand[4]=de__serverCommand;
	_Context->hint_serverCommand[5]=nl__serverCommand;
	_Context->hint_serverCommand[6]=pt__serverCommand;
	_Context->hint_serverCommand[7]=xx__serverCommand;
	for (i=0; i < 8; i++)_Context->msg_serverPhp[i]=" ";
	_Context->msg_serverPhp[0]=en_serverPhp;
	_Context->msg_serverPhp[1]=fr_serverPhp;
	_Context->msg_serverPhp[2]=it_serverPhp;
	_Context->msg_serverPhp[3]=es_serverPhp;
	_Context->msg_serverPhp[4]=de_serverPhp;
	_Context->msg_serverPhp[5]=nl_serverPhp;
	_Context->msg_serverPhp[6]=pt_serverPhp;
	_Context->msg_serverPhp[7]=xx_serverPhp;
	_Context->hint_serverPhp[0]=en__serverPhp;
	_Context->hint_serverPhp[1]=fr__serverPhp;
	_Context->hint_serverPhp[2]=it__serverPhp;
	_Context->hint_serverPhp[3]=es__serverPhp;
	_Context->hint_serverPhp[4]=de__serverPhp;
	_Context->hint_serverPhp[5]=nl__serverPhp;
	_Context->hint_serverPhp[6]=pt__serverPhp;
	_Context->hint_serverPhp[7]=xx__serverPhp;
	for (i=0; i < 8; i++)_Context->msg_serverAbal[i]=" ";
	_Context->msg_serverAbal[0]=en_serverAbal;
	_Context->msg_serverAbal[1]=fr_serverAbal;
	_Context->msg_serverAbal[2]=it_serverAbal;
	_Context->msg_serverAbal[3]=es_serverAbal;
	_Context->msg_serverAbal[4]=de_serverAbal;
	_Context->msg_serverAbal[5]=nl_serverAbal;
	_Context->msg_serverAbal[6]=pt_serverAbal;
	_Context->msg_serverAbal[7]=xx_serverAbal;
	_Context->hint_serverAbal[0]=en__serverAbal;
	_Context->hint_serverAbal[1]=fr__serverAbal;
	_Context->hint_serverAbal[2]=it__serverAbal;
	_Context->hint_serverAbal[3]=es__serverAbal;
	_Context->hint_serverAbal[4]=de__serverAbal;
	_Context->hint_serverAbal[5]=nl__serverAbal;
	_Context->hint_serverAbal[6]=pt__serverAbal;
	_Context->hint_serverAbal[7]=xx__serverAbal;
	for (i=0; i < 8; i++)_Context->msg_widgetPackaging[i]=" ";
	_Context->msg_widgetPackaging[0]=en_widgetPackaging;
	_Context->msg_widgetPackaging[1]=fr_widgetPackaging;
	_Context->msg_widgetPackaging[2]=it_widgetPackaging;
	_Context->msg_widgetPackaging[3]=es_widgetPackaging;
	_Context->msg_widgetPackaging[4]=de_widgetPackaging;
	_Context->msg_widgetPackaging[5]=nl_widgetPackaging;
	_Context->msg_widgetPackaging[6]=pt_widgetPackaging;
	_Context->msg_widgetPackaging[7]=xx_widgetPackaging;
	_Context->hint_widgetPackaging[0]=en__widgetPackaging;
	_Context->hint_widgetPackaging[1]=fr__widgetPackaging;
	_Context->hint_widgetPackaging[2]=it__widgetPackaging;
	_Context->hint_widgetPackaging[3]=es__widgetPackaging;
	_Context->hint_widgetPackaging[4]=de__widgetPackaging;
	_Context->hint_widgetPackaging[5]=nl__widgetPackaging;
	_Context->hint_widgetPackaging[6]=pt__widgetPackaging;
	_Context->hint_widgetPackaging[7]=xx__widgetPackaging;
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
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3644,_Context->y_Auto3644,660+10,600+10);
	return(0);
}

public 	int	laser_production_parameters_hide(struct laser_production_parameters_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3644,_Context->y_Auto3644);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	laser_production_parameters_remove(
	struct laser_production_parameters_context * _Context,
	char * pFileStub,
	char * pLaserId,
	char * pServerUrl,
	char * pSafNs,
	char * pLaserNs,
	char * pSvgNs,
	char * pGenSaf,
	char * pGenLaser,
	char * pGenComment,
	char * pGenTestData,
	char * pGenMP4,
	char * pmethodText,
	char * psoapInterfcae,
	char * pserverCommand,
	char * pserverPhp,
	char * pserverAbal,
	char * pwidgetPackaging)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSWWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileStub, 255, pFileStub);
		visual_transferout(_Context->buffer_LaserId, 255, pLaserId);
		visual_transferout(_Context->buffer_ServerUrl, 255, pServerUrl);
		visual_transferout(_Context->buffer_SafNs, 255, pSafNs);
		visual_transferout(_Context->buffer_LaserNs, 255, pLaserNs);
		visual_transferout(_Context->buffer_SvgNs, 255, pSvgNs);
		visual_transferout((void *) 0, 0, pGenSaf);
		if ( pGenSaf != (char *) 0)
			*((int*)pGenSaf) = _Context->value_GenSaf;
		visual_transferout((void *) 0, 0, pGenLaser);
		if ( pGenLaser != (char *) 0)
			*((int*)pGenLaser) = _Context->value_GenLaser;
		visual_transferout((void *) 0, 0, pGenComment);
		if ( pGenComment != (char *) 0)
			*((int*)pGenComment) = _Context->value_GenComment;
		visual_transferout((void *) 0, 0, pGenTestData);
		if ( pGenTestData != (char *) 0)
			*((int*)pGenTestData) = _Context->value_GenTestData;
		visual_transferout((void *) 0, 0, pGenMP4);
		if ( pGenMP4 != (char *) 0)
			*((int*)pGenMP4) = _Context->value_GenMP4;
		visual_transferout((void *) 0, 0, pmethodText);
		if ( pmethodText != (char *) 0)
			*((int*)pmethodText) = _Context->value_methodText;
		visual_transferout((void *) 0, 0, psoapInterfcae);
		if ( psoapInterfcae != (char *) 0)
			*((int*)psoapInterfcae) = _Context->value_soapInterfcae;
		visual_transferout((void *) 0, 0, pserverCommand);
		if ( pserverCommand != (char *) 0)
			*((int*)pserverCommand) = _Context->value_serverCommand;
		visual_transferout((void *) 0, 0, pserverPhp);
		if ( pserverPhp != (char *) 0)
			*((int*)pserverPhp) = _Context->value_serverPhp;
		visual_transferout((void *) 0, 0, pserverAbal);
		if ( pserverAbal != (char *) 0)
			*((int*)pserverAbal) = _Context->value_serverAbal;
		visual_transferout((void *) 0, 0, pwidgetPackaging);
		if ( pwidgetPackaging != (char *) 0)
			*((int*)pwidgetPackaging) = _Context->value_widgetPackaging;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	laser_production_parameters_show(struct laser_production_parameters_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3644,_Context->y_Auto3644);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3644,_Context->y_Auto3644,660,600,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3644,_Context->y_Auto3644,660,600,vfh[1],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto3644+40,_Context->y_Auto3644+30,580,30,vfh[4],47,0,_Context->msg_Auto3645[_Context->language],strlen(_Context->msg_Auto3645[_Context->language]),259);
	visual_filzone(_Context->x_Auto3644+40,_Context->y_Auto3644+60,580,460,90,16);
	visual_filzone(_Context->x_Auto3644+40,_Context->y_Auto3644+60,580,460,90,1);
	visual_text(_Context->x_Auto3644+60,_Context->y_Auto3644+80,532,16,vfh[2],16,0,_Context->msg_Auto3648[_Context->language],strlen(_Context->msg_Auto3648[_Context->language]),258);
	visual_text(_Context->x_Auto3644+60,_Context->y_Auto3644+130,532,16,vfh[2],16,0,_Context->msg_Auto3649[_Context->language],strlen(_Context->msg_Auto3649[_Context->language]),258);
	visual_text(_Context->x_Auto3644+60,_Context->y_Auto3644+360,532,16,vfh[2],16,0,_Context->msg_Auto3650[_Context->language],strlen(_Context->msg_Auto3650[_Context->language]),258);
	visual_text(_Context->x_Auto3644+60,_Context->y_Auto3644+310,532,16,vfh[2],16,0,_Context->msg_Auto3651[_Context->language],strlen(_Context->msg_Auto3651[_Context->language]),258);
	visual_text(_Context->x_Auto3644+60,_Context->y_Auto3644+410,532,16,vfh[2],16,0,_Context->msg_Auto3652[_Context->language],strlen(_Context->msg_Auto3652[_Context->language]),258);
	visual_text(_Context->x_Auto3644+60,_Context->y_Auto3644+460,532,16,vfh[2],16,0,_Context->msg_Auto3653[_Context->language],strlen(_Context->msg_Auto3653[_Context->language]),258);
	visual_frame(_Context->x_Auto3644+60,_Context->y_Auto3644+100,536+2,16+2,5);
	visual_text(_Context->x_Auto3644+60+1,_Context->y_Auto3644+100+1,536,16,vfh[1],16,0,_Context->buffer_FileStub,255,0);
	visual_frame(_Context->x_Auto3644+60,_Context->y_Auto3644+150,536+2,16+2,5);
	visual_text(_Context->x_Auto3644+60+1,_Context->y_Auto3644+150+1,536,16,vfh[1],16,0,_Context->buffer_LaserId,255,0);
	visual_frame(_Context->x_Auto3644+60,_Context->y_Auto3644+330,536+2,16+2,5);
	visual_text(_Context->x_Auto3644+60+1,_Context->y_Auto3644+330+1,536,16,vfh[1],16,0,_Context->buffer_ServerUrl,255,0);
	visual_frame(_Context->x_Auto3644+60,_Context->y_Auto3644+380,536+2,16+2,5);
	visual_text(_Context->x_Auto3644+60+1,_Context->y_Auto3644+380+1,536,16,vfh[1],16,0,_Context->buffer_SafNs,255,0);
	visual_frame(_Context->x_Auto3644+60,_Context->y_Auto3644+430,536+2,16+2,5);
	visual_text(_Context->x_Auto3644+60+1,_Context->y_Auto3644+430+1,536,16,vfh[1],16,0,_Context->buffer_LaserNs,255,0);
	visual_frame(_Context->x_Auto3644+60,_Context->y_Auto3644+480,536+2,16+2,5);
	visual_text(_Context->x_Auto3644+60+1,_Context->y_Auto3644+480+1,536,16,vfh[1],16,0,_Context->buffer_SvgNs,255,0);
	_Context->trigger_GenSaf=visual_trigger_code(_Context->msg_GenSaf[_Context->language],strlen(_Context->msg_GenSaf[_Context->language]));
	visual_check(_Context->x_Auto3644+60,_Context->y_Auto3644+180,266,16,vfh[2],16,28,_Context->msg_GenSaf[_Context->language],strlen(_Context->msg_GenSaf[_Context->language]),_Context->value_GenSaf|0);
	_Context->trigger_GenLaser=visual_trigger_code(_Context->msg_GenLaser[_Context->language],strlen(_Context->msg_GenLaser[_Context->language]));
	visual_check(_Context->x_Auto3644+330,_Context->y_Auto3644+180,266,16,vfh[2],16,28,_Context->msg_GenLaser[_Context->language],strlen(_Context->msg_GenLaser[_Context->language]),_Context->value_GenLaser|0);
	_Context->trigger_GenComment=visual_trigger_code(_Context->msg_GenComment[_Context->language],strlen(_Context->msg_GenComment[_Context->language]));
	visual_check(_Context->x_Auto3644+60,_Context->y_Auto3644+200,266,16,vfh[2],16,28,_Context->msg_GenComment[_Context->language],strlen(_Context->msg_GenComment[_Context->language]),_Context->value_GenComment|0);
	_Context->trigger_GenTestData=visual_trigger_code(_Context->msg_GenTestData[_Context->language],strlen(_Context->msg_GenTestData[_Context->language]));
	visual_check(_Context->x_Auto3644+330,_Context->y_Auto3644+200,266,16,vfh[2],16,28,_Context->msg_GenTestData[_Context->language],strlen(_Context->msg_GenTestData[_Context->language]),_Context->value_GenTestData|0);
	_Context->trigger_GenMP4=visual_trigger_code(_Context->msg_GenMP4[_Context->language],strlen(_Context->msg_GenMP4[_Context->language]));
	visual_check(_Context->x_Auto3644+60,_Context->y_Auto3644+220,266,16,vfh[2],16,28,_Context->msg_GenMP4[_Context->language],strlen(_Context->msg_GenMP4[_Context->language]),_Context->value_GenMP4|0);
	_Context->trigger_methodText=visual_trigger_code(_Context->msg_methodText[_Context->language],strlen(_Context->msg_methodText[_Context->language]));
	visual_check(_Context->x_Auto3644+330,_Context->y_Auto3644+220,266,16,vfh[2],16,28,_Context->msg_methodText[_Context->language],strlen(_Context->msg_methodText[_Context->language]),_Context->value_methodText|0);
	_Context->trigger_soapInterfcae=visual_trigger_code(_Context->msg_soapInterfcae[_Context->language],strlen(_Context->msg_soapInterfcae[_Context->language]));
	visual_check(_Context->x_Auto3644+60,_Context->y_Auto3644+240,252,16,vfh[2],16,28,_Context->msg_soapInterfcae[_Context->language],strlen(_Context->msg_soapInterfcae[_Context->language]),_Context->value_soapInterfcae|0);
	_Context->trigger_serverCommand=visual_trigger_code(_Context->msg_serverCommand[_Context->language],strlen(_Context->msg_serverCommand[_Context->language]));
	visual_check(_Context->x_Auto3644+330,_Context->y_Auto3644+240,266,16,vfh[2],16,28,_Context->msg_serverCommand[_Context->language],strlen(_Context->msg_serverCommand[_Context->language]),_Context->value_serverCommand|0);
	_Context->trigger_serverPhp=visual_trigger_code(_Context->msg_serverPhp[_Context->language],strlen(_Context->msg_serverPhp[_Context->language]));
	visual_check(_Context->x_Auto3644+60,_Context->y_Auto3644+260,266,16,vfh[2],16,28,_Context->msg_serverPhp[_Context->language],strlen(_Context->msg_serverPhp[_Context->language]),_Context->value_serverPhp|0);
	_Context->trigger_serverAbal=visual_trigger_code(_Context->msg_serverAbal[_Context->language],strlen(_Context->msg_serverAbal[_Context->language]));
	visual_check(_Context->x_Auto3644+330,_Context->y_Auto3644+260,266,16,vfh[2],16,28,_Context->msg_serverAbal[_Context->language],strlen(_Context->msg_serverAbal[_Context->language]),_Context->value_serverAbal|0);
	_Context->trigger_widgetPackaging=visual_trigger_code(_Context->msg_widgetPackaging[_Context->language],strlen(_Context->msg_widgetPackaging[_Context->language]));
	visual_check(_Context->x_Auto3644+330,_Context->y_Auto3644+280,266,16,vfh[2],16,28,_Context->msg_widgetPackaging[_Context->language],strlen(_Context->msg_widgetPackaging[_Context->language]),_Context->value_widgetPackaging|0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3644+260,_Context->y_Auto3644+530,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3644+330,_Context->y_Auto3644+530,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	visual_thaw(_Context->x_Auto3644,_Context->y_Auto3644,660,600);

	return(0);
}

private int Auto3644action(struct laser_production_parameters_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			laser_production_parameters_hide(_Context);

		_Context->x_Auto3644 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3644 < 0) { _Context->x_Auto3644=0; }
		_Context->y_Auto3644 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3644 < 0) { _Context->y_Auto3644=0; }
			laser_production_parameters_show(_Context);

		visual_thaw(_Context->x_Auto3644,_Context->y_Auto3644,660,600);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct laser_production_parameters_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct laser_production_parameters_context * _Context) {
	return(27);
	return(-1);
}


public	int	laser_production_parameters_event(
struct laser_production_parameters_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_GenSaf == mb ) return(8);
		if (_Context->trigger_GenLaser == mb ) return(9);
		if (_Context->trigger_GenComment == mb ) return(10);
		if (_Context->trigger_GenTestData == mb ) return(11);
		if (_Context->trigger_GenMP4 == mb ) return(12);
		if (_Context->trigger_methodText == mb ) return(13);
		if (_Context->trigger_soapInterfcae == mb ) return(14);
		if (_Context->trigger_serverCommand == mb ) return(15);
		if (_Context->trigger_serverPhp == mb ) return(16);
		if (_Context->trigger_serverAbal == mb ) return(17);
		if (_Context->trigger_widgetPackaging == mb ) return(18);
		if (_Context->trigger_Accept == mb ) return(19);
		if (_Context->trigger_Cancel == mb ) return(20);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3644+639) )  
	&&  (my >= (_Context->y_Auto3644+4) )  
	&&  (mx <= (_Context->x_Auto3644+656) )  
	&&  (my <= (_Context->y_Auto3644+20) )) {
		return(1);	/* Auto3644 */

		}
	if ((mx >= (_Context->x_Auto3644+623) )  
	&&  (my >= (_Context->y_Auto3644+4) )  
	&&  (mx <= (_Context->x_Auto3644+640) )  
	&&  (my <= (_Context->y_Auto3644+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vlaser.htm");
			};
		return(-1);	/* Auto3644 */

		}
	if ((mx >= (_Context->x_Auto3644+607) )  
	&&  (my >= (_Context->y_Auto3644+4) )  
	&&  (mx <= (_Context->x_Auto3644+624) )  
	&&  (my <= (_Context->y_Auto3644+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		laser_production_parameters_show(_Context);
		return(-1);	/* Auto3644 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3644+4) )  
		&&  (my >= (_Context->y_Auto3644+4) )  
		&&  (mx <= (_Context->x_Auto3644+592) )  
		&&  (my <= (_Context->y_Auto3644+20) )) {
			return( Auto3644action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3644+60) ) 
	&&  ( my >= (_Context->y_Auto3644+100) ) 
	&&  ( mx <= (_Context->x_Auto3644+60+536) ) 
	&&  ( my <= (_Context->y_Auto3644+100+16))) {
		return(2); /* FileStub */
		}
	if (( mx >= (_Context->x_Auto3644+60) ) 
	&&  ( my >= (_Context->y_Auto3644+150) ) 
	&&  ( mx <= (_Context->x_Auto3644+60+536) ) 
	&&  ( my <= (_Context->y_Auto3644+150+16))) {
		return(3); /* LaserId */
		}
	if (( mx >= (_Context->x_Auto3644+60) ) 
	&&  ( my >= (_Context->y_Auto3644+330) ) 
	&&  ( mx <= (_Context->x_Auto3644+60+536) ) 
	&&  ( my <= (_Context->y_Auto3644+330+16))) {
		return(4); /* ServerUrl */
		}
	if (( mx >= (_Context->x_Auto3644+60) ) 
	&&  ( my >= (_Context->y_Auto3644+380) ) 
	&&  ( mx <= (_Context->x_Auto3644+60+536) ) 
	&&  ( my <= (_Context->y_Auto3644+380+16))) {
		return(5); /* SafNs */
		}
	if (( mx >= (_Context->x_Auto3644+60) ) 
	&&  ( my >= (_Context->y_Auto3644+430) ) 
	&&  ( mx <= (_Context->x_Auto3644+60+536) ) 
	&&  ( my <= (_Context->y_Auto3644+430+16))) {
		return(6); /* LaserNs */
		}
	if (( mx >= (_Context->x_Auto3644+60) ) 
	&&  ( my >= (_Context->y_Auto3644+480) ) 
	&&  ( mx <= (_Context->x_Auto3644+60+536) ) 
	&&  ( my <= (_Context->y_Auto3644+480+16))) {
		return(7); /* SvgNs */
		}
	if (( mx >= (_Context->x_Auto3644+60) ) 
	&&  ( my >= (_Context->y_Auto3644+180) ) 
	&&  ( mx <= (_Context->x_Auto3644+60+266) ) 
	&&  ( my <= (_Context->y_Auto3644+180+16))) {
		return(8); /* GenSaf */
		}
	if (( mx >= (_Context->x_Auto3644+330) ) 
	&&  ( my >= (_Context->y_Auto3644+180) ) 
	&&  ( mx <= (_Context->x_Auto3644+330+266) ) 
	&&  ( my <= (_Context->y_Auto3644+180+16))) {
		return(9); /* GenLaser */
		}
	if (( mx >= (_Context->x_Auto3644+60) ) 
	&&  ( my >= (_Context->y_Auto3644+200) ) 
	&&  ( mx <= (_Context->x_Auto3644+60+266) ) 
	&&  ( my <= (_Context->y_Auto3644+200+16))) {
		return(10); /* GenComment */
		}
	if (( mx >= (_Context->x_Auto3644+330) ) 
	&&  ( my >= (_Context->y_Auto3644+200) ) 
	&&  ( mx <= (_Context->x_Auto3644+330+266) ) 
	&&  ( my <= (_Context->y_Auto3644+200+16))) {
		return(11); /* GenTestData */
		}
	if (( mx >= (_Context->x_Auto3644+60) ) 
	&&  ( my >= (_Context->y_Auto3644+220) ) 
	&&  ( mx <= (_Context->x_Auto3644+60+266) ) 
	&&  ( my <= (_Context->y_Auto3644+220+16))) {
		return(12); /* GenMP4 */
		}
	if (( mx >= (_Context->x_Auto3644+330) ) 
	&&  ( my >= (_Context->y_Auto3644+220) ) 
	&&  ( mx <= (_Context->x_Auto3644+330+266) ) 
	&&  ( my <= (_Context->y_Auto3644+220+16))) {
		return(13); /* methodText */
		}
	if (( mx >= (_Context->x_Auto3644+60) ) 
	&&  ( my >= (_Context->y_Auto3644+240) ) 
	&&  ( mx <= (_Context->x_Auto3644+60+252) ) 
	&&  ( my <= (_Context->y_Auto3644+240+16))) {
		return(14); /* soapInterfcae */
		}
	if (( mx >= (_Context->x_Auto3644+330) ) 
	&&  ( my >= (_Context->y_Auto3644+240) ) 
	&&  ( mx <= (_Context->x_Auto3644+330+266) ) 
	&&  ( my <= (_Context->y_Auto3644+240+16))) {
		return(15); /* serverCommand */
		}
	if (( mx >= (_Context->x_Auto3644+60) ) 
	&&  ( my >= (_Context->y_Auto3644+260) ) 
	&&  ( mx <= (_Context->x_Auto3644+60+266) ) 
	&&  ( my <= (_Context->y_Auto3644+260+16))) {
		return(16); /* serverPhp */
		}
	if (( mx >= (_Context->x_Auto3644+330) ) 
	&&  ( my >= (_Context->y_Auto3644+260) ) 
	&&  ( mx <= (_Context->x_Auto3644+330+266) ) 
	&&  ( my <= (_Context->y_Auto3644+260+16))) {
		return(17); /* serverAbal */
		}
	if (( mx >= (_Context->x_Auto3644+330) ) 
	&&  ( my >= (_Context->y_Auto3644+280) ) 
	&&  ( mx <= (_Context->x_Auto3644+330+266) ) 
	&&  ( my <= (_Context->y_Auto3644+280+16))) {
		return(18); /* widgetPackaging */
		}
	if (( mx >= (_Context->x_Auto3644+260) ) 
	&&  ( my >= (_Context->y_Auto3644+530) ) 
	&&  ( mx <= (_Context->x_Auto3644+260+56) ) 
	&&  ( my <= (_Context->y_Auto3644+530+48))) {
		return(19); /* Accept */
		}
	if (( mx >= (_Context->x_Auto3644+330) ) 
	&&  ( my >= (_Context->y_Auto3644+530) ) 
	&&  ( mx <= (_Context->x_Auto3644+330+56) ) 
	&&  ( my <= (_Context->y_Auto3644+530+48))) {
		return(20); /* Cancel */
		}

	return(-1);
}


public	int	laser_production_parameters_focus(struct laser_production_parameters_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FileStub */
				_Context->keycode = visual_edit(_Context->x_Auto3644+60+1,_Context->y_Auto3644+100+1,536,16,vfh[1],_Context->buffer_FileStub,255);
			break;
			case	0x3 :
				/* LaserId */
				_Context->keycode = visual_edit(_Context->x_Auto3644+60+1,_Context->y_Auto3644+150+1,536,16,vfh[1],_Context->buffer_LaserId,255);
			break;
			case	0x4 :
				/* ServerUrl */
				_Context->keycode = visual_edit(_Context->x_Auto3644+60+1,_Context->y_Auto3644+330+1,536,16,vfh[1],_Context->buffer_ServerUrl,255);
			break;
			case	0x5 :
				/* SafNs */
				_Context->keycode = visual_edit(_Context->x_Auto3644+60+1,_Context->y_Auto3644+380+1,536,16,vfh[1],_Context->buffer_SafNs,255);
			break;
			case	0x6 :
				/* LaserNs */
				_Context->keycode = visual_edit(_Context->x_Auto3644+60+1,_Context->y_Auto3644+430+1,536,16,vfh[1],_Context->buffer_LaserNs,255);
			break;
			case	0x7 :
				/* SvgNs */
				_Context->keycode = visual_edit(_Context->x_Auto3644+60+1,_Context->y_Auto3644+480+1,536,16,vfh[1],_Context->buffer_SvgNs,255);
			break;
			case	0x8 :
				/* GenSaf */
				visual_check(_Context->x_Auto3644+60,_Context->y_Auto3644+180,266,16,vfh[2],16,28,_Context->msg_GenSaf[_Context->language],strlen(_Context->msg_GenSaf[_Context->language]),(_Context->value_GenSaf |2));
				_Context->keycode = visual_getch();
				_Context->trigger_GenSaf=visual_trigger_code(_Context->msg_GenSaf[_Context->language],strlen(_Context->msg_GenSaf[_Context->language]));
	visual_check(_Context->x_Auto3644+60,_Context->y_Auto3644+180,266,16,vfh[2],16,28,_Context->msg_GenSaf[_Context->language],strlen(_Context->msg_GenSaf[_Context->language]),_Context->value_GenSaf|0);
				break;
			case	0x9 :
				/* GenLaser */
				visual_check(_Context->x_Auto3644+330,_Context->y_Auto3644+180,266,16,vfh[2],16,28,_Context->msg_GenLaser[_Context->language],strlen(_Context->msg_GenLaser[_Context->language]),(_Context->value_GenLaser |2));
				_Context->keycode = visual_getch();
				_Context->trigger_GenLaser=visual_trigger_code(_Context->msg_GenLaser[_Context->language],strlen(_Context->msg_GenLaser[_Context->language]));
	visual_check(_Context->x_Auto3644+330,_Context->y_Auto3644+180,266,16,vfh[2],16,28,_Context->msg_GenLaser[_Context->language],strlen(_Context->msg_GenLaser[_Context->language]),_Context->value_GenLaser|0);
				break;
			case	0xa :
				/* GenComment */
				visual_check(_Context->x_Auto3644+60,_Context->y_Auto3644+200,266,16,vfh[2],16,28,_Context->msg_GenComment[_Context->language],strlen(_Context->msg_GenComment[_Context->language]),(_Context->value_GenComment |2));
				_Context->keycode = visual_getch();
				_Context->trigger_GenComment=visual_trigger_code(_Context->msg_GenComment[_Context->language],strlen(_Context->msg_GenComment[_Context->language]));
	visual_check(_Context->x_Auto3644+60,_Context->y_Auto3644+200,266,16,vfh[2],16,28,_Context->msg_GenComment[_Context->language],strlen(_Context->msg_GenComment[_Context->language]),_Context->value_GenComment|0);
				break;
			case	0xb :
				/* GenTestData */
				visual_check(_Context->x_Auto3644+330,_Context->y_Auto3644+200,266,16,vfh[2],16,28,_Context->msg_GenTestData[_Context->language],strlen(_Context->msg_GenTestData[_Context->language]),(_Context->value_GenTestData |2));
				_Context->keycode = visual_getch();
				_Context->trigger_GenTestData=visual_trigger_code(_Context->msg_GenTestData[_Context->language],strlen(_Context->msg_GenTestData[_Context->language]));
	visual_check(_Context->x_Auto3644+330,_Context->y_Auto3644+200,266,16,vfh[2],16,28,_Context->msg_GenTestData[_Context->language],strlen(_Context->msg_GenTestData[_Context->language]),_Context->value_GenTestData|0);
				break;
			case	0xc :
				/* GenMP4 */
				visual_check(_Context->x_Auto3644+60,_Context->y_Auto3644+220,266,16,vfh[2],16,28,_Context->msg_GenMP4[_Context->language],strlen(_Context->msg_GenMP4[_Context->language]),(_Context->value_GenMP4 |2));
				_Context->keycode = visual_getch();
				_Context->trigger_GenMP4=visual_trigger_code(_Context->msg_GenMP4[_Context->language],strlen(_Context->msg_GenMP4[_Context->language]));
	visual_check(_Context->x_Auto3644+60,_Context->y_Auto3644+220,266,16,vfh[2],16,28,_Context->msg_GenMP4[_Context->language],strlen(_Context->msg_GenMP4[_Context->language]),_Context->value_GenMP4|0);
				break;
			case	0xd :
				/* methodText */
				visual_check(_Context->x_Auto3644+330,_Context->y_Auto3644+220,266,16,vfh[2],16,28,_Context->msg_methodText[_Context->language],strlen(_Context->msg_methodText[_Context->language]),(_Context->value_methodText |2));
				_Context->keycode = visual_getch();
				_Context->trigger_methodText=visual_trigger_code(_Context->msg_methodText[_Context->language],strlen(_Context->msg_methodText[_Context->language]));
	visual_check(_Context->x_Auto3644+330,_Context->y_Auto3644+220,266,16,vfh[2],16,28,_Context->msg_methodText[_Context->language],strlen(_Context->msg_methodText[_Context->language]),_Context->value_methodText|0);
				break;
			case	0xe :
				/* soapInterfcae */
				visual_check(_Context->x_Auto3644+60,_Context->y_Auto3644+240,252,16,vfh[2],16,28,_Context->msg_soapInterfcae[_Context->language],strlen(_Context->msg_soapInterfcae[_Context->language]),(_Context->value_soapInterfcae |2));
				_Context->keycode = visual_getch();
				_Context->trigger_soapInterfcae=visual_trigger_code(_Context->msg_soapInterfcae[_Context->language],strlen(_Context->msg_soapInterfcae[_Context->language]));
	visual_check(_Context->x_Auto3644+60,_Context->y_Auto3644+240,252,16,vfh[2],16,28,_Context->msg_soapInterfcae[_Context->language],strlen(_Context->msg_soapInterfcae[_Context->language]),_Context->value_soapInterfcae|0);
				break;
			case	0xf :
				/* serverCommand */
				visual_check(_Context->x_Auto3644+330,_Context->y_Auto3644+240,266,16,vfh[2],16,28,_Context->msg_serverCommand[_Context->language],strlen(_Context->msg_serverCommand[_Context->language]),(_Context->value_serverCommand |2));
				_Context->keycode = visual_getch();
				_Context->trigger_serverCommand=visual_trigger_code(_Context->msg_serverCommand[_Context->language],strlen(_Context->msg_serverCommand[_Context->language]));
	visual_check(_Context->x_Auto3644+330,_Context->y_Auto3644+240,266,16,vfh[2],16,28,_Context->msg_serverCommand[_Context->language],strlen(_Context->msg_serverCommand[_Context->language]),_Context->value_serverCommand|0);
				break;
			case	0x10 :
				/* serverPhp */
				visual_check(_Context->x_Auto3644+60,_Context->y_Auto3644+260,266,16,vfh[2],16,28,_Context->msg_serverPhp[_Context->language],strlen(_Context->msg_serverPhp[_Context->language]),(_Context->value_serverPhp |2));
				_Context->keycode = visual_getch();
				_Context->trigger_serverPhp=visual_trigger_code(_Context->msg_serverPhp[_Context->language],strlen(_Context->msg_serverPhp[_Context->language]));
	visual_check(_Context->x_Auto3644+60,_Context->y_Auto3644+260,266,16,vfh[2],16,28,_Context->msg_serverPhp[_Context->language],strlen(_Context->msg_serverPhp[_Context->language]),_Context->value_serverPhp|0);
				break;
			case	0x11 :
				/* serverAbal */
				visual_check(_Context->x_Auto3644+330,_Context->y_Auto3644+260,266,16,vfh[2],16,28,_Context->msg_serverAbal[_Context->language],strlen(_Context->msg_serverAbal[_Context->language]),(_Context->value_serverAbal |2));
				_Context->keycode = visual_getch();
				_Context->trigger_serverAbal=visual_trigger_code(_Context->msg_serverAbal[_Context->language],strlen(_Context->msg_serverAbal[_Context->language]));
	visual_check(_Context->x_Auto3644+330,_Context->y_Auto3644+260,266,16,vfh[2],16,28,_Context->msg_serverAbal[_Context->language],strlen(_Context->msg_serverAbal[_Context->language]),_Context->value_serverAbal|0);
				break;
			case	0x12 :
				/* widgetPackaging */
				visual_check(_Context->x_Auto3644+330,_Context->y_Auto3644+280,266,16,vfh[2],16,28,_Context->msg_widgetPackaging[_Context->language],strlen(_Context->msg_widgetPackaging[_Context->language]),(_Context->value_widgetPackaging |2));
				_Context->keycode = visual_getch();
				_Context->trigger_widgetPackaging=visual_trigger_code(_Context->msg_widgetPackaging[_Context->language],strlen(_Context->msg_widgetPackaging[_Context->language]));
	visual_check(_Context->x_Auto3644+330,_Context->y_Auto3644+280,266,16,vfh[2],16,28,_Context->msg_widgetPackaging[_Context->language],strlen(_Context->msg_widgetPackaging[_Context->language]),_Context->value_widgetPackaging|0);
				break;
			case	0x13 :
				/* Accept */
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
				visual_button(_Context->x_Auto3644+260,_Context->y_Auto3644+530,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3644+260,_Context->y_Auto3644+530,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
				break;
			case	0x14 :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(_Context->x_Auto3644+330,_Context->y_Auto3644+530,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3644+330,_Context->y_Auto3644+530,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			laser_production_parameters_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=20;
			laser_production_parameters_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=laser_production_parameters_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3644 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* FileStub */
					continue;
				case	0x3 :
					/* LaserId */
					continue;
				case	0x4 :
					/* ServerUrl */
					continue;
				case	0x5 :
					/* SafNs */
					continue;
				case	0x6 :
					/* LaserNs */
					continue;
				case	0x7 :
					/* SvgNs */
					continue;
				case	0x8 :
					/* GenSaf */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_GenSaf += 1;
						_Context->value_GenSaf &= 1;
						}
					continue;
				case	0x9 :
					/* GenLaser */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_GenLaser += 1;
						_Context->value_GenLaser &= 1;
						}
					continue;
				case	0xa :
					/* GenComment */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_GenComment += 1;
						_Context->value_GenComment &= 1;
						}
					continue;
				case	0xb :
					/* GenTestData */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_GenTestData += 1;
						_Context->value_GenTestData &= 1;
						}
					continue;
				case	0xc :
					/* GenMP4 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_GenMP4 += 1;
						_Context->value_GenMP4 &= 1;
						}
					continue;
				case	0xd :
					/* methodText */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_methodText += 1;
						_Context->value_methodText &= 1;
						}
					continue;
				case	0xe :
					/* soapInterfcae */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_soapInterfcae += 1;
						_Context->value_soapInterfcae &= 1;
						}
					continue;
				case	0xf :
					/* serverCommand */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_serverCommand += 1;
						_Context->value_serverCommand &= 1;
						}
					continue;
				case	0x10 :
					/* serverPhp */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_serverPhp += 1;
						_Context->value_serverPhp &= 1;
						}
					continue;
				case	0x11 :
					/* serverAbal */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_serverAbal += 1;
						_Context->value_serverAbal &= 1;
						}
					continue;
				case	0x12 :
					/* widgetPackaging */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_widgetPackaging += 1;
						_Context->value_widgetPackaging &= 1;
						}
					continue;
				case	0x13 :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(_Context->x_Auto3644+260,_Context->y_Auto3644+530,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3644+260,_Context->y_Auto3644+530,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0x14 :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(_Context->x_Auto3644+330,_Context->y_Auto3644+530,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3644+330,_Context->y_Auto3644+530,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
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

public	int	laser_production_parameters(
	char * pFileStub,
	char * pLaserId,
	char * pServerUrl,
	char * pSafNs,
	char * pLaserNs,
	char * pSvgNs,
	char * pGenSaf,
	char * pGenLaser,
	char * pGenComment,
	char * pGenTestData,
	char * pGenMP4,
	char * pmethodText,
	char * psoapInterfcae,
	char * pserverCommand,
	char * pserverPhp,
	char * pserverAbal,
	char * pwidgetPackaging)
{
	int	status=0;
	struct laser_production_parameters_context * _Context=(struct laser_production_parameters_context*) 0;
	status = laser_production_parameters_create(
	&_Context,
	 pFileStub,
	 pLaserId,
	 pServerUrl,
	 pSafNs,
	 pLaserNs,
	 pSvgNs,
	 pGenSaf,
	 pGenLaser,
	 pGenComment,
	 pGenTestData,
	 pGenMP4,
	 pmethodText,
	 psoapInterfcae,
	 pserverCommand,
	 pserverPhp,
	 pserverAbal,
	 pwidgetPackaging);
	if ( status != 0) return(status);
	status = laser_production_parameters_show(_Context);
		enter_modal();
	status = laser_production_parameters_focus(_Context);
		leave_modal();
	status = laser_production_parameters_hide(_Context);
	status = laser_production_parameters_remove(
	_Context,
	 pFileStub,
	 pLaserId,
	 pServerUrl,
	 pSafNs,
	 pLaserNs,
	 pSvgNs,
	 pGenSaf,
	 pGenLaser,
	 pGenComment,
	 pGenTestData,
	 pGenMP4,
	 pmethodText,
	 psoapInterfcae,
	 pserverCommand,
	 pserverPhp,
	 pserverAbal,
	 pwidgetPackaging);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vlaser_c */
