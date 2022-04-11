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

#include "singxml.h"

#include "xmlparse.h"
#include "xmlthree.h"

#include "singprot.h"
#include "singdbed.h"

extern	struct visual_database_editor VDE;

#define	__QUOTE	0x0022
extern	struct	screen_control	Context;
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


struct	widget_grid_lock_configuration {
	int	widget;
	int	value;
	} WidgetGridLock = { -1, -1 };

public	void	lendollarstring(FILE * h, char * sptr )
{
	fprintf(h,"%s",sptr);
	return;
}

public	void	lendollardotstring(FILE * h, char * sptr )
{
	int	c;
	while ((c = *(sptr++)) != 0 ) {
		if ( c == ' ' )
			c = '/';
		fprintf(h,"%c",c);
		}
	return;
}

public	void	abal_xml_dcl(FILE *  h, char * pptr,char *  nptr, int type, int width, int first, int second, int special, int decimal )
{
	int	v;
	if ( type == _ABAL_FIELD ) {
		indent(h,3);
		fprintf(h,"<FIELD>@%s",nptr);
		if ( first ) {
			fprintf(h,"(%u",first);
			if ( second )
				fprintf(h,",%u)",second);
			else	fprintf(h,")");
			}
		fprintf(h,"</FIELD>");
		}
	else if ( type == _ABAL_FILLER ) {
		indent(h,3);
		fprintf(h,"<FILLER>*%u</FILLER>",width);
		}
	else if ( type == _ABAL_OBJ ) {
		indent(h,3);
		fprintf(h,"<MEMBER>");
		if ( special & 1 )
			fprintf(h,"!");
		if ( special & 2 )
			fprintf(h,"?");
		lendollarstring(h,pptr);
		lendollardotstring(h,nptr);
		fprintf(h,"</MEMBER>");
		}
	else	{
		indent(h,3);
		fprintf(h,"<MEMBER>");
		if ( special & 1 )
			fprintf(h,"!");
		if ( special & 2 )
			fprintf(h,"?");
		lendollarstring(h,pptr);
		lendollarstring(h,nptr);
		switch ( type ) {
			case	_ABAL_BYTE	: fprintf(h,"#");		break;
			case	_ABAL_WORD	: fprintf(h,"%c",0x0025); 	break;
			case	_ABAL_LONG	: fprintf(h,":"); 		break;
			case	_ABAL_STRING	:
				fprintf(h,"$");
				fprintf(h,"=%u",width);
				break;
			case	_ABAL_BCD	:
				fprintf(h,"=%u",width);
				if ( decimal ) 
					fprintf(h,".%u",decimal);
		
				break;
			}
		if ((v=first) != 0) {
			fprintf(h,"(%u",v);
			if ((v=second) != 0)
				fprintf(h,",%u",v);
			fprintf(h,")");
			}
		fprintf(h,"</MEMBER>");
		}
	linefeed(h);
	return;
}

public	void	abal_print_dcl(FILE *  h, char * pptr,char *  nptr, int type, int width, int first, int second, int special, int decimal )
{
	int	v;
	if ( type == _ABAL_FIELD ) {
		fprintf(h,"<li> redefines %s",nptr);
		if ( first ) {
			fprintf(h,"(%u",first);
			if ( second )
				fprintf(h,",%u) ",second);
			else	fprintf(h,") ");
			}
		else	fprintf(h," ");
		linefeed(h);
		}
	else if ( type == _ABAL_FILLER ) {
		fprintf(h,"<li> filler %u",width);
		linefeed(h);
		}
	else	{
		fprintf(h,"<li>");
		if ( special & 1 )
			fprintf(h,"!");
		lendollarstring(h,pptr);
		lendollarstring(h,nptr);
		switch ( type ) {
			case	_ABAL_BYTE	: fprintf(h,"#");		break;
			case	_ABAL_WORD	: fprintf(h,"%c",0x0025); 	break;
			case	_ABAL_LONG	: fprintf(h,":"); 		break;
			case	_ABAL_STRING	:
				fprintf(h,"$");
				fprintf(h,"=%u",width);
				break;
			case	_ABAL_BCD	:
				fprintf(h,"=%u",width);
				if ( decimal )
					fprintf(h,".%u",decimal);
				break;
			}
		if ((v=first) != 0) {
			fprintf(h,"(%u",v);
			if ((v=second) != 0)
				fprintf(h,",%u",v);
			fprintf(h,")");
			}
		linefeed(h);
		}
	return;
}

public	void	string_print_dcl(char * rptr, char * pptr,char *  nptr, int type, int width, int first, int second, int special, int decimal )
{
	int	v;
	if ( type == _ABAL_FIELD ) {
		sprintf(rptr,"Field=m,%s",nptr);
		if ( first ) {
			rptr += strlen( rptr );
			sprintf(rptr,"(%u",first);
			rptr += strlen( rptr );
			if ( second )
				sprintf(rptr,",%u)",second);
			else	sprintf(rptr,")");
			}
		return;
		}
	else if ( type == _ABAL_FILLER ) {
		sprintf(rptr,"Filler=%u",width);
		return;
		}
	sprintf(rptr,"%s",nptr); rptr += strlen( rptr );
	switch ( type ) {
		case	_ABAL_BYTE	: sprintf(rptr,"#");		break;
		case	_ABAL_WORD	: sprintf(rptr,"%c",0x0025); 	break;
		case	_ABAL_LONG	: sprintf(rptr,":"); 		break;
		case	_ABAL_STRING	: sprintf(rptr,"$=%u",width);	break;
		case	_ABAL_BCD	: 
			sprintf(rptr,"=%u",width);
			if ( decimal ) { 
				rptr += strlen( rptr );
				sprintf(rptr,".%u",decimal); 
				}
			break;
		}
	rptr += strlen( rptr );
	if ((v=first) != 0) {
		sprintf(rptr,"(%u",v);
		rptr += strlen( rptr );
		if ((v=second) != 0)
			sprintf(rptr,",%u)",v);
		else	sprintf(rptr,")");
		}
	return;
}

public	struct link_control * liberate_link_control(struct link_control * lptr)
{
	if ( lptr ) {
		if ( lptr->name )
			liberate( lptr->name );
		if ( lptr->jointure )
			liberate( lptr->jointure );
		if ( lptr->source )
			liberate( lptr->source );
		if ( lptr->target )
			liberate( lptr->target );
		liberate( lptr );
		}
	return((struct link_control *) 0);
}

public	struct link_control * allocate_link_control()
{
	struct	link_control * lptr;
	if (!( lptr = allocate( sizeof ( struct link_control ) ) ))
		return(lptr);
	else	{
		lptr->jointure = lptr->name = lptr->source = lptr->target = (char *) 0;
		lptr->previous = lptr->next = (struct link_control *) 0;
		lptr->nature = 0;
		return( lptr );
		}
}

public	void	store_database_link(struct link_control * lptr)
{
	if (!( lptr->previous = FileManager->lastlink ))
		FileManager->firstlink = lptr;
	else	lptr->previous->next = lptr;
	FileManager->lastlink = lptr;
	return;
}

public	struct link_control * create_database_link( char * nptr, char * jptr, char * slptr, char * tlptr, int nature)
{
	struct	link_control * lptr;
	if (!( lptr = allocate_link_control() ))
		return((struct link_control *) 0);
	else if (!( lptr->name = allocate_string( nptr ))) {
		liberate_link_control( lptr );
		return((struct link_control *) 0);
		}
	else if (!( lptr->jointure = allocate_string( jptr ))) {
		liberate_link_control( lptr );
		return((struct link_control *) 0);
		}
	else if (!( lptr->source = allocate_string( slptr ))) {
		liberate_link_control( lptr );
		return((struct link_control *) 0);
		}
	else if (!( lptr->target = allocate_string( tlptr ))) {
		liberate_link_control( lptr );
		return((struct link_control *) 0);
		}
	else	{
		lptr->nature = nature;
		store_database_link( lptr );
		return( lptr );
		}
}

public	void	export_database_help( FILE * h, struct file_control * fptr )
{
	int	i;
	int	n;

	/* ------------------------------- */
	/* conditional file help documents */
	/* ------------------------------- */
	for (i=0,n=0; i < MAXNATLANG; i++ ) {
		if ( method_is_valid( fptr->document[i] ) )
			n++;
		}
	if (!( n ))	return;
		
	indent(h,1);
	fprintf(h,"<COMMENT>"); 
	linefeed(h);

	xml_put_word(h,"TOOL",fptr->doctool,1);
		
	if ( fptr->document[0] ) 
		xml_put_helptext(h,"ENGLISH",fptr->document[0],1);
	if ( fptr->document[1] ) 
		xml_put_helptext(h,"FRANCAIS",fptr->document[1],1);
	if ( fptr->document[2] ) 
		xml_put_helptext(h,"ITALIANO",fptr->document[2],1);
	if ( fptr->document[3] ) 
		xml_put_helptext(h,"ESPAGNOL",fptr->document[3],1);
	if ( fptr->document[4] ) 
		xml_put_helptext(h,"DEUTSCH",fptr->document[4],1);
	if ( fptr->document[5] ) 
		xml_put_helptext(h,"NEDERLANDS",fptr->document[5],1);
	if ( fptr->document[6] ) 
		xml_put_helptext(h,"PORTUGUES",fptr->document[6],1);
	if ( fptr->document[7] ) 
		xml_put_helptext(h,"OTHER",fptr->document[7],1);
	indent(h,1);
	fprintf(h,"</COMMENT>");
	linefeed(h);
	return;
}

private	int	export_database_records( FILE * h )
{
	char *	tagname;
	struct data_control * dptr;
	struct file_control * tptr;
	struct link_control * lptr;
	int	i;
	int	v;

	/* For all file records in the DataBase Manager */
	/* -------------------------------------------- */
	for ( 	tptr  = FileManager->first;
		tptr != (struct file_control *) 0;
		tptr = tptr->next ) {

		/* Validate both classname and identity */
		/* ------------------------------------ */
		if ((!( tptr->classname ))
		&&  (!( tptr->identity  )))
			continue;

		/* Determine Record Type */
		/* --------------------- */
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

		/* ----------------------------------------------- */
		/* information required by the new database editor */
		/* ----------------------------------------------- */
		if (( tptr->x != -1 )
		&&  ( tptr->y != -1 )) {
			fprintf(h," X=%u Y=%u OPTION=%u",tptr->x,tptr->y,tptr->state);
			}

		fprintf(h,">");
		linefeed(h);
		if ( tptr->filename ) {
			indent(h,2);
			fprintf(h,"<FILE>%s</FILE>",tptr->filename);
			linefeed(h);
			}
		/* Generate File Members */
		/* --------------------- */
		if (( dptr = tptr->payload ) != (struct data_control *) 0) {

			/* Test for and generate file help information */
			/* ------------------------------------------- */
			export_database_help( h, tptr );
			if ( dptr->indexfields != 0 ) {

				/* Generate Index Information */
				/* -------------------------- */
				indent(h,2);
				fprintf(h,"<INDEX");
				fprintf(h," TYPE=");
				if ( dptr->option & _A_LINE )
					fprintf(h,"X");
				else if ( dptr->option & _A_LEFT )
					fprintf(h,"L");
				else if ( dptr->option & _A_RIGHT )
					fprintf(h,"R");
				if ( dptr->option & _A_SHADOW )
					fprintf(h,"MK");
				else	fprintf(h,"K");

				fprintf(h," SIZE=%u>",dptr->indexlength);

				if ( dptr->indexfields ) {

					/* Generate Index Members */
					/* ---------------------- */
					linefeed(h);
					for ( i=0; i < dptr->indexfields; i++ ) {
						abal_xml_dcl(h,"\0",dptr->name[i],dptr->type[i],dptr->width[i],dptr->first[i],dptr->second[i],dptr->special[i],dptr->decimal[i]);
						}
					indent(h,2);
					}
				fprintf(h,"</INDEX>");
				linefeed(h);
				}

			if ( dptr->datafields != 0 ) {

				/* Generate Data Record Information */
				/* -------------------------------- */
				indent(h,2);
				fprintf(h,"<RECORD");
				if ( dptr->option & _A_BOLD )
					fprintf(h," TYPE=VD");
				fprintf(h," SIZE=%u>",dptr->datalength);
				if ( dptr->datafields ) {
					linefeed(h);

					/* Generate Data Record Members */
					/* ---------------------------- */
					for ( i=0; i < dptr->datafields; i++ ) {
						abal_xml_dcl(h,"\0",dptr->name[(i+dptr->indexfields)],dptr->type[(i+dptr->indexfields)],dptr->width[(i+dptr->indexfields)],dptr->first[(i+dptr->indexfields)],dptr->second[(i+dptr->indexfields)],dptr->special[(i+dptr->indexfields)],dptr->decimal[(i+dptr->indexfields)]);
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

	/* For all link records in the DataBase Manager */
	/* -------------------------------------------- */
	for ( 	lptr  = FileManager->firstlink;
		lptr != (struct link_control *) 0;
		lptr = lptr->next ) {
		indent(h,1);
		fprintf(h,"<LINK NAME=%s JOINTURE=%s SOURCE=%s TARGET=%s TYPE=%u/>",
			(lptr->name ? lptr->name : "relation"),
			(lptr->jointure ? lptr->jointure : "jointure" ),
			(lptr->source ? lptr->source : "source.member"),
			(lptr->target ? lptr->target : "target.member"),
			lptr->nature);
		linefeed(h);		
		}

	return(0);
}

public	int	print_database_records( FILE * h )
{
	char *	tagname;
	char *	hptr;
	struct data_control * dptr;
	struct file_control * tptr;
	int	i;
	int	v;
	int	filecount=0;

	start_html_document(
			h,
			"Sing Database Printout",
			Document.logo,
			Document.screenstyle,
			Document.printstyle,
			(struct form_control *) 0
			);

	/* For all file records in the DataBase Manager */
	/* -------------------------------------------- */

	for ( 	tptr  = FileManager->first;
		tptr != (struct file_control *) 0;
		tptr = tptr->next ) {

		/* Validate both classname and identity */
		/* ------------------------------------ */
		if ((!( tptr->classname ))
		&&  (!( tptr->identity  )))
			continue;

		/* Determine Record Type */
		/* --------------------- */
		switch ( tptr->nature ) {
			case	_SQFILE_FRAME	: tagname = "SQ"; break;
			case	_DBFILE_FRAME	: tagname = "BD"; break;
			case	_MCFILE_FRAME	: tagname = "MC"; break;
			case	_SIFILE_FRAME	: tagname = "SI"; break;
			case	_VMEMORY_FRAME	: tagname = "VM"; break;
			default			: tagname = "SI"; break;
			}
		fprintf(h,"<table><tr><th width=%c5%c%c rowspan=2>%u<th width=%c10%c%c>%s<th>%s<th>%s<th>",
				__QUOTE,0x0025,__QUOTE,
				++filecount,
				__QUOTE,0x0025,__QUOTE,
				tagname,tptr->classname,tptr->identity );
		if ( tptr->filename ) {
			fprintf(h,"<i>%s</i>",tptr->filename);
			}
		linefeed(h);
		fprintf(h,"</tr><tr><td colspan=4>");

		/* Generate File Members */
		/* --------------------- */
		if (( dptr = tptr->payload ) != (struct data_control *) 0) {

			/* generate corresponding help text to the document */
			/* ------------------------------------------------ */
			if ( method_is_valid(( hptr = tptr->document[ visual_national_language(-1) ] )) )  {
				linefeed(h);
				html_tag(h,"p");
				html_text(h,hptr); 
				html_tag(h,"p");
				linefeed(h);
				fprintf(h,"</tr><tr><td colspan=4>");
				}

			fprintf(h,"<ul>");linefeed(h);

			if ( dptr->indexlength != 0 ) {

				fprintf(h,"<li>Primary Index : ");

				/* Generate Index Information */
				/* -------------------------- */
				if ( dptr->option & _A_LINE )
					fprintf(h,"X");
				else if ( dptr->option & _A_LEFT )
					fprintf(h,"L");
				else if ( dptr->option & _A_RIGHT )
					fprintf(h,"R");
				if ( dptr->option & _A_SHADOW )
					fprintf(h,"MK");
				else	fprintf(h,"K");
				fprintf(h,"=%u",dptr->indexlength);
				linefeed(h);

				if ( dptr->indexfields ) {

					/* Generate Index Members */
					/* ---------------------- */
					fprintf(h,"<ol>");linefeed(h);
					for ( i=0; i < dptr->indexfields; i++ ) {
						abal_print_dcl(h,"\0",dptr->name[i],dptr->type[i],dptr->width[i],dptr->first[i],dptr->second[i],dptr->special[i],dptr->decimal[i]);
						}
					fprintf(h,"</ol>");linefeed(h);
					}
				}
			if ( dptr->datalength != 0 ) {

				/* Generate Data Record Information */
				/* -------------------------------- */
				fprintf(h,"<li>Data Record : ");
				if ( dptr->option & _A_BOLD )
					fprintf(h," VD=%u ",dptr->datalength);
				else	fprintf(h," D=%u ",dptr->datalength);
				linefeed(h);

				if ( dptr->datafields ) {

					/* Generate Data Record Members */
					/* ---------------------------- */
					fprintf(h,"<ol>");linefeed(h);
					for ( i=0; i < dptr->datafields; i++ ) {
						abal_print_dcl(h,"\0",dptr->name[(i+dptr->indexfields)],dptr->type[(i+dptr->indexfields)],dptr->width[(i+dptr->indexfields)],dptr->first[(i+dptr->indexfields)],dptr->second[(i+dptr->indexfields)],dptr->special[(i+dptr->indexfields)],dptr->decimal[(i+dptr->indexfields)]);
						}
					fprintf(h,"</ol>");linefeed(h);
					}
				}

			fprintf(h,"</ul>"); linefeed(h);

			}
		fprintf(h,"</tr></table>");
		}
	close_html_document(h, Document.footer );
	
	return(0);
}

public	int	export_database( char * nptr, int nlen )
{
	FILE *	h;
	char *	dptr;
	char *	basename;
	char *	xsname=(char *) 0;
	int	i;
	int	n;
	int	status=0;
	char *app_forms,*vtrav;

	/* Allocate and copy database ressource name */
	/* ----------------------------------------- */
	if (!( basename = allocate( nlen+1 )))
		return(27);

	for (i=0,n=0; i < nlen; i++ )
		if (( *(basename+i) = *(nptr+i) ) != ' ')
			n = (i+1);
	*(basename+n) = 0;

	if ( method_is_valid((app_forms = application_forms_folder())) ) {
		add_path_terminator(&app_forms);
		vtrav=relative_filename(basename, app_forms);
		liberate(app_forms);
		liberate(basename);
		basename=vtrav;
		};

	/* Create Production Target */
	/* ------------------------ */
	if (!(h = open_xml_target( basename, &xsname, "DATABASE", xml_base_type, xml_base_style  ))) {
		status = 46;
		}
	else 	{

		/* Open Document Section */
		/* --------------------- */
		fprintf(h,"<BASE>");
		linefeed(h);

		/* Generate Records */
		/* ---------------- */
		status = export_database_records( h );

		/* Close Document Section */
		/* ---------------------- */
			fprintf(h,"</BASE>");
			linefeed(h);
		linefeed(h);
			close_production_target(h,xsname);
			liberate( xsname );
			}
			
	liberate( basename );
	return(status);
}

public	int	import_database( char * nptr, int nlen )
{
	struct camera3d * kptr;
	FILE *	h;
	char *	basename;
	char *	xsname=(char *) 0;
	int	i;
	int	n;
	int	status=0;

	/* Ensure valid camera */
	/* ------------------- */
	if (!( kptr = Context.Camera ))
		return(118);

	/* Allocate and copy database ressource name */
	/* ----------------------------------------- */
	if (!( basename = allocate( nlen+1 )))
		return(27);

	for (i=0,n=0; i < nlen; i++ )
		if (( *(basename+i) = *(nptr+i) ) != ' ')
			n = (i+1);
	*(basename+n) = 0;

	/* Perform the low level database import */
	/* ------------------------------------- */
	load_XmlDataBase( kptr, basename, ( _INHIBIT_REFRESH | _INHIBIT_PROPERTIES) );

	return(0);
}

private	void	xml_put_gridlock(FILE * h, char * tagname, int i )
{
	int	w;
	for ( w=0; w <= 20; w++ ) {
		indent(h,i);
		fprintf(h,"<GRIDLOCK WIDGET=%c%u%c VALUE=%c%u%c/>",
			__QUOTE,w,__QUOTE,
			__QUOTE,get_widget_gridlock(w),__QUOTE);
		linefeed(h);
		}
	fprintf(h,"<LOCKON>%u</LOCKON>",Context.lockon);
	fprintf(h,"<GRIDTYPE>%u</GRIDTYPE>",Context.gridtype);
	linefeed(h);
	return;
}

public 	void	xml_put_Camera( struct camera3d * kptr, char * dtdname, int automatic )
{
	struct	view3d * vptr;
	FILE * h;
	FILE * xh=(FILE*)0;
	int	v;
	int	i;
	char * dbname=(char *) 0;
	char * sname=(char *) 0;
	char * xsname=(char *) 0;
	char * tagname=(char *) 0;
	struct object3d * optr;
	struct form_control * fptr;
	struct data_control * dptr;
	struct file_control * tptr;
#ifdef	ABAL32A
	struct application_parameters * aptr=(struct application_parameters *) 0;
	if ( kptr ) { aptr = kptr->application; }
#endif
	if ((h = open_xml_target( kptr->name, &sname, "THREED", xml_threed_type, xml_threed_style )) != (FILE*) 0) {

		fprintf(h,"<THREED>");
		linefeed(h);

		xml_put_filename_string(h,"NAME",kptr->name,1);
		xml_put_xyz(h,"VECTOR",Vektor.x,Vektor.y,Vektor.z,1);
		xml_put_xyz(h,"SIZES",DefaultSizes.x,DefaultSizes.y,DefaultSizes.z,1);

		/* Save Camera View Points */
		/* ----------------------- */
		if ( kptr->topview ) {
			for (	vptr=kptr->topview;
				vptr != (struct view3d*) 0;
				vptr = vptr->next ) {
				indent(h,1);
				fprintf(h,"<VIEW>");
				linefeed(h);
				xml_put_xyz(h,"POSITION",vptr->position.x,vptr->position.y,vptr->position.z,2);
				xml_put_coordinate(h,"FOCUS",vptr->focus.x,vptr->focus.y,2);
				xml_put_word(h,"DIRECTION",vptr->direction,2);
				indent(h,1);
				fprintf(h,"</VIEW>");
				linefeed(h);
				}
			}

		xml_put_xyz(h,"POSITION",kptr->position.x,kptr->position.y,kptr->position.z,1);
		xml_put_coordinate(h,"FOCUS",kptr->focus.x,kptr->focus.y,1);
		xml_put_word(h,"DIRECTION",kptr->direction,1);
		xml_put_word(h,"MOVEMENT",movement,1);
		xml_put_word(h,"TIMER",kptr->timer,1);
		xml_put_word(h,"STEP",kptr->step,1);

		/* Abal Source Type : For Alliance ! */
		/* --------------------------------- */
		indent(h,1);
		fprintf(h,"<EXTENSION>%u</EXTENSION>",Context.BalOrAbal);
		linefeed(h);

		if (!( palette_is_active() ))
			kptr->options &= ~_THREED_PALETTE; /* 0x0010; */
		else	kptr->options |=  _THREED_PALETTE; /* 0x0010; */

		if (!( toolbar_is_active() ))
			kptr->options &= ~_THREED_TOOLBAR; /* 0x0020; */
		else	kptr->options |=  _THREED_TOOLBAR; /* 0x0020; */

		if (!( treeview_is_active() ))
			kptr->options &= ~_THREED_TREEVIEW; /* 0x0040; */
		else	kptr->options |=  _THREED_TREEVIEW; /* 0x0040; */

#ifdef	ABAL32A
		context_is_uptodate( kptr );
#endif
		xml_put_word(h,"OPTION",(kptr->options & ~_CAMERA_OBJECT_LOCK),1);
#ifdef	ABAL32A
		xml_put_word(h,"ICONS",aptr->imagetype,1);
#else
		xml_put_word(h,"ICONS",Application.imagetype,1);
#endif
		xml_put_filename_string(h,"IMAGE",kptr->background->iname,1);
		xml_put_word(h,"FILL",(kptr->background->colour | (kptr->background->style << 8)),1);
#ifdef	ABAL32A
		xml_put_word(h,"DOCUMENT",aptr->isdocument,1);
		xml_put_filename_string(h,"DOCNAME", aptr->document,1);
		xml_put_word(h,"PRODUCTION",aptr->productiontype,1);
		xml_put_filename_string(h,"TARGET",aptr->target,1);
		xml_put_word(h,"LANGUAGE",aptr->language,1);
#else
		xml_put_word(h,"DOCUMENT",Application.isdocument,1);
		xml_put_filename_string(h,"DOCNAME", Application.document,1);
		xml_put_word(h,"PRODUCTION",Application.productiontype,1);
		xml_put_filename_string(h,"TARGET",Application.target,1);
		xml_put_word(h,"LANGUAGE",Application.language,1);
#endif
		xml_put_word(h,"NATLANG",Context.natlang,1);
		xml_put_word(h,"TESTDATA",Context.UseTestData,1);
		xml_put_word(h,"USESTYLE",Context.usestyle,1);
		xml_put_filename_string(h,"STYLE", aptr->stylesheet,1 );
#ifdef	ABAL32A
		xml_put_word(h,"PROJECT",aptr->makefile,1);
		xml_put_filename_string(h,"MAKEFILE", aptr->makename,1 );
#else
		xml_put_word(h,"PROJECT",Application.makefile,1);
		xml_put_filename_string(h,"MAKEFILE", Application.makename,1 );
#endif
		xml_put_string(h,"CONFIGURE",kptr->configuration,1 );

		xml_put_gridlock(h,"GRIDLOCK",1);

		indent(h,1);
		fprintf(h,"<HTML-PRODUCTION>");
		linefeed(h);
		xml_put_string(h,"TITLE",Document.title,2);
		xml_put_string(h,"SCREEN",Document.screenstyle,2);
		xml_put_string(h,"PRINT",Document.printstyle,2);
		xml_put_string(h,"LOGO",Document.logo,2);
		xml_put_string(h,"FOOTER",Document.footer,2);
		xml_put_filename_string(h,"PATH",Document.pathroot,2);
		xml_put_word(h,"SEPARATE",Document.separate,2);
		xml_put_word(h,"REPORT",Document.report,2);
		xml_put_word(h,"NATIONAL",Document.forcelang,2);
		xml_put_word(h,"LANGUAGE",Document.language,2);
		xml_put_word(h,"METRIC",Document.metric,2);
		xml_put_word(h,"SCALE",Document.scale,2);
		indent(h,1);
		fprintf(h,"</HTML-PRODUCTION>");
		linefeed(h);

		indent(h,1);
		fprintf(h,"<TREEVIEW FONT=%u ZONE=%u SPACING=%u SOURCE=%u TARGET=%u PACKAGE=%u IDENTITY=%u WIDTH=%u />",
				TreeConf.font,TreeConf.zonage,TreeConf.spacing,
				TreeConf.source,TreeConf.target,TreeConf.packaging,TreeConf.identity,TreeConf.width);
		linefeed(h);


#ifdef	ABAL32A
		if ( method_is_valid(aptr->components) ) {
			xml_put_filename_string(h,"COMPONENTS",aptr->components,1);
			}
		if ( method_is_valid(aptr->formulaires) ) {
			xml_put_filename_string(h,"FORMSFOLDER",aptr->formulaires,1);
			}

		if ( method_is_valid(aptr->src_product) ) {
			xml_put_filename_string(h,"SOURCESFOLDER",aptr->src_product,1);
			}

		if ( method_is_valid(aptr->obj_product) ) {
			xml_put_filename_string(h,"BINARIESFOLDER",aptr->obj_product,1);
			}
		if ( method_is_valid(aptr->palettename) ) {
			xml_put_filename_string(h,"PALETTE",aptr->palettename,1);
			}
		if ( method_is_valid(aptr->template) ) {
			xml_put_filename_string(h,"TEMPLATE",aptr->template,1);
			}

		if ( method_is_valid(aptr->modules) ) {
			xml_put_filename_string(h,"MODULES",aptr->modules,1);
			}
#else
		if ( method_is_valid(Application.formulaires) ) {
			xml_put_filename_string(h,"FORMSFOLDER",Application.formulaires,1);
			}

		if ( method_is_valid(Application.src_product) ) {
			xml_put_filename_string(h,"SOURCESFOLDER",Application.src_product,1);
			}

		if ( method_is_valid(Application.obj_product) ) {
			xml_put_filename_string(h,"BINARIESFOLDER",Application.obj_product,1);
			}

		if ( method_is_valid(Application.palettename) ) {
			xml_put_filename_string(h,"PALETTE",Application.palettename,1);
			}
		if ( method_is_valid(Application.template) ) {
			xml_put_filename_string(h,"TEMPLATE",Application.template,1);
			}

		if ( method_is_valid(Application.modules) ) {
			xml_put_filename_string(h,"MODULES",Application.modules,1);
			}
#endif		
		xml_put_word(h,"ROLLBACK",Context.rollback,1);

		indent(h,1);
		fprintf(h,"<DATABASE");

		/* Generate Database Model Editor Parameters */
		/* ----------------------------------------- */
		fprintf(h," HYPERVIEW=%u FRACTION=%u HELP=%u",
			VDE.hyperspace,VDE.fraction,VDE.bubblehelp);
		fprintf(h," TRACING=%u WIDTH=%u COLOUR=%u",
			VDE.bender,VDE.tracewidth,VDE.tracecolour);
		fprintf(h," XPADDING=%u YPADDING=%u MARGIN=%u DEPTH=%u",
			VDE.xpadding,VDE.ypadding,VDE.tracepadding,VDE.depth);

		/* Generate Data Base Ressource Information */
		/* ---------------------------------------- */
		if ( method_is_valid((dbname = application_databasename(kptr))) ) {

			/* To separate ressource file */
			/* -------------------------- */
			fprintf(h,">");
			xml_put_filename(h,dbname);
			fprintf(h,"</DATABASE>");
			linefeed(h);
			export_database( dbname, strlen( dbname ) );
			}
		else	{
			/* To project ressource file */
			/* ------------------------- */
			fprintf(h,"/>");
			linefeed(h);
			export_database_records( h );
			}

		if ( dbname ) { liberate( dbname ); }
			
#ifdef	SORT_DURING_SAVE
		for (	otype=0; otype < 3; otype++ ) {
#endif
		for (	optr=kptr->first;
			optr != (struct object3d *) 0;
			optr = optr->next ) {
#ifdef	SORT_DURING_SAVE
			switch ( optr->nature ) {
				case	__3D_TEXT	:
					if (otype == 0)
						break;
					else	continue;
				case	__3D_IMAGE	:
					if (otype == 1)
						break;
					else	continue;
				case	__3D_FORM	:
					if (otype == 2)
						break;
					else	continue;
				}
#endif				
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
					xml_put_filename_string(h,"TEXT",optr->name,2);
					break;
				case	__3D_FORM	:
					xml_put_filename_string(h,"FORM",optr->name,2);
					break;
				case	__3D_IMAGE	:
					xml_put_filename_string(h,"IMAGE",optr->name,2);
					break;
				default			:
					xml_put_filename_string(h,"NAME",optr->name,2);
					break;
				}

			indent(h,1);
			fprintf(h,"</OBJECT>");
			linefeed(h);
			}
#ifdef	SORT_DURING_SAVE
			}
#endif
		fprintf(h,"</THREED>");
		linefeed(h);

		close_production_target(h,sname);

		for (	optr=kptr->first;
			optr != (struct object3d *) 0;
			optr = optr->next ) {
			switch ( optr->nature ) {
				case	__3D_FORM	:
					if ((fptr = optr->payload) != (struct form_control *) 0) {
						if (( fptr->loadstamp < fptr->savestamp )
						||  ( fptr->outofdate )
						||  ( ModelControl.saveall )) {
							if (ModelControl.saveimages )
								save_form_image( optr->name, optr->image, optr->options, 0  );
							if (( ModelControl.savemembers )
							||  ( fptr->outofdate ))
								save_Form( fptr, automatic, sname );
 							fptr->loadstamp = fptr->savestamp = time((long*)0);
							}
						}
					break;
				}
			}
		/* liberate project name now */
		/* ------------------------- */
		liberate( sname );
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
	struct	link_control	* lptr;

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
			case	DATABASE_LINK	:
				xptr->payload[1] = (void *) 0;
				if (!( lptr = allocate_link_control()) != (struct link_control*) 0)
					return(27);
				else	xptr->payload[1] = lptr;
				break;

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
			case	ELEMENT_GRIDLOCK	:
				WidgetGridLock.widget = WidgetGridLock.value = -1;
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


public	int	quoted_atoi( char * vptr )
{
	if ( *vptr == __QUOTE )
		vptr++;
	return( atoi( vptr ) );
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

		case	ELEMENT_WIDGET	: /* these two provide the atributs for */
		case	ELEMENT_VALUE	: /* the grid lock element		*/

		case	DATABASE_HYPERVIEW	:
		case	DATABASE_FRACTION	:
		case	DATABASE_HELP  		:
		case	DATABASE_TRACING	:
		case	DATABASE_COLOUR		:
		case	DATABASE_PADDING	:
		case	DATABASE_YPADDING	:
		case	DATABASE_XPADDING	:
		case	DATABASE_MARGIN		:
		case	DATABASE_DEPTH		:
		case	DATABASE_JOINTURE	:

		case	ELEMENT_OPTION	:
		case	ELEMENT_NAME 	:
		case	DATABASE_X	:
		case	DATABASE_Y	:
		case	DATABASE_CLASS	:
		case	DATABASE_SIZE 	:
		case	DATABASE_TYPE	:
			xptr->heap[xptr->nested++]=i;
			break;

		case	ELEMENT_SOURCE		:	
		case	ELEMENT_TARGET		:	
			if ( xptr->heap[(xptr->nested-1)] == ELEMENT_TREEVIEW ) {
				xptr->heap[xptr->nested++]=i;
				break;
				}
			else if ( xptr->heap[(xptr->nested-1)] == DATABASE_LINK ) {
				xptr->heap[xptr->nested++]=i;
				break;
				}
			else if ( xptr->strict ) {
				sprintf(xptr->buffer,"unknown atb : %s",name);	
				status_message( xptr->buffer,2);		
				return(30);					
				}						
			else	break;

		case	ELEMENT_WIDTH		:
			if ( xptr->heap[(xptr->nested-1)] == ELEMENT_DATABASE ) {
				xptr->heap[xptr->nested++]=i;
				break;
				}
		case	ELEMENT_FONT		:	
		case	ELEMENT_ZONE		:	
		case	ELEMENT_SPACING		:	
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

private	int	database_editor_atb_value(int i,struct xml_application * xptr, char * value )
{
	if ( xptr->heap[(xptr->nested-1)] != ELEMENT_DATABASE )
		return(30);

	switch ( i ) {
		case	DATABASE_HYPERVIEW	:
			VDE.hyperspace = quoted_atoi(value); break;
		case	DATABASE_FRACTION	:
			VDE.fraction = quoted_atoi(value); break;
		case	DATABASE_HELP  		:
			VDE.bubblehelp = quoted_atoi(value); break;
		case	DATABASE_TRACING	:
			VDE.bender = quoted_atoi(value); break;
		case	DATABASE_COLOUR		:
			VDE.tracecolour= quoted_atoi(value); break;
		case	ELEMENT_WIDTH  		:
			VDE.tracewidth= quoted_atoi(value); break;
		case	DATABASE_PADDING	:
			VDE.xpadding = VDE.ypadding = quoted_atoi(value); break;
		case	DATABASE_XPADDING	:
			VDE.xpadding = quoted_atoi(value); break;
		case	DATABASE_YPADDING	:
			VDE.ypadding = quoted_atoi(value); break;
		case	DATABASE_MARGIN		:
			VDE.tracepadding = quoted_atoi(value); break;
		case	DATABASE_DEPTH		:
			VDE.depth = quoted_atoi(value); break;
		default				:
			if ( xptr->strict ) {
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
	struct	link_control	* lptr;

	/* TREEVIEW Atributs */
	/* ----------------- */
	switch ((i = xptr->heap[--xptr->nested])) {
		case	DATABASE_HYPERVIEW	:
		case	DATABASE_FRACTION	:
		case	DATABASE_HELP  		:
		case	DATABASE_TRACING	:
		case	DATABASE_COLOUR		:
		case	DATABASE_PADDING	:
		case	DATABASE_XPADDING	:
		case	DATABASE_YPADDING	:
		case	DATABASE_MARGIN		:
		case	DATABASE_DEPTH		:
			return( database_editor_atb_value(i, xptr, value ) );

		case	ELEMENT_WIDGET		: WidgetGridLock.widget	= quoted_atoi( value ); return(0);
		case	ELEMENT_VALUE 		: WidgetGridLock.value	= quoted_atoi( value ); return(0);
		case	ELEMENT_FONT		: TreeConf.font 	= quoted_atoi( value ); return(0);
		case	ELEMENT_ZONE		: TreeConf.zonage	= quoted_atoi( value ); return(0);
		case	ELEMENT_SPACING		: TreeConf.spacing	= quoted_atoi( value ); return(0);	
		case	DATABASE_JOINTURE	:
			if ( xptr->heap[(xptr->nested-1)] != DATABASE_LINK ) 
				break;
			else if (!(  lptr = xptr->payload[1] ))
				return(30);
			else	{
				lptr->jointure = allocate_string( value );
				return(0);
				}

		case	ELEMENT_NAME		:
			if ( xptr->heap[(xptr->nested-1)] != DATABASE_LINK ) 
				break;
			else if (!(  lptr = xptr->payload[1] ))
				return(30);
			else	{
				lptr->name = allocate_string( value );
				return(0);
				}

		case	DATABASE_TYPE		:
			if ( xptr->heap[(xptr->nested-1)] != DATABASE_LINK ) 
				break;
			else if (!(  lptr = xptr->payload[1] ))
				return(30);
			else	{
				lptr->nature = quoted_atoi( value );
				return(0);
				}

		case	ELEMENT_SOURCE		: 
			if ( xptr->heap[(xptr->nested-1)] != DATABASE_LINK ) {
				TreeConf.source 	= quoted_atoi( value ); return(0);	
				}
			else if (!(  lptr = xptr->payload[1] ))
				return(30);
			else	{
				lptr->source = allocate_string( value );
				return(0);
				}			
		case	ELEMENT_TARGET		: 
			if ( xptr->heap[(xptr->nested-1)] != DATABASE_LINK ) {
				TreeConf.target 	= quoted_atoi( value ); return(0);		
				}
			else if (!(  lptr = xptr->payload[1] ))
				return(30);
			else	{
				lptr->target = allocate_string( value );
				return(0);
				}			

		case	ELEMENT_PACKAGE		: TreeConf.packaging 	= quoted_atoi( value ); return(0);		
		case	ELEMENT_IDENTITY	: TreeConf.identity	= quoted_atoi( value ); return(0);		
		case	ELEMENT_WIDTH    	: 
			if (!( database_editor_atb_value( i, xptr, value )))
				return(0);
			else	{
				TreeConf.width = quoted_atoi( value ); 
				return(0);		
				}
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

		case	ELEMENT_OPTION 	:
			fptr->state = quoted_atoi( value ); return(0);

		case	DATABASE_X	:
			fptr->x = quoted_atoi( value ); return(0);

		case	DATABASE_Y	:
			fptr->y = quoted_atoi( value ); return(0);

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
			break;

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

private	char *	add_data_format_member( char * rptr, char * pptr, char * sptr )
{
	char *	xptr;

	if (!( xptr = allocate( strlen( rptr ) + strlen( pptr ) + strlen( sptr ) + 64 ) )) {
		allocate_failure();
		return( rptr );
		}
	else	{
		sprintf(xptr,"%s%s%s",rptr,pptr,sptr);
		liberate( rptr );
		return( xptr );
		}
}

private	void	xml_get_database_language(struct xml_application * xptr, int id)
{
	struct file_control * fptr;

	if ( xptr->heap[ (xptr->nested-1) ] == DATABASE_COMMENT ) {
		switch ( xptr->heap[ (xptr->nested-2) ]  ) {
			case	DATABASE_SQFILE	:
			case	DATABASE_SIFILE	:
			case	DATABASE_MCFILE	:
			case	DATABASE_DBFILE	:
			case	DATABASE_VMEMORY:
				if ((fptr = xptr->payload[1]) ) 
					xml_get_text(xptr, &fptr->document[id] );
			}
		}
	return;
}

private	int	xml_close_camera_tag(struct xml_application * xptr)
{
	int	i;
	struct	camera3d 	* kptr;
	struct	object3d 	* optr;
	struct	link_control	* lptr;
	struct	file_control	* fptr;
	struct	file_control	* ffptr;
#ifdef	ABAL32A
	struct	application_parameters * aptr;
#endif
	if (!( kptr = xptr->payload[0] )) {
		sprintf(xptr->buffer,"unexpected close");
		status_message(xptr->buffer,3);
		return(41);
		}
	else if ( xptr->nested ) {
#ifdef	ABAL32A
		aptr = kptr->application;
#endif
		i = xptr->heap[--xptr->nested];
		*(xptr->buffer + xptr->offset) = 0;
		if ( i != MAX_ELEMENT ) {
			if ( xptr->echo ) { printf("</%s>\r\n",XmlElement[i]); }
			}

		switch ( i ) {

			case	DATABASE_LINK		:
				if ((lptr = xptr->payload[1]) != (struct link_control*) 0)
					store_database_link( lptr );
				break;

			case 	DATABASE_COMMENT	:
			case 	DATABASE_TOOL		:       
				break;
			case 	DATABASE_ENGLISH	: xml_get_database_language(xptr,0); break;
			case 	DATABASE_FRANCAIS	: xml_get_database_language(xptr,1); break;
			case 	DATABASE_ITALIANO	: xml_get_database_language(xptr,2); break;
			case 	DATABASE_ESPAGNOL	: xml_get_database_language(xptr,3); break;
			case 	DATABASE_DEUTSCH	: xml_get_database_language(xptr,4); break;
			case 	DATABASE_NEDERLANDS 	: xml_get_database_language(xptr,5); break;
			case 	DATABASE_PORTUGUES  	: xml_get_database_language(xptr,6); break;
			case 	DATABASE_OTHER		: xml_get_database_language(xptr,7); break;
					
			case	DATABASE_SQFILE	:
			case	DATABASE_SIFILE	:
			case	DATABASE_MCFILE	:
			case	DATABASE_DBFILE	:
			case	DATABASE_VMEMORY:

				if ((fptr = xptr->payload[1]) != (struct file_control*) 0) {
					if ((ffptr = AddFileClass((void*)0,fptr->nature,fptr->classname,fptr->identity,fptr->filename,fptr->format)) != (struct file_control *) 0) {
						transfer_file_comment((void *) 0, ffptr, fptr );
						ffptr->x = fptr->x;
						ffptr->y = fptr->y;
						ffptr->state = fptr->state;
						}
					liberate_file_control((void *) 0, fptr );
					}
				xptr->payload[1] = (void*) 0;
				break;
			case	DATABASE_FILLER	:
			case	DATABASE_FIELD  :
			case	DATABASE_MEMBER	:
				if ((fptr = xptr->payload[1]) != (struct file_control*) 0) {
					if ( fptr->members )
						fptr->format = add_data_format_member( fptr->format, " , ",xptr->buffer);
					else	fptr->format = add_data_format_member( fptr->format, " : ",xptr->buffer);
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

			case	ELEMENT_VIEW		:
				camera_new_view( kptr );
				break;
				
			case	ELEMENT_LOCKON		:
				xml_get_word( xptr, &Context.lockon );
				break;

			case	ELEMENT_GRIDTYPE	:
				xml_get_word( xptr, &Context.gridtype );
				configure_gridlock(Context.gridtype);
				break;

			case	ELEMENT_GRIDLOCK	:
				if (( WidgetGridLock.widget != -1 ) &&  ( WidgetGridLock.value  != -1 )) {
					set_widget_gridlock( WidgetGridLock.widget, WidgetGridLock.value );
					}
				break;

			case	MAX_ELEMENT		:
				break;

			case	ELEMENT_BASE		:
			case	ELEMENT_THREED		:
				xptr->payload[0] = (struct camera3d*) 0;
				break;

			case	ELEMENT_OBJECT		:
				if ( xptr->payload[1] ) {
					load_CameraItem(xptr->payload[1], ( _INHIBIT_REFRESH | _INHIBIT_PROPERTIES));
					xptr->payload[1] = (struct object3d*) 0;
					}
				break;

			case	ELEMENT_IMAGE		:
				if ( xptr->heap[(xptr->nested-1)] == ELEMENT_THREED ) {
					xml_get_filename_string( xptr, & kptr->background->iname );
					break;
					}
				else if ( xptr->heap[(xptr->nested-1)] == ELEMENT_OBJECT ) {
					if (!( optr = xptr->payload[1] ))
						break;
					else	xml_get_filename_string( xptr, & optr->name );
					}
				break;

			case	ELEMENT_NAME		:
				if ( xptr->heap[(xptr->nested-1)] == ELEMENT_THREED ) {
					/* ------------------------------------- */
					/* this kills the full path name version */
					/* xml_get_string( xptr, & kptr->name ); */
					/* ------------------------------------- */
					break;
					}
			case	ELEMENT_FORM		:
			case	ELEMENT_TEXT		:
				if ( xptr->heap[(xptr->nested-1)] == ELEMENT_OBJECT ) {
					if (!( optr = xptr->payload[1] ))
						break;
					else	xml_get_filename_string( xptr, & optr->name );
					}
				break;

			case	ELEMENT_VECTOR		:
				xml_get_xyz( xptr, &Vektor.x,&Vektor.y,&Vektor.z);
				break;

			case	ELEMENT_SIZES		:
				xml_get_xyz( xptr, &DefaultSizes.x,&DefaultSizes.y,&DefaultSizes.z);
				break;
			case	ELEMENT_POSITION	:
				xml_get_xyz( xptr, &kptr->position.x,&kptr->position.y,&kptr->position.z );
				break;
			case	ELEMENT_FOCUS		:
				xml_get_xy( xptr, &kptr->focus.x,&kptr->focus.y );
				break;
			case	ELEMENT_DIRECTION	:
				xml_get_word( xptr, &kptr->direction );
				break;
			case	ELEMENT_MOVEMENT	:
				xml_get_word( xptr, &movement );
				break;
			case	ELEMENT_TIMER		:
				xml_get_word( xptr, &kptr->timer );
				break;
			case	ELEMENT_STEP		:
				xml_get_word( xptr, &kptr->step );
				break;
			case	ELEMENT_ROLLBACK	:
				xml_get_word( xptr, &Context.rollback );
				if ( Context.rollback )
					Context.rollback = 1;
				else	Context.rollback = 0;
				break;
			case	ELEMENT_PRODUCTION	:
#ifdef	ABAL32A
				xml_get_word( xptr, &aptr->productiontype );
#else
				xml_get_word( xptr, &Application.productiontype );
#endif
				break;
			case	ELEMENT_TARGET		:
#ifdef	ABAL32A
				xml_get_filename_string( xptr, &aptr->target );
#else
				xml_get_filename_string( xptr, &Application.target );
#endif
				break;
			case	ELEMENT_LANGUAGE	:
				if ( xptr->heap[(xptr->nested-1)] == ELEMENT_HTML_PRODUCTION )
					xml_get_word( xptr, &Document.language );
#ifdef	ABAL32A
				else	xml_get_word( xptr, &aptr->language );
#else
				else	xml_get_word( xptr, &Application.language );
#endif
				break;
			case	ELEMENT_NATLANG	:
				xml_get_word( xptr, &Context.natlang );
				break;
			case	ELEMENT_USESTYLE:
				xml_get_word( xptr, &Context.usestyle);
				break;
			case	ELEMENT_TESTDATA:
				xml_get_word( xptr, &Context.UseTestData);
				break;
			case	ELEMENT_PROJECT		:
#ifdef	ABAL32A
				xml_get_word( xptr, &aptr->makefile );
#else
				xml_get_word( xptr, &Application.makefile );
#endif
				break;
			case	ELEMENT_STYLE		:
#ifdef	ABAL32A
				xml_get_filename_string( xptr, &aptr->stylesheet );
#else
				xml_get_filename_string( xptr, &Application.stylesheet );
#endif
				break;
			case	ELEMENT_MAKEFILE	:
#ifdef	ABAL32A
				xml_get_filename_string( xptr, &aptr->makename );
#else
				xml_get_filename_string( xptr, &Application.makename );
#endif
				break;
			case	ELEMENT_CONFIGURE	:
				xml_get_string( xptr, &kptr->configuration );
				if (!( is_valid_method( kptr->configuration )))
					kptr->configuration = allocate_string( "visual" );
				if ( is_valid_method( kptr->configuration )) {
					LoadConfiguration( kptr->configuration);
					}
				break;

			case	ELEMENT_TEMPLATE	:
#ifdef	ABAL32A
				xml_get_filename_string( xptr, &aptr->template );
#else
				xml_get_filename_string( xptr, &Application.template );
#endif
				break;

			case	ELEMENT_MODULES 	:
#ifdef	ABAL32A
				xml_get_filename_string( xptr, &aptr->modules  );
#else
				xml_get_filename_string( xptr, &Application.modules  );
#endif
				break;
			case	ELEMENT_COMPONENTS 	:
#ifdef	ABAL32A
				xml_get_filename_string( xptr, &aptr->components );
#endif
				break;

			case	ELEMENT_FORMULAIRES	:
#ifdef	ABAL32A
				xml_get_filename_string( xptr, &aptr->formulaires  );
#else
				xml_get_filename_string( xptr, &Application.formulaires  );
#endif
				break;
				

			case	ELEMENT_REPSOURCES 	:
#ifdef	ABAL32A
				xml_get_filename_string( xptr, &aptr->src_product  );
#else
				xml_get_filename_string( xptr, &Application.src_product  );
#endif
				break;
				
			case	ELEMENT_BINAIRES 	:
#ifdef	ABAL32A
				xml_get_filename_string( xptr, &aptr->obj_product  );
#else
				xml_get_filename_string( xptr, &Application.obj_product  );
#endif
				break;

			case	ELEMENT_DATABASE	:
#ifdef	ABAL32A
				xml_get_filename_string( xptr, &aptr->databasename );
				if ( aptr->databasename ) {
					load_XmlDataBase( kptr, aptr->databasename, ( _INHIBIT_REFRESH | _INHIBIT_PROPERTIES) );
					}
#else
				xml_get_filename_string( xptr, &Application.databasename );
				if ( Application.databasename ) {
					load_XmlDataBase( kptr, Application.databasename, ( _INHIBIT_REFRESH | _INHIBIT_PROPERTIES) );
					}
#endif
				break;

			
			case ELEMENT_TREEVIEW		:
				reconfigure_treeview();
				break;

			case	ELEMENT_PALETTE 	:
#ifdef	ABAL32A
				xml_get_filename_string( xptr, &aptr->palettename );
				use_application_palette();
#else
				xml_get_filename_string( xptr, &Application.palettename );
				if ( Application.palettename ) {
					visual_palette(Application.palettename, strlen( Application.palettename ) );
					}
#endif
				break;

			case	ELEMENT_ICONS 		:
#ifdef	ABAL32A
				xml_get_word( xptr, &aptr->imagetype );
#else
				xml_get_word( xptr, &Application.imagetype );
#endif	
				break;

			case	ELEMENT_OPTION		:
				if ( xptr->heap[(xptr->nested-1)] == ELEMENT_THREED ) {
					xml_get_word( xptr, &kptr->options );
#ifdef	ABAL32A
					context_is_uptodate( kptr );
#endif
					break;
					}
				else if ( xptr->heap[(xptr->nested-1)] == ELEMENT_OBJECT ) {
					if (!( optr = xptr->payload[1] ))
						break;
					else	{
						xml_get_word( xptr, & optr->options );
						}
					}
				break;

			case	ELEMENT_FILL		:
				xml_get_word( xptr, &i );
				kptr->background->colour = (i & 0x00FF);
				kptr->background->style = (i >> 8);
				break;

			case	ELEMENT_DOCUMENT	:
#ifdef	ABAL32A
				xml_get_word( xptr, &aptr->isdocument );
#else
				xml_get_word( xptr, &Application.isdocument );
#endif
				break;

			case	ELEMENT_DOCNAME 	:
#ifdef	ABAL32A
				xml_get_filename_string( xptr, &aptr->document );
#else
				xml_get_filename_string( xptr, &Application.document );
#endif
				break;

			case	ELEMENT_TOPLEFT		:
				if (( xptr->heap[(xptr->nested-1)] == ELEMENT_OBJECT )
				&&  (( optr = xptr->payload[1] ) != (struct object3d *) 0)) 
					xml_get_xyz( xptr, &optr->topleft.x,&optr->topleft.y,&optr->topleft.z );
				break;
				
			case	ELEMENT_BOTTOMRIGHT	:
				if (( xptr->heap[(xptr->nested-1)] == ELEMENT_OBJECT )
				&&  (( optr = xptr->payload[1] ) != (struct object3d *) 0)) 
					xml_get_xyz( xptr, &optr->bottomright.x,&optr->bottomright.y,&optr->bottomright.z );
				break;
					

			case	ELEMENT_NATURE		:
				if (( xptr->heap[(xptr->nested-1)] == ELEMENT_OBJECT )
				&&  (( optr = xptr->payload[1] ) != (struct object3d *) 0)) 
					xml_get_word( xptr, &optr->nature );
				break;

			case	ELEMENT_XLR		:
				if (( xptr->heap[(xptr->nested-1)] == ELEMENT_OBJECT )
				&&  (( optr = xptr->payload[1] ) != (struct object3d *) 0)) 
					xml_get_xy(xptr,&optr->colours.left,&optr->colours.right);
				break;

			case	ELEMENT_YUL		:
				if (( xptr->heap[(xptr->nested-1)] == ELEMENT_OBJECT )
				&&  (( optr = xptr->payload[1] ) != (struct object3d *) 0)) 
					xml_get_xy(xptr,&optr->colours.upper,&optr->colours.lower);
				break;

			case	ELEMENT_ZFB		:
				if (( xptr->heap[(xptr->nested-1)] == ELEMENT_OBJECT )
				&&  (( optr = xptr->payload[1] ) != (struct object3d *) 0)) 
					xml_get_xy(xptr,&optr->colours.front,&optr->colours.back);
				break;

			case	ELEMENT_SHL		:
				if (( xptr->heap[(xptr->nested-1)] == ELEMENT_OBJECT )
				&&  (( optr = xptr->payload[1] ) != (struct object3d *) 0)) 
					xml_get_xy(xptr,&optr->colours.shadow,&optr->colours.light);
				break;

			case	ELEMENT_EXTENSION		:
				xml_get_word(xptr, &Context.BalOrAbal);
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
			case	ELEMENT_METRIC	:
				if ( xptr->heap[(xptr->nested-1)] == ELEMENT_HTML_PRODUCTION )
					xml_get_word( xptr, &Document.metric);
				break;
			case	ELEMENT_SCALE		:
				if ( xptr->heap[(xptr->nested-1)] == ELEMENT_HTML_PRODUCTION )
					xml_get_word( xptr, &Document.scale);
				break;
			case	ELEMENT_FOOTER			:
				if ( xptr->heap[(xptr->nested-1)] == ELEMENT_HTML_PRODUCTION )
					xml_get_string( xptr, &Document.footer );
				break;
			case	ELEMENT_PATH			:
				if ( xptr->heap[(xptr->nested-1)] == ELEMENT_HTML_PRODUCTION )
					xml_get_filename_string( xptr, &Document.pathroot );
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
	struct	file_manager * fptr=(struct file_manager *) 0;
	int	status;
	char *	dptr;

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
	char *app_forms,*vtrav;

	if (!( cptr ))
		return((struct camera3d*) 0);

	else if (!( loadname = allocate_string( loadname )))
		return((struct camera3d*) 0);
	else if (!( loadname = enforce_extension( loadname, XML_EXTENSION ) ))
		return((struct camera3d*) 0);


	if ( loadname )
		if (!( automatic & _INHIBIT_STATUS ))
			status_message( loadname,3);

	if ( method_is_valid((app_forms = application_forms_folder())) )  {
		add_path_terminator(&app_forms);
		vtrav=relative_filename(loadname, app_forms);
		liberate(app_forms);
		liberate(loadname);
		loadname=vtrav;
		};

	if ((fptr = resolve_file_manager((void*)0,loadname)) != (struct file_manager *) 0)
		connect_camera_database( cptr, fptr );
	else if (( fptr = allocate_file_manager((void*) 0,loadname)) != (struct file_manager *) 0) {
		connect_camera_database( cptr, fptr );
		if ((status = xml_parse( loadname,& relays, cptr )) != 0 ) {
			status_message("xml parse failure",3);
			}
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
		status_message("xml parse failure",3);
		}

	/* Ensure Project is as explicitly named */
	/* ------------------------------------- */
	if ( loadname ) {
		if ( cptr->name )
			cptr->name = liberate( cptr->name );
		cptr->name = allocate_string( loadname );
		}

	if ( application_template() ) 	{	LoadTemplate(cptr);				}

	use_camera_environment( cptr );

 
	return( cptr );
}

#endif	/* _xmlthree_c */
	/* ----------- */

