#ifndef	_xmlthree_c
#define	_xmlthree_c

#include <stdio.h>

#include "sing.h"
#include "palet.h"
#include "stdpsu.h"
#include "guimouse.h"
#include "singrel.h"
#include "singpix.h"
#include "allocate.h"
#include "singlang.h"
#include "singprod.h"
#include "singpage.h"
#include "singtree.h"
#include "singconf.h"
#include "singpal.h"
#include "singbar.h"
#include "singmenu.h"
#include "singtool.h"
#include "singtext.h"
#include "singimg.h"
#include "singdesk.h"
#include "visual.h"
#include "singcam.h"
#include "singfile.h"
#include "singtree.h"

#include "xmlparse.h"
#include "xmlthree.h"

#include "singprot.h"

extern	char * workbuffer;
extern 	struct	coordinate3d	Vektor;
extern 	struct	coordinate3d	DefaultSizes;
extern	int	movement;
extern	struct	application_parameters Application;
extern	struct	model_control ModelControl;
extern	struct	document_parameters Document;
extern	struct	tree_configuration TreeConf;

public 	struct camera3d * load_XmlDataBase(struct camera3d * cptr, char * loadname, int automatic );
public	int	xml_error_handler( char * nomfic, int status, int nblin );


public 	void	xml_put_Camera( struct camera3d * kptr, char * dtdname, int automatic )
{
	FILE * h;
	FILE * xh=(FILE*)0;
	int	v;
	int	i;
	char * sname=(char *) 0;
	char * xsname=(char *) 0;
	char * tagname=(char *) 0;
	struct object3d * optr;
	struct form_control * fptr;
	struct data_control * dptr;
	struct file_control * tptr;

	if ((h = open_xml_target( kptr->name, &sname, "THREED", dtdname, "threed.css" )) != (FILE*) 0) {

		fprintf(h,"<THREED>");
		linefeed(h);

		xml_put_string(h,"NAME",kptr->name,1);
		xml_put_xyz(h,"VECTOR",Vektor.x,Vektor.y,Vektor.z,1);
		xml_put_xyz(h,"SIZES",DefaultSizes.x,DefaultSizes.y,DefaultSizes.z,1);
		xml_put_xyz(h,"POSITION",kptr->position.x,kptr->position.y,kptr->position.z,1);
		xml_put_coordinate(h,"FOCUS",kptr->focus.x,kptr->focus.y,1);
		xml_put_word(h,"DIRECTION",kptr->direction,1);
		xml_put_word(h,"MOVEMENT",movement,1);
		xml_put_word(h,"TIMER",kptr->timer,1);
		xml_put_word(h,"STEP",kptr->step,1);

		if (!( palette_is_active() )) {
			kptr->options &= ~_THREED_PALETTE; /* 0x0010; */
			}
		else	{
			kptr->options |=  _THREED_PALETTE; /* 0x0010; */
			}
		if (!( toolbar_is_active() ))
			kptr->options &= ~_THREED_TOOLBAR; /* 0x0020; */
		else	kptr->options |=  _THREED_TOOLBAR; /* 0x0020; */

		if (!( treeview_is_active() ))
			kptr->options &= ~_THREED_TREEVIEW; /* 0x0040; */
		else	kptr->options |=  _THREED_TREEVIEW; /* 0x0040; */

		xml_put_word(h,"OPTION",kptr->options,1);
		xml_put_word(h,"ICONS",Application.imagetype,1);
		xml_put_string(h,"IMAGE",kptr->background->iname,1);
		xml_put_word(h,"FILL",(kptr->background->colour | (kptr->background->style << 8)),1);
		xml_put_word(h,"DOCUMENT",Application.isdocument,1);
		xml_put_string(h,"DOCNAME", Application.document,1);
		xml_put_word(h,"PRODUCTION",Application.productiontype,1);
		xml_put_string(h,"TARGET",Application.target,1);
		xml_put_word(h,"LANGUAGE",Application.language,1);
		xml_put_word(h,"PROJECT",Application.makefile,1);
		xml_put_string(h,"MAKEFILE", Application.makename,1 );
		xml_put_string(h,"CONFIGURE",kptr->configuration,1 );
		indent(h,1);
		fprintf(h,"<HTML-PRODUCTION>");
		linefeed(h);
		xml_put_string(h,"TITLE",Document.title,2);
		xml_put_string(h,"SCREEN",Document.screenstyle,2);
		xml_put_string(h,"PRINT",Document.printstyle,2);
		xml_put_string(h,"LOGO",Document.logo,2);
		xml_put_string(h,"FOOTER",Document.footer,2);
		xml_put_string(h,"PATH",Document.pathroot,2);
		xml_put_word(h,"SEPARATE",Document.separate,2);
		xml_put_word(h,"REPORT",Document.report,2);
		xml_put_word(h,"NATIONAL",Document.forcelang,2);
		xml_put_word(h,"LANGUAGE",Document.language,2);
		indent(h,1);
		fprintf(h,"</HTML-PRODUCTION>");
		linefeed(h);

		if ( Application.palettename ) {
			xml_put_string(h,"PALETTE",Application.palettename,1);
			}

		indent(h,1);
		fprintf(h,"<TREEVIEW FONT=%u ZONE=%u SPACING=%u SOURCE=%u TARGET=%u PACKAGE=%u IDENTITY=%u WIDTH=%u />",
				TreeConf.font,TreeConf.zonage,TreeConf.spacing,
				TreeConf.source,TreeConf.target,TreeConf.packaging,TreeConf.identity,TreeConf.width);
		linefeed(h);

		if ( Application.databasename ) {
			xml_put_string(h,"DATABASE",Application.databasename,1);
			xh = h;
			if ((h = open_xml_target( Application.databasename, &xsname, "DATABASE", dtdname, "database.css" )) != (FILE*) 0) {
				fprintf(h,"<BASE>");
				linefeed(h);
				}
			else	{
				h = xh;
				xh = (FILE*) 0;
				}
			}

		for ( 	tptr  = FileManager.first;
			tptr != (struct file_control *) 0;
			tptr = tptr->next ) {

			if ((!( tptr->classname ))
			&&  (!( tptr->identity  )))
				continue;
			indent(h,1);
			switch ( tptr->nature ) {
				case	_SQFILE_FRAME	: tagname = "SQFILE"; break;
				case	_DBFILE_FRAME	: tagname = "DBFILE"; break;
				case	_MCFILE_FRAME	: tagname = "MCFILE"; break;
				case	_SIFILE_FRAME	: tagname = "SIFILE"; break;
				case	_VMEMORY_FRAME	: tagname = "VMEMORY"; break;
				default			: tagname = "SIFILE"; break;
				}
			fprintf(h,"<%s",tagname);
			if ( tptr->classname ) {
				fprintf(h," CLASS=%s",tptr->classname);
				}
			if ( tptr->identity ) {
				fprintf(h," NAME=%s",
					tptr->identity);
				}
			fprintf(h,">");
			linefeed(h);
			if ( tptr->filename ) {
				indent(h,2);
				fprintf(h,"<FILE>%s</FILE>",tptr->filename);
				linefeed(h);
				}
			if (( dptr = tptr->payload ) != (struct data_control *) 0) {
				if ( dptr->indexlength != 0 ) {
					indent(h,2);
					fprintf(h,"<INDEX");
					if ( tptr->indextype ) { fprintf(h," TYPE=%s",tptr->indextype); }
					fprintf(h," SIZE=%u>",dptr->indexlength);
					if ( dptr->indexfields ) {
						linefeed(h);
						for ( i=0; i < dptr->indexfields; i++ ) {
							indent(h,3);
							fprintf(h,"<MEMBER>");
							fprintf(h,"%s",dptr->name[i]);
							switch ( dptr->type[i] ) {
								case	_ABAL_BYTE	: fprintf(h,"#");		break;
								case	_ABAL_WORD	: fprintf(h,"%c",0x0025); 	break;
								case	_ABAL_LONG	: fprintf(h,":"); 		break;
								case	_ABAL_STRING	:
									fprintf(h,"$");
								case	_ABAL_BCD	:
									fprintf(h,"=%u",dptr->width[i]);
									break;
								}
							if ((v=dptr->first[i]) != 0) {
								fprintf(h,"(%u",v);
								if ((v=dptr->second[i]) != 0)
									fprintf(h,",%u",v);
								fprintf(h,")");
								}
							fprintf(h,"</MEMBER>");
							linefeed(h);
							}
						indent(h,2);
						}
					fprintf(h,"</INDEX>");
					linefeed(h);
					}
				if ( dptr->datalength != 0 ) {
					indent(h,2);
					fprintf(h,"<RECORD");
					if ( tptr->recordtype ) { fprintf(h," TYPE=%s",tptr->recordtype); }
					fprintf(h," SIZE=%u>",dptr->datalength);
					if ( dptr->datafields ) {
						linefeed(h);
						for ( i=0; i < dptr->datafields; i++ ) {
							indent(h,3);
							fprintf(h,"<MEMBER>");
							fprintf(h,"%s",dptr->name[(i+dptr->indexfields)]);
							switch ( dptr->type[(i+dptr->indexfields)] ) {
								case	_ABAL_BYTE	: fprintf(h,"#");		break;
								case	_ABAL_WORD	: fprintf(h,"%c",0x0025); 	break;
								case	_ABAL_LONG	: fprintf(h,":"); 		break;
								case	_ABAL_STRING	: fprintf(h,"$");
								case	_ABAL_BCD	:
									fprintf(h,"=%u",dptr->width[(i+dptr->indexfields)]);
									break;
								}
							if ((v=dptr->first[(i+dptr->indexfields)]) != 0) {
								fprintf(h,"(%u",v);
								if ((v=dptr->second[(i+dptr->indexfields)]) != 0)
									fprintf(h,",%u",v);
								fprintf(h,")");
								}
							fprintf(h,"</MEMBER>");
							linefeed(h);
							}
						indent(h,2);
						}
					fprintf(h,"</RECORD>");
					linefeed(h);
					}
				}
			indent(h,1);
			fprintf(h,"</%s>",tagname);
			linefeed(h);

			}

		if (( Application.databasename ) && ( xsname ) && ( xh )) {
			fprintf(h,"</BASE>");
			linefeed(h);
			close_production_target(h,xsname);
			liberate( xsname );
			h = xh;
			xh = (FILE*) 0;
			xsname = (char *) 0;
			}
			
		for (	optr=kptr->first;
			optr != (struct object3d *) 0;
			optr = optr->next ) {
			indent(h,1);
			fprintf(h,"<OBJECT>");
			linefeed(h);
			xml_put_xyz(h,"TOPLEFT",optr->topleft.x,optr->topleft.y,optr->topleft.z,2);
			xml_put_xyz(h,"BOTTOMRIGHT",optr->bottomright.x,optr->bottomright.y,optr->bottomright.z,2);
			xml_put_word(h,"NATURE",optr->nature,2);
			xml_put_word(h,"OPTION",optr->options,2);
			xml_put_coordinate(h,"XLR",optr->colours.left,optr->colours.right,2);
			xml_put_coordinate(h,"YUL",optr->colours.upper,optr->colours.lower,2);
			xml_put_coordinate(h,"ZFB",optr->colours.front,optr->colours.back,2);
			xml_put_coordinate(h,"SHL",optr->colours.shadow,optr->colours.light,2);

			switch ( optr->nature ) {
				case	__3D_TEXT	:
					xml_put_string(h,"TEXT",optr->name,2);
					break;
				case	__3D_FORM	:
					xml_put_string(h,"FORM",optr->name,2);
					break;
				case	__3D_IMAGE	:
					xml_put_string(h,"IMAGE",optr->name,2);
					break;
				default			:
					xml_put_string(h,"NAME",optr->name,2);
					break;
				}
			indent(h,1);
			fprintf(h,"</OBJECT>");
			linefeed(h);
			}


		fprintf(h,"</THREED>");
		linefeed(h);

		close_production_target(h,sname);
		liberate( sname );

		for (	optr=kptr->first;
			optr != (struct object3d *) 0;
			optr = optr->next ) {
			switch ( optr->nature ) {
				case	__3D_FORM	:
					if ((fptr = optr->payload) != (struct form_control *) 0) {
						if (( fptr->loadstamp < fptr->savestamp )
						||  ( ModelControl.saveall )) {
							if (ModelControl.saveimages )
								save_form_image( optr->name, optr->image, optr->options  );
							if ( ModelControl.savemembers )
								save_Form( fptr, automatic );
 							fptr->loadstamp = fptr->savestamp = time((long*)0);
							}
						}
					break;
				}
			}
		}
	return;
}

private	int	xml_form_document(struct xml_application * xptr)
{
 	struct form_control * load_XmlForm(struct form_control* fptr, char * loadname,int reset, int automatic );
 	struct form_control * fptr;
	struct	camera3d    * kptr;
	struct	object3d 	* optr;
	
	if (!( kptr = xptr->payload[0] ))
		return(41);
	else if (!( optr = allocate_cube() ))
		return(27);
	else	{
		add_cube(kptr,optr);
		xptr->payload[1] = optr;
		optr->name = allocate_string(xptr->parent->name );
		kptr->name = allocate_string("?");
		optr->nature = __3D_FORM;
		optr->topleft.x     = 		optr->topleft.y     = optr->topleft.z 	  = 200;
		optr->bottomright.x = 		optr->bottomright.y = optr->bottomright.z = 300;
		kptr->position.x    = 600;	
		kptr->position.y    = 450; 
		kptr->position.z    = 400;
		optr->options = (_CAMERA_AUTOSIZE | 0x40);
		(void) xml_close( xptr->parent );
		load_CameraItem(xptr->payload[1], ( _INHIBIT_REFRESH | _INHIBIT_PROPERTIES));
		xptr->payload[1] = (struct object3d*) 0;
		return(48);
		}
}

/*	------------------------------		*/
/*	XML PARSER : DERIVATION RELAYS		*/
/*	------------------------------		*/

private	int	xml_open_camera_tag(struct xml_application * xptr, char * name )
{
	int	i;
	struct	camera3d 	* kptr;
	struct	object3d 	* optr;
	struct	file_control	* fptr;

	if (!( kptr = xptr->payload[0] ))
		return(41);

	for (i=0; i < MAX_ELEMENT; i++ )
		if ( string_compare( name, XmlElement[i] ) )
			break;

	if ( i == MAX_ELEMENT ) {
		if ( xptr->strict ) {
			sprintf(xptr->buffer,"unknown tag : %s",name);	
			status_message( xptr->buffer,2);		
			return(30);					
			}						
		}
	if ( xptr->nested < _XML_MAX_NESTING ) {
		xptr->heap[xptr->nested++]=i;
		xptr->offset=0;
		switch ( i ) {
			case	DATABASE_SQFILE	:
			case	DATABASE_SIFILE	:
			case	DATABASE_MCFILE	:
			case	DATABASE_DBFILE	:
			case	DATABASE_VMEMORY:
				xptr->payload[1] = (void *) 0;
				if (!( fptr = allocate_file_control((void*)0)) != (struct file_control*) 0)
					return(27);
				else	{
					xptr->payload[1] = fptr;
					fptr->members=0;
					switch ( i ) {
						case	DATABASE_SQFILE	: fptr->nature = _SQFILE_FRAME; break;
						case	DATABASE_SIFILE	: fptr->nature = _SIFILE_FRAME; break;
						case	DATABASE_MCFILE	: fptr->nature = _MCFILE_FRAME; break;
						case	DATABASE_DBFILE	: fptr->nature = _DBFILE_FRAME; break;
						case	DATABASE_VMEMORY: fptr->nature = _VMEMORY_FRAME; break;
						}
					}
				break;

			case	ELEMENT_FORM		:	// 0x0017
				if ( 	xptr->heap[(xptr->nested-2)] != ELEMENT_OBJECT ) {
					/* FORM DOCUMENT */
					/* ------------- */
					return( xml_form_document(xptr) );
					}
				else	return(0);

			case	ELEMENT_OBJECT	:
				xptr->payload[1] = (void *) 0;
				if (!( optr = allocate_cube() ))
					return(27);
				else	{
					add_cube(kptr,optr);
					xptr->payload[1] = optr;
					}
			}
		return(0);
		}
	else	{
		sprintf(xptr->buffer,"illegal element nesting : %s",name);
		status_message( xptr->buffer,2);
		return(105);
		}

}

private	int	xml_camera_atb_name(struct xml_application * xptr, char * name )
{
	int	i;

	for (i=0; i < MAX_ELEMENT; i++ )
		if ( string_compare( name, XmlElement[i] ) )
			break;

	if ( i == MAX_ELEMENT ) {
		if ( xptr->strict ) {
			sprintf(xptr->buffer,"unknown atb : %s",name);	
			status_message( xptr->buffer,2);		
			return(30);					
			}						
		}
	
	switch ( i ) {
		case	DATABASE_CLASS	:
		case	DATABASE_SIZE 	:
		case	ELEMENT_NAME 	:
		case	DATABASE_TYPE	:
			xptr->heap[xptr->nested++]=i;
			break;

		case	ELEMENT_FONT		:	
		case	ELEMENT_ZONE		:	
		case	ELEMENT_SPACING		:	
		case	ELEMENT_SOURCE		:	
		case	ELEMENT_TARGET		:	
		case	ELEMENT_WIDTH		:
		case	ELEMENT_PACKAGE		:	
		case	ELEMENT_IDENTITY	:	
			if ( xptr->heap[(xptr->nested-1)] == ELEMENT_TREEVIEW ) {
				xptr->heap[xptr->nested++]=i;
				break;
				}

		default			:
			if ( xptr->strict ) {
				sprintf(xptr->buffer,"unknown atb : %s",name);	
				status_message( xptr->buffer,2);		
				return(30);					
				}						
		}
	return(0);
}

private	int	xml_camera_atb_value(struct xml_application * xptr, char * value )
{
	int	i;
	char *	prefix;
	struct	file_control	* fptr;

	/* TREEVIEW Atributs */
	/* ----------------- */
	switch ((i = xptr->heap[--xptr->nested])) {
		
		case	ELEMENT_FONT		: TreeConf.font 	= atoi( value ); return(0);
		case	ELEMENT_ZONE		: TreeConf.zonage	= atoi( value ); return(0);
		case	ELEMENT_SPACING		: TreeConf.spacing	= atoi( value ); return(0);	
		case	ELEMENT_SOURCE		: TreeConf.source 	= atoi( value ); return(0);	
		case	ELEMENT_TARGET		: TreeConf.target 	= atoi( value ); return(0);		
		case	ELEMENT_PACKAGE		: TreeConf.packaging 	= atoi( value ); return(0);		
		case	ELEMENT_IDENTITY	: TreeConf.identity	= atoi( value ); return(0);		
		case	ELEMENT_WIDTH    	: TreeConf.width     	= atoi( value ); return(0);		
		}

	if (!(  fptr = xptr->payload[1] ))
		return(30);

	/* DATABASE Atributs */
	/* ----------------- */
	switch ( i ) {

		case	ELEMENT_NAME 	:
			if ( fptr->identity )
				liberate( fptr->identity );
			if (!( fptr->identity = allocate_string( value )))
				return(27);
			else	break;

		case	DATABASE_CLASS	:
			if ( fptr->classname )
				liberate( fptr->classname );
			if (!( fptr->classname = allocate_string( value )))
				return(27);
			else	break;

		case	DATABASE_TYPE 	:
			switch ( xptr->heap[(xptr->nested-1)] ) {
				case	DATABASE_INDEX	: fptr->indextype  = allocate_string( value ); break;
				case	DATABASE_RECORD	: fptr->recordtype = allocate_string( value ); break;
				}

		case	DATABASE_SIZE 	:
			switch ( xptr->heap[(xptr->nested-1)] ) {
				case	DATABASE_INDEX	: 
					while (!( prefix = fptr->indextype ))
						if (!( fptr->indextype = allocate_string("K") ))
							return(27);
					break;
				case	DATABASE_RECORD	: 
					while (!( prefix = fptr->recordtype ))
						if (!( fptr->recordtype = allocate_string("D") ))
							return(27);
					break;
				}		
			if (!( fptr->format )) {
				if (!( fptr->format = allocate( 2048 ) ))
					return(27);
				else	strcpy(fptr->format,"\0");
				}
			if ( prefix ) {
				sprintf((fptr->format+strlen(fptr->format))," %s=%s ",prefix,value);
				}
			break;
		}
	return(0);
}

private	int	xml_close_camera_tag(struct xml_application * xptr)
{
	int	i;
	struct	camera3d 	* kptr;
	struct	object3d 	* optr;
	struct	file_control	* fptr;

	if (!( kptr = xptr->payload[0] )) {
		sprintf(xptr->buffer,"unexpected close");
		status_message(xptr->buffer,3);
		return(41);
		}
	else if ( xptr->nested ) {
		i = xptr->heap[--xptr->nested];
		*(xptr->buffer + xptr->offset) = 0;
		if ( i != MAX_ELEMENT ) {
			if ( xptr->echo ) { printf("</%s>\r\n",XmlElement[i]); }
			}

		switch ( i ) {

			case	DATABASE_SQFILE	:
			case	DATABASE_SIFILE	:
			case	DATABASE_MCFILE	:
			case	DATABASE_DBFILE	:
			case	DATABASE_VMEMORY:
				if ((fptr = xptr->payload[1]) != (struct file_control*) 0) {
					AddFileClass((void*)0,fptr->nature,fptr->classname,fptr->identity,fptr->filename,fptr->format);
					liberate_file_control((void *) 0, fptr );
					}
				xptr->payload[1] = (void*) 0;
				break;
			case	DATABASE_MEMBER	:
				if ((fptr = xptr->payload[1]) != (struct file_control*) 0) {
					if ( fptr->members )
						sprintf((fptr->format+strlen(fptr->format))," , %s",xptr->buffer );
					else	sprintf((fptr->format+strlen(fptr->format))," : %s",xptr->buffer );
					fptr->members++;
					}
				break;

			case	DATABASE_FILE	:
				if ((fptr = xptr->payload[1]) != (struct file_control*) 0) {
					if ( fptr->filename )
						liberate( fptr->filename );
					if (!( fptr->filename = allocate_string( xptr->buffer )))
						return(27);
					}
				break;

			case	DATABASE_RECORD :
			case	DATABASE_INDEX 	:
				if ((fptr = xptr->payload[1]) != (struct file_control*) 0) {
					if ( fptr->members != 0 ) {
						sprintf((fptr->format+strlen(fptr->format))," ; ");
						fptr->members=0;
						}
					}
				break;
				
			case	MAX_ELEMENT		:
				break;

			case	ELEMENT_BASE		:
			case	ELEMENT_THREED		:	// 0x0000
				xptr->payload[0] = (struct camera3d*) 0;
				break;

			case	ELEMENT_OBJECT		:	// 0x000F
				if ( xptr->payload[1] ) {
					load_CameraItem(xptr->payload[1], ( _INHIBIT_REFRESH | _INHIBIT_PROPERTIES));
					xptr->payload[1] = (struct object3d*) 0;
					}
				break;

			case	ELEMENT_IMAGE		:	// 0x000B
				if ( xptr->heap[(xptr->nested-1)] == ELEMENT_THREED ) {
					xml_get_string( xptr, & kptr->background->iname );
					break;
					}
				else if ( xptr->heap[(xptr->nested-1)] == ELEMENT_OBJECT ) {
					if (!( optr = xptr->payload[1] ))
						break;
					else	xml_get_string( xptr, & optr->name );
					}
				break;

			case	ELEMENT_NAME		:	// 0x0001
				if ( xptr->heap[(xptr->nested-1)] == ELEMENT_THREED ) {
					xml_get_string( xptr, & kptr->name );
					break;
					}
			case	ELEMENT_FORM		:	// 0x0017
			case	ELEMENT_TEXT		:	// 0x0018
				if ( xptr->heap[(xptr->nested-1)] == ELEMENT_OBJECT ) {
					if (!( optr = xptr->payload[1] ))
						break;
					else	xml_get_string( xptr, & optr->name );
					}
				break;

			case	ELEMENT_VECTOR		:	// 0x0002
				xml_get_xyz( xptr, &Vektor.x,&Vektor.y,&Vektor.z);
				break;

			case	ELEMENT_SIZES		:	// 0x0003
				xml_get_xyz( xptr, &DefaultSizes.x,&DefaultSizes.y,&DefaultSizes.z);
				break;
			case	ELEMENT_POSITION	:	// 0x0004
				xml_get_xyz( xptr, &kptr->position.x,&kptr->position.y,&kptr->position.z );
				break;
			case	ELEMENT_FOCUS		:	// 0x0005
				xml_get_xy( xptr, &kptr->focus.x,&kptr->focus.y );
				break;
			case	ELEMENT_DIRECTION	:	// 0x0006
				xml_get_word( xptr, &kptr->direction );
				break;
			case	ELEMENT_MOVEMENT	:	// 0x0007
				xml_get_word( xptr, &movement );
				break;
			case	ELEMENT_TIMER		:	// 0x0008
				xml_get_word( xptr, &kptr->timer );
				break;
			case	ELEMENT_STEP		:	// 0x0009
				xml_get_word( xptr, &kptr->step );
				break;
			case	ELEMENT_PRODUCTION	:	// 0x0019
				xml_get_word( xptr, &Application.productiontype );
				break;
			case	ELEMENT_TARGET		:	// 0x001A
				xml_get_string( xptr, &Application.target );
				break;
			case	ELEMENT_LANGUAGE	:	// 0x001B
				if ( xptr->heap[(xptr->nested-1)] == ELEMENT_HTML_PRODUCTION )
					xml_get_word( xptr, &Document.language );
				else	xml_get_word( xptr, &Application.language );
				break;
			case	ELEMENT_PROJECT		:	// 0x001D
				xml_get_word( xptr, &Application.makefile );
				break;
			case	ELEMENT_MAKEFILE	:	// 0x001E
				xml_get_string( xptr, &Application.makename );
				break;
			case	ELEMENT_CONFIGURE	:	// 0x001F
				xml_get_string( xptr, &kptr->configuration );
				if (!( is_valid_method( kptr->configuration )))
					kptr->configuration = allocate_string( "visual" );
				if ( is_valid_method( kptr->configuration )) {
					LoadConfiguration( kptr->configuration);
					}
				break;

			case	ELEMENT_DATABASE	:	// 0x001F
				xml_get_string( xptr, &Application.databasename );
				if ( Application.databasename ) {
					load_XmlDataBase( kptr, Application.databasename, ( _INHIBIT_REFRESH | _INHIBIT_PROPERTIES) );
					}
				break;

			
			case ELEMENT_TREEVIEW		:	//	0x0039
				reconfigure_treeview();
				break;

			case	ELEMENT_PALETTE 	:	// 0x0028
				xml_get_string( xptr, &Application.palettename );
				if ( Application.palettename ) {
					visual_palette(Application.palettename, strlen( Application.palettename ) );
					}
				break;

			case	ELEMENT_ICONS 		:	// 0x000A
				xml_get_word( xptr, &Application.imagetype );
				break;

			case	ELEMENT_OPTION		:	// 0x000A
				if ( xptr->heap[(xptr->nested-1)] == ELEMENT_THREED ) {
					xml_get_word( xptr, & kptr->options );
					break;
					}
				else if ( xptr->heap[(xptr->nested-1)] == ELEMENT_OBJECT ) {
					if (!( optr = xptr->payload[1] ))
						break;
					else	xml_get_word( xptr, & optr->options );
					}
				break;

			case	ELEMENT_FILL		:	// 0x000C
				xml_get_word( xptr, &i );
				kptr->background->colour = (i & 0x00FF);
				kptr->background->style = (i >> 8);
				break;

			case	ELEMENT_DOCUMENT	:	// 0x000D
				xml_get_word( xptr, &Application.isdocument );
				break;

			case	ELEMENT_DOCNAME 	:	// 0x000E
				xml_get_string( xptr, &Application.document );
				break;

			case	ELEMENT_TOPLEFT		:	// 0x0010
				if (( xptr->heap[(xptr->nested-1)] == ELEMENT_OBJECT )
				&&  (( optr = xptr->payload[1] ) != (struct object3d *) 0)) 
					xml_get_xyz( xptr, &optr->topleft.x,&optr->topleft.y,&optr->topleft.z );
				break;
				
			case	ELEMENT_BOTTOMRIGHT	:	// 0x0011
				if (( xptr->heap[(xptr->nested-1)] == ELEMENT_OBJECT )
				&&  (( optr = xptr->payload[1] ) != (struct object3d *) 0)) 
					xml_get_xyz( xptr, &optr->bottomright.x,&optr->bottomright.y,&optr->bottomright.z );
				break;
					

			case	ELEMENT_NATURE		:	// 0x0012
				if (( xptr->heap[(xptr->nested-1)] == ELEMENT_OBJECT )
				&&  (( optr = xptr->payload[1] ) != (struct object3d *) 0)) 
					xml_get_word( xptr, &optr->nature );
				break;

			case	ELEMENT_XLR		:	// 0x0013
				if (( xptr->heap[(xptr->nested-1)] == ELEMENT_OBJECT )
				&&  (( optr = xptr->payload[1] ) != (struct object3d *) 0)) 
					xml_get_xy(xptr,&optr->colours.left,&optr->colours.right);
				break;

			case	ELEMENT_YUL		:	// 0x0014
				if (( xptr->heap[(xptr->nested-1)] == ELEMENT_OBJECT )
				&&  (( optr = xptr->payload[1] ) != (struct object3d *) 0)) 
					xml_get_xy(xptr,&optr->colours.upper,&optr->colours.lower);
				break;

			case	ELEMENT_ZFB		:	// 0x0015
				if (( xptr->heap[(xptr->nested-1)] == ELEMENT_OBJECT )
				&&  (( optr = xptr->payload[1] ) != (struct object3d *) 0)) 
					xml_get_xy(xptr,&optr->colours.front,&optr->colours.back);
				break;

			case	ELEMENT_SHL		:	// 0x0016
				if (( xptr->heap[(xptr->nested-1)] == ELEMENT_OBJECT )
				&&  (( optr = xptr->payload[1] ) != (struct object3d *) 0)) 
					xml_get_xy(xptr,&optr->colours.shadow,&optr->colours.light);
				break;

			case	ELEMENT_HTML_PRODUCTION		:
				break;

			case	ELEMENT_TITLE			:
				if ( xptr->heap[(xptr->nested-1)] == ELEMENT_HTML_PRODUCTION )
					xml_get_string( xptr, &Document.title );
				break;

			case	ELEMENT_SCREEN			:
				if ( xptr->heap[(xptr->nested-1)] == ELEMENT_HTML_PRODUCTION )
					xml_get_string( xptr, &Document.screenstyle );
				break;
			case	ELEMENT_PRINT			:
				if ( xptr->heap[(xptr->nested-1)] == ELEMENT_HTML_PRODUCTION )
					xml_get_string( xptr, &Document.printstyle );
				break;
			case	ELEMENT_LOGO			:
				if ( xptr->heap[(xptr->nested-1)] == ELEMENT_HTML_PRODUCTION )
					xml_get_string( xptr, &Document.logo );
				break;
			case	ELEMENT_FOOTER			:
				if ( xptr->heap[(xptr->nested-1)] == ELEMENT_HTML_PRODUCTION )
					xml_get_string( xptr, &Document.footer );
				break;
			case	ELEMENT_PATH			:
				if ( xptr->heap[(xptr->nested-1)] == ELEMENT_HTML_PRODUCTION )
					xml_get_string( xptr, &Document.pathroot );
				break;
			case	ELEMENT_SEPARATE		:
				if ( xptr->heap[(xptr->nested-1)] == ELEMENT_HTML_PRODUCTION )
					xml_get_word( xptr, &Document.separate );
				break;
			case	ELEMENT_REPORT			:
				if ( xptr->heap[(xptr->nested-1)] == ELEMENT_HTML_PRODUCTION )
					xml_get_word( xptr, &Document.report );
				break;
			case	ELEMENT_NATIONAL		:
				if ( xptr->heap[(xptr->nested-1)] == ELEMENT_HTML_PRODUCTION )
					xml_get_word( xptr, &Document.forcelang );
				break;
			
			}
		xptr->offset=0;
		return(0);
		}
	else	{
		sprintf(xptr->buffer,"unexpected close");
		status_message(xptr->buffer,3);
		return(30);
		}
}

public 	struct camera3d * load_XmlDataBase(struct camera3d * cptr, char * loadname, int automatic )
{
	int	status;

	struct	xml_relay relays = {
		xml_open_camera_tag,
		xml_camera_atb_name,
		xml_camera_atb_value,
		(void *) 0,
		(void *) 0,
		(void *) 0,
		xml_close_camera_tag,
		xml_error_handler
		};

	if (!( cptr ))
		return (void *)0; 

	else if (!( loadname = allocate_string( loadname )))
		return (void *)0; 
	else if (!( loadname = enforce_extension( loadname, XML_EXTENSION ) ))
		return (void *)0; 


	if ( loadname )
		if (!( automatic & _INHIBIT_STATUS ))
			status_message( loadname,3);

	if ((status = xml_parse( loadname,& relays, cptr )) != 0 ) {
		status_message("xml parse failure",3);
		}

	if ( loadname )
		liberate( loadname );

	return( cptr );
}

public 	struct camera3d * load_XmlCamera(struct camera3d * cptr, char * loadname,int reset, int automatic )
{
	int	status;

	struct	xml_relay relays = { 
		xml_open_camera_tag,
		xml_camera_atb_name,
		xml_camera_atb_value,
		(void *) 0,
		(void *) 0,
		(void *) 0,
		xml_close_camera_tag,
		xml_error_handler
		};

	if (!( cptr )) {
		if (!( cptr = initialise_Camera() )) {
			loadname = liberate( loadname );
			return(cptr);
			}
		}
	if ( loadname )
		if (!( automatic & _INHIBIT_STATUS ))
			status_message( loadname,3);

	if ((status = xml_parse( loadname,& relays, cptr )) != 0 ) {
		if ( loadname ) {
			if ( cptr->name )
				cptr->name = liberate( cptr->name );
			cptr->name = allocate_string( loadname );
			}
		status_message("xml parse failure",3);
		}
	if ( cptr->configuration )
		LoadConfiguration( cptr->configuration);

	if ( cptr->options & _THREED_PALETTE ) {
		show_DeskTop_Palette();
		}
	else	hide_DeskTop_Palette();
	if ( cptr->options & _THREED_TOOLBAR )
		show_DeskTop_ToolBar();
	else	hide_DeskTop_ToolBar();
	if ( cptr->options & _THREED_TREEVIEW )
		show_DeskTop_TreeView();
	else	hide_DeskTop_TreeView();
 
	return( cptr );
}

#endif	/* _singx3d_c */
	/* ---------- */

