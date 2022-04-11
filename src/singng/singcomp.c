#ifndef	_singcomp_c	
#define	_singcomp_c	

struct	form_compare_parameters	{
	char	*	formname;
	int		fixpayloads;
	int		fixmethods;
	int		fixevents;
	int		fixformat;
	int		fixdetail;
	int		fixreport;
	char *		fixlog;
	FILE *		loghandle;
	}  FormCompare = { (char *) 0, 0, 0, 0, 0, 0, 0, (char *) 0, (FILE *) 0 };

private	int	form_compare_failure(
		struct form_control * fptr, 
		struct form_item * wptr,
		char *	reason,
		char *	message1,
		char *	message2)
{
	char	mbuffer[256];
	if ( FormCompare.fixreport ) {
		if ( FormCompare.fixlog ) {
			if (!( FormCompare.loghandle )) {
				if ((FormCompare.loghandle = fopen(FormCompare.fixlog,"w")) != (FILE *) 0)
					fprintf(FormCompare.loghandle,"Form Compare Report : \n\n");
				}
			if ( FormCompare.loghandle ) {
				if ( fptr )
					fprintf(FormCompare.loghandle,"%s",fptr->prodname);
				else	fprintf(FormCompare.loghandle,"%s","[form]");
				if ( wptr )
					fprintf(FormCompare.loghandle,".%s",wptr->Contents.name);
				else	fprintf(FormCompare.loghandle,".%s","[widget]");
				fprintf(FormCompare.loghandle," : %s \n",reason);
				if ( FormCompare.fixdetail ) {
					if (( message1 ) && ( *message1 ))
						fprintf(FormCompare.loghandle,"\t1) =[%s]=\n",message1);
					if (( message2 ) && ( *message2 ))
						fprintf(FormCompare.loghandle,"\t2) =[%s]=\n",message2);
					}
				return(0);
				}
			}
		}
	if ( fptr )
		status_message(fptr->prodname,1);
	else	status_message("[form]",1);
	if ( wptr )
		status_message(wptr->Contents.name,2);
	else	status_message("[widget]",2);
	sprintf(mbuffer,"%s [%s] [%s]",reason,message1,message2);
	status_message(mbuffer,3);
	return(1);
}

private	int	widget_count(struct form_control * fptr)
{
	struct	form_item 	* 	iptr;
	int				number=0;
	if (!( fptr ))
		return(0);
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
		number++;
	return(number);
}

private	int	compare_widget_method( char ** lptr, char **rptr )
{
	if (!( method_is_valid( *lptr ) )) {
		if ( method_is_valid( *rptr ) ) {
			if (!( FormCompare.fixevents ))
				return( 0 );
			else	*rptr = liberate( *rptr );
			}
		}
	else if (!( method_is_valid( *rptr ) )) {
		if (!( FormCompare.fixevents ))
			return( 0 );
		else	*rptr = allocate_string( *lptr );
		}
	else if ( strcmp( *lptr, *rptr ) ) {
		if (!( FormCompare.fixevents ))
			return(0);
		else	{
			*rptr = liberate( *rptr );
			*rptr = allocate_string( *lptr );
			}
		}
	return(1);
}

private	int	form_string_compare( char * aptr, char * bptr )
{
	if (!( aptr )) {
		if (!( bptr ))
			return(0);
		else	return(1);
		}
	else if (!( bptr ))
		return(2);
	else if (!( strcmp(aptr,bptr)))
		return(0);
	else	return(3);
}

private	int	compare_form_members( struct form_control * lptr, struct form_control * rptr )
{
	struct	forms_data_member * lmember;
	struct	forms_data_member * rmember;

	lmember = lptr->rootmember;
	rmember = rptr->rootmember;

	while (1) {

		/* neither member exists */
		/* --------------------- */
		if ((!( lmember )) && (!( rmember )))
			return(0);

		/* check that both members exist */
		/* ----------------------------- */
		if ((!( lmember)) && ( rmember ))
			{ if ( form_compare_failure( rptr, (struct form_item *) 0, "new member", "\0" , rmember->name ) ) return(1); else return(0); }
			
		else if ((!( rmember)) && ( lmember ))
			{ if ( form_compare_failure( lptr, (struct form_item *) 0, "missing member", lmember->name, "\0" ) ) return(1); else return(0); }

		/* check identical names */
		/* --------------------- */
		if ( form_string_compare( lmember->name, rmember->name ) ) 
			{ if ( form_compare_failure( lptr, (struct form_item *) 0, "different member names", lmember->name, rmember->name ) ) return(1); else return(0); }

		/* check identical types */
		/* --------------------- */
		if ( lmember->type != rmember->type )
			{ if ( form_compare_failure( lptr, (struct form_item *) 0, "different member types",lmember->name, rmember->name  ) ) return(1); }

		/* check identical sizes */
		/* --------------------- */
		if ( lmember->size != rmember->size )
			{ if ( form_compare_failure( lptr, (struct form_item *) 0, "different member sizes",lmember->name, rmember->name  ) ) return(1); }

		/* check identical firsts */
		/* --------------------- */
		if ( lmember->first != rmember->first )
			{ if ( form_compare_failure( lptr, (struct form_item *) 0, "different member 1st dim",lmember->name, rmember->name  ) ) return(1); }

		/* check identical types */
		/* --------------------- */
		if ( lmember->second != rmember->second )
			{ if ( form_compare_failure( lptr, (struct form_item *) 0, "different member 2nd dim",lmember->name, rmember->name  ) ) return(1); }

		/* check identical names */
		/* --------------------- */
		if ( form_string_compare( lmember->comment, rmember->comment ) ) 
			{ if ( form_compare_failure( lptr, (struct form_item *) 0, "different member comment", lmember->name, rmember->name ) ) return(1); }

		/* check identical constructions */
		/* --------------------- */
		if ( form_string_compare( lmember->construction, rmember->construction ) ) 
			{ if ( form_compare_failure( lptr, (struct form_item *) 0, "different member construction", lmember->name, rmember->name ) ) return(1); }

		/* check identical klasss */
		/* --------------------- */
		if ( form_string_compare( lmember->klass, rmember->klass ) ) 
			{ if ( form_compare_failure( lptr, (struct form_item *) 0, "different member class", lmember->name, rmember->name ) ) return(1); else return(0); }

		/* next members */
		/* ------------ */
		lmember = lmember->next;
		rmember = rmember->next;

		}
}


private	int	compare_form_methods( struct form_control * lptr, struct form_control * rptr )
{
	struct	forms_method * lmethod;
	struct	forms_method * rmethod;

	lmethod = lptr->rootmethod;
	rmethod = rptr->rootmethod;

	while (1) {

		/* neither method exists */
		/* --------------------- */
		if ((!( lmethod )) && (!( rmethod )))
			return(0);

		/* check that both methods exist */
		/* ----------------------------- */
		if ((!( lmethod)) && ( rmethod ))
			{ if ( form_compare_failure( rptr, (struct form_item *) 0, "new method", "\0" , rmethod->name ) ) return(1); else return(0); }
			
		else if ((!( rmethod)) && ( lmethod ))
			{ if ( form_compare_failure( lptr, (struct form_item *) 0, "missing method", lmethod->name, "\0" ) ) return(1); else return(0); }

		/* check identical names */
		/* --------------------- */
		if ( form_string_compare( lmethod->name, rmethod->name ) ) 
			{ if ( form_compare_failure( lptr, (struct form_item *) 0, "different method names", lmethod->name, rmethod->name ) ) return(1); else return(0); }

		/* check identical types */
		/* --------------------- */
		if ( lmethod->type != rmethod->type )
			{ if ( form_compare_failure( lptr, (struct form_item *) 0, "different method types",lmethod->name, rmethod->name  ) ) return(1); }

		/* check identical class */
		/* --------------------- */
		if ( form_string_compare( lmethod->klass, rmethod->klass ) ) 
			{ if ( form_compare_failure( lptr, (struct form_item *) 0, "different method class",lmethod->name, rmethod->name  ) ) return(1); }

		/* check identical param */
		/* --------------------- */
		if ( form_string_compare( lmethod->signature, rmethod->signature ) ) 
			{ if ( form_compare_failure( lptr, (struct form_item *) 0, "different method signatures",lmethod->name, rmethod->name  ) ) return(1); }

		/* check identical texts */
		/* --------------------- */
		if ( form_string_compare( lmethod->signature, rmethod->signature ) ) 
			{ if ( form_compare_failure( lptr, (struct form_item *) 0, "different method texts",lmethod->name, rmethod->name  ) ) return(1); }

		/* next methods */
		/* ------------ */
		lmethod = lmethod->next;
		rmethod = rmethod->next;

		}
}

private	int	compare_form_document_parameters( struct form_control * lptr, struct form_control * rptr )
{
	if ( form_string_compare(lptr->printout.TopMargin, rptr->printout.TopMargin) )
		{ if ( form_compare_failure( rptr, (struct form_item *) 0, "top margin", "\0", "\0" ) ) return(1); }
	if ( form_string_compare(lptr->printout.LeftMargin, rptr->printout.LeftMargin)	 )
		{ if ( form_compare_failure( rptr, (struct form_item *) 0, "left margin", "\0", "\0" ) ) return(1); }
	if ( form_string_compare(lptr->printout.PageHead, rptr->printout.PageHead)	 )
		{ if ( form_compare_failure( rptr, (struct form_item *) 0, "page header", "\0", "\0" ) ) return(1); }
	if ( form_string_compare(lptr->printout.PageFoot, rptr->printout.PageFoot)	 )
		{ if ( form_compare_failure( rptr, (struct form_item *) 0, "page footer", "\0", "\0" ) ) return(1); }
	if ( form_string_compare(lptr->printout.DeviceName, rptr->printout.DeviceName)	 )
		{ if ( form_compare_failure( rptr, (struct form_item *) 0, "device name", "\0", "\0" ) ) return(1); }
	if ( form_string_compare(lptr->printout.DriverName, rptr->printout.DriverName)	 )
		{ if ( form_compare_failure( rptr, (struct form_item *) 0, "driver name", "\0", "\0" ) ) return(1); }
	if ( lptr->printout.BottomMargin	!= rptr->printout.BottomMargin	 )
		{ if ( form_compare_failure( rptr, (struct form_item *) 0, "bottom margin", "\0", "\0" ) ) return(1); }
	if ( lptr->printout.RightMargin		!= rptr->printout.RightMargin	 )
		{ if ( form_compare_failure( rptr, (struct form_item *) 0, "right margin", "\0", "\0" ) ) return(1); }
	if ( lptr->printout.ZoneWidth		!= rptr->printout.ZoneWidth	 )
		{ if ( form_compare_failure( rptr, (struct form_item *) 0, "zone width", "\0", "\0" ) ) return(1); }
	if ( lptr->printout.ZoneHeight		!= rptr->printout.ZoneHeight	 )
		{ if ( form_compare_failure( rptr, (struct form_item *) 0, "zone height", "\0", "\0" ) ) return(1); }
	if ( lptr->printout.Layout		!= rptr->printout.Layout	 )
		{ if ( form_compare_failure( rptr, (struct form_item *) 0, "layout", "\0", "\0" ) ) return(1); }
	if ( lptr->printout.Preview		!= rptr->printout.Preview	 )
		{ if ( form_compare_failure( rptr, (struct form_item *) 0, "preview", "\0", "\0" ) ) return(1); }
	if ( lptr->printout.Alignment		!= rptr->printout.Alignment 	 )
		{ if ( form_compare_failure( rptr, (struct form_item *) 0, "alignment", "\0", "\0" ) ) return(1); }
	if ( lptr->printout.PaperType		!= rptr->printout.PaperType	 )
		{ if ( form_compare_failure( rptr, (struct form_item *) 0, "paper type", "\0", "\0" ) ) return(1); }
	if ( lptr->printout.PrintResolution	!= rptr->printout.PrintResolution)
		{ if ( form_compare_failure( rptr, (struct form_item *) 0, "resolution", "\0", "\0" ) ) return(1); }
	if ( lptr->printout.TitleOpt		!= rptr->printout.TitleOpt	 )
		{ if ( form_compare_failure( rptr, (struct form_item *) 0, "title option", "\0", "\0" ) ) return(1); }
	if ( lptr->printout.FeedOpt		!= rptr->printout.FeedOpt	 )
		{ if ( form_compare_failure( rptr, (struct form_item *) 0, "pagefeed option", "\0", "\0" ) ) return(1); }
	if ( lptr->printout.NumbOpt		!= rptr->printout.NumbOpt	 )
		{ if ( form_compare_failure( rptr, (struct form_item *) 0, "number option", "\0", "\0" ) ) return(1); }

	return(0);
}

/*	-----------------	*/
/*	Compare Two Forms	*/
/*	-----------------	*/

int	form_compare( struct form_control * lptr, struct form_control * rptr, int options )
{
	int	fixedmsgs=0;
	int	fixedhints=0;
	int	fixedmethods=0;
	int	fixedevents=0;
	int	fixedformat=0;
	int	i;
	struct	form_item 	* 	lwptr;
	struct	form_item 	* 	rwptr;

	if (!( lptr )) 
		return(0); 
	else if (!( rptr )) 
		return(0);

	if ( widget_count( lptr ) != widget_count( rptr ) )
		{ if ( form_compare_failure( rptr, (struct form_item *) 0, "widget count", "\0", "\0" ) ) return(1); }

	if ( compare_form_document_parameters(lptr, rptr ) != 0)
		return(0);

	if ( compare_form_members( lptr, rptr ) != 0 )
		return(0);

	if ( compare_form_methods( lptr, rptr ) != 0 )
		return(0);

	if ( form_string_compare(lptr->palette, rptr->palette) )
		{ if ( form_compare_failure( lptr, (struct form_item *) 0, "palette", "\0", "\0" ) ) return(1); }

	/* check widget help texts */
	/* ----------------------- */
	for (i=0; i < MAXNATLANG; i++ )
		if ( form_string_compare( lptr->document[i], rptr->document[i] ) )
			if ( form_compare_failure( rptr, (struct form_item *) 0, "help text", lptr->document[i], rptr->document[i] ) )
				return(1); 

	for (	lwptr=lptr->first, 
		rwptr=rptr->first;
		(lwptr != (struct form_item *) 0) &&
		(rwptr != (struct form_item *) 0) ;
		lwptr = lwptr->next,
		rwptr = rwptr->next  ) {

		/* Check explicite names */
		if ( is_named_widget( lwptr ) ) {
			if (!( is_named_widget( rwptr ) ))
				{ if ( form_compare_failure( rptr, rwptr, "named widget1", lwptr->Contents.name, "[auto]"  ) ) return(1); }
			if ( strcmp(lwptr->Contents.name, rwptr->Contents.name ) )
				{ if ( form_compare_failure( rptr, rwptr, "named widget2", lwptr->Contents.name ,rwptr->Contents.name ) ) return(1); }
			}
		else if ( is_named_widget( rwptr ) )
			{ if ( form_compare_failure( rptr, rwptr, "named widget3", "[auto]", rwptr->Contents.name  ) ) return(1); }

		/* Check integer fields */
		/* -------------------- */
		if ( lwptr->Contents.x != rwptr->Contents.x )
			{ if ( form_compare_failure( rptr, rwptr, "x position", "\0", "\0") ) return(1); }
		if ( lwptr->Contents.y != rwptr->Contents.y )
			{ if ( form_compare_failure( rptr, rwptr, "y position", "\0", "\0") ) return(1); }
		if ( lwptr->Contents.w != rwptr->Contents.w )
			{ if ( form_compare_failure( rptr, rwptr, "w position", "\0", "\0") ) return(1); }
		if ( lwptr->Contents.h != rwptr->Contents.h )
			{ if ( form_compare_failure( rptr, rwptr, "h position", "\0", "\0") ) return(1); }
		if ( lwptr->Contents.font != rwptr->Contents.font )
			{ if ( form_compare_failure( rptr, rwptr, "font", "\0", "\0") ) return(1); } 
		if ( lwptr->Contents.colour != rwptr->Contents.colour )
			{ if ( form_compare_failure( rptr, rwptr, "colour", "\0", "\0") ) return(1); } 
		if ( lwptr->Contents.style != rwptr->Contents.style )
			{ if ( form_compare_failure( rptr, rwptr, "style", "\0", "\0") ) return(1); } 
		if ( lwptr->Contents.align != rwptr->Contents.align )
			{ if ( form_compare_failure( rptr, rwptr, "align", "\0", "\0") ) return(1); } 
		if ( lwptr->Contents.interfaceitem != rwptr->Contents.interfaceitem )
			{ if ( form_compare_failure( rptr, rwptr, "interfaceitem", "\0", "\0") ) return(1); } 
		if ( lwptr->Contents.size != rwptr->Contents.size )
			{ if ( form_compare_failure( rptr, rwptr, "size", "\0", "\0") ) return(1); } 
		if ( lwptr->Contents.special != rwptr->Contents.special )
			{ if ( form_compare_failure( rptr, rwptr, "special", "\0", "\0") ) return(1); } 
		if ( lwptr->Contents.focus != rwptr->Contents.focus )
			{ if ( form_compare_failure( rptr, rwptr, "focus", "\0", "\0") ) return(1); } 
		if ( lwptr->Contents.page != rwptr->Contents.page )
			{ if ( form_compare_failure( rptr, rwptr, "page", "\0", "\0") ) return(1); } 
		if ( lwptr->Contents.radio != rwptr->Contents.radio )
			{ if ( form_compare_failure( rptr, rwptr, "radio", "\0", "\0") ) return(1); } 
		if ( lwptr->Contents.adjust != rwptr->Contents.adjust )
			{ if ( form_compare_failure( rptr, rwptr, "adjust", "\0", "\0") ) return(1); } 
		if ( lwptr->Contents.xlimit != rwptr->Contents.xlimit )
			{ if ( form_compare_failure( rptr, rwptr, "xlimit", "\0", "\0") ) return(1); } 
		if ( lwptr->Contents.ylimit != rwptr->Contents.ylimit )
			{ if ( form_compare_failure( rptr, rwptr, "ylimit", "\0", "\0") ) return(1); } 
		if ( lwptr->Contents.trigger != rwptr->Contents.trigger )
			{ if ( form_compare_failure( rptr, rwptr, "trigger", "\0", "\0") ) return(1); } 
		if ( lwptr->Contents.interfacenumber != rwptr->Contents.interfacenumber )
			{ if ( form_compare_failure( rptr, rwptr, "interfacenumber", "\0", "\0") ) return(1); } 
		if ( lwptr->Contents.datatype != rwptr->Contents.datatype )
			{ if ( form_compare_failure( rptr, rwptr, "datatype", "\0", "\0") ) return(1); } 

		/* check payload messages */
		/* ---------------------- */
		for (i=0; i < MAXNATLANG; i++ ) {
			if (!( lwptr->Contents.messages[i] )) {
				if (!( rwptr->Contents.messages[i] ))
					continue;
				else if (!( FormCompare.fixpayloads ))
					{ if ( form_compare_failure( rptr, rwptr, "new message", "[null]", rwptr->Contents.messages[i] ) ) return(1); } 
				else	{
					fixedmsgs++;
					rwptr->Contents.messages[i] = liberate( rwptr->Contents.messages[i] );
					continue;
					}
				}
			else if (!( rwptr->Contents.messages[i] )) {
				if (!( FormCompare.fixpayloads ))
					{ if ( form_compare_failure( lptr, lwptr, "missing message", lwptr->Contents.messages[i], "[null]") ) return(1); } 
				else	{
					fixedmsgs++;
					rwptr->Contents.messages[i] = allocate_string(lwptr->Contents.messages[i]);
					continue;
					}
				} 
			else if (!( strcmp(lwptr->Contents.messages[i],rwptr->Contents.messages[i] )))
				continue;
			else if (!( FormCompare.fixpayloads ))
				{ if ( form_compare_failure( rptr, rwptr, "message compare", lwptr->Contents.messages[i],rwptr->Contents.messages[i]) ) return(1); } 
			else	{
				fixedmsgs++;
				rwptr->Contents.messages[i] = liberate( rwptr->Contents.messages[i] );
				rwptr->Contents.messages[i] = allocate_string(lwptr->Contents.messages[i]);
				continue;
				}
			}
		/* check hint messages */
		for (i=0; i < MAXNATLANG; i++ ) {
			if (!( lwptr->Contents.hmessages[i] )) {
				if (!( rwptr->Contents.hmessages[i] ))
					continue;
				else if (!( FormCompare.fixpayloads ))
					{ if ( form_compare_failure( rptr, rwptr, "new hint", "[null]", rwptr->Contents.hmessages[i]) ) return(1); } 
				else	{
					fixedhints++;
					rwptr->Contents.hmessages[i] = liberate( rwptr->Contents.hmessages[i] );
					continue;
					}
				}
			else if (!( rwptr->Contents.hmessages[i] )) {
				if (!( FormCompare.fixpayloads ))
					{ if ( form_compare_failure( lptr, lwptr, "missing hint", lwptr->Contents.hmessages[i], "[null]") ) return(1); } 
				else	{
					fixedhints++;
					rwptr->Contents.hmessages[i] = allocate_string(lwptr->Contents.hmessages[i]);
					continue;
					}
				}
			else if (!( strcmp(lwptr->Contents.hmessages[i],rwptr->Contents.hmessages[i] )))
				continue;
			else if (!( FormCompare.fixpayloads ))
				{ if ( form_compare_failure( rptr, rwptr, "hint compare", lwptr->Contents.hmessages[i],rwptr->Contents.hmessages[i]) ) return(1); } 
			else	{
				fixedhints++;
				rwptr->Contents.hmessages[i] = liberate( rwptr->Contents.hmessages[i] );
				rwptr->Contents.hmessages[i] = allocate_string(lwptr->Contents.hmessages[i]);
				continue;
				}
			}

		/* check widget help texts */
		for (i=0; i < MAXNATLANG; i++ ) {
			if (!( form_string_compare( lwptr->document[i], rwptr->document[i] ) ))
				continue;
			else if (!( form_compare_failure( rptr, rwptr, "help text", lwptr->document[i], rwptr->document[i] ) ))
				continue;
			else	return(1); 
			} 

		/* check format */
		if (!( method_is_valid( lwptr->Contents.format ) )) {
			if ( method_is_valid( rwptr->Contents.format ) ) {
				if (!( FormCompare.fixformat ))
					{ if ( form_compare_failure( rptr, rwptr, "new format", "[null]", rwptr->Contents.format) ) return(1); } 
				else	rwptr->Contents.format = liberate( rwptr->Contents.format );
				}
			}
		else if (!( method_is_valid( rwptr->Contents.format ) )) {
			if (!( FormCompare.fixformat ))
				{ if ( form_compare_failure( lptr, lwptr, "missing format", lwptr->Contents.format, "[null]") ) return(1); } 
			else	rwptr->Contents.format = allocate_string( lwptr->Contents.format );
			}
		else if ( strcmp( lwptr->Contents.format,rwptr->Contents.format ) ) {
			if (!( FormCompare.fixformat ))
				{ if ( form_compare_failure( rptr, rwptr, "format compare", lwptr->Contents.format,rwptr->Contents.format) ) return(1); } 
			else	{
				rwptr->Contents.format = liberate( rwptr->Contents.format );
				rwptr->Contents.format = allocate_string( lwptr->Contents.format );
				}
			}
		/* check stylesheet */
		if (!( method_is_valid( lwptr->Contents.stylesheet ) )) {
			if ( method_is_valid( rwptr->Contents.stylesheet ) ) {
				if (!( FormCompare.fixformat ))
					{ if ( form_compare_failure( rptr, rwptr, "new stylesheet", "[null]", rwptr->Contents.stylesheet) ) return(1); } 
				else	rwptr->Contents.stylesheet = liberate( rwptr->Contents.stylesheet );
				}
			}
		else if (!( method_is_valid( rwptr->Contents.stylesheet ) )) {
			if (!( FormCompare.fixformat ))
				{ if ( form_compare_failure( lptr, lwptr, "missing stylesheet", lwptr->Contents.stylesheet, "[null]") ) return(1); } 
			else	rwptr->Contents.stylesheet = allocate_string( lwptr->Contents.stylesheet );
			}
		else if ( strcmp( lwptr->Contents.stylesheet,rwptr->Contents.stylesheet ) ) {
			if (!( FormCompare.fixformat ))
				{ if ( form_compare_failure( rptr, rwptr, "stylesheet compare", lwptr->Contents.stylesheet, rwptr->Contents.stylesheet ) ) return(1); } 
			else	{
				rwptr->Contents.stylesheet = liberate( rwptr->Contents.stylesheet );
				rwptr->Contents.stylesheet = allocate_string( lwptr->Contents.stylesheet );
				}
			}

		/* check event methods */
		/* ------------------- */
		if ( lwptr->Contents.events->xo_create != rwptr->Contents.events->xo_create) {
			if (!( FormCompare.fixevents ))
				{ if ( form_compare_failure( rptr, rwptr, "on_create", "\0", "\0") ) return(1); } 
			else 	rwptr->Contents.events->xo_create = lwptr->Contents.events->xo_create;
			}

		if ( lwptr->Contents.events->xo_remove != rwptr->Contents.events->xo_remove) {
			if (!( FormCompare.fixevents ))
				{ if ( form_compare_failure( rptr, rwptr, "xo_remove", "\0", "\0") ) return(1); } 
			else 	rwptr->Contents.events->xo_remove = lwptr->Contents.events->xo_remove;
			}

		if ( lwptr->Contents.events->xo_show != rwptr->Contents.events->xo_show) {
			if (!( FormCompare.fixevents ))
				{ if ( form_compare_failure( rptr, rwptr, "xo_show", "\0", "\0") ) return(1); } 
			else	rwptr->Contents.events->xo_show = lwptr->Contents.events->xo_show;
			}

		if ( lwptr->Contents.events->xo_hide != rwptr->Contents.events->xo_hide) {
			if (!( FormCompare.fixevents ))
				{ if ( form_compare_failure( rptr, rwptr, "xo_hide", "\0", "\0") ) return(1); } 
			else	rwptr->Contents.events->xo_hide = lwptr->Contents.events->xo_hide;
			}

		if ( lwptr->Contents.events->xo_get_focus != rwptr->Contents.events->xo_get_focus ) {
			if (!( FormCompare.fixevents ))
				{ if ( form_compare_failure( rptr, rwptr, "xo_get_focus", "\0", "\0") ) return(1); } 
			else	rwptr->Contents.events->xo_get_focus = lwptr->Contents.events->xo_get_focus;
			}

		if ( lwptr->Contents.events->xo_lose_focus != rwptr->Contents.events->xo_lose_focus) {
			if (!( FormCompare.fixevents ))
				{ if ( form_compare_failure( rptr, rwptr, "xo_lose_focus", "\0", "\0") ) return(1); } 
			else	rwptr->Contents.events->xo_lose_focus = lwptr->Contents.events->xo_lose_focus;
			}
		if ( lwptr->Contents.events->xo_event != rwptr->Contents.events->xo_event ) {
			if (!( FormCompare.fixevents ))
				{ if ( form_compare_failure( rptr, rwptr, "xo_event", "\0", "\0") ) return(1); } 
			else	rwptr->Contents.events->xo_event = lwptr->Contents.events->xo_event;
			}

		if (!( compare_widget_method( 	&lwptr->Contents.events->on_create,
						&rwptr->Contents.events->on_create)))
			{ if ( form_compare_failure( rptr, rwptr, "on_create", lwptr->Contents.events->on_create, rwptr->Contents.events->on_create) ) return(1); } 
		if (!( compare_widget_method( 	&lwptr->Contents.events->on_remove,
						&rwptr->Contents.events->on_remove)))
			{ if ( form_compare_failure( rptr, rwptr, "on_remove", lwptr->Contents.events->on_remove, rwptr->Contents.events->on_remove) ) return(1); } 
		if (!( compare_widget_method( 	&lwptr->Contents.events->on_show,
						&rwptr->Contents.events->on_show)))
			{ if ( form_compare_failure( rptr, rwptr, "on_show", lwptr->Contents.events->on_show, rwptr->Contents.events->on_show) ) return(1); } 
		if (!( compare_widget_method( 	&lwptr->Contents.events->on_hide,
						&rwptr->Contents.events->on_hide)))
			{ if ( form_compare_failure( rptr, rwptr, "on_hide", lwptr->Contents.events->on_hide, rwptr->Contents.events->on_hide) ) return(1); } 
		if (!( compare_widget_method( 	&lwptr->Contents.events->on_event,
						&rwptr->Contents.events->on_event)))
			{ if ( form_compare_failure( rptr, rwptr, "on_event", lwptr->Contents.events->on_event, rwptr->Contents.events->on_event) ) return(1); } 
		if (!( compare_widget_method( 	&lwptr->Contents.events->on_get_focus,
						&rwptr->Contents.events->on_get_focus)))
			{ if ( form_compare_failure( rptr, rwptr, "on_get_focus", lwptr->Contents.events->on_get_focus, rwptr->Contents.events->on_get_focus) ) return(1); } 
		if (!( compare_widget_method( 	&lwptr->Contents.events->on_lose_focus,
						&rwptr->Contents.events->on_lose_focus)))
			{ if ( form_compare_failure( rptr, rwptr, "on_lose_focus",lwptr->Contents.events->on_lose_focus, rwptr->Contents.events->on_lose_focus) ) return(1); } 

		}

	return(0);
}

void	close_form_compare_report()
{
	if ((FormCompare.loghandle)) {
		fprintf(FormCompare.loghandle,"\nEnd of Form Compare Report\n\n");
		fclose(FormCompare.loghandle );
		FormCompare.loghandle = (FILE *) 0;
		standard_text_editor( FormCompare.fixlog, strlen(FormCompare.fixlog)  );
		}
	return;
}

void	compare_Forms( struct form_control * fptr )
{
	char	*	thisform;
	char	*	other=(char *) 0;
	struct	form_control * optr;

	if (!( fptr ))
		return;
	else if (!( fptr->loadname ))
		return;
	else if (!( thisform = allocate_string( fptr->loadname ) ))
		return;
	else if (!( thisform = enforce_extension(thisform, XML_EXTENSION)))
		return;

	if (!( FormCompare.fixlog )) {
#ifndef	WIN32
		if ((FormCompare.fixlog = allocate(strlen("/tmp/formcompare.lst")+64)) != (char *) 0)
			sprintf(FormCompare.fixlog,"/tmp/formcompare%u.lst",getpid());
#else
		FormCompare.fixlog = allocate_string("formcompare.lst");
#endif		
		}

	if ( accept_form_compare( 
			&thisform,
			&FormCompare.formname,
			&FormCompare.fixpayloads,
			&FormCompare.fixmethods,
			&FormCompare.fixevents,
			&FormCompare.fixformat,
			&FormCompare.fixreport,
			&FormCompare.fixdetail,
			&FormCompare.fixlog ) != 27 ) {
		if ( method_is_valid( FormCompare.formname ) ) {
			if (( FormCompare.formname = enforce_extension(FormCompare.formname, XML_EXTENSION)) != (char *) 0) {
				if (( optr = resolve_form_control( FormCompare.formname )) != (struct form_control *) 0) {
					(void) form_compare( fptr, optr, 0 );
					close_form_compare_report();
					}
				else	status_message("form not found",3);
				}
			}
		}
	if ( thisform )
		liberate( thisform );
	return;		
}





#endif	/* _singcomp_c */
	/* ----------- */









