
#ifndef	_abalpage_c
#define _abalpage_c

#define	_REPORT_BAR_FG		27
#define	_REPORT_BAR_BG		28
#define	_REPORT_WINDOW_X	100
#define	_REPORT_WINDOW_Y	100
#define	_REPORT_WINDOW_W	200
#define	_REPORT_WINDOW_H	120

/*	---------------------------------	*/
/*	Printer Overlay Method Activation	*/
/*	---------------------------------	*/

public	void	generate_printer_attach( FILE * h, int margin, char * nptr )
{
	/* ---------------------- */
	/* Attach Printer Overlay */
	/* ---------------------- */
	indent(h,margin);
	fprintf(h,"%s %s%s(%c%s%c)",
		__abal_keyword_attach,
		__abal_keyword_raster,__abal_keyword_printer,
		0x0022,nptr,0x0022);

	linefeed(h);
	return;
}

public	void	generate_printer_create( FILE * h, int margin )
{
	/* ---------------------------- */
	/* Printer Overlay Construction */
	/* ---------------------------- */
	indent(h,margin);
	/* 1 + 2 */
	fprintf(h,"%s(%s%s(%u))(%s%s)",
		__abal_keyword_call,
		__abal_keyword_raster,__abal_keyword_method,
		_PRINTER_CREATE,
		__abal_keyword_raster,__abal_keyword_printer);
	linefeed(h);
	return;
}

public	void	generate_printer_open( FILE * h, int margin )
{
	indent(h,margin);
	/* 2 + 2 */
	fprintf(h,"%s=%s(%s%s(%u))(%s%s,%s%s,%s%s,%s%s,%s%s,%s%s,%s%s)",
		__abal_keyword_status,__abal_keyword_call,
		__abal_keyword_raster,__abal_keyword_method,
		_PRINTER_OPEN,
		__abal_keyword_raster,__abal_keyword_printer,
		__abal_keyword_printer,__abal_keyword_name,
		__abal_keyword_printer,__abal_keyword_dpi,
		__abal_keyword_paper,__abal_keyword_width,
		__abal_keyword_paper,__abal_keyword_height,
		__abal_keyword_paper,__abal_keyword_options,
		__abal_keyword_printer,__abal_keyword_driver );
	linefeed(h);
	return;
}

public	void	generate_printer_row( FILE * h, int margin)
{
	/* 3 + 2 */
	indent(h,margin); 
	fprintf(h,"%s=%s(%s%s(%u))(%s%s,%s%s,%s%s)",
		__abal_keyword_status,__abal_keyword_call,
		__abal_keyword_raster,__abal_keyword_method,
		_PRINTER_ROW,
		__abal_keyword_raster,__abal_keyword_printer,
		__abal_keyword_row,__abal_keyword_buffer,
		__abal_keyword_paper,__abal_keyword_width);
	linefeed(h);
	return;
}

public	void	generate_printer_page( FILE * h, int margin)
{
	indent(h,margin);
	/* 4 + 2 */
	fprintf(h,"%s(%s%s(%u))(%s%s)",
		__abal_keyword_call,
		__abal_keyword_raster,__abal_keyword_method,
		_PRINTER_PAGE,
		__abal_keyword_raster,__abal_keyword_printer);
	linefeed(h);

}

public	void	generate_printer_flush( FILE * h, int margin)
{
	indent(h,margin);
	/* 5+2 */
	fprintf(h,"%s(%s%s(%u))(%s%s)",
		__abal_keyword_call,
		__abal_keyword_raster,__abal_keyword_method,
		_PRINTER_FLUSH,
		__abal_keyword_raster,__abal_keyword_printer
		);
	linefeed(h);
	return;
}

public	void	generate_printer_remove( FILE * h, int margin)
{
	indent(h,margin);
	/* 6 + 2 */
	fprintf(h,"%s(%s%s(%u))(%s%s)",
		__abal_keyword_call,
		__abal_keyword_raster,__abal_keyword_method,
		_PRINTER_REMOVE,
		__abal_keyword_raster,__abal_keyword_printer);
	linefeed(h);
	return;
}

public	void	generate_printer_detach( FILE * h, int margin)
{
	indent(h,margin);
	fprintf(h,"%s %s%s",
		__abal_keyword_detach,
		__abal_keyword_raster,__abal_keyword_printer);
	linefeed(h);
	return;
}


/*	----------------------------------	*/
/*	Document Model Production Routines
/*	----------------------------------	*/


public	void	abal_page_onstart( FILE * h, int hasobjects )
{
	int	bufferlength;
	struct window_control Window;

	/* calculate maximum buffer width */
	/* ------------------------------ */
	form_Dimensions( &Window, Context.Form );
	bufferlength = 	( Context.Form->printout.Layout == 1 ? 	Window.w : Window.h );


	if ( hasobjects ) {
		aplus_visual_apl(h);
		}

	/* these pragmas apply to the visual classes */
	/* ----------------------------------------- */
	if ( Abal_Config.generate_program )
		abal_pragmas(h,Context.Form );
	else if ( Abal_Config.generate_overlay )
		abal_pragmas(h,Context.Form );

	abal_user(h,__abal_visual_def);
	abal_user(h,__abal_printer_def);

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
		abal_argv_control(h,Context.Form);
		}

	if ( hasobjects ) {
		aplus_visual_resolution(h);
		}

	/* Printer Overlay Attachment Variables */
	/* ------------------------------------ */
	abal_ptr(h,__abal_keyword_raster,__abal_keyword_printer,_ABAL_STRING,10,0,0);
	abal_field(h,__abal_keyword_raster,__abal_keyword_printer);
	abal_ptr(h,__abal_keyword_raster,__abal_keyword_method,_ABAL_PROC,5,_PRINTER_METHODS,0);
				/* -------------------- */
				/* Method 1 : Create	*/
				/* Method 2 : Open  	*/
				/* Method 3 : Row   	*/
				/* Method 4 : Page  	*/
				/* Method 5 : Close 	*/
				/* Method 6 : Remove	*/
				/* -------------------- */
	abal_ptr(h,__abal_keyword_raster,"Global",_ABAL_STRING,10000,0,0);
	abal_field(h,(char *) 0,(char *) 0);

	/* Standard Printer Page Control Parameters */
	/* ---------------------------------------- */	
	abal_dcl(h,__abal_keyword_printer,__abal_keyword_dpi,	_ABAL_WORD,0,0,0);
	abal_dcl(h,__abal_keyword_printer,__abal_keyword_name,  _ABAL_STRING,64,0,0);
	abal_dcl(h,__abal_keyword_printer,__abal_keyword_driver,_ABAL_STRING,64,0,0);
	abal_dcl(h,__abal_keyword_page,__abal_keyword_row,	_ABAL_WORD,0,0,0);
	abal_dcl(h,__abal_keyword_page,"Number",		_ABAL_WORD,0,0,0);
	abal_dcl(h,"Window","X",_ABAL_WORD,0,0,0);
	abal_dcl(h,"Window","Y",_ABAL_WORD,0,0,0);
	abal_dcl(h,__abal_keyword_page,__abal_keyword_handle,	_ABAL_WORD,0,0,0);
	abal_dcl(h,__abal_keyword_row,__abal_keyword_buffer,	_ABAL_STRING,(bufferlength*4),0,0);
	abal_dcl(h,__abal_keyword_paper,__abal_keyword_width,	_ABAL_WORD,0,0,0);
	abal_dcl(h,__abal_keyword_paper,__abal_keyword_handle,	_ABAL_WORD,0,0,0);
	abal_dcl(h,__abal_keyword_paper,__abal_keyword_height,  _ABAL_WORD,0,0,0);
	abal_dcl(h,__abal_keyword_paper,__abal_keyword_options, _ABAL_WORD,0,0,0);
	abal_dcl(h,__abal_keyword_left,__abal_keyword_margin,	_ABAL_WORD,0,0,0);
	abal_dcl(h,__abal_keyword_right,__abal_keyword_margin,  _ABAL_WORD,0,0,0);
	abal_dcl(h,__abal_keyword_top,__abal_keyword_margin,	_ABAL_WORD,0,0,0);
	abal_dcl(h,__abal_keyword_bottom,__abal_keyword_margin, _ABAL_WORD,0,0,0);

	/* Instance Structure if Required */
	/* ------------------------------ */
	Abal_Config.members = generate_abal_structure(h);

	if ( Abal_Config.generate_program ) {
		if ( Abal_Config.generate_overlay ) {
			abal_overlay_dependance(h);
			}
		else 	{
			abal_visual_forward(h);
			if ( Context.Form->dependance)
				abal_dependance(h,Context.Form->dependance,3);
			}
		Abal_Config.members = 0;
		}
	abal_forms_method_forward(h,Context.Form);
	return;
}

public	void	abal_page_onremove( FILE * h,struct form_control * fptr )
{
	char	*	sptr;
	int	margin=1;
	struct form_item * iptr;
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
		
		if (((iptr->Contents.style & _FRAME_TYPE) == _TAB_FRAME)
		&&  ( iptr->Contents.datatype == _WIDGET_OVERLAY ))
			detach_widget_overlay(h,iptr);
		}

	indent(h,1);
	fprintf(h,"%s(%s(%s%s) <> 0 )",
		__abal_keyword_if,__abal_keyword_validptr,
		__abal_keyword_raster,__abal_keyword_printer);
	linefeed(h);
		margin = 2;
		if ( Context.Form->printout.Preview ) {
			indent(h,margin++);
			fprintf(h,"%s(%s$(%s%s) <> 0)",
				__abal_keyword_if,
				__abal_keyword_len,
				__abal_keyword_printer,__abal_keyword_name);
				linefeed(h);
			}

		generate_printer_flush(h,margin);
		reset_visual_page(h,margin);
		if ( Context.Form->printout.Preview ) {
			abal_else(h,(margin-1));
			indent(h,margin);	
			fprintf(h,"%s=%s(%s%s,0,0)",
				__abal_keyword_status,
				__abal_visual_put,
				__abal_keyword_page,__abal_keyword_handle
				);
			linefeed(h);
			abal_endif(h,--margin);
			}

		generate_printer_remove(h,2);
		generate_printer_detach(h,2);
	abal_endif(h,1);


	/* -------------------------------------------------- */
	/* Visual Buffer and Visual Get for Progression Saver */
	/* -------------------------------------------------- */
	if (((sptr = Context.Form->printout.PageHead ) != (char *) 0)
	&&  ( *sptr != 0 )) {
		indent(h,1);
		fprintf(h,"%s=%s(%s%s,WindowX,WindowY)",
			__abal_keyword_status,
			__abal_visual_put,
			__abal_keyword_paper,__abal_keyword_handle);
		linefeed(h);

		indent(h,1);	fprintf(h,"%s(%s%s > 0)",
					__abal_keyword_if,
					__abal_keyword_paper,__abal_keyword_handle);
		linefeed(h);
		indent(h,2);	fprintf(h,"%s%s=%s(%s%s)",
					__abal_keyword_paper,__abal_keyword_handle,
					__abal_visual_drop,
					__abal_keyword_paper,__abal_keyword_handle);
		linefeed(h);
		abal_endif(h,1);
		}

	/* Restore screen output and release buffer mechanism */
	/* -------------------------------------------------- */
	indent(h,1);	fprintf(h,"%s(%s%s > 0)",
				__abal_keyword_if,
				__abal_keyword_page,__abal_keyword_handle);
	linefeed(h);
	indent(h,2);	fprintf(h,"%s%s=%s(%s%s)",
				__abal_keyword_page,__abal_keyword_handle,
				__abal_visual_drop,
				__abal_keyword_page,__abal_keyword_handle);
	linefeed(h);
	abal_endif(h,1);

	/* Transfer eventual parameter values */
	/* ---------------------------------- */
	if ( Abal_Config.members ) abal_transfer_parameters(h,0);

	if ( Abal_Config.generate_program ) {
		if (!( Abal_Config.generate_overlay )) {
			/* Terminate Visual Library */
			/* ------------------------ */
			indent(h,1);
			fprintf(h,"%s(%s()= -1)",__abal_keyword_if,__abal_visual_liberate);
			linefeed(h);
				abal_return(h,"56",2); 
			abal_endif(h,1);
			}
		}

	abal_return(h,__abal_string_zero,1);
	abal_error_abort(h,1,1);
	abal_error_return(h,__abal_keyword_status,1);
	abal_endproc(h);
	return;
}


public	void	abal_page_oncreate( FILE * h, struct form_control * fptr )
{
	char	envbuffer[80];
	char *	sptr;
	char *	abal_printer_name;
	char *	tptr;
	int	dpi=75;
	int	i;
	struct form_item * iptr;
	struct window_control Window;
	int	margin=1;

	form_Dimensions( &Window, Context.Form );

	if (!( SingConf ))
		abal_printer_name = "printer.at";
	else if (!( abal_printer_name = SingConf->printer ))
		abal_printer_name = "printer.at";

	abal_oncreate_methods( h );

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay )) 
		open_overlay_create(h);
	else	{
		abal_procedure(h,Abal_Config.cname,__abal_method_create, Abal_Config.members, fptr );
 		abal_error_trap(h,1,1);
		if (!( Abal_Config.generate_overlay )) {
			generate_abal_fonts(h);
			/* initialise_abal_fonts(h); */
			}
		}

	indent(h,1);
	fprintf(h,"Status = %s(_VISUAL_GETKEYS,KeyBuffer,Len(KeyBuffer))",__abal_visual_control);
	linefeed(h);

	sprintf(envbuffer,"Env(%cPRINTERAT%c)",0x0022,0x0022);
	abal_initialise_national_language(h,fptr);
	indent(h,1); fprintf(h,"if (Len$(%s)<> 0)",envbuffer); linefeed(h);
	indent(h,2);
	fprintf(h,"%s %s%s(%s)",__abal_keyword_attach,__abal_keyword_raster,__abal_keyword_printer,envbuffer);
	linefeed(h);
	indent(h,1); fprintf(h,"Else"); linefeed(h);
	indent(h,2); fprintf(h,"Select Conf(10)"); linefeed(h);
	indent(h,2); fprintf(h,"Case 3"); linefeed(h);
	generate_printer_attach(h,3,abal_printer_name);
	indent(h,2); fprintf(h,"Case 0,1"); linefeed(h);
	generate_printer_attach(h,3,"printer.at");
	indent(h,2); fprintf(h,"EndSel"); linefeed(h);
	indent(h,1); fprintf(h,"Endif"); linefeed(h);
	
	/* ------------------- */
	/* Validate Attachment */
	/* ------------------- */
	indent(h,1);
	fprintf(h,"%s(%s(%s%s) = 0 )",
		__abal_keyword_if,__abal_keyword_validptr,
		__abal_keyword_raster,__abal_keyword_printer);
	linefeed(h);
		abal_raise(h,118,2); 
	abal_else(h,1);
		generate_printer_create(h,2);
	abal_endif(h,1);

	if ( Abal_Config.generate_program )
		if (!( Abal_Config.generate_overlay ))
			abal_visual_startup(h,0);

	abal_page_control( h );
	fprintf(h,"\tPageHandle  =0 "); linefeed(h);

	Context.Form->printout.ZoneWidth  = Window.w;
	Context.Form->printout.ZoneHeight = Window.h;

	/* ------------------------------------- */
	/* Generate Default Logical Printer Name */
	/* ------------------------------------- */
	indent(h,1); fprintf(h,"%s%s=",
			__abal_keyword_printer,__abal_keyword_name);
	if (!( Context.Form->printout.DeviceName ))
		string_value(h, "LO" );
	else	string_value(h, Context.Form->printout.DeviceName );
	linefeed(h);		

	/* ------------------------------------- */
	/* Generate Default Printer Driver  Name */
	/* ------------------------------------- */
	indent(h,1); fprintf(h,"%s%s=",
			__abal_keyword_printer,__abal_keyword_driver);
	if (!( Context.Form->printout.DriverName ))
		string_value(h, "printer" );
	else	string_value(h, Context.Form->printout.DriverName );
	linefeed(h);		

	/* ------------------------------------- */
	/* Generate Logical Paper Width / Height */
	/* ------------------------------------- */
	indent(h,1); fprintf(h,"%s%s=0",
			__abal_keyword_page,"Number");
			linefeed(h);		

	indent(h,1); fprintf(h,"WindowX=((Conf(69)-%u)/2)",
			_REPORT_WINDOW_W);
			linefeed(h);		
	indent(h,1); fprintf(h,"WindowY=((Conf(68)-%u)/2)",
			_REPORT_WINDOW_H);
			linefeed(h);		

	indent(h,1); fprintf(h,"%s%s=%u",
			__abal_keyword_paper,__abal_keyword_width,
			( Context.Form->printout.Layout == 1 ?
				Context.Form->printout.ZoneWidth  :
				Context.Form->printout.ZoneHeight ) );	
			linefeed(h);		

	indent(h,1); fprintf(h,"%s%s=%u",
			__abal_keyword_paper,__abal_keyword_height,
			( Context.Form->printout.Layout == 1 ?
				Context.Form->printout.ZoneHeight :
				Context.Form->printout.ZoneWidth  ) );	

	linefeed(h);		
	indent(h,1); fprintf(h,"%s%s=/0%x",
			__abal_keyword_paper,__abal_keyword_options,
				(Context.Form->printout.Alignment | ((Context.Form->printout.PaperType-1) << 8)) );

	if ( fptr->abal.flags & 256 ) {
		fprintf(h," + (Conf(70)*16)");
		}

	linefeed(h);		
	/* ------------------------------ */
	/* Generate Logical Paper Margins */
	/* ------------------------------ */
	indent(h,1); fprintf(h,"%s%s=%u",
			__abal_keyword_left,__abal_keyword_margin,
				Context.Form->printout.LeftMargin);	
	linefeed(h);		
	indent(h,1); fprintf(h,"%s%s=%u",
			__abal_keyword_right,__abal_keyword_margin,
				Context.Form->printout.RightMargin);	
	linefeed(h);		
	indent(h,1); fprintf(h,"%s%s=%u",
			__abal_keyword_top,__abal_keyword_margin,
				Context.Form->printout.TopMargin);	
	linefeed(h);		
	indent(h,1); fprintf(h,"%s%s=%u",
			__abal_keyword_bottom,__abal_keyword_margin,
				Context.Form->printout.BottomMargin);
	linefeed(h);		

	dpi = page_resolution();

	/* ----------------------------------- */
	/* Generate Print Density / Resolution */
	/* ----------------------------------- */
	indent(h,1);	fprintf(h,"%s%s\t=%u",__abal_keyword_printer,__abal_keyword_dpi,dpi);
	linefeed(h);		

	if ( Abal_Config.members )
		abal_transfer_parameters(h,1);

	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		if ( fptr->formflags & _MULTILINGUAL ) {
			abal_national_messages(h,iptr);
			}

		if ( iptr->Contents.events.xo_create & _EVENT_IS_FOCUS ) {
			/* Generate Position and Dimensions Variables */
			fprintf(h,"\tx_%s=%u",iptr->Contents.name,iptr->Contents.x+WindowCol);
			linefeed(h);
			fprintf(h,"\ty_%s=%u",iptr->Contents.name,iptr->Contents.y+WindowRow);
			linefeed(h);
			fprintf(h,"\tw_%s=%u",iptr->Contents.name,iptr->Contents.w);
			linefeed(h);
			fprintf(h,"\th_%s=%u",iptr->Contents.name,iptr->Contents.h);
			linefeed(h);
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

			case	_TAB_FRAME 	:
				indent(h,1);
				fprintf(h,"FocusPages(%u) = %u",iptr->Contents.page,iptr->Contents.focus);
				linefeed(h);
				if ( iptr->Contents.datatype == _WIDGET_OVERLAY )
					attach_widget_overlay(h,iptr);
				break;

			case	_SCROLL_FRAME	:
				indent(h,1);
				fprintf(h,"m_%s = 1",iptr->Contents.name);
				linefeed(h);

			case	_PROGRESS_FRAME	:
				indent(h,1);
				fprintf(h,"v_%s = 1",iptr->Contents.name);
				linefeed(h);
				indent(h,1);
				fprintf(h,"l_%s = 1",iptr->Contents.name);
				linefeed(h);
				break;

			case	_FORM_FRAME	:
				alias_redefined_widget(h, iptr, "1", 1 );
				indent(h,1);
				fprintf(h,"b_%s=%c %c",iptr->Contents.name,0x0022,0x0022);
				linefeed(h);
				break;

			case	_EDIT_FRAME	:
				indent(h,1);
				fprintf(h,"b_%s=",iptr->Contents.name);
				if ((!( tptr = abal_payload(iptr) ))
				||  (!(*tptr 			     )))
					fprintf(h,"%c %c",0x0022,0x0022);
				else	string_value(h,tptr);
				linefeed(h);
				break;

			case	_RADIO_FRAME	:
				if ( iptr->Contents.radio == 1 ) {
					indent(h,1);
					fprintf(h,"v_%s = 1",iptr->Contents.name);
					linefeed(h);
					}
				break;

			}
		abal_invoke_widget_create(h,iptr,0,1);
		}

	indent(h,1); fprintf(h,"%s((%s%s=0)'",
			__abal_keyword_if,__abal_keyword_paper,__abal_keyword_width);
	linefeed(h);
	indent(h,1); fprintf(h,"%s(%s%s=0))",
			__abal_keyword_or,__abal_keyword_paper,__abal_keyword_height);
	linefeed(h);
		abal_raise(h,55,2); 
	abal_endif(h,1);

	margin = 1;
	if ( Context.Form->printout.Preview ) {
		indent(h,margin++);
		fprintf(h,"%s(%s$(%s%s) <> 0)",
			__abal_keyword_if,
			__abal_keyword_len,
			__abal_keyword_printer,__abal_keyword_name);
			linefeed(h);
		}

#ifdef	OVERLAY_DOES_THIS
	indent(h,margin++);
	fprintf(h,"%s(%s$(%s%s) <> 0)",
		__abal_keyword_if,
		__abal_keyword_len,
		__abal_keyword_printer,__abal_keyword_driver);
		linefeed(h);
		indent(h,margin);

		fprintf(h,"LoadUser(1) = %s%s",
			__abal_keyword_printer,__abal_keyword_driver);


	linefeed(h);
	abal_endif(h,--margin);
#endif

	generate_printer_open(h,margin);

	if ( Context.Form->printout.Preview ) {
		abal_else(h,(margin-1));
		indent(h,margin);
		fprintf(h,"%s=0",__abal_keyword_status);
		linefeed(h);
		abal_endif(h,--margin);
		}

	indent(h,1); fprintf(h,"%s(%s <> 0)",
			__abal_keyword_if,__abal_keyword_status);
	linefeed(h);
		abal_return(h,__abal_keyword_status,2); 
	abal_else(h,1);

		/* -------------------------------------------------- */
		/* Visual Buffer and Visual Get for Progression Saver */
		/* -------------------------------------------------- */
		if (((sptr = Context.Form->printout.PageHead ) != (char *) 0)
		&&  ( *sptr != 0 )) {
			indent(h,2);
			fprintf(h,"%s%s=%s(%u+10,%u+10)",
				__abal_keyword_paper,__abal_keyword_handle,
				__abal_visual_buffer,
				_REPORT_WINDOW_W,_REPORT_WINDOW_H);
			linefeed(h);
			indent(h,2);
			fprintf(h,"%s(%s%s > 0)",
				__abal_keyword_if,
				__abal_keyword_paper,__abal_keyword_handle);
			linefeed(h);
			indent(h,3);
			fprintf(h,"%s=%s(%s%s,WindowX,WindowY)",
				__abal_keyword_status,
				__abal_visual_get,
				__abal_keyword_paper,__abal_keyword_handle);
			linefeed(h);
			abal_endif(h,2);
			}

		indent(h,2); 
		if ( Context.Form->printout.Layout == 1 ) {
			fprintf(h,"%s%s=%s(%s%s,%s%s)",
					__abal_keyword_page,__abal_keyword_handle,
					__abal_visual_buffer,
					__abal_keyword_paper,__abal_keyword_width,
					__abal_keyword_paper,__abal_keyword_height);
			}
		else	{
			fprintf(h,"%s%s=%s(%s%s,%s%s)",
					__abal_keyword_page,__abal_keyword_handle,
					__abal_visual_buffer,
					__abal_keyword_paper,__abal_keyword_height,
					__abal_keyword_paper,__abal_keyword_width);
			}

		linefeed(h);
		indent(h,2); 
		fprintf(h,"%s(%s%s= -1)",__abal_keyword_if,__abal_keyword_page,__abal_keyword_handle);
		linefeed(h);
			abal_raise(h,27,3); 
			abal_else(h,2);
				margin=3;
				if ( Context.Form->printout.Preview ) {
					indent(h,margin++);
					fprintf(h,"%s(%s$(%s%s) <> 0)",
						__abal_keyword_if,
						__abal_keyword_len,
						__abal_keyword_printer,__abal_keyword_name);
					linefeed(h);
					}
				indent(h,margin);
				fprintf(h,"%s(%s(%s%s) = -1)",__abal_keyword_if,__abal_visual_page,__abal_keyword_page,__abal_keyword_handle);
				linefeed(h);
					abal_raise(h,56,margin+1); 
				abal_endif(h,margin);
				if ( Context.Form->printout.Preview ) {
					abal_else(h,(margin-1));
					indent(h,margin);	
					fprintf(h,"%s=%s(%s%s,0,0)",
						__abal_keyword_status,
						__abal_visual_get,
						__abal_keyword_page,__abal_keyword_handle
						);
					linefeed(h);
					abal_endif(h,--margin);
					}
		abal_endif(h,2);
	abal_endif(h,1);
	abal_return(h,__abal_string_zero,1); 
	abal_error_abort(h,1,1);
	abal_error_return(h,__abal_keyword_status,1); 
	abal_endproc(h);
	return;
}

public	void	abal_page_onshow( FILE * h )
{
	abal_form_onshow(h);
	return;
}

public	void	abal_page_ongetfocus( FILE * h )
{
	char		 * object_pointer="\0";
	char		 * eptr;
	struct form_item * iptr;

	if (( Abal_Config.generate_program ) 
	&&  ( Abal_Config.generate_overlay ))
		object_pointer = "o";

	abal_onevent_methods( h );
	abal_onget_methods( h, __abal_method_get_focus );
	abal_onlose_methods( h, __abal_method_lose_focus );

	abal_procedure(h,Abal_Config.cname,__abal_method_hide,0,(struct form_control *) 0 );
	abal_error_trap(h,1,1);
	abal_returni(h,0,1);
	abal_error_abort(h,1,1);
	abal_error_return(h,__abal_string_zero,1);
	abal_endproc(h);

	abal_procedure(h,Abal_Config.cname,__abal_method_event,0,(struct form_control *) 0);
	abal_error_trap(h,1,1);
	abal_returni(h,0,1);
	abal_error_abort(h,1,1);
	abal_error_return(h,__abal_string_zero,1);
	abal_endproc(h);

	abal_procedure(h,Abal_Config.cname,__abal_method_focus,0,(struct form_control *) 0);

	abal_dcl(h,__abal_keyword_page,__abal_keyword_control,_ABAL_WORD,0,0,0);
	abal_endloc(h,1);
	abal_error_trap(h,1,1);

	abal_repeat(h,1);

	indent(h,2);
	fprintf(h,"%s%s=0",__abal_keyword_page,__abal_keyword_control);
	linefeed(h);
	indent(h,2);
	fprintf(h,"%s=0",__abal_keyword_keycode);
	linefeed(h);

	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if (!( eptr =  iptr->Contents.events.on_get_focus))
			continue;
		else if (!( *eptr ))
			continue;

		abal_invoke_widget_get_focus(h,iptr,3,2);

		/* Detect ESCAPE/ENTER trapping required */
		/* ------------------------------------- */
		if ( Context.Form->formflags & (_FORM_ESC | _FORM_RC) ) {

			indent(h,2);
			fprintf(h,"%s (%s)",__abal_keyword_select,__abal_keyword_keycode);
			linefeed(h);

			/* Handle ESCAPE returns */
			/* --------------------- */
			if ( Context.Form->formflags & _FORM_ESC ) {
				indent(h,2);
				fprintf(h,"%s %u :: %s(%u)",__abal_keyword_case,27,__abal_keyword_exit,27);
				linefeed(h);
				}

			/* Handle VALIDATE returns */
			/* ----------------------- */
			if ( Context.Form->formflags & _FORM_RC ) {
				indent(h,2);
				fprintf(h,"%s %u :: %s%s = %s%s +1 ",
					__abal_keyword_case,13,
					__abal_keyword_page,__abal_keyword_control,
					__abal_keyword_page,__abal_keyword_control);
				linefeed(h);
				}
			abal_endsel(h,2);
			}
		abal_invoke_widget_lose_focus(h,iptr,3,2);
		indent(h,2);
		fprintf(h,"%s=0",__abal_keyword_keycode);
		linefeed(h);

		}

	indent(h,2);
	fprintf(h,"%s (%s%s <> 0)",__abal_keyword_if,__abal_keyword_page,__abal_keyword_control);
	linefeed(h);
		indent(h,3);
		fprintf(h,"%s=%s%s(%s)",__abal_keyword_status,Abal_Config.cname,__abal_method_flush,object_pointer);
		linefeed(h);
		indent(h,3);
		fprintf(h,"%s (%s = 27)",__abal_keyword_if,__abal_keyword_status);
		linefeed(h);
		abal_return(h,__abal_keyword_status,4);
		abal_endif(h,3);
	abal_endif(h,2);

	indent(h,1);
	fprintf(h,"%s ( %s%s=0 )",__abal_keyword_until,__abal_keyword_page,__abal_keyword_control);
	linefeed(h);
	abal_return(h,__abal_string_zero,1);
	abal_error_abort(h,1,1);
	abal_error_return(h,__abal_keyword_status,1);
	abal_endproc(h);
	return;
}

private	void	abal_visual_page(FILE * h, int i )
{
	/* ------------------------------------ */
	/* VisualPage( PageHandle )		*/
	/* ------------------------------------ */
	indent(h,i); 
	fprintf(h,"%s = %s(%s%s)",
		__abal_keyword_status,__abal_visual_page,
		__abal_keyword_page,__abal_keyword_handle);
	linefeed(h);
	return;
}

private	void	reset_visual_page(FILE * h, int i )
{
	/* ------------------------------------ */
	/* VisualPage( PageHandle )		*/
	/* ------------------------------------ */
	indent(h,i); 
	fprintf(h,"%s = %s(0)",__abal_keyword_status,__abal_visual_page);
	linefeed(h);
	return;
}


private		void	abal_page_progression_frame( FILE * h, int margin, char * sptr )
{
	reset_visual_page(h,margin);

	indent(h,margin);
	fprintf(h,"PageNumber += 1");
	linefeed(h);
	indent(h,margin);
	fprintf(h,"%s%s=Print(($,N4Z),%c%s%c,PageNumber)",
		__abal_keyword_row,__abal_keyword_buffer,
		0x0022,sptr,0x0022);
	linefeed(h);

	/* WINDOW */
	/* ------ */
	indent(h,margin);
	fprintf(h,"%s(WindowX,WindowY,%u,%u,FontHandle(2),%c%s%c,%u,/0400)",
		__abal_visual_window,
		_REPORT_WINDOW_W,_REPORT_WINDOW_H,
		0x0022,SingConf->printer,0x0022,strlen(SingConf->printer));
	linefeed(h);

	/* FRAME */
	/* ----- */
	indent(h,margin);
	fprintf(h,"%s(WindowX+5,WindowY+24,%u,%u,4)",
		__abal_visual_zone,
		_REPORT_WINDOW_W-10,_REPORT_WINDOW_H-32);
	linefeed(h);

	/* TEXT */
	/* ---- */
	indent(h,margin);
	fprintf(h,"%s(WindowX+20,WindowY+30,%u,24,FontHandle(2),16,0,%s%s,Len$(%s%s),3)",
		__abal_visual_text,
		_REPORT_WINDOW_W-40,
		__abal_keyword_printer,__abal_keyword_name,
		__abal_keyword_printer,__abal_keyword_name );
	linefeed(h);

	indent(h,margin);
	fprintf(h,"%s(WindowX+20,WindowY+50,%u,24,FontHandle(2),16,0,%s%s,Len$(%s%s),3)",
		__abal_visual_text,
		_REPORT_WINDOW_W-40,
		__abal_keyword_row,__abal_keyword_buffer,
		__abal_keyword_row,__abal_keyword_buffer );
	linefeed(h);

	/* OP NEXT,STATUS */
	/* -------------- */
	indent(h,margin);
	fprintf(h,"Do :: ");
	fprintf(h,"Op Next,Status");
	linefeed(h);
	indent(h,margin+1);
	fprintf(h,"if ( Status = 27 ) :: Exit( Status ) :: Endif");
	linefeed(h);
	indent(h,margin+1);
	fprintf(h,"if ( Status = 0  ) :: Break :: Endif");
	linefeed(h);
	indent(h,margin);
	fprintf(h,"Loop");
	linefeed(h);
	return;
}

private		void	abal_page_progression_bar( FILE * h, int margin, char * sptr )
{
	reset_visual_page(h,margin);
	indent(h,margin);
	fprintf(h,"%s(WindowX+20,WindowY+76,%u,24,FontHandle(2),%u,%u,%s%s,%s%s,0)",
		__abal_visual_progress,
		_REPORT_WINDOW_W-40,
		_REPORT_BAR_FG,_REPORT_BAR_BG,
		__abal_keyword_paper,__abal_keyword_height,
		__abal_keyword_page,__abal_keyword_row);
	linefeed(h);
	abal_visual_page(h,margin);
	return;
}

public	void	abal_page_onflush( FILE * h )
{
	char *	buffer;
	char *	sptr;
	int	isoverlay=0;
	abal_onhide_methods( h, __abal_method_flush );
	abal_procedure(h,Abal_Config.cname,__abal_method_flush,0,(struct form_control *) 0);
	abal_error_trap(h,1,1);

	if ( Context.Form->printout.Preview ) {
		indent(h,1);
		fprintf(h,"%s(%s$(%s%s) = 0)",
			__abal_keyword_if,
			__abal_keyword_len,
			__abal_keyword_printer,__abal_keyword_name);
		linefeed(h);
		indent(h,2);
		fprintf(h,"%s",__abal_visual_keycode);
		linefeed(h);
		abal_return(h,__abal_keyword_keycode,2);
		abal_endif(h,1);
		}		

	if ( Context.Form->printout.FeedOpt == 2 ) {
		generate_printer_page(h,1);
		}

	/* Check for print progression display title */
	/* ----------------------------------------- */
	if (((sptr = Context.Form->printout.PageHead ) != (char *) 0)
	&&  ( *sptr != 0 )) {
		abal_page_progression_frame(h,1,sptr);
		}


	if ( Context.Form->printout.Layout != 1 ) {
		indent(h,1); 
		/* ------------------------------------------ */
		/* VisualTransform( PageHandle, 0 , 90, 0 );  */
		/* ------------------------------------------ */
		fprintf(h,"%s = %s(%s%s,0,90,0)",
			__abal_keyword_status,__abal_visual_transform,
			__abal_keyword_page,__abal_keyword_handle);
		linefeed(h);
		abal_visual_page(h,1);
		}

	indent(h,1); fprintf(h,"%s %s%s=1 %s %s%s",
			__abal_keyword_for,
			__abal_keyword_page,__abal_keyword_row,
			__abal_keyword_to,
			__abal_keyword_paper,__abal_keyword_height );
	linefeed(h);
	indent(h,2); fprintf(h,"%s(%s(%s%s,%s%s,%s%s) <> %s%s)",
			__abal_keyword_if,__abal_visual_getrow,
			__abal_keyword_page,__abal_keyword_row,
			__abal_keyword_row,__abal_keyword_buffer,
			__abal_keyword_paper,__abal_keyword_width,
			__abal_keyword_page,__abal_keyword_row );
	linefeed(h);
	indent(h,3); fprintf(h,__abal_keyword_break); linefeed(h);
	abal_else(h,2);
	generate_printer_row(h,3);
	indent(h,3); fprintf(h,"%s (%s<> 0)::%s(%s):: %s",
			__abal_keyword_if,__abal_keyword_status,
				__abal_keyword_exit,__abal_keyword_status,
			__abal_keyword_endif);
	linefeed(h);
	abal_endif(h,2);


	if (((sptr = Context.Form->printout.PageHead ) != (char *) 0)
	&&  ( *sptr != 0 )) {
		abal_page_progression_bar(h,2,sptr);
		}
	else	{
		generate_abal_flush(h,2);
		}
	indent(h,1); fprintf(h,"%s %s%s",
			__abal_keyword_next,
			__abal_keyword_page,__abal_keyword_row);
	linefeed(h);

	if ( Context.Form->printout.Layout != 1 ) {
		indent(h,1); 
		/* ------------------------------------------ */
		/* VisualTransform( PageHandle, 0 , 270, 0 ); */
		/* ------------------------------------------ */
		fprintf(h,"%s = %s(%s%s,0,270,0)",
			__abal_keyword_status,__abal_visual_transform,
			__abal_keyword_page,__abal_keyword_handle);
		linefeed(h);
		abal_visual_page(h,1);
		}


	if ( Context.Form->printout.FeedOpt == 3 ) {
		generate_printer_page(h,1);
		}

	/* Page Control using Close/Open to avoid spooling monsters */
	/* -------------------------------------------------------- */
	else if ( Context.Form->printout.FeedOpt == 4 ) {
		generate_printer_flush(h,1);
		generate_printer_remove(h,1);
		generate_printer_create(h,1);
		generate_printer_open(h,1);
		}

	abal_return(h,__abal_string_zero,1);
	abal_error_abort(h,1,1);
	abal_error_return(h,__abal_keyword_status,1);
	abal_endproc(h);
	return;
}

public	void	abal_page_ondoit( FILE * h, struct form_control * fptr )
{
	char * optr;
	int	i;
	if ( Abal_Config.generate_program ) {
		if ( Abal_Config.generate_overlay ) {
			open_overlay_onexec(h,fptr);
			optr = "o"; i = 1;
			}
		else	{
			optr = "\0"; i= 2;
			abal_segment(h,__abal_string_zero);
			abal_error_trap(h,1,1);
			indent(h,1);
			fprintf(h,"%s=%s%s()",__abal_keyword_status,Abal_Config.cname,__abal_method_create);
			linefeed(h);
			indent(h,1);
			fprintf(h,"%s(%s=0)",__abal_keyword_if,__abal_keyword_status);
			linefeed(h);
			}
		indent(h,i);
		fprintf(h,"%s=%s%s(%s)",__abal_keyword_status,Abal_Config.cname,__abal_method_show,optr);
		linefeed(h);
		indent(h,i);
		fprintf(h,"%s(%s=0)",__abal_keyword_if,__abal_keyword_status);
		linefeed(h);
		indent(h,i+1);
		fprintf(h,"%s=%s%s(%s)",__abal_keyword_status,Abal_Config.cname,__abal_method_focus,optr);
		linefeed(h);
		indent(h,i+1);
		fprintf(h,"%s(%s=0)",__abal_keyword_if,__abal_keyword_status);
		linefeed(h);
		indent(h,i+2);
		fprintf(h,"%s=%s%s(%s)",__abal_keyword_status,Abal_Config.cname,__abal_method_flush,optr);
		linefeed(h);
		abal_endif(h,i+1);
		abal_endif(h,i);
		
		if (( Abal_Config.generate_program )
		&&  ( Abal_Config.generate_overlay )) 
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
		abal_call(h,Abal_Config.cname,__abal_method_create, Abal_Config.members,1,fptr );
		abal_call(h,Abal_Config.cname,__abal_method_show, 0,1,fptr );
		abal_call(h,Abal_Config.cname,__abal_method_focus,0,1,fptr);
		abal_call(h,Abal_Config.cname,__abal_method_flush, 0,1,fptr );
		abal_call(h,Abal_Config.cname,__abal_method_remove, Abal_Config.members,1,fptr );
		abal_return(h,__abal_keyword_keycode,1);
		abal_endproc(h);
		}
	return;
}

public  void	export_abal_page( FILE * h )
{
	struct form_item * iptr;
	struct form_item * wptr;
	int	i;
	int	isoverlay=0;

	/* ---------------------------------------------------- */
	/* Determine Object Prefix and Configuration Parameters */
	/* ---------------------------------------------------- */
	Abal_Config.generate_program = Context.Form->isprogram;
	Abal_Config.generate_overlay = Context.Form->isoverlay;

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
		Abal_Config.cname = "printer_page";

	else if (!( *Abal_Config.cname ))
		Abal_Config.cname = "printer_page";

	/* Generate File Banner Block */
	production_banner(h,_GENERATE_BAL,Context.Form->loadname,Context.Form->prodname);

	/* ------------------------------- */
	/* Generate Inclusions for Program */
	/* ------------------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_page_onstart( h, Context.Form->objects );

	/*	------		*/
	/* 	EXTERN		*/
	/*	------		*/
	abal_extern_methods(h, Context.Form );

	/*	-------		*/
	/* 	FORWARD		*/
	/*	-------		*/
	abal_forward_methods(h, Context.Form );

	/* 	-------		*/
	/* 	METHODS		*/
	/* 	-------		*/
	abal_forms_members(h,Context.Form);
	abal_forms_methods(h,Context.Form);

	/* -------------------- */
	/*	ON _ CREATE	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_page_oncreate( h, Context.Form );

	/* -------------------- */
	/*	ON _ REMOVE	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_page_onremove( h, Context.Form );

	/* -------------------- */
	/*	ON _ FLUSH 	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_page_onflush( h );

	/* -------------------- */
	/*	ON _  SHOW 	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_page_onshow( h );

	/* -------------------- */
	/*	ON _ FOCUS 	*/
	/* -------------------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_page_ongetfocus( h );

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
	abal_page_ondoit(h,Context.Form);

	/* ----------- */
	/* ON _ FINISH */
	/* ----------- */
	status_progress(2,Abal_Config.actions,Abal_Config.action++);
	abal_form_onfinish(h);
	return;
}

#endif	/* _abalpage_c */
	/* ----------- */

