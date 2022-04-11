#ifndef	_plusform_c
#define	_plusform_c

public	void	generate_aplus_file_class( FILE * h, struct form_control * fptr )
{
	struct	form_item * iptr;
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((iptr->Contents.style & _FRAME_TYPE) == _DATA_FRAME) {
			if (( iptr->Contents.align & 7 ) == _SIFILE_FRAME)
				generate_aplus_sifile_class(h, iptr );
			else if (( iptr->Contents.align & 7 ) == _MCFILE_FRAME)
				generate_aplus_mcfile_class(h, iptr );
			}
		else if ((iptr->Contents.style & _FRAME_TYPE) == _FORM_FRAME) {
			generate_aplus_table_class(h, iptr );
			}
		}
	return;
}					

public	void	aplus_visual_resolution( FILE * h )
{
	int	truecolour=256;
	if ( Context.Form ) {
		if ( Context.Form->abal.flags & 256 )
			truecolour += 512;
		}
	fprintf(h,"visual_library_resolution vlr(%u+%u)",TargetBiosMode,truecolour);
	linefeed(h);
	return;
}

/*	----------------------------------------------		*/
/*	A P L U S _ F O R M _ O N S T A R T ( file * )		*/
/*	----------------------------------------------		*/
public	void	aplus_form_onstart( FILE * h )
{
	/* Generate File Banner Block */

	production_banner(h,_GENERATE_ABAL,Context.Form->loadname,Context.Form->prodname);

	open_class_exclusion(h,Abal_Config.cname);

	aplus_inclusion(h);

	abal_visual_dependance(h,Context.Form);

	generate_aplus_file_class(h, Context.Form );

	linefeed(h); fprintf(h,"%s\t\t%s",keyword_class,Abal_Config.cname); linefeed(h);

	fprintf(h,"(%s visual_group)",keyword_public);  
	linefeed(h);
	fprintf(h,"%s dcl focus_item%c" ,keyword_private,0x0025); linefeed(h);
	fprintf(h,"%s dcl focus_items%c",keyword_private,0x0025); linefeed(h);
	fprintf(h,"%s dcl originx%c"	,keyword_private,0x0025); linefeed(h);
	fprintf(h,"%s dcl originy%c"	,keyword_private,0x0025); linefeed(h);

	if ( Abal_Config.generate_program )
		if (!( Abal_Config.generate_overlay ))
			aplus_visual_resolution(h);

	generate_primary_create( h );

	return;

}

/*	------------------------------------------------	*/
/*	A P L U S _ F O R M _ O N C R E A T E ( file * )	*/
/*	------------------------------------------------	*/
public	struct form_item * aplus_form_oncreate( FILE * h, struct form_control * fptr )
{
	struct window_control  Window;
	int	i;
	char *	fname;
	int	focus_items=0;
	char *	mptr;
	struct form_item * iptr;
	struct form_item * wptr=(struct form_item *) 0;

	fprintf(h,"%s visual_palette colourmap(%c%s%c;%u)",
		keyword_private,
		0x0022,SingConf->palette,0x0022,strlen( SingConf->palette ));

	linefeed(h);

	for (i=FONT_MIN; i< FONT_MAX; i++ ) {
		if (!(fname = font_name[i]))
			continue;
		else	{
			fprintf(h,"%s visual_font font%u(%c%s%c;%u)",
				keyword_private,
				i,0x0022,fname,0x0022,strlen(fname));
			linefeed(h);
			}
		}

	/* detect a window component */
	for (	wptr=(struct form_item *) 0,
		iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if ((iptr->Contents.style&_FRAME_TYPE)==_WINDOW_FRAME) {
			wptr = iptr;
			break;
			}
		}

	if ( Context.Form->ispopup ) {
		form_Dimensions( &Window, fptr );
		fprintf(h,"%s visual_pushpop __FormPush(originx+%u;originy+%u;%u;%u)",keyword_private,Window.x,Window.y,Window.w,Window.h);
		linefeed(h);
		}

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {

		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else	{
			instance_aplus(h,iptr);
			iptr->Contents.focus = ++focus_items;
			}
			
		}

	wptr = generate_on_create( h, wptr, focus_items );
	aplus_end(h);

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if ( iptr->Contents.events.on_create ) {
			aplus_object_method(h,iptr->Contents.name,"create",iptr->Contents.events.on_create,
				( iptr->Contents.events.xo_create & _EVENT_IS_FUNCTION ));
			}
		}

	return(wptr);

}

/*	----------------------------------------------		*/
/*	A P L U S _ F O R M _ O N H I D E   ( file * )		*/
/*	----------------------------------------------		*/
public	void	aplus_form_onhide  ( FILE * h )
{
	struct form_item * iptr;

	generate_on_hide( h );

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if ( iptr->Contents.events.on_hide ) {
			aplus_object_method(h,iptr->Contents.name,"hide",iptr->Contents.events.on_hide,
				( iptr->Contents.events.xo_hide & _EVENT_IS_FUNCTION ));
			}
		}
	return;
}

/*	------------------------------------------------	*/
/*	A P L U S _ F O R M _ O N R E M O V E ( file * )	*/
/*	------------------------------------------------	*/
public	void	aplus_form_onremove( FILE * h, struct form_item * wptr, struct form_control * fptr )
{
	struct form_item * iptr;

	generate_on_remove( h, wptr );	aplus_end(h);

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if ( iptr->Contents.events.on_remove ) {
			aplus_object_method(h,iptr->Contents.name,"remove",iptr->Contents.events.on_remove,
				( iptr->Contents.events.xo_remove & _EVENT_IS_FUNCTION ));
			}
		}

	return;
}

/*	----------------------------------------------		*/
/*	A P L U S _ F O R M _ O N S H O W   ( file * )		*/
/*	----------------------------------------------		*/
public	void	aplus_form_onshow  ( FILE * h, struct form_item * wptr )
{
	struct form_item * iptr;

	generate_on_show(h,wptr);

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if ( iptr->Contents.events.on_show ) {
			aplus_object_method(h,iptr->Contents.name,"show",iptr->Contents.events.on_show,
				( iptr->Contents.events.xo_show & _EVENT_IS_FUNCTION ));
			}
		}
	return;
}

/*	----------------------------------------------		*/
/*	A P L U S _ F O R M _ O N E V E N T ( file * )		*/
/*	----------------------------------------------		*/
public	void	aplus_form_onevent ( FILE * h, struct form_item * wptr  )
{
	struct form_item * iptr;

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if (!( iptr->Contents.events.xo_event & _EVENT_IS_FOCUS ))
			continue;
		else if (!( iptr->Contents.events.on_event ))
			continue;
		else if(( iptr->Contents.datatype == _WIDGET_OVERLAY ) 
		     || ( iptr->Contents.datatype == _WIDGET_CHAIN   ) 
		     || ( iptr->Contents.datatype == _WIDGET_SYSTEM  ) 
		     || ( iptr->Contents.datatype == _WIDGET_LOADGO  )){
			aplus_object_trigger(h,iptr->Contents.name,"event",iptr->Contents.events.on_event,
				( iptr->Contents.events.xo_event & _EVENT_IS_FUNCTION ));
			}
		else	{
			aplus_object_method(h,iptr->Contents.name,"event",iptr->Contents.events.on_event,
				( iptr->Contents.events.xo_event & _EVENT_IS_FUNCTION ));
			}
		}

	generate_on_event(h,wptr);

	return;

}

public	void	aplus_getfocus_methods( FILE * h )
{
	struct form_item * iptr;
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if ( iptr->Contents.events.on_get_focus ) {
			aplus_object_method(h,iptr->Contents.name,"getfocus",iptr->Contents.events.on_get_focus,
				( iptr->Contents.events.xo_get_focus & _EVENT_IS_FUNCTION ));
			}
		}
	return;
}

public	void	aplus_losefocus_methods( FILE * h )
{
	struct form_item * iptr;
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if ( iptr->Contents.events.on_lose_focus ) {
			aplus_object_method(h,iptr->Contents.name,"losefocus",iptr->Contents.events.on_lose_focus,
				( iptr->Contents.events.xo_lose_focus & _EVENT_IS_FUNCTION ));
			}
		}
	return;
}


/*	----------------------------------------------		*/
/*	A P L U S _ F O R M _ O N F O C U S ( file * )		*/
/*	----------------------------------------------		*/
public	void	aplus_form_onfocus ( FILE * h, struct form_item * wptr )
{
	struct form_item * iptr;

	generate_on_get_focus(h,wptr);
	aplus_getfocus_methods(h);
	generate_on_lose_focus(h,wptr);
	aplus_losefocus_methods(h);

	return;
}

/*	--------------------------------------------------	*/
/*	A P L U S _ O V E R L A Y _ A T T A C H ( file * )	*/
/*	--------------------------------------------------	*/
public	void	aplus_overlay_attach( FILE * h )
{
	return;
}

/*	--------------------------------------------------	*/
/*	A P L U S _ O V E R L A Y _ D E T A C H ( file * )	*/
/*	--------------------------------------------------	*/
public	void	aplus_overlay_detach( FILE * h )
{
	return;
}

/*	------------------------------------------------	*/
/*	A P L U S _ F O R M _ O N F I N I S H ( file * )	*/
/*	------------------------------------------------	*/
public	void	aplus_form_onfinish( FILE * h )
{
	linefeed(h);
	fprintf(h,"%s\t\t%s",keyword_endclass,Abal_Config.cname);
	linefeed(h);
	close_class_exclusion(h,Abal_Config.cname);
	return;
}

/*	------------------------------------------------	*/
/*	A P L U S _ F O R M _ O N D O I T     ( file * )	*/
/*	------------------------------------------------	*/
public	void	aplus_form_ondoit( FILE * h )
{
	if ( Abal_Config.generate_program ) {
		if ( Abal_Config.generate_overlay ) {
			linefeed(h);
			aplus_overlay_loader(h);
			fprintf(h,"Program Overlay %s_loader Sing End",Abal_Config.cname);
			}
		else	{

			linefeed(h);
			fprintf(h,"%s %s_application",keyword_class,Abal_Config.cname);
			linefeed(h);
			fprintf(h,"(%s visual_command_line)",keyword_public);
			linefeed(h); linefeed(h);

			fprintf(h,"%s %s vA(CommandLine;Len$(CommandLine))",keyword_public,Abal_Config.cname);
			linefeed(h); linefeed(h);

			fprintf(h,"%s inline constructor on_create:",keyword_public);
				linefeed(h);
				indent(h,1);
				fprintf(h,"vA.on_show");	linefeed(h);
				indent(h,1); 
				fprintf(h,"vA.on_get_focus"); 	linefeed(h);
				aplus_end(h);			linefeed(h);

			fprintf(h,"%s",keyword_endclass);			
			linefeed(h); linefeed(h);

			fprintf(h,"Program %s_application Sing End",Abal_Config.cname);
			linefeed(h);
			}
		}
	else if ( Abal_Config.generate_overlay ) {
		linefeed(h);
		aplus_overlay_loader(h);
		fprintf(h,"Module %s Sing End",Abal_Config.cname);
		}
	linefeed(h);
	abal_comment(h,"end of file",0);
	linefeed(h);
}

/*	------------------------------------------------	*/
/*	  E X P O R T _ A P L U S _ F O R M ( file )		*/
/*	------------------------------------------------	*/
public	void	export_aplus_form( FILE * h )
{
	struct form_item * wptr=(struct form_item *) 0;

	/* ---------------------------------------------------- */
	/* Determine Object Prefix and Configuration Parameters */
	/* ---------------------------------------------------- */
	Abal_Config.generate_overlay = Context.Form->isoverlay;
	Abal_Config.generate_program = Context.Form->isprogram;

	Abal_Config.page_control       = 0;
	Abal_Config.members            = 0;
	Abal_Config.action             = 0;
	Abal_Config.actions            = 8;

	if (!( Abal_Config.cname = Context.Form->identifier ))
		Abal_Config.cname = "visual_component";

	else if (!( *Abal_Config.cname ))
		Abal_Config.cname = "visual_component";

	/* ------------------------------- */
	/* Generate Inclusions for Program */
	/* ------------------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	aplus_form_onstart( h );

	/*	-------		*/
	/* 	MEMBERS		*/
	/*	-------		*/
	aplus_forms_members(h,Context.Form);

	/*	-------		*/
	/* 	METHODS		*/
	/*	-------		*/
	aplus_forms_methods(h,Context.Form);

	/* -------------------- */
	/*	ON _ CREATE	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	wptr = aplus_form_oncreate( h,Context.Form );

	/* -------------------- */
	/*	ON _ HIDE  	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	aplus_form_onhide( h );

	/* -------------------- */
	/*	ON _ REMOVE	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	aplus_form_onremove( h, wptr, Context.Form );


	/* -------------------- */
	/*	ON _  SHOW 	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	aplus_form_onshow( h, wptr );

	/* -------------------- */
	/*	ON _ EVENT 	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	aplus_form_onevent( h, wptr );

	/* -------------------- */
	/*	ON _ FOCUS 	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	aplus_form_onfocus( h, wptr );

	/* -------------------- */
	/*	ON _ ATTACH	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	aplus_overlay_attach( h );

	/* -------------------- */
	/*	ON _ DETACH	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	aplus_overlay_detach( h );

	/* ----------- */
	/* ON _ FINISH */
	/* ----------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	aplus_form_onfinish(h);

	/* --------- */
	/* ON _ DOIT */
	/* --------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	aplus_form_ondoit(h);

	return;
}

#endif	/* _plusform_c */
	/* ----------- */


