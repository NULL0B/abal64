#include "singmeth.h"
#ifdef WIN32
#include <direct.h>
#include <stdio.h> 
#include <io.h>
#include <errno.h>
#else
#include <unistd.h>
#endif

#include "vconsultp.h"

#define	_ON_CREATE			"OnCreate"
#define	_ON_REMOVE			"OnRemove"
#define	_ON_HIDE  			"OnHide"
#define	_ON_SHOW			"OnShow"
#define	_ON_FOCUS_SHOW			"OnFocusShow"
#define	_ON_GETFOCUS			"OnFocus"
#define	_ON_LOSEFOCUS			"OnLoseFocus"
#define	_ON_EVENT			"OnEvent"
#define	_ON_GERER			"OnCreateAndExec"
#define	_ON_EXEC			"OnExec"
#define	__QUOTE				0x0022
#define	_METHOD_CPP_ONHINT		"OnHint" 
#define	_ON_TRANSFERTIN			"TransfertIn"
#define	_ON_TRANSFERTOUT		"TransfertOut"
#define	_ON_INITIALISETRANSFERT		"InitialiseStructure"
#define	_DATA_INTERFACE			"DataInterface"
#define _SET_PAYLOAD			"SetPayload"

#define USE_POINTER_METHOD	0
#define _ATTACHE			"METHOD_ATTACHE"
#define _METHOD_ONCREATE		"MethodOnCreate"
#define _METHOD_ONSHOW			"MethodOnShow"
#define _METHOD_ONEVENT			"MethodOnEvent"
#define _METHOD_ONFOCUS			"MethodOnFocus"
#define _METHOD_ONHIDE			"MethodOnHide"
#define _METHOD_ONREMOVE		"MethodOnRemove"
#define _METHOD_ONLOSEFOCUS		"MethodOnLoseFocus"
#define _METHOD_ONHELP			"MethodOnHelp"

#define _BEGIN "Begin"
#define _END "End"

#define DECORE_CLASS	"_OBJ"

private	char *	CppWidgetClass[_FRAME_TYPE+1] = {
	"fill",		"frame",	"frame",	"frame",
	"frame",	"edit",		"text",		"image",

	"line",		"button",	"window",	"tabpage",	
	"check",	"radio",	"select",	"form",

	"scroll",	"progress",	"switch",	"graph",
	"data",		""
	};

private	char *	__method_create		="create";
private	char *	__method_show		="show";
private	char *	__method_getfocus	="getfocus";
private	char *	__method_focus		="focus";
private	char *	__method_event		="event";
private	char *	__method_action		="action";
private	char *	__method_losefocus	="losefocus";
private	char *	__method_hide		="hide";
private	char *	__method_remove		="remove";
private	char * __visual_natlang="visual_national_language";
private	char * __c_page_number ="page_number";
private	char * __c_focus_item  ="focus_item";
private	char * __c_keycode     ="keycode";
private	char * __c_status      ="status";
private	char * __c_stdinput    ="stdinput";
private	char *	__visual_signature="visual_signature";
private	char *	__visual_transferin="visual_transferin";
private	char *	__visual_transferout="visual_transferout";
private	char *	__visual_palette="visual_palette";
private	char *	__visual_font="visual_font";
private	char *	__visual_initialise="visual_initialise";
private	char *	__visual_liberate="visual_liberate";

private	char *	__visual_freeze="visual_freeze";
private	char *	__visual_thaw="visual_thaw";
private	char *	__visual_window="visual_window";
private	char *	__visual_tabpage="visual_tabpage";
private	char *	__visual_text="visual_text";
private	char *	__visual_button="visual_button";
private	char *	__visual_check="visual_check";
private	char *	__visual_radio="visual_radio";
private	char *	__visual_edit="visual_edit";
private	char *	__visual_scrollbar="visual_scrollbar";
private	char *	__visual_relief="visual_relief";
private	char *	__visual_filzone="visual_filzone";
private	char *	__visual_frame="visual_frame";
private	char *	__visual_select="visual_select";
private	char *	__visual_progress="visual_progress";
private	char *	__visual_image="visual_image";
private	char *	__visual_graph="visual_graph";
private	char *	__visual_switch="visual_switch";
private	char *	__visual_table="visual_table";
private	char *	__visual_line="visual_line";
private	char *	__visual_viewport="visual_viewport";
private	char * __c_mouse_type  ="visual_event(1)";
private	char * __c_visual_event="visual_event";
private	char * __c_mouse_button="visual_event(2)";
private	char * __c_mouse_column="visual_event(7)";
private	char * __c_mouse_row   ="visual_event(6)";
private	char * __c_test_event  ="visual_kbhit()";
private	char * __c_get_event   ="visual_getch";

extern	struct line_parser LineParser;
extern	char *	keyword_include	;
extern	char *	keyword_user	;
extern	char *	keyword_this	;
extern	char *	keyword_thisform;
extern	char *	keyword_exit	;
extern	char *	keyword_dcl 	;
extern	char *	keyword_ptr 	;
extern	char *	keyword_field	;
extern	char *	keyword_onshow	;
extern	char *	keyword_onhide	;
extern	char *	keyword_onevent ;
extern	char *	keyword_keycode ;
extern	char *	keyword_focusitem ;

static char lwidget[512];

/* ---------- */
/* prototypes */
/* ---------- */
struct	form_control * locate_form_control(char * cname);
private	int	cpp_method_body( FILE * h, char * eptr, int l, char * hptr, int margin,char *cname,	struct form_item * iptr );
public  void	cpp_call( FILE * h, char * cname, char * fname, int members, int level, char * genret );
private	int	inline_cpp_method( FILE * h,char * mptr, char* nptr, char * eptr, int type, int margin,char *cname,	struct form_item * iptr  );
private	int	cpp_method_line( FILE * h, char * eptr, int l, char * hptr, int * feeder , char *cname,	struct form_item * iptr);
private	int	open_cpp_page(FILE * h,struct form_item * iptr, int i);
	void	write_protect(FILE * h,int *wptr,int type);
private int	copie_fichier(char *nfo,char *nfd);
private int fichier_error(char *nfo,char *nfd);
private void fputs_formate(char *l,FILE *fd);
private char *index_string(char *o,char *s);
private int TailleFichier(char *cname,int *LMaxConsult);

private	char *	get_cpp_widget_class( int wid )
{
	return( CppWidgetClass[(wid  & _FRAME_TYPE)] );
}

private int	cpp_module_description( FILE * h,char * cname)
{
	char 		* headname=(char *) 0;
	struct	form_control * fptr;

	if (!( fptr = locate_form_control(cname)))
		return(0);
	else if (!( headname = headername( fptr->prodname, H_EXTENSION ) ))
		return(0);

	else	{
		c_include(h, headname );
		liberate( headname );
		return(1);
		}
}

private char *allocate_cpp_module_description(char * cname)
{
	char 		* headname=(char *) 0;
	struct	form_control * fptr;

	if (!( cname ))
		return((char *) 0);
	else if (!( fptr = locate_form_control(cname)))
		return((char *) 0);
	else	return(headername( fptr->prodname, OBJ_EXTENSION));
}

/* includes pour object database visual */
private void export_cpp_datahead(FILE * h)
{
	struct	form_item * iptr;
	
	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if ((iptr->Contents.style & _FRAME_TYPE) != _DATA_FRAME)
			continue;
		else if ((iptr->Contents.align & 0x000F) != _VISUAL_FRAME)
			continue;
		else	{
			switch ( iptr->Contents.datatype ) {
				case	_WIDGET_MODULE	:
				case	_WIDGET_OVERLAY	:
					if ( method_is_valid( c_payload(iptr) ) ) {
						if (!( cpp_module_description(h,c_payload( iptr )) )) {
							fprintf(h,"class class_%s;",c_payload(iptr));
							linefeed(h);
							}
						}
					break;
				}
			}		
		}	
}

char *	cpp_item_name(struct form_item * iptr)
{
	static char *t=(char *)0;
	static unsigned int l=0;

	if (!(iptr)) {
		if (t) t=(char *)liberate(t);
		l=0;
		return(NULL);
		}
	if (l < (strlen(iptr->Contents.name)+strlen(DECORE_CLASS)+10)) {
		if (t) t=(char *)liberate(t);
		l=strlen(iptr->Contents.name)+strlen(DECORE_CLASS)+10;
		t=(char *)allocate(l);
		}
	if ((iptr->Contents.style & _FRAME_TYPE )==_RADIO_FRAME)
		sprintf(t,"%s%s%u",iptr->Contents.name,DECORE_CLASS,iptr->Contents.radio);
	else	sprintf(t,"%s%s",iptr->Contents.name,DECORE_CLASS);
	return(t);
}

private	void	define_cpp_instance(FILE * h, char * cname)
{
	struct	form_item * iptr;
	struct form_item * wptr=(struct form_item*) 0;
	char	pbuffer[256]="\0";
	char *WidgetClass;


	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		WidgetClass=get_cpp_widget_class(iptr->Contents.style);
		if (!method_is_valid(WidgetClass)) continue;

		if ((iptr->Contents.style & _FRAME_TYPE ) == _WINDOW_FRAME)
			{
			wptr = iptr;
			if (!( FixedWindows )) {
				sprintf(pbuffer,"%s->x",cpp_item_name(iptr));
				set_zero_window_column( pbuffer, iptr->Contents.x );	
				sprintf(pbuffer,"%s->y",cpp_item_name(iptr));
				set_zero_window_line( pbuffer,iptr->Contents.y );
				pbuffer[0]=0;
				}
			}
#ifdef GWB_1
		/* debut GWB le 14/03/2007 */
		if ((iptr->Contents.style & _FRAME_TYPE) == _FORM_FRAME)
			{
			indent(h,1);
			fprintf(h,"%s_%s * %s%s;",cname,iptr->Contents.name,iptr->Contents.name);
			}
		else
		/* fin GWB le 14/03/2007 */
#endif
		indent(h,1);
		switch (iptr->Contents.style & _FRAME_TYPE ) {
			case _DATA_FRAME	:
				if (method_is_valid(c_payload(iptr))) {
					switch ( iptr->Contents.datatype ) {
						case	_WIDGET_MODULE	:
						case	_WIDGET_OVERLAY	:
							fprintf(h,"class_%s *%s;",c_payload(iptr),cpp_item_name(iptr));
							break;

						case	_WIDGET_CLASS  	:
							fprintf(h,"struct %s %s;",c_payload(iptr),cpp_item_name(iptr));
							break;

						case 	_WIDGET_POINTER : 
							fprintf(h,"struct %s *%s;",c_payload(iptr),cpp_item_name(iptr));
							break;
						}
					break;
					}
			default	:
				fprintf(h,"class_visual_%s *%s;",WidgetClass,cpp_item_name(iptr));
				break;
			}
		linefeed(h);
		}
	return;
}

private	void	define_cpp_radio(FILE * h)
{
	struct	form_item * iptr;

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (((iptr->Contents.style & _FRAME_TYPE ) == _RADIO_FRAME)
		&&   ( iptr->Contents.radio == 1 )) {
			fprintf(h,"\tint value_%s;",iptr->Contents.name);
			linefeed(h);
			}
		}
	return;
}

void define_cpp_help(FILE *h,char *cname)
{
	struct	form_control * fptr;
	struct	form_item    * iptr;
	if (!( fptr = Context.Form ))
		return;
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if (!( detect_widget_help( iptr ))) 
			continue;
		else	{
			indent(h,1);
			if ((iptr->Contents.style & _FRAME_TYPE) != _RADIO_FRAME)
				fprintf(h,"int %s_help();",iptr->Contents.name);
			else	fprintf(h,"int %s%u_help();",iptr->Contents.name,iptr->Contents.radio);			
			linefeed(h);
			}
		}
	return;
}

void cpp_entete(FILE *h,char *nclass,char *fonction)
{
	unsigned int i;
	char buffer[256];
	if (nclass)
		sprintf(buffer,"fonction %s :: %s",nclass,fonction);
	else	sprintf(buffer,"fonction %s",fonction);

	linefeed(h); 
	linefeed(h); 
	c_comment_line (h,buffer,0);
	c_comment_space(h,buffer,0);
	c_comment(h,buffer,0);
	c_comment_space(h,buffer,0);
	c_comment_line (h,buffer,0);
	linefeed(h);
}

public	void	cpp_forms_method_prototype(FILE * h, struct forms_method * mptr, struct form_control * fptr,char *cname)
{

	switch (( mptr->type & _METHOD_TYPE) ) {
		case	_METHOD_VOID	:	fprintf(h,"void\t"); break;
		case	_METHOD_BYTE 	:	fprintf(h,"char\t"); break;
		case	_METHOD_WORD 	:	fprintf(h,"short\t"); break;
		case	_METHOD_NUMERIC :	fprintf(h,"float\t"); break;
		case	_METHOD_CLASS	:	fprintf(h,"struct %s ",mptr->klass); break;
		case	_METHOD_STRING	:	fprintf(h,"char *\t" ); break;
		case	_METHOD_LONG    :
					if (string_compare(__c_stdinput,mptr->name))
						fprintf(h,"int\t" );
					else
						fprintf(h,"long\t" );
					break;
		}
	if ( mptr->type & _METHOD_POINTER )
		fprintf(h," * ");

	if (cname) fprintf(h,"%s :: ",cname);
	fprintf(h,"%s(",mptr->name);

	if (!( method_is_valid(mptr->signature )))
		fprintf(h,")");
	else 	fprintf(h,"%s)",mptr->signature);
	return;
}

/* -------------------------------- */
/* attache une méthode du container */
/* -------------------------------- */
void attache_method(FILE *h,struct form_item *iptr,char *methode,char *cname,char *fonction,int margin)
{
	indent(h,margin);
	fprintf(h,"%s(%s,%s,&%s::%s_%s,this);",_ATTACHE,cpp_item_name(iptr),methode,cname,iptr->Contents.name,fonction);
	linefeed(h);
	return;
}

void attache_method_radio(FILE *h,struct form_item *iptr,char *methode,char *cname,char *fonction,int margin)
{
	indent(h,margin);
	fprintf(h,"%s(%s,%s,&%s::%s%u_%s,this);",_ATTACHE,cpp_item_name(iptr),methode,cname,iptr->Contents.name,iptr->Contents.radio,fonction);
	linefeed(h);
	return;
}

/* -------------------------------- */
/* attache une méthode de l'object  */
/* -------------------------------- */
void attache_method_base(FILE *h,struct	form_item *iptr,char *methode,char *fonction,int margin)
{
	indent(h,margin);
	fprintf(h,"%s(%s,%s,&",_ATTACHE,cpp_item_name(iptr),methode);

	switch (iptr->Contents.style & _FRAME_TYPE ) {
		case _DATA_FRAME:
			if (((iptr->Contents.align & 0x000F) == _VISUAL_FRAME) 
			&&  (( iptr->Contents.datatype == _WIDGET_MODULE) 
			||   (iptr->Contents.datatype == _WIDGET_OVERLAY)) 
			&&  (method_is_valid(c_payload(iptr))) 
			&&  (!(iptr->Contents.align & _A_BOLD))) {
				fprintf(h,"class_%s",c_payload(iptr));
				break;
				}
		default	:
			fprintf(h,"class_visual_%s",get_cpp_widget_class(iptr->Contents.style));
			break;
		}
	fprintf(h,"::%s,%s);",fonction,cpp_item_name(iptr));
	linefeed(h);
	return;
}

public	void	define_cpp_forms_method(FILE * h, struct form_control * fptr,int *wptr,int type)
{
	struct	forms_method 	* mptr;
	char			* optr;
	int first=0;

	if (!( fptr ))	return;

/*	if ( C_Config.newstdin ==2 ) {*/
	if (!type) {
		if (*wptr) linefeed(h);
		write_protect(h,wptr,type);
		indent(h,1);
		fprintf(h,"int %s();",__c_stdinput);
		linefeed(h);
		}

	for (	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {
		if (!( mptr->name ))
			continue;
		else if (!( mptr->type & _METHOD_FUNCTION ))
			continue;
		else if (string_compare(__c_stdinput,mptr->name))
			continue;
		else	{
			if ((!( mptr->type & _METHOD_PUBLIC )) && (!type)) continue;
			if ((( mptr->type & _METHOD_PUBLIC )) && (type)) continue;
			if (!first) { linefeed(h); first=1; }
			write_protect(h,wptr,type);
			indent(h,1);
			cpp_forms_method_prototype(h,mptr,fptr,NULL);
			fprintf(h,";");
			linefeed(h);
			}
		}
	return;
}

private	void	define_cpp_methods(FILE * h)
{
	struct	form_item * iptr;

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		if (method_is_valid( iptr->Contents.events->on_create )
		&&  ( iptr->Contents.events->xo_create & _EVENT_IS_FUNCTION ))	{
			indent(h,1);
			fprintf(h,"int %s_%s();",iptr->Contents.name,__method_create);
			linefeed(h);
			}

		if (method_is_valid( iptr->Contents.events->on_remove )
		&&  ( iptr->Contents.events->xo_remove & _EVENT_IS_FUNCTION ))	{
			indent(h,1);
			fprintf(h,"int %s_%s();",iptr->Contents.name,__method_remove);
			linefeed(h);
			}

		if (method_is_valid( iptr->Contents.events->on_show )
		&&  ( iptr->Contents.events->xo_show & _EVENT_IS_FUNCTION ))	{
			indent(h,1);
			fprintf(h,"int %s_%s();",iptr->Contents.name,__method_show);
			linefeed(h);
			}

		if (method_is_valid( iptr->Contents.events->on_hide )
		&&  ( iptr->Contents.events->xo_hide & _EVENT_IS_FUNCTION ))	{
			indent(h,1);
			fprintf(h,"int %s_%s();",iptr->Contents.name,__method_hide);
			linefeed(h);
			}

		if (method_is_valid( iptr->Contents.events->on_get_focus )
		&&  ( iptr->Contents.events->xo_get_focus & _EVENT_IS_FUNCTION )) {
			indent(h,1);
			fprintf(h,"int %s_%s();",iptr->Contents.name,__method_getfocus);
			linefeed(h);
			}

		if (method_is_valid( iptr->Contents.events->on_lose_focus )
		&&  ( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION )) {
			indent(h,1);
			fprintf(h,"int %s_%s();",iptr->Contents.name,__method_losefocus);
			linefeed(h);
			}

		if (method_is_valid( iptr->Contents.events->on_event )
		&&  ( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION ))	{
			indent(h,1);
			fprintf(h,"int %s_%s();",iptr->Contents.name,__method_event);
			linefeed(h);
			}

		switch ((iptr->Contents.style & _FRAME_TYPE))	{
			case _SCROLL_FRAME	:
			case _WINDOW_FRAME	:
				indent(h,1);
				fprintf(h,"int %s_%s();",iptr->Contents.name,__method_action);
				linefeed(h);
				break;
			}
		}
	return;
}

public  int	cpp_member_parameters( FILE * h ,int iscall)
{
	int	nb;
	char *	prefix, * suffix;
	struct form_item * iptr;
	if (iscall != 1)
		prefix = "char *";
	else	prefix = "\0";

	if (iscall != 2)
		suffix = ",";
	else	suffix = ";";

	for (	nb=0,iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		switch ((iptr->Contents.style)&_FRAME_TYPE) {
			case	_RADIO_FRAME	:
				if ( iptr->Contents.radio != 1 )
					break;
			case	_GRAPH_FRAME	:
			case	_SWITCH_FRAME	:
			case	_SELECT_FRAME	:
			case	_CHECK_FRAME	:
			case	_EDIT_FRAME	:
				
				if (!( iptr->Contents.interfaceitem ))
					break;
				if (iscall != 99) {
					if ( nb )
						fprintf(h,"%s",suffix);
					linefeed(h);
					indent(h,2);	
					fprintf(h,"%s p%s",prefix,iptr->Contents.name);
					}
				nb++;
			}
		}
	if ((iscall==2) && (nb)) 
		fprintf(h,"%s",suffix);
	return(nb);
}

void cpp_initialise_parameters(FILE * h)
{
	struct form_item * iptr;

	for (iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		switch ((iptr->Contents.style)&_FRAME_TYPE) {
			case	_RADIO_FRAME	:
				if ( iptr->Contents.radio != 1 )
					break;
			case	_GRAPH_FRAME	:
			case	_SWITCH_FRAME	:
			case	_SELECT_FRAME	:
			case	_CHECK_FRAME	:
			case	_EDIT_FRAME	:
				
				if (!( iptr->Contents.interfaceitem ))
					break;

				indent(h,1);
				fprintf(h,"%s.p%s = p%s;",_DATA_INTERFACE,iptr->Contents.name,iptr->Contents.name);
				linefeed(h);
			}
		}
	return;
}


public  void	cpp_transfer_parameters( FILE * h , int direction )
{
	int	e=0;
	int	item=0;
	int	s;
	struct form_item * iptr;
	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (!( iptr->Contents.interfaceitem ))
			continue;
		switch (((s=iptr->Contents.style)&_FRAME_TYPE)) {
			case	_EDIT_FRAME	:
				if (!( direction )) {
					if ( iptr->Contents.datatype == _WIDGET_TEXTFILE ) {
						if (!( e )) {
							indent(h,1);
							fprintf(h,"if (%s == 27 ) {",__c_keycode);
							linefeed(h);
							}
						e++;
						indent(h,2);
						fprintf(h,"filetransferdrop(");
						fprintf(h,"%s->buffer);",cpp_item_name(iptr));
						linefeed(h);
						}
					}
				}
		}
	if ( e != 0 ) {
		indent(h,2);
		linefeed(h);
		c_else(h,1);
		}
	else	{
		indent(h,1);
		fprintf(h,"if (%s != 27 ) {",__c_keycode);
		linefeed(h);
		}
	indent(h,2);
	fprintf(h,"strcpy(signature,%c%s%c);",__QUOTE,Signature,__QUOTE);
	linefeed(h);
	indent(h,2);
	fprintf(h,"%s(signature,signature);",__visual_signature);
	linefeed(h);
	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (!( iptr->Contents.interfaceitem ))
			continue;
		switch (((s=iptr->Contents.style)&_FRAME_TYPE)) {
			case	_RADIO_FRAME	:
				if ( iptr->Contents.radio != 1 )
					break;
				if ( direction ) {
					/* transfer  in */
					indent(h,2);
					fprintf(h,"%s((void *) 0, 0, %s.p%s);",__visual_transferin,_DATA_INTERFACE,iptr->Contents.name);
					linefeed(h);
					indent(h,2);
					fprintf(h,"if (!( %s.p%s )) %s->value=0;",_DATA_INTERFACE,iptr->Contents.name,cpp_item_name(iptr));
					linefeed(h);
					indent(h,2);
					fprintf(h,"else");
					indent(h,1);
					fprintf(h,"value_%s = *((int *)%s.p%s);",iptr->Contents.name,_DATA_INTERFACE,iptr->Contents.name);
					linefeed(h);
					}
				else	{
					/* transfer out */
					indent(h,2);
					fprintf(h,"%s((void *) 0, 0, %s.p%s);",__visual_transferout,_DATA_INTERFACE,iptr->Contents.name);
					linefeed(h);
					indent(h,2);
					fprintf(h,"if ( %s.p%s != (char *) 0)",_DATA_INTERFACE,iptr->Contents.name);
					linefeed(h);
					indent(h,3);
					fprintf(h,"*((int*)%s.p%s) = value_%s;",_DATA_INTERFACE,iptr->Contents.name,iptr->Contents.name);
					linefeed(h);
					}
				item++;
				break;


			case	_SELECT_FRAME	:
			case	_SWITCH_FRAME	:
			case	_GRAPH_FRAME	:
			case	_CHECK_FRAME	:
				if ( direction ) {
					/* transfer  in */
					indent(h,2);
					fprintf(h,"%s((void *) 0, 0, %s.p%s);",__visual_transferin,_DATA_INTERFACE,iptr->Contents.name);
					linefeed(h);
					indent(h,2);
					fprintf(h,"if (!( %s.p%s )) %s->value=0;",_DATA_INTERFACE,iptr->Contents.name,cpp_item_name(iptr));
					linefeed(h);
					indent(h,2);
					fprintf(h,"else");
					indent(h,1);
					fprintf(h,"%s->value = *((int *)%s.p%s);",cpp_item_name(iptr),_DATA_INTERFACE,iptr->Contents.name);
					linefeed(h);
					}
				else	{
					/* transfer out */
					indent(h,2);
					fprintf(h,"%s((void *) 0, 0, %s.p%s);",__visual_transferout,_DATA_INTERFACE,iptr->Contents.name);
					linefeed(h);
					indent(h,2);
					fprintf(h,"if ( %s.p%s != (char *) 0)",_DATA_INTERFACE,iptr->Contents.name);
					linefeed(h);
					indent(h,3);
					fprintf(h,"*((int*)%s.p%s) = %s->value;",_DATA_INTERFACE,iptr->Contents.name,cpp_item_name(iptr));
					linefeed(h);
					}
				item++;
				break;
			case	_EDIT_FRAME	:
				calculate_edit_size( &iptr->Contents );
				indent(h,2);
				if ( direction ) {
					/* transfer  in */
					if ( iptr->Contents.datatype == _WIDGET_TEXTFILE ) {	
						fprintf(h,"liberate(%s->buffer);",cpp_item_name(iptr));
						linefeed(h); indent(h,2);
						fprintf(h,"%s->buffer=(char *) 0;",cpp_item_name(iptr));
						linefeed(h);
						indent(h,2);
						fprintf(h,"%s(&%s->buffer, %u, %s.p%s);",__visual_transferin,cpp_item_name(iptr)
									,iptr->Contents.size,_DATA_INTERFACE,iptr->Contents.name);
						}
					else	{	
						fprintf(h,"%s(%s->buffer, %u, %s.p%s);",__visual_transferin,cpp_item_name(iptr),iptr->Contents.size,_DATA_INTERFACE,iptr->Contents.name);
						}
					linefeed(h);
					}
				else	{
					/* transfer out */
					if ( iptr->Contents.datatype == _WIDGET_TEXTFILE ) {	
						fprintf(h,"%s(&%s->buffer, %u, %s.p%s);",__visual_transferout,cpp_item_name(iptr),iptr->Contents.size,_DATA_INTERFACE,iptr->Contents.name);
						}
					else	{
						fprintf(h,"%s(%s->buffer, %u, %s.p%s);",__visual_transferout,cpp_item_name(iptr),iptr->Contents.size,_DATA_INTERFACE,iptr->Contents.name);
						}
					linefeed(h);
					}
				item++;
			}
		}
	indent(h,2);
	fprintf(h,"}");
	linefeed(h);
	return;
}

#ifdef GWB_1
private	void	sort_cpp_form( FILE * h,char * cname )
{
	struct form_item * iptr;
	int linelength, nblines,i,fields,posit;
	int	fieldwidth[_MAX_FORM_FIELDS];
	char *tptr;
	char *rptr;
	char comment[256];

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
			continue;

		linefeed(h);
		c_comment_line(h,"resolve sorted item",0);
		c_comment(h,"resolve sorted item",0);
		c_comment_line(h,"resolve sorted item",0);
		fprintf(h,"int %s_%s::tabsort(int nelts)",cname,iptr->Contents.name);
		linefeed(h);
		fprintf(h,"{"); 
		linefeed(h);
		fprintf(h,"if (!( nelts )) { return(nelts); }");
		linefeed(h);
		fprintf(h,"else {");
		linefeed(h);	indent(h,1);
		fprintf(h,"return( this.tab_sort[(nelts-1)] );");
		linefeed(h);	indent(h,1);
		fprintf(h,"}");
		linefeed(h);
		fprintf(h,"}");
		linefeed(h);

		linefeed(h);
		c_comment_line(h,"select the linesort to fill",0);
		c_comment(h,"select the linesort to fill",0);
		c_comment_line(h,"select the linesort to fill",0);
		fprintf(h,"void %s_%s::linesort(int nelts)",cname,iptr->Contents.name);
		linefeed(h);

		fprintf(h,"{");
		linefeed(h);
		fprintf(h,"if (nelts>this.nelt) nelts=this.nelts");
		linefeed(h);
		fprintf(h,"if (!nelts) nelts=1;");
		linefeed(h);
		calculate_edit_size( &iptr->Contents );
		calculate_form_lines( iptr, &linelength, &nblines );
		fprintf(h,"this.row = &this.libsort[(nelts-1)*%u];",linelength);
		linefeed(h);
		fprintf(h,"}");
		linefeed(h);

		linefeed(h);
		c_comment_line(h,"allocate the intermediate sort table",0);
		c_comment(h,"allocate the intermediate sort table",0);
		c_comment_line(h,"allocate the intermediate sort table",0);

		fprintf(h,"void %s_%s::startsort(int nelts)",cname,iptr->Contents.name);
		linefeed(h);

		fprintf(h,"{");
		linefeed(h);

		fprintf(h,"if (this.nelt<nelts) {");
		linefeed(h);
		indent(h,1);
		fprintf(h,"liberate(this.tab_sort);");
		linefeed(h);
		indent(h,1);
		fprintf(h,"if ((this.tab_sort=allocate(nelts*sizeof(int))) == NULL) return;");
		linefeed(h);				
		indent(h,1);
		fprintf(h,"for (this.nelt=0;this.nelt<nelts;this.nelt++)");
		linefeed(h);
		indent(h,2);
		fprintf(h,"{ this.tab_sort[this.nelt]=this.nelt+1; }	/* initialisation tableau sans tri */");
		linefeed(h);
		indent(h,1);
		fprintf(h,"}");
		linefeed(h);
		fprintf(h,"if ((this.indsort=allocate(nelts*sizeof(char))) == NULL) return;");
		linefeed(h);
		fprintf(h,"if ((this.libsort=allocate(nelts*%u)) != NULL)",linelength);
		linefeed(h);
		indent(h,1);
		fprintf(h,"memset(this.libsort,' ',nelts*%u);",linelength);
		linefeed(h);
		fprintf(h,"}");
		linefeed(h);	linefeed(h);

		c_comment_line(h,"sort the intermediate table into tab_sort",0);
		c_comment(h,"sort the intermediate table into tab_sort",0);
		c_comment_line(h,"sort the intermediate table into tab_sort",0);
		fprintf(h,"void %s_%s::sort(int nelts)",cname,iptr->Contents.name);
		linefeed(h);
		fprintf(h,"{");
		linefeed(h);
		fprintf(h,"int\ti,j,k;");
		linefeed(h);
		fprintf(h,"memset(this.indsort,0,nelts);");
		linefeed(h);
		fprintf(h,"for (i=0;i<nelts;i++) {");
		linefeed(h);
		indent(h,1);
		fprintf(h,"for (k=0;(k<nelts) && (this.indsort[k]);k++);");
		linefeed(h);
		indent(h,1);
		fprintf(h,"if (k<nelts-1) {");
		linefeed(h);
		indent(h,2);
		fprintf(h,"for (j=k+1;j<nelts;j++) {");
		linefeed(h);
		indent(h,3);
		fprintf(h,"if ((!this.indsort[j]) && (this.compare(j,k)<0)) k=j;");
		linefeed(h);
		indent(h,3);
		fprintf(h,"}	/* for j */");
		linefeed(h);
		indent(h,2);
		fprintf(h,"}	/* if k<nbelt-1 */");
		linefeed(h);
		indent(h,1);
		fprintf(h,"this.tab_sort[i]=k+1;");
		linefeed(h);
		indent(h,1);
		fprintf(h,"this.indsort[k]=1;");
		linefeed(h);
		indent(h,1);
		fprintf(h,"}	/* for i */");
		linefeed(h);
		fprintf(h,"liberate(this.libsort);");
		linefeed(h);
		fprintf(h,"liberate(this.indsort);");
		linefeed(h);
		fprintf(h,"}");
		linefeed(h);	linefeed(h);

		c_comment_line(h,"compare the elements a et b of libsort",0);
		c_comment(h,"compare the elements a et b of libsort",0);
		c_comment_line(h,"compare the elements a et b of libsort",0);
		fprintf(h,"int %s_%s::compare(int a,int b)",cname,iptr->Contents.name);
		linefeed(h);
		fprintf(h,"{");
		fprintf(h,"int i,j;");
		linefeed(h); linefeed(h);
		calculate_edit_size( &iptr->Contents );
		calculate_form_lines( iptr, &linelength, &nblines );
		if (( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) )) {
			if ((tptr = abal_payload(iptr)) != NULL) {
				memset(comment,0,256);
				strcpy(comment,tptr);
				tptr=comment;
				while ((rptr =strchr(tptr,'|')) != (char *) 0) {
					*rptr=0;
					tptr+=strlen(tptr)+1;
					}
				}
			tptr=comment;
			fprintf(h,"i=memicmp(&this.libsort[%d*a],&this.libsort[%d*b],%d); /* compare zone 1 */",
				linelength,linelength,fieldwidth[0]);
			posit=0;
			linefeed(h);
			fprintf(h,"switch (this.formsort) {");
			linefeed(h);
			for (i=0;i<fields;i++) {
				indent(h,1);
				fprintf(h,"case %d:	/* %s ordre normal */",i+1,tptr);
				linefeed(h);
				indent(h,2);
				if (i) {
					fprintf(h,"j=memicmp(&this.libsort[%d*a+%d],&this.libsort[%d*b+%d],%d);",
						linelength,posit,linelength,posit,fieldwidth[i]);
					linefeed(h);
					indent(h,2);
					fprintf(h,"if (!j) return(i); /* if zones equal, compare column 1 */");
					linefeed(h);
					indent(h,2);
					fprintf(h,"return(j);");
					}
				else	fprintf(h,"return(i);");
				linefeed(h);	linefeed(h);
				indent(h,1);
				fprintf(h,"case -%d:	/* %s ordre inverse */",i+1,tptr);
				linefeed(h);
				indent(h,2);
				if (i) 	{
					fprintf(h,"j=memicmp(&this.libsort[%d*b+%d],&this.libsort[%d*a+%d],%d);",
						linelength,posit,linelength,posit,fieldwidth[i]);
					linefeed(h);
					indent(h,2);
					fprintf(h,"if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */");
					linefeed(h);
					indent(h,2);
					fprintf(h,"return(j);");
					}
				else	fprintf(h,"return(-i);");
				linefeed(h);
				if (i<fields-1) linefeed(h);
				posit+=fieldwidth[i];
				tptr+=strlen(tptr)+1;
				}
			indent(h,1);
			fprintf(h,"default:		/* pas de tri */");
			linefeed(h);
			indent(h,2);
			fprintf(h,"if (a<b) return(-1);");
			linefeed(h);
			indent(h,2);
			fprintf(h,"return(1);");
			linefeed(h);
			indent(h,1);
			fprintf(h,"} /* fin du switch */");
			linefeed(h);
			}
		fprintf(h,"}");
		linefeed(h);	linefeed(h);

		c_comment_line(h,"select the line to fill",0);
		c_comment(h,"select the line to fill",0);
		c_comment_line(h,"select the line to fill",0);
		fprintf(h,"void %s_%s::line(int nelts)",cname,iptr->Contents.name);
		linefeed(h);
		fprintf(h,"{");
		linefeed(h);
		fprintf(h,"if (nelts>0) this.row = &this.buffer[(nelts-1)*%u];",linelength);
		linefeed(h);
		fprintf(h,"}");
		linefeed(h);
		linefeed(h);
		
		c_comment_line(h,"select the adresse of column to fill",0);
		c_comment(h,"select the adresse of column to fill",0);
		c_comment_line(h,"select the adresse of column to fill",0);
		fprintf(h,"char *%s_%s::column(int ncol)",cname,iptr->Contents.name);
		linefeed(h);
		fprintf(h,"{");
		if (( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) )) {
			if ((tptr = abal_payload(iptr)) != NULL) {
				memset(comment,0,256);
				strcpy(comment,tptr);
				tptr=comment;
				while ((rptr =strchr(tptr,'|')) != (char *) 0) {
					*rptr=0;
					tptr+=strlen(tptr)+1;
					}
				}
			tptr=comment;
			posit=0;
			linefeed(h);
			fprintf(h,"switch (ncol) {");
			linefeed(h);
			for (i=0;i<fields;i++) 	{
				indent(h,1);
				fprintf(h,"case %d:	/* %s */",i+1,tptr);
				linefeed(h); indent(h,2);
				fprintf(h,"return(this.row + %u);",posit);
				linefeed(h);
				linefeed(h);
				posit+=fieldwidth[i];
				tptr+=strlen(tptr)+1;
				}
			indent(h,1);
			fprintf(h,"default:");
			linefeed(h); indent(h,2);
			fprintf(h,"return(this.row);");
			linefeed(h); indent(h,1);
			fprintf(h,"}");
			}
		fprintf(h,"}");
		linefeed(h);
		linefeed(h);
		}
	return;
}
#endif	/* GWB_1 */

private	void	cpp_national_messages( FILE * h, struct form_item * iptr )
{
	int	nl;
	char *	sptr;

	if ( max_payload_size( iptr ) > 0 ) {

		for (nl=0; nl < MAXNATLANG; nl++ ) {
			indent(h,1);
			fprintf(h,"%s->msg[%u]=",cpp_item_name(iptr),nl);
			if ((!(sptr = iptr->Contents.messages[nl]))
			&&  (!(sptr = iptr->Contents.payload)))
				fprintf(h,"%c %c;",__QUOTE,__QUOTE);
			else if ( *sptr == _UNQUOTED_STRING )
				fprintf(h,"%c %c;",__QUOTE,__QUOTE);
			else if ((iptr->Contents.style & _FRAME_TYPE ) == _RADIO_FRAME)
				fprintf(h,"%s%u_%s;",language_prefix(nl),iptr->Contents.radio,iptr->Contents.name);
			else	fprintf(h,"%s_%s;",language_prefix(nl),iptr->Contents.name);
			linefeed(h);
			}
		}
	for (nl=0; nl < MAXNATLANG; nl++ ) {
		if (!(sptr = iptr->Contents.hmessages[nl]))
			continue;
		else if ( *sptr == _UNQUOTED_STRING )
			continue;
		else	{
			indent(h,1);
			fprintf(h,"%s->hint[%u]=",cpp_item_name(iptr),nl);
			if ((iptr->Contents.style & _FRAME_TYPE ) == _RADIO_FRAME)
				fprintf(h,"%s%u__%s;",language_prefix(nl),iptr->Contents.radio,iptr->Contents.name);
			else	fprintf(h,"%s__%s;",language_prefix(nl),iptr->Contents.name);
			linefeed(h);
			}
		}
	return;		
}

private	void	generate_cpp_initfont(FILE * h,int margin)
{
	int	i;
	char *	fname;

	for (i=FONT_MIN; i< FONT_MAX; i++ ) {
		if (!(fname = font_name[i]))
			continue;
		else	{
			indent(h,margin);
			fprintf(h,"vfh[%u] = new class_visual_font();",i);
			linefeed(h); 
			}
		}
	return;
}

private	void	generate_cpp_createfont(FILE * h,int margin)
{
	int	i;
	char *	fname;

	for (i=FONT_MIN; i< FONT_MAX; i++ ) {
		if (!(fname = font_name[i]))
			continue;
		else	{
			indent(h,margin);
			fprintf(h,"vfh[%u]->charger_fonte(",i);
			quoted_filename(h,fname);
			fprintf(h,");");
			linefeed(h); 
			}
		}
	return;
}

public	void	generate_cpp_popup( FILE * h, struct form_item * wptr, int margin )
{
	indent(h,margin);	
	fprintf(h,"%s->ObjPopUp();",cpp_item_name(wptr));
	linefeed(h);
}

public	void	generate_cpp_popdown( FILE * h, struct form_item * wptr, int margin )
{
	indent(h,margin);	
	fprintf(h,"%s->ObjPopDown();",cpp_item_name(wptr));
	linefeed(h);
}

public	void	drop_cpp_widget_saver( FILE * h, struct form_item * wptr, int margin )
{
	indent(h,margin);	
	fprintf(h,"%s->DropSaver();",cpp_item_name(wptr));
	linefeed(h);
}


private	void	activate_cpp_method( FILE * h,char * mptr, char* nptr, char * eptr, int type, int margin )
{
	if (!( method_is_valid( eptr ) ))
		return;
	if (!( type )) {
		/* void call */
		indent(h,margin);
		fprintf(h,"(void) %s_%s();",mptr,nptr);
		}
	else	{
		indent(h,margin);
		fprintf(h,"if ((%s = %s_%s()) != -1) break;",
			__c_keycode,mptr,nptr);
		}
	linefeed(h);
	return;
}

public	void	cpp_special_method( FILE * h, struct  forms_method * mptr, int i,char *cname )
{
	int	l;
	char *	qname;

	if (!( qname = mptr->name ))
		return;

	if ( mptr->type & _METHOD_FUNCTION ) {

		/* Function Method */
		/* --------------- */
		indent(h,i);
		fprintf(h,"%s();",qname);
		linefeed(h);
		}
	else	{
		/* Inline Method */
		/* ------------- */
		inline_cpp_method(h,qname,qname,mptr->text,0,i,cname,NULL);
		}
	return;
}

private	int	inline_cpp_method( FILE * h,char * mptr, char* nptr, char * eptr, int type, int margin,char *cname,	struct form_item * iptr  )
{
	int	l;
	char thisname[256];

	if (!(l = method_is_valid( eptr )))
		return(0);
	else	{
		sprintf(thisname,"%s%s->",mptr,DECORE_CLASS);
		return( cpp_method_body( h, eptr, l,thisname, margin,cname,iptr) );
		}
}



private	void	create_cpp_form(FILE * h, char * cname,	struct form_item * *value_wptr)
{
	struct	form_item * iptr;
	struct form_item * wptr=(struct form_item*) 0;

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		if (!method_is_valid(get_cpp_widget_class(iptr->Contents.style))) 
			continue;

		if (((iptr->Contents.style & _FRAME_TYPE ) == _DATA_FRAME) 
		&&  (( iptr->Contents.datatype == _WIDGET_CLASS) 
		||   (iptr->Contents.datatype == _WIDGET_POINTER) 
		||   (iptr->Contents.align & _A_BOLD) 
		||   (!method_is_valid(c_payload(iptr))))) 
			continue;
		
		if ((iptr->Contents.style & _FRAME_TYPE ) == _WINDOW_FRAME) {
			wptr = iptr;
			*value_wptr=iptr;
			}

		if ( method_is_valid( iptr->Contents.events->on_create ) ) { 
			if ( iptr->Contents.events->xo_create & _EVENT_IS_FUNCTION ) {
#if USE_POINTER_METHOD
				indent(h,1);
				fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONCREATE);
				linefeed(h);
#else
				activate_cpp_method(h,iptr->Contents.name,__method_create,iptr->Contents.events->on_create,0,1);
#endif
				}
			else	{
#if USE_POINTER_METHOD
				indent(h,1);
				fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONCREATE);
				linefeed(h);
#else
				indent(h,1);
				fprintf(h,"%s->%s();",cpp_item_name(iptr),_ON_CREATE);
				linefeed(h);
#endif
				inline_cpp_method(h,iptr->Contents.name,__method_create,iptr->Contents.events->on_create,0,1,cname,iptr);
				}
			}
		else	{
#if USE_POINTER_METHOD
			indent(h,1);
			fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONCREATE);
			linefeed(h);
#else
			indent(h,1);
			fprintf(h,"%s->%s();",cpp_item_name(iptr),_ON_CREATE);
			linefeed(h);
#endif
			}
		}

	/* handle screen saver */
	/* ------------------- */
	if ( Context.Form->ispopup ) {
		indent(h,1);
		fprintf(h,"SetPopUp(1,");
		if ((wptr) && (( wptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME )
		&&  ( wptr->Contents.align & _A_SHADOW )) {
			fprintf(h,"10");
			}
		else	{
			fprintf(h,"0");
			}
		fprintf(h,");");linefeed(h);
		}
}

public	int	cpp_macro_conversion( FILE * h, char * sptr, char * hptr )
{
	char *cname = Context.Form->identifier;
	int	feeder=0;
	return( cpp_method_line( h, sptr, strlen(sptr), hptr, &feeder , cname,(struct form_item *)0) );
}

private	int	is_payload_unquoted(struct form_item * iptr)
{
	char		*	sptr;
	struct 	form_control * fptr;

	if (!( fptr = iptr->parent ))
		sptr=iptr->Contents.payload;
	else if (!( fptr->formflags & _INTERNATIONAL ))
		sptr=iptr->Contents.payload;
	else if (!( fptr->formflags & _MULTILINGUAL  ))
		sptr=iptr->Contents.messages[fptr->natlang];
	else if (!( sptr = c_payload(iptr) ))
		sptr=iptr->Contents.messages[fptr->natlang];
	else if ( *sptr == _UNQUOTED_STRING )
		sptr=iptr->Contents.messages[fptr->natlang];
	else return(0);
	if (!sptr) return(0);
	if (*sptr == _UNQUOTED_STRING)
		return(1);
	else
		return(0);
}

private	void	cpp_payload_value(FILE * h, struct form_item * iptr)
{
	char		*	sptr;
	struct 	form_control * fptr;

	if (!( fptr = iptr->parent ))
		string_value(h,iptr->Contents.payload);
	else if (!( fptr->formflags & _INTERNATIONAL ))
		string_value(h,iptr->Contents.payload);
	else if (!( fptr->formflags & _MULTILINGUAL  ))
		string_value(h,iptr->Contents.messages[fptr->natlang]);
	else if (!( sptr = c_payload(iptr) ))
		{
		if (method_is_valid(iptr->Contents.messages[fptr->natlang]))
			{
			string_value(h,iptr->Contents.messages[fptr->natlang]);
			}
		else
			fprintf(h,"(char *)0");
		}
	else if ( *sptr == _UNQUOTED_STRING )
		string_value(h,iptr->Contents.messages[fptr->natlang]);
	else fprintf(h,"(char *)0");
	return;
}

private	void	cpp_payload_parameter(FILE * h, struct form_item * iptr)
{
	fprintf(h,",");
	cpp_payload_value(h,iptr);
	return;
}


private	void cpp_add_visual_element(FILE * h, struct form_item * iptr, char * sptr)
{
	char *	vptr;
	char *	selection_item(int,char *);
	struct line_parser SvLineParser;
	int item=0;

	if ( sptr != (char *) 0) {
		while ((vptr = selection_item(item,sptr )) != (char *) 0) {		
			item++;
			indent(h,1);
			fprintf(h,"%s->AddStyleSheet(",cpp_item_name(iptr));

			if ( *vptr != _UNQUOTED_STRING ) {
				quoted_string(h,vptr);
				}
			else 	{
				memcpy(&SvLineParser,&LineParser,sizeof(struct line_parser));
				c_macro_conversion(h,(vptr+1),(char *) 0);
				memcpy(&LineParser,&SvLineParser,sizeof(struct line_parser));
				}
			fprintf(h,");");
			linefeed(h);
			liberate( vptr );
			}
		}
	return;
}

private	void cpp_add_visual_focus_element(FILE * h, struct form_item * iptr, char * sptr)
{
	char *	vptr;
	char *	selection_item(int,char *);
	struct line_parser SvLineParser;
	int item=0;

	if ( sptr != (char *) 0) {
		while ((vptr = selection_item(item,sptr )) != (char *) 0) {		
			item++;
			indent(h,1);
			fprintf(h,"%s->AddStyleFocus(",cpp_item_name(iptr));

			if ( *vptr != _UNQUOTED_STRING ) {
				quoted_string(h,vptr);
				}
			else 	{
				memcpy(&SvLineParser,&LineParser,sizeof(struct line_parser));
				c_macro_conversion(h,(vptr+1),(char *) 0);
				memcpy(&LineParser,&SvLineParser,sizeof(struct line_parser));
				}
			fprintf(h,");");
			linefeed(h);
			liberate( vptr );
			}
		}
	return;
}

private	void	construct_cpp_form(FILE * h, char * cname)
{
	struct	form_item * iptr;
	int		  items=0;
	int linelength, nblines,i,fields;
	int	fieldwidth[_MAX_FORM_FIELDS];
	struct form_item * wptr=(struct form_item*) 0;
	char	pbuffer[256]="\0";
	int etat;
	struct form_item *first=NULL;
	struct form_item *nprevious=NULL;
	char *mptr=NULL;
	struct form_control *fptr;
	char	*	sptr;
	char *WidgetClass;
	int pwx=0,pwy=0;
	struct	window_control * pwptr=(struct window_control *) 0;

	/* déclarer tableau si widget tab */
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if ((iptr->Contents.style & _FRAME_TYPE ) == _FORM_FRAME) {
			fprintf(h,"int pfieldwidth[_MAX_FORM_FIELDS];");
			linefeed(h); linefeed(h);
			break;
			}
		}

	if ((pwptr = connect_production_window()) != (struct window_control *) 0) {
		pwx=pwptr->x;
		pwy=pwptr->y;
		}
	linefeed(h);

	generate_cpp_initfont(h,1);
	if ( Context.Form->pages ) {
		indent(h,1);
		fprintf(h,"allocate_focus_pages(%u+1);",Context.Form->pages);
		linefeed(h);
		}

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		WidgetClass=get_cpp_widget_class(iptr->Contents.style);
		if (!method_is_valid(WidgetClass)) continue;
		
		if ((iptr->Contents.style & _FRAME_TYPE ) == _FORM_FRAME) {
			calculate_edit_size( &iptr->Contents );
			calculate_form_lines( iptr, &linelength, &nblines );
			fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength);
			if (fields) {
				for (i=0;i<fields;i++) { 
					indent(h,1);
					fprintf(h,"pfieldwidth[%d]=%d;",i,fieldwidth[i]);
					linefeed(h);
					}
				}
			else 	{
				indent(h,1);
				fprintf(h,"pfieldwidth[0]=0;");
				linefeed(h);
				}
			}
		switch (iptr->Contents.style & _FRAME_TYPE ) {
			case _DATA_FRAME:
				if (((iptr->Contents.align & 0x000F) == _VISUAL_FRAME) 
				&&  (( iptr->Contents.datatype == _WIDGET_MODULE) 
				||   (iptr->Contents.datatype == _WIDGET_OVERLAY)) 
				&&   (method_is_valid(c_payload(iptr))) 
				&&   (!(iptr->Contents.align & _A_BOLD))) {
					indent(h,1);
					fprintf(h,"%s = new class_%s",cpp_item_name(iptr),c_payload(iptr));
					break;
					}

				if ((( iptr->Contents.datatype == _WIDGET_CLASS) 
				||   ( iptr->Contents.datatype == _WIDGET_POINTER)) 
				&&  (method_is_valid(c_payload(iptr)))) 
					continue;

				if (((iptr->Contents.align & 0x000F) == _VISUAL_FRAME) 
				&&  (( iptr->Contents.datatype == _WIDGET_MODULE) 
				||   (iptr->Contents.datatype == _WIDGET_OVERLAY)) 
				&&  ((iptr->Contents.align & _A_BOLD))) {
					indent(h,1);
					fprintf(h,"%s = (class_%s *)0;",cpp_item_name(iptr),c_payload(iptr));
					linefeed(h);
					continue;
					}

			default	:
				indent(h,1);
				fprintf(h,"%s = new class_visual_%s",cpp_item_name(iptr),WidgetClass);
				break;
			}

		fprintf(h,"(x+%u,y+%u", iptr->Contents.x-pwx,iptr->Contents.y-pwy);
		if ((iptr->Contents.style & _FRAME_TYPE ) == _LINE_FRAME)
			fprintf(h,",y+%u,x+%u",iptr->Contents.h,iptr->Contents.w);
		else	fprintf(h,",%u,%u",iptr->Contents.h,iptr->Contents.w);
		colour_parameter(h,iptr);
		fprintf(h,",vfh[%u],this",iptr->Contents.font);
		fprintf(h,",%u",iptr->Contents.focus);
		if (nprevious==NULL)
			fprintf(h,",NULL");
		else	fprintf(h,",%s",cpp_item_name(nprevious));
		nprevious=iptr;
		fprintf(h,",1");
		switch ((iptr->Contents.style & _FRAME_TYPE )) {
			case	_FILL_FRAME	: 
				fprintf(h,",%u",(iptr->Contents.align&_VFILL_MASK));
				break;

			case	_LINE_FRAME 	: 
				fprintf(h,",%u",iptr->Contents.size );
				break;

			case	_OUTSET_FRAME	: 
			case	_INSET_FRAME	: 
			case	_RIDGE_FRAME	: 
			case	_GROOVE_FRAME	: 
				fprintf(h,",%u",iptr->Contents.style);
				if (is_payload_unquoted(iptr))
					fprintf(h,",(char*)0");
				else	cpp_payload_parameter(h,iptr);
				align_parameter(h,iptr);
				break;

			case	_IMAGE_FRAME	: 
				if (is_payload_unquoted(iptr))
					fprintf(h,",(char*)0");
				else	cpp_payload_parameter(h,iptr);
				fprintf(h,",%u",iptr->Contents.align);
				break;

			case	_TAB_FRAME	: 
				sprintf(pbuffer,"focus_pages[%u]=%u;",iptr->Contents.page,iptr->Contents.focus);
				C_Config.page_control=1;
				if (is_payload_unquoted(iptr))
					fprintf(h,",(char*)0");
				else	cpp_payload_parameter(h,iptr);
				align_parameter(h,iptr);
				fprintf(h,",%u",iptr->Contents.adjust);
				break;
			
			case	_BUTTON_FRAME	: 
				if (is_payload_unquoted(iptr))
					fprintf(h,",(char*)0");
				else	cpp_payload_parameter(h,iptr);
				align_parameter(h,iptr);
				etat = (iptr->Contents.align & 0x0F00);
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
				fprintf(h,",%u",etat);
				break;

			case	_SELECT_FRAME	: 
				if (is_payload_unquoted(iptr))
					fprintf(h,",(char*)0");
				else	cpp_payload_parameter(h,iptr);
				fprintf(h,",0");
				align_parameter(h,iptr);
				fprintf(h,",%u",iptr->Contents.special);
				items = add_interface_item(items, iptr, _SYMBOLIC_WORD );
				break;

			case	_RADIO_FRAME	: 
				if ( iptr->Contents.radio == 1 )
					items = add_interface_item(items, iptr, _SYMBOLIC_WORD );
				if (is_payload_unquoted(iptr))
					fprintf(h,",(char*)0");
				else	cpp_payload_parameter(h,iptr);
				fprintf(h,",%u",iptr->Contents.radio);
				fprintf(h,",&value_%s",iptr->Contents.name);
				break;
			
			case	_GRAPH_FRAME	: 
				if (is_payload_unquoted(iptr))
					fprintf(h,",(char*)0");
				else	cpp_payload_parameter(h,iptr);
				fprintf(h,",0");
				break;

			case	_SWITCH_FRAME	: 
			case	_CHECK_FRAME	: 
				items = add_interface_item(items, iptr, _SYMBOLIC_WORD );
				if (is_payload_unquoted(iptr))
					fprintf(h,",(char*)0");
				else	cpp_payload_parameter(h,iptr);
				align_parameter(h,iptr);
				fprintf(h,",0");
				break;

			
			case	_WINDOW_FRAME	:
				wptr = iptr;
				if (is_payload_unquoted(iptr))
					fprintf(h,",(char*)0");
				else	cpp_payload_parameter(h, iptr);
				align_parameter(h,iptr);
				if (((fptr = iptr->parent) != (struct form_control*) 0)
				&&  (fptr->formflags & _MULTILINGUAL ))
					fprintf(h,",1");
				else	fprintf(h,",0");
				break;

			case	_TEXT_FRAME	:
				if (is_payload_unquoted(iptr))
					fprintf(h,",(char*)0");
				else	cpp_payload_parameter(h,iptr);
				align_parameter(h,iptr);
				break;


			case _PROGRESS_FRAME	:
				fprintf(h,",1,1");
				items = add_interface_item(items, iptr, _SYMBOLIC_WORD );
				items = add_interface_item(items, iptr, _SYMBOLIC_WORD );
				break;

			case _SCROLL_FRAME	:
				fprintf(h,",1,1,1");
				align_parameter(h,iptr);
				items = add_interface_item(items, iptr, _SYMBOLIC_WORD );
				items = add_interface_item(items, iptr, _SYMBOLIC_WORD );
				items = add_interface_item(items, iptr, _SYMBOLIC_WORD );
				break;

			case	_EDIT_FRAME	: 
				fprintf(h,",%u,%u",iptr->Contents.style,iptr->Contents.datatype);
				align_parameter(h,iptr);
				calculate_edit_size( &iptr->Contents );
				length_parameter(h,iptr->Contents.size);
				calculate_edit_lines( iptr, &linelength, &nblines );
				fprintf(h,",%d,%d",linelength,nblines);
				items = add_interface_item(items, iptr, _SYMBOLIC_STRING );
				break;

			case _FORM_FRAME	:
				if (is_payload_unquoted(iptr))
					fprintf(h,",(char*)0");
				else	cpp_payload_parameter(h,iptr);
				if (!( is_valid_format( iptr->Contents.format ) )) 
					fprintf(h,",(char*) 0");
				else	string_parameter(h,iptr->Contents.format);
				align_parameter(h,iptr);
				fprintf(h,",%u",iptr->Contents.datatype);
				fprintf(h,",%d,%d,%d,pfieldwidth",nblines,linelength,fields);
				items = add_interface_item(items, iptr, _SYMBOLIC_STRING );
				break;
			}

		fprintf(h,");");
		linefeed(h);

		if (strlen(pbuffer)) {
			indent(h,1);
			fprintf(h,"%s",pbuffer);
			pbuffer[0]=0;
			linefeed(h);
			}

		if ( Context.Form->formflags & _MULTILINGUAL )
			cpp_national_messages(h,iptr);

		if ( iptr->Contents.events->xo_hide & _EVENT_IS_POP ) {
			indent(h,1);
			fprintf(h,"%s->SetPopUp();",cpp_item_name(iptr));
			linefeed(h);
			}
		
		if ( method_is_valid((sptr = iptr->Contents.stylesheet)) ) {
			cpp_add_visual_element( h, iptr, sptr);
			}
		if ( method_is_valid((sptr = iptr->Contents.stylefocus)) ) {
			cpp_add_visual_focus_element( h, iptr, sptr);
			}

#if USE_POINTER_METHOD
		if (method_is_valid( iptr->Contents.events->on_create )
		&&  ( iptr->Contents.events->xo_create & _EVENT_IS_FUNCTION ))
			attache_method(h,iptr,_METHOD_ONCREATE,cname,__method_create,1);
		else	attache_method_base(h,iptr,_METHOD_ONCREATE,_ON_CREATE,1);
		

		if (!( iptr->Contents.events->xo_show & _EVENT_IS_COND )) {
			if ( method_is_valid( iptr->Contents.events->on_show ) 
			&& (iptr->Contents.events->xo_show & _EVENT_IS_FUNCTION))
				attache_method(h,iptr,_METHOD_ONSHOW,cname,__method_show,1);
			else	attache_method_base(h,iptr,_METHOD_ONSHOW,_ON_SHOW,1);
			}

		if (( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS )) {
			if (method_is_valid( iptr->Contents.events->on_event )
			&&  ( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION ))
				attache_method(h,iptr,_METHOD_ONEVENT,cname,__method_event,1);
			else	attache_method_base(h,iptr,_METHOD_ONEVENT,_ON_EVENT,1);
			}


		if (( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )) {
			if ( method_is_valid( iptr->Contents.events->on_get_focus )
			&& ( iptr->Contents.events->xo_get_focus & _EVENT_IS_FUNCTION ))
				attache_method(h,iptr,_METHOD_ONFOCUS,cname,__method_getfocus,1);
			else	attache_method_base(h,iptr,_METHOD_ONFOCUS,_ON_GETFOCUS,1);
			}

		if (method_is_valid( iptr->Contents.events->on_hide )
		&&  ( iptr->Contents.events->xo_hide & _EVENT_IS_FUNCTION ))
			attache_method(h,iptr,_METHOD_ONHIDE,cname,__method_hide,1);
		else	attache_method_base(h,iptr,_METHOD_ONHIDE,_ON_HIDE,1);

		if (method_is_valid( iptr->Contents.events->on_remove )
		&&  ( iptr->Contents.events->xo_remove & _EVENT_IS_FUNCTION ))
			attache_method(h,iptr,_METHOD_ONREMOVE,cname,__method_remove,1);
		else	attache_method_base(h,iptr,_METHOD_ONREMOVE,_ON_REMOVE,1);

		if (method_is_valid( iptr->Contents.events->on_lose_focus )
		&&  ( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION ))
			attache_method(h,iptr,_METHOD_ONLOSEFOCUS,cname,__method_losefocus,1);
		else	attache_method_base(h,iptr,_METHOD_ONLOSEFOCUS,_ON_LOSEFOCUS,1);

		if  ((Context.Form->onlinehelp & 7) && (detect_widget_help(iptr))) {
			if ((iptr->Contents.style & _FRAME_TYPE ) != _RADIO_FRAME)
				attache_method(h,iptr,_METHOD_ONHELP,cname,"help",1);
			else 	attache_method_radio(h,iptr,_METHOD_ONHELP,cname,"help",1);
			}
#endif

		if (!first) first=iptr;
		linefeed(h);		
		}

	if (first) {
		indent(h,1);
		fprintf(h,"premier_fils=%s;",cpp_item_name(first));
		c_comment(h,"initialise container",1);
		indent(h,1);
		fprintf(h,"dernier_fils=%s;",cpp_item_name(nprevious));
		linefeed(h);
		}

	if (items) {
		indent(h,1);
		fprintf(h,"allocate_signature(%c%s%c);",__QUOTE,Signature,__QUOTE);
		linefeed(h);
		}

	if (( C_Config.generate_program ) 
	&& (!C_Config.generate_overlay) 
	&& (wptr != (struct form_item*) 0)) {
		indent(h,1);
		fprintf(h,"visual_set_size(%d,%d);",wptr->Contents.w,wptr->Contents.h);
		linefeed(h);
		indent(h,1);
		fprintf(h,"visual_show_window();");
		linefeed(h);
		}
	return;
}

private	void	destruct_cpp_form(FILE * h, char * cname)
{
	struct	form_item * iptr;

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		if (!method_is_valid(get_cpp_widget_class(iptr->Contents.style))) continue;
		
		if (((iptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME) 
		||  (( iptr->Contents.datatype != _WIDGET_CLASS) 
		&&   (iptr->Contents.datatype != _WIDGET_POINTER) 
		&&   (!(iptr->Contents.align & _A_BOLD)) 
		&&   (!method_is_valid(c_payload(iptr))))) {
			indent(h,1);
			fprintf(h,"delete %s;",cpp_item_name(iptr));
			linefeed(h);
			}
		}

	if (( C_Config.generate_program ) && (!C_Config.generate_overlay)) {
		indent(h,1);
		fprintf(h,"%s();",__visual_liberate);
		linefeed(h);
		}

	return;
}

private	void	generate_cpp_trigger_code( FILE * h, struct form_item * iptr, int margin )
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
		case	_BUTTON_FRAME	:
		case	_SWITCH_FRAME	:
		case	_CHECK_FRAME	:
		case	_TAB_FRAME	:
			if (!( sptr = c_payload(iptr)))
				return;
			indent(h,margin);
			fprintf(h,"%s->trigger=visual_trigger_code(",cpp_item_name(iptr));
			break;

		default			:
			return;
		}
	fprintf(h,"%s->msg[language],strlen(%s->msg[language]));",cpp_item_name(iptr),cpp_item_name(iptr));
	linefeed(h);
	return;
}

public  void	generate_cpp_thaw( FILE * h,  int margin )
{
	indent(h,margin);
	fprintf(h,"%s(x,y,w,h);",__visual_thaw);
	linefeed(h);
}

void	setpayload(FILE *h,struct form_item * iptr,int margin)
{
	char sav_lwidget[512];

	if (is_payload_unquoted(iptr)) {
		memcpy(sav_lwidget,lwidget,512);
		if (margin) indent(h,margin);
		fprintf(h,"%s->%s(",cpp_item_name(iptr),_SET_PAYLOAD);
		cpp_payload_value(h,iptr);
		fprintf(h,");");
		linefeed(h);
		memcpy(lwidget,sav_lwidget,512);
		}
	return;
}

private	void	show_cpp_form(FILE * h, char * cname)
{
	struct	form_item * iptr;
	struct form_item * wptr=(struct form_item*) 0;
	int margin;
	int pn;

	for (	iptr=Context.Form->first; 
		(iptr != (struct form_item *) 0) && (wptr == (struct form_item*) 0); 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if (( iptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME)
			wptr = iptr;
		}

	/* ------------------- */
	/* handle screen saver */
	/* ------------------- */
	if ( Context.Form->ispopup ) {
		indent(h,1);	
		fprintf(h,"ObjPopUp();");
		linefeed(h);
		}

	/* -------------------- */
	/* Ensure Screen Frozen */
	/* -------------------- */
	generate_c_freeze(h,1);
		 
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
			continue;
		if (!method_is_valid(get_cpp_widget_class(iptr->Contents.style))) continue;

		if (!(pn = open_cpp_page( h, iptr,1 )))
				margin=1;
		else	margin=2;
			
		if ( method_is_valid( iptr->Contents.events->on_show ) && ((iptr->Contents.style & _FRAME_TYPE ) != _TAB_FRAME)) {
			if ( iptr->Contents.events->xo_hide & _EVENT_IS_POP ) {
				generate_cpp_popup(h,iptr,margin);
				}
			if ( iptr->Contents.events->xo_show & _EVENT_IS_FUNCTION  )
#if USE_POINTER_METHOD
				{
				indent(h,margin);
				fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONSHOW);
				linefeed(h);
				}
#else
				activate_cpp_method(h,iptr->Contents.name,__method_show,iptr->Contents.events->on_show,0,margin);
#endif
			else	inline_cpp_method(h,iptr->Contents.name,__method_show,iptr->Contents.events->on_show,0,margin,cname,iptr);
			}
		else	{
			generate_cpp_trigger_code( h, iptr, margin );
			if ((iptr->Contents.style & _FRAME_TYPE ) == _TAB_FRAME) {
				setpayload(h,iptr,margin);
				indent(h,margin);
				fprintf(h,"%s->%s();",cpp_item_name(iptr),_ON_FOCUS_SHOW);
				linefeed(h);
				if ( method_is_valid( iptr->Contents.events->on_show )) {
					if ( iptr->Contents.events->xo_show & _EVENT_IS_FUNCTION  )
#if USE_POINTER_METHOD
						{
						indent(h,margin);
						fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONSHOW);
						linefeed(h);
						}
#else
						activate_cpp_method(h,iptr->Contents.name,__method_show,iptr->Contents.events->on_show,0,margin);
#endif
					else	inline_cpp_method(h,iptr->Contents.name,__method_show,iptr->Contents.events->on_show,0,margin,cname,iptr);
					}
				c_else(h,margin);
				indent(h,margin);
				fprintf(h,"%s->%s();",cpp_item_name(iptr),_ON_SHOW);
				}
			else 	{
				setpayload(h,iptr,margin);
				indent(h,margin);
#if USE_POINTER_METHOD
				fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONSHOW);
#else
				fprintf(h,"%s->%s();",cpp_item_name(iptr),_ON_SHOW);
#endif
				}
			linefeed(h);
			}	

		close_c_page(h,pn,1);
		}
	generate_cpp_thaw(h,1);
	return;
}

public	void	cpp_onshow_widget(FILE * h, struct form_item * iptr, int margin, int focus )
{
	char *sptr;
	int items;
	generate_cpp_trigger_code( h, iptr, margin );
	setpayload(h,iptr,margin);
	indent(h,margin);
	if (focus)
		fprintf(h,"%s->%s();",cpp_item_name(iptr),_ON_FOCUS_SHOW);
	else	fprintf(h,"%s->%s();",cpp_item_name(iptr),_ON_SHOW);
	linefeed(h);
}


private	void	cpp_widget_mouse_event(FILE * handle, struct form_item * iptr, int margin )
{
	int	fw;
	int	fh;

	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
		return;

	fw = guifontsize(iptr->Contents.font);
	fh = (fw >> 8); fw &= 0x00FF;	

	indent(handle,margin);
	fprintf(handle,"if ((%s->value = ((%s - (%s->y)) / %u)) < 1)",
		cpp_item_name(iptr),__c_mouse_row,cpp_item_name(iptr),fh);
	linefeed(handle);
	indent(handle,margin+1);
	fprintf(handle,"%s->value=0;",cpp_item_name(iptr));
	linefeed(handle);
	indent(handle,margin);
	fprintf(handle,"else if (%s->value > %s->nlig )",cpp_item_name(iptr),cpp_item_name(iptr));
	linefeed(handle);
	indent(handle,margin+1);
	fprintf(handle,"%s->value=%s->nlig;",cpp_item_name(iptr),cpp_item_name(iptr));
	linefeed(handle);
	indent(handle,margin);
	fprintf(handle,"if ( %s->value > 0 ) { %s->line(%s->value); }"
		,cpp_item_name(iptr),cpp_item_name(iptr),cpp_item_name(iptr));
	linefeed(handle);
	indent(handle,margin);
	fprintf(handle,"%s->init_column(%s - (%s->x));",cpp_item_name(iptr),__c_mouse_column,cpp_item_name(iptr));
	linefeed(handle);
	indent(handle,margin);
	fprintf(handle,"if ((!(%s->value)) && (%s==_MIMO_DOWN)) {	/* si clic sur titre */",cpp_item_name(iptr),__c_mouse_type);
	linefeed(handle);
	indent(handle,margin+1);
	fprintf(handle,"if (%s->formsort==(%s->ncol+1)) /* si colonne choisie concerne déjà le tri */",cpp_item_name(iptr),cpp_item_name(iptr));
	linefeed(handle);
	indent(handle,margin+2);
	fprintf(handle,"%s->formsort=-(%s->ncol+1);	/* alors tri décroissant */",cpp_item_name(iptr),cpp_item_name(iptr));
	linefeed(handle);
	indent(handle,margin+1);
	fprintf(handle,"else");
	linefeed(handle);
	indent(handle,margin+2);
	fprintf(handle,"%s->formsort=%s->ncol+1; }	/* sinon tri croissant */",cpp_item_name(iptr),cpp_item_name(iptr));
	linefeed(handle);
	return;
}

private	int	open_cpp_page(FILE * h,struct form_item * iptr, int i)
{
	int	pn=0;

	if ((iptr->Contents.style & _FRAME_TYPE) == _TAB_FRAME)  {
		pn = iptr->Contents.page;
		}

	else if (!( C_Config.page_control ))
		return(0);

	else if (!(pn = iptr->Contents.page ))
		return(0);

	if ( i ) indent(h,i);
	fprintf(h,"if (%s == %u ) {",__c_page_number,pn);
	linefeed(h);
	return(pn);
}

private	void	cpp_event_switch_break( FILE * h, struct form_item * iptr, int margin )
{
	indent(h,margin);
	fprintf(h,"%s=%s->focus;",__c_focus_item,cpp_item_name(iptr));
	linefeed(h);
	indent(h,margin);
	fprintf(h,"return(-1);");
	linefeed(h);
	return;
}

private	void	cpp_event_switch_continue( FILE * h, struct form_item * iptr, int margin )
{
	struct	form_control * fptr;
	indent(h,margin);
	fprintf(h,"%s=%s->focus;",__c_focus_item,cpp_item_name(iptr));
	linefeed(h);
	indent(h,margin);
	if (( fptr = iptr->parent ) != (struct form_control *) 0) {
		switch (( fptr->formflags & _FORM_TYPE_FLAGS )) {
			case	_FORM_TYPE_DIALOG	:
				fprintf(h,"return(%s->focus);",cpp_item_name(iptr));
				break;
			case	_FORM_TYPE_EVENT 	:
				fprintf(h,"return(256);");
				break;
			}
		}
	else	{
		fprintf(h,"return(%s->focus);",cpp_item_name(iptr));
		}
	linefeed(h);
	return;
}

private	void	trigger_cpp_event( 
			FILE * h, 
			struct form_item * iptr,
			int mode,
			int margin ,char *cname,int check)
{
	char	*	eptr;

	if (!( method_is_valid( iptr->Contents.events->on_event )))
		return;
	if (check) c_check_widget_event(h,iptr,margin++);
	if ( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION )
#if USE_POINTER_METHOD
		{
		indent(h,margin);
		if (mode)
			fprintf(h,"if ((%s = ",__c_keycode);
		fprintf(h,"%s->%s.Invoke()",cpp_item_name(iptr),_METHOD_ONEVENT);
		if (mode)
			fprintf(h,") != -1) break");
		fprintf(h,";");
		linefeed(h);
		}
#else
		activate_cpp_method(h,iptr->Contents.name,__method_event,iptr->Contents.events->on_event, mode ,margin);
#endif
	else	inline_cpp_method(h,iptr->Contents.name,__method_event,iptr->Contents.events->on_event, 1, margin,cname,iptr);
	
	if (check) {
		indent(h,margin);
		fprintf(h,"}");
		linefeed(h);
		}
	return;
}


public	void	cpp_event_switch_item( FILE * h, struct form_item * iptr, int mode, int margin,char *cname,int check )
{
	/* invisible things can't be clicked on */
	/* ------------------------------------ */
	if ((!( iptr->Contents.w  ))
	||  (!( iptr->Contents.h  )))
		return;

	if (!method_is_valid(get_cpp_widget_class(iptr->Contents.style))) return;

	/* Explicite Event reception inhibition flag */
	/* ----------------------------------------- */
	if (!( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ))
		return;

	/* Does not take the focus */
	/* ----------------------- */
	else if (!( iptr->Contents.focus ))
		return;

	/* Detect and generate integration with switch case */
	/* ------------------------------------------------ */
	if ( mode & 1 ) {
		c_case(h,iptr->Contents.focus,margin++);
		c_comment(h,iptr->Contents.name,margin);
		}
	else	{
		/* generate lose focus and get focus */
		/* --------------------------------- */
		margin=margin;
		}

	switch ((iptr->Contents.style&_FRAME_TYPE)) {

		case	_DATA_FRAME	:
		case	_WINDOW_FRAME	:

			if (!( iptr->Contents.events->on_event )) {
				indent(h,margin++); 
				fprintf(h,"if (%s & _MIMO_UP) {",__c_mouse_type);
				linefeed(h);
				indent(h,margin); 
				fprintf(h,"%s=27;",__c_keycode);
				linefeed(h);
				if ( mode )
					c_break(h,margin--);
				else	cpp_event_switch_break(h,iptr,margin--);
				c_else(h,margin++);
				if ( mode )
					c_continue(h,margin);
				else	cpp_event_switch_continue(h,iptr,margin);
				if (!( mode & 2 )) {
					c_endif(h,margin);
					}
				}
			else	{
				trigger_cpp_event(h,iptr,mode,margin,cname,check);
				if ( mode )
					c_continue(h,margin);
				else	cpp_event_switch_continue(h,iptr,margin);
				}
			break;

		case	_TAB_FRAME	:

			indent(h,margin++); 
			fprintf(h,"if (%s & _MIMO_DOWN) {",__c_mouse_type);
			linefeed(h);
			cpp_call(h,"\0",_ON_LOSEFOCUS, 0,margin,(char*) 0 );
			indent(h,margin);
			fprintf(h,"%s = %u;",__c_page_number,iptr->Contents.page);
			linefeed(h);
			cpp_call(h,"\0",_ON_SHOW, 0,margin,(char *) 0 );
			indent(h,margin--); fprintf(h,"}"); linefeed(h);
			trigger_cpp_event(h,iptr,mode,margin,cname,check);
			if ( mode )
				c_continue(h,margin);
			else	cpp_event_switch_continue(h,iptr,margin);
			break;

		case	_SCROLL_FRAME	:
			activate_cpp_method(h,iptr->Contents.name,__method_action,"action",0,margin);
			if ( mode )
				c_continue(h,margin);
			else	cpp_event_switch_continue(h,iptr,margin);
			break;
	
		case	_RADIO_FRAME	:
			indent(h,margin++);
			fprintf(h,"if (%s & _MIMO_UP) {",__c_mouse_type);
			linefeed(h);
			indent(h,margin);
			fprintf(h,"value_%s = %u;",iptr->Contents.name,iptr->Contents.radio);
			linefeed(h);
			cpp_call(h,"\0",_ON_SHOW, 0,margin,(char *) 0 );
			indent(h,margin--); fprintf(h,"}"); linefeed(h);
			trigger_cpp_event(h,iptr,mode,margin,cname,check);
			if ( mode )
				c_continue(h,margin);
			else	cpp_event_switch_continue(h,iptr,margin);
			break;

		case	_SWITCH_FRAME	:
		case	_CHECK_FRAME	:
			indent(h,margin++);
			fprintf(h,"if (%s & _MIMO_UP) {",__c_mouse_type);
			linefeed(h);
			indent(h,margin);
			fprintf(h,"%s->value += 1;",cpp_item_name(iptr));
			linefeed(h);
			indent(h,margin);
			fprintf(h,"%s->value &= 1;",cpp_item_name(iptr));
			linefeed(h);
			if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )) {
				switch ((iptr->Contents.style&_FRAME_TYPE)) {
					case	_SWITCH_FRAME	:
						cpp_onshow_widget(h,iptr,margin,0);
						break;
					case	_CHECK_FRAME	:
						cpp_onshow_widget(h,iptr,margin,0);
						break;
					}
				}
			indent(h,margin--); fprintf(h,"}"); linefeed(h);
			trigger_cpp_event(h,iptr,mode,margin,cname,check);
			if ( mode )
				c_continue(h,margin);
			else	cpp_event_switch_continue(h,iptr,margin);
			break;

		case	_BUTTON_FRAME	:
			indent(h,margin++);
			fprintf(h,"if (%s & _MIMO_DOWN) {",__c_mouse_type);
			linefeed(h);
			cpp_onshow_widget(h,iptr,margin,1);
			indent(h,margin--); fprintf(h,"}"); 
			linefeed(h);
			indent(h,margin++);
			fprintf(h,"else if (%s & _MIMO_UP) {",__c_mouse_type);
			linefeed(h);
			cpp_onshow_widget(h,iptr,margin,0);
			indent(h,margin--); fprintf(h,"}"); 
			linefeed(h);
			trigger_cpp_event(h,iptr,mode,margin,cname,check);
			if ( mode )
				c_continue(h,margin);
			else	cpp_event_switch_continue(h,iptr,margin);
			break;

		case	_EDIT_FRAME	:
			if ( iptr->Contents.datatype == _WIDGET_KONSTANT ) 
				return;

		case	_SELECT_FRAME	:
		default			:
			trigger_cpp_event(h,iptr,mode,margin,cname,check);
			if ( mode )
				c_continue(h,margin);
			else	cpp_event_switch_continue(h,iptr,margin);
		}
	return;
}


private	void	widget_event_cpp_response(FILE * handle, struct form_item * iptr, int margin ,char *cname)
{
	struct	form_control * fptr;

	if (!( iptr ))
		return;
	else if (!( fptr = iptr->parent ))
		return;

	switch (( fptr->formflags & _FORM_TYPE_FLAGS )) {
		case	_FORM_TYPE_DIALOG	:
			indent(handle,margin);
			fprintf(handle,"return(%s->focus);",cpp_item_name(iptr));
			linefeed(handle);
			break;
		case	_FORM_TYPE_EVENT 	:
			cpp_event_switch_item( handle, iptr, 0, margin,cname,1 );
			break;
		}
	return;
}

public	void	cpp_move_event(FILE * h, struct form_item * iptr, int margin )
{
	char	*optr;

	indent(h,margin);
	fprintf(h,"return( %s_%s() );",iptr->Contents.name,__method_action);
	linefeed(h);
}

/*	MULTILINGUAL Language Switch 	*/
/*	----------------------------	*/
public	void	cpp_lang_event(FILE * h, struct form_item * iptr, int margin )
{
	struct form_control * fptr;

	indent(h,margin);
	fprintf(h,"if (%s ==_MIMO_LEFT) {",__c_mouse_button);
	linefeed(h);
	indent(h,(margin+1));	
	fprintf(h,"language++; language %c=%u;",0x0025,MAXNATLANG);
	linefeed(h);
	indent(h,(margin+1));	fprintf(h,"}");		linefeed(h);	
	indent(h,margin);	fprintf(h,"else {");	linefeed(h);
	indent(h,margin);	
	fprintf(h,"if ( language > 0 ) { language--; language %c=%u; }",0x0025,MAXNATLANG);
	linefeed(h);
	indent(h,margin);	
	fprintf(h,"else { language=7; }");
	linefeed(h);
	indent(h,(margin+1));	fprintf(h,"}");		linefeed(h);	
	indent(h,margin);
	fprintf(h,"(void) %s(language);",__visual_natlang);
	linefeed(h);
	cpp_call(h,"\0",_ON_SHOW, 0,2,(char *) 0 );
	return;
}

private	void	dynamic_widget_cpp_event(FILE * handle, struct form_item * iptr, int margin )
{
	indent(handle,margin);
	fprintf(handle,"if ((mx >= %s->x ) ",cpp_item_name(iptr));
	linefeed(handle);
	indent(handle,margin);
	fprintf(handle,"&&  (my >= %s->y ) ",cpp_item_name(iptr));
	linefeed(handle);
	indent(handle,margin);
	fprintf(handle,"&&  (mx <  (%s->x+%s->w)) ",cpp_item_name(iptr),cpp_item_name(iptr));
	linefeed(handle);
	indent(handle,margin);
	fprintf(handle,"&&  (my <  (%s->y+%s->h))) {",cpp_item_name(iptr),cpp_item_name(iptr));
	linefeed(handle);
	return;
}

private	void	generate_cpp_event(FILE * handle, struct form_item * iptr ,char *cname)
{
	int		margin;
	char	*	tptr;
	int		pn;
	int		fh;
	int		fw;
	int		f;
	int		hwx;
	int		wx;
	int		wy;
	int		v=0;
	struct	form_control * fptr;

	if (((fptr = iptr->parent) != (struct form_control*) 0)
	&&   ( fptr->formflags & _MULTILINGUAL))
		v = 1;

	switch ((iptr->Contents.style&_FRAME_TYPE)) {

		case	_WINDOW_FRAME	:
			if ((!( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ))
			&&  (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )))
				break;

			if (!( f = iptr->Contents.font ))
				break;
			else	{
				fh = guifontsize(f);
				fw = (fh & 0x00FF);
				fh >>= 8;
				fh &= 0x00FF;
				}

			if (( iptr->Contents.align & (_A_BOLD | _A_LINE) ) || ( v ) || ( iptr->Contents.special )) {
				indent(handle,1);
				fprintf(handle,"switch (mt) {");
				linefeed(handle);
				indent(handle,1);
				fprintf(handle,"case _MIMO_UP :");
				linefeed(handle);
				}

			if ( iptr->Contents.align & _A_BOLD ) {
#if GESTION_FIXED
				if (!( FixedWindows )) {
#endif
					indent(handle,1);
					fprintf(handle,"if ((mx >= (%s->x+%s->w-%u) )  ",cpp_item_name(iptr),cpp_item_name(iptr),fh+5);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my >= (%s->y+%u) )  ",cpp_item_name(iptr),4);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (mx <= (%s->x+%s->w-4) )  ",cpp_item_name(iptr),cpp_item_name(iptr));
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my <= (%s->y+%u) )) {",cpp_item_name(iptr),(fh+4));
					linefeed(handle);
					indent(handle,2); 
#if GESTION_FIXED
					}
				else	{
					wx = ((iptr->Contents.x+iptr->Contents.w)-(fh+5));
					wy = (iptr->Contents.y+4);
					indent(handle,1);
					fprintf(handle,"if ((mx >= %u )  ",wx+WindowCol);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my >= %u )  ",wy+WindowRow);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (mx <= %u )  ",wx+WindowCol+fh);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my <= %u )) {",wy+WindowRow+fh);
					linefeed(handle);
					indent(handle,2); 
					}
#endif
				fprintf(handle,"return(%s->focus);",cpp_item_name(iptr));

				linefeed(handle);
				indent(handle,2);
				fprintf(handle,"}");
				linefeed(handle);

				}

			if ( iptr->Contents.align & _A_LINE ) {

#if GESTION_FIXED
				if (!( FixedWindows )) {
#endif
					indent(handle,1);
					fprintf(handle,"if ((mx >= (%s->x+%s->w-%u) )  ",cpp_item_name(iptr),cpp_item_name(iptr),(fh*2)+5);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my >= (%s->y+%u) )  ",cpp_item_name(iptr),4);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (mx <= (%s->x+%s->w-%u) )  ",cpp_item_name(iptr),cpp_item_name(iptr),fh+4);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my <= (%s->y+%u) )) {",cpp_item_name(iptr),(fh+4));
					linefeed(handle);
					indent(handle,2); 
#if GESTION_FIXED
					}
				else	{
					hwx = ((iptr->Contents.x+iptr->Contents.w)-((fh*2)+5));
					wy = (iptr->Contents.y+4);
					indent(handle,1);
					fprintf(handle,"if ((mx >= %u )  ",hwx+WindowCol);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my >= %u )  ",wy+WindowRow);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (mx <= %u )  ",hwx+WindowCol+fh);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my <= %u )) {",wy+WindowRow+fh);
					linefeed(handle);
					}
#endif

				generate_c_help(handle,iptr,2);
				indent(handle,2); 
				fprintf(handle,"return(-1);");
				linefeed(handle);
				indent(handle,2);
				fprintf(handle,"}");
				linefeed(handle);
				}

			if ( v ) {
#if GESTION_FIXED
				if (!( FixedWindows )) {
#endif
					indent(handle,1);
					fprintf(handle,"if ((mx >= (%s->x+%s->w-%u) )  ",cpp_item_name(iptr),cpp_item_name(iptr),(fh*3)+5);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my >= (%s->y+%u) )  ",cpp_item_name(iptr),4);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (mx <= (%s->x+%s->w-%u) )  ",cpp_item_name(iptr),cpp_item_name(iptr),(fh*2)+4);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my <= (%s->y+%u) )) {",cpp_item_name(iptr),(fh+4));
					linefeed(handle);
					indent(handle,2); 
#if GESTION_FIXED
					}
				else	{
					hwx = ((iptr->Contents.x+iptr->Contents.w)-((fh*3)+5));
					wy = (iptr->Contents.y+4);
					indent(handle,1);
					fprintf(handle,"if ((mx >= %u )  ",hwx+WindowCol);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my >= %u )  ",wy+WindowRow);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (mx <= %u )  ",hwx+WindowCol+fh);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my <= %u )) {",wy+WindowRow+fh);
					linefeed(handle);
					}
#endif
				cpp_lang_event(handle,iptr,2);
				indent(handle,2); 
				fprintf(handle,"return(-1);",iptr->Contents.focus);
				c_comment(handle,iptr->Contents.name,1);
				linefeed(handle);
				indent(handle,2);
				fprintf(handle,"}");
				linefeed(handle);
				}

			if ( iptr->Contents.special ) {
				indent(handle,1);
				fprintf(handle,"case _MIMO_DOWN :");
				linefeed(handle);
				indent(handle,2);
				fprintf(handle,"if ((mx >= (%s->x+%u) )  ",cpp_item_name(iptr),4);
				linefeed(handle);
				indent(handle,2);
				fprintf(handle,"&&  (my >= (%s->y+%u) )  ",cpp_item_name(iptr),4);
				linefeed(handle);
				indent(handle,2);
				fprintf(handle,"&&  (mx <= (%s->x+%s->w-%u) )  ",cpp_item_name(iptr),cpp_item_name(iptr),(fh*4)+4);
				linefeed(handle);
				indent(handle,2);
				fprintf(handle,"&&  (my <= (%s->y+%u) )) {",cpp_item_name(iptr),(fh+4));
				linefeed(handle);
				cpp_move_event(handle,iptr,3);
				indent(handle,3);
				fprintf(handle,"}");
				linefeed(handle);
				}

			if (( iptr->Contents.align & (_A_BOLD | _A_LINE) ) || ( v ) || ( iptr->Contents.special )) {
				indent(handle,2);
				fprintf(handle,"}");
				linefeed(handle);
				}
			break;
	
		case	_SELECT_FRAME	:

			if ((!( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ))
			&&  (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )))
				break;

			if (!(pn = open_cpp_page( handle, iptr,1 )))
				margin=1;
			else	margin=2;

			if ( iptr->Contents.events->xo_create & _EVENT_IS_FOCUS ) {
				dynamic_widget_cpp_event(handle,iptr,margin);
				}
#if GESTION_FIXED
			else if ( FixedWindows ) {
				indent(handle,margin);
				fprintf(handle,"if ((mx >= %u ) ",iptr->Contents.x+WindowCol+iptr->Contents.adjust);
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  (my >= %u ) ",iptr->Contents.y+WindowRow);	
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  (mx <= %u ) ",(iptr->Contents.x+WindowCol+iptr->Contents.xlimit+iptr->Contents.adjust));
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  (my <= %u )) {",(iptr->Contents.y+WindowRow+iptr->Contents.ylimit));
				linefeed(handle);
				}
#endif
			else	{
				indent(handle,margin);
				fprintf(handle,"if (( mx >= (%s->x+%u) ) ",cpp_item_name(iptr),iptr->Contents.adjust);
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( my >= (%s->y) ) ",cpp_item_name(iptr));
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( mx <= (%s->x+%u) ) ",cpp_item_name(iptr),iptr->Contents.xlimit+iptr->Contents.adjust);
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( my <= (%s->y+%u))) {",cpp_item_name(iptr),iptr->Contents.ylimit);
				linefeed(handle);
				}
			widget_event_cpp_response(handle,iptr,margin+1,cname);
			indent(handle,margin+1);
			fprintf(handle,"}");
			linefeed(handle);
			close_c_page(handle,pn,1);
			break;

		case	_TAB_FRAME	:
			if ((!( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ))
			&&  (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )))
				break;
			if (!(pn = open_cpp_page( handle, iptr,1 )))
				margin=1;
			else	{
				c_else(handle,1);
				margin=2;
				}
			if ( iptr->Contents.events->xo_create & _EVENT_IS_FOCUS ) {
				dynamic_widget_cpp_event(handle,iptr,margin);
				}
#if GESTION_FIXED
			else if ( FixedWindows ) {
				indent(handle,margin);
				fprintf(handle,"if ((mx >= %u ) ",(iptr->Contents.x+WindowCol+iptr->Contents.adjust));
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  (my >= %u ) ",iptr->Contents.y+WindowRow);
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  (mx <= %u ) ",(iptr->Contents.x+WindowCol+iptr->Contents.adjust+iptr->Contents.xlimit));
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  (my <= %u )) {",(iptr->Contents.y+WindowRow+iptr->Contents.ylimit));
				linefeed(handle);
				}
#endif
			else	{
				indent(handle,margin);
				fprintf(handle,"if (( mx >= (%s->x+%u) ) ",cpp_item_name(iptr),iptr->Contents.adjust);
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( my >= (%s->y) ) ",cpp_item_name(iptr));
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( mx <= (%s->x+%u) ) ",cpp_item_name(iptr),iptr->Contents.xlimit+iptr->Contents.adjust);
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( my <= (%s->y+%u))) {",cpp_item_name(iptr),iptr->Contents.ylimit);
				linefeed(handle);
				}
			widget_event_cpp_response(handle,iptr,margin+1,cname);
			indent(handle,margin+1);
			fprintf(handle,"}");
			linefeed(handle);
			close_c_page(handle,pn,1);
			break;

		case	_TEXT_FRAME	:
			break;

		case	_EDIT_FRAME	:
		case	_FORM_FRAME	:

			if ( iptr->Contents.datatype == _WIDGET_KONSTANT ) 
				break;

		case	_SCROLL_FRAME	:
		case	_PROGRESS_FRAME	:
		case	_BUTTON_FRAME	:
		case	_SWITCH_FRAME	:
		case	_GRAPH_FRAME	:
		case	_CHECK_FRAME	:
		case	_RADIO_FRAME	:
		default			:
			if ((!( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ))
			&&  (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )))
				break;
			if (!(pn = open_cpp_page( handle, iptr,1 )))
				margin=1;
			else	margin=2;

			if ( iptr->Contents.events->xo_create & _EVENT_IS_FOCUS ) {
				dynamic_widget_cpp_event(handle,iptr,margin);
				}
#if GESTION_FIXED
			else if ( FixedWindows ) {
				indent(handle,margin);
				fprintf(handle,"if (( mx >= %u ) ",iptr->Contents.x+WindowCol);
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( my >= %u ) ",iptr->Contents.y+WindowRow);
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( mx <= %u ) ",(iptr->Contents.x+WindowCol+iptr->Contents.w));
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( my <= %u )) {",(iptr->Contents.y+WindowRow+iptr->Contents.h));
				linefeed(handle);
				}
#endif
			else	{
				indent(handle,margin);
				fprintf(handle,"if (( mx >= (%s->x) ) ",cpp_item_name(iptr));
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( my >= (%s->y) ) ",cpp_item_name(iptr));
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( mx <= (%s->x+%s->w) ) ",cpp_item_name(iptr),cpp_item_name(iptr));
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( my <= (%s->y+%s->h))) {",cpp_item_name(iptr),cpp_item_name(iptr));
				linefeed(handle);
				}
			cpp_widget_mouse_event(handle,iptr,(margin+1));
			widget_event_cpp_response(handle,iptr,margin+1,cname);
			indent(handle,margin+1);
			fprintf(handle,"}");
			linefeed(handle);
			close_c_page(handle,pn,1);
		}
	return;
}

private	void	cpp_hint_method(FILE * h, struct form_item * iptr, int margin )
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
	else if (!( method_is_valid((sptr = c_hint(iptr) )) ))
		return;
	else	{
		indent(h,margin);
		fprintf(h,"%s(",_METHOD_CPP_ONHINT);
		c_hint_value(h,iptr );
		fprintf(h,");");
		linefeed(h);
		return;
		}
}


private	void	generate_cpp_onhelp_switch( FILE * h )
{
	struct	form_item * iptr;
	int	margin=3;
	indent(h,margin++); 
	fprintf(h,"if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {");
	linefeed(h);
		indent(h,margin++);
#if USE_POINTER_METHOD
		fprintf(h,"if (form_help(retcode) !=0) continue;");
#else
		fprintf(h,"switch ((%s = retcode)) {",__c_focus_item);
		linefeed(h);
		for (	iptr=Context.Form->first;  
			iptr != (struct form_item *) 0; 
			iptr = iptr->next )  {
			if (!( detect_widget_help( iptr ) ))
				continue;
			else if (!( iptr->Contents.focus ))
				continue;
			else	{
				c_case(h,iptr->Contents.focus,margin++);
				indent(h,margin);
				fprintf(h,"if (");
#if USE_POINTER_METHOD
				fprintf(h,"%s->%s.Invoke()",cpp_item_name(iptr),_METHOD_ONHELP);
#else
				if ((iptr->Contents.style & _FRAME_TYPE ) != _RADIO_FRAME)
						fprintf(h,"%s_help()",iptr->Contents.name);
				else	fprintf(h,"%s%u_help()",iptr->Contents.name,iptr->Contents.radio);
#endif
				fprintf(h," != 0) { continue; }");
				linefeed(h);
				indent(h,margin--);
				fprintf(h,"else { break; }");
				linefeed(h);
				}
			}
		indent(h,margin--);
		fprintf(h,"}");
#endif
	linefeed(h);
	indent(h,margin--);
	fprintf(h,"}");
	linefeed(h);
	return;
}


private	void	generate_cpp_event_switch( FILE * h,char *cname)
{
	struct	form_item * iptr;

	/* avoid pollution of current state if no widget selected */
	/* ------------------------------------------------------ */

	indent(h,3); fprintf(h,"if ((retcode=OnEvent()) == -1)");
	linefeed(h); c_continue(h,4);

	if ( Context.Form->onlinehelp & 16 ) {
		generate_cpp_onhelp_switch( h );
		}

	/* Determine Widget Selected by Event */
	/* ---------------------------------- */
	indent(h,3); fprintf(h,"switch ((%s = retcode)) {",__c_focus_item);
	linefeed(h);

	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {

		cpp_event_switch_item( h, iptr, 1, 4 ,cname,1);

		}

	c_case(h,-1,4);
	c_default(h,4);
		indent(h,5);
		fprintf(h,"%s=1;",__c_focus_item);
		linefeed(h);
		c_continue(h,4);
	indent(h,4);
	fprintf(h,"}");
	linefeed(h);
	return;
}

public  void	generate_cpp_event_flush( FILE * h )
{
	linefeed(h);
	indent(h,1);
	fprintf(h,"while( %s ) (void) %s();",__c_test_event,C_Config.input_method);
	linefeed(h);
}

private	int	cpp_test_page( FILE * h,struct form_item * iptr, int margin )
{
	int	pn=0;
	if ((pn = iptr->Contents.page) != 0) {
		indent(h,margin);
		fprintf(h,"if (%s == %u) {",__c_page_number,iptr->Contents.page);
		linefeed(h);
		}
	return(pn);
}

private	void	cpp_button_widget(
			FILE * handle, 
			struct form_item * iptr, 
			int margin,
			int etat )
{
	indent(handle,margin);


	etat |= (iptr->Contents.align & 0x0F00);
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
	fprintf(handle,"%s->etat=%u;",cpp_item_name(iptr),etat);
	linefeed(handle);
	setpayload(handle,iptr,margin);
	indent(handle,margin);
	fprintf(handle,"%s->%s();",cpp_item_name(iptr),_ON_SHOW);
	linefeed(handle);

	return;
}

private	void	cpp_widget_pagetrigger( FILE * h,	struct form_item * iptr, int margin,char *cname )
{
	int	pn=0;

	switch ((iptr->Contents.style&_FRAME_TYPE)) {

		case	_TAB_FRAME	:

			c_comment(h,iptr->Contents.name,margin);
			indent(h,margin);
			cpp_call(h,"\0",_ON_LOSEFOCUS, 0,margin,(char*) 0 );
			indent(h,margin);
			fprintf(h,"%s = %u;",__c_page_number,iptr->Contents.page);
			linefeed(h);
			cpp_call(h,"\0",_ON_SHOW, 0,margin,(char *) 0 );
			break;

		case	_RADIO_FRAME	:
			if ((pn = cpp_test_page(h,iptr,margin)) != 0)
				margin++;
			c_comment(h,iptr->Contents.name,margin);
			indent(h,margin);
			fprintf(h,"value_%s = %u;",iptr->Contents.name,iptr->Contents.radio);
			linefeed(h);
			cpp_call(h,"\0",_ON_SHOW, 0,margin,(char *) 0 );
			break;

		case	_SWITCH_FRAME	:
		case	_CHECK_FRAME	:
			if ((pn = cpp_test_page(h,iptr,margin)) != 0)
				margin++;
			c_comment(h,iptr->Contents.name,margin);
			indent(h,margin);
			fprintf(h,"%s->value += 1;",cpp_item_name(iptr));
			linefeed(h);
			indent(h,margin);
			fprintf(h,"%s->value &= 1;",cpp_item_name(iptr));
			linefeed(h);
			break;

		case	_BUTTON_FRAME	:
			if ((pn = cpp_test_page(h,iptr,margin)) != 0)
				margin++;
			c_comment(h,iptr->Contents.name,margin);
			cpp_button_widget(h,iptr,margin,8);
			cpp_button_widget(h,iptr,margin,0);
			break;
		}

	indent(h,margin);
	fprintf(h,"%s=%u;",__c_focus_item,iptr->Contents.focus);
	linefeed(h);
	if ( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION )
#if USE_POINTER_METHOD
		{
		indent(h,margin);
		fprintf(h,"if ((%s = %s->%s.Invoke()) != -1) break;",__c_keycode,cpp_item_name(iptr),_METHOD_ONEVENT);
		linefeed(h);
		}
#else
		activate_cpp_method(h,iptr->Contents.name,__method_event,iptr->Contents.events->on_event,1,margin);
#endif
	else	inline_cpp_method(h,iptr->Contents.name,__method_event,iptr->Contents.events->on_event,1,margin,cname,iptr);
	c_continue(h,margin);
	if ( pn ) {
		indent(h,margin--);
		fprintf(h,"}");
		linefeed(h);
		}
	return;
}

private	void	cpp_widget_formtrigger( FILE * h,	struct form_item * iptr, int margin, char *cname )
{
	switch ((iptr->Contents.style&_FRAME_TYPE)) {

		case	_TAB_FRAME	:

			c_case_hotkey(h,_MIMO_ALT|iptr->Contents.trigger,margin++);
			c_comment(h,iptr->Contents.name,margin);

			indent(h,margin);
			cpp_call(h,"\0",_ON_LOSEFOCUS, 0,margin,(char*) 0 );
			indent(h,margin);
			fprintf(h,"%s = %u;",__c_page_number,iptr->Contents.page);
			linefeed(h);
			cpp_call(h,"\0",_ON_SHOW, 0,margin,(char *) 0 );
			break;

		case	_RADIO_FRAME	:
			c_case_hotkey(h,_MIMO_ALT|iptr->Contents.trigger,margin++);
			c_comment(h,iptr->Contents.name,margin);
			indent(h,margin);
			fprintf(h,"value_%s = %u;",iptr->Contents.name,iptr->Contents.radio);
			linefeed(h);
			cpp_call(h,"\0",_ON_SHOW, 0,margin,(char *) 0 );
			break;

		case	_SWITCH_FRAME	:
		case	_CHECK_FRAME	:
			c_case_hotkey(h,_MIMO_ALT|iptr->Contents.trigger,margin++);
			c_comment(h,iptr->Contents.name,margin);
			indent(h,margin);
			fprintf(h,"%s->value += 1;",cpp_item_name(iptr));
			linefeed(h);
			indent(h,margin);
			fprintf(h,"%s->value &= 1;",cpp_item_name(iptr));
			linefeed(h);
			break;

		case	_BUTTON_FRAME	:
			c_case_hotkey(h,_MIMO_ALT|iptr->Contents.trigger,margin++);
			c_comment(h,iptr->Contents.name,margin);
			cpp_button_widget(h,iptr,margin,8);
			cpp_button_widget(h,iptr,margin,0);
			break;

		}
	indent(h,margin);
	fprintf(h,"%s=%u;",__c_focus_item,iptr->Contents.focus);
	linefeed(h);
	if ( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION )
#if USE_POINTER_METHOD
		{
		indent(h,margin);
		fprintf(h,"if ((%s = %s->%s.Invoke()) != -1) break;",__c_keycode,cpp_item_name(iptr),_METHOD_ONEVENT);
		linefeed(h);
		}
#else
		activate_cpp_method(h,iptr->Contents.name,__method_event,iptr->Contents.events->on_event,1,margin);
#endif
	else	inline_cpp_method(h,iptr->Contents.name,__method_event,iptr->Contents.events->on_event,1,margin,cname,iptr);
	c_continue(h,margin);
	return;
}


private	void	generate_cpp_hotkey_switch( FILE * h, int margin,char *cname )
{
	struct form_item * iptr;
	int		triggermap[256];
	int		triggers=0;
	int		i;
	int		c;

	/* not required when multilingual */
	/* ------------------------------ */
	if ( Context.Form->formflags & _MULTILINGUAL )
		return;

	else if ( Context.Form->pages ) {

		/* Triggers generated by Tab Page Collection */
		/* ----------------------------------------- */
		for (	iptr=Context.Form->first;  
			iptr != (struct form_item *) 0; 
			iptr = iptr->next )  {

			if ((!( iptr->Contents.w  ))
			||  (!( iptr->Contents.h  )))
				continue;
			if (!method_is_valid(get_cpp_widget_class(iptr->Contents.style))) continue;

			if (!( widget_can_trigger( &iptr->Contents ) ))
				continue;
			else if (!( iptr->Contents.trigger ))
				continue;
			for (i=0; i < triggers; i++ )
				if ( compare_hotkeys( iptr->Contents.trigger, triggermap[i] ) )
					break;
			if ( i< triggers )
				continue;
			else	triggermap[triggers++] = (iptr->Contents.trigger | _MIMO_ALT);
			}

		for ( i=0; i < triggers; i++ ) {
			c = (triggermap[i] & 0x00FF);
			if ((c  >= 'a')
			&&  (c  <= 'z')) {
				indent(h,margin);
				fprintf(h,"case 0x8%x : ",c);
				linefeed(h);
				indent(h,margin);
				fprintf(h,"case 0x8%x : ",(c-('a'-'A')));
				linefeed(h);
				}

			else if ((c >= 'A')
			     &&  (c <= 'Z')) {
				indent(h,margin);
				fprintf(h,"case 0x8%x : ",(c+('a'-'A')));
				linefeed(h);
				indent(h,margin);
				fprintf(h,"case 0x8%x : ",c);
				linefeed(h);
				}
			else	{
				indent(h,margin);
				fprintf(h,"case 0x8%x : ",c);
				linefeed(h);
				}

			for (	iptr=Context.Form->first;  
				iptr != (struct form_item *) 0; 
				iptr = iptr->next )  {

				if ((!( iptr->Contents.w  ))
				||  (!( iptr->Contents.h  )))
					continue;
				if (!method_is_valid(get_cpp_widget_class(iptr->Contents.style))) continue;
				if (!( widget_can_trigger( &iptr->Contents ) ))
					continue;

				else if (!( iptr->Contents.trigger ))
					continue;

				else if (!( compare_hotkeys( iptr->Contents.trigger, triggermap[i] )))
					continue;

				else	cpp_widget_pagetrigger(h,iptr,margin+1,cname);

				}
			c_continue(h,margin+1);
			}

		}
	else	{

		for (	iptr=Context.Form->first;  
			iptr != (struct form_item *) 0; 
			iptr = iptr->next )  {

			/* invisible things can't be clicked on */
			/* ------------------------------------ */
			if ((!( iptr->Contents.w  ))
			||  (!( iptr->Contents.h  )))
				continue;
			if (!method_is_valid(get_cpp_widget_class(iptr->Contents.style))) continue;

			/* Explicite Event reception inhibition flag */
			/* ----------------------------------------- */
			if (!( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ))
				continue;
			else if (!( iptr->Contents.focus ))
				continue;
			else if (!( iptr->Contents.trigger  ))
				continue;
			else	cpp_widget_formtrigger(h,iptr,margin,cname);
			}
		}
	return;
}

private	void	generate_cpp_focus(FILE * h, struct form_item * iptr , char *cname)
{
	char	*	tptr;
	int		pn=0;
	int	margin=0;

	if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS ))
		return;

	switch ((iptr->Contents.style&_FRAME_TYPE)) {

		case	_DATA_FRAME	:

			if (( iptr->Contents.align & 0x000F ) == _VISUAL_FRAME) {
				switch ( iptr->Contents.datatype ) {

					case	_WIDGET_MODULE	:
					case	_WIDGET_OVERLAY	:

						c_case(h,iptr->Contents.focus,margin=3);
						c_comment(h,iptr->Contents.name,++margin);
						if ((pn = open_cpp_page(h,iptr,margin)) != 0)
							margin++;

						if ( method_is_valid( iptr->Contents.events->on_get_focus ) ) {
							if ( iptr->Contents.events->xo_get_focus & _EVENT_IS_FUNCTION )
#if USE_POINTER_METHOD
								{
								indent(h,margin);
								fprintf(h,"if ((%s = %s->%s.Invoke()) != -1) break;",__c_keycode,cpp_item_name(iptr),_METHOD_ONFOCUS);
								linefeed(h);
								}
#else
								activate_cpp_method(h,iptr->Contents.name,__method_getfocus,iptr->Contents.events->on_get_focus,1,margin);
#endif
								else	inline_cpp_method  (h,iptr->Contents.name,__method_getfocus,iptr->Contents.events->on_get_focus,0,margin,cname,iptr);
							}
						else	{
							indent(h,margin);
#if USE_POINTER_METHOD

							fprintf(h,"%s = %s->%s.Invoke();",__c_keycode,cpp_item_name(iptr),_METHOD_ONFOCUS);
#else
							fprintf(h,"%s = %s->%s();",__c_keycode,cpp_item_name(iptr),_ON_GETFOCUS);
#endif
							linefeed(h);
							}

#if !USE_POINTER_METHOD
						indent(h,margin);
						fprintf(h,"%s->OnLoseFocus();",cpp_item_name(iptr));
						linefeed(h);
#endif
						if ( method_is_valid( iptr->Contents.events->on_lose_focus ) ) {
							if ( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION )
#if USE_POINTER_METHOD
								{
								indent(h,margin);
								fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONLOSEFOCUS);
								linefeed(h);
								}
#else
								activate_cpp_method(h,iptr->Contents.name,__method_losefocus,iptr->Contents.events->on_lose_focus,0,margin);
#endif
							else 	{
#if USE_POINTER_METHOD
								indent(h,margin);
								fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONLOSEFOCUS);
								linefeed(h);
#else
								indent(h,margin);
								fprintf(h,"%s->OnLoseFocus();",cpp_item_name(iptr));
								linefeed(h);
#endif
								inline_cpp_method  (h,iptr->Contents.name,__method_losefocus,iptr->Contents.events->on_lose_focus,0,margin,cname,iptr);
								}
							}
#if USE_POINTER_METHOD
						else
							{
							indent(h,margin);
							fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONLOSEFOCUS);
							linefeed(h);
							}
#endif

					if ( pn ) {
						c_else( h, margin-1 );
						indent(h,margin);
						fprintf(h,"%s = 5;",__c_keycode);
						linefeed(h);
						}
					close_c_page(h,pn,--margin);
					c_break(h,margin);
					}
				}
			break;

		case	_FORM_FRAME	:
		case	_EDIT_FRAME	:

			if ( iptr->Contents.datatype == _WIDGET_KONSTANT ) 
				break;
			else	{
				c_case(h,iptr->Contents.focus,margin=3);
				c_comment(h,iptr->Contents.name,++margin);

				if ((pn = open_cpp_page(h,iptr,margin)) != 0)
					margin++;

				cpp_hint_method( h, iptr, margin );

				if ( method_is_valid( iptr->Contents.events->on_get_focus ) ) {
					if ( iptr->Contents.events->xo_get_focus & _EVENT_IS_FUNCTION )
#if USE_POINTER_METHOD
						{
						indent(h,margin);
						switch ((iptr->Contents.style&_FRAME_TYPE))
							{
							case	_EDIT_FRAME	:
								fprintf(h,"if ((%s = %s->%s.Invoke()) != -1) break;",__c_keycode,cpp_item_name(iptr),_METHOD_ONFOCUS);
								break;
							case	_FORM_FRAME	:
								fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONFOCUS);
								break;
							}
						linefeed(h);
						}
#else
						activate_cpp_method(h,iptr->Contents.name,__method_getfocus,iptr->Contents.events->on_get_focus,1,margin);
#endif
					else	inline_cpp_method  (h,iptr->Contents.name,__method_getfocus,iptr->Contents.events->on_get_focus,0,margin,cname,iptr);
					}
				else	{
					if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )) {
						indent(h,margin);
						fprintf(h,"%s = 5;",__c_keycode);
						linefeed(h);
						} 
					else	{
						indent(h,margin);
#if USE_POINTER_METHOD
						fprintf(h,"%s = %s->%s.Invoke();",__c_keycode,cpp_item_name(iptr),_METHOD_ONFOCUS);
#else
						fprintf(h,"%s = %s->%s();",__c_keycode,cpp_item_name(iptr),_ON_GETFOCUS);
#endif
						linefeed(h);
						}
					}

#if !USE_POINTER_METHOD
				indent(h,margin);
				fprintf(h,"%s->OnLoseFocus();",cpp_item_name(iptr));
				linefeed(h);
#endif
				if ( method_is_valid( iptr->Contents.events->on_lose_focus ) ) {
					if ( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION )
#if USE_POINTER_METHOD
						{
						indent(h,margin);
						fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONLOSEFOCUS);
						linefeed(h);
						}
#else
						activate_cpp_method(h,iptr->Contents.name,__method_losefocus,iptr->Contents.events->on_lose_focus,0,margin);
#endif
					else	{
#if USE_POINTER_METHOD
						indent(h,margin);
						fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONLOSEFOCUS);
						linefeed(h);
#else
						indent(h,margin);
						fprintf(h,"%s->OnLoseFocus();",cpp_item_name(iptr));
						linefeed(h);
#endif
						inline_cpp_method  (h,iptr->Contents.name,__method_losefocus,iptr->Contents.events->on_lose_focus,0,margin,cname,iptr);
						}
					}
#if USE_POINTER_METHOD
				else	{
					indent(h,margin);
					fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONLOSEFOCUS);
					linefeed(h);
					}
#endif

				if ( pn ) {
					c_else( h,(margin-1) );
					indent(h,margin);
					fprintf(h,"%s = 5;",__c_keycode);
					linefeed(h);
					}
				close_c_page(h,pn,--margin);
				c_break(h,margin);
				}
			break;

		case	_IMAGE_FRAME	:
		case	_SELECT_FRAME	:
		case	_BUTTON_FRAME	:
		case	_SWITCH_FRAME	:
		case	_GRAPH_FRAME	:
		case	_CHECK_FRAME	:
		case	_RADIO_FRAME	:
		case	_SCROLL_FRAME	:
		case	_WINDOW_FRAME	:
		case	_TAB_FRAME	:
			c_case(h,iptr->Contents.focus,(margin=3));
			c_comment(h,iptr->Contents.name,++margin);
			if (( pn = open_cpp_page(h,iptr,margin ))!=0)
					margin++;

			cpp_hint_method( h, iptr, margin );

			if ( method_is_valid( iptr->Contents.events->on_get_focus ) ) {
				if ( iptr->Contents.events->xo_get_focus & _EVENT_IS_FUNCTION )
#if USE_POINTER_METHOD
					{
					indent(h,margin);
					fprintf(h,"if ((%s = %s->%s.Invoke()) != -1) break;",__c_keycode,cpp_item_name(iptr),_METHOD_ONFOCUS);
					linefeed(h);
					}
#else
					activate_cpp_method(h,iptr->Contents.name,__method_getfocus,iptr->Contents.events->on_get_focus,1,margin);
#endif
				else	inline_cpp_method  (h,iptr->Contents.name,__method_getfocus,iptr->Contents.events->on_get_focus,0,margin,cname,iptr);
				}
			else	{
				if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )) {
						indent(h,margin);
						fprintf(h,"%s = 5;",__c_keycode);
						linefeed(h);
					} 
				else	{
					indent(h,margin);
#if USE_POINTER_METHOD
					fprintf(h,"%s = %s->%s.Invoke();",__c_keycode,cpp_item_name(iptr),_METHOD_ONFOCUS);
#else
					fprintf(h,"%s = %s->%s();",__c_keycode,cpp_item_name(iptr),_ON_GETFOCUS);
#endif
					linefeed(h);
					}
				}

#if !USE_POINTER_METHOD
			indent(h,margin);
			fprintf(h,"%s->OnLoseFocus();",cpp_item_name(iptr));
			linefeed(h);
#endif
			if ( method_is_valid( iptr->Contents.events->on_lose_focus ) ) {
				if ( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION )
#if USE_POINTER_METHOD
					{
					indent(h,margin);
					fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONLOSEFOCUS);
					linefeed(h);
					}
#else
					activate_cpp_method(h,iptr->Contents.name,__method_losefocus,iptr->Contents.events->on_lose_focus,0,margin);
#endif
				else	{
#if USE_POINTER_METHOD
					indent(h,margin);
					fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONLOSEFOCUS);
					linefeed(h);
#else
					indent(h,margin);
					fprintf(h,"%s->OnLoseFocus();",cpp_item_name(iptr));
					linefeed(h);
#endif
					inline_cpp_method  (h,iptr->Contents.name,__method_losefocus,iptr->Contents.events->on_lose_focus,0,margin,cname,iptr);
					}
				}
#if USE_POINTER_METHOD
			else	{
				indent(h,margin);
				fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONLOSEFOCUS);
				linefeed(h);
				}
#endif
			if ( pn ) {
				c_else( h, margin-1 );
				indent(h,margin);
				fprintf(h,"%s = 5;",__c_keycode);
				linefeed(h);
				}
			close_c_page(h,pn,--margin);

			c_break(h,margin);
			break;

		}

	return;

}

void 	onfocus_cpp_form(FILE *h, char * cname)
{
	struct form_item * iptr;

	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (!method_is_valid(get_cpp_widget_class(iptr->Contents.style))) continue;
		if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS ))
			continue;
		else	generate_cpp_focus(h,iptr,cname);
		}
	return;
}

void 	lose_cpp_form(FILE *h, char * cname)
{
	struct form_item * iptr;

	if (!( Context.Form->pages))
		return;

	linefeed(h);
	indent(h,1);	fprintf(h,"switch (%s) {",__c_page_number);
	linefeed(h);

	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
	
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (!method_is_valid(get_cpp_widget_class(iptr->Contents.style))) continue;
		if ((iptr->Contents.style & _FRAME_TYPE) != _TAB_FRAME)
			continue;
		indent(h,2);
		fprintf(h,"case %u : ",iptr->Contents.page);
		linefeed(h); 

#if !USE_POINTER_METHOD
		indent(h,3);
		fprintf(h,"%s->OnLoseFocus();",cpp_item_name(iptr));
		linefeed(h);
#endif
		if ( method_is_valid( iptr->Contents.events->on_lose_focus ) ) {
			if ( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION )
#if USE_POINTER_METHOD
				{
				indent(h,3);
				fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONLOSEFOCUS);
				linefeed(h);
				}
#else
				activate_cpp_method(h,iptr->Contents.name,__method_losefocus,iptr->Contents.events->on_lose_focus,0,3);
#endif
			else	{
#if USE_POINTER_METHOD
				indent(h,3);
				fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONLOSEFOCUS);
				linefeed(h);
#else
				indent(h,3);
				fprintf(h,"%s->OnLoseFocus();",cpp_item_name(iptr));
				linefeed(h);
#endif
				inline_cpp_method  (h,iptr->Contents.name,__method_losefocus,iptr->Contents.events->on_lose_focus,0,3,cname,iptr);
				}
			}
#if USE_POINTER_METHOD
		else	{
			indent(h,3);
			fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONLOSEFOCUS);
			linefeed(h);
			}
#endif
		indent(h,3);
		fprintf(h,"break;");
		linefeed(h); 
		}
	indent(h,1);
	fprintf(h,"}");
	linefeed(h);
	return;
}

void event_cpp_form(FILE *h,char *cname)
{
	struct form_item * iptr;

	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (!method_is_valid(get_cpp_widget_class(iptr->Contents.style))) 
			continue;
		if (((iptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME) 
		||  (( iptr->Contents.datatype != _WIDGET_CLASS)
		&&   (iptr->Contents.datatype != _WIDGET_POINTER))
		||  (!method_is_valid(c_payload(iptr)))) {
			generate_cpp_event(h,iptr,cname);
			}
		}
}


public	int	cpp_hide_visual_widget(FILE * h, struct form_item * iptr, int margin )
{
	/* this will handle the visual.overlay type widget */
	/* ----------------------------------------------- */
	if (( iptr->Contents.align & 0x000F ) == _VISUAL_FRAME) {
		switch ( iptr->Contents.datatype ) {
			case	_WIDGET_MODULE	:
			case	_WIDGET_OVERLAY	:
				indent(h,margin);
				fprintf(h,"%s->hide();",c_payload(iptr));
				linefeed(h);
				break;
			default			:
				return(0);
			}
		return( 1 );
		}
	else	{	
		return(0);
		}
}

private	void	hide_cpp_form(FILE * h, char * cname)
{
	struct	form_item * iptr;
	struct form_item * wptr=(struct form_item*) 0;

	/* -------------------------------------- */
	/* Activate these in reverse order please */
	/* -------------------------------------- */
	for (	wptr=(struct form_item*) 0, 
		iptr=Context.Form->last;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->previous )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		if (!method_is_valid(get_cpp_widget_class(iptr->Contents.style))) continue;
		
		if (((iptr->Contents.style & _FRAME_TYPE ) == _DATA_FRAME)
		&&  (( iptr->Contents.datatype == _WIDGET_CLASS) 
		||   (iptr->Contents.datatype == _WIDGET_POINTER) 
		||   (!method_is_valid(c_payload(iptr))) 
		||   ((iptr->Contents.align & _A_BOLD)))) 
			continue;
		
		if (( iptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME)
			wptr = iptr;

		if ( method_is_valid( iptr->Contents.events->on_hide ) ) {
			if ( iptr->Contents.events->xo_hide & _EVENT_IS_POP )
				generate_cpp_popdown(h,iptr,1);

			if ( iptr->Contents.events->xo_hide & _EVENT_IS_FUNCTION )
#if USE_POINTER_METHOD
				{
				indent(h,1);
				fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONHIDE);
				linefeed(h);
				}
#else
				activate_cpp_method(h,iptr->Contents.name,__method_hide,iptr->Contents.events->on_hide,0,1);
#endif
			else	inline_cpp_method(h,iptr->Contents.name,__method_hide,iptr->Contents.events->on_hide,0,1,cname,iptr);
			}
		else	{

//	--------------------------------------------------------------------------
// 	GGBI AVOIR TODO
//	--------------------------------------------------------------------------
//			if (( iptr->Contents.style & _FRAME_TYPE) == _DATA_FRAME) {
//				cpp_hide_visual_widget(h,iptr,1);
//				}
//	--------------------------------------------------------------------------

#if USE_POINTER_METHOD
			indent(h,1);
			fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONHIDE);
			linefeed(h);
#else
			indent(h,1);
			fprintf(h,"%s->%s();",cpp_item_name(iptr),_ON_HIDE);
			linefeed(h);
#endif
			}

		}

	/* ------------------- */
	/* handle screen saver */
	/* ------------------- */
	if ( Context.Form->ispopup ) {
		indent(h,1);	
		fprintf(h,"ObjPopDown();");
		linefeed(h);
		}

	linefeed(h);
	return;
}


private	void	remove_cpp_form(FILE * h, char * cname)
{
	struct	form_item * iptr;
	struct form_item * wptr=(struct form_item*) 0;


	/* -------------------------------------- */
	/* Activate these in reverse order please */
	/* -------------------------------------- */
	for (	wptr=(struct form_item*) 0, 
		iptr=Context.Form->last;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->previous )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		if (!method_is_valid(get_cpp_widget_class(iptr->Contents.style))) continue;

		if ((iptr->Contents.style & _FRAME_TYPE ) == _DATA_FRAME) {
			if ((( iptr->Contents.datatype == _WIDGET_CLASS) 
			||   (iptr->Contents.datatype == _WIDGET_POINTER)) 
			&&  (method_is_valid(c_payload(iptr)))) 
				continue;
			if (((iptr->Contents.align & 0x000F) == _VISUAL_FRAME) 
			&&  (( iptr->Contents.datatype == _WIDGET_MODULE) 
			||   (iptr->Contents.datatype == _WIDGET_OVERLAY)) 
			&&  (method_is_valid(c_payload(iptr))) 
			&&  ((iptr->Contents.align & _A_BOLD))) 
				continue;
			}

		if (( iptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME)
			wptr = iptr;

		if ( method_is_valid( iptr->Contents.events->on_remove ) ) {
			if ( iptr->Contents.events->xo_remove & _EVENT_IS_FUNCTION  )
#if USE_POINTER_METHOD
				{
				indent(h,1);
				fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONREMOVE);
				linefeed(h);
				}
#else
				activate_cpp_method(h,iptr->Contents.name,__method_remove,iptr->Contents.events->on_remove,0,1);
#endif
			else	{
				inline_cpp_method(h,iptr->Contents.name,__method_remove,iptr->Contents.events->on_remove,0,1,cname,iptr);
#if USE_POINTER_METHOD
				indent(h,1);
				fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONREMOVE);
				linefeed(h);
#endif
				}
			}

#if USE_POINTER_METHOD
		else	{
			indent(h,1);
			fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONREMOVE);
			linefeed(h);
			}
#else
		indent(h,1);
		fprintf(h,"%s->%s();",cpp_item_name(iptr),_ON_REMOVE);
		linefeed(h);
#endif

//	--------------------------------------------------------------------------
// 	GGBI AVOIR TODO
//	--------------------------------------------------------------------------
//		switch ( iptr->Contents.style & _FRAME_TYPE ) {		
//			case	_DATA_FRAME	:
//				if ((iptr->Contents.align & 0x000F) == _VISUAL_FRAME) {
//					switch ( iptr->Contents.datatype ) {
//						case	_WIDGET_MODULE	:
//						case	_WIDGET_OVERLAY	:
//							indent(h,1);
//							fprintf(h,"status = %s->remove(%s);",c_payload(iptr),iptr->Contents.name);
//							linefeed(h);
//							indent(h,1);
//							fprintf(h,"%s = (struct %s_context*) 0;",iptr->Contents.name,c_payload(iptr));
//							linefeed(h);
//							break;
//						}
//					}
//			}
//	--------------------------------------------------------------------------
		
		}
	/* ------------------- */
	/* handle screen saver */
	/* ------------------- */
	if ( Context.Form->ispopup ) {
		indent(h,1);	
		fprintf(h,"DropSaver();");
		linefeed(h);
		}
	return;
}


private	void	cpp_banner(FILE * h, char * token )
{
	int	tokenlen;
	int	i;
	if (!( token ))
		return;
	else if (!( tokenlen =strlen( token ) ))
		return;
	else	tokenlen *= 2;

	linefeed(h);
	fprintf(h,"/*\t");
	for (i=0; i < tokenlen; i++ )
		fprintf(h,"-");
	fprintf(h,"\t*/");

	linefeed(h);
	fprintf(h,"/*\t");
	while ( *token )
		fprintf(h,"%c ",*(token++));

	fprintf(h,"\t*/");

	linefeed(h);
	fprintf(h,"/*\t");
	for (i=0; i < tokenlen; i++ )
		fprintf(h,"-");
	fprintf(h,"\t*/");
	linefeed(h);
	return;
}

private	void	void_cpp_method(FILE * h, char * cname, char * fname )
{
	if ( fname != (char *) 0)
		cpp_banner(h,fname);

	linefeed(h);
	fprintf(h,"void %s::",cname);
	if (!( fname ))
		fprintf(h,"~%s()",cname);
	else	fprintf(h,"%s()",fname);
	linefeed(h);
	fprintf(h,"{");
	return;
}

private	void	void_cpp_emethod(FILE * h)
{
	linefeed(h);
	indent(h,1);
	fprintf(h,"return;");
	linefeed(h);
	fprintf(h,"}");
	linefeed(h);
	return;
}

private	void	int_cpp_emethod(FILE * h)
{
	linefeed(h);
	indent(h,1);
	fprintf(h,"return(0);");
	linefeed(h);
	fprintf(h,"}");
	linefeed(h);
	return;
}

private	void	int_cpp_method(FILE * h, char * cname, char * fname )
{
	if ( fname != (char *) 0)
		cpp_banner(h,fname);

	linefeed(h);
	fprintf(h,"int  %s::",cname);
	if (!( fname ))
		fprintf(h,"~%s()",cname);
	else	fprintf(h,"%s()",fname);
	linefeed(h);
	fprintf(h,"}");
	return;
}

private	void	events_cpp(FILE * h, char * cname)
{
	struct	form_item * iptr;
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (!method_is_valid(get_cpp_widget_class(iptr->Contents.style))) continue;
		}


	return;
}

private	void	construction_cpp(FILE * h, char * cname)
{
	struct	form_item * iptr;
	void_cpp_method(h,cname,cname);
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		}

	void_cpp_emethod(h);
	return;
}

private	void	destruction_cpp(FILE * h, char * cname)
{
	struct	form_item * iptr;
	void_cpp_method(h,cname,(char *) 0);
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		}
	void_cpp_emethod(h);
	return;
}

private	void	on_show_cpp(FILE * h, char * cname)
{
	struct	form_item * iptr;
	void_cpp_method(h,cname,"on_show");
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		}
	void_cpp_emethod(h);
	return;
}

private	void	on_hide_cpp(FILE * h, char * cname)
{
	struct	form_item * iptr;
	void_cpp_method(h,cname,"on_hide_focus");
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		}
	void_cpp_emethod(h);
	return;
}

private	void	on_get_cpp(FILE * h, char * cname)
{
	struct	form_item * iptr;
	void_cpp_method(h,cname,"on_get_focus");
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		}
	void_cpp_emethod(h);
	return;
}

private	void	on_lose_cpp(FILE * h, char * cname)
{
	struct	form_item * iptr;
	void_cpp_method(h,cname,"on_lose_focus");
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		}
	void_cpp_emethod(h);
	return;
}

private	void	on_event_cpp(FILE * h, char * cname)
{
	struct	form_item * iptr;
	int_cpp_method(h,cname,"on_event");
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		}
	int_cpp_emethod(h);
	return;
}

public	void	export_cpp_menu( FILE * h )
{
	return;
}

private	void	generate_cpp_onstart(FILE * h, int mode)
{
	int		i;
	char	*	fname;
	struct	form_control * fptr;
	indent(h,1);

	if (!( mode )) {
		if ((( fptr = Context.Form) != (struct form_control*) 0)
		&&  ( fptr->abal.flags & 256 ))
			fprintf(h,"if ( %s(%u|512) == -1 )",__visual_initialise,TargetBiosMode);
		else	fprintf(h,"if ( %s(%u|256) == -1 )",__visual_initialise,TargetBiosMode);
		}
	else	{
		fprintf(h,"if ( %s(%u|mode) == -1 )",__visual_initialise,TargetBiosMode);
		}

	linefeed(h); c_return(h,"56",2); linefeed(h);
	indent(h,1);
	fprintf(h,"else\t{");
	linefeed(h);
	indent(h,2);
	if (method_is_valid( Context.Form->palette ) ) {
		fprintf(h,"%s(",__visual_palette);
		quoted_string(h,Context.Form->palette);
		fprintf(h,",%u);",strlen( Context.Form->palette ));
		}
	else	{
		fprintf(h,"%s(",__visual_palette);
		quoted_filename(h,SingConf->palette);
		fprintf(h,",%u);",strlen(SingConf->palette));
		}
	linefeed(h);
	indent(h,2);
	fprintf(h,"cicopalette(0,0);");
	linefeed(h);
	indent(h,2);
	fprintf(h,"initialise_mouse();");
	linefeed(h);
	indent(h,2);
	fprintf(h,"}");
	linefeed(h);
	return;
}

static	void	cpp_initialise_national_language(FILE * h, struct form_control * fptr, int mode)
{
	if ( fptr->formflags & _MULTILINGUAL ) {
		if (( C_Config.generate_program )
		&&  ( mode )) {
			if (!( C_Config.generate_overlay )) {
				indent(h,1);
				fprintf(h,"language=%u;",fptr->natlang);
				linefeed(h);
				indent(h,1);
				fprintf(h,"(void) %s(language);",
					__visual_natlang);
				linefeed(h);
				}
			else	{
				indent(h,1);
				fprintf(h,"language = %s(-1);",
					__visual_natlang);
				linefeed(h);
				}
			}
		else	{
			indent(h,1);
			fprintf(h,"language = %s(-1);",
				__visual_natlang);
			linefeed(h);
			}
		}
	return;
}

public	int	cpp_include_line( FILE * sh, FILE * th, char * bptr, int  blen,	struct form_item * iptr ,char *cname)
{
	int	i=0;
	int	c;
	int	status=0;
	int	feeder=0;
	while ( i < blen ) {

		if ((c = fgetc(sh)) <= 0)	break;
		else if ( c == '\r' )		continue;
		else if ( c == '\n' ) {
			if (!( i ))	continue;
			else 		break;
			}
		else 	{
			if ( c == '\t' )	c = ' ';
			if ( c != ' ' )		*(bptr+i)=c;
			else if (!( i ))	continue;
			else			*(bptr+i)=c;
			i++;
			}
		}
	if (!( i ))
		return(48);
	else	{
		*(bptr+i) = 0;
		indent(th,1);
		status = cpp_method_line(th, bptr, i, LineParser.thisname, &feeder,cname,iptr );
		linefeed(th);
		return(status);
		}
}

public	int	cpp_include_source( FILE * h, char * tptr,struct form_item * iptr ,char *cname )
{
	FILE *	sh;
	char *	bptr;
	int	failure=0;
	int	i;
	if (!( tptr ))	
		return((failure=30));
	else if (!( h    ))  
		return((failure=30));
	else if (!( bptr = allocate( 2048 )))
		return((failure=27));
	else if (!( push_line_parser() )) {
		liberate( bptr );
		return((failure=27));
		}
	else 	{
		if ( *tptr == '"' ) {
			tptr++;
			for (i=0; *(tptr+i) != 0; i++ ) {
				if ( *(tptr+i) == '"' ) {
					*(tptr+i) = 0;
					break;
					}
				}
			}
		while (!(sh = fopen(tptr,"r")))  {
			if ( file_not_found( tptr ) == 27 ) {
				LineParser.status = 40;
				break;
				}
			}

		if ( sh != (FILE *) 0) {
			while (!(failure = cpp_include_line(sh,h,bptr,2040,iptr,cname)));
			if ( failure == 48 ) failure = 0;
			fclose(sh);
			}	
		liberate( bptr );
		return( pop_line_parser() );
		}
}

/* appel des fonctions du container */
public  void	cpp_call( FILE * h, char * cname, char * fname, int members, int level, char * genret )
{
	indent(h,level);

	if ( genret )
		fprintf(h,"%s = ",genret);

	if (!( *fname ))
		fprintf(h,"%s(",cname);
	else	{
		if (method_is_valid(cname))
			fprintf(h,"%s%s(",cname,fname);
		else	fprintf(h,"%s(",fname);
		}
//	----------------------------------------------------
//	 si on veut surcharger les classes remplacer par 
//		fprintf(h,"(%spere)->%s(",cname,fname);
//	----------------------------------------------------

	if ( members != 0 )
		c_member_parameters(h,1);

	fprintf(h,");");
	linefeed(h);
	return;
}

/* ici on est dans thisform.Onshow() par exemple */
private	char *	cpp_method_statement( FILE * h, char * tptr,struct form_item *iptr,char *cname )
{
	int	c;
	int	token;
	struct forms_method *	mptr;
	struct form_control * fptr;
	struct forms_method *	is_forms_Method( char *,struct form_control *);

	if (!( iptr ))
		return((char *) 0);
	else if (!( fptr = iptr->parent ))
		return((char *) 0);

	if ( string_compare( tptr, keyword_include ) ) {
		if (!( tptr = c_get_token(0) )) {
			c_syntax_error( keyword_include,1 );
			return((char *) 0);
			}
		else	{
			cpp_include_source(h,tptr,iptr,cname);		
			return((char *) 0);
			}
		}

	else if ((mptr = is_forms_Method( tptr,fptr )) != (struct forms_method *) 0 ) {
		if (!(c = c_get_punctuation() ))
			return( tptr );
		else if (c != '(' )
			return( tptr );
		else	{
			fprintf(h,"%s(",tptr);
			return((char *) 0);
			}

		}
	else	{
		switch ( is_visual_member( tptr, 1 ) ) {
			case	VISUAL_MEMBER_X	:
				fprintf(h,"x");
				return((char *) 0);
			case	VISUAL_MEMBER_Y	:
				fprintf(h,"y");
				return((char *) 0);
			case	VISUAL_MEMBER_W	:
				fprintf(h,"w");
				return((char *) 0);
			case	VISUAL_MEMBER_H	:
				fprintf(h,"h");
				return((char *) 0);
			case	VISUAL_MEMBER_FONT	:
				fprintf(h,"font");
				return((char *) 0);
			case	VISUAL_MEMBER_FG	:
				fprintf(h,"fg");
				return((char *) 0);
			case	VISUAL_MEMBER_BG	:
				fprintf(h,"bg");
				return((char *) 0);
			case	VISUAL_MEMBER_FOCUS	:
				fprintf(h,"focus");
				return((char *) 0);

			case	VISUAL_MEMBER_ONHIDE	:
				if (!( remove_brackets() ))
					break;
				else	{

					cpp_call(h,lwidget, _ON_HIDE, 0,1,(char *) 0 );
					return((char *) 0);
					}

			case	VISUAL_MEMBER_ONSHOW	:
				if (!( remove_brackets() ))
					break;
				else	{
					cpp_call(h,lwidget,_ON_SHOW, 0,1,(char *) 0 );
					return((char *) 0);
					}
			case	VISUAL_MEMBER_ONFOCUS	:
				if (!( remove_brackets() ))
					break;
				else	{
					cpp_call(h,lwidget,_ON_GETFOCUS, 0,1,(char *) 0 );
					return((char *) 0);
					}
			}
		return( tptr );
		}
}



private	char *	cpp_column_variable(FILE * h, struct form_item * iptr )
{
int c;

	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
		return((char *) 0);
	else if (!( iptr->Contents.name ))
		return((char *) 0);
	else	{
		fprintf(h,"%sncol",lwidget);
		return((char *) 0);
		}
}

private	char *	cpp_line_variable(FILE * h, struct form_item * iptr )
{
	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
		return((char *) 0);
	else if (!( iptr->Contents.name ))
		return((char *) 0);
	else	{
		fprintf(h,"%svalue",lwidget);
		return((char *) 0);
		}
}

private	char *	cpp_member_column(FILE * h, struct form_item * iptr )
{
	int	c;
	char * tptr;
	if (!(c = c_get_punctuation() ))
		return( cpp_column_variable(h,iptr) );
	else if (c == '(' ) {
		if (!( tptr = c_get_token(0) ))
			return( tptr );
		else if (!(c = c_get_punctuation() ))
			return( (char *) 0 );
		else if (c != ')' )
			return( (char *) 0 );
		else 	{ 
			fprintf(h,"%scolumn(%s)",lwidget,tptr);
			return((char *) 0);
			}
		}
	else 	{
		parser_ungetch();
		return( cpp_column_variable(h,iptr) );
		}
}

private	char *	cpp_member_line(FILE * h, struct form_item * iptr )
{
	int	c;
	char * tptr;
	if (!(c = c_get_punctuation() ))
		return( cpp_line_variable(h,iptr) );
	else if (c == '(' ) {
		if (!( tptr = c_get_token(0) ))
			return( tptr );
		else if (!(c = c_get_punctuation() ))
			return( (char *) 0 );
		else if (c != ')' )
			return( (char *) 0 );
		else 	{ 
			fprintf(h,"%sline(%s)",lwidget,tptr);
			return((char *) 0);
			}
		}
	else 	{
		parser_ungetch();
		return( cpp_line_variable(h,iptr) );
		}
}

private	char *	cpp_member_linesort(FILE * h, struct form_item * iptr )
{
	int	c;
	char * tptr;
	if (!(c = c_get_punctuation() ))
		return( (char *)0 );
	else if (c == '(' ) {
		if (!( tptr = c_get_token(0) ))
			return( tptr );
		else if (!(c = c_get_punctuation() ))
			return( (char *) 0 );
		else if (c != ')' )
			return( (char *) 0 );
		else 	{ 
			fprintf(h,"%slinesort(%s);",lwidget,tptr);
			return((char *) 0);
			}
		}
	else 	{
		parser_ungetch();
		return( (char *)0 );
		}
}

private	char *	cpp_macro_columnsize( FILE * h, struct form_item * iptr, char * tptr )
{
	int	linesize=1;
	int	linecount=1;
	int	fields;
	int	offset=0;
	int	field=0;
	int	f=0;
	int	fieldwidth[_MAX_FORM_FIELDS];
	char *	sptr;


	if (!( tptr )) {
		c_syntax_error( iptr->Contents.name,3 );
		return((char *) 0);
		}
	else if (!( sptr = c_payload(iptr) )) {
		c_syntax_error( iptr->Contents.name,4 );
		return((char *) 0);
		}
	else if ( *sptr == _UNQUOTED_STRING ) {
		c_syntax_error( iptr->Contents.name,5 );
		return((char *) 0);
		}
	else  {
		field = 0;
		while ( *tptr ) {
			if (( *tptr >= '0' ) && ( *tptr <= '9'))
				field = ((field * 10) + (*(tptr++) - '0'));
			else	break;
			}
		if ((iptr->Contents.style & _FRAME_TYPE) == _FORM_FRAME )
			fprintf(h,"%sfieldwidth[%u]",lwidget,field-1);
		else	fprintf(h,"%stlig",lwidget,field-1);
		return((char *) 0);
		}
}

private	void	generate_cpp_trigger( FILE * h, struct form_item * iptr, int margin )
{
	struct	form_item * xptr;

	c_comment(h,iptr->Contents.name,margin);
	if ((iptr->Contents.style&_FRAME_TYPE) != _TAB_FRAME) {
		if ( iptr->Contents.page ) {
			for (	xptr=Context.Form->first;
				xptr != (struct form_item *) 0;
				xptr = xptr->next ) {
				if ((xptr->Contents.style&_FRAME_TYPE) != _TAB_FRAME)
					continue;
 				else if ( iptr->Contents.page != xptr->Contents.page )
					continue;
				else	{
					generate_cpp_trigger(h,xptr,margin);
					break;
					}
				}
			}
		}
	else	{
		cpp_call(h,"\0", _ON_LOSEFOCUS, 0,margin,(char *) 0 );
		indent(h,margin);
		fprintf(h,"page_number = %u;",iptr->Contents.page);
		linefeed(h);
		}

	cpp_call(h,"\0", _ON_SHOW, 0,margin,(char *) 0 );
	indent(h,margin);
	fprintf(h,"focus_item = %s->focus;",cpp_item_name(iptr));
	linefeed(h);
	return;
}

public	void	cpp_widget_viewport(FILE * h, struct form_item * iptr )
{
	switch ((iptr->Contents.style & _FRAME_TYPE)) {

		case	_EDIT_FRAME	:

//	-----------------------------------------------------------------------
//	si on veut surcharger les classes remplacer par
//	-----------------------------------------------------------------------
//		fprintf(h,"(%spere)->%s=%s(%sx+1,%sy+1,%sw,%sh,vfh[%sfont]);",
//				lwidget,"status",__visual_viewport,
//				lwidget,
//				lwidget,
//				lwidget,
//				lwidget,
//				lwidget);
//	-----------------------------------------------------------------------
		fprintf(h,"%s=%s(%sx+1,%sy+1,%sw,%sh,vfh[%sfont]);",
				"status",__visual_viewport,
				lwidget,
				lwidget,
				lwidget,
				lwidget,
				lwidget);
			break;

		case	_OUTSET_FRAME	:
		case	_INSET_FRAME	:
			fprintf(h,"%s=%s(%sx+1,%sy+1,%sw-2,%sh-2,vfh[%sfont]);",
				"status",__visual_viewport,
				lwidget,
				lwidget,
				lwidget,
				lwidget,
				lwidget);
			fprintf(h,")");

			break;

		case	_RIDGE_FRAME	:
		case	_GROOVE_FRAME	:
			fprintf(h,"%s=%s(%sx+2,%sy+2,%sw-4,%sh-4,vfh[%sfont]);",
				"status",__visual_viewport,
				lwidget,
				lwidget,
				lwidget,
				lwidget,
				lwidget);
			break;

		default			:
			fprintf(h,"%s=%s(%sx,%sy,%sw,%sh,vfh[%sfont]);",
				"status",__visual_viewport,
				lwidget,
				lwidget,
				lwidget,
				lwidget,
				lwidget);

		}
	return;
}

private	char *	cpp_macro_reset( FILE * h, struct form_item * iptr )
{
	if ( iptr->Contents.events->xo_create & _EVENT_IS_FOCUS ) {
		/* Generate Position and Dimensions Variables */
		fprintf(h,"%sx=%s;",lwidget,widget_x_position(iptr,1));
		fprintf(h,"%sy=%s;",lwidget,widget_y_position(iptr,1));
		fprintf(h,"%sw=%s;",lwidget,widget_w_dimension(iptr,1));
		fprintf(h,"%sh=%s;",lwidget,widget_h_dimension(iptr,1));
		}
	return((char*)0);
}

private	char *	cpp_widget_overlay_method( FILE * h, struct form_item * iptr, char * tptr )	/* GWB le 16/04/2007 avant private */
{
	int	c=0;
	struct	forms_method * mptr;
	struct	form_control * fptr;
	char *	sptr;

	if (( sptr = c_payload( iptr )) &&  (fptr = locate_form_control(sptr))) {
		for (	mptr=fptr->rootmethod;
			mptr != (struct forms_method *) 0;
			mptr = mptr->next ) {
			if (!( mptr->name ))
				continue;
			else if (!( mptr->type & _METHOD_PUBLIC ))
				continue;
			else if (!( mptr->type & _METHOD_FUNCTION ))
				continue;
			if (!( upper_compare( tptr, mptr->name )))
				continue;
			else if ((c = c_get_punctuation()) !=  '(')
				break;
			else	{
				fprintf(h,"%s->%s(",cpp_item_name(iptr),mptr->name);
				return((char *)0);
				break;
				}
			}
		}

	fprintf(h,"%s->%s",cpp_item_name(iptr),tptr);
	if (c) fprintf(h,"%c",c);
	return((char *) 0);
}

private	char *	cpp_convert_token( FILE * h, char * tptr,char *cname,	struct form_item * pptr)
{
	int	nbc=0;
	int	nbr=0;
	int	linesize=1;
	int	linecount=1;
	int	i;
	int	c;
	char * xtptr;
	char *underscore;

	struct form_item * iptr=pptr;

	if (method_is_valid(tptr)>9) {
		if (!strncmp(tptr,"SysFontMem",10))	/* GGBI pour debug avec break */
		c=1;
		}

	if (( LineParser.thisname )
	&&  ( string_compare( tptr, keyword_this ) ))
		tptr = LineParser.thisname;

	else if ( upper_compare( tptr, keyword_exit ) ) {
		if ( not_white_space() != '(' )
			return( tptr );
		else	{
			fprintf(h,"return");
			return((char *) 0);
			}
		}
	else if ( upper_compare( tptr, keyword_keycode ) ) {
		fprintf(h,"keycode");
		return((char *) 0);
		}
	else if ( upper_compare( tptr, keyword_focusitem ) ) {
		fprintf(h,"focus_item");
		return((char *) 0);
		}
	else if ( upper_compare( tptr, keyword_thisform ) ) {
		if ((c = parser_getch()) != '.' ) {
			parser_ungetch();
			fprintf(h,"this");
			return( (char *)0 );
			}
		else if (!( xtptr = c_get_token(1) )) {
			return( xtptr );
			}

		lwidget[0]=0;
		return( cpp_method_statement( h, xtptr,pptr,cname ) );
		}


	if (upper_compare(tptr,"pere")) {
		if ((c = parser_getch()) != '.' ) {
			parser_ungetch();
			return(tptr);
			}
		strcpy(lwidget,"pere->");
		iptr=NULL;
		}
	else	{
		if (string_compare( tptr, "_Context" )) {
			if (parser_getch() != '-' ) {
				parser_ungetch();
				return( tptr );
				} 
			if (parser_getch() != '>' ) {
				parser_ungetch();
				parser_ungetch();
				return( tptr );
				}
			return((char *)0);
			}
		else 	{
			if ((!( iptr = locate_widget( tptr,Context.Form ))) 
			&&  (!(string_compare( tptr, LineParser.thisname )))) {
				if ((underscore=strchr(tptr,'_')) != (char *)0) {
					if (iptr=locate_widget(underscore+1,Context.Form)) {
						if ((c=parser_getch())=='(') {
							parser_ungetch();
							return(tptr);
							}
						else	{
							if (c) parser_ungetch();
							c=*underscore;
							*underscore=0;
							fprintf(h,"%s->%s",cpp_item_name(iptr),tptr);
							*underscore=c;
							return((char *)0);
							}
						}
					}
				lwidget[0]=0;
				return( cpp_method_statement( h, tptr,pptr,cname ) );
				}
			else if ((c = parser_getch()) != '.' ) {
				parser_ungetch();
				/* GGBI, soit on reconnait un widget et on */
				/* le nomme soit on renvoie le libellé 	   */
				if (iptr)
					fprintf(h,"%s",cpp_item_name(iptr));
				else	fprintf(h,"%s",tptr);
				return((char *)0);
				}
			}
	
		if (!iptr) {
			sprintf(lwidget,"%s",LineParser.thisname);
			iptr=pptr;
			}
		else	{
			sprintf(lwidget,"%s->",cpp_item_name(iptr));
			}

		}

	if (!( tptr = c_get_token(0) )) {
		fprintf(h,"%s",lwidget);
		return( tptr );
		}

	i = is_visual_member( tptr, 1 );

	switch ( i ) {
		case	VISUAL_MEMBER_X	:
			fprintf(h,"%sx",lwidget);
			return((char *) 0);
		case	VISUAL_MEMBER_Y	:
			fprintf(h,"%sy",lwidget);
			return((char *) 0);
		case	VISUAL_MEMBER_W	:
			fprintf(h,"%sw",lwidget);
			return((char *) 0);
		case	VISUAL_MEMBER_H	:
			fprintf(h,"%sh",lwidget);
			return((char *) 0);
		case	VISUAL_MEMBER_FONT	:
			fprintf(h,"%sfontclass",lwidget);
			return((char *) 0);
		case	VISUAL_MEMBER_FONTWIDTH	:
			if (iptr)
				fprintf(h,"%u", Context.FontTable[iptr->Contents.font].width );
			else	fprintf(h,"0");
			return((char *) 0);
		case	VISUAL_MEMBER_FONTHEIGHT :
			if (iptr)
				fprintf(h,"%u", Context.FontTable[iptr->Contents.font].height );
			else	fprintf(h,"0");
			return((char *) 0);
		case	VISUAL_MEMBER_FG	:
			fprintf(h,"%ufg",lwidget);
			return((char *) 0);
		case	VISUAL_MEMBER_BG	:
			fprintf(h,"%ubg",lwidget);
			return((char *) 0);
		case	VISUAL_MEMBER_FOCUS	:
			fprintf(h,"%sfocus",lwidget);
			return((char *) 0);

		case	VISUAL_MEMBER_VALUE	:
			if (iptr) {
				switch ((iptr->Contents.style & _FRAME_TYPE)) {
					case	_RADIO_FRAME	:
						fprintf(h,"value_%s",iptr->Contents.name);
						break;

					case	_CHECK_FRAME	:
					case	_SELECT_FRAME	:
					case	_SWITCH_FRAME	:
					case	_GRAPH_FRAME	:
					case	_SCROLL_FRAME	:
					case	_PROGRESS_FRAME	:
						fprintf(h,"%svalue",lwidget);
						break;
					case	_FORM_FRAME	:
					case	_EDIT_FRAME	:
						fprintf(h,"Conv(%sbuffer)",lwidget);
						break;
					default			:
						c_syntax_error(tptr,11);
						break;
					}
				}
			else	c_syntax_error(tptr,11);
			return((char *) 0);

		case	VISUAL_MEMBER_HINT	:
			fprintf(h,"%shint[(%spere)->language]",lwidget,lwidget);
			return((char *) 0);

		case	VISUAL_MEMBER_PAYLOAD	:
			fprintf(h,"%spayload",lwidget);
			return((char *) 0);
		case	VISUAL_MEMBER_BUFFER	:
			fprintf(h,"%sbuffer",lwidget);
			return((char *) 0);
		case	VISUAL_MEMBER_LIMIT	:
			fprintf(h,"%slimit",lwidget);
			return((char *) 0);

		case	VISUAL_MEMBER_MAX	:
			fprintf(h,"%smax",lwidget);
			return((char *) 0);

		case	VISUAL_MEMBER_SIZE	:
			if ((iptr) && ((iptr->Contents.style & _FRAME_TYPE) == _FORM_FRAME))
				fprintf(h,"%snlig*%stlig",lwidget,lwidget);
			else fprintf(h,"%stbuff",lwidget);
			return((char *) 0);

		case	VISUAL_MEMBER_COLUMN	:
			if (iptr)
				return( cpp_member_column(h, iptr ) );
			else	c_syntax_error(tptr,11);
			break;

		case	VISUAL_MEMBER_LINE  	:
			if (iptr)
				return( cpp_member_line(h, iptr ) );
			else	c_syntax_error(tptr,11);
			break;

		case	VISUAL_MEMBER_COLUMNSIZE	:
			if (!( tptr = c_dimension() ))
				break;
			if (!iptr) break;
			else	{
				return( cpp_macro_columnsize( h, iptr, tptr ) );
				}

		case	VISUAL_MEMBER_POSITION :
			if (!( tptr = c_dimension() ))
				break;
			if (!iptr) break;
			else	{
				return( c_macro_position( h, iptr, tptr ) );
				}

		case	VISUAL_MEMBER_COLUMNS	:
			if (!iptr) break;
			return( c_macro_columns( h, iptr ) );

		case	VISUAL_MEMBER_LINES	:
			fprintf(h,"%snlig",lwidget);

			return((char *) 0);

		case	VISUAL_MEMBER_LINESIZE	:
			fprintf(h,"%stlig",lwidget);

			return((char *) 0);

		case	VISUAL_MEMBER_FORMSORT	:
			fprintf(h,"%sformsort",lwidget);
			return((char *) 0);

		case	VISUAL_MEMBER_TABSORT	:
			if (!( tptr = c_dimension() ))
				break;
			else	{
				fprintf(h,"%stabsort(%s);",lwidget,tptr);
				return((char *) 0);
				}

		case	VISUAL_MEMBER_LINESORT  	:
			if (!iptr) break;
			return( cpp_member_linesort(h, iptr ) );

		case	VISUAL_MEMBER_START_SORT	:
			if (!( tptr = c_dimension() ))
				break;
			else	{
				fprintf(h,"%sstartsort(%s);",lwidget,tptr);
				return((char *) 0);			
				}

		case	VISUAL_MEMBER_SORT	:
			if (!( tptr = c_dimension() ))
				break;
			else	{
				fprintf(h,"%ssort(%s);",lwidget,tptr);
				return((char *) 0);				
				}

		case	VISUAL_MEMBER_HELP	:
			if (!( remove_brackets() ))
				break;
			if (!iptr) break;
			else 	{
				if ( Context.Form->onlinehelp & 7 ) {
 					if ( detect_widget_help( iptr ) ) {
#if USE_POINTER_METHOD
						fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONHELP);
#else
						if ((iptr->Contents.style & _FRAME_TYPE) != _RADIO_FRAME)
							fprintf(h,"int %s_help();",iptr->Contents.name);
						else	fprintf(h,"int %s%u_help();",iptr->Contents.name,iptr->Contents.radio);	
#endif
						}
					}
				return((char *) 0);				
				}

		case	VISUAL_MEMBER_ATTACH	:
			if (!( remove_brackets() ))
				break;
			if (!iptr) break;
			else	{
				fprintf(h,"%s_attach()",c_payload(iptr));
				return((char *) 0);
				}

		case	VISUAL_MEMBER_DETACH	:
			if (!( remove_brackets() ))
				break;
			if (!iptr) break;
			else	{
				fprintf(h,"%s_detach()",c_payload(iptr));
				return((char *) 0);				
				}

		case	VISUAL_MEMBER_ONHIDE	:
			if (!( remove_brackets() ))
				break;

			fprintf(h,"%s%s();",lwidget,_ON_HIDE);
			return((char *) 0);

		case	VISUAL_MEMBER_ONFOCUS	:
			if (!( remove_brackets() ))
				break;
			else fprintf(h,"keycode=%s%s();",lwidget,_ON_GETFOCUS);
			return((char *) 0);

		case	VISUAL_MEMBER_ONSHOW	:
			if (!( remove_brackets() ))
				break;
			if (iptr) setpayload(h,iptr,0);
				fprintf(h,"%s%s();",lwidget,_ON_SHOW); 
			return((char *) 0);

		case	VISUAL_MEMBER_TRIGGER	:
			if (!( remove_brackets() ))
				break;
			if (iptr) generate_cpp_trigger(h,iptr,1);
			return((char *) 0);

		case	VISUAL_MEMBER_FREEZE	:
			if (!( remove_brackets() ))
				break;
			fprintf(h,"%s()",__visual_freeze);
			return((char *) 0);

		case	VISUAL_MEMBER_VIEWPORT	:
			if (!( remove_brackets() ))
				break;
			if (iptr) cpp_widget_viewport(h,iptr);
			return((char *) 0);

		case	VISUAL_MEMBER_THAW  	:
			if (!( remove_brackets() ))
				break;
			if ((( iptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME )
			&&  ( iptr->Contents.align & _A_SHADOW )) {
				fprintf(h,"%s(%sx,%sy,%sw+%u,%sh+%u)",
					__visual_thaw,
				lwidget,
				lwidget,
				lwidget,10,
				lwidget,10);
				}
			else	{
				fprintf(h,"%s(%sx,%sy,%sw,%sh)",
					__visual_thaw,
				lwidget,
				lwidget,
				lwidget,
				lwidget);
				}
			return((char *) 0);

		case	VISUAL_MEMBER_FILL  	:
			if (!( remove_brackets() ))
				break;

			fprintf(h,"%s=%s(%sx,%sy,%sw,%sh,%sfg,0);",
				"status",__visual_filzone,
				lwidget,
				lwidget,
				lwidget,
				lwidget,
				lwidget);

			return((char *) 0);

		case	VISUAL_MEMBER_WIPE  	:
			if (!( remove_brackets() ))
				break;
				fprintf(h,"%s=%s(%sx,%sy,%sw,%sh,%sbg,0);",
				"status",__visual_filzone,
				lwidget,
				lwidget,
				lwidget,
				lwidget,
				lwidget);
			return((char *) 0);

		case	VISUAL_MEMBER_RESET	:
			if (!( remove_brackets() ))
				break;
			if (!iptr) break;
			return( cpp_macro_reset(h,iptr) );

		case	VISUAL_MEMBER_CREATE	:
		case	VISUAL_MEMBER_REMOVE	:
		case	VISUAL_MEMBER_SHOW  	:
		case	VISUAL_MEMBER_HIDE  	:
		case	VISUAL_MEMBER_EVENT 	:
		case	VISUAL_MEMBER_GETFOCUS	:
		case	VISUAL_MEMBER_LOSEFOCUS	:
			if (!( remove_brackets() ))
				break;
			if (!iptr) break;
			for (i=0;*(tptr+i)!=0;i++)
				if (( *(tptr+i) >= 'A' )
				&&  ( *(tptr+i) <= 'Z' ))
					*(tptr+i) += ('a' - 'A');
			if ((iptr->Contents.style & _FRAME_TYPE ) == _RADIO_FRAME)
				fprintf(h,"%s%u",iptr->Contents.name,iptr->Contents.radio);
			else
				fprintf(h,"%s",iptr->Contents.name);
			fprintf(h,"_%s()",tptr);
			/* si on veut surcharger les classes remplacer par fprintf(h,"%s->%s()",lwidget,tptr);*/
			return((char *) 0);

		case -1:
			/* fonction non répertoriée -> si DATA OK */
			if ((iptr) 
			&&  ((iptr->Contents.style & _FRAME_TYPE) == _DATA_FRAME)
			&&  ((iptr->Contents.align & 0x000F) == _VISUAL_FRAME)) {
				if ( iptr->Contents.datatype == _WIDGET_MODULE  )
					return( cpp_widget_overlay_method(h,iptr,tptr) );
				else if ( iptr->Contents.datatype == _WIDGET_OVERLAY )
					return( cpp_widget_overlay_method(h,iptr,tptr) );
				else	return((char *) 0);
				}			
		}

	c_syntax_error( tptr,12 );
	fprintf(h,"%s.",iptr->Contents.name);
	return( tptr );
			
}

private	int	cpp_method_line( FILE * h, char * eptr, int l, char * hptr, int * feeder , char *cname,	struct form_item * iptr)
{
	int	punctuate=1;
	int	c;
	char *	tptr;
	if ( feeder ) *feeder = 0;
	if (!( initialise_line_parser( eptr, hptr ) )) 
		return(0);
	while (1) {
		if ((c = c_get_punctuation())) {
			punctuate++;
			fprintf(h,"%c",c);
			/* ----------------------------------------- */
			/* GGBI il faudrait tester aussi le -> 	     */
			/* cas du struct.qqchose ou struct->qqchose, */
			/* si ce qqchose porte le même nom 	     */
			/* qu'un widget on ajouterai alors _OBJ .... */
			/* ----------------------------------------- */
			if (c=='.') {
				if (tptr = c_get_token(0))
					fprintf(h,"%s",tptr);
				}
			}
		else if (!( tptr = c_get_token(0) ))
			break;
		else 	{
			if (!( punctuate ))
				fprintf(h," ");
			punctuate = 0;
			if (!(tptr =  cpp_convert_token(h,tptr,cname,iptr) ))
				continue;
			else 	fprintf(h,"%s",tptr);
			}
		}
	*feeder = 1;
	return(LineParser.status);
}

private	int	cpp_method_body( FILE * h, char * eptr, int l, char * hptr, int margin,char *cname,	struct form_item * iptr )
{
	int	i;
	int	c;
	char *	lptr;
	int	status=0;
	int	feeder=0;
	while ( *eptr != 0 ) {
		/* avoid empty lines */
		feeder=0;
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
			status = cpp_method_line(h,lptr,i,hptr,&feeder,cname,iptr);
			*eptr = c;
			if ( feeder ) linefeed(h);
			if ( status ) break;
			}
		}
	return(status);
}


private	int	cpp_method( 
	FILE * h,
	char * mptr, 
	char * nptr, 
	char * eptr ,char *cname,	struct form_item * iptr,char *method_before,char *method_after)
{
	int	l;
	int	status=0;
	char thisname[256];

	if (!( eptr ))
		return(0);
	else if (( l=strlen(eptr)) > 0 ) {
		sprintf(thisname,"%s_%s",mptr,nptr);
		cpp_entete(h,cname,thisname);
		fprintf(h,"int %s::%s() {",cname,thisname);
		linefeed(h);
		if (method_is_valid(method_before))
			{
			indent(h,1);
			fprintf(h,"%s->%s();",cpp_item_name(iptr),method_before);
			indent(h,1);
			c_comment(h,"/* Ajoute par sing */",0);
			linefeed(h);
			}
		sprintf(thisname,"%s%s->",mptr,DECORE_CLASS);
	/* si on veut surcharger les classes remplacer par thisname[0]=0; */
		status = cpp_method_body( h, eptr, l, thisname, 1 ,cname,iptr);
		if (method_is_valid(method_after))
			{
			linefeed(h);
			fprintf(h,"%s->%s();",cpp_item_name(iptr),method_after);
			indent(h,1);
			fprintf(h,"/* Ajoute par sing */");
			linefeed(h);
			}
		c_return(h,"-1",1);
		fprintf(h,"}");
		linefeed(h);
		}		
	return(status);
}


private	void	cpp_scrollbar_payload( FILE * h, struct form_item * iptr , char *cname,int tabul)
{
	char	*	eptr;
	int		l;

	if (((eptr = iptr->Contents.events->on_event ) != (char *) 0)
	&&  (( l=strlen(eptr)) > 0 )) {
		if ( iptr->Contents.events->xo_show & _EVENT_IS_FUNCTION )
#if USE_POINTER_METHOD
			{
			indent(h,tabul);
			fprintf(h,"%s->%s.Invoke();",cpp_item_name(iptr),_METHOD_ONEVENT);
			linefeed(h);
			}
#else
			activate_cpp_method(h,iptr->Contents.name,__method_event,iptr->Contents.events->on_event,0,tabul);
#endif
		else	inline_cpp_method(h,iptr->Contents.name,__method_event,iptr->Contents.events->on_event,0,tabul,cname,iptr);
		}
	else 	{
		/* Default Invocation of the FORM SHOW method */
		/* ------------------------------------------ */
		if ( C_Config.generate_program ) {
			indent(h,tabul);
			fprintf(h,"on_show();");
			linefeed(h);
			}
		else	{	
			cpp_call(h,"\0",_ON_SHOW, 0,tabul,"status" );
			}
		}
	indent(h,tabul);
	fprintf(h,"%s->visual_widget(1);",cpp_item_name(iptr));
	linefeed(h);
	return;
}

private	void	cpp_scrollbar_up(FILE * h)
{
	indent(h,2); 
	fprintf(h,"do { while( %s() != 256); } while ( %s  != _MIMO_UP );",
				C_Config.input_method,__c_mouse_type);
	linefeed(h); 
	return;
}

private	void	cpp_scrollbutton_driver( FILE * h, struct form_item * iptr, char *cname )
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
			linefeed(h); 
			indent(h,1); fprintf(h,"if ( %s < (%s->x+%s->h) ) {",__c_mouse_column,cpp_item_name(iptr),cpp_item_name(iptr));
			linefeed(h); 
				cpp_scrollbar_up(h);
				indent(h,2); fprintf(h,"%s->value -= 1;",cpp_item_name(iptr));
				linefeed(h);
				indent(h,2); fprintf(h,"%s->limitmin();",cpp_item_name(iptr));
				linefeed(h);
				cpp_scrollbar_payload(h,iptr,cname,2);
				c_return(h,"-1",2);
			c_endif(h,2);
			}
		if ( iptr->Contents.align & _A_RIGHT ) {
			indent(h,1); fprintf(h,"if ( %s > (%s->x+%s->w-%s->h) ) {",__c_mouse_column,cpp_item_name(iptr),cpp_item_name(iptr),cpp_item_name(iptr));
			linefeed(h); 
				cpp_scrollbar_up(h);
				indent(h,2); fprintf(h,"%s->value += 1;",cpp_item_name(iptr));
				linefeed(h);
				indent(h,2); fprintf(h,"%s->limitmax();",cpp_item_name(iptr));
				linefeed(h);
				cpp_scrollbar_payload(h,iptr,cname,2);
				c_return(h,"-1",2);
			c_endif(h,2);
			}
		}
	else	{
		/* ------------------- */
		/* Up and Down Buttons */
		/* ------------------- */
		if ( iptr->Contents.align & _A_LEFT ) {
			indent(h,1); fprintf(h,"if ( %s < (%s->y+%s->w) ) {",__c_mouse_row,cpp_item_name(iptr),cpp_item_name(iptr));
			linefeed(h);
				cpp_scrollbar_up(h);
				indent(h,2); fprintf(h,"%s->value -= 1;",cpp_item_name(iptr));
				linefeed(h);
				indent(h,2); fprintf(h,"%s->limitmin();",cpp_item_name(iptr));
				linefeed(h);
				cpp_scrollbar_payload(h,iptr,cname,2);
				c_return(h,"-1",2);
			c_endif(h,2);
			}
		if ( iptr->Contents.align & _A_RIGHT ) {
			indent(h,1); fprintf(h,"if ( %s > (%s->y+%s->h-%s->w) ) {",__c_mouse_row,cpp_item_name(iptr),cpp_item_name(iptr),cpp_item_name(iptr));
			linefeed(h);
				cpp_scrollbar_up(h);
				indent(h,2); fprintf(h,"%s->value += 1;",cpp_item_name(iptr));
				linefeed(h);
				indent(h,2); fprintf(h,"%s->limitmax();",cpp_item_name(iptr));
				linefeed(h);
				cpp_scrollbar_payload(h,iptr,cname,2);
				c_return(h,"-1",2);
			c_endif(h,2);
			}
		}
	return;
}


private	void	cpp_scrollbar_driver( FILE * h, struct form_item * iptr,char *cname )
{
	int	status=0;
	char	*	eptr;
	int		l;
	char 	*	mode;
	int		item;
	char	*	optr;
	char nfonc[256];

	if ( iptr->Contents.w > iptr->Contents.h ) {
		item = 7;
		mode = "x"; /* horizontal */
		}
	else	{
		item = 6;
		mode = "y"; /* vertical	*/
		}

	sprintf(nfonc,"%s_%s",iptr->Contents.name,__method_action);
	cpp_entete(h,cname,nfonc);
	linefeed(h);
	fprintf(h,"int %s :: %s() {",cname,nfonc);
	linefeed(h); 
	indent(h,1); fprintf(h,"int status;");
	linefeed(h); 
	indent(h,1); fprintf(h,"int at%s=%s(%u);",mode,__c_visual_event,item);
	linefeed(h); 
	indent(h,1); fprintf(h,"int to%s=%s(%u);",mode,__c_visual_event,item);
	linefeed(h); 
	indent(h,1); fprintf(h,"if ( %s !=_MIMO_DOWN) { return(0); }",__c_mouse_type);
	linefeed(h); 

	if ( iptr->Contents.align & ( _A_LEFT |_A_RIGHT ) ) {
		cpp_scrollbutton_driver(h,iptr,cname);
		}
		
	indent(h,1);	fprintf(h,"%s->visual_widget(1);",cpp_item_name(iptr));
	linefeed(h); indent(h,1); fprintf(h,"do {");
	linefeed(h); indent(h,2); 
	if ( C_Config.newstdin )
		fprintf(h,"while(%s() != 256);",C_Config.input_method);
	else	fprintf(h,"while(%s() != 256);",C_Config.input_method);
	linefeed(h); 

	indent(h,2); fprintf(h,"switch( %s ) {",__c_mouse_button);	linefeed(h); 
	indent(h,2); fprintf(h,"case _MIMO_LEFT  :");			linefeed(h); 
	indent(h,2); fprintf(h,"case _MIMO_RIGHT :");			linefeed(h); 

	indent(h,3); fprintf(h,"at%s = %s->value;",mode,cpp_item_name(iptr));
	linefeed(h); 
	indent(h,3); 
	fprintf(h,"%s->value = ",cpp_item_name(iptr));
	if ( iptr->Contents.w > iptr->Contents.h ) {
		switch ( iptr->Contents.align & 0x0007 ) {
			case	_A_NONE		:
			case	_A_JUSTIFY	:
				fprintf(h,"(((%s - %s->x) * %s->max) / %s->w);",
					__c_mouse_column,
					cpp_item_name(iptr),
					cpp_item_name(iptr),
					cpp_item_name(iptr));
				break;
			case	_A_CENTER	:
				fprintf(h,"(((%s - (%s->x+%s->h)) * %s->max) / (%s->w - (2 * %s->h)));",
					__c_mouse_column,
					cpp_item_name(iptr),
					cpp_item_name(iptr),
					cpp_item_name(iptr),
					cpp_item_name(iptr),
					cpp_item_name(iptr));
				break;
			case	_A_LEFT  	:
				fprintf(h,"(((%s - (%s->x+%s->h)) * %s->max) / (%s->w - %s->h));",
					__c_mouse_column,
					cpp_item_name(iptr),
					cpp_item_name(iptr),
					cpp_item_name(iptr),
					cpp_item_name(iptr),
					cpp_item_name(iptr));
				break;
			case	_A_RIGHT	:
				fprintf(h,"(((%s - %s->x) * %s->max) / (%s->w - %s->h));",
					__c_mouse_column,
					cpp_item_name(iptr),
					cpp_item_name(iptr),
					cpp_item_name(iptr),
					cpp_item_name(iptr));
				break;
			default			:
				fprintf(h,"%s->value;",cpp_item_name(iptr));
			}
		}
	else	{
		switch ( iptr->Contents.align & 0x0007 ) {
			case	_A_NONE		:
			case	_A_JUSTIFY	:
				fprintf(h,"(((%s - %s->y) * %s->max) / %s->h );",
					__c_mouse_row,
					cpp_item_name(iptr),
					cpp_item_name(iptr),
					cpp_item_name(iptr));
				break;
			case	_A_CENTER	:
				fprintf(h,"(((%s - (%s->y+%s->w)) * %s->max) / (%s->h - (2 * %s->w)));",
					__c_mouse_row,
					cpp_item_name(iptr),
					cpp_item_name(iptr),
					cpp_item_name(iptr),
					cpp_item_name(iptr),
					cpp_item_name(iptr));
				break;
			case	_A_LEFT		:
				fprintf(h,"(((%s - (%s->y+%s->w)) * %s->max) / (%s->h - %s->w));",
					__c_mouse_row,
					cpp_item_name(iptr),
					cpp_item_name(iptr),
					cpp_item_name(iptr),
					cpp_item_name(iptr),
					cpp_item_name(iptr));
				break;
			case	_A_RIGHT	:
				fprintf(h,"(((%s - %s->y) * %s->max) / (%s->h - %s->w));",
					__c_mouse_row,
					cpp_item_name(iptr),
					cpp_item_name(iptr),
					cpp_item_name(iptr),
					cpp_item_name(iptr));
				break;
			default			:
				fprintf(h,"%s->value;",cpp_item_name(iptr));
			}
		}	
	linefeed(h);
	indent(h,3);	fprintf(h,"%s->limits();",cpp_item_name(iptr));
	linefeed(h);
	indent(h,3); fprintf(h,"if (%s->value != at%s) {",cpp_item_name(iptr),mode);
	linefeed(h); 
	cpp_scrollbar_payload(h,iptr,cname,4);
	indent(h,4); fprintf(h,"}");
	linefeed(h); 
	indent(h,3); fprintf(h,"}");						linefeed(h); 
	indent(h,2); fprintf(h,"}");						linefeed(h);
	indent(h,1); fprintf(h,"while (%s != _MIMO_UP);",__c_mouse_type);	linefeed(h);
	indent(h,1); fprintf(h,"switch( %s ) {",__c_mouse_button);		linefeed(h); 
	indent(h,2); fprintf(h,"case _MIMO_WHEELUP   :");			linefeed(h); 
		indent(h,3); fprintf(h,"%s->value -= (%s->limit/2);",cpp_item_name(iptr),cpp_item_name(iptr));
		linefeed(h); 
		indent(h,3);	fprintf(h,"%s->limitmin();",cpp_item_name(iptr));
		linefeed(h); 
		cpp_scrollbar_payload(h,iptr,cname,3);
		indent(h,3); fprintf(h,"break;"); 				linefeed(h);

	indent(h,2); fprintf(h,"case _MIMO_WHEELDOWN :");			linefeed(h); 
		indent(h,3); fprintf(h,"%s->value += (%s->limit/2);",cpp_item_name(iptr),cpp_item_name(iptr));
		linefeed(h);
		indent(h,3); fprintf(h,"%s->limitmax();",cpp_item_name(iptr));
		linefeed(h);
		cpp_scrollbar_payload(h,iptr,cname,3);
		indent(h,3); fprintf(h,"break;"); 				linefeed(h);

	indent(h,2); fprintf(h,"}");						linefeed(h); 
	indent(h,1);	fprintf(h,"%s->visual_widget(0);",cpp_item_name(iptr));
	linefeed(h); indent(h,1); fprintf(h,"return(1);");
	linefeed(h); fprintf(h,"}");
	linefeed(h);
	return;
}

public	void	cpp_window_driver( FILE * h, struct form_item * iptr,char *cname )
{
	char	*	eptr;
	int		l;
	char 	*	mode;
	char 	*	item;
	char	*	optr;
	char nfonc[256];

	sprintf(nfonc,"%s_%s",iptr->Contents.name,__method_action);
	cpp_entete(h,cname,nfonc);
	linefeed(h);
	fprintf(h,"int %s :: %s() {",cname,nfonc);
	linefeed(h);
	indent(h,1); fprintf(h,"int x=%s;",__c_mouse_column); linefeed(h);
	indent(h,1); fprintf(h,"int y=%s;",__c_mouse_row); linefeed(h);
	indent(h,1); fprintf(h,"do {");	 linefeed(h); 
		indent(h,2); fprintf(h,"do {");	 linefeed(h); 
		linefeed(h); indent(h,3); 
			if ( C_Config.newstdin )
				fprintf(h,"while(%s() != 256);",C_Config.input_method);
			else	fprintf(h,"while(%s() != 256);",C_Config.input_method);
			linefeed(h); 
		indent(h,3); fprintf(h,"}");	 linefeed(h); 
		indent(h,2); fprintf(h,"while( %s );",__c_test_event);	 linefeed(h); 
		generate_c_freeze(h,2);
		cpp_call(h,"\0", _ON_HIDE, 0,2,(char *) 0 );
		linefeed(h);

		indent(h,2);
		fprintf(h,"AddToPosition(%s-x,%s-y);",__c_mouse_column,__c_mouse_row);
		linefeed(h);
		indent(h,2); fprintf(h,"x=%s;",__c_mouse_column); linefeed(h);
		indent(h,2); fprintf(h,"y=%s;",__c_mouse_row);    linefeed(h);

		cpp_call(h,"\0",_ON_SHOW, 0,2,(char *) 0 );
		linefeed(h);
		generate_cpp_thaw(h,2);
	indent(h,2); fprintf(h,"}"); linefeed(h);
	indent(h,1); fprintf(h,"while ((%s & _MIMO_UP) != _MIMO_UP);",__c_mouse_type); linefeed(h);
	indent(h,1); fprintf(h,"return(-1);"); linefeed(h);
	fprintf(h,"}"); linefeed(h);

	return;

}


private	void	cpp_declare_methods( FILE * h ,char *cname)
{
	struct form_item * iptr;
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (!method_is_valid(get_cpp_widget_class(iptr->Contents.style))) continue;

		if (( iptr->Contents.events->on_create )
		&&  ( iptr->Contents.events->xo_create & _EVENT_IS_FUNCTION ))
			cpp_method(h,iptr->Contents.name,__method_create,iptr->Contents.events->on_create,cname,iptr,_ON_CREATE,NULL);

		if (method_is_valid( iptr->Contents.events->on_remove )
			&&  ( iptr->Contents.events->xo_remove & _EVENT_IS_FUNCTION ))
			cpp_method(h,iptr->Contents.name,__method_remove,iptr->Contents.events->on_remove,cname,iptr,NULL,_ON_REMOVE);

		if (method_is_valid( iptr->Contents.events->on_show )
			&&  ( iptr->Contents.events->xo_show & _EVENT_IS_FUNCTION ))
			cpp_method(h,iptr->Contents.name,__method_show,iptr->Contents.events->on_show,cname,iptr,NULL,NULL);

		if (method_is_valid( iptr->Contents.events->on_hide )
			&&  ( iptr->Contents.events->xo_hide & _EVENT_IS_FUNCTION ))
			cpp_method(h,iptr->Contents.name,__method_hide,iptr->Contents.events->on_hide,cname,iptr,NULL,NULL);

		if (method_is_valid( iptr->Contents.events->on_get_focus )
			&&  ( iptr->Contents.events->xo_get_focus & _EVENT_IS_FUNCTION ))
			cpp_method(h,iptr->Contents.name,__method_getfocus,iptr->Contents.events->on_get_focus,cname,iptr,NULL,NULL);

		if (method_is_valid( iptr->Contents.events->on_lose_focus )
			&&  ( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION ))
			cpp_method(h,iptr->Contents.name,__method_losefocus,iptr->Contents.events->on_lose_focus,cname,iptr,_ON_LOSEFOCUS,NULL);

		if (method_is_valid( iptr->Contents.events->on_event )
			&&  ( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION ))
				cpp_method(h,iptr->Contents.name,__method_event,iptr->Contents.events->on_event,cname,iptr,_ON_EVENT,NULL);


		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_WINDOW_FRAME	:
				if ( iptr->Contents.special ) {
					cpp_window_driver(h,iptr,cname);
					}
				break;

			case	_SCROLL_FRAME	:
				/* Scroll Bar Specific Complement */
				/* ------------------------------ */
				cpp_scrollbar_driver(h,iptr,cname);
				break;

			}		
		
		}

	return;
}

private	void	cpp_standard_input( FILE * h, struct form_control * fptr,char *cname)
{
	struct	forms_method 	* mptr;

	for (	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {
		if (!( mptr->name ))
			continue;
		else if (!( mptr->type & _METHOD_FUNCTION ))
			continue;
		else if (string_compare(__c_stdinput,mptr->name))
			return;
		}

	cpp_entete(h,cname,__c_stdinput);
	linefeed(h);
	fprintf(h,"int %s :: %s()",cname,__c_stdinput);
	linefeed(h);
	fprintf(h,"{");
	linefeed(h);
	indent(h,1);
		
	if ( C_Config.newstdin != 2)
		{
		fprintf(h,"return(%s());",C_Config.input_method);
		}
	else
		{
		fprintf(h,"int tempfocus=0;");
		linefeed(h);
		indent(h,1);
		fprintf(h,"while(1) {");
		linefeed(h);
			indent(h,2);
			fprintf(h,"switch ((%s=%s())) {",__c_keycode,__c_get_event);
			linefeed(h);
				indent(h,3);
				fprintf(h,"case 256 :");
				linefeed(h);
					indent(h,4);
					fprintf(h,"if ( %s == _MIMO_MOVE ) {",__c_mouse_type);
					linefeed(h);
						indent(h,5);
						fprintf(h,"if ((tempfocus = %s()) == -1) continue;",_ON_EVENT);
						linefeed(h);
						indent(h,5);
						fprintf(h,"if (tempfocus == %s ) continue;",__c_focus_item);
						linefeed(h);
						indent(h,5);
						fprintf(h,"}");
						linefeed(h);
				indent(h,3);
				fprintf(h,"default  :");
				linefeed(h);

					indent(h,4);
					fprintf(h,"return(%s);",__c_keycode);
					linefeed(h);

				indent(h,3);
				fprintf(h,"}");
				linefeed(h);
			indent(h,2);
			fprintf(h,"}");
			linefeed(h);
		indent(h,1);
		fprintf(h,"return(-1);");
	}
	
	linefeed(h);
	fprintf(h,"}");
	linefeed(h);
	linefeed(h);
	return;
}

void	insert_special_forms_methods(FILE * h,struct form_control * fptr,char *name,char *cname )
{
	struct forms_method *	mptr;
	int			  l;
	
	if (!( fptr ))
		return;


	for (	mptr  = fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next) {
		if (!( mptr->name ))
			continue;
	
		if (upper_compare(mptr->name,name)) {
			if ( mptr->type & _METHOD_FUNCTION ) {
				fprintf(h,"%s();",mptr->name);
				}
			else	{
				if (( l=method_is_valid(mptr->text)) > 0 ) {
					cpp_method_body( h, mptr->text, l, "\0", 1 ,cname,NULL);
					linefeed(h);
					}
				}
			}
		}
	return;
}

public	void	cpp_forms_methods(FILE * h, struct form_control * fptr,char *cname)
{
	struct	forms_method 	* mptr;
	char			* optr;
	int			  l;
	int			  status;

	if (!( fptr ))	
		return;

	cpp_standard_input(h,fptr,cname);

	for (	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {
		if (!( mptr->name ))
			continue;
		else if (!( mptr->type & _METHOD_FUNCTION ))
			continue;
		else	{
			cpp_entete(h,cname,mptr->name);
			cpp_forms_method_prototype(h,mptr,fptr,cname);
			fprintf(h,"{");
			linefeed(h);
			if (( l=method_is_valid(mptr->text)) > 0 ) {
				status = cpp_method_body( h, mptr->text, l, "\0", 1 ,cname,NULL);
				}		
			linefeed(h);
			fprintf(h,"}");
			linefeed(h);
			}
		}
	return;

}

private	void	cpp_detect_trigger_event( FILE * h, struct form_item * iptr, int *margin,char *cname,int *first)
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
		case	_BUTTON_FRAME	:
		case	_SWITCH_FRAME	:
		case	_CHECK_FRAME	:
		case	_TAB_FRAME	:
			if (!( sptr = c_payload(iptr)))
				return;
			break;
		default			:
			return;
		}

	if (!(*first)) {
		indent(h,(*margin)++); 
		fprintf(h,"if (%s & _MIMO_ALT) {",__c_mouse_type);
		linefeed(h);	
		indent(h,(*margin)++);
		fprintf(h,"switch (detect_trigger_events()) {",__c_focus_item);
		linefeed(h);
		(*first)=1;
		}

	indent(h,(*margin)++);
	fprintf(h,"case %u:",iptr->Contents.focus);
	linefeed(h);

	if (!( fptr )) {
		indent(h,(*margin));
		fprintf(h,"return(%u);",iptr->Contents.focus);
		}
	else	{
		switch (( fptr->formflags & _FORM_TYPE_FLAGS )) {
			case	_FORM_TYPE_DIALOG	:
				indent(h,(*margin));
				fprintf(h,"return(%u);",iptr->Contents.focus);
				break;

			case	_FORM_TYPE_EVENT 	:
				cpp_event_switch_item(h, iptr, 0, (*margin),cname,0);
				break;
			}
		}
	linefeed(h);
	c_break(h,(*margin)--);
	linefeed(h);
	return;
}

private	void	cpp_detect_trigger_events( FILE * h, int margin,char *cname )
{
	struct form_item * iptr;
	int first=0;

	
	for (	iptr=Context.Form->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
			cpp_detect_trigger_event(h,iptr,&margin,cname,&first);

	if (first) {
		indent(h,margin--);
		fprintf(h,"}");
		linefeed(h);
		indent(h,margin--);
		fprintf(h,"}");
		linefeed(h);
		}

	return;
}

private	void	export_cpp_formbody( FILE * h, char * cname, char * headfile )
{
	int members;
	char pbuffer[256];
	struct form_item * wptr=(struct form_item*) 0,*iptr;
	int margin;
	char classname[256];
	int wx,wy;
	int first_bouton=0;

	sprintf(classname,"class_%s",cname);

	/* Generate File Banner Block */
	production_banner(h,_GENERATE_CPP,Context.Form->loadname,cname);

	cpp_banner(h,cname);


	if ( C_Config.generate_program )
		c_include(h,"<stdio.h>");

	linefeed(h); linefeed(h);
		
	c_include(h,headfile);

	if ( Context.Form->formflags & _MULTILINGUAL )
		c_define_messages(h,Context.Form);

	linefeed(h);

#ifdef GWB_1
	sort_cpp_form(h,cname);	/* GWB le 14/03/2007 */
#endif
	cpp_declare_methods(h,classname);

	/* Forms Constructor */
	/* ----------------- */
	cpp_entete(h,classname,classname);
	linefeed(h );	fprintf(h,"%s::%s(int px,int py,int ph,int pw,int pfg,int pbg,class_visual_font *pfontclass,class_visual_container *ppere,int pfocus,class_visual_object *pprevious,int pmovable)",classname,classname);

	linefeed(h );	fprintf(h," : class_visual_container(px,py,ph,pw,pfg,pbg,pfontclass,ppere,pfocus,pprevious,pmovable)");
	linefeed(h );	fprintf(h,"{"); linefeed(h);

	sprintf(pbuffer,"%sConstruct",_BEGIN);
	insert_special_forms_methods(h,Context.Form,pbuffer,cname);
	construct_cpp_form(h,classname);
	sprintf(pbuffer,"%sConstruct",_END);
	insert_special_forms_methods(h,Context.Form,pbuffer,cname);

	linefeed(h );
	indent(h,1);
	fprintf(h,"return;");
	linefeed(h );
	fprintf(h,"}");
	linefeed(h );

	/* Forms Destructor */
	/* ---------------- */
	sprintf(pbuffer,"~class_%s",classname);
	cpp_entete(h,classname,pbuffer);
	linefeed(h );	fprintf(h,"%s::~%s()",classname,classname);
	linefeed(h );	fprintf(h,"{");

	sprintf(pbuffer,"%sDestruct",_BEGIN);
	insert_special_forms_methods(h,Context.Form,pbuffer,cname);
	linefeed(h);
	destruct_cpp_form(h,classname);

	sprintf(pbuffer,"%sDestruct",_END);
	insert_special_forms_methods(h,Context.Form,pbuffer,cname);

	linefeed(h );
	indent(h,1);
	fprintf(h,"return;");
	linefeed(h );
	fprintf(h,"}");
	linefeed(h );

	/* On TransfertIn */
	/* -------------- */
	if ((members=cpp_member_parameters(h,99))) {
		cpp_entete(h,classname,_ON_TRANSFERTIN);
		linefeed(h );	fprintf(h,"int %s::%s()",classname,_ON_TRANSFERTIN);
		linefeed(h );	fprintf(h,"{"); linefeed(h);
		cpp_transfer_parameters(h,1);
		indent(h,1);
		fprintf(h,"return(-1);");
		linefeed(h);
		fprintf(h,"}");
		linefeed(h);
		}

	/* On TransfertOut */
	/* --------------- */
	if (members) {
		cpp_entete(h,classname,_ON_TRANSFERTOUT);
		linefeed(h );	fprintf(h,"int %s::%s()",classname,_ON_TRANSFERTOUT);
		linefeed(h );	fprintf(h,"{"); linefeed(h);
		cpp_transfer_parameters(h,0);
		indent(h,1);
		fprintf(h,"return(-1);");
		linefeed(h);
		fprintf(h,"}");
		linefeed(h);
		}

	/* initialise structure */
	/* -------------------- */
	if (members) 	{
		cpp_entete(h,classname,_ON_INITIALISETRANSFERT);
		linefeed(h );	fprintf(h,"int %s::%s(",classname,_ON_INITIALISETRANSFERT);
		cpp_member_parameters(h,0);
		fprintf(h,")");
		linefeed(h );	fprintf(h,"{"); linefeed(h);
		cpp_initialise_parameters(h);
		indent(h,1);
		fprintf(h,"return(-1);");
		linefeed(h);
		fprintf(h,"}");
		linefeed(h);
		}

	/* On Create */
	/* --------- */
	cpp_entete(h,classname,_ON_CREATE);
	linefeed(h );	fprintf(h,"int %s::%s()",classname,_ON_CREATE);
	linefeed(h );	fprintf(h,"{"); linefeed(h);

	sprintf(pbuffer,"%s%s",_BEGIN,_ON_CREATE);
	insert_special_forms_methods(h,Context.Form,pbuffer,cname);
	
	generate_cpp_createfont(h,1);
	indent(h,1);
	fprintf(h,"%s=0;",__c_keycode);
	linefeed(h);
	indent(h,1);
	fprintf(h,"%s=1;",__c_focus_item);
	linefeed(h);
	indent(h,1);
	fprintf(h,"%ss=%u;",__c_focus_item,Context.Form->focus);
	linefeed(h);

	if ( C_Config.page_control ) {
		indent(h,1);
		fprintf(h,"%s=1;",__c_page_number);
		linefeed(h);
		}

	if ( C_Config.generate_program ) {
		/* init / palette etc */
		generate_cpp_onstart( h, 0 );
		}
	cpp_initialise_national_language(h,Context.Form,1);
	if (method_is_valid( Context.Form->stylesheet) ) {
		indent(h,1);
		fprintf(h,"status = load_visual_style(");
		quoted_string(h,Context.Form->stylesheet);
		fprintf(h,",%u);",strlen(Context.Form->stylesheet));
		linefeed(h);
		}

	if (members)
		{
		indent(h,1);
		fprintf(h,"%s();",_ON_TRANSFERTIN);
		linefeed(h);
		}
	create_cpp_form(h,classname,&wptr);

	sprintf(pbuffer,"%s%s",_END,_ON_CREATE);
	insert_special_forms_methods(h,Context.Form,pbuffer,cname);
	
	linefeed(h );
	indent(h,1);
	fprintf(h,"return(-1);");
	linefeed(h );
	fprintf(h,"}");
	linefeed(h );

	/* On Remove */
	/* --------- */
	cpp_entete(h,classname,_ON_REMOVE);
	linefeed(h );	fprintf(h,"int %s::%s()",classname,_ON_REMOVE);
	linefeed(h );	fprintf(h,"{"); linefeed(h);

	sprintf(pbuffer,"%s%s",_BEGIN,_ON_REMOVE);
	insert_special_forms_methods(h,Context.Form,pbuffer,cname);
	
	remove_cpp_form(h,classname);

	if (members)
		{
		indent(h,1);
		fprintf(h,"%s();",_ON_TRANSFERTOUT);
		linefeed(h);
		}
	sprintf(pbuffer,"%s%s",_END,_ON_REMOVE);
	insert_special_forms_methods(h,Context.Form,pbuffer,cname);

	linefeed(h );
	indent(h,1);
	fprintf(h,"return(-1);");
	linefeed(h );
	fprintf(h,"}");
	linefeed(h );

	/* On Show */
	/* ------- */
	cpp_entete(h,classname,_ON_SHOW);
	linefeed(h );	fprintf(h,"int %s::%s()",classname,_ON_SHOW);
	linefeed(h );	fprintf(h,"{"); linefeed(h);

	sprintf(pbuffer,"%s%s",_BEGIN,_ON_SHOW);
	insert_special_forms_methods(h,Context.Form,pbuffer,cname);
	
	cpp_initialise_national_language(h,Context.Form,1);
	show_cpp_form(h,classname);

	sprintf(pbuffer,"%s%s",_END,_ON_SHOW);
	insert_special_forms_methods(h,Context.Form,pbuffer,cname);
	
	linefeed(h );
	indent(h,1);
	fprintf(h,"return(0);");
	linefeed(h );
	fprintf(h,"}");
	linefeed(h );

	/* -------------------- */
	/*	ON _ HELP  	*/
	/* -------------------- */
	if ( (Context.Form->onlinehelp & 7) ) {
		cpp_entete(h,NULL,"d'aide");
		c_form_onhelp( h,classname );
		}

	/* On Hide */
	/* ------- */
	cpp_entete(h,classname,_ON_HIDE);
	linefeed(h );	fprintf(h,"int %s::%s()",classname,_ON_HIDE);
	linefeed(h );	fprintf(h,"{"); linefeed(h);

	sprintf(pbuffer,"%s%s",_BEGIN,_ON_HIDE);
	insert_special_forms_methods(h,Context.Form,pbuffer,cname);
	
	hide_cpp_form(h,classname);

	sprintf(pbuffer,"%s%s",_END,_ON_HIDE);
	insert_special_forms_methods(h,Context.Form,pbuffer,cname);
	
	linefeed(h);
	indent(h,1);
	fprintf(h,"return(-1);");
	linefeed(h );
	fprintf(h,"}");
	linefeed(h );

	/* On GetFocus */
	/* ----------- */
	cpp_entete(h,classname,_ON_GETFOCUS);
	linefeed(h );	fprintf(h,"int %s::%s()",classname,_ON_GETFOCUS);
	linefeed(h );	fprintf(h,"{"); linefeed(h);
	linefeed(h);
	indent(h,1); fprintf(h,"int retcode=0;");
	linefeed(h);

	sprintf(pbuffer,"%s%s",_BEGIN,_ON_GETFOCUS);
	insert_special_forms_methods(h,Context.Form,pbuffer,cname);
	
	if (!( Context.Form->focus )) { /* No focus items ! */
		indent(h,1);
		fprintf(h,"%s=13;",__c_keycode);
		linefeed(h);
		}
	else	{	

		generate_cpp_event_flush(h); 
		linefeed(h);	

// GGBI
//		fprintf(h,"while (visual_getch()!=27);");
//		linefeed(h);
//		fprintf(h,"return(-1);");
//		linefeed(h); linefeed(h);
// fin GGBI

		indent(h,1);	fprintf(h,"while(1) {");
		linefeed(h);
		linefeed(h);
		indent(h,2);	fprintf(h,"switch (%s) {",__c_focus_item);
		linefeed(h);
	
		onfocus_cpp_form(h,classname);

		linefeed(h);
		c_default(h,3);
		indent(h,4);
		fprintf(h,"%s=5;",__c_keycode);
		linefeed(h);
		indent(h,3);
		fprintf(h,"}");
		linefeed(h);
		if (!( Context.Form->mimoflags & _MIMO_KEYBOARD )) {
			fprintf(h,"retry:");
			linefeed(h);
			}
		indent(h,2);	fprintf(h,"switch (%s) {",__c_keycode);
		linefeed(h);
		c_case(h,0x000C,2);	/* Home	     */
			if ( C_Config.page_control ) {
				cpp_call(h,"\0",_ON_LOSEFOCUS, 0,3,(char*) 0 );
				indent(h,3);
				fprintf(h,"%s=1;",__c_page_number);
				linefeed(h);
				}
			indent(h,3);
			fprintf(h,"%s=1;",__c_focus_item);
			linefeed(h);
			cpp_call(h,"\0",_ON_SHOW, 0,3,(char*) 0 );
			c_continue(h,3);
			
		c_case(h,0x0002,2);	/* End 	     */
			if ( C_Config.page_control ) {
				cpp_call(h,"\0",_ON_LOSEFOCUS, 0,3,(char*) 0 );
				indent(h,3);
				fprintf(h,"%s=%u;",__c_page_number,Context.Form->pages);
				linefeed(h);
				}
			indent(h,3);
			fprintf(h,"%s=%u;",__c_focus_item,Context.Form->focus);
			linefeed(h);
			cpp_call(h,"\0",_ON_SHOW, 0,3,(char *) 0 );
			c_continue(h,3);

	if ( C_Config.page_control ) {
		c_case(h,3,2);	/* Page Down */
			cpp_call(h,"\0",_ON_LOSEFOCUS, 0,3,(char*) 0 );
			indent(h,3);
			fprintf(h,"if ( %s < %u )",__c_page_number,Context.Form->pages );
			linefeed(h);
			indent(h,4);
			fprintf(h,"%s++;",__c_page_number);
			linefeed(h);
			indent(h,3);
			fprintf(h,"else\t%s=1;",__c_page_number);
			linefeed(h);
			indent(h,3);
			fprintf(h,"%s=focus_pages[%s];",__c_focus_item,__c_page_number);
			linefeed(h);
			cpp_call(h,"\0",_ON_SHOW, 0,3,(char *) 0 );
			c_continue(h,3);
		c_case(h,0x0012,2);	/* Page Up   */
			cpp_call(h,"\0",_ON_LOSEFOCUS, 0,3,(char*) 0 );
			indent(h,3);
			fprintf(h,"if (%s > 1 )",__c_page_number);
			linefeed(h);
			indent(h,4);
			fprintf(h,"%s--;",__c_page_number);
			linefeed(h);
			indent(h,3);
			fprintf(h,"else\t%s = %u;",__c_page_number,C_Config.page_control);
			linefeed(h);
			indent(h,3);
			fprintf(h,"%s=focus_pages[%s];",__c_focus_item,__c_page_number);
			linefeed(h);
			cpp_call(h,"\0",_ON_SHOW, 0,3,(char *) 0 );
			c_continue(h,3);

		}
		c_case(h,256,2);
			if ((!( Context.Form->mimoflags & _MIMO_KEYBOARD ))
			&&  (!( Context.Form->formflags & _MULTILINGUAL  ))) {
				indent(h,3); fprintf(h,"if (%s & _MIMO_ALT) {",__c_mouse_type);
				fprintf(h," %s=%s; goto retry; }",__c_keycode,__c_mouse_button);
				linefeed(h);
				}
			margin=3;
			if ( Context.Form->formflags & _FORM_DEFAULT ) {
/*				if ((pwptr = connect_production_window()) != (struct window_control *) 0) {*/
						indent(h,3);
						fprintf(h,"if (!( %s  & _MIMO_ALT )) { ",__c_mouse_type);
						linefeed(h);
						
/* GGBI, pour gestion des menus, a voir en optionnel pour ne pas perturber les autres fenetres */
						indent(h,4);
						fprintf(h,"if ((pere)");
						linefeed(h);
						indent(h,4);
						fprintf(h,"&& ( %s >= pere->x )",__c_mouse_column);
						linefeed(h);
						indent(h,4);
						fprintf(h,"&& ( %s >= pere->y )",__c_mouse_row);
						linefeed(h);
						indent(h,4);
						fprintf(h,"&& ( %s <= pere->x+pere->w )",__c_mouse_column);
						linefeed(h);
						indent(h,4);
						fprintf(h,"&& ( %s <= pere->y+pere->h )",__c_mouse_row);
						linefeed(h);
						indent(h,4);
						fprintf(h,"&& (%s & _MIMO_MOVE))",__c_mouse_type);
						linefeed(h);
						c_return(h,"-2",5);
/* fin gestion menus */

						indent(h,4);
						fprintf(h,"if (( %s <  x )",__c_mouse_column);
						linefeed(h);
						indent(h,4);
						fprintf(h,"|| ( %s <  y )",__c_mouse_row);
						linefeed(h);
						indent(h,4);
						fprintf(h,"|| ( %s >  x+w )",__c_mouse_column);
						linefeed(h);
						indent(h,4);
						fprintf(h,"|| ( %s >  y+h )) {",__c_mouse_row);
						linefeed(h);
						margin=5;

					indent(h,margin);
					fprintf(h,"if ( %s  & _MIMO_MOVE ) { continue; }",__c_mouse_type);
					linefeed(h);
					indent(h,margin);
					fprintf(h,"else { return(256); }");
					linefeed(h);
					if (margin>3) {
						indent(h,margin--);
						fprintf(h,"}");
						linefeed(h);
						indent(h,margin--);
						fprintf(h,"}");
						linefeed(h);
						}
					/*}*/
				}
			generate_cpp_event_switch(h,classname);
			c_break(h,4);

		c_case(h,27,2);
			if ( Context.Form->OnEscape ) {
				cpp_special_method(h, Context.Form->OnEscape , 3,classname );
				} 
			c_break(h,3);
		c_case(h,13,2);

		if (( Context.Form->formflags & _FORM_RC )) {
			if ( Context.Form->OnEnter ) {
				cpp_special_method(h, Context.Form->OnEnter , 3,classname );
				} 
			c_break(h,3);
			linefeed(h);
			}
		else
			{
			for (	iptr=Context.Form->first;  
				iptr != (struct form_item *) 0; 
				iptr = iptr->next )  {

				if ((!( iptr->Contents.w  ))
				||  (!( iptr->Contents.h  ))
				|| ((iptr->Contents.style & _FRAME_TYPE) != _BUTTON_FRAME))
					continue;

				else if (!( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ))
					continue;
				else if (!( method_is_valid(iptr->Contents.events->on_event) ))
					continue;
				
				else if (!(first_bouton)) {
					indent(h,3);
					fprintf(h,"switch (%s) {",__c_focus_item);
					linefeed(h);
					first_bouton=1;
					}
				cpp_event_switch_item( h, iptr, 1, 4,cname,0 );	/* si event <>-1 alors break */
				linefeed(h);
				}
			if (first_bouton) {
				indent(h,4);
				fprintf(h,"default :");
				linefeed(h);
				indent(h,5);
				fprintf(h,"%s = 5;",__c_keycode);	/* ainsi CR sur autre chose qu'un bouton entraine fleche bas */
				linefeed(h);
				c_continue(h,5);
				indent(h,4);
				fprintf(h,"}");
				linefeed(h);
				c_break(h,3);		/* on arrive ici si event <>-1 ce qui entraine sortie du while et du onfocus */
				linefeed(h);
				}
			}

		c_case(h, 9,2); 
		c_case(h, 5,2); 
			indent(h,3);
			fprintf(h,"if ( %s < %ss ) {",__c_focus_item,__c_focus_item);
			linefeed(h);
				indent(h,4);
				fprintf(h,"%s++;",__c_focus_item);
				linefeed(h); indent(h,3);
			c_else(h,3);
				indent(h,4);
				fprintf(h,"%s=1;",__c_focus_item);
				linefeed(h);
			c_endif(h,3);
			c_continue( h,3 );
		c_case(h,11,2);
			indent(h,3);
			fprintf(h,"if ( %s > 1 ) {",__c_focus_item);
			linefeed(h);
				indent(h,4);
				fprintf(h,"%s--;",__c_focus_item);
				linefeed(h);
			c_else( h, 3 );
				indent(h,4);
				fprintf(h,"%s=%u;",__c_focus_item,
					Context.Form->focus);
				linefeed(h);
			c_endif( h, 3 );
			c_continue( h,3 );
		if ( Context.Form->mimoflags & _MIMO_INTERRUPT ) {
			generate_cpp_hotkey_switch(h,2,classname);
			}

		if (!( Context.Form->formflags & _FORM_DEFAULT )) {
			indent(h,2);
			fprintf(h,"default :");
			linefeed(h);
			if ( Context.Form->OnDefault) {
				cpp_special_method(h, Context.Form->OnDefault, 3 ,classname);
				} 
			c_continue(h,3);
			}
		else	{
			c_case(h,0,2);
			indent(h,3);
			linefeed(h);
			c_continue(h,3);
			c_case(h,-1,2);
			indent(h,3);
			linefeed(h);
			c_continue(h,3);
			}

	linefeed(h);	indent(h,3);	fprintf(h,"}");
	linefeed(h);	c_break(h,2);
	indent(h,2);	fprintf(h,"}");
	linefeed(h);
		} /* ! focus */

	linefeed(h);

	sprintf(pbuffer,"%s%s",_END,_ON_GETFOCUS);
	insert_special_forms_methods(h,Context.Form,pbuffer,cname);
	
	if (!( Context.Form->formflags & _FORM_DEFAULT )) {
		generate_cpp_event_flush(h);
		c_return(h,__c_keycode,1);
		}
	else	{
		indent(h,1);
		fprintf(h,"return( %s );",__c_keycode);
		}
	linefeed(h); fprintf(h,"}"); linefeed(h);
	linefeed(h );

	/* On LoseFocus */
	/* ------------ */
	cpp_entete(h,classname,_ON_LOSEFOCUS);
	linefeed(h );	fprintf(h,"int %s::%s()",classname,_ON_LOSEFOCUS);
	linefeed(h );	fprintf(h,"{"); linefeed(h);


	sprintf(pbuffer,"%s%s",_BEGIN,_ON_LOSEFOCUS);
	insert_special_forms_methods(h,Context.Form,pbuffer,cname);
	
	lose_cpp_form(h,classname);

	sprintf(pbuffer,"%s%s",_BEGIN,_ON_LOSEFOCUS);
	insert_special_forms_methods(h,Context.Form,pbuffer,cname);
	
	linefeed(h );
	indent(h,1);
	fprintf(h,"return(-1);");
	linefeed(h );
	fprintf(h,"}");
	linefeed(h );

	/* On Event */
	/* -------- */
	cpp_entete(h,classname,_ON_EVENT);
	linefeed(h );	fprintf(h,"int %s::%s()",classname,_ON_EVENT);
	linefeed(h );	fprintf(h,"{"); linefeed(h);

	indent(h,1);	fprintf(h,"int\tmx,my,mt,mb;");
	linefeed(h);
						
	sprintf(pbuffer,"%s%s",_BEGIN,_ON_EVENT);
	insert_special_forms_methods(h,Context.Form,pbuffer,cname);
	
	/* ---------------------------------------------- */
	/* international / multilingual trigger detection */
	/* ---------------------------------------------- */
	if (( Context.Form->formflags & _INTERNATIONAL )
	&&  ( Context.Form->formflags & _MULTILINGUAL  )) {
		cpp_detect_trigger_events(h,1,cname);
		}

	indent(h,1);
	fprintf(h,"if (!((mt = %s) & 0x%x)) return(-1); ",__c_mouse_type,Context.Form->mimoflags);	linefeed(h);

	indent(h,1);	fprintf(h,"mx = %s;",__c_mouse_column);	linefeed(h);
	indent(h,1);	fprintf(h,"my = %s;",__c_mouse_row);		linefeed(h);
	event_cpp_form(h,classname);


/* GGBI, pour gestion des menus, a voir en optionnel pour ne pas perturber les autres fenetres */
	indent(h,1);
	fprintf(h,"if ((pere)");
	linefeed(h);
	indent(h,1);
	fprintf(h,"&& ( %s >= pere->x )",__c_mouse_column);
	linefeed(h);
	indent(h,1);
	fprintf(h,"&& ( %s >= pere->y )",__c_mouse_row);
	linefeed(h);
	indent(h,1);
	fprintf(h,"&& ( %s <= pere->x+pere->w )",__c_mouse_column);
	linefeed(h);
	indent(h,1);
	fprintf(h,"&& ( %s <= pere->y+pere->h )",__c_mouse_row);
	linefeed(h);
	indent(h,1);
	fprintf(h,"&& (%s & _MIMO_MOVE))",__c_mouse_type);
	linefeed(h);
	c_return(h,"256",2);
/* GGBI fin gestion menus  */

	sprintf(pbuffer,"%s%s",_END,_ON_EVENT);
	insert_special_forms_methods(h,Context.Form,pbuffer,cname);
	
	linefeed(h);
	linefeed(h );
	indent(h,1);
	fprintf(h,"return(-1);");
	linefeed(h );
	fprintf(h,"}");
	linefeed(h );

	/* forms methods */
	/* ------------- */
	cpp_forms_methods(h,Context.Form,classname);

	/* gerer fiche  */
	/* ------------ */
	cpp_entete(h,classname,_ON_GERER);
	linefeed(h );	fprintf(h,"int %s::%s(",classname,_ON_GERER);
	members=cpp_member_parameters(h,0);
	fprintf(h,")");
	linefeed(h );	fprintf(h,"{");
	linefeed(h); indent(h,1); fprintf(h,"int result=0;");
	linefeed(h);
	if (members)
		{
		linefeed(h); indent(h,1); fprintf(h,"%s(",_ON_INITIALISETRANSFERT);
		cpp_member_parameters(h,1);
		fprintf(h,");");
		}

	linefeed(h); indent(h,1); fprintf(h,"%s();",_ON_CREATE);
	linefeed(h); indent(h,1); fprintf(h,"%s();",_ON_SHOW);
	if (!(C_Config.generate_program) &&
		(( Context.Form->formflags & _FORM_TYPE_FLAGS ) == _FORM_TYPE_DIALOG)) {
		linefeed(h);
		indent(h,1); 
		fprintf(h,"enter_modal();"); 
		}
	linefeed(h); indent(h,1); fprintf(h,"result = %s();",_ON_GETFOCUS);
	if (!(C_Config.generate_program) &&
		(( Context.Form->formflags & _FORM_TYPE_FLAGS ) == _FORM_TYPE_DIALOG)) {
		linefeed(h);
		indent(h,1); 
		fprintf(h,"leave_modal();"); 
		}
	linefeed(h); indent(h,1); fprintf(h,"%s();",_ON_LOSEFOCUS);
	linefeed(h); indent(h,1); fprintf(h,"%s();",_ON_HIDE);
	linefeed(h); indent(h,1); fprintf(h,"%s();",_ON_REMOVE);
	linefeed(h); indent(h,1); fprintf(h,"return(result);");
	linefeed(h );	fprintf(h,"}");
	linefeed(h );

	/* saisie fiche  */
	/* ------------- */
	cpp_entete(h,classname,_ON_EXEC);
	linefeed(h );	fprintf(h,"int %s::%s()",classname,_ON_EXEC);
	linefeed(h );	fprintf(h,"{");
	linefeed(h); indent(h,1); fprintf(h,"int result=0;");
	linefeed(h);
	linefeed(h); indent(h,1); fprintf(h,"%s();",_ON_SHOW);
	if (!(C_Config.generate_program) &&
		(( Context.Form->formflags & _FORM_TYPE_FLAGS ) == _FORM_TYPE_DIALOG)) {
		linefeed(h);
		indent(h,1); 
		fprintf(h,"enter_modal();"); 
		}
	linefeed(h); indent(h,1); fprintf(h,"result = %s();",_ON_GETFOCUS);
	if (!(C_Config.generate_program) &&
		(( Context.Form->formflags & _FORM_TYPE_FLAGS ) == _FORM_TYPE_DIALOG)) {
		linefeed(h);
		indent(h,1); 
		fprintf(h,"leave_modal();"); 
		}
	linefeed(h); indent(h,1); fprintf(h,"%s();",_ON_LOSEFOCUS);
	linefeed(h); indent(h,1); fprintf(h,"%s();",_ON_HIDE);
	linefeed(h); indent(h,1); fprintf(h,"return(result);");
	linefeed(h );	fprintf(h,"}");
	linefeed(h );
	
	if (wptr != (struct form_item *)0)
		{
		calculate_window_alignment(wptr);
		get_window_alignment(&wx,&wy);
		}

	if (C_Config.generate_overlay) {


		if (!C_Config.generate_program)	/* DLL */
			{
			linefeed(h);
			fprintf(h,"#ifdef EXPORT_LIBRARY");
			linefeed(h);
			fprintf(h,"extern %cC%c {",__QUOTE,__QUOTE);
			linefeed(h); indent(h,1);
			fprintf(h,"public void *attach_obj()");
			linefeed(h); indent(h,1); fprintf(h,"{");

			linefeed(h); indent(h,2); fprintf(h,"%s * instance;",classname);
			linefeed(h); indent(h,2); fprintf(h,"instance = new %s();",classname);
			linefeed(h); indent(h,2); fprintf(h,"return((void *)instance);");
			linefeed(h); indent(h,1); fprintf(h,"}");
			linefeed(h); linefeed(h); indent(h,1);

			fprintf(h,"#ifdef WIN32");
			linefeed(h); indent(h,2);
			fprintf(h,"__declspec( dllexport ) void detach(void *instance);");
			linefeed(h); indent(h,1);
			fprintf(h,"#endif	/* WIN32 */");
			linefeed(h); linefeed(h); indent(h,1);

			fprintf(h,"public void detach(void *instance)");
			linefeed(h); indent(h,1); fprintf(h,"{");

			linefeed(h); indent(h,2); fprintf(h,"delete (%s *)instance;",classname);
			linefeed(h); indent(h,1); fprintf(h,"}");
			linefeed(h); fprintf(h,"}");
			linefeed(h);		

			fprintf(h,"#endif	/* EXPORT_LIBRARY */");
			}
		linefeed(h);
		}
	else if (C_Config.generate_program)	{
		linefeed(h); fprintf(h,"extern %cC%c { unsigned char *nprog=(unsigned char *)%c%s%c; }",__QUOTE,__QUOTE,__QUOTE,cname,__QUOTE);	// les accolades ‚vitent un warning sous UseIt
		linefeed(h);
		linefeed(h); fprintf(h,"extern %cC%c int cpp_main(int argc,char *argv[])",__QUOTE,__QUOTE);
		linefeed(h); fprintf(h,"{");
		linefeed(h); indent(h,1);	fprintf(h,"int result;");
		linefeed(h); indent(h,1);	fprintf(h,"%s * instance=0;",classname);
		linefeed(h);  indent(h,1);
/*		if ((pwptr = connect_production_window()) != (struct window_control *) 0)
			{
			fprintf(h,"instance = new %s(%d,%d,%d,%d);",classname,pwptr->x+wx,pwptr->y+wy,pwptr->h,pwptr->w);
			}
		else*/
			fprintf(h,"instance = new %s(0,0);",classname);
		linefeed(h); indent(h,1); fprintf(h,"result = instance->%s(",_ON_GERER);
		cpp_member_parameters(h,1);
		fprintf(h,");");
		linefeed(h); indent(h,1); fprintf(h,"delete instance;");
		linefeed(h); indent(h,1); fprintf(h,"return(result);");
		linefeed(h); fprintf(h,"}");
		linefeed(h);
		}
	else	{
		cpp_entete(h,NULL,cname);	
		fprintf(h,"extern %cC%c",__QUOTE,__QUOTE);
		linefeed(h);
		fprintf(h,"public int %s(",cname);
		members=cpp_member_parameters(h,0);
		fprintf(h,")");
		linefeed(h); fprintf(h,"{");
		linefeed(h); indent(h,1); fprintf(h,"int result=0;");
		linefeed(h); indent(h,1); fprintf(h,"%s * instance;",classname);
		linefeed(h); indent(h,1); 

		fprintf(h,"instance = new %s();",classname);

		linefeed(h); fprintf(h,"\tresult = instance->%s(",_ON_GERER);
		cpp_member_parameters(h,1);
		fprintf(h,");");
		linefeed(h); indent(h,1); fprintf(h,"delete instance;");
		linefeed(h); indent(h,1); fprintf(h,"return(result);");
		linefeed(h); fprintf(h,"}");
		linefeed(h);
		}

	linefeed(h);
	return;
}

/* GWB le 14/03/2007 */
#ifdef GWB_1
private	void	export_cpp_headsort( FILE * h,char * cname )
{
	struct form_item * iptr;
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if ((iptr->Contents.style & _FRAME_TYPE) == _FORM_FRAME)
			{
			linefeed(h);
			fprintf(h,"class\t%s_%s : visual_%s {",cname,iptr->Contents.name,get_cpp_widget_class(iptr->Contents.style));
			
			linefeed(h);	indent(h,1);
			fprintf(h,"int formsort;\t\t\t\t/* sort 0 rien, positif numéro de colonne, négatif, numéro de colonne tri decroissant */");
			linefeed(h);	indent(h,1);
			fprintf(h,"char *libsort;\t\t\t\t/* table intermédiaire contenant la liste des éléments a trier */");
			linefeed(h);	indent(h,1);
			fprintf(h,"int *tab_sort;\t\t\t\t/* numéro d'ordre des elements triés */");
			linefeed(h);	indent(h,1);
			fprintf(h,"char *indsort;\t\t\t\t/* pointeur table intermédiaire de tri */");
			linefeed(h);	indent(h,1);
			fprintf(h,"int nelt;\t\t\t\t\t/* nombre d'eléments aloués dans tab_sort */");
	
			linefeed(h);	indent(h,1);	
			fprintf(h,"int tabsort(int nelts);\t\t/* returns resolved sort item */");
			linefeed(h);	indent(h,1);
			fprintf(h,"void linesort(int nelts);\t/* select the linesort to fill */");
			linefeed(h);	indent(h,1);
			fprintf(h,"void startsort(int nelts);\t/* allocate intermediate sort table */");
			linefeed(h);	indent(h,1);
			fprintf(h,"void sort(int nelts);\t\t/* sort the intermediate table into tab_sort */");
			linefeed(h);	indent(h,1);
			fprintf(h,"int compare(int a,int b);\t/* compare the elements a et b of libsort */");
			linefeed(h);	indent(h,1);


			fprintf(h,"void line(int nelts);\t/* select the line to fill */");
			linefeed(h);	indent(h,1);
			fprintf(h,"char *column(int ncol);\t/* select the adresse of column to fill */");
			linefeed(h);	indent(h,1);

			fprintf(h,"}");
			linefeed(h);
			}
		}

	return;
}
#endif	/* GWB_1 */
/* fin GWB le 14/03/2007 */

void write_protect(FILE * h,int *wptr,int type)
{
	if (*wptr) return;

	switch (type) {
		case 0:	/* public */
			fprintf(h,"public:");
			break;
		case 1:	/* private */
			fprintf(h,"private:");
			break;
		}
	linefeed(h);
	(*wptr)=1;
	return;
}			

private	void	export_cpp_formhead( FILE * h, char * cname )
{
	struct	form_item * iptr;
	struct	window_control * pwptr=(struct window_control *) 0;
	struct form_item * wptr=(struct form_item*) 0;
	int wx=0,wy=0;
	int wprivate=0,wpublic=0;
	cpp_banner(h,cname);

	c_include(h,"vclass.h");
	c_include(h,"visual.h");

	if ( Context.Form->dependance)
		c_dependance(h,Context.Form->dependance);

	export_cpp_datahead(h);

#ifdef GWB_1
	export_cpp_headsort(h,cname);	/* GWB le 14/03/2007 */
#endif

	linefeed(h);
	fprintf(h,"#undef public");

	linefeed(h); linefeed(h);

	/* définition structure de paramétres */
	if (cpp_member_parameters(h,99)) {
		fprintf(h,"extern %cC%c {",__QUOTE,__QUOTE);
		linefeed(h);
		fprintf(h,"struct data_%s {",cname);
		cpp_member_parameters(h,2);
		linefeed(h);
		indent(h,2);
		fprintf(h,"}");
		linefeed(h);
		fprintf(h,"}");
		linefeed(h);
		linefeed(h);
		}

	fprintf(h,"class\tclass_%s : public class_visual_container {",cname);
	linefeed(h);
	write_protect(h,&wpublic,0);
	define_cpp_instance(h,cname);
	linefeed(h);	define_cpp_radio(h);
	if (cpp_member_parameters(h,99)) {
		indent(h,1);
		fprintf(h,"struct data_%s %s;",cname,_DATA_INTERFACE);
		linefeed(h);
		}

	linefeed(h );
	indent(h,1);
	fprintf(h,"class_%s(",cname);
		
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
				
		if ((iptr->Contents.style & _FRAME_TYPE ) == _WINDOW_FRAME)
			{
			wptr=iptr;
			calculate_window_alignment(iptr);
			get_window_alignment(&wx,&wy);
			break;
			}
		}

	if ((pwptr = connect_production_window()) != (struct window_control *) 0)
		fprintf(h,"int px=%u,int py=%u,int ph=%d,int pw=%d",pwptr->x+wx,pwptr->y+wy,pwptr->h,pwptr->w);
	else 	{
		if (wptr != (struct form_item*) 0)
			fprintf(h,"int px=%u,int py=%u,int ph=%d,int pw=%d",wx,wy,wptr->Contents.h,wptr->Contents.w);
		else	fprintf(h,"int px=0,int py=0,int ph=0,int pw=0");
		}

	fprintf(h,",int pfg=1,int pbg=0,class_visual_font *pfontclass=(class_visual_font *)0,class_visual_container *ppere=NULL,int pfocus=1,class_visual_object *pprevious=NULL,int pmovable=1);");
	linefeed(h );	fprintf(h,"\t~class_%s();",cname);
	linefeed(h);	define_cpp_methods(h);

	if ( (Context.Form->onlinehelp & 7) ) { linefeed(h); define_cpp_help(h,cname); }

	linefeed(h );	indent(h,1);
	fprintf(h,"int %s();",_ON_CREATE);
	linefeed(h );	indent(h,1); fprintf(h,"int %s();",_ON_SHOW);
	linefeed(h );	indent(h,1); fprintf(h,"int %s();",_ON_EVENT);
	linefeed(h );	indent(h,1); fprintf(h,"int %s();",_ON_GETFOCUS);
	linefeed(h );	indent(h,1); fprintf(h,"int %s();",_ON_HIDE);
	linefeed(h );	indent(h,1); fprintf(h,"int %s();",_ON_REMOVE);
	linefeed(h );	indent(h,1); fprintf(h,"int %s();",_ON_LOSEFOCUS);
	if (cpp_member_parameters(h,99))
		{
		linefeed(h );	indent(h,1); fprintf(h,"int %s();",_ON_TRANSFERTIN);
		linefeed(h );	indent(h,1); fprintf(h,"int %s();",_ON_TRANSFERTOUT);
		linefeed(h );	indent(h,1); fprintf(h,"int %s(",_ON_INITIALISETRANSFERT);
		cpp_member_parameters(h,0);
		fprintf(h,");");
		}

	linefeed(h );	indent(h,1);
	fprintf(h,"int %s(",_ON_GERER);
	cpp_member_parameters(h,0);
	fprintf(h,");");
	linefeed(h );	indent(h,1); fprintf(h,"int %s();",_ON_EXEC);

	linefeed(h);
	define_cpp_forms_method(h,Context.Form,&wpublic,0);

	/* methodes privates */
	define_cpp_forms_method(h,Context.Form,&wprivate,1);

	fprintf(h,"}");
	linefeed(h);
	linefeed(h);
	fprintf(h,"#define public");
	linefeed(h);
	return;
}


public	void	export_cpp_page( FILE * h, char * headname )
{
	return;
}

public	void	export_cpp_form( FILE * h, char * headname )
{
	char	*		cname;


	C_Config.generate_program   = Context.Form->isprogram;
	C_Config.generate_overlay   = Context.Form->isoverlay;
	set_c_form_input( Context.Form );
	set_c_form_error( Context.Form );

	if (!( cname = Context.Form->identifier))
		cname = "visual_component";

	else if (!( *cname ))
		cname = "visual_component";


	if (!( headname ))
		export_cpp_formhead( h,cname);
	else	export_cpp_formbody( h,cname, headname);


	reset_c_form_input();
	cpp_item_name(NULL);	/* pour desallocation mémoire */
	return;
}

/* -------------------------*/
/*                          */
/* generation d'executables */
/*                          */
/* ------------------------ */

/*	------------------------	*/	
/*	c o m p i l e _ c p p () 	*/
/*	------------------------	*/	
int	compile_cpp(char *cname)
{
	int	i;
	int coder,with_path=1;
	char sv_dir[257];
	char *dir_cl,*dir_cname;
	char *cde;
	char *include,*ptr_include;
	FILE *f;
	struct	form_control * fptr;
	char *cop_cname;

	if (!( cname ))
		return(118);
	else if (!( fptr = locate_form_control(cname)))
		return(118);
	else if (!( method_is_valid(SingConf->cpp.program)))
		return(30);
	else if (!( cop_cname = allocate(strlen(cname)+4) ))
		return(27);

#ifdef WIN32
	_getcwd(sv_dir,257);
#else
	getcwd(sv_dir,257);
#endif
	if (!( dir_cname=allocate_string(cname) )) {
		liberate( cop_cname );
		return(27);
		}
	else 	fn_parser(cname,dir_cname,0x0007);

	if (!(method_is_valid(dir_cname))) {
#ifdef WIN32
		strcat(sv_dir,"\\");
#else
		strcat(sv_dir,"/");
#endif
		with_path=0;
		liberate(dir_cname);
		if (!( dir_cname=allocate_string(sv_dir) )) {
			liberate( cop_cname );
			return(27);
			}
		}

	if (!( dir_cl = allocate_string(SingConf->cpp.program) )) {
		liberate( dir_cname );
		liberate( cop_cname );
		return(27);
		}
	else 	fn_parser(SingConf->cpp.program,dir_cl,0x0007);

	if (!( cde=allocate(strlen(SingConf->cpp.program)+strlen(SingConf->cpp.path)+strlen(SingConf->cpp.options)+strlen(dir_cname)*4+strlen(cname)+70+method_is_valid(fptr->OptionsCompile)+method_is_valid(SingConf->cpp.define)))) {
		liberate( dir_cl );
		liberate( dir_cname );
		liberate( cop_cname );
		return(27);
		}
#ifdef WIN32
	fn_parser(SingConf->cpp.program,cde,0x0018);
#else
	strcpy(cde,SingConf->cpp.program);
#endif
	strcat(cde,SingConf->cpp.options);
	if (method_is_valid(fptr->OptionsCompile)) {
		strcat(cde," ");
		strcat(cde,fptr->OptionsCompile);
		}

	if (method_is_valid(SingConf->cpp.define)) {
		strcat(cde," ");
		strcat(cde,SingConf->cpp.define);
		}

	if (method_is_valid(SingConf->cpp.path)) {
		if (!( include=allocate_string(SingConf->cpp.path) )) {
			liberate( cde    );
			liberate( dir_cl );
			liberate( dir_cname );
			liberate( cop_cname );
			return(27);
			}
		ptr_include=include;
		while (strchr(ptr_include,';')) {
#ifdef WIN32
		 	strcat(cde," /I\"");
#else
		 	strcat(cde," \"-I");
#endif
			for ( i=0; *(ptr_include+i) != 0; i++ ) {
				if ( *(ptr_include+i) == ';' ) {
					*(ptr_include+i) = 0;
					break;
					}
				}
			strcat(cde,ptr_include);
			ptr_include+=strlen(ptr_include)+1;
			strcat(cde,"\"");
			}
	   
		if (strlen(ptr_include)) {
#ifdef WIN32
		 	strcat(cde," /I\"");
#else
		 	strcat(cde," \"-I");
#endif
			strcat(cde,ptr_include);
			strcat(cde,"\" ");
			}
		else	strcat(cde," ");
		}

#ifdef WIN32
	strcat(cde,"/Fo");	/* Pas de quote autour de /Fo */
	strcat(cde,dir_cname);
#endif

	strcat(cde," \"");
	if (!with_path)
		strcat(cde,dir_cname);
	strcat(cde,cname);

	strcat(cde,"\" 1> \"");
	strcat(cde,dir_cname);
	strcat(cde,"pipo1\"");
	strcat(cde," 2> \"");
	strcat(cde,dir_cname);
	strcat(cde,"pipo2\"");

#ifdef	TRACE_COMPILE
#ifdef WIN32
	if ((f = fopen("c:\\ggis.s","w")) != (FILE *) 0) {
#else
	if ((f=fopen("/home/Dev/abal32/gg/testcpp/ggis.s","w")) != (FILE *) 0) {
#endif	
		fprintf(f,"%s\n",cde);
		fclose(f);
		}
#endif
	strcpy(cop_cname,cname);
	cop_cname=enforce_extension(cop_cname,ERR_EXTENSION);

#ifdef WIN32
	_chdir(dir_cl);
	remove("vc60.idb");
	remove("vc60.pch");
	if ((coder=system(cde)) == -1)
		system_failure( cde );

	_chdir(sv_dir);
	while ((_access(cname,6)==-1) &&(errno==EACCES));
	copie_fichier("pipo1",cop_cname);
#else
	if ((coder=system(cde)) == -1)
		system_failure( cde );

	while (access(cname,R_OK | W_OK)==EACCES) usleep(1);
	copie_fichier("pipo2",cop_cname);
#endif
	FileNameConsult=cop_cname;
	if ((HMaxConsult=TailleFichier(FileNameConsult,&LMaxConsult)) != 0)
		accept_consult();
#ifdef WIN32
	coder=fichier_error("pipo1",cop_cname);
#else
	coder=fichier_error("pipo2",cop_cname);
#endif
	if ( coder ) {
		if (!( trace_model(cname) ))	
			trace_editor(cname);
		}
	liberate(dir_cl);
	liberate(cde);
	liberate(include);
	liberate(dir_cname);
	liberate( cop_cname );
	return(coder);
}

/*	------------------	*/	
/*	l i n k _ c p p () 	*/
/*	------------------	*/	
int	link_cpp(char *cname)
{
	int	i;
	int coder,with_path=1;
	char sv_dir[257];
	char *dir_link,*dir_cname;
	char *cde;
#ifdef WIN32
	char *include,*ptr_include;
#endif
	char *cop_cname;
	FILE *f;
	struct	form_item * iptr;
	char *obj_compl,*obj_path_compl;
	int lch_objects=0;
	struct	form_control * fptr = locate_form_control(cname);

#ifdef WIN32
	_getcwd(sv_dir,257);
#else
	getcwd(sv_dir,257);
#endif
	dir_cname=allocate_string(cname);
	fn_parser(cname,dir_cname,0x0007);

	if (!method_is_valid(dir_cname)) {
#ifdef WIN32
		strcat(sv_dir,"\\");
#else
		strcat(sv_dir,"/");
#endif
		with_path=0;
		liberate(dir_cname);
		dir_cname=allocate_string(sv_dir);
		}

	dir_link=allocate_string(SingConf->lpp.program);
	fn_parser(SingConf->lpp.program,dir_link,0x0007);

	/* fichier obj a linker avec */
	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if (( iptr->Contents.w  ) && ( iptr->Contents.h  ) &&
			((iptr->Contents.style & _FRAME_TYPE) == _DATA_FRAME) &&
			((iptr->Contents.align & 0x000F) == _VISUAL_FRAME) &&
			( iptr->Contents.datatype == _WIDGET_OVERLAY) &&	// pas _WIDGET_MODULE
			( method_is_valid( c_payload(iptr)))) {
			if ((obj_compl=allocate_cpp_module_description(c_payload(iptr))) != NULL) {
				obj_path_compl=relative_filename(obj_compl,dir_cname);
				lch_objects+=method_is_valid(obj_path_compl)+1;
				liberate(obj_compl);
				liberate(obj_path_compl);
				}
			}
		}

	cde=allocate(strlen(SingConf->lpp.program)+strlen(SingConf->lpp.path)+strlen(SingConf->lpp.options)+strlen(dir_cname)+strlen(cname)+350+lch_objects+method_is_valid(fptr->OptionsLinkage));
#ifdef WIN32
	fn_parser(SingConf->lpp.program,cde,0x0018);
#else
	strcpy(cde,SingConf->lpp.program);
#endif

	strcat(cde," ");
	strcat(cde,SingConf->lpp.options);

#ifdef WIN32
	include=allocate_string(SingConf->lpp.path);
	ptr_include=include;
	while (strchr(ptr_include,';')) {
		strcat(cde," /libpath:\"");
		for (i=0; *(ptr_include+i) != 0; i++ ) {
			if ( *(ptr_include +i) == ';' ) {
				*(ptr_include+i) = 0;
				break;
				}
			}
		strcat(cde,ptr_include);
		ptr_include+=strlen(ptr_include)+1;
		strcat(cde,"\"");
		}
	   
	if (strlen(ptr_include)) {
		strcat(cde," /libpath:\"");
		strcat(cde,ptr_include);
		strcat(cde,"\" ");
		}
	else	strcat(cde," ");

	strcat(cde,"/out:\"");
#else
	strcat(cde," \"");
#endif

	if (!with_path)
		strcat(cde,dir_cname);
	cop_cname=(char *)allocate(strlen(cname)+4);
#ifdef WIN32
	strcpy(cop_cname,cname);
	cop_cname=enforce_extension(cop_cname,EXE_EXTENSION);
#else
	fn_parser(cname,cop_cname,0x00F);
#endif
	strcat(cde,cop_cname);
	strcat(cde,"\" ");

	if (method_is_valid(fptr->OptionsLinkage))  {
		strcat(cde,fptr->OptionsLinkage);
		strcat(cde," ");
		}

	strcat(cde,SingConf->lpp.define);
	strcat(cde," \"");

	if (!with_path)
		strcat(cde,dir_cname);
	strcpy(cop_cname,cname);
	cop_cname=enforce_extension(cop_cname,OBJ_EXTENSION);
	strcat(cde,cop_cname);

	/* fichier obj a linker avec */
	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if (( iptr->Contents.w  ) && ( iptr->Contents.h  ) &&
			((iptr->Contents.style & _FRAME_TYPE) == _DATA_FRAME) &&
			((iptr->Contents.align & 0x000F) == _VISUAL_FRAME) &&
			( iptr->Contents.datatype == _WIDGET_OVERLAY) &&
			( method_is_valid( c_payload(iptr)))) {
			if ((obj_compl=allocate_cpp_module_description(c_payload(iptr))) != NULL) {
				obj_path_compl=relative_filename(obj_compl,dir_cname);
				strcat(cde,"\" \"");
				strcat(cde,obj_path_compl);
				liberate(obj_compl);
				liberate(obj_path_compl);
				}
			}
		}

	strcat(cde,"\" 1> \"");
	strcat(cde,dir_cname);
	strcat(cde,"pipo3\"");
	strcat(cde," 2> \"");
	strcat(cde,dir_cname);
	strcat(cde,"pipo4\"");
#ifdef	CANECASSEPAS
#ifdef WIN32
	_chdir(dir_link);
	remove("vc60.idb");
	remove("vc60.pch");
	f=fopen("c:\\ggis1.s","w");
#else
	f=fopen("/home/Dev/abal32/gg/testcpp/ggis1.s","w");
#endif
	fprintf(f,"%s\n",cde);
	fclose(f);
#endif

	printf("cppexec: %s\n",cde);
	if ((coder=system(cde)) == -1)
		system_failure( cde );

#ifdef WIN32
	_chdir(sv_dir);
	while ((_access(cop_cname,6)==-1) &&(errno==EACCES));
#else
	while (access(cop_cname,R_OK | W_OK)==EACCES) usleep(1);
#endif

	liberate(cop_cname);
	liberate(cde);
	liberate(dir_link);
#ifdef WIN32
	liberate(include);
#endif
	liberate(dir_cname);
	return(0);
}

/* -------------------------*/
/*                          */
/* generation de librairies */
/*                          */
/* ------------------------ */
int	compile_dll_cpp(char *cname)
{
	int	i;
	int coder,with_path=1;
	char sv_dir[257];
	char *dir_cl,*dir_cname;
	char *cde;
	char *include,*ptr_include;
FILE *f;
	struct	form_control * fptr = locate_form_control(cname);

#ifdef WIN32
	_getcwd(sv_dir,257);
#else
	getcwd(sv_dir,257);
#endif
	dir_cname=allocate_string(cname);
	fn_parser(cname,dir_cname,0x0007);

	if (!method_is_valid(dir_cname)) {
#ifdef WIN32
		strcat(sv_dir,"\\");
#else
		strcat(sv_dir,"/");
#endif
		with_path=0;
		liberate(dir_cname);
		dir_cname=allocate_string(sv_dir);
		}


	dir_cl=allocate_string(SingConf->dll_cpp.program);
	fn_parser(SingConf->dll_cpp.program,dir_cl,0x0007);

	cde=allocate(strlen(SingConf->dll_cpp.program)+strlen(SingConf->dll_cpp.path)+strlen(SingConf->dll_cpp.options)+strlen(dir_cname)*3+strlen(cname)+70+method_is_valid(fptr->OptionsCompile)+method_is_valid(SingConf->dll_cpp.define));
#ifdef WIN32
	fn_parser(SingConf->dll_cpp.program,cde,0x0018);
#else
	strcpy(cde,SingConf->dll_cpp.program);
#endif

	strcat(cde," ");
	strcat(cde,SingConf->dll_cpp.options);

	if (method_is_valid(fptr->OptionsCompile))  {
		strcat(cde," ");
		strcat(cde,fptr->OptionsCompile);
		}

	if (method_is_valid(SingConf->dll_cpp.define)) {
		strcat(cde," ");
		strcat(cde,SingConf->dll_cpp.define);
		}

	include=allocate_string(SingConf->dll_cpp.path);
	ptr_include=include;
	while (strchr(ptr_include,';')) {
#ifdef WIN32
		strcat(cde," /I\"");
#else
		strcat(cde," \"-I");
#endif
		for ( i=0; *(ptr_include+i) != 0; i++ ) {
			if ( *(ptr_include+i) == ';' ) {
				*(ptr_include+i) = 0;
			break;
			}
		}
		strcat(cde,ptr_include);
		ptr_include+=strlen(ptr_include)+1;	
		strcat(cde,"\"");
		}
	   
	if (strlen(ptr_include)) {
#ifdef WIN32
		strcat(cde," /I\"");
#else
		strcat(cde," \"-I");
#endif
		strcat(cde,ptr_include);
		strcat(cde,"\" ");
		}
	else	strcat(cde," ");

#ifdef WIN32
	strcat(cde,"/Fo");	/* Pas de quote autour de /Fo */
	strcat(cde,dir_cname);
	strcat(cde," \"");
#else
	strcat(cde,"\"");
#endif

	if (!with_path)
		strcat(cde,dir_cname);
	strcat(cde,cname);
	strcat(cde,"\" 1> \"");
	strcat(cde,dir_cname);
	strcat(cde,"pipo1\"");
	strcat(cde," 2> \"");
	strcat(cde,dir_cname);
	strcat(cde,"pipo2\"");
#ifdef	CANECASSEPAS
#ifdef WIN32
	_chdir(dir_cl);
	remove("vc60.idb");
	remove("vc60.pch");
	f=fopen("c:\\ggis.s","w");
#else
	f=fopen("/home/Dev/abal32/gg/testcpp/ggis.s","w");
#endif
	fprintf(f,"%s\n",cde);
	fclose(f);
#endif
	printf("cppexec: %s\n",cde);
	if ((coder=system(cde)) == -1)
		system_failure( cde );


#ifdef WIN32
	_chdir(sv_dir);
	while ((_access(cname,6)==-1) &&(errno==EACCES));
#else
	while (access(cname,R_OK | W_OK)==EACCES) usleep(1);
#endif

	liberate(dir_cl);
	liberate(cde);
	liberate(include);
	liberate(dir_cname);
	return(0);
}
	
int	link_dll_cpp(char *cname)
{
	int coder,with_path=1;
	char sv_dir[257];
	char *dir_link,*dir_cname;
	char *cde;
	char *include,*ptr_include;
	char *cop_cname;
	FILE *f;
	struct	form_control * fptr = locate_form_control(cname);

#ifdef WIN32
	_getcwd(sv_dir,257);
#else
	getcwd(sv_dir,257);
#endif
	dir_cname=allocate_string(cname);
	fn_parser(cname,dir_cname,0x0007);

	if (!method_is_valid(dir_cname)) {
#ifdef WIN32
		strcat(sv_dir,"\\");
#else
		strcat(sv_dir,"/");
#endif
		with_path=0;
		liberate(dir_cname);
		dir_cname=allocate_string(sv_dir);
		}

	dir_link=allocate_string(SingConf->dll_lpp.program);
	fn_parser(SingConf->dll_lpp.program,dir_link,0x0007);
	cde=allocate(strlen(SingConf->dll_lpp.program)+strlen(SingConf->dll_lpp.path)+strlen(SingConf->dll_lpp.options)+strlen(dir_cname)*2+strlen(cname)*2+350+method_is_valid(fptr->OptionsLinkage));
#ifdef WIN32
	fn_parser(SingConf->dll_lpp.program,cde,0x0018);
#else
	strcpy(cde,SingConf->dll_lpp.program);
#endif

	strcat(cde," ");
	strcat(cde,SingConf->dll_lpp.options);

	if (method_is_valid(fptr->OptionsLinkage)) {
		strcat(cde," ");
		strcat(cde,fptr->OptionsLinkage);
		}

#ifdef WIN32
	include=allocate_string(SingConf->dll_lpp.path);
	ptr_include=include;
	while (strchr(ptr_include,';')) {
		strcat(cde," /libpath:\"");
		for ( i=0; *(ptr_include+i) != 0; i++ ) {
			if ( *(ptr_include+i) == ';' ) {
				*(ptr_include+i) = 0;
				break;
				}
			}
		strcat(cde,ptr_include);
		ptr_include+=strlen(ptr_include)+1;
		strcat(cde,"\"");
		}
	   
	if (strlen(ptr_include)) {
		strcat(cde," /libpath:\"");
		strcat(cde,ptr_include);
		strcat(cde,"\" ");
		}
	else	strcat(cde," ");

	strcat(cde,"/out:\"");
	if (!with_path)	
		strcat(cde,dir_cname);
	cop_cname=(char *)allocate(strlen(cname)+4);
	strcpy(cop_cname,cname);
	cop_cname=enforce_extension(cop_cname,".dll");
	strcat(cde,cop_cname);
	strcat(cde,"\" ");
	strcat(cde,"/implib:\"");
#else
	strcat(cde," \"");
#endif

	if (!with_path)
		strcat(cde,dir_cname);
	cop_cname=(char *)allocate(strlen(cname)+4);
	strcpy(cop_cname,cname);
#ifdef WIN32
	cop_cname=enforce_extension(cop_cname,".lib");
#else
	cop_cname=enforce_extension(cop_cname,".so");
#endif
	strcat(cde,cop_cname);
	strcat(cde,"\" ");

	strcat(cde,SingConf->dll_lpp.define);

	strcat(cde," \"");
	if (!with_path)
		strcat(cde,dir_cname);
	cop_cname=enforce_extension(cop_cname,OBJ_EXTENSION);
	strcat(cde,cop_cname);

	strcat(cde,"\" 1> \"");
	strcat(cde,dir_cname);
	strcat(cde,"pipo3\"");
	strcat(cde," 2> \"");
	strcat(cde,dir_cname);
	strcat(cde,"pipo4\"");

#ifdef	CANECASSEPAS
#ifdef WIN32
_chdir(dir_link);
	remove("vc60.idb");
	remove("vc60.pch");
	f=fopen("c:\\ggis1.s","w");
#else
	f=fopen("/home/Dev/abal32/gg/testcpp/ggis1.s","w");
#endif
	fprintf(f,"%s\n",cde);
	fclose(f);
#endif
	printf("cppexec: %s\n",cde);
	if ((coder=system(cde)) == -1)
		system_failure( cde );


#ifdef WIN32
	_chdir(sv_dir);
	while ((_access(cop_cname,6)==-1) &&(errno==EACCES));
#else
	while (access(cop_cname,R_OK | W_OK)==EACCES) usleep(1);
#endif

	liberate(cop_cname);
	liberate(cde);
	liberate(dir_link);
#ifdef WIN32
	liberate(include);
#endif
	liberate(dir_cname);
	return(0);
}



public	int	run_library( char * nomfic )
{
	return(0);
}

private int	copie_fichier(char *nfo,char *nfd)
{
	FILE *fo,*fd;
	char l[1024];

	if ((fo=fopen(nfo,"r"))==NULL) 
		return(0);
	if ((fd=fopen(nfd,"w"))==NULL) {
		fclose(fo);
		return(0);
		}
	while (fgets(l,255,fo))
		fputs(l,fd);

	fclose(fo);
	fclose(fd);
	return(0);
}


/* -------------------------------------- */
/* adapte le fichier erreurs pour edition */
/* -------------------------------------- */
private int fichier_error(char *nfo,char *nfd)
{
	FILE *fo,*fd;
	char l[1024];
	int necr=0;

	if ((fo=fopen(nfo,"r"))==NULL) return(0);
	if ((fd=fopen(nfd,"w"))==NULL) {
		fclose(fo);
		return(0);
		}
	while (fgets(l,255,fo)) {
		if (index_string(l,"error")) {
			fputs_formate(l,fd);
			necr++;
			}
		}
	fclose(fo);
	fclose(fd);
	return(necr);
}


private void fputs_formate(char *l,FILE *fd)
{
	char *ptrl=l;
#ifdef WIN32
	/* les lignes sont de la forme : "nomfic(ligne) : libelle" */
	/* on veut                       "nomfic ligne  1 libelle" */
	/* pour etre compatible avec le fichier d'erreurs ABAL     */
	if (ptrl=strchr(ptrl,'(')) ptrl[0]=' ';
	if (ptrl=strchr(ptrl,')')) ptrl[0]=' ';
	if (ptrl=strchr(ptrl,':')) ptrl[0]='1';
#else
	/* les lignes sont de la forme : "nomfic:ligne: libelle" */
	/* on veut                       "nomfic ligne  1 libelle" */
	/* pour etre compatible avec le fichier d'erreurs ABAL     */
	if (ptrl=strchr(ptrl,':')) ptrl[0]=' ';
	if (ptrl=strchr(ptrl,':')) ptrl[0]=' ';
#endif
	fputs(l,fd);
}

private char *index_string(char *o,char *s)
{
	char *ptro=o;

	while (ptro=strchr(ptro,s[0])) {
		if (!strncmp(ptro,s,strlen(s))) 
			return(ptro);
		ptro++;
		}
	return((char *)0);
}

private int TailleFichier(char *cname,int *LMaxConsult)
{
	int nl,nc;
	FILE *f;
	char l[1024];

	*LMaxConsult=0;
	nl=0;
	if ((f=fopen(cname,"r")) != (FILE *)0) {
		while (fgets(l,255,f)) {
			nl++;
			nc=strlen(l)-1;
			if (nc>*LMaxConsult) *LMaxConsult=nc;
			}
		fclose(f);
		}
	return(nl);
}


