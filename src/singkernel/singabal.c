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

#define	SING_FONT_MAX 16

private	char *	LanguagePrefix[MAXNATLANG] = { "en","fr","it","es","de","nl","pt","xx" };

extern	int	FixedWindows;


public	char *	language_prefix(int nl)
{
	if (( nl >= 0 ) && ( nl < 8 ))
		return( LanguagePrefix[nl] );
	else	return( "kk" );
}

	

/*	Function Prototypes	*/
/*	-------------------	*/
public	struct	form_item * locate_widget( char * nptr );
public	void	generate_abal_show(FILE * handle, struct form_item * iptr, int paging  );
public	void	declare_abal_fonts(FILE * h);
public	void	abal_error_trap( FILE * h, int i, int level );
public	void	abal_error_abort( FILE * h, int i, int level );
public	void	abal_error_return( FILE * h, char * vptr, int level );
public	int	inline_abal_method( FILE * h,char * mptr, char* nptr, char * eptr, int type,int margin );
public	int	activate_abal_method( FILE * h,char * mptr, char* nptr, char * eptr, int type, int margin );
public	void	construction_parameters(FILE * h,struct form_control * fptr,int mode);
public	void	abal_scrollbar_widget(FILE * handle, struct form_item * iptr, int margin, int focus );
public	void	abal_data_expression( FILE* h, struct form_item * iptr , int keycode, int margin, char * tptr );
public	void	abal_file_member_name(FILE * h,struct form_item * iptr,	int f );
public	void	abal_button_widget( FILE * h, struct form_item * iptr, int margin, int etat );
public	int	is_named_edit( struct form_item * iptr );
public	char *	project_configuration();

#include "abalsynt.c"
#include "aballine.c"

public	void	abal_forms_method_signature(FILE * h, struct form_control * fptr, char * scope, int v)
{
	struct	forms_method 	* mptr;
	char			* optr;
	if (!( fptr ))	return;

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = __abal_overlay_object;
	else	optr = "\0";

	for (	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {
		if ( v ) {
			if (!( mptr->type & _METHOD_PUBLIC ))
				continue;
			else if (!( mptr->type & _METHOD_FUNCTION ))
				continue;
			}
		if (!( mptr->name ))
			continue;
		else if (!( method_is_valid(mptr->signature) )) {
			fprintf(h,"%s %s %s(%s)",
				scope,
				__abal_keyword_proc,
				mptr->name,optr);
			}
		else if (!(*optr )) {
			fprintf(h,"%s %s %s(%s)",
				scope,
				__abal_keyword_proc,
				mptr->name,
				mptr->signature);
			}
		else	{
			fprintf(h,"%s %s %s(%s,%s)",
				scope,
				__abal_keyword_proc,
				mptr->name,
				optr,
				mptr->signature);
			}
		switch ( (mptr->type & _METHOD_TYPE) ) {
			case	_METHOD_VOID	: break;
			case	_METHOD_BYTE	: fprintf(h," : # " ); break;
			case	_METHOD_LONG	: 
			case	_METHOD_WORD	: fprintf(h," : %% "); break;
			case	_METHOD_NUMERIC	: fprintf(h," : =8 "); break; 
			case	_METHOD_CLASS	:
			case	_METHOD_STRING	: fprintf(h," : $ " ); break;
			}
		linefeed(h);
		}
	return;

}

public	void	abal_forms_method_forward(FILE * h, struct form_control * fptr)
{
	abal_forms_method_signature(h,fptr,__abal_keyword_forward,0);
	return;
}

public	void	abal_forms_method_extern(FILE * h, struct form_control * fptr)
{
	abal_forms_method_signature(h,fptr,__abal_keyword_extern,1);
	return;
}

public 	void	constant_length_parameter(FILE * handle, struct form_item * iptr )
{
	fprintf(handle,",%s(",__abal_keyword_len);
	constant_value(handle,iptr);
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
			if (!( method_is_valid((eptr = abal_payload(iptr)))))
				eptr = " ";
			if ( *eptr == _UNQUOTED_STRING )
				continue;
			if (!( fptr->formflags &_MULTILINGUAL )) {
				if (( iptr->Contents.style & _FRAME_TYPE ) == _RADIO_FRAME)
					sprintf(prefix,"msg%u_",iptr->Contents.radio);
				else	strcpy(prefix,"msg_");
			 	abal_string_constant(h,prefix,iptr->Contents.name,abal_payload(iptr));
				}
			else	{
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
			indent(h,margin);
			status = abal_method_line(h,lptr,i,hptr,&feeder);
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
		if ( method_is_valid( mptr->name ) )
			abal_dcl(h,"\0",mptr->name,mptr->type,mptr->size,mptr->first,mptr->second);
		}
	return;
}

public	void	abal_forms_methods(FILE * h, struct form_control * fptr)
{
	struct	forms_method 	* mptr;
	char			* optr;
	int	l;
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
		if (!( method_is_valid( mptr->signature ) ))  {
			fprintf(h,"%s %s(%s)",	
				__abal_keyword_proc,
				mptr->name,optr);
			}
		else if (!(*optr )) {
			fprintf(h,"%s %s(%s)",
				__abal_keyword_proc,
				mptr->name,mptr->signature);
			}
		else	{
			fprintf(h,"%s %s(%s,%s)",	
				__abal_keyword_proc,
				mptr->name,optr,mptr->signature);
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
			abal_pragma_enter(h,"this",mptr->name);
			abal_method_body(h,mptr->text,l,mptr->name,1);
			abal_pragma_leave(h,"this",mptr->name);
			}
		linefeed(h);
		abal_endproc(h);
		linefeed(h);

		}
	return;

}

public	int	abal_method( 
	FILE * h,
	char * mptr, 
	char * nptr, 
	char * eptr  )
{
	int	status=0;
	int	l;
	int	n;
	int	i;
	char	*	optr;
	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = __abal_overlay_object;
	else	optr = "\0";
	if (!( l = method_is_valid( eptr )))
		return(0);
	else	{
		linefeed(h);
		fprintf(h,"%s %s%s(%s) : %c ",__abal_keyword_proc,mptr,nptr,optr,0x0025);
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

public	void	instance_widget_overlay( FILE * h, struct form_item * iptr )
{
	/* -------------------------------------------- */
	/* PTR O$=10 :: F=M,O :: PTR PROC O.M(N) :: F=M	*/
	/* -------------------------------------------- */
	abal_ptr(h,_OVL_PREFIX,iptr->Contents.name,_ABAL_STRING,10,0,0);
	abal_field(h,_OVL_PREFIX,iptr->Contents.name);
	abal_ptr(h,_IMT_PREFIX,iptr->Contents.name,_ABAL_PROC,5,_OVL_METHODS,0);
	abal_field(h,(char *)0,(char *) 0);
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

	fprintf(h,"%s (%s%s(%u))(",
		__abal_keyword_call, _IMT_PREFIX,iptr->Contents.name, method);
	fprintf(h,"%s%s",_OVL_PREFIX,iptr->Contents.name);
	if ( method == _OVL_ONCREATE )  {
		fprintf(h,",%s%s,%s$(%s%s))",
			_BUF_PREFIX,iptr->Contents.name,
			__abal_keyword_len,
			_BUF_PREFIX,iptr->Contents.name);
		}
	else 	fprintf(h,")");
	linefeed(h);

	abal_endif(h,1);
	return;

}


public	void	attach_widget_overlay( FILE * h, struct form_item * iptr )
{
	char *	nptr;
	/* ATTACH O("file.at") */
	/* ------------------- */
	if (( nptr = iptr->Contents.format ) != (char *) 0) {
		if ( *nptr != _UNQUOTED_STRING ) {
			indent(h,1);
			if (!( nptr = allocate_string( nptr ) )) {
				fprintf(h,"allocation failure");
				return;
				}
			else if (!( nptr = enforce_extension( nptr, AT_EXTENSION ) )) {
				fprintf(h,"allocation failure");
				return;
				}
			sprintf(namebuffer,"%c%s%c",0x0022,nptr,0x0022);
			liberate( nptr );
			fprintf(h,"%s %s%s(%s)",__abal_keyword_attach,
				_OVL_PREFIX,iptr->Contents.name,namebuffer);
			linefeed(h);
			}
		else	{
			indent(h,1);
			fprintf(h,"%s %s%s(",
				__abal_keyword_attach,
					_OVL_PREFIX,iptr->Contents.name);
			variable_value(h,(nptr+1));
			fprintf(h,")");
			linefeed(h);
			}
		}
	

	/* O.CREATE */
	/* -------- */
	invoke_widget_overlay(h,iptr,_OVL_ONCREATE);

	return;

}

public	void	abal_invoke_widget_create( FILE * h, struct form_item * iptr, int mode, int margin )
{
	if ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME)
		if(!( iptr = locate_radio_create( iptr->parent,iptr->Contents.name )))
			return;
	if ( iptr->Contents.events.xo_create & _EVENT_IS_FUNCTION ) {
		activate_abal_method(h,iptr->Contents.name,__abal_method_create,iptr->Contents.events.on_create,mode,margin);
		}
	else 	inline_abal_method(h,iptr->Contents.name,__abal_method_create,iptr->Contents.events.on_create,mode,margin);
	return;
}

public	int	abal_invoke_widget_show( FILE * h, struct form_item * iptr, int mode, int margin )
{
	if ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME)
		if(!( iptr = locate_radio_show( iptr->parent,iptr->Contents.name )))
			return(0);
	if ( iptr->Contents.events.xo_show & _EVENT_IS_FUNCTION ) {
		return( activate_abal_method(h,iptr->Contents.name,__abal_method_show,iptr->Contents.events.on_show,mode,margin) );
		}
	else	return( inline_abal_method(h,iptr->Contents.name,__abal_method_show,iptr->Contents.events.on_show,mode,margin) );
	return(0);
}

public	void	abal_invoke_widget_get_focus( FILE * h, struct form_item * iptr, int mode, int margin )
{
	if ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME)
		if(!( iptr = locate_radio_get_focus( iptr->parent,iptr->Contents.name )))
			return;
	if ( iptr->Contents.events.xo_get_focus & _EVENT_IS_FUNCTION ) {
		activate_abal_method(h,iptr->Contents.name,__abal_method_get_focus,iptr->Contents.events.on_get_focus,mode,margin);
		}
	else	inline_abal_method(h,iptr->Contents.name,__abal_method_get_focus,iptr->Contents.events.on_get_focus,mode,margin);
	return;
}

public	void	abal_invoke_widget_event( FILE * h, struct form_item * iptr, int mode, int margin )
{
	if ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME)
		if(!( iptr = locate_radio_event( iptr->parent,iptr->Contents.name )))
			return;
	if ( iptr->Contents.events.xo_event & _EVENT_IS_FUNCTION ) {
		activate_abal_method(h,iptr->Contents.name,__abal_method_event,iptr->Contents.events.on_event,mode,margin);
		}
	else	inline_abal_method(h,iptr->Contents.name,__abal_method_event,iptr->Contents.events.on_event,mode,margin);
	return;
}

public	void	abal_invoke_widget_lose_focus( FILE * h, struct form_item * iptr,int mode, int margin )
{
	if ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME)
		if(!( iptr = locate_radio_lose_focus( iptr->parent,iptr->Contents.name )))
			return;
	if ( iptr->Contents.events.xo_lose_focus & _EVENT_IS_FUNCTION ) {
		activate_abal_method(h,iptr->Contents.name,__abal_method_lose_focus,iptr->Contents.events.on_lose_focus,mode,margin);
		}
	else	inline_abal_method(h,iptr->Contents.name,__abal_method_lose_focus,iptr->Contents.events.on_lose_focus,mode,margin);
	return;
}

public	void	abal_invoke_widget_hide( FILE * h, struct form_item * iptr,int mode, int margin  )
{
	if ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME)
		if(!( iptr = locate_radio_hide( iptr->parent,iptr->Contents.name )))
			return;
	if ( iptr->Contents.events.xo_hide & _EVENT_IS_FUNCTION ) {
			activate_abal_method(h,iptr->Contents.name,__abal_method_hide,iptr->Contents.events.on_hide,mode,margin);
		}
	else	inline_abal_method(h,iptr->Contents.name,__abal_method_hide,iptr->Contents.events.on_hide,mode,margin);
	return;
}

public	void	abal_invoke_widget_remove( FILE * h, struct form_item * iptr, int mode, int margin )
{
	if ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME)
		if(!( iptr = locate_radio_remove( iptr->parent,iptr->Contents.name )))
			return;
	if ( iptr->Contents.events.xo_remove & _EVENT_IS_FUNCTION ) {
		activate_abal_method(h,iptr->Contents.name,__abal_method_remove,iptr->Contents.events.on_remove,mode,margin);
		}
	else	inline_abal_method(h,iptr->Contents.name,__abal_method_remove,iptr->Contents.events.on_remove,mode,margin);
	return;
}

public	void	detach_widget_overlay( FILE * h, struct form_item * iptr )
{
	/* O.REMOVE */
	/* -------- */
	invoke_widget_overlay(h,iptr,_OVL_ONREMOVE);

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

public	void	abal_window_driver( FILE * h, struct form_item * iptr )
{
	char	*	eptr;
	int		l;
	char 	*	mode;
	char 	*	item;
	char	*	optr;
	char	*	ooptr;

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
	abal_dcl(h,"\0","x",_ABAL_WORD,2,0,0);
	abal_dcl(h,"\0","y",_ABAL_WORD,2,0,0);
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
	
	abal_dcl(h,"to",mode,_ABAL_WORD,0,0,0);
	abal_dcl(h,"at",mode,_ABAL_WORD,0,0,0);
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
				fprintf(h,"(((%s - %s) * m_%s) / %s)",
					__abal_mouse_column,
					widget_x_position(iptr,0),
					iptr->Contents.name,
					widget_w_dimension(iptr,0));
				break;
			case	_A_CENTER	:
				fprintf(h,"(((%s - (%s+%s)) * m_%s) / (%s - (2 * %s)))",
					__abal_mouse_column,
					widget_x_position(iptr,0),
					widget_h_dimension(iptr,0),
					iptr->Contents.name,
					widget_w_dimension(iptr,0),
					widget_h_dimension(iptr,0));
				break;
			case	_A_LEFT  	:
				fprintf(h,"(((%s - (%s+%s)) * m_%s) / (%s - %s))",
					__abal_mouse_column,
					widget_x_position(iptr,0),
					widget_h_dimension(iptr,0),
					iptr->Contents.name,
					widget_w_dimension(iptr,0),
					widget_h_dimension(iptr,0));
				break;
			case	_A_RIGHT	:
				fprintf(h,"(((%s - %s) * m_%s) / (%s - %s))",
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
				fprintf(h,"(((%s - %s) * m_%s) / %s )",
					__abal_mouse_row,
					widget_y_position(iptr,0),
					iptr->Contents.name,
					widget_h_dimension(iptr,0));
				break;
			case	_A_CENTER	:
				fprintf(h,"(((%s - (%s+%s)) * m_%s) / (%s - (2 * %s)))",
					__abal_mouse_row,
					widget_y_position(iptr,0),
					widget_w_dimension(iptr,0),
					iptr->Contents.name,
					widget_h_dimension(iptr,0),
					widget_w_dimension(iptr,0));
				break;
			case	_A_LEFT		:
				fprintf(h,"(((%s - (%s+%s)) * m_%s) / (%s - %s))",
					__abal_mouse_row,
					widget_y_position(iptr,0),
					widget_w_dimension(iptr,0),
					iptr->Contents.name,
					widget_h_dimension(iptr,0),
					widget_w_dimension(iptr,0));
				break;
			case	_A_RIGHT	:
				fprintf(h,"(((%s - %s) * m_%s) / (%s - %s))",
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
	if ( method_is_valid(iptr->Contents.events.on_event) ) 
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

public	void	abal_error_abort( FILE * h, int i, int level )
{
	struct	form_control * fptr;
	fprintf(h,"&elabel%u",level);
	linefeed(h);
	indent(h,i);
	fprintf(h,"On Local %s Abort",__abal_keyword_error);
	linefeed(h);
	if (( fptr = Context.Form ) != (struct form_control*) 0) {
		if ( fptr->StandardError ) {
			indent(h,i);
			fprintf(h,"stderror()");
			linefeed(h);
			}
		}
	return;
}
public	void	abal_error_return( FILE * h, char * vptr, int level )
{
	abal_error(h,vptr,level);
	return;
}

public	void	abal_program_trigger( FILE * h, struct form_item * iptr )
{
	char	*	nptr;
	char	*	eptr;
	int		l;
	int		trapper=1;

	char	*	optr;
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

	abal_dcl(h,"h_",iptr->Contents.name,_ABAL_WORD,2,0,0);
	abal_dcl(h,"e_",iptr->Contents.name,_ABAL_WORD,2,0,0);

	abal_endloc(h,0);

	abal_error_trap(h,1,1);

	if ((l = method_is_valid((eptr = iptr->Contents.events.on_event))) != 0) {
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
	     	if ( iptr->Contents.datatype != _WIDGET_SYSTEM ) {
			if (!( nptr = enforce_extension( nptr, AT_EXTENSION ) )) {
				fprintf(h,"allocation failure");
				return;
				}
			}
		fprintf(h,"%s=h_%s,%c%s%c:Next,e_%s",__abal_keyword_assign,
			iptr->Contents.name,0x0022,nptr,0x0022,iptr->Contents.name);
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

public	void	abal_overlay_trigger( FILE * h, struct form_item * iptr )
{
	char	*	eptr;
	int		l;
	int		trapper=1;

	char	*	optr;
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

	instance_widget_overlay(h,iptr);
	abal_endloc(h,0);

	abal_error_trap(h,1,1);

	if ((l = method_is_valid((eptr = iptr->Contents.events.on_event))) != 0) {
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

public	int	abal_forward_method( FILE * h, char * mptr,  char * nptr,  char * eptr )
{
	int	status=0;
	int	l;
	int	n;
	int	i;
	char	*	optr;

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = __abal_overlay_object;
	else	optr = "\0";
	if (!( eptr ))
		return(0);
	else if (( l=strlen(eptr)) > 0 ) {
		fprintf(h,"%s %s %s%s(%s) : %c ",
			__abal_keyword_forward,__abal_keyword_proc,
			mptr,nptr,optr,0x0025);
		linefeed(h);
		return(1);
		}
	else	return(0);

}

public	int	abal_forward_onmethod( FILE * h, char * mptr,  char * nptr )
{
	int	status=0;
	int	l;
	int	n;
	int	i;
	char	*	optr;

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = __abal_overlay_object;
	else	optr = "\0";
	fprintf(h,"%s %s %s%s(%s)",
		__abal_keyword_forward,__abal_keyword_proc,
		mptr,nptr,optr);
	linefeed(h);
	return(1);
}

private	detect_model_object( char * mptr )
{
	char *	nptr;
	FILE * 	hptr;
	if (!( nptr = allocate_string( mptr )))
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
	FILE 	*	hptr=(FILE *)0;
	char	*	nptr=(char *)0;
	char	*	mptr=(char *)0;
	int		i=0;

	if (!( mptr = fptr->construction ))
		return;
	else if (!( mptr = allocate_string( mptr )))
		return;

	else	while ( *mptr == ' ' )
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
		else if ( *(mptr+i) != ' ' ) {
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
		while ( *mptr == ' ' )
			mptr++;
		}
	return;
}

public	void	abal_forward_methods(FILE * h, struct form_control * fptr )
{
	struct	form_item * iptr;
	linefeed(h);
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w))
		&&  (!( iptr->Contents.w)))
			continue;
		else	{
			if (( is_named_edit  ( iptr ) )
			||  ( is_named_select( iptr ) ))
				abal_forward_onmethod(h,iptr->Contents.name,__abal_method_onshow);
			if ( iptr->Contents.events.xo_create & _EVENT_IS_FUNCTION )
				abal_forward_method(h,iptr->Contents.name,__abal_method_create,iptr->Contents.events.on_create);
			if ( iptr->Contents.events.xo_remove & _EVENT_IS_FUNCTION )
				abal_forward_method(h,iptr->Contents.name,__abal_method_remove,iptr->Contents.events.on_remove);
			if ( iptr->Contents.events.xo_show & _EVENT_IS_FUNCTION )
				abal_forward_method(h,iptr->Contents.name,__abal_method_show,iptr->Contents.events.on_show);
			if ( iptr->Contents.events.xo_hide & _EVENT_IS_FUNCTION )
				abal_forward_method(h,iptr->Contents.name,__abal_method_hide,iptr->Contents.events.on_hide);
			if ( iptr->Contents.events.xo_get_focus & _EVENT_IS_FUNCTION )
				abal_forward_method(h,iptr->Contents.name,__abal_method_get_focus,iptr->Contents.events.on_get_focus);
			if ( iptr->Contents.events.xo_lose_focus & _EVENT_IS_FUNCTION )
				abal_forward_method(h,iptr->Contents.name,__abal_method_lose_focus,iptr->Contents.events.on_lose_focus);
			
			if ( Abal_Config.generate_overlay )
				abal_forward_method(h,Abal_Config.cname,__abal_method_lose_focus,iptr->Contents.events.on_lose_focus);

			if ( iptr->Contents.events.xo_event & _EVENT_IS_FUNCTION )
				abal_forward_method(h,iptr->Contents.name,__abal_method_event,iptr->Contents.events.on_event);
			}
		}
	linefeed(h);
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
					fprintf(handle,",(v_%s",iptr->Contents.name);
				else	fprintf(handle,",(0");
				fprintf(handle," or /%04.4X)",(( iptr->Contents.align & 0x0F00) | (( iptr->Contents.align & 0x000F) << 4)));
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
				fprintf(handle,",%u",(iptr->Contents.align << 8));
			default			:
				fprintf(handle,")");
			}
		linefeed(handle);
		}
	return;
}

public	void	abal_visual_widget(FILE * h, struct form_item * iptr, int margin )
{
	if ((iptr->Contents.align & 0x000F) == 2) {
		indent(h,margin);
		fprintf(h,"%s.on_show",iptr->Contents.name);
		linefeed(h);
		}
	return;
}

public	int	abal_onfocus_widget(FILE * h, struct form_item * iptr, int margin )
{

	switch (( iptr->Contents.style & _FRAME_TYPE )) {
		case	_BUTTON_FRAME		:
		case	_CHECK_FRAME		:
		case	_RADIO_FRAME		:
		case	_SWITCH_FRAME		:
		case	_FORM_FRAME		:
		case	_EDIT_FRAME		:
		case	_SELECT_FRAME		:
		case	_SCROLL_FRAME		:
		default				:
			break;
		}
	indent(h,margin);
	fprintf(h,__abal_visual_keycode);
	linefeed(h);
	return(1);

}

public	int	abal_onshow_widget(FILE * h, struct form_item * iptr, int margin )
{

	int	pn;

	if (( iptr->Contents.style & _FRAME_TYPE ) == _TAB_FRAME )
		return(0);

	else	pn = open_abal_page(h,iptr,margin);

	if (method_is_valid( iptr->Contents.stylesheet )) 
		abal_visual_element( h, iptr, (char *) 0, (char *) 0, margin );

	else	

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
			abal_control_show(h,iptr,__abal_visual_button,0,0);
			break;

		case	_CHECK_FRAME		:
			abal_control_show(h,iptr,__abal_visual_check,1,0);
			break;
		
		case	_RADIO_FRAME		:
			abal_control_show(h,iptr,__abal_visual_radio,1,0);
			break;
		
		case	_GRAPH_FRAME		:
			abal_control_show(h,iptr,__abal_visual_graph,1,0);
			break;
		
		case	_SWITCH_FRAME	:
			abal_control_show(h,iptr,__abal_visual_switch,1,0);
			break;
		
		case	_FORM_FRAME		:
		case	_EDIT_FRAME		:
			abal_dialog_show(h,iptr,0);
			break;

		case	_SELECT_FRAME		:
			abal_select_show(h,iptr,0);
			break;

		case	_SCROLL_FRAME		:
			abal_control_show(h,iptr,__abal_visual_scroll,1,0);
			break;

		case	_PROGRESS_FRAME		:
			abal_control_show(h,iptr,__abal_visual_progress,1,0);
			break;


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
	if (!(iptr->Contents.events.xo_show & _EVENT_IS_COND ))
		return(0);
	else if (!(iptr->Contents.events.xo_show & _EVENT_IS_FUNCTION ))
		return(0);
	else	return(1); /*  is_named_widget( iptr ) ); */
}

	
public	void	abal_conditional_show(FILE * handle, struct form_item * iptr, int mode )
{
	char *	tptr;
	int	pn=0;
	int	status=0;
	char	*	optr;

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
			fprintf(handle,"%s %s%s(%s)",__abal_keyword_proc,
				iptr->Contents.name,__abal_method_onshow,optr);
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

	char	*	optr;
	char	*	moptr;

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay )) {
		moptr = "o"; optr = __abal_overlay_object;
		}
	else	{
		moptr = optr = "\0";
		}
	if ((status = is_named_scroll  ( iptr )) != 0) {
		if (!( mode )) {
			fprintf(handle,"\t%s%s(%s)",iptr->Contents.name,__abal_method_onshow,moptr);
			linefeed(handle);
			return;
			}
		else	{
			fprintf(handle,"%s %s%s(%s)",__abal_keyword_proc,iptr->Contents.name,__abal_method_onshow,optr);
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

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay )) {
		moptr = "o"; optr = __abal_overlay_object;
		}
	else	{
		moptr = optr = "\0";
		}

	if ((status = is_named_progress  ( iptr )) != 0) {
		if (!( mode )) {
			fprintf(handle,"\t%s%s(%s)",iptr->Contents.name,__abal_method_onshow,moptr);
			linefeed(handle);
			return;
			}
		else	{
			fprintf(handle,"%s %s%s(%s)",__abal_keyword_proc,iptr->Contents.name,__abal_method_onshow,optr);
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
			fprintf(handle,"\t%s%s(%s)",iptr->Contents.name,__abal_method_onshow,moptr);
			linefeed(handle);
			return;
			}
		else	{
			fprintf(handle,"%s %s%s(%s)",__abal_keyword_proc,iptr->Contents.name,__abal_method_onshow,optr);
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
		fprintf(handle,",/0%x",iptr->Contents.align);
		string_parameter(handle,"()");
		length_parameter(handle,2);
		}
	else	{
		fprintf(handle,",/%x",(iptr->Contents.align | 0x4000));
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
			fprintf(handle,"\t%s%s(%s)",iptr->Contents.name,__abal_method_onshow,moptr);
			linefeed(handle);
			return;
			}
		else	{
			fprintf(handle,"%s %s%s(%s)",__abal_keyword_proc,iptr->Contents.name,__abal_method_onshow,optr);
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
		fprintf(handle,",%u)",iptr->Contents.style );
		linefeed(handle);
		abal_widget_function(handle,__abal_visual_text,1);
		widget_position(handle,iptr,1,1);
		widget_dimensions(handle,iptr,0,0);
		font_parameter(handle,iptr);
		colour_parameter(handle,iptr);
		fprintf(handle,",b_%s",iptr->Contents.name);
		length_parameter(handle,iptr->Contents.size);
		if ( iptr->Contents.datatype == _WIDGET_KONSTANT )
			fprintf(handle,",%u)",iptr->Contents.align );
		else	fprintf(handle,",0)");
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
	calculate_edit_lines( &iptr->Contents, &linelength, &nblines );

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
	fprintf(h,"if ( v_%s < 1 ) :: v_%s  = 0",
		iptr->Contents.name,
		iptr->Contents.name );
	linefeed(h);
	indent(h,margin);
	fprintf(h,"%s :: if ( v_%s > %u ) :: v_%s  = %u :: %s",
		__abal_keyword_else,
		iptr->Contents.name,nblines,
		iptr->Contents.name,nblines,
		__abal_keyword_endif);
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
		fprintf(h,"if ( c_%s < %u )",iptr->Contents.name,(xfi+f+1));
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
	for (	f=0; f < fields; f++ ) { abal_endif(h,--margin); }

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


public	void	abal_initialise_national_language(FILE * h, struct form_control * fptr)
{
	if ( fptr->formflags & _MULTILINGUAL ) {
		if ( Abal_Config.generate_program ) {
			if (!( Abal_Config.generate_overlay )) {
				indent(h,1);
				fprintf(h,"NationalLanguage=%u",fptr->natlang+1);
				linefeed(h);
				indent(h,1);
				fprintf(h,"Status = %s(_VISUAL_LANGUAGE,%c %c,NationalLanguage)",
					__abal_visual_control,0x0022,0x0022);
				linefeed(h);
				}
			else	{
				indent(h,1);
				fprintf(h,"NationalLanguage = %s(_VISUAL_LANGUAGE,%c %c,-1)",
					__abal_visual_control,0x0022,0x0022);
				linefeed(h);
				}
			}
		else	{
			indent(h,1);
			fprintf(h,"NationalLanguage = %s(_VISUAL_LANGUAGE,%c %c,-1)",
				__abal_visual_control,0x0022,0x0022);
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
		fprintf(h,"MouseType = PageNumber :: PageNumber = 0");
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
	fprintf(h,"%s = %s(_VISUAL_LANGUAGE,%c %c,NationalLanguage)",__abal_keyword_status,__abal_visual_control,0x0022,0x0022);
	linefeed(h);
	abal_widget_function(h,__abal_visual_freeze,1);
	fprintf(h,")");
	linefeed(h);

	if (((fptr = iptr->parent) != (struct form_control *) 0)	
	&&  ( fptr->pages != 0 )) {
		indent(h,margin);	
		fprintf(h,"PageNumber = MouseType");
		linefeed(h);
		indent(h,margin);
		fprintf(h,"%s%s(%s)",Abal_Config.cname,__abal_method_show,optr);
		linefeed(h);
		}
	else	{
		indent(h,margin);
		fprintf(h,"%s%s(%s)",Abal_Config.cname,__abal_method_show,optr);
		linefeed(h);
		}

	abal_widget_function_thaw(h,iptr,1);
	return;
}

public	void	abal_help_event(FILE * h, struct form_item * iptr, int margin )
{
	char *	sptr;
	struct form_control * fptr;

	if (!( fptr = iptr->parent ))
		return;
	else if (!( sptr = allocate_string( fptr->prodname )))
		return;
	else if (!( sptr = enforce_extension( sptr, HTM_EXTENSION) ))
		return;
	else	{
		indent(h,margin);
		fprintf(h,"if (( %s and _MIMO_UP) <> 0)",__abal_mouse_type);
		linefeed(h);
		indent(h,margin+1);
		fprintf(h,"%s = %s(_VISUAL_HELP,",__abal_keyword_status,__abal_visual_control);
		quoted_string(h,sptr);
		fprintf(h,",%u)",strlen( sptr ));
		linefeed(h);
		abal_endif(h,1);
		liberate( sptr );
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
			if (!( iptr->Contents.events.mimo )) {
				if (( Abal_Config.generate_program )
				&&  ( Abal_Config.generate_overlay ))
					abal_return(handle,__abal_focus_item,margin);
				else	abal_returni(handle,-1,margin);
				}
			else	{
				abal_select(handle,__abal_mouse_type,margin);
				if ( iptr->Contents.events.mimo & _MIMO_UP ) {
					abal_cases(handle,"_MIMO_UP",margin);
					abal_return_focus(handle,iptr,margin);
					}
				if ( iptr->Contents.events.mimo & _MIMO_DOWN ) {
					abal_cases(handle,"_MIMO_DOWN",margin);
					abal_return_focus(handle,iptr,margin);
					}
				if ( iptr->Contents.events.mimo & _MIMO_MOVE ) {
					abal_cases(handle,"_MIMO_MOVE",margin);
					abal_return_focus(handle,iptr,margin);
					}
				if ( iptr->Contents.events.mimo & _MIMO_WHILE_DOWN ) {	
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
	struct	form_control * fptr;

	if (((fptr = iptr->parent) != (struct form_control*) 0)
	&&   ( fptr->formflags & _MULTILINGUAL))
		v = 1;

	switch ((iptr->Contents.style & _FRAME_TYPE)) {

		case	_WINDOW_FRAME	:

			if ((!( iptr->Contents.events.xo_event & _EVENT_IS_FOCUS ))
			&&  (!( iptr->Contents.events.xo_get_focus & _EVENT_IS_FOCUS )))
				break;

			

			if (!( f = iptr->Contents.font ))
				break;
			else	{
				fh = guifontsize(f);
				fw = (fh & 0x00FF);
				fh >>= 8;
				fh &= 0x00FF;
				}

			if (( iptr->Contents.align & (_A_BOLD | _A_LINE) )
			|| ( v )
			|| ( iptr->Contents.special )) {

				indent(handle,1);
				fprintf(handle,"Select ( %s )",__abal_mouse_type);
				
				}

			if (( iptr->Contents.align & (_A_BOLD | _A_LINE) )
			|| ( v )) {
				indent(handle,1);
				fprintf(handle,"Case _MIMO_UP");
				linefeed(handle);
				}

			if ( iptr->Contents.align & _A_BOLD ) {
				wx = ((iptr->Contents.x+iptr->Contents.w)-(fh+5));
				wy = (iptr->Contents.y+4);

				if ( FixedWindows ) {
					fprintf(handle,"\tif ((%s >= %u ) '",__abal_mouse_column,wx+WindowCol);	
					linefeed(handle);
					fprintf(handle,"\tand (%s >= %u ) '",__abal_mouse_row,wy+WindowRow);
					linefeed(handle);
					fprintf(handle,"\tand (%s <= %u ) '",__abal_mouse_column,wx+fh+WindowCol);
					linefeed(handle);
					fprintf(handle,"\tand (%s <= %u ))",__abal_mouse_row,wy+fh+WindowRow);
					linefeed(handle);
					}
				else	{
					fprintf(handle,"\tif ((%s >= (%s+%u) ) '",__abal_mouse_column,widget_x_position(iptr,1),wx);
					linefeed(handle);
					fprintf(handle,"\tand (%s >= (%s+%u) ) '",__abal_mouse_row,widget_y_position(iptr,1),wy);
					linefeed(handle);
					fprintf(handle,"\tand (%s <= (%s+%u) ) '",__abal_mouse_column,widget_x_position(iptr,1),wx+fh);
					linefeed(handle);
					fprintf(handle,"\tand (%s <= (%s+%u) ))",__abal_mouse_row,widget_y_position(iptr,1),wy+fh);
					linefeed(handle);
					}

				indent(handle,2);
				abal_comment(handle,iptr->Contents.name,1);
				abal_mouse_event( handle, iptr, 2 );
				abal_endif(handle,1);
				}
			if ( iptr->Contents.align & _A_LINE ) {

				hwx = ((iptr->Contents.x+iptr->Contents.w)-((fh*2)+5));
				wy = (iptr->Contents.y+4);

				if ( FixedWindows ) {
					fprintf(handle,"\tif ((%s >= %u ) '",__abal_mouse_column,hwx+WindowCol);
					linefeed(handle);
					fprintf(handle,"\tand (%s >= %u ) '",__abal_mouse_row,wy+WindowRow);
					linefeed(handle);
					fprintf(handle,"\tand (%s <= %u ) '",__abal_mouse_column,hwx+fh+WindowCol);
					linefeed(handle);
					fprintf(handle,"\tand (%s <= %u ))",__abal_mouse_row,wy+fh+WindowRow);
					linefeed(handle);
					}
				else	{
					fprintf(handle,"\tif ((%s >= (%s+%u) ) '",__abal_mouse_column,widget_x_position(iptr,1),hwx);
					linefeed(handle);
					fprintf(handle,"\tand (%s >= (%s+%u) ) '",__abal_mouse_row,widget_y_position(iptr,1),wy);
					linefeed(handle);
					fprintf(handle,"\tand (%s <= (%s+%u) ) '",__abal_mouse_column,widget_x_position(iptr,1),hwx+fh);
					linefeed(handle);
					fprintf(handle,"\tand (%s <= (%s+%u) ))",__abal_mouse_row,widget_y_position(iptr,1),wy+fh);
					linefeed(handle);
					}
				indent(handle,2);
				abal_comment(handle,iptr->Contents.name,1);
				abal_help_event( handle, iptr, 2 );
				abal_endif(handle,1);
				}

			if ( v ) {

				hwx = ((iptr->Contents.x+iptr->Contents.w)-((fh*3)+7));
				wy = (iptr->Contents.y+4);

				if ( FixedWindows ) {
					fprintf(handle,"\tif ((%s >= %u ) '",__abal_mouse_column,hwx+WindowCol);
					linefeed(handle);
					fprintf(handle,"\tand (%s >= %u ) '",__abal_mouse_row,wy+WindowRow);
					linefeed(handle);
					fprintf(handle,"\tand (%s <= %u ) '",__abal_mouse_column,hwx+fh+WindowCol);
					linefeed(handle);
					fprintf(handle,"\tand (%s <= %u ))",__abal_mouse_row,wy+fh+WindowRow);
					linefeed(handle);
					}
				else	{
					fprintf(handle,"\tif ((%s >= (%s+%u) ) '",__abal_mouse_column,widget_x_position(iptr,1),hwx);
					linefeed(handle);
					fprintf(handle,"\tand (%s >= (%s+%u) ) '",__abal_mouse_row,widget_y_position(iptr,1),wy);
					linefeed(handle);
					fprintf(handle,"\tand (%s <= (%s+%u) ) '",__abal_mouse_column,widget_x_position(iptr,1),hwx+fh);
					linefeed(handle);
					fprintf(handle,"\tand (%s <= (%s+%u) ))",__abal_mouse_row,widget_y_position(iptr,1),wy+fh);
					linefeed(handle);
					}

				indent(handle,2);
				abal_comment(handle,iptr->Contents.name,1);
				abal_lang_event( handle, iptr, 2 );
				abal_endif(handle,1);
				}

			if (( iptr->Contents.special ) && (!( FixedWindows ))) {
				indent(handle,1); fprintf(handle,"Case _MIMO_DOWN"); linefeed(handle);

				hwx = (iptr->Contents.w-((fh*4)+7));
				indent(handle,2);
				fprintf(handle,"if ((%s >= (%s+4) ) '",__abal_mouse_column,widget_x_position(iptr,1));
				linefeed(handle);
				indent(handle,2);
				fprintf(handle,"and (%s >= (%s+4) ) '",__abal_mouse_row,widget_y_position(iptr,1));
				linefeed(handle);
				indent(handle,2);
				fprintf(handle,"and (%s <= (%s+%u) ) '",__abal_mouse_column,widget_x_position(iptr,1),hwx);
				linefeed(handle);
				indent(handle,2);
				fprintf(handle,"and (%s <= (%s+4+%u) ))",__abal_mouse_row,widget_y_position(iptr,1),fh);
				linefeed(handle);
				indent(handle,3);
				abal_comment(handle,iptr->Contents.name,1);
				abal_move_event( handle, iptr, 3 );
				abal_endif(handle,2);
				}

			if (( iptr->Contents.align & (_A_BOLD | _A_LINE) )
			|| ( v )
			|| ( iptr->Contents.special )) {
				fprintf(handle,"\tEndSel");
				linefeed(handle);
				}

			break;

		case	_TAB_FRAME	:
			if ((!( iptr->Contents.events.xo_event & _EVENT_IS_FOCUS ))
			&&  (!( iptr->Contents.events.xo_get_focus & _EVENT_IS_FOCUS )))
				break;
			if ((pn = open_abal_page( handle, iptr,1 )) != 0)
				abal_else(handle,1);
			if ( FixedWindows ) {
				fprintf(handle,"\tif ((%s >= %u ) '",__abal_mouse_column,(iptr->Contents.x+WindowCol+iptr->Contents.adjust));
				linefeed(handle);
				fprintf(handle,"\tand (%s >= %u ) '",__abal_mouse_row,iptr->Contents.y+WindowRow);
				linefeed(handle);
				fprintf(handle,"\tand (%s <= %u ) '",__abal_mouse_column,(iptr->Contents.x+WindowCol+iptr->Contents.adjust+iptr->Contents.xlimit));
				linefeed(handle);
				fprintf(handle,"\tand (%s <= %u ))",__abal_mouse_row,(iptr->Contents.y+WindowRow+iptr->Contents.ylimit));
				}
			else	{
				fprintf(handle,"\tif ((%s >= (%s+%u) ) '",__abal_mouse_column,widget_x_position(iptr,1),iptr->Contents.adjust);
				linefeed(handle);
				fprintf(handle,"\tand (%s >= (%s) ) '",__abal_mouse_row,widget_y_position(iptr,1));
				linefeed(handle);
				fprintf(handle,"\tand (%s <= (%s+%u) ) '",__abal_mouse_column,widget_x_position(iptr,1),iptr->Contents.adjust+iptr->Contents.xlimit);
				linefeed(handle);
				fprintf(handle,"\tand (%s <= (%s+%u) ))",__abal_mouse_row,widget_y_position(iptr,1),iptr->Contents.ylimit);
				linefeed(handle);
				}
			linefeed(handle);
			indent(handle,2);
			abal_comment(handle,iptr->Contents.name,1);
			abal_mouse_event( handle, iptr, 2 );
			abal_endif(handle,1);
			close_abal_page( handle, pn,1 );
			break;

		case	_SELECT_FRAME	:

			if ((!( iptr->Contents.events.xo_event & _EVENT_IS_FOCUS ))
			&&  (!( iptr->Contents.events.xo_get_focus & _EVENT_IS_FOCUS )))
				break;
			pn = open_abal_page( handle, iptr,1 );
			if ( FixedWindows ) {
				fprintf(handle,"\tif ((%s >= %u ) '",__abal_mouse_column,(iptr->Contents.x+WindowCol+iptr->Contents.adjust));
				linefeed(handle);
				fprintf(handle,"\tand (%s >= %u ) '",__abal_mouse_row,iptr->Contents.y+WindowRow);
				linefeed(handle);
				fprintf(handle,"\tand (%s <= %u ) '",__abal_mouse_column,(iptr->Contents.x+WindowCol+iptr->Contents.adjust+iptr->Contents.xlimit));
				linefeed(handle);
				fprintf(handle,"\tand (%s <= %u ))",__abal_mouse_row,(iptr->Contents.y+WindowRow+iptr->Contents.ylimit));
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
			if ( iptr->Contents.events.xo_hide & _EVENT_IS_POP ) {
				indent(handle,2);	
				fprintf(handle,"if ((p_%s<>0) and ( s_%s<>0))",
					iptr->Contents.name,	
					iptr->Contents.name );
				linefeed(handle);
				}

			abal_mouse_event( handle, iptr, 2 );
			/* detect conditional items and test if selectionable */
			/* -------------------------------------------------- */
			if ( iptr->Contents.events.xo_hide & _EVENT_IS_POP ) {
				abal_endif(handle,1);
				}
			abal_endif(handle,1);
			close_abal_page( handle, pn,1 );
			break;

		case	_DATA_FRAME	:
			if (( iptr->Contents.align & 0x00F ) != _VISUAL_FRAME )
				break;
		case	_FORM_FRAME	:
		case	_EDIT_FRAME	:

			if ( iptr->Contents.datatype == _WIDGET_KONSTANT )
				break;

		case	_BUTTON_FRAME	:
		case	_SWITCH_FRAME	:
		case	_GRAPH_FRAME	:
		case	_CHECK_FRAME	:
		case	_RADIO_FRAME	:
		default			:
			if ((!( iptr->Contents.events.xo_event & _EVENT_IS_FOCUS ))
			&&  (!( iptr->Contents.events.xo_get_focus & _EVENT_IS_FOCUS )))
				break;

			pn = open_abal_page( handle, iptr,1 );

			if ( FixedWindows ) {
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
			/* detect conditional items and test if selectionable */
			/* -------------------------------------------------- */
			if ( iptr->Contents.events.xo_hide & _EVENT_IS_POP ) {
				indent(handle,2);	
				fprintf(handle,"if ((p_%s<>0) and ( s_%s<>0))",
					iptr->Contents.name,	
					iptr->Contents.name );
				linefeed(handle);
				}

			widget_mouse_event(handle,iptr,2);
			abal_mouse_event( handle, iptr, 2 );
			/* detect conditional items and test if selectionable */
			/* -------------------------------------------------- */
			if ( iptr->Contents.events.xo_hide & _EVENT_IS_POP ) {
				abal_endif(handle,1);
				}
			abal_endif(handle,1);
			close_abal_page( handle, pn,1 );
			break;
		}
	return;
}

public	int	activate_abal_method( FILE * h,char * mptr, char* nptr, char * eptr, int type, int margin )
{
	char	*	optr;

	if (!( method_is_valid( eptr )))	return(0);

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = "o";
	else	optr = "\0";

	indent(h,margin);

	if (!( type & 1 )) /* void call */
		fprintf(h,"%s%s(%s)",mptr,nptr,optr);
	else	{
		fprintf(h,"%s= %s%s(%s)",__abal_keyword_keycode,mptr,nptr,optr);
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

public	int	inline_abal_method( FILE * h,char * mptr, char* nptr, char * eptr, int type, int margin )
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

	if ( iptr->Contents.events.xo_hide & _EVENT_IS_POP ) {
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
	fprintf(handle,",%u,%u)",iptr->Contents.adjust,option);
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

public void	abal_frame_widget(FILE * handle, struct form_item * iptr, int margin )
{
	int	fh=0;
	int	xh=0;

	if (( iptr->Contents.align != _A_NONE     ) 
	&&  ( abal_payload(iptr) != (char *) 0)) {
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
		iptr->Contents.y += fh;
		iptr->Contents.h = xh;
		iptr->Contents.h -= fh;
		}
	else	{
		xh = fh = 0;
		}
	abal_widget_function(handle,__abal_visual_zone,margin);
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	fprintf(handle,",%u)",iptr->Contents.style );
	linefeed(handle);
	iptr->Contents.h += fh;
	iptr->Contents.y -= fh;
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
	abal_widget_function(handle,__abal_visual_window,margin);
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	font_parameter(handle,iptr);
	constant_parameter(handle,iptr );
	constant_length_parameter(handle,iptr);
	fprintf(handle,",/0%x)",
	((iptr->Contents.align & _A_SHADOW) | v | 
	 (iptr->Contents.align & _A_BOLD ? _WINDOW_EXIT_BUTTON : 0 ) | 
	 (iptr->Contents.align & _A_LINE ? _WINDOW_HELP_BUTTON : 0 )));
	linefeed(handle);
	return;
}

public void	generate_abal_onshow(FILE * handle, struct form_item * iptr, int tabul  )
{
	if (method_is_valid( iptr->Contents.stylesheet )) 
		abal_visual_element( handle, iptr, (char *) 0, (char *) 0, tabul );

	else	
	switch ((iptr->Contents.style&_FRAME_TYPE)) {

		case	_DATA_FRAME		:
			abal_visual_widget(handle,iptr,tabul);
			break;

		case	_FILL_FRAME	:
			abal_fill_widget(handle,iptr,tabul);
			break;

		case	_INSET_FRAME	:
		case	_OUTSET_FRAME	:
		case	_GROOVE_FRAME	:
		case	_RIDGE_FRAME	:
			abal_frame_widget(handle,iptr,tabul);
			break;

		case	_TEXT_FRAME	:
			abal_text_widget(handle,iptr,tabul);
			break;
	
		case	_LINE_FRAME	:
			abal_line_widget(handle,iptr,tabul);
			break;
	
		case	_IMAGE_FRAME	:
			abal_image_widget(handle,iptr,tabul);
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
			abal_window_widget(handle,iptr,tabul);
			break;

		}
	return;
}

private	void	abal_instance_trigger_code( FILE * h, struct form_item * iptr, int margin )
{
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
			abal_dcl(h,"t_",iptr->Contents.name,_ABAL_WORD,2,0,0);
			break;

		case	_BUTTON_FRAME	:
		case	_SWITCH_FRAME	:
		case	_CHECK_FRAME	:
		case	_TAB_FRAME	:
			if (!( sptr = abal_payload(iptr)))
				return;
			abal_dcl(h,"t_",iptr->Contents.name,_ABAL_WORD,2,0,0);
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

	if (!( paging )) {
		if ((pn = open_abal_page( handle, iptr,1 )) != 0)
			tabul=2;
		else	tabul=1;
		}
	else	tabul=2;

	generate_abal_trigger_code(handle, iptr, tabul);

	if ((iptr->Contents.style&_FRAME_TYPE) != _TAB_FRAME) {
		if (!( abal_invoke_widget_show(handle,iptr,0, tabul )))
			generate_abal_onshow(handle,iptr,tabul);
		}
	else	{
		if (!( paging & 2 )) {
			abal_tab_widget(handle,iptr,tabul,2);
			if ( iptr->Contents.datatype == _WIDGET_OVERLAY )
				invoke_widget_overlay(handle,iptr,_OVL_ONSHOW);
			}
		abal_invoke_widget_show(handle,iptr,0,tabul );
		if ( pn != 0 )
			abal_else(handle,1);
		if (!( paging & 1 )) {
			abal_tab_widget(handle,iptr,tabul,0);
			}
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
	if (method_is_valid( iptr->Contents.stylesheet )) 
		abal_visual_element( h, iptr, (char *) 0, (char *) 0, margin );
	else	{
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
		fprintf(h,",/0%X)",etat);
		linefeed(h);
		}
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
	if ((iptr->Contents.align & 0x000F) == 2) {
		indent(h,margin);
		fprintf(h,"%s.on_get_focus",iptr->Contents.name);
		linefeed(h);
		indent(h,margin);
		fprintf(h,"%s=%s.keycode",__abal_keyword_keycode,iptr->Contents.name);
		linefeed(h);
		}
	return;
}

public	void	abal_data_lose_focus(FILE * h, struct form_item * iptr, int margin )
{
	if ((iptr->Contents.align & 0x000F) == 2) {
		indent(h,margin);
		fprintf(h,"%s=%s.on_lose_focus",__abal_keyword_keycode,iptr->Contents.name);
		linefeed(h);
		}
	return;
}

public	void	abal_control_focus(FILE * handle, struct form_item * iptr, char * mptr, int mode )
{
	int	pn=0;
	int	margin=0;

	abal_case_focus(handle,iptr,2);
	abal_comment(handle,iptr->Contents.name,3);
	if (!( pn = open_abal_page(handle,iptr,3) ))
		margin = 3;
	else	margin = 4;

	abal_invoke_widget_get_focus(handle,iptr,1,margin );

	switch ((iptr->Contents.style & _FRAME_TYPE)) {

		case	_DATA_FRAME	:
			abal_data_get_focus(handle,iptr,margin);
			break;

		case	_FORM_FRAME	:
			if (!( iptr->Contents.events.xo_get_focus & _EVENT_IS_FOCUS )) { 
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
			fprintf(handle,",v_%s,%u)",iptr->Contents.name,((iptr->Contents.align << 8) | 2));
			break;

		case	_BUTTON_FRAME	:
			if ( iptr->Contents.events.xo_get_focus & _EVENT_IS_FOCUS ) { 
				abal_button_widget(handle,iptr,margin,2);
				indent(handle,margin);
				fprintf(handle,__abal_visual_keycode);
				linefeed(handle);
				abal_button_widget(handle,iptr,margin,0);
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
			if (!( iptr->Contents.events.xo_get_focus & _EVENT_IS_FOCUS )) { 
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
		if (!( iptr->Contents.events.xo_get_focus & _EVENT_IS_FOCUS )) {
			if (!( iptr->Contents.events.on_get_focus )) {
				if ( iptr->Contents.datatype != _WIDGET_OVERLAY ) {
					indent(handle,margin);
					fprintf(handle,"%s=5",__abal_keyword_keycode);
					linefeed(handle);
					}
				}
			else	abal_invoke_widget_get_focus(handle,iptr,1,margin );
			}
		else if (!( iptr->Contents.events.on_get_focus )) {
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

		abal_invoke_widget_lose_focus(handle,iptr,0,margin );

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
		if (!( iptr->Contents.events.xo_get_focus & _EVENT_IS_FOCUS )) {
			if (!( iptr->Contents.events.on_get_focus )) {
				indent(handle,margin);
				fprintf(handle,"%s=5",__abal_keyword_keycode);
				linefeed(handle);
				}
			else	abal_invoke_widget_get_focus(handle,iptr,1,margin );
			}
		else if (!( iptr->Contents.events.on_get_focus )) {
			indent(handle,margin);
			fprintf(handle,__abal_visual_keycode);
			linefeed(handle);
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

public	void	abal_standard_ask(FILE* h, struct form_item * iptr, int margin)
{
	indent(h,margin);
	fprintf(h,"Ask=1,T=ThisLine,X=Next,I=Next,U=Next,D=Next,/03=Next,/12=Next,/0D=Next,/09=Next:Tab(1,1),Paint(8,15),");
	return;
}

public	void	abal_visual_ask(FILE * h, struct form_item * iptr, int margin )
{
	indent(h,margin);
	abal_widget_viewport(h,iptr );
	linefeed(h);
	abal_standard_ask(h,iptr,margin);
	fprintf(h,"%s=b_%s",iptr->Contents.format,iptr->Contents.name);
	linefeed(h);
	indent(h,margin);
	fprintf(h,"KeyCode=HotKey");
	linefeed(h);
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
		fprintf(handle,",%u)",iptr->Contents.align);
	linefeed(handle);
	return;
}

private	void	abal_onfocus_edit(FILE * h, struct form_item * iptr, int margin )
{
	if (( is_valid_format( iptr->Contents.format ) )
	&&  ( iptr->Contents.align & _A_BOLD ))
		abal_visual_ask(h,iptr,margin);
	else	abal_visual_edit(h,iptr,margin);
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
		if (!( iptr->Contents.events.xo_get_focus & _EVENT_IS_FOCUS )) {
			if (!( iptr->Contents.events.on_get_focus )) {
				indent(h,margin);
				fprintf(h,"%s=5",__abal_keyword_keycode);
				linefeed(h);
				}
			else	abal_invoke_widget_get_focus(h,iptr,1,margin);
			}
		else if (!( iptr->Contents.events.on_get_focus )) {
			abal_onfocus_edit(h,iptr,margin);
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
	int		fields=0;
	int		fieldwidth[_MAX_FORM_FIELDS];
	int		linelength=0;
	int		nblines=0;
	char *		xptr;
	int		ecart;
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
	calculate_edit_lines( &iptr->Contents, &linelength, &nblines );

	if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) )) {
		abal_control_focus(h,iptr,__abal_visual_key,1); 
		return;
		}
	abal_form_member_alias(h,iptr,(char *) 0,margin);
	linefeed(h);
	indent(h,margin);
	fprintf(h,"%s (c_%s)",__abal_keyword_select,iptr->Contents.name);
	linefeed(h);
	sprintf(namebuffer,"((v_%s-1) and 1)",iptr->Contents.name);
	xptr = allocate_string((namebuffer));
	for ( 	f = 0, xfi=0;
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
			fprintf(h,"(%s+(v_%s*%u)+2),",widget_y_position(iptr,0),iptr->Contents.name,fh);

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
				fprintf(h,"(%s+(v_%s*%u)+2),",widget_y_position(iptr,0),iptr->Contents.name,fh);

				/* The field pixel width and height */
				/* -------------------------------- */
				fprintf(h,"%u,%u",((fieldwidth[f]-1)*fw),fh);

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
				fprintf(h,"(%s+(v_%s*%u)+2),",widget_y_position(iptr,0),iptr->Contents.name,fh);

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
				fprintf(h,",%u)",iptr->Contents.align);
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
		fprintf(h,"(%s+(v_%s*%u)+2),",widget_y_position(iptr,0),iptr->Contents.name,fh);

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
	calculate_edit_lines( &iptr->Contents, &linelength, &nblines );

	if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) )) {
		abal_control_focus(h,iptr,__abal_visual_key,1); 
		return;
		}
	abal_case_focus(h,iptr,2);
	abal_comment(h,iptr->Contents.name,3);
		if (!(pn = open_abal_page(h,iptr,3)))
			margin=3;
		else	margin=4;
		if (!( iptr->Contents.events.xo_get_focus & _EVENT_IS_FOCUS )) {
			if (!( method_is_valid( iptr->Contents.events.on_get_focus ) )) {
				indent(h,margin);
				fprintf(h,"%s=5",__abal_keyword_keycode);
				linefeed(h);
				}
			else	abal_invoke_widget_get_focus(h,iptr,1,margin );
			}
		else if (!( method_is_valid( iptr->Contents.events.on_get_focus ) )) {
			abal_onfocus_form( h, iptr, margin );
			}
		else	abal_invoke_widget_get_focus(h,iptr,1,margin );

		if ( method_is_valid( iptr->Contents.events.on_lose_focus ) )
			abal_invoke_widget_lose_focus(h,iptr,0,margin);	

		if ( iptr->Contents.events.xo_lose_focus & _EVENT_IS_FOCUS )
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
			fprintf(h,"\tr_%s = Alias( l_%s(%s) )",
					iptr->Contents.name,
					iptr->Contents.name, item );
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
		else	return(vformat(iptr->Contents.format, fieldwidth, _MAX_FORM_FIELDS, linelength ) );
		}
	else if (!( tptr = abal_payload(iptr) ))
		return(0);
	else if ( *tptr == _UNQUOTED_STRING )
		return(0);
	else	return(vfields(tptr, fieldwidth, _MAX_FORM_FIELDS, linelength ));
}

public	void	redefine_multiline_widget( FILE * h, struct form_item * iptr, int linelength,int nblines )
{
	char	*	tptr;
	char	*	wptr;
	int		f;
	int		fields=0;
	int		fieldwidth[_MAX_FORM_FIELDS];
	char		prefix[16];

	abal_field(h,"b_",iptr->Contents.name);
	abal_dcl(h,"l_",iptr->Contents.name,_ABAL_STRING,linelength,nblines,0);
	abal_field(h,(char *) 0,(char *) 0);

	switch ((iptr->Contents.style & _FRAME_TYPE)) {

		case	_FORM_FRAME	:

			if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
					break;

			/* Declare Redefined member pointer */
			abal_ptr(h,"r_",iptr->Contents.name,_ABAL_STRING,linelength,0,0);

			if ( fields > 1 ) {
				
				/* Define Table Record */
				abal_field(h,"r_",iptr->Contents.name);
				for (f=0; f < fields; f++ ) {
					sprintf(prefix,"m%u_",(f+1));
					abal_dcl(h,prefix,iptr->Contents.name,_ABAL_STRING,fieldwidth[f],0,0);
					}
				abal_field(h,(char *) 0,(char *) 0);
				}
			}

	return;
}

private	void	instance_position_control( FILE * h, struct form_item * iptr )
{
	char	pbuffer[256];
	/* Generate Position and Dimensions Variables */
	abal_dcl(h,"x_",iptr->Contents.name,_ABAL_WORD,0,0,0);
	abal_dcl(h,"y_",iptr->Contents.name,_ABAL_WORD,0,0,0);
	abal_dcl(h,"w_",iptr->Contents.name,_ABAL_WORD,0,0,0);
	abal_dcl(h,"h_",iptr->Contents.name,_ABAL_WORD,0,0,0);
	if (!( FixedWindows )) {
		if (( iptr->Contents.style & _FRAME_TYPE ) == _WINDOW_FRAME) {
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


public  int	generate_abal_structure( FILE * h )
{
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

	WindowCol = WindowRow = 0;

	abal_dcl(h,"Key","Code",_ABAL_WORD,0,0,0);
	abal_dcl(h,"Focus","Item",_ABAL_WORD,0,0,0);
	abal_dcl(h,"Focus","Items",_ABAL_WORD,0,0,0);
	abal_dcl(h,"Key","Buffer",_ABAL_STRING,32,0,0);
	abal_field(h,"Key","Buffer");
	abal_dcl(h,"Key","Value",_ABAL_BYTE,1,32,0);

	if ( Context.Form->formflags & _MULTILINGUAL ) {
		abal_dcl(h,"National","Language",_ABAL_WORD,0,0,0);
		}

	declare_abal_fonts(h);

	if ( Context.Form->pages != 0 )
		abal_dcl(h,"Focus","Pages",_ABAL_WORD,0,Context.Form->pages,0);

	Signature[(SignatureItems=0)] = 0;

	for (	items=0, iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {

		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		if ( iptr->Contents.events.xo_create & _EVENT_IS_FOCUS )
			instance_position_control( h, iptr );

		if ( iptr->Contents.events.xo_hide & _EVENT_IS_POP ) {
			if (((iptr->Contents.style & _FRAME_TYPE ) != _WINDOW_FRAME)
			||  (!( Context.Form->ispopup ))) {
				abal_dcl(h,"s_",iptr->Contents.name,_ABAL_WORD,0,0,0);
				abal_dcl(h,"p_",iptr->Contents.name,_ABAL_WORD,0,0,0);
				}
			}
		if (( Context.Form->formflags & _MULTILINGUAL )
		&&  (( payloadmax = max_payload_size( iptr )) != 0)) {
			abal_dcl(h,"msg_",iptr->Contents.name,_ABAL_STRING,payloadmax,MAXNATLANG,0);
			abal_instance_trigger_code(h,iptr,1);
			}

		switch (((s=iptr->Contents.style)&_FRAME_TYPE)) {

			case	_WINDOW_FRAME	:
				calculate_window_alignment( iptr );

				if (!( iptr->Contents.events.xo_create & _EVENT_IS_FOCUS ))
					instance_position_control( h, iptr );
				if (!( iptr->Contents.events.xo_hide & _EVENT_IS_POP )) {
					abal_dcl(h,"s_",iptr->Contents.name,_ABAL_WORD,0,0,0);
					abal_dcl(h,"p_",iptr->Contents.name,_ABAL_WORD,0,0,0);
					}
				break;

			case	_TAB_FRAME	:
				if (!( Abal_Config.page_control )) {
					abal_dcl(h,"Page","Number",_ABAL_WORD,0,0,0);
					Abal_Config.page_control = 1;
					}
				if ( iptr->Contents.datatype != _WIDGET_OVERLAY )
					break;
				abal_dcl(h,"b_",iptr->Contents.name,_ABAL_STRING,120,0,0);
				instance_widget_overlay(h,iptr);
				break;

			case	_DATA_FRAME	:
				abal_data_instance(h,iptr);
				break;

			case	_PROGRESS_FRAME	:
				abal_dcl(h,"v_",iptr->Contents.name,_ABAL_WORD,0,0,0);
				abal_dcl(h,"l_",iptr->Contents.name,_ABAL_WORD,0,0,0);
	 			items = add_interface_item( items, iptr, _SYMBOLIC_WORD );
	 			items = add_interface_item( items, iptr, _SYMBOLIC_WORD );
				break;

			case	_SCROLL_FRAME	:
				abal_dcl(h,"v_",iptr->Contents.name,_ABAL_WORD,0,0,0);
				abal_dcl(h,"l_",iptr->Contents.name,_ABAL_WORD,0,0,0);
				abal_dcl(h,"m_",iptr->Contents.name,_ABAL_WORD,0,0,0);
	 			items = add_interface_item( items, iptr, _SYMBOLIC_WORD );
	 			items = add_interface_item( items, iptr, _SYMBOLIC_WORD );
	 			items = add_interface_item( items, iptr, _SYMBOLIC_WORD );
				break;

			case	_BUTTON_FRAME	:
				if (( iptr->Contents.datatype != _WIDGET_OVERLAY )
				&&  ( iptr->Contents.datatype != _WIDGET_CHAIN   )
				&&  ( iptr->Contents.datatype != _WIDGET_SYSTEM  )
				&&  ( iptr->Contents.datatype != _WIDGET_LOADGO  ))
					break;
				abal_dcl(h,"b_",iptr->Contents.name,_ABAL_STRING,120,0,0);
				break;

			case	_GRAPH_FRAME	:
				abal_dcl(h,"l_",iptr->Contents.name,_ABAL_WORD,0,0,0);
				abal_dcl(h,"b_",iptr->Contents.name,_ABAL_STRING,iptr->Contents.w,0,0);
				if ( iptr->Contents.datatype != _WIDGET_VOID ) {
					abal_field(h,"b_",iptr->Contents.name);
					switch ( iptr->Contents.datatype ) {
						case	_WIDGET_BYTE :
							abal_dcl(h,"v_",iptr->Contents.name,_ABAL_BYTE,1,iptr->Contents.w,0);
				 			items = add_interface_item( items, iptr, _SYMBOLIC_BYTE );
							break;
						case	_WIDGET_WORD :
							abal_dcl(h,"v_",iptr->Contents.name,_ABAL_WORD,2,iptr->Contents.w/2,0);
				 			items = add_interface_item( items, iptr, _SYMBOLIC_WORD );
							break;
						case	_WIDGET_LONG :
							abal_dcl(h,"v_",iptr->Contents.name,_ABAL_WORD,4,iptr->Contents.w/4,2);
				 			items = add_interface_item( items, iptr, _SYMBOLIC_LONG );
							break;
						}
					abal_field(h,(char *) 0,(char *) 0);
					}
				break;

			case	_RADIO_FRAME	:
				if ( iptr->Contents.radio != 1 )
					break;

			case	_SELECT_FRAME	:
			case	_CHECK_FRAME	:
			case	_SWITCH_FRAME	:
				abal_dcl(h,"v_",iptr->Contents.name,_ABAL_WORD,0,0,0);
	 			items = add_interface_item( items, iptr, _SYMBOLIC_WORD );
				break;

			case	_FORM_FRAME	:
				calculate_edit_size( &iptr->Contents );
				calculate_edit_lines( &iptr->Contents, &linelength, &nblines );
				abal_dcl(h,"v_",iptr->Contents.name,_ABAL_WORD, 0,0,0);
				abal_dcl(h,"c_",iptr->Contents.name,_ABAL_WORD, 0,0,0);
				abal_dcl(h,"b_",iptr->Contents.name,_ABAL_STRING,iptr->Contents.size,0,0);
				redefine_multiline_widget(h,iptr,linelength,nblines );
	 			items = add_interface_item( items, iptr, _SYMBOLIC_STRING );
				break;

			case	_EDIT_FRAME	:
				calculate_edit_size( &iptr->Contents );
				calculate_edit_lines( &iptr->Contents, &linelength, &nblines );
				abal_dcl(h,"b_",iptr->Contents.name,_ABAL_STRING,iptr->Contents.size,0,0);
				if ( nblines > 1 ) {
					redefine_multiline_widget(h,iptr,linelength,nblines );
					}
	 			items = add_interface_item( items, iptr, _SYMBOLIC_STRING );
				break;
			}
		}

	SignatureItems = items;

	abal_dcl(h,"Sign","ature",_ABAL_STRING,items+1,0,0);
	abal_dcl(h,"Sta","tus",_ABAL_WORD,2,0,0);
	abal_dcl(h,"Mouse","Event",_ABAL_STRING,8,0,0);
	abal_field(h,"MouseEvent",(char *) 0);
	abal_dcl(h,"Mouse","Type",_ABAL_WORD,0,0,0);
	abal_dcl(h,"Mouse","Button",_ABAL_WORD,0,0,0);
	abal_dcl(h,"Mouse","Column",_ABAL_WORD,0,0,0);
	abal_dcl(h,"Mouse","Row",_ABAL_WORD,0,0,0);
	abal_field(h,(char *) 0,(char *) 0);
	return(items);
}

private	void	construction_parameters
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

		switch ( iptr->Contents.datatype ) {

			case	_WIDGET_KONSTANT	:
				if (!( mode ))
					fprintf(h,"p_%s$=%u",iptr->Contents.name,iptr->Contents.size);
				else	fprintf(h,"p_%u",iptr->Contents.name);
				break;

			case	_WIDGET_STRING		:
				if (!( mode ))
					fprintf(h,"ptr p_%s$,pl%s%%",iptr->Contents.name,iptr->Contents.name);
				else	fprintf(h,"p_%s,pl%s",iptr->Contents.name,iptr->Contents.name);
				break;

			case	_WIDGET_WORD	:
				if (!( mode ))
					fprintf(h,"ptr p_%s%%",iptr->Contents.name);
				else	fprintf(h,"p_%s",iptr->Contents.name);
				break;

			case	_WIDGET_BYTE	:
				if (!( mode ))
					fprintf(h,"ptr p_%s#",iptr->Contents.name);
				else	fprintf(h,"p_%s",iptr->Contents.name);
				break;

			case	_WIDGET_LONG	:
				if (!( mode ))
					fprintf(h,"ptr p_%s:",iptr->Contents.name);
				else	fprintf(h,"p_%s",iptr->Contents.name);
				break;

			case	_WIDGET_FLOAT	:
			case	_WIDGET_NUMERIC	:
				if (!( mode ))
					fprintf(h,"ptr p_%s,pl%s%%",iptr->Contents.name,iptr->Contents.name);
				else	fprintf(h,"p_%s,pl%s",iptr->Contents.name,iptr->Contents.name);
				break;
			}
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

public  int	abal_import_parameter( FILE * h , struct form_item * iptr, int i ) 
{
	if (!( iptr->Contents.interfaceitem ))
		return(0);
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
				fprintf(h,"b_%s = %c %c",iptr->Contents.name,0x0022,0x0022);
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
			break;

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
			fprintf(h,"v_%s = p_%s",
				iptr->Contents.name,
				iptr->Contents.name);
			linefeed(h);
			abal_else(h,i);
			indent(h,i+1);
			fprintf(h,"v_%s = 0",iptr->Contents.name);
			linefeed(h);
			abal_endif(h,i);
			return(1);
			break;
		} 
	return(0);
}

public  int	abal_export_parameter( FILE * h ,struct form_item * iptr,int i )
{

	if (!( iptr->Contents.interfaceitem ))
		return(0);
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
			break;

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
			fprintf(h,"p_%s = v_%s",
				iptr->Contents.name,
				iptr->Contents.name);
			linefeed(h);
			abal_endif(h,i);
			return(1);
			break;
		} 
	return(0);
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

public	void	abal_oncreate_methods( FILE * h )
{
	struct form_item * iptr;
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (( iptr->Contents.events.on_create )
		&&  ( iptr->Contents.events.xo_create & _EVENT_IS_FUNCTION ))
			abal_method(h,iptr->Contents.name,__abal_method_create,iptr->Contents.events.on_create);
		}

	return;
}

public	void	abal_onshow_methods( FILE * h )
{
	struct form_item * iptr;
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (( iptr->Contents.events.on_show )
		&&  ( iptr->Contents.events.xo_show & _EVENT_IS_FUNCTION ))
			abal_method(h,iptr->Contents.name,__abal_method_show,iptr->Contents.events.on_show);
		}

	return;
}

public	void	abal_onget_methods( FILE * h, char * nptr )
{
	struct form_item * iptr;
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (( iptr->Contents.events.on_get_focus )
		&&  ( iptr->Contents.events.xo_get_focus & _EVENT_IS_FUNCTION ))
			abal_method(h,iptr->Contents.name,nptr,iptr->Contents.events.on_get_focus);
		}

	return;
}

public	void	abal_onlose_methods( FILE * h, char * nptr )
{
	struct form_item * iptr;
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (( iptr->Contents.events.on_lose_focus )
		&&  ( iptr->Contents.events.xo_lose_focus & _EVENT_IS_FUNCTION ))
			abal_method(h,iptr->Contents.name,nptr,iptr->Contents.events.on_lose_focus);
		}

	return;
}

public	void	abal_onevent_methods( FILE * h )
{
	struct form_item * iptr;

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {

		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
	
		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_WINDOW_FRAME	:

				if ( iptr->Contents.special ) {
					abal_window_driver(h,iptr);
					}
				continue;

			case	_SCROLL_FRAME	:

				if (( iptr->Contents.events.on_event )
				&&  ( iptr->Contents.events.xo_event & _EVENT_IS_FUNCTION ))
					abal_method(h,iptr->Contents.name,__abal_method_event,iptr->Contents.events.on_event);

				abal_scrollbar_driver(h,iptr);
				continue;

			case	_BUTTON_FRAME	:
				if ( iptr->Contents.datatype == _WIDGET_OVERLAY ) {
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
			default			:
				if (( iptr->Contents.events.on_event )
				&&  ( iptr->Contents.events.xo_event & _EVENT_IS_FUNCTION ))
					abal_method(h,iptr->Contents.name,__abal_method_event,iptr->Contents.events.on_event);
			}
		}

	return;
}

public	void	abal_onhide_methods( FILE * h, char * nptr )
{
	struct form_item * iptr;
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		if (( iptr->Contents.events.on_hide )
		&&  ( iptr->Contents.events.xo_hide & _EVENT_IS_FUNCTION ))
			abal_method(h,iptr->Contents.name,nptr,iptr->Contents.events.on_hide);


		}

	return;
}

public	void	abal_onremove_methods( FILE * h )
{
	struct form_item * iptr;
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (( iptr->Contents.events.on_remove )
		&&  ( iptr->Contents.events.xo_remove & _EVENT_IS_FUNCTION ))
			abal_method(h,iptr->Contents.name,__abal_method_remove,iptr->Contents.events.on_remove);
		}

	return;
}

public	void	abal_event_methods( FILE * h )
{
	abal_oncreate_methods(h);	
	abal_onshow_methods(h);	
	abal_onget_methods(h,__abal_method_get_focus);	
	abal_onlose_methods(h,__abal_method_lose_focus);	
	abal_onevent_methods(h);	
	abal_onhide_methods(h,__abal_method_hide);	
	abal_onremove_methods(h);	
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

private	void	declare_abal_fonts(FILE * h)
{
	if ( Context.RelativeFonts ) 
		abal_dcl(h,"Font","Handle",_ABAL_WORD,2,SING_FONT_MAX,0);
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
/*		if (!(fname = font_name[i]))
			continue;	*/

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


#endif 	/* _SINGABAL_C */
	/* ----------- */


