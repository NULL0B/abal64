#ifndef	_singagent_c
#define	_singagent_c

#include "abaltype.h"
#include "abalterm.h"
#include "singmemb.h"
#include "singmeth.h"
#include "singabal.h"

#ifdef	WIN32
#define	_DYNAMIC_IMAGE_PATH "c:\\temp\\"
#else
#define	_DYNAMIC_IMAGE_PATH "/tmp/"
#endif

#define	__QUOTE			0x0022
#define	__PERCENT		0x0025
#define	__ArgV			"ArgV"
#define	__ARGV			"ARGV"
#define	__SessionImage		"SessionImage"
#define	__FocusItem		"FocusItem"
#define	__FocusItems		"FocusItems"
#define	__PageNumber		"PageNumber"
#define	__ResponseFile		"ResponseFile"
#define	__ClientRedirect	"ClientRedirect"
#define	__NatLang		"NatLang"
#define	__WebClassLibrary	"web"
#define	__FilesClassLibrary	"files"
#define	__FireWallClassName	"web_server_firewall"
#define	__FireWallFileName	"wasp_firewall_filename"
#define	__FireWallDiskFile 	"FWFN.FileName"

#define	_CALL_ABORT	0
#define	_CALL_NESTED	1
#define	_CALL_CHAINED	2

struct form_control * locate_form_control( char * );
private	void	web_agent_set_lang( h );

/*	----------------------------------------------------------------------		*/
/*	This source is concerned with the generation fo Web Application Agents 		*/
/*	for distributed abal applications over the internet				*/
/*	----------------------------------------------------------------------		*/
static	char	*	WebAgent=(char *) 0;
static	int		DebugAgent=0;

private	void	web_agent_comment( FILE * h, char * mptr, int i )
{
	char	*	sptr;

	indent(h,i); fprintf(h,";** ");
	for (sptr=mptr; *sptr!= 0; sptr++ )
		fprintf(h,"--");
	linefeed(h);
	indent(h,i); fprintf(h,";** ");
	for (sptr=mptr; *sptr!= 0; sptr++ )
		fprintf(h,"%c ",*sptr);
	linefeed(h);
	indent(h,i); fprintf(h,";** ");
	for (sptr=mptr; *sptr!= 0; sptr++ )
		fprintf(h,"--");
	linefeed(h);
	return;
}

private	void	web_agent_use_page(FILE * h)
{
	indent(h,1); 	fprintf(h,"if ( PageHandle <> 0 )");			linefeed(h);
	indent(h,2); 	fprintf(h,"Status=%s(PageHandle)",__abal_visual_page); 	linefeed(h);
	indent(h,1); 	fprintf(h,"Endif");					linefeed(h);
	return;
}

private	void	web_agent_release_page(FILE * h)
{
	indent(h,1); 	fprintf(h,"if ( PageHandle <> 0 )");		linefeed(h);
	indent(h,2); 	fprintf(h,"Status=%s(0)",__abal_visual_page); 	linefeed(h);
	indent(h,1); 	fprintf(h,"Endif");				linefeed(h);
	return;
}

private	void	web_agent_drop_page(FILE * h)
{
	indent(h,1); 	fprintf(h,"if ( PageHandle <> 0 )");			linefeed(h);
	indent(h,2);	fprintf(h,"Status=%s(PageHandle)",__abal_visual_drop);	linefeed(h);
	indent(h,1); 	fprintf(h,"Endif");					linefeed(h);
	return;
}

private	void	web_agent_allocate_page(FILE * h,struct form_control * fptr)
{
	struct window_control Window;
	form_Dimensions( &Window, fptr);
	indent(h,1);	fprintf(h,"PageHandle=%s(%u,%u)",__abal_visual_buffer,Window.w,Window.h);
	linefeed(h);
	return;
}

private	void	web_agent_signature( FILE * h, char * nptr, int mode )
{
	switch ( mode ) {
		case	-1:
			fprintf(h,"proc %s() : %c",nptr,__PERCENT);
			break;
		case	0 :	
			fprintf(h,"proc %s(ptr o$=10) : %c",nptr,__PERCENT);
			break;
		case	1 :	
			fprintf(h,"proc %s(ptr o$=10,handle%c,ptr url$,ulen%c,identity$=64) : %c",
				nptr,__PERCENT,__PERCENT,__PERCENT);
			break;
		case	2 :	
			fprintf(h,"proc %s(ptr o$=10,ptr url$,ulen%c) : %c",
				nptr,__PERCENT,__PERCENT);
			break;
		case	3	:
			fprintf(h,"proc %s(ptr o$=10,item%c,ptr v$,vlen%c) : %c",
				nptr,__PERCENT,__PERCENT,__PERCENT);
			break;
		case	4	:
			fprintf(h,"proc %s(ptr o$=10,item%c,ptr v$,vlen%c) : $",
				nptr,__PERCENT,__PERCENT);
			break;
		}

	return;
}

private	void	web_agent_prototype( FILE * h, char * nptr,int mode )
{
	fprintf(h,"forward ");
	web_agent_signature(h,nptr,mode);
	return;
}

private	void	web_agent_method( FILE * h, char * nptr, int mode )
{
	web_agent_comment(h,nptr,0);
	linefeed(h);
	web_agent_signature(h,nptr,mode);
	linefeed(h);
	abal_error_trap(h,1,1);
	linefeed(h);

	if ( DebugAgent ) {
		indent(h,1);
		fprintf(h,"Status=VisualControl(999,%c%s%c,Len$(%c%s%c))",__QUOTE,nptr,__QUOTE,__QUOTE,nptr,__QUOTE);
		linefeed(h);
		}

	switch ( mode ) {
		case	1 :
		case	2 :
			indent(h,1); 
			fprintf(h,"Alter url(ulen)"); 				
			linefeed(h);
			break;
		case	3 :
		case	4 :
			indent(h,1); 
			fprintf(h,"Alter v(vlen)"); 				
			linefeed(h);
			break;
		}
	return;
}

private	void	web_agent_page_number( FILE * h, struct form_item * iptr, int margin )
{
	indent(h,margin); 
	fprintf(h,"PageNumber = %u",iptr->Contents.page);
	linefeed(h);
	return;
}

private	void	web_agent_event_focus( FILE * h, struct form_item * iptr, int margin )
{
	/* scan forward to next focus item */
	/* ------------------------------- */
	while ((!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS ))
	||     (!(  iptr->Contents.focus )))
		if (!(iptr = iptr->next ))
			return;

	indent(h,margin);
	fprintf(h,"LastFocus=FocusItem :: ");
	fprintf(h,"FocusItem=%u",iptr->Contents.focus);
	linefeed(h);
	return;
}

private	void	web_agent_endmethod( FILE * h )
{
	linefeed(h);
	abal_return(h,"0",1);
	abal_error_abort(h,1,1);
	abal_throw(h,"Status",1);
	abal_endproc(h);
	linefeed(h);
}

private	void	web_agent_normal( FILE * h )
{
	indent(h,1);	fprintf(h,"ClientRedirect=%u",_CALL_ABORT);
	linefeed(h);
	return;
}

private	void	web_agent_nested( FILE * h )
{
	indent(h,1);	fprintf(h,"ClientRedirect=%u",_CALL_NESTED);	
	linefeed(h);
	return;
}

private	void	web_agent_chained( FILE * h )
{
	indent(h,1);	fprintf(h,"ClientRedirect=%u",_CALL_CHAINED);	
	linefeed(h);
	return;
}


/*	------------------------------------------------------------------------	*/
/*	w e b _ a g e n t _ m o d u l e _ t r i g g e r ( handle, form, widget )	*/
/*	------------------------------------------------------------------------	*/
/*	This method is invoked from "abal_module_trigger" upon detection of a		*/
/*	modular push button declared as a module activation trigger .			*/
/*	------------------------------------------------------------------------	*/
public	void	web_agent_hyperlink_trigger( FILE * h, struct form_control * fptr, struct form_item * iptr )
{
	return;
}

private	void	redirect_agent_response(FILE * h, struct form_item * iptr, int margin )
{
	char	*	sptr;
	indent(h,margin);
	if (!( method_is_valid( (sptr = iptr->Contents.format ) ) )) {
		fprintf(h,"LineBuffer = %c %c",__QUOTE,__QUOTE);
		}
	else if ( *sptr != _UNQUOTED_STRING )	{
		if ( *sptr != '/' ) {
			fprintf(h,"LineBuffer = Print(($,$,$),Parse(ResponseFile,7),Parse(%c%s%c,8),Parse(ResponseFile,16))",__QUOTE,sptr,__QUOTE);
			}
		else	{
			fprintf(h,"if ( Len$(Parse(%c%s%c,16)) <> 0)",__QUOTE,sptr,__QUOTE);
			linefeed(h);
				indent(h,margin+1);
				fprintf(h,"LineBuffer = %c%s%c",__QUOTE,sptr,__QUOTE);
				linefeed(h);
			indent(h,margin);
			fprintf(h,"Else :: LineBuffer = Print(($,$),Parse(%c%s%c,/000F),%c.htm%c)",__QUOTE,sptr,__QUOTE,__QUOTE,__QUOTE);
			linefeed(h);
			indent(h,margin);
			fprintf(h,"Endif");
			}
		}
	else	{
		fprintf(h,"if ( Index("); variable_value(h,(sptr+1)); fprintf(h,",%c/%c) = 1)",__QUOTE,__QUOTE);
		linefeed(h);
		indent(h,margin+1);
			fprintf(h,"if ( Len$(Parse(");
				variable_value(h,(sptr+1));
				fprintf(h,",16)) <> 0)",__QUOTE,sptr,__QUOTE);
				linefeed(h);
			indent(h,margin+1);
				fprintf(h,"LineBuffer = "); variable_value(h,(sptr+1));
				linefeed(h);
			indent(h,margin);
			fprintf(h,"Else :: LineBuffer = Print(($,$),Parse(");
				variable_value(h,(sptr+1));
			fprintf(h,",/000F),%c.htm%c)",__QUOTE,__QUOTE);
			linefeed(h);
			indent(h,margin);
			fprintf(h,"Endif");
		indent(h,margin);
		fprintf(h,"Else :: LineBuffer = Print(($,$,$),Parse(ResponseFile,7),Parse(");
			variable_value(h,(sptr+1));
			fprintf(h,",8),Parse(ResponseFile,16))");
			linefeed(h);
		indent(h,margin);
		fprintf(h,"Endif");
		}
	linefeed(h);
	return;
}

public	void	web_agent_module_trigger( FILE * h, struct form_control * fptr, struct form_item * iptr )
{
	struct	form_control * mptr;
	struct	form_item * wptr;
	
	/* Detect module control already generated */
	/* --------------------------------------- */
	if ( add_module_control(iptr->Contents.format) != 0) {

		web_agent_comment(h,iptr->Contents.format,0);

		if (!( mptr = locate_form_control( iptr->Contents.format ) )) {
			web_agent_method(h,iptr->Contents.format,-1);
			}
		else	{
			linefeed(h);
			fprintf(h,"proc %s(",iptr->Contents.format);
			construction_parameters(h,mptr, 0 );
			fprintf(h,") : %c",__PERCENT);
			linefeed(h);
			abal_error_trap(h,1,1);
			linefeed(h);
			}
		if ( fptr->pages ) {
			indent(h,1);	fprintf(h,"ResponseFile = LineBuffer");
			linefeed(h);
			}
		redirect_agent_response( h, iptr, 1 );
		indent(h,1);	fprintf(h,"ResponseFile = LineBuffer");
		linefeed(h);
		indent(h,1);	fprintf(h,"CommandLine=%c %c",__QUOTE,__QUOTE);
		linefeed(h);
		if ( mptr ) {
			for (	wptr=mptr->first;
			wptr != (struct form_item *) 0;
			wptr = wptr->next ) {
			if (!( wptr->Contents.interfaceitem ))
				continue;
			else	{
	
				switch ( wptr->Contents.datatype ) {
					case	_WIDGET_STRING		:
						indent(h,1);	
						fprintf(h,"Alter p_%s(pl%s)",wptr->Contents.name,wptr->Contents.name);
						linefeed(h);
					case	_WIDGET_KONSTANT	:
						indent(h,1);	
						fprintf(h,"LineBuffer = Print((%c%s=%c,$),p_%s)",__QUOTE,wptr->Contents.name,__QUOTE,wptr->Contents.name);
						linefeed(h);
						break;
					case	_WIDGET_WORD		:
					case	_WIDGET_BYTE		:
					case	_WIDGET_LONG		:
					case	_WIDGET_FLOAT		:
					case	_WIDGET_NUMERIC		:
						indent(h,1);	
						fprintf(h,"LineBuffer = Print((%c%s=%c,$),Conv$(p_%s))",__QUOTE,wptr->Contents.name,__QUOTE,wptr->Contents.name);
						linefeed(h);
						break;
					default				:
						continue;
					}
				indent(h,1);	
				fprintf(h,"if ( Len$(CommandLine) = 0 )");
				linefeed(h);
				indent(h,2);	
				fprintf(h,"CommandLine = LineBuffer");
				linefeed(h);
				indent(h,1);	
				fprintf(h,"Else :: CommandLine = Print(($,%c&%c,$),CommandLine,LineBuffer)",__QUOTE,__QUOTE);
				linefeed(h);
				indent(h,1);	
				fprintf(h,"Endif");linefeed(h);
				}
	
			}
			}
		web_agent_nested(h);
		web_agent_endmethod(h);
		}	/* add_module_control */
	abal_event_trigger( h, iptr );
	return;
}

public	void	web_agent_program_trigger( FILE * h, struct form_control * fptr, struct form_item * iptr )
{
	int	l;
	char *	eptr;
	struct	form_control * mptr;
	web_agent_comment(h,iptr->Contents.format,0);
	linefeed(h);
	fprintf(h,"proc %s%s(ptr o$=10) : %c ",
		iptr->Contents.name,__abal_method_event,
		__PERCENT);
	linefeed(h);
	abal_error_trap(h,1,1);
	linefeed(h);

	if ((l = method_is_valid((eptr = iptr->Contents.events->on_event))) != 0) {
		abal_pragma_enter(h,iptr->Contents.name,__abal_method_event);
		abal_method_body(h,eptr,l,iptr->Contents.name,1);
		abal_pragma_leave(h,iptr->Contents.name,__abal_method_event);
		}

	if ( fptr->pages ) {
		indent(h,1);	fprintf(h,"ResponseFile = LineBuffer");
		linefeed(h);
		}
	redirect_agent_response( h, iptr, 1 );
	indent(h,1);	fprintf(h,"ResponseFile = LineBuffer");
	linefeed(h);
	indent(h,1);
	fprintf(h,"if ( Len$(b_%s) > 0 ) :: CommandLine=Print((%c%s=%c,$),b_%s) :: Else :: CommandLine = %c %c :: Endif",
		iptr->Contents.name,__QUOTE,__ArgV,__QUOTE,iptr->Contents.name,__QUOTE,__QUOTE);
	linefeed(h);

	/* ----------------------------------------------- */
	/* Determine call type : chained or nested or none */
	/* ----------------------------------------------- */
	switch ( iptr->Contents.datatype ) {
		case	_WIDGET_CHAIN	:
			web_agent_chained(h);
			break;

		case	_WIDGET_LOADGO	:
		case	_WIDGET_MODULE	:
		case	_WIDGET_OVERLAY	:
			web_agent_nested(h);
			break;
		default			:
			web_agent_normal(h);
			break;
		}
	web_agent_endmethod(h);
	return;
}

/*	--------------------------------------------------	*/
/*	w e b _ a g e n t _ s t a r t u p ( handle, form )	*/
/*	--------------------------------------------------	*/
private	void	web_agent_startup( FILE * h, struct form_control * fptr )
{
	web_agent_comment(h,"W E B  A G E N T  S O U R C E",0);

	reset_abal_config();

	set_abal_config_name("On");
	set_abal_config_overlay(1);
	set_abal_config_program(1);

	fptr->abal.flags |= 16;		/* ignore case off */
	fptr->abal.flags |= 64;		/* use token size  */
	fptr->abal.tokensize = 64;

	abal_pragmas( h, fptr );

	abal_user(h,"visual.def");
	abal_user(h,"bdanet.def");

	abal_define(h,"SING_WEB_AGENT",fptr->identifier);

	abal_visual_dependance(h,Context.Form);

	if ( Context.Form->dependance)
		abal_dependance(h,Context.Form->dependance,0);


	if (!( ActiveAgentImages )) {
		/* do not need web classes */
		/* ----------------------- */
		fprintf(h,"#use %s",__FilesClassLibrary);
		linefeed(h);
		}
	else	{
		/* needs web classes for firewall description */
		/* ------------------------------------------ */
		fprintf(h,"#use %s",__WebClassLibrary);
		linefeed(h);
		}


	abal_program(h,fptr->identifier);

	abal_include(h,"mimo.as");
	abal_include(h,"visidef.as");

	abal_widget_constants(h, fptr);

	if ( Context.Form->dependance)
		abal_dependance(h,Context.Form->dependance,1);

	web_agent_prototype(h,"PreConstruction",0);	linefeed(h);
	web_agent_prototype(h,"PostDestruction",0);	linefeed(h);
	web_agent_prototype(h,"OnCreate",2);		linefeed(h);
	web_agent_prototype(h,"OnShow",0);		linefeed(h);
	web_agent_prototype(h,"OnFocus",0);		linefeed(h);
	web_agent_prototype(h,"OnEvent",0);		linefeed(h);
	web_agent_prototype(h,"OnLosefocus",0);		linefeed(h);
	web_agent_prototype(h,"OnHide",0);		linefeed(h);
	web_agent_prototype(h,"OnRemove",0);		linefeed(h);
	web_agent_prototype(h,"OnRequest",1);		linefeed(h);
	web_agent_prototype(h,"OnResponse",0);		linefeed(h);
	web_agent_prototype(h,"OnRedirect",2);		linefeed(h);
	abal_forms_method_forward(h,fptr,1);
	abal_forms_method_forward(h,fptr,2);
	abal_forward_methods(h,fptr);
	abal_extern_methods(h,fptr);
	web_agent_prototype(h,"SelectCheck",3);		linefeed(h);
	web_agent_prototype(h,"SelectValue",4);		linefeed(h);
	abal_argv_control( h, fptr );

	if ( Context.Form->dependance) {
		abal_dependance(h,Context.Form->dependance,2);
		}
	abal_include(h,"arg.as");
	abal_include(h,"cleaner.as");
	return;
}

/*	----------------------------------------------------	*/
/*	w e b _ a g e n t _ i n s t a n c e ( handle, form )	*/
/*	----------------------------------------------------	*/
private	void	web_agent_instance( FILE * h, struct form_control * fptr )
{
	int	members;
	web_agent_comment(h,"Instance Container",0);
	web_agent_comment(h,"agent specific",0);
	abal_dcl(h,"Page","Handle",_ABAL_WORD,0,0,0,NULL);
	abal_dcl(h,"Is","Visible",_ABAL_WORD,0,0,0,NULL);

	abal_dcl(h,"Client","Socket",_ABAL_WORD,2,0,0,NULL);
	abal_dcl(h,"Client","Cookie",_ABAL_STRING,32,0,0,NULL);
	abal_dcl(h,"Client","Address",_ABAL_STRING,64,0,0,NULL);
	abal_dcl(h,"Client","Redirect",_ABAL_WORD,2,0,0,NULL);

	abal_dcl(h,"Command","Line",_ABAL_STRING,1024,0,0,NULL);
	abal_dcl(h,"Response","File",_ABAL_STRING,1024,0,0,NULL);
	abal_dcl(h,"Name","Token",_ABAL_STRING,256,0,0,NULL);
	abal_dcl(h,"Table","Dimension",_ABAL_STRING,256,0,0,NULL);
	abal_dcl(h,"Column","Dimension",_ABAL_WORD,2,0,0,NULL);
	abal_dcl(h,"Row","Dimension",_ABAL_WORD,2,0,0,NULL);
	abal_dcl(h,"Value","Token",_ABAL_STRING,8192,0,0,NULL);
	abal_dcl(h,"Value","Word",_ABAL_WORD,8192,0,0,NULL);
	abal_dcl(h,"Value","Long",_ABAL_LONG,8192,0,0,NULL);
	abal_dcl(h,"Value","Byte",_ABAL_BYTE,8192,0,0,NULL);
	abal_dcl(h,"Work","Buffer",_ABAL_STRING,2048,0,0,NULL);
	abal_dcl(h,"Line","Buffer",_ABAL_STRING,2048,0,0,NULL);
	web_agent_comment(h,"widget specific",0);
	members = generate_abal_structure(h,fptr);
	return;
}

private	void	web_agent_wipe_value( FILE * h, int margin )
{
	indent(h,margin); 
	fprintf(h,"While(Index(ValueToken,%c+%c)<>0)::ValueToken=Includ(Index(ValueToken,%c+%c),%c %c)::Wend",
			__QUOTE, __QUOTE, 	__QUOTE, __QUOTE, 	__QUOTE, __QUOTE);
	linefeed(h);
	return;
}

static	int	NewVersion=1;
private	web_remove_token( FILE * h, int i, char * rptr, char * sptr, char * wptr )
{
	if ( NewVersion ) {
		indent(h,i); 
		fprintf(h,"%s = Tokenise(%s,%c%s%c)",rptr,sptr,__QUOTE,wptr,__QUOTE); 
		linefeed(h);
		}
	else	{
		indent(h,3); fprintf(h,"i = Index(%s,%c%s%c)",sptr,__QUOTE,wptr,__QUOTE);linefeed(h);
		indent(h,3); fprintf(h,"Select i");					linefeed(h);
		indent(h,3); fprintf(h,"Case   0");					linefeed(h);
			indent(h,4); fprintf(h,"%s = %s",rptr,sptr);			linefeed(h);
			indent(h,4); fprintf(h,"%s = %c %c",sptr,__QUOTE,__QUOTE);	linefeed(h);
		indent(h,3); fprintf(h,"Case   1");					linefeed(h);
			indent(h,4); fprintf(h,"%s = %c %c",rptr,__QUOTE,__QUOTE);	linefeed(h);
			indent(h,4); fprintf(h,"%s=Includ(1,Space(i))",sptr); 		linefeed(h);
			indent(h,4); fprintf(h,"%s=Shl(%s)",sptr,sptr); 		linefeed(h);
		indent(h,3); fprintf(h,"Default ");					linefeed(h);
			indent(h,4); fprintf(h,"%s = Left(%s,(i-1))",rptr,sptr);	linefeed(h);
			indent(h,4); fprintf(h,"%s=Includ(1,Space(i))",sptr); 		linefeed(h);
			indent(h,4); fprintf(h,"%s=Shl(%s)",sptr,sptr); 		linefeed(h);
		indent(h,3); fprintf(h,"EndSel");					linefeed(h);
		}
	return;
}

/*	----------------------------------------------------	*/
/*	w e b _ a g e n t _ o n c r e a t e ( handle, form )	*/
/*	----------------------------------------------------	*/
private	void	web_agent_oncreate( FILE * h, struct form_control * fptr )
{
	abal_oncreate_methods( h, fptr );

	web_agent_method(h,"PreConstruction",0);linefeed(h);
		web_agent_endmethod(h);			

	web_agent_method(h,"OnCreate",2);		linefeed(h);
		abal_dcl(h,"\0","i",_ABAL_WORD,2,0,0,NULL);
		abal_init_global(h);
		web_agent_normal(h);
		abal_visual_startup(h,0,fptr->resizeauto);
		abal_form_style(h,fptr,0);
		indent(h,1); fprintf(h,"For i=1 to ArgC :: ArgV(i) = %c %c :: Next i",__QUOTE,__QUOTE);	linefeed(h);
		abal_initialise_national_language(h,fptr);
		indent(h,1); fprintf(h,"LineBuffer = url");					linefeed(h);
		indent(h,1); fprintf(h,"i = Index(LineBuffer,%c?%c)",__QUOTE,__QUOTE); 		linefeed(h);
		indent(h,1); fprintf(h,"if ( i > 1 ) ");			 		linefeed(h);
			indent(h,2); fprintf(h,"LineBuffer=Includ(1,Space(i))"); 		linefeed(h);
			indent(h,2); fprintf(h,"LineBuffer=Shl(LineBuffer)"); 			linefeed(h);
			indent(h,2); fprintf(h,"While (Len$(LineBuffer) <> 0)"); 		linefeed(h);
			web_remove_token(h,3,"NameToken","LineBuffer","=");
			indent(h,3); fprintf(h,"if ( Len(NameToken) = 0 ) :: Break :: Endif");		linefeed(h);
			web_remove_token(h,3,"ValueToken","LineBuffer","&");
			web_agent_wipe_value(h,3);
			indent(h,3); fprintf(h,"Select Large(NameToken)");				linefeed(h);
			indent(h,3); fprintf(h,"Case %c%s%c",__QUOTE,__ARGV,__QUOTE);		linefeed(h);
				indent(h,4); fprintf(h,"ArgB = ValueToken"); 			linefeed(h);
				indent(h,4); fprintf(h,"Main()"); 				linefeed(h);
			indent(h,3); fprintf(h,"EndSel");					linefeed(h);
			indent(h,2); fprintf(h,"Wend"); 					linefeed(h);
		indent(h,1); fprintf(h,"Endif");				 		linefeed(h);
		web_agent_allocate_page(h,fptr);
		indent(h,1); fprintf(h,"FirstPage=1"); linefeed(h);
		abal_widget_construction(h,fptr);
		indent(h,1); fprintf(h,"FocusItem=1"); linefeed(h);
		web_agent_endmethod(h);			
	return;
}

/*	----------------------------------------------------	*/
/*	w e b _ a g e n t _ o n r e m o v e ( handle, form )	*/
/*	----------------------------------------------------	*/
private	void	web_agent_onremove( FILE * h, struct form_control * fptr )
{
	abal_onremove_methods( h, fptr );

	web_agent_method(h,"OnRemove",0);		linefeed(h);
		abal_widget_destruction(h,fptr);
		web_agent_release_page(h);
		web_agent_drop_page(h);
		/* abal_visual_closure(h); */
		web_agent_endmethod(h);
			
	web_agent_method(h,"PostDestruction",0);	linefeed(h);
		web_agent_endmethod(h);			
	return;
}

/*	--------------------------------------------------	*/
/*	w e b _ a g e n t _ r e q u e s t ( handle, form )	*/
/*	--------------------------------------------------	*/
private	void	web_agent_scrollbar_show( FILE * h, struct form_item * iptr, int tabul)
{
	abal_scrollbar_widget(h,iptr,tabul,0);
	return;
}

private	void	web_agent_scroll_methods( FILE * h, struct form_control * fptr )
{
	char	mename[256];
	struct	form_item *	iptr;
	for (	iptr=fptr->first;
		iptr != (struct	form_item *) 0;
		iptr = iptr->next ) {
		if ((iptr->Contents.style  & _FRAME_TYPE) != _SCROLL_FRAME)
			continue;
		sprintf(mename,"%sUpEvent",iptr->Contents.name);
		web_agent_method(h,mename,0);	linefeed(h);
			indent(h,1);
			fprintf(h,"if ( v_%s > 1 ) :: v_%s -= 1 :: Else :: v_%s = 0 :: Endif",
				iptr->Contents.name,iptr->Contents.name,
				iptr->Contents.name,iptr->Contents.name,
				iptr->Contents.name);
			linefeed(h);
			web_agent_scrollbar_show(h,iptr,1);
			if ((( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION ))
			&&  ( method_is_valid( iptr->Contents.events->on_event ) )) {
				indent(h,1);
				fprintf(h,"%sEvent(o)",iptr->Contents.name);
				linefeed(h);
				}
			else	web_agent_event_focus(h,iptr,1);
			web_agent_endmethod(h);			

		sprintf(mename,"%sBarEvent",iptr->Contents.name);
		web_agent_method(h,mename,0);	linefeed(h);
			web_agent_scrollbar_show(h,iptr,1);
			if ((( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION ))
			&&  ( method_is_valid( iptr->Contents.events->on_event )) ) {
				indent(h,1);
				fprintf(h,"%sEvent(o)",iptr->Contents.name);
				linefeed(h);
				}
			else	web_agent_event_focus(h,iptr,1);
			web_agent_endmethod(h);			

		sprintf(mename,"%sDownEvent",iptr->Contents.name);
		web_agent_method(h,mename,0);	linefeed(h);
			indent(h,1);
			fprintf(h,"if (( v_%s + 1 + l_%s) < m_%s ) :: v_%s += 1 ",
				iptr->Contents.name,iptr->Contents.name,
				iptr->Contents.name,iptr->Contents.name,
				iptr->Contents.name);
			linefeed(h);
			fprintf(h,"Else :: if ( v_%s < (m_%s-l_%s)) :: v_%s += 1 :: Endif :: Endif",iptr->Contents.name,iptr->Contents.name,iptr->Contents.name,iptr->Contents.name);
			linefeed(h);
			web_agent_scrollbar_show(h,iptr,1);
			if ((( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION ))
			&&  ( method_is_valid( iptr->Contents.events->on_event )) ) {
				indent(h,1);
				fprintf(h,"%sEvent(o)",iptr->Contents.name);
				linefeed(h);
				}
			else	web_agent_event_focus(h,iptr,1);
			web_agent_endmethod(h);			

		}

}

private	void	ensure_windows_filename(FILE * h, char * vn)
{
	indent(h,3); fprintf(h,"if ( Conf(10) = 1) "); linefeed(h);
	indent(h,4); fprintf(h,"While(Index(%s,Chr$(/2F)) <> 0) :: %s=Includ(Index(%s,Chr$(/2F)),Chr$(/5C),1) :: Wend",vn,vn,vn); linefeed(h);
	indent(h,3); fprintf(h,"Endif"); linefeed(h);
	return;
}

private	void	ensure_url_filename(FILE * h, char * vn)
{
	indent(h,3); fprintf(h,"if ( Conf(10) = 1) "); linefeed(h);
	indent(h,4); fprintf(h,"While(Index(%s,Chr$(/5C)) <> 0) :: %s=Includ(Index(%s,Chr$(/5C)),Chr$(/2F),1) :: Wend",vn,vn,vn); linefeed(h);
	indent(h,3); fprintf(h,"Endif"); linefeed(h);
	return;
}

private	int	web_agent_component_event( FILE * h , struct form_control * fptr, char * prefix, struct form_item * wptr )
{
	int	items;
	struct	form_item * iptr;
	int	i;
	int	interf=_OVL_ONLOSE ; /* 'interface' est un mot clé sous windows ! */

	interf += abal_forms_overlay_public_method_count( fptr );

	if (( fptr->isdynamic ) &&  (!( fptr->PositionAt)))
		interf++;

	for (	items=0,iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		/* Eliminate Private Widgets */
		/* ------------------------- */			
		if (!( iptr->Contents.access & _WIDGET_PUBLIC ))
			continue;

		/* Eliminate None Storage Widgets */
		/* ------------------------------ */
		else if (!( i = is_public_widget_method( "OnEvent", iptr )) != 0) {
			interf += public_widget_method_count( iptr );
			continue;
			}
		else	{

			if ((( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION ))
			&&  ( method_is_valid(iptr->Contents.events->on_event)) ) {
				indent(h,5);
				indent(h,5); 
				overlay_widget_invocation_expression(h,wptr,interf,i);
				linefeed(h);
				}
			interf += public_widget_method_count( iptr );
			}
		}
	return(items);
}

private	int	web_agent_event_cases( FILE * h , struct form_control * fptr, char * prefix )
{
	int			items=0;
	struct	form_item * 	iptr;
	char		  *	sptr;
	struct	form_control *	vfptr;

	for (	items=0,iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		/* Test for Nested component */
		/* ------------------------- */
		if ( *prefix ) {
			/* Eliminate Private Widgets */
			/* ------------------------- */			
			if (!( iptr->Contents.access & _WIDGET_PUBLIC ))
				continue;
			}

		switch ( (iptr->Contents.style & _FRAME_TYPE) ) {

			case	_DATA_FRAME	:
				if (( iptr->Contents.align & 0x000F ) != _VISUAL_FRAME)
					continue;
				else if ( iptr->Contents.datatype != _WIDGET_OVERLAY )
					continue;
				else if (!( method_is_valid((sptr = abal_payload( iptr )) ) ))
					continue;
				else if (!( vfptr = locate_form_control( sptr ) ))
					continue;
				else	{
					items += web_agent_component_event( h, vfptr, iptr->Contents.name, iptr );
					continue; /* for now */
					}

			case	_SWITCH_FRAME	:
				indent(h,5); 
				fprintf(h,"Case %c%s.Event%c",__QUOTE,iptr->Contents.name,__QUOTE);
				linefeed(h);
				indent(h,6); 
				fprintf(h,"if ( v_%s <> 0) :: v_%s = 0 :: Else :: v_%s = 1 :: Endif",
						iptr->Contents.name,
						iptr->Contents.name,
						iptr->Contents.name);
				linefeed(h);
				if ((( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION ))
				&&  ( method_is_valid(iptr->Contents.events->on_event)) ) {
					indent(h,6);
					fprintf(h,"%sEvent()",iptr->Contents.name);
					linefeed(h);
					}
				break;

			case	_SCROLL_FRAME	:
				indent(h,5); 
				fprintf(h,"Case %c%sUp.Event%c :: %sUpEvent(o)",__QUOTE,iptr->Contents.name,__QUOTE,iptr->Contents.name);
				linefeed(h);
				indent(h,5); 
				fprintf(h,"Case %c%sBar.Event%c :: %sBarEvent(o)",__QUOTE,iptr->Contents.name,__QUOTE,iptr->Contents.name);
				linefeed(h);
				indent(h,5); 
				fprintf(h,"Case %c%sDown.Event%c :: %sDownEvent(o)",__QUOTE,iptr->Contents.name,__QUOTE,iptr->Contents.name);
				linefeed(h);
				break;

			case	_TAB_FRAME	:
				indent(h,5); 
				fprintf(h,"Case %c%s.Event%c",__QUOTE,iptr->Contents.name,__QUOTE);
				linefeed(h);
				web_agent_page_number(h,iptr,6);
				web_agent_event_focus(h,iptr,6);
				if ((( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION ))
				&&  ( method_is_valid( iptr->Contents.events->on_event )) ) {
					indent(h,6); 
					fprintf(h,"%sEvent(o)",iptr->Contents.name);
					linefeed(h);
					}
				else	{
					indent(h,6); 
					fprintf(h,"OnShow(o)");
					linefeed(h);
					}
				break;

			case	_IMAGE_FRAME	:
			case	_BUTTON_FRAME	:
				if ((( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION ))
				&& ( method_is_valid( iptr->Contents.events->on_event )) ) {
					indent(h,5); 
					fprintf(h,"Case %c%s.Event%c",__QUOTE,iptr->Contents.name,__QUOTE);
					linefeed(h);
					web_agent_event_focus(h,iptr,6);
					indent(h,6); 
					fprintf(h,"%sEvent(o)",iptr->Contents.name);
					linefeed(h);
					}
				break;
	
			}

		if ((( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION ))
		&&  ( method_is_valid( iptr->Contents.events->on_lose_focus )) ) {
			indent(h,5); 
			fprintf(h,"Case %c%s.LoseFocus%c",__QUOTE,iptr->Contents.name,__QUOTE);
			linefeed(h);
			web_agent_event_focus(h,iptr,6);
			indent(h,6); 
			fprintf(h,"%sLosefocus(o)",iptr->Contents.name);
			linefeed(h);
			}

		}

	return( items );
}

private	int	web_agent_component_set( FILE * h , struct form_control * fptr, char * prefix, struct form_item * wptr )
{
	int	items;
	struct	form_item * iptr;
	int	i;
	int	interf=_OVL_ONLOSE ; /* 'interface' est un mot clé sous windows ! */

	interf += abal_forms_overlay_public_method_count( fptr );

	if (( fptr->isdynamic ) &&  (!( fptr->PositionAt)))
		interf++;

	for (	items=0,iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		/* Eliminate Private Widgets */
		/* ------------------------- */			
		if (!( iptr->Contents.access & _WIDGET_PUBLIC ))
			continue;

		/* Eliminate None Storage Widgets */
		/* ------------------------------ */
		if (!( i = is_public_widget_method( "OnSet", iptr )) != 0) {
			interf += public_widget_method_count( iptr );
			continue;
			}
		else	{			
			/* Integer Values Need Conversion */
			/* ------------------------------ */
			switch ( (iptr->Contents.style & _FRAME_TYPE) ) {
				case	_EDIT_FRAME	:
					indent(h,4); 
					fprintf(h,"Case %c%s%s%c",__QUOTE,prefix,iptr->Contents.name,__QUOTE);
					linefeed(h);
					break;
				case	_CHECK_FRAME	:
					indent(h,4); 
					fprintf(h,"Case %c%s%s%c",__QUOTE,prefix,iptr->Contents.name,__QUOTE);
					linefeed(h);
					indent(h,5);	
					switch ( iptr->Contents.datatype ) {
						case	_ABAL_BYTE	:
							fprintf(h,"ValueByte = 1"); break;
						case	_ABAL_LONG	:
							fprintf(h,"ValueLong = 1"); break;
						case	_ABAL_WORD	:
						default			:
							fprintf(h,"ValueWord = 1"); break;
						}
					linefeed(h);
					break;
				case	_RADIO_FRAME	:
				case	_SWITCH_FRAME	:
				case	_SELECT_FRAME	:
					indent(h,4); 
					fprintf(h,"Case %c%s%s%c",__QUOTE,prefix,iptr->Contents.name,__QUOTE);
					linefeed(h);
					indent(h,5); 
					switch ( iptr->Contents.datatype ) {
						case	_ABAL_BYTE	:
							fprintf(h,"ValueByte = Conv%c(ValueToken)",__PERCENT); break;
						case	_ABAL_LONG	:
							fprintf(h,"ValueLong = Conv%c(ValueToken)",__PERCENT); break;
						case	_ABAL_WORD	:
						default			:
							fprintf(h,"ValueWord = Conv%c(ValueToken)",__PERCENT); break;
						}
					linefeed(h);
					break;
				default			:
					interf += public_widget_method_count( iptr );
					continue;
				}
			indent(h,5); 
			overlay_widget_invocation_expression(h,wptr,interf,i);
			switch ( (iptr->Contents.style & _FRAME_TYPE) ) {
				case	_EDIT_FRAME	:
					fprintf(h,"ValueToken,Len$(ValueToken))");
					linefeed(h);
					break;
				case	_CHECK_FRAME	:
				case	_RADIO_FRAME	:
				case	_SWITCH_FRAME	:
				case	_SELECT_FRAME	:
					switch ( iptr->Contents.datatype ) {
						case	_ABAL_BYTE	: fprintf(h,"ValueByte)"); break;
						case	_ABAL_LONG	: fprintf(h,"ValueLong)"); break;
						case	_ABAL_WORD	: 
						default			: fprintf(h,"ValueWord)"); break;
						}
					linefeed(h);
					break;
				}
			}

		interf += public_widget_method_count( iptr );

		}
	return(items);
}

private	int	web_agent_component_get( FILE * h , struct form_control * fptr, char * prefix, struct form_item * wptr )
{
	int	items;
	struct	form_item * iptr;
	int	i;
	int	interf=_OVL_ONLOSE ; /* 'interface' est un mot clé sous windows ! */

	interf += abal_forms_overlay_public_method_count( fptr );

	if (( fptr->isdynamic ) &&  (!( fptr->PositionAt)))
		interf++;

	for (	items=0,iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		/* Eliminate Private Widgets */
		/* ------------------------- */			
		if (!( iptr->Contents.access & _WIDGET_PUBLIC ))
			continue;

		/* Eliminate None Storage Widgets */
		/* ------------------------------ */
		if (( i = is_public_widget_method( "OnGet", iptr )) != 0) {
			switch ( (iptr->Contents.style & _FRAME_TYPE) ) {
				case	_EDIT_FRAME	:
					indent(h,4); 
					fprintf(h,"Case %c%s%s.buffer%c",__QUOTE,prefix,iptr->Contents.name,__QUOTE);
					linefeed(h);
					break;
				case	_CHECK_FRAME	:
				case	_RADIO_FRAME	:
				case	_SWITCH_FRAME	:
				case	_SELECT_FRAME	:
					indent(h,4); 
					fprintf(h,"Case %c%s%s%c",__QUOTE,prefix,iptr->Contents.name,__QUOTE);
					linefeed(h);
					break;
				default			:
					continue;
				}
			indent(h,5); 
			overlay_widget_invocation_expression(h,wptr,interf,i);
			switch ( (iptr->Contents.style & _FRAME_TYPE) ) {
				case	_EDIT_FRAME	:
					fprintf(h,"ValueToken,Len(ValueToken))");
					linefeed(h);
					break;
				case	_CHECK_FRAME	:
				case	_RADIO_FRAME	:
				case	_SWITCH_FRAME	:
				case	_SELECT_FRAME	:
					switch ( iptr->Contents.datatype ) {
						case	_ABAL_BYTE	: fprintf(h,"ValueByte)"); break;
						case	_ABAL_LONG	: fprintf(h,"ValueLong)"); break;
						case	_ABAL_WORD	: 
						default			: fprintf(h,"ValueWord)"); break;
						}
					linefeed(h);
					break;
				}
			switch ( (iptr->Contents.style & _FRAME_TYPE) ) {
				case	_EDIT_FRAME	:
					indent(h,5);
					fprintf(h,"LineBuffer = Print(($,$),LineBuffer,ValueToken)");
					linefeed(h);
					break;
				case	_CHECK_FRAME	:
				case	_RADIO_FRAME	:
				case	_SWITCH_FRAME	:
				case	_SELECT_FRAME	:
					indent(h,5);
					fprintf(h,"ValueToken = %c %c :: if ( ",__QUOTE,__QUOTE);
					switch ( iptr->Contents.datatype ) {
						case	_ABAL_BYTE	: fprintf(h,"ValueByte <> 0)"); break;
						case	_ABAL_LONG	: fprintf(h,"ValueLong <> 0)"); break;
						case	_ABAL_WORD	: 
						default			: fprintf(h,"ValueWord <> 0)"); break;
						}
					fprintf(h," :: ValueToken = %cchecked%c :: Endif",__QUOTE,__QUOTE);
					linefeed(h);
					indent(h,5);
					fprintf(h,"LineBuffer = Print(($,X,$),LineBuffer,ValueToken)");
					linefeed(h);
					break;
				}
			}

		interf += public_widget_method_count( iptr );

		}
	return(items);
}

private	int	web_agent_widget_set( FILE * h , struct form_control * fptr, char * prefix )
{
	char		  *	sptr;
	struct	form_control *	vfptr;
	int	items;
	struct	form_item * iptr;
	int	i;
	int	fields=0;
	int	fieldwidth[_MAX_FORM_FIELDS];
	int	linelength=0;
	int	nblines=0;

	for (	items=0,iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		switch ( (iptr->Contents.style & _FRAME_TYPE) ) {

			case	_DATA_FRAME	:
				if (( iptr->Contents.align & 0x000F ) != _VISUAL_FRAME)
					continue;
				else if ( iptr->Contents.datatype != _WIDGET_OVERLAY )
					continue;
				else if (!( method_is_valid((sptr = abal_payload( iptr )) ) ))
					continue;
				else if (!( vfptr = locate_form_control( sptr ) ))
					continue;
				else	{
					items += web_agent_component_set( h, vfptr, iptr->Contents.name, iptr );
					continue; /* for now */
					}

			case	_SCROLL_FRAME	:
				indent(h,4); 
				fprintf(h,"Case %c%s%c :: v_%s = Conv%c(ValueToken)",__QUOTE,iptr->Contents.name,__QUOTE,iptr->Contents.name,__PERCENT);
				linefeed(h);
				break;

			case	_SELECT_FRAME	:
				indent(h,4); 
				fprintf(h,"Case %c%s%c :: v_%s = Conv%c(ValueToken)",__QUOTE,iptr->Contents.name,__QUOTE,iptr->Contents.name,__PERCENT);
				linefeed(h);
				break;

			case	_CHECK_FRAME	:
				indent(h,4); 
				/* fprintf(h,"Case %c%s%c :: if ( Large(ValueToken) = %cON%c ) :: v_%s = 1 :: Endif",__QUOTE,iptr->Contents.name,__QUOTE,__QUOTE,__QUOTE,iptr->Contents.name); */
				fprintf(h,"Case %c%s%c :: v_%s = 1 ",__QUOTE,iptr->Contents.name,__QUOTE,iptr->Contents.name);
				linefeed(h);
				break;

			case	_RADIO_FRAME	:
				if ( iptr->Contents.radio == 1 ) {
					indent(h,4); 
					fprintf(h,"Case %c%s%c :: v_%s = Conv%c(ValueToken)",__QUOTE,iptr->Contents.name,__QUOTE,iptr->Contents.name,__PERCENT);
					linefeed(h);
					}
				break;

			case	_FORM_FRAME	:
				calculate_edit_size( &iptr->Contents );
				calculate_form_lines( iptr, &linelength, &nblines );
				fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength);
				indent(h,4); 
				fprintf(h,"Case %c%s%c :: r_%s = Alias(l_%s(RowDimension))",__QUOTE,iptr->Contents.name,__QUOTE,iptr->Contents.name,iptr->Contents.name,iptr->Contents.name);
				linefeed(h);
				indent(h,5); 
				fprintf(h,"Select ColumnDimension"); 
				linefeed(h);
				for ( i=0; i < fields; i++ ) {
					indent(h,5); 
					fprintf(h,"Case %u :: m%u_%s = ValueToken",i+1,i+1,iptr->Contents.name);
					linefeed(h);
					}
				indent(h,5); 
				fprintf(h,"EndSel"); 
				linefeed(h);
				break;

			case	_EDIT_FRAME	:

				indent(h,4); 
				calculate_edit_size( &iptr->Contents );
				calculate_form_lines( iptr, &linelength, &nblines );
				fprintf(h,"Case %c%s%c :: b_%s = ValueToken",__QUOTE,iptr->Contents.name,__QUOTE,iptr->Contents.name);
				linefeed(h);
				if ( nblines > 1 ) {
					indent(h,4);
					fprintf(h,"StringCleaner(b_%s,%u,%u)",iptr->Contents.name,linelength,nblines);
					linefeed(h);
					}
				break;
			}
		}
	return(items);
}

/*	--------------------------------------------------	*/
/*	w e b _ a g e n t _ r e q u e s t ( handle, form )	*/
/*	--------------------------------------------------	*/
private	void	web_agent_request( FILE * h, struct form_control * fptr )
{
	struct	form_item * iptr;
	int	nl=0;
	int	i;
	int	items=0;
	int	fields=0;
	int	fieldwidth[_MAX_FORM_FIELDS];
	int	linelength=0;
	int	nblines=0;

	abal_onevent_methods( h, fptr );
	web_agent_scroll_methods( h, fptr );
	web_agent_method(h,"OnRedirect",2);					linefeed(h);
	indent(h,1); fprintf(h,"if ( Len$(CommandLine) > 0 )");
	linefeed(h);
	indent(h,2); fprintf(h,"url=Print(($,%c?%c,$),ResponseFile,CommandLine)",__QUOTE,__QUOTE);
	linefeed(h);
	indent(h,1); fprintf(h,"Else :: url=ResponseFile");
	linefeed(h);
	indent(h,1); fprintf(h,"Endif");
	linefeed(h);
	web_agent_endmethod(h);

	web_agent_method(h,"OnRequest",1);					linefeed(h);
	abal_dcl(h,"\0","i",_ABAL_WORD,2,0,0,NULL);
	web_agent_normal(h);
	indent(h,1); fprintf(h,"ClientCookie=identity");			linefeed(h);
	indent(h,1); fprintf(h,"i = Index(url,%c?%c)",__QUOTE,__QUOTE); 	linefeed(h);
	indent(h,1); fprintf(h,"if ( i > 1 ) ");		 		linefeed(h);
		if ( fptr->pages ) {
			indent(h,2); fprintf(h,"LineBuffer = Left(url,(i-1))");		linefeed(h);
			indent(h,2); fprintf(h,"if ( PageNumber=0 ) :: PageNumber = 1 :: Endif");	 linefeed(h);
			}
		else	{
			indent(h,2); fprintf(h,"ResponseFile = Left(url,(i-1))");	linefeed(h);
			ensure_windows_filename(h,"ResponseFile");
			}
		/* --------------------------------------- */
		/* Reset all check boxes and radio buttons */
		/* --------------------------------------- */
		for (	items=0,iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next ) {
			switch ( (iptr->Contents.style & _FRAME_TYPE) ) {

				case	_CHECK_FRAME	:
					if (!( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ))
						break;
					if ( fptr->pages ) {
						indent(h,2); 
						fprintf(h,"if ( PageNumber = %u )",iptr->Contents.page);
						linefeed(h);
						}
					indent(h,2); 
					fprintf(h,"v_%s = 0",iptr->Contents.name);	
					linefeed(h);
					if ( fptr->pages ) {
						indent(h,2); 
						fprintf(h,"Endif");
						linefeed(h);
						}
					break;
				case	_RADIO_FRAME	:
					if (!( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ))
						break;
					if ( fptr->pages ) {
						indent(h,2); 
						fprintf(h,"if ( PageNumber = %u )",iptr->Contents.page);
						linefeed(h);
						}
					if ( iptr->Contents.radio == 1 ) {
						indent(h,2); 
						fprintf(h,"v_%s = 1",iptr->Contents.name);	
						linefeed(h);
						}
					if ( fptr->pages ) {
						indent(h,2); 
						fprintf(h,"Endif");
						linefeed(h);
						}
					break;
				}
			}
		indent(h,2); fprintf(h,"url = includ(1,Space((i-1)))"); 		linefeed(h);
		indent(h,2); fprintf(h,"url = Shl(url)");				linefeed(h);
		indent(h,2); fprintf(h,"url = includ(1,%c&%c)",__QUOTE,__QUOTE); 		linefeed(h);
		indent(h,2); fprintf(h,"WorkBuffer = url")		; 		linefeed(h);
		indent(h,2); fprintf(h,"while ( index(url,%c&%c) = 1)",__QUOTE,__QUOTE); 	linefeed(h);
			indent(h,3); fprintf(h,"url = includ(1,%c %c)",__QUOTE,__QUOTE); 		linefeed(h);
			indent(h,3); fprintf(h,"url = Shl(url)");				linefeed(h);
			indent(h,3); fprintf(h,"i = Index(url,%c=%c)",__QUOTE,__QUOTE); 		linefeed(h);
			indent(h,3); fprintf(h,"if ( i <> 0 ) ");		 			linefeed(h);
				indent(h,4); fprintf(h,"NameToken=Left(url,(i-1))"); 			linefeed(h);
				indent(h,4); fprintf(h,"url = includ(1,Space(i))"); 			linefeed(h);
				indent(h,4); fprintf(h,"url = Shl(url)");				linefeed(h);
				indent(h,4); fprintf(h,"i=index(url,%c&%c)",__QUOTE,__QUOTE); 	linefeed(h);
				indent(h,4); fprintf(h,"Select i");				linefeed(h);
				indent(h,4); fprintf(h,"Case   1");				linefeed(h);
					indent(h,5); fprintf(h,"ValueToken=%c %c",__QUOTE,__QUOTE);		linefeed(h);
				indent(h,4); fprintf(h,"Case   0");				linefeed(h);
					indent(h,5); fprintf(h,"ValueToken=url");			linefeed(h);
					indent(h,5); fprintf(h,"url = %c %c",__QUOTE,__QUOTE);		linefeed(h);
				indent(h,4); fprintf(h,"Default"); 					linefeed(h);
					indent(h,5); fprintf(h,"ValueToken = Left(url,(i-1))");		linefeed(h);
					indent(h,5); fprintf(h,"url = includ(1,Space((i-1)))"); 		linefeed(h);
					indent(h,5); fprintf(h,"url = Shl(url)");				linefeed(h);
				indent(h,4); fprintf(h,"EndSel"); 					linefeed(h);
				web_agent_wipe_value(h,4);
				indent(h,4); fprintf(h,"if ( Index(NameToken,%c(%c)<> 0)",__QUOTE,__QUOTE); linefeed(h);
					indent(h,5); fprintf(h,"TableDimension = NameToken",__QUOTE,__QUOTE); linefeed(h);
					indent(h,5); fprintf(h,"NameToken = Left(NameToken,(Index(NameToken,%c(%c)-1))",__QUOTE,__QUOTE); linefeed(h);
					indent(h,5); fprintf(h,"TableDimension = Includ(1,Space(Index(TableDimension,%c(%c)))",__QUOTE,__QUOTE);  linefeed(h);
					indent(h,5); fprintf(h,"TableDimension = Shl(TableDimension)"); linefeed(h);
					indent(h,5); fprintf(h,"ColumnDimension = Conv%(TableDimension)"); linefeed(h);
					indent(h,5); fprintf(h,"TableDimension = Includ(1,Space(Index(TableDimension,%c,%c)))",__QUOTE,__QUOTE);  linefeed(h);
					indent(h,5); fprintf(h,"TableDimension = Shl(TableDimension)"); linefeed(h);
					indent(h,5); fprintf(h,"RowDimension = Conv%(TableDimension)"); linefeed(h);
				indent(h,4); fprintf(h,"Else"); 					linefeed(h);
					indent(h,5); fprintf(h,"ColumnDimension=1 :: RowDimension=1");	linefeed(h);
				indent(h,4); fprintf(h,"Endif"); 					linefeed(h);
				indent(h,4); 
				/* --------------------------------- */
				/* Set Widget Storage from Parameter */
				/* --------------------------------- */
				fprintf(h,"Select(NameToken)"); 
				linefeed(h);
				items = web_agent_widget_set( h, fptr, "\0");
				indent(h,4); 	fprintf(h,"EndSel"); 	linefeed(h);
			indent(h,3); fprintf(h,"Endif"); 					linefeed(h);
		indent(h,2); fprintf(h,"Wend"); 					linefeed(h);
		indent(h,2); fprintf(h,"url = WorkBuffer")		; 		linefeed(h);
		indent(h,2); fprintf(h,"while ( index(url,%c&%c) = 1)",__QUOTE,__QUOTE); 	linefeed(h);
			indent(h,3); fprintf(h,"url = includ(1,%c %c)",__QUOTE,__QUOTE); 		linefeed(h);
			indent(h,3); fprintf(h,"url = Shl(url)");				linefeed(h);
			indent(h,3); fprintf(h,"i = Index(url,%c=%c)",__QUOTE,__QUOTE); 		linefeed(h);
			indent(h,3); fprintf(h,"if ( i <> 0 ) ");		 			linefeed(h);
				indent(h,4); fprintf(h,"NameToken=Left(url,(i-1))"); 			linefeed(h);
				indent(h,4); fprintf(h,"url = includ(1,Space(i))"); 			linefeed(h);
				indent(h,4); fprintf(h,"url = Shl(url)");				linefeed(h);
				indent(h,4); fprintf(h,"i=index(url,%c&%c)",__QUOTE,__QUOTE); 	linefeed(h);
				indent(h,4); fprintf(h,"Select i");				linefeed(h);
				indent(h,4); fprintf(h,"Case   1");				linefeed(h);
					indent(h,5); fprintf(h,"ValueToken=%c %c",__QUOTE,__QUOTE);		linefeed(h);
				indent(h,4); fprintf(h,"Case   0");				linefeed(h);
					indent(h,5); fprintf(h,"ValueToken=url");			linefeed(h);
					indent(h,5); fprintf(h,"url = %c %c",__QUOTE,__QUOTE);		linefeed(h);
				indent(h,4); fprintf(h,"Default"); 					linefeed(h);
					indent(h,5); fprintf(h,"ValueToken = Left(url,(i-1))");		linefeed(h);
					indent(h,5); fprintf(h,"url = includ(1,Space((i-1)))"); 		linefeed(h);
					indent(h,5); fprintf(h,"url = Shl(url)");				linefeed(h);
					indent(h,5); fprintf(h,"While (Index(ValueToken,%c+%c) <> 0) :: ValueToken=Includ(Index(ValueToken,%c+%c),%c %c) :: Wend",
						__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE); linefeed(h);
				indent(h,4); fprintf(h,"EndSel"); 					linefeed(h);
				indent(h,4); fprintf(h,"if ( Index(NameToken,%c(%c)<> 0)",__QUOTE,__QUOTE); linefeed(h);
					indent(h,5); fprintf(h,"TableDimension = NameToken",__QUOTE,__QUOTE); linefeed(h);
					indent(h,5); fprintf(h,"NameToken = Left(NameToken,(Index(NameToken,%c(%c)-1))",__QUOTE,__QUOTE); linefeed(h);
					indent(h,5); fprintf(h,"TableDimension = Includ(1,Space(Index(TableDimension,%c(%c)))",__QUOTE,__QUOTE);  linefeed(h);
					indent(h,5); fprintf(h,"TableDimension = Shl(TableDimension)"); linefeed(h);
					indent(h,5); fprintf(h,"ColumnDimension = Conv%(TableDimension)"); linefeed(h);
					indent(h,5); fprintf(h,"TableDimension = Includ(1,Space(Index(TableDimension,%c,%c)))",__QUOTE,__QUOTE);  linefeed(h);
					indent(h,5); fprintf(h,"TableDimension = Shl(TableDimension)"); linefeed(h);
					indent(h,5); fprintf(h,"RowDimension = Conv%(TableDimension)"); linefeed(h);
				indent(h,4); fprintf(h,"Else"); 					linefeed(h);
					indent(h,5); fprintf(h,"ColumnDimension=1 :: RowDimension=1");	linefeed(h);
				indent(h,4); fprintf(h,"Endif"); 					linefeed(h);
				/* ---------------------- */
				/* Activate Widget Method */
				/* ---------------------- */
				indent(h,4); fprintf(h,"Select(NameToken)"); 				linefeed(h);
				indent(h,4); fprintf(h,"Case %cMethod%c",__QUOTE,__QUOTE);		linefeed(h);
				indent(h,5); fprintf(h,"Select(ValueToken)"); 				linefeed(h);
				if ( fptr->formflags &_MULTILINGUAL ) {
					indent(h,5); 	
					fprintf(h,"Case %c%s%c",__QUOTE,__NatLang,__QUOTE);
					linefeed(h);
					indent(h,6);
					fprintf(h,"if ( NationalLanguage < 8 ) :: NationalLanguage += 1 :: Else :: NationalLanguage = 1 :: Endif");
					linefeed(h);
					web_agent_set_lang(h);
					indent(h,6); 
					fprintf(h,"OnShow(o)");
					linefeed(h);
					for ( nl=0; nl < MAXNATLANG; nl++ ) {
						indent(h,5); 	
						fprintf(h,"Case %c%s%u%c",__QUOTE,__NatLang,nl,__QUOTE);
						linefeed(h);
						indent(h,6);
						fprintf(h,"NationalLanguage = %u ",nl);
						linefeed(h);
						web_agent_set_lang(h);
						indent(h,6); 
						fprintf(h,"OnShow(o)");
						linefeed(h);
						}
					}
				items = web_agent_event_cases( h, fptr, "\0" );
				indent(h,5); 	fprintf(h,"EndSel"); 	linefeed(h);
				for (	items=0,iptr=fptr->first;
					iptr != (struct form_item *) 0;
					iptr = iptr->next ) {
					switch ( (iptr->Contents.style & _FRAME_TYPE) ) {
						case	_FORM_FRAME	:
							if ((( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION ))
							&&  ( method_is_valid( iptr->Contents.events->on_event )) ) {
								fprintf(h,"Case %c%sEvent%c",__QUOTE,iptr->Contents.name,__QUOTE);
								linefeed(h);
								web_agent_event_focus(h,iptr,5);
								indent(h,5);
								fprintf(h,"if ( Conv%c(ValueToken) <> 0 )",__PERCENT);
								linefeed(h);
								indent(h,6); 
								fprintf(h,"c_%s=Conv%c(ValueToken)",iptr->Contents.name,__PERCENT);
								linefeed(h);
								indent(h,6);
								fprintf(h,"ValueToken=Includ(1,space(index(ValueToken,%c,%c)))",__QUOTE,__QUOTE);
								linefeed(h);
								indent(h,6); 
								fprintf(h,"ValueToken=Shl(ValueToken)",__QUOTE,__QUOTE);
								linefeed(h);
								indent(h,6); 
								fprintf(h,"v_%s=Conv%c(ValueToken)",iptr->Contents.name,__PERCENT);
								linefeed(h);
								indent(h,6); 
								fprintf(h,"%sEvent(o)",iptr->Contents.name);
								linefeed(h);
								indent(h,5);
								fprintf(h,"Endif");
								linefeed(h);
								}
							if ((( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION ))
							&&  ( method_is_valid( iptr->Contents.events->on_lose_focus )) ) {
								indent(h,4); 
								fprintf(h,"Case %c%sLoseFocus%c",__QUOTE,iptr->Contents.name,__QUOTE);
								linefeed(h);
								indent(h,5);
								fprintf(h,"if ( Conv%c(ValueToken) <> 0 )",__PERCENT);
								linefeed(h);
								indent(h,6); 
								fprintf(h,"c_%s=Conv%c(ValueToken)",iptr->Contents.name,__PERCENT);
								linefeed(h);
								indent(h,6);
								fprintf(h,"ValueToken=Includ(1,space(index(ValueToken,%c,%c)))",__QUOTE,__QUOTE);
								linefeed(h);
								indent(h,6); 
								fprintf(h,"ValueToken=Shl(ValueToken)",__QUOTE,__QUOTE);
								linefeed(h);
								indent(h,6); 
								fprintf(h,"v_%s=Conv%c(ValueToken)",iptr->Contents.name,__PERCENT);
								linefeed(h);
								indent(h,6); 
								fprintf(h,"%sLosefocus(o)",iptr->Contents.name);
								linefeed(h);
								indent(h,5);
								fprintf(h,"Endif");
								linefeed(h);
								}
							break;
						}
					}
				indent(h,4); 	fprintf(h,"EndSel"); 	linefeed(h);
			indent(h,3); fprintf(h,"Endif"); linefeed(h);
		indent(h,2); fprintf(h,"Wend");	linefeed(h);
		if ( fptr->pages ) {
			indent(h,2); fprintf(h,"if ( ClientRedirect = 0 )"); linefeed(h);
			ensure_windows_filename(h,"LineBuffer");
			indent(h,3); fprintf(h,"Select PageNumber"); linefeed(h);
			for (	i=1; i <= fptr->pages; i++ ) {
				indent(h,3); fprintf(h,"Case %u :: ResponseFile = Print(($,%cpage%u_%c,$),Parse(LineBuffer,7),Parse(LineBuffer,8+16))",i,__QUOTE,i,__QUOTE);	 linefeed(h);
				}
			indent(h,3); fprintf(h,"EndSel"); linefeed(h);
			indent(h,2); fprintf(h,"EndIf"); linefeed(h);
			}
	indent(h,1); fprintf(h,"Else");	linefeed(h);
	if (!( fptr->pages )) {
		indent(h,2); fprintf(h,"ResponseFile=url");linefeed(h);
		ensure_windows_filename(h,"ResponseFile");
		}
	else	{
		indent(h,2); fprintf(h,"if ( PageNumber=0 ) :: PageNumber = 1 :: Endif");	 linefeed(h);
		indent(h,2); fprintf(h,"if ( ClientRedirect = 0 )");			 linefeed(h);
		indent(h,2); fprintf(h,"WorkBuffer=url");linefeed(h);
		ensure_windows_filename(h,"WorkBuffer");
		indent(h,3); fprintf(h,"Select PageNumber");			 linefeed(h);
		for (	i=1; i <= fptr->pages; i++ ) {
			indent(h,3); fprintf(h,"Case %u :: ResponseFile = Print(($,%cpage%u_%c,$),Parse(WorkBuffer,7),Parse(WorkBuffer,8+16))",i,__QUOTE,i,__QUOTE);	 linefeed(h);
			}
		indent(h,3); fprintf(h,"EndSel");			 linefeed(h);
		indent(h,2); fprintf(h,"EndIf");			 linefeed(h);
		}
	indent(h,1); fprintf(h,"Endif");			 	linefeed(h);
	indent(h,1); fprintf(h,"ClientSocket=handle"); 			linefeed(h);
	if ( fptr->formflags &_MULTILINGUAL ) {
		indent(h,1); fprintf(h,"if ( ClientRedirect = 0 )");	linefeed(h);
		indent(h,2); fprintf(h,"Select (NationalLanguage)");	linefeed(h);
		indent(h,2); fprintf(h,"Case 1 :: ResponseFile = Print(($,%cen/%c,$),Parse(ResponseFile,7),Parse(ResponseFile,16+8))",__QUOTE,__QUOTE); linefeed(h);
		indent(h,2); fprintf(h,"Case 2 :: ResponseFile = Print(($,%cfr/%c,$),Parse(ResponseFile,7),Parse(ResponseFile,16+8))",__QUOTE,__QUOTE); linefeed(h);
		indent(h,2); fprintf(h,"Case 3 :: ResponseFile = Print(($,%cit/%c,$),Parse(ResponseFile,7),Parse(ResponseFile,16+8))",__QUOTE,__QUOTE); linefeed(h);
		indent(h,2); fprintf(h,"Case 4 :: ResponseFile = Print(($,%ces/%c,$),Parse(ResponseFile,7),Parse(ResponseFile,16+8))",__QUOTE,__QUOTE); linefeed(h);
		indent(h,2); fprintf(h,"Case 5 :: ResponseFile = Print(($,%cde/%c,$),Parse(ResponseFile,7),Parse(ResponseFile,16+8))",__QUOTE,__QUOTE); linefeed(h);
		indent(h,2); fprintf(h,"Case 6 :: ResponseFile = Print(($,%cnl/%c,$),Parse(ResponseFile,7),Parse(ResponseFile,16+8))",__QUOTE,__QUOTE); linefeed(h);
		indent(h,2); fprintf(h,"Case 7 :: ResponseFile = Print(($,%cpt/%c,$),Parse(ResponseFile,7),Parse(ResponseFile,16+8))",__QUOTE,__QUOTE); linefeed(h);
		indent(h,2); fprintf(h,"Case 8 :: ResponseFile = Print(($,%cxx/%c,$),Parse(ResponseFile,7),Parse(ResponseFile,16+8))",__QUOTE,__QUOTE); linefeed(h);
		indent(h,2); fprintf(h,"EndSel");			linefeed(h);
		ensure_windows_filename(h,"ResponseFile");
		indent(h,1); fprintf(h,"Endif");			linefeed(h);
		}
	indent(h,1); fprintf(h,"if ( ClientRedirect <> 0 )");	linefeed(h);
	ensure_url_filename(h,"ResponseFile");
	indent(h,1); fprintf(h,"Endif");			linefeed(h);
	indent(h,1); fprintf(h,"Exit(ClientRedirect)");			linefeed(h);
	web_agent_endmethod(h);			
	return;
}

/*	------------------------------------------------	*/
/*	w e b _ a g e n t _ o n s h o w ( handle, form )	*/
/*	------------------------------------------------	*/
private	void	web_agent_select_method( FILE * h, int mode )
{	
	abal_dcl(h,"\0","i",_ABAL_WORD,2,0,0,NULL);
	abal_dcl(h,"\0","j",_ABAL_WORD,2,0,0,NULL);
	abal_ptr(h,"\0","w",_ABAL_STRING,15,0,0,NULL);
	if ( mode == _ABAL_STRING ) { abal_dcl(h,"\0","result",_ABAL_STRING,256,0,0,NULL); }
	indent(h,1); 	fprintf(h,"Create w(vlen+1)"); 				linefeed(h);
	indent(h,1); 	fprintf(h,"w = Print(($,%c|%c),v)",__QUOTE,__QUOTE);	linefeed(h);
	indent(h,1); 	fprintf(h,"j=1");	 				linefeed(h);
	indent(h,1); 	fprintf(h,"Do");	 				linefeed(h);
	indent(h,2); 	fprintf(h,"i = Index(w,%c|%c)",__QUOTE,__QUOTE);	linefeed(h);
	indent(h,2); 	fprintf(h,"Select i");					linefeed(h);
	if ( mode == _ABAL_STRING ) {
		indent(h,2); 	fprintf(h,"Case 0  :: Remove w :: Exit(%c %c)",__QUOTE,__QUOTE);linefeed(h);
		indent(h,2); 	fprintf(h,"Case 1  :: result = %c %c",__QUOTE,__QUOTE);		linefeed(h);
		indent(h,2); 	fprintf(h,"Default :: result = Left(w,(i-1))");			linefeed(h);
		}
	else	{
		indent(h,2); 	fprintf(h,"Case 0 :: Remove w :: Exit(0)");			linefeed(h);
		}
	indent(h,2); 	fprintf(h,"EndSel");					linefeed(h);
	indent(h,2); 	fprintf(h,"if ( j >= item )");				linefeed(h);
	indent(h,3);
	if ( mode == _ABAL_STRING ) 	fprintf(h,"Remove w :: Exit(result)");
	else				fprintf(h,"Remove w :: Exit(1)");
	linefeed(h);
	indent(h,2); 	fprintf(h,"Else :: j+= 1");				linefeed(h);
	indent(h,2); 	fprintf(h,"Endif");					linefeed(h);

	indent(h,2); 	fprintf(h,"w = Includ(1,Space(i))");			linefeed(h);
	indent(h,2); 	fprintf(h,"w = Shl(w)");				linefeed(h);
	indent(h,1); 	fprintf(h,"Loop");	 				linefeed(h);
	indent(h,1);
	if ( mode == _ABAL_STRING ) 	fprintf(h,"Remove w :: Exit(%c %c)",__QUOTE,__QUOTE);
	else				fprintf(h,"Remove w :: Exit(0)");
	linefeed(h);
	return;
}

private	void	web_agent_member_response( FILE * h, struct form_control * fptr )
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
		if (!( method_is_valid( mptr->name ) ))
			continue;
		else if ( mptr->first )
			continue;
		else if ( mptr->second )
			continue;
		else	{
			indent(h,4); 	fprintf(h,"Case %c%s%c",__QUOTE,mptr->name,__QUOTE); 	linefeed(h);
			indent(h,5); 	
			switch (mptr->type) {
				case	_ABAL_BYTE	:
				case	_ABAL_WORD	:
				case	_ABAL_LONG	:
				case	_ABAL_BCD 	:
					fprintf(h,"LineBuffer = Print(($,$),LineBuffer,Conv$(%s))",mptr->name);
					break;
				case	_ABAL_STRING	:
					fprintf(h,"LineBuffer = Print(($,$),LineBuffer,%s)",mptr->name);
					break;
				}
			linefeed(h);
			}	
		}
	return;
}

private	void	web_agent_method_response( FILE * h, struct form_control * fptr )
{
	struct	forms_method 	* mptr;
	if (!( fptr ))
		return;
	if (!( fptr->rootmethod ))
		return;
	linefeed(h);
	for (	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {
		if (!( mptr->type & _METHOD_PUBLIC ))
			continue;
		else if ( method_is_valid( mptr->name ) ) {
			indent(h,4); 	fprintf(h,"Case %c%s%c",__QUOTE,mptr->name,__QUOTE); 	linefeed(h);
			indent(h,5); 	
			switch ( (mptr->type & _METHOD_TYPE) ) {
				case	_METHOD_VOID	:
					fprintf(h,"%s(o)",mptr->name);
					break;
				case	_METHOD_BYTE	: 
				case	_METHOD_WORD	: 
				case	_METHOD_NUMERIC	: 
				case	_METHOD_LONG	: 
					fprintf(h,"LineBuffer = Print(($,$),LineBuffer,Conv$(%s(o)))",mptr->name);
					break;
				case	_METHOD_CLASS	: 
				case	_METHOD_STRING	: 
					fprintf(h,"LineBuffer = Print(($,$),LineBuffer,%s(o))",mptr->name);
				}
			linefeed(h);
			}	
		}
	return;
}

private	void	web_agent_onshow( FILE * h, struct form_control * fptr )
{
	char *	xptr=(char *) 0;
	int	fit=0;
	int	i;
	int	items=0;
	char *	sptr;
	struct	form_item * iptr;
	struct	form_item * wptr;
	int		fields=0;
	int		fieldwidth[_MAX_FORM_FIELDS];
	int		linelength=0;
	int		nblines=0;
	struct	form_control * vfptr;

	web_agent_method(h,"SelectCheck",3);	linefeed(h);
	web_agent_select_method(h,_ABAL_WORD);
	web_agent_endmethod(h);			
	web_agent_method(h,"SelectValue",4);	linefeed(h);
	web_agent_select_method(h,_ABAL_STRING);
	web_agent_endmethod(h);			

	web_agent_method(h,"OnResponse",0);	linefeed(h);
	abal_dcl(h,"\0","i",_ABAL_WORD,2,0,0,NULL);
	abal_dcl(h,"\0","j",_ABAL_WORD,2,0,0,NULL);
	abal_dcl(h,"\0","pn",_ABAL_WORD,2,0,0,NULL);
	if ( ActiveAgentImages ) {
		abal_dcl(h,"Session","Url",_ABAL_STRING,256,0,0,NULL);
		abal_dcl(h,"Session","Image",_ABAL_STRING,256,0,0,NULL);
		}
	if ( ActiveAgentImages ) {
		fprintf(h,"%s FWFN",__FireWallFileName);
		linefeed(h);
		fprintf(h,"%s FireWall(%s)",__FireWallClassName,__FireWallDiskFile);
		linefeed(h);
		}
	fprintf(h,"stdin  Infile(ResponseFile)");
	linefeed(h);
	if ( ActiveAgentImages ) {
		web_agent_use_page(h);
		indent(h,1);  fprintf(h,"if ( Len$(Env(%cDYNAMICPATH%c)) <> 0)",__QUOTE,__QUOTE); linefeed(h);
			indent(h,2); 
			if ((xptr = image_extension((fit = form_imagetype( fptr )))) != (char *) 0) {
				fprintf(h,"SessionImage=Print(($,$,%c%s%c),Env(%cDYNAMICPATH%c),ClientCookie)",
					__QUOTE,xptr,__QUOTE,__QUOTE,__QUOTE);
				}
			else	{
				fprintf(h,"SessionImage=Print(($,$,%c.jpg%c),Env(%cDYNAMICPATH%c),ClientCookie)",
					__QUOTE,__QUOTE,__QUOTE,__QUOTE);
				}
			linefeed(h);
		indent(h,1); fprintf(h,"Else"); linefeed(h);
			indent(h,2); 
			if ((xptr = image_extension((fit = form_imagetype( fptr )))) != (char *) 0) {
				fprintf(h,"SessionImage=Print((%c%s%c,$,%c%s%c),ClientCookie)",
					__QUOTE,_DYNAMIC_IMAGE_PATH,__QUOTE,__QUOTE,xptr,__QUOTE);
				}
			else	{
				fprintf(h,"SessionImage=Print((%c%s%c,$,%c.jpg%c),ClientCookie)",
					__QUOTE,_DYNAMIC_IMAGE_PATH,__QUOTE,__QUOTE,__QUOTE);
				}
			linefeed(h);
		indent(h,1); fprintf(h,"Endif"); linefeed(h);
		indent(h,1); 
		switch ( (fit & 0x0C0) >> 6 )  {
			case	_IMAGE_IS_PNG	:
				fprintf(h,"Status=VisualControl(_VISUAL_SAVEPNG,SessionImage,Len$(SessionImage))");
				break;
			case	_IMAGE_IS_BMP	:
				fprintf(h,"Status=VisualControl(_VISUAL_SAVEBMP,SessionImage,Len$(SessionImage))");
				break;
			case	_IMAGE_IS_GIF	:
				fprintf(h,"Status=VisualControl(_VISUAL_SAVEGIF,SessionImage,Len$(SessionImage))");
				break;
			case	_IMAGE_IS_JPG	:	
			default		   	:
				fprintf(h,"Status=VisualControl(_VISUAL_SAVEJPG,SessionImage,Len$(SessionImage))");
				break;
			}
		linefeed(h);
		indent(h,1); fprintf(h,"SessionUrl=SessionImage"); linefeed(h);
		indent(h,1); 
		fprintf(h,"FireWall.AddBinary(SessionUrl;SessionImage;%c*%c;%c*%c)",
			__QUOTE,__QUOTE,__QUOTE,__QUOTE);
		linefeed(h);
		web_agent_release_page(h);
		}
	if ( DebugAgent ) {
		indent(h,1);
		fprintf(h,"ValueToken=Print((%c-r%c,$),Conv$(ClientSocket))",__QUOTE,__QUOTE);
		linefeed(h);
		indent(h,1);
		fprintf(h,"HttpConfigure(ValueToken,Len$(ValueToken))");
		linefeed(h);
		}
	if ( DebugAgent ) {
		indent(h,1); fprintf(h,"Print=1:(%cresponse=%c,$,X,/1),ResponseFile,ClientCookie",__QUOTE,__QUOTE);	linefeed(h);
		}
	indent(h,1);	fprintf(h,"Do");							linefeed(h);
	indent(h,2);	fprintf(h,"LineBuffer=%c %c",__QUOTE,__QUOTE);				linefeed(h);
	indent(h,2);	fprintf(h,"Infile.get_line(LineBuffer;Len(LineBuffer))");		linefeed(h);
	indent(h,2);	fprintf(h,"if ( Infile.error_value <> 0 ) :: Break :: Endif");		linefeed(h);

	indent(h,2);	fprintf(h,"Do");							linefeed(h);

	indent(h,3);	fprintf(h,"i = Index(LineBuffer,%c<widget%c)",__QUOTE,__QUOTE);		linefeed(h);
	indent(h,3);	fprintf(h,"if ( i <> 0 )");						linefeed(h);

	indent(h,4);	fprintf(h,"WorkBuffer = Right(LineBuffer,Len(LineBuffer)-i)");		linefeed(h);
	indent(h,4);	fprintf(h,"LineBuffer = Left(LineBuffer,i-1)");				linefeed(h);
	indent(h,4);	fprintf(h,"WorkBuffer = Includ(1,Space(Index(WorkBuffer,Chr$(32))))");	linefeed(h);
	indent(h,4);	fprintf(h,"WorkBuffer = Shl(WorkBuffer)");				linefeed(h);
	indent(h,4);	fprintf(h,"WorkBuffer = Includ(1,Space(5))");				linefeed(h);
	indent(h,4);	fprintf(h,"WorkBuffer = Shl(WorkBuffer)");				linefeed(h);
	indent(h,4);	fprintf(h,"i = Index(WorkBuffer,%c>%c)",__QUOTE,__QUOTE);			linefeed(h);
	indent(h,4);	fprintf(h,"NameToken = Left(WorkBuffer,(i-1))");			linefeed(h);
	indent(h,4);	fprintf(h,"WorkBuffer = Includ(1,Space(i))");				linefeed(h);
	indent(h,4);	fprintf(h,"WorkBuffer = Shl(WorkBuffer)");				linefeed(h);
	indent(h,4); fprintf(h,"if ( Index(NameToken,%c(%c)<> 0)",__QUOTE,__QUOTE); linefeed(h);
		indent(h,5); fprintf(h,"TableDimension = NameToken",__QUOTE,__QUOTE); linefeed(h);
		indent(h,5); fprintf(h,"NameToken = Left(NameToken,(Index(NameToken,%c(%c)-1))",__QUOTE,__QUOTE); linefeed(h);
		indent(h,5); fprintf(h,"TableDimension = Includ(1,Space(Index(TableDimension,%c(%c)))",__QUOTE,__QUOTE);  linefeed(h);
		indent(h,5); fprintf(h,"TableDimension = Shl(TableDimension)"); linefeed(h);
		indent(h,5); fprintf(h,"ColumnDimension = Conv%(TableDimension)"); linefeed(h);
		indent(h,5); fprintf(h,"TableDimension = Includ(1,Space(Index(TableDimension,%c,%c)))",__QUOTE,__QUOTE);  linefeed(h);
		indent(h,5); fprintf(h,"TableDimension = Shl(TableDimension)"); linefeed(h);
		indent(h,5); fprintf(h,"RowDimension = Conv%(TableDimension)"); linefeed(h);
	indent(h,4); fprintf(h,"Else"); 					linefeed(h);
		indent(h,5); fprintf(h,"ColumnDimension=1 :: RowDimension=1");	linefeed(h);
	indent(h,4); fprintf(h,"Endif"); 					linefeed(h);

	indent(h,4); 
	fprintf(h,"Select(NameToken)"); 
	linefeed(h);
	
	/* widget expressions */
	/* ------------------ */
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_DATA_FRAME	:
			case	_SELECT_FRAME	:
			case	_FORM_FRAME	:
			case	_EDIT_FRAME	:
			case	_CHECK_FRAME	:
			case	_RADIO_FRAME	:
			case	_SCROLL_FRAME	:
			case	_SWITCH_FRAME	:
				break;
			default			:
				continue;
			}
		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_FORM_FRAME	:
				calculate_edit_size( &iptr->Contents );
				calculate_form_lines( iptr, &linelength, &nblines );
				fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength);
				indent(h,4); 
				fprintf(h,"Case %c%sCell%c",__QUOTE,iptr->Contents.name,__QUOTE);
				linefeed(h);
					indent(h,5); 
					fprintf(h,"LineBuffer = Print(($,$,%c_%c,$),LineBuffer,Conv$(c_%s),Conv$(v_%s))",__QUOTE,__QUOTE,iptr->Contents.name,iptr->Contents.name);
					linefeed(h);
				indent(h,4); 
				fprintf(h,"Case %c%sColumn%c",__QUOTE,iptr->Contents.name,__QUOTE);
				linefeed(h);
					indent(h,5); 
					fprintf(h,"LineBuffer = Print(($,$),LineBuffer,Conv$(c_%s))",iptr->Contents.name);
					linefeed(h);
				indent(h,4); 
				fprintf(h,"Case %c%sRow%c",__QUOTE,iptr->Contents.name,__QUOTE);
				linefeed(h);
					indent(h,5); 
					fprintf(h,"LineBuffer = Print(($,$),LineBuffer,Conv$(v_%s))",iptr->Contents.name);
					linefeed(h);
				indent(h,4); 
				fprintf(h,"Case %c%s%c :: r_%s = Alias(l_%s(RowDimension))",__QUOTE,iptr->Contents.name,__QUOTE,iptr->Contents.name,iptr->Contents.name,iptr->Contents.name);
				linefeed(h);
				indent(h,5); 
				fprintf(h,"Select ColumnDimension"); 
				linefeed(h);
				for ( i=0; i < fields; i++ ) {
					indent(h,5); 
					fprintf(h,"Case %u :: if ( Len$(m%u_%s) = 0 ) :: LineBuffer = Print(($,$),LineBuffer,%c%s%c) :: Else :: LineBuffer = Print(($,$),LineBuffer,m%u_%s) :: Endif ",i+1,i+1,iptr->Contents.name,__QUOTE,"&nbsp;",__QUOTE,i+1,iptr->Contents.name);
					linefeed(h);
					}
				indent(h,5); 
				fprintf(h,"EndSel"); 
				linefeed(h);
				break;

			case	_SELECT_FRAME	:
				indent(h,4); 
				fprintf(h,"Case %c%s%c  :: LineBuffer = ",__QUOTE,iptr->Contents.name,__QUOTE);
				if (!( method_is_valid((sptr = abal_payload(iptr)))))
					sptr = " ";
				if ( *sptr == _UNQUOTED_STRING ) {
					abal_macro_conversion( h, (sptr+1), iptr->Contents.name );
					/* was this fprintf(h,"%s",(sptr+1)); */
					}
				else	fprintf(h,"%c%s%c",__QUOTE,sptr,__QUOTE);
				linefeed(h);
				indent(h,4);	fprintf(h,"j=1");						linefeed(h);
				indent(h,4);	fprintf(h,"Repeat",(sptr+1));					linefeed(h);
				indent(h,5);	fprintf(h,"LineBuffer=SelectValue(o,j");
				constant_parameter(h,iptr );
				constant_length_parameter(h,iptr);
				fprintf(h,")");	linefeed(h);
				indent(h,5);    fprintf(h,"ValueToken=Print((%c<option value=%c,$),Conv$(j))",__QUOTE,__QUOTE); linefeed(h);
				indent(h,5);	fprintf(h,"if (v_%s =j)",iptr->Contents.name);			linefeed(h);
				indent(h,6);	fprintf(h,"LineBuffer=Insert(1,%c selected>%c)",__QUOTE,__QUOTE);	linefeed(h);
				indent(h,5);	fprintf(h,"Else",iptr->Contents.name);				linefeed(h);
				indent(h,6);	fprintf(h,"LineBuffer=Insert(1,%c>%c)",__QUOTE,__QUOTE);	linefeed(h);
				indent(h,5);	fprintf(h,"Endif");						linefeed(h);
				indent(h,5);	fprintf(h,"LineBuffer=Insert(1,ValueToken,Len$(ValueToken))");	linefeed(h);
				indent(h,5);	fprintf(h,"Status = HttpPutLine(ClientSocket,LineBuffer,Len$(LineBuffer))"); linefeed(h);
				indent(h,5);	fprintf(h,"j+=1");						linefeed(h);
				indent(h,4);	fprintf(h,"Until (SelectCheck(o,j");
				constant_parameter(h,iptr );
				constant_length_parameter(h,iptr);
				fprintf(h,") = 0)");	linefeed(h);
				indent(h,4);	fprintf(h,"LineBuffer=%c %c",__QUOTE,__QUOTE);
				break;

			case	_DATA_FRAME	:
				if ( is_file_Widget( iptr ) ) {
					html_file_agent(h,iptr);
					continue;
					}					
				else if (( iptr->Contents.align & 0x000F ) != _VISUAL_FRAME)
					continue;
				else if ( iptr->Contents.datatype != _WIDGET_OVERLAY )
					continue;
				else if (!( method_is_valid((sptr = abal_payload( iptr )) ) ))
					continue;
				else if (!( vfptr = locate_form_control( sptr ) ))
					continue;
				else	{
					items += web_agent_component_get( h, vfptr, iptr->Contents.name, iptr );
					continue; /* for now */
					}

			case	_SCROLL_FRAME	:
				indent(h,4); 
				fprintf(h,"Case %c%s.value%c\nLineBuffer = Print(($,$),LineBuffer,Conv$(v_%s))",__QUOTE,iptr->Contents.name,__QUOTE,iptr->Contents.name);
				linefeed(h);
				indent(h,4); 
				fprintf(h,"Case %c%s.limit%c\nLineBuffer = Print(($,$),LineBuffer,Conv$(l_%s))",__QUOTE,iptr->Contents.name,__QUOTE,iptr->Contents.name);
				linefeed(h);
				indent(h,4); 
				fprintf(h,"Case %c%s.max%c\nLineBuffer = Print(($,$),LineBuffer,Conv$(m_%s))",__QUOTE,iptr->Contents.name,__QUOTE,iptr->Contents.name);
				linefeed(h);
				break;

			case	_EDIT_FRAME	:
				indent(h,4); 
				fprintf(h,"Case %c%s.buffer%c :: LineBuffer = Print(($,$),LineBuffer,b_%s)",__QUOTE,iptr->Contents.name,__QUOTE,iptr->Contents.name);
				linefeed(h);
				break;
			case	_RADIO_FRAME	:
				indent(h,4); 
				fprintf(h,"Case %c%s%u%c :: if ( v_%s = %u ) :: LineBuffer = Print(($,X,$),LineBuffer,%cchecked%c) :: Endif",__QUOTE,iptr->Contents.name,iptr->Contents.radio,__QUOTE,iptr->Contents.name,iptr->Contents.radio,__QUOTE,__QUOTE);
				linefeed(h);
				break;
			case	_CHECK_FRAME	:
				indent(h,4); 
				fprintf(h,"Case %c%s%c :: if ( v_%s <> 0 ) :: LineBuffer = Print(($,X,$),LineBuffer,%cchecked%c) :: Endif",__QUOTE,iptr->Contents.name,__QUOTE,iptr->Contents.name,__QUOTE,__QUOTE);
				linefeed(h);
				break;
			case	_SWITCH_FRAME	:
				indent(h,4); 
				fprintf(h,"Case %c%s.value%c :: LineBuffer = Print(($,X,Z),LineBuffer,v_%s)",__QUOTE,iptr->Contents.name,__QUOTE,iptr->Contents.name);
				linefeed(h);
				break;

			}
		}

	/* Forms Member Expressions */
	/* ------------------------ */
	web_agent_member_response(h,fptr);

	/* Forms Method Expressions */
	/* ------------------------ */
	web_agent_method_response(h,fptr);

	/* Specific Forms Variables */
	/* ------------------------ */
	if ( ActiveAgentImages ) {
		indent(h,4); 	fprintf(h,"Case %c%s%c",__QUOTE,__SessionImage,__QUOTE); 	linefeed(h);
				indent(h,5); 
				fprintf(h,"LineBuffer = Print(($,$),LineBuffer,SessionUrl)",__QUOTE,__QUOTE);
				linefeed(h);
		}
	indent(h,4); 	fprintf(h,"Case %c%s%c",__QUOTE,__ArgV,__QUOTE); 	linefeed(h);
			indent(h,5); 
			fprintf(h,"LineBuffer = Print(($,$),LineBuffer,ArgV(ColumnDimension))",__QUOTE,__QUOTE);
			linefeed(h);

	indent(h,4); 	fprintf(h,"Case %c%s%c",__QUOTE,__FocusItem,__QUOTE); 	linefeed(h);
			indent(h,5); 
			fprintf(h,"LineBuffer = Print(($,$),LineBuffer,Conv$(FocusItem))",__QUOTE,__QUOTE);
			linefeed(h);

	indent(h,4); 	fprintf(h,"Case %c%s%c",__QUOTE,__FocusItems,__QUOTE); 	linefeed(h);
			indent(h,5); 
			fprintf(h,"LineBuffer = Print(($,$),LineBuffer,Conv$(FocusItems))",__QUOTE,__QUOTE);
			linefeed(h);

	if ( fptr->pages ) {
		indent(h,4); 	fprintf(h,"Case %c%s%c",__QUOTE,__PageNumber,__QUOTE); 	linefeed(h);
				indent(h,5); 
				fprintf(h,"LineBuffer = Print(($,$),LineBuffer,Conv$(PageNumber))",__QUOTE,__QUOTE);
				linefeed(h);
		}

	indent(h,4); 	fprintf(h,"Case %c%s%c",__QUOTE,__ResponseFile,__QUOTE); 	linefeed(h);
			indent(h,5); 
			fprintf(h,"LineBuffer = Print(($,$),LineBuffer,Conv$(ResponseFile))",__QUOTE,__QUOTE);
			linefeed(h);
	indent(h,4); 	fprintf(h,"Case %c%s%c",__QUOTE,__ClientRedirect,__QUOTE); 	linefeed(h);
			indent(h,5); 
			fprintf(h,"LineBuffer = Print(($,$),LineBuffer,Conv$(ClientRedirect))",__QUOTE,__QUOTE);
			linefeed(h);


	

	indent(h,4); 	fprintf(h,"EndSel"); 	linefeed(h);

	indent(h,4);	fprintf(h,"LineBuffer = Print(($,$),LineBuffer,WorkBuffer)");		linefeed(h);
	indent(h,3);	fprintf(h,"Else :: Break");						linefeed(h);
	indent(h,3);	fprintf(h,"Endif");							linefeed(h);
	indent(h,2);	fprintf(h,"Loop");							linefeed(h);
	indent(h,2);	fprintf(h,"Status = HttpPutLine(ClientSocket,LineBuffer,Len$(LineBuffer))"); linefeed(h);
	indent(h,1);	fprintf(h,"Loop");							linefeed(h);
	if ( DebugAgent ) {
		indent(h,1);
		fprintf(h,"ValueToken=Print((%c-r%c,Z),0)",__QUOTE,__QUOTE);
		linefeed(h);
		indent(h,1);
		fprintf(h,"HttpConfigure(ValueToken,Len$(ValueToken))");
		linefeed(h);
		}
	web_agent_endmethod(h);			
	/* On Hide */
	web_agent_method(h,"OnHide",0);		linefeed(h);
	if (fptr->pages != 0 ) 
		abal_form_hidepages( h );
	else	abal_form_hide( h );
	web_agent_endmethod(h);			

	/* Allow instance specific widget methods to be generated */
	/* ------------------------------------------------------ */
	abal_onhide_methods( h, fptr, __abal_method_hide );
	abal_onshow_methods( h, fptr );

	/* Allow widget methods to be generated */
	/* ------------------------------------ */
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else	abal_dialog_show(h,iptr,1);
		}

	/* On Show */
	web_agent_method(h,"OnShow",0);		linefeed(h);
	web_agent_use_page(h);

	/* Always freeze */
	/* ------------- */
	abal_widget_function(h,__abal_visual_freeze,1);
	fprintf(h,")");
	linefeed(h);

	/* Detect Tab Page Generation Required */
	/* ----------------------------------- */
	if ( fptr->pages != 0 ) 
		abal_form_showpages( h );
	else	abal_form_show( h );

	web_agent_endmethod(h);			
	return;
}

/*	--------------------------------------------------	*/
/*	w e b _ a g e n t _ o n e v e n t ( handle, form )	*/
/*	--------------------------------------------------	*/
private	void	web_agent_onevent( FILE * h, struct form_control * fptr )
{
	web_agent_method(h,"OnEvent",0);		linefeed(h);
	web_agent_endmethod(h);			
	return;
}

/*	--------------------------------------------------	*/
/*	w e b _ a g e n t _ o n f o c u s ( handle, form )	*/
/*	--------------------------------------------------	*/
private	void	web_agent_get_lang( h )
{
	indent(h,1);
	fprintf(h,"NationalLanguage = Conf(5)");
	linefeed(h);
	indent(h,1);
	fprintf(h,"if ( NationalLanguage = 0 ) :: NationalLanguage = 1 :: Endif");
	linefeed(h);
	return;
}

private	void	web_agent_set_lang( h )
{
	indent(h,1);
	fprintf(h,"Lang NationalLanguage");
	linefeed(h);
	return;
}

private	void	web_agent_onfocus( FILE * h, struct form_control * fptr )
{
	abal_onlose_methods( h,fptr, __abal_method_lose_focus, 0 );
	web_agent_method(h,"OnLosefocus",0);	linefeed(h);
	web_agent_release_page(h);
	web_agent_endmethod(h);			

	abal_onget_methods( h, fptr,__abal_method_get_focus );
	web_agent_method(h,"OnFocus",0);	linefeed(h);

	/* Agent needs its own palette */
	/* --------------------------- */
	abal_load_visual_palette(h,1);

	/* Ensure Correct national language */
	/* -------------------------------- */
	if ( fptr->formflags &_MULTILINGUAL )
		web_agent_get_lang( h );

	/* Reload the Agent style sheet */
	/* ---------------------------- */
	abal_form_style(h,fptr,0);

	/* Activate The Visual Page Buffer */
	/* ------------------------------- */
	web_agent_use_page( h );

	web_agent_endmethod(h);			
	return;
}

/*	------------------------------------------------------	*/
/*	w e b _ a g e n t _ t e r m i n a t e ( handle, form )	*/
/*	------------------------------------------------------	*/
private	void	web_agent_terminate( FILE * h, struct form_control * fptr )
{
	linefeed(h);
	abal_segment(h,"0");
	abal_pause(h,"Web Agent",1);
	abal_stop(h,1);
	abal_endseg(h,"0");
	abal_end(h,0);
	linefeed(h);
	web_agent_comment(h,"end of file",0);
	return;
}

/*	--------------------------------------------------	*/
/*	g e n e r a t e _ w e b _ a g e n t ( form, mode )	*/
/*	--------------------------------------------------	*/

public	int	generate_web_agent(struct form_control * fptr, int automatic, int debugme, int nature /* 0 : normal, 1 : special */ )
{
	FILE *	handle;
	char *	nomfic;

	DebugAgent = debugme;

	/* -------------------------------------------------------------- */
	/* Check entry conditions, allocate filename and start production */
	/* -------------------------------------------------------------- */
	if (!( fptr ))							return;
	else if (!( WebAgent = fptr->identifier ))			return;
	else if (!( fptr->prodname ))					return;
	else if (!( nomfic = allocate_string( fptr->prodname )))	return;
	else if (!( nomfic = enforce_extension( nomfic, ".as" )))	return;
	else if (!( nomfic = use_temporary_directory( nomfic )))	return;
	else if (!( handle = open_production_target( nomfic, 0 ))) {
		liberate( nomfic );
		return;
		}

	/* ------------------------ */
	/* Ensure clean module list */
	/* ------------------------ */
	drop_module_control();

	/* --------------------------------- */
	/* Generate dependance and structure */
	/* --------------------------------- */
	web_agent_startup( handle, fptr );

	/* --------------------------- */	
	/* Generate Instance Container */
	/* --------------------------- */	
	web_agent_instance( handle, fptr );

	/* ----------------------- */
	/* Forms Member Generation */
	/* ----------------------- */
	abal_forms_members(handle,fptr);

	/* ----------------------- */
	/* Forms Method Generation */
	/* ----------------------- */
	abal_forms_methods(handle,fptr);

	/* --------------------------- */	
	/* Object Container Construct  */
	/* --------------------------- */	
	web_agent_oncreate( handle, fptr );

	/* --------------------------- */	
	/* Object Container Destructor */
	/* --------------------------- */	
	web_agent_onremove( handle, fptr );

	/* --------------------------- */	
	/* Integrate Member State Info */
	/* --------------------------- */	
	web_agent_request( handle, fptr );

	/* --------------------------- */	
	/* Generate Output for Display */
	/* --------------------------- */	
	web_agent_onshow( handle, fptr );

	/* -------------------------- */	
	/* Web Agent Event Dispatcher */
	/* -------------------------- */	
	web_agent_onevent( handle, fptr );

	/* -------------------------- */	
	/* Web Agent Focus Dispatcher */
	/* -------------------------- */	
	web_agent_onfocus( handle, fptr );

	/* --------------------- */	
	/* Web Agent Termination */
	/* --------------------- */	
	web_agent_terminate( handle, fptr );

	/* --------------------------------- */
	/* Terminate production of web agent */
	/* --------------------------------- */
	close_production_target( handle, nomfic );

	/* ------------------------ */
	/* Ensure clean module list */
	/* ------------------------ */
	drop_module_control();

	return;

}


#endif	/* _singagent_c */
	/* ------------ */


