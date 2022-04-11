#ifndef	_abalform_c
#define	_abalform_c

#include "singplus.h"
#include "vcommand.h"
#include "singappl.h"
extern	struct	application_parameters Application;
#define	__QUOTE	0x0022
#ifdef WIN32
private	void	abal_detect_trigger_events( FILE * h, int margin );
#endif

struct	window_control * connect_production_window();
char *	language_prefix(int nl);

public char *	postfix_string( char * aptr, char * bptr )
{
	char	*	rptr;
	if (!( aptr )) {
		if ( bptr )
			return( allocate_string( bptr ) );
		else	return( bptr );
		}
	else if (!( bptr )) 
		return( allocate_string( aptr ) );
	else if (!( rptr = allocate( strlen(aptr) + strlen(bptr) + 16 ) ))
		return( rptr );
	else	{
		sprintf(rptr,"%s%s",aptr,bptr);
		return(rptr);
		}
}

/*	---------	--------	*/
/*	ABAL FORM	ON START	*/
/*	---------	--------	*/

public	char *	forms_modules(
		struct form_control * fptr,
		char		    * sptr)
{
	char *	rptr=(char *) 0;
	struct	form_item * iptr;
/*
	if ( fptr->language == _GENERATE_HTML )
		return( sptr );
 */
	for ( 	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		switch ((iptr->Contents.style & _FRAME_TYPE )) {
			case	_DATA_FRAME	:
				if ( iptr->Contents.datatype == _WIDGET_MODULE ) {
					if (!( method_is_valid( abal_payload(iptr) ) ))
						continue;
					if (!( sptr ))
						sptr = allocate_string(abal_payload(iptr));
					else if ((rptr = allocate( strlen( sptr ) + strlen(abal_payload(iptr)) + 8 )) != (char *) 0) {
						sprintf(rptr,"%s %s",sptr,abal_payload(iptr));
						liberate( sptr );
						sptr = rptr;
						}
					}
				break;

			case	_TAB_FRAME	:
			case	_BUTTON_FRAME	:
				if ( iptr->Contents.datatype == _WIDGET_MODULE ) {
					if (!( method_is_valid( iptr->Contents.format ) ))
						continue;
					if (!( sptr ))
						sptr = allocate_string(iptr->Contents.format);
					else if ((rptr = allocate( strlen( sptr ) + strlen(iptr->Contents.format) + 8 )) != (char *) 0) {
						sprintf(rptr,"%s %s",sptr,iptr->Contents.format);
						liberate( sptr );
						sptr = rptr;
						}
					}

			}
		}
	return( sptr );
}

public	void	abal_page_control( FILE * h )
{
	if ( Abal_Config.page_control ) {
		if ( Context.Form->pages != 0 ) 
			fprintf(h,"\tPageNumber=0;");
		else	fprintf(h,"\tPageNumber=1;");
		linefeed(h);
		}
	return;
}


public	void	abal_visual_forward(FILE * h,char * prefix,int mode)
{
	linefeed(h);
	if ( mode ) {
		/* not a module */
		/* ------------ */
		fprintf(h,"%s %s %s() : %c",__abal_keyword_forward,__abal_keyword_proc,__abal_method_oncreate,0x0025);
		linefeed(h);

		fprintf(h,"%s %s %s%s() : %c",__abal_keyword_forward,__abal_keyword_proc,prefix,__abal_method_remove,0x0025);
		linefeed(h);
		}
	else	{
		/* is a module */
		/* ----------- */
		fprintf(h,"%s ",__abal_keyword_forward);
		abal_signature(h,prefix,__abal_method_create, Abal_Config.members, Context.Form );
		fprintf(h,"%s ",__abal_keyword_forward);
		abal_signature(h,prefix,__abal_method_remove, Abal_Config.members, Context.Form );
		}

	fprintf(h,"%s %s %s%s() : %c",__abal_keyword_forward,__abal_keyword_proc,prefix,__abal_method_hide,0x0025);
	linefeed(h);

	fprintf(h,"%s %s %s%s() : %c",__abal_keyword_forward,__abal_keyword_proc,prefix,__abal_method_show,0x0025);
	linefeed(h);

	fprintf(h,"%s %s %s%s() : %c",__abal_keyword_forward,__abal_keyword_proc,prefix,__abal_method_event,0x0025);
	linefeed(h);

	fprintf(h,"%s %s %s%s() : %c",__abal_keyword_forward,__abal_keyword_proc,prefix,__abal_method_focus,0x0025);
	linefeed(h);

	fprintf(h,"%s %s %s%s() : %c",__abal_keyword_forward,__abal_keyword_proc,prefix,__abal_method_lose_focus,0x0025);
	linefeed(h);

	if (!( mode )) {
		/* is a module */
		/* ----------- */
		fprintf(h,"%s ",__abal_keyword_forward);
		abal_signature(h,Context.Form->identifier,"\0", Abal_Config.members, Context.Form );
		}
	abal_forward_positionat(h,Context.Form);
	return;
}


public	void	abal_overlay_dependance( FILE * h )
{
	struct	form_control * fptr;

	if (!( fptr = Context.Form ))
		return;
	if ( fptr->dependance) {
		abal_dependance(h,fptr->dependance,1);
		}

	abal_comment(h,"Overlay Object Procedure Signature",0);
	abal_comment(h,"Visual Object Standard Interface ",0);

	if (!( fptr->OnPreConstr )) {
		fprintf(h,"%s %s preconstruction(%s,ptr a$,ptr b$,ptr c$, ptr d$,ptr e$) : %c ",__abal_keyword_forward,__abal_keyword_proc,__abal_overlay_object,0x0025);
		linefeed(h);
		}
	else	AbalFormsMethodSignature(h,fptr->OnPreConstr,__abal_keyword_forward,__abal_overlay_object);

	if (!( fptr->OnPostDestr )) {
		fprintf(h,"%s %s postdestruction(%s,ptr a$,ptr b$,ptr c$, ptr d$,ptr e$) : %c ",__abal_keyword_forward,__abal_keyword_proc,__abal_overlay_object,0x0025);
		linefeed(h);
		}
	else	AbalFormsMethodSignature(h,fptr->OnPostDestr,__abal_keyword_forward,__abal_overlay_object);

	fprintf(h,"%s %s %s(%s, ptr argp$, argl%c ) : %c",
		__abal_keyword_forward,__abal_keyword_proc,__abal_method_oncreate,__abal_overlay_object,
		0x0025,0x0025 );
		linefeed(h);
	fprintf(h,"%s %s On%s(%s) : %c",__abal_keyword_forward,__abal_keyword_proc,__abal_method_remove,__abal_overlay_object,0x0025);
	linefeed(h);

	fprintf(h,"%s %s On%s(%s) : %c",__abal_keyword_forward,__abal_keyword_proc,__abal_method_hide,__abal_overlay_object,0x0025);
	linefeed(h);

	fprintf(h,"%s %s On%s(%s) : %c",__abal_keyword_forward,__abal_keyword_proc,__abal_method_show,__abal_overlay_object,0x0025);
	linefeed(h);

	fprintf(h,"%s %s On%s(%s) : %c",__abal_keyword_forward,__abal_keyword_proc,__abal_method_event,__abal_overlay_object,0x0025);
	linefeed(h);

	fprintf(h,"%s %s On%s(%s) : %c",__abal_keyword_forward,__abal_keyword_proc,__abal_method_focus,__abal_overlay_object,0x0025);
	linefeed(h);

	fprintf(h,"%s %s On%s(%s) : %c",__abal_keyword_forward,__abal_keyword_proc,__abal_method_exec,__abal_overlay_object,0x0025);
	linefeed(h);

	fprintf(h,"%s %s On%s(%s,gmode%c) : %c",__abal_keyword_forward,__abal_keyword_proc,__abal_method_attach,__abal_overlay_object,0x0025,0x0025);
	linefeed(h);

	fprintf(h,"%s %s On%s(%s) : %c",__abal_keyword_forward,__abal_keyword_proc,__abal_method_detach,__abal_overlay_object,0x0025);
	linefeed(h);

	switch ( fptr->formflags & _FORM_TYPE_FLAGS ) {
		case	_FORM_TYPE_DIALOG	:
		case	_FORM_TYPE_EVENT 	:
			fprintf(h,"%s %s On%s(%s) : %c",__abal_keyword_forward,__abal_keyword_proc,__abal_method_lose_focus,__abal_overlay_object,0x0025);
			linefeed(h);
		}

	if (( fptr->isdynamic ) && (!( fptr->PositionAt ))) {
		fprintf(h,"%s %s On%s(%s,x%c,y%c)",__abal_keyword_forward,__abal_keyword_proc,"PositionAt",__abal_overlay_object,0x0025,0x0025);
		linefeed(h);
		}
	abal_resize_method_forward(h,Context.Form,"On",1);

	abal_comment(h,"Visual Object Derived Interface ",0);
	abal_comment(h,"Public Forms Interface Methods ",0);
	abal_forms_method_forward(h,fptr,1);
	return;
}

private	void	abal_private_dependance( FILE * h, struct form_control * fptr )
{
	abal_comment(h,"Private Forms Method Interface ",0);

	abal_sort_method_forward(h,fptr,fptr);

	if (( fptr->isprogram ) && ( fptr->isoverlay ))  {
		abal_forms_method_forward(h,fptr,2);
		if ( fptr->dependance) {
			abal_dependance(h,fptr->dependance,2);
			}
		}
	else	{
		abal_forms_method_forward(h,fptr,0);
		if ( fptr->dependance) {
			abal_dependance(h,fptr->dependance,3);
			}
		}
	return;
}

public	void	abal_pragmas( FILE * h, struct form_control * fptr )
{
	if ( fptr->abal.flags & 1 ) {
		fprintf(h,"#mem %u",fptr->abal.diezemem );
		linefeed(h);
		}
	if ( fptr->abal.flags & 2 ) {
		fprintf(h,"#files %u",fptr->abal.diezefiles );
		linefeed(h);
		}
	if ( fptr->abal.flags & 4 ) {
		fprintf(h,"#stack %u",fptr->abal.diezestack );
		linefeed(h);
		}
	if ( fptr->abal.flags & 8 ) {
		fprintf(h,"#heap %u",fptr->abal.diezemem );
		linefeed(h);
		}
	if ( fptr->abal.flags & 16 )
		fprintf(h,"#pragma ignore_case off");
	else	fprintf(h,"#pragma ignore_case on");
	linefeed(h);
	if ( fptr->abal.flags & 32 )	
		fprintf(h,"#pragma optimise tables on");
	else	fprintf(h,"#pragma optimise tables off");
	linefeed(h);
	if ( fptr->abal.flags & 64 ) {
		fprintf(h,"#pragma tokensize %u",fptr->abal.tokensize );
		linefeed(h);
		}
	if ( fptr->abal.flags & 128) {
		fprintf(h,"#pragma labelsize %u",fptr->abal.labelsize );
		linefeed(h);
		}
	if ( fptr->abal.flags & 512 ) {
		if ( fptr->abal.pragmafile )
			abal_dependance(h,fptr->abal.pragmafile,2);
		else	abal_dependance(h,"pragmas.as",2);
		}
	return;
}


public	void	abal_visual_dependance( FILE * h, struct form_control * fptr )
{
	struct	form_item * iptr;
	char		  * sptr;
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if (( iptr->Contents.style & _FRAME_TYPE) != _DATA_FRAME)
			continue;
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			continue;
		else if (( iptr->Contents.datatype != _WIDGET_CLASS ) && ( iptr->Contents.datatype != _WIDGET_POINTER))
			continue;
		else if (!( sptr = abal_payload( iptr ) ))
			continue;
		else if (!( sptr = allocate_string( sptr ) ))
			continue;
		else if (!( sptr = enforce_extension( sptr, CLASS_EXTENSION ) ))
			continue;
		else	{
			abal_include(h,sptr);
			liberate( sptr );
			}
		}
	return;
}

public	void	abal_argv_control( FILE * h, struct form_control * fptr )
{
	int	nbargv;

	fptr->interfaceitems = 0;

	if (( fptr->isprogram ) && ( fptr->isoverlay )) 
		calculate_interface_items(fptr);

	nbargv = (fptr->interfaceitems + fptr->argvcount);

	abal_dcl(h,"Arg","N",_ABAL_WORD,0,0,0,NULL);
	abal_arg(h,"Arg","B",_ABAL_STRING,fptr->argvlen*nbargv,0,0,NULL);
	abal_dcl(h,"Arg","V",_ABAL_STRING,fptr->argvlen,nbargv,0,NULL);
	abal_dcl(h,"Arg","C",_ABAL_WORD,0,0,0,NULL);
	return;
}

public	void	abal_form_onstart( FILE * h, int hasobjects )
{
	if ( hasobjects )
		aplus_visual_apl( h );

	/* these pragmas apply to the visual classes */
	/* ----------------------------------------- */
	if ( Abal_Config.generate_program )
		abal_pragmas(h,Context.Form );
	else if ( Abal_Config.generate_overlay )
		abal_pragmas(h,Context.Form );

	abal_user(h,__abal_visual_def);

	abal_visual_dependance(h,Context.Form);

	if ( Context.Form->dependance)
		abal_dependance(h,Context.Form->dependance,0);

	if ( Abal_Config.generate_program ) {
		abal_program(h,Abal_Config.cname);
		}
	else if ( Abal_Config.generate_overlay ) {
		abal_module(h,Abal_Config.cname);
		}

	abal_include(h,__abal_mimo_as);
	abal_include(h,"visidef.as");

	abal_widget_constants(h, Context.Form );

	/* Overlay Parameter Reception Mechanism */
	/* ------------------------------------- */
	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay )) {
		abal_argv_control( h, Context.Form );
		}

	if ( hasobjects ) {
		aplus_visual_resolution(h);
		}

	/* Instance Structure if Required */
	/* ------------------------------ */
	Abal_Config.members = generate_abal_structure(h,Context.Form);

	if ( Abal_Config.generate_program ) {
		if ( Abal_Config.generate_overlay ) {
			abal_overlay_dependance(h);
			}
		else 	{
			if ( Context.Form->formflags & _FORM_COMMANDLINE ) {
				abal_argv_control( h, Context.Form );
				}
			abal_visual_forward(h,"On",1);
			}
		Abal_Config.members = 0;
		}
	else if ( Abal_Config.generate_overlay ) {
		abal_visual_forward(h,Abal_Config.cname,0);
		}
	return;
}

public	void	abal_form_hidepages( FILE * h )
{
	struct form_item * iptr;
	int		   thispage;
	int		   started=0;
	/* Page by Page Generation */
	/* ----------------------- */
	for ( 	thispage=Context.Form->pages;
		thispage > 0 ; thispage-- ) {

		/* Item by Item analysis */
		/* --------------------- */
		for (	started=0,
			iptr=Context.Form->last;  
			iptr != (struct form_item *) 0; 
			iptr = iptr->previous)  {

			/* Unsized items are discarded */
			/* --------------------------- */
			if ((!( iptr->Contents.w  ))
			||  (!( iptr->Contents.h  )))
				continue;

			/* other page items are also discarded */
			/* ----------------------------------- */
			else if ( iptr->Contents.page != thispage )
				continue;

			if (( thispage != 0)
			&&  (!( started ))) {
				fprintf(h,"\tif (PageNumber=%u)",thispage);
				linefeed(h);
				started = 1;
				}

			generate_abal_hide(h,iptr,1);


			}
		if ( started ) {
			abal_endif(h,1);
			started = 0;
			}
		}

	fprintf(h,"\tPageNumber=0;");
	linefeed(h);
	return;
}


public	void	abal_form_hide( FILE * h )
{
	struct form_item * iptr;

	for (	iptr=Context.Form->last;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->previous ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else	generate_abal_hide(h,iptr,0);
		}
	return;
}

/*	---------	-------		*/
/*	ABAL FORM	ON HIDE		*/
/*	---------	-------		*/


public	void	abal_form_onhide( FILE * h )
{
	struct form_item * iptr;
	struct form_item * wptr=(struct form_item *) 0;

	abal_onhide_methods( h, __abal_method_hide );

	/* Allow widget methods to be generated */
	/* ------------------------------------ */
	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		switch ( (iptr->Contents.style & _FRAME_TYPE ) ) {
			case	_WINDOW_FRAME	:
				if (( Context.Form->ispopup )
				||  ( Context.Form->resizeauto ))
					wptr = iptr;
				break;
			}
		}

	/* Generate the Form HIDE method activetool the above */
	/* --------------------------------------------- */
	abal_procedure(h,Abal_Config.cname,__abal_method_hide,0,(struct form_control *) 0);
	abal_error_trap(h,1,1);

	if ( Context.Form->pages != 0 ) 
		abal_form_hidepages( h );
	else	abal_form_hide( h );

	if (( Context.Form->ispopup )
	||  ( Context.Form->resizeauto )) {
		if ( wptr != (struct form_item *) 0) { 
			abal_form_popup_put( h, wptr );
			}
		}

	abal_returni(h,0,1);
	abal_error_abort(h,1,1);
	abal_error_return(h,__abal_keyword_status,1);
	abal_endproc(h);

	return;
}

public	int	abal_visual_element(FILE * h, struct form_item * iptr, char * sptr, char * mptr, int i)
{
	int	item=0;
	char *	vptr;
	indent(h,i);
	if (!( iptr )) {
		fprintf(h,"%s = VisualStyle(0,0,Conf(69),Conf(68)",__abal_keyword_status);
		fprintf(h,",");
		quoted_string(h,sptr);
		fprintf(h,",%u,",strlen( sptr ));
		if ( mptr ) {
			quoted_string(h,mptr);
			fprintf(h,",%u)",strlen( mptr ));
			}
		else	{
			quoted_string(h," ");
			fprintf(h,",%u)",strlen(" "));
			}
		}
	else if ((sptr != (char *) 0)
	     ||  (( sptr = iptr->Contents.stylesheet) != (char *) 0)) {
		while ((vptr = selection_item(item,sptr )) != (char *) 0) {		
			if (!( item )) 
				fprintf(h,"if (");
			else	{
				fprintf(h," '");
				linefeed(h);
				indent(h,i);
				fprintf(h,"or ");
				}
			item++;
			fprintf(h,"( VisualStyle(" );
			widget_position(h,iptr,0,0);
			if ((iptr->Contents.style & _FRAME_TYPE) == _EDIT_FRAME)
				widget_dimensions(h,iptr,2,2);
			else	widget_dimensions(h,iptr,0,0);
			if ( *vptr == _UNQUOTED_STRING ) {
				fprintf(h,",");
				variable_value(h,(vptr+1));
				fprintf(h,",");
				variable_lendol(h,(vptr+1));
				}
			else	{
				fprintf(h,",");
				quoted_string(h,vptr);
				fprintf(h,",%u",strlen(vptr));
				}
			if ((iptr->Contents.style & _FRAME_TYPE) == _EDIT_FRAME) {
				fprintf(h,",b_%s",iptr->Contents.name);
				length_parameter(h,iptr->Contents.size);
				}
			else	{
				constant_parameter(h,iptr );
				constant_lendol_parameter(h,iptr);
				}
			fprintf(h,") <> 0)");
			liberate( vptr );
			}
		if ( item ) {
			fprintf(h,")");
			}
		}
	linefeed(h);
	return(item);
}

#ifdef	ABAL32A
public	void	css_generate_stylesheet( char * filename, struct form_control * fptr )
{
	FILE			* h;
	struct	form_item 	* iptr;
	char 			* vptr;	
	char 			* sptr;	
	struct	element_style	* eptr;
	int			  item=0;

	if (!( h = open_production_target(filename,0))) {
		printf("error generating stylsheet : %s \n",filename);
		return;
		}

	production_banner( h, _GENERATE_C, fptr->identifier, filename );
	for ( 	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if (!( sptr = iptr->Contents.stylesheet))
			continue;
		else	{
			item =0;
			while ((vptr = selection_item(item++,sptr )) != (char *) 0) {		
				if (!( eptr = resolve_style_class( vptr ) ))
					continue;
				else	GenerateStyleClass((void*)0,h,eptr );
				}
			}
		}
	close_production_target( h, filename );
	return;
}
#endif	/* ABAL32A */
	/* ------- */

public	void	abal_visual_stylesheet(FILE * h, char * sptr, int margin )
{
	indent(h,1);
	fprintf(h,"%s = %s(_VISUAL_STYLE,",__abal_keyword_status,__abal_visual_control);
	if ( *sptr != _UNQUOTED_STRING ) {
		quoted_string(h,sptr);
		fprintf(h,",%u)",strlen( sptr));
		}
	else	{
		sptr++;
		fprintf(h,"%s,Len$(%s))",sptr,sptr);
		}
	linefeed(h);
	return;
}

public	void	abal_form_style( FILE * h, struct form_control * fptr, int background )
{
	char *	sptr;
	if ( method_is_valid((sptr = fptr->stylesheet)) ) {
		abal_visual_stylesheet(h,sptr,1);
		}
#ifdef	ABAL32A
	if ( fptr->styling ) {
		if ((sptr = allocate_string( fptr->prodname )) !=(char *) 0) {
			if (( sptr = enforce_extension( sptr, CSS_EXTENSION )) != (char *) 0) {
				abal_visual_stylesheet(h,sptr,1);
				css_generate_stylesheet( sptr, fptr );
				liberate( sptr );
				}
			}			
		}
#endif
	if ( background ) {
		if ((sptr = method_is_valid(  fptr->clearscreen)) != (char *) 0)
			abal_visual_element(h,(struct form_item *)0,fptr->clearscreen," ",1);
		}
	return;
}

public	void	abal_visual_control(FILE * h,struct form_control * fptr)
{
	indent(h,1);
	fprintf(h,"%s = %s(_VISUAL_TITLE,",__abal_keyword_status,__abal_visual_control);
	quoted_string(h,fptr->identifier);
	fprintf(h,",%u)",strlen( fptr->identifier ));
	linefeed(h);
	indent(h,1);
	fprintf(h,"%s = %s(_VISUAL_ICON,",__abal_keyword_status,__abal_visual_control);
	quoted_string(h,"exa");
	fprintf(h,",%u)",strlen( "exa" ));
	linefeed(h);
	abal_form_style(h,fptr,1);
	return;
}

public	void	abal_load_visual_palette(FILE * h, int tabul )
{
	char	*	sptr;
	indent(h,tabul);
	fprintf(h,"%s(%s(",
		__abal_keyword_if,__abal_visual_palette);
	if (method_is_valid((sptr = Context.Form->palette) ) ) {
		quoted_string(h,sptr);
		fprintf(h,",%u) <> 0 )",strlen( sptr ));
		}
	else if ( method_is_valid((sptr = application_palette()) ) ) {
		quoted_string(h,sptr);
		fprintf(h,",%u) <> 0 )",strlen( sptr ));
		}
	else if (!(SingConf)) {
		quoted_string(h,"standard.rgb");
		fprintf(h,",%u) <> 0 )",strlen( "standard.rgb" ));
		}
	else	{
		quoted_string(h,SingConf->palette);
		fprintf(h,",%u) <> 0 )",strlen( SingConf->palette ));
		}
	linefeed(h);
	abal_raise(h,40,3); 
	abal_endif(h,2);
	return;
}

public	void	abal_visual_startup(FILE * h,int gmode,int resizeauto)
{
	char *	sptr;
	char *	nptr;
	int	truecolour=256;
	if ( Context.Form ) {
		if ( Context.Form->abal.flags & 256 )
			truecolour += 512;
		}
	indent(h,1);

	if (!( gmode )) {

		/* ------------------------------------------ */
		/* ceci assure le mode graphique pour windows */
		/* ------------------------------------------ */
		fprintf(h,"Event(82)=1"); linefeed(h); 	indent(h,1);

		if ( method_is_valid((nptr = project_configuration()))) {
			fprintf(h,"%s = %s(_VISUAL_CONFIG,",__abal_keyword_status,__abal_visual_control);
			quoted_string(h,nptr);
			if (!( nptr ))
				fprintf(h,",1)");
			else 	fprintf(h,",%u)",strlen( nptr ));
			linefeed(h);
			indent(h,1);
			}
		if (resizeauto) {
			fprintf(h,"%s (len$(env(\"GIGOMODE\")) = 0)",__abal_keyword_if);
			linefeed(h); indent(h,2);
			if ( TargetBiosMode != 7 )
				fprintf(h,"Status=%s(%u+%u)",__abal_visual_initialise,TargetBiosMode,truecolour);
			else	fprintf(h,"Status=%s(%u,%u,%u)",__abal_visual_activate,TargetBiosWidth,TargetBiosHeight,truecolour);
			linefeed(h); abal_else(h,1);	indent(h,2);
			fprintf(h,"%s (conv(env(\"GIGOMODE\")) < 6)",__abal_keyword_if);
			linefeed(h); indent(h,3);
			fprintf(h,"Status=%s(conv(env(\"GIGOMODE\"))+%u)",__abal_visual_initialise,truecolour);
			linefeed(h); abal_else(h,2);
			indent(h,3);
			fprintf(h,"x_internal=conv(env(\"GIGOXSIZE\"))");
			linefeed(h); indent(h,3);
			fprintf(h,"y_internal=conv(env(\"GIGOYSIZE\"))");
			linefeed(h); indent(h,3);
			fprintf(h,"%s ((x_internal=0) OR (y_internal=0))",__abal_keyword_if);
			linefeed(h); indent(h,4);
			fprintf(h,"x_internal=1600");
			linefeed(h); indent(h,4);
			fprintf(h,"y_internal=1200");
			linefeed(h); abal_endif(h,3);
			indent(h,3);
			fprintf(h,"Status=%s(x_internal,y_internal,%u)",__abal_visual_activate,truecolour);
			linefeed(h); abal_endif(h,2);
			abal_endif(h,1);
			indent(h,1);
			fprintf(h,"%s (Status = -1 )",__abal_keyword_if);
			}
		else if ( TargetBiosMode != 7 ) {
			fprintf(h,"%s(%s(%u+%u) = -1 )",
				__abal_keyword_if,__abal_visual_initialise,TargetBiosMode,truecolour);
			}
		else	{
			fprintf(h,"%s(%s(%u,%u,%u) = -1 )",
				__abal_keyword_if,__abal_visual_activate,TargetBiosWidth,TargetBiosHeight,truecolour);
			}
		}
	else	{
		fprintf(h,"%s(%s(gmode+%u) = -1 )",
			__abal_keyword_if,__abal_visual_initialise,truecolour);
		}
	linefeed(h);
	abal_raise(h,56,2); 
	abal_else(h,1);
		abal_load_visual_palette(h,2);
	abal_endif(h,1);
	generate_abal_fonts(h);
	return;
}

private	void	generate_abal_onhelp_switch( FILE * h )
{
	struct	form_item * iptr;
	int	margin=3;
	indent(h,margin++); 
	fprintf(h,"if (( MouseType = _MIMO_DOWN ) && ( MouseButton = _MIMO_RIGHT)) ");
	linefeed(h);
		abal_select(h,__abal_focus_item,margin);
		for (	iptr=Context.Form->first;  
			iptr != (struct form_item *) 0; 
			iptr = iptr->next )  {
			if (!( detect_widget_help( iptr ) ))
				continue;
			else if (!( iptr->Contents.focus ))
				continue;
			else	{
				indent(h,margin);
				fprintf(h,"Case %u",iptr->Contents.focus);
				linefeed(h);
				indent(h,margin++);
				fprintf(h,"if (");
				invoke_abal_widget_help(h,iptr);
				fprintf(h," != 0) ");
				linefeed(h);
				indent(h,margin--);
				fprintf(h,"Goto &Continue");
				linefeed(h);
				indent(h,margin--);
				fprintf(h,"Endif");
				linefeed(h);
				}
			}
		indent(h,margin);
		fprintf(h,"EndSel");
		linefeed(h);

	indent(h,--margin);
	fprintf(h,"Endif");
	linefeed(h);
	return;
}

private	int	abal_plain_text(FILE * h, char * sptr,int * linesize )
{
	int	c;
	int	linecount=0;
	int	width=0;
	if ( h  ) {
		indent(h,1);
		fprintf(h,"HelpText(%u)=%c",linecount+1,__QUOTE);
		}
	while ((c =  *(sptr++)) != 0) {
		if ( c == '\r' )
			continue;
		else if ( c == '"' )
			continue;
		else if ( c == '\t' ) { 
			width++;
			if( width > *linesize ) { *linesize=width; }
			fprintf(h," ");
			}
		else if ( c == '\n') {
			if ( h ) { fprintf(h,"\\n"); }
			if( width > *linesize ) { *linesize=width; }
			width=0;			
			linecount++;
			}
		else 	{
			width++;
			if( width > *linesize ) { *linesize=width; }
			if ( h ) { fprintf(h,"%c",c); }
			}
		}
	if( width > *linesize ) { *linesize=width; }
	if ( h ) {
		fprintf(h," %c",__QUOTE);
		linefeed(h);
		}
	return( linecount );
}

private	void	abal_help_newline(FILE * h, int linecount )
{
	fprintf(h," %c",__QUOTE);
	linefeed(h);
	indent(h,1);
	fprintf(h,"HelpText(%u)=%c",linecount+1,__QUOTE);
	return;
}

private	char *	abal_consume_html_tag(FILE * h, char * sptr,int * linecount)
{
	int	closure=0;
	int	c;
	int	i=0;
	char	tagname[256];

	/* ensure next character is alpha */
	/* ------------------------------ */
	if ( *sptr != '/' ) { 
		if ((( *sptr <= 'z' ) && ( *sptr >= 'a'))
		||  (( *sptr <= 'Z' ) && ( *sptr >= 'A')))
			i = 0;
		else	{
			if ( h ) { fprintf(h,"<"); }
			return	sptr;
			}
		}

	/* collect uppercased tagname */
	/* -------------------------- */
	while ((c = *(sptr++)) != 0) {
		if ( c == '/' ) {
			if (!( i )) {
				closure=1;
				continue;
				}
			else	break;
			}
		if ((c >= 'a') && ( c <= 'z'))
			c -= ('a'-'A');
		if (( c <= 'A' ) || ( c >= 'Z' ))
			break;
		tagname[i++]=c;
		}
	/* terminate and test valid tag */
	/* ---------------------------- */
	tagname[i] = 0;

	if ( i > 0 ) {
		
		/* detect certain tag types */
		/* ------------------------ */
		if (( tagname[0] == 'P' ) && (!( tagname[1] ))) {
			if (!( closure )) {
				*linecount += 1;
				if ( h ) { abal_help_newline(h,*linecount); }
				*linecount += 1;
				if ( h ) { abal_help_newline(h,*linecount); }
				}
			else	{ 
				*linecount += 1; 
				if ( h ) { abal_help_newline(h,*linecount); }
				}
			}
		else if (( tagname[0] == 'B' ) && ( tagname[1] == 'R' ) && (!( tagname[2] ))) {
			if (!( closure )) {
				*linecount += 1; 
				if ( h ) { abal_help_newline(h,*linecount); }
				}
			}
		else if (( tagname[0] == 'T' ) && ( tagname[1] == 'R' ) && (!( tagname[2] ))) {
			if (!( closure )) {
				*linecount += 1;
				if ( h ) { abal_help_newline(h,*linecount); }
				}
			}
		else if (( tagname[0] == 'T' ) && ( tagname[1] == 'H' ) && (!( tagname[2] ))) {
			if (!( closure )) {
				*linecount += 1;
				if ( h ) { fprintf(h," "); }
				}
			}
		else if (( tagname[0] == 'T' ) && ( tagname[1] == 'D' ) && (!( tagname[2] ))) {
			if (!( closure )) {
				*linecount += 1;
				if ( h ) { fprintf(h," "); }
				}
			}
		else if (( tagname[0] == 'O' ) && ( tagname[1] == 'L' ) && (!( tagname[2] ))) {
			*linecount += 1;
			if ( h ) { abal_help_newline(h,*linecount); }
			}
		else if (( tagname[0] == 'U' ) && ( tagname[1] == 'L' ) && (!( tagname[2] ))) {
			*linecount += 1;
			if ( h ) { abal_help_newline(h,*linecount); }
			}
		else if (( tagname[0] == 'L' ) && ( tagname[1] == 'I' ) && (!( tagname[2] ))) {
			if (!( closure )) {
				*linecount += 1;
				if ( h ) { abal_help_newline(h,*linecount); }
				} 
			}
		else if (( tagname[0] == 'D' ) && ( tagname[1] == 'L' ) && (!( tagname[2] ))) {
			*linecount += 1;
			if ( h ) { abal_help_newline(h,*linecount); }
			}
		else if (( tagname[0] == 'D' ) && ( tagname[1] == 'T' ) && (!( tagname[2] ))) {
			if (!( closure )) {
				*linecount += 1;
				if ( h ) { abal_help_newline(h,*linecount); }
				}
			}
		else if (( tagname[0] == 'D' ) && ( tagname[1] == 'D' ) && (!( tagname[2] ))) {
			if (!( closure )) {
				*linecount += 1;
				if ( h ) { abal_help_newline(h,*linecount); }
				}
			}
		else if (( tagname[0] == 'D' ) && ( tagname[1] == 'I' )&& ( tagname[2] == 'V' ) && (!( tagname[3] ))) {
			*linecount += 1;
			if ( h ) { abal_help_newline(h,*linecount); }
			}
		else if (( tagname[0] == 'T' ) 
		     &&  ( tagname[1] == 'A' ) 
		     &&  ( tagname[2] == 'B' ) 
		     &&  ( tagname[3] == 'L' ) 
		     &&  ( tagname[4] == 'E' ) 
		     && (!( tagname[5] ))) {
			*linecount += 1;
			if ( h ) { abal_help_newline(h,*linecount); }
			}
		}
	/* scan past tag closure */
	/* --------------------- */ 
	while (( c != 0 ) && ( c != '>' )) { c = *(sptr++); }
	if (!( c ))
		return((char *) 0);
	else	return( sptr );
}

private	int	abal_html_text(FILE * h, char * sptr, int * linesize )
{
	int	oldlines=0;
	int	c;
	int	linecount=0;
	int	width=0;
	if ( h ) {
		indent(h,1);
		fprintf(h,"HelpText(%u)=%c",linecount+1,__QUOTE);
		}
	while ((c =  *(sptr++)) != 0) {
		if ( c == '\r' )
			continue;
		else if ( c == '"' )
			continue;
		else if ( c == '\t' ) {
			if ( width > 64 ) {
				linecount++;
				if ( h ) { abal_help_newline(h,linecount); }
				if( width > *linesize ) { *linesize=width; }
				width=0;
				}
			else	{
				width++;
				if( width > *linesize ) { *linesize=width; }
				if ( h ) { fprintf(h," "); }
				}
			continue;
			}
		else if ( c == '\n') {
			if ( width > 64 ) {
				linecount++;
				if ( h ) { abal_help_newline(h,linecount); }
				if( width > *linesize ) { *linesize=width; }
				width=0;
				}
			else	{
				width++;
				if( width > *linesize ) { *linesize=width; }
				if ( h ) { fprintf(h," "); }
				}
			continue;
			}
		else if ( c != '<' ) {
			if (( c == ' ' ) && ( width > 64 )) {
				linecount++;
				if ( h ) { abal_help_newline(h,linecount); }
				if( width > *linesize ) { *linesize=width; }
				width=0;
				}
			else 	{
				if ( h ) { fprintf(h,"%c",c); }
				width++;
				if( width > *linesize ) { *linesize=width; }
				}
			}
		else if (!( sptr = abal_consume_html_tag(h,sptr,&linecount) ))
			break;
		else if ( oldlines != linecount ) {
			oldlines = linecount;
			if( width > *linesize ) { *linesize=width; }
			width=0;
			}
		}
	if ( width ) { linecount++;  }
	if ( h ) {
		fprintf(h," %c",__QUOTE);
		linefeed(h);
		}
	if( width > *linesize ) { *linesize=width; }
	return( linecount );
}

private	void	abal_helptext_dimensions(FILE * h, char * sptr, int margin )
{
	int	linecount=0;
	int	linesize=0;
	switch ( (Context.Form->onlinehelp  & 7)) {
		case	1 : linecount = abal_plain_text((FILE *) 0,sptr,&linesize); break;
		case	2 : linecount = abal_html_text((FILE *) 0,sptr,&linesize); break;
		}
	indent(h,margin); fprintf(h,"HelpLines=%u",linecount);	linefeed(h);
	indent(h,margin); fprintf(h,"HelpColumns=%u",linesize);	linefeed(h);
	return;
}

private	void	abal_help_message(FILE * h, char * sptr, int margin )
{
	int	linesize=0;
	int	linecount=0;
	char *	optr="\0";
	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = "o";
	else	optr = "\0";
	indent(h,margin); fprintf(h,"Forget HelpText",__QUOTE);		linefeed(h);
	abal_helptext_dimensions(h,sptr,margin);
	indent(h,margin); fprintf(h,"if ((HelpLines > 0) and (HelpColumns > 0))",__QUOTE);
		linefeed(h);
		indent(h,++margin); fprintf(h,"Create HelpText(HelpColumns,HelpLines)",__QUOTE);
		linefeed(h);
		switch ( (Context.Form->onlinehelp & 7) ) {
			case	1 : linecount = abal_plain_text(h, sptr, &linesize ); break;
			case	2 : linecount = abal_html_text(h, sptr, &linesize );  break;
			}
		linefeed(h);
		indent(h,margin);
		fprintf(h,"Exit(%sHelp(%s))",Abal_Config.cname,optr);
		linefeed(h);
	indent(h,--margin);
	fprintf(h,"Endif");
	linefeed(h);
	return;
}

public	void	abal_widget_onhelp( FILE * h,struct form_control * fptr, struct form_item * iptr )
{
	int	i;
	char *	sptr;
	char * 	optr="\0";
	if ((!( fptr )) || (!( iptr )))
		return;

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = "ptr o$=10";
	else	optr = "\0";

	/* resolve symbolic accent encoding */
	/* -------------------------------- */
	for (i=0; i < MAXNATLANG; i++) { transcode_accents(&iptr->document[i],1); }

	linefeed(h);
	if ((iptr->Contents.style & _FRAME_TYPE) != _RADIO_FRAME)
		fprintf(h,"%s %sHelp(",__abal_keyword_proc,iptr->Contents.name);
	else	fprintf(h,"%s %s%uHelp(",__abal_keyword_proc,iptr->Contents.name,iptr->Contents.radio);
	fprintf(h,"%s) : %c",optr,0x0025);
	linefeed(h);
		/* Not an international form : first help slot */
		/* ------------------------------------------- */ 
		 if (!( fptr->formflags & _INTERNATIONAL )) {
			if ( method_is_valid((sptr = iptr->document[0])) ) {
				abal_help_message(h,sptr,1);
				}
			}

		/* not multilingual : test required language slot */
		/* ---------------------------------------------- */
		else if (!( fptr->formflags & _MULTILINGUAL )) {
			if ( method_is_valid((sptr = iptr->document[fptr->natlang])) ) {
				abal_help_message(h,sptr,1);
				}
			}

		/* multilingual : detect presence of help */
		/* -------------------------------------- */
		else	{
			indent(h,1);
			fprintf(h,"Select (NationalLanguage)");
			linefeed(h);
			for (i=0; i < MAXNATLANG; i++ ) {
				if ( method_is_valid((sptr = iptr->document[i])) ) {
					indent(h,1); fprintf(h,"Case %u ",i+1); linefeed(h);
					abal_help_message(h,sptr,2);
					}
				}
			indent(h,1);
			fprintf(h,"Default :: Exit(0);");
			linefeed(h);
			indent(h,1);
			fprintf(h,"EndSel");
			linefeed(h);
			}
		indent(h,1); fprintf(h,"Exit(0);"); linefeed(h);
	fprintf(h,"%s",__abal_keyword_endproc);
	linefeed(h);

	/* restore symbolic accent encoding */
	/* -------------------------------- */
	for (i=0; i < MAXNATLANG; i++) { transcode_accents(&iptr->document[i],2); }

	return;
}

public	void	abal_form_onhelp( FILE * h )
{
	struct	form_control * fptr;
	struct	form_item    * iptr;
	char 		     * optr="\0";
	if (!( fptr = Context.Form ))
		return;

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = "ptr o$=10";
	else	optr = "\0";

	fprintf(h,"%s %sHelp(",__abal_keyword_proc,Abal_Config.cname);
	fprintf(h,"%s) : %c",optr,0x0025);
	linefeed(h);
		abal_dcl(h,"hw","X",_ABAL_WORD,0,0,0,NULL);
		abal_dcl(h,"hw","Y",_ABAL_WORD,0,0,0,NULL);
		abal_dcl(h,"hw","W",_ABAL_WORD,0,0,0,NULL);
		abal_dcl(h,"hw","H",_ABAL_WORD,0,0,0,NULL);
		abal_dcl(h,"hw","P",_ABAL_WORD,0,0,0,NULL);
		abal_dcl(h,"hw","S",_ABAL_STRING,64,0,0,NULL);
		abal_dcl(h,"hw","L",_ABAL_WORD,0,0,0,NULL);
		indent(h,1); fprintf(h,"if ( ValidPtr(HelpText) = 0 ) :: Exit(0) :: Endif"); linefeed(h);
		indent(h,1); fprintf(h,"if ( MouseButton <> _MIMO_RIGHT ) :: Exit(0) :: Endif"); linefeed(h);
		indent(h,1); fprintf(h,"hwP=0"); linefeed(h);
		indent(h,1); fprintf(h,"Repeat"); linefeed(h);
		indent(h,2); fprintf(h,"hwX = MouseColumn"); linefeed(h);
		indent(h,2); fprintf(h,"hwY = MouseRow"); linefeed(h);
		indent(h,2); fprintf(h,"if ( HelpColumns = 0 ) :: HelpColumns = 64 :: Endif"); linefeed(h);
		indent(h,2); fprintf(h,"if ( HelpLines   = 0 ) :: HelpLines   =  4 :: Endif"); linefeed(h);
		indent(h,2); fprintf(h,"hwW = ((HelpColumns+2)*8)"); linefeed(h);
		indent(h,2); fprintf(h,"hwH = ((HelpLines+2)*16)"); linefeed(h);
		indent(h,2); fprintf(h,"if ((hwX+hwW) > Conf(69)) :: hwX = (Conf(69) - hwW) :: Endif"); linefeed(h);
		indent(h,2); fprintf(h,"if ((hwY+hwH) > Conf(68)) :: hwY = (Conf(68) - hwH) :: Endif"); linefeed(h);
		indent(h,2); fprintf(h,"if ( hwP = 0 )"); linefeed(h);
			indent(h,3); fprintf(h,"hwP = VisualBuffer(hwW,hwH)"); linefeed(h);
		indent(h,2); fprintf(h,"Endif"); linefeed(h);
		indent(h,2); fprintf(h,"if ( hwP > 0 )"); linefeed(h);
			indent(h,3); fprintf(h,"VisualGet(hwP,hwX,hwY)"); linefeed(h);
		indent(h,2); fprintf(h,"Endif"); linefeed(h);
		indent(h,2); fprintf(h,"hwS = %c%s%c",__QUOTE,"widget_help_frame",__QUOTE); linefeed(h);
		indent(h,2); fprintf(h,"VisualStyle(hwX,hwY,hwW,hwH,hwS,Len$(hwS),%c %c,0)",__QUOTE,__QUOTE); linefeed(h);
		indent(h,2); fprintf(h,"hwS = %c%s%c",__QUOTE,"widget_help_text",__QUOTE); linefeed(h);
		indent(h,2); fprintf(h,"For  hwL = 1 to HelpLines"); linefeed(h);
			indent(h,3); fprintf(h,"VisualStyle(hwX+8,hwY+(hwL*16),hwW,16,hwS,Len$(hwS),HelpText(hwL),Len$(HelpText(hwL)))"); linefeed(h);
		indent(h,2); fprintf(h,"Next hwL"); linefeed(h);
		indent(h,2); fprintf(h,"Do :: if ( VisualKey(1) = 256) :: VisualEvent(MouseEvent) :: Break :: Endif :: Loop"); linefeed(h);
		indent(h,2); fprintf(h,"if ( hwP > 0 )"); linefeed(h);
			indent(h,3); fprintf(h,"VisualPut(hwP,hwX,hwY)"); linefeed(h);
		indent(h,2); fprintf(h,"Endif"); linefeed(h);
		indent(h,1); fprintf(h,"Until( MouseType = _MIMO_UP )"); linefeed(h);
		indent(h,1); fprintf(h,"if ( hwP > 0 )"); linefeed(h);
			indent(h,2); fprintf(h,"VisualDrop(hwP)"); linefeed(h);
		indent(h,1); fprintf(h,"Endif"); linefeed(h);
		indent(h,1); fprintf(h,"Remove HelpText"); linefeed(h);
		indent(h,1); fprintf(h,"Exit(1)"); linefeed(h);
	fprintf(h,"%s",__abal_keyword_endproc);
	linefeed(h);

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if (!( detect_widget_help( iptr ))) 
			continue;
		else	abal_widget_onhelp(h,fptr, iptr );
		}
	return;
}


public	void	abal_visual_closure(FILE * h)
{
	indent(h,1);
	fprintf(h,"%s(%s()= -1)",__abal_keyword_if,__abal_visual_liberate);
	linefeed(h);
		abal_raise(h,56,2); 
	abal_endif(h,1);
	return;
}

public	void	abal_init_global(FILE * h)
{
	indent(h,1);
	fprintf(h,"InitGlobal");
	linefeed(h);
	return;
}

public	void	abal_overlay_attach( FILE * h, int mode ) /* mode : 0 : module , 1 : Overlay */
{
	linefeed(h);
	if ( mode ) {
		fprintf(h,"%s %s%s(%s,gmode%c) : %c",
			__abal_keyword_proc,
			Abal_Config.cname,__abal_method_attach,__abal_overlay_object,
			0x0025,0x0025 );
		}
	else	{
		fprintf(h,"%s %s%s(gmode%c) : %c",
			__abal_keyword_proc,
			Abal_Config.cname,__abal_method_attach,
			0x0025,0x0025 );
		}

	linefeed(h);
	abal_error_trap(h,1,1);
	abal_visual_startup(h,1,0);
	abal_returni(h,0,1);
	abal_error_abort(h,1,1);
	abal_error_return(h,__abal_keyword_status,1);
	abal_endproc(h);
	return;
}

public	void	abal_overlay_detach( FILE * h, int mode )
{
	linefeed(h);
	if ( mode ) {
		fprintf(h,"%s %s%s(%s) : %c",
			__abal_keyword_proc,
			Abal_Config.cname,__abal_method_detach,__abal_overlay_object,
			0x0025 );
		}
	else	{
		fprintf(h,"%s %s%s() : %c",
			__abal_keyword_proc,
			Abal_Config.cname,__abal_method_detach,
			0x0025 );
		}
	linefeed(h);
	abal_error_trap(h,1,1);
	abal_visual_closure(h);
	abal_returni(h,0,1);
	abal_error_abort(h,1,1);
	abal_error_return(h,__abal_keyword_status,1);
	abal_endproc(h);
	return;
}

public	void	open_overlay_create( FILE * h )
{
	linefeed(h);
	fprintf(h,"%s %s%s(%s, ptr argp$, argl%c ) : %c",
		__abal_keyword_proc,
		Abal_Config.cname,__abal_method_create,__abal_overlay_object,
		0x0025,0x0025 );

	linefeed(h);
	abal_error_trap(h,1,1);
	indent(h,1);
	fprintf(h,"%s argp(argl)",__abal_keyword_alter);
	linefeed(h);
	indent(h,1);	fprintf(h,"ArgB = argp");			linefeed(h);
	indent(h,1);	fprintf(h,"ArgN = %u",Context.Form->argvcount+Context.Form->interfaceitems);
			linefeed(h);
	indent(h,1);
	fprintf(h,"%s=Main()",__abal_keyword_status);
	linefeed(h);
	/* initialise_abal_fonts(h); */
	generate_abal_fonts(h);
	return;
}


public 		void	generate_position_control(
		FILE * h,
		struct form_item * iptr
		)
{
	struct	form_control * fptr;
	int	wy=0;
	int	wx=0;
	/* Generate Position and Dimensions Variables */
	if (( iptr->Contents.style & _FRAME_TYPE ) == _WINDOW_FRAME ) {
		if ((!( fptr = iptr->parent ))
		||  (!( fptr->abal.flags & 1024 ))
		||	(is_xy_modif(iptr))) {
			get_window_alignment(&wx,&wy);
			indent(h,1);
			if (is_xy_modif(iptr))
				fprintf(h,"x_%s=(%u*_wref)/%d",iptr->Contents.name,iptr->Contents.x+wx,w_base_resize(iptr));
			else	fprintf(h,"x_%s=%u",iptr->Contents.name,iptr->Contents.x+wx);
			linefeed(h);
			indent(h,1);
			if (is_xy_modif(iptr))
				fprintf(h,"y_%s=(%u*_href)/%d",iptr->Contents.name,iptr->Contents.y+wy,h_base_resize(iptr));
			else	fprintf(h,"y_%s=%u",iptr->Contents.name,iptr->Contents.y+wy);
			linefeed(h);
			}
		else	{
			switch ( (iptr->Contents.align & 3) ) {
				case	0 :
					indent(h,1);
					fprintf(h,"x_%s=%u",iptr->Contents.name,iptr->Contents.x);
					linefeed(h);
					indent(h,1);
					fprintf(h,"y_%s=%u",iptr->Contents.name,iptr->Contents.y);
					linefeed(h);
					break;
				case	1 :
					indent(h,1);
					fprintf(h,"x_%s=0;",iptr->Contents.name);
					linefeed(h);
					indent(h,1);
					fprintf(h,"if (Conf(68) > %u) ",iptr->Contents.h);
					linefeed(h);
					indent(h,2);
					fprintf(h,"y_%s=((Conf(68) - %u)/2)",iptr->Contents.name,iptr->Contents.h);
					linefeed(h);
					indent(h,1);
					fprintf(h,"Else :: y_%s=0 :: Endif",iptr->Contents.name);
					linefeed(h);
					break;
				case	2 :
					indent(h,1);
					fprintf(h,"if (Conf(69) > %u) ",iptr->Contents.w);
					linefeed(h);
					indent(h,2);
					fprintf(h,"x_%s=(Conf(69) - %u)",iptr->Contents.name,iptr->Contents.w);
					linefeed(h);
					indent(h,1);
					fprintf(h,"Else :: x_%s=0 :: Endif",iptr->Contents.name);
					linefeed(h);
					indent(h,1);
					fprintf(h,"if (Conf(68) > %u) ",iptr->Contents.h);
					linefeed(h);
					indent(h,2);
					fprintf(h,"y_%s=((Conf(68) - %u)/2)",iptr->Contents.name,iptr->Contents.h);
					linefeed(h);
					indent(h,1);
					fprintf(h,"Else :: y_%s=0 :: Endif",iptr->Contents.name);
					linefeed(h);
					break;
				case	3 :
					indent(h,1);
					fprintf(h,"if (Conf(69) > %u) ",iptr->Contents.w);
					linefeed(h);
					indent(h,2);
					fprintf(h,"x_%s=((Conf(69) - %u)/2)",iptr->Contents.name,iptr->Contents.w);
					linefeed(h);
					indent(h,1);
					fprintf(h,"Else :: x_%s=0 :: Endif",iptr->Contents.name);
					linefeed(h);
					indent(h,1);
					fprintf(h,"if (Conf(68) > %u) ",iptr->Contents.h);
					linefeed(h);
					indent(h,2);
					fprintf(h,"y_%s=((Conf(68) - %u)/2)",iptr->Contents.name,iptr->Contents.h);
					linefeed(h);
					indent(h,1);
					fprintf(h,"Else :: y_%s=0 :: Endif",iptr->Contents.name);
					linefeed(h);
					break;
				}
			}			
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
	else if (( iptr->Contents.style & _FRAME_TYPE ) == _RADIO_FRAME ) {
		indent(h,1);
		fprintf(h,"x%u_%s=%s",iptr->Contents.radio,iptr->Contents.name,widget_x_position(iptr,1));
		linefeed(h);
		indent(h,1);
		fprintf(h,"y%u_%s=%s",iptr->Contents.radio,iptr->Contents.name,widget_y_position(iptr,1));
		linefeed(h);
		indent(h,1);
		fprintf(h,"w%u_%s=%s",iptr->Contents.radio,iptr->Contents.name,widget_w_dimension(iptr,1));
		linefeed(h);
		indent(h,1);
		fprintf(h,"h%u_%s=%s",iptr->Contents.radio,iptr->Contents.name,widget_h_dimension(iptr,1));
		linefeed(h);
		}
	else	{
		indent(h,1);
		fprintf(h,"x_%s=%s",iptr->Contents.name,widget_x_position(iptr,1));
		linefeed(h);
		indent(h,1);
		fprintf(h,"y_%s=%s",iptr->Contents.name,widget_y_position(iptr,1));
		linefeed(h);
		indent(h,1);
		fprintf(h,"w_%s=%s",iptr->Contents.name,widget_w_dimension(iptr,1));
		linefeed(h);
		indent(h,1);
		fprintf(h,"h_%s=%s",iptr->Contents.name,widget_h_dimension(iptr,1));
		linefeed(h);
		}
	return;
}

/*	---------	---------	*/
/*	ABAL FORM	ON CREATE	*/
/*	---------	--------	*/

public	void	abal_reset_popcontrol( FILE * h,struct form_item * iptr, int margin )
{
	indent(h,margin);
	fprintf(h,"s_%s = 0",iptr->Contents.name);
	linefeed(h);
	indent(h,margin);
	fprintf(h,"p_%s = 0",iptr->Contents.name);
	linefeed(h);
	return;
}

private	void	abal_national_messages( FILE * h, struct form_item * iptr )
{
	int	nl;
	char *	sptr;
	if (!( max_payload_size( iptr ) ))
		return;
	for (nl=0; nl < MAXNATLANG; nl++ ) {
		if ((!(sptr = iptr->Contents.messages[nl]))
		&&  (!(sptr = iptr->Contents.payload)))
			continue;
		else if ( *sptr == _UNQUOTED_STRING )
			continue;
		else	{
			indent(h,1);
			if (( iptr->Contents.style & _FRAME_TYPE ) == _RADIO_FRAME) {
				fprintf(h,"msg%u_%s(%u)=%s%u_%s",
					iptr->Contents.radio,iptr->Contents.name,(nl+1),
					language_prefix(nl),iptr->Contents.radio,iptr->Contents.name
					);
				}
			else	{
				fprintf(h,"msg_%s(%u)=%s_%s",
					iptr->Contents.name,(nl+1),
					language_prefix(nl),iptr->Contents.name
					);
				}
			linefeed(h);
			}
		}
	return;		
}


private	void	abal_hint_messages( FILE * h, struct form_item * iptr )
{
	int	nl;
	char *	sptr;
	if (!( max_hint_size( iptr ) ))
		return;
	for (nl=0; nl < MAXNATLANG; nl++ ) {
		if ((!(sptr = iptr->Contents.hmessages[nl]))
		&&  (!(sptr = iptr->Contents.hint)))
			continue;
		else if ( *sptr == _UNQUOTED_STRING )
			continue;
		else	{
			indent(h,1);
			if (( iptr->Contents.style & _FRAME_TYPE ) == _RADIO_FRAME) {
				fprintf(h,"hint%u_%s(%u)=%s%uh%s",
					iptr->Contents.radio,iptr->Contents.name,(nl+1),
					language_prefix(nl),iptr->Contents.radio,iptr->Contents.name
					);
				}
			else	{
				fprintf(h,"hint_%s(%u)=%sh%s",
					iptr->Contents.name,(nl+1),
					language_prefix(nl),iptr->Contents.name
					);
				}
			linefeed(h);
			}
		}
	return;		
}

public	int	abal_widget_parameter( FILE * h, struct form_item * iptr, int margin )
{
	struct	form_control * fptr;
	if ( Abal_Config.members ) {
		if (!( abal_import_parameter(h,iptr,margin) ))
			return(0);
		else	return(1);
		}
	else if (!( fptr = iptr->parent ))
		return(0);
	else if (( fptr->isoverlay ) && ( fptr->isprogram )) {
		if (!( abal_import_parameter(h,iptr,margin) ))
			return(0);
		else	return(1);
		}
	else	return(0);
}

public	int	abal_widget_onremove( FILE * h, struct form_item * iptr )
{
	char	*	tptr;
	struct	form_control * fptr;
	if (!( iptr ))
		return(0);
	else if (!( fptr = iptr->parent ))
		return(0);

	if ((iptr->Contents.style & _FRAME_TYPE) == _DATA_FRAME)
		abal_data_destruction(h,iptr,1);

	else if (((iptr->Contents.style & _FRAME_TYPE) == _TAB_FRAME)
	     &&  ( iptr->Contents.datatype == _WIDGET_OVERLAY ))
		detach_widget_overlay(h,iptr);

	if ( iptr->Contents.events->xo_hide & _EVENT_IS_POP ) {
		if (((iptr->Contents.style & _FRAME_TYPE ) != _WINDOW_FRAME)
		||  ((!( fptr->ispopup )) && (!fptr->resizeauto))) {
			indent(h,1);
			fprintf(h,"%s=%s(p_%s)",
				__abal_keyword_status,
				__abal_visual_drop,
				iptr->Contents.name 
				);
			linefeed(h);
			}
		}

	return(0);
}

private	void	abal_normal_access(FILE * h, struct form_item * iptr, int margin )
{
	indent(h,margin);
	if ((iptr->Contents.style & _FRAME_TYPE) != _RADIO_FRAME)
		fprintf(h,"a_%s=0",iptr->Contents.name);
	else	fprintf(h,"a%u_%s=0",iptr->Contents.radio,iptr->Contents.name);
	fprintf(h," ;** initialise access : normal",iptr->Contents.name);
	linefeed(h);
	return;
}

public	int	abal_widget_oncreate( FILE * h, struct form_item * iptr, int parameters )
{
	char	*	tptr;
	struct	form_control * fptr;
	if (!( iptr ))
		return(0);
	else if (!( fptr = iptr->parent ))
		return(0);
	else if ( fptr->formflags & _MULTILINGUAL ) {
		abal_national_messages(h,iptr);
		if ( fptr->OnHint ) {
			abal_hint_messages(h,iptr);
			}
		}

	if ( parameters )
		if (( iptr->Contents.events->xo_create & _EVENT_IS_FOCUS ) 
		||  (is_xy_modif(iptr)))
			generate_position_control( h,iptr );

	if ( iptr->Contents.events->xo_hide & _EVENT_IS_POP ) {
		if (((iptr->Contents.style & _FRAME_TYPE ) != _WINDOW_FRAME)
		||  ((!( fptr->ispopup )) && (!fptr->resizeauto))) {
			abal_reset_popcontrol(h,iptr,1);
			indent(h,1);
			switch (( iptr->Contents.style & _FRAME_TYPE )) {
				case	_EDIT_FRAME	:
					fprintf(h,"p_%s=%s(%s+2,%s+2)",
						iptr->Contents.name,
						__abal_visual_buffer,
						widget_w_dimension(iptr,0),
						widget_h_dimension(iptr,0));
					break;
				case	_OUTSET_FRAME	:
				case	_INSET_FRAME	:
					fprintf(h,"p_%s=%s(%s+1,%s+1)",
						iptr->Contents.name,
						__abal_visual_buffer,
						widget_w_dimension(iptr,0),
						widget_h_dimension(iptr,0));
					break;
				case	_GROOVE_FRAME	:
				case	_RIDGE_FRAME	:
					fprintf(h,"p_%s=%s(%s+2,%s+2)",
						iptr->Contents.name,
						__abal_visual_buffer,
						widget_w_dimension(iptr,0),
						widget_h_dimension(iptr,0));
					break;
				default			:
					fprintf(h,"p_%s=%s(%s,%s)",
						iptr->Contents.name,
						__abal_visual_buffer,
						widget_w_dimension(iptr,0),
						widget_h_dimension(iptr,0));
					break;
				}
			linefeed(h);
			}
		}
	/* Specialised Construction */
	/* ------------------------ */
	switch ( (iptr->Contents.style & _FRAME_TYPE ) ) {
		case	_GRAPH_FRAME	:
			indent(h,1);
			switch ( iptr->Contents.datatype ) {
				case	_WIDGET_WORD : fprintf(h,"l_%s=%u",iptr->Contents.name,iptr->Contents.w); break;
				case	_WIDGET_LONG : fprintf(h,"l_%s=%u",iptr->Contents.name,iptr->Contents.w); break;
				case	_WIDGET_VOID :
				case	_WIDGET_BYTE : 
				default		     : fprintf(h,"l_%s=%u",iptr->Contents.name,iptr->Contents.w); break;
				}
			linefeed(h);
			break;


		case	_DATA_FRAME	:
			abal_data_construction(h,iptr,1);
			break;

		case	_WINDOW_FRAME	:
			if ( parameters )
				if ( Abal_Config.members )
					(void) abal_import_parameter(h,iptr,1);
			if (( Context.Form->ispopup ) || (Context.Form->resizeauto )) {
				if ((!( iptr->Contents.events->xo_create & _EVENT_IS_FOCUS ))
				&&  (!(is_xy_modif(iptr))) )
					generate_position_control( h,iptr );
				abal_reset_popcontrol(h,iptr,1);
				}
			break;

		case	_TAB_FRAME 	:
			if ( parameters )
				if ( Abal_Config.members )
					(void) abal_import_parameter(h,iptr,1);
			indent(h,1);
			fprintf(h,"FocusPages(%u) = %u",iptr->Contents.page,iptr->Contents.focus);
			linefeed(h);
			indent(h,1);
			if (is_w_modif(iptr))
				fprintf(h,"v_%s = (%u*_wref)/%d ",iptr->Contents.name,iptr->Contents.adjust,w_base_resize(iptr));
			else	fprintf(h,"v_%s = %u ",iptr->Contents.name,iptr->Contents.adjust);
			linefeed(h);
			indent(h,1);
			fprintf(h,"l_%s = %u ",iptr->Contents.name,iptr->Contents.xlimit);
			linefeed(h);
			if ( iptr->Contents.datatype == _WIDGET_OVERLAY )
				attach_widget_overlay(h,iptr);
			break;

		case	_SCROLL_FRAME	:
			if ((!( parameters ))
			||  (!( abal_widget_parameter(h,iptr,1) ))) {
				indent(h,1);
				fprintf(h,"v_%s = 0",iptr->Contents.name);
				linefeed(h);
				indent(h,1);
				fprintf(h,"m_%s = 0",iptr->Contents.name);
				linefeed(h);
				indent(h,1);
				fprintf(h,"l_%s = 1",iptr->Contents.name);
				linefeed(h);
				}
			break;

		case	_PROGRESS_FRAME	:
			if ((!( parameters ))
			||  (!( abal_widget_parameter(h,iptr,1) ))) {
				indent(h,1);
				fprintf(h,"v_%s = 1",iptr->Contents.name);
				linefeed(h);
				indent(h,1);
				fprintf(h,"l_%s = 1",iptr->Contents.name);
				linefeed(h);
				}
			break;

		case	_BUTTON_FRAME	:
			abal_normal_access(h,iptr,1);
			break;

		case	_SELECT_FRAME	:
		case	_SWITCH_FRAME	:
		case	_CHECK_FRAME	:
			abal_normal_access(h,iptr,1);
			if ((!( parameters ))
			||  (!( abal_widget_parameter(h,iptr,1) ))) {
				indent(h,1);
				fprintf(h,"v_%s = 0",iptr->Contents.name);
				linefeed(h);
				}
			break;

		case	_FORM_FRAME	:
			if (is_w_modif(iptr)) {
				fprintf(h,"nc_%s = (w_%s-4)/%u",
					iptr->Contents.name,iptr->Contents.name,Context.FontTable[iptr->Contents.font].width);
				linefeed(h);
				}
			alias_redefined_widget(h, iptr, "1", 1 );
			if ((!( parameters ))
			||  (!( abal_widget_parameter(h,iptr,1) ))) {
				indent(h,1);
				fprintf(h,"b_%s=%c %c",iptr->Contents.name,0x0022,0x0022);
				linefeed(h);
				}
			indent(h,1);
			fprintf(h,"f_%s=0 ;** no sort",iptr->Contents.name);
			linefeed(h);
			indent(h,1);
			fprintf(h,"create ts_%s",iptr->Contents.name);
			linefeed(h);
			indent(h,1);
			indent(h,1);
			fprintf(h,"for ns_%s=1 to 256",iptr->Contents.name);
			linefeed(h);
			indent(h,2);
			fprintf(h,"ts_%s(ns_%s)=ns_%s ; initialisation sans tri",iptr->Contents.name,iptr->Contents.name,iptr->Contents.name);
			linefeed(h);
			indent(h,1);
			fprintf(h,"next ns_%s",iptr->Contents.name);
			linefeed(h);
			indent(h,1);
			fprintf(h,"ns_%s=256",iptr->Contents.name);
			linefeed(h);
			break;

		case	_EDIT_FRAME	:
			abal_normal_access(h,iptr,1);
			if ( iptr->Contents.align & _A_ASK ) {
				indent(h,1);
				fprintf(h,"k_%s=",iptr->Contents.name);
				fprintf(h,"%c %c",0x0022,0x0022);
				linefeed(h);
				}
			if ((!( parameters ))
			||  (!( abal_widget_parameter(h,iptr,1) ))) {
				indent(h,1);
				fprintf(h,"b_%s=",iptr->Contents.name);
				if ((!( tptr = abal_payload(iptr) ))
				||  (!(*tptr 			     )))
					fprintf(h,"%c %c",0x0022,0x0022);
				else	string_value(h,tptr);
				linefeed(h);
				}
			break;

		case	_RADIO_FRAME	:
			abal_normal_access(h,iptr,1);
			if ((!( parameters ))
			||  (!( abal_widget_parameter(h,iptr,1) ))) {
				if ( iptr->Contents.radio == 1 ) {
					indent(h,1);
					fprintf(h,"v_%s = 1",iptr->Contents.name);
					linefeed(h);
					}
				}
			break;
		default		:
			if ( parameters )
				if ( Abal_Config.members )
					(void) abal_import_parameter(h,iptr,1);
		}
	return;
}

public	struct form_item * abal_widget_construction( FILE * h,struct form_control * fptr )
{
	int	x;
	int	y;
	int	a;
	int	fh;
	char	*	tptr;
	struct form_item * iptr;
	struct form_item * wptr=(struct form_item*)0;

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if ((!( wptr )) && ((iptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME)) {
			wptr = iptr;
			}
		/* Generate ON CREATE with Parameters */
		/* ---------------------------------- */
		abal_widget_oncreate( h, iptr, 1 );
		abal_invoke_widget_create(h,iptr,0,1);
		}
	return(wptr);
}

public	void	abal_form_popup_reset(FILE * h, struct form_item * wptr )
{
	/* -------------------------------------------------------------- */
	/* This resets the visual buffer page and usage variables to zero */
	/* -------------------------------------------------------------- */
	indent(h,1);
	fprintf(h,"p_%s = 0 :: s_%s = 0",wptr->Contents.name,wptr->Contents.name);
	linefeed(h);
	return;
}

public	void	abal_form_popup_get(FILE * h, struct form_item * wptr )
{
	indent(h,1);
	fprintf(h,"if ((p_%s<>0) and ( s_%s=0))",
		wptr->Contents.name,	
		wptr->Contents.name );
		linefeed(h);
		indent(h,2);	
		fprintf(h,"s_%s=1",wptr->Contents.name );
		linefeed(h);
		indent(h,2);	
		fprintf(h,"%s=%s(p_%s,x_%s,y_%s)",
			__abal_keyword_status,
			__abal_visual_get,
			wptr->Contents.name,	
			wptr->Contents.name,	
			wptr->Contents.name );
		linefeed(h);
	abal_endif(h,1);
	return;
}

public	void	abal_form_popup_put(FILE * h, struct form_item * wptr )
{
	indent(h,1);
	fprintf(h,"if ((p_%s<>0) and ( s_%s<>0))",
		wptr->Contents.name,	
		wptr->Contents.name );
	linefeed(h);
		indent(h,1);	
		fprintf(h,"s_%s=0",wptr->Contents.name );
		linefeed(h);
		indent(h,1);	
		fprintf(h,"%s=%s(p_%s,%s,%s)",
			__abal_keyword_status,
			__abal_visual_put,
			wptr->Contents.name,	
			widget_x_position(wptr,0),
			widget_y_position(wptr,0));
		linefeed(h);
	abal_endif(h,1);
	return;
}

public	void	abal_form_popup_remove(FILE * h, struct form_item * wptr )
{
	indent( h,1 );
	fprintf(h,"if ( p_%s <> 0 ) :: ",wptr->Contents.name);
	fprintf(h,"%s=%s(p_%s)",
		__abal_keyword_status,
		__abal_visual_drop,
		wptr->Contents.name 
		);
	fprintf(h," :: p_%s = 0 :: Endif",wptr->Contents.name);
	linefeed(h);
	return;
}

public	void	abal_form_popup_create(FILE * h, struct form_item * wptr )
{
	int	fh;
	/* -------------------------------------------- */
	/* This allocates the forms popup visual buffer */
	/* -------------------------------------------- */
	indent( h,1 );
	fprintf(h,"if ( p_%s = 0 ) :: ",wptr->Contents.name);
	if ((( wptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME)
	&&   ( wptr->Contents.align & _A_SHADOW )) {
		fh = 10;
		fprintf(h,"p_%s=%s(w_%s+%u,h_%s+%u)",
			wptr->Contents.name,
			__abal_visual_buffer,
			wptr->Contents.name,fh,
			wptr->Contents.name,fh);
		}
	else	{
		fprintf(h,"p_%s=%s(w_%s,h_%s)",
			wptr->Contents.name,
			__abal_visual_buffer,
			wptr->Contents.name,
			wptr->Contents.name 
			);
		}
	fprintf(h," :: Endif");
	linefeed(h);
}

public	void	abal_form_oncreate( FILE * h,struct form_control * fptr )
{
	int	fh;
	char	*	tptr;
	struct form_item * iptr;
	struct form_item * wptr=(struct form_item*)0;

	abal_oncreate_methods( h );

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		open_overlay_create(h);
	else	{

		abal_procedure(h,Abal_Config.cname,__abal_method_create, Abal_Config.members, fptr );
		abal_error_trap(h,1,1);
		if (!( Abal_Config.generate_program )) {
			/* initialise_abal_fonts(h); */
			generate_abal_fonts(h);
			}
		}

	indent(h,1);
	fprintf(h,"Status = %s(_VISUAL_GETKEYS,KeyBuffer,Len(KeyBuffer))",__abal_visual_control);
	linefeed(h);

	abal_initialise_national_language(h,fptr,1);

	indent(h,1); fprintf(h,"KeyCode=0"); 				linefeed(h);
	indent(h,1); fprintf(h,"FirstPage=1"); 				linefeed(h);
	indent(h,1); fprintf(h,"Event(57)=15"); 			linefeed(h);
	indent(h,1); fprintf(h,"AskForeGround=%u",fptr->askfore);	linefeed(h);
	indent(h,1); fprintf(h,"AskBackGround=%u",fptr->askback);	linefeed(h);
	indent(h,1); fprintf(h,"AskAtribut=%u",fptr->askatb);		linefeed(h);
	indent(h,1); fprintf(h,"%s=1",__abal_focus_item);		linefeed(h);
	indent(h,1); fprintf(h,"%ss=%u",__abal_focus_item,fptr->focus);	linefeed(h);

	if ( Abal_Config.generate_program ) {
		if (!( Abal_Config.generate_overlay )) {
			abal_visual_startup(h,0,fptr->resizeauto);
			abal_visual_control(h,fptr);
			}
		else	abal_form_style(h,fptr,0);
		}
	else	abal_form_style(h,fptr,0);

	if ( fptr->resizeauto ) {
		indent(h,1); fprintf(h,"_wref=Conf(69)");	linefeed(h);
		indent(h,1); fprintf(h,"_href=Conf(68)");	linefeed(h);
		}

	abal_page_control(h);

	/* Ensure activation of mouse move events if required */
	/* -------------------------------------------------- */
	if ( fptr->mimoflags & _MIMO_MOVE ) {
		indent(h,1); 
		fprintf(h,"Event(0)=(Event(5) or _MIMO_MOVE)"); 
		linefeed(h);
		}

	wptr = abal_widget_construction( h, fptr );

	if ((( fptr->ispopup ) || (fptr->resizeauto)) 
	&&  ( wptr != (struct form_item *) 0)) {
		abal_form_popup_reset (h, wptr );
		abal_form_popup_create(h, wptr );
		}

	abal_returni(h,0,1);
	abal_error_abort(h,1,1);
	abal_error_return(h,__abal_keyword_status,1);
	abal_endproc(h);
}

/*	---------	---------	*/
/*	ABAL FORM	ON REMOVE	*/
/*	---------	---------	*/
public	void	abal_widget_destruction( FILE * h, struct form_control * fptr )
{
	struct form_item * iptr;

	for (	iptr=Context.Form->last;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->previous ) {

		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else	{
			abal_invoke_widget_remove(h,iptr,0,1);
			abal_widget_onremove( h, iptr );
			}
		}
	return;
}

public	void	abal_form_onremove( FILE * h, struct form_control * fptr )
{
	struct form_item * iptr;
	struct form_item * wptr=(struct form_item *) 0;
	abal_onremove_methods( h );
	abal_procedure(h,Abal_Config.cname,__abal_method_remove, Abal_Config.members, fptr );
	abal_error_trap(h,1,1);

	abal_widget_destruction(h,Context.Form);

	if ( Abal_Config.members )
		abal_transfer_parameters(h,0);

	if (( Context.Form->ispopup ) 
	&&  ( wptr != (struct form_item *) 0)) {
		abal_form_popup_remove( h, wptr );
		abal_form_popup_reset ( h, wptr );
		}

	if ( Abal_Config.generate_program ) {
		if (!( Abal_Config.generate_overlay )) {
			abal_visual_closure(h);
			}
		}

	abal_returni(h,0,1);
	abal_error_abort(h,1,1);
	abal_error_return(h,__abal_keyword_status,1);
	abal_endproc(h);
	return;
}


/*	---------	-------		*/
/*	ABAL FORM	ON SHOW		*/
/*	---------	-------		*/

public	void	abal_widget_function_thaw( FILE * h, struct form_item * wptr, int margin )
{
	if (!( wptr ))
		return;
	indent(h,1);
	abal_widget_function(h,__abal_visual_thaw,1);
	widget_position(h,wptr,0,0);
	widget_dimensions(h,wptr,0,0);
	fprintf(h,")");
	linefeed(h);
	return;
}

public	void	abal_form_showpages( FILE * h )
{
	struct	window_control * pwptr=(struct window_control *) 0;
	struct form_item * iptr;
	struct form_item * wptr;
	struct form_item * pptr;

	int		   thispage;

	/* Page by Page Generation */
	/* ----------------------- */
	for ( 	thispage=0,
		wptr = (struct form_item *) 0;
		thispage <= Context.Form->pages; thispage++ ) {

		/* Item by Item analysis */
		/* --------------------- */
		for (	pptr = (struct form_item *) 0,
			iptr=Context.Form->first;  
			iptr != (struct form_item *) 0; 
			iptr = iptr->next )  {

			/* Unsized items are discarded */
			/* --------------------------- */
			if ((!( iptr->Contents.w  )) ||  (!( iptr->Contents.h  )))
				continue;

			/* special case for first pass : PAGE 0 */
			/* ------------------------------------ */
			else if (!( thispage )) {

				/* ignore page items this time round */
				/* --------------------------------- */
				if ( iptr->Contents.page != thispage )
					continue;

				if ((!( wptr ))
				&&  (( iptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME)) {

					wptr = iptr;

					/* And open the Conditional Section */
					/* -------------------------------- */
					fprintf(h,"\tif (PageNumber=0)");
					linefeed(h);

					}

				/* OK, we've got a valid page and or item */
				/* -------------------------------------- */
				if (!( iptr->Contents.events->xo_show & _EVENT_IS_COND ))
					generate_abal_show(h,iptr,0);

				continue;

				}

			/* Ignore unpaged items when paging */
			/* -------------------------------- */
			else if (!( iptr->Contents.page ))
				continue;

			/* other page items are also discarded */
			/* ----------------------------------- */
			else if ( iptr->Contents.page != thispage )
				continue;

			/* We've got a valid page item to show */
			/* ----------------------------------- */
			/* Is it the page itself */
			/* --------------------- */
			if (( iptr->Contents.style & _FRAME_TYPE ) == _TAB_FRAME) {

				/* Yes so keep the reference */
				/* ------------------------- */
				pptr = iptr;

				/* And open the Conditional Section */
				/* -------------------------------- */
				fprintf(h,"\tif (PageNumber=%u)",thispage);
				linefeed(h);

				}

			/* No : check that we have found the page */
			/* ---------------_---------------------- */
			else if (!( pptr )) {

				/* Discard if no parent page */
				/* ------------------------- */
				continue;

				}
			/* OK, we've got a valid page and or item */
			/* -------------------------------------- */
			else if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
				continue;

			generate_abal_show(h,iptr,1);

			}

		/* check terminal conditions */
		/* ------------------------- */
		if ((!( thispage ))
		&&  ( wptr != (struct form_item *) 0)) {
			/* we have a window : activate paging */
			/* ---------------------------------- */
			fprintf(h,"\tPageNumber=FirstPage;");
			linefeed(h);
			abal_endif(h, 1);
			}
		else if ( pptr != (struct form_item *) 0) {

			/* Change Conditional Section */
			/* -------------------------- */
			abal_else(h, 1);

			/* Show tab/without page */
			/* --------------------- */
			generate_abal_show(h,pptr,2);

			abal_endif(h, 1);
			}
		}

	/* The first window must performed a FREEZE to THAW */
	/* ------------------------------------------------ */
	if ( wptr != (struct form_item *) 0 ) {
		abal_widget_function_thaw(h,wptr,1);
		}
	else if ((pwptr = connect_production_window()) != (struct window_control *) 0) {
		indent(h,1);
		abal_widget_function(h,__abal_visual_thaw,1);
		fprintf(h,"%u,%u,%u,%u",pwptr->x,pwptr->y,pwptr->h);
		fprintf(h,")");
		linefeed(h);
		}


	return;
}


public	void	abal_form_show( FILE * h )
{
	struct	window_control * pwptr=(struct window_control *) 0;
	struct form_item * iptr;
	struct form_item * wptr;

	for (	wptr=(struct form_item *) 0,
		iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {

		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		else if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
			continue;

		/* The first window must perform a FREEZE */
		/* -------------------------------------- */
		if ((!( wptr ))
		&&  (( iptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME)) {
			wptr = iptr;
			}
		generate_abal_show(h,iptr,0);
		}

	/* The first window must performed a FREEZE to THAW */
	/* ------------------------------------------------ */
	if ( wptr != (struct form_item *) 0 ) {
		indent(h,1);
		abal_widget_function(h,__abal_visual_thaw,1);
		widget_position(h,wptr,0,0);
		widget_dimensions(h,wptr,0,0);
		fprintf(h,")");
		linefeed(h);
		}
	else if ((pwptr = connect_production_window()) != (struct window_control *) 0) {
		indent(h,1);
		abal_widget_function(h,__abal_visual_thaw,1);
		fprintf(h,"%u,%u,%u,%u",pwptr->x,pwptr->y,pwptr->h);
		fprintf(h,")");
		linefeed(h);
		}

	return;
}

public	void	abal_radio_show( FILE * h, struct form_item * rptr )
{
	struct form_item * iptr;
	struct form_control * fptr;

	/* ------------------------------------ */
	/* validate radio production parameters */
	/* ------------------------------------ */
	if (!( h ))				return;
	else if (!( rptr ))			return;
	else if (!( fptr = rptr->parent )) 	return;
	else if ( fptr->radioshow >= rptr->Contents.radiogroup )
		return;
	else	fptr->radioshow++;


	/* --------------------------------------------- */
	/* Generate the Form SHOW method activetool the above */
	/* --------------------------------------------- */
	abal_procedure(h,rptr->Contents.name,__abal_method_show,0,(struct form_control *) 0);
	abal_error_trap(h,1,1);

	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if (( iptr->Contents.style & _FRAME_TYPE) != _RADIO_FRAME )
			continue;
		else if ( iptr->Contents.radiogroup != rptr->Contents.radiogroup )
			continue;
		else if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
			continue;
		else	generate_abal_show(h,iptr,0);
		}

	/* -------------------------- */
	/* Close the Target Procedure */
	/* -------------------------- */
	abal_returni(h,0,1);
	abal_error_abort(h,1,1);
	abal_error_return(h,__abal_keyword_status,1);
	abal_endproc(h);

	return;
}

public	void	abal_form_onshow( FILE * h )
{
	struct form_item * iptr;
	struct form_item * wptr=(struct form_item*)0;


	/* Allow instance specific widget methods to be generated */
	/* ------------------------------------------------------ */
	abal_onshow_methods( h );

	if (!( Context.radioshowall )) {

		/* ------------------------- */
		/* Generate Radio Group Show */
		/* ------------------------- */
		for (	iptr=Context.Form->first;  
			iptr != (struct form_item *) 0; 
			iptr = iptr->next )  {
			if ((!( iptr->Contents.w  ))
			||  (!( iptr->Contents.h  )))
				continue;
			else if (( iptr->Contents.style & _FRAME_TYPE) != _RADIO_FRAME )
				continue;
			else	abal_radio_show(h,iptr);
			}				
		}

	/* Allow widget methods to be generated */
	/* ------------------------------------ */
	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else	abal_dialog_show(h,iptr,1);

		switch ( (iptr->Contents.style & _FRAME_TYPE ) ) {
			case	_WINDOW_FRAME	:
				if (( Context.Form->ispopup )
				|| ( Context.Form->resizeauto ))
					wptr = iptr;
				break;
			}

		}
	/* Generate the Form SHOW method activetool the above */
	/* --------------------------------------------- */
	abal_procedure(h,Abal_Config.cname,__abal_method_show,0,(struct form_control *) 0);
	abal_error_trap(h,1,1);

	abal_initialise_national_language(h,Context.Form,0);

	if (( Context.Form->ispopup ) || ( Context.Form->resizeauto )) {
		if ( wptr != (struct form_item *) 0) {
			abal_form_popup_get( h, wptr );
			}
		}


	/* Always freeze */
	/* ------------- */
	abal_widget_function(h,__abal_visual_freeze,1);
	fprintf(h,")");
	linefeed(h);

	/* Detect Tab Page Generation Required */
	/* ----------------------------------- */
	if ( Context.Form->pages != 0 ) 
		abal_form_showpages( h );
	else	abal_form_show( h );

	/* Close the Target Procedure */
	/* -------------------------- */
	abal_returni(h,0,1);
	abal_error_abort(h,1,1);
	abal_error_return(h,__abal_keyword_status,1);
	abal_endproc(h);

	return;
}


public	void	abal_form_onevent( FILE * h )
{
	struct	form_item * iptr;
	struct	form_control * fptr;

	if (!( fptr = Context.Form )) 	return;

	abal_onevent_methods( h,fptr );
	abal_procedure(h,Abal_Config.cname,__abal_method_event,0,(struct form_control *) 0);
	abal_error_trap(h,1,1);
	if ( fptr->mimoflags & _MIMO_KEYBOARD ) {
		indent(h,1);
		fprintf(h,"%s=%s(MouseEvent)",__abal_keyword_status,__abal_visual_event);
		linefeed(h);
		}

	/* ---------------------------------------------- */
	/* international / multilingual trigger detection */
	/* ---------------------------------------------- */
	if (( fptr->formflags & _INTERNATIONAL )
	&&  ( fptr->formflags & _MULTILINGUAL  )) {
		abal_detect_trigger_events(h,1);
		}

	switch ( fptr->formflags & _FORM_TYPE_FLAGS ) {

		case	_FORM_TYPE_DIALOG	:

			/* standard event type filtering */
			/* ----------------------------- */
			indent(h,1);
			fprintf( h,"if ((%s and /0%x) = 0)",__abal_mouse_type,(fptr->mimoflags & _MOUSE_EVENTS));
			linefeed(h);
			abal_returni(h,0,2);
			abal_endif(h,1);

			/* enhanced button level filtering */
			/* ------------------------------- */
			if ( fptr->mimoflags & _MIMO_WIDGETS  ) {
				indent(h,1); fprintf( h,"Select ( %s )",__abal_mouse_button); linefeed(h);
				if ( fptr->mimoflags & _MIMO_SEND_LEFT ) {
					indent(h,1); fprintf( h,"Case _MIMO_LEFT"); linefeed(h);
					}
				if ( fptr->mimoflags & _MIMO_SEND_RIGHT) {
					indent(h,1); fprintf( h,"Case _MIMO_RIGHT"); linefeed(h);
					}
				if ( fptr->mimoflags & _MIMO_SEND_MIDDLE) {
					indent(h,1); fprintf( h,"Case _MIMO_OTHER"); linefeed(h);
					}
				if ( fptr->mimoflags & _MIMO_SEND_WHEEL) {
					indent(h,1); fprintf( h,"Case _MIMO_UPWHEEL"); 	linefeed(h);
					indent(h,1); fprintf( h,"Case _MIMO_DOWNWHEEL");linefeed(h);
					}
				indent(h,1); fprintf( h,"Default "); linefeed(h);
					abal_returni(h,0,2);
				indent(h,1); fprintf( h,"EndSel"); linefeed(h);	
				}
			break;

		case	_FORM_TYPE_EVENT 	:
			break;
		}

	for (	iptr=fptr->last;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->previous )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else	generate_abal_event(h,iptr);
		}
	abal_returni(h,-1,1);
	abal_error_abort(h,1,1);
	abal_error_return(h,__abal_keyword_status,1);
	abal_endproc(h);
	return;
}


public	void	progress_scroll_item( 
		FILE * h,
		struct form_item * iptr,
		int	i) 
{
	indent(h,4);
	fprintf(h,"v_%s = ",iptr->Contents.name);

	if ( iptr->Contents.w > iptr->Contents.h ) {
		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_PROGRESS_FRAME	:
				fprintf(h,"(((MouseColumn-%s)*l_%s)/%s)+1",
					widget_x_position(iptr,0),
					iptr->Contents.name,
					widget_w_dimension(iptr,0));
				break;
			case	_SCROLL_FRAME	:
				fprintf(h,"(((MouseColumn-%s)*m_%s)/%s)+1",
					widget_x_position(iptr,0),
					iptr->Contents.name,
					widget_w_dimension(iptr,0));
				break;
			}
		}
	else	{
		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_PROGRESS_FRAME	:
				fprintf(h,"(((MouseRow-%s)*l_%s)/%s)+1",
					widget_y_position(iptr,0),
					iptr->Contents.name,
					widget_h_dimension(iptr,0));
				break;
			case	_SCROLL_FRAME	:
				fprintf(h,"(((MouseRow-%s)*m_%s)/%s)+1",
					widget_y_position(iptr,0),
					iptr->Contents.name,
					widget_h_dimension(iptr,0));
				break;
			}
		}
	linefeed(h);
	return;
}

public	void	abal_retry_event(FILE * h, int margin)
{
	indent(h,margin); 
	fprintf(h,"goto &Retry"); 
	linefeed(h);
	return;
}

public	void	abal_check_widget_event( FILE * h, struct form_item * iptr, int margin )
{
	indent(h,margin);
	fprintf(h,"if ((%s and /0%x) <> 0)",
			__abal_mouse_type,
			(iptr->Contents.events->mimo & _MOUSE_EVENTS));
	linefeed(h);
	return;
}

public	void	trigger_abal_event( FILE * h, struct form_item * iptr, int margin )
{
	char	*	eptr;

	if ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME)
		if (!( iptr = locate_radio_event( iptr->parent, iptr->Contents.name ) ))
			return;

	if (((iptr->Contents.style & _FRAME_TYPE) != _BUTTON_FRAME)
	||  ( iptr->Contents.datatype == _WIDGET_HYPERLINK )) {
		if ((!( eptr =  iptr->Contents.events->on_event ))
		||  (!( *eptr )))
			return;
		}

	abal_check_widget_event(h,iptr,margin);
	abal_invoke_widget_event(h,iptr,1,margin);
	abal_endif(h,margin);
	return;
}

public	void	trigger_visual_module_event( FILE * h, struct form_item * iptr, int margin )
{
	char	*	eptr;
	abal_check_widget_event(h,iptr,margin);
	if ((!( eptr =  iptr->Contents.events->on_event )) ||  (!( *eptr ))) {
		/* default behaviour for these widgets */
		indent(h,(margin+1));
		fprintf(h,"if ( %sOnEvent() > 0 )",abal_payload(iptr));
		linefeed(h); 
		abal_retry_event(h,margin);
		abal_endif(h,margin);
		}
	else	{
		/* explicite behaviour is programmer defined */
		/* ----------------------------------------- */
		abal_invoke_widget_event(h,iptr,1,margin);
		}
	abal_endif(h,margin);
	return;
}

public	void	trigger_visual_overlay_event( FILE * h, struct form_item * iptr, int margin )
{
	char	*	eptr;
	abal_check_widget_event(h,iptr,margin);
	if ((!( eptr =  iptr->Contents.events->on_event ))
	||  (!( *eptr ))) {
		/* default behaviour for these widgets */
		invoke_widget_overlay(h,iptr,_OVL_ONEVENT);
		fprintf(h,"if ( Status  > 0 )",iptr->Contents.name);
		linefeed(h);
		/* indent(h,margin); fprintf(h,"goto &Retry"); linefeed(h); */
		abal_endif(h,margin);
		}
	else	{
		/* explicite behaviour is programmer defined */
		/* ----------------------------------------- */
		abal_invoke_widget_event(h,iptr,1,margin);
		}
	abal_endif(h,margin);
	return;
}

public	void	trigger_visual_object_event( FILE * h, struct form_item * iptr, int margin )
{
	char	*	eptr;
	abal_check_widget_event(h,iptr,margin);
	if ((!( eptr =  iptr->Contents.events->on_event ))
	||  (!( *eptr ))) {
		/* default behaviour for these widgets */
		indent(h,(margin+1));
		fprintf(h,"if ( %s.on_event > 0 )",iptr->Contents.name);
		linefeed(h);
		visual_object_event_retry(h,iptr->Contents.name,(margin+1));
		abal_endif(h,margin);
		}
	else	{
		/* explicite behaviour is programmer defined */
		/* ----------------------------------------- */
		abal_invoke_widget_event(h,iptr,1,margin);
		}
	abal_endif(h,margin);
	return;
}

private	void	refresh_abal_event( FILE * h, struct form_item * iptr, int margin )
{
	/* ------------------------------------------------------- */ 
	/* switch and check components will change state each time */
	/* they receive an event, this may require default refresh */
	/* to ensure that the widget state is visible, unless this */
	/* has been inhibited by a variety of means.		   */
	/* ------------------------------------------------------- */ 
	if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )) {
		/* the widget will not receive the focus so will not redisplay */
		if (!( iptr->Contents.events->xo_show & _EVENT_IS_COND )) {
			/* this widget is not a conditional display widget */
			if (!( method_is_valid( iptr->Contents.events->on_event ) )) {
				/* this is no defined event method which would take charge */
				/* default action requires redisplay of switch/check state */
				generate_abal_show(h,iptr,0);
				}
			}
		}
	return;
}

public	void	refresh_abal_edit( FILE * h, struct form_item * iptr, int margin )
{
	/* ------------------------------------------------------- */ 
	/* edit components with style require redisplay to ensure  */
	/* display is style coherent				   */
	/* ------------------------------------------------------- */ 
	if (!( iptr->Contents.events->xo_show & _EVENT_IS_COND )) {
		/* this widget is not a conditional display widget */
		if (!( method_is_valid( iptr->Contents.events->on_lose_focus ) )) {
			/* this is no defined lose focus method which would take charge */
			/* default action requires redisplay of edit contents           */
			generate_abal_show(h,iptr,0);
			}
		}
	return;
}

public	void	abal_widget_useevent( 
		FILE * h, struct form_item * iptr, int margin )
{
	char	*	optr;

	if (!( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ))
		return;

	else	{
		if (( Abal_Config.generate_program )
		&&  ( Abal_Config.generate_overlay ))
			optr = "o";
		else	optr = "\0";

		switch ((iptr->Contents.style&_FRAME_TYPE)) {

			case	_WINDOW_FRAME	:
				abal_case_focus(h,iptr,margin);
				abal_comment(h,iptr->Contents.name,margin+1);
				if (!( iptr->Contents.events->on_event )) {
					indent(h,margin+1);
					fprintf(h,"if ((%s and _MIMO_UP) <> 0)",__abal_mouse_type);
					linefeed(h);
					indent(h,margin+2); fprintf(h,"KeyCode=27"); linefeed(h);
					abal_retry_event(h,margin+2);
					/* was abal_break(h,margin+2); */
					abal_else(h,margin+1);
					abal_continue(h,margin+2);
					abal_endif(h,margin+1);
					}
				else	{
					trigger_abal_event(h,iptr,margin+1);
					abal_continue(h,margin);
					}
				break;

			case	_TAB_FRAME	:
				abal_case_focus(h,iptr,margin);
				abal_comment(h,iptr->Contents.name,margin+1);
				indent(h,margin+1);
				fprintf(h,"if ((%s and (_MIMO_DOWN or _MIMO_UP))<> 0)",__abal_mouse_type);
				linefeed(h);
				indent(h,margin+2);
				fprintf(h,"if ( PageNumber <> %u )",iptr->Contents.page);
				linefeed(h);
				indent(h,margin+3);
				fprintf(h,"Status = %s%s(%s)",Abal_Config.cname,__abal_method_lose_focus,optr);
				linefeed(h);
				indent(h,margin+3);
				fprintf(h,"PageNumber = %u",iptr->Contents.page);
				linefeed(h);
				indent(h,margin+3);
				fprintf(h,"Status = %s%s(%s)",Abal_Config.cname,__abal_method_show,optr);
				linefeed(h);
				abal_endif(h,margin+2);
				abal_endif(h,margin+1);
				trigger_abal_event(h,iptr,margin+1);
				abal_continue(h,margin);
				break;

			case	_RADIO_FRAME	:
				abal_case_focus(h,iptr,margin);
				abal_comment(h,iptr->Contents.name,margin+1);
				indent(h,margin+1);
				fprintf(h,"if ((%s and _MIMO_UP) <> 0)",__abal_mouse_type);
				linefeed(h);
				indent(h,margin+2);
				fprintf(h,"v_%s = %u",iptr->Contents.name,iptr->Contents.radio);
				linefeed(h);
				if ( Context.radioshowall ) {
					indent(h,margin+1);
					fprintf(h,"%s%s(%s)",Abal_Config.cname,__abal_method_show,optr);
					linefeed(h);
					}
				else	{
					indent(h,margin+1);
					fprintf(h,"%s%s(%s)",iptr->Contents.name,__abal_method_show,optr);
					linefeed(h);
					}
				abal_endif(h,margin+1);
				trigger_abal_event(h,iptr,margin+1);
				abal_continue(h,margin);
				break;

			case	_SWITCH_FRAME	:
			case	_CHECK_FRAME	:
				abal_case_focus(h,iptr,margin);
				abal_comment(h,iptr->Contents.name,margin+1);
				indent(h,margin+1);
				fprintf(h,"if ((%s and _MIMO_UP) <> 0)",__abal_mouse_type);
				linefeed(h);
				indent(h,margin+2);
				fprintf(h,"v_%s = v_%s + 1",iptr->Contents.name,iptr->Contents.name);
				linefeed(h);
				indent(h,margin+2);
				fprintf(h,"v_%s = v_%s and 1",iptr->Contents.name,iptr->Contents.name);
				linefeed(h);
				abal_endif(h,margin+1);
				refresh_abal_event(h,iptr,margin+1);
				trigger_abal_event(h,iptr,margin+1);
				abal_continue(h,margin);
				break;

			case	_BUTTON_FRAME	:
				abal_case_focus(h,iptr,margin);
				abal_comment(h,iptr->Contents.name,margin+1);

				if (!( method_is_valid( iptr->Contents.events->on_get_focus ) )) {
					indent(h,margin+1);
					fprintf(h,"if (( %s and _MIMO_DOWN) <> 0)",__abal_mouse_type);
					linefeed(h);
					abal_onshow_widget(h,iptr,margin+2,4);
					abal_endif(h,margin+1);
					indent(h,margin+1);
					fprintf(h,"if (( %s and _MIMO_UP) <> 0)",__abal_mouse_type);
					linefeed(h);
					abal_onshow_widget(h,iptr,margin+2,0);
					abal_endif(h,margin+1);
					}

				trigger_abal_event(h,iptr,margin+1);
				abal_continue(h,margin);
				break;

			case	_SCROLL_FRAME	:
				abal_case_focus(h,iptr,margin);
				abal_comment(h,iptr->Contents.name,margin+1);
				indent(h,margin+1);
				fprintf(h,"Status = %s%s(%s)",iptr->Contents.name,__abal_method_action,optr);
				linefeed(h);
				abal_continue(h,margin+1);
				break;

			case	_DATA_FRAME	:
				if (( iptr->Contents.align & 0x000F) != _VISUAL_FRAME )
					break;
				abal_case_focus(h,iptr,margin);
				abal_comment(h,iptr->Contents.name,margin+1);
				switch ( iptr->Contents.datatype ) {
					case	_WIDGET_CLASS	:
					case	_WIDGET_POINTER	:
						trigger_visual_object_event(h,iptr,margin+1);
						break;
					case	_WIDGET_MODULE 	:
						trigger_visual_module_event(h,iptr,margin+1);
						break;
					case	_WIDGET_OVERLAY	:
						trigger_visual_overlay_event(h,iptr,margin+1);
						break;
					}
				abal_continue(h,margin);
				break;

			case	_EDIT_FRAME	:

/*				if ( iptr->Contents.datatype == _WIDGET_KONSTANT ) break;	*/

			case	_SELECT_FRAME	:
			default			:
				abal_case_focus(h,iptr,margin);
				abal_comment(h,iptr->Contents.name,margin+1);
				trigger_abal_event(h,iptr,margin+1);
				abal_continue(h,margin);
				break;
			}
		}
	return;
}

public	void	abal_form_useevent( FILE * h, int margin )
{
	char * mptr;
	struct form_item * iptr;

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		mptr = "o";
	else	mptr = "\0";


	indent(h,margin);
	fprintf(h,"%s=%sEvent(%s)",__abal_keyword_status,Abal_Config.cname,mptr);
	linefeed(h);
	indent(h,margin);
	fprintf(h,"if (%s = 0)",__abal_keyword_status);
	linefeed(h);
	abal_continue(h,margin+1);
	abal_else(h,margin);
	indent(h,margin+1);
	fprintf(h,"%s=%s",__abal_focus_item,__abal_keyword_status);
	linefeed(h);
	abal_endif(h,margin);

	if ( Context.Form->onlinehelp & 16 ) {
		generate_abal_onhelp_switch( h );
		}

	abal_select(h,__abal_focus_item,margin);

	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {

		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else	abal_widget_useevent( h, iptr, margin );
		}

	abal_default(h,margin);
	indent(h,margin+1); fprintf(h,"FocusItem=1"); linefeed(h);
	abal_continue(h,margin+1);
	abal_endsel(h,margin);
	return;
}

public	void	abal_case_hotkey( FILE * h, int keycode, int margin )
{
	int	other;
	indent(h,margin);
	if (( keycode >= 'a' ) && ( keycode <= 'z' ))
		other = (keycode - ('a'-'A'));
	else	other = (keycode + ('a'-'A'));
	fprintf(h,"Case /0%x,/0%x",(keycode|_MIMO_ALT),(other|_MIMO_ALT));
	linefeed(h);
	return;
}

private	void	abal_detect_trigger_event( FILE * h, struct form_item * iptr, int margin)
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
			indent(h,margin);
			fprintf(h,"if (t%u_%s",iptr->Contents.radio,iptr->Contents.name);
			break;

		case	_BUTTON_FRAME	:
		case	_SWITCH_FRAME	:
		case	_CHECK_FRAME	:
		case	_TAB_FRAME	:
			if (!( sptr = abal_payload(iptr)))
				return;
			indent(h,margin);
			fprintf(h,"if (t_%s",iptr->Contents.name);
			break;
		default			:
			return;
		}
	fprintf(h," = MouseButton ) :: Exit(%u) :: Endif",iptr->Contents.focus);
	linefeed(h);
	return;
}

/*	-------------------------------------------------------------------------------		*/
/*	generates alt hotkey detection mechanisms for international/multilingual models 	*/
/*	-------------------------------------------------------------------------------		*/
private	void	abal_detect_trigger_events( FILE * h, int margin )
{
	struct form_item * iptr;

	indent(h,margin); 	fprintf(h,"if ((MouseType and _MIMO_ALT) <> 0)");			linefeed(h);	
	indent(h,(margin+1));	fprintf(h,"MouseButton = (MouseButton and /00FF)");			linefeed(h);	
	indent(h,(margin+1));	fprintf(h,"if (( MouseButton >= /0061) and (MouseButton <= /007A))");	linefeed(h);
	indent(h,(margin+2));	fprintf(h,"MouseButton -= /0020");					linefeed(h);
	indent(h,(margin+1));	fprintf(h,"endif");							linefeed(h);

	for (	iptr=Context.Form->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
		abal_detect_trigger_event(h,iptr,(margin+1));

	indent(h,(margin+1));	fprintf(h,"Exit(-1)");							linefeed(h);	
	indent(h,margin);	fprintf(h,"endif");							linefeed(h);	
	return;
}



public	void	generate_abal_trigger( FILE * h, struct form_item * iptr, int margin )
{
	struct	form_item * xptr;
	char *	optr;

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = "o";
	else	optr = "\0";

	abal_comment(h,iptr->Contents.name,margin);
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
					generate_abal_trigger(h,xptr,margin);
					break;
					}
				}
			}
		}
	else	{
		indent(h,margin+1);
		fprintf(h,"Status = %s%s(%s)",Abal_Config.cname,__abal_method_lose_focus,optr);
		linefeed(h);
		indent(h,margin+1);
		fprintf(h,"PageNumber = %u",iptr->Contents.page);
		linefeed(h);
		}

	indent(h,margin+1);
	fprintf(h,"%s%s(%s)",Abal_Config.cname,__abal_method_show,optr);
	linefeed(h);
	indent(h,margin+1);
	fprintf(h,"FocusItem=%u",iptr->Contents.focus);
	linefeed(h);
	return;
}

public	void	abal_widget_formtrigger(
		FILE * h, struct form_item * iptr, int margin )
{
	char	*	optr;

	if (!( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ))
		return;

	else if (!( iptr->Contents.trigger ))
		return;

	else if (!( iptr->Contents.focus ))
		return;

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = "o";
	else	optr = "\0";

	switch ((iptr->Contents.style & _FRAME_TYPE)) {

		case	_TAB_FRAME	:
			abal_case_hotkey(h,iptr->Contents.trigger,margin);
			abal_comment(h,iptr->Contents.name,margin+1);
			indent(h,margin+1);
			fprintf(h,"Status = %s%s(%s)",Abal_Config.cname,__abal_method_lose_focus,optr);
			linefeed(h);
			indent(h,margin+1);
			fprintf(h,"PageNumber = %u",iptr->Contents.page);
			linefeed(h);
			indent(h,margin+1);
			fprintf(h,"Status = %s%s(%s)",Abal_Config.cname,__abal_method_show,optr);
			linefeed(h);
			break;

		case	_RADIO_FRAME	:
			abal_case_hotkey(h,iptr->Contents.trigger,margin);
			abal_comment(h,iptr->Contents.name,margin+1);
			indent(h,margin+1);
			fprintf(h,"v_%s = %u",iptr->Contents.name,iptr->Contents.radio);
			linefeed(h);
			indent(h,margin+1);
			fprintf(h,"%s%s(%s)",Abal_Config.cname,__abal_method_show,optr);
			linefeed(h);
			break;

		case	_SWITCH_FRAME	:
		case	_CHECK_FRAME	:
			abal_case_hotkey(h,iptr->Contents.trigger,margin);
			abal_comment(h,iptr->Contents.name,margin+1);
			indent(h,margin+1);
			fprintf(h,"v_%s = v_%s + 1",iptr->Contents.name,iptr->Contents.name);
			linefeed(h);
			indent(h,margin+2);
			fprintf(h,"v_%s = v_%s and 1",iptr->Contents.name,iptr->Contents.name);
			linefeed(h);
			break;

		case	_BUTTON_FRAME	:
			abal_case_hotkey(h,iptr->Contents.trigger,margin);
			abal_comment(h,iptr->Contents.name,margin+1);
			abal_button_widget(h,iptr,margin+1,8);
			abal_button_widget(h,iptr,margin+1,0);
			break;
		
		default			:
			return;
		}
	indent(h,margin+1);
	fprintf(h,"FocusItem=%u",iptr->Contents.focus);
	linefeed(h);
	abal_invoke_widget_event(h,iptr,1,margin+1);
	abal_continue(h,margin);
	return;
}

public	void	abal_widget_pagetrigger(
		FILE * h, struct form_item * iptr, int margin )
{
	char	*	optr;
	int		pn=0;

	if (!( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ))
		return;

	else if (!( iptr->Contents.trigger ))
		return;

	else if (!( iptr->Contents.focus ))
		return;

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = "o";
	else	optr = "\0";

	switch ((iptr->Contents.style & _FRAME_TYPE)) {

		case	_TAB_FRAME	:
			abal_comment(h,iptr->Contents.name,margin);
			indent(h,margin);
			fprintf(h,"Status = %s%s(%s)",Abal_Config.cname,__abal_method_lose_focus,optr);
			linefeed(h);
			indent(h,margin);
			fprintf(h,"PageNumber = %u",iptr->Contents.page);
			linefeed(h);
			indent(h,margin);
			fprintf(h,"Status = %s%s(%s)",Abal_Config.cname,__abal_method_show,optr);
			linefeed(h);
			break;

		case	_RADIO_FRAME	:
			if ((pn=iptr->Contents.page) != 0) {
				indent(h,margin++);
				fprintf(h,"if (PageNumber = %u)",pn);
				linefeed(h);
				}
			abal_comment(h,iptr->Contents.name,margin);
			indent(h,margin);
			fprintf(h,"v_%s = %u",iptr->Contents.name,iptr->Contents.radio);
			linefeed(h);
			indent(h,margin);
			fprintf(h,"%s%s(%s)",Abal_Config.cname,__abal_method_show,optr);
			linefeed(h);
			break;

		case	_SWITCH_FRAME	:
		case	_CHECK_FRAME	:
			if ((pn=iptr->Contents.page) != 0) {
				indent(h,margin++);
				fprintf(h,"if (PageNumber = %u)",pn);
				linefeed(h);
				}
			abal_comment(h,iptr->Contents.name,margin);
			indent(h,margin);
			fprintf(h,"v_%s = v_%s + 1",iptr->Contents.name,iptr->Contents.name);
			linefeed(h);
			indent(h,margin);
			fprintf(h,"v_%s = v_%s and 1",iptr->Contents.name,iptr->Contents.name);
			linefeed(h);
			break;

		case	_BUTTON_FRAME	:
			if ((pn=iptr->Contents.page) != 0) {
				indent(h,margin++);
				fprintf(h,"if (PageNumber = %u)",pn);
				linefeed(h);
				}
			abal_comment(h,iptr->Contents.name,margin);
			abal_button_widget(h,iptr,margin,8);
			abal_button_widget(h,iptr,margin,0);
			break;
		
		default			:
			return;
		}

	indent(h,margin);
	fprintf(h,"FocusItem=%u",iptr->Contents.focus);
	linefeed(h);
	abal_invoke_widget_event(h,iptr,1,margin);
	abal_continue(h,margin);
	if ( pn ) {	abal_endif(h,--margin);	}
	return;
}

public	void	abal_form_usetriggers( FILE * h, int margin )
{
	struct form_item * iptr;
	int		triggermap[256];
	int		triggers=0;
	int		i;
	int		c;

	if (( Context.Form->formflags & _INTERNATIONAL)
	&&  ( Context.Form->formflags & _MULTILINGUAL ))
		return;

	else if ( Context.Form->pages ) {

		for (	iptr=Context.Form->first;  
			iptr != (struct form_item *) 0; 
			iptr = iptr->next )  {

			if ((!( iptr->Contents.w  ))
			||  (!( iptr->Contents.h  )))
				continue;
			else if (!( widget_can_trigger( &iptr->Contents ) ))
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
				fprintf(h,"Case /8%x,/8%x",c,(c-('a'-'A')));
				linefeed(h);
				}

			else if ((c >= 'A')
			     &&  (c <= 'Z')) {
				indent(h,margin);
				fprintf(h,"Case /8%x,/8%x",(c+('a'-'A')),c);
				linefeed(h);
				}
			else	abal_case(h,triggermap[i],margin);

			for (	iptr=Context.Form->first;  
				iptr != (struct form_item *) 0; 
				iptr = iptr->next )  {

				if ((!( iptr->Contents.w  ))
				||  (!( iptr->Contents.h  )))
					continue;

				else if (!( widget_can_trigger( &iptr->Contents ) ))
					continue;

				else if (!( iptr->Contents.trigger ))
					continue;

				else if (!( compare_hotkeys( iptr->Contents.trigger, triggermap[i] )))
					continue;

				else	abal_widget_pagetrigger(h,iptr,margin+1);

				}
			}

		}
	else	{

		for (	iptr=Context.Form->first;  
			iptr != (struct form_item *) 0; 
			iptr = iptr->next )  {

			if ((!( iptr->Contents.w  ))
			||  (!( iptr->Contents.h  )))
				continue;
			else	abal_widget_formtrigger( h, iptr, margin );
			}

		}
	return;
}

public	void	abal_form_onlosefocus( FILE * h )
{
	char *	mptr;
	struct form_item * iptr;

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		mptr = "o";
	else	mptr = "\0";

	abal_onlose_methods( h, __abal_method_lose_focus, 1 );

	abal_procedure(h,Abal_Config.cname,__abal_method_lose_focus,0,(struct form_control *) 0);
	abal_error_trap(h,1,1);
	if ( Context.Form->pages != 0 ) {
		indent(h,1);	fprintf(h,"%s (PageNumber)",__abal_keyword_select);
		linefeed(h);
		for (	iptr=Context.Form->first;  
			iptr != (struct form_item *) 0; 
			iptr = iptr->next )  {
			if ((!( iptr->Contents.w  ))
			||  (!( iptr->Contents.h  )))
				continue;
			else if ((iptr->Contents.style & _FRAME_TYPE) != _TAB_FRAME)
				continue;
			indent(h,2);
			fprintf(h,"Case %u ",iptr->Contents.page);
			linefeed(h); 
			abal_invoke_widget_lose_focus(h,iptr,0,3);
			}
		linefeed(h); 
		indent(h,1);
		fprintf(h,__abal_keyword_endsel);
		linefeed(h); 
		}
	abal_returni(h,0,1);	
	abal_error_abort(h,1,1);
	abal_error_return(h,__abal_keyword_status,1);
	abal_endproc(h);
	return;

}


private	void	abal_focus_next( FILE * h, int margin )
{
	indent(h,margin++);
	fprintf(h,"repeat");
	linefeed(h);

	abal_if(h,margin,"FocusItem < FocusItems");
		indent(h,margin+1);
		fprintf(h,"FocusItem = FocusItem+1");
		linefeed(h);
	abal_else(h,margin);
		indent(h,margin+1);
		fprintf(h,"FocusItem = 1");
		linefeed(h);
	abal_endif(h,margin);

	indent(h,margin--);
	fprintf(h,"v_access = value_access(FocusItem)");
	linefeed(h);
	indent(h,margin);
	fprintf(h,"until (v_access = 0)");
	linefeed(h);

	abal_continue(h,margin);
	return;
}

public	void	abal_form_onfocus( FILE * h )
{
	char *	mptr;
	struct form_item * iptr;
	struct	window_control * pwptr=(struct window_control *) 0;
	struct form_item * wptr=(struct form_item *) 0;
	int first_bouton=0;
	char	*	eptr;

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		mptr = "o";
	else	mptr = "\0";

	abal_onget_methods( h, __abal_method_get_focus );
	abal_procedure(h,Abal_Config.cname,__abal_method_focus,0,(struct form_control *) 0);
	abal_dcl(h,"v_","access",_ABAL_BYTE,0,0,0,"Pour tester le changement de focus");
	abal_error_trap(h,1,1);
	if (!( Context.Form->focus )) {
		linefeed(h);
		fprintf(h,"\tKeyCode=13");
		linefeed(h);
		}
	else	{
	indent(h,1);
	fprintf(h,"%ss=%u",__abal_focus_item,Context.Form->focus);
	linefeed(h);
	if (!( Context.Form->inhibit_flush & 1)) {
		generate_abal_flush(h,1);
		}
	abal_do(h,1);
	abal_label(h,"Continue");
	/* Ensure activation of mouse move events if required */
	/* -------------------------------------------------- */
	if ( Context.Form->mimoflags & _MIMO_MOVE ) {
		indent(h,1); 
		fprintf(h,"Event(0)=(Event(5) or _MIMO_MOVE)"); 
		linefeed(h);
		}
	else	{
		indent(h,1); 
		fprintf(h,"Event(0)=(Event(5) and /FEFF)"); 
		linefeed(h);
		}
	indent(h,1);
	fprintf(h,"LastFocus=FocusItem");
	linefeed(h);
	abal_select(h,__abal_focus_item,2);

	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if ((iptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME)
			wptr = iptr;
		if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS ))
			continue;
		else	generate_abal_focus(h,iptr);
		}

	abal_default(h,2); indent(h,3); fprintf(h,"KeyCode=5"); linefeed(h);
	abal_endsel(h,2);
	abal_label(h,"Retry");
	abal_select(h,"KeyCode",2);

		abal_case(h,0,2);	/* Nothing   */
			abal_continue(h,3);

		abal_case(h,0x000C,2);	/* Home	     */
			if ( Abal_Config.page_control ) {
				indent(h,3);
				fprintf(h,"PageNumber=1");
				linefeed(h);
				}
			indent(h,3);
			fprintf(h,"%s=1",__abal_focus_item);
			linefeed(h);
			indent(h,3);
			fprintf(h,"Status = %sShow(%s)",Abal_Config.cname,mptr);
			linefeed(h);
			abal_continue(h,3);
			
		abal_case(h,0x0002,2);	/* End 	     */
			if ( Abal_Config.page_control ) {
				indent(h,3);
				fprintf(h,"PageNumber=%u",Context.Form->pages);
				linefeed(h);
				}
			indent(h,3);
			fprintf(h,"%s=%u",__abal_focus_item,Context.Form->focus);
			linefeed(h);
			indent(h,3);
			fprintf(h,"Status = %sShow(%s)",Abal_Config.cname,mptr);
			linefeed(h);
			abal_continue(h,3);

	if ( Abal_Config.page_control ) {

		if (( Context.Form->formflags & _FORM_PAGE_DOWN ) != 0) {

			abal_case(h,3,2);	/* Page Down */
				indent(h,3);
				fprintf(h,"Status = %s%s(%s)",Abal_Config.cname,__abal_method_lose_focus,mptr);
				linefeed(h);
				indent(h,3);
				fprintf(h,"if ( PageNumber < %u )",Context.Form->pages);
				linefeed(h);
				indent(h,4);
				fprintf(h,"PageNumber = PageNumber + 1");
				linefeed(h);
				indent(h,3);
				fprintf(h,"Else :: PageNumber = 1");
				linefeed(h);
				abal_endif(h,3);
				indent(h,3);
				fprintf(h,"%s=FocusPages(PageNumber)",__abal_focus_item);
				linefeed(h);
				indent(h,3);
				fprintf(h,"Status = %sShow(%s)",Abal_Config.cname,mptr);
				linefeed(h);
				abal_continue(h,3);
			}
		if (( Context.Form->formflags & _FORM_PAGE_UP ) != 0) {
			abal_case(h,0x0012,2);	/* Page Up   */
				indent(h,3);
				fprintf(h,"Status = %s%s(%s)",Abal_Config.cname,__abal_method_lose_focus,mptr);
				linefeed(h);
				indent(h,3);
				fprintf(h,"if ( PageNumber > 1 )");
				linefeed(h);
				indent(h,4);
				fprintf(h,"PageNumber = PageNumber - 1");
				linefeed(h);
				indent(h,3);
				fprintf(h,"Else :: PageNumber = %u",Context.Form->pages);
				linefeed(h);
				abal_endif(h,3);
				indent(h,3);
				fprintf(h,"%s=FocusPages(PageNumber)",__abal_focus_item);
				linefeed(h);
				indent(h,3);
				fprintf(h,"Status = %sShow(%s)",Abal_Config.cname,mptr);
				linefeed(h);
				abal_continue(h,3);
			}
		}
		abal_case(h,256,2);
			if (!( Context.Form->mimoflags & _MIMO_KEYBOARD )) {
				indent(h,3);
				fprintf(h,"%s=%s(MouseEvent)",__abal_keyword_status,__abal_visual_event);
				linefeed(h);
				if (!( Context.Form->formflags & _MULTILINGUAL)) {
					indent(h,3); fprintf(h,"if ((%s and _MIMO_ALT) <> 0)",__abal_mouse_type);
					linefeed(h); 
					indent(h,4); fprintf(h,"KeyCode = %s",__abal_mouse_button);
					linefeed(h);
					abal_retry_event(h,4);
					abal_endif(h,3);
					}
				}
			if ( Context.Form->formflags & _FORM_DEFAULT ) {
				if (!( Context.Form->isdynamic )) {
					if ((pwptr = connect_production_window()) != (struct window_control *) 0) {
						indent(h,3);
						fprintf(h,"if (( %s  and  _MIMO_ALT) = 0) ",__abal_mouse_type);
						linefeed(h);
						fprintf(h,"if (( %s <  %u )'",__abal_mouse_column,pwptr->x);
						linefeed(h);
						fprintf(h,"or ( %s <  %u )'",__abal_mouse_row   ,pwptr->y);
						linefeed(h);
						fprintf(h,"or ( %s >  %u )'",__abal_mouse_column,pwptr->x+pwptr->w);
						linefeed(h);
						fprintf(h,"or ( %s >  %u )) ",__abal_mouse_row   ,pwptr->y+pwptr->h);
						linefeed(h);
	
						if (!( Context.Form->inhibit_flush & 2)) {

							indent(h,5);
							fprintf(h,"if (( %s  and  _MIMO_MOVE) <> 0) ",__abal_mouse_type);
							linefeed(h);
								abal_continue(h,6);
							abal_else(h,5);
							indent(h,6);
								fprintf(h,"Exit(256);");
							linefeed(h);
							abal_endif(h,5);

							}
						else	{
							indent(h,5);
								fprintf(h,"Exit(256);");
							linefeed(h);
							}
						abal_endif(h,4);
						abal_endif(h,3);
						}
					}
				else if ( wptr ) {
					indent(h,3);
					fprintf(h,"if (( %s  and  _MIMO_ALT) = 0) ",__abal_mouse_type);
					linefeed(h);
					if ( wptr->Contents.events->xo_create & _EVENT_IS_FOCUS ) {
						fprintf(h,"\tif ((%s < (%s) ) '",__abal_mouse_column,widget_x_position(wptr,0));
						linefeed(h);
						fprintf(h,"\tor (%s < (%s) ) '",__abal_mouse_row,widget_y_position(wptr,0));
						linefeed(h);
						fprintf(h,"\tor (%s > (%s+w_%s) ) '",__abal_mouse_column,widget_x_position(wptr,0),wptr->Contents.name);
						linefeed(h);
						fprintf(h,"\tor (%s > (%s+h_%s) ))",__abal_mouse_row,widget_y_position(wptr,0),wptr->Contents.name);
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
					if (!( Context.Form->inhibit_flush & 2)) {
						indent(h,5);
						fprintf(h,"if (( %s  and  _MIMO_MOVE) <> 0) ",__abal_mouse_type);
						linefeed(h);
						abal_continue(h,6);
						abal_else(h,5);
						indent(h,6);
						fprintf(h,"Exit(256);");
						linefeed(h);
						abal_endif(h,5);
						}
					else	{
						indent(h,5);
							fprintf(h,"Exit(256);");
						linefeed(h);
						}

					abal_endif(h,4);
					abal_endif(h,3);
					}
				}
			abal_form_useevent(h,3);
			abal_break(h,3);

		if ( Context.Form->formflags & _FORM_ESC ) {
			abal_case(h,27,2);
			if ( Context.Form->OnEscape ) {
				abal_special_method(h, Context.Form->OnEscape , 3, 0 );
				} 
			abal_break(h,3);
			}
		if ( Context.Form->formflags & _FORM_RC ) {
			abal_case(h,13,2);
			if ( Context.Form->OnEnter ) {
				abal_special_method(h, Context.Form->OnEnter , 3, 0 );
				} 
			abal_break(h,3);
			}
		else	{
			abal_case(h,13,2);
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
					abal_select(h,"FocusItem",3);
					first_bouton=1;
					}
				abal_case_focus(h,iptr,3);
				abal_comment(h,iptr->Contents.name,4);
				abal_invoke_widget_event(h,iptr,1,4);
				abal_continue(h,4);
				}
			if (first_bouton) { abal_endsel(h,3); }
			abal_focus_next(h,3);
			}

		switch (( Context.Form->formflags & (_FORM_DOWN | _FORM_TAB) )) {
			case	_FORM_DOWN	:
				abal_case(h,2,5);
				break;
			case	_FORM_TAB	:
				abal_case(h,2,9);
				break;
			case	_FORM_DOWN | _FORM_TAB :
				abal_cases(h,"9,5",2);
				break;
			}
		if (( Context.Form->formflags & (_FORM_DOWN | _FORM_TAB) ) != 0) {
			abal_focus_next(h,3);
			}
		if ( Context.Form->formflags & _FORM_UP ) {
			abal_case(h,11,2);
			indent(h,3); fprintf(h,"repeat"); linefeed(h);
			abal_if(h,4,"FocusItem > 1");
				indent(h,5);
				fprintf(h,"FocusItem = FocusItem-1");
				linefeed(h);
			abal_else(h,4);
				indent(h,5);
				fprintf(h,"FocusItem = FocusItems");
				linefeed(h);
			abal_endif(h,4);
			linefeed(h);
			indent(h,4);
			fprintf(h,"v_access = value_access(FocusItem)");
			linefeed(h);
			indent(h,3);
			fprintf(h,"until (v_access = 0)");
			linefeed(h);
			abal_continue(h,3);
			}
		if ( Context.Form->mimoflags & _MIMO_INTERRUPT ) {
			abal_form_usetriggers(h,2);
			}

		if (!( Context.Form->formflags & _FORM_DEFAULT  )) {
			abal_default(h,2);
			linefeed(h);
			abal_continue(h,3);
			}
		else if ( Context.Form->OnDefault) {
			abal_default(h,2);
			abal_special_method(h, Context.Form->OnDefault, 3, 0 );
			abal_break(h,2);
			} 


	abal_endsel(h,2);
	abal_break(h,2);
	abal_loop(h,1);
		} /* ! can focus */
	indent(h,1);
	fprintf(h,"Exit(KeyCode)");
	linefeed(h);
	/* abal_returni(h,0,1); */
	abal_error_abort(h,1,1);
	abal_error_return(h,__abal_keyword_status,1);
	abal_endproc(h);
	return;
}

public	void	abal_positionat_signature( FILE * h, struct form_control * fptr, char * xptr )
{
	if ( xptr )
		fprintf(h,"%s ",xptr);
	fprintf(h,"Proc %s%s(",Abal_Config.cname,"PositionAt");
	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		fprintf(h,"%s,",__abal_overlay_object);
	fprintf(h,"x%c,y%c)",0x0025,0x0025);
	linefeed(h);
	return;
}

public	void	abal_extern_positionat( FILE * h, struct form_control * fptr )
{
	if (!( fptr->isdynamic ))
		return;
	else if ( fptr->PositionAt )
		return;
	else	{
		abal_positionat_signature(h,fptr,__abal_keyword_extern);
		return;
		}
}

public	void	abal_forward_positionat( FILE * h, struct form_control * fptr )
{
	if (!( fptr->isdynamic ))
		return;
	else if ( fptr->PositionAt )
		return;
	else	{
		abal_positionat_signature(h,fptr,__abal_keyword_forward);
		return;
		}
}

public	void	abal_form_positionat( FILE * h, struct form_control * fptr )
{
	struct	form_item * iptr;
	char *	optr;
	if (!( fptr->isdynamic ))
		return;
	else if ( fptr->PositionAt )
		return;
	else	{
		abal_positionat_signature(h,fptr,(char *) 0);
		abal_error_trap(h,1,1);	
		for (	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next ) {
			if (( iptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME) {
				indent(h,1);
				fprintf(h,"x_%s = x",iptr->Contents.name);
				linefeed(h);
				indent(h,1);
				fprintf(h,"y_%s = y",iptr->Contents.name);
				linefeed(h);
				}
			else if (( iptr->Contents.style & _FRAME_TYPE) == _DATA_FRAME) {
				switch ( iptr->Contents.datatype ) {
					case	_WIDGET_MODULE	:
					case	_WIDGET_OVERLAY	:
						if ( forms_dynamic_position( abal_payload( iptr ) ) ) {
							abal_invoke_widget_create(h,iptr,0,1);
							}
						break;
					}
				}
			}
		if (( fptr->resizeauto )) { 
			indent(h,1);
			if (( fptr->isprogram ) && ( fptr->isoverlay ))
				fprintf(h,"%s%s(o,_wref,_href)",Abal_Config.cname,__abal_method_Resize);
			else	fprintf(h,"%s%s(_wref,_href)",Abal_Config.cname,__abal_method_Resize);
			linefeed(h); 
			}
		abal_return(h,(char *) 0,1);
		abal_error_abort(h,1,1);
		abal_error_return(h,__abal_keyword_status,1);
		abal_endproc(h);
		}
	return;
}

public	void	open_overlay_onexec( FILE * h,struct form_control * fptr )
{
	abal_procedure(h,Abal_Config.cname,__abal_method_exec, Abal_Config.members,fptr );
	abal_error_trap(h,1,1);
	return;
}

public	void	close_overlay_onexec( FILE * h )
{
	abal_return(h,__abal_keyword_status,1);
	abal_error_abort(h,1,1);
	abal_error_return(h,__abal_keyword_status,1);
	abal_endproc(h);
	if (!( Context.Form->OnPreConstr )) {
		fprintf(h,"%s preconstruction(%s,ptr a$,ptr b$,ptr c$, ptr d$,ptr e$) : %c ",__abal_keyword_proc,__abal_overlay_object,0x0025);
		linefeed(h);
		abal_init_global(h);
		abal_endproc(h);
		}
	if (!( Context.Form->OnPostDestr )) {
		fprintf(h,"%s postdestruction(%s,ptr a$,ptr b$,ptr c$, ptr d$,ptr e$) : %c ",__abal_keyword_proc,__abal_overlay_object,0x0025);
		linefeed(h);
		abal_endproc(h);
		}
	abal_segment(h,__abal_string_zero);
	abal_error_trap(h,1,1);
	indent(h,1);
	fprintf(h,"%s=1:(/1,X3,$,X,$,/1),",__abal_keyword_print);
	quoted_string(h,"Sing/Abal Overlay" );
	linefeed(h);
	return;
}

public	void	add_path_terminator( char ** ssptr )
{
	int	slen;
	char *	sptr;

	/* recover string pointer checking location adresse */
	/* ------------------------------------------------ */
 	if (!( ssptr )) { return; } else if (!( sptr = *ssptr )) { return; }

	if ((slen = strlen(sptr)) != 0) {
#ifdef WIN32
		if (sptr[(slen-1)] != '\\')
			sptr = postfix_string( sptr, "\\" );
#else
		if (sptr[(slen-1)] != '/')
			sptr = postfix_string( sptr, "/" );
#endif
		}
	*ssptr = sptr;
	return;
}

public	char *	use_temporary_directory( char * nomfic )
{
	char	*	source_name=(char *) 0;
	char 	*	app_sources=(char *) 0;
	char	*	sptr;
	if ( method_is_valid((app_sources = application_source_production())) ) {
		add_path_terminator(&app_sources);
		source_name=relative_filename(nomfic, app_sources );
		app_sources=liberate(app_sources);
		}
	else	source_name=allocate_string(nomfic);

	return( source_name );
}

public	char *	use_product_directory( char * nomfic )
{
	char	*	path_name=(char *) 0;
	char 	*	app_objects=(char *) 0;
	char	*	sptr;
	if ( method_is_valid((app_objects = application_object_production())) ) {
		add_path_terminator(&app_objects);
		path_name=relative_filename(nomfic, app_objects );
		app_objects=liberate(app_objects);
		}
	else	path_name=allocate_string(nomfic);

	return( path_name );
}

public	void	abal_end_method(FILE * h)
{	
	indent(h,1); fprintf(h,"end"); linefeed(h);
	return;
}

public	void	abal_method_signature( FILE * h, char * prefix, char * mname, int nature, struct form_control * fptr)
{
	fprintf(h,"public indirect integer function %s%s:",prefix,mname);
	switch ( nature ) {
		case	1 :	/* on_create */
			fprintf(h,"( ptr cmd$, lencmd%c )",0x0025);
			break;
		case	2 :	/* position_at */
			fprintf(h,"( atx%c, aty%c )",0x0025,0x0025);
			break;

		}
	linefeed(h);
	abal_end_method(h);
}

public	void	overlay_prototype( struct form_control * fptr )
{
	struct forms_method * mptr;
	char	*	pname;
	FILE	*	h;
	char	*	source_name;

	if (!( source_name = use_temporary_directory( fptr->prodname ) ))
		return;
	else if (!(pname = allocate_string( source_name ) )) {
		liberate( source_name );
		return;
		}
	else if (!( pname = enforce_extension( pname, CLASS_EXTENSION ) )) {
		liberate( source_name );
		return;
		}
	else if (!( h = fopen( pname, "wa" ))) {
		liberate( pname );
		liberate( source_name );
		return;
		}
	else	{
		production_banner( h,fptr->language, fptr->identifier, pname );
		open_file_exclusion(h,pname);
		fprintf(h,"#pragma enhanced indirect off");
		linefeed(h);
		fprintf(h,"#class ovl_%s",fptr->identifier);
		linefeed(h);
		abal_method_signature(h,"\0",__aplus_method_create, 1, fptr );
		abal_method_signature(h,"\0",__aplus_method_remove, 0, fptr );
		abal_method_signature(h,"\0",__aplus_method_hide,0,(struct form_control*) 0);
		abal_method_signature(h,"\0",__aplus_method_show,0,(struct form_control*) 0);
		abal_method_signature(h,"\0",__aplus_method_event,0,(struct form_control*) 0);
		abal_method_signature(h,"\0",__aplus_method_get_focus,0,(struct form_control*) 0);
		abal_method_signature(h,"\0",__aplus_method_exec,0,(struct form_control*) 0);
		abal_method_signature(h,"\0",__aplus_method_attach,0, fptr );
		abal_method_signature(h,"\0",__aplus_method_detach,0, fptr );
		abal_method_signature(h,"\0",__aplus_method_lose_focus,0,(struct form_control*) 0);

		if (( fptr->isdynamic ) && (!( fptr->PositionAt ))) {
			abal_method_signature(h,"\0",__aplus_method_position,2, fptr);
			}

		abal_class_methods_interface(h,fptr);
		abal_class_widgets_interface(h,fptr);

		fprintf(h,"#endclass ovl_%s",fptr->identifier);
		linefeed(h);

		linefeed(h);
		fprintf(h,"#class %s",fptr->identifier);
		linefeed(h);
		fprintf(h,"(public overlay ovl_%s)",fptr->identifier);
		linefeed(h);

		fprintf(h,"private strict inline constructor on_attach:(filename$)");
		linefeed(h);
			indent(h,1);
			fprintf(h,"Attach ovl_%s(filename)",fptr->identifier);
			linefeed(h);
			abal_end_method(h);

		fprintf(h,"private strict inline destructor on_detach:(filename$)");
		linefeed(h);
			indent(h,1);
			fprintf(h,"if ( ValidPtr(ovl_%s) <> 0 ) :: Detach ovl_%s :: Endif",
				fptr->identifier,fptr->identifier);
			linefeed(h);
			abal_end_method(h);

		fprintf(h,"#endclass %s",fptr->identifier);
		linefeed(h);

		close_file_exclusion(h,pname);
		fclose(h);
		if ( source_name ) 	liberate( source_name );
		if ( pname )		liberate( pname );
		return;
		}
}
	
public	void	module_prototype( struct form_control * fptr )
{
	struct forms_method * mptr;
	char	*	pname;
	FILE	*	h;
	char	*	source_name;

	if (!( source_name = use_temporary_directory( fptr->prodname ) ))
		return;
	else if (!(pname = allocate_string( source_name ) )) {
		liberate( source_name );
		return;
		}
	else if (!( pname = enforce_extension( pname, EXT_EXTENSION ) )) {
		liberate( source_name );
		return;
		}
	else if (!( h = fopen( pname, "wa" ))) {
		liberate( pname );
		liberate( source_name );
		return;
		}
	else	{
		production_banner( h,fptr->language, fptr->identifier, pname );
		open_file_exclusion(h,pname);
		fprintf(h,"%s ",__abal_keyword_extern);
		abal_signature(h,Abal_Config.cname,__abal_method_create, Abal_Config.members, fptr );
		fprintf(h,"%s ",__abal_keyword_extern);
		abal_signature(h,Abal_Config.cname,__abal_method_show,0,(struct form_control*) 0);
		fprintf(h,"%s ",__abal_keyword_extern);
		abal_signature(h,Abal_Config.cname,__abal_method_lose_focus,0,(struct form_control*) 0);
		fprintf(h,"%s ",__abal_keyword_extern);
		abal_signature(h,Abal_Config.cname,__abal_method_event,0,(struct form_control*) 0);
		fprintf(h,"%s ",__abal_keyword_extern);
		abal_signature(h,Abal_Config.cname,__abal_method_focus,0,(struct form_control*) 0);
		fprintf(h,"%s ",__abal_keyword_extern);
		abal_signature(h,Abal_Config.cname,__abal_method_hide,0,(struct form_control*) 0);
		fprintf(h,"%s ",__abal_keyword_extern);
		abal_signature(h,Abal_Config.cname,__abal_method_remove, Abal_Config.members, fptr );
		fprintf(h,"%s ",__abal_keyword_extern);
		abal_signature(h,Abal_Config.cname,__abal_method_attach, -1, fptr );
		fprintf(h,"%s ",__abal_keyword_extern);
		abal_signature(h,Abal_Config.cname,__abal_method_detach, 0, fptr );
		abal_extern_positionat(h,fptr);
		fprintf(h,"%s ",__abal_keyword_extern);
		abal_signature(h,fptr->identifier,"\0", Abal_Config.members, fptr );
		abal_forms_method_extern(h,fptr);
		abal_public_widgets(h,fptr);
		close_file_exclusion(h,pname);
		fclose(h);
		if ( source_name ) 	liberate( source_name );
		if ( pname )		liberate( pname );
		return;
		}
}
	
public	void	abal_form_ondoit( FILE * h, struct form_control * fptr )
{
	char	* mptr;

	if ( Abal_Config.generate_program ) {

		if ( Abal_Config.generate_overlay ) {
			overlay_prototype(fptr);
			mptr = "o";
			open_overlay_onexec(h,fptr);
			}
		else	{
			mptr = "\0";
			abal_segment(h,__abal_string_zero);
			abal_error_trap(h,1,1);
			if ( fptr->formflags & _FORM_COMMANDLINE ) {
				indent(h,1);	
				fprintf(h,"ArgN = %u",fptr->argvcount+fptr->interfaceitems);	
				linefeed(h);
				indent(h,1);
				fprintf(h,"%s=Main()",__abal_keyword_status);
				linefeed(h);
				/* Main */
				}
			indent(h,1);
			fprintf(h,"%s=%s%s()",__abal_keyword_status,Abal_Config.cname,__abal_method_create);
			linefeed(h);
			indent(h,1);
			fprintf(h,"if (%s=0)",__abal_keyword_status);
			linefeed(h);
			}

		indent(h,2);
		fprintf(h,"%s=%s%s(%s)",__abal_keyword_status,Abal_Config.cname,__abal_method_show,mptr);
		linefeed(h);
		indent(h,2);
		fprintf(h,"%s=%s%s(%s)",__abal_keyword_status,Abal_Config.cname,__abal_method_focus,mptr);
		linefeed(h);
		indent(h,2);
		fprintf(h,"%s=%s%s(%s)",__abal_keyword_status,Abal_Config.cname,__abal_method_hide,mptr);
		linefeed(h);
		if ( Abal_Config.generate_overlay )
			close_overlay_onexec(h);
		else	{
			indent(h,2);
			fprintf(h,"%s=%s%s()",__abal_keyword_status,Abal_Config.cname,__abal_method_remove);
			linefeed(h);
			abal_endif(h,1);
			}

		abal_stop(h,1);
		abal_error_abort(h,1,1);
		abal_stop(h,1);
		abal_endseg(h,__abal_string_zero);

		}

	else if ( Abal_Config.generate_overlay ) {
		module_prototype(fptr);
		linefeed(h);
		abal_signature(h,fptr->identifier,"\0", Abal_Config.members, fptr );
		abal_error_trap(h,1,1);	
		abal_call(h,Abal_Config.cname,__abal_method_create, Abal_Config.members,1 , fptr );
		abal_call(h,Abal_Config.cname,__abal_method_show, 0,1 , fptr );
		abal_call(h,Abal_Config.cname,__abal_method_focus, 0,1 , fptr );
		abal_call(h,Abal_Config.cname,__abal_method_hide, 0,1 , fptr );
		abal_call(h,Abal_Config.cname,__abal_method_remove, Abal_Config.members,1 , fptr );
		abal_return(h,__abal_keyword_keycode,1);
		abal_error_abort(h,1,1);
		abal_error_return(h,__abal_keyword_status,1);
		abal_endproc(h);
		}
	return;
}

public	void	abal_form_onfinish( FILE * h )
{
	if (( Abal_Config.generate_program )
	||  ( Abal_Config.generate_overlay ))
		abal_end(h,0);
	abal_comment(h,"End of File",0);
	return;
}

public	void	set_abal_config_name(char * vptr)
{
	Abal_Config.cname = vptr;
	return;
}
public	void	set_abal_config_overlay(int v )
{
	Abal_Config.generate_overlay = v;
	return;
}

public	void	set_abal_config_program(int v )
{
	Abal_Config.generate_program = v;
	return;
}

public	void	reset_abal_config()
{
	Abal_Config.page_control       = 0;
	Abal_Config.members            = 0;
	Abal_Config.action             = 0;
	Abal_Config.actions            = 8;
	return;
}

public  void	abal_command_line( FILE * h, struct form_control * fptr )
{
	/* ------------------------------- */
	/* Include Command Line Parser Now */
	/* ------------------------------- */
	if ( fptr->isprogram ) {
		if ( fptr->formflags & _FORM_COMMANDLINE )
			abal_include(h,"arg.as");
		else if ( fptr->isoverlay )
			abal_include(h,"arg.as");
		}
	return;
}


public  void	export_abal_form( FILE * h )
{
	char		     * eptr;
	struct	form_control * fptr;
	struct form_item * iptr;
	struct form_item * wptr;
	int	i;
	int	isoverlay;

	if (!( fptr = Context.Form ))
		return;
	else	reset_abal_config();

	set_abal_config_overlay(fptr->isoverlay);
	set_abal_config_program(fptr->isprogram);

	if (( Abal_Config.generate_overlay )
	&&  ( Abal_Config.generate_program ))
		isoverlay = 1;
	else	isoverlay = 0;

	if ( Abal_Config.generate_program ) 
		set_abal_config_name("On");
	else if ( Abal_Config.generate_overlay ) {
		if ((eptr = confgetenv("MODULE_PREFIX_BUG")) != (char *) 0 ) 
			Abal_Config.cname = fptr->identifier;
		else	{
			/* Its a module : so ModuleOnMethod instead of ModuleMethod */
			sprintf(Abal_Config.Special,"%sOn",fptr->identifier);
			Abal_Config.cname = Abal_Config.Special;
			}
		}
	else if (!( Abal_Config.cname = fptr->identifier ))
		set_abal_config_name("dialog_box");

	else if (!( *Abal_Config.cname ))
		set_abal_config_name("dialog_box");


	set_abal_form_input( fptr );
	set_abal_form_error( fptr );

	/* Generate File Banner Block */
	production_banner(h,_GENERATE_BAL,fptr->loadname,fptr->prodname);

	/* ------------------------------- */
	/* Generate Inclusions for Program */
	/* ------------------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_form_onstart( h, fptr->objects );

	/*	-------		*/
	/* 	FORWARD		*/
	/*	-------		*/
	abal_forward_methods(h, fptr );

	/* 	-------		*/
	/* 	PRIVATE 	*/
	/* 	-------		*/
	abal_private_dependance( h, fptr );

	/*	------		*/
	/* 	EXTERN		*/
	/*	------		*/
	abal_extern_methods(h, fptr );
	abal_forms_method_externs(h,fptr);

	/*	-------		*/
	/* 	METHODS		*/
	/*	-------		*/

	abal_forms_members(h,fptr);
	abal_forms_methods(h,fptr);
	abal_sort_methods(h,fptr);
	abal_access_method(h,fptr);
	abal_command_line(h,fptr);
	abal_resize_method(h,fptr);

	/* -------------------- */
	/*	ON _ CREATE	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_form_oncreate( h,fptr );

	/* -------------------- */
	/*	ON _ HIDE  	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_form_onhide( h );

	/* -------------------- */
	/*	ON _ REMOVE	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_form_onremove( h,fptr );


	/* -------------------- */
	/*	ON _  SHOW 	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_form_onshow( h );

	/* -------------------- */
	/*	ON _ HELP	*/
	/* -------------------- */
	if ( (fptr->onlinehelp & 7) ) {
		status_progress(2,Abal_Config.actions,Abal_Config.action++);
		abal_form_onhelp( h );
		}

	/* -------------------- */
	/*	ON _ EVENT 	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_form_onevent( h );

	/* -------------------- */
	/*	ON _ LOSEFOCUS	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_form_onlosefocus( h );

	/* -------------------- */
	/*	ON _ FOCUS 	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_form_onfocus( h );

	/* -------------------- */
	/*	ON _ ATTACH	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_overlay_attach( h, isoverlay );

	/* -------------------- */
	/*	ON _ DETACH	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_overlay_detach( h, isoverlay );

	/* ------------- */
	/* POSITION _ AT */
	/* ------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_form_positionat(h,fptr);

	/* --------- */
	/* ON _ DOIT */
	/* --------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_form_ondoit(h,fptr);

	/* ----------- */
	/* ON _ FINISH */
	/* ----------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_form_onfinish(h);
	return;
}

public int is_xy_modif(struct form_item * iptr)
{
	struct	form_control * fptr;

	if (!( fptr = iptr->parent ))
		return(0);
	else if (!( fptr->resizeauto ))
		return(0);

	switch ( (iptr->Contents.style & _FRAME_TYPE ) ) {
		case	_FILL_FRAME	:
		case	_OUTSET_FRAME	:
		case	_INSET_FRAME	:
		case	_RIDGE_FRAME	:
		case	_GROOVE_FRAME	:
		case	_EDIT_FRAME	:
		case	_TEXT_FRAME	:
		case	_IMAGE_FRAME	:
		case	_LINE_FRAME	:
		case	_BUTTON_FRAME	:
		case	_WINDOW_FRAME	:
		case	_TAB_FRAME 	:
		case	_CHECK_FRAME	:
		case	_RADIO_FRAME	:
		case	_SELECT_FRAME	:
		case	_FORM_FRAME	:
		case	_SCROLL_FRAME	:
		case	_PROGRESS_FRAME	:
		case	_SWITCH_FRAME	:
		case _GRAPH_FRAME	:
			return(1);
		case _DATA_FRAME	:
			if ((iptr->Contents.align & 0x00FF) == 2)
				return(1);
		}
	return(0);
}

public int is_w_modif(struct form_item * iptr)
{
	struct	form_control * fptr;

	if (!( fptr = iptr->parent ))
		return(0);
	else if (!( fptr->resizeauto ))
		return(0);

	switch ( (iptr->Contents.style & _FRAME_TYPE ) ) {
		case	_FILL_FRAME	:
		case	_OUTSET_FRAME	:
		case	_INSET_FRAME	:
		case	_RIDGE_FRAME	:
		case	_GROOVE_FRAME	:
		case	_EDIT_FRAME	:
		case	_TEXT_FRAME	:
		case	_IMAGE_FRAME	:
		case	_LINE_FRAME	:
		case	_BUTTON_FRAME	:
		case	_WINDOW_FRAME	:
		case	_TAB_FRAME 	:
		case	_CHECK_FRAME	:
		case	_RADIO_FRAME	:
		case	_SELECT_FRAME	:
		case	_FORM_FRAME	:
		case	_SCROLL_FRAME	:
		case	_PROGRESS_FRAME	:
		case	_SWITCH_FRAME	:
		case	_GRAPH_FRAME	:
			return(iptr->Contents.wResize);
		}
	return(0);
}

public int is_h_modif(struct form_item * iptr)
{
	struct	form_control * fptr;

	if (!( fptr = iptr->parent ))
		return(0);
	else if (!(fptr->resizeauto))
		return(0);

	switch ((iptr->Contents.style & _FRAME_TYPE )) {
		case	_FILL_FRAME	:
		case	_OUTSET_FRAME	:
		case	_INSET_FRAME	:
		case	_RIDGE_FRAME	:
		case	_GROOVE_FRAME	:
		case	_EDIT_FRAME	:
		case	_TEXT_FRAME	:
		case	_IMAGE_FRAME	:
		case	_LINE_FRAME	:
		case	_BUTTON_FRAME	:
		case	_WINDOW_FRAME	:
		case	_TAB_FRAME 	:
		case	_CHECK_FRAME	:
		case	_RADIO_FRAME	:
		case	_SELECT_FRAME	:
		case	_FORM_FRAME	:
		case	_SCROLL_FRAME	:
		case	_PROGRESS_FRAME	:
		case	_SWITCH_FRAME	:
		case	_GRAPH_FRAME	:
			return(iptr->Contents.hResize);
		};
	return(0);
}

public int w_base_resize(struct form_item * iptr)
{
	struct	form_control * fptr;
	if (!( fptr = iptr->parent ))
		return(0);
	else if (!fptr->resizeauto) 
		return(0);
	else	return(fptr->resizew);
}

public int h_base_resize(struct form_item * iptr)
{
	struct	form_control * fptr;
	if (!( fptr = iptr->parent ))
		return(0);
	else if (!fptr->resizeauto) 
		return(0);
	else	return(fptr->resizeh);
}

#endif	/* _abalform_c */

