#ifndef	_abalform_c
#define	_abalform_c

#include "vcommand.h"

struct	window_control * connect_production_window();
char	*	language_prefix(int nl);

/*	---------	--------	*/
/*	ABAL FORM	ON START	*/
/*	---------	--------	*/

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


public	void	abal_visual_forward(FILE * h)
{
	linefeed(h);
	fprintf(h,"%s %s %s() : %c",__abal_keyword_forward,__abal_keyword_proc,__abal_method_oncreate,0x0025);
	linefeed(h);

	fprintf(h,"%s %s On%s() : %c",__abal_keyword_forward,__abal_keyword_proc,__abal_method_remove,0x0025);
	linefeed(h);

	fprintf(h,"%s %s On%s() : %c",__abal_keyword_forward,__abal_keyword_proc,__abal_method_hide,0x0025);
	linefeed(h);

	fprintf(h,"%s %s On%s() : %c",__abal_keyword_forward,__abal_keyword_proc,__abal_method_show,0x0025);
	linefeed(h);

	fprintf(h,"%s %s On%s() : %c",__abal_keyword_forward,__abal_keyword_proc,__abal_method_event,0x0025);
	linefeed(h);

	fprintf(h,"%s %s On%s() : %c",__abal_keyword_forward,__abal_keyword_proc,__abal_method_focus,0x0025);
	linefeed(h);

	fprintf(h,"%s %s On%s() : %c",__abal_keyword_forward,__abal_keyword_proc,__abal_method_lose_focus,0x0025);
	linefeed(h);
	return;
}


public	void	abal_overlay_dependance( FILE * h )
{
	if ( Context.Form->dependance)
		abal_dependance(h,Context.Form->dependance,1);

	fprintf(h,"%s %s preconstruction(%s,ptr a$,ptr b$,ptr c$, ptr d$,ptr e$) ",__abal_keyword_forward,__abal_keyword_proc,__abal_overlay_object);
	linefeed(h);
	fprintf(h,"%s %s postdestruction(%s,ptr a$,ptr b$,ptr c$, ptr d$,ptr e$) ",__abal_keyword_forward,__abal_keyword_proc,__abal_overlay_object);
	linefeed(h);
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

	abal_include(h,"arg.as");
	if ( Context.Form->dependance)
		abal_dependance(h,Context.Form->dependance,2);
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

private	void	abal_argv_control( FILE * h, struct form_control * fptr )
{
	abal_dcl(h,"Arg","N",_ABAL_WORD,0,0,0);
	abal_arg(h,"Arg","B",_ABAL_STRING,fptr->argvlen*fptr->argvcount,0,0);
	abal_dcl(h,"Arg","V",_ABAL_STRING,fptr->argvlen,fptr->argvcount,0);
	abal_dcl(h,"Arg","C",_ABAL_WORD,0,0,0);
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
	Abal_Config.members = generate_abal_structure(h);

	if ( Abal_Config.generate_program ) {
		if ( Abal_Config.generate_overlay ) {
			abal_overlay_dependance(h);
			}
		else 	{
			if ( Context.Form->formflags & _FORM_COMMANDLINE ) {
				abal_argv_control( h, Context.Form );
				abal_include(h,"arg.as");
				}
			abal_visual_forward(h);
			if ( Context.Form->dependance)
				abal_dependance(h,Context.Form->dependance,3);
			}
		Abal_Config.members = 0;
		}
	else if ( Abal_Config.generate_overlay ) {
		if ( Context.Form->dependance)
			abal_dependance(h,Context.Form->dependance,3);
		}
	abal_forms_method_forward(h,Context.Form);
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
				if ( Context.Form->ispopup )
					wptr = iptr;
				break;
			}
		}

	/* Generate the Form HIDE method using the above */
	/* --------------------------------------------- */
	abal_procedure(h,Abal_Config.cname,__abal_method_hide,0,(struct form_control *) 0);
	abal_error_trap(h,1,1);

	if ( Context.Form->pages != 0 ) 
		abal_form_hidepages( h );
	else	abal_form_hide( h );

	if ( Context.Form->ispopup ) {
		if ( wptr != (struct form_item *) 0) { 
			generate_abal_popdown(h,wptr,1);
			}
		}

	abal_returni(h,0,1);
	abal_error_abort(h,1,1);
	abal_error_return(h,__abal_keyword_status,1);
	abal_endproc(h);

	return;
}

public	void	abal_visual_element(FILE * h, struct form_item * iptr, char * sptr, char * mptr, int i)
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
	else if (( sptr = iptr->Contents.stylesheet) != (char *) 0) {
		while ((vptr = selection_item(item,sptr )) != (char *) 0) {		
			if ( item++ > 0 ) {
				linefeed(h);
				indent(h,i);
				}
			fprintf(h,"%s = VisualStyle(",__abal_keyword_status);
			widget_position(h,iptr,0,0);
			widget_dimensions(h,iptr,0,0);
			if ( *vptr == _UNQUOTED_STRING ) {
				fprintf(h,",");
				variable_value(h,(vptr+1));
				fprintf(h,",");
				variable_length(h,(vptr+1));
				}
			else	{
				fprintf(h,",");
				quoted_string(h,vptr);
				fprintf(h,",%u",strlen(vptr));
				}
			constant_parameter(h,iptr );
			constant_lendol_parameter(h,iptr);
			fprintf(h,")");
			liberate( vptr );
			}
		}
	linefeed(h);
	return;
}

public	void	abal_form_style( FILE * h, struct form_control * fptr )
{
	char *	sptr;
	if ((sptr = method_is_valid(  fptr->stylesheet)) != (char *) 0) {
		indent(h,1);
		fprintf(h,"%s = %s(30,",__abal_keyword_status,__abal_visual_control);
		quoted_string(h,fptr->stylesheet);
		fprintf(h,",%u)",strlen( fptr->stylesheet ));
		linefeed(h);
		}
	if ((sptr = method_is_valid(  fptr->clearscreen)) != (char *) 0)
		abal_visual_element(h,(struct form_item *)0,fptr->clearscreen," ",1);
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
	abal_form_style(h,fptr);
	return;
}

public	void	abal_visual_startup(FILE * h,int gmode)
{
	char *	nptr;
	int	truecolour=256;
	if ( Context.Form ) {
		if ( Context.Form->abal.flags & 256 )
			truecolour += 512;
		}
	indent(h,1);
	if (!( gmode )) {
		if ( method_is_valid((nptr = project_configuration()))) {
			fprintf(h,"%s = %s(_VISUAL_CONFIG,",__abal_keyword_status,__abal_visual_control);
			quoted_string(h,nptr);
			if (!( nptr ))
				fprintf(h,",1)");
			else 	fprintf(h,",%u)",strlen( nptr ));
			linefeed(h);
			indent(h,1);
			}
		fprintf(h,"%s(%s(%u+%u) = -1 )",
			__abal_keyword_if,__abal_visual_initialise,TargetBiosMode,truecolour);
		}
	else	{  
		fprintf(h,"%s(%s(gmode+%u) = -1 )",
			__abal_keyword_if,__abal_visual_initialise,truecolour);
		}

	linefeed(h);
	abal_raise(h,56,2); 
	abal_else(h,1);
	indent(h,2);
	fprintf(h,"%s(%s(",
		__abal_keyword_if,__abal_visual_palette);
	if (!(SingConf)) {
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
	abal_endif(h,1);
	generate_abal_fonts(h);
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
	if ( mode ) {
		indent(h,1);
		fprintf(h,"InitGlobal");
		linefeed(h);
		}
	abal_visual_startup(h,1);
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
	fprintf(h,"InitGlobal");
	linefeed(h);
	indent(h,1);
	fprintf(h,"%s argp(argl)",__abal_keyword_alter);
	linefeed(h);
	indent(h,1);	fprintf(h,"ArgB = argp");			linefeed(h);
	indent(h,1);	fprintf(h,"ArgN = %u",Context.Form->argvcount);	linefeed(h);
	indent(h,1);
	fprintf(h,"%s=Main()",__abal_keyword_status);
	linefeed(h);
	/* initialise_abal_fonts(h); */
	generate_abal_fonts(h);
	return;
}


private		void	generate_position_control(
		FILE * h,
		struct form_item * iptr
		)
{
	int	wy=0;
	int	wx=0;
	/* Generate Position and Dimensions Variables */
	if (( iptr->Contents.style & _FRAME_TYPE ) == _WINDOW_FRAME ) {
		get_window_alignment(&wx,&wy);
		indent(h,1);
		fprintf(h,"x_%s=%u",iptr->Contents.name,iptr->Contents.x+wx);
		linefeed(h);
		indent(h,1);
		fprintf(h,"y_%s=%u",iptr->Contents.name,iptr->Contents.y+wy);
		linefeed(h);
		indent(h,1);
		fprintf(h,"w_%s=%u",iptr->Contents.name,iptr->Contents.w);
		linefeed(h);
		indent(h,1);
		fprintf(h,"h_%s=%u",iptr->Contents.name,iptr->Contents.h);
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
				fprintf(h,"msg%u_%s(%u)=%s_%s",
					iptr->Contents.radio,iptr->Contents.name,(nl+1),
					language_prefix(nl),iptr->Contents.name
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

	abal_initialise_national_language(h,fptr);

	indent(h,1); fprintf(h,"KeyCode=0"); linefeed(h);
	indent(h,1);
	fprintf(h,"%s=1",__abal_focus_item);
	linefeed(h);
	indent(h,1);
	fprintf(h,"%ss=%u",__abal_focus_item,fptr->focus);
	linefeed(h);

	if ( Abal_Config.generate_program ) {
		if (!( Abal_Config.generate_overlay )) {
			abal_visual_startup(h,0);
			abal_visual_control(h,fptr);
			}
		else	abal_form_style(h,fptr);
		}
	else	abal_form_style(h,fptr);

	abal_page_control(h);

	/* Ensure activation of mouse move events if required */
	/* -------------------------------------------------- */
	if ( fptr->mimoflags & _MIMO_MOVE ) {
		indent(h,1); 
		fprintf(h,"Event(0)=(Event(5) or _MIMO_MOVE)"); 
		linefeed(h);
		}

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		if ( fptr->formflags & _MULTILINGUAL ) {
			abal_national_messages(h,iptr);
			}

		if ( iptr->Contents.events.xo_create & _EVENT_IS_FOCUS )
			generate_position_control( h,iptr );

		if ( iptr->Contents.events.xo_hide & _EVENT_IS_POP ) {
			if (((iptr->Contents.style & _FRAME_TYPE ) != _WINDOW_FRAME)
			||  (!( fptr->ispopup ))) {
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
					case	_WIDGET_WORD : fprintf(h,"l_%s=%u",iptr->Contents.name,iptr->Contents.w/2); break;
					case	_WIDGET_LONG : fprintf(h,"l_%s=%u",iptr->Contents.name,iptr->Contents.w/4); break;
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
				if ( Abal_Config.members )
					(void) abal_import_parameter(h,iptr,1);
				if ( Context.Form->ispopup ) {
					if (!( iptr->Contents.events.xo_create & _EVENT_IS_FOCUS ))
						generate_position_control( h,iptr );
					abal_reset_popcontrol(h,iptr,1);
					wptr = iptr;
					}
				break;

			case	_TAB_FRAME 	:
				if ( Abal_Config.members )
					(void) abal_import_parameter(h,iptr,1);
				indent(h,1);
				fprintf(h,"FocusPages(%u) = %u",iptr->Contents.page,iptr->Contents.focus);
				linefeed(h);
				if ( iptr->Contents.datatype == _WIDGET_OVERLAY )
					attach_widget_overlay(h,iptr);
				break;

			case	_SCROLL_FRAME	:
				if ((!( Abal_Config.members ))
				||  (!( abal_import_parameter(h,iptr,1) ))) {
					indent(h,1);
					fprintf(h,"m_%s = 1",iptr->Contents.name);
					linefeed(h);
					indent(h,1);
					fprintf(h,"v_%s = 1",iptr->Contents.name);
					linefeed(h);
					indent(h,1);
					fprintf(h,"l_%s = 1",iptr->Contents.name);
					linefeed(h);
					}
				break;

			case	_PROGRESS_FRAME	:
				if ((!( Abal_Config.members ))
				||  (!( abal_import_parameter(h,iptr,1) ))) {
					indent(h,1);
					fprintf(h,"v_%s = 1",iptr->Contents.name);
					linefeed(h);
					indent(h,1);
					fprintf(h,"l_%s = 1",iptr->Contents.name);
					linefeed(h);
					}
				break;

			case	_FORM_FRAME	:
				if ((!( Abal_Config.members ))
				||  (!( abal_import_parameter(h,iptr,1) ))) {
					alias_redefined_widget(h, iptr, "1", 1 );
					indent(h,1);
					fprintf(h,"b_%s=%c %c",iptr->Contents.name,0x0022,0x0022);
					linefeed(h);
					}
				break;

			case	_EDIT_FRAME	:
				if ((!( Abal_Config.members ))
				||  (!( abal_import_parameter(h,iptr,1) ))) {
					indent(h,1);
					fprintf(h,"b_%s=",iptr->Contents.name);
					if ((!( tptr = abal_payload(iptr) ))
					||  (!(*tptr 			     )))
						fprintf(h,"%c %c",0x0022,0x0022);
					else	string_value(h,tptr);
					}
				linefeed(h);
				break;

			case	_RADIO_FRAME	:
				if ((!( Abal_Config.members ))
				||  (!( abal_import_parameter(h,iptr,1) ))) {
					if ( iptr->Contents.radio == 1 ) {
						indent(h,1);
						fprintf(h,"v_%s = 1",iptr->Contents.name);
						linefeed(h);
						}
					}
				break;
			default		:
				if ( Abal_Config.members )
					(void) abal_import_parameter(h,iptr,1);

			}
		abal_invoke_widget_create(h,iptr,0,1);
		}

	if (( fptr->ispopup )
	&&  ( wptr != (struct form_item *) 0)) {
		indent( h,1 );
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
		linefeed(h);
		}

	abal_returni(h,0,1);
	abal_error_abort(h,1,1);
	abal_error_return(h,__abal_keyword_status,1);
	abal_endproc(h);
}

/*	---------	---------	*/
/*	ABAL FORM	ON REMOVE	*/
/*	---------	---------	*/

public	void	abal_form_onremove( FILE * h, struct form_control * fptr )
{
	struct form_item * iptr;
	struct form_item * wptr=(struct form_item *) 0;
	abal_onremove_methods( h );
	abal_procedure(h,Abal_Config.cname,__abal_method_remove, Abal_Config.members, fptr );
	abal_error_trap(h,1,1);

	for (	iptr=Context.Form->last;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->previous ) {

		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		abal_invoke_widget_remove(h,iptr,0,1);

		if ((iptr->Contents.style & _FRAME_TYPE) == _DATA_FRAME)
			abal_data_destruction(h,iptr,1);

		else if (((iptr->Contents.style & _FRAME_TYPE) == _TAB_FRAME)
		     &&  ( iptr->Contents.datatype == _WIDGET_OVERLAY ))
			detach_widget_overlay(h,iptr);

		else if ((iptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME)
			wptr = iptr;
	
		if ( iptr->Contents.events.xo_hide & _EVENT_IS_POP ) {
			if (((iptr->Contents.style & _FRAME_TYPE ) != _WINDOW_FRAME)
			||  (!( Context.Form->ispopup ))) {
				indent(h,1);
				fprintf(h,"%s=%s(p_%s)",
					__abal_keyword_status,
					__abal_visual_drop,
					iptr->Contents.name 
					);
				linefeed(h);
				}
			}
		}

	if ( Abal_Config.members )
		abal_transfer_parameters(h,0);

	if (( Context.Form->ispopup ) 
	&&  ( wptr != (struct form_item *) 0)) {
		indent( h,1 );
		fprintf(h,"%s=%s(p_%s)",
			__abal_keyword_status,
			__abal_visual_drop,
			wptr->Contents.name 
			);
		linefeed(h);
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
				if (!( iptr->Contents.events.xo_show & _EVENT_IS_COND ))
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
			else if ( iptr->Contents.events.xo_show & _EVENT_IS_COND )
				continue;

			generate_abal_show(h,iptr,1);

			}

		/* check terminal conditions */
		/* ------------------------- */
		if ((!( thispage ))
		&&  ( wptr != (struct form_item *) 0)) {
			/* we have a window : activate paging */
			/* ---------------------------------- */
			fprintf(h,"\tPageNumber=1;");
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

		else if ( iptr->Contents.events.xo_show & _EVENT_IS_COND )
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

public	void	abal_form_onshow( FILE * h )
{
	struct form_item * iptr;
	struct form_item * wptr=(struct form_item*)0;


	/* Allow instance specific widget methods to be generated */
	/* ------------------------------------------------------ */
	abal_onshow_methods( h );

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
				if ( Context.Form->ispopup )
					wptr = iptr;
				break;
			}

		}
	/* Generate the Form SHOW method using the above */
	/* --------------------------------------------- */
	abal_procedure(h,Abal_Config.cname,__abal_method_show,0,(struct form_control *) 0);
	abal_error_trap(h,1,1);

	if ( Context.Form->ispopup ) {
		if ( wptr != (struct form_item *) 0) {
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
	struct form_item * iptr;

	abal_onevent_methods( h );
	abal_procedure(h,Abal_Config.cname,__abal_method_event,0,(struct form_control *) 0);
	abal_error_trap(h,1,1);
	if ( Context.Form->mimoflags & _MIMO_KEYBOARD ) {
		indent(h,1);
		fprintf(h,"%s=%s(MouseEvent)",__abal_keyword_status,__abal_visual_event);
		linefeed(h);
		}

	/* ---------------------------------------------- */
	/* international / multilingual trigger detection */
	/* ---------------------------------------------- */
	if (( Context.Form->formflags & _INTERNATIONAL )
	&&  ( Context.Form->formflags & _MULTILINGUAL  )) {
		abal_detect_trigger_events(h,1);
		}

	switch ( Context.Form->formflags & _FORM_TYPE_FLAGS ) {

		case	_FORM_TYPE_DIALOG	:
			/* very simple for now */
			/* ------------------- */
			indent(h,1);
			fprintf( h,"if ((%s and /0%x) = 0)",__abal_mouse_type,Context.Form->mimoflags);
			linefeed(h);
			abal_returni(h,0,2); /* __abal_focus_item,2); */
			abal_endif(h,1);
			break;

		case	_FORM_TYPE_EVENT 	:
			break;
		}

	for (	iptr=Context.Form->last;  
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

public	void	trigger_abal_event( FILE * h, struct form_item * iptr, int margin )
{
	char	*	eptr;

	if ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME)
		if (!( iptr = locate_radio_event( iptr->parent, iptr->Contents.name ) ))
			return;

	if ((!( eptr =  iptr->Contents.events.on_event ))
	||  (!( *eptr )))
		return;

	indent(h,margin);
	fprintf(h,"if ((%s and /0%x) <> 0)",__abal_mouse_type,iptr->Contents.events.mimo);
	linefeed(h);
	abal_invoke_widget_event(h,iptr,1,margin);
	abal_endif(h,margin);
	return;
}

public	void	trigger_visual_object_event( FILE * h, struct form_item * iptr, int margin )
{
	char	*	eptr;
	indent(h,margin);
	fprintf(h,"if ((%s and /0%x) <> 0)",__abal_mouse_type,iptr->Contents.events.mimo);
	linefeed(h);
	if ((!( eptr =  iptr->Contents.events.on_event ))
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

public	void	abal_widget_useevent( 
		FILE * h, struct form_item * iptr, int margin )
{
	char	*	optr;

	if (!( iptr->Contents.events.xo_event & _EVENT_IS_FOCUS ))
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
				if (!( iptr->Contents.events.on_event )) {
					indent(h,margin+1);
					fprintf(h,"if ((%s and _MIMO_UP) <> 0)",__abal_mouse_type);
					linefeed(h);
					indent(h,margin+2);
					fprintf(h,"KeyCode=27");
					linefeed(h);
					abal_break(h,margin+2);
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
				fprintf(h,"if ((%s and _MIMO_DOWN)<> 0)",__abal_mouse_type);
				linefeed(h);
				indent(h,margin+2);
				fprintf(h,"Status = %s%s(%s)",Abal_Config.cname,__abal_method_lose_focus,optr);
				linefeed(h);
				indent(h,margin+2);
				fprintf(h,"PageNumber = %u",iptr->Contents.page);
				linefeed(h);
				indent(h,margin+2);
				fprintf(h,"Status = %s%s(%s)",Abal_Config.cname,__abal_method_show,optr);
				linefeed(h);
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
				indent(h,margin+1);
				fprintf(h,"%s%s(%s)",Abal_Config.cname,__abal_method_show,optr);
				linefeed(h);
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
				trigger_abal_event(h,iptr,margin+1);
				abal_continue(h,margin);
				break;

			case	_BUTTON_FRAME	:
				abal_case_focus(h,iptr,margin);
				abal_comment(h,iptr->Contents.name,margin+1);
				indent(h,margin+1);
				fprintf(h,"if (( %s and _MIMO_DOWN) <> 0)",__abal_mouse_type);
				linefeed(h);
				abal_button_widget(h,iptr,margin+2,8);
				abal_endif(h,margin+1);
				indent(h,margin+1);
				fprintf(h,"if (( %s and _MIMO_UP) <> 0)",__abal_mouse_type);
				linefeed(h);
				abal_button_widget(h,iptr,margin+2,0);
				abal_endif(h,margin+1);
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
				trigger_visual_object_event(h,iptr,margin+1);
				abal_continue(h,margin);
				break;

			case	_EDIT_FRAME	:
				if ( iptr->Contents.datatype == _WIDGET_KONSTANT )
					break;

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

	if (!( iptr->Contents.events.xo_event & _EVENT_IS_FOCUS ))
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

	if (!( iptr->Contents.events.xo_event & _EVENT_IS_FOCUS ))
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

	abal_onlose_methods( h, __abal_method_lose_focus );

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
	abal_if(h,margin,"FocusItem < FocusItems");
		indent(h,margin+1);
		fprintf(h,"FocusItem = FocusItem+1");
		linefeed(h);
	abal_else(h,margin);
		indent(h,margin+1);
		fprintf(h,"FocusItem = 1");
		linefeed(h);
	abal_endif(h,margin);
	abal_continue(h,margin);
	return;
}

public	void	abal_form_onfocus( FILE * h )
{
	char *	mptr;
	struct form_item * iptr;
	struct	window_control * pwptr=(struct window_control *) 0;

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		mptr = "o";
	else	mptr = "\0";

	abal_onget_methods( h, __abal_method_get_focus );
	abal_procedure(h,Abal_Config.cname,__abal_method_focus,0,(struct form_control *) 0);
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
	generate_abal_flush(h,1);
	abal_do(h,1);
	abal_label(h,"Continue");
	abal_select(h,__abal_focus_item,2);

	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (!( iptr->Contents.events.xo_get_focus & _EVENT_IS_FOCUS ))
			continue;
		else	generate_abal_focus(h,iptr);
		}

	abal_default(h,2); indent(h,3); fprintf(h,"KeyCode=5"); linefeed(h);
	abal_endsel(h,2);
	abal_label(h,"Retry");
	abal_select(h,"KeyCode",2);

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
					indent(h,4); fprintf(h,"Goto &Retry");
					linefeed(h);
					abal_endif(h,3);
					}
				}
			if ( Context.Form->formflags & _FORM_DEFAULT ) {
				if ((pwptr = connect_production_window()) != (struct window_control *) 0) {
					indent(h,3);
					fprintf(h,"if (( %s  and  _MIMO_ALT) = 0) ",__abal_mouse_type);
					linefeed(h);
					indent(h,4);
					fprintf(h,"if (( %s <  %u )'",__abal_mouse_column,pwptr->x);
					linefeed(h);
					indent(h,4);
					fprintf(h,"or ( %s <  %u )'",__abal_mouse_row   ,pwptr->y);
					linefeed(h);
					indent(h,4);
					fprintf(h,"or ( %s >  %u )'",__abal_mouse_column,pwptr->x+pwptr->w);
					linefeed(h);
					indent(h,4);
					fprintf(h,"or ( %s >  %u )) ",__abal_mouse_row   ,pwptr->y+pwptr->h);
					linefeed(h);
					indent(h,5);
					fprintf(h,"if (( %s  and  _MIMO_MOVE) <> 0) ",__abal_mouse_type);
					linefeed(h);
					abal_continue(h,6);
					abal_else(h,5);
					indent(h,6);
					fprintf(h,"Exit(256);");
					linefeed(h);
					abal_endif(h,5);
					abal_endif(h,4);
					abal_endif(h,3);
					}
				}
			abal_form_useevent(h,3);
			abal_break(h,3);

		if ( Context.Form->formflags & _FORM_ESC ) {
			abal_case(h,27,2);
			abal_break(h,3);
			}
		if ( Context.Form->formflags & _FORM_RC ) {
			abal_case(h,13,2);
			abal_break(h,3);
			}
		else	{
			abal_case(h,13,2);
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
			abal_if(h,3,"FocusItem > 1");
				indent(h,4);
				fprintf(h,"FocusItem = FocusItem-1");
				linefeed(h);
			abal_else(h,3);
				indent(h,4);
				fprintf(h,"FocusItem = FocusItems");
				linefeed(h);
			abal_endif(h,3);
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


	abal_endsel(h,2);
	abal_break(h,2);
	abal_loop(h,1);
		} /* ! can focus */
	abal_returni(h,0,1);
	abal_error_abort(h,1,1);
	abal_error_return(h,__abal_keyword_status,1);
	abal_endproc(h);
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
	fprintf(h,"%s preconstruction(%s,ptr a$,ptr b$,ptr c$, ptr d$,ptr e$) ",__abal_keyword_proc,__abal_overlay_object);
	linefeed(h);
	abal_endproc(h);
	fprintf(h,"%s postdestruction(%s,ptr a$,ptr b$,ptr c$, ptr d$,ptr e$) ",__abal_keyword_proc,__abal_overlay_object);
	linefeed(h);
	abal_endproc(h);
	abal_segment(h,__abal_string_zero);
	abal_error_trap(h,1,1);
	indent(h,1);
	fprintf(h,"%s=1:(/1,X3,$,X,$,/1),",__abal_keyword_print);
	quoted_string(h,"Sing/Abal Overlay" );
	linefeed(h);
	return;
}
			
public	void	module_prototype( struct form_control * fptr )
{
	struct forms_method * mptr;
	char	*	pname;
	FILE	*	h;

	if (!(pname = allocate_string( fptr->prodname ) ))
		return;
	else if (!( pname = enforce_extension( pname, EXT_EXTENSION ) ))
		return;
	else if (( h = fopen( pname, "wa" )) != (FILE *) 0) {
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
		fprintf(h,"%s ",__abal_keyword_extern);
		abal_signature(h,Abal_Config.cname,"\0", Abal_Config.members, fptr );
		abal_forms_method_extern(h,Context.Form);
		close_file_exclusion(h,pname);
		fclose(h);
		}
	liberate( pname );
	return;
}
	
public	void	abal_form_ondoit( FILE * h, struct form_control * fptr )
{
	char	* mptr;

	if ( Abal_Config.generate_program ) {

		if ( Abal_Config.generate_overlay ) {
			mptr = "o";
			open_overlay_onexec(h,fptr);
			}
		else	{
			mptr = "\0";
			abal_segment(h,__abal_string_zero);
			abal_error_trap(h,1,1);
			if ( fptr->formflags & _FORM_COMMANDLINE ) {
				indent(h,1);	
				fprintf(h,"ArgN = %u",fptr->argvcount);	
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
		abal_signature(h,Abal_Config.cname,"\0", Abal_Config.members, fptr );
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

public  void	export_abal_form( FILE * h )
{
	struct form_item * iptr;
	struct form_item * wptr;
	int	i;
	int	isoverlay;

	Abal_Config.generate_overlay = Context.Form->isoverlay;
	Abal_Config.generate_program = Context.Form->isprogram;


	if (( Abal_Config.generate_overlay )
	&&  ( Abal_Config.generate_program ))
		isoverlay = 1;
	else	isoverlay = 0;

	Abal_Config.page_control       = 0;
	Abal_Config.members            = 0;
	Abal_Config.action             = 0;
	Abal_Config.actions            = 8;

	if ( Abal_Config.generate_program ) 
		Abal_Config.cname = "On";

	else if (!( Abal_Config.cname = Context.Form->identifier ))
		Abal_Config.cname = "dialog_box";

	else if (!( *Abal_Config.cname ))
		Abal_Config.cname = "dialog_box";


	/* Generate File Banner Block */
	production_banner(h,_GENERATE_BAL,Context.Form->loadname,Context.Form->prodname);

	/* ------------------------------- */
	/* Generate Inclusions for Program */
	/* ------------------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_form_onstart( h, Context.Form->objects );

	/*	------		*/
	/* 	EXTERN		*/
	/*	------		*/
	abal_extern_methods(h, Context.Form );

	/*	-------		*/
	/* 	FORWARD		*/
	/*	-------		*/
	abal_forward_methods(h, Context.Form );

	/* 	METHODS		*/
	/*	-------		*/
	abal_forms_members(h,Context.Form);
	abal_forms_methods(h,Context.Form);

	/* -------------------- */
	/*	ON _ CREATE	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_form_oncreate( h,Context.Form );

	/* -------------------- */
	/*	ON _ HIDE  	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_form_onhide( h );

	/* -------------------- */
	/*	ON _ REMOVE	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_form_onremove( h,Context.Form );


	/* -------------------- */
	/*	ON _  SHOW 	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_form_onshow( h );

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

	/* --------- */
	/* ON _ DOIT */
	/* --------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_form_ondoit(h,Context.Form);

	/* ----------- */
	/* ON _ FINISH */
	/* ----------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_form_onfinish(h);
	return;
}

#endif	/* _abalform_c */

