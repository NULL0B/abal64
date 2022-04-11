#ifndef	_singplus_c
#define	_singplus_c

/*	-------------------------------------------------------------	*/
/*	A B A L + +   C L A S S  /  O B J E C T   P R O D U C T I O N 	*/
/*	-------------------------------------------------------------	*/

#include <stdio.h>
#include "sing.h"
#include "palet.h"
#include "stdpsu.h"
#include "guimouse.h"
#include "singrel.h"
#include "singpix.h"
#include "allocate.h"
#define	_SYSTEM_IMAGES
#include "sysimage.h"
#include "stdimage.h"
#include "singlang.h"
#include "singedit.h"
#include "singprod.h"
#include "singpage.h"
#include "singpal.h"
#include "singbar.h"
#include "singmenu.h"
#include "singtool.h"
#include "singtext.h"
#include "singimg.h"
#include "singdesk.h"
#include "vconf.h"
#include "visual.h"
#include "singconf.h"
#include "singabal.h"
#include "abalterm.h"
#include "singtool.h"
#include "singmeth.h"
#include "singmemb.h"
#include "singplus.h"

/*	---------------------	*/
/*	ABAL++ CLASS KEYWORDS	*/
/*	---------------------	*/
public	char * keyword_public="public";
public	char * keyword_private="private";
static	char * keyword_common="common";
static	char * keyword_strict="strict";
public	char * keyword_function="function";
public	char * keyword_inline="inline";
public	char * keyword_routine="routine";
static	char * keyword_virtual="virtual";
static	char * keyword_overload="overload";
static	char * keyword_indirect="indirect";
static	char * keyword_integer="integer";
static	char * keyword_numeric="numeric";
static	char * keyword_string="string";
static	char * keyword_klass="class";
public	char * keyword_pointer="pointer";
static	char * keyword_create="create";
static	char * keyword_forget="forget";
static	char * keyword_remove="remove";
static	char * keyword_validptr="validptr";
static	char * keyword_method="method";
public	char * keyword_constructor="constructor";
public	char * keyword_destructor="destructor";
public	char * keyword_class="#class";
public	char * keyword_endclass="#endclass";

extern	char *	classbuffer;

private	char *	aplus_payload( struct form_item * iptr );
private	int	aplus_method_body( FILE * h,char * eptr, int l, char * hptr);
private	void	aplus_comment(FILE * h, struct form_item * iptr, int i);

public	void	aplus_form_onhide( FILE * h );
public	void	aplus_form_onshow  ( FILE * h, struct form_item * wptr );
public	void	aplus_form_onevent ( FILE * h, struct form_item * wptr  );
public	void	aplus_getfocus_methods( FILE * h );
public	void	aplus_losefocus_methods( FILE * h );
public	void	aplus_overlay_attach( FILE * h );
public	void	aplus_overlay_detach( FILE * h );
public	void	aplus_page_onflush( FILE * h );
public	void	aplus_page_onfinish( FILE * h );
public	void	visual_object_event_retry( FILE * h,char * prefix, int margin );

private	int	convert_integer( char * sptr )
{
	int result=0;
	int	i;
	if (!( sptr ))
		return( result );
	for ( i=0; *(sptr+i) != 0; i++ ) {
		if (( *(sptr+i) >= '0' )
		&&  ( *(sptr+i) <= '9' ))
			result = ((result*10)+( *(sptr+i) - '0' ));
		else	break;
		}
	return( result );
}

public	void	aplus_font_paramter(FILE * handle, struct form_item * iptr )
{
	fprintf(handle,";font%u.value",iptr->Contents.font);
	return;
}

public 	void	aplus_colour_parameter(FILE * handle, struct form_item * iptr )
{
	fprintf(handle,";%u;%u",
		widget_foreground_value(iptr),
		widget_background_value(iptr));
	return;
}

public 	void	aplus_string_parameter(FILE * handle, char * sptr )
{
	fprintf(handle,";");
	string_value( handle, sptr );
	return;
}

public 	void	aplus_buffer_parameter(FILE * handle, char * sptr )
{
	fprintf(handle,";");
	buffer_value( handle, sptr );
	return;
}

public 	void	aplus_length_parameter(FILE * handle, int l)
{
	fprintf(handle,";%u",l);
	return;
}

private	void aplus_overload_function(FILE * h,char * nptr) 
{
	linefeed(h);
	fprintf(h,"%s %s %s %s:",keyword_public,keyword_overload,keyword_function,nptr);
	return;
}

private	void aplus_integer_overload_function(FILE * h,char * nptr) 
{
	linefeed(h);
	fprintf(h,"%s %s %s %s %s:",keyword_public,keyword_overload,keyword_integer,keyword_function,nptr);
	return;
}

public	void	open_class_exclusion( FILE * h, char * token )
{
	fprintf(h,"#ifndef _%s_cls",token);
	linefeed(h);
	fprintf(h,"#define _%s_cls",token);
	linefeed(h);
	return;
}

public	void	close_class_exclusion( FILE * h, char * token )
{
	fprintf(h,"#endif  _%s_cls",token);
	linefeed(h);
	return;
}


private	void	instance_object_data( FILE * h, struct form_item * iptr )
{
	char *	classname=(char *) 0;
	switch (iptr->Contents.align & 0x000F) {
		case	_VARIABLE_FRAME :	/* variable 	*/
			return;
		case	_VISUAL_FRAME  :	/* visual form	*/
			if (( iptr->Contents.datatype == _WIDGET_CLASS   )
			||  ( iptr->Contents.datatype == _WIDGET_POINTER )) {
				if ( iptr->Contents.datatype == _WIDGET_POINTER ) {
					fprintf(h,"%s %s %s %s(originx+%u;originy+%u)",
						keyword_public,aplus_payload(iptr),keyword_pointer,
						iptr->Contents.name,iptr->Contents.x,iptr->Contents.y);
					}
				else	{
					fprintf(h,"%s %s %s(originx+%u;originy+%u)",
						keyword_public,aplus_payload(iptr),
						iptr->Contents.name,iptr->Contents.x,iptr->Contents.y);
					}
				linefeed(h);
				}
			return;
		case	_OBJECT_FRAME :	/* structure	*/
			if ( iptr->Contents.datatype == _WIDGET_POINTER )
				fprintf(h,"%s %s %s %s",keyword_public,aplus_payload(iptr),keyword_pointer,iptr->Contents.name);
			else	fprintf(h,"%s %s %s",keyword_public,aplus_payload(iptr),iptr->Contents.name);
			if ( iptr->Contents.format )
				fprintf(h,"(%s)",iptr->Contents.format);
			linefeed(h);
			return;
		case	_SIFILE_FRAME :	/* sifile	*/
			check_class_buffer();
			sprintf(classname=classbuffer,"sifile_%s",iptr->Contents.name);
			break;
		case	_MCFILE_FRAME :	/* mcfile	*/
			check_class_buffer();
			sprintf(classname=classbuffer,"mcfile_%s",iptr->Contents.name);
			break;
		}

	check_data_widget( &iptr->Contents);

	if ( iptr->Contents.datatype == _WIDGET_POINTER )
		fprintf(h,"%s %s %s %s(",keyword_public,classname,keyword_pointer,iptr->Contents.name);
	else	fprintf(h,"%s %s %s(",keyword_public,classname,iptr->Contents.name);
	string_value( h, aplus_payload(iptr));
	fprintf(h,")");
	linefeed(h);
	return;

}

public	void	aplus_name_and_length(FILE * handle, char * sptr, int slen )
{
	if (!( sptr )) {
		aplus_string_parameter(handle,sptr);
		aplus_length_parameter(handle,slen);
		}
	else if ( *sptr != _UNQUOTED_STRING ) {
		aplus_string_parameter(handle,sptr);
		aplus_length_parameter(handle,slen);
		}
	else	{
		aplus_string_parameter(handle,sptr);
		fprintf(handle,";Len(%s)",(sptr+1));
		}
	return;
}

private	char *	aplus_payload( struct form_item * iptr )
{
	struct form_control * fptr;
	if (!( fptr = iptr->parent )) 
		return( check_payload(iptr->Contents.payload) );
	else if (!( fptr->formflags & _INTERNATIONAL ))
		return( check_payload(iptr->Contents.payload) );
	else	return( check_payload(iptr->Contents.messages[fptr->natlang]) );
}
	
private	char *	aplus_hint( struct form_item * iptr )
{
	struct form_control * fptr;
	if (!( fptr = iptr->parent )) 
		return( check_payload(iptr->Contents.hint) );
	else if (!( fptr->formflags & _INTERNATIONAL ))
		return( check_payload(iptr->Contents.hint) );
	else	return( check_payload(iptr->Contents.hmessages[fptr->natlang]) );
}
	
public	void	aplus_string_and_length(FILE * handle, struct form_item * iptr )
{
	char * 	sptr;
	if (!( sptr = aplus_payload(iptr) )) {
		aplus_string_parameter(handle,sptr);
		aplus_length_parameter(handle,0);
		}
	else if ( *sptr != _UNQUOTED_STRING ) {
		aplus_string_parameter(handle,sptr);
		aplus_length_parameter(handle,strlen( sptr));
		}
	else	{
		aplus_string_parameter(handle,sptr);
		fprintf(handle,";Len(%s)",(sptr+1));
		}
	return;
}

public	void	aplus_hint_and_length(FILE * handle, struct form_item * iptr )
{
	char * 	sptr;
	if (!( sptr = aplus_hint(iptr) )) {
		aplus_string_parameter(handle,sptr);
		aplus_length_parameter(handle,0);
		}
	else if ( *sptr != _UNQUOTED_STRING ) {
		aplus_string_parameter(handle,sptr);
		aplus_length_parameter(handle,strlen( sptr));
		}
	else	{
		aplus_string_parameter(handle,sptr);
		fprintf(handle,";Len(%s)",(sptr+1));
		}
	return;
}

public	void	instance_aplus(FILE * handle, struct form_item * iptr )
{
	int	v;
	struct form_control * fptr;
	int	s;
	int	i=0;
	int	xh=0;
	int	fh=0;
	int	isevent=0;
	char 	*	mptr;

#ifdef not_any_ore
	if (!( iptr )) {
		/* visual_group : replaces visual window */
		/* ------------------------------------- */
		fprintf(handle,"%s visual_group vgroup",keyword_public);
		linefeed(handle);
		return;
		}
#endif
	if (!( iptr ))
		return;
	if ((!( iptr->Contents.w  ))
	||  (!( iptr->Contents.h  )))
		return;

	switch (((s=iptr->Contents.style)&_FRAME_TYPE)) {
		case	_INSET_FRAME	:
		case	_OUTSET_FRAME	:
		case	_GROOVE_FRAME	:
		case	_RIDGE_FRAME	:
			if (( iptr->Contents.align != _A_NONE     ) 
			&&  ( aplus_payload(iptr) != (char *) 0)) {
				fh = (guifontsize(iptr->Contents.font)>>8);
				xh = iptr->Contents.h;
				iptr->Contents.h = fh;
				fprintf(handle,"%s visual_text l_%s(originx+%u;originy+%u;%u;%u",
						keyword_public,
						iptr->Contents.name,
						iptr->Contents.x,
						iptr->Contents.y,
						iptr->Contents.w,
						iptr->Contents.h );
				aplus_font_paramter(handle,iptr);
				aplus_colour_parameter(handle,iptr);
				aplus_string_and_length(handle,iptr);
				fprintf(handle,";%u)",iptr->Contents.align);
				linefeed(handle);
				iptr->Contents.y += fh;
				iptr->Contents.h = xh;
				iptr->Contents.h -= fh;
				}			
		}
	switch (((s=iptr->Contents.style)&_FRAME_TYPE)) {
		case	_DATA_FRAME	:
			instance_object_data(handle,iptr);
			break;
		case	_FILL_FRAME	:
			fprintf(handle,"%s visual_fill %s(originx+%u;originy+%u;%u;%u;%u;%u)",
					keyword_public,
					iptr->Contents.name,
					iptr->Contents.x,
					iptr->Contents.y,
					iptr->Contents.w,
					iptr->Contents.h,
					iptr->Contents.align,
					iptr->Contents.colour );
			linefeed(handle);
			break;

		case	_INSET_FRAME	:
			fprintf(handle,"%s visual_frame %s(originx+%u;originy+%u;%u;%u;%u)",
					keyword_public,
					iptr->Contents.name,
					iptr->Contents.x,
					iptr->Contents.y,
					iptr->Contents.w,
					iptr->Contents.h,s );
			linefeed(handle);
			iptr->Contents.y -= fh; 
			iptr->Contents.h += fh;
			break;

		case	_OUTSET_FRAME	:
			fprintf(handle,"%s visual_frame %s(originx+%u;originy+%u;%u;%u;%u)",
					keyword_public,
					iptr->Contents.name,
					iptr->Contents.x,
					iptr->Contents.y,
					iptr->Contents.w,
					iptr->Contents.h,s );
			linefeed(handle);
			iptr->Contents.y -= fh; 
			iptr->Contents.h += fh;
			break;

		case	_GROOVE_FRAME	:
			fprintf(handle,"%s visual_frame %s(originx+%u;originy+%u;%u;%u;%u)",
					keyword_public,
					iptr->Contents.name,
					iptr->Contents.x,
					iptr->Contents.y,
					iptr->Contents.w,
					iptr->Contents.h,s );
			linefeed(handle);
			iptr->Contents.y -= fh; 
			iptr->Contents.h += fh;
			break;

		case	_RIDGE_FRAME	:
			fprintf(handle,"%s visual_frame %s(originx+%u;originy+%u;%u;%u;%u)",
					keyword_public,
					iptr->Contents.name,
					iptr->Contents.x,
					iptr->Contents.y,
					iptr->Contents.w,
					iptr->Contents.h,s );
			linefeed(handle);
			iptr->Contents.y -= fh; 
			iptr->Contents.h += fh;
			break;

		case	_EDIT_FRAME	:
			calculate_edit_size( &iptr->Contents );
			fprintf(handle,"%s visual_edit %s(originx+%u;originy+%u;%u;%u",
					keyword_public,
					iptr->Contents.name,
					iptr->Contents.x,
					iptr->Contents.y,
					iptr->Contents.w+2,
					iptr->Contents.h+2 );
			aplus_font_paramter(handle,iptr);
			aplus_string_parameter(handle,aplus_payload(iptr));
			aplus_length_parameter(handle,iptr->Contents.size);
			fprintf(handle,")");
			linefeed(handle);
			break;

		case	_SELECT_FRAME	:
			calculate_edit_size( &iptr->Contents );
			fprintf(handle,"%s visual_select %s(originx+%u;originy+%u;%u;%u",
					keyword_public,
					iptr->Contents.name,
					iptr->Contents.x,
					iptr->Contents.y,
					iptr->Contents.w,
					iptr->Contents.h );
			aplus_font_paramter(handle,iptr);
			aplus_colour_parameter(handle,iptr);
			aplus_string_and_length(handle,iptr);
			fprintf(handle,";0)");
			linefeed(handle);
			break;
		case	_TEXT_FRAME	:
			fprintf(handle,"%s visual_text %s(originx+%u;originy+%u;%u;%u",
					keyword_public,
					iptr->Contents.name,
					iptr->Contents.x,
					iptr->Contents.y,
					iptr->Contents.w,
					iptr->Contents.h );
			aplus_font_paramter(handle,iptr);
			aplus_colour_parameter(handle,iptr);
			aplus_string_and_length(handle,iptr);
			fprintf(handle,";%u)",iptr->Contents.align);
			linefeed(handle);
			break;
		case	_LINE_FRAME	:
			fprintf(handle,"%s visual_line %s(originx+%u;originy+%u;%u;%u;%u;%u)",
					keyword_public,
					iptr->Contents.name,
					iptr->Contents.x,
					iptr->Contents.y,
					iptr->Contents.w,
					iptr->Contents.h,
					iptr->Contents.size,
					iptr->Contents.colour  );
			linefeed(handle);
			break;

		case	_IMAGE_FRAME	:
			fprintf(handle,"%s visual_image %s(originx+%u;originy+%u;%u;%u",
					keyword_public,
					iptr->Contents.name,
					iptr->Contents.x,
					iptr->Contents.y,
					iptr->Contents.w,
					iptr->Contents.h);
			aplus_string_and_length(handle,iptr);
			fprintf(handle,";%u)",iptr->Contents.align);
			linefeed(handle);
			break;

		case	_BUTTON_FRAME	:
			if ( iptr->Contents.datatype == _WIDGET_OVERLAY ) {
				fprintf(handle,"%s overlay_button %s(originx+%u;originy+%u;%u;%u",
						keyword_public,
						iptr->Contents.name,
						iptr->Contents.x,
						iptr->Contents.y,
						iptr->Contents.w,
						iptr->Contents.h );
				}
			else if ( iptr->Contents.datatype == _WIDGET_CHAIN ) {
				fprintf(handle,"%s chain_button %s(originx+%u;originy+%u;%u;%u",
						keyword_public,
						iptr->Contents.name,
						iptr->Contents.x,
						iptr->Contents.y,
						iptr->Contents.w,
						iptr->Contents.h );
				}
			else if (( iptr->Contents.datatype == _WIDGET_SYSTEM ) 
#ifdef	ABAL32A
			     ||  ( iptr->Contents.datatype == _WIDGET_TASK   )   
#endif
			     ||  ( iptr->Contents.datatype == _WIDGET_LOADGO )) {
				fprintf(handle,"%s loadgo_button %s(originx+%u;originy+%u;%u;%u",
						keyword_public,
						iptr->Contents.name,
						iptr->Contents.x,
						iptr->Contents.y,
						iptr->Contents.w,
						iptr->Contents.h );
				}
			else	{
				fprintf(handle,"%s visual_button %s(originx+%u;originy+%u;%u;%u",
						keyword_public,
						iptr->Contents.name,
						iptr->Contents.x,
						iptr->Contents.y,
						iptr->Contents.w,
						iptr->Contents.h );
				}
			aplus_font_paramter(handle,iptr);
			aplus_colour_parameter(handle,iptr);
			aplus_string_and_length(handle,iptr);
			if (( iptr->Contents.datatype == _WIDGET_OVERLAY ) 
			||  ( iptr->Contents.datatype == _WIDGET_CHAIN   ) 
#ifdef	ABAL32A
			||  ( iptr->Contents.datatype == _WIDGET_TASK    ) 
#endif
			||  ( iptr->Contents.datatype == _WIDGET_SYSTEM  ) 
			||  ( iptr->Contents.datatype == _WIDGET_LOADGO  )) {
				aplus_name_and_length(handle,iptr->Contents.format,strlen(iptr->Contents.format));
				}
			if ( iptr->Contents.align & 1 )
				isevent |= _VISUAL_IMAGE;
			if ( iptr->Contents.align & 2 )
				isevent |= _INHIBIT_FRAME;
			if ( iptr->Contents.align & _A_BOLD )
				isevent |= _A_BOLD;
			if ( iptr->Contents.align & _A_LINE )
				isevent |= _A_LINE;
			if ( iptr->Contents.align & _A_SHADOW )
				isevent |= _A_SHADOW;
			fprintf(handle,";%u)",isevent);
			linefeed(handle);
			break;
		case	_SWITCH_FRAME	:
			fprintf(handle,"%s visual_switch %s(originx+%u;originy+%u;%u;%u",
					keyword_public,
					iptr->Contents.name,
					iptr->Contents.x,
					iptr->Contents.y,
					iptr->Contents.w,
					iptr->Contents.h );
			aplus_font_paramter(handle,iptr);
			aplus_colour_parameter(handle,iptr);
			aplus_string_and_length(handle,iptr);
			fprintf(handle,";/%04.4X",(( iptr->Contents.align & 0x0F00) | (( iptr->Contents.align & 0x000F) << 4)));
			fprintf(handle,")");
			linefeed(handle);
			break;
		case	_PROGRESS_FRAME	:
			fprintf(handle,"%s visual_progress %s(originx+%u;originy+%u;%u;%u",
					keyword_public,
					iptr->Contents.name,
					iptr->Contents.x,
					iptr->Contents.y,
					iptr->Contents.w,
					iptr->Contents.h );
			aplus_font_paramter(handle,iptr);
			aplus_colour_parameter(handle,iptr);
			fprintf(handle,")");
			linefeed(handle);
			break;
		case	_SCROLL_FRAME	:
			fprintf(handle,"%s visual_scroll %s(originx+%u;originy+%u;%u;%u",
					keyword_public,
					iptr->Contents.name,
					iptr->Contents.x,
					iptr->Contents.y,
					iptr->Contents.w,
					iptr->Contents.h );
			aplus_font_paramter(handle,iptr);
			aplus_colour_parameter(handle,iptr);
			fprintf(handle,";%u)",iptr->Contents.align);
			linefeed(handle);
			break;

		case	_FORM_FRAME	:
			fprintf(handle,"%s visual_table_%s %s(originx+%u;originy+%u;%u;%u",
					keyword_public,
					iptr->Contents.name,
					iptr->Contents.name,
					iptr->Contents.x,
					iptr->Contents.y,
					iptr->Contents.w,
					iptr->Contents.h );
			aplus_font_paramter(handle,iptr);
			aplus_colour_parameter(handle,iptr);
			aplus_string_and_length(handle,iptr);
			if (!( is_valid_format( iptr->Contents.format ) )) {
				aplus_string_parameter(handle,"()");
				aplus_length_parameter(handle,2);
				fprintf(handle,";/0%x)",iptr->Contents.align);
				}
			else	{
				aplus_string_parameter(handle,iptr->Contents.format);
				aplus_length_parameter(handle,strlen(iptr->Contents.format));
				fprintf(handle,";/%x)",(iptr->Contents.align | 0x4000));
				}
			linefeed(handle);
			break;

		case	_GRAPH_FRAME	:
			fprintf(handle,"%s visual_graph %s(originx+%u;originy+%u;%u;%u",
					keyword_public,
					iptr->Contents.name,
					iptr->Contents.x,
					iptr->Contents.y,
					iptr->Contents.w,
					iptr->Contents.h );
			aplus_font_paramter(handle,iptr);
			aplus_colour_parameter(handle,iptr);
			if (!( i = convert_integer(aplus_payload(iptr)) ))
				i = iptr->Contents.w;
			aplus_length_parameter(handle,i);
			switch ( iptr->Contents.datatype ) {
				case	_WIDGET_WORD : fprintf(handle,";1"); break;
				case	_WIDGET_LONG : fprintf(handle,";2"); break;
				case	_WIDGET_VOID :
				case	_WIDGET_BYTE : 
				default		     : fprintf(handle,";0"); break;
				}
			fprintf(handle,")");
			linefeed(handle);
			break;
		case	_CHECK_FRAME	:
			fprintf(handle,"%s visual_check %s(originx+%u;originy+%u;%u;%u",
					keyword_public,
					iptr->Contents.name,
					iptr->Contents.x,
					iptr->Contents.y,
					iptr->Contents.w,
					iptr->Contents.h );
			aplus_font_paramter(handle,iptr);
			aplus_colour_parameter(handle,iptr);
			aplus_string_and_length(handle,iptr);
			fprintf(handle,")");
			linefeed(handle);
			break;
		case	_RADIO_FRAME	:
			fprintf(handle,"%s visual_radio %s(originx+%u;originy+%u;%u;%u",
					keyword_public,
					iptr->Contents.name,
					iptr->Contents.x,
					iptr->Contents.y,
					iptr->Contents.w,
					iptr->Contents.h );
			aplus_font_paramter(handle,iptr);
			aplus_colour_parameter(handle,iptr);
			aplus_string_and_length(handle,iptr);
			fprintf(handle,")");
			linefeed(handle);
			break;

		case	_WINDOW_FRAME	:
			if (((fptr = iptr->parent) != (struct form_control*) 0)
			&&  (fptr->formflags & _MULTILINGUAL ))
				v = _WINDOW_LANG_BUTTON;
			else	v = 0;
			fprintf(handle,"%s visual_window %s(originx+%u;originy+%u;%u;%u",
					keyword_public,
					iptr->Contents.name,
					iptr->Contents.x,
					iptr->Contents.y,
					iptr->Contents.w,
					iptr->Contents.h);
			aplus_font_paramter(handle,iptr);
			aplus_string_and_length(handle,iptr);
			fprintf(handle,";%u;3)",
				((iptr->Contents.align & _A_SHADOW) | v | 
				 (iptr->Contents.align & _A_BOLD ? _WINDOW_EXIT_BUTTON : 0 ) | 
				 (iptr->Contents.align & _A_LINE ? _WINDOW_HELP_BUTTON : 0 )));
			linefeed(handle);
			break;

		case	_TAB_FRAME	:
			v = 0;
			if ( iptr->Contents.align & _A_RIGHT )
				v |= 0x0010;
			if ( iptr->Contents.align & _A_LEFT )
				v |= 0x0020;
			v |= (iptr->Contents.align & 0x0F00);
			if ( iptr->Contents.datatype == _WIDGET_OVERLAY ) {
				fprintf(handle,"%s overlay_tabpage %s(originx+%u;originy+%u;%u;%u",
						keyword_public,
						iptr->Contents.name,
						iptr->Contents.x,
						iptr->Contents.y,
						iptr->Contents.w,
						iptr->Contents.h);
				}
			else	{
				fprintf(handle,"%s visual_tabpage %s(originx+%u;originy+%u;%u;%u",
						keyword_public,
						iptr->Contents.name,
						iptr->Contents.x,
						iptr->Contents.y,
						iptr->Contents.w,
						iptr->Contents.h);
				}
			aplus_font_paramter(handle,iptr);
			aplus_string_and_length(handle,iptr);
			if ( iptr->Contents.datatype == _WIDGET_OVERLAY ) {
				aplus_string_parameter(handle,iptr->Contents.name);
				aplus_length_parameter(handle,strlen(iptr->Contents.name));
				}
			fprintf(handle,";%u;%u;%u)", iptr->Contents.adjust,iptr->Contents.xlimit,v);
			linefeed(handle);
			break;

		}

	return;

}

public	void	activate_method( FILE * h,char * mptr, char* nptr, char * eptr, int i )
{
	if (!( eptr ))
		return;
	indent(h,i);
	fprintf(h,"on_%s_%s",mptr,nptr);
	linefeed(h);
	return;
}

public	void	aplus_forms_methods(FILE * h, struct form_control * fptr)
{
	struct	forms_method 	* mptr;
	char			* optr;
	int	l;
	int	status;
	if (!( fptr ))	return;
	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = __abal_overlay_object;
	else	optr = "\0";
	for (	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {
		if (!( mptr->name ))
			continue;
		linefeed(h);

		if ( mptr->type & _METHOD_PUBLIC )
			fprintf(h,"%s ",keyword_public );
		else	fprintf(h,"%s ",keyword_private);

		switch ( (mptr->type & _METHOD_TYPE) ) {
			case	_METHOD_VOID	: break;
			case	_METHOD_BYTE	:
			case	_METHOD_WORD	:
			case	_METHOD_LONG	: fprintf(h,"%s ",keyword_integer); break;
			case	_METHOD_NUMERIC	: fprintf(h,"%s ",keyword_numeric); break;
			case	_METHOD_STRING 	: fprintf(h,"%s ",keyword_string ); break;
			case	_METHOD_CLASS  	: fprintf(h,"%s %s ",keyword_klass,mptr->klass ); break;
			}

		if ( mptr->type & _METHOD_POINTER )
			fprintf(h,"%s ",keyword_pointer);

		if ( mptr->type & _METHOD_VIRTUAL )
			fprintf(h,"%s %s:",keyword_virtual,mptr->name);

		else if ( mptr->type & _METHOD_OVERLOAD )
			fprintf(h,"%s %s:",keyword_virtual,mptr->name);

		if ( mptr->type & _METHOD_FUNCTION)
			fprintf(h,"%s %s:",keyword_function,mptr->name);
		else	fprintf(h,"%s %s:",keyword_inline  ,mptr->name);

		if ( method_is_valid(mptr->signature) )
			fprintf(h,"( %s )",mptr->signature);
		linefeed(h);
		if ((l = method_is_valid( mptr->text )) != 0) {
			abal_pragma_enter(h,"this",mptr->name);
			status = aplus_method_body(h,mptr->text,l,mptr->name);
			abal_pragma_leave(h,"this",mptr->name);
			}
		aplus_end(h);
		linefeed(h);
		}
	return;

}

private	int	aplus_method_body( FILE * h,char * eptr, int l, char * hptr)
{
	int	i;
	int	c;
	char *	lptr;
	int	status=0;
	int	feeder=0;
	while ( *eptr != 0 ) {
		feeder=0;
		/* avoid empty lines */
		if (( *eptr == '\n' ) 
		||  ( *eptr == '\r' )) {
			eptr++;
			continue;
			}
		else	{
			/* scan till end of line or zero */
			/* ----------------------------- */
			for (	i=0,lptr = eptr;
				*eptr != 0;
				eptr++ ) {
				if (( *eptr == '\n' ) 
				||  ( *eptr == '\r' ))
					break;
				else	i++;
				}
			c = *eptr;
			*eptr = 0;
			indent(h,1);
 			status = aplus_method_line(h,lptr,i,hptr,&feeder);
			*eptr = c;
			if ( feeder ) linefeed(h);
			if ( status ) break;
			}
		}
	return(status);
}

public	void	aplus_end( FILE * h )
{
	indent(h,1); 
	fprintf(h,"end");
	linefeed(h);
}

public	int	aplus_object_method( 
	FILE * h,
	char * mptr, 
	char * nptr, 
	char * eptr,
	int    mode )	/* 0 : inline, other : function */
{
	int	l;
	int	n;
	int	i;
	int	status=0;

	if (!( eptr ))
		return(0);


	else if (( l=strlen(eptr)) > 0 ) {

		if ( mode ) {
			fprintf(h,"%s %s %s %s on_%s_%s:",
				keyword_public,keyword_integer,keyword_function,keyword_method,
				mptr,nptr);
			}
		else	{
			fprintf(h,"%s %s %s on_%s_%s:",
				keyword_public,keyword_inline,keyword_method,
				mptr,nptr);
			}
		linefeed(h);
		abal_pragma_enter(h,mptr,nptr);
		status = aplus_method_body(h,eptr,l,mptr);
		abal_pragma_leave(h,mptr,nptr);
		aplus_end(h);
		}		
	return(status);
}

public	int	aplus_object_trigger( 
	FILE * h,
	char * mptr, 
	char * nptr, 
	char * eptr,
	int    mode )	/* 0 : inline, other : function */
{
	int	l;
	int	n;
	int	i;
	int	status=0;

	if (!( eptr ))
		return(0);


	else if (( l=strlen(eptr)) > 0 ) {

		if ( mode ) {
			fprintf(h,"%s %s %s on_%s_%s:",
				keyword_public,keyword_function,keyword_method,
				mptr,nptr);
			}
		else	{
			fprintf(h,"%s %s %s on_%s_%s:",
				keyword_public,keyword_inline,keyword_method,
				mptr,nptr);
			}
		linefeed(h);
		status = aplus_method_body(h,eptr,l,mptr);
		indent(h,1); 
		fprintf(h,"%s.on_exec",mptr);
		linefeed(h);
		aplus_end(h);
		}		
	return(status);
}

public	void	aplus_command_reception( FILE * h, int items, int length )
{
	linefeed(h);
	fprintf(h,"(public visual_argv(%u;%u))",items,length);
	linefeed(h);
	fprintf(h,"%s %s %s command_reception:(ptr aptr$,alen%%)",keyword_public,keyword_constructor,keyword_function);
	linefeed(h);
	indent(h,1);
	fprintf(h,"originx=0 :: originy=0");
	linefeed(h);
	indent(h,1);
	fprintf(h,"Main(aptr;alen)");
	linefeed(h);
	aplus_end(h);
}

public	void	generate_primary_create( FILE * h )
{
	if (!( Abal_Config.generate_overlay )) {
		if (!( Abal_Config.generate_program )) {
			/* class packaging */
			/* --------------- */
			linefeed(h);
			fprintf(h,"%s %s %s origin_create:(px%%,py%%)",keyword_public,keyword_constructor,keyword_function);
			linefeed(h);
			indent(h,1);
			fprintf(h,"originx=px :: originy=py");
			linefeed(h);
			aplus_end(h);
			}
		else	{
			/* program packaging */
			/* ----------------- */

			if ( Context.Form->formflags & _FORM_COMMANDLINE ) {
				aplus_command_reception(h,Context.Form->argvcount,Context.Form->argvlen);
				}
			}
		}
	else if (!( Abal_Config.generate_program )) {
		/* modular packaging */
		/* ----------------- */
		linefeed(h);
		}
	else	{
		/* overlay packaging */
		/* ----------------- */
		aplus_command_reception(h,Context.Form->argvcount,Context.Form->argvlen);
		}

	return;
}

public	struct form_item * generate_on_create( FILE * h, struct form_item * wptr, int focus_items )
{
	struct form_item * 	iptr;
	struct form_item * 	tptr=(struct form_item *)0;
	int			window_number=0;
	int			f;
	struct window_control  Window;

	linefeed(h);
	fprintf(h,"%s %s %s on_create:",keyword_public,keyword_constructor,keyword_function);
	linefeed(h);

	indent(h,1);
	fprintf(h,"focus_item=1");
	linefeed(h);
	indent(h,1);
	fprintf(h,"focus_items=%u",focus_items);
	linefeed(h);

	form_Dimensions( &Window, Context.Form );
	indent(h,1);
	fprintf(h,"on_build(originx;originy;%u;%u;1;16;0)",Window.w,Window.h);
	linefeed(h);

	if ( wptr ) {
		activate_method(h,wptr->Contents.name,"create",wptr->Contents.events->on_create,1);
		window_number = wptr->number;
		indent(h,1);
		fprintf(h,"add_member(%s;%u)",wptr->Contents.name,wptr->Contents.focus);
		linefeed(h);
		wptr=(struct form_item *) 0;
		}
	else	{
		window_number = -1;
		}

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {

		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		if ( iptr->number != window_number )
			activate_method(h,iptr->Contents.name,"create",iptr->Contents.events->on_create,1);

		if (( iptr->Contents.style & _FRAME_TYPE ) == _DATA_FRAME)
			if ((iptr->Contents.align & 7) != _VISUAL_FRAME)
				continue;

		switch (( iptr->Contents.style & _FRAME_TYPE )) {
			case	_WINDOW_FRAME	:
				wptr = iptr;
				continue;
			case	_TAB_FRAME	:
				indent(h,1);
				if (!( wptr ))
					fprintf(h,"add_member(%s;%u)",iptr->Contents.name,iptr->Contents.focus);
				else	fprintf(h,"%s.add_member(%s;%u)",wptr->Contents.name,iptr->Contents.name,iptr->Contents.focus);

				linefeed(h);
				if (!( wptr ))	
					wptr = iptr;
				tptr = iptr;
				continue;
			case	_DATA_FRAME	:
			case	_SELECT_FRAME	:
			case	_EDIT_FRAME	:
			case	_SWITCH_FRAME	:
			case	_SCROLL_FRAME	:
			case	_CHECK_FRAME	:
			case	_RADIO_FRAME	:
			case	_BUTTON_FRAME	:
				break;
			case	_GROOVE_FRAME	:
			case	_RIDGE_FRAME	:
			case	_INSET_FRAME	:
			case	_OUTSET_FRAME	:
				if (( iptr->Contents.align != _A_NONE )
				&&  ( aplus_payload(iptr) != (char *) 0 )) {
					indent(h,1);
					if (!( tptr ))
						fprintf(h,"add_member(l_%s;0)",iptr->Contents.name);
					else	fprintf(h,"%s.add_member(l_%s;0)",tptr->Contents.name,iptr->Contents.name);
					linefeed(h);
					}
			default			:
				iptr->Contents.focus = 0;
			}
		indent(h,1);
		if (!( tptr ))
			fprintf(h,"add_member(%s;%u)",iptr->Contents.name,iptr->Contents.focus);
		else	fprintf(h,"%s.add_member(%s;%u)",tptr->Contents.name,iptr->Contents.name,iptr->Contents.focus);

		linefeed(h);

		}
	return(wptr);
}


public	void	generate_on_remove( FILE * h, struct form_item * wptr )
{
	int	window_number=0;
	struct form_item * iptr;
	int	f;

	linefeed(h);

	fprintf(h,"%s %s %s %s on_remove:",
		keyword_public,keyword_overload,keyword_destructor,keyword_function);

/*
	if ( Context.Form->construction )
		fprintf(h, "( %s )",Context.Form->construction);
 */
	linefeed(h);

	if ( wptr ) {

		window_number = wptr->number;

		for (	iptr=Context.Form->last; 
			iptr != (struct form_item *) 0; 
			iptr = iptr->next ) {
			if ((!( iptr->Contents.w  ))
			||  (!( iptr->Contents.h  )))
				continue;
			else if ( iptr->number != window_number )
				activate_method(h,iptr->Contents.name,"remove",iptr->Contents.events->on_remove,1);
			}

		activate_method(h,wptr->Contents.name,"remove",wptr->Contents.events->on_remove,1);

		}
	return;
}

public	void	aplus_forms_members(FILE * h, struct form_control * fptr)
{
	struct	forms_data_member 	* mptr;
	if (!( fptr ))
		return;
	if (!( fptr->rootmember ))
		return;
	linefeed(h);
	for (	mptr=fptr->rootmember;
		mptr != (struct forms_data_member *) 0;
		mptr = mptr->next ) {
		if ( method_is_valid( mptr->name ) )
			abal_dcl(h,"\0",mptr->name,mptr->type,mptr->size,mptr->first,mptr->second,mptr->comment);
		}
	return;
}

public	void	aplus_check_widget_event( FILE * h, struct form_item * iptr, int margin )
{
	indent(h,margin);
	fprintf(h,"if ((visual_event..parameter(1) and /0%x) <> 0)",(iptr->Contents.events->mimo & _MOUSE_EVENTS));
	linefeed(h);
	return;
}
public	void	generate_on_event( FILE * h, struct form_item * wptr )
{
	int		   first=1;
	struct form_item * iptr;
	char		 * collector=(char *) 0;
	int		   focus_item=0;
	aplus_integer_overload_function(h,"on_event");
	linefeed(h);
	indent(h,1); fprintf(h,"local dcl local_item%");linefeed(h);
	indent(h,1); fprintf(h,"visual_event..refresh");linefeed(h);

/*	if ( wptr ) collector = wptr->Contents.name; else	*/
	collector = "visual_group.";

	indent(h,1); fprintf(h,"if ( visual_object..on_event <> identity) :: exit(-1) :: endif"); 
	linefeed(h);
	indent(h,1); fprintf(h,"local_item = %s.on_event",collector); 
	linefeed(h);
	indent(h,1); fprintf(h,"if ( local_item == -1 )"); 
	linefeed(h);
	indent(h,2); fprintf(h,"exit(-1)");
	linefeed(h);
	indent(h,1); fprintf(h,"endif"); 
	linefeed(h);
	indent(h,1); fprintf(h,"visual_event..cancel"); linefeed(h);
	indent(h,1); fprintf(h,"select local_item");	linefeed(h);

	for (	focus_item=0,iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next,focus_item++ ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		switch (( iptr->Contents.style & _FRAME_TYPE )) {
			case	_DATA_FRAME	:
				if ((iptr->Contents.align & 7) == _VISUAL_FRAME) {
					if (!( first )) first = iptr->Contents.focus;
					indent(h,1); 
					fprintf(h,"case\t%u",iptr->Contents.focus);
					linefeed(h);
					aplus_comment(h,iptr,2);
					indent(h,2); fprintf(h,"focus_item = local_item");	linefeed(h);
					}
				break;

			case	_TAB_FRAME	:	/* TODO */
				if (!( first )) first = iptr->Contents.focus;
				indent(h,1); 
				fprintf(h,"case\t%u",iptr->Contents.focus);
				linefeed(h);
				aplus_comment(h,iptr,2);
				indent(h,2); fprintf(h,"focus_item = local_item");	linefeed(h);
				indent(h,2); fprintf(h,"on_show");			linefeed(h);
				aplus_check_widget_event(h,iptr,2);
				activate_method(h,iptr->Contents.name,"event",iptr->Contents.events->on_event,3);
				abal_endif(h,2);
				break;

			case	_SCROLL_FRAME	:
				if (!( first )) first = iptr->Contents.focus;
				indent(h,1); 
				fprintf(h,"case\t%u",iptr->Contents.focus);
				linefeed(h);
				aplus_comment(h,iptr,2);
				indent(h,2); fprintf(h,"focus_item = local_item");	linefeed(h);
				aplus_check_widget_event(h,iptr,2);
				indent(h,3);
				fprintf(h,"%s.on_action",iptr->Contents.name);
				linefeed(h);
				activate_method(h,iptr->Contents.name,"event",iptr->Contents.events->on_event,3);
				abal_endif(h,2);
				break;

			case	_SELECT_FRAME	:
			case	_EDIT_FRAME	:
			case	_SWITCH_FRAME	:
			case	_CHECK_FRAME	:
			case	_RADIO_FRAME	:
			case	_BUTTON_FRAME	:
				if (!( first )) first = iptr->Contents.focus;
				indent(h,1); 
				fprintf(h,"case\t%u",iptr->Contents.focus);
				linefeed(h);
				aplus_comment(h,iptr,2);
				indent(h,2); fprintf(h,"focus_item = local_item");	linefeed(h);
				aplus_check_widget_event(h,iptr,2);
				activate_method(h,iptr->Contents.name,"event",iptr->Contents.events->on_event,3);
				abal_endif(h,2);
				break;
			default			:
				if (iptr->Contents.events->on_event ) {
					if (!( first )) first = iptr->Contents.focus;
					indent(h,1); 
					fprintf(h,"case\t%u",iptr->Contents.focus);
					linefeed(h);
					aplus_comment(h,iptr,2);
					indent(h,2); fprintf(h,"focus_item = local_item");	linefeed(h);
					activate_method(h,iptr->Contents.name,"event",iptr->Contents.events->on_event,2);
					}
				break;
			}
		}
	if ( first ) {
		indent(h,1);	fprintf(h,"case 0"); 			linefeed(h);
		indent(h,2);	fprintf(h,"focus_item=%u",first);	linefeed(h);
		}

	indent(h,1);
	fprintf(h,"endsel");
	linefeed(h);
	indent(h,1);
	fprintf(h,"exit(focus_item)");
	linefeed(h);
	aplus_end(h);
	return;
}

public	void	generate_aplus_show( FILE * h, struct form_item * iptr )
{
	if (!( method_is_valid( iptr->Contents.events->on_show ) )) {
		if ((iptr->Contents.style & _FRAME_TYPE) == _DATA_FRAME)
			if ((iptr->Contents.align & 0x000F) != _VISUAL_FRAME )
				return;
		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_OUTSET_FRAME 	:
			case	_INSET_FRAME 	:
			case	_RIDGE_FRAME 	:
			case	_GROOVE_FRAME 	:
				if (( iptr->Contents.align != _A_NONE     ) 
				&&  ( aplus_payload(iptr) != (char *) 0)) {
					indent(h,1);
					fprintf(h,"l_%s.on_show",iptr->Contents.name);
					linefeed(h);
					}
			default		:
				indent(h,1);
				fprintf(h,"%s.on_show",iptr->Contents.name);
				linefeed(h);
			}
		}
	else	{
		activate_method(h,iptr->Contents.name,"show",iptr->Contents.events->on_show,1);
		}
	return;
}

public	void	generate_aplus_showpage( FILE * h, struct form_control * fptr, int pagenumber )
{
	struct	form_item * iptr;
	int	foundit=0;
	for ( 	foundit=0,
		iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if ( iptr->Contents.page != pagenumber )
			continue;
		else if (iptr->Contents.events->xo_show & _EVENT_IS_COND )
			continue;
		else if (( iptr->Contents.style & _FRAME_TYPE) > _DATA_FRAME )
			continue;
		else	{
			generate_aplus_show(h,iptr);
			if ((iptr->Contents.style & _FRAME_TYPE) == _TAB_FRAME) {
				foundit=1;
				indent(h,1);
				fprintf(h,"if ( %s.is_active <> 0 )",iptr->Contents.name);
				linefeed(h);
				}
			}

		}
	if ( foundit ) {
		indent(h,1);
		fprintf(h,"Endif");
		linefeed(h);
		}
	return;
}

public	void	generate_on_show( FILE * h, struct form_item * wptr )
{
	int	p=0;
	struct form_item * iptr;
	aplus_overload_function(h,"on_show");
	linefeed(h);

	indent(h,1);
	fprintf(h,"visual_library_interface..VisualFreeze");
	linefeed(h);

	if ( Context.Form->ispopup ) {
		indent(h,1);
		fprintf(h,"__FormPush.on_show");
		linefeed(h);
		}
	if ( Context.Form->pages != 0 ) {

		for (p=0; p <= Context.Form->pages; p++ )
			generate_aplus_showpage( h, Context.Form, p );

		}
	else	{
		for (	iptr=Context.Form->first; 
			iptr != (struct form_item *) 0; 
			iptr = iptr->next ) {
			if ((!( iptr->Contents.w  ))
			||  (!( iptr->Contents.h  )))
				continue;

			else if (iptr->Contents.events->xo_show & _EVENT_IS_COND )
				continue;

			else if (( iptr->Contents.style & _FRAME_TYPE) > _DATA_FRAME )
				continue;

			else	generate_aplus_show(h,iptr);

			}
		}

	indent(h,1);
	fprintf(h,"visual_library_interface..VisualThaw");
	if ( wptr )
		fprintf(h,"(%u;%u;%u;%u)",wptr->Contents.x,wptr->Contents.y,wptr->Contents.w,wptr->Contents.h);
	else	fprintf(h,"(0;0;0;0)");
	linefeed(h);
	aplus_end(h);
	return;
}

public	void	generate_on_hide( FILE * h )
{
	struct form_item * iptr;
	aplus_overload_function(h,"on_hide");
	linefeed(h);
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else	activate_method(h,iptr->Contents.name,"hide",iptr->Contents.events->on_hide,1);
		}
	if ( Context.Form->ispopup ) {
		indent(h,1);
		fprintf(h,"__FormPush.on_hide");
		linefeed(h);
		}
	aplus_end(h);
	return;
}

private	void	aplus_comment(FILE * h, struct form_item * iptr, int i)
{
	char * sptr;
	if (( sptr = get_widget_class( iptr->Contents.style )) != (char *) 0)
		strcpy(namebuffer,sptr);
	else	strcpy(namebuffer,"what");
	strcat( namebuffer," ");
	if (( sptr = iptr->Contents.name ) != (char *) 0)
		strcat( namebuffer,sptr );
	else	strcpy(namebuffer,"who");
	abal_comment(h,	namebuffer, i );
}

public	void	visual_object_event_retry( FILE * h,char * prefix, int margin )
{
	indent(h,margin);
	if (!( prefix )) {
		/* no object prefix provided : called from inside a visual class */
		/* ------------------------------------------------------------- */
		fprintf(h,"if ( visual_event..keycode <> -1 ) :: goto &retry :: endif");
		}
	else	{
		/* object prefix provided : called from outside of a visual class */
		/* -------------------------------------------------------------- */
		fprintf(h,"KeyCode = %s.keycode",prefix);
		linefeed(h);
		indent(h,margin);
		fprintf(h,"goto &Retry");
		}
	linefeed(h);
	return;
}

public	void	generate_on_get_focus( FILE * h, struct form_item * wptr )
{
	struct form_item * iptr;
	int	focus_item;
	aplus_overload_function(h,"on_get_focus");
	linefeed(h);
	indent(h,1); fprintf(h,"visual_event..purge");  linefeed(h);
	indent(h,2); fprintf(h,"do"); 			linefeed(h);
	fprintf(h,"&continue");				linefeed(h);
	indent(h,2); fprintf(h,"select focus_item");	linefeed(h);
	for (	focus_item=0,iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next,focus_item++) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS ))
			continue;
		switch (( iptr->Contents.style & _FRAME_TYPE )) {
			case	_DATA_FRAME	:
				if ((iptr->Contents.align & 7) == _VISUAL_FRAME) {
					indent(h,2); fprintf(h,"case\t%u",iptr->Contents.focus);
					linefeed(h);
					aplus_comment(h,iptr,3);
					if (iptr->Contents.events->on_get_focus ) {
						activate_method(h,iptr->Contents.name,"getfocus",iptr->Contents.events->on_get_focus,3);
						}
					else	{
						indent(h,3); fprintf(h,"%s.on_get_focus",iptr->Contents.name); linefeed(h);
						}
					}
				break;

			case	_SELECT_FRAME	:
			case	_EDIT_FRAME	:
			case	_SWITCH_FRAME	:
			case	_SCROLL_FRAME	:
			case	_CHECK_FRAME	:
			case	_RADIO_FRAME	:
			case	_BUTTON_FRAME	:
			case	_TAB_FRAME	:
				indent(h,2); fprintf(h,"case\t%u",iptr->Contents.focus);
				linefeed(h);
				aplus_comment(h,iptr,3);
				activate_method(h,iptr->Contents.name,"getfocus",iptr->Contents.events->on_get_focus,3);
				indent(h,3); fprintf(h,"%s.on_get_focus",iptr->Contents.name); linefeed(h);
				activate_method(h,iptr->Contents.name,"losefocus",iptr->Contents.events->on_lose_focus,3);
				break;
			default			:
				if (iptr->Contents.events->on_get_focus ) {
					indent(h,2); 
					fprintf(h,"case\t%u",iptr->Contents.focus);
					linefeed(h);
					aplus_comment(h,iptr,3);
					activate_method(h,iptr->Contents.name,"getfocus",iptr->Contents.events->on_get_focus,3);
					activate_method(h,iptr->Contents.name,"losefocus",iptr->Contents.events->on_lose_focus,3);
					}
				break;
			}
		}
	if ( focus_item > 0 ) {
		indent(h,2);
		fprintf(h,"default\t :: visual_event..keycode=5");
		linefeed(h);
		}
	indent(h,2); fprintf(h,"endsel"); linefeed(h);

	fprintf(h,"&retry");	linefeed(h);
	indent(h,2); fprintf(h,"select visual_event..keycode"); linefeed(h);

	indent(h,2); fprintf(h,"case\t256"); linefeed(h);

	if (!( Abal_Config.generate_program )) {
		indent(h,3);
		fprintf(h,"if ( on_event <= 0 ) :: exit :: endif");
		linefeed(h);
		}
	else	{
		indent(h,3);
		fprintf(h,"if ( on_event <= 0 ) :: goto &continue :: endif");
		linefeed(h);
		}


	visual_object_event_retry(h,(char *) 0,3);
	indent(h,2);
	fprintf(h,"case\t27,13 :: exit");
	linefeed(h);
	indent(h,2);
	fprintf(h,"case\t9,5");
	linefeed(h);
	indent(h,3);
	fprintf(h,"if ( focus_item < focus_items ) :: focus_item += 1 :: else :: ");
	if ( Context.Form->formflags & _FORM_DEFAULT  )
		fprintf(h,"exit :: endif");
	else 	fprintf(h,"focus_item = 1 :: endif");
	linefeed(h);
	indent(h,2);
	fprintf(h,"case\t11");
	linefeed(h);
	indent(h,3);
	fprintf(h,"if ( focus_item > 1 ) :: focus_item -= 1 :: else :: ");
	if ( Context.Form->formflags & _FORM_DEFAULT  )
		fprintf(h,"exit :: endif");
	else	fprintf(h,"focus_item = focus_items :: endif");
	linefeed(h);
	indent(h,2);
	fprintf(h,"case -1 ");
	linefeed(h);
	if ( Context.Form->formflags & _FORM_DEFAULT  ) {
		indent(h,2);
		fprintf(h,"default ");
		linefeed(h);
		indent(h,3);
		fprintf(h,"exit");
		linefeed(h);
		}
	indent(h,2);
	fprintf(h,"endsel");
	linefeed(h);
	indent(h,1);
	fprintf(h,"loop");
	linefeed(h);
	aplus_end(h);
	return;
}

public	void	generate_on_lose_focus( FILE * h, struct form_item * wptr )
{
	struct form_item * iptr;
	aplus_overload_function(h,"on_lose_focus");
	linefeed(h);
	aplus_end(h);
	return;
}

public	void	aplus_dependance( FILE * h, char * sptr )
{
	standard_dependance( h, sptr, keyword_include );
}

public	void	aplus_apl( FILE * h, char * nptr )
{
	fprintf(h,"%s %s",keyword_use,nptr);	  linefeed(h);
}


public	void	aplus_visual_apl( FILE * h )
{
	fprintf(h,"%s pragmas.as",keyword_include); linefeed(h);
	aplus_apl( h, "visual" );
}

private	void	aplus_inclusion( FILE * h )
{
	if ( Abal_Config.generate_program ) {
		aplus_visual_apl(h);
		fprintf(h,"%s files",keyword_use);	linefeed(h);
		}

	else if ( Abal_Config.generate_overlay ) {
		aplus_visual_apl(h);
		fprintf(h,"%s files",keyword_use);	linefeed(h);
		}

	if ( Context.Form->dependance)
		aplus_dependance(h,Context.Form->dependance);
	return;
}

private	void	redirected_method(FILE * h,char * mptr)
{
	linefeed(h);
	fprintf(h,"public indirect integer function %s:",mptr);
	linefeed(h);
	indent(h,1);
	fprintf(h,"payload.%s",mptr);
	linefeed(h);
	aplus_end(h);
	return;
}

private	void	aplus_overlay_loader(FILE * h)
{
	linefeed(h);
	fprintf(h,"#pragma enhanced indirect off");
	linefeed(h);
	fprintf(h,"%s %s_loader",keyword_class,Abal_Config.cname);
	linefeed(h);
	linefeed(h);
	fprintf(h,"inherit visual_overlay");
	linefeed(h);
	linefeed(h);
	fprintf(h,"private %s pointer payload",Abal_Config.cname);
	linefeed(h);
	linefeed(h);

	fprintf(h,"public indirect integer function on_create:(ptr argp$,argl%%)");
	linefeed(h);
	indent(h,1);	fprintf(h,"check_visual_event");linefeed(h);
	indent(h,1);	fprintf(h,"create payload(argp;argl)");	linefeed(h);
	aplus_end(h);

	fprintf(h,"public indirect integer function on_remove:");
	linefeed(h);
	indent(h,1);	fprintf(h,"remove payload");	linefeed(h);
	indent(h,1);	fprintf(h,"drop_visual_event"); linefeed(h);
	aplus_end(h);

	redirected_method( h,__aplus_method_hide);
	redirected_method( h,__aplus_method_show);
	redirected_method( h,__aplus_method_event);
	redirected_method( h,__aplus_method_get_focus);
	redirected_method( h,__aplus_method_exec);
	redirected_method( h,__aplus_method_attach);
	redirected_method( h,__aplus_method_detach);

	fprintf(h,"%s %s_loader",keyword_endclass,Abal_Config.cname);
	linefeed(h);
	fprintf(h,"#pragma enhanced indirect on");
	linefeed(h);
	linefeed(h);
	return;
}

#include "abalterm.h"
#include "abalkeys.c"
#include "pluspage.c"
#include "plusform.c"
#include "abaledit.c"

#endif 	/* _singplus_c */
	/* ----------- */



