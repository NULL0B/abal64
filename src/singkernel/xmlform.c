#ifndef	_singxml_c
#define	_singxml_c

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

extern	char * workbuffer;

struct	form_item 		* allocate_for_Widget();
struct	forms_method		* allocate_for_Method();
struct	forms_data_member	* allocate_for_Member();
static	int			CurrentAtbName=0;

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

private	void	xml_put_margin(FILE * h, char * tag, int value, int type, int margin )
{
	indent(h,margin);
	fprintf(h,"<%sMARGIN>%u %u</%sMARGIN>",tag,value,type,tag);
	linefeed(h);
}

private	void	xml_put_helptext(FILE * h, char * tag, char * sptr, int margin)
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

public 	void	xml_put_Form( struct form_control * fptr, char * dtdname )
{
	char *	sptr;
	FILE * h;
	char * fmptr;
	char * sname=(char *) 0;
	struct	form_item * iptr;
	struct	forms_method * mptr;
	struct	forms_data_member * dptr;
	int	i;

	if ((h = open_xml_target( fptr->loadname, &sname,"FORM", "sing.dtd", "sing.css" )) != (FILE*) 0) {

		fprintf(h,"<FORM>");
		linefeed(h);
		xml_put_string(h,"IDENTIFIER",fptr->identifier,1);
		switch ( fptr->language ) {
			case	_GENERATE_C	: sptr = "C"; break;
			case	_GENERATE_CPP	: sptr = "C++"; break;
			case	_GENERATE_BAL	: sptr = "ABAL"; break;
			case	_GENERATE_ABAL	: sptr = "ABAL++"; break;
			case	_GENERATE_HTML	: sptr = "HTML"; break;
			case	_GENERATE_JAVA	: sptr = "JAVA"; break;
			case	_GENERATE_COBOL : sptr = "COBOL"; break;
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

		if ( fptr->formflags & _FORM_CONSTANTS )
			xml_put_word(h,"CONSTANTS",1,1);
		else	xml_put_word(h,"CONSTANTS",0,1);

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

		if ( fptr->stylesheet ) {
			xml_put_string(h,"STYLE",fptr->stylesheet,1);
			}
		if ( fptr->clearscreen) {
			xml_put_string(h,"CLEAR",fptr->clearscreen,1);
			}
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
			case 	_FORM_TYPE_SCROLL	:
				fprintf(h," SCROLL"); break;
			case 	_FORM_TYPE_PAGE		:
				fprintf(h," PAGE"); break;
			}
		fprintf(h,"</CLASS>");
		linefeed(h);
		xml_put_string(h,"SOURCE",fptr->loadname,1);
		xml_put_string(h,"TARGET",fptr->prodname,1);
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
		if ( fptr->mimoflags & 2 )
			fprintf(h," KEY");
		if ( fptr->mimoflags & _MIMO_SEND_LEFT )
			fprintf(h," LEFT");
		if ( fptr->mimoflags & _MIMO_SEND_MIDDLE)
			fprintf(h," OTHER");
		if ( fptr->mimoflags & _MIMO_SEND_RIGHT)
			fprintf(h," RIGHT");
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
			if (!( method_is_valid( dptr->name ) ))
				continue;
			else	{
				indent(h,1);
				fprintf(h,"<MEMBER NAME=%s TYPE=%u SIZE=%u FIRST=%u SECOND=%u />",dptr->name,dptr->type,dptr->size,dptr->first,dptr->second); 
				linefeed(h);
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
			xml_put_string(h,"CLASS",get_widget_class(iptr->Contents.style & _FRAME_TYPE),2);
			if ( iptr->Contents.style )
				xml_put_string(h,"STYLE",iptr->Contents.stylesheet,2);
			xml_put_coordinate(h,"POSITION",iptr->Contents.x,iptr->Contents.y,2);
			xml_put_coordinate(h,"DIMENSION",iptr->Contents.w,iptr->Contents.h,2);
			xml_put_word(h,"FONT",iptr->Contents.font,2);
			xml_put_word(h,"COLOUR",iptr->Contents.colour,2);
			xml_put_word(h,"MOUSE",iptr->Contents.events.mimo,2);
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
			xml_put_word(h,"CONTROL",iptr->Contents.events.control,2);
			xml_put_word(h,"DATATYPE",iptr->Contents.datatype,2);
			xml_put_word(h,"ALIGN",iptr->Contents.align,2);
			xml_put_event(h,"ONCREATE",iptr->Contents.events.xo_create,iptr->Contents.events.on_create,2);
			xml_put_event(h,"ONSHOW",iptr->Contents.events.xo_show,iptr->Contents.events.on_show,2);
			xml_put_event(h,"ONGETFOCUS",iptr->Contents.events.xo_get_focus,iptr->Contents.events.on_get_focus,2);
			xml_put_event(h,"ONEVENT",iptr->Contents.events.xo_event,iptr->Contents.events.on_event,2);
			xml_put_event(h,"ONLOSEFOCUS",iptr->Contents.events.xo_lose_focus,iptr->Contents.events.on_lose_focus,2);
			xml_put_event(h,"ONHIDE",iptr->Contents.events.xo_hide,iptr->Contents.events.on_hide,2);
			xml_put_event(h,"ONREMOVE",iptr->Contents.events.xo_remove,iptr->Contents.events.on_remove,2);
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
			if ( iptr->Contents.hint ) {
				xml_put_string(h,"HINT",iptr->Contents.hint,1);
				}
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
	return;
}

private	void	xml_get_event_text(struct xml_application * xptr)
{
	struct	form_item * wptr;
	if (!( wptr = xptr->payload[1] ))
		return;
	else if ( xptr->heap[ (xptr->nested-2) ] != ELEMENT_WIDGET )
		return;
	else	{
		switch ( xptr->heap[ (xptr->nested-1) ] ) {
			case	ELEMENT_ONCREATE	: // 0x001E	
				xml_get_text( xptr, & wptr->Contents.events.on_create );
				break;
			case	ELEMENT_ONSHOW		: // 0x001F	
				xml_get_text( xptr, & wptr->Contents.events.on_show );
				break;
			case	ELEMENT_ONGETFOCUS	: // 0x0020	
				xml_get_text( xptr, & wptr->Contents.events.on_get_focus );
				break;
			case	ELEMENT_ONEVENT		: // 0x0021 	
				xml_get_text( xptr, & wptr->Contents.events.on_event );
				break;
			case	ELEMENT_ONLOSEFOCUS	: // 0x0022 	
				xml_get_text( xptr, & wptr->Contents.events.on_lose_focus );
				break;
			case	ELEMENT_ONHIDE		: // 0x0023		
				xml_get_text( xptr, & wptr->Contents.events.on_hide );
				break;
			case	ELEMENT_ONREMOVE	: // 0x0024
				xml_get_text( xptr, & wptr->Contents.events.on_remove );
				break;

			}
		}
	return;
}

private	void	xml_get_event_option(struct xml_application * xptr)
{
	struct	form_item * wptr;
	if (!( wptr = xptr->payload[1] ))
		return;
	else if ( xptr->heap[ (xptr->nested-2) ] != ELEMENT_WIDGET )
		return;
	else	{
		switch ( xptr->heap[ (xptr->nested-1) ] ) {
			case	ELEMENT_ONCREATE	: // 0x001E	
				xml_get_word(xptr, & wptr->Contents.events.xo_create );
				break;
			case	ELEMENT_ONSHOW		: // 0x001F	
				xml_get_word(xptr, & wptr->Contents.events.xo_show );
				break;
			case	ELEMENT_ONGETFOCUS	: // 0x0020	
				xml_get_word(xptr, & wptr->Contents.events.xo_get_focus );
				break;
			case	ELEMENT_ONEVENT		: // 0x0021 	
				xml_get_word(xptr, & wptr->Contents.events.xo_event );
				break;
			case	ELEMENT_ONLOSEFOCUS	: // 0x0022 	
				xml_get_word(xptr, & wptr->Contents.events.xo_lose_focus );
				break;
			case	ELEMENT_ONHIDE		: // 0x0023		
				xml_get_word(xptr, & wptr->Contents.events.xo_hide );
				break;
			case	ELEMENT_ONREMOVE	: // 0x0024
				xml_get_word(xptr, & wptr->Contents.events.xo_remove );
				break;

			}
		}
	return;
}

private	void	xml_get_align(struct xml_application * xptr)
{
	struct form_control * fptr;
	struct form_item * wptr;
	if ( xptr->heap[ (xptr->nested-1) ] == ELEMENT_WIDGET ) {
		if (!(wptr = xptr->payload[1] ))
			return;
		else	xml_get_word(xptr, &wptr->Contents.align );
		}
	else if ( xptr->heap[ (xptr->nested-1) ] == ELEMENT_PAGE ) {
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
		fptr->mimoflags |= 2 ;
		}
	else	fptr->mimoflags &=~2 ;
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
		fptr->mimoflags |= _MIMO_IS_DOWN ;
		}
	else	fptr->mimoflags &=~_MIMO_IS_DOWN ;
	while ( *sptr == ' ' ) sptr++;
	if ( xml_mnemonic( sptr, "MOVE") ) { 
		sptr += 4; 
		fptr->mimoflags |= _MIMO_MOVE ;
		}
	else	fptr->mimoflags &=~_MIMO_MOVE ;
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
	else if ( xml_mnemonic( sptr, "JAVA" 	) )
		fptr->language = _GENERATE_JAVA;
	else if ( xml_mnemonic( sptr, "HTML" 	) )
		fptr->language = _GENERATE_HTML;
	return;
}

private	void	xml_get_class(struct xml_application * xptr)
{
	int	i;
	char *	sptr;
	struct form_control * fptr;
	struct forms_method * mptr;
	struct form_item * wptr;
	if (!( sptr = xptr->buffer ))
		return;
	while ( *sptr == ' ' ) sptr++;
	if ( xptr->heap[ (xptr->nested-1) ] == ELEMENT_WIDGET ) {
		if (!( wptr = xptr->payload[1] ))
			return;
		for (i=0; i < _FRAME_TYPE; i++ ) {
			if ( string_compare(sptr,get_widget_class(i)) ) {
				wptr->Contents.style = i;
				break;
				}
			}
		}
	else if ( xptr->heap[ (xptr->nested-1) ] == ELEMENT_FORM ) {
		if (!( fptr = xptr->payload[0] ))
			return;
		fptr->formflags &=  ~_FORM_TYPE_FLAGS;
		if ( xml_mnemonic( sptr, "DIALOG" ) )
			fptr->formflags |= _FORM_TYPE_DIALOG;
		else if ( xml_mnemonic( sptr, "EVENT" ) )
			fptr->formflags |= _FORM_TYPE_EVENT;
		else if ( xml_mnemonic( sptr, "SCROLL" ) )
			fptr->formflags |= _FORM_TYPE_SCROLL;
		else if ( xml_mnemonic( sptr, "PAGE" ) )
			fptr->formflags |= _FORM_TYPE_PAGE;
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

static	int	xml_form_atb_value(struct xml_application * xptr,char * sptr)
{ 
	struct forms_data_member* dptr;
	if ( xptr->echo )
		printf("=%s",sptr);
	if (!(dptr = xptr->payload[1]))
		return;
	switch ( CurrentAtbName ) {
		case	ELEMENT_NAME	:	dptr->name  =allocate_string( sptr ); 	break;
		case	ELEMENT_TYPE	:	dptr->type  =atoi( sptr );		break;
		case	ELEMENT_SIZE	:	dptr->size  =atoi( sptr );		break;
		case	ELEMENT_FIRST	:	dptr->first =atoi( sptr );		break;
		case	ELEMENT_SECOND	:	dptr->second=atoi( sptr );		break;
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

			case	ELEMENT_STYLE		:
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 )
					xml_get_string(xptr, &wptr->Contents.stylesheet );
				else 	xml_get_string(xptr, &fptr->stylesheet );
				break;

			case	ELEMENT_CLEAR		:
				xml_get_string(xptr, &fptr->clearscreen);
				break;
			case	ELEMENT_IDENTIFIER	: // 0x0001
				xml_get_string(xptr, &fptr->identifier );
				break;
 
			case	ELEMENT_INTERNATIONAL	: // 0x002B
				xml_get_word(xptr,&i);
				if ( i )
					fptr->formflags |= _FORM_INTERNATIONAL;
				break;

			case	ELEMENT_CONSTANTS	: // 0x002B
				xml_get_word(xptr,&i);
				if ( i )
					fptr->formflags |= _FORM_CONSTANTS;
				break;

			case	ELEMENT_COMMAND		: // 0x002C
				xml_get_xyz(xptr,&i,&fptr->argvlen,&fptr->argvcount);
				if ( i )
				fptr->formflags |= _FORM_COMMANDLINE;
				if (!( fptr->argvlen ))
					fptr->argvlen = 24;
				if (!( fptr->argvcount ))
					fptr->argvcount = 10;
				break;

			case	ELEMENT_MULTILINGUAL	: // 0x002D
				xml_get_word(xptr,&i);
				if ( i )
					fptr->formflags |= _FORM_MULTILINGUAL;
				break;

			case	ELEMENT_NATIONAL	: // 0x002A
				xml_get_word(xptr, &fptr->natlang );
				break;

			case	ELEMENT_LANGUAGE	: // 0x0002
				xml_get_production(xptr);
				break;

			case	ELEMENT_PACKAGE		: // 0x0003
				xml_get_package(xptr);
				break;

			case	ELEMENT_CLASS		: // 0x0004      
				xml_get_class(xptr);
				break;

			case	ELEMENT_SOURCE		: // 0x0005     
				xml_get_string(xptr, &fptr->loadname );
				break;
			case	ELEMENT_TARGET		: // 0x0006     
				xml_get_string(xptr, &fptr->prodname );
				break;

			case	ELEMENT_KEYS		: // 0x0007       
				xml_get_keys(xptr);
				break;

			case	ELEMENT_EVENTS		: // 0x0008      
				xml_get_events(xptr);
				break;


			case	ELEMENT_INCLUSION	: // 0x0009
				xml_get_string(xptr, &fptr->dependance );
				break;

			case	ELEMENT_MODULES		: // 0x000A
				xml_get_string(xptr, &fptr->construction );
				break;
			case	ELEMENT_DOCUMENT	: // 0x000B
				break;
			case	ELEMENT_TOOL		: // 0x000C       
				break;
			case	ELEMENT_ENGLISH		: // 0x000d    
				xml_get_language(xptr,0);
				break;
			case	ELEMENT_FRANCAIS	: // 0x000E   
				xml_get_language(xptr,1);
				break;
			case	ELEMENT_ITALIANO	: // 0x000F   
				xml_get_language(xptr,2);
				break;
			case	ELEMENT_ESPAGNOL	: // 0x0010   
				xml_get_language(xptr,3);
				break;
			case	ELEMENT_DEUTSCH		: // 0x0011    
				xml_get_language(xptr,4);
				break;
			case	ELEMENT_NEDERLANDS	: // 0x0012 
				xml_get_language(xptr,5);
				break;
			case	ELEMENT_PORTUGEUS	: // 0x0013  
				xml_get_language(xptr,6);
				break;
			case	ELEMENT_OTHER		: // 0x0014      
				xml_get_language(xptr,7);
				break;
			case	ELEMENT_WIDGET		: // 0x0015
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 ) {
					get_national_payload(wptr,fptr->natlang);
					add_Widget(   fptr, wptr, 1);
					check_Widget( wptr );
					}
				xptr->payload[1]  = (struct form_item *) 0;
				break;
			case	ELEMENT_POSITION	: // 0x0016	
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 )
					xml_get_xy(xptr,&wptr->Contents.x,&wptr->Contents.y);
				break;
			case	ELEMENT_DIMENSION	: // 0x0017 	
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 )
					xml_get_xy(xptr,&wptr->Contents.w,&wptr->Contents.h);
				break;
			case	ELEMENT_FONT		: // 0x0018		
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 )
					xml_get_word(xptr,&wptr->Contents.font);
				break;
			case	ELEMENT_COLOUR		: // 0x0019	
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 )
					xml_get_word(xptr,&wptr->Contents.colour);
				break;
			case	ELEMENT_MOUSE 		: // 0x0044	
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 )
					xml_get_word(xptr,&wptr->Contents.events.mimo);
				break;
			case	ELEMENT_FORMAT		: // 0x000000
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 )
					xml_get_string(xptr, &wptr->Contents.format );
				break;
			case	ELEMENT_INTERFACE	: // 0x001B 	
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 )
					xml_get_xy(xptr, &wptr->Contents.interfaceitem, &wptr->Contents.special );
				break;
			case	ELEMENT_DATATYPE	: // 0x001C	
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 )
					xml_get_word(xptr, &wptr->Contents.datatype );
				break;
			case	ELEMENT_CONTROL		: // 0x0027
				if ((wptr = xptr->payload[1]) != (struct form_item *) 0 )
					xml_get_word(xptr, &wptr->Contents.events.control );
				break;
			case	ELEMENT_ALIGN		: // 0x001D		
				xml_get_align(xptr);
				break;
			case	ELEMENT_PAYLOAD		: // 0x001A 
				break;
			case	ELEMENT_ONCREATE	: // 0x001E	
				break;
			case	ELEMENT_ONSHOW		: // 0x001F	
				break;
			case	ELEMENT_ONGETFOCUS	: // 0x0020	
				break;
			case	ELEMENT_ONEVENT		: // 0x0021 	
				break;
			case	ELEMENT_ONLOSEFOCUS	: // 0x0022 	
				break;
			case	ELEMENT_ONHIDE		: // 0x0023		
				break;
			case	ELEMENT_ONREMOVE	: // 0x0024
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

			case	ELEMENT_TEXT		: // 0x0025
				if ( xptr->heap[ (xptr->nested-2) ] == ELEMENT_WIDGET ) {
					if ((wptr = xptr->payload[1]) != (struct form_item *) 0 ) {
						xml_get_event_text(xptr);
						}
					}
				else if ( xptr->heap[ (xptr->nested-1) ] == ELEMENT_METHOD ) {
					if ((mptr = xptr->payload[1]) != (struct forms_method *) 0 ) {
						xml_get_text(xptr,&mptr->text);
						}
					}
				break;

			case	ELEMENT_OPTION		: // 0x0026
				xml_get_event_option(xptr);
				break;

			case	ELEMENT_HINT		: // 0x004A
				if ( xptr->heap[ (xptr->nested-1) ] == ELEMENT_WIDGET ) {
					if ((wptr = xptr->payload[1]) != (struct form_item *) 0 ) {
						xml_get_string(xptr, &wptr->Contents.hint );
						}
					}
				break;

			case	ELEMENT_NAME		: // 0x0028
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
			case	ELEMENT_PAGE		:	// 0x002E
				break;
			case	ELEMENT_DEVICE		:	// 0x002F
				xml_get_string	(xptr,&fptr->printout.DeviceName);
				break;
			case	ELEMENT_DRIVER		:	// 0x0030
				xml_get_string	(xptr,&fptr->printout.DriverName);
				break;
			case	ELEMENT_LAYOUT		:	// 0x0031
				xml_get_word	(xptr,&fptr->printout.Layout);
				break;
			case	ELEMENT_PAPER		:	// 0x0032
				xml_get_word	(xptr,&fptr->printout.PaperType);
				break;
			case	ELEMENT_DPI		:	// 0x0033
				xml_get_word	(xptr,&fptr->printout.PrintResolution);
				break;
			case	ELEMENT_FEED		:	// 0x0035
				xml_get_word	(xptr,&fptr->printout.FeedOpt);
				break;
			case	ELEMENT_PREVIEW		:	// 0x0036
				xml_get_word	(xptr,&fptr->printout.Preview);
				break;
			case	ELEMENT_MESSAGE		:	// 0x0037
				xml_get_string	(xptr,&fptr->printout.PageHead);
				break;
			case	ELEMENT_TOPMARGIN	:	// 0x0038
				xml_get_xy	(xptr,&fptr->printout.TopMargin,&fptr->printout.BottomMargin);
				break;
			case	ELEMENT_LEFTMARGIN	:	// 0x0039
				xml_get_xy	(xptr,&fptr->printout.LeftMargin,&fptr->printout.RightMargin);
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

			case	ELEMENT_GRID 		:	 	
				xml_get_word(xptr,&fptr->gridsize);
				if (!( fptr->gridsize & 0x00FF))
					fptr->gridsize |= 0x000A;
				if (!( fptr->gridsize & 0xFF00))
					fptr->gridsize |= 0x0A00;
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
	int	status;
	char *	eptr;
	int	evalue=0;
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

	if (!( fptr )) {
		if (!( fptr = allocate_Form(loadname))) {
			loadname = liberate( loadname );
			return(fptr);
			}
		else	new_Form(fptr, loadname );
		}
	if ( fptr->loadname )
		if (!( automatic & _INHIBIT_STATUS ))
			status_message(fptr->loadname,3);

	if ((eptr = getenv("XMLECHO")) != (char *) 0)
		evalue = (*eptr - '0');
	else	evalue = 0;
	set_xml_echo(evalue);

	if ((status = xml_parse( loadname,& relays, fptr )) != 0 ) {
		status_message("xml parse failure",3);
		}
	return( fptr );
}

#endif	/* _singxml_c */



