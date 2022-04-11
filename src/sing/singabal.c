#ifndef	_SINGABAL_C
#define	_SINGABAL_C

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
#include "singpars.h"
#include "singexpo.h"

#include "singpal.h"
#include "singbar.h"
#include "singmenu.h"
#include "singtool.h"
#include "singtext.h"
#include "singimg.h"
#include "singdesk.h"
#include "vconf.h"
#include "vcommand.h"
#include "visual.h"
#include "singconf.h"
#include "singabal.h"
#include "singtool.h"
#include "singmeth.h"
#include "singmemb.h"
#include "abalterm.h"
#include "abalkeys.c"
#include "singplus.h"

#define	SING_FONT_MAX 16
#define	__stdinput	"StdInput"
#define	__QUOTE	0x0022

#include "singnatl.h"

extern	int	FixedWindows;

struct	standard_zone	{
	int	x;
	int	y;
	int	w;
	int	h;
	};


#define	__abal_method_get	"OnGet"
#define	__abal_method_set	"OnSet"

public	char *	component_object_prefix( char * component );

public	char *	language_prefix(int nl)
{
	if (( nl >= 0 ) && ( nl < 8 ))
		return( LanguagePrefix[nl] );
	else	return( "kk" );
}

public	int	use_visual_interface( struct form_control * fptr, int isvisual )
{
	if ( fptr->language != _GENERATE_PHP )
		return(1);
	else if (!( fptr->weboptions & _WEB_OPTION_AGENT ))
		return(0);
	else if (!( isvisual )) // is a visual function
		return(1);	// so inhibit it
	else	return(0);	// otherwise a member function
}

/*	Function Prototypes	*/
/*	-------------------	*/
public	void	abal_widget_getset_parameters(  FILE * h, struct form_item * iptr );
public	int	abal_datatype_parameter( FILE * h,struct form_item * iptr, int mode );
public	struct form_control * resolve_form_control( char * sptr );
public	struct	form_item * locate_widget( char * nptr,struct form_control * fptr );
public	void	generate_abal_show(FILE * handle, struct form_item * iptr, int paging  );
public	void	declare_abal_fonts(FILE * h);
public	void	abal_error_trap( FILE * h, int i, int level );
public	void	abal_error_abort( FILE * h, int i, int level );
public	void	abal_error_return( FILE * h, char * vptr, int level );
public	int	inline_abal_method( FILE * h,struct form_item * iptr,char * mptr, char* nptr, char * eptr, int type,int margin );
public	int	activate_abal_method( FILE * h,struct form_item * iptr,char * mptr, char* nptr, char * eptr, int type, int margin );
public	void	construction_parameters(FILE * h,struct form_control * fptr,int mode);
public	void	abal_scrollbar_widget(FILE * handle, struct form_item * iptr, int margin, int focus );
public	void	abal_data_expression( FILE* h, struct form_item * iptr , int keycode, int margin, char * tptr );
public	void	abal_file_member_name(FILE * h,struct form_item * iptr,	int f );
public	void	abal_button_widget( FILE * h, struct form_item * iptr, int margin, int etat );
public	int	is_named_edit( struct form_item * iptr );
public	char *	project_configuration();
public	void	abal_widget_focus(FILE * handle, struct form_item * iptr, char * mptr, int mode );
public	void	abal_onfocus_default(FILE * handle, struct form_item * iptr, int margin );
private	void	abal_onfocus_select(FILE * h, struct form_item * iptr, int margin );
private	void	abal_onfocus_edit(FILE * h, struct form_item * iptr, int margin );
private	void	abal_forward_signature(FILE * h, struct form_item * iptr, char * methodname );
private	void	abal_forward_signatures(FILE * h, struct form_control * fptr, char * methodname );
public	struct form_control * locate_form_control( char * sptr );

#include "abalsynt.c"
#include "aballine.c"

public	void	abal_hex_parameter(FILE * h, int v )
{
	fprintf(h,",/%04.4X",v);
	return;
}

public 	void	set_abal_form_input( struct form_control * fptr )
{
	struct forms_method * mptr=(struct forms_method*)0;
	Abal_Config.newstdin=0;
	if (!( fptr )) {
		Abal_Config.input_method = (char *) 0;
		}
	else if (!( fptr->StandardInput )) {
		if (!( fptr->mimoflags & _MIMO_MOVE ))
			Abal_Config.input_method = (char *) 0;
		else	{
			Abal_Config.newstdin=2;
			Abal_Config.input_method = __stdinput;
			}
		}
	else if (!( fptr->StandardInput->name )) {
		Abal_Config.input_method = (char *) 0;
		}
	else	{
		Abal_Config.newstdin=1;
		Abal_Config.input_method = fptr->StandardInput->name;
		}
	return;
}

public 	void	set_abal_form_error( struct form_control * fptr )
{
	struct forms_method * mptr=(struct forms_method*)0;
	Abal_Config.newstderr=0;
	if (!( fptr ))
		Abal_Config.error_method = (char *) 0;
	else if (!( fptr->StandardError ))
		Abal_Config.error_method = (char *) 0;
	else if (!( fptr->StandardError->name ))
		Abal_Config.error_method = (char *) 0;
	else	{
		Abal_Config.newstderr=1;
		Abal_Config.error_method = fptr->StandardError->name;
		}
	return;
}

private	char *	resolve_method_name( char * mptr )
{
	switch ( detect_forms_special_method( mptr ) ) {
		case	_FORMS_STDINPUT		:	return( _METHOD_STDINPUT  );
		case	_FORMS_STDERROR		:	return( _METHOD_STDERROR  );
		case	_FORMS_ONHINT		:	return( _METHOD_ONHINT	  );
		case	_FORMS_ONPAGE		:	return( _METHOD_ONPAGE	  );
		case	_FORMS_ONESCAPE		:	return( _METHOD_ONESCAPE  );
		case	_FORMS_ONENTER		:	return( _METHOD_ONENTER   );
		case	_FORMS_ONDEFAULT	:	return( _METHOD_ONDEFAULT );
		case	_FORMS_ONPREVIEW	:	return( _METHOD_ONPREVIEW );
		case	_FORMS_ONPRECONSTR	:	return( _METHOD_ONPRECONSTR );
		case	_FORMS_ONPOSTDESTR	:	return( _METHOD_ONPOSTDESTR );
		case	_FORMS_POSITIONAT	:	return( _METHOD_POSITIONAT);
		default				:	return( mptr );
		}
}

public	void	AbalFormsMethodSignature(FILE * h, struct forms_method * mptr, char * scope, char * optr )
{
	char *	qname;

	qname = resolve_method_name( mptr->name );

	if (!( method_is_valid(mptr->signature) )) {
		fprintf(h,"%s %s %s(%s)",
			scope,
			__abal_keyword_proc,
			qname,optr);
		}
	else if (!(*optr )) {
		fprintf(h,"%s %s %s(%s)",
			scope,
			__abal_keyword_proc,
			qname,
			mptr->signature);
		}
	else	{
		fprintf(h,"%s %s %s(%s,%s)",
			scope,
			__abal_keyword_proc,
			qname,
			optr,
			mptr->signature);
		}
	switch ( (mptr->type & _METHOD_TYPE) ) {
		case	_METHOD_VOID	: break;
		case	_METHOD_BYTE	: fprintf(h," : # " ); break;
		case	_METHOD_LONG : fprintf(h," : :  "); break;
		case	_METHOD_WORD	: fprintf(h," : %% "); break;
		case	_METHOD_NUMERIC	: fprintf(h," : =8 "); break; 
		case	_METHOD_CLASS	:
		case	_METHOD_STRING	: fprintf(h," : $ " ); break;
		}
	linefeed(h);
	return;
}

public	void	abal_forms_method_signature(FILE * h, struct form_control * fptr, char * scope, int v)
{
	struct	forms_method 	* mptr;
	char			* optr;
	char 			* qname;
	if (!( fptr ))	return;

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = __abal_overlay_object;
	else	optr = "\0";

	for (	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {

		if (!( v & 16 )) {
			if ( mptr->type & _METHOD_EXTERN )
				continue;
			}
		else if (!( mptr->type & _METHOD_EXTERN ))
			continue;

		if ( v ) {
			if ( v & 1 ) {
				if (!( mptr->type & _METHOD_PUBLIC ))
					continue;
				else if (!( mptr->type & _METHOD_FUNCTION ))
					continue;
				}
			else if ( v & 2 ) {
				if ( mptr->type & _METHOD_PUBLIC )
					continue;
				else if (!( mptr->type & _METHOD_FUNCTION ))
					continue;
				}
			}
		else if (!( mptr->type & _METHOD_FUNCTION ))
			continue;
 
		if (!( mptr->name ))
			continue;

		AbalFormsMethodSignature(h,mptr,scope,optr);

		}
	return;

}

private	void	AbalClassWidgetInterface( FILE * h, struct form_item * iptr, char * mptr, int mode )
{
	fprintf(h,"public integer indirect function %s_%s:",iptr->Contents.name,mptr);
	if ( mode ) {
		fprintf(h,"( ");
		abal_widget_getset_parameters(h,iptr);
		fprintf(h," )");
		}
	linefeed(h);
	abal_end_method(h);
}

private	void	AbalClassFormInterface( FILE * h, struct form_control * fptr, char * mptr )
{
	int		    members=0;
	struct	form_item * iptr;

	fprintf(h,"public integer indirect function %s:",mptr);
	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (!( iptr->Contents.access & _WIDGET_PUBLIC ))
			continue;
		if ( members++ )
			fprintf(h,",");
		else	fprintf(h,"(");
		abal_widget_getset_parameters(h,iptr);
		}		
	if ( members ) {
		fprintf(h,")");
		}
	linefeed(h);
	abal_end_method(h);
}
	
private	void	AbalClassMethodInterface( FILE * h, struct forms_method * mptr )
{
	fprintf(h,"public integer indirect function %s:",mptr->name);
	if ( method_is_valid( mptr->signature ) ) {
		fprintf(h,"(%s)",mptr->signature);
		}
	linefeed(h);
	abal_end_method(h);
}

public	int	public_widgets_method_count( struct form_control * fptr )
{
	int	public_widgets=0;
	struct	form_item * iptr;

	if (!( fptr ))	return;

	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (!( iptr->Contents.access & _WIDGET_PUBLIC ))
			continue;

		public_widgets += public_widget_method_count( iptr );

		}
	if ( public_widgets ) 
		public_widgets += 2;

	return( public_widgets );
}

public	void	abal_class_widgets_interface(FILE * h, struct form_control * fptr )
{
	int	public_widgets=0;
	struct	form_item * iptr;

	if (!( fptr ))	return;

	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (!( iptr->Contents.access & _WIDGET_PUBLIC ))
			continue;
		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_EDIT_FRAME	:
			case	_BUTTON_FRAME	:
			case	_RADIO_FRAME	:
			case	_CHECK_FRAME	:
			case	_SWITCH_FRAME	:
			case	_SCROLL_FRAME	:
			case	_PROGRESS_FRAME	:
			case	_SELECT_FRAME	:
				AbalClassWidgetInterface( h, iptr, __class_widget_set,1 );
				AbalClassWidgetInterface( h, iptr, __class_widget_get,1 );
				public_widgets++;
			}
		if (( is_named_edit  ( iptr ) )
		||  ( is_named_select( iptr ) ))
			AbalClassWidgetInterface(h,iptr,__class_widget_onshow,0);
		if (( iptr->Contents.events->xo_create & _EVENT_IS_FUNCTION )
		&&  ( method_is_valid(iptr->Contents.events->on_create)))
			AbalClassWidgetInterface(h,iptr,__class_widget_create,0);
		if (( iptr->Contents.events->xo_remove & _EVENT_IS_FUNCTION )
		&&  ( method_is_valid(iptr->Contents.events->on_remove)))
			AbalClassWidgetInterface(h,iptr,__class_widget_remove,0);
		if (( iptr->Contents.events->xo_show & _EVENT_IS_FUNCTION )
		&&  ( method_is_valid(iptr->Contents.events->on_show)))
			AbalClassWidgetInterface(h,iptr,__class_widget_show,0);
		if (( iptr->Contents.events->xo_hide & _EVENT_IS_FUNCTION )
		&&  ( method_is_valid(iptr->Contents.events->on_hide)))
			AbalClassWidgetInterface(h,iptr,__class_widget_hide,0);
		if (( iptr->Contents.events->xo_get_focus & _EVENT_IS_FUNCTION )
		&&  ( method_is_valid(iptr->Contents.events->on_get_focus)))
			AbalClassWidgetInterface(h,iptr,__class_widget_get_focus,0);
		if (( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION )
		&&  ( method_is_valid(iptr->Contents.events->on_lose_focus)))
			AbalClassWidgetInterface(h,iptr,__class_widget_lose_focus,0);
		if (( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION )
		&&  ( method_is_valid(iptr->Contents.events->on_event)))
			AbalClassWidgetInterface(h,iptr,__class_widget_event,0);
		}
	if ( public_widgets ) {
		/* combined of global Set Get methods */
		AbalClassFormInterface(h,fptr,__class_widget_set);
		AbalClassFormInterface(h,fptr,__class_widget_get);
		}
	linefeed(h);
	return;
}

public	void	abal_class_methods_interface(FILE * h, struct form_control * fptr )
{
	struct	forms_method 	* mptr;

	if (!( fptr ))	return;

	for (	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {

		if (!( mptr->type & _METHOD_FUNCTION ))
			continue;
		else if (!( mptr->type & _METHOD_PUBLIC ))
			continue;
		else if (!( mptr->name ))
			continue;

		AbalClassMethodInterface(h,mptr);

		}
	return;

}

public	void	abal_resize_method_forward( FILE * h,struct form_control *fptr,char * prefix,int overlay)
{
	switch ( fptr->formflags & _FORM_TYPE_FLAGS ) {
		case	_FORM_TYPE_DIALOG	:
		case	_FORM_TYPE_EVENT 	:
			break;
		default				:
			return;
		}
	if (!( fptr->resizeauto )) return;

	if (overlay)
		fprintf(h,"%s %s %s%s(%s,wref%c,href%c)",__abal_keyword_forward,__abal_keyword_proc,prefix,__abal_method_Resize,__abal_overlay_object,0x0025,0x0025);
	else	fprintf(h,"%s %s %s%s(wref%c,href%c)",__abal_keyword_forward,__abal_keyword_proc,prefix,__abal_method_Resize,0x0025,0x0025);
	linefeed(h);

}

public	void	abal_resize_method( FILE * h,struct form_control *fptr,char * prefix,int overlay)
{
	struct form_item * iptr;
	
	switch ( fptr->formflags & _FORM_TYPE_FLAGS ) {
		case	_FORM_TYPE_DIALOG	:
		case	_FORM_TYPE_EVENT 	:
			break;
		default				:
			return;
		}
	if (!( fptr->resizeauto )) return;

	if ( Abal_Config.generate_program ) {
		if ( Abal_Config.generate_overlay )
			fprintf(h,"%s On%s(%s,wref%c,href%c)",__abal_keyword_proc,__abal_method_Resize,__abal_overlay_object,0x0025,0x0025);
		else	fprintf(h,"%s On%s(wref%c,href%c)",__abal_keyword_proc,__abal_method_Resize,0x0025,0x0025);
		}
	else if ( Abal_Config.generate_overlay ) {
		fprintf(h,"%s %s%s(wref%c,href%c)",__abal_keyword_proc,Abal_Config.cname,__abal_method_Resize,0x0025,0x0025);
		}
	else return;

	linefeed(h);

	for (	iptr=fptr->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		switch ( (iptr->Contents.style & _FRAME_TYPE ) ) {
			case	_WINDOW_FRAME	:
				generate_abal_popdown(h,iptr,1);
				break;
			}
		}
		
	indent(h,1);
	fprintf(h,"_wref = wref");
	linefeed(h);
	indent(h,1);
	fprintf(h,"_href = href");
	linefeed(h);

	if ( Abal_Config.page_control ) {
		indent(h,1);
		fprintf(h,"FirstPage = PageNumber");
		linefeed(h);
		indent(h,1);
		fprintf(h,"PageNumber = 0		; Pour réafficher la fenetre");
		linefeed(h);
		};

	/* recalculer toutes les tailles de widgets */
	/* ---------------------------------------- */
	for (	iptr=fptr->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if (is_xy_modif(iptr)) {
			/* GWB, pas de recalcul position de la fenetre */
			if (( iptr->Contents.style & _FRAME_TYPE ) == _WINDOW_FRAME ) {
				indent(h,1);
				if (is_w_modif(iptr))
					fprintf(h,"w_%s=(%u*_wref)/%d",iptr->Contents.name,iptr->Contents.w,w_base_resize(iptr));
				else	fprintf(h,"w_%s=%u",iptr->Contents.name,iptr->Contents.w);
				linefeed(h);
				indent(h,1);
				if (is_h_modif(iptr))
					fprintf(h,"h_%s=(%u*_href)/%d",iptr->Contents.name,iptr->Contents.h,h_base_resize(iptr));
				else	fprintf(h,"h_%s=%u",iptr->Contents.name,iptr->Contents.h);
				linefeed(h);
				}
			else	generate_position_control( h,iptr );

			/* Specialised Construction */
			/* ------------------------ */
			switch ( (iptr->Contents.style & _FRAME_TYPE ) ) {
				case	_DATA_FRAME	:
					if (( iptr->Contents.align & 0x000F ) == _VISUAL_FRAME)
						abal_invoke_position_at( h, iptr );
					break;

				case	_TAB_FRAME 	:
					if (is_w_modif(iptr)) {
						fprintf(h,"v_%s = (%u*_wref)/%d ",iptr->Contents.name,iptr->Contents.adjust,w_base_resize(iptr));
						linefeed(h);
						indent(h,1);
						}
					break;

				case	_FORM_FRAME	:
					if (is_w_modif(iptr)) {
						fprintf(h,"nc_%s = (w_%s-4)/%u",
							iptr->Contents.name,iptr->Contents.name,Context.FontTable[iptr->Contents.font].width);
						linefeed(h);
						}

					/* recalculate table column widths */
					/* ------------------------------- */
					initialise_table_columnwidths(h , iptr );
					break;
				}
			}
		}
	indent(h,1);
	if ( Abal_Config.generate_program ) {
		if ( Abal_Config.generate_overlay )
			fprintf(h,"%s=On%s(o)",__abal_keyword_status,__abal_method_show);
		else 	fprintf(h,"%s=On%s()",__abal_keyword_status,__abal_method_show);
		}
	else  	{
		abal_call(h,Abal_Config.cname,__abal_method_show, 0,1 , fptr );
		}

	linefeed(h);
	fprintf(h,"endproc");
	linefeed(h);	
	linefeed(h);
}

public	void	abal_sort_method_forward( FILE * h,struct form_control *fptr )
{
	struct form_item * iptr;
	switch ( fptr->formflags & _FORM_TYPE_FLAGS ) {
		case	_FORM_TYPE_DIALOG	:
		case	_FORM_TYPE_EVENT 	:
			break;
		default				:
			return;
		}
	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if ((iptr->Contents.style & _FRAME_TYPE) == _FORM_FRAME)
			{
			fprintf(h,"%s %s als_%s(nelts%%):%%\t\t; allocate intermediate sort tables",__abal_keyword_forward,__abal_keyword_proc,iptr->Contents.name);
			linefeed(h);
			fprintf(h,"%s %s sort_%s(nelts%%)\t\t; sort the intermediate table into ts_%s",__abal_keyword_forward,__abal_keyword_proc,iptr->Contents.name,iptr->Contents.name);
			linefeed(h);
			fprintf(h,"%s %s cmp_%s(a%%,b%%):#\t\t; comparer les elements a et b de ls_%s",__abal_keyword_forward,__abal_keyword_proc,iptr->Contents.name,iptr->Contents.name);
			linefeed(h);
			fprintf(h,"%s %s lts_%s(elt%%):%%\t\t; lire le numero d'un element trie",__abal_keyword_forward,__abal_keyword_proc,iptr->Contents.name);
			linefeed(h);
			};
		}

	return;
}


public	void	abal_sort_methods( FILE * h ,struct form_control *fptr)
{
	struct form_item * iptr;
	char *tptr;
	char *rptr;
	char mon_code[256];
	char comment[256];
	int linelength, nblines,i,fields,posit;
	int	fieldwidth[_MAX_FORM_FIELDS];

	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if ((iptr->Contents.style & _FRAME_TYPE) == _FORM_FRAME)
			{
			fprintf(h,"* ------------------------------------- *");
			linefeed(h);
			fprintf(h,"* allocate intermediate sort tables     *");
			linefeed(h);
			fprintf(h,"* ------------------------------------- *");
			linefeed(h);
			fprintf(h,"%s als_%s(nelts%%):%%",__abal_keyword_proc,iptr->Contents.name);
			linefeed(h);
			fprintf(h,"dcl er%%,i%%");
			linefeed(h);

			abal_error_trap(h,1,1);

			fprintf(h,"if (ns_%s<nelts)",iptr->Contents.name);
			linefeed(h);
			indent(h,1);
			fprintf(h,"remove ts_%s",iptr->Contents.name);
			linefeed(h);
			indent(h,1);
			fprintf(h,"create ts_%s(nelts)",iptr->Contents.name);
			linefeed(h);
			indent(h,1);
			fprintf(h,"if (er<>0) : Exit(er)");
			linefeed(h);				
			indent(h,1);
			fprintf(h,"for i=1 to nelts",iptr->Contents.name);
			linefeed(h);
			indent(h,2);
			fprintf(h,"ts_%s(i)=ns_%s ; initialise unsorted table",iptr->Contents.name,iptr->Contents.name);
			linefeed(h);
			indent(h,1);
			fprintf(h,"next i",iptr->Contents.name);
			linefeed(h);
			fprintf(h,"ns_%s = nelts",iptr->Contents.name);
			linefeed(h);
			fprintf(h,"endif");
			linefeed(h); linefeed(h);

			fprintf(h,"create is_%s(nelts)",iptr->Contents.name);
			linefeed(h);

			calculate_edit_size( &iptr->Contents );
			calculate_form_lines( iptr, &linelength, &nblines );
			fprintf(h,"create ls_%s(%u,nelts)",iptr->Contents.name,linelength);
			linefeed(h);
			linefeed(h);

			fprintf(h,"for i=1 to nelts");
			linefeed(h);
			indent(h,1);
			fprintf(h,"ls_%s(i)=\" \"",iptr->Contents.name);
			linefeed(h);
			fprintf(h,"next i");
			linefeed(h);
			fprintf(h,"Exit(validptr(ls_%s))",iptr->Contents.name);
			linefeed(h);

			abal_error_abort(h,1,1);
			abal_error_return(h,__abal_keyword_status,1);

			fprintf(h,"endproc");
			linefeed(h);	linefeed(h);


			/* fonction de tri */
			sprintf(comment,"sort the intermediate table into ts_%s",iptr->Contents.name);
			memset(mon_code,'-',strlen(comment));
			mon_code[strlen(comment)]=0;
			fprintf(h,";* %s *",mon_code);
			linefeed(h);
			fprintf(h,";* %s *",comment);
			linefeed(h);
			fprintf(h,";* %s *",mon_code);
			linefeed(h);		

			fprintf(h,"%s sort_%s(nelts%%)",__abal_keyword_proc,iptr->Contents.name);
			linefeed(h);
			fprintf(h,"dcl i%%,j%%,k%%");
			linefeed(h);
			fprintf(h,"endloc");
			linefeed(h);	linefeed(h);

			abal_error_trap(h,1,1);

			fprintf(h,"for i=1 to nelts");
			linefeed(h);
			indent(h,1);
			fprintf(h,"is_%s(i)=0	; Reset Sort Flags",iptr->Contents.name);
			linefeed(h);
			fprintf(h,"next i");
			linefeed(h);		linefeed(h);

			fprintf(h,"for i=1 to nelts");
			linefeed(h);

			indent(h,1);
			fprintf(h,"k=1");
			linefeed(h);
			indent(h,1);
			fprintf(h,"while ((k<nelts) AND (is_%s(k)<>0))",iptr->Contents.name);
			linefeed(h);
			indent(h,2);
			fprintf(h,"k=k+1");
			linefeed(h);
			indent(h,1);
			fprintf(h,"wend");
			linefeed(h);

			indent(h,1);
			fprintf(h,"if (k<=(nelts-1))");
			linefeed(h);

			indent(h,2);
			fprintf(h,"for j=k+1 to nelts");
			linefeed(h);

			indent(h,3);
			fprintf(h,"if ((is_%s(j)=0) AND (cmp_%s(j,k)<0)) : k=j",iptr->Contents.name,iptr->Contents.name);
			linefeed(h);

			indent(h,2);
			fprintf(h,"next j");
			linefeed(h);
			indent(h,1);
			fprintf(h,"endif");
			linefeed(h);
			indent(h,1);
			fprintf(h,"ts_%s(i)=k",iptr->Contents.name);
			linefeed(h);
			indent(h,1);
			fprintf(h,"is_%s(k)=1;",iptr->Contents.name);
			linefeed(h);
			fprintf(h,"next i");
			linefeed(h);
			fprintf(h,"remove ls_%s",iptr->Contents.name);
			linefeed(h);
			fprintf(h,"remove is_%s",iptr->Contents.name);
			linefeed(h);
			indent(h,1); fprintf(h,"Exit"); linefeed(h);
			abal_error_abort(h,1,1);
			abal_error_return(h,__abal_keyword_status,1);
			fprintf(h,"endproc");
			linefeed(h);	linefeed(h);


			/* fonction de comparaison entre deux elements */
			sprintf(comment,"compare the elements a et b of ls_%s",iptr->Contents.name);
			memset(mon_code,'-',strlen(comment));
			mon_code[strlen(comment)]=0;
			fprintf(h,";* %s ",mon_code);
			linefeed(h);
			fprintf(h,";* %s ",comment);
			linefeed(h);
			fprintf(h,";* %s ",mon_code);
			linefeed(h);
			
			fprintf(h,"%s cmp_%s(a%%,b%%):#",__abal_keyword_proc,iptr->Contents.name);
			linefeed(h);

			fprintf(h,"dcl i%%,j%%");
			linefeed(h);
			fprintf(h,"endloc");
			linefeed(h); linefeed(h);
	
			abal_error_trap(h,1,1);

			fprintf(h,"r_%s=alias(ls_%s(a))",iptr->Contents.name,iptr->Contents.name);
			linefeed(h);
			fprintf(h,"rs_%s=alias(ls_%s(b))",iptr->Contents.name,iptr->Contents.name);
			linefeed(h);
			fprintf(h,"r_%s=large(r_%s)",iptr->Contents.name,iptr->Contents.name);
			linefeed(h);
			fprintf(h,"rs_%s=large(rs_%s)",iptr->Contents.name,iptr->Contents.name);
			linefeed(h);

			if (( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
				{
				if ((tptr = abal_payload(iptr)) != NULL)
					{
					memset(comment,0,256);
					strcpy(comment,tptr);
					tptr=comment;
					while ((rptr = strchr(tptr,'|')) != (char *) 0)
						{
						*rptr=0;
						tptr+=strlen(tptr)+1;
						};
					};
				tptr=comment;

				fprintf(h,"if (m1_%s<ms1_%s) : i=-1",iptr->Contents.name,iptr->Contents.name);
				linefeed(h);
				fprintf(h,"if (m1_%s=ms1_%s) : i=0",iptr->Contents.name,iptr->Contents.name);
				linefeed(h);
				fprintf(h,"if (m1_%s>ms1_%s) : i=1",iptr->Contents.name,iptr->Contents.name);
				linefeed(h);

				fprintf(h,"select (f_%s)",iptr->Contents.name);
				linefeed(h);

				for (i=0;i<fields;i++)
					{
					indent(h,1);
					fprintf(h,"case %u	; %s normal order",i+1,tptr);
					linefeed(h);
					indent(h,2);
					if (i)
						{
						fprintf(h,"if (m%u_%s<ms%u_%s) : Exit(-1)",i+1,iptr->Contents.name,i+1,iptr->Contents.name);
						linefeed(h);
						indent(h,2);
						fprintf(h,"if (m%u_%s=ms%u_%s) : Exit(i)",i+1,iptr->Contents.name,i+1,iptr->Contents.name);
						linefeed(h);
						indent(h,2);
						fprintf(h,"if (m%u_%s>ms%u_%s) : Exit(1)",i+1,iptr->Contents.name,i+1,iptr->Contents.name);
						linefeed(h);
						}
					else
						fprintf(h,"Exit(i)");
					linefeed(h);	linefeed(h);
					indent(h,1);
					fprintf(h,"case -%d	; %s inverse order",i+1,tptr);
					linefeed(h);
					indent(h,2);
					if (i)
						{
						fprintf(h,"if (ms%u_%s<m%u_%s) : Exit(-1)",i+1,iptr->Contents.name,i+1,iptr->Contents.name);
						linefeed(h);
						indent(h,2);
						fprintf(h,"if (ms%u_%s=m%u_%s) : Exit(-i)",i+1,iptr->Contents.name,i+1,iptr->Contents.name);
						linefeed(h);
						indent(h,2);
						fprintf(h,"if (ms%u_%s>m%u_%s) : Exit(1)",i+1,iptr->Contents.name,i+1,iptr->Contents.name);
						linefeed(h);
						}
					else
						fprintf(h,"Exit(-i)");
					linefeed(h);
					if (i<fields-1) linefeed(h);
					tptr+=strlen(tptr)+1;
					};
	
				indent(h,1);
				fprintf(h,"default		; unsorted");
				linefeed(h);
				indent(h,2);
				fprintf(h,"if (a<b) : exit(-1)");
				linefeed(h);
				indent(h,2);
				fprintf(h,"exit(1)");
				linefeed(h);
				fprintf(h,"endsel");
				linefeed(h);
				};

			indent(h,1); fprintf(h,"Exit(0)"); linefeed(h);
			abal_error_abort(h,1,1);
			abal_error_return(h,__abal_keyword_status,1);
			fprintf(h,"endproc");
			linefeed(h);	linefeed(h);
			fprintf(h,"* -------------------------------- *");
			linefeed(h);
			fprintf(h,"* lire le numero d'un element trie *");
			linefeed(h);
			fprintf(h,"* -------------------------------- *");
			linefeed(h);
			fprintf(h,"%s lts_%s(elt%%):%%",__abal_keyword_proc,iptr->Contents.name);
			linefeed(h);

			abal_error_trap(h,1,1);

			fprintf(h,"if (elt=0) : Exit(1)",iptr->Contents.name);
			linefeed(h);
			
			
			fprintf(h,"if (elt<=ns_%s)",iptr->Contents.name);
			linefeed(h);

			indent(h,1);
			fprintf(h,"Exit(ts_%s(elt))",iptr->Contents.name);
			linefeed(h);

			fprintf(h,"else");
			linefeed(h);

			indent(h,1);
			fprintf(h,"Exit(elt)");
			linefeed(h);

			fprintf(h,"endif");
			linefeed(h);

			indent(h,1); fprintf(h,"Exit(0)"); linefeed(h);
			abal_error_abort(h,1,1);
			abal_error_return(h,__abal_keyword_status,1);
			fprintf(h,"endproc");
			linefeed(h);	linefeed(h);
			};
		}
	return;
}

public	void	abal_access_method( FILE * h ,struct form_control *fptr)
{
	struct form_item * iptr;
	int	fitems=0;

	linefeed(h);	linefeed(h);
	fprintf(h,"* ------------------------- *");
	linefeed(h);
	fprintf(h,"* Test Widget Access Rights *");
	linefeed(h);
	fprintf(h,"* ------------------------- *");
	linefeed(h);
	fprintf(h,"%s value_access(FocusItem%%):%%",__abal_keyword_proc);
	linefeed(h);

	abal_error_trap(h,1,1);

	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {

		/* eliminate non focus items now */
		/* ----------------------------- */
		if (!( iptr->Contents.focus )) 
			continue;

		switch (iptr->Contents.style & _FRAME_TYPE) {
			case	_DATA_FRAME	:
				if (( iptr->Contents.align & 0x000F ) != _VISUAL_FRAME)
					continue;

			case	_BUTTON_FRAME	:
			case	_SELECT_FRAME	:
			case	_SWITCH_FRAME	:
			case	_CHECK_FRAME	:
			case	_EDIT_FRAME	:
				if (!( fitems++ )) {
					fprintf(h,"Select (FocusItem)");
					linefeed(h);
					}
				fprintf(h,"Case __%s :: Exit(a_%s)",iptr->Contents.name,iptr->Contents.name);
				linefeed(h);
				break;
			case	_RADIO_FRAME	:
				if (!( fitems++ )) {
					fprintf(h,"Select (FocusItem)");
					linefeed(h);
					}
				fprintf(h,"Case _%u_%s :: Exit(a%u_%s)",iptr->Contents.radio,iptr->Contents.name,iptr->Contents.radio,iptr->Contents.name);
				linefeed(h);
				break;

			};
		};
	if ( fitems ) {
		fprintf(h,"EndSel");
		linefeed(h);
		}

	fprintf(h,"Exit(0)");
	linefeed(h);

	abal_error_abort(h,1,1);
	abal_error_return(h,__abal_keyword_status,1);

	fprintf(h,"EndProc");
	linefeed(h);	linefeed(h);
}

public	void	abal_forms_method_forward(FILE * h, struct form_control * fptr,int mode)
{
	abal_forms_method_signature(h,fptr,__abal_keyword_forward,mode);
	return;
}

public	void	abal_forms_method_extern(FILE * h, struct form_control * fptr)
{
	abal_forms_method_signature(h,fptr,__abal_keyword_extern,1);
	return;
}

public	void	abal_forms_method_externs(FILE * h, struct form_control * fptr)
{
	abal_forms_method_signature(h,fptr,__abal_keyword_extern,16);
	return;
}

public 	void	constant_length_parameter(FILE * handle, struct form_item * iptr )
{
	fprintf(handle,",%s(",__abal_keyword_len);
	constant_value(handle,iptr);
	fprintf(handle,")");
	return;
}

public 	void	constant_hint_length_parameter(FILE * handle, struct form_item * iptr )
{
	fprintf(handle,",%s(",__abal_keyword_len);
	constant_hint_value(handle,iptr);
	fprintf(handle,")");
	return;
}

public 	void	constant_lendol_parameter(FILE * handle, struct form_item * iptr )
{
	fprintf(handle,",%s$(",__abal_keyword_len);
	constant_value(handle,iptr);
	fprintf(handle,")");
	return;
}

public	void	abal_widget_constants(FILE * h, struct form_control * fptr)
{
	char *	mptr;
	struct	form_item * iptr;
	char	prefix[16];
	char *	eptr;
	char *	nptr;
	int	nl;
	abal_comment(h,"Widget Message Constants",0);
	if (!( fptr->formflags & _FORM_CONSTANTS )) {
		for  ( 	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next )  {

			/* Widget Payload Constants */
			/* ------------------------ */
			if (!( method_is_valid((eptr = abal_payload(iptr)))))
				eptr = " ";
			if ( *eptr != _UNQUOTED_STRING ) {
				if (!( fptr->formflags &_MULTILINGUAL )) {
					/* Mono Lingual */
					/* ------------ */
					if (( iptr->Contents.style & _FRAME_TYPE ) == _RADIO_FRAME)
						sprintf(prefix,"msg%u_",iptr->Contents.radio);
					else	strcpy(prefix,"msg_");
				 	abal_string_constant(h,prefix,iptr->Contents.name,abal_payload(iptr));
					}
				else	{
					/* Multi Lingual */
					/* ------------- */
					for (nl=0; nl < MAXNATLANG; nl++ ) {
						if (!( mptr = iptr->Contents.messages[nl] ))
							mptr= abal_payload(iptr);
						if (( iptr->Contents.style & _FRAME_TYPE ) == _RADIO_FRAME)
							sprintf(prefix,"%s%u_",language_prefix(nl),iptr->Contents.radio);
						else	sprintf(prefix,"%s_",language_prefix(nl));
					 	abal_string_constant(h,prefix,iptr->Contents.name,mptr);
						}
					}
				}

			if (!( fptr->OnHint ))
				continue;

			/* Widget Hint Constants */
			/* --------------------- */
			if (!( method_is_valid((mptr = abal_hint(iptr)))))
				mptr = " ";
			if ( *mptr != _UNQUOTED_STRING ) {
				if (!( fptr->formflags &_MULTILINGUAL )) {
					/* Mono Lingual */
					/* ------------ */
					if (( iptr->Contents.style & _FRAME_TYPE ) == _RADIO_FRAME)
						sprintf(prefix,"hint%u_",iptr->Contents.radio);
					else	strcpy(prefix,"hint_");
				 	abal_string_constant(h,prefix,iptr->Contents.name,abal_hint(iptr));
					}
				else	{
					/* Multi Lingual */
					/* ------------- */
					for (nl=0; nl < MAXNATLANG; nl++ ) {
						if (!( mptr = iptr->Contents.hmessages[nl] ))
							mptr= abal_hint(iptr);
						if (( iptr->Contents.style & _FRAME_TYPE ) == _RADIO_FRAME)
							sprintf(prefix,"%s%uh",language_prefix(nl),iptr->Contents.radio);
						else	sprintf(prefix,"%sh",language_prefix(nl));
					 	abal_string_constant(h,prefix,iptr->Contents.name,mptr);
						}	
					}
				}
			}
		}
	abal_comment(h,"Widget Focus Values",0);
	for  ( 	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) { 
		if (!( iptr->Contents.focus )) 
			continue;
		else if (( iptr->Contents.style & _FRAME_TYPE ) == _RADIO_FRAME)
			sprintf(prefix,"_%u_",iptr->Contents.radio);
		else	strcpy(prefix,"__");
		abal_integer_constant(h,prefix,iptr->Contents.name,iptr->Contents.focus);
		}
	return;
}

public	int	abal_method_body( FILE * h,char * eptr, int l, char * hptr,int margin)
{
	int	n;
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
			c = *eptr; *eptr = 0;
			for (n=0; *(lptr+i) != 0; n++ ) {
				if ( *(lptr+i) == ';' )
					break;
				else if ( *(lptr+i) == ' ' )
					continue;
				else if ( *(lptr+i) == '\t' )
					continue;
				else	break;
				}

			if ( *(lptr+n) != ';' ) {
				indent(h,margin);
				status = abal_method_line(h,lptr,i,hptr,&feeder);
				}
			else	{
				feeder = status=0;
				}
			*eptr = c;
			if ( feeder ) linefeed(h);
			if ( status ) break;
			}
		}
	return(status);
}

public	void	abal_forms_members(FILE * h, struct form_control * fptr)
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
		if (( mptr->type & 7) == _ABAL_FIELD ) {
			if ( method_is_valid( mptr->name ) )
				abal_field(h,"\0",mptr->name);
			else	abal_field(h,(char *) 0, (char *) 0);
			}
		else if (( mptr->type & 7) == _ABAL_FILLER )
			abal_filler(h,mptr->size);
		else if ( method_is_valid( mptr->name ) ) {
			switch ((mptr->type & 0x18) >> 3) {
				case 0	:
					abal_dcl(h,"\0",mptr->name,(mptr->type & 7),mptr->size,mptr->first,mptr->second,mptr->comment);
					break;
				case 1	:
					abal_ptr(h,"\0",mptr->name,(mptr->type & 7),mptr->size,mptr->first,mptr->second);
					break;
				case 2	:
					abal_const(h,"\0",mptr->name,(mptr->type & 7),mptr->comment);
					break;
				}
			}
		}
	return;
}

public	void	abal_onfocus_default(FILE * handle, struct form_item * iptr, int margin )
{
	char	*	optr;
	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = "o";
	else	optr = "\0";
	indent(handle,margin);
	if (!( Abal_Config.input_method ))
		fprintf(handle,__abal_visual_keycode);
	else	fprintf(handle,"KeyCode=%s(%s)",Abal_Config.input_method,optr);
	linefeed(handle);
	return;
}

public	struct	form_item * locate_forms_window( struct form_control * fptr)
{
	struct	form_control * ffptr;
	struct	form_item * wptr;
	for (	wptr=fptr->first;
		wptr != (struct form_item *) 0;
		wptr = wptr->next )
	{
		if ((wptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME )
			break;
	}
	if ( wptr )
		return( wptr );
	else if (!( method_is_valid( fptr->extends ) ))
		return( wptr ); 
	else if (!( ffptr = locate_form_control( fptr->extends ) ))
		return( wptr );
	else	return( locate_forms_window( ffptr ) );
}

private	void	abal_standard_input( FILE * h,struct form_control * fptr, char * optr)
{
	char	*	sptr;
	struct	form_item * wptr;
	if ( method_is_valid((sptr = Abal_Config.input_method))) {
		fprintf(h,"%s %s(%s) : %c",__abal_keyword_proc,sptr,optr,0x0025);
		linefeed(h);
		if ( *optr ) optr = "o";
		abal_dcl(h,"Focus","Number",_ABAL_WORD,2,0,0,NULL);
		indent(h,1); fprintf(h,"do"); linefeed(h);
			indent(h,2);
			fprintf(h,__abal_visual_keycode);
			linefeed(h);
			indent(h,2); fprintf(h,"Select KeyCode"); 	linefeed(h);
			indent(h,2); fprintf(h,"Case   256"); 		linefeed(h);
			indent(h,3); fprintf(h,"VisualEvent(MouseEvent)");	linefeed(h);
			indent(h,3); fprintf(h,"Select MouseType");		linefeed(h);
			indent(h,3); fprintf(h,"Case _MIMO_MOVE");		linefeed(h);

			if (( fptr->inhibit_flush & 2 )
			&&  (( wptr = locate_forms_window( fptr )) != (struct form_item *) 0)) {
				/* all events including MOVE are raised */
				indent(h,4);
				if ( wptr->Contents.events->xo_create & _EVENT_IS_FOCUS ) {
					fprintf(h,"if ((%s < (%s) ) '",__abal_mouse_column,widget_x_position(wptr,0));
					linefeed(h);
					fprintf(h,"or (%s < (%s) ) '",__abal_mouse_row,widget_y_position(wptr,0));
					linefeed(h);
					fprintf(h,"or (%s > (%s+w_%s) ) '",__abal_mouse_column,widget_x_position(wptr,0),wptr->Contents.name);
					linefeed(h);
					fprintf(h,"or (%s > (%s+h_%s) ))",__abal_mouse_row,widget_y_position(wptr,0),wptr->Contents.name);
					linefeed(h);
					}
				else	{
					fprintf(h,"if (( %s <  x_%s )'",__abal_mouse_column,wptr->Contents.name);
					linefeed(h);
					fprintf(h,"or ( %s <  y_%s )'",__abal_mouse_row   ,wptr->Contents.name);
					linefeed(h);
					fprintf(h,"or ( %s >  (x_%s+%u) )'",__abal_mouse_column,wptr->Contents.name,wptr->Contents.w);
					linefeed(h);
					fprintf(h,"or ( %s >  (y_%s+%u) )) ",__abal_mouse_row   ,wptr->Contents.name,wptr->Contents.h);
					linefeed(h);
					}
				indent(h,5); fprintf(h,"Exit(256)");		linefeed(h);
				abal_endif(h,4);
				}
			indent(h,4); fprintf(h,"FocusNumber=%sEvent(%s)",Abal_Config.cname,optr);
			linefeed(h);
			indent(h,4); fprintf(h,"if (( FocusNumber <> -1 )  and ( FocusNumber <> FocusItem )) :: Exit(KeyCode) :: Endif");
			linefeed(h);
			indent(h,3); fprintf(h,"Default"); 			linefeed(h);
			indent(h,4); fprintf(h,"Exit(KeyCode)");			linefeed(h);
			indent(h,3); fprintf(h,"EndSel");	 		linefeed(h);
			indent(h,2); fprintf(h,"Default"); 		linefeed(h);
			indent(h,3); fprintf(h,"Exit(KeyCode)");		linefeed(h);
			indent(h,2); fprintf(h,"EndSel"); 		linefeed(h);
		indent(h,1); fprintf(h,"loop"); linefeed(h);
		linefeed(h);
		abal_endproc(h);
		linefeed(h);
		}
	return;
}

public	void	abal_forms_methods(FILE * h, struct form_control * fptr)
{
	struct	forms_method 	* mptr;
	char			* optr;
	int	l;
	char *			qname;

	if (!( fptr ))	return;
	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = __abal_overlay_object;
	else	optr = "\0";
	if ( Abal_Config.newstdin ==2 ) {
		abal_standard_input(h,fptr,optr);
		}
	for (	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {
		if (!( mptr->name ))
			continue;
		if (!( mptr->type & _METHOD_FUNCTION ))
			continue;
		if ( mptr->type & _METHOD_EXTERN )
			continue;
		linefeed(h);
		qname = resolve_method_name( mptr->name );
		if (!( method_is_valid( mptr->signature ) ))  {
			fprintf(h,"%s %s(%s)",	
				__abal_keyword_proc,
				qname,optr);
			}
		else if (!(*optr )) {
			fprintf(h,"%s %s(%s)",
				__abal_keyword_proc,
				qname,mptr->signature);
			}
		else	{
			fprintf(h,"%s %s(%s,%s)",	
				__abal_keyword_proc,
				qname,optr,mptr->signature);
			}
		if ( mptr->type & _METHOD_TYPE ) {
			switch (( mptr->type & _METHOD_TYPE) ) {
				case	_METHOD_BYTE 	:	fprintf(h," : # " ); break;
				case	_METHOD_WORD 	:	fprintf(h," : %% "); break;
				case	_METHOD_NUMERIC :	fprintf(h," : * " ); break;
				case	_METHOD_CLASS	:	
				case	_METHOD_STRING	:	fprintf(h," : $ " ); break;
				case	_METHOD_LONG    :	fprintf(h," : : " ); break;
				}
			}
		linefeed(h);
		if (( l = method_is_valid( mptr->text )) != 0) {
			abal_pragma_enter(h,"this",qname);
			abal_method_body(h,mptr->text,l,qname,1);
			abal_pragma_leave(h,"this",qname);
			}
		linefeed(h);
		abal_endproc(h);
		linefeed(h);

		}
	return;

}

public	int	abal_method( 
	FILE * h,
	struct form_item * iptr,
	char * mptr, 
	char * nptr, 
	char * eptr  )
{
	struct	form_control * fptr;
	int	status=0;
	int	l;
	int	n;
	int	i;
	char	*	optr;
	if (!( iptr ))
		return(0);
	else if (!( fptr = iptr->parent ))
		return(0);
	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = __abal_overlay_object;
	else	optr = "\0";
	if (!( l = method_is_valid( eptr )))
		return(0);
	else	{
		linefeed(h);
		if (( iptr->Contents.access & _WIDGET_PUBLIC ) 
		&&  ( fptr->isoverlay ) 
		&&  (!( fptr->isprogram )))
			fprintf(h,"%s %s%s%s(%s) : %c ",__abal_keyword_proc,fptr->identifier,mptr,nptr,optr,0x0025);
		else	fprintf(h,"%s %s%s(%s) : %c ",__abal_keyword_proc,mptr,nptr,optr,0x0025);
		linefeed(h);
		abal_error_trap(h,1,1);
		abal_pragma_enter(h,mptr,nptr);
		status = abal_method_body(h,eptr,l,mptr,1);
		abal_pragma_leave(h,mptr,nptr);
		abal_returni(h,-1,1);
		abal_error_abort(h,1,1);
		abal_error_return(h,__abal_keyword_status,1);
		abal_endproc(h);
		linefeed(h);
		}		
	return(status);
}

public	void	abal_widget_getset_parameters(  FILE * h, struct form_item * iptr )
{
	switch ((iptr->Contents.style & _FRAME_TYPE)) {

		case	_EDIT_FRAME	:
			switch ( iptr->Contents.datatype ) {
				case	_WIDGET_WORD		:
					fprintf(h,"ptr p_%s%c",iptr->Contents.name,0x0025);
					break;
				case	_WIDGET_BYTE		:
					fprintf(h,"ptr p_%s#",iptr->Contents.name);
					break;
				case	_WIDGET_LONG		:
					fprintf(h,"ptr p_%s:",iptr->Contents.name);
					break;
				case	_WIDGET_FLOAT		:
				case	_WIDGET_NUMERIC		:
				case	_WIDGET_STRING		:
				case	_WIDGET_KONSTANT	:
					fprintf(h,"ptr p_%s",iptr->Contents.name);
					fprintf(h,"$,pl%s%c",iptr->Contents.name,0x0025);
					break;
				}
			break;
		case	_BUTTON_FRAME	:
			fprintf(h,"ptr p_%s",iptr->Contents.name);
			fprintf(h,"$,pl%s%c",iptr->Contents.name,0x0025);
			break;

		case	_RADIO_FRAME	:

		case	_CHECK_FRAME	:
		case	_SWITCH_FRAME	:
		case	_SCROLL_FRAME	:
		case	_PROGRESS_FRAME	:
		case	_SELECT_FRAME	:
			fprintf(h,"ptr p_%s",iptr->Contents.name);
			fprintf(h,"%c",0x0025);
			break;
		}
	return;
}

public	char	*	abal_public_method_signature( 
	FILE * h,
	struct form_item * iptr,
	char * fnptr,
	char * mptr, 
	char * nptr )
{
	char *	optr;
	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = __abal_overlay_object;
	else	optr = "\0";
	if ( *optr )
		fprintf(h,"%s %s%s%s(%s,",__abal_keyword_proc,fnptr,mptr,nptr,optr);
	else	fprintf(h,"%s %s%s%s(%s",__abal_keyword_proc,fnptr,mptr,nptr,optr);

	abal_widget_getset_parameters( h, iptr );

	fprintf(h,") : %c ",0x0025);
	linefeed(h);
	return(optr);
}

/*	--------------------------------------------	*/
/*	a b a l _ p u b l i c _ m e t h o d ( .... )	*/
/*	--------------------------------------------	*/
/*	performs generation of an individual get/set	*/
/*	method comprising the corresponding transfer	*/
/*	for a widget declared public.			*/
/*	--------------------------------------------	*/
public	int	abal_public_method( 
	FILE * h,
	char * mptr, 
	char * nptr, 
	struct form_item * iptr,
	int    mode )
{
	int	status=0;
	int	l;
	int	n;
	int	i;
	char	*	optr;
	struct	form_control * fptr;

	if (!( iptr ))
		return(0);
	else if (!( fptr = iptr->parent ))
		return(0);
	else if (!( fptr->identifier ))
		return(0);
	linefeed(h);

	optr = abal_public_method_signature(h,iptr,fptr->identifier,mptr,nptr);

	abal_error_trap(h,1,1);
	
	switch ( mode ) {
		case	0	:	/* SET */
			abal_import_widget(h,iptr,1);
			break;
		case	1	:	/* GET */
			abal_export_widget(h,iptr,1);
		}

	abal_returni(h,-1,1);
	abal_error_abort(h,1,1);
	abal_error_return(h,__abal_keyword_status,1);
	abal_endproc(h);
	linefeed(h);
	return(status);
}

public	char	*	abal_public_methods_signature(
	FILE * h,
	struct form_control * fptr, char * methodname )
{
	int		started=0;
	char	*	optr;
	struct	form_item * iptr;
	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = __abal_overlay_object;
	else	optr = "\0";
	if ( *optr )
		fprintf(h,"%s %s%s(%s,",__abal_keyword_proc,fptr->identifier,methodname,optr);
	else	fprintf(h,"%s %s%s(%s",__abal_keyword_proc,fptr->identifier,methodname,optr);

	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if (!( iptr->Contents.access & _WIDGET_PUBLIC ))
			continue;
		switch ((iptr->Contents.style & _FRAME_TYPE)) {

			case	_EDIT_FRAME	:
				if (started) fprintf(h,",");
				started += abal_datatype_parameter(h,iptr,(*methodname == 'G' ? 0 : 2));
				break;

			case	_BUTTON_FRAME	:
				if (started) fprintf(h,",");
				fprintf(h,"ptr p_%s",iptr->Contents.name);
				fprintf(h,"$,pl%s%c",iptr->Contents.name,0x0025);
				started++;
				break;

			case	_RADIO_FRAME	:
	
			case	_CHECK_FRAME	:
			case	_SWITCH_FRAME	:
			case	_SCROLL_FRAME	:
			case	_PROGRESS_FRAME	:
			case	_SELECT_FRAME	:
				if (started) fprintf(h,",");
				fprintf(h,"ptr p_%s",iptr->Contents.name);
				fprintf(h,"%c",0x0025);
				started++;
				break;
			}
		}

	fprintf(h,") : %c ",0x0025);
	linefeed(h);
	return( optr );
}

/*	----------------------------------------------	*/
/*	a b a l _ p u b l i c _ m e t h o d s ( .... )	*/
/*	----------------------------------------------	*/
/*	performs generation of the formlevel get/set	*/
/*	method comprising the corresponding transfer	*/
/*	for the various widgets declard public		*/
/*	----------------------------------------------	*/
public	int	abal_public_methods(
	FILE * h,
	struct form_control * fptr, char * methodname )
{
	char	*	optr;
	struct	form_item * iptr;
	if (!( fptr ))
		return(0);
	else if (!( h ))
		return(0);
	else if (!( methodname ))
		return(0);
	linefeed(h);

	optr = abal_public_methods_signature( h, fptr, methodname );

	abal_error_trap(h,1,1);
	
	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if (!( iptr->Contents.access & _WIDGET_PUBLIC ))
			continue;
		switch ((iptr->Contents.style & _FRAME_TYPE)) {

			case	_EDIT_FRAME	:
				indent(h,1);
				if ( *optr )
					fprintf(h,"%s%s%s(o,",fptr->identifier,iptr->Contents.name,methodname);
				else	fprintf(h,"%s%s%s(",fptr->identifier,iptr->Contents.name,methodname);
				abal_datatype_parameter(h,iptr,1);
				fprintf(h,")",iptr->Contents.name,iptr->Contents.name);
				linefeed(h);
				break;
			case	_BUTTON_FRAME	:
				indent(h,1);
				if ( *optr )
					fprintf(h,"%s%s%s(o,",fptr->identifier,iptr->Contents.name,methodname);
				else	fprintf(h,"%s%s%s(",fptr->identifier,iptr->Contents.name,methodname);
				fprintf(h,"p_%s,pl%s)",iptr->Contents.name,iptr->Contents.name);
				linefeed(h);
				break;

			case	_RADIO_FRAME	:
	
			case	_CHECK_FRAME	:
			case	_SWITCH_FRAME	:
			case	_SCROLL_FRAME	:
			case	_PROGRESS_FRAME	:
			case	_SELECT_FRAME	:
				indent(h,1);
				if ( *optr )
					fprintf(h,"%s%s%s(o,",fptr->identifier,iptr->Contents.name,methodname);
				else	fprintf(h,"%s%s%s(",fptr->identifier,iptr->Contents.name,methodname);
				fprintf(h,"p_%s)",iptr->Contents.name,iptr->Contents.name);
				linefeed(h);
				break;
			}
		}

	abal_returni(h,-1,1);
	abal_error_abort(h,1,1);
	abal_error_return(h,__abal_keyword_status,1);
	abal_endproc(h);
	linefeed(h);


	return(1);
}


public	void	instance_widget_overlay( FILE * h, struct form_item * iptr, int methods )
{
	/* -------------------------------------------- */
	/* PTR O$=10 :: F=M,O :: PTR PROC O.M(N) :: F=M	*/
	/* -------------------------------------------- */
	abal_ptr(h,_OVL_PREFIX,iptr->Contents.name,_ABAL_STRING,10,0,0);
	abal_field(h,_OVL_PREFIX,iptr->Contents.name);
	abal_ptr(h,_IMT_PREFIX,iptr->Contents.name,_ABAL_PROC,5,methods,0);
	abal_field(h,(char *)0,(char *) 0);
	return;
}

public	int	sing_throw_failure( int v, char * message )
{
	return( v );
}


/*	-------------------------------------------------------		*/
/*	r e s o l v e _ o v e r l a y _ m e t h o d _ e n t r y		*/
/*	-------------------------------------------------------		*/
/*	The order of methods in the overlay method table is not		*/
/*	the same for web services and web agents and standard		*/
/*	application overlays. This function is here to resolve 		*/
/*	these differences ... especially since the introduction		*/
/*	of the new php/soap three layer production model where		*/
/*	the web service overlay packagin must respect the usual		*/
/*	web service interface while presenting the standard form	*/
/*	visual interface method entry points.				*/
/*	-------------------------------------------------------		*/
public	int	resolve_overlay_method_entry( struct form_control * fptr, int method )
{
	switch ( fptr->language ) {
		case	_GENERATE_PHP	:
			return( soap_resolve_overlay_method( fptr, method ) );
		default			:
			return( method );
		}
}

public	void	invoke_widget_overlay_method( FILE * h, struct form_item * iptr,int method )
{
	int	ovlmethod;
	if (!( ovlmethod = resolve_overlay_method_entry( Context.Form, method ) )) {
		sing_throw_failure( 78, "unresolved overlay method" );
		return;
	}
	fprintf(h,"%s (%s%s(%u))(",
		__abal_keyword_call, _IMT_PREFIX,iptr->Contents.name, ovlmethod);
	fprintf(h,"%s%s",_OVL_PREFIX,iptr->Contents.name);
	if ( method == _OVL_ONCREATE )  {
		fprintf(h,",%s%s,%s$(%s%s))",
			_BUF_PREFIX,iptr->Contents.name,
			__abal_keyword_len,
			_BUF_PREFIX,iptr->Contents.name);
		}
	else 	fprintf(h,")");
	return;
}

public	void	invoke_widget_overlay( FILE * h, struct form_item * iptr,int method )
{
	/* --------------------------------------------------- */
	/* IF ( VALIDPTR(O) <> 0 ) :: CALL (O.M(N))() :: ENDIF */
	/* --------------------------------------------------- */
	indent(h,1);
	fprintf(h,"%s (%s(%s%s) <> 0)",
		__abal_keyword_if,__abal_keyword_validptr,
		_OVL_PREFIX,iptr->Contents.name );
	linefeed(h);

	indent(h,2);

	if ( method == _OVL_ONFOCUS )
		fprintf(h,"%s = ",__abal_keyword_keycode);
	else 	fprintf(h,"%s = ",__abal_keyword_status);

	invoke_widget_overlay_method( h, iptr, method );

	linefeed(h);

	abal_endif(h,1);
	return;
}

public	void	InvokeWidgetOverlay( FILE * h, struct form_item * iptr,int method,char * pptr )
{
	if ( *pptr != '(' ) {
		invoke_widget_overlay( h,iptr, method );
		return;
		}
	/* --------------------------------------------------- */
	/* IF ( VALIDPTR(O) <> 0 ) :: CALL (O.M(N))() :: ENDIF */
	/* --------------------------------------------------- */
	indent(h,1);
	fprintf(h,"%s (%s(%s%s) <> 0)",
		__abal_keyword_if,__abal_keyword_validptr,
		_OVL_PREFIX,iptr->Contents.name );
	linefeed(h);

	indent(h,2);

	if ( method == _OVL_ONFOCUS )
		fprintf(h,"%s = ",__abal_keyword_keycode);
	else 	fprintf(h,"%s = ",__abal_keyword_status);

	fprintf(h,"%s (%s%s(%u))(",
		__abal_keyword_call, _IMT_PREFIX,iptr->Contents.name, method);
	fprintf(h,"%s%s",_OVL_PREFIX,iptr->Contents.name);
	if ( method == _OVL_ONCREATE )  {
		fprintf(h,",%s%s,%s$(%s%s))",
			_BUF_PREFIX,iptr->Contents.name,
			__abal_keyword_len,
			_BUF_PREFIX,iptr->Contents.name);
		}
	else 	{
		fprintf(h,",");
		abal_macro_conversion(h,pptr+1,iptr->Contents.name);
		}

	linefeed(h);

	abal_endif(h,1);
	return;
}


public	void	attach_widget_overlay( FILE * h, struct form_item * iptr )
{
	char *	tptr;
	char *	wptr;

	char *	pptr;
	char *	bptr;
	char *	nptr;
	/* ATTACH O("file.at") */
	/* ------------------- */
	if (( iptr->Contents.style & _FRAME_TYPE) == _BUTTON_FRAME)
		nptr = iptr->Contents.format;
	else	nptr = abal_payload(iptr);

	if ( method_is_valid( nptr ) ) {

		if ( *nptr != _UNQUOTED_STRING ) {
			indent(h,1);
			if (!( pptr = allocate_string( nptr ) )) {
				fprintf(h,"allocation failure");
				return;
				}
			else	bptr= pptr;

			while ( *pptr != 0 ) {
				if ( *pptr == '(' )
					break;
				else	pptr++;
				}
			/* --------------------------- */
			/* special case for components */
			/* --------------------------- */
			switch (iptr->Contents.style & _FRAME_TYPE) {
				case	_DATA_FRAME	:
#ifdef	EARLY_RESOLVE_COMPONENT
					if (( iptr->Contents.align & 0x000F ) == _VISUAL_FRAME) {
						if ((tptr = component_object_prefix( nptr )) != (char *) 0 ) {
							if (( wptr = allocate( strlen( nptr ) + strlen( tptr ) + 16 )) != (char *) 0) {
								sprintf(wptr,"%s%s",tptr,nptr);
								nptr = wptr;
								break;
								}
							}
						}
#endif

				default			:
					if (!( nptr = allocate_string( nptr ) )) {
						fprintf(h,"allocation failure");
						liberate( bptr );
						return;
						}
					else	break;
				}

			if (!( nptr = enforce_extension( nptr, AT_EXTENSION ) )) {
				fprintf(h,"allocation failure");
				liberate( bptr );
				return;
				}
			sprintf(namebuffer,"%c%s%c",__QUOTE,nptr,__QUOTE);
			liberate( nptr );
			fprintf(h,"%s %s%s(%s)",__abal_keyword_attach,
				_OVL_PREFIX,iptr->Contents.name,namebuffer);
			linefeed(h);

			/* O.PRECONSTR */
			/* ----------- */
			InvokeWidgetOverlay(h,iptr,_OVL_PRECONST,pptr);
			liberate( bptr );
			}
		else	{
			indent(h,1);
			fprintf(h,"%s %s%s(",
				__abal_keyword_attach,
					_OVL_PREFIX,iptr->Contents.name);
			variable_value(h,(nptr+1));
			fprintf(h,")");
			linefeed(h);
			/* O.PRECONSTR */
			/* ----------- */
			invoke_widget_overlay(h,iptr,_OVL_PRECONST);
			}
		}
	


	/* O.CREATE */
	/* -------- */
	invoke_widget_overlay(h,iptr,_OVL_ONCREATE);

	return;

}

public	void	abal_invoke_widget_create( FILE * h, struct form_item * iptr, int mode, int margin )
{
	if ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME) {
		if(!( iptr = locate_radio_create( iptr->parent,iptr->Contents.name )))
			return;
		}
	if ( iptr->Contents.events->xo_create & _EVENT_IS_FUNCTION ) {
		activate_abal_method(h,iptr,iptr->Contents.name,__abal_method_create,iptr->Contents.events->on_create,mode,margin);
		}
	else 	inline_abal_method(h,iptr,iptr->Contents.name,__abal_method_create,iptr->Contents.events->on_create,mode,margin);
	return;
}

public	int	abal_invoke_widget_show( FILE * h, struct form_item * iptr, int mode, int margin )
{
	if ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME) {
		if(!( iptr = locate_radio_show( iptr->parent,iptr->Contents.name )))
			return(0);
		}
	if ( iptr->Contents.events->xo_show & _EVENT_IS_FUNCTION ) {
		return( activate_abal_method(h,iptr,iptr->Contents.name,__abal_method_show,iptr->Contents.events->on_show,mode,margin) );
		}
	else	return( inline_abal_method(h,iptr,iptr->Contents.name,__abal_method_show,iptr->Contents.events->on_show,mode,margin) );
	return(0);
}

public	void	abal_invoke_widget_get_focus( FILE * h, struct form_item * iptr, int mode, int margin )
{
	if ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME) {
		if(!( iptr = locate_radio_get_focus( iptr->parent,iptr->Contents.name )))
			return;
		}
	if ( iptr->Contents.events->xo_get_focus & _EVENT_IS_FUNCTION ) {
		activate_abal_method(h,iptr,iptr->Contents.name,__abal_method_get_focus,iptr->Contents.events->on_get_focus,mode|2,margin);
		}
	else	inline_abal_method(h,iptr,iptr->Contents.name,__abal_method_get_focus,iptr->Contents.events->on_get_focus,mode,margin);
	return;
}

public	void	abal_invoke_widget_event( FILE * h, struct form_item * iptr, int mode, int margin )
{
	if ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME) {
		if(!( iptr = locate_radio_event( iptr->parent,iptr->Contents.name )))
			return;
		}
	if ( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION ) {
		activate_abal_method(h,iptr,iptr->Contents.name,__abal_method_event,iptr->Contents.events->on_event,mode,margin);
		}
	else	inline_abal_method(h,iptr,iptr->Contents.name,__abal_method_event,iptr->Contents.events->on_event,mode,margin);
	return;
}

public	void	abal_invoke_widget_lose_focus( FILE * h, struct form_item * iptr,int mode, int margin )
{
	if ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME) {
		if(!( iptr = locate_radio_lose_focus( iptr->parent,iptr->Contents.name )))
			return;
		}
	if ( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION ) {
		activate_abal_method(h,iptr,iptr->Contents.name,__abal_method_lose_focus,iptr->Contents.events->on_lose_focus,mode|2,margin);
		}
	else	inline_abal_method(h,iptr,iptr->Contents.name,__abal_method_lose_focus,iptr->Contents.events->on_lose_focus,mode,margin);
	return;
}

public	void	abal_invoke_widget_hide( FILE * h, struct form_item * iptr,int mode, int margin  )
{
	if ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME) {
		if(!( iptr = locate_radio_hide( iptr->parent,iptr->Contents.name )))
			return;
		}
	if ( iptr->Contents.events->xo_hide & _EVENT_IS_FUNCTION ) {
		activate_abal_method(h,iptr,iptr->Contents.name,__abal_method_hide,iptr->Contents.events->on_hide,mode,margin);
		}
	else	inline_abal_method(h,iptr,iptr->Contents.name,__abal_method_hide,iptr->Contents.events->on_hide,mode,margin);
	return;
}

public	void	abal_invoke_widget_remove( FILE * h, struct form_item * iptr, int mode, int margin )
{
	if ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME) {
		if(!( iptr = locate_radio_remove( iptr->parent,iptr->Contents.name )))
			return;
		}
	if ( iptr->Contents.events->xo_remove & _EVENT_IS_FUNCTION ) {
		activate_abal_method(h,iptr,iptr->Contents.name,__abal_method_remove,iptr->Contents.events->on_remove,mode,margin);
		}
	else	inline_abal_method(h,iptr,iptr->Contents.name,__abal_method_remove,iptr->Contents.events->on_remove,mode,margin);
	return;
}

public	void	detach_widget_overlay( FILE * h, struct form_item * iptr )
{
	/* O.REMOVE */
	/* -------- */
	invoke_widget_overlay(h,iptr,_OVL_ONREMOVE);

	/* O.POSTDESTR */
	/* ----------- */
	invoke_widget_overlay(h,iptr,_OVL_POSTDEST);

	/* IF VALIDPTR(O) :: DETACH O :: ENDIF */
	/* ----------------------------------- */
	indent(h,1);
	fprintf(h,"%s (%s(%s%s) <> 0)",
		__abal_keyword_if,__abal_keyword_validptr,
		_OVL_PREFIX,iptr->Contents.name );
	linefeed(h);
	indent(h,2);
	fprintf(h,"%s %s%s",__abal_keyword_detach,_OVL_PREFIX, iptr->Contents.name);
	linefeed(h);
	abal_endif(h,1);

	return;

}

public	void	abal_scrollbutton_driver( FILE * h, struct form_item * iptr )
{
	int		fw;
	int		fh;

	fw = guifontsize(iptr->Contents.font);
	fh = (fw >> 8); fw &= 0x00FF;

	if ( iptr->Contents.w > iptr->Contents.h ) {

		/* ---------------------- */
		/* Left and Right Buttons */
		/* ---------------------- */
		if ( iptr->Contents.align & _A_LEFT ) {
			indent(h,1); fprintf(h,"if ( %s < (%s+%s) )",__abal_mouse_column,widget_x_position(iptr,0),widget_h_dimension(iptr,0));
			linefeed(h); 
				abal_gosub(h,"&awaitup",2);
				indent(h,2); fprintf(h,"v_%s -= 1",iptr->Contents.name);
				linefeed(h);
				abal_gosub(h,"&limits",2);
				abal_gosub(h,"&payload",2);
				abal_scrollbar_widget(h,iptr,2,0);
				abal_returni(h,-1,2);
			abal_endif(h,1);
			}
		if ( iptr->Contents.align & _A_RIGHT ) {
			indent(h,1); fprintf(h,"if ( %s > (%s+%s-%s) )",__abal_mouse_column,widget_x_position(iptr,0),widget_w_dimension(iptr,0),widget_h_dimension(iptr,0));
			linefeed(h); 
				abal_gosub(h,"&awaitup",2);
				indent(h,2); fprintf(h,"v_%s += 1",iptr->Contents.name);
				linefeed(h);
				abal_gosub(h,"&limits",2);
				abal_gosub(h,"&payload",2);
				abal_scrollbar_widget(h,iptr,2,0);
				abal_returni(h,-1,2);
			abal_endif(h,1);
			}
		}
	else	{
		/* ------------------- */
		/* Up and Down Buttons */
		/* ------------------- */
		if ( iptr->Contents.align & _A_LEFT ) {
			indent(h,1); fprintf(h,"if ( %s < (%s+%s) )",__abal_mouse_row,widget_y_position(iptr,0),widget_w_dimension(iptr,0));
			linefeed(h);
				abal_gosub(h,"&awaitup",2);
				indent(h,2); fprintf(h,"v_%s -= 1",iptr->Contents.name);
				linefeed(h);
				abal_gosub(h,"&limits",2);
				abal_gosub(h,"&payload",2);
				abal_scrollbar_widget(h,iptr,2,0);
				abal_returni(h,-1,2);
			abal_endif(h,1);
			}
		if ( iptr->Contents.align & _A_RIGHT ) {
			indent(h,1); fprintf(h,"if ( %s > (%s+%s-%s) )",__abal_mouse_row,widget_y_position(iptr,0),widget_h_dimension(iptr,0),widget_w_dimension(iptr,0));
			linefeed(h);
				abal_gosub(h,"&awaitup",2);
				indent(h,2); fprintf(h,"v_%s += 1",iptr->Contents.name);
				linefeed(h);
				abal_gosub(h,"&limits",2);
				abal_gosub(h,"&payload",2);
				abal_scrollbar_widget(h,iptr,2,0);
				abal_returni(h,-1,2);
			abal_endif(h,1);
			}
		}
	return;
}
		
public	void	abal_widget_viewport(FILE * h, struct form_item * iptr )
{
	switch ((iptr->Contents.style & _FRAME_TYPE)) {

		case	_EDIT_FRAME	:

			fprintf(h,"%s=%s(%s+1,%s+1,%s,%s",
				__abal_keyword_status,__abal_visual_viewport,
				widget_x_position(iptr,0),
				widget_y_position(iptr,0),
				widget_w_dimension(iptr,0),
				widget_h_dimension(iptr,0));
			break;

		case	_OUTSET_FRAME	:
		case	_INSET_FRAME	:
			fprintf(h,"%s=%s(%s+1,%s+1,%s-2,%s-2",
				__abal_keyword_status,__abal_visual_viewport,
				widget_x_position(iptr,0),
				widget_y_position(iptr,0),
				widget_w_dimension(iptr,0),
				widget_h_dimension(iptr,0));
			break;

		case	_RIDGE_FRAME	:
		case	_GROOVE_FRAME	:
			fprintf(h,"%s=%s(%s+2,%s+2,%s-4,%s-4",
				__abal_keyword_status,__abal_visual_viewport,
				widget_x_position(iptr,0),
				widget_y_position(iptr,0),
				widget_w_dimension(iptr,0),
				widget_h_dimension(iptr,0));
			break;

		default			:
			fprintf(h,"%s=%s(%s,%s,%s,%s",
				__abal_keyword_status,__abal_visual_viewport,
				widget_x_position(iptr,0),
				widget_y_position(iptr,0),
				widget_w_dimension(iptr,0),
				widget_h_dimension(iptr,0));
		}
	font_parameter(h,iptr);
	fprintf(h,")");
	return;
}

public	void	abal_widget_action( FILE * h, struct form_item * iptr )
{
	char *	optr;
	struct	form_control * fptr;
	if (!( fptr = iptr->parent ))
		return;
	else if ((fptr->isprogram) && (fptr->isoverlay))
		optr = "o,";
	else	optr = "\0";
	fprintf(h,"%s%s(%s)",iptr->Contents.name,__abal_method_action,optr);
	return;
}

public	void	abal_window_driver( FILE * h, struct form_item * iptr )
{
	char	*	eptr;
	int		l;
	char 	*	mode;
	char 	*	item;
	char	*	optr;
	char	*	ooptr;
	struct form_item * wptr;
	struct form_control *fptr;

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay )) {
		ooptr = "o";
		optr = __abal_overlay_object;
		}
	else	{	
		ooptr = optr = "\0";
		}
	linefeed(h);

	fprintf(h,"%s %s%s(%s) : %c",
		__abal_keyword_proc,
		iptr->Contents.name,__abal_method_action,
		optr,0x0025);
		linefeed(h);
	abal_dcl(h,"\0","x",_ABAL_WORD,2,0,0,NULL);
	abal_dcl(h,"\0","y",_ABAL_WORD,2,0,0,NULL);
	indent(h,1); fprintf(h,"x=MouseColumn"); linefeed(h);
	indent(h,1); fprintf(h,"y=MouseRow");    linefeed(h);
	indent(h,1); fprintf(h,"Repeat");	 linefeed(h); 
		abal_gosub(h,"&getevent",2);
		abal_widget_function(h,__abal_visual_freeze,2); fprintf(h,")"); linefeed(h);
		indent(h,2);
		if (( Abal_Config.generate_program )
		&&  ( Abal_Config.generate_overlay ))
			fprintf(h,"Status = %sHide(%s)",Abal_Config.cname,ooptr);
		else	fprintf(h,"%sHide()",Abal_Config.cname);
		linefeed(h);
		indent(h,2); fprintf(h,"x_%s += (MouseColumn-x)",iptr->Contents.name); linefeed(h);
		indent(h,2); fprintf(h,"x=MouseColumn"); linefeed(h);
		indent(h,2); fprintf(h,"if (x_%s < 0) :: x_%s = 0 :: Endif",iptr->Contents.name,iptr->Contents.name); linefeed(h);
		indent(h,2); fprintf(h,"y_%s += (MouseRow-y)",iptr->Contents.name); linefeed(h);
		indent(h,2); fprintf(h,"y=MouseRow");    linefeed(h);
		indent(h,2); fprintf(h,"if (y_%s < 0) :: y_%s = 0 :: Endif",iptr->Contents.name,iptr->Contents.name); linefeed(h);
		/* Recalculate coordinates */
		/* ----------------------- */
		if ((fptr=iptr->parent) != (struct form_control *)0) {
			for (	wptr=fptr->first;
				wptr != (struct form_item *) 0; 
				wptr = wptr->next )  {
				if ((!( wptr->Contents.w  ))
				||  (!( wptr->Contents.h  )))
					continue;
				if (iptr == wptr)
					continue;
				if (( wptr->Contents.events->xo_create & _EVENT_IS_FOCUS ) 
				||  (is_xy_modif(wptr))) {
					if (( wptr->Contents.style & _FRAME_TYPE ) == _RADIO_FRAME ) {
						indent(h,2);
						fprintf(h,"x%u_%s=%s",wptr->Contents.radio,wptr->Contents.name,widget_x_position(wptr,1));
						linefeed(h);
						indent(h,2);
						fprintf(h,"y%u_%s=%s",wptr->Contents.radio,wptr->Contents.name,widget_y_position(wptr,1));
						linefeed(h);
						}
					else	{
						indent(h,2);
						fprintf(h,"x_%s=%s",wptr->Contents.name,widget_x_position(wptr,1));
						linefeed(h);
						indent(h,2);
						fprintf(h,"y_%s=%s",wptr->Contents.name,widget_y_position(wptr,1));
						linefeed(h);
						}
					}
				}
			}
		indent(h,2);
		if (( Abal_Config.generate_program )
		&&  ( Abal_Config.generate_overlay ))
			fprintf(h,"Status = %sShow(%s)",Abal_Config.cname,ooptr);
		else	fprintf(h,"%sShow()",Abal_Config.cname);
		linefeed(h);
		abal_widget_function_thaw(h,iptr,2);
	indent(h,1); fprintf(h,"Until (%s = _MIMO_UP)",__abal_mouse_type);
	linefeed(h);

	abal_returni(h,-1,1);

	fprintf(h,"&getevent");
	linefeed(h);
	indent(h,1); fprintf(h,"While(VisualKey(1) <> 256) :: Wend");
	linefeed(h); 
	indent(h,1); fprintf(h,"Status = VisualEvent(MouseEvent)");
	linefeed(h); 	
	indent(h,1); fprintf(h,__abal_keyword_return);
	linefeed(h); 	

	abal_endproc(h);
	return;

}



	
public	void	abal_scrollbar_driver( FILE * h, struct form_item * iptr )
{
	char	*	eptr;
	int		l;
	char 	*	mode;
	char 	*	item;
	char	*	optr;

	if (!( use_visual_interface( iptr->parent,1 ) ))
		return;

	if ( iptr->Contents.w > iptr->Contents.h ) {
		item = "Column";
		mode = "x"; /* horizontal */
		}
	else	{
		item = "Row";
		mode = "y"; /* vertical	*/
		}

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = __abal_overlay_object;
	else	optr = "\0";

	linefeed(h);

	fprintf(h,"%s %s%s(%s) : %c ",
		__abal_keyword_proc,
		iptr->Contents.name,__abal_method_action,
		optr,0x0025);
		linefeed(h);
	
	abal_dcl(h,"to",mode,_ABAL_WORD,0,0,0,NULL);
	abal_dcl(h,"at",mode,_ABAL_WORD,0,0,0,NULL);
	abal_endloc(h,0);

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = "o";
	else	optr = "\0";

	/* ---------------------------- */
	/* ScrollButton Click Detection */
	/* ---------------------------- */
	if ( iptr->Contents.align & (_A_LEFT | _A_RIGHT) ) {
		abal_scrollbutton_driver(h,iptr);
		}
		
	/* ------------------------- */
	/* Scroll Bar Drag Operation */
	/* ------------------------- */
	linefeed(h); indent(h,1); fprintf(h,"at%s = Mouse%s",mode,item);
	linefeed(h); 
	abal_scrollbar_widget(h,iptr,1,0x0100);
	indent(h,1); fprintf(h,"Repeat");
	linefeed(h); 
	abal_gosub(h,"&getevent",2);
	indent(h,2); fprintf(h,"Select (%s)",__abal_mouse_button); linefeed(h);
	indent(h,2); fprintf(h,"Case _MIMO_LEFT,_MIMO_RIGHT"); linefeed(h);
	indent(h,2); fprintf(h,"at%s = v_%s",mode,iptr->Contents.name);
	linefeed(h); 
	indent(h,2); 
	fprintf(h,"v_%s = ",iptr->Contents.name);
	if ( iptr->Contents.w > iptr->Contents.h ) {
		switch ( iptr->Contents.align & 0x0007 ) {
			case	_A_NONE		:
			case	_A_JUSTIFY	:
				fprintf(h,"(((%s - (%s)) * m_%s) / %s)",
					__abal_mouse_column,
					widget_x_position(iptr,0),
					iptr->Contents.name,
					widget_w_dimension(iptr,0));
				break;
			case	_A_CENTER	:
				fprintf(h,"(((%s - ((%s)+%s)) * m_%s) / (%s - (2 * %s)))",
					__abal_mouse_column,
					widget_x_position(iptr,0),
					widget_h_dimension(iptr,0),
					iptr->Contents.name,
					widget_w_dimension(iptr,0),
					widget_h_dimension(iptr,0));
				break;
			case	_A_LEFT  	:
				fprintf(h,"(((%s - ((%s)+%s)) * m_%s) / (%s - %s))",
					__abal_mouse_column,
					widget_x_position(iptr,0),
					widget_h_dimension(iptr,0),
					iptr->Contents.name,
					widget_w_dimension(iptr,0),
					widget_h_dimension(iptr,0));
				break;
			case	_A_RIGHT	:
				fprintf(h,"(((%s - (%s)) * m_%s) / (%s - %s))",
					__abal_mouse_column,
					widget_x_position(iptr,0),
					iptr->Contents.name,
					widget_w_dimension(iptr,0),
					widget_h_dimension(iptr,0));
				break;
			default			:
				fprintf(h,"v_%s",iptr->Contents.name);
			}
		}
	else	{
		switch ( iptr->Contents.align & 0x0007 ) {
			case	_A_NONE		:
			case	_A_JUSTIFY	:
				fprintf(h,"(((%s - (%s)) * m_%s) / %s )",
					__abal_mouse_row,
					widget_y_position(iptr,0),
					iptr->Contents.name,
					widget_h_dimension(iptr,0));
				break;
			case	_A_CENTER	:
				fprintf(h,"(((%s - ((%s)+%s)) * m_%s) / (%s - (2 * %s)))",
					__abal_mouse_row,
					widget_y_position(iptr,0),
					widget_w_dimension(iptr,0),
					iptr->Contents.name,
					widget_h_dimension(iptr,0),
					widget_w_dimension(iptr,0));
				break;
			case	_A_LEFT		:
				fprintf(h,"(((%s - ((%s)+%s)) * m_%s) / (%s - %s))",
					__abal_mouse_row,
					widget_y_position(iptr,0),
					widget_w_dimension(iptr,0),
					iptr->Contents.name,
					widget_h_dimension(iptr,0),
					widget_w_dimension(iptr,0));
				break;
			case	_A_RIGHT	:
				fprintf(h,"(((%s - (%s)) * m_%s) / (%s - %s))",
					__abal_mouse_row,
					widget_y_position(iptr,0),
					iptr->Contents.name,
					widget_h_dimension(iptr,0),
					widget_w_dimension(iptr,0));
				break;
			default			:
				fprintf(h,"v_%s",iptr->Contents.name);
			}
		}	
	linefeed(h); 
	abal_gosub(h,"&limits",2);
	indent(h,2); fprintf(h,"if ( v_%s <> at%s)",iptr->Contents.name,mode);
	linefeed(h); 
	abal_gosub(h,"&payload",3);
	abal_scrollbar_widget(h,iptr,3,0x0100);
	abal_endif(h,2);
	indent(h,2); fprintf(h,"EndSel"); linefeed(h);
	indent(h,1); fprintf(h,"Until (%s = _MIMO_UP)",__abal_mouse_type);
	linefeed(h);
	indent(h,2); fprintf(h,"Select (%s)",__abal_mouse_button); linefeed(h);
	indent(h,2); fprintf(h,"Case _MIMO_UPWHEEL"); linefeed(h);
		indent(h,2); fprintf(h,"v_%s -= (l_%s/2)",iptr->Contents.name,iptr->Contents.name);
		linefeed(h);
		abal_gosub(h,"&limits",2);
		abal_gosub(h,"&payload",2);
	indent(h,2); fprintf(h,"Case _MIMO_DOWNWHEEL"); linefeed(h);
		indent(h,2); fprintf(h,"v_%s += (l_%s/2)",iptr->Contents.name,iptr->Contents.name);
		linefeed(h);
		abal_gosub(h,"&limits",2);
		abal_gosub(h,"&payload",2);
	indent(h,2); fprintf(h,"Default "); linefeed(h);
		abal_gosub(h,"&payload",2);
	indent(h,2); fprintf(h,"EndSel"); linefeed(h);
	abal_scrollbar_widget(h,iptr,1,0);
	abal_returni(h,-1,1);
	linefeed(h);

	/* ----------------------------------------------- */
	/* Event Collection Routines for all callers above */
	/* ----------------------------------------------- */
	if ( iptr->Contents.align & 3 ) {
		fprintf(h,"&awaitup");
		linefeed(h);
		indent(h,1); fprintf(h,"Repeat");
		linefeed(h); 
		indent(h,2); fprintf(h,"%s &getevent",__abal_keyword_gosub);
		linefeed(h); 
		indent(h,1); fprintf(h,"Until (%s = _MIMO_UP)",__abal_mouse_type);
		linefeed(h);
		indent(h,1); fprintf(h,__abal_keyword_return);
		linefeed(h);
		}

	fprintf(h,"&getevent");
	linefeed(h);
	indent(h,1); fprintf(h,"While(VisualKey(1) <> 256) :: Wend");
	linefeed(h); 
	indent(h,1); fprintf(h,"Status = VisualEvent(MouseEvent)");
	linefeed(h); 	
	indent(h,1); fprintf(h,__abal_keyword_return);
	linefeed(h);

	/* -------------------------------------------------- */
	/* Limit Checking Routines : Used by Buttons and Drag */
	/* -------------------------------------------------- */
	fprintf(h,"&limits");
	linefeed(h);
	indent(h,1); fprintf(h,"if (v_%s < 0)",iptr->Contents.name);
	linefeed(h); 
	indent(h,2); fprintf(h,"v_%s = 0",iptr->Contents.name);
	linefeed(h); 
	indent(h,1); fprintf(h,"%s:: if (v_%s > (m_%s-l_%s))",
			__abal_keyword_else,iptr->Contents.name,iptr->Contents.name,iptr->Contents.name);
	linefeed(h); 
	indent(h,3); fprintf(h,"v_%s = (m_%s-l_%s)",iptr->Contents.name,iptr->Contents.name,iptr->Contents.name);
	linefeed(h); 
	abal_endif(h,2);
	abal_endif(h,1);
	indent(h,1); fprintf(h,__abal_keyword_return);
	linefeed(h);

	/* ---------------------------------------------------- */
	/* Charge Utile : Payload : Gosub from Buttons and Drag */
	/* ---------------------------------------------------- */
	fprintf(h,"&payload");
	linefeed(h);
	if ( method_is_valid(iptr->Contents.events->on_event) ) 
		abal_invoke_widget_event(h,iptr,0,1);

	else	{
		/* standard payload : activate global show */
		indent(h,1);
		fprintf(h,"%s = %s%s(%s)",
			__abal_keyword_status,Abal_Config.cname,__abal_method_show,optr);
		linefeed(h);
		}
	indent(h,1); fprintf(h,__abal_keyword_return);
	linefeed(h);
	abal_endproc(h);
	return;
}

public	void	abal_error_trap( FILE * h, int i, int level )
{
	indent(h,i);
	fprintf(h,"On Local %s Goto &elabel%u,Status",__abal_keyword_error,level);
	linefeed(h);
	return;
}

public	void	abal_special_method( FILE * h, struct  forms_method * mptr, int i, int mode )
{
	int	l;
	char *	optr="\0";
	char *	qname;

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = "o";
	else	optr = "\0";


	if (!( qname = resolve_method_name( mptr->name ) ))
		return;

	if ( mptr->type & _METHOD_FUNCTION ) {
		/* Function Method */
		/* --------------- */
		indent(h,i);
		if (!( mode ))
			fprintf(h,"%s(%s)",qname,optr);
		else	fprintf(h,"%s(%s,%u)",qname,optr,mode);
		linefeed(h);
		}
	else	{
		/* Inline Method */
		/* ------------- */
		if (( l = method_is_valid( mptr->text )) != 0) {
			abal_pragma_enter(h,"this",qname);
			abal_method_body(h,mptr->text,l,qname,i);
			abal_pragma_leave(h,"this",qname);
			}
		linefeed(h);
		}
	return;
}

public	void	return_abal_special_method( FILE * h, struct  forms_method * mptr, int i )
{
	int	l;
	char *	optr="\0";
	char *	qname;

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = "o";
	else	optr = "\0";

	if (!( qname = resolve_method_name( mptr->name ) ))
		return;

	if ( mptr->type & _METHOD_FUNCTION ) {
		/* Function Method */
		/* --------------- */
		indent(h,i);
		fprintf(h,"KeyCode = %s(%s)",qname,optr);
		linefeed(h);
		}
	else	{
		/* Inline Method */
		/* ------------- */
		if (( l = method_is_valid( mptr->text )) != 0) {
			abal_pragma_enter(h,"this",qname);
			abal_method_body(h,mptr->text,l,qname,i);
			abal_pragma_leave(h,"this",qname);
			}
		linefeed(h);
		}
	return;
}

public	void	abal_error_abort( FILE * h, int i, int level )
{
	int	l;
	struct  forms_method * mptr;
	struct	form_control * fptr;
	fprintf(h,"&elabel%u",level);
	linefeed(h);
	indent(h,i);
	fprintf(h,"On Local %s Abort",__abal_keyword_error);
	linefeed(h);
	if (( fptr = Context.Form ) != (struct form_control*) 0) {
		if ((mptr = fptr->StandardError) != (struct forms_method *) 0 ) {
			abal_special_method(h, mptr, i, 0 );
			}
		}
	return;
}
public	void	abal_error_return( FILE * h, char * vptr, int level )
{
	abal_error(h,vptr,level);
	return;
}

public	int	abal_php_event(  FILE * h, struct form_item * iptr )
{
	if (( iptr->Contents.events->on_event )
	&&  ( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION ))
		abal_method(h,iptr,iptr->Contents.name,__abal_method_event,iptr->Contents.events->on_event);
	return;
}

public	void	abal_event_trigger( FILE * h, struct form_item * iptr )
{
	if (( iptr->Contents.events->on_event )
	&&  ( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION )) {
		abal_method(h,iptr,iptr->Contents.name,__abal_method_event,iptr->Contents.events->on_event);
		return(1);
		}
	else	return(0);
}

public	int	forms_model_is_document( char * nptr )
{
	struct	form_control * fptr;

	if (!( method_is_valid( nptr ) ))
		return(0);
	else if (!( nptr = allocate_string( nptr )))
		return(0);
	else if (!( nptr = enforce_extension( nptr, XML_EXTENSION ) ))
		return(0);
	else if (!( fptr = resolve_form_control( nptr ) )) {
		liberate(nptr);
		return(0);
		}
	else	{
		liberate(nptr);
		switch ( fptr->formflags & _FORM_TYPE_FLAGS ) {
			case	_FORM_TYPE_DIALOG	:
			case	_FORM_TYPE_EVENT 	:
				return(0);
			default				:
				return(1);
			}
		}
}

public	void	abal_program_trigger( FILE * h, struct form_item * iptr )
{
	char	*	nptr;
	char	*	eptr;
	int		l;
	int		trapper=1;
	char	*	optr;

	struct	form_control * fptr;

	if ((( fptr = iptr->parent ) != (struct form_control *) 0)
	&&  ( fptr->language == _GENERATE_HTML )) {
	     	if ( iptr->Contents.datatype != _WIDGET_SYSTEM ) {
			web_agent_program_trigger(h,fptr,iptr);
			return;
			}
		}
	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = __abal_overlay_object;
	else	optr = "\0";

	linefeed(h);
	fprintf(h,"%s %s%s(%s) : %c ",
		__abal_keyword_proc,
		iptr->Contents.name,__abal_method_event,
		optr,0x0025);
	linefeed(h);

	abal_dcl(h,"h_",iptr->Contents.name,_ABAL_WORD,2,0,0,NULL);
	abal_dcl(h,"e_",iptr->Contents.name,_ABAL_WORD,2,0,0,NULL);

	abal_endloc(h,0);

	abal_error_trap(h,1,1);

	if ((l = method_is_valid((eptr = iptr->Contents.events->on_event))) != 0) {
		abal_pragma_enter(h,iptr->Contents.name,__abal_method_event);
		abal_method_body(h,eptr,l,iptr->Contents.name,1);
		abal_pragma_leave(h,iptr->Contents.name,__abal_method_event);
		}

	if ( fptr->language  != _GENERATE_PHP ) {
	
		indent(h,1);
		fprintf(h,"h_%s=Event(77)",iptr->Contents.name);
		linefeed(h);	
		indent(h,1);

		if (!( nptr = iptr->Contents.format ))
			nptr = iptr->Contents.name;

		if ( *nptr != _UNQUOTED_STRING ) {
			if (!( nptr = allocate_string( nptr ) )) {
				fprintf(h,"allocation failure");
				return;
				}
		     	if ( iptr->Contents.datatype != _WIDGET_SYSTEM ) {
				if (!( nptr = enforce_extension( nptr, AT_EXTENSION ) )) {
					fprintf(h,"allocation failure");
					return;
					}
				}
			fprintf(h,"%s=h_%s,%c%s%c:Next,e_%s",__abal_keyword_assign,
				iptr->Contents.name,__QUOTE,nptr,__QUOTE,iptr->Contents.name);
			liberate( nptr );
			}
		else if (( iptr->Contents.datatype == _WIDGET_LOADGO ) 
		     ||  ( iptr->Contents.datatype == _WIDGET_CHAIN  )){
			fprintf(h,"%s=h_%s,Parse(",__abal_keyword_assign,iptr->Contents.name);
			variable_value(h,(nptr+1));
			fprintf(h,",/000F)!%c.at%c:Next,e_%s",__QUOTE,__QUOTE,iptr->Contents.name);
			}
		else	{
			/* SYSTEM et TASK */
			fprintf(h,"%s=h_%s,",__abal_keyword_assign,iptr->Contents.name);
			variable_value(h,(nptr+1));
			fprintf(h,":Next,e_%s",iptr->Contents.name);
			}

		linefeed(h);

		if ( iptr->Contents.datatype == _WIDGET_CHAIN ) {
			indent(h,1);
			fprintf(h,"if (Len$(b_%s) <> 0)",iptr->Contents.name);
			linefeed(h);
				indent(h,2);
				fprintf(h,"%s=h_%s,b_%s:Next,e_%s",
					"Chain",
					iptr->Contents.name,iptr->Contents.name,iptr->Contents.name);
				linefeed(h);
			abal_else(h,1);
				indent(h,2);
				fprintf(h,"%s=h_%s:Next,e_%s",
					"Chain",
					iptr->Contents.name,iptr->Contents.name);
				linefeed(h);
			abal_endif(h,1);
			indent(h,1); fprintf(h,"Stop"); linefeed(h);	
			}
		else if (( iptr->Contents.datatype == _WIDGET_LOADGO ) 
#ifdef	ABAL32A
		     ||  ( iptr->Contents.datatype == _WIDGET_TASK   )
#endif
		     ||  ( iptr->Contents.datatype == _WIDGET_SYSTEM )) {
			indent(h,1);
			fprintf(h,"if (Len$(b_%s) <> 0)",iptr->Contents.name);
			linefeed(h);
				indent(h,2);
				fprintf(h,"%s=h_%s,b_%s:Next,e_%s",
					"Load.Go",
					iptr->Contents.name,iptr->Contents.name,iptr->Contents.name);
				linefeed(h);
			abal_else(h,1);
				indent(h,2);
				fprintf(h,"%s=h_%s:Next,e_%s",
				"Load.Go",
				iptr->Contents.name,iptr->Contents.name);
				linefeed(h);
			abal_endif(h,1);
			}

		indent(h,1);
		fprintf(h,"Event(77)=h_%s",iptr->Contents.name);
		linefeed(h);	
	}

	abal_error_abort(h,1,1);

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = "o";
	else	optr = "\0";
	indent(h,1);
	fprintf(h,"Status = %s%s(%s)",Abal_Config.cname,__abal_method_show,optr);
	linefeed(h);
	abal_returni(h,-1,1);
	abal_endproc(h);
	return;
}

#ifdef	ABAL32A
public	void	abal_task_trigger( FILE * h, struct form_item * iptr )
{
	char	*	nptr;
	char	*	eptr;
	int		l;
	int		trapper=1;
	char	*	optr;

	struct	form_control * fptr;

	if ((( fptr = iptr->parent ) != (struct form_control *) 0)
	&&  ( fptr->language == _GENERATE_HTML )) {
	     	if ( iptr->Contents.datatype != _WIDGET_TASK ) {
			web_agent_program_trigger(h,fptr,iptr);
			return;
			}
		}
	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = __abal_overlay_object;
	else	optr = "\0";

	linefeed(h);
	fprintf(h,"%s %s%s(%s) : %c ",
		__abal_keyword_proc,
		iptr->Contents.name,__abal_method_event,
		optr,0x0025);
	linefeed(h);

	abal_dcl(h,"h_",iptr->Contents.name,_ABAL_WORD,2,0,0,NULL);
	abal_dcl(h,"e_",iptr->Contents.name,_ABAL_WORD,2,0,0,NULL);

	abal_endloc(h,0);

	abal_error_trap(h,1,1);

	if ((l = method_is_valid((eptr = iptr->Contents.events->on_event))) != 0) {
		abal_pragma_enter(h,iptr->Contents.name,__abal_method_event);
		abal_method_body(h,eptr,l,iptr->Contents.name,1);
		abal_pragma_leave(h,iptr->Contents.name,__abal_method_event);
		}

	indent(h,1);
	fprintf(h,"h_%s=Event(77)",iptr->Contents.name);
	linefeed(h);	
	indent(h,1);

	if (!( nptr = iptr->Contents.format ))
		nptr = iptr->Contents.name;

	if ( *nptr != _UNQUOTED_STRING ) {
		if (!( nptr = allocate_string( nptr ) )) {
			fprintf(h,"allocation failure");
			return;
			}
	     	if (( iptr->Contents.datatype != _WIDGET_SYSTEM ) 
#ifdef	ABAL32A
	     	&&  ( iptr->Contents.datatype != _WIDGET_TASK   )
#endif
			) {
			if (!( nptr = enforce_extension( nptr, AT_EXTENSION ) )) {
				fprintf(h,"allocation failure");
				return;
				}
			}
		fprintf(h,"%s=h_%s,%c%s%c:Next,e_%s",__abal_keyword_assign,
			iptr->Contents.name,__QUOTE,nptr,__QUOTE,iptr->Contents.name);
		liberate( nptr );
		}
	else	{
		fprintf(h,"%s=h_%s,",__abal_keyword_assign,iptr->Contents.name);
		variable_value(h,(nptr+1));
		fprintf(h,":Next,e_%s",iptr->Contents.name);
		}

	linefeed(h);

	if ( iptr->Contents.datatype == _WIDGET_CHAIN ) {
		indent(h,1);
		fprintf(h,"if (Len$(b_%s) <> 0)",iptr->Contents.name);
		linefeed(h);
			indent(h,2);
			fprintf(h,"%s=h_%s,b_%s:Next,e_%s",
				"Chain",
				iptr->Contents.name,iptr->Contents.name,iptr->Contents.name);
			linefeed(h);
		abal_else(h,1);
			indent(h,2);
			fprintf(h,"%s=h_%s:Next,e_%s",
				"Chain",
				iptr->Contents.name,iptr->Contents.name);
			linefeed(h);
		abal_endif(h,1);
		indent(h,1); fprintf(h,"Stop"); linefeed(h);	
		}
	else if (( iptr->Contents.datatype == _WIDGET_LOADGO ) 
#ifdef	ABAL32A
	     ||  ( iptr->Contents.datatype == _WIDGET_TASK   )
#endif
	     ||  ( iptr->Contents.datatype == _WIDGET_SYSTEM )) {
		indent(h,1);
		fprintf(h,"if (Len$(b_%s) <> 0)",iptr->Contents.name);
		linefeed(h);
			indent(h,2);
			fprintf(h,"%s=h_%s,b_%s","Load.Go",iptr->Contents.name,iptr->Contents.name);
#ifdef	ABAL32A
			if ( iptr->Contents.datatype == _WIDGET_TASK   ) {
				fprintf(h,",(TASK)");
				}
#endif
			fprintf(h,":Next,e_%s",iptr->Contents.name);
			linefeed(h);
		abal_else(h,1);
			indent(h,2);
			fprintf(h,"%s=h_%s","Load.Go",iptr->Contents.name);
#ifdef	ABAL32A
			if ( iptr->Contents.datatype == _WIDGET_TASK   ) {
				fprintf(h,",(TASK)");
				}
#endif
			fprintf(h,":Next,e_%s",iptr->Contents.name);
			linefeed(h);
		abal_endif(h,1);
		}

	indent(h,1);
	fprintf(h,"Event(77)=h_%s",iptr->Contents.name);
	linefeed(h);	

	abal_error_abort(h,1,1);

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = "o";
	else	optr = "\0";
	indent(h,1);
	fprintf(h,"Status = %s%s(%s)",Abal_Config.cname,__abal_method_show,optr);
	linefeed(h);
	abal_returni(h,-1,1);
	abal_endproc(h);
	return;
}
#endif


public	void	abal_overlay_trigger( FILE * h, struct form_item * iptr )
{
	char	*	eptr;
	int		l;
	int		trapper=1;
	char	*	optr;
	char	*	sptr;
	struct	form_control * fptr;

	if ((( fptr = iptr->parent ) != (struct form_control *) 0)
	&&  ( fptr->language == _GENERATE_HTML )) {
	     	if ( iptr->Contents.datatype != _WIDGET_SYSTEM ) {
		     	if ( iptr->Contents.datatype != _WIDGET_OVERLAY ) {
				web_agent_program_trigger(h,fptr,iptr);
				return;
				}
			else if (!( method_is_valid((sptr = iptr->Contents.format)) ))
				return;
			else if ( *sptr != _UNQUOTED_STRING ) {
				if (!( forms_model_is_document( iptr->Contents.format ) )) {
					web_agent_program_trigger(h,fptr,iptr);
					return;
					}
				}
			}
		}
	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = __abal_overlay_object;
	else	optr = "\0";

	linefeed(h);
	fprintf(h,"%s %s%s(%s) : %c ",
		__abal_keyword_proc,
		iptr->Contents.name,__abal_method_event,
		optr,0x0025);
	linefeed(h);

	/* needs to calculate the total method count */
	/* ----------------------------------------- */
	instance_widget_overlay(h,iptr,overlay_interface_count(iptr));
	abal_endloc(h,0);

	abal_error_trap(h,1,1);

	if ((l = method_is_valid((eptr = iptr->Contents.events->on_event))) != 0) {
		abal_pragma_enter(h,iptr->Contents.name,__abal_method_event);
		abal_method_body(h,eptr,l,iptr->Contents.name,1);
		abal_pragma_leave(h,iptr->Contents.name,__abal_method_event);
		}

	/* ATTACH :: O.ONEXEC :: DETACH */
	/* ---------------------------- */
	attach_widget_overlay(h,iptr);
	abal_error_trap(h,1,2);
	invoke_widget_overlay(h,iptr,_OVL_ONEXEC);
	abal_error_abort(h,1,2);
	detach_widget_overlay(h,iptr);
	abal_error_abort(h,1,1);

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = "o";
	else	optr = "\0";
	indent(h,1);
	fprintf(h,"Status = %s%s(%s)",Abal_Config.cname,__abal_method_show,optr);
	linefeed(h);
	abal_returni(h,-1,1);
	abal_endproc(h);
	return;
}

public	int	abal_forward_method( FILE * h,struct form_item * iptr, char * mptr,  char * nptr,  char * eptr )
{
	struct	form_control * fptr;
	int	status=0;
	int	l;
	int	n;
	int	i;
	char	*	optr;

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = __abal_overlay_object;
	else	optr = "\0";
	if (!( method_is_valid( eptr) ))
		return(0);
	else if (( l=strlen(eptr)) > 0 ) {
		if (( iptr != (struct form_item *) 0)
		&&  ( iptr->Contents.access & _WIDGET_PUBLIC )
		&&  ((fptr = iptr->parent) != (struct form_control *) 0)
		&&  ( fptr->isoverlay )
		&&  (!( fptr->isprogram ))) {
			fprintf(h,"%s %s %s%s%s(%s) : %c ",
				__abal_keyword_forward,__abal_keyword_proc,
				fptr->identifier,mptr,nptr,optr,0x0025);
			}
		else	{
			fprintf(h,"%s %s %s%s(%s) : %c ",
				__abal_keyword_forward,__abal_keyword_proc,
				mptr,nptr,optr,0x0025);
			}
		linefeed(h);
		return(1);
		}
	else	return(0);

}

public	int	abal_forward_onmethod( FILE * h,struct form_item * iptr, char * mptr,  char * nptr, int result )
{
	struct	form_control * fptr;
	int	status=0;
	int	l;
	int	n;
	int	i;
	char	*	optr;

	if (!( iptr ))
		return(0);
	else if (!( fptr = iptr->parent ))
		return(0);
	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = __abal_overlay_object;
	else	optr = "\0";
	if ((iptr->Contents.access & _WIDGET_PUBLIC) && (fptr->isoverlay) && (!( fptr->isprogram))) {
		fprintf(h,"%s %s %s%s%s(%s)",
			__abal_keyword_forward,__abal_keyword_proc,
			fptr->identifier,mptr,nptr,optr);
		}
	else	{
		fprintf(h,"%s %s %s%s(%s)",
			__abal_keyword_forward,__abal_keyword_proc,
			mptr,nptr,optr);
		}
	/* Return Result */
	/* ------------- */
	if ( result ) {	fprintf(h," : %c ",0x0025); }
	linefeed(h);
	return(1);
}

public	int	abal_extern_onmethod( FILE * h,struct form_item * iptr, char * mptr,  char * nptr, int mode )
{
	struct	form_control * fptr;
	int	status=0;
	int	l;
	int	n;
	int	i;
	char	*	optr;

	if (!( iptr ))
		return(0);
	else if (!( fptr = iptr->parent ))
		return(0);
	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = __abal_overlay_object;
	else	optr = "\0";
	if ((iptr->Contents.access & _WIDGET_PUBLIC ) && (fptr->isoverlay) && (!( fptr->isprogram))) {
		fprintf(h,"%s %s %s%s%s(%s)",
			__abal_keyword_extern,__abal_keyword_proc,
			fptr->identifier,mptr,nptr,optr);
		}
	else	{
		fprintf(h,"%s %s %s%s(%s)",
			__abal_keyword_extern,__abal_keyword_proc,
			mptr,nptr,optr);
		}
	if ( mode ) { fprintf(h," : %c ",0x0025); }
	linefeed(h);
	return(1);
}

private	int	detect_model_object( char * mptr )
{
	char *	nptr;
	FILE * 	hptr;
	struct	form_control * fptr;

	if ((fptr = locate_form_control( mptr )) != (struct form_control *) 0) {
		if (!(fptr->isoverlay))
			return( 0 );
		else if (!( fptr->isprogram ))
			return(1);
		else	return(0);
		}
	else if (!( nptr = allocate_string( mptr )))
		return(0);
	else if (!( nptr = enforce_extension( nptr, MODEL_EXTENSION ) ))
		return(0);
	else if (( hptr = fopen( nptr, "rb" )) != (FILE *) 0) {
		liberate( nptr );
		fclose(hptr);
		return(1);
		}
	liberate( nptr );
	if (!( nptr = allocate_string( mptr )))
		return(0);
	else if (!( nptr = enforce_extension( nptr, XML_EXTENSION ) ))
		return(0);
	else if (( hptr = fopen( nptr, "r" )) != (FILE *) 0) {	
		liberate( nptr );
		fclose(hptr);
		return(2);
		}
	liberate( nptr );
	return(0);
}

public	void	abal_extern_methods(FILE * h, struct form_control * fptr )
{
	struct	form_item *	iptr;
	FILE 	*	hptr=(FILE *)0;
	char	*	nptr=(char *)0;
	char	*	mptr=(char *)0;
	int		i=0;
	char	*	lmptr;
	
	if (!( fptr ))
		return;
	else	fptr->modext = 0;

	for ( 	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if (( iptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME )
			continue;
		else if ( include_modext_data(h, iptr ) ) {
			fptr->modext=1;
			break;
			}
		else	continue;
		}

	if (( mptr = fptr->construction ) != (char *) 0)
		if (!( mptr = allocate_string( mptr )))
			return;

	if (!( mptr = forms_modules( fptr, mptr ) ))
		return;
	else	lmptr = mptr;

	while  (( *mptr == ' '  ) 
	|| 	( *mptr == '\t' )
	|| 	( *mptr == '\r' )
	|| 	( *mptr == '\n' ))
		mptr++;

	while ( *mptr != 0 ) {
		for ( i=0; *(mptr+i) != 0; i++ ) {
			if ( *(mptr+i) == ' ' )
				break;
			else if ( *(mptr+i) == '\t' )
			 	break;
			else if ( *(mptr+i) == '\r' )
				break;
			else if ( *(mptr+i) == '\n' )
				break;
			}
		if (!( i )) 
			break;
		else if ( *(mptr+i) != 0 ) {
			*(mptr+i) = 0;
			i++;
			}
		if ( detect_model_object( mptr ) ) {
			if (!( nptr = allocate_string( mptr )))
				break;
			else if (!( nptr = enforce_extension( nptr, EXT_EXTENSION ) ))
				break;
			abal_include(h, nptr );
			liberate( nptr );
			}
		mptr += i;
		while ( *mptr ) {
			switch ( *mptr ) {
				case	' '	:
				case	'\r'	:
				case	'\n'	:
				case	'\t'	:
					mptr++;
					continue;
				}
			break;
			}
		}
	if ( lmptr )
		liberate( lmptr );
	return;
}

public	void	abal_forward_methods(FILE * h, struct form_control * fptr )
{
	int	public_widgets=0;
	struct	form_item * iptr;
	linefeed(h);
	abal_comment(h,"Public Widget Interface Methods",0);
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w))
		&&  (!( iptr->Contents.w)))
			continue;
		else if (!( iptr->Contents.access & _WIDGET_PUBLIC))
			continue;
		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_EDIT_FRAME	:
			case	_BUTTON_FRAME	:
			case	_RADIO_FRAME	:
			case	_CHECK_FRAME	:
			case	_SWITCH_FRAME	:
			case	_SCROLL_FRAME	:
			case	_PROGRESS_FRAME	:
			case	_SELECT_FRAME	:
				abal_forward_signature( h, iptr,__abal_method_set);
				abal_forward_signature( h, iptr,__abal_method_get);
				public_widgets++;
			}
		if (( is_named_edit  ( iptr ) )
		||  ( is_named_select( iptr ) ))
			abal_forward_onmethod(h,iptr,iptr->Contents.name,__abal_method_onshow,0);
		if ( iptr->Contents.events->xo_create & _EVENT_IS_FUNCTION )
			abal_forward_method(h,iptr,iptr->Contents.name,__abal_method_create,iptr->Contents.events->on_create);
		if ( iptr->Contents.events->xo_remove & _EVENT_IS_FUNCTION )
			abal_forward_method(h,iptr,iptr->Contents.name,__abal_method_remove,iptr->Contents.events->on_remove);
		if ( iptr->Contents.events->xo_show & _EVENT_IS_FUNCTION )
			abal_forward_method(h,iptr,iptr->Contents.name,__abal_method_show,iptr->Contents.events->on_show);
		if ( iptr->Contents.events->xo_hide & _EVENT_IS_FUNCTION )
			abal_forward_method(h,iptr,iptr->Contents.name,__abal_method_hide,iptr->Contents.events->on_hide);
		if ( iptr->Contents.events->xo_get_focus & _EVENT_IS_FUNCTION )
			abal_forward_method(h,iptr,iptr->Contents.name,__abal_method_get_focus,iptr->Contents.events->on_get_focus);
		if ( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION )
			abal_forward_method(h,iptr,iptr->Contents.name,__abal_method_lose_focus,iptr->Contents.events->on_lose_focus);
		if ( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION )
			abal_forward_method(h,iptr,iptr->Contents.name,__abal_method_event,iptr->Contents.events->on_event);
		}
	linefeed(h);
	if ( public_widgets ) {
		abal_forward_signatures( h, fptr,__abal_method_set);
		abal_forward_signatures( h, fptr,__abal_method_get);
		}
	if ( fptr->language != _GENERATE_HTML ) {
		if (!( fptr->isoverlay) || (!( fptr->isprogram))) {
			abal_resize_method_forward(h,fptr,Abal_Config.cname,0);
			}
		}
	abal_comment(h,"Private Widget Interface Methods",0);
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w))
		&&  (!( iptr->Contents.w)))
			continue;
		else if ( iptr->Contents.access & _WIDGET_PUBLIC)
			continue;

		if (( is_named_edit  ( iptr ) )
		||  ( is_named_select( iptr ) ))
			abal_forward_onmethod(h,iptr,iptr->Contents.name,__abal_method_onshow,0);
		if ( iptr->Contents.events->xo_create & _EVENT_IS_FUNCTION )
			abal_forward_method(h,iptr,iptr->Contents.name,__abal_method_create,iptr->Contents.events->on_create);
		if ( iptr->Contents.events->xo_remove & _EVENT_IS_FUNCTION )
			abal_forward_method(h,iptr,iptr->Contents.name,__abal_method_remove,iptr->Contents.events->on_remove);
		if ( iptr->Contents.events->xo_show & _EVENT_IS_FUNCTION )
			abal_forward_method(h,iptr,iptr->Contents.name,__abal_method_show,iptr->Contents.events->on_show);
		if ( iptr->Contents.events->xo_hide & _EVENT_IS_FUNCTION )
			abal_forward_method(h,iptr,iptr->Contents.name,__abal_method_hide,iptr->Contents.events->on_hide);
		if ( iptr->Contents.events->xo_get_focus & _EVENT_IS_FUNCTION )
			abal_forward_method(h,iptr,iptr->Contents.name,__abal_method_get_focus,iptr->Contents.events->on_get_focus);
		if ( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION )
			abal_forward_method(h,iptr,iptr->Contents.name,__abal_method_lose_focus,iptr->Contents.events->on_lose_focus);
		if ( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION )
			abal_forward_method(h,iptr,iptr->Contents.name,__abal_method_event,iptr->Contents.events->on_event);

		}

	/* Scroll bar Specifics */
	/* -------------------- */
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		if ((!( iptr->Contents.w))
		&&  (!( iptr->Contents.w)))
			continue;

		if (( iptr->Contents.style & _FRAME_TYPE ) == _SCROLL_FRAME ) {
			abal_forward_onmethod(h,iptr,iptr->Contents.name,__abal_method_action,1);
			}
		}

	linefeed(h);
	return;
}

private	void	abal_public_signature(FILE * h, struct form_item * iptr, char * methodname )
{
	struct	form_control * fptr;
	if (!( h ))
		return;
	else if (!( iptr ))
		return;
	else if (!( fptr = iptr->parent ))
		return;
	else if (!( methodname ))
		return;
	else	{
		fprintf(h,"%s ",__abal_keyword_extern);
		abal_public_method_signature(h,iptr,fptr->identifier,iptr->Contents.name,methodname);
		return;
		}
}

private	void	abal_forward_signature(FILE * h, struct form_item * iptr, char * methodname )
{
	struct	form_control * fptr;
	if (!( h ))
		return;
	else if (!( iptr ))
		return;
	else if (!( fptr = iptr->parent ))
		return;
	else if (!( methodname ))
		return;
	else	{
		fprintf(h,"%s ",__abal_keyword_forward);
		abal_public_method_signature(h,iptr,fptr->identifier,iptr->Contents.name,methodname);
		return;
		}
}

private	void	abal_forward_signatures(FILE * h, struct form_control * fptr, char * methodname )
{
	if (!( h ))
		return;
	else if (!( fptr ))
		return;
	else if (!( methodname ))
		return;
	else	{
		fprintf(h,"%s ",__abal_keyword_forward);
		abal_public_methods_signature(h,fptr,methodname);
		return;
		}
}


private	void	abal_public_signatures(FILE * h, struct form_control * fptr, char * methodname )
{
	if (!( h ))
		return;
	else if (!( fptr ))
		return;
	else if (!( methodname ))
		return;
	else	{
		fprintf(h,"%s ",__abal_keyword_extern);
		abal_public_methods_signature(h,fptr,methodname);
		return;
		}
}

private	void	abal_public_widget(FILE * h, struct form_item * iptr, char * widgetname,char * methodname, char * methodbody, int mode )
{
	if (!( h ))
		return;
	else if (!( widgetname ))
		return;
	else if (!( methodname ))
		return;
	else if (!( method_is_valid( methodbody ) ))
		return;
	else	{
		abal_extern_onmethod(h,iptr,widgetname,methodname,mode);
		return;
		}
}

public	void	abal_public_widgets(FILE * h, struct form_control * fptr )
{
	int	public_widgets=0;
	struct	form_item * iptr;
	linefeed(h);
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w))
		&&  (!( iptr->Contents.w)))
			continue;
		else if (!( iptr->Contents.access & _WIDGET_PUBLIC))
			continue;
		else	{
			switch ((iptr->Contents.style & _FRAME_TYPE)) {
				case	_EDIT_FRAME	:
				case	_BUTTON_FRAME	:
				case	_RADIO_FRAME	:
				case	_CHECK_FRAME	:
				case	_SWITCH_FRAME	:
				case	_SCROLL_FRAME	:
				case	_PROGRESS_FRAME	:
				case	_SELECT_FRAME	:
					abal_public_signature( h, iptr,__abal_method_set);
					abal_public_signature( h, iptr,__abal_method_get);
					public_widgets++;
				}
			if ( iptr->Contents.events->xo_create & _EVENT_IS_FUNCTION )
				abal_public_widget(h,iptr,iptr->Contents.name,__abal_method_create,iptr->Contents.events->on_create,1);
			if ( iptr->Contents.events->xo_remove & _EVENT_IS_FUNCTION )
				abal_public_widget(h,iptr,iptr->Contents.name,__abal_method_remove,iptr->Contents.events->on_remove,1);
			if ( iptr->Contents.events->xo_show & _EVENT_IS_FUNCTION )
				abal_public_widget(h,iptr,iptr->Contents.name,__abal_method_show,iptr->Contents.events->on_show,1);
			if ( iptr->Contents.events->xo_hide & _EVENT_IS_FUNCTION )
				abal_public_widget(h,iptr,iptr->Contents.name,__abal_method_hide,iptr->Contents.events->on_hide,1);
			if ( iptr->Contents.events->xo_get_focus & _EVENT_IS_FUNCTION )
				abal_public_widget(h,iptr,iptr->Contents.name,__abal_method_get_focus,iptr->Contents.events->on_get_focus,1);
			if ( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION )
				abal_public_widget(h,iptr,iptr->Contents.name,__abal_method_lose_focus,iptr->Contents.events->on_lose_focus,1);
			if ( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION )
				abal_public_widget(h,iptr,iptr->Contents.name,__abal_method_event,iptr->Contents.events->on_event,1);
			}
		}
	linefeed(h);
	if ( public_widgets ) {
		abal_public_signatures( h, fptr,__abal_method_set);
		abal_public_signatures( h, fptr,__abal_method_get);
		}
	return;
}

public	int	open_abal_page(FILE * h,struct form_item * iptr,int i)
{
	int	pn=0;

	if ((iptr->Contents.style & _FRAME_TYPE) == _TAB_FRAME)
		pn = iptr->Contents.page;

	else if (!(pn = iptr->Contents.page ))
		return(0);

	if ( i != 0 ) indent(h,i);
	fprintf(h,"If ( PageNumber = %u ) ",pn);
	linefeed(h);
	return(pn);
}

public	void	close_abal_page(FILE * h,int pn,int i)
{
	if ( pn != 0 ) {
		if ( i != 0 ) indent(h,i);
		fprintf(h,"Endif");
		linefeed(h);
		}
	return;
}

public	void	abal_widget_function( FILE * handle, char * mptr, int i )
{
	indent( handle, i );
	fprintf(handle,"%s=%s(",__abal_keyword_status,mptr);
	return;
}

public	void	abal_scrollbar_widget(FILE * handle, struct form_item * iptr, int margin, int focus )
{
	abal_widget_function(handle,__abal_visual_scroll,margin);
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	font_parameter(handle,iptr);
	colour_parameter(handle,iptr);
	fprintf(handle,",v_%s",iptr->Contents.name);
	fprintf(handle,",l_%s",iptr->Contents.name);
	fprintf(handle,",m_%s,%u)",iptr->Contents.name,(iptr->Contents.align|focus));
	linefeed(handle);
	return;
}

public	void	abal_control_show(FILE * handle, struct form_item * iptr, char * mptr, int mode, int isevent)
{
	char	*	tptr;

	if ((iptr->Contents.style & _FRAME_TYPE) == _BUTTON_FRAME) 
		abal_button_widget(handle,iptr,1,0);
	else	{
		abal_widget_function(handle,mptr,1);
		widget_position(handle,iptr,0,0);
		widget_dimensions(handle,iptr,0,0);
		font_parameter(handle,iptr);
		colour_parameter(handle,iptr);

		switch (( iptr->Contents.style & _FRAME_TYPE )) {
			case	_PROGRESS_FRAME	:
				fprintf(handle,",l_%s",iptr->Contents.name);
				fprintf(handle,",v_%s,%u",iptr->Contents.name,iptr->Contents.align);
				break;
			case	_SCROLL_FRAME	:
				fprintf(handle,",v_%s",iptr->Contents.name);
				fprintf(handle,",l_%s",iptr->Contents.name);
				fprintf(handle,",m_%s,%u",iptr->Contents.name,iptr->Contents.align);
				break;

			case	_GRAPH_FRAME	:
				fprintf(handle,",b_%s,l_%s",iptr->Contents.name,iptr->Contents.name);
				switch ( iptr->Contents.datatype ) {
					case	_WIDGET_WORD : fprintf(handle,",5"); break;
					case	_WIDGET_LONG : fprintf(handle,",6"); break;
					case	_WIDGET_VOID :
					case	_WIDGET_BYTE : 
					default		     : fprintf(handle,",4"); break;
					}
				break;

			case	_SWITCH_FRAME	:
			case	_CHECK_FRAME	:
				constant_parameter(handle,iptr );
				constant_length_parameter(handle,iptr);
				if ( mode )	
					fprintf(handle,",((v_%s+",iptr->Contents.name);
				else	fprintf(handle,",((");
				if ((iptr->Contents.style & _FRAME_TYPE) == _CHECK_FRAME) 
					fprintf(handle,"(a_%s * 4))",iptr->Contents.name);
				else	fprintf(handle,"0)");
				fprintf(handle," or /%04.4X)",(isevent | (iptr->Contents.align & 0x0F00) | (( iptr->Contents.align & 0x000F) << 4)));
				break;


			case	_SELECT_FRAME	:
			default			:
				constant_parameter(handle,iptr );
				constant_length_parameter(handle,iptr);
	
				if ( mode )	
					fprintf(handle,",v_%s",iptr->Contents.name);
				else	fprintf(handle,",0");
	
			}

		switch (( iptr->Contents.style & _FRAME_TYPE )) {
			case	_RADIO_FRAME	:
				fprintf(handle,",%u)",iptr->Contents.radio);
				break;
			case	_SELECT_FRAME	:
				fprintf(handle,",%u+(a_%s*8)",(isevent | (iptr->Contents.align << 8)),iptr->Contents.name);
			default			:
				fprintf(handle,")");
			}
		linefeed(handle);
		}
	return;
}

public	void	abal_visual_widget(FILE * h, struct form_item * iptr, int margin )
{
	if (( iptr->Contents.align & 0x000F ) == _VISUAL_FRAME) {
		switch ( iptr->Contents.datatype ) {
			case	_WIDGET_CLASS	:
			case	_WIDGET_POINTER	:
				indent(h,margin);
				fprintf(h,"%s.on_show",iptr->Contents.name);
				linefeed(h);
				break;
			case	_WIDGET_MODULE	:
				indent(h,margin);
				fprintf(h,"%sOnShow()",abal_payload(iptr));
				linefeed(h);
				break;
			case	_WIDGET_OVERLAY	:
				invoke_widget_overlay(h,iptr,_OVL_ONSHOW);
				break;
			}
		}
	return;
}

public	int	abal_onfocus_widget(FILE * handle, struct form_item * iptr, int margin )
{

	switch ((iptr->Contents.style&_FRAME_TYPE)) {
		case	_DATA_FRAME	:
			abal_widget_focus(handle,iptr,abal_payload(iptr),0);
			break;
		case	_FORM_FRAME	:
			abal_form_focus(handle,iptr,3);
			break;
		case	_EDIT_FRAME	:
			abal_onfocus_edit(handle, iptr, margin);
			break;
		case	_SELECT_FRAME	:
			abal_onfocus_select(handle, iptr, margin);
			break;

		default			:
			abal_onfocus_default(handle,iptr,margin);
			break;

		}
	return(1);
}

private	char *	widget_style_class( struct form_item * iptr, int focus )
{
	if (!( focus ))
		return( iptr->Contents.stylesheet );
	else if (!( focus & (4|8) ))
		return( iptr->Contents.stylefocus );
	else	return( iptr->Contents.stylepress );
}

public	int	abal_onshow_widget(FILE * h, struct form_item * iptr, int margin, int focus )
{
	char *	sptr=(char *) 0;
	int	items=0;
	int	pn;

	if (!( use_visual_interface( iptr->parent,1 )))
		return(0);

	if (( iptr->Contents.style & _FRAME_TYPE ) == _TAB_FRAME )
		return(0);

	else	pn = open_abal_page(h,iptr,margin);

	if ( iptr->Contents.events->xo_hide & _EVENT_IS_POP ) {
		generate_abal_popup(h,iptr,margin);
		}

	sptr = widget_style_class( iptr, focus );

	if (method_is_valid( sptr )) {
		items = abal_visual_element( h, iptr, sptr, (char *) 0, margin++ );
		}

	switch (( iptr->Contents.style & _FRAME_TYPE )) {
		case	_DATA_FRAME		:
			abal_visual_widget(h,iptr,margin);
			break;

		case	_FILL_FRAME		:
			abal_fill_widget(h,iptr,margin);
			break;

		case	_OUTSET_FRAME		:
		case	_INSET_FRAME		:
		case	_RIDGE_FRAME		:
		case	_GROOVE_FRAME		:
			abal_frame_widget(h,iptr,margin);
			break;

		case	_TEXT_FRAME		:
			abal_text_widget(h,iptr,margin);
			break;
		case	_IMAGE_FRAME		:
			abal_image_widget(h,iptr,margin);
			break;

		case	_LINE_FRAME		:
			abal_line_widget(h,iptr,margin);
			break;

		case	_WINDOW_FRAME		:
			abal_window_widget(h,iptr,margin);
			break;

		case	_BUTTON_FRAME		:
			if ( focus )
				abal_button_widget(h,iptr,margin,focus);
			else	abal_button_widget(h,iptr,margin,0);
			break;

		case	_CHECK_FRAME		:
			if ( focus )
				abal_control_show(h,iptr,__abal_visual_check,1,focus);
			else	abal_control_show(h,iptr,__abal_visual_check,1,0);
			break;
		
		case	_RADIO_FRAME		:
			if ( focus )
				abal_control_show(h,iptr,__abal_visual_radio,1,focus);
			else	abal_control_show(h,iptr,__abal_visual_radio,1,0);
			break;
		
		case	_GRAPH_FRAME		:
			abal_control_show(h,iptr,__abal_visual_graph,1,0);
			break;
		
		case	_SWITCH_FRAME	:
			if ( focus )
				abal_control_show(h,iptr,__abal_visual_switch,1,focus);
			else	abal_control_show(h,iptr,__abal_visual_switch,1,0);
			break;
		
		case	_FORM_FRAME		:
		case	_EDIT_FRAME		:
			abal_dialog_show(h,iptr,0);
			break;

		case	_SELECT_FRAME		:
			if ( focus )
				abal_select_show(h,iptr,focus);
			else	abal_select_show(h,iptr,0);
			break;

		case	_SCROLL_FRAME		:
			abal_control_show(h,iptr,__abal_visual_scroll,1,0);
			break;

		case	_PROGRESS_FRAME		:
			abal_control_show(h,iptr,__abal_visual_progress,1,0);
			break;


		}
	if ( method_is_valid( sptr  ) ) {
		margin--;
		if ( items ) {
			indent(h,margin);
			fprintf(h,"Endif");
			linefeed(h);
			}
		}
	if ( pn ) { close_abal_page(h,pn,margin); }
	return(1);
}

public	int	is_named_edit( struct form_item * iptr )
{
	if (((iptr->Contents.style & _FRAME_TYPE) != _EDIT_FRAME)
	&&  ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME))
		return(0);
	else	return(1); /*  is_named_widget( iptr ) ); */
}

public	int	is_named_progress( struct form_item * iptr )
{
	if ((iptr->Contents.style & _FRAME_TYPE) != _PROGRESS_FRAME)
		return(0);
	else 	return(1); /* is_named_widget( iptr ) ); */
}

public	int	is_named_scroll( struct form_item * iptr )
{
	if ((iptr->Contents.style & _FRAME_TYPE) != _SCROLL_FRAME)
		return(0);
	else	return(1); /*  is_named_widget( iptr ) ); */
}

public	int	is_named_select( struct form_item * iptr )
{
	if ((iptr->Contents.style & _FRAME_TYPE) != _SELECT_FRAME)
		return(0);
	else	return(1); /* is_named_widget( iptr ) ); */
}

public	int	is_named_conditional( struct form_item * iptr )
{
	if (!(iptr->Contents.events->xo_show & _EVENT_IS_COND ))
		return(0);
	else if (!(iptr->Contents.events->xo_show & _EVENT_IS_FUNCTION ))
		return(0);
	else	return(1); /*  is_named_widget( iptr ) ); */
}

	
public	void	abal_conditional_show(FILE * handle, struct form_item * iptr, int mode )
{
	char *	tptr;
	int	pn=0;
	int	status=0;
	char	*	optr;
	struct	form_control * fptr;
	char	*	fnptr;

	if (!( iptr ))
		return;
	else if (!( fptr = iptr->parent ))
		return;
	else if (( iptr->Contents.access & _WIDGET_PUBLIC)
	     &&  (   fptr->isoverlay     )
	     &&  (!( fptr->isprogram     )))
		fnptr = fptr->identifier;
	else	fnptr = "\0";

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = __abal_overlay_object;
	else	optr = "\0";

	if ((status = is_named_conditional( iptr )) != 0) {

		if (!( mode )) {
			abal_comment(handle,iptr->Contents.name,1);
			return;
			}
		else	{
			fprintf(handle,"%s %s%s%s(%s)",__abal_keyword_proc,
				fnptr,iptr->Contents.name,__abal_method_onshow,optr);
			linefeed(handle);
			pn = open_abal_page( handle, iptr,1 );
			}	
		}

	/* End of the line */
	/* --------------- */
	else if ( mode ) return;

	generate_abal_show(handle,iptr, pn );

	if ( status ) {
		close_abal_page( handle, pn,1 );
		indent(handle,1);
		fprintf(handle,__abal_keyword_exit);
		linefeed(handle);
		fprintf(handle,__abal_keyword_endproc);
		linefeed(handle);
		}
	return;

}

public	void	abal_scroll_show(FILE * handle, struct form_item * iptr, int mode )
{
	char *	tptr;
	int	pn=0;
	int	status=0;
	struct	form_control * fptr;
	char	*	fnptr;

	char	*	optr;
	char	*	moptr;

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay )) {
		moptr = "o"; optr = __abal_overlay_object;
		}
	else	{
		moptr = optr = "\0";
		}
	if (!( iptr ))
		return;
	else if (!( fptr = iptr->parent ))
		return;
	else if (( iptr->Contents.access & _WIDGET_PUBLIC )
	     &&  (   fptr->isoverlay     )
	     &&  (!( fptr->isprogram     )))
		fnptr = fptr->identifier;
	else	fnptr = "\0";

	if ((status = is_named_scroll  ( iptr )) != 0) {
		if (!( mode )) {
			fprintf(handle,"\t%s%s%s(%s)",fnptr,iptr->Contents.name,__abal_method_onshow,moptr);
			linefeed(handle);
			return;
			}
		else	{
			fprintf(handle,"%s %s%s%s(%s)",__abal_keyword_proc,fnptr,iptr->Contents.name,__abal_method_onshow,optr);
			linefeed(handle);
			pn = open_abal_page( handle, iptr,1 );
			}	
		}
	else if ( mode ) {
		abal_conditional_show(handle,iptr,mode);
		return;
		}

	abal_scrollbar_widget(handle,iptr,1, 0);

	if ( status ) {
		close_abal_page( handle, pn,1 );
		indent(handle,1);
		fprintf(handle,__abal_keyword_exit);
		linefeed(handle);
		fprintf(handle,__abal_keyword_endproc);
		linefeed(handle);
		}
	return;

}

public	void	abal_progress_show(FILE * handle, struct form_item * iptr, int mode )
{
	char *	tptr;
	int	pn=0;
	int	status=0;
	char	*	optr;
	char	*	moptr;

	struct	form_control * fptr;
	char	*	fnptr;

	if (!( iptr ))
		return;
	else if (!( fptr = iptr->parent ))
		return;
	else if (( iptr->Contents.access & _WIDGET_PUBLIC)
	     &&  (   fptr->isoverlay     )
	     &&  (!( fptr->isprogram     )))
		fnptr = fptr->identifier;
	else	fnptr = "\0";

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay )) {
		moptr = "o"; optr = __abal_overlay_object;
		}
	else	{
		moptr = optr = "\0";
		}

	if ((status = is_named_progress  ( iptr )) != 0) {
		if (!( mode )) {
			fprintf(handle,"\t%s%s%s(%s)",fnptr,iptr->Contents.name,__abal_method_onshow,moptr);
			linefeed(handle);
			return;
			}
		else	{
			fprintf(handle,"%s %s%s%s(%s)",__abal_keyword_proc,fnptr,iptr->Contents.name,__abal_method_onshow,optr);
			linefeed(handle);
			pn = open_abal_page( handle, iptr,1 );
			}	
		}
	else if ( mode ) {
		abal_scroll_show(handle,iptr,mode);
		return;
		}

	abal_control_show(handle,iptr,__abal_visual_progress,1,0);

	if ( status ) {
		close_abal_page( handle, pn,1 );
		indent(handle,1);
		fprintf(handle,__abal_keyword_exit);
		linefeed(handle);
		fprintf(handle,__abal_keyword_endproc);
		linefeed(handle);
		}
	return;

}

public	void	abal_select_show(FILE * handle, struct form_item * iptr, int mode )
{
	char *	tptr;
	int	pn=0;
	int	status=0;

	char	*	optr;
	char	*	moptr;
	struct	form_control * fptr;
	char	*	fnptr;

	if (!( iptr ))
		return;
	else if (!( fptr = iptr->parent ))
		return;
	else if (( iptr->Contents.access & _WIDGET_PUBLIC)
	     &&  (   fptr->isoverlay     )
	     &&  (!( fptr->isprogram     )))
		fnptr = fptr->identifier;
	else	fnptr = "\0";

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay )) {
		moptr = "o"; optr = __abal_overlay_object;
		}
	else	{
		moptr = optr = "\0";
		}

	calculate_edit_size( &iptr->Contents );

	if ((status = is_named_select  ( iptr )) != 0) {
		if (!( mode )) {
			fprintf(handle,"\t%s%s%s(%s)",fnptr,iptr->Contents.name,__abal_method_onshow,moptr);
			linefeed(handle);
			return;
			}
		else	{
			fprintf(handle,"%s %s%s%s(%s)",__abal_keyword_proc,fnptr,iptr->Contents.name,__abal_method_onshow,optr);
			linefeed(handle);
			pn = open_abal_page( handle, iptr,1 );
			}	
		}
	else if ( mode ) {
		abal_progress_show(handle,iptr,mode);
		return;
		}

	abal_control_show(handle,iptr,__abal_visual_select,1,0);

	if ( status ) {
		close_abal_page( handle, pn,1 );
		indent(handle,1);
		fprintf(handle,__abal_keyword_exit);
		linefeed(handle);
		fprintf(handle,__abal_keyword_endproc);
		linefeed(handle);
		}
	return;

}



public	void	abal_table_widget(FILE * handle, struct form_item * iptr, int margin )
{
	/* test for auto focus required */
	if ( iptr->Contents.align & _A_BAR ) {
		indent(handle,margin);
		fprintf(handle,"Status = %s(_VISUAL_TABLEFOCUS,%c %c,v_%s)",
					__abal_visual_control,__QUOTE,__QUOTE,iptr->Contents.name);
		linefeed(handle);
		}
	abal_widget_function(handle,__abal_visual_table,margin);
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	font_parameter(handle,iptr);
	colour_parameter(handle,iptr);
	constant_parameter(handle,iptr );
	constant_length_parameter(handle,iptr);
	fprintf(handle,",b_%s",iptr->Contents.name);
	length_parameter(handle,iptr->Contents.size);
	if (!( is_valid_format( iptr->Contents.format ) )) {
		abal_hex_parameter(handle,(iptr->Contents.align & 0x0F07)|(iptr->Contents.special & 1 ? 0x2000:0));
		string_parameter(handle,"()");
		length_parameter(handle,2);
		}
	else	{
		abal_hex_parameter(handle,((iptr->Contents.align&0x0F07) | 0x4000|(iptr->Contents.special & 1 ? 0x2000:0)));
		string_parameter(handle,iptr->Contents.format);
		length_parameter(handle,strlen(iptr->Contents.format));
		}
	fprintf(handle,")");
	linefeed(handle);
	return;
}

public	void	abal_dialog_show(FILE * handle, struct form_item * iptr, int mode )
{
	char *	tptr;
	int	pn=0;
	int	status=0;

	char	*	optr;
	char	*	moptr;

	struct	form_control * fptr;
	char	*	fnptr;

	if (!( iptr ))
		return;
	else if (!( fptr = iptr->parent ))
		return;
	else if (( iptr->Contents.access & _WIDGET_PUBLIC)
	     &&  (   fptr->isoverlay     )
	     &&  (!( fptr->isprogram     )))
		fnptr = fptr->identifier;
	else	fnptr = "\0";

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay )) {
		moptr = "o"; optr = __abal_overlay_object;
		}
	else	{
		moptr = optr = "\0";
		}

	calculate_edit_size( &iptr->Contents );

	if ((status = is_named_edit  ( iptr )) != 0) {
		if (!( mode )) {
			fprintf(handle,"\t%s%s%s(%s)",fnptr,iptr->Contents.name,__abal_method_onshow,moptr);
			linefeed(handle);
			return;
			}
		else	{
			fprintf(handle,"%s %s%s%s(%s)",__abal_keyword_proc,fnptr,iptr->Contents.name,__abal_method_onshow,optr);
			linefeed(handle);
			abal_error_trap(handle,1,1);
			pn = open_abal_page( handle, iptr,1 );
			}	
		}

	else if ( mode ) {
		abal_select_show(handle,iptr,mode);
		return;
		}

	if  ((iptr->Contents.style & _FRAME_TYPE) == _BUTTON_FRAME) {
		abal_button_widget(handle,iptr,1,0);
		}
	else if  ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME) {
		abal_widget_function(handle,__abal_visual_zone,1);
		widget_position(handle,iptr,0,0);
		widget_dimensions(handle,iptr,2,2);
		if ((iptr->Contents.style & _FRAME_TYPE) == _EDIT_FRAME)
			fprintf(handle,",%u + (a_%s * 128))	; si access vaut 2 alors gris",iptr->Contents.style,iptr->Contents.name );
		else	fprintf(handle,",%u)",iptr->Contents.style );
		linefeed(handle);
		if (!( iptr->Contents.align & 0x000F )) {
			abal_visual_editshow(handle,iptr,1);
			}
		else	{
			abal_widget_function(handle,__abal_visual_text,1);
			widget_position(handle,iptr,1,1);
			widget_dimensions(handle,iptr,0,0);
			font_parameter(handle,iptr);
			colour_parameter(handle,iptr);
			if (!( iptr->Contents.align & 512 )) {
				fprintf(handle,",b_%s",iptr->Contents.name);
				length_parameter(handle,iptr->Contents.size);
				}
			else	{
				fprintf(handle,",Gener(%u,chr$(/2A)),Len$(b_%s)",
					iptr->Contents.size,iptr->Contents.name);
				}
			if ( iptr->Contents.datatype == _WIDGET_KONSTANT )
				fprintf(handle,",%u)",iptr->Contents.align );
			else	fprintf(handle,",0)");
			}
		linefeed(handle);
		}
	else	{
		abal_table_widget(handle,iptr,1);
		}

	if ( status ) {
		close_abal_page( handle, pn,1 );
		indent(handle,1);
		fprintf(handle,__abal_keyword_exit);
		linefeed(handle);
		abal_error_abort(handle,1,1);
		abal_error_return(handle,__abal_keyword_status,1);
		fprintf(handle,__abal_keyword_endproc);
		linefeed(handle);
		}
	return;

}


public	void	widget_mouse_event(FILE * h, struct form_item * iptr, int margin )
{
	int	xfi=0;
	int	f=0;
	int	fields=0;
	int	fieldwidth[_MAX_FORM_FIELDS];
	int	linelength=0;
	int	nblines=0;
	int	fw;
	int	fh;

	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
		return;

	calculate_edit_size( &iptr->Contents );
	calculate_form_lines( iptr, &linelength, &nblines );

	if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
		return;

	fw = guifontsize(iptr->Contents.font);
	fh = (fw >> 8); fw &= 0x00FF;	

	indent(h,margin);
	fprintf(h,"v_%s = ((%s - (%s)) / %u)",
		iptr->Contents.name,
		__abal_mouse_row, widget_y_position(iptr,0), fh );
	linefeed(h);

	indent(h,margin);
	if (is_h_modif(iptr)) {
		fprintf(h,"y_internal=(%u*_href)/%u",nblines,h_base_resize(iptr));
		linefeed(h);
		indent(h,margin);
		}
	fprintf(h,"if ( v_%s < 1 ) :: v_%s  = 0",
		iptr->Contents.name,
		iptr->Contents.name );
	linefeed(h);
	indent(h,margin);
	if (is_h_modif(iptr)) {
		fprintf(h,"%s :: if ( v_%s > y_internal ) :: v_%s  = y_internal :: %s",
			__abal_keyword_else,
			iptr->Contents.name,
			iptr->Contents.name,
			__abal_keyword_endif);
		}
	else	{
		fprintf(h,"%s :: if ( v_%s > %u ) :: v_%s  = %u :: %s",
			__abal_keyword_else,
			iptr->Contents.name,nblines,
			iptr->Contents.name,nblines,
			__abal_keyword_endif);
		}

	linefeed(h);
	abal_endif(h,margin);

	indent(h,margin);
	fprintf(h,"c_%s = (%s - (%s))",
		iptr->Contents.name,
		__abal_mouse_column, widget_x_position(iptr,0));
	linefeed(h);

	for (	f=0,xfi=0;
		f<fields;
		f++ ) {
		xfi += (fieldwidth[f]*fw);
		indent(h,margin++);
		if (is_w_modif(iptr)) {
			if (!( f ))
				fprintf(h,"x_internal =  (cw_%s(%u)*%u)",iptr->Contents.name,(f+1),fw);
			else	fprintf(h,"x_internal += (cw_%s(%u)*%u)",iptr->Contents.name,(f+1),fw);
			linefeed(h);
			indent(h,margin);
			fprintf(h,"if ( c_%s < x_internal)",iptr->Contents.name/* (xfi+f+1)*/);
			}
		else	fprintf(h,"if ( c_%s < %u )",iptr->Contents.name,xfi/* (xfi+f+1)*/);
		linefeed(h);
		indent(h,margin);
		fprintf(h,"c_%s = %u",iptr->Contents.name,f+1);
		linefeed(h);
		if ( (f+1) < fields ) {
			indent(h,(margin-1));
			fprintf(h,__abal_keyword_else);
			linefeed(h);
			}
		}
	abal_else(h,(margin-1));
	indent(h,(margin));
	fprintf(h,"c_%s = %u",iptr->Contents.name,fields);
	linefeed(h);
	for (	f=0; f < fields; f++ ) { abal_endif(h,--margin); }

	indent(h,margin);
	fprintf(h,"if (( v_%s =0 ) ((MouseType and _MIMO_DOWN) <> 0))	; si clic dans la zone titre du tableau",
		iptr->Contents.name);
	linefeed(h);
	indent(h,margin+1);
	fprintf(h,"if ( f_%s = c_%s )	; si c'est d‚j… la colonne tri‚e",
		iptr->Contents.name,iptr->Contents.name);
	linefeed(h);
	indent(h,margin+2);
	fprintf(h,"f_%s = -c_%s		; alors tri inverse",
		iptr->Contents.name,iptr->Contents.name);
	linefeed(h);
	indent(h,margin+1);
	fprintf(h,__abal_keyword_else);
	linefeed(h);
	indent(h,margin+2);
	fprintf(h,"f_%s = c_%s		; sinon tri normal",
		iptr->Contents.name,iptr->Contents.name);
	linefeed(h);
	abal_endif(h,margin+1);	
	abal_endif(h,margin);
	return;
}
	
static char * nocons="\0NoConstants";

public	void	abal_return_focus(FILE * handle, struct form_item * iptr, int margin )
{
	if ( *nocons )
		abal_returni(handle,iptr->Contents.focus,margin);
	else if (!( iptr->Contents.focus )) 
		abal_returni(handle,iptr->Contents.focus,margin);
	else	{
		indent(handle,margin);
		if (( iptr->Contents.style & _FRAME_TYPE ) == _RADIO_FRAME)
			fprintf(handle,"%s(_%u_%s)",__abal_keyword_exit,iptr->Contents.radio,iptr->Contents.name);
		else	fprintf(handle,"%s(__%s)",__abal_keyword_exit,iptr->Contents.name);
		linefeed(handle);
		}
	return;
}


public	void	abal_initialise_national_language(FILE * h, struct form_control * fptr, int mode)
{
	if ( fptr->formflags & _MULTILINGUAL ) {
		if (!( mode )) {
			indent(h,1);
			fprintf(h,"NationalLanguage = %s(_VISUAL_LANGUAGE,%c %c,-1)",
				__abal_visual_control,__QUOTE,__QUOTE);
			linefeed(h);
			indent(h,1);
			fprintf(h,"if ( NationalLanguage = 0 ) :: NationalLanguage = %u :: Endif",fptr->natlang+1);
			linefeed(h);
			}
		else if ( Abal_Config.generate_program ) {
			if (!( Abal_Config.generate_overlay )) {
				indent(h,1);
				fprintf(h,"NationalLanguage=%u",fptr->natlang+1);
				linefeed(h);
				indent(h,1);
				fprintf(h,"Status = %s(_VISUAL_LANGUAGE,%c %c,NationalLanguage)",
					__abal_visual_control,__QUOTE,__QUOTE);
				linefeed(h);
				}
			else	{
				indent(h,1);
				fprintf(h,"NationalLanguage = %s(_VISUAL_LANGUAGE,%c %c,-1)",
					__abal_visual_control,__QUOTE,__QUOTE);
				linefeed(h);
				indent(h,1);
				fprintf(h,"if ( NationalLanguage = 0 ) :: NationalLanguage = %u :: Endif",fptr->natlang+1);
				linefeed(h);
				}
			}
		else	{
			indent(h,1);
			fprintf(h,"NationalLanguage = %s(_VISUAL_LANGUAGE,%c %c,-1)",
				__abal_visual_control,__QUOTE,__QUOTE);
			linefeed(h);
			indent(h,1);
			fprintf(h,"if ( NationalLanguage = 0 ) :: NationalLanguage = %u :: Endif",fptr->natlang+1);
			linefeed(h);
			}
		}
	return;
}

/*	MULTILINGUAL Language Switch 	*/
/*	----------------------------	*/
public	void	abal_move_event(FILE * h, struct form_item * iptr, int margin )
{
	char	*optr;

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = "o";
	else	optr = "\0";
	indent(h,margin);
	fprintf(h,"Status = %s%s(%s)",
		iptr->Contents.name,__abal_method_action,
		optr);
	linefeed(h);
	abal_returni(h,-1,margin);

}


public	void	abal_lang_event(FILE * h, struct form_item * iptr, int margin )
{
	char	*	optr;
	struct form_control * fptr;
	if (((fptr = iptr->parent) != (struct form_control *) 0)	
	&&  ( fptr->pages != 0 )) {
		indent(h,margin);	
		fprintf(h,"FirstPage = PageNumber :: PageNumber = 0");
		linefeed(h);
		}
	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = "o";
	else	optr = "\0";

	indent(h,margin++);
	fprintf(h,"if (MouseButton=_MIMO_LEFT)");
	linefeed(h);
	indent(h,margin);	
		fprintf(h,"if (NationalLanguage = %u) :: NationalLanguage = 1 :: else :: NationalLanguage += 1 :: Endif",MAXNATLANG);
		linefeed(h);
	abal_else(h,(margin-1));
	indent(h,margin);	
		fprintf(h,"if (NationalLanguage > 1) :: NationalLanguage -= 1 :: else :: NationalLanguage = %u :: Endif",MAXNATLANG);
		linefeed(h);
	abal_endif(h,--margin);
	indent(h,margin);
	fprintf(h,"%s = %s(_VISUAL_LANGUAGE,%c %c,NationalLanguage)",__abal_keyword_status,__abal_visual_control,__QUOTE,__QUOTE);
	linefeed(h);
	abal_widget_function(h,__abal_visual_freeze,1);
	fprintf(h,")");
	linefeed(h);
	indent(h,margin);
	fprintf(h,"%s%s(%s)",Abal_Config.cname,__abal_method_show,optr);
	linefeed(h);
	abal_widget_function_thaw(h,iptr,1);
	return;
}

private	void	abal_visual_help( FILE * h, char* sptr, int margin )
{
	indent(h,margin);
	fprintf(h,"%s = %s(_VISUAL_HELP,",__abal_keyword_status,__abal_visual_control);
	quoted_string(h,sptr);
	fprintf(h,",%u)",strlen( sptr ));
	linefeed(h);
	return;
}

private	void	form_help_event(FILE * h, char * sptr, int margin )
{
	if (!( sptr = enforce_extension( sptr, HTM_EXTENSION) ))
		return;
	else	{
		indent(h,margin);
		fprintf(h,"if (( %s and _MIMO_UP) <> 0)",__abal_mouse_type);
		linefeed(h);
		abal_visual_help(h,sptr,margin+1);
		abal_endif(h,1);
		liberate( sptr );
		return;
		}
}

public	void	abal_help_event(FILE * h, struct form_item * iptr, int margin )
{
	char *	sptr;
	struct form_control * fptr;
	if (!( fptr = iptr->parent ))
		return;
	else if (!( sptr = allocate_string( fptr->prodname )))
		return;
	else	{
		form_help_event(h,sptr,margin);
		return;
		}
}

public	void	abal_mouse_event(FILE * handle, struct form_item * iptr, int margin )
{
	switch (( Context.Form->formflags & _FORM_TYPE_FLAGS )) {

		case	_FORM_TYPE_DIALOG	:
			/* very simple for now */
			/* ------------------- */
			abal_return_focus(handle,iptr,margin);
			break;

		case	_FORM_TYPE_EVENT 	:
			if (!( iptr->Contents.events->mimo )) {
				if (( Abal_Config.generate_program )
				&&  ( Abal_Config.generate_overlay ))
					abal_return(handle,__abal_focus_item,margin);
				else	abal_returni(handle,-1,margin);
				}
			else	{
				abal_select(handle,__abal_mouse_type,margin);
				if ( iptr->Contents.events->mimo & _MIMO_UP ) {
					abal_cases(handle,"_MIMO_UP",margin);
					abal_return_focus(handle,iptr,margin);
					}
				if ( iptr->Contents.events->mimo & _MIMO_DOWN ) {
					abal_cases(handle,"_MIMO_DOWN",margin);
					abal_return_focus(handle,iptr,margin);
					}
				if ( iptr->Contents.events->mimo & _MIMO_MOVE ) {
					abal_cases(handle,"_MIMO_MOVE",margin);
					abal_return_focus(handle,iptr,margin);
					}
				if ( iptr->Contents.events->mimo & _MIMO_WHILE_DOWN ) {	
					abal_cases(handle,"_MIMO_WHILE_DOWN",margin);
					abal_return_focus(handle,iptr,margin);
					}
				abal_default(handle,margin);
				if (( Abal_Config.generate_program )
				&&  ( Abal_Config.generate_overlay ))
					abal_return(handle,__abal_focus_item,margin+1);
				else	abal_returni(handle,-1,margin+1);
				abal_endsel(handle,margin);
				}
			break;
		}
	return;
}

private	int	start_abal_filter_select( FILE * handle, int margin )
{
	indent(handle,margin); 
	fprintf( handle,"Select ( %s )",__abal_mouse_button); 
	linefeed(handle);
	indent(handle,margin); 
	fprintf( handle,"Case ");
	return(1);
}

private	void	close_abal_filter_select( FILE * handle, int margin )
{
	indent(handle,margin); 
	fprintf( handle,"EndSel");
	linefeed(handle);
	return;
}

private	int	abal_widget_mouse_filter(FILE * handle, struct form_item * iptr,int margin)
{
	int	b=0;
	struct	form_control * fptr;
	if (!( iptr ))
		return(0);
	else if (!( fptr = iptr->parent ))
		return(0);
	else if (!( fptr->mimoflags & _MIMO_WIDGETS  ))
		return(0);
	else	{
		if ( iptr->Contents.events->mimo & _MIMO_SEND_LEFT ) {
			if (!( b++ ))
				start_abal_filter_select(handle,margin);				
			else	fprintf( handle,",");
			fprintf(handle,"_MIMO_LEFT" );
			}
		if ( iptr->Contents.events->mimo & _MIMO_SEND_MIDDLE ) {
			if (!( b++ ))
				start_abal_filter_select(handle,margin);				
			else	fprintf( handle,",");
			fprintf(handle,"_MIMO_OTHER" );
			}
		if ( iptr->Contents.events->mimo & _MIMO_SEND_RIGHT ) {
			if (!( b++ ))
				start_abal_filter_select(handle,margin);				
			else	fprintf( handle,",");
			fprintf(handle,"_MIMO_RIGHT" );
			}
		if ( iptr->Contents.events->mimo & _MIMO_SEND_WHEEL ) {
			if (!( b++ ))
				start_abal_filter_select(handle,margin);
			else	fprintf( handle,",");
			fprintf(handle,"_MIMO_UPWHEEL,_MIMO_DOWNWHEEL" );
			}
		if ( b ) linefeed(handle);
		return(b);
		}
}

#include "abalwind.c"

public	void	generate_abal_event(FILE * handle, struct form_item * iptr )
{
	char	*	tptr;
	int		pn=0;
	int		fh;
	int		fw;
	int		f;
	int		wx;
	int		hwx;
	int		wy;
	int		v=0;
	int		b=0;
	struct	form_control * fptr;
	int		with_access=0;
	char *		optr;

	if (((fptr = iptr->parent) != (struct form_control*) 0)
	&&   ( fptr->formflags & _MULTILINGUAL))
		v = 1;

	if ((fptr->isprogram) && (fptr->isoverlay))
		optr = "o,";
	else	optr = "\0";

	switch ((iptr->Contents.style & _FRAME_TYPE)) {

		case	_WINDOW_FRAME	:
			generate_abal_window_event( handle, iptr, optr, v );
			break;


		case	_TAB_FRAME	:
			if ((!( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ))
			&&  (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )))
				break;
			if ((pn = open_abal_page( handle, iptr,1 )) != 0)
				abal_else(handle,1);
			if ( FixedWindows ) {
				if (is_xy_modif(iptr))	{
					fprintf(handle,"\tx_internal = (((%u*_wref)/%d) + v_%s)",(iptr->Contents.x+WindowCol),w_base_resize(iptr),iptr->Contents.name);
					linefeed(handle);
					fprintf(handle,"\ty_internal = ((%u*_href)/%d)",iptr->Contents.y+WindowRow,h_base_resize(iptr));
					linefeed(handle);
					fprintf(handle,"\tif ((%s >= x_internal ) '",__abal_mouse_column);
					linefeed(handle);
					fprintf(handle,"\tand (%s >= y_internal ) '",__abal_mouse_row);
					linefeed(handle);
					fprintf(handle,"\tand (%s <= (x_internal+l_%s) ) '",__abal_mouse_column,iptr->Contents.name,iptr->Contents.name);
					linefeed(handle);
					fprintf(handle,"\tand (%s <= (y_internal+%u) ))",__abal_mouse_row,iptr->Contents.ylimit);
					}
				else	{
					fprintf(handle,"\tif ((%s >= (%u + v_%s) ) '",__abal_mouse_column,(iptr->Contents.x+WindowCol),iptr->Contents.name);
					linefeed(handle);
					fprintf(handle,"\tand (%s >= %u ) '",__abal_mouse_row,iptr->Contents.y+WindowRow);
					linefeed(handle);
					fprintf(handle,"\tand (%s <= (%u+v_%s+l_%s) ) '",__abal_mouse_column,(iptr->Contents.x+WindowCol),iptr->Contents.name,iptr->Contents.name);
					linefeed(handle);
					fprintf(handle,"\tand (%s <= %u ))",__abal_mouse_row,(iptr->Contents.y+WindowRow+iptr->Contents.ylimit));
					}
				}
			else	{
				fprintf(handle,"\tif ((%s >= (%s + v_%s) ) '",__abal_mouse_column,widget_x_position(iptr,1),iptr->Contents.name);
				linefeed(handle);
				fprintf(handle,"\tand (%s >= (%s) ) '",__abal_mouse_row,widget_y_position(iptr,1));
				linefeed(handle);
				fprintf(handle,"\tand (%s <= (%s+v_%s+l_%s) ) '",__abal_mouse_column,widget_x_position(iptr,1),iptr->Contents.name,iptr->Contents.name);
				linefeed(handle);
				fprintf(handle,"\tand (%s <= (%s+%u) ))",__abal_mouse_row,widget_y_position(iptr,1),iptr->Contents.ylimit);
				linefeed(handle);
				}
			linefeed(handle);
			indent(handle,2);
			abal_comment(handle,iptr->Contents.name,1);
			b = abal_widget_mouse_filter(handle,iptr,2);
			abal_mouse_event( handle, iptr,( b ? 3 : 2 ) );
			if ( b ) { close_abal_filter_select( handle, 2 ); }
			abal_endif(handle,1);
			close_abal_page( handle, pn,1 );
			break;

		case	_SELECT_FRAME	:

			if ((!( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ))
			&&  (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )))
				break;
			pn = open_abal_page( handle, iptr,1 );
			if ( FixedWindows ) {
				if (is_xy_modif(iptr))	{
					if (is_w_modif(iptr)) {
						fprintf(handle,"\tx_internal = ((%u*_wref)/%d)",(iptr->Contents.x+WindowCol+iptr->Contents.adjust),w_base_resize(iptr));
						linefeed(handle);
						fprintf(handle,"\ts_internal = ((%u*_wref)/%d)",(iptr->Contents.x+WindowCol+iptr->Contents.adjust+iptr->Contents.xlimit),w_base_resize(iptr));
						}
					else	{
						fprintf(handle,"\tx_internal = ((%u*_wref)/%d)+%u",(iptr->Contents.x+WindowCol),w_base_resize(iptr),iptr->Contents.adjust);
						linefeed(handle);
						fprintf(handle,"\ts_internal = ((%u*_wref)/%d)+%u",(iptr->Contents.x+WindowCol),w_base_resize(iptr),iptr->Contents.adjust+iptr->Contents.xlimit);
						}
					linefeed(handle);
					fprintf(handle,"\ty_internal = ((%u*_href)/%d)",iptr->Contents.y+WindowRow,h_base_resize(iptr));
					linefeed(handle);
					fprintf(handle,"\tif ((%s >= x_internal ) '",__abal_mouse_column);
					linefeed(handle);
					fprintf(handle,"\tand (%s >= y_internal ) '",__abal_mouse_row);
					linefeed(handle);
					fprintf(handle,"\tand (%s <= s_internal ) '",__abal_mouse_column);
					linefeed(handle);
					fprintf(handle,"\tand (%s <= (y_internal+%u) ))",__abal_mouse_row,iptr->Contents.ylimit);
					}
				else	{
					fprintf(handle,"\tif ((%s >= %u ) '",__abal_mouse_column,(iptr->Contents.x+WindowCol+iptr->Contents.adjust));
					linefeed(handle);
					fprintf(handle,"\tand (%s >= %u ) '",__abal_mouse_row,iptr->Contents.y+WindowRow);
					linefeed(handle);
					fprintf(handle,"\tand (%s <= %u ) '",__abal_mouse_column,(iptr->Contents.x+WindowCol+iptr->Contents.adjust+iptr->Contents.xlimit));
					linefeed(handle);
					fprintf(handle,"\tand (%s <= %u ))",__abal_mouse_row,(iptr->Contents.y+WindowRow+iptr->Contents.ylimit));
					}
				}
			else if (is_w_modif(iptr))	{
				fprintf(handle,"\tx_internal = %s+((%u*_wref)/%d)",widget_x_position(iptr,1),(iptr->Contents.adjust),w_base_resize(iptr));
				linefeed(handle);
				fprintf(handle,"\ts_internal = %s+((%u*_wref)/%d)",widget_x_position(iptr,1),(iptr->Contents.w+iptr->Contents.adjust),w_base_resize(iptr));
				linefeed(handle);
				fprintf(handle,"\tif ((%s >= x_internal ) '",__abal_mouse_column);
				linefeed(handle);
				fprintf(handle,"\tand (%s >= (%s) ) '",__abal_mouse_row,widget_y_position(iptr,1));
				linefeed(handle);
				fprintf(handle,"\tand (%s <= s_internal ) '",__abal_mouse_column);
				linefeed(handle);
				fprintf(handle,"\tand (%s <= (%s+%u) ))",__abal_mouse_row,widget_y_position(iptr,1),iptr->Contents.ylimit);
				linefeed(handle);
				}
			else	{
				fprintf(handle,"\tif ((%s >= (%s+%u) ) '",__abal_mouse_column,widget_x_position(iptr,1),iptr->Contents.adjust);
				linefeed(handle);
				fprintf(handle,"\tand (%s >= (%s) ) '",__abal_mouse_row,widget_y_position(iptr,1));
				linefeed(handle);
				fprintf(handle,"\tand (%s <= (%s+%u) ) '",__abal_mouse_column,widget_x_position(iptr,1),iptr->Contents.w+iptr->Contents.adjust);
				linefeed(handle);
				fprintf(handle,"\tand (%s <= (%s+%u) ))",__abal_mouse_row,widget_y_position(iptr,1),iptr->Contents.ylimit);
				linefeed(handle);
				}
			linefeed(handle);
			indent(handle,2);
			abal_comment(handle,iptr->Contents.name,1);
			/* detect conditional items and test if selectionable */
			/* -------------------------------------------------- */
			if ( iptr->Contents.events->xo_hide & _EVENT_IS_POP ) {
				indent(handle,2);	
				fprintf(handle,"if ((p_%s<>0) and ( s_%s<>0))",
					iptr->Contents.name,	
					iptr->Contents.name );
				linefeed(handle);
				}

			indent(handle,2); fprintf(handle,"if (a_%s=0)",iptr->Contents.name); linefeed(handle);
			b = abal_widget_mouse_filter(handle,iptr,2);
			abal_mouse_event( handle, iptr,( b ? 3 :  2 ) );
			if ( b ) { close_abal_filter_select( handle, 2 ); }
			abal_endif(handle,2);

			/* detect conditional items and test if selectionable */
			/* -------------------------------------------------- */
			if ( iptr->Contents.events->xo_hide & _EVENT_IS_POP ) {
				abal_endif(handle,1);
				}
			abal_endif(handle,1);
			close_abal_page( handle, pn,1 );
			break;

		case	_DATA_FRAME	:
			if (( iptr->Contents.align & 0x00F ) != _VISUAL_FRAME )
				break;
		case	_EDIT_FRAME	:
		case	_BUTTON_FRAME	:
		case	_SWITCH_FRAME	:
		case	_RADIO_FRAME	:
		case	_CHECK_FRAME	:
			with_access=1;
		case	_FORM_FRAME	:
		case	_GRAPH_FRAME	:
		default			:
			if (!( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ))
				break;

			pn = open_abal_page( handle, iptr,1 );
			if (is_xy_modif(iptr)) {
				if ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME)
					{
					fprintf(handle,"\tif ((%s >= (%s) ) '",__abal_mouse_column,widget_x_position(iptr,2));
					linefeed(handle);
					fprintf(handle,"\tand (%s >= (%s) ) '",__abal_mouse_row,widget_y_position(iptr,2));
					linefeed(handle);
					fprintf(handle,"\tand (%s <= (%s+w%u_%s) ) '",__abal_mouse_column,widget_x_position(iptr,2),iptr->Contents.radio,iptr->Contents.name);
					linefeed(handle);
					fprintf(handle,"\tand (%s <= (%s+h%u_%s) ))",__abal_mouse_row,widget_y_position(iptr,2),iptr->Contents.radio,iptr->Contents.name);
					linefeed(handle);
					}
				else
					{
					fprintf(handle,"\tif ((%s >= (%s) ) '",__abal_mouse_column,widget_x_position(iptr,2));
					linefeed(handle);
					fprintf(handle,"\tand (%s >= (%s) ) '",__abal_mouse_row,widget_y_position(iptr,2));
					linefeed(handle);
					fprintf(handle,"\tand (%s <= (%s+w_%s) ) '",__abal_mouse_column,widget_x_position(iptr,2),iptr->Contents.name);
					linefeed(handle);
					fprintf(handle,"\tand (%s <= (%s+h_%s) ))",__abal_mouse_row,widget_y_position(iptr,2),iptr->Contents.name);
					linefeed(handle);
					}
				}
			else if ( iptr->Contents.events->xo_create & _EVENT_IS_FOCUS ) {

				/* Widget has sizes */
				/* ---------------- */
				/* IJM : 21/04/2007 */
				/* ---------------- */
				if ( FixedWindows ) {
					fprintf(handle,"\tif ((%s >= (%s) ) '",__abal_mouse_column,widget_x_position(iptr,0));
					linefeed(handle);
					fprintf(handle,"\tand (%s >= (%s) ) '",__abal_mouse_row,widget_y_position(iptr,0));
					linefeed(handle);
					fprintf(handle,"\tand (%s <= (%s+w_%s) ) '",__abal_mouse_column,widget_x_position(iptr,0),iptr->Contents.name);
					linefeed(handle);
					fprintf(handle,"\tand (%s <= (%s+h_%s) ))",__abal_mouse_row,widget_y_position(iptr,0),iptr->Contents.name);
					linefeed(handle);

					}
				else	{
					fprintf(handle,"\tif ((%s >= (%s) ) '",__abal_mouse_column,widget_x_position(iptr,2));
					linefeed(handle);
					fprintf(handle,"\tand (%s >= (%s) ) '",__abal_mouse_row,widget_y_position(iptr,2));
					linefeed(handle);
					fprintf(handle,"\tand (%s <= (%s+w_%s) ) '",__abal_mouse_column,widget_x_position(iptr,2),iptr->Contents.name);
					linefeed(handle);
					fprintf(handle,"\tand (%s <= (%s+h_%s) ))",__abal_mouse_row,widget_y_position(iptr,2),iptr->Contents.name);
					linefeed(handle);

					}

				}

			else if ( FixedWindows ) {
				fprintf(handle,"\tif ((%s >= %u ) '",__abal_mouse_column,iptr->Contents.x+WindowCol);
				linefeed(handle);
				fprintf(handle,"\tand (%s >= %u ) '",__abal_mouse_row,iptr->Contents.y+WindowRow);
				linefeed(handle);
				fprintf(handle,"\tand (%s <= %u ) '",__abal_mouse_column,(iptr->Contents.x+WindowCol+iptr->Contents.w));
				linefeed(handle);
				fprintf(handle,"\tand (%s <= %u ))",__abal_mouse_row,(iptr->Contents.y+WindowRow+iptr->Contents.h));
				linefeed(handle);
				}
			else	{
				fprintf(handle,"\tif ((%s >= (%s) ) '",__abal_mouse_column,widget_x_position(iptr,1));
				linefeed(handle);
				fprintf(handle,"\tand (%s >= (%s) ) '",__abal_mouse_row,widget_y_position(iptr,1));
				linefeed(handle);
				fprintf(handle,"\tand (%s <= (%s+%u) ) '",__abal_mouse_column,widget_x_position(iptr,1),iptr->Contents.w);
				linefeed(handle);
				fprintf(handle,"\tand (%s <= (%s+%u) ))",__abal_mouse_row,widget_y_position(iptr,1),iptr->Contents.h);
				linefeed(handle);
				}
			indent(handle,2);
			abal_comment(handle,iptr->Contents.name,1);

			/* -----------------------------------------	*/
			/* test if mouse event corresponds to filter 	*/
			/* if widget level mouse button filtering is 	*/
			/* active for the formulaire			*/
			/* -----------------------------------------	*/
			b = abal_widget_mouse_filter(handle,iptr,2);

			/* ------------------------------- */
			/* detect if widget has been shown */
			/* ------------------------------- */
			if ( iptr->Contents.events->xo_hide & _EVENT_IS_POP ) {
				indent(handle,2);	
				fprintf(handle,"if ((p_%s<>0) and ( s_%s<>0))",
					iptr->Contents.name,	
					iptr->Contents.name );
				linefeed(handle);
				}

			/* ----------------------------- */
			/* Detect if widget access is ok */
			/* ----------------------------- */
			if ( with_access ) {
				indent(handle,2);
				if ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME)
					fprintf(handle,"if (a%d_%s=0)",iptr->Contents.radio,iptr->Contents.name);
				else	fprintf(handle,"if (a_%s=0)",iptr->Contents.name);
				linefeed(handle);
				}

			/* ----------------------------------------- */
			/* generate event action and method for this */
			/* ----------------------------------------- */
			widget_mouse_event(handle,iptr,2+with_access);
			abal_mouse_event( handle, iptr, 2+with_access );

			/* ------------------------ */
			/* close widget access test */
			/* ------------------------ */
			if  (with_access) { abal_endif(handle,2); }

			/* ------------------------------------------- */
			/* closure of widget event filtering is active */
			/* ------------------------------------------- */
			if ( b ) { close_abal_filter_select( handle, 2 ); }

			/* --------------------------- */
			/* wudget visible test closure */
			/* --------------------------- */
			if ( iptr->Contents.events->xo_hide & _EVENT_IS_POP ) 
				abal_endif(handle,2);

			/* ------------------------------------ */
			/* closure of mouse detection condition */
			/* ------------------------------------ */
			abal_endif(handle,1);

			/* ------------------------------- */
			/* close tab page validity testing */
			/* ------------------------------- */
			close_abal_page( handle, pn,1 );

			break;
		}
	return;
}

public	int	activate_abal_method( FILE * h, struct form_item * iptr,char * mptr, char* nptr, char * eptr, int type, int margin )
{
	char	*	optr;
	struct	form_control * fptr;
	if (!( iptr ))
		return(0);
	else if (!( fptr = iptr->parent ))
		return(0);
	else if (!( method_is_valid( eptr )))	
		return(0);

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = "o";
	else	optr = "\0";

	indent(h,margin);

	if (!( type & 1 )) /* void call */ {
		if ((iptr->Contents.access & _WIDGET_PUBLIC) && (fptr->isoverlay) && (!( fptr->isprogram ))) {
			fprintf(h,"%s%s%s(%s)",fptr->identifier,mptr,nptr,optr);
			}
		else	{
			fprintf(h,"%s%s(%s)",mptr,nptr,optr);
			}
		}
	else	{
		if ((iptr->Contents.access & _WIDGET_PUBLIC) && (fptr->isoverlay) && (!( fptr->isprogram ))) {
			fprintf(h,"%s= %s%s%s(%s)",__abal_keyword_keycode,fptr->identifier,mptr,nptr,optr);
			}
		else	{
			fprintf(h,"%s= %s%s(%s)",__abal_keyword_keycode,mptr,nptr,optr);
			}
		linefeed(h);
		if (!( type & 2 )) {
			indent(h,2);
			fprintf(h,"If (%s <> -1)",__abal_keyword_keycode);
			linefeed(h);
				abal_retry(h,3);
			abal_endif(h,2);
			}
		}
	linefeed(h);
	return(1);
}

public	int	inline_abal_method( FILE * h,struct form_item * iptr,char * mptr, char* nptr, char * eptr, int type, int margin )
{
	int	l;
	int	status;
	if (!( l = method_is_valid( eptr ) ))
		return(0);
	else	{
		abal_pragma_enter(h,mptr,nptr);
		status = abal_method_body(h,eptr,l,mptr,margin);
		abal_pragma_leave(h,mptr,nptr);
		return( 1 );
		}
}

public	void	abalname_parameter(FILE * handle, char * sptr )
{
	fprintf(handle,",");
	if (!( sptr ))
		quoted_string(handle,"\\0");
	else if ( *(sptr) == _UNQUOTED_STRING )
		variable_value(handle,(sptr+1));
	else 	quoted_string(handle,sptr);
	return;
}

public	void	abalname_length_parameter(FILE * handle, char * sptr )
{
	fprintf(handle,",");
	if (!( sptr ))
		string_length(handle,"\\0");
	else if ( *(sptr) == _UNQUOTED_STRING )
		variable_length(handle,(sptr+1));
	else 	string_length(handle,sptr);
	return;
}

public	void	generate_abal_popup( FILE * h, struct form_item * wptr, int margin )
{
	indent(h,margin++);	
	fprintf(h,"if ((p_%s<>0) and ( s_%s=0))",
		wptr->Contents.name,	
		wptr->Contents.name );
	linefeed(h);
		indent(h,margin);	
		fprintf(h,"s_%s=1",wptr->Contents.name );
		linefeed(h);
		indent(h,margin);	
		fprintf(h,"%s=%s(p_%s,%s,%s)",
			__abal_keyword_status,
			__abal_visual_get,
			wptr->Contents.name,	
			widget_x_position(wptr,0),
			widget_y_position(wptr,0));
		linefeed(h);
	abal_endif(h,--margin);
	return;
}

public	void	generate_abal_popdown( FILE * h, struct form_item * wptr, int margin )
{
	indent(h,margin++);	
	fprintf(h,"if ((p_%s<>0) and ( s_%s<>0))",
		wptr->Contents.name,	
		wptr->Contents.name );
	linefeed(h);
		indent(h,margin);	
		fprintf(h,"s_%s=0",wptr->Contents.name );
		linefeed(h);
		indent(h,margin);	
		fprintf(h,"%s=%s(p_%s,%s,%s)",
			__abal_keyword_status,
			__abal_visual_put,
			wptr->Contents.name,	
			widget_x_position(wptr,0),
			widget_y_position(wptr,0));
		linefeed(h);
	abal_endif(h,--margin);
	return;
}

public	void	generate_abal_hide(FILE * handle, struct form_item * iptr, int paging )
{
	int	pn=0;
	int	tabul=1;

	if (!( paging )) {
		if ((pn = open_abal_page( handle, iptr,1 )) != 0)
			tabul=2;
		else	tabul=1;
		}
	else	tabul = 2;

	abal_invoke_widget_hide(handle,iptr,0,tabul);

	if ( iptr->Contents.events->xo_hide & _EVENT_IS_POP ) {
		generate_abal_popdown(handle,iptr,tabul);
		}

	if (((iptr->Contents.style & _FRAME_TYPE) == _TAB_FRAME)
	&&  ( iptr->Contents.datatype == _WIDGET_OVERLAY ))
		invoke_widget_overlay(handle,iptr,_OVL_ONHIDE);

	close_abal_page( handle, pn,1 );

	return;

}


public void	abal_tab_widget(FILE * handle, struct form_item * iptr, int margin, int option )
{
	abal_widget_function(handle,__abal_visual_tabpage,margin);
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	font_parameter(handle,iptr);
	constant_parameter(handle,iptr );
	constant_length_parameter(handle,iptr);
	if ( iptr->Contents.align & _A_RIGHT )
		option |= 0x0010;
	if ( iptr->Contents.align & _A_LEFT )
		option |= 0x0020;
	option |= (iptr->Contents.align & 0x0F00);
	fprintf(handle,",v_%s,%u)",iptr->Contents.name,option);
	linefeed(handle);
	return;
}

public void	abal_fill_widget(FILE * handle, struct form_item * iptr, int margin )
{
	abal_widget_function(handle,__abal_visual_fill,margin);
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	fprintf(handle,",%u,%u)",iptr->Contents.colour,(iptr->Contents.align&_VFILL_MASK));
	linefeed(handle);
	return;
}

public void	abal_visual_frame_widget(FILE * handle, struct form_item * iptr, int margin )
{
	int	fh=0;
	int	xh=0;

	if (( iptr->Contents.align != _A_NONE   ) 
	&&  ( abal_payload(iptr) != (char *) 0  )
	&&  ( max_payload_size( iptr ) != 0     )) {
		fh = (guifontsize(iptr->Contents.font) >> 8 );
		xh = iptr->Contents.h;
		iptr->Contents.h = fh;
		abal_widget_function(handle,__abal_visual_text,margin);
		widget_position(handle,iptr,0,0);
		widget_font_dimensions(handle,iptr,0,0);
		font_parameter(handle,iptr);
		colour_parameter(handle,iptr);
		constant_parameter(handle,iptr);
		constant_length_parameter(handle,iptr);
		fprintf(handle,",%u)",iptr->Contents.align);
		linefeed(handle);
		iptr->Contents.h = xh;
		}
	else	{
		xh = fh = 0;
		}
	abal_widget_function(handle,__abal_visual_zone,margin);
	widget_position(handle,iptr,0,0);
	if (fh) fprintf(handle,"+%u",fh);
	widget_dimensions(handle,iptr,0,0);
	if (fh) fprintf(handle,"-%u",fh);
	fprintf(handle,",%u)",iptr->Contents.style );
	linefeed(handle);
	return;
}

public void	abal_styled_frame_widget(FILE * handle, struct form_item * iptr, int margin )
{
	/* styled version requires frame to be placed first */
	/* ------------------------------------------------ */
	indent(handle,margin);
	fprintf(handle,"if ( VisualStyle(");
		widget_position(handle,iptr,0,0);
		widget_dimensions(handle,iptr,0,0);
	switch ( iptr->Contents.style & _FRAME_TYPE ) {
		case	_OUTSET_FRAME	: 
			fprintf(handle,",%c%s%c,%u",__QUOTE,"outsetframe",__QUOTE,strlen("outsetframe")); break;
		case	_INSET_FRAME	: 
			fprintf(handle,",%c%s%c,%u",__QUOTE,"insetframe",__QUOTE,strlen("insetframe")); break;
		case	_RIDGE_FRAME	: 
			fprintf(handle,",%c%s%c,%u",__QUOTE,"ridgeframe",__QUOTE,strlen("ridgeframe")); break;
		case	_GROOVE_FRAME	: 
			fprintf(handle,",%c%s%c,%u",__QUOTE,"grooveframe",__QUOTE,strlen("grooveframe")); break;
		}
	fprintf(handle,",%c %c,0) <> 0)",__QUOTE,__QUOTE);
		linefeed(handle);
	abal_visual_frame_widget(handle,iptr,margin+1);
	if (( iptr->Contents.align != _A_NONE   ) 
	&&  ( abal_payload(iptr) != (char *) 0  )
	&&  ( max_payload_size( iptr ) != 0     )) {
		indent(handle,margin); fprintf(handle,"Else"); linefeed(handle);
		indent(handle,margin);
		abal_widget_function(handle,"VisualStyle",margin);
		widget_position(handle,iptr,0,0);
		widget_dimensions(handle,iptr,0,0);
		switch ( iptr->Contents.style & _FRAME_TYPE ) {
			case	_OUTSET_FRAME	: 
				fprintf(handle,",%c%s%c,%u",__QUOTE,"outsettitle",__QUOTE,strlen("outsettitle")); break;
			case	_INSET_FRAME	: 
				fprintf(handle,",%c%s%c,%u",__QUOTE,"insettitle",__QUOTE,strlen("insettitle")); break;
			case	_RIDGE_FRAME	: 
				fprintf(handle,",%c%s%c,%u",__QUOTE,"ridgetitle",__QUOTE,strlen("ridgetitle")); break;
			case	_GROOVE_FRAME	: 
				fprintf(handle,",%c%s%c,%u",__QUOTE,"groovetitle",__QUOTE,strlen("groovetitle")); break;
			}
		constant_parameter(handle,iptr);
		constant_length_parameter(handle,iptr);
		fprintf(handle,")");
		linefeed(handle);
		}
	indent(handle,margin);
	fprintf(handle,"Endif");
	linefeed(handle);
	return;
}

public void	abal_frame_widget(FILE * handle, struct form_item * iptr, int margin )
{
	if ( Context.usestyle ) {
		abal_styled_frame_widget(handle, iptr, margin );
		}
	else	{
		abal_visual_frame_widget(handle,iptr,margin);
		}
	return;
}


public void	abal_text_widget(FILE * handle, struct form_item * iptr, int margin )
{
	abal_widget_function(handle,__abal_visual_text,margin);
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	font_parameter(handle,iptr);
	colour_parameter(handle,iptr);
	constant_parameter(handle,iptr );
	constant_length_parameter(handle,iptr);
	fprintf(handle,",%u)",iptr->Contents.align);
	linefeed(handle);
	return;
}

public void	abal_line_widget(FILE * handle, struct form_item * iptr, int margin )
{
	abal_widget_function(handle,__abal_visual_line,margin);
	widget_position(handle,iptr,0,0);
	widget_bottom(handle,iptr,0,0);
	fprintf(handle,",%u,%u)",iptr->Contents.size,iptr->Contents.colour);
	linefeed(handle);
	return;
}

public void	abal_image_widget(FILE * handle, struct form_item * iptr, int margin )
{
	abal_widget_function(handle,__abal_visual_image,margin);
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	abalname_parameter(handle,abal_payload(iptr));
	abalname_length_parameter(handle,abal_payload(iptr));
	fprintf(handle,",%u)",iptr->Contents.align);
	linefeed(handle);
	return;
}

public void	abal_window_widget(FILE * handle, struct form_item * iptr, int margin )
{
	struct form_control * fptr;
	int	v;
	if (((fptr = iptr->parent) != (struct form_control*) 0)
	&&  (fptr->formflags & _MULTILINGUAL ))
		v = _WINDOW_LANG_BUTTON;
	else	v = 0;
	if (is_xy_modif(iptr)) {
		indent(handle,margin);
		fprintf(handle,"if ((_wref = %u) AND (_href=%u))",w_base_resize(iptr),h_base_resize(iptr));
		linefeed(handle); indent(handle,margin+1);
		fprintf(handle,"x_internal = %u",_WINDOW_MAXIMIZE);
		linefeed(handle); abal_else(handle,margin); indent(handle,margin+1);
		fprintf(handle,"x_internal = %u",_WINDOW_MINIMIZE);
		linefeed(handle); abal_endif(handle,margin);
		}

	abal_widget_function(handle,__abal_visual_window,margin);
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	font_parameter(handle,iptr);
	constant_parameter(handle,iptr );
	constant_length_parameter(handle,iptr);
	abal_hex_parameter(handle,
	((iptr->Contents.align & _A_SHADOW) | v | 
	 (iptr->Contents.align & _A_BOLD ? _WINDOW_EXIT_BUTTON : 0 ) | 
	 (iptr->Contents.align & _A_LINE ? _WINDOW_HELP_BUTTON : 0 )));
	if (is_xy_modif(iptr))
		fprintf(handle," OR x_internal)");
	else	fprintf(handle,")");
	linefeed(handle);
	return;
}

public void	generate_abal_onshow(FILE * handle, struct form_item * iptr, int margin, int focus  )
{
	int	items=0;
	char *	sptr=(char *) 0;

	if ( iptr->Contents.events->xo_hide & _EVENT_IS_POP ) {
		generate_abal_popup(handle,iptr,margin);
		}

	sptr = widget_style_class( iptr, focus );

	if (method_is_valid( sptr  ))  {
		items = abal_visual_element( handle, iptr, sptr, (char *) 0, margin++ );
		}

	switch ((iptr->Contents.style&_FRAME_TYPE)) {

		case	_DATA_FRAME		:
			abal_visual_widget(handle,iptr,margin);
			break;

		case	_FILL_FRAME	:
			abal_fill_widget(handle,iptr,margin);
			break;

		case	_INSET_FRAME	:
		case	_OUTSET_FRAME	:
		case	_GROOVE_FRAME	:
		case	_RIDGE_FRAME	:
			abal_frame_widget(handle,iptr,margin);
			break;

		case	_TEXT_FRAME	:
			abal_text_widget(handle,iptr,margin);
			break;
	
		case	_LINE_FRAME	:
			abal_line_widget(handle,iptr,margin);
			break;
	
		case	_IMAGE_FRAME	:
			abal_image_widget(handle,iptr,margin);
			break;
	
		case	_FORM_FRAME	:
		case	_EDIT_FRAME	:
			abal_dialog_show(handle,iptr,0);
			break;

		case	_SELECT_FRAME	:
			abal_select_show(handle,iptr,0);
			break;

		case	_PROGRESS_FRAME	:
			abal_progress_show(handle,iptr,0);
			break;

		case	_SCROLL_FRAME	:
			abal_scroll_show(handle,iptr,0);
			break;

		case	_BUTTON_FRAME	:
			abal_control_show(handle,iptr,__abal_visual_button,0,0);
			break;

		case	_SWITCH_FRAME	:
			abal_control_show(handle,iptr,__abal_visual_switch,1,0);
			break;

		case	_GRAPH_FRAME	:
			abal_control_show(handle,iptr,__abal_visual_graph,1,0);
			break;

		case	_CHECK_FRAME	:
			abal_control_show(handle,iptr,__abal_visual_check,1,0);
			break;

		case	_RADIO_FRAME	:
			abal_control_show(handle,iptr,__abal_visual_radio,1,0);
			break;

		case	_TAB_FRAME	:
			break;

		case	_WINDOW_FRAME	:
			abal_window_widget(handle,iptr,margin);
			break;

		}
	if ( method_is_valid( sptr  ) ) {
		margin--;
		if ( items ) {
			indent(handle,margin);
			fprintf(handle,"Endif");
			linefeed(handle);
			}
		}
	return;
}

private	void	abal_instance_trigger_code( FILE * h, struct form_item * iptr, int margin )
{
	char	prefix[32];
	struct form_control * fptr;
	char		    * sptr;
	if (!( fptr = iptr->parent))
		return;
	else if (!( fptr->formflags & _INTERNATIONAL ))
		return;
	else if (!( fptr->formflags & _MULTILINGUAL ))
		return;

	switch ((iptr->Contents.style&_FRAME_TYPE)) {
		case	_RADIO_FRAME	:
			if (!( sptr = abal_payload(iptr)))
				return;
			sprintf(prefix,"t%u_",iptr->Contents.radio);
			abal_dcl(h,prefix,iptr->Contents.name,_ABAL_WORD,2,0,0,NULL);
			break;

		case	_BUTTON_FRAME	:
		case	_SWITCH_FRAME	:
		case	_CHECK_FRAME	:
		case	_TAB_FRAME	:
			if (!( sptr = abal_payload(iptr)))
				return;
			abal_dcl(h,"t_",iptr->Contents.name,_ABAL_WORD,2,0,0,NULL);
			break;
		}
	return;
}

private	void	generate_abal_trigger_code( FILE * h, struct form_item * iptr, int margin )
{
	struct form_control * fptr;
	char		*	sptr;
	if (!( fptr = iptr->parent))
		return;
	else if (!( fptr->formflags & _INTERNATIONAL ))
		return;
	else if (!( fptr->formflags & _MULTILINGUAL ))
		return;

	switch ((iptr->Contents.style&_FRAME_TYPE)) {
		case	_RADIO_FRAME	:
			if (!( sptr = abal_payload(iptr)))
				return;
			indent(h,margin);
			fprintf(h,"t%u_%s=%s(_VISUAL_TRIGGER",iptr->Contents.radio,iptr->Contents.name,__abal_visual_control);
			break;
		case	_BUTTON_FRAME	:
			if ( iptr->Contents.align & 1 )
				return;
			else if (!( sptr = abal_payload(iptr)))
				return;
			else if ( *sptr == _UNQUOTED_STRING )
				return;

		case	_SWITCH_FRAME	:
		case	_CHECK_FRAME	:
		case	_TAB_FRAME	:
			if (!( sptr = abal_payload(iptr)))
				return;
			indent(h,margin);
			fprintf(h,"t_%s=%s(_VISUAL_TRIGGER",iptr->Contents.name,__abal_visual_control);
			break;
		default			:
			return;
		}
	constant_parameter(h,iptr );
	constant_length_parameter(h,iptr);
	fprintf(h,")");
	linefeed(h);
	return;
}

public void	generate_abal_show(FILE * handle, struct form_item * iptr, int paging  )
{
	int	xh=0;
	int	fh=0;
	char	* tptr;
	int	pn=0;
	int	tabul=1;
	int show_cond=0;
	int sv_align,sv_colour;

	if (!( paging )) {
		if ((pn = open_abal_page( handle, iptr,1 )) != 0)
			tabul=2;
		else	tabul=1;
		}
	else	tabul=2;

	generate_abal_trigger_code(handle, iptr, tabul);

	if ((iptr->Contents.style & _FRAME_TYPE) != _TAB_FRAME) {

		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_BUTTON_FRAME	:
				indent(handle,tabul++);
				fprintf(handle,"if (a_%s = 2)	;** affichage gris‚ si 2",iptr->Contents.name);
				linefeed(handle);

				sv_align = iptr->Contents.align;
				sv_colour = iptr->Contents.colour;

				iptr->Contents.align |= _A_SHADOW;
				iptr->Contents.colour &= 0xFF00;
				iptr->Contents.colour |= standard_grayed;

				if (!( abal_invoke_widget_show(handle,iptr,0, tabul )))
					generate_abal_onshow(handle,iptr,tabul,0);

				iptr->Contents.align = sv_align;
				iptr->Contents.colour = sv_colour;

				indent(handle,--tabul);
				fprintf(handle,"endif");
				linefeed(handle);

				show_cond=1;
				indent(handle,tabul++);
				fprintf(handle,"if (a_%s = 0)	;** affichage normal si 0",iptr->Contents.name);
				linefeed(handle);
				break;

			case	_SELECT_FRAME	:
			case	_EDIT_FRAME	:
			case	_CHECK_FRAME	:
				show_cond=1;
				indent(handle,tabul++);
				fprintf(handle,"if (a_%s <> 1)	;** affichage si diff‚rent de 1",iptr->Contents.name);
				linefeed(handle);
				break;

			case	_SWITCH_FRAME	:
				indent(handle,tabul++);
				fprintf(handle,"if (a_%s = 2)	;** affichage gris‚ si 2",iptr->Contents.name);
				linefeed(handle);

				sv_colour = iptr->Contents.colour;

				iptr->Contents.colour = (standard_grayed << 8) + standard_grayed;

				if (!( abal_invoke_widget_show(handle,iptr,0, tabul )))
					generate_abal_onshow(handle,iptr,tabul,0);

				iptr->Contents.colour = sv_colour;

				indent(handle,--tabul);
				fprintf(handle,"endif");
				linefeed(handle);

				show_cond=1;
				indent(handle,tabul++);
				fprintf(handle,"if (a_%s = 0)	;** affichage normal si 0",iptr->Contents.name);
				linefeed(handle);
				break;			
			
			
			case	_RADIO_FRAME	:
				indent(handle,tabul++);
				fprintf(handle,"if (a%u_%s = 2)	;** affichage gris‚ si 2",iptr->Contents.radio,iptr->Contents.name);
				linefeed(handle);

				sv_colour = iptr->Contents.colour;

				iptr->Contents.colour &= 0xFF00;
				iptr->Contents.colour |= standard_grayed;

				if (!( abal_invoke_widget_show(handle,iptr,0, tabul )))
					generate_abal_onshow(handle,iptr,tabul,0);

				iptr->Contents.colour = sv_colour;
				iptr->Contents.colour &= 0xFF00;
				iptr->Contents.colour |= standard_black;

				indent(handle,--tabul);
				fprintf(handle,"endif");
				linefeed(handle);

				show_cond=1;
				indent(handle,tabul++);
				fprintf(handle,"if (a%u_%s = 0)	;** affichage normal si 0",iptr->Contents.radio,iptr->Contents.name);
				linefeed(handle);
			}
		if (!( abal_invoke_widget_show(handle,iptr,0, tabul )))
			generate_abal_onshow(handle,iptr,tabul,0);

		if (show_cond) {
			indent(handle,--tabul);
			fprintf(handle,"endif");
			linefeed(handle);
			}
		}
	else	{
		if (!( paging & 2 )) {
			abal_tab_widget(handle,iptr,tabul,2);
			if ( iptr->Contents.datatype == _WIDGET_OVERLAY )
				invoke_widget_overlay(handle,iptr,_OVL_ONSHOW);
		 	abal_invoke_widget_show(handle,iptr,0,tabul );
			}
		if ( pn != 0 )
			abal_else(handle,1);
		if (!( paging & 1 )) {
			abal_tab_widget(handle,iptr,tabul,0);
			}
		if ( paging & 2 )
			abal_invoke_widget_hide(handle,iptr,0, tabul );
		close_abal_page( handle, pn,1 );
		return;
		}

	close_abal_page( handle, pn,1 );

	return;

}

public	void	generate_abal_flush(FILE * handle,int i)
{
	indent(handle,i);
	fprintf(handle,"%s (%s(0) <> 0) :: %s :: %s",
		__abal_keyword_while,
		__abal_visual_key,
		__abal_visual_keycode,
		__abal_keyword_wend);
	linefeed(handle);
	return;
}

public	void	abal_button_widget( 
			FILE * h, 
			struct form_item * iptr, 
			int margin, 
			int etat )
{
	abal_widget_function(h,__abal_visual_button,margin);
	widget_position(h,iptr,0,0);
	widget_dimensions(h,iptr,0,0);
	font_parameter(h,iptr);
	colour_parameter(h,iptr);
	constant_parameter(h,iptr );
	constant_length_parameter(h,iptr);
	if ( iptr->Contents.align & 1 )
		etat |= _VISUAL_IMAGE;
	if ( iptr->Contents.align & 2 )
		etat |= _INHIBIT_FRAME;
	if ( iptr->Contents.align & _A_BOLD )
		etat |= _A_BOLD;
	if ( iptr->Contents.align & _A_LINE )
		etat |= _A_LINE;
	if ( iptr->Contents.align & _A_SHADOW )
		etat |= _A_SHADOW;
	abal_hex_parameter(h,etat);
	fprintf(h,")");
	linefeed(h);
	return;
}

public	void	abal_standard_ask(FILE* h, struct form_item * iptr, int margin)
{
	indent(h,margin);
	fprintf(h,"Ask=1,T=ThisLine,X=Next,I=Next,U=Next,D=Next,/03=Next,/12=Next,/0D=Next,/09=Next:Tab(1,1),Atb(AskAtribut),Paint(AskForeGround,AskBackGround),");
	return;
}

public	void	abal_hotkey_ask(FILE* h, struct form_item * iptr, int margin)
{
	indent(h,margin);
	fprintf(h,"Ask=1,(Left(k_%s,Len$(k_%s)))=Next,T=ThisLine,X=Next,I=Next,U=Next,D=Next,/03=Next,/12=Next,/0D=Next,/09=Next:Tab(1,1),Atb(AskAtribut),Paint(AskForeGround,AskBackGround),",iptr->Contents.name,iptr->Contents.name);
	return;
}

public	void	abal_ask(FILE * h, struct form_item * iptr, int margin )
{
	indent(h,margin++);
	fprintf(h,"if ( Len$(k_%s) > 0 )",iptr->Contents.name);
	linefeed(h);

		abal_hotkey_ask(h,iptr,--margin);
		fprintf(h,"%s=b_%s",iptr->Contents.format,iptr->Contents.name);
		linefeed(h);

	indent(h,margin++);
	fprintf(h,"Else");
	linefeed(h);

		abal_standard_ask(h,iptr,--margin);
		fprintf(h,"%s=b_%s",iptr->Contents.format,iptr->Contents.name);
		linefeed(h);

	indent(h,margin++);
	fprintf(h,"Endif");
	linefeed(h);
}

public	void	abal_visual_ask(FILE * h, struct form_item * iptr, int margin )
{
	indent(h,margin);
	abal_widget_viewport(h,iptr );
	linefeed(h);
	abal_ask( h, iptr, margin );
	indent(h,margin);
	fprintf(h,"KeyCode=HotKey");
	linefeed(h);
	indent(h,margin);
	if (!( Context.Form->formflags & _FORM_RC )) 
		fprintf(h,"if (KeyCode=0) : KeyCode=13	; CR si l'utilisateur a fait une saisie");
	else	fprintf(h,"if (KeyCode=0) : KeyCode= 5	; Next if Ask Input OK");
	linefeed(h);
	return;
}

public	void	abal_visual_select(FILE * handle, struct form_item * iptr, int margin )
{
	indent(handle,margin);
	fprintf(handle,"%s=%s(",__abal_keyword_keycode,__abal_visual_select);
		widget_position(handle,iptr,1,1);
		widget_dimensions(handle,iptr,0,0);
		font_parameter(handle,iptr);
		colour_parameter(handle,iptr);
		constant_parameter(handle,iptr );
		constant_length_parameter(handle,iptr);
		fprintf(handle,",v_%s,%u)",iptr->Contents.name,((iptr->Contents.align << 8) | (iptr->Contents.special << 2) | (iptr->Contents.align&_A_BOLD?8:0) | 2)
		);
	linefeed(handle);
	return;
}

public	void	abal_visual_edit(FILE * handle, struct form_item * iptr, int margin )
{
	indent(handle,margin);
	fprintf(handle,"%s=%s(",__abal_keyword_keycode,__abal_visual_edit);
		widget_position(handle,iptr,1,1);
		widget_dimensions(handle,iptr,0,0);
		font_parameter(handle,iptr);
		fprintf(handle,",b_%s",iptr->Contents.name);
		length_parameter(handle,iptr->Contents.size);
		fprintf(handle,",%u)",	( (iptr->Contents.align & 0x0F0F) 
				      	| (iptr->Contents.special & 1 ? 0x0400:0) 
					| ( iptr->Contents.cursor << 4)) );
	linefeed(handle);
	return;
}

public	void	abal_visual_editshow(FILE * handle, struct form_item * iptr, int margin )
{
	indent(handle,margin);
	fprintf(handle,"%s=%s(",__abal_keyword_status,__abal_visual_edit);
		widget_position(handle,iptr,1,1);
		widget_dimensions(handle,iptr,0,0);
		font_parameter(handle,iptr);
		fprintf(handle,",b_%s",iptr->Contents.name);
		length_parameter(handle,iptr->Contents.size);
		fprintf(handle,",/%04.4X)",(iptr->Contents.align | 0x0800));
	linefeed(handle);
	return;
}

private	void	abal_onfocus_select(FILE * h, struct form_item * iptr, int margin )
{
	abal_visual_select(h,iptr,margin);
}

private	void	abal_onfocus_edit(FILE * h, struct form_item * iptr, int margin )
{
	if (( is_valid_format( iptr->Contents.format ) )
	&&  ( iptr->Contents.align & _A_ASK ))
		abal_visual_ask(h,iptr,margin);
	else	abal_visual_edit(h,iptr,margin);
	refresh_abal_edit(h,iptr,margin+1);
	return;
}

public	void	abal_case_focus(FILE * handle, struct form_item * iptr, int margin )
{
	if ( *nocons )
		abal_case(handle,iptr->Contents.focus,margin);
	else if (!( iptr->Contents.focus )) 
		abal_case(handle,iptr->Contents.focus,margin);
	else	{
		indent(handle,margin);
		if (( iptr->Contents.style & _FRAME_TYPE ) == _RADIO_FRAME)
			fprintf(handle,"%s _%u_%s",__abal_keyword_case,iptr->Contents.radio,iptr->Contents.name);
		else	fprintf(handle,"%s __%s",__abal_keyword_case,iptr->Contents.name);
		linefeed(handle);
		}
	return;
}

public	void	abal_data_get_focus(FILE * h, struct form_item * iptr, int margin )
{
	if (( iptr->Contents.align & 0x000F ) == _VISUAL_FRAME) {
		switch ( iptr->Contents.datatype ) {
			case	_WIDGET_CLASS	:
			case	_WIDGET_POINTER	:
				indent(h,margin);
				fprintf(h,"%s.on_get_focus",iptr->Contents.name);
				linefeed(h);
				indent(h,margin);
				fprintf(h,"%s=%s.keycode",__abal_keyword_keycode,iptr->Contents.name);
				linefeed(h);
				break;
			case	_WIDGET_MODULE	:
				indent(h,margin);
				fprintf(h,"%s = %sOnFocus()",__abal_keyword_keycode,abal_payload(iptr));
				linefeed(h);
				break;
			case	_WIDGET_OVERLAY	:
				invoke_widget_overlay(h,iptr,_OVL_ONFOCUS);
				break;
			}
		}
	return;
}

public	void	abal_data_lose_focus(FILE * h, struct form_item * iptr, int margin )
{
	if (( iptr->Contents.align & 0x000F ) == _VISUAL_FRAME) {
		switch ( iptr->Contents.datatype ) {
			case	_WIDGET_CLASS	:
			case	_WIDGET_POINTER	:
				if ( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FOCUS ) { 
					indent(h,margin);
					fprintf(h,"%s=%s.on_lose_focus",__abal_keyword_keycode,iptr->Contents.name);
					linefeed(h);
					}
				break;
			case	_WIDGET_MODULE	:
				if ( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FOCUS ) { 
					indent(h,margin);
					fprintf(h,"%sOnLosefocus()",abal_payload(iptr));
					linefeed(h);
					}
				break;
			case	_WIDGET_OVERLAY	:
				if ( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FOCUS ) { 
					invoke_widget_overlay(h,iptr,_OVL_ONLOSE);	
					}
				break;
			}
		}
	return;
}

public	void	abal_button_press( FILE * h, struct form_item * iptr )
{
	switch ((iptr->Contents.style & _FRAME_TYPE)) {
		case	_BUTTON_FRAME	:
			abal_onshow_widget(h,iptr,1,4);
			/* abal_button_widget(h,iptr,1,4) */;
			break;
		}
	return;
}
	

public	void	abal_widget_focus(FILE * handle, struct form_item * iptr, char * mptr, int mode )
{
	int	pn=0;
	int	margin=0;

	switch ((iptr->Contents.style & _FRAME_TYPE)) {

		case	_DATA_FRAME	:
			abal_data_get_focus(handle,iptr,margin);
			break;

		case	_FORM_FRAME	:
			if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )) { 
				indent(handle,margin);
				fprintf(handle,"%s=5",__abal_keyword_keycode);
				linefeed(handle);
				}
			else	{
				indent(handle,margin);
				fprintf(handle,__abal_visual_keycode);
				linefeed(handle);
				}
			break;

		case	_SELECT_FRAME	:
			indent(handle,margin);
			fprintf(handle,"%s=%s(",__abal_keyword_keycode,mptr);
			widget_position(handle,iptr,0,0);
			widget_dimensions(handle,iptr,0,0);
			font_parameter(handle,iptr);
			colour_parameter(handle,iptr);
			constant_parameter(handle,iptr );
			constant_length_parameter(handle,iptr);
			fprintf(handle,",v_%s,%u)",iptr->Contents.name,((iptr->Contents.align << 8) | (iptr->Contents.special << 2) | 2));
			break;

		case	_BUTTON_FRAME	:
			if ( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS ) { 
				abal_onshow_widget(handle,iptr,margin,2);
				/* abal_button_widget(handle,iptr,margin,2); */

				/* invoke forms stdinput please */
				abal_onfocus_default(handle,iptr,margin);

				abal_onshow_widget(handle,iptr,margin,0);
				/* abal_button_widget(handle,iptr,margin,0); */
				}
			else	{
				indent(handle,margin);
				fprintf(handle,"%s=5",__abal_keyword_keycode);
				linefeed(handle);
				}
			break;

		case	_SWITCH_FRAME	:
		case	_CHECK_FRAME	:

			abal_widget_function(handle,mptr,margin);
			widget_position(handle,iptr,0,0);
			widget_dimensions(handle,iptr,0,0);
			font_parameter(handle,iptr);
			colour_parameter(handle,iptr);
			constant_parameter(handle,iptr );
			constant_length_parameter(handle,iptr);
			if ( mode ) 
				fprintf(handle,",((v_%s or 2)",iptr->Contents.name);
			else	fprintf(handle,",(2");
			fprintf(handle," or /%04.4X))",(( iptr->Contents.align & 0x0F00) | (( iptr->Contents.align & 0x000F) << 4)));
			linefeed(handle);

		case	_GRAPH_FRAME	:
		case	_RADIO_FRAME	:
			if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )) { 
				indent(handle,margin);
				fprintf(handle,"%s=5",__abal_keyword_keycode);
				linefeed(handle);
				}
			else	{
				indent(handle,margin);
				fprintf(handle,__abal_visual_keycode);
				linefeed(handle);
				}

			switch ( (iptr->Contents.style & _FRAME_TYPE) ) {
				case	_RADIO_FRAME	:
				case	_GRAPH_FRAME	:
					break;
				case	_SWITCH_FRAME	:
				case	_CHECK_FRAME	:

					abal_widget_function(handle,mptr,margin);
					widget_position(handle,iptr,0,0);
					widget_dimensions(handle,iptr,0,0);
					font_parameter(handle,iptr);
					colour_parameter(handle,iptr);
					constant_parameter(handle,iptr );
					constant_length_parameter(handle,iptr);
					if ( mode ) 
						fprintf(handle,",(v_%s",iptr->Contents.name);
					else	fprintf(handle,",(0");
					fprintf(handle," or /%04.4X))",(( iptr->Contents.align & 0x0F00) | (( iptr->Contents.align & 0x000F) << 4)));
					linefeed(handle);
					break;

				default			:
					indent(handle,margin);
					fprintf(handle,"%s=%s(",__abal_keyword_status,mptr);
					widget_position(handle,iptr,0,0);
					widget_dimensions(handle,iptr,0,0);
					font_parameter(handle,iptr);
					colour_parameter(handle,iptr);
					constant_parameter(handle,iptr );
					constant_length_parameter(handle,iptr);
					if ( mode ) 
						fprintf(handle,",v_%s)",iptr->Contents.name);
					else	fprintf(handle,",0)");
				}
			break;
			}
	linefeed(handle);
	return;
}

private	void	abal_hint_method(FILE * h, struct form_item * iptr, int margin )
{
	char *	optr;
	char *	sptr;
	if (!( iptr ))
		return;
	else if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS ))
		return;
	else if (!( iptr->parent ))
		return;
	else if (!( iptr->parent->OnHint ))
		return;
	else if (!( method_is_valid((sptr = abal_hint(iptr) )) ))
		return;
	else	{
		if (( Abal_Config.generate_program )
		&&  ( Abal_Config.generate_overlay ))
			optr = "o"; /* __abal_overlay_object; */
		else	optr = "\0";
		indent(h,margin);
		if ( *optr ) {
			fprintf(h,"%s(%s",_METHOD_ONHINT,optr);
			constant_hint_parameter(h,iptr );
			}
		else	{
			fprintf(h,"%s(",_METHOD_ONHINT);
			constant_hint_value(h,iptr );
			}
		fprintf(h,")");
		linefeed(h);
		return;
		}
}

public	void	abal_control_focus(FILE * handle, struct form_item * iptr, char * mptr, int mode )
{
	int	pn=0;
	int	margin=0;

	if (!( iptr ))
		return;
	else if (!( iptr->Contents.focus ))
		return;
	abal_case_focus(handle,iptr,2);
	abal_comment(handle,iptr->Contents.name,3);
	if (!( pn = open_abal_page(handle,iptr,3) ))
		margin = 3;
	else	margin = 4;

	abal_hint_method( handle, iptr, 1 );

	if ( method_is_valid( iptr->Contents.events->on_get_focus ) ) 
		abal_invoke_widget_get_focus(handle,iptr,1,margin );
	else 	abal_widget_focus(handle,iptr,mptr,mode);

	if ( method_is_valid( iptr->Contents.events->on_lose_focus ) ) 
		abal_invoke_widget_lose_focus(handle,iptr,0,margin );

	if ( pn ) {
		indent(handle,3);
		fprintf(handle,"%s :: %s=5",__abal_keyword_else,__abal_keyword_keycode);
		linefeed(handle);
		}
	close_abal_page(handle,pn,3);
	return;
}

public	void	abal_tab_focus(FILE * handle, struct form_item * iptr, int mode )
{
	int	pn;
	int	margin=2;
	abal_case_focus(handle,iptr,2);
	abal_comment(handle,iptr->Contents.name,3);
		if (!( pn = open_abal_page(handle,iptr,3)))
			margin = 3;
		else	margin = 4;
		abal_hint_method( handle, iptr, 1 );
		if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )) {
			if (!( iptr->Contents.events->on_get_focus )) {
				if ( iptr->Contents.datatype != _WIDGET_OVERLAY ) {
					indent(handle,margin);
					fprintf(handle,"%s=5",__abal_keyword_keycode);
					linefeed(handle);
					}
				}
			else	abal_invoke_widget_get_focus(handle,iptr,1,margin );
			}
		else if (!( iptr->Contents.events->on_get_focus )) {
			if ( iptr->Contents.datatype != _WIDGET_OVERLAY ) {
				indent(handle,margin);
				fprintf(handle,__abal_visual_keycode);
				linefeed(handle);
				}
			}
		else	abal_invoke_widget_get_focus(handle,iptr,1,margin );

		if ( iptr->Contents.datatype == _WIDGET_OVERLAY ) {
			invoke_widget_overlay(handle,iptr,_OVL_ONFOCUS);
			}

		if ( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FOCUS ) {
			abal_invoke_widget_lose_focus(handle,iptr,0,margin );
			}

		if ( pn ) {
			indent(handle,3);
			fprintf(handle,"%s :: %s = 5",__abal_keyword_else,__abal_keyword_keycode);
			linefeed(handle);
			}
		close_abal_page(handle,pn,3);
	return;
}

public	void	abal_default_focus(FILE * handle, struct form_item * iptr, int mode )
{
	int	pn;
	int	margin;
	abal_case_focus(handle,iptr,2);
	abal_comment(handle,iptr->Contents.name,3);
		if (!( pn = open_abal_page(handle,iptr,3)))
			margin = 3;
		else	margin = 4;
		abal_hint_method( handle, iptr, 1 );
		if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )) {
			if (!( iptr->Contents.events->on_get_focus )) {
				indent(handle,margin);
				fprintf(handle,"%s=5",__abal_keyword_keycode);
				linefeed(handle);
				}
			else	abal_invoke_widget_get_focus(handle,iptr,1,margin );
			}
		else if (!( method_is_valid( iptr->Contents.events->on_get_focus ) )) {
			abal_onfocus_default(handle,iptr,margin);
			}
		else	abal_invoke_widget_get_focus(handle,iptr,1,margin );

		abal_invoke_widget_lose_focus(handle,iptr,0,margin );

		if ( pn ) {
			indent(handle,3);
			fprintf(handle,"%s :: %s = 5",__abal_keyword_else,__abal_keyword_keycode);
			linefeed(handle);
			}
		close_abal_page(handle,pn,3);
	return;
}



public	void	abal_edit_focus(FILE * h, struct form_item * iptr, int mode )
{
	int	pn;
	int	margin;
	if ( iptr->Contents.datatype == _WIDGET_KONSTANT )
		return;

	calculate_edit_size( &iptr->Contents );
	abal_case_focus(h,iptr,2);
	abal_comment(h,iptr->Contents.name,3);
		if (!( pn = open_abal_page(h,iptr,3) ))
			margin = 3;
		else	margin = 4;
		abal_hint_method( h, iptr, 1 );
		if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )) {
			/* --------------------------------------- */
			/* explicite inhibition of focus reception */
			/* --------------------------------------- */
			if (!( method_is_valid( iptr->Contents.events->on_get_focus ) )) {
				indent(h,margin);
				fprintf(h,"%s=5",__abal_keyword_keycode);
				linefeed(h);
				}
			else	abal_invoke_widget_get_focus(h,iptr,1,margin);
			}

		/* ------------------------------------ */
		/* standard edit widget focus reception */
		/* ------------------------------------ */
		else if (!( method_is_valid( iptr->Contents.events->on_get_focus ) )) {
			abal_onfocus_edit(h,iptr,margin);
			linefeed(h);
			}
		else	abal_invoke_widget_get_focus(h,iptr,1,margin);

		abal_invoke_widget_lose_focus(h,iptr,0,margin );

		if ( pn ) {
			indent(h,3);
			fprintf(h,"%s :: %s=5",__abal_keyword_else,__abal_keyword_keycode);
			linefeed(h);
			}
		close_abal_page(h,pn,3);
	return;
}

public	void	abal_form_losefocus(FILE * h, struct form_item * iptr, int margin, int fields, int nblines )
{
	struct form_control * fptr;
	if (!( fptr = iptr->parent ))
		return;
	indent(h,margin++);
	fprintf(h,"if ( KeyCode = 9 )");
	if (!( fptr->formflags & _FORM_RC ))
		fprintf(h,"or ( KeyCode = 13 )");
	linefeed(h);
		indent(h,margin);
		fprintf(h,"c_%s+=1",iptr->Contents.name);
		linefeed(h);
		indent(h,margin++);
		fprintf(h,"if ( c_%s > %u )",iptr->Contents.name,fields);
		linefeed(h);
			indent(h,margin);
			fprintf(h,"c_%s=1",iptr->Contents.name);
			linefeed(h);
			indent(h,margin);
			fprintf(h,"v_%s+=1",iptr->Contents.name);
			linefeed(h);
			indent(h,margin++);
			fprintf(h,"if ( v_%s > %u )",iptr->Contents.name,nblines);
			linefeed(h);
				indent(h,margin);
				fprintf(h,"v_%s=1",iptr->Contents.name);
				linefeed(h);
			indent(h,--margin);
			fprintf(h,__abal_keyword_endif);
			linefeed(h);
		indent(h,--margin);
		fprintf(h,__abal_keyword_endif);
		linefeed(h);
		indent(h,margin);
		fprintf(h,"KeyCode=0;");
		linefeed(h);
	indent(h,--margin);
	fprintf(h,__abal_keyword_endif);
	linefeed(h);
	return;
}

public	void	abal_onfocus_form(FILE * h, struct form_item * iptr, int margin )
{
	int		f;
	int		fh;
	int		fw;
	int		xfi=0;
	int		yfi=0;
	int		fields=0;
	int		fieldwidth[_MAX_FORM_FIELDS];
	int		linelength=0;
	int		nblines=0;
	char *		xptr;
	int		ecart;
	struct	standard_zone	awz;

	ecart = 2;
	if (!( fw = guifontsize(iptr->Contents.font))) {
		abal_control_focus(h,iptr,__abal_visual_key,1); 
		return;
		}
	else if (!(fh = (fw >> 8))) {
		abal_control_focus(h,iptr,__abal_visual_key,1); 
		return;
		}
	else	fw &= 0x00FF;

	calculate_edit_size( &iptr->Contents );
	calculate_form_lines( iptr, &linelength, &nblines );

	if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) )) {
		abal_control_focus(h,iptr,__abal_visual_key,1); 
		return;
		}

	awz.x = awz.y = awz.w = awz.h = 0;
	if (!( Context.usestyle )) {
		xfi = yfi = 0;
		}
	else if ( resolve_style_margin("tabledata", &awz.y,&awz.w,&awz.h,&awz.x ) != 0) {
		yfi = awz.y;
		xfi = awz.x;
		}
	else	{
		xfi = yfi = 0;
		}

	abal_form_member_alias(h,iptr,(char *) 0,margin);
	linefeed(h);
	indent(h,margin);
	fprintf(h,"%s (c_%s)",__abal_keyword_select,iptr->Contents.name);
	linefeed(h);
	sprintf(namebuffer,"((v_%s-1) and 1)",iptr->Contents.name);
	xptr = allocate_string((namebuffer));
	for ( 	f = 0;
		f < fields;
		f++ ) {
		abal_case(h,f+1,margin);
		if ( iptr->Contents.datatype == _WIDGET_KONSTANT ) {
			indent(h,margin);
			abal_widget_function(h,__abal_visual_text,1);

			/* the pixel column position */
			/* ------------------------- */
			if ( xfi ) 	fprintf(h,"%s+%u,",widget_x_position(iptr,0),xfi+ecart /*(fw/2) */);
			else		fprintf(h,"%s+%u,",widget_x_position(iptr,0),ecart /*(fw/2) */);

			/* the pixel line position */
			/* ----------------------- */
			fprintf(h,"(%s+(v_%s*%u)+2+%u),",widget_y_position(iptr,0),iptr->Contents.name,fh,yfi);

			/* The field pixel width and height */
			/* -------------------------------- */
			fprintf(h,"%u,%u",((fieldwidth[f]-1)*fw),fh);

			/* Font and Colour Parameters */
			/* -------------------------- */
			font_parameter(h,iptr);
			zoned_colour_parameter(h,iptr,xptr );

			/* The zone buffer and Length */
			/* -------------------------- */
			fprintf(h,",m%u_%s",(f+1),iptr->Contents.name);
			length_parameter(h,fieldwidth[f]-1);

			fprintf(h,",%u)",(_A_BOLD | _A_LINE ));
			linefeed(h);

			indent(h,margin+1);
			fprintf(h,__abal_visual_keycode);
			linefeed(h);

			}
		else	{
			/* ----------------------------- */
			/* Generation of the EDIT WIDGET */
			/* ----------------------------- */
			if (( is_valid_format( iptr->Contents.format ) )
			&&  ( iptr->Contents.align & _A_BOLD )) {

				/* Visual Table/Form View Port */
				/* --------------------------- */
				indent(h,margin+1);
				fprintf(h,"%s=%s(",__abal_keyword_status,__abal_visual_viewport);

				/* the pixel column position */
				/* ------------------------- */
				if ( xfi ) 	fprintf(h,"%s+%u,",widget_x_position(iptr,0),xfi+ecart /*(fw/2) */);
				else		fprintf(h,"%s+%u,",widget_x_position(iptr,0),ecart /*(fw/2) */);

				/* the pixel line position */
				/* ----------------------- */
				fprintf(h,"(%s+(v_%s*%u)+2+%u),",widget_y_position(iptr,0),iptr->Contents.name,fh,yfi);

				/* The field pixel width and height */
				/* -------------------------------- */
				fprintf(h,"%u,%u",(fieldwidth[f]*fw),fh);

				/* The font parameter */
				/* ------------------ */
				font_parameter(h,iptr);
				fprintf(h,")");
				linefeed(h);

				/* Visual Table/Form Ask */
				/* --------------------- */
				abal_standard_ask(h,iptr,margin+1);
				abal_member_format_value(h,iptr,(f+1));
				fprintf(h,"=m%u_%s",(f+1),iptr->Contents.name);
				linefeed(h);
				indent(h,margin);
				fprintf(h,"KeyCode=HotKey");
				linefeed(h);
				indent(h,margin);
				fprintf(h,"if (KeyCode=0) : KeyCode=13	; CR si l'utilisateur a fait une saisie");
				linefeed(h);
				}
			else	{
				/* Visual Table/Form Edit */
				/* ---------------------- */
				indent(h,margin+1);
				fprintf(h,"%s=%s(",__abal_keyword_keycode,__abal_visual_edit);

	
				/* the pixel column position */
				/* ------------------------- */
				if ( xfi ) 	fprintf(h,"%s+%u,",widget_x_position(iptr,0),xfi+ecart /*(fw/2) */);
				else		fprintf(h,"%s+%u,",widget_x_position(iptr,0),ecart /*(fw/2) */);

				/* the pixel line position */
				/* ----------------------- */
				fprintf(h,"(%s+(v_%s*%u)+2+%u),",widget_y_position(iptr,0),iptr->Contents.name,fh,yfi);

				/* The field pixel width and height */
				/* -------------------------------- */
				fprintf(h,"%u,%u",((fieldwidth[f]-1)*fw),fh);

				/* The font parameter */
				/* ------------------ */
				font_parameter(h,iptr);

				/* The zone buffer and Length */
				/* -------------------------- */
				fprintf(h,",m%u_%s",(f+1),iptr->Contents.name);
				length_parameter(h,fieldwidth[f]-1);
				fprintf(h,",%u)",(iptr->Contents.align & ~ (_A_SHADOW|_A_BAR)));
				linefeed(h);
				}

			}

		/* ----------------------------- */
		/* Generation of the TEXT WIDGET */
		/* ----------------------------- */
		indent(h,margin);
		abal_widget_function(h,__abal_visual_text,1);

		/* the pixel column position */
		/* ------------------------- */
		if ( xfi ) 	fprintf(h,"%s+%u,",widget_x_position(iptr,0),xfi+ecart /*(fw/2) */);
		else		fprintf(h,"%s+%u,",widget_x_position(iptr,0),ecart /*(fw/2) */);

		/* the pixel line position */
		/* ----------------------- */
		fprintf(h,"(%s+(v_%s*%u)+2+%u),",widget_y_position(iptr,0),iptr->Contents.name,fh,yfi);

		/* The field pixel width and height */
		/* -------------------------------- */
		fprintf(h,"%u,%u",((fieldwidth[f]-1)*fw),fh);

		/* Font and Colour Parameters */
		/* -------------------------- */
		font_parameter(h,iptr);
		zoned_colour_parameter(h,iptr,xptr );

		/* The zone buffer and Length */
		/* -------------------------- */
		fprintf(h,",m%u_%s",(f+1),iptr->Contents.name);
		length_parameter(h,fieldwidth[f]-1);

		fprintf(h,",0)");
		linefeed(h);
		xfi += (fieldwidth[f]*fw);
		}
	if ( xptr )
		liberate( xptr );
	indent(h,margin);
	fprintf(h,"%s",__abal_keyword_endsel);
	linefeed(h);
	return;
}

public	void	abal_form_focus(FILE * h, struct form_item * iptr, int mode )
{
	int		pn;
	int		margin=0;
	int		fw;
	int		fh;
	int		fields=0;
	int		nblines=0;
	int		linelength=0;
	int		fieldwidth[_MAX_FORM_FIELDS];

	if (!( is_valid_format( iptr->Contents.format) )) {
		abal_control_focus(h,iptr,__abal_visual_key,1); 
		return;
		}
	if (!( fw = guifontsize(iptr->Contents.font))) {
		abal_control_focus(h,iptr,__abal_visual_key,1); 
		return;
		}
	else if (!(fh = (fw >> 8))) {
		abal_control_focus(h,iptr,__abal_visual_key,1); 
		return;
		}
	else	fw &= 0x00FF;

	calculate_edit_size( &iptr->Contents );
	calculate_form_lines( iptr, &linelength, &nblines );

	if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) )) {
		abal_control_focus(h,iptr,__abal_visual_key,1); 
		return;
		}
	abal_case_focus(h,iptr,2);
	abal_comment(h,iptr->Contents.name,3);
		if (!(pn = open_abal_page(h,iptr,3)))
			margin=3;
		else	margin=4;
		abal_hint_method( h, iptr, 1 );
		if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )) {
			if (!( method_is_valid( iptr->Contents.events->on_get_focus ) )) {
				indent(h,margin);
				fprintf(h,"%s=5",__abal_keyword_keycode);
				linefeed(h);
				}
			else	abal_invoke_widget_get_focus(h,iptr,1,margin );
			}
		else if (!( method_is_valid( iptr->Contents.events->on_get_focus ) )) {
			abal_onfocus_form( h, iptr, margin );
			}
		else	abal_invoke_widget_get_focus(h,iptr,1,margin );

		if ( method_is_valid( iptr->Contents.events->on_lose_focus ) )
			abal_invoke_widget_lose_focus(h,iptr,0,margin);	

		if ( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FOCUS )
			abal_form_losefocus(h,iptr,margin,fields,nblines);

		if ( pn ) {
			indent(h,(margin-1));
			fprintf(h,"%s :: %s=5",__abal_keyword_else,__abal_keyword_keycode);
			linefeed(h);
			}
		close_abal_page(h,pn,(margin-1));
	return;
}

public	void	generate_abal_focus(FILE * handle, struct form_item * iptr )
{
	char	*	tptr;
	int		pn=0;
	switch ((iptr->Contents.style&_FRAME_TYPE)) {
		case	_DATA_FRAME	:
			abal_control_focus(handle,iptr,abal_payload(iptr),0);
			break;
		case	_FORM_FRAME	:
			abal_form_focus(handle,iptr,3);
			break;
		case	_EDIT_FRAME	:
			abal_edit_focus(handle,iptr,3);
			break;
		case	_SELECT_FRAME	:
			abal_control_focus(handle,iptr,__abal_visual_select,0);
			break;
		case	_BUTTON_FRAME	:
			abal_control_focus(handle,iptr,__abal_visual_button,0);
			break;
		case	_CHECK_FRAME	:
			abal_control_focus(handle,iptr,__abal_visual_check,1);
			break;
		case	_SWITCH_FRAME	:
			abal_control_focus(handle,iptr,__abal_visual_switch,1);
			break;
		case	_GRAPH_FRAME	:
			abal_control_focus(handle,iptr,__abal_visual_graph,1);
			break;
		case	_RADIO_FRAME	:
			abal_control_focus(handle,iptr,__abal_visual_radio,1);
			break;
		case	_TAB_FRAME	:
			abal_tab_focus(handle,iptr,3);
			break;
		default			:
			abal_default_focus(handle,iptr,3);
			break;
		}
	return;

}

public void	alias_redefined_widget( FILE * h, struct form_item * iptr, char * item, int tabstop )
{
	char	* tptr;
	switch ((iptr->Contents.style & _FRAME_TYPE)) {

		case	_FORM_FRAME	:

			if (!( tptr = abal_payload(iptr) ))
				break;

			else if ( *tptr == _UNQUOTED_STRING )
				break;

			indent(h,tabstop);
			fprintf(h,"\tc_%s = %s",iptr->Contents.name,item);
			linefeed(h);
			indent(h,tabstop);
			fprintf(h,"\tv_%s = %s",iptr->Contents.name,item);
			linefeed(h);
			indent(h,tabstop);
			if (is_w_modif(iptr)) {
				fprintf(h,"\tr_%s = Alias( l_%s((%s-1)*nc_%s+1) )",
					iptr->Contents.name,
					iptr->Contents.name, item,iptr->Contents.name );
				}
			else	{
				fprintf(h,"\tr_%s = Alias( l_%s(%s) )",
					iptr->Contents.name,
					iptr->Contents.name, item );
				}
			linefeed(h);
			}
	return;
}


public	int calculate_form_fields( 
		struct form_item * iptr,
		int fieldwidth[], 
		int maxfield, 
		int linelength )
{
	char	*	tptr;
	if (( is_valid_format((tptr = iptr->Contents.format) ))) {
		if ( *tptr == _UNQUOTED_STRING )
			return(0);
		else	return(vformat(iptr->Contents.format, fieldwidth, maxfield, linelength ) );
		}
	else if (!( tptr = abal_payload(iptr) ))
		return(0);
	else if ( *tptr == _UNQUOTED_STRING )
		return(0);
	else	return( vfields(tptr, fieldwidth, maxfield, linelength ));
}

public	int calculate_form_columns( 
		struct form_item * iptr,
		int fieldwidth[], 
		int maxfield, 
		int linelength )
{
	char	*	tptr;
	if (( is_valid_format((tptr = iptr->Contents.format) ))) {
		if ( *tptr == _UNQUOTED_STRING )
			return(0);
		else	return(vcolumns(iptr->Contents.format, fieldwidth, maxfield, linelength ) );
		}
	else if (!( tptr = abal_payload(iptr) ))
		return(0);
	else if ( *tptr == _UNQUOTED_STRING )
		return(0);
	else	return( vfields(tptr, fieldwidth, maxfield, linelength ));
}

public	void	initialise_table_columnwidths( FILE * h , struct form_item * iptr )
{
	int		f;
	int		fw;
	int		surplus=0;
	int		declared=0;
	int		linelength=0;
	int		nblines=0;
	int		fields=0;
	int		fieldwidth[_MAX_FORM_FIELDS];
	struct	form_control * fptr;
	if (!( iptr ))
		return;
	else if (!( fptr = iptr->parent ))
		return; 
	else if (!( fw = guifontsize(iptr->Contents.font) ))
		return;
	else	fw &= 0x00FF;	

	calculate_edit_size( &iptr->Contents );
	calculate_form_lines( iptr, &linelength, &nblines );
	if (!( fields = calculate_form_columns(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
		return;
	for (declared=0,f=0; f < fields; f++ )
		declared += fieldwidth[f];

	if ((surplus = (linelength - declared)) < 0)
		surplus = 0;

	for (f=0; f < fields; f++ ) {
		indent(h,1);
		if (!( fptr->resizeauto ))
			fprintf(h,"cw_%s(%u) = %u",iptr->Contents.name,f+1,fieldwidth[f]);
		else if ( fieldwidth[f] )
			fprintf(h,"cw_%s(%u) = %u",iptr->Contents.name,f+1,fieldwidth[f]);
		else	fprintf(h,"cw_%s(%u) = ((w_%s/%u)-%u)",iptr->Contents.name,f+1,iptr->Contents.name,fw,declared);
		linefeed(h);
		}
	return;	
}

	

public	void	redefine_multiline_widget( FILE * h, struct form_item * iptr, int linelength,int nblines )
{
	char	*	tptr;
	char	*	wptr;
	int		f;
	int		fields=0;
	int		fieldwidth[_MAX_FORM_FIELDS];
	char		prefix[16];
	struct	form_control * fptr;
	if (!( iptr ))
		return;
	else if (!( fptr = iptr->parent ))
		return;
	abal_field(h,"b_",iptr->Contents.name);
	if ((is_w_modif(iptr)) && ((iptr->Contents.style&_FRAME_TYPE) == _FORM_FRAME))
		abal_dcl(h,"l_",iptr->Contents.name,_ABAL_STRING,1,((linelength*1600)/w_base_resize(iptr))*(((nblines+1)*1200)/h_base_resize(iptr)),0,NULL);
	else	abal_dcl(h,"l_",iptr->Contents.name,_ABAL_STRING,linelength,nblines,0,NULL);
	abal_field(h,(char *) 0,(char *) 0);

	switch ((iptr->Contents.style & _FRAME_TYPE)) {

		case	_FORM_FRAME	:

			if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
					break;

			/* Declare Redefined member pointer */
			abal_ptr(h,"r_",iptr->Contents.name,_ABAL_STRING,linelength,0,0);

			if ( fields > 0 ) {
				
				/* Define Table Record */
				abal_field(h,"r_",iptr->Contents.name);
				for (f=0; f < fields; f++ ) {
					sprintf(prefix,"m%u_",(f+1));
					abal_dcl(h,prefix,iptr->Contents.name,_ABAL_STRING,fieldwidth[f],0,0,NULL);
					}
				abal_field(h,(char *) 0,(char *) 0);
				}

			abal_ptr(h,"rs_",iptr->Contents.name,_ABAL_STRING,linelength,0,0);

			if ( fields > 0 ) {
				
				/* Define Table Record */
				abal_field(h,"rs_",iptr->Contents.name);
				for (f=0; f < fields; f++ ) {
					sprintf(prefix,"ms%u_",(f+1));
					abal_dcl(h,prefix,iptr->Contents.name,_ABAL_STRING,fieldwidth[f],0,0,NULL);
					}
				abal_field(h,(char *) 0,(char *) 0);
				abal_dcl(h,"cw_",iptr->Contents.name,_ABAL_WORD, 0,fields,0,"dynamic column widths");
				}
			}

	return;
}

private	void	instance_position_control( FILE * h, struct form_item * iptr )
{
	char	pbuffer[256];
	/* Generate Position and Dimensions Variables */
	if ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME) 
	{
		sprintf(pbuffer,"x%u_",iptr->Contents.radio);
		abal_dcl(h,pbuffer,iptr->Contents.name,_ABAL_WORD,0,0,0,NULL);
		sprintf(pbuffer,"y%u_",iptr->Contents.radio);
		abal_dcl(h,pbuffer,iptr->Contents.name,_ABAL_WORD,0,0,0,NULL);
		sprintf(pbuffer,"w%u_",iptr->Contents.radio);
		abal_dcl(h,pbuffer,iptr->Contents.name,_ABAL_WORD,0,0,0,NULL);
		sprintf(pbuffer,"h%u_",iptr->Contents.radio);
		abal_dcl(h,pbuffer,iptr->Contents.name,_ABAL_WORD,0,0,0,NULL);
		sprintf(pbuffer,"fg%u_",iptr->Contents.radio);
		abal_dcl(h,pbuffer,iptr->Contents.name,_ABAL_WORD,0,0,0,NULL);
		sprintf(pbuffer,"bg%u_",iptr->Contents.radio);
		abal_dcl(h,pbuffer,iptr->Contents.name,_ABAL_WORD,0,0,0,NULL);
	}
	else	
	{
		abal_dcl(h,"x_",iptr->Contents.name,_ABAL_WORD,0,0,0,NULL);
		abal_dcl(h,"y_",iptr->Contents.name,_ABAL_WORD,0,0,0,NULL);
		abal_dcl(h,"w_",iptr->Contents.name,_ABAL_WORD,0,0,0,NULL);
		abal_dcl(h,"h_",iptr->Contents.name,_ABAL_WORD,0,0,0,NULL);
		abal_dcl(h,"fg_",iptr->Contents.name,_ABAL_WORD,0,0,0,NULL);
		abal_dcl(h,"bg_",iptr->Contents.name,_ABAL_WORD,0,0,0,NULL);
	}
	if (!( FixedWindows )) 
	{
		if (( iptr->Contents.style & _FRAME_TYPE ) == _WINDOW_FRAME) 
		{
			sprintf(pbuffer,"x_%s",iptr->Contents.name);
			set_zero_window_column( pbuffer, iptr->Contents.x );	
			sprintf(pbuffer,"y_%s",iptr->Contents.name);
			set_zero_window_line( pbuffer,iptr->Contents.y );	
		}
	}
	return;
}

#include "abaldata.c"

public	int	pixel_payload_size( struct form_item * iptr )
{
	int	i,n;
	char *	sptr;
	int	l=0;
	for (i=0; i < MAXNATLANG; i++ ) {
		if ((!( sptr = iptr->Contents.messages[i] ))
		&&  (!( sptr = iptr->Contents.payload )))
			continue;
		else  if ((n = textsizelen(iptr->Contents.font, sptr, strlen( sptr ))) > l)
			l = n;
		}
	return(l);
}

public	int	max_payload_size( struct form_item * iptr )
{
	int	i,n;
	char *	sptr;
	int	l=0;
	for (i=0; i < MAXNATLANG; i++ ) {
		if ((!( sptr = iptr->Contents.messages[i] ))
		&&  (!( sptr = iptr->Contents.payload )))
			continue;
		else if ((n = strlen( sptr )) > l)
			l = n;
		}
	return(l);
}

public	int	max_hint_size( struct form_item * iptr )
{
	int	i,n;
	char *	sptr;
	int	l=0;
	for (i=0; i < MAXNATLANG; i++ ) {
		if ((!( sptr = iptr->Contents.hmessages[i] ))
		&&  (!( sptr = iptr->Contents.hint )))
			continue;
		else if ((n = strlen( sptr )) > l)
			l = n;
		}
	return(l);
}

public  void	dcl_abal_forms_control( FILE * h, struct form_control * fptr )
{
	abal_dcl(h,"Key","Code",_ABAL_WORD,0,0,0,NULL);
	abal_dcl(h,"Focus","Item",_ABAL_WORD,0,0,0,NULL);
	abal_dcl(h,"Last","Focus",_ABAL_WORD,0,0,0,NULL);
	abal_dcl(h,"Focus","Items",_ABAL_WORD,0,0,0,NULL);
	abal_dcl(h,"__","pi",_ABAL_WORD,0,0,0,NULL);
	abal_dcl(h,"__","si",_ABAL_WORD,0,0,0,NULL);
	abal_dcl(h,"Key","Buffer",_ABAL_STRING,32,0,0,NULL);
	abal_field(h,"Key","Buffer");
	abal_dcl(h,"Key","Value",_ABAL_BYTE,1,32,0,NULL);
	abal_dcl(h,"Ask","ForeGround",_ABAL_WORD,0,0,0,NULL);
	abal_dcl(h,"Ask","BackGround",_ABAL_WORD,0,0,0,NULL);
	abal_dcl(h,"Ask","Atribut",_ABAL_WORD,0,0,0,NULL);
	abal_dcl(h,"First","Page",_ABAL_WORD,0,0,0,NULL);
	if ( fptr->formflags & _MULTILINGUAL ) {
		abal_dcl(h,"National","Language",_ABAL_WORD,0,0,0,NULL);
		}

	if ( fptr->pages != 0 ) {
		abal_dcl(h,"Focus","Pages",_ABAL_WORD,0,fptr->pages,0,NULL);
		}
	if (fptr->resizeauto) {
		abal_dcl(h,"x_","internal",_ABAL_WORD,0,0,0,"Pour calcul coordonnees");
		abal_dcl(h,"s_","internal",_ABAL_WORD,0,0,0,"Pour calcul coordonnees");
		abal_dcl(h,"y_","internal",_ABAL_WORD,0,0,0,"Pour calcul coordonnees");
		abal_dcl(h,"_w","ref",_ABAL_WORD,0,0,0,"Reference largeur pour redimensionnement");
		abal_dcl(h,"_h","ref",_ABAL_WORD,0,0,0,"Reference largeur pour redimensionnement");
		};
	if (fptr->onlinehelp) {
		abal_dcl(h,"Help","Lines",_ABAL_WORD,0,0,0,"For Online Help Display");
		abal_dcl(h,"Help","Columns",_ABAL_WORD,0,0,0,"For Online Help Display");
		abal_ptr(h,"Help","Text",_ABAL_STRING,64,2,0);
		}
	return;
}

public  int	abal_file_structure( FILE * h, struct form_control * fptr )
{
	char	*		fnptr;
	struct	form_control * 	ffptr;
	struct	form_item *	iptr;
	for (	iptr=fptr->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  
	{
		if (( iptr->Contents.style &_FRAME_TYPE) != _DATA_FRAME )
			continue;
		else if (is_file_Widget( iptr ))
			abal_data_instance(h,iptr);
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			continue;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			continue;
		else	abal_file_structure( h, ffptr );
	}
	return(0);
}

public  int	abal_file_construction( FILE * h, struct form_control * fptr )
{
	char	*		fnptr;
	struct	form_control * 	ffptr;
	struct	form_item * iptr;
	for (	iptr=fptr->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  
	{
		if (( iptr->Contents.style &_FRAME_TYPE) != _DATA_FRAME )
			continue;
		else if (is_file_Widget( iptr ))
			abal_data_construction(h,iptr,1);
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			continue;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			continue;
		else	abal_file_construction( h, ffptr );
	}
	return(0);
}

public  int	abal_file_destruction( FILE * h, struct form_control * fptr )
{
	char	*		fnptr;
	struct	form_control * 	ffptr;
	struct	form_item * iptr;
	for (	iptr=fptr->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  
	{
		if (( iptr->Contents.style &_FRAME_TYPE) != _DATA_FRAME )
			continue;
		else if (is_file_Widget( iptr ))
			abal_data_destruction(h,iptr,1);
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			continue;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			continue;
		else	abal_file_destruction( h, ffptr );
	}
	return(0);
}

public  int	generate_abal_structure( FILE * h, struct form_control * fptr )
{
	int	scrollsymb;
	int	scrolltype;
	char	prefix[32];
	char	*	tptr;
	struct form_item * iptr;
	int	s;
	int	items=0;
	int	fw;
	int	fh;
	int	wt;
	int	linelength=0;
	int	nblines=0;
	int	payloadmax=0;
	int	hintmax=0;

	WindowCol = WindowRow = 0;

	dcl_abal_forms_control(h,fptr);

	declare_abal_fonts(h);

	Signature[(SignatureItems=0)] = 0;

	for (	items=0, iptr=fptr->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {

		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		if (( iptr->Contents.events->xo_create & _EVENT_IS_FOCUS )
		||  (is_xy_modif(iptr)))
			instance_position_control( h, iptr );

		if ( iptr->Contents.events->xo_hide & _EVENT_IS_POP ) {
			if (((iptr->Contents.style & _FRAME_TYPE ) != _WINDOW_FRAME)
			||  (!( fptr->ispopup ))) {
				abal_dcl(h,"s_",iptr->Contents.name,_ABAL_WORD,0,0,0,NULL);
				abal_dcl(h,"p_",iptr->Contents.name,_ABAL_WORD,0,0,0,NULL);
				}
			}
		if (( fptr->formflags & _MULTILINGUAL )
		&&  (( payloadmax = max_payload_size( iptr )) != 0)) {
			if (( iptr->Contents.style & _FRAME_TYPE ) == _RADIO_FRAME)
				sprintf(prefix,"msg%u_",iptr->Contents.radio);
			else	strcpy(prefix,"msg_");
			abal_dcl(h,prefix,iptr->Contents.name,_ABAL_STRING,payloadmax,MAXNATLANG,0,NULL);
			abal_instance_trigger_code(h,iptr,1);
			}

		if ( fptr->OnHint ) {
			if ( fptr->formflags & _MULTILINGUAL ) {
				if (!( hintmax = max_hint_size( iptr )))
					hintmax = 1;
				abal_dcl(h,"hint_",iptr->Contents.name,_ABAL_STRING,hintmax,MAXNATLANG,0,NULL);
				}
			}

		switch (((s=iptr->Contents.style)&_FRAME_TYPE)) {

			case	_WINDOW_FRAME	:

				if ( fptr->language == _GENERATE_HTML )
					clear_window_alignment();
				else	calculate_window_alignment( iptr );

				if ((!( iptr->Contents.events->xo_create & _EVENT_IS_FOCUS ))
				&&  (!(is_xy_modif(iptr))))
					instance_position_control( h, iptr );

				if (!( iptr->Contents.events->xo_hide & _EVENT_IS_POP )) {
					abal_dcl(h,"s_",iptr->Contents.name,_ABAL_WORD,0,0,0,NULL);
					abal_dcl(h,"p_",iptr->Contents.name,_ABAL_WORD,0,0,0,NULL);
					}
				break;

			case	_TAB_FRAME	:
				if (!( Abal_Config.page_control )) {
					abal_dcl(h,"Page","Number",_ABAL_WORD,0,0,0,"Numero d'onglet actif");
					Abal_Config.page_control = 1;
					}
				abal_dcl(h,"a_",iptr->Contents.name,_ABAL_WORD, 0,0,0,"access : 0 pour normal, 1 pour invisible, 2 pour gris");
				abal_dcl(h,"v_",iptr->Contents.name,_ABAL_WORD,2,0,0,"Tab Button Offset");
				abal_dcl(h,"l_",iptr->Contents.name,_ABAL_WORD,2,0,0,"Tab Button Limit ");
				if ( iptr->Contents.datatype != _WIDGET_OVERLAY )
					break;
				abal_dcl(h,"b_",iptr->Contents.name,_ABAL_STRING,1024,0,0,"Buffer : Name of the overlay");
				instance_widget_overlay(h,iptr,overlay_interface_count( iptr ));
				break;

			case	_DATA_FRAME	:
				if (( iptr->Contents.align & 0x000F ) == _VISUAL_FRAME)
					abal_dcl(h,"a_",iptr->Contents.name,_ABAL_WORD, 0,0,0,"access : 0 pour normal, 1 pour invisible, 2 pour gris");
				abal_data_instance(h,iptr);
				break;

			case	_PROGRESS_FRAME	:
				switch ( iptr->Contents.datatype ) {
					case	_WIDGET_FLOAT	:
					case	_WIDGET_NUMERIC	: 
					case	_WIDGET_LONG 	: 
						scrollsymb = _SYMBOLIC_LONG;
						scrolltype = _ABAL_LONG; 
						break;
					case	_WIDGET_BYTE 	: 
						scrollsymb = _SYMBOLIC_BYTE;
						scrolltype = _ABAL_BYTE; 
						break;
					case	_WIDGET_VOID 	:
					case	_WIDGET_WORD 	: 
					default		     	: 
						scrollsymb = _SYMBOLIC_WORD;
						scrolltype = _ABAL_WORD; 
						break;
					}
				abal_dcl(h,"v_",iptr->Contents.name,scrolltype,0,0,0,"Value for progress frame");
				abal_dcl(h,"l_",iptr->Contents.name,scrolltype,0,0,0,"Limit for progress frame");
	 			items = add_interface_item( items, iptr, scrollsymb );
	 			items = add_interface_item( items, iptr, scrollsymb );
				break;

			case	_SCROLL_FRAME	:
				switch ( iptr->Contents.datatype ) {
					case	_WIDGET_FLOAT	:
					case	_WIDGET_NUMERIC	: 
					case	_WIDGET_LONG 	: 
						scrollsymb = _SYMBOLIC_LONG;
						scrolltype = _ABAL_LONG; 
						break;
					case	_WIDGET_BYTE 	: 
						scrollsymb = _SYMBOLIC_BYTE;
						scrolltype = _ABAL_BYTE; 
						break;
					case	_WIDGET_VOID 	:
					case	_WIDGET_WORD 	: 
					default		     	: 
						scrollsymb = _SYMBOLIC_WORD;
						scrolltype = _ABAL_WORD; 
						break;
					}
				abal_dcl(h,"a_",iptr->Contents.name,_ABAL_WORD, 0,0,0,"access : 0 pour normal, 1 pour invisible, 2 pour gris");
				abal_dcl(h,"v_",iptr->Contents.name,scrolltype,0,0,0,"Value : actual value of scrool bar");
				abal_dcl(h,"l_",iptr->Contents.name,scrolltype,0,0,0,"limit : page size");
				abal_dcl(h,"m_",iptr->Contents.name,scrolltype,0,0,0,"max : total size");
	 			items = add_interface_item( items, iptr, scrollsymb );
	 			items = add_interface_item( items, iptr, scrollsymb );
	 			items = add_interface_item( items, iptr, scrollsymb );
				break;

			case	_BUTTON_FRAME	:
				abal_dcl(h,"a_",iptr->Contents.name,_ABAL_WORD, 0,0,0,"access : 0 pour normal, 1 pour invisible, 2 pour gris");
				if (( iptr->Contents.datatype != _WIDGET_OVERLAY )
				&&  ( iptr->Contents.datatype != _WIDGET_CHAIN   )
				&&  ( iptr->Contents.datatype != _WIDGET_SYSTEM  )
#ifdef	ABAL32A
				&&  ( iptr->Contents.datatype != _WIDGET_TASK    )
#endif
				&&  ( iptr->Contents.datatype != _WIDGET_LOADGO  ))
					break;
				abal_dcl(h,"b_",iptr->Contents.name,_ABAL_STRING,1024,0,0,"Buffer : parameters for module/overlay/chain or load.go");
				break;

			case	_GRAPH_FRAME	:
				abal_dcl(h,"l_",iptr->Contents.name,_ABAL_WORD,0,0,0,NULL);
				if ( iptr->Contents.datatype != _WIDGET_VOID ) {
					switch ( iptr->Contents.datatype ) {
						case	_WIDGET_BYTE :
							abal_dcl(h,"b_",iptr->Contents.name,_ABAL_STRING,iptr->Contents.w,0,0,NULL);
							abal_field(h,"b_",iptr->Contents.name);
							abal_dcl(h,"v_",iptr->Contents.name,_ABAL_BYTE,1,iptr->Contents.w,0,NULL);
				 			items = add_interface_item( items, iptr, _SYMBOLIC_BYTE );
							break;
						case	_WIDGET_WORD :
							abal_dcl(h,"b_",iptr->Contents.name,_ABAL_STRING,iptr->Contents.w*2,0,0,NULL);
							abal_field(h,"b_",iptr->Contents.name);
							abal_dcl(h,"v_",iptr->Contents.name,_ABAL_WORD,2,iptr->Contents.w,0,NULL);
				 			items = add_interface_item( items, iptr, _SYMBOLIC_WORD );
							break;
						case	_WIDGET_LONG :
							abal_dcl(h,"b_",iptr->Contents.name,_ABAL_STRING,iptr->Contents.w*4,0,0,NULL);
							abal_field(h,"b_",iptr->Contents.name);
							abal_dcl(h,"v_",iptr->Contents.name,_ABAL_LONG,4,iptr->Contents.w,0,NULL);
				 			items = add_interface_item( items, iptr, _SYMBOLIC_LONG );
							break;
						}
					abal_field(h,(char *) 0,(char *) 0);
					}
				else	abal_dcl(h,"b_",iptr->Contents.name,_ABAL_STRING,iptr->Contents.w,0,0,NULL);
				break;

			case	_RADIO_FRAME	:
				sprintf(prefix,"a%u_",iptr->Contents.radio);
				abal_dcl(h,prefix,iptr->Contents.name,_ABAL_WORD, 0,0,0,"access : 0 pour normal, 1 pour invisible, 2 pour gris");
				if ( iptr->Contents.radio != 1 )
					break;

			case	_SELECT_FRAME	:
			case	_CHECK_FRAME	:
			case	_SWITCH_FRAME	:
				if ((iptr->Contents.style & _FRAME_TYPE) != _RADIO_FRAME)
					abal_dcl(h,"a_",iptr->Contents.name,_ABAL_WORD, 0,0,0,"access : 0 pour normal, 1 pour invisible, 2 pour gris");
				abal_dcl(h,"v_",iptr->Contents.name,_ABAL_WORD,0,0,0,"Value : Number of user choice");
	 			items = add_interface_item( items, iptr, _SYMBOLIC_WORD );
				break;

			case	_FORM_FRAME	:
				calculate_edit_size( &iptr->Contents );
				calculate_form_lines( iptr, &linelength, &nblines );
				abal_dcl(h,"a_",iptr->Contents.name,_ABAL_WORD, 0,0,0,"access : 0 pour normal, 1 pour invisible, 2 pour gris");
				abal_dcl(h,"v_",iptr->Contents.name,_ABAL_WORD, 0,0,0,NULL);
				abal_dcl(h,"c_",iptr->Contents.name,_ABAL_WORD, 0,0,0,NULL);
				if (is_w_modif(iptr))	{
					abal_dcl(h,"nc_",iptr->Contents.name,_ABAL_WORD, 0,0,0,"Nombre de colonnes du tableau");
					abal_dcl(h,"b_",iptr->Contents.name,_ABAL_STRING,((linelength*1600)/w_base_resize(iptr))*(((nblines+1)*1200)/h_base_resize(iptr)),0,0,NULL);
					}
				else	{
					if (is_h_modif(iptr)) {
						iptr->Contents.size=((iptr->Contents.size+linelength)*1200)/h_base_resize(iptr);
						nblines=((nblines+1)*1200)/h_base_resize(iptr);
						}
					abal_dcl(h,"b_",iptr->Contents.name,_ABAL_STRING,iptr->Contents.size,0,0,NULL);
					}
				abal_dcl(h,"f_",iptr->Contents.name,_ABAL_WORD, 0,0,0,"formsort : 0 pour rien positif pour numéro de colonne négatif pour numéro de colonne tri décroissant");
				abal_ptr(h,"ls_",iptr->Contents.name,_ABAL_STRING, linelength,256,0);
				abal_ptr(h,"ts_",iptr->Contents.name,_ABAL_WORD, 0,256,0);
				abal_ptr(h,"is_",iptr->Contents.name,_ABAL_WORD, 0,256,0);
				abal_dcl(h,"ns_",iptr->Contents.name,_ABAL_WORD, 0,0,0,"nombre d'elements a trier");
				redefine_multiline_widget(h,iptr,linelength,nblines );
	 			items = add_interface_item( items, iptr, _SYMBOLIC_STRING );
				break;

			case	_EDIT_FRAME	:
				if ( iptr->Contents.align & _A_ASK ) {
					abal_dcl(h,"k_",iptr->Contents.name,_ABAL_STRING,256,0,0,"Ask Hotkey Buffer");
					}
				abal_dcl(h,"a_",iptr->Contents.name,_ABAL_WORD, 0,0,0,"access : 0 pour normal, 1 pour invisible, 2 pour gris");
				calculate_edit_size( &iptr->Contents );
				calculate_form_lines( iptr, &linelength, &nblines );
				if (is_w_modif(iptr)) {
					iptr->Contents.size=((iptr->Contents.size+1)*1600)/w_base_resize(iptr);
					linelength=((linelength)*1200)/w_base_resize(iptr);
					}
				if (is_h_modif(iptr)) {
					iptr->Contents.size=((iptr->Contents.size+linelength)*1200)/h_base_resize(iptr);
					nblines=((nblines)*1200)/h_base_resize(iptr);
					};
				abal_dcl(h,"b_",iptr->Contents.name,_ABAL_STRING,iptr->Contents.size,0,0,"Buffer : user field");
				if ( nblines > 1 ) {
					redefine_multiline_widget(h,iptr,linelength,nblines );
					}
	 			items = add_interface_item( items, iptr, _SYMBOLIC_STRING );
				break;
			}
		}

	SignatureItems = items;

	abal_dcl(h,"Sign","ature",_ABAL_STRING,items+1,0,0,NULL);
	abal_dcl(h,"Sta","tus",_ABAL_WORD,2,0,0,NULL);
	abal_dcl(h,"Mouse","Event",_ABAL_STRING,8,0,0,NULL);
	abal_field(h,"MouseEvent",(char *) 0);
	abal_dcl(h,"Mouse","Type",_ABAL_WORD,0,0,0,NULL);
	abal_dcl(h,"Mouse","Button",_ABAL_WORD,0,0,0,NULL);
	abal_dcl(h,"Mouse","Column",_ABAL_WORD,0,0,0,NULL);
	abal_dcl(h,"Mouse","Row",_ABAL_WORD,0,0,0,NULL);
	abal_field(h,(char *) 0,(char *) 0);
	return(items);
}

public	int	abal_datatype_parameter(
		FILE * h,
		struct form_item * iptr,
		int mode	/* 	0 : instance pointers  , 
					2 : instance parameters, 
					1 : transmit parameters 	*/
		)
{
	switch ( iptr->Contents.datatype ) {

		case	_WIDGET_KONSTANT	:
			if (!( mode & 1 ))
				fprintf(h,"p_%s$=%u",iptr->Contents.name,iptr->Contents.size);
			else	fprintf(h,"p_%u",iptr->Contents.name);
			return(1);

		case	_WIDGET_STRING		:
			if (!( mode  & 1 ))
				fprintf(h,"ptr p_%s$,pl%s%%",iptr->Contents.name,iptr->Contents.name);
			else	fprintf(h,"p_%s,pl%s",iptr->Contents.name,iptr->Contents.name);
			return(1);

		case	_WIDGET_WORD	:
			if ( mode & 2 )
				fprintf(h,"p_%s%%",iptr->Contents.name);
			else if (!( mode & 1 ))
				fprintf(h,"ptr p_%s%%",iptr->Contents.name);
			else	fprintf(h,"p_%s",iptr->Contents.name);
			return(1);

		case	_WIDGET_BYTE	:
			if ( mode & 2 )
				fprintf(h,"p_%s#",iptr->Contents.name);
			else if (!( mode & 1 ))
				fprintf(h,"ptr p_%s#",iptr->Contents.name);
			else	fprintf(h,"p_%s",iptr->Contents.name);
			return(1);

		case	_WIDGET_LONG	:
			if ( mode & 2 )
				fprintf(h,"p_%s:",iptr->Contents.name);
			else if (!( mode & 1 ))
				fprintf(h,"ptr p_%s:",iptr->Contents.name);
			else	fprintf(h,"p_%s",iptr->Contents.name);
			return(1);

		case	_WIDGET_FLOAT	:
		case	_WIDGET_NUMERIC	:
			if (!( mode & 1 ))
				fprintf(h,"ptr p_%s,pl%s%%",iptr->Contents.name,iptr->Contents.name);
			else	fprintf(h,"p_%s,pl%s",iptr->Contents.name,iptr->Contents.name);
			return(1);
		}
	return(0);
}

public	void	construction_parameters
		( 
		FILE * h,
		struct form_control * fptr,
		int mode	/* 	0 : instance parameters, 
					1 : transmit parameters 	*/
		)
{
	int	paging=0;
	int	items=0;
	struct	form_item * iptr;

	if (!( fptr ))	
		return;

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		if (!( iptr->Contents.interfaceitem ))
			continue;
		switch ( iptr->Contents.datatype ) {
			case	_WIDGET_STRING		:
			case	_WIDGET_KONSTANT	:
			case	_WIDGET_WORD		:
			case	_WIDGET_BYTE		:
			case	_WIDGET_LONG		:
			case	_WIDGET_FLOAT		:
			case	_WIDGET_NUMERIC		:
				break;
			default				:
				continue;
			}


		if ( items ) fprintf(h,",");
		items++;

		if ( paging > 5 ) {
			fprintf(h," '");
			linefeed(h); indent(h,1); paging=0;
			}
		else	paging++;

		abal_datatype_parameter(h, iptr, mode );

		}

}

public  void	abal_signature( FILE * h, char * cname, char * fname, int members, struct form_control * fptr )
{
	int	p;
	if (!( *fname ))
		fprintf(h,"proc %s(",cname);
	else	fprintf(h,"proc %s%s(",cname,fname);
	if ( members != 0 ) {
		if ( members == -1 )
			fprintf(h,"gmode%c",0x0025);
		else if (!( fptr )) {
			/* ambiguous pointer ! */
			for (	p=0; p < members; p++ ) {
				if (p>0)
					fprintf(h,",char * pptr%u",p);
				else	fprintf(h," char * pptr%u",p);
				}
			}
		else	construction_parameters( h, fptr,0 );
		}
	
	fprintf(h,") : %% ");	linefeed(h);
	return;
}

public  void	abal_call( FILE * h, char * cname, char * fname, int members, int level, struct form_control * fptr )
{
	int	p;

	indent(h,level);
	if (!( *fname ))
		fprintf(h,"%s(",cname);
	else	fprintf(h,"%s%s(",cname,fname);

	if ( members != 0 ) {
		if (!( fptr )) {
			for (	p=0; p < members; p++ ) {
				if (p>0)
					fprintf(h,",pptr%u",p);
				else	fprintf(h,"pptr%u",p);
				}
			}
		else	construction_parameters(h,fptr,1);
		}
	fprintf(h,")");
	linefeed(h);
	return;
}

public  int	abal_import_widget( FILE * h , struct form_item * iptr, int i ) 
{
	switch ( iptr->Contents.datatype ) {
		case	_WIDGET_FLOAT	:
		case	_WIDGET_NUMERIC	:
		case	_WIDGET_STRING	:
			/* BCD Data Types and STRING DataTypes */
			/* ----------------------------------- */
			indent(h,i); fprintf(h,"if (%s(p_%s)<>0)",__abal_keyword_validptr,iptr->Contents.name);
			linefeed(h);
			indent(h,i+1); fprintf(h,"%s p_%s(pl%s)",__abal_keyword_alter,iptr->Contents.name,iptr->Contents.name);
			linefeed(h);
			indent(h,i+1); fprintf(h,"b_%s = p_%s",iptr->Contents.name,iptr->Contents.name);
			linefeed(h);
			abal_else(h,i);
			indent(h,i+1);
			if ( iptr->Contents.datatype == _WIDGET_STRING ) 
				fprintf(h,"b_%s = %c %c",iptr->Contents.name,__QUOTE,__QUOTE);
			else	fprintf(h,"b_%s = 0",iptr->Contents.name);
			linefeed(h);
			abal_endif(h,i);
			return(1);

		case	_WIDGET_KONSTANT	:
			indent(h,i);
			fprintf(h,"b_%s = p_%s",
				iptr->Contents.name,
				iptr->Contents.name);
			linefeed(h);
			return(1);

		case	_WIDGET_LONG	:
		case	_WIDGET_BYTE	:
		case	_WIDGET_WORD	:
			/* Integer Data Types */
			/* ------------------ */
			indent(h,i); 
			fprintf(h,"if (%s(p_%s)<>0)",
				__abal_keyword_validptr,
				iptr->Contents.name);
			linefeed(h);
			indent(h,i+1);
			if ((iptr->Contents.style & _FRAME_TYPE) == _EDIT_FRAME) {
				fprintf(h,"b_%s = Print((E),p_%s)",
					iptr->Contents.name,
					iptr->Contents.name);
				}
			else	{
				fprintf(h,"v_%s = p_%s",
					iptr->Contents.name,
					iptr->Contents.name);
				}
			linefeed(h);
			abal_else(h,i);
			indent(h,i+1);
			if ((iptr->Contents.style & _FRAME_TYPE) == _EDIT_FRAME) {
				fprintf(h,"b_%s = Print((N2Z),0)",
					iptr->Contents.name,
					iptr->Contents.name);
				}
			else	{
				fprintf(h,"v_%s = 0",iptr->Contents.name);
				}
			linefeed(h);
			abal_endif(h,i);
			return(1);
		} 
	return(0);
}

public  int	abal_import_parameter( FILE * h , struct form_item * iptr, int i ) 
{
	struct	form_control * fptr;
	if (!( iptr->Contents.interfaceitem ))
		return(0);
	else if (!( fptr = iptr->parent ))
		return(0);
	if ((fptr->isprogram) && (fptr->isoverlay)) {
		if (!( iptr->Contents.interfacenumber ))
			return(0);
		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_CHECK_FRAME	:
			case	_RADIO_FRAME	:
			case	_SCROLL_FRAME	:
			case	_PROGRESS_FRAME	:
			case	_SWITCH_FRAME	:
			case	_SELECT_FRAME	:
				indent(h,i);
				fprintf(h,"v_%s = ",iptr->Contents.name);
				fprintf(h,"Conv%c(ArgV(%u))",0x0025,iptr->Contents.interfacenumber);
				linefeed(h);
				return(1);

			case	_BUTTON_FRAME	:
			case	_EDIT_FRAME	:
				indent(h,i);
				fprintf(h,"b_%s = ",iptr->Contents.name);
				fprintf(h,"ArgV(%u)",iptr->Contents.interfacenumber);
				linefeed(h);
				return(1);
			default			:
				return(0);
			}
		}

	return( abal_import_widget(h,iptr,i) );
}

public  int	abal_export_widget( FILE * h , struct form_item * iptr, int i ) 
{
	switch ( iptr->Contents.datatype ) {
		case	_WIDGET_FLOAT	:
		case	_WIDGET_NUMERIC	:
		case	_WIDGET_STRING	:
			/* BCD Data Types and STRING DataTypes */
			/* ----------------------------------- */
			indent(h,i); fprintf(h,"if(%s(p_%s)<>0)",__abal_keyword_validptr,iptr->Contents.name);
			linefeed(h);
			indent(h,i+1); fprintf(h,"%s p_%s(pl%s)",__abal_keyword_alter,iptr->Contents.name,iptr->Contents.name);
			linefeed(h);
			indent(h,i+1); fprintf(h,"p_%s = b_%s",iptr->Contents.name,iptr->Contents.name);
			linefeed(h);
			abal_endif(h,i);
			return(1);

		case	_WIDGET_LONG	:
		case	_WIDGET_BYTE	:
		case	_WIDGET_WORD	:
			/* Integer Data Types */
			/* ------------------ */
			indent(h,i); 
			fprintf(h,"if(%s(p_%s)<>0)",
				__abal_keyword_validptr,
				iptr->Contents.name);
			linefeed(h);
			indent(h,i+1);
			if ((iptr->Contents.style & _FRAME_TYPE) == _EDIT_FRAME) {
				fprintf(h,"p_%s = Conv(b_%s)",
					iptr->Contents.name,
					iptr->Contents.name);
				}
			else	{
				fprintf(h,"p_%s = v_%s",
					iptr->Contents.name,
					iptr->Contents.name);
				}
			linefeed(h);
			abal_endif(h,i);
			return(1);
		} 
	return(0);
}

public  int	abal_export_parameter( FILE * h ,struct form_item * iptr,int i )
{

	if (!( iptr->Contents.interfaceitem ))
		return(0);
	else	return( abal_export_widget(h,iptr,i) );
}

public  void	abal_transfer_parameters( FILE * h , int direction )
{
	int	item=0;
	int	s;
	struct form_item * iptr;
	indent(h,1);
	fprintf(h,"If (%s <> 27)",__abal_keyword_keycode);
	linefeed(h);
	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if ( direction )
			abal_import_parameter(h,iptr,2);
		else	abal_export_parameter(h,iptr,2);
		}
	abal_endif(h,1);
	return;
}

public	void	abal_function_methods( struct form_control * fptr )
{
	struct form_item * iptr;
	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ( method_is_valid( iptr->Contents.events->on_create ) )
			iptr->Contents.events->xo_create 	|= _EVENT_IS_FUNCTION;
		if ( method_is_valid( iptr->Contents.events->on_show ) )
			iptr->Contents.events->xo_show   	|= _EVENT_IS_FUNCTION;
		if ( method_is_valid( iptr->Contents.events->on_get_focus ) )
			iptr->Contents.events->xo_get_focus  	|= _EVENT_IS_FUNCTION;
		if ( method_is_valid( iptr->Contents.events->on_event ) )
			iptr->Contents.events->xo_event  	|= _EVENT_IS_FUNCTION;
		if ( method_is_valid( iptr->Contents.events->on_lose_focus ) )
			iptr->Contents.events->xo_lose_focus   	|= _EVENT_IS_FUNCTION;
		if ( method_is_valid( iptr->Contents.events->on_hide ) )
			iptr->Contents.events->xo_hide   	|= _EVENT_IS_FUNCTION;
		if ( method_is_valid( iptr->Contents.events->on_remove ) )
			iptr->Contents.events->xo_remove 	|= _EVENT_IS_FUNCTION;
		}
	return;
}

public	void	abal_oncreate_methods( FILE * h ,struct	form_control * fptr )
{
	int	public_methods=0;
	struct form_item * iptr;
	if (!( fptr ))
		return;
	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (( iptr->Contents.events->on_create )
		&&  ( iptr->Contents.events->xo_create & _EVENT_IS_FUNCTION ))
			abal_method(h,iptr,iptr->Contents.name,__abal_method_create,iptr->Contents.events->on_create);
		if (!( iptr->Contents.access & _WIDGET_PUBLIC))
			continue;
		else 	{
			abal_public_method(h,iptr->Contents.name,__abal_method_set,iptr,0);
			public_methods++;
			}
		}
	if ( public_methods ) {
		abal_public_methods(h,fptr,__abal_method_set);
		}
	return;
}

public	void	abal_onshow_methods( FILE * h, struct form_control * fptr )
{
	struct form_item * iptr;
	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (( iptr->Contents.events->on_show )
		&&  ( iptr->Contents.events->xo_show & _EVENT_IS_FUNCTION ))
			abal_method(h,iptr,iptr->Contents.name,__abal_method_show,iptr->Contents.events->on_show);
		}

	return;
}

public	void	abal_onget_methods( FILE * h,struct form_control * fptr, char * nptr )
{
	struct form_item * iptr;
	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (( iptr->Contents.events->on_get_focus )
		&&  ( iptr->Contents.events->xo_get_focus & _EVENT_IS_FUNCTION ))
			abal_method(h,iptr,iptr->Contents.name,nptr,iptr->Contents.events->on_get_focus);
		}

	return;
}

public	void	abal_onlose_methods( FILE * h, struct form_control * fptr, char * nptr, int mode )
{
	struct form_item * iptr;
	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if (!( method_is_valid( iptr->Contents.events->on_lose_focus ) ))
			continue;
		else	{
			if (!( mode ))
				abal_method(h,iptr,iptr->Contents.name,nptr,iptr->Contents.events->on_lose_focus);
			else if (( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION ))
				abal_method(h,iptr,iptr->Contents.name,nptr,iptr->Contents.events->on_lose_focus);
			}
		}

	return;
}

public	void	abal_module_trigger( FILE * h, struct form_item * iptr )
{
	struct	form_control * fptr;
	if (!( fptr = iptr->parent ))
		abal_event_trigger(h,iptr);
	else if ( fptr->language != _GENERATE_HTML )
		abal_event_trigger(h,iptr);
	else	web_agent_module_trigger(h,fptr,iptr);
	return;
}

public	void	abal_hyperlink_footer( FILE * h, struct form_item * iptr )
{
	char	*	optr;
	abal_error_abort(h,1,1);
	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = "o";
	else	optr = "\0";
	indent(h,1);
	fprintf(h,"Status = %s%s(%s)",Abal_Config.cname,__abal_method_show,optr);
	linefeed(h);
	abal_returni(h,-1,1);
	abal_endproc(h);
	return;
}

public	void	abal_hyperlink_header( FILE * h, struct form_item * iptr )
{
	char	*	optr;
	int	l;
	char *	eptr;

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = __abal_overlay_object;
	else	optr = "\0";

	linefeed(h);
	fprintf(h,"%s %s%s(%s) : %c ",
		__abal_keyword_proc,
		iptr->Contents.name,__abal_method_event,
		optr,0x0025);
	linefeed(h);

	abal_dcl(h,"h_",iptr->Contents.name,_ABAL_WORD,2,0,0,NULL);
	abal_dcl(h,"e_",iptr->Contents.name,_ABAL_WORD,2,0,0,NULL);
	abal_endloc(h,0);
	
	abal_error_trap(h,1,1);

	if ((l = method_is_valid((eptr = iptr->Contents.events->on_event))) != 0) {
		abal_pragma_enter(h,iptr->Contents.name,__abal_method_event);
		abal_method_body(h,eptr,l,iptr->Contents.name,1);
		abal_pragma_leave(h,iptr->Contents.name,__abal_method_event);
		}
	return;
}

public	void	abal_hyperlink_trigger( FILE * h, struct form_item * iptr )
{
	int	l;
	char	*	sptr;
	struct	form_control * fptr;
	if (!( fptr = iptr->parent ))
		abal_event_trigger(h,iptr);
	else if ( fptr->language == _GENERATE_HTML ) {
		abal_hyperlink_header(h,iptr);
		web_agent_hyperlink_trigger(h,fptr,iptr);
		abal_hyperlink_footer(h,iptr);
		}
	else if (!( sptr = iptr->Contents.format ))
		return;
	else if ( *sptr == _UNQUOTED_STRING ) {
		abal_hyperlink_header(h,iptr);
		indent(h,1);
		fprintf(h,"if (( %s and _MIMO_UP) <> 0)",__abal_mouse_type);
		linefeed(h);
		indent(h,1);
		fprintf(h,"%s = %s(_VISUAL_HELP,",__abal_keyword_status,__abal_visual_control);
		variable_value(h,(sptr+1));
		fprintf(h,",Len$(");
		variable_value(h,(sptr+1));
		fprintf(h,",))");
		linefeed(h);
		abal_endif(h,1);
		liberate( sptr );
		abal_hyperlink_footer(h,iptr);

		}
	else if (!( sptr = allocate_string( sptr )))
		return;
	else if (!( sptr = enforce_extension( sptr, HTM_EXTENSION) ))
		return;
	else	{
		abal_hyperlink_header(h,iptr);
		indent(h,1);
		fprintf(h,"if (( %s and _MIMO_UP) <> 0)",__abal_mouse_type);
		linefeed(h);
		abal_visual_help(h,sptr,1);
		abal_endif(h,1);
		liberate( sptr );
		abal_hyperlink_footer(h,iptr);
		return;
		}
	return;
}

public	void	abal_onevent_methods( FILE * h, struct form_control * fptr )
{
	struct form_item * iptr;

	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {

		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
	
		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_WINDOW_FRAME	:

				abal_event_trigger(h,iptr);

				if ( iptr->Contents.special ) {
					abal_window_driver(h,iptr);
					}
				continue;

			case	_SCROLL_FRAME	:

				if (( iptr->Contents.events->on_event )
				&&  ( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION ))
					abal_method(h,iptr,iptr->Contents.name,__abal_method_event,iptr->Contents.events->on_event);

				abal_scrollbar_driver(h,iptr);
				continue;

			case	_BUTTON_FRAME	:
				if ( iptr->Contents.datatype == _WIDGET_MODULE ) {
					abal_module_trigger(h,iptr);
					continue;
					}
				else if ( iptr->Contents.datatype == _WIDGET_OVERLAY ) {
					abal_overlay_trigger(h,iptr);
					continue;
					}
				else if ( iptr->Contents.datatype == _WIDGET_CHAIN ) {
					abal_program_trigger(h,iptr);
					continue;
					}
				else if ( iptr->Contents.datatype == _WIDGET_LOADGO ) {
					abal_program_trigger(h,iptr);
					continue;
					}
				else if ( iptr->Contents.datatype == _WIDGET_SYSTEM ) {
					abal_program_trigger(h,iptr);
					continue;
					}
#ifdef	ABAL32A
				else if ( iptr->Contents.datatype == _WIDGET_TASK ) {
					abal_task_trigger(h,iptr);
					continue;
					}
#endif
				else if ( iptr->Contents.datatype == _WIDGET_HYPERLINK ) {
					abal_hyperlink_trigger(h,iptr);
					continue;
					}
			default			:
				abal_event_trigger(h,iptr);
			}
		}

	return;
}

public	void	abal_onhide_methods( FILE * h, struct form_control * fptr, char * nptr )
{
	struct form_item * iptr;
	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		if (( iptr->Contents.events->on_hide )
		&&  ( iptr->Contents.events->xo_hide & _EVENT_IS_FUNCTION ))
			abal_method(h,iptr,iptr->Contents.name,nptr,iptr->Contents.events->on_hide);


		}

	return;
}

public	void	abal_onremove_methods( FILE * h, struct form_control * fptr)
{
	int	public_methods=0;
	struct form_item * iptr;
	if (!( fptr ))
		return;
	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (( iptr->Contents.events->on_remove )
		&&  ( iptr->Contents.events->xo_remove & _EVENT_IS_FUNCTION ))
			abal_method(h,iptr,iptr->Contents.name,__abal_method_remove,iptr->Contents.events->on_remove);
		if (!( iptr->Contents.access & _WIDGET_PUBLIC))
			continue;
		else 	{
			abal_public_method(h,iptr->Contents.name,__abal_method_get,iptr,1);
			public_methods++;
			}
		}
	if ( public_methods ) {
		abal_public_methods(h,fptr,__abal_method_get);
		}
	return;
}

public	void	abal_event_methods( FILE * h )
{
	abal_oncreate_methods(h,Context.Form );	
	abal_onshow_methods(h,Context.Form);	
	abal_onget_methods(h,Context.Form,__abal_method_get_focus);	
	abal_onlose_methods(h,Context.Form,__abal_method_lose_focus,1);	
	abal_onevent_methods(h,Context.Form);	
	abal_onhide_methods(h,Context.Form,__abal_method_hide);	
	abal_onremove_methods(h,Context.Form);	
	return;
}

public	void	abal_dependance( FILE * h, char * sptr, int mode )
{
	char *	kptr=(char *) 0;
	int	nature;
	int	i;
	/* Mode : 0 : #user, Mode : != 0 : #include 1 dcl, 2 other, 3 all */

	if (!( sptr )) return;

	while ( *sptr ) {

		/* step over white space */
		while ( *sptr ) {
			if (( *sptr == ' ' )
			||  ( *sptr == '\t')
			||  ( *sptr == '\r')
			||  ( *sptr == '\n'))
				sptr++;
			else	break;
			}
		if (!( *sptr ))	break;

		for ( i=0; i < 128; i++ ) {
			switch ( *(sptr+i) ) {
				case	0	:
				case	' '	:
				case	','	:
				case	';'	:
				case	'\t'	:
				case	'\n'	:
				case	'\r'	:
					break;
				default		:
					workbuffer[i] = *(sptr+i);
					continue;
				}
			break;
			}
		workbuffer[i] = 0;
		if ( *(sptr+i) != 0 ) i++;
		sptr += i;
		for ( i=0; workbuffer[i] != 0; i++ )
			if ( workbuffer[i] == '.' )
				break;

		if ( workbuffer[i] != '.' )
			nature = 2;

		else 	{
			if (( workbuffer[i+1] == 'd' )
			&&  ( workbuffer[i+2] == 'e' )
			&&  ( workbuffer[i+3] == 'f' ))
				nature=0;
			else if (( workbuffer[i+1] == 'a' )
			     &&  ( workbuffer[i+2] == 'p' )
			     &&  ( workbuffer[i+3] == 'l' )) {
				workbuffer[i] =0;
				nature=8;
				}
			else if (( workbuffer[i+1] == 'c' )
			     &&  ( workbuffer[i+2] == 'l' )
			     &&  ( workbuffer[i+3] == 's' ))
				nature=4;
			else if (( workbuffer[i+1] == 'd' )
			     &&  ( workbuffer[i+2] == 'c' )
			     &&  ( workbuffer[i+3] == 'l' ))
				nature=1;
			else	nature=2;
			}
		
		if ((!( mode )) 
		&&  (!( nature & 3  ))) {
			switch ( nature ) {
				case	0 :	kptr = keyword_user; 	break;
				case	4 :	kptr = keyword_include; break;
				case	8 :	kptr = keyword_use; 	break;
				default	  :	kptr = (char *) 0;	break;
				}
			if ( kptr )
				standard_dependance( h, workbuffer, kptr );
			}
		else if ((nature & mode) != 0)
			standard_dependance( h, workbuffer, keyword_include );

		}


}

public 	void	declare_abal_fonts(FILE * h)
{
	if ( Context.RelativeFonts ) 
		abal_dcl(h,"Font","Handle",_ABAL_WORD,2,SING_FONT_MAX,0,NULL);
	return;
}

public  void	logical_abal_font( FILE * h, int fid )
{
	if ( Context.RelativeFonts ) 
		fprintf(h,"FontHandle(%i)",fid);
	else	fprintf(h,"%u",fid);
	return;
}

public	void	initialise_abal_fonts( FILE * h )
{
	int	i;
	if ( Context.RelativeFonts ) {
		for (i=FONT_MIN; i< FONT_MAX; i++ )  {
			indent(h,1);
			logical_abal_font(h,i);
			fprintf(h," = %u",i);
			linefeed(h);
			}
		}
	return;
}

public	void	generate_abal_fonts(FILE * h)
{
	int	f;
	int	i;
	char 	*	guifontname(int);
	char	*	fname;
	struct form_item * iptr;
	int	follow[256];
	struct	form_control * fptr;
	for (i=0; i < 256; i++) follow[i] = 0;
	for (i=FONT_MIN; i< FONT_MAX; i++ ) {
		follow[i] = 1;
		if (!( fname = SingConf->fontname[(i-1)] ))
			continue;

		else if ( Context.RelativeFonts ) {
			indent(h,1);		
			logical_abal_font(h,i);
			fprintf(h," = %s(",__abal_visual_font);
			quoted_string(h,fname);
			fprintf(h,",%u)",strlen(fname));
			linefeed(h); 
			}
		else	{
			fprintf(h,"\tif ( %s(",__abal_visual_font);
				quoted_string(h,fname);
				fprintf(h,",%u) <> %u)",strlen(fname),i);
				linefeed(h); abal_returni(h,40,2); 
			abal_endif(h,1);
			}
		}
	if (!( fptr = Context.Form ))
		return;
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ( follow[(i = iptr->Contents.font) ] )
			continue;
		else if (!( fname = guifontname( i ) ))
			continue;
		else	{
			follow[i] = 1;
			indent(h,1);		
			logical_abal_font(h,i);
			fprintf(h," = %s(",__abal_visual_font);
			quoted_string(h,fname);
			fprintf(h,",%u)",strlen(fname));
			linefeed(h); 
			}
		}
	return;
}

static	int	konvert_integer(char * sptr, int slen )
{
	int	i,l;
	int	c;
	for (l=0, i=0; i < slen; i++ ) {
		if ((c = *(sptr+i)) == ' ' ) {
			if (!( l ))
				continue;
			else	break;
			}
		else if (( c >= '0') && ( c <= '9'))
			l = ((l*10) + ( c - '0'));
		else if ((c == ',') || (c == '(') || ( c == '.' ) || ( c == ')'))
			break;
		}
	return( l );
}

public	void	analyse_variable_expression(
		char * cptr, int clen, 
		int * tptr, int * lptr, 
		int * fptr, int * sptr,
		int * dptr, int mode
		)
{
	int	i;
	int	n;
	int	type=0;
	int	size=0;
	for ( n=0; n < clen; n++ ) {
		switch (*(cptr+n)) {
			case	'#' : type=1; *tptr = _ABAL_BYTE;   *(cptr+n) = 0; break;
			case	'%' : type=1; *tptr = _ABAL_WORD;   *(cptr+n) = 0; break;
			case	':' : type=1; *tptr = _ABAL_LONG;   *(cptr+n) = 0; break;
			case	'$' : type=1; *tptr = _ABAL_STRING; *(cptr+n) = 0; break;
			case	'*' : type=1; *tptr = _ABAL_BCD;    *(cptr+n) = 0; break;
			case	'=' : 
				size = 1;
				*(cptr+n) = 0;
				*lptr = konvert_integer(cptr+(n+1),clen-(n+1)); 
				break;
			case	'.' : 
				*dptr = konvert_integer(cptr+(n+1),clen-(n+1)); 
				break;
			case    '(' : 
				*(cptr+n) = 0;
				*fptr = konvert_integer(cptr+(n+1),clen-(n+1)); 
				break;
			case	')' : *(cptr+n) = ' '; break;
			case	',' : *(cptr+n) = 0;
				*sptr = konvert_integer(cptr+(n+1),clen-(n+1)); 
				break;
			case	'/' :
				*(cptr+n) = ' '; 
			case	' ' :
				for (i=n; i < clen; i++ )
					if ( *(cptr+i) != ' ' )
						break;
				if (!( type )) {
					if ( i < clen )
						*tptr = _ABAL_OBJ;
					else	*tptr = _ABAL_BCD;
					type = 1;
					}
				n = clen;
			}
		}

	if (!( mode ))
		return;

	if (!( type )) 
		*tptr = _ABAL_BCD; 

	if (!( size )) {
		switch ( *tptr ) {
			case	_ABAL_BYTE	: *lptr =  1; break; 
			case	_ABAL_WORD	: *lptr =  2; break; 
			case	_ABAL_LONG	: *lptr =  4; break; 
			case	_ABAL_BCD	: *lptr =  8; break; 
			case	_ABAL_STRING	: *lptr = 15; break; 
			case	_ABAL_OBJ	: *lptr =  0; break;
			}
		}
	return;
}

public	int	abal_production_parameters(struct form_control * fptr)
{
	int		truecolour=0;
	int		autotrad=1;
	int		pnature=0;
	int		usediezemem=0;
	int		usediezefiles=0;
	int		usepragmafile=0;
	int		usediezestack=0;
	int		usediezeheap=0;
	int		usetokensize=0;
	int		uselabelsize=0;
	int		userespectcase=0;
	int		useoptimisetables=0;
	int		exactdimensions=0;

	pnature = program_nature( fptr->isprogram,fptr->isoverlay);
	if ( fptr->abal.flags & 1 ) 
		usediezemem = 1; 
	else	usediezemem = 0;
	if ( fptr->abal.flags & 2 ) 
		usediezefiles = 1; 
	else	usediezefiles = 0;
	if ( fptr->abal.flags & 4 ) 
		usediezestack = 1; 
	else	usediezestack = 0;
	if ( fptr->abal.flags & 8 ) 
		usediezeheap = 1;  
	else	usediezeheap = 0;
	if ( fptr->abal.flags & 16 )
		userespectcase= 1; 
	else	userespectcase= 0;
	if ( fptr->abal.flags & 32 )
		useoptimisetables = 1;
	else	useoptimisetables = 0;
	if ( fptr->abal.flags & 64 )
		usetokensize = 1;
	else	usetokensize = 0;
	if ( fptr->abal.flags & 128 )
		uselabelsize = 1;
	else	uselabelsize = 0;
	if ( fptr->abal.flags & 512 )
		usepragmafile = 1;	
	else	usepragmafile = 0;
	if ( fptr->abal.flags & 256 )
		truecolour=1;
	else	truecolour=0;
	if ( fptr->abal.flags & 1024 )
		exactdimensions=1;
	else	exactdimensions=0;

	switch ( fptr->language ) {
		case	_GENERATE_BAL		: set_abal_path_selection(1); break;
		case	_GENERATE_ABAL		: set_abal_path_selection(2); break;
		}

	if ( accept_abal_production( 
			&fptr->prodname,	&Context.sourcepathitem,
		 	&fptr->identifier, 
			&pnature,		&autotrad,&truecolour,&exactdimensions,
			&TargetBiosMode, 	
			&fptr->dependance,	&fptr->construction,	
			&usediezemem,		&usediezestack,
			&usediezefiles,		&usediezeheap,
			&fptr->abal.diezemem,	&fptr->abal.diezestack,
			&fptr->abal.diezefiles,	&fptr->abal.diezeheap,
			&usepragmafile,		&fptr->abal.pragmafile,
			&userespectcase,	&useoptimisetables,
			&usetokensize,		&uselabelsize,
			&fptr->abal.tokensize,	&fptr->abal.labelsize
			) == 27 ) {
		return(27);
		}
	if (!( fptr->prodname = UsePathSelection( fptr->prodname, Context.sourcepathitem)))
		return(27);

	if ( usediezemem )
		fptr->abal.flags |= 1;
	else	fptr->abal.flags &= ~1;
	if ( usediezefiles )
		fptr->abal.flags |= 2;
	else	fptr->abal.flags &= ~2;
	if ( usediezestack )
		fptr->abal.flags |= 4;
	else	fptr->abal.flags &= ~4;
	if ( usediezeheap )
		fptr->abal.flags |= 8;
	else	fptr->abal.flags &= ~8;
	if ( userespectcase )
		fptr->abal.flags |= 16;
	else	fptr->abal.flags &= ~16;
	if ( useoptimisetables )
		fptr->abal.flags |= 32;
	else	fptr->abal.flags &= ~32;
	if ( usetokensize )
		fptr->abal.flags |= 64;
	else	fptr->abal.flags &= ~64;
	if ( uselabelsize )
		fptr->abal.flags |= 128;
	else	fptr->abal.flags &= ~128;
	if( usepragmafile )
		fptr->abal.flags |= 512;
	else	fptr->abal.flags &= ~512;
	if( truecolour )
		fptr->abal.flags |= 256;
	else	fptr->abal.flags &= ~256;
	if ( exactdimensions )
		fptr->abal.flags |= 1024;
	else	fptr->abal.flags &= ~1024;

	switch ( pnature ) {
		case	_NATURE_PROGRAM :
			fptr->isprogram = 1; 
			fptr->isoverlay = 0;
			break;
		case	_NATURE_OVERLAY :
			fptr->isprogram = 1; 
			fptr->isoverlay = 1;
			break;
		case	_NATURE_MODULE  :
			fptr->isprogram = 0; 
			fptr->isoverlay = 1;
			break;
		case	_NATURE_INCLUDE :
			fptr->isprogram = 0; 
			fptr->isoverlay = 0;
			break;
		}
	return(autotrad);
}

#endif 	/* _SINGABAL_C */
	/* ----------- */


