
#ifndef	_xmlform_c
#define	_xmlform_c

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
#include "singmemb.h"
#include "singtool.h"
#include "singtext.h"
#include "singimg.h"
#include "singdesk.h"
#include "visual.h"

#include "xmlparse.h"
#include "xmlform.h"
#include "abaltype.h"
#include "singfile.h"
#include "singxml.h"

extern	char * workbuffer;

public	int				  xml_error_handler( char * nomfic, int status, int nblin );
public	struct	form_item 		* allocate_for_Widget();
public	struct	forms_method		* allocate_for_Method();
public	struct	forms_data_member	* allocate_for_Member();
static	int			CurrentAtbName=0;

#include "singappl.h"
extern	struct	application_parameters Application;

static	int	resolve_xml_align( char * sptr )
{
	if (!( strcmp( sptr, "(none)" ) ))
		return(0);
	else if (!( strcmp( sptr, "(block)" ) ))
		return(0);
	else if (!( strcmp( sptr, "(text)" ) ))
		return(0);
	else if (!( strcmp( sptr, "(left)" ) ))
		return(2);
	else if (!( strcmp( sptr, "(disk)" ) ))
		return(2);
	else if (!( strcmp( sptr, "(right)" ) ))
		return(1);
	else if (!( strcmp( sptr, "(frame)" ) ))
		return(1);
	else if (!( strcmp( sptr, "(image)" ) ))
		return(1);
	else if (!( strcmp( sptr, "(center)" ) ))
		return(3);
	else if (!( strcmp( sptr, "(circle)" ) ))
		return(4);
	else	return(4);
}

public	char *	join_widget_style( struct form_item * iptr )
{
	char *	rptr;
	int	rlen=0;
	if ( iptr->Contents.stylesheet )
		rlen += strlen( iptr->Contents.stylesheet );
	if ( iptr->Contents.stylefocus )
		rlen += strlen( iptr->Contents.stylefocus );
	if ( iptr->Contents.stylepress )
		rlen += strlen( iptr->Contents.stylepress );

	if (!( rlen ))
		return( (char *) 0 );
	else if (!( rptr = allocate( rlen + 16 ) ))
		return(rptr);
	else	{
		*rptr=0;
		if ( iptr->Contents.stylesheet )
			strcat(rptr,iptr->Contents.stylesheet);
		if ( iptr->Contents.stylefocus ) {
			strcat(rptr,",");
			strcat(rptr,iptr->Contents.stylefocus);
			}
		if ( iptr->Contents.stylepress ) {
			if (!( rptr ))
				strcat(rptr,",");
			strcat(rptr,",");
			strcat(rptr,iptr->Contents.stylepress);
			}
		return(rptr);
		}
}

public	void	separate_widget_style( struct form_item * wptr, char * sptr )
{
	char	*	fcptr=(char *) 0;
	char	*	shptr=(char *) 0;
	char	*	prptr=(char *) 0;
	int	i;
	if (!( wptr ))
		return;

	if ( wptr->Contents.stylesheet )
		wptr->Contents.stylesheet = liberate( wptr->Contents.stylesheet );

	if ( wptr->Contents.stylefocus )
		wptr->Contents.stylefocus = liberate( wptr->Contents.stylefocus );

	if ( wptr->Contents.stylepress )
		wptr->Contents.stylepress = liberate( wptr->Contents.stylepress );

	if (!( shptr = sptr ))
		return;

	for (i=0; *(sptr+i) != 0; i++ ) {
		if ( *(sptr+i) == ',' ) {
			if (!( fcptr ))
				fcptr = (sptr+i+1);
			else if (!( prptr ))
				prptr = (sptr+i+1);
			}
		}
	if ( prptr ) {
		*(prptr-1) = 0;
		wptr->Contents.stylepress = allocate_string( prptr );
		}
	if ( fcptr ) {
		*(fcptr-1) = 0;
		wptr->Contents.stylefocus = allocate_string( fcptr );
		}
	if ( shptr ) {
		wptr->Contents.stylesheet = allocate_string( shptr );
		}

	liberate( sptr );
	return;
}

public	void	xml_put_payload(FILE * h, char * name, char * value, int margin)
{
	if ((!( name )) || (!( value )))
		return;
	indent(h,margin);
	fprintf(h,"<%s>",name);
	xml_put_cdata(h,value);
	fprintf(h,"</%s>",name);
	linefeed(h);
	return;
}

public 	void	xml_put_coordinate(FILE * h, char * name, int x, int y, int margin)
{
	indent(h,margin);
	fprintf(h,"<%s>%u %u</%s>",name,x,y,name);
	linefeed(h);
	return;
}

public 	void	xml_put_xyz(FILE * h, char * name, int x, int y, int z, int margin)
{
	indent(h,margin);
	fprintf(h,"<%s>%u %u %u</%s>",name,x,y,z,name);
	linefeed(h);
	return;
}

private	void	xml_put_method(FILE * h, char * tag, char * text, int margin )
{
	linefeed(h); 
	indent(h,margin); 
	fprintf(h,"<%s>",tag); xml_put_cdata(h, text ); fprintf(h,"</%s>",tag);
	linefeed(h);
	
}

private	void	xml_put_member(FILE * h, char * tag, char * text, int margin )
{
	linefeed(h); 
	indent(h,margin); 
	fprintf(h,"<%s>",tag); xml_put_cdata(h, text ); fprintf(h,"</%s>",tag);
	linefeed(h);
	
}

private	void	xml_put_event(FILE * h, char * tag, int options, char * text, int margin )
{
	indent(h,margin);
	fprintf(h,"<%s><OPTION>%u</OPTION>",tag,options);
	if ( method_is_valid( text ) ) {
		linefeed(h); 
		xml_put_method(h,"TEXT" ,text,margin);
		indent(h,margin);
		}
	fprintf(h,"</%s>",tag);
	linefeed(h);
	return;
}

private	void	xml_put_margin(FILE * h, char * tag, char * value, int type, int margin )
{
	indent(h,margin);
	if ( value )
		fprintf(h,"<%sMARGIN>%s %u</%sMARGIN>",tag,value,type,tag);
	else	fprintf(h,"<%sMARGIN>0  %u</%sMARGIN>",tag,type,tag);
	linefeed(h);
}

public 	void	xml_put_helptext(FILE * h, char * tag, char * sptr, int margin)
{
	int	c;
	if (!( sptr  ))
		return;
	else if (!( *sptr ))
		return;
	else	{
		indent(h,margin);
		fprintf(h,"<%s>",tag); xml_put_cdata( h, sptr ); fprintf(h,"</%s>",tag);	
		linefeed(h);
		}
	return;
}

public	void	string_print_member(char * rptr, struct forms_data_member * dptr)
{
	int	v;
	*rptr = 0;
	switch ( dptr->type ) {
		case	_ABAL_FIELD	:
			if (!( method_is_valid( dptr->name ) )) 
				sprintf(rptr,"FIELD=M");
			else	sprintf(rptr,"FIELD=M,%s",dptr->name);
			break;
		case	_ABAL_FILLER	:
			sprintf(rptr,"Filler=%u",dptr->size);
			break;
		default			:
			if (!( method_is_valid( dptr->name ) )) 
				break;
			switch ( dptr->type ) {
				case	_ABAL_BYTE	: 
					sprintf(rptr,"%s#",dptr->name);
					break;
				case	_ABAL_WORD	: 
					sprintf(rptr,"%s%c",dptr->name,0x0025); 	
					break;
				case	_ABAL_LONG	: 
					sprintf(rptr,"%s:",dptr->name); 		
					break;
				case	_ABAL_STRING	: 
					sprintf(rptr,"%s$=%u",dptr->name,dptr->size);	
					break;
				case	_ABAL_BCD	: 
					sprintf(rptr,"%s=%u",dptr->name,dptr->size);	
					break;
				}
			rptr += strlen( rptr );
			if ((v=dptr->first) != 0) {
				sprintf(rptr,"(%u",v);
				rptr += strlen( rptr );	
				if ((v=dptr->second) != 0)
					sprintf(rptr,",%u)",v);
				else	sprintf(rptr,")");	
				}
		}
	return;
}

public 	FILE *	open_xml_target( char * xmlname, char ** target, char * document, char * dtdname, char * cssname )
{
	char	*	sname;
	FILE 	*	h=(FILE*) 0;

	*target = (char *) 0;

	if (!( sname = allocate_string( xmlname ) ))
		return(h);

	else if (!( sname = enforce_extension( sname,".xml") ))
		return(h);

	if (!(h = open_production_target(sname,0))) {
		liberate( sname );
		return(h);
		}

	else	{
		status_message(sname,3);

		fprintf(h,"<?xml version=%c1.0%c encoding=%cutf-8%c?>",
			0x0022,0x0022,0x0022,0x0022);
		linefeed(h);

		fprintf(h,"<?xml-stylesheet type=%ctext/css%c href=%c%s%c?>",
			0x0022,0x0022,0x0022,cssname,0x0022);
		linefeed(h);

		if ( dtdname != (char *) 0 ) {
			fprintf(h,"<!DOCTYPE %s SYSTEM %c%s%c>",document,0x0022,dtdname,0x0022);
			linefeed(h);
			}

		fprintf(h,"<!-- FILENAME %s -->",sname);
		linefeed(h);
		
		*target = sname;

		return( h );

		}
}

private	void classnamecorrection(char * sptr )
{
	while ( *sptr )
	{
		if ( *sptr == '-' )
			*sptr = '_';
		sptr++;
	}
}

public 	void	xml_put_Form( char * nptr, struct form_control * fptr, char * dtdname )
{
	char *	sptr;
	FILE * h;
	char * fmptr;
	char * sname=(char *) 0;
	struct	form_item * iptr;
	struct	forms_method * mptr;
	struct	forms_data_member * dptr;
	int	i;
	if ((h = open_xml_target( nptr, &sname,"FORM", xml_form_type, xml_form_style )) != (FILE*) 0) {

		if (( fptr->x != -1 )
		&&  ( fptr->y != -1 )) 
			fprintf(h,"<FORM X=%u Y=%u FLOW=%u>",fptr->x,fptr->y,fptr->flow);
		else	fprintf(h,"<FORM>");

		linefeed(h);
		xml_put_string(h,"IDENTIFIER",fptr->identifier,1);
		switch ( fptr->language ) {
			case	_GENERATE_C	: sptr = "C"; break;
			case	_GENERATE_CPP	: sptr = "C++"; break;
			case	_GENERATE_PHP	: sptr = "PHP"; break;
			case	_GENERATE_NODE	: sptr = "NODE"; break;
			case	_GENERATE_REACT	: sptr = "REACT"; break;
			case	_GENERATE_BAL	: sptr = "ABAL"; break;
			case	_GENERATE_ABAL	: sptr = "ABAL++"; break;
			case	_GENERATE_HTML	: sptr = "HTML"; break;
			case	_GENERATE_JAVA	: sptr = "JAVA"; break;
			case	_GENERATE_COBOL : sptr = "COBOL"; break;
			case	_GENERATE_BIFS  : sptr = "BIFS"; break;
			case	_GENERATE_XMTA  : sptr = "XMTA"; break;
			case	_GENERATE_LASER : sptr = "LASER"; break;
			case	_GENERATE_ANDROID : sptr = "ANDROID"; break;
			default			: sptr = "UNKNOWN"; break;
			}
		xml_put_string(h,"LANGUAGE",sptr,1);
		xml_put_word(h,"FLAGS", 	fptr->abal.flags,1);
		xml_put_word(h,"VALUES", 	fptr->abal.values,1);
		xml_put_word(h,"MEMORY", 	fptr->abal.diezemem,1);
		xml_put_word(h,"FILES", 	fptr->abal.diezefiles,1);
		xml_put_word(h,"STACK", 	fptr->abal.diezestack,1);
		xml_put_word(h,"HEAP"	, 	fptr->abal.diezeheap,1);
		xml_put_word(h,"TOKENSIZE", 	fptr->abal.tokensize,1);
		xml_put_word(h,"LABELSIZE", 	fptr->abal.labelsize,1);
		xml_put_word(h,"GRID", 		fptr->gridsize,1);
		if ( fptr->abal.flags & 512 ) {
			xml_put_string(h,"PRAGMAFILE", 	fptr->abal.pragmafile,1);
			}

		xml_put_word(h,"NATIONAL",fptr->natlang,1);
		xml_put_word(h,"FLUSH",fptr->inhibit_flush,1);
		xml_put_word(h,"ASKATB",fptr->askatb,1);
		xml_put_word(h,"ASKFORE",fptr->askfore,1);
		xml_put_word(h,"ASKBACK",fptr->askback,1);

		if ( fptr->formflags & _FORM_CONSTANTS )
			xml_put_word(h,"CONSTANTS",1,1);
		else	xml_put_word(h,"CONSTANTS",0,1);

		xml_put_word(h,"HELP",fptr->onlinehelp,1);
		xml_put_word(h,"EXTENSION",fptr->extension,1);
		indent(h,1);
		fprintf(h,"<RESIZE>");
		if ( fptr->resizeauto )
			fprintf(h,"1 %u %u",fptr->resizew,fptr->resizeh);
		else	fprintf(h,"0 %u %u",fptr->resizew,fptr->resizeh);
		fprintf(h,"</RESIZE>");
		linefeed(h);

		if ( fptr->formflags & _FORM_INTERNATIONAL )
			xml_put_word(h,"INTERNATIONAL",1,1);
		else	xml_put_word(h,"INTERNATIONAL",0,1);

		indent(h,1);
		fprintf(h,"<COMMAND>");
		if ( fptr->formflags & _FORM_COMMANDLINE )
			fprintf(h,"1 %u %u",fptr->argvlen,fptr->argvcount);
		else	fprintf(h,"0 %u %u",fptr->argvlen,fptr->argvcount);
		fprintf(h,"</COMMAND>");
		linefeed(h);

#ifdef	AVANTARGVLEN
		if ( fptr->formflags & _FORM_COMMANDLINE )
			xml_put_word(h,"COMMAND",1,1);
		else	xml_put_word(h,"COMMAND",0,1);
#endif
		if ( fptr->formflags & _FORM_MULTILINGUAL )
			xml_put_word(h,"MULTILINGUAL",1,1);
		else	xml_put_word(h,"MULTILINGUAL",0,1);

		if ( method_is_valid(fptr->stylesheet) ) {
			xml_put_string(h,"STYLE",fptr->stylesheet,1);
			}
		if ( method_is_valid(fptr->palette) ) {
			xml_put_string(h,"PALETTE",fptr->palette,1);
			}
#ifdef	ABAL32A
		if ( fptr->styling ) {
			xml_put_word(h,"STYLING",1,1);
			}
		if ( fptr->weboptions ) {
			xml_put_word(h,"WEBOPTIONS",fptr->weboptions,1);
			}
#endif
		if ( fptr->clearscreen) {
			classnamecorrection( fptr->clearscreen );
			xml_put_string(h,"CLEAR",fptr->clearscreen,1);
			}
#ifdef	NEWSING
		if ( fptr->extends) 
		{
			xml_put_string(h,"EXTENDS",fptr->extends,1);
		}
#endif
		indent(h,1);
		fprintf(h,"<PACKAGE>");
			if ( fptr->ispopup ) 
				fprintf(h," POPUP");
			if ( fptr->isdynamic ) 
				fprintf(h," DYNAMIC");
			if ( fptr->isprogram ) {
				fprintf(h," PROGRAM");
				if ( fptr->isoverlay )
					fprintf(h," OVERLAY");
				}
			else if ( fptr->isoverlay )
				fprintf(h," MODULE");
			else	fprintf(h," INCLUDE");
		fprintf(h,"</PACKAGE>");
		linefeed(h);
		indent(h,1);
		fprintf(h,"<CLASS>");
		switch (fptr->formflags & _FORM_TYPE_FLAGS) {
			case 	_FORM_TYPE_DIALOG	:
				fprintf(h," DIALOG"); break;
			case 	_FORM_TYPE_EVENT	:
				fprintf(h," EVENT"); break;
			case 	_FORM_TYPE_QUALITY	:
				fprintf(h," QUALITY"); break;
			case 	_FORM_TYPE_PAGE		:
				fprintf(h," PAGE"); break;
			case 	_FORM_TYPE_SERVICE		:
				fprintf(h," SERVICE"); break;
			case 	_FORM_TYPE_AGENT		:
				fprintf(h," AGENT"); break;
			}
		fprintf(h,"</CLASS>");
		linefeed(h);
		xml_put_string(h,"SOURCE",fptr->loadname,1);
		xml_put_string(h,"TARGET",fptr->prodname,1);
		xml_put_string(h,"HOST",fptr->hostname,1);
		indent(h,1);
		fprintf(h,"<KEYS>");
		if ( fptr->formflags & _FORM_ESC )
			fprintf(h," ESC");
		if ( fptr->formflags & _FORM_PAGE_UP )
			fprintf(h," PGUP");
		if ( fptr->formflags & _FORM_PAGE_DOWN)
			fprintf(h," PGDOWN");
		if ( fptr->formflags & _FORM_TAB )
			fprintf(h," TAB");
		if ( fptr->formflags & _FORM_RC )
			fprintf(h," CR");
		if ( fptr->formflags & _FORM_UP )
			fprintf(h," UP");
		if ( fptr->formflags & _FORM_DOWN )
			fprintf(h," DOWN");
		if ( fptr->formflags & _FORM_DEFAULT )
			fprintf(h," DEFAULT");
		fprintf(h,"</KEYS>");
		linefeed(h);
		indent(h,1);
		fprintf(h,"<EVENTS>");
		if ( fptr->mimoflags & _MIMO_INTERRUPT )
			fprintf(h," INTR");
		if ( fptr->mimoflags & _MIMO_KEYBOARD )
			fprintf(h," KEY");
		if ( fptr->mimoflags & _MIMO_SEND_LEFT )
			fprintf(h," LEFT");
		if ( fptr->mimoflags & _MIMO_SEND_MIDDLE)
			fprintf(h," OTHER");
		if ( fptr->mimoflags & _MIMO_SEND_RIGHT)
			fprintf(h," RIGHT");
		if ( fptr->mimoflags & _MIMO_SEND_WHEEL)
			fprintf(h," WHEEL");
		if ( fptr->mimoflags & _MIMO_DOWN )
			fprintf(h," DOWN");
		if ( fptr->mimoflags & _MIMO_UP )
			fprintf(h," UP");
		if ( fptr->mimoflags & _MIMO_WHILE_DOWN)
			fprintf(h," DRAG");
		if ( fptr->mimoflags & _MIMO_IS_DOWN )
			fprintf(h," HOVER");
		if ( fptr->mimoflags & _MIMO_MOVE )
			fprintf(h," MOVE");
		if ( fptr->mimoflags & _MIMO_WIDGETS )
			fprintf(h," WIDGET");
		fprintf(h,"</EVENTS>");
		linefeed(h);

		indent(h,1);
		fprintf(h,"<PAGE>");
		linefeed(h);
			xml_put_string	(h,"DEVICE"	,fptr->printout.DeviceName,2);
			xml_put_string	(h,"DRIVER"	,fptr->printout.DriverName,2);
			xml_put_word	(h,"LAYOUT"	,fptr->printout.Layout,2);
			xml_put_word	(h,"PAPER"	,fptr->printout.PaperType,2);
			xml_put_word	(h,"DPI"	,fptr->printout.PrintResolution,2);
			xml_put_word	(h,"ALIGN"	,fptr->printout.Alignment,2);
			xml_put_word	(h,"FEED"	,fptr->printout.FeedOpt,2);
			xml_put_word	(h,"PREVIEW"	,fptr->printout.Preview,2);
			xml_put_string	(h,"MESSAGE"	,fptr->printout.PageHead,2);
			xml_put_margin	(h,"TOP"	,fptr->printout.TopMargin,fptr->printout.BottomMargin,2);
			xml_put_margin	(h,"LEFT"	,fptr->printout.LeftMargin,fptr->printout.RightMargin,2);
		indent(h,1);
		fprintf(h,"</PAGE>");
		linefeed(h);

		if ( fptr->dependance )
			xml_put_string(h,"INCLUSION",fptr->dependance,1);
		if ( fptr->construction )
			xml_put_string(h,"MODULES",fptr->construction,1);
		
		if ( fptr->OptionsCompile )
			xml_put_string(h,"OPTIONS_COMPILE",fptr->OptionsCompile,1);
		if ( fptr->OptionsLinkage )
			xml_put_string(h,"OPTIONS_LINKAGE",fptr->OptionsLinkage,1);

		indent(h,1);
		fprintf(h,"<DOCUMENT>"); 
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
		fprintf(h,"</DOCUMENT>");
		linefeed(h);

		for ( 	dptr=fptr->rootmember;
			dptr != (struct forms_data_member*) 0;
			dptr=dptr->next) {
			switch ( dptr->type ) {
				case	_ABAL_FIELD	:
					indent(h,1);
					if (!( method_is_valid( dptr->name ) )) 
						fprintf(h,"<MEMBER TYPE=%u />",dptr->type);
					else	fprintf(h,"<MEMBER TYPE=%u NAME=%s />",dptr->type,dptr->name);
					linefeed(h);
					break;
				case	_ABAL_FILLER	:
					indent(h,1);
					fprintf(h,"<MEMBER TYPE=%u SIZE=%u />",dptr->type,dptr->size);
					linefeed(h);
					break;
				default			:
					if (!( method_is_valid( dptr->name ) ))
						continue;
					else	{
						indent(h,1);
						fprintf(h,"<MEMBER NAME=%s TYPE=%u SIZE=%u FIRST=%u SECOND=%u ",dptr->name,dptr->type,dptr->size,dptr->first,dptr->second);
						if (method_is_valid(dptr->comment)) fprintf(h,"COMMENT=\"%s\" ",dptr->comment);
						fprintf(h,"/>");
						linefeed(h);
						}
				}
			}
		for ( 	mptr=fptr->rootmethod;
			mptr != (struct forms_method*) 0;
			mptr=mptr->next) {
			if ( mptr->name ) {
				indent(h,1);
				fprintf(h,"<METHOD>"); 
				linefeed(h);
				xml_put_string(h,"NAME",	mptr->name,	2);
				if ( method_is_valid( mptr->signature ) ) 
					xml_put_method(h,"SIGNATURE",	mptr->signature,2);
				xml_put_word  (h,"TYPE",	mptr->type,	2);
				xml_put_string(h,"CLASS",	mptr->klass,	2);
				if ( method_is_valid( mptr->text ) )
					xml_put_method(h,"TEXT",	mptr->text,	2);
				indent(h,1);
				fprintf(h,"</METHOD>");
				linefeed(h);
				}
			}

		for (	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next ) {
			indent(h,1); fprintf(h,"<WIDGET>"); linefeed(h);
			xml_put_string(h,"NAME",iptr->Contents.name,2);
			if ( iptr->Contents.access & _WIDGET_PUBLIC ) {
				fprintf(h,"<PUBLIC/>");
				linefeed(h);
				}
			if ( iptr->Contents.access & _WIDGET_EXTERN ) {
				fprintf(h,"<EXTERN/>");
				linefeed(h);
				}
			switch ((iptr->Contents.access & _WIDGET_ACCESS) >> 2) {
				case	0 : break;
				case	1 : fprintf(h,"<DISABLE/>"); break;
				case	2 : fprintf(h,"<INHIBIT/>"); break;
				}
			xml_put_string(h,"CLASS",get_widget_class(iptr->Contents.style & _FRAME_TYPE),2);
			if (( iptr->Contents.stylesheet ) || ( iptr->Contents.stylefocus )) {
				indent(h,1); fprintf(h,"<STYLE>"); 
				if ( iptr->Contents.stylesheet )
				{
					classnamecorrection( iptr->Contents.stylesheet );
					fprintf(h,"%s",iptr->Contents.stylesheet);
				}
				if ( iptr->Contents.stylefocus )
				{
					classnamecorrection( iptr->Contents.stylefocus );
					fprintf(h,",%s",iptr->Contents.stylefocus);
					if ( iptr->Contents.stylepress )
					{
						classnamecorrection( iptr->Contents.stylepress );
						fprintf(h,",%s",iptr->Contents.stylepress);
					}
				}
				else if ( iptr->Contents.stylepress )
				{
					classnamecorrection( iptr->Contents.stylepress );
					fprintf(h,",,%s",iptr->Contents.stylepress);
				}

				fprintf(h,"</STYLE>");  linefeed(h);
				}
			if ((iptr->Contents.style & _FRAME_TYPE) == _LINE_FRAME) {
				xml_put_word(h,"SIZE",iptr->Contents.size,2);
				}

			xml_put_coordinate(h,"POSITION",iptr->Contents.x,iptr->Contents.y,2);
			xml_put_coordinate(h,"DIMENSION",iptr->Contents.w,iptr->Contents.h,2);
			xml_put_word(h,"FONT",iptr->Contents.font,2);
			xml_put_word(h,"COLOUR",iptr->Contents.colour,2);
			xml_put_word(h,"CURSOR",iptr->Contents.cursor,2);
			xml_put_word(h,"MOUSE",iptr->Contents.events->mimo,2);
			if (!( fptr->formflags & _INTERNATIONAL )) {
				indent(h,2); fprintf(h,"<PAYLOAD>"); linefeed(h);
				xml_put_payload(h,"ENGLISH",iptr->Contents.payload,2);
				indent(h,2); fprintf(h,"</PAYLOAD>"); linefeed(h);
				}
			else	{
				set_national_payload(iptr,fptr->natlang);
				indent(h,2); fprintf(h,"<PAYLOAD>"); linefeed(h);
				if ( iptr->Contents.messages[0] ) 
					xml_put_payload(h,"ENGLISH",iptr->Contents.messages[0],2);
				if ( iptr->Contents.messages[1] ) 
					xml_put_payload(h,"FRANCAIS",iptr->Contents.messages[1],2);
				if ( iptr->Contents.messages[2] ) 
					xml_put_payload(h,"ITALIANO",iptr->Contents.messages[2],2);
				if ( iptr->Contents.messages[3] ) 
					xml_put_payload(h,"ESPAGNOL",iptr->Contents.messages[3],2);
				if ( iptr->Contents.messages[4] ) 
					xml_put_payload(h,"DEUTSCH",iptr->Contents.messages[4],2);
				if ( iptr->Contents.messages[5] ) 
					xml_put_payload(h,"NEDERLANDS",iptr->Contents.messages[5],2);
				if ( iptr->Contents.messages[6] ) 
					xml_put_payload(h,"PORTUGUES",iptr->Contents.messages[6],2);
				if ( iptr->Contents.messages[7] ) 
					xml_put_payload(h,"OTHER",iptr->Contents.messages[7],2);
				indent(h,2); fprintf(h,"</PAYLOAD>"); linefeed(h);
				indent(h,2); fprintf(h,"<HINT>"); linefeed(h);
				if ( iptr->Contents.hmessages[0] ) 
					xml_put_payload(h,"ENGLISH",iptr->Contents.hmessages[0],2);
				if ( iptr->Contents.hmessages[1] ) 
					xml_put_payload(h,"FRANCAIS",iptr->Contents.hmessages[1],2);
				if ( iptr->Contents.hmessages[2] ) 
					xml_put_payload(h,"ITALIANO",iptr->Contents.hmessages[2],2);
				if ( iptr->Contents.hmessages[3] ) 
					xml_put_payload(h,"ESPAGNOL",iptr->Contents.hmessages[3],2);
				if ( iptr->Contents.hmessages[4] ) 
					xml_put_payload(h,"DEUTSCH",iptr->Contents.hmessages[4],2);
				if ( iptr->Contents.hmessages[5] ) 
					xml_put_payload(h,"NEDERLANDS",iptr->Contents.hmessages[5],2);
				if ( iptr->Contents.hmessages[6] ) 
					xml_put_payload(h,"PORTUGUES",iptr->Contents.hmessages[6],2);
				if ( iptr->Contents.hmessages[7] ) 
					xml_put_payload(h,"OTHER",iptr->Contents.hmessages[7],2);
				indent(h,2); fprintf(h,"</HINT>"); linefeed(h);
				get_national_payload(iptr,fptr->natlang);
				}
			if ( is_file_Widget( iptr ) ) {
				if (!( symbolic_data_control(h, iptr, "FORMAT"  ) )) {
					if ( iptr->Contents.format )
						xml_put_string(h,"FORMAT",iptr->Contents.format,2);
					}
				}
			else if ( iptr->Contents.format )
				xml_put_string(h,"FORMAT",iptr->Contents.format,2);

			xml_put_coordinate(h,"INTERFACE",iptr->Contents.interfaceitem,iptr->Contents.special,2);
			xml_put_coordinate(h,"WHRESIZE",iptr->Contents.wResize,iptr->Contents.hResize,2);	/* GWB le 09/01/2007 */
			xml_put_word(h,"DATATYPE",iptr->Contents.datatype,2);
			xml_put_word(h,"ALIGN",iptr->Contents.align,2);
#ifdef	ABAL32ABCD
			indent(h,2); fprintf(h,"<ABAL>"); linefeed(h);
#endif	/* ABAL32ABCD */
			xml_put_word(h,"CONTROL",iptr->Contents.events->control,2);
			xml_put_event(h,"ONCREATE",iptr->Contents.events->xo_create,iptr->Contents.events->on_create,2);
			xml_put_event(h,"ONSHOW",iptr->Contents.events->xo_show,iptr->Contents.events->on_show,2);
			xml_put_event(h,"ONGETFOCUS",iptr->Contents.events->xo_get_focus,iptr->Contents.events->on_get_focus,2);
			xml_put_event(h,"ONEVENT",iptr->Contents.events->xo_event,iptr->Contents.events->on_event,2);
			xml_put_event(h,"ONLOSEFOCUS",iptr->Contents.events->xo_lose_focus,iptr->Contents.events->on_lose_focus,2);
			xml_put_event(h,"ONHIDE",iptr->Contents.events->xo_hide,iptr->Contents.events->on_hide,2);
			xml_put_event(h,"ONREMOVE",iptr->Contents.events->xo_remove,iptr->Contents.events->on_remove,2);
#ifdef	ABAL32ABCD
			indent(h,2); fprintf(h,"<ABAL>"); linefeed(h);
			xml_put_word(h,"CONTROL",iptr->Contents.abal_events.control,2);
			xml_put_event(h,"ONCREATE",iptr->Contents.abal_events.xo_create,iptr->Contents.abal_events.on_create,2);
			xml_put_event(h,"ONSHOW",iptr->Contents.abal_events.xo_show,iptr->Contents.abal_events.on_show,2);
			xml_put_event(h,"ONGETFOCUS",iptr->Contents.abal_events.xo_get_focus,iptr->Contents.abal_events.on_get_focus,2);
			xml_put_event(h,"ONEVENT",iptr->Contents.abal_events.xo_event,iptr->Contents.abal_events.on_event,2);
			xml_put_event(h,"ONLOSEFOCUS",iptr->Contents.abal_events.xo_lose_focus,iptr->Contents.abal_events.on_lose_focus,2);
			xml_put_event(h,"ONHIDE",iptr->Contents.abal_events.xo_hide,iptr->Contents.abal_events.on_hide,2);
			xml_put_event(h,"ONREMOVE",iptr->Contents.abal_events.xo_remove,iptr->Contents.abal_events.on_remove,2);
			indent(h,2); fprintf(h,"</ABAL>"); linefeed(h);
			indent(h,2); fprintf(h,"<C>"); linefeed(h);
			xml_put_word(h,"CONTROL",iptr->Contents.c_events.control,2);
			xml_put_event(h,"ONCREATE",iptr->Contents.c_events.xo_create,iptr->Contents.c_events.on_create,2);
			xml_put_event(h,"ONSHOW",iptr->Contents.c_events.xo_show,iptr->Contents.c_events.on_show,2);
			xml_put_event(h,"ONGETFOCUS",iptr->Contents.c_events.xo_get_focus,iptr->Contents.c_events.on_get_focus,2);
			xml_put_event(h,"ONEVENT",iptr->Contents.c_events.xo_event,iptr->Contents.c_events.on_event,2);
			xml_put_event(h,"ONLOSEFOCUS",iptr->Contents.c_events.xo_lose_focus,iptr->Contents.c_events.on_lose_focus,2);
			xml_put_event(h,"ONHIDE",iptr->Contents.c_events.xo_hide,iptr->Contents.c_events.on_hide,2);
			xml_put_event(h,"ONREMOVE",iptr->Contents.c_events.xo_remove,iptr->Contents.c_events.on_remove,2);
			indent(h,2); fprintf(h,"</C>"); linefeed(h);
#endif	/* ABAL32ABCD */
			indent(h,2);
			fprintf(h,"<DOCUMENT>");
			linefeed(h);

			xml_put_word(h,"TOOL",iptr->doctool,2);
		
			if ( iptr->document[0] ) 
				xml_put_helptext(h,"ENGLISH",iptr->document[0],2);
			if ( iptr->document[1] ) 
				xml_put_helptext(h,"FRANCAIS",iptr->document[1],2);
			if ( iptr->document[2] ) 
				xml_put_helptext(h,"ITALIANO",iptr->document[2],2);
			if ( iptr->document[3] ) 
				xml_put_helptext(h,"ESPAGNOL",iptr->document[3],2);
			if ( iptr->document[4] ) 
				xml_put_helptext(h,"DEUTSCH",iptr->document[4],2);
			if ( iptr->document[5] ) 
				xml_put_helptext(h,"NEDERLANDS",iptr->document[5],2);
			if ( iptr->document[6] ) 
				xml_put_helptext(h,"PORTUGUES",iptr->document[6],2);
			if ( iptr->document[7] ) 
				xml_put_helptext(h,"OTHER",iptr->document[7],2);
			indent(h,2);
			fprintf(h,"</DOCUMENT>");
			linefeed(h);
#ifdef	OLD_FORM_HINT
			if ( iptr->Contents.hint ) {
				xml_put_string(h,"HINT",iptr->Contents.hint,1);
				}
#endif
			indent(h,1);fprintf(h,"</WIDGET>"); linefeed(h);
			}

		fprintf(h,"</FORM>");
		linefeed(h);
		linefeed(h);
		close_production_target(h,sname);
		}
	liberate( sname );
	return;
}

/*	---------------------------------------		*/
/*	X M L   I N P U T   M E C H A N I S M S		*/
/*	---------------------------------------		*/

private	void	xml_get_language(struct xml_application * xptr, int id)
{
	struct form_control * fptr;
	struct form_item * wptr;
	if ( xptr->heap[ (xptr->nested-1) ] == ELEMENT_DOCUMENT ) {
		if ( xptr->heap[ (xptr->nested-2) ] == ELEMENT_WIDGET ) {
			if ((wptr = xptr->payload[1]) ) 
				xml_get_text(xptr, &wptr->document[id] );
			}
		else if ( xptr->heap[ (xptr->nested-2) ] == ELEMENT_FORM ) {
			if ((fptr = xptr->payload[0])) 
				xml_get_text(xptr, &fptr->document[id] );
			}
		}
	else if ( xptr->heap[ (xptr->nested-1) ] == ELEMENT_PAYLOAD ) {
		if ( xptr->heap[ (xptr->nested-2) ] == ELEMENT_WIDGET ) {
			if ((wptr = xptr->payload[1])) 
				xml_get_text(xptr, &wptr->Contents.messages[id] );
			}
		}
	else if ( xptr->heap[ (xptr->nested-1) ] == ELEMENT_HINT    ) {
		if ( xptr->heap[ (xptr->nested-2) ] == ELEMENT_WIDGET ) {
			if ((wptr = xptr->payload[1])) 
				xml_get_text(xptr, &wptr->Contents.hmessages[id] );
			}
		}
	return;
}

private	void	xml_get_event_text(struct xml_application * xptr)
{
	struct	form_item * wptr;
	if (!( wptr = xptr->payload[1] ))
		return;
	else if ( xptr->heap[ (xptr->nested-2) ] != ELEMENT_WIDGET ) {
		switch ( xptr->heap[ (xptr->nested-2) ]  ) {

			case	ELEMENT_WIDGET	:
				break;

			case	ELEMENT_ABAL	:
			case	ELEMENT_C	:
				if ( xptr->heap[ (xptr->nested-3) ] == ELEMENT_WIDGET )
					break;
			default			:
				return;
			}
		}
	switch ( xptr->heap[ (xptr->nested-1) ] ) {
		case	ELEMENT_ONCREATE	: // 0x001E	
			xml_get_text( xptr, & wptr->Contents.events->on_create );
			break;
		case	ELEMENT_ONSHOW		: // 0x001F	
			xml_get_text( xptr, & wptr->Contents.events->on_show );
			break;
		case	ELEMENT_ONGETFOCUS	: // 0x0020	
			xml_get_text( xptr, & wptr->Contents.events->on_get_focus );
			break;
		case	ELEMENT_ONEVENT		: // 0x0021 	
			xml_get_text( xptr, & wptr->Contents.events->on_event );
			break;
		case	ELEMENT_ONLOSEFOCUS	: // 0x0022 	
			xml_get_text( xptr, & wptr->Contents.events->on_lose_focus );
			break;
		case	ELEMENT_ONHIDE		: // 0x0023		
			xml_get_text( xptr, & wptr->Contents.events->on_hide );
			break;
		case	ELEMENT_ONREMOVE	: // 0x0024
			xml_get_text( xptr, & wptr->Contents.events->on_remove );
			break;
		}
	return;
}

private	void	xml_get_event_option(struct xml_application * xptr)
{
	struct	form_item * wptr;
	if (!( wptr = xptr->payload[1] ))
		return;
	else if ( xptr->heap[ (xptr->nested-2) ] != ELEMENT_WIDGET ) {
		switch ( xptr->heap[ (xptr->nested-2) ]  ) {
			case	ELEMENT_ABAL	:
			case	ELEMENT_C	:
				if ( xptr->heap[ (xptr->nested-3) ] == ELEMENT_WIDGET )
					break;
			default			:
				return;
			}
		}
	switch ( xptr->heap[ (xptr->nested-1) ] ) {
		case	ELEMENT_ONCREATE	: // 0x001E	
			xml_get_word(xptr, & wptr->Contents.events->xo_create );
			break;
		case	ELEMENT_ONSHOW		: // 0x001F	
			xml_get_word(xptr, & wptr->Contents.events->xo_show );
			break;
		case	ELEMENT_ONGETFOCUS	: // 0x0020	
			xml_get_word(xptr, & wptr->Contents.events->xo_get_focus );
			break;
		case	ELEMENT_ONEVENT		: // 0x0021 	
			xml_get_word(xptr, & wptr->Contents.events->xo_event );
			break;
		case	ELEMENT_ONLOSEFOCUS	: // 0x0022 	
			xml_get_word(xptr, & wptr->Contents.events->xo_lose_focus );
			break;
		case	ELEMENT_ONHIDE		: // 0x0023		
			xml_get_word(xptr, & wptr->Contents.events->xo_hide );
			break;
		case	ELEMENT_ONREMOVE	: // 0x0024
			xml_get_word(xptr, & wptr->Contents.events->xo_remove );
			break;
		}
	return;
}

private	void	xml_get_align(struct xml_application * xptr)
{
	struct form_control * fptr;
	struct form_item * wptr;
	char * newalign=(char *) 0;
	if ( xptr->heap[ (xptr->nested-1) ] == ELEMENT_WIDGET ) 
	{
		if (!(wptr = xptr->payload[1] ))
			return;
		else
		{
			xml_get_string(xptr, &newalign);
			if ( *newalign != '(' )
				xml_get_word(xptr, &wptr->Contents.align );
			else	wptr->Contents.align = resolve_xml_align( newalign );
			liberate(newalign);
		}
	}
	else if ( xptr->heap[ (xptr->nested-1) ] == ELEMENT_PAGE ) 
	{
		if (!( fptr = xptr->payload[0] ))
			return;
		else	xml_get_word(xptr, &fptr->printout.Alignment );
	}
	return;

}

/*	---------------------------------------------------------------		*/
/*	Specialised Visual Forms Document Information Retrieval Methods		*/
/*	---------------------------------------------------------------		*/

private	void	xml_get_keys(struct xml_application * xptr)
{
	char *	sptr;
	struct form_control * fptr;
	if (!( fptr = xptr->payload[0] ))
		return;
	else if (!( sptr = xptr->buffer ))
		return;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "ESC") ) {
		sptr+=3;
		fptr->formflags |= _FORM_ESC;
		}
	else	fptr->formflags &= ~_FORM_ESC;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "PGUP") ) {
		sptr+=4;
		fptr->formflags |= _FORM_PAGE_UP;
		}
	else	fptr->formflags &= ~_FORM_PAGE_UP;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "PGDOWN") ) {
		sptr+=6;
		fptr->formflags |= _FORM_PAGE_DOWN;
		}
	else	fptr->formflags &= ~_FORM_PAGE_DOWN;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "TAB") ) {
		sptr+=3;
		fptr->formflags |= _FORM_TAB;
		}
	else	fptr->formflags &= ~_FORM_TAB;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "CR") ) {
		sptr+=2;
		fptr->formflags |= _FORM_RC;
		}
	else	fptr->formflags &= ~_FORM_RC;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "UP") ) {
		sptr+=2;
		fptr->formflags |= _FORM_UP;
		}
	else	fptr->formflags &= ~_FORM_UP;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "DOWN") ) {
		sptr+=4;
		fptr->formflags |= _FORM_DOWN;
		}
	else	fptr->formflags &= ~_FORM_DOWN;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "DEFAULT") ) {
		sptr+=7;
		fptr->formflags |= _FORM_DEFAULT;
		}
	else	fptr->formflags &= ~_FORM_DEFAULT;
	return;
}

private	void	xml_get_events(struct xml_application * xptr)
{
	char *	sptr;
	struct form_control * fptr;
	if (!( fptr = xptr->payload[0] ))
		return;
	else if (!( sptr = xptr->buffer ))
		return;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "INTR") ) { 
		sptr += 4; 
		fptr->mimoflags |= _MIMO_INTERRUPT;
		}
	else	fptr->mimoflags &=~_MIMO_INTERRUPT;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "KEY") ) { 
		sptr += 3; 
		fptr->mimoflags |= _MIMO_KEYBOARD;
		}
	else	fptr->mimoflags &=~_MIMO_KEYBOARD;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "LEFT") ) { 
		sptr += 4; 
		fptr->mimoflags |= _MIMO_SEND_LEFT ;
		}
	else	fptr->mimoflags &=~_MIMO_SEND_LEFT ;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "OTHER") ) {
		sptr += 5; 
		fptr->mimoflags |= _MIMO_SEND_MIDDLE;
		}
	else	fptr->mimoflags &=~_MIMO_SEND_MIDDLE;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "RIGHT") ) {
		sptr += 5; 
		fptr->mimoflags |= _MIMO_SEND_RIGHT;
		}
	else	fptr->mimoflags &=~_MIMO_SEND_RIGHT;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "WHEEL") ) {
		sptr += 5; 
		fptr->mimoflags |= _MIMO_SEND_WHEEL;
		}
	else	fptr->mimoflags &=~_MIMO_SEND_WHEEL;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "DOWN") ) { 
		sptr += 4; 
		fptr->mimoflags |= _MIMO_DOWN ;
		}
	else	fptr->mimoflags &=~_MIMO_DOWN ;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "UP") ) { 
		sptr += 2; 
		fptr->mimoflags |= _MIMO_UP ;
		}
	else	fptr->mimoflags &=~_MIMO_UP ;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "DRAG") ) { 
		sptr += 4; 
		fptr->mimoflags |= _MIMO_WHILE_DOWN;
		}
	else	fptr->mimoflags &=~_MIMO_WHILE_DOWN;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "HOVER") ) { 
		sptr += 5; 
		fptr->mimoflags |= _MIMO_IS_DOWN;
		}
	else	fptr->mimoflags &=~_MIMO_IS_DOWN;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "MOVE") ) { 
		sptr += 4; 
		fptr->mimoflags |= _MIMO_MOVE;
		}
	else	fptr->mimoflags &=~_MIMO_MOVE;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "WIDGET") ) { 
		sptr += 6; 
		fptr->mimoflags |= _MIMO_WIDGETS;
		}
	else	fptr->mimoflags &=~_MIMO_WIDGETS;
	return;
}

private	void	xml_get_margin( struct xml_application * xptr, char ** vptr, int * uptr  )
{
	char *	sptr=(char *) 0;
	char *	wptr=(char *) 0;
	xml_get_string(xptr, & sptr );
	*vptr = (char *) 0;
	*uptr = 0;
	if ((wptr = sptr) != (char *) 0) {
		while ( *wptr != 0 ) { if ( *wptr == ' ' ) wptr++; else break; }
		while ( *wptr != 0 ) { if ( *wptr == ' ' ) break; else wptr++; }
		if ( *wptr == ' ' ) {
			*(wptr++) = 0;
			while ( *wptr != 0 ) { if ( *wptr == ' ' ) wptr++; else break; }
			if (( *wptr >= '0' )
			&&  ( *wptr <= '9' ))
				*uptr = (*wptr - '0');
			}			
		*vptr = sptr;
		}
	return;
}


private	void	xml_get_package(struct xml_application * xptr)
{
	char *	sptr;
	struct form_control * fptr;
	if (!( fptr = xptr->payload[0] ))
		return;
	else if (!( sptr = xptr->buffer ))
		return;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "POPUP" ) ) {
		fptr->ispopup=1;
		sptr += 5;
		}
	else	fptr->ispopup=0;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "DYNAMIC" ) ) {
		fptr->isdynamic=1;
		sptr += 7;
		}
	else	fptr->isdynamic=0;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "PROGRAM" ) ) {
		fptr->isprogram = 1;
		sptr += 7;
		while ( *sptr == ' ' ) sptr++;
		if ( xml_mnemonic( sptr, "OVERLAY" ) )
			fptr->isoverlay = 1;
		else	fptr->isoverlay = 0;
		}
	else	{
		fptr->isprogram = 0;
		if ( xml_mnemonic( sptr, "MODULE" ) )
			fptr->isoverlay = 1;
		else if ( xml_mnemonic( sptr, "INCLUDE" ) )
			fptr->isoverlay = 0;
		}
	return;
}

private	void	xml_get_production(struct xml_application * xptr)
{
	int	i;
	char *	sptr;
	struct form_control * fptr;
	if (!( fptr = xptr->payload[0] ))
		return;
	else if (!( sptr = xptr->buffer ))
		return;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "COBOL"	) )
		fptr->language = _GENERATE_COBOL;
	else if ( xml_mnemonic( sptr, "C++" 		) )
		fptr->language = _GENERATE_CPP;
	else if ( xml_mnemonic( sptr, "C" 		) )
		fptr->language = _GENERATE_C;
	else if ( xml_mnemonic( sptr, "ABAL++" 	) )
		fptr->language = _GENERATE_ABAL;
	else if ( xml_mnemonic( sptr, "ABAL" 	) )
		fptr->language = _GENERATE_BAL;
	else if ( xml_mnemonic( sptr, "PHP" 	) )
		fptr->language = _GENERATE_PHP;
	else if ( xml_mnemonic( sptr, "REACT" 	) )
		fptr->language = _GENERATE_REACT;
	else if ( xml_mnemonic( sptr, "NODE" 	) )
		fptr->language = _GENERATE_NODE;
	else if ( xml_mnemonic( sptr, "JAVA" 	) )
		fptr->language = _GENERATE_JAVA;
	else if ( xml_mnemonic( sptr, "HTML" 	) )
		fptr->language = _GENERATE_HTML;
	else if ( xml_mnemonic( sptr, "BIFS" 	) )
		fptr->language = _GENERATE_BIFS;
	else if ( xml_mnemonic( sptr, "XMTA" 	) )
		fptr->language = _GENERATE_XMTA;
	else if ( xml_mnemonic( sptr, "LASER" 	) )
		fptr->language = _GENERATE_LASER;
	else if ( xml_mnemonic( sptr, "ANDROID" 	) )
		fptr->language = _GENERATE_ANDROID;
	return;
}

private	void	xml_get_class(struct xml_application * xptr)
{
	int	i;
	char *	sptr;
	struct form_control * fptr;
	struct forms_method * mptr;
	struct form_item * wptr;
	char *	kptr;
	if (!( sptr = xptr->buffer ))
		return;
	while ( *sptr == ' ' ) sptr++;
	if ( xptr->heap[ (xptr->nested-1) ] == ELEMENT_WIDGET ) {
		if (!( wptr = xptr->payload[1] ))
			return;
		if (!( strcmp( sptr, "table" ) ))
			sptr = "form";
		for (i=0; i < 32; i++ ) {
			if (!(kptr = get_widget_class(i)))
			{
				break;
			}
			else if ( kptr == -1 )
			{
				break;
			}
			if ( string_compare(sptr,get_widget_class(i)) ) {
				wptr->Contents.style = i;
				break;
				}
			}
		init_whResize(wptr);
		}
	else if ( xptr->heap[ (xptr->nested-1) ] == ELEMENT_FORM ) {
		if (!( fptr = xptr->payload[0] ))
			return;
		fptr->formflags &=  ~_FORM_TYPE_FLAGS;
		if ( xml_mnemonic( sptr, "DIALOG" ) )
			fptr->formflags |= _FORM_TYPE_DIALOG;
		else if ( xml_mnemonic( sptr, "EVENT" ) )
			fptr->formflags |= _FORM_TYPE_EVENT;
		else if ( xml_mnemonic( sptr, "QUALITY" ) )
			fptr->formflags |= _FORM_TYPE_QUALITY;
		else if ( xml_mnemonic( sptr, "PAGE" ) )
			fptr->formflags |= _FORM_TYPE_PAGE;
		else if ( xml_mnemonic( sptr, "SERVICE" ) )
			fptr->formflags |= _FORM_TYPE_SERVICE;
		else if ( xml_mnemonic( sptr, "AGENT" ) )
			fptr->formflags |= _FORM_TYPE_AGENT;
		}
	else if ( xptr->heap[ (xptr->nested-1) ] == ELEMENT_METHOD ) {
		if (!( mptr = xptr->payload[1] ))
			return;
		else	xml_get_string(xptr, &mptr->klass );
		}
	return;
}

/*	------------------------------		*/
/*	XML PARSER : DERIVATION RELAYS		*/
/*	------------------------------		*/
private	int	xml_open_form_tag(struct xml_application * xptr, char * name )
{
	int	i;
	struct	form_item * wptr;
	struct	forms_method * mptr;
	struct	forms_data_member * dptr;
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
		if ( i == ELEMENT_WIDGET ) {
			if ((wptr = allocate_for_Widget()) != (struct form_item*)0) {
				wptr->parent = xptr->payload[0];
				use_widget_events(wptr);
				xptr->payload[1] = wptr;
				}
			}
		else if ( i == ELEMENT_METHOD ) {
			if ((mptr = allocate_for_Method()) != (struct forms_method *)0) {
				xptr->payload[1] = mptr;
				}
			}
		else if ( i == ELEMENT_MEMBER ) {
			if ((dptr = allocate_for_Member()) != (struct forms_data_member *)0) {
				xptr->payload[1] = dptr;
				}
			}
		else if ( i == ELEMENT_ABAL ) {
			if ((wptr = (struct form_item*) xptr->payload[1]) != (struct form_item*)0 )
				wptr->Contents.events = &wptr->Contents.abal_events;
			}
		else if ( i == ELEMENT_C ) {
			if ((wptr = (struct form_item*) xptr->payload[1]) != (struct form_item*)0 )
				wptr->Contents.events = &wptr->Contents.c_events;
			}
		if ( xptr->echo ) { printf("<%s>\r\n",name); }
		return(0);
		}
	else	{
		sprintf(xptr->buffer,"illegal element nesting : %s",name);
		status_message( xptr->buffer,2);
		return(105);
		}

}

static	int	xml_form_atb_name(struct xml_application * xptr,char * name)	
{ 
	int	i;
	if ( xptr->echo )
		printf(" %s",name);	

	for (i=0; i < MAX_ELEMENT; i++ )
		if ( string_compare( name, XmlElement[i] ) )
			break;

	CurrentAtbName = i;
	return(0); 
}

private int     style_hex(char * tptr, int tlen )
{
        int     i;
        int     v;
        for (i=0,v=0; i < tlen; i++ ) {
                if ((*(tptr+i) >= '0' )
                &&  (*(tptr+i) <= '9' ))
                        v = ((v * 16) + ( *(tptr+i) - '0' ));
                else if ((*(tptr+i) >= 'a' )
                     &&  (*(tptr+i) <= 'f' ))
                        v = ((v * 16) + ( *(tptr+i) - 'a' ) + 10);
                else if ((*(tptr+i) >= 'A' )
                    &&  (*(tptr+i) <= 'F' ))
                        v = ((v * 16) + ( *(tptr+i) - 'A' ) + 10);
                else    break;
                }
        return(v);
}

static	int	resolve_xml_colour_name( char * sptr );
static	int 	resolve_xml_rgb( char * tptr )
{
        int	red=0,green=0,blue=0;    
	if ( *tptr == '#' ) tptr++;
	red   = style_hex(tptr,2); tptr+=2;
	green = style_hex(tptr,2); tptr+=2;
	blue  = style_hex(tptr,2);
	if ( red > blue )
	{
		if ( red > green )
			return( resolve_xml_colour_name("red" ));
		else if ( red == green )
			return( resolve_xml_colour_name("brown" ));
		else	return( resolve_xml_colour_name("green"));
	}
	else if ( red == blue )
	{
		if ( blue > green )
			return( resolve_xml_colour_name("purple" ));
		else if ( blue == green )
			return( resolve_xml_colour_name("silver" ));
		else	return( resolve_xml_colour_name("brown"));
	}
	else
	{
		if ( blue > green )
			return( resolve_xml_colour_name("blue" ));
		else if ( blue == green )
			return( resolve_xml_colour_name("cyan" ));
		else	return( resolve_xml_colour_name("green"));
	}
}

static	char * 	xml_colour_names[]= 
{
	"black","navy","green","cyan","red","purple","brown","grey",
	"silver","blue","lime","sky","pink","magenta","yellow","white",
	(char *) 0
};

static	int	resolve_xml_colour_name( char * sptr )
{
	int	i;
	if (!( strcmp( sptr, "transparent" ) ))
		return(0);
	else if (!( strcmp( sptr, "black" ) ))
		return(16);
	else if (!(strcmp( sptr, "gold" ) ))
		sptr = "yellow";
	else if ( *sptr == '#' )
		return( resolve_xml_rgb( sptr ) );
	else
	{
		for ( i=0; xml_colour_names[i] != (char *) 0; i++ )
			if (!( strcmp( sptr, xml_colour_names[i] ) ))
				break;

		return(i);
	}
}


static	int	xml_form_atb_value(struct xml_application * xptr,char * sptr)
{ 
	struct forms_data_member* dptr;
	struct form_control * fptr;

	if ( xptr->echo )
		printf("=%s",sptr);

	switch ( CurrentAtbName ) {
		case	ELEMENT_FLOW	:
			if (( fptr = xptr->payload[0]) != (struct form_control *) 0) 
				fptr->flow = quoted_atoi( sptr );
			CurrentAtbName = 0;
			return(0); 

		case	ELEMENT_X	:
			if (( fptr = xptr->payload[0]) != (struct form_control *) 0) 
				fptr->x = quoted_atoi( sptr );
			CurrentAtbName = 0;
			return(0); 

		case	ELEMENT_Y	:
			if (( fptr = xptr->payload[0]) != (struct form_control *) 0) 
				fptr->y = quoted_atoi( sptr );
			CurrentAtbName = 0;
			return(0); 

		}

	if (!(dptr = xptr->payload[1]))
		return(0);

	switch ( CurrentAtbName ) {
		case	ELEMENT_NAME	:	dptr->name  =allocate_string( sptr ); 	break;
		case	ELEMENT_TYPE	:	dptr->type  =quoted_atoi( sptr );	break;
		case	ELEMENT_SIZE	:	dptr->size  =quoted_atoi( sptr );	break;
		case	ELEMENT_FIRST	:	dptr->first =quoted_atoi( sptr );	break;
		case	ELEMENT_SECOND	:	dptr->second=quoted_atoi( sptr );	break;
		case	ELEMENT_COMMENT	:	dptr->comment = allocate_string( sptr );
						if (sptr[0]=='\"') {
							strcpy(dptr->comment,&dptr->comment[1]);
							if ((strlen(dptr->comment) !=0) 
							&&  (dptr->comment[strlen(dptr->comment)-1]=='\"'))
								dptr->comment[strlen(dptr->comment)-1]=0;
							}								
						break;
		}
	CurrentAtbName = 0;
	return(0); 
}

private	int	xml_close_form_tag(struct xml_application * xptr)
{
	int	i=0;
	struct form_control 	* fptr;
	struct form_item	* wptr;
	struct forms_method	* mptr;
	struct forms_data_member* dptr;
	char			* sptr=(char *) 0;
	char			* vptr=(char *) 0;
	char 			* newcolours=(char *) 0;
	int		newfg=0;
	int		newbg=0;

	if (!( fptr = xptr->payload[0] )) {
		sprintf(xptr->buffer,"unexpected close");
		status_message(xptr->buffer,3);
		return(30);
		}
	else if ( xptr->nested ) {
		i = xptr->heap[--xptr->nested];
		*(xptr->buffer + xptr->offset) = 0;
		if ( i != MAX_ELEMENT ) {
			if ( xptr->echo ) { printf("</%s>\r\n",XmlElement[i]);	}
			}
		switch ( i ) {
			case	MAX_ELEMENT		:
				break;

			case	ELEMENT_FORM		: // 0x0000
				fptr = (struct form_control *) 0;
				break;

			case	ELEMENT_STYLING		:
#ifdef	ABAL32A
				xml_get_word(xptr,&fptr->styling);
				if ( fptr->styling ) {
					load_form_styling( fptr );
					}
#endif
				break;
			case	ELEMENT_WEBOPTIONS	:
#ifdef	ABAL32A
				xml_get_word(xptr,&fptr->weboptions);
#endif
				break;

			case	ELEMENT_PALETTE		:
				xml_get_string(xptr, &fptr->palette);
				break;

			case	ELEMENT_STYLE		:
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 ) {
					xml_get_string(xptr, &sptr);
					if ( sptr ) {
						separate_widget_style( wptr, sptr );
						}
					}
				else 	xml_get_string(xptr, &fptr->stylesheet );
				break;
#ifdef	NEWSING
			case	ELEMENT_EXTENDS		:
				xml_get_string(xptr, &fptr->extends);
				break;
#endif
			case	ELEMENT_CLEAR		:
				xml_get_string(xptr, &fptr->clearscreen);
				break;
			case	ELEMENT_IDENTIFIER	: 
				xml_get_string(xptr, &fptr->identifier );
				break;
 
			case	ELEMENT_INTERNATIONAL	: 
				xml_get_word(xptr,&i);
				if ( i )
					fptr->formflags |= _FORM_INTERNATIONAL;
				break;

			case	ELEMENT_CONSTANTS	: 
				xml_get_word(xptr,&i);
				if ( i )
					fptr->formflags |= _FORM_CONSTANTS;
				break;

			case	ELEMENT_RESIZE		:
				xml_get_xyz(xptr,&fptr->resizeauto,&fptr->resizew,&fptr->resizeh);
				if (!fptr->resizew) fptr->resizew=800;
				if (!fptr->resizeh) fptr->resizeh=600;
				break;


			case	ELEMENT_COMMAND		:
				xml_get_xyz(xptr,&i,&fptr->argvlen,&fptr->argvcount);
				if ( i )
				fptr->formflags |= _FORM_COMMANDLINE;
				if (!( fptr->argvlen ))
					fptr->argvlen = 24;
				if (!( fptr->argvcount ))
					fptr->argvcount = 10;
				break;

			case	ELEMENT_MULTILINGUAL	:
				xml_get_word(xptr,&i);
				if ( i )
					fptr->formflags |= _FORM_MULTILINGUAL;
				break;

			case	ELEMENT_NATIONAL	:
				xml_get_word(xptr, &fptr->natlang );
				break;
			case	ELEMENT_FLUSH	:
				xml_get_word(xptr, &fptr->inhibit_flush );
				break;
			case	ELEMENT_ASKATB	:
				xml_get_word(xptr, &fptr->askatb );
				break;
			case	ELEMENT_ASKFORE	:
				xml_get_word(xptr, &fptr->askfore );
				break;
			case	ELEMENT_ASKBACK	:
				xml_get_word(xptr, &fptr->askback );
				break;
			case	ELEMENT_SSL		:
				break;
			case	ELEMENT_LANGUAGE	:
				xml_get_production(xptr);
				break;

			case	ELEMENT_PACKAGE		:
				xml_get_package(xptr);
				break;

			case	ELEMENT_CLASS		:
				xml_get_class(xptr);
				break;

			case	ELEMENT_SOURCE		:
				xml_get_string(xptr, &fptr->loadname );
				break;
			case	ELEMENT_TARGET		:
				xml_get_string(xptr, &fptr->prodname );
				break;

			case	ELEMENT_HOST		:
				xml_get_string(xptr, &fptr->hostname );
				break;

			case	ELEMENT_KEYS		:
				xml_get_keys(xptr);
				break;

			case	ELEMENT_EVENTS		:
				xml_get_events(xptr);
				break;


			case	ELEMENT_INCLUSION	:
				xml_get_string(xptr, &fptr->dependance );
				break;

			case	ELEMENT_MODULES		:
				xml_get_string(xptr, &fptr->construction );
				break;
			case	ELEMENT_DOCUMENT	:
				break;
			case	ELEMENT_TOOL		:
				break;
			case	ELEMENT_ENGLISH		:
				xml_get_language(xptr,0);
				break;
			case	ELEMENT_FRANCAIS	:
				xml_get_language(xptr,1);
				break;
			case	ELEMENT_ITALIANO	:
				xml_get_language(xptr,2);
				break;
			case	ELEMENT_ESPAGNOL	:
				xml_get_language(xptr,3);
				break;
			case	ELEMENT_DEUTSCH		:
				xml_get_language(xptr,4);
				break;
			case	ELEMENT_NEDERLANDS	:
				xml_get_language(xptr,5);
				break;
			case	ELEMENT_PORTUGEUS	:
				xml_get_language(xptr,6);
				break;
			case	ELEMENT_OTHER		:
				xml_get_language(xptr,7);
				break;
			case	ELEMENT_WIDGET		:
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 ) {
					get_national_payload(wptr,fptr->natlang);
					add_Widget(   fptr, wptr, 1);
					use_widget_events( wptr );
					check_Widget( wptr );
					}
				xptr->payload[1]  = (struct form_item *) 0;
				break;
			case	ELEMENT_POSITION	:
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 )
					xml_get_xy(xptr,&wptr->Contents.x,&wptr->Contents.y);
				break;
			case	ELEMENT_DIMENSION	:
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 )
					xml_get_xy(xptr,&wptr->Contents.w,&wptr->Contents.h);
				break;
			case	ELEMENT_FONT		:
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 )
					xml_get_word(xptr,&wptr->Contents.font);
				break;
			case	ELEMENT_SIZE		:
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 )
					xml_get_word(xptr,&wptr->Contents.size);
				break;
			case	ELEMENT_COLOUR		:
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 )
				{
					/* new version allows string colours */
					/* (fg,bg) */
					xml_get_string(xptr,&newcolours);	
					if ( *newcolours != '(' )
						wptr->Contents.colour = atoi(newcolours);
					else
					{
						sptr = (newcolours+1);
						vptr = sptr;
						while (( *vptr != 0 ) && ( *vptr != ',' )) vptr++;
						if ( *vptr ) *(vptr++) = 0;
						newfg = resolve_xml_colour_name( sptr );
						sptr = vptr;
						while (( *vptr != 0 ) && ( *vptr != ')' )) vptr++;
						if ( *vptr ) *(vptr++) = 0;
						newbg = resolve_xml_colour_name( sptr );
						wptr->Contents.colour = ((newbg << 8) | (newfg & 0x00FF));

					}
					liberate(newcolours);
				}
				break;
			case	ELEMENT_CURSOR		:
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 )
					xml_get_word(xptr,&wptr->Contents.cursor);
				break;
			case	ELEMENT_MOUSE 		:
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 )
					xml_get_word(xptr,&wptr->Contents.events->mimo);
				break;
			case	ELEMENT_FORMAT		:
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 )
					xml_get_string(xptr, &wptr->Contents.format );
				break;
			case	ELEMENT_INTERFACE	:
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 )
					xml_get_xy(xptr, &wptr->Contents.interfaceitem, &wptr->Contents.special );
				break;
			case	ELEMENT_DATATYPE	:
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 )
					xml_get_word(xptr, &wptr->Contents.datatype );
				break;
			case	ELEMENT_CONTROL		:
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 )
					xml_get_word(xptr, &wptr->Contents.events->control );
				break;
			case	ELEMENT_ALIGN		:
				xml_get_align(xptr);
				break;
			case	ELEMENT_HINT		:
				break;
			case	ELEMENT_PAYLOAD		:
				break;
			case	ELEMENT_ONCREATE	:
				break;
			case	ELEMENT_ONSHOW		:
				break;
			case	ELEMENT_ONGETFOCUS	:
				break;
			case	ELEMENT_ONEVENT		:
				break;
			case	ELEMENT_ONLOSEFOCUS	:
				break;
			case	ELEMENT_ONHIDE		:
				break;
			case	ELEMENT_ONREMOVE	:
				break;

			case	ELEMENT_MEMBER		:
				if ((dptr = xptr->payload[1]) != (struct forms_data_member *) 0 ) {
					add_Member(   fptr, dptr );
					}
				xptr->payload[1]  = (struct forms_data_member *) 0;
				break;

			case	ELEMENT_METHOD		:
				if ((mptr = xptr->payload[1]) != (struct forms_method *) 0 ) {
					add_Method(   fptr, mptr );
					}
				xptr->payload[1]  = (struct forms_method *) 0;
				break;

			case	ELEMENT_SIGNATURE	:
				if ( xptr->heap[ (xptr->nested-1) ] == ELEMENT_METHOD ) {
					if ((mptr = xptr->payload[1]) != (struct forms_method *) 0 ) {
						xml_get_text(xptr, &mptr->signature );
						}
					}
				break;

			case	ELEMENT_TYPE		:
				if ( xptr->heap[ (xptr->nested-1) ] == ELEMENT_METHOD ) {
					if ((mptr = xptr->payload[1]) != (struct forms_method *) 0 ) {
						xml_get_word(xptr, &mptr->type );
						}
					}
				break;

			case	ELEMENT_TEXT		:

				if ( xptr->heap[ (xptr->nested-1) ] == ELEMENT_METHOD ) {
					if ((mptr = xptr->payload[1]) != (struct forms_method *) 0 ) {
						xml_get_text(xptr,&mptr->text);
						}
					}
				else if ( xptr->heap[ (xptr->nested-2) ] == ELEMENT_WIDGET ) {
					if ((wptr = xptr->payload[1]) != (struct form_item *) 0 ) {
						xml_get_event_text(xptr);
						}
					}
				else	{
					switch ( xptr->heap[ (xptr->nested-2) ]  ) {
						case	ELEMENT_ABAL	:
						case	ELEMENT_C	:
							if ( xptr->heap[ (xptr->nested-3) ] == ELEMENT_WIDGET ) {
								if ((wptr = xptr->payload[1]) != (struct form_item *) 0 ) {
									xml_get_event_text(xptr);
									}
								}
							break;
						}
					}
				break;

			case	ELEMENT_OPTION		:
				xml_get_event_option(xptr);
				break;

			case	ELEMENT_NAME		:
				if ( xptr->heap[ (xptr->nested-1) ] == ELEMENT_WIDGET ) {
					if ((wptr = xptr->payload[1]) != (struct form_item *) 0 ) {
						xml_get_string(xptr, &wptr->Contents.name );
						}
					}
				else if ( xptr->heap[ (xptr->nested-1) ] == ELEMENT_METHOD ) {
					if ((mptr = xptr->payload[1]) != (struct forms_method *) 0 ) {
						xml_get_string(xptr, &mptr->name );
						}
					}
				break;
			case	ELEMENT_PUBLIC		:
				if ( xptr->heap[ (xptr->nested-1) ] == ELEMENT_WIDGET ) {
					if ((wptr = xptr->payload[1]) != (struct form_item *) 0 ) {
						wptr->Contents.access |=_WIDGET_PUBLIC;
						}
					}
				break;

			case	ELEMENT_EXTERN	:
				if ( xptr->heap[ (xptr->nested-1) ] == ELEMENT_WIDGET ) {
					if ((wptr = xptr->payload[1]) != (struct form_item *) 0 ) {
						wptr->Contents.access |=_WIDGET_EXTERN;
						}
					}
				break;
			case	ELEMENT_DISABLE	:
				if ( xptr->heap[ (xptr->nested-1) ] == ELEMENT_WIDGET ) {
					if ((wptr = xptr->payload[1]) != (struct form_item *) 0 ) {
						wptr->Contents.access |=_WIDGET_DISABLE;
						}
					}
				break;
			case	ELEMENT_INHIBIT	:
				if ( xptr->heap[ (xptr->nested-1) ] == ELEMENT_WIDGET ) {
					if ((wptr = xptr->payload[1]) != (struct form_item *) 0 ) {
						wptr->Contents.access |=_WIDGET_INHIBIT;
						}
					}
				break;

			case	ELEMENT_PAGE		:
				break;
			case	ELEMENT_DEVICE		:
				xml_get_string	(xptr,&fptr->printout.DeviceName);
				break;
			case	ELEMENT_DRIVER		:
				xml_get_string	(xptr,&fptr->printout.DriverName);
				break;
			case	ELEMENT_LAYOUT		:
				xml_get_word	(xptr,&fptr->printout.Layout);
				break;
			case	ELEMENT_PAPER		:
				xml_get_word	(xptr,&fptr->printout.PaperType);
				break;
			case	ELEMENT_DPI		:
				xml_get_word	(xptr,&fptr->printout.PrintResolution);
				break;
			case	ELEMENT_FEED		:
				xml_get_word	(xptr,&fptr->printout.FeedOpt);
				break;
			case	ELEMENT_PREVIEW		:
				xml_get_word	(xptr,&fptr->printout.Preview);
				break;
			case	ELEMENT_MESSAGE		:
				xml_get_string	(xptr,&fptr->printout.PageHead);
				break;
			case	ELEMENT_TOPMARGIN	:
				xml_get_margin	(xptr,&fptr->printout.TopMargin,&fptr->printout.BottomMargin);
				break;
			case	ELEMENT_LEFTMARGIN	:
				xml_get_margin	(xptr,&fptr->printout.LeftMargin,&fptr->printout.RightMargin);
				break;

			case	ELEMENT_FLAGS		:	
				xml_get_word(xptr,&fptr->abal.flags);		break;
			case	ELEMENT_VALUES		:	 	
				xml_get_word(xptr,&fptr->abal.values);		break;
			case	ELEMENT_MEMORY		:	 	
				xml_get_word(xptr,&fptr->abal.diezemem);	break;
			case	ELEMENT_FILES		:	 	
				xml_get_word(xptr,&fptr->abal.diezefiles);	break;
			case	ELEMENT_STACK		:	 	
				xml_get_word(xptr,&fptr->abal.diezestack);	break;
			case	ELEMENT_HEAP		:	 	
				xml_get_word(xptr,&fptr->abal.diezeheap);	break;
			case	ELEMENT_TOKENSIZE	:	 	
				xml_get_word(xptr,&fptr->abal.tokensize);	break;
			case	ELEMENT_LABELSIZE	:	 	
				xml_get_word(xptr,&fptr->abal.labelsize);	break;
			case	ELEMENT_PRAGMAFILE	:	 	
				xml_get_string(xptr,&fptr->abal.pragmafile);	break;

			case	ELEMENT_HELP		:	 	
				xml_get_word(xptr,&fptr->onlinehelp);		break;

			case	ELEMENT_EXTENSION		:	 	
				xml_get_word(xptr,&fptr->extension);		break;

			case	ELEMENT_GRID 		:	 	
				xml_get_word(xptr,&fptr->gridsize);
				if (!( fptr->gridsize & 0x00FF))
					fptr->gridsize |= 0x000A;
				if (!( fptr->gridsize & 0xFF00))
					fptr->gridsize |= 0x0A00;
				break;

			case	ELEMENT_WHRESIZE	:
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 )
					xml_get_xy(xptr, &wptr->Contents.wResize, &wptr->Contents.hResize );
				break;

			case	ELEMENT_OPTIONS_COMPILE	:
				xml_get_string(xptr, &fptr->OptionsCompile );
				break;

			case	ELEMENT_OPTIONS_LINKAGE	:
				xml_get_string(xptr, &fptr->OptionsLinkage );
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

public	int	xml_error_handler( char * nomfic, int status, int nblin )
{
	char	*	nptr;
	FILE	*	hptr;
	if (!(nptr = allocate_string( nomfic ) ))
		return(status);
	else if (!(nptr = enforce_extension( nptr, ERR_EXTENSION ) ))
		return(status);
	else if (!( hptr = fopen( nptr, "w" ) )) {
		liberate( nptr );
		return( status );
		}
	else	{
		fprintf(hptr,"%s %lu 1 xml parser failure : %u \r\n",nomfic,nblin+1,nomfic,status);
		fclose(hptr);
		trace_editor( nptr );
		return( status );
		}
}

public 	struct form_control * load_XmlForm(struct form_control* fptr, char * loadname,int reset, int automatic )
{
	char *	dptr;
	int	status;
	char *	eptr;
	int	evalue=0;
	FILE *	h;
	struct	xml_relay relays = {
		xml_open_form_tag,
		xml_form_atb_name,
		xml_form_atb_value,
		(void*)0,
		(void*)0,
		(void*)0,
		xml_close_form_tag,
		xml_error_handler,
		};
	char * vtrav,*app_forms;


	if ( method_is_valid((app_forms = application_forms_folder())) ) {
		add_path_terminator(&app_forms );
		vtrav=relative_filename(loadname, app_forms);
		liberate(app_forms);
		}
	else if (!( vtrav=allocate_string(loadname) ))
		return( fptr );
		
	inhibit_rollback();

	if (!( fptr )) {
		if (!( fptr = allocate_Form(vtrav))) {
			vtrav=liberate(vtrav);
			allow_rollback();
			return(fptr);
			}
		else	new_Form(fptr, vtrav );
		reset = 0;
		}
	else if ( reset ) {
		if (!( h = fopen(vtrav,"r" ))) {
			vtrav=liberate(vtrav);
			allow_rollback();
			return(fptr);
			}		
		else 	fclose(h);
		}

	if ( loadname )
		if (!( automatic & _INHIBIT_STATUS ))
			status_message(loadname,3);

	if ((eptr = confgetenv("XMLECHO")) != (char *) 0)
		evalue = (*eptr - '0');
	else	evalue = 0;

	set_xml_echo(evalue);

	if ( reset ) { remove_Form( fptr ); }

	if ((status = xml_parse( vtrav,& relays, fptr )) != 0 ) {
		status_message("xml parse failure",3);
		}

	if ( fptr ) {
		if ( fptr->loadname ) { liberate( fptr->loadname ); }
		fptr->loadname = allocate_string( vtrav );
		}

	vtrav=liberate(vtrav);
	allow_rollback();
	return( fptr );
}

public	void	Xml_form_data_widget( FILE * h, struct form_item * iptr )
{
	int	linelength;
	int	nblines;

	switch (iptr->Contents.style&_FRAME_TYPE) {

		case	_WINDOW_FRAME	:
			break;

		case	_TAB_FRAME	:
			if ( iptr->Contents.datatype != _WIDGET_OVERLAY )
				break;
			abal_xml_dcl(h,"b_",iptr->Contents.name,_ABAL_STRING,120,0,0,0);
			break;

		case	_DATA_FRAME	:
			break;

		case	_PROGRESS_FRAME	:
			abal_xml_dcl(h,"v_",iptr->Contents.name,_ABAL_WORD,0,0,0,0);
			abal_xml_dcl(h,"l_",iptr->Contents.name,_ABAL_WORD,0,0,0,0);
			break;

		case	_SCROLL_FRAME	:
			abal_xml_dcl(h,"v_",iptr->Contents.name,_ABAL_WORD,0,0,0,0);
			abal_xml_dcl(h,"l_",iptr->Contents.name,_ABAL_WORD,0,0,0,0);
			abal_xml_dcl(h,"m_",iptr->Contents.name,_ABAL_WORD,0,0,0,0);
			break;

		case	_BUTTON_FRAME	:
			if (( iptr->Contents.datatype != _WIDGET_OVERLAY )
			&&  ( iptr->Contents.datatype != _WIDGET_CHAIN   )
#ifdef	ABAL32A
			&&  ( iptr->Contents.datatype != _WIDGET_TASK    )
#endif
			&&  ( iptr->Contents.datatype != _WIDGET_SYSTEM  )
			&&  ( iptr->Contents.datatype != _WIDGET_LOADGO  ))
				break;
			abal_xml_dcl(h,"b_",iptr->Contents.name,_ABAL_STRING,120,0,0,0);
			break;

		case	_GRAPH_FRAME	:
			abal_xml_dcl(h,"l_",iptr->Contents.name,_ABAL_WORD,0,0,0,0);
			if ( iptr->Contents.datatype != _WIDGET_VOID ) {
				switch ( iptr->Contents.datatype ) {
					case	_WIDGET_BYTE :
						abal_xml_dcl(h,"v_",iptr->Contents.name,_ABAL_BYTE,1,iptr->Contents.w,0,0);
						break;
					case	_WIDGET_WORD :
						abal_xml_dcl(h,"v_",iptr->Contents.name,_ABAL_WORD,2,iptr->Contents.w,0,0);
						break;
					case	_WIDGET_LONG :
						abal_xml_dcl(h,"v_",iptr->Contents.name,_ABAL_LONG,4,iptr->Contents.w,0,0);
						break;
					}
				}
			else	abal_xml_dcl(h,"b_",iptr->Contents.name,_ABAL_STRING,iptr->Contents.w,0,0,0);
			break;

		case	_RADIO_FRAME	:
			if ( iptr->Contents.radio != 1 )
				break;

		case	_SELECT_FRAME	:
		case	_CHECK_FRAME	:
		case	_SWITCH_FRAME	:
			abal_xml_dcl(h,"v_",iptr->Contents.name,_ABAL_WORD,0,0,0,0);
			break;

		case	_FORM_FRAME	:
			calculate_edit_size( &iptr->Contents );
			calculate_form_lines( iptr, &linelength, &nblines );
			abal_xml_dcl(h,"b_",iptr->Contents.name,_ABAL_STRING,iptr->Contents.size,0,0,0);
			break;

		case	_EDIT_FRAME	:
			calculate_edit_size( &iptr->Contents );
			calculate_edit_lines( iptr, &linelength, &nblines );
			abal_xml_dcl(h,"b_",iptr->Contents.name,_ABAL_STRING,iptr->Contents.size,0,0,0);
			break;
		}
	return;
}

public	void	Xml_form_data_collection( char * bnptr, int blen, char * fnptr, int flen )
{
	struct form_control * fptr;
	struct form_item * iptr;
	char	*	xsname=(char *) 0;
	char	*	basename;
	char	*	formname;
	int	i;
	FILE *	h=(FILE *) 0;

	if (!( formname = allocate( flen + 1)))
		return;
	for (i=0; i < flen; i++ ) 
		if (( *(formname +i) = *(fnptr+i)) == ' ')
			break;
	*(formname+i) = 0;

	if (!( basename = allocate( blen + 1))) {
		liberate( formname );
		return;
		}
	for (i=0; i < blen; i++ ) 
		if (( *(basename +i) = *(bnptr+i)) == ' ')
			break;
	*(basename+i) = 0;

	
	if (!( fptr = locate_form_control( formname ) )) {
		liberate( basename );
		liberate( formname );
		}

	/* Create Production Target */
	/* ------------------------ */
	else if (!(h = open_xml_target( basename, &xsname, "DATABASE", _DATABASE_DTD , _DATABASE_CSS ))) {
		liberate( basename );
		return;
		}
	else 	{

		/* Open Document Section */
		/* --------------------- */
		fprintf(h,"<BASE>");
		linefeed(h);

		indent(h,1);
		fprintf(h,"<%s","VMEMORY");
		fprintf(h," CLASS=class_%s",fptr->identifier);
		fprintf(h," NAME=name_%s",fptr->identifier);
		fprintf(h,">");	
		linefeed(h);

		indent(h,2);
		fprintf(h,"<FILE>file_%s</FILE>",fptr->identifier);
		linefeed(h);
		indent(h,2);
		fprintf(h,"<RECORD SIZE=%u>",13);
		linefeed(h);

		for (	iptr=fptr->first;  
			iptr != (struct form_item *) 0; 
			iptr = iptr->next )  {
			if ((!( iptr->Contents.w  ))
			||  (!( iptr->Contents.h  )))
				continue;
			else	Xml_form_data_widget( h, iptr );
			}
		indent(h,1);
		fprintf(h,"</%s>","VMEMORY");
		linefeed(h);

		/* Close Document Section */
		/* ---------------------- */
		fprintf(h,"</BASE>");
		linefeed(h);
		linefeed(h);
		close_production_target(h,xsname);
		liberate( xsname );
		liberate( basename );
		liberate( formname );
		}
	return;
}


#endif	/* _xmlform_c */
	/* ---------- */



