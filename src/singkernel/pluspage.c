/*	----------------------------------------------		*/
/*	A P L U S _ P A G E _ O N S T A R T ( file * )		*/
/*	----------------------------------------------		*/
public	void	aplus_page_onstart( FILE * h )
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
	fprintf(h,"%s visual_printer %s printer",
		keyword_private,keyword_pointer);	 linefeed(h);
	fprintf(h,"%s visual_page    %s paper",
		keyword_private,keyword_pointer);	 linefeed(h);
	fprintf(h,"%s dcl focus_item%c" ,keyword_private,0x0025); linefeed(h);
	fprintf(h,"%s dcl focus_items%c",keyword_private,0x0025); linefeed(h);
	fprintf(h,"%s dcl originx%c"	,keyword_private,0x0025); linefeed(h);
	fprintf(h,"%s dcl originy%c"	,keyword_private,0x0025); linefeed(h);

	generate_primary_create( h);

	return;

}

/*	------------------------------------------------	*/
/*	A P L U S _ P A G E _ O N C R E A T E ( file * )	*/
/*	------------------------------------------------	*/
public	struct form_item * aplus_page_oncreate( FILE * h, struct form_control * fptr )
{
	int	i;
	char *	fname;
	char *	device;
	char *	driver;
	int	focus_items=0;
	int	dpi;
	char *	mptr;
	struct form_item * iptr;
	struct form_item * wptr=(struct form_item *) 0;
	struct window_control Window;

	form_Dimensions( &Window, Context.Form );
	dpi = page_resolution();
	Context.Form->printout.ZoneWidth  = Window.w;
	Context.Form->printout.ZoneHeight = Window.h;
	if (!( device = Context.Form->printout.DeviceName ))
		device = "LO";
	else if (!( *device ))
		device = "LO";

	if (!( driver = Context.Form->printout.DriverName ))
		driver = "printer";
	else if (!( *driver ))
		driver = "printer";


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

	for (	wptr=(struct form_item *) 0,
		iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {

		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		if ((!( wptr ))
		&&  ((iptr->Contents.style&_FRAME_TYPE)==_WINDOW_FRAME))
			wptr = iptr;

		instance_aplus(h,iptr);
		iptr->Contents.focus = ++focus_items;
			
		}

	wptr = generate_on_create( h, wptr, focus_items );

	indent(h,1); fprintf(h,"%s printer",keyword_forget); linefeed(h);
	indent(h,1); fprintf(h,"%s paper",keyword_forget); linefeed(h);

	indent(h,1); fprintf(h,"%s printer(",keyword_create);
	string_value( h, device );
	fprintf(h,";%u;%u;%u;%u;",dpi,
				( Context.Form->printout.Layout == 1 ?
				  Context.Form->printout.ZoneWidth  :
				  Context.Form->printout.ZoneHeight ),
				( Context.Form->printout.Layout == 1 ?
				  Context.Form->printout.ZoneHeight :
				  Context.Form->printout.ZoneWidth  ),
				  Context.Form->printout.Alignment  );
	string_value( h, driver );
	fprintf(h,")");
	linefeed(h);
	indent(h,1); fprintf(h,"%s paper(%u;%u)",
			keyword_create,
			( Context.Form->printout.Layout == 1 ?
				Context.Form->printout.ZoneWidth  :
				Context.Form->printout.ZoneHeight ),
			( Context.Form->printout.Layout == 1 ?
				Context.Form->printout.ZoneHeight :
				Context.Form->printout.ZoneWidth  ));
	linefeed(h);

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
	return( wptr );

}

/*	------------------------------------------------	*/
/*	A P L U S _ P A G E _ O N R E M O V E ( file * )	*/
/*	------------------------------------------------	*/
public	void	aplus_page_onremove( FILE * h, struct  form_item * wptr, struct form_control * fptr )
{
	struct form_item * iptr;

	generate_on_remove( h, wptr );

	indent(h,1); fprintf(h,"if (%s(paper) <> 0) :: %s paper(0;0) :: endif",keyword_validptr,keyword_remove);
	linefeed(h);
	indent(h,1); fprintf(h,"if (%s(printer) <> 0) :: %s printer(%c %c;0;0) :: endif",keyword_validptr,keyword_remove,0x0022,0x0022);
	linefeed(h);

	aplus_end(h);

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

/*	------------------------------------------------	*/
/*	A P L U S _ P A G E _ O N F L U S H   ( file * )	*/
/*	------------------------------------------------	*/

public	void	aplus_page_onflush( FILE * h )
{
	linefeed(h);
	aplus_integer_overload_function(h,"on_flush");
	linefeed(h);

	if ( Context.Form->printout.FeedOpt == 2 ) {
		indent(h,1); fprintf(h,"printer.pagefeed"); linefeed(h);
		}

	if ( Context.Form->printout.Layout != 1 ) {
		indent(h,1); fprintf(h,"paper.rotate(90)"); linefeed(h);
		}

	indent(h,1); fprintf(h,"paper.output(printer)"); linefeed(h);

	if ( Context.Form->printout.Layout != 1 ) {
		indent(h,1); fprintf(h,"paper.rotate(90)"); linefeed(h);
		}

	if ( Context.Form->printout.FeedOpt == 3 ) {
		indent(h,1); fprintf(h,"printer.pagefeed"); linefeed(h);
		}

	aplus_end(h);
	return;
}

/*	------------------------------------------------	*/
/*	A P L U S _ P A G E _ O N F I N I S H ( file * )	*/
/*	------------------------------------------------	*/
public	void	aplus_page_onfinish( FILE * h )
{
	linefeed(h);
	aplus_overload_function(h,"on_exec");		linefeed(h);
	indent(h,1); fprintf(h,"on_show");	 	linefeed(h);
	indent(h,1); fprintf(h,"on_get_focus");	 	linefeed(h);
	indent(h,1); fprintf(h,"on_flush");	 	linefeed(h);
	aplus_end(h);

	linefeed(h);
	fprintf(h,"%s\t\t%s",keyword_endclass,Abal_Config.cname);
	linefeed(h);

	close_class_exclusion(h,Abal_Config.cname);

	return;
}

/*	----------------------------------------------		*/
/*	A P L U S _ P A G E _ O N S T A R T ( file * )		*/
/*	----------------------------------------------		*/
public	void	aplus_page_ongetfocus( FILE * h, struct form_item * wptr )
{
	char	*	eptr;
	struct form_item * iptr;

	aplus_form_onhide( h );
	aplus_form_onevent( h,wptr );

	aplus_getfocus_methods(h);
	generate_on_lose_focus(h,wptr);
	aplus_losefocus_methods(h);

	aplus_overload_function(h,"on_get_focus");
	linefeed(h);
	indent(h,1); fprintf(h,"local dcl pagecontrol%%"); linefeed(h);
	abal_repeat(h,1);
	indent(h,2); fprintf(h,"pagecontrol=0");	  linefeed(h);

	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (!( eptr =  iptr->Contents.events.on_get_focus))
			continue;
		else if (!( *eptr ))
			continue;

		indent(h,2); fprintf(h,"visual_event..cancel");	  linefeed(h);
		activate_method(h,iptr->Contents.name,"getfocus",iptr->Contents.events.on_get_focus,2);

		/* Detect ESCAPE/ENTER trapping required */
		/* ------------------------------------- */
		if ( Context.Form->formflags & (_FORM_ESC | _FORM_RC) ) {

			indent(h,2); fprintf(h,"select visual_event..keycode");
			linefeed(h);

			/* Handle ESCAPE returns */
			/* --------------------- */
			if ( Context.Form->formflags & _FORM_ESC ) {
				indent(h,2);	fprintf(h,"case 27 :: exit");
				linefeed(h);
				}

			/* Handle VALIDATE returns */
			/* ----------------------- */
			if ( Context.Form->formflags & _FORM_RC ) {
				indent(h,2);	fprintf(h,"case 13 :: pagecontrol += 1");
				linefeed(h);
				}

			indent(h,2); fprintf(h,"endsel");
			linefeed(h);
			}

		if ((( eptr =  iptr->Contents.events.on_lose_focus) != (char *) 0)
		&&  ( *eptr != 0 )) {
			activate_method(h,iptr->Contents.name,"losefocus",iptr->Contents.events.on_lose_focus,2);
			}

		}

	indent(h,2); fprintf(h,"if (pagecontrol <> 0) :: result=on_flush :: endif"); 	linefeed(h);
	indent(h,1); fprintf(h,"until ( pagecontrol=0 )");	linefeed(h);

	aplus_end(h);
	return;
}


/*	------------------------------------------------	*/
/*	A P L U S _ P A G E _ O N D O I T     ( file * )	*/
/*	------------------------------------------------	*/
public	void	aplus_page_ondoit( FILE * h )
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
			linefeed(h); linefeed(h);

			fprintf(h,"%s %s vA",keyword_public,Abal_Config.cname);
			linefeed(h); linefeed(h);

			fprintf(h,"%s inline constructor on_create:",keyword_public);
				linefeed(h);
				indent(h,1);
				fprintf(h,"vA.on_show");	linefeed(h);
				indent(h,1); 
				fprintf(h,"vA.on_get_focus"); 	linefeed(h);
				indent(h,1); 
				fprintf(h,"vA.on_flush"); 	linefeed(h);
				aplus_end(h);			linefeed(h);

			fprintf(h,"%s",keyword_endclass);			
			linefeed(h); linefeed(h);

			fprintf(h,"Program %s_application Sing End",Abal_Config.cname);
			linefeed(h);
			}
		}
	else if ( Abal_Config.generate_overlay ) {
		linefeed(h);
		fprintf(h,"Module %s Sing End",Abal_Config.cname);
		}
	linefeed(h);
	abal_comment(h,"end of file",0);
	linefeed(h);
}


/*	------------------------------------------------	*/
/*	  E X P O R T _ A P L U S _ P A G E ( file )		*/
/*	------------------------------------------------	*/

public	void	export_aplus_page( FILE * h )
{
	struct form_item * iptr;
	struct form_item * wptr;
	int	i;

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
		Abal_Config.cname = "printer_page";

	else if (!( *Abal_Config.cname ))
		Abal_Config.cname = "printer_page";

	/* ------------------------------- */
	/* Generate Inclusions for Program */
	/* ------------------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	aplus_page_onstart( h );

	/*	-------		*/
	/* 	METHODS		*/
	/*	-------		*/
	aplus_forms_methods(h,Context.Form);

	/* -------------------- */
	/*	ON _ CREATE	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	wptr = aplus_page_oncreate( h, Context.Form );

	/* -------------------- */
	/*	ON _ REMOVE	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	aplus_page_onremove( h, wptr, Context.Form );

	/* -------------------- */
	/*	ON _ FLUSH 	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	aplus_page_onflush( h );

	/* -------------------- */
	/*	ON _  SHOW 	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	aplus_form_onshow( h,wptr );

	/* -------------------- */
	/*	ON _ FOCUS 	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	aplus_page_ongetfocus( h, wptr );

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
	aplus_page_onfinish(h);

	/* --------- */
	/* ON _ DOIT */
	/* --------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	aplus_page_ondoit(h);

	return;

}

