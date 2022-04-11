struct	window_control * connect_production_window();

public  void	generate_c_event_flush( FILE * h )
{
	linefeed(h);
	indent(h,1);
	if ( C_Config.newstdin )
		fprintf(h,"while( %s ) (void) %s(%s);",__c_test_event,C_Config.input_method,__c_instance_prefix);
	else	fprintf(h,"while( %s ) (void) %s();",__c_test_event,C_Config.input_method);
	linefeed(h);
	return;
}

private	void	generate_c_onfinish(FILE * h)
{
	linefeed(h);
	indent(h,1);
	fprintf(h,"if ( %s() == -1 )",__visual_liberate);
	linefeed(h); 	c_return(h,"56",2); 
	linefeed(h);
	return;
}

private	void	c_national_messages( FILE * h, struct form_item * iptr )
{
	int	nl;
	char *	sptr;
	if (!( max_payload_size( iptr ) ))
		return;

	indent(h,1);
	fprintf(h,"for (i=0; i < %u; i++)",MAXNATLANG); 
	if ((iptr->Contents.style & _FRAME_TYPE ) == _RADIO_FRAME)
		fprintf(h,"%s->msg%u_%s[i]=",__c_instance_prefix,iptr->Contents.radio,iptr->Contents.name);
	else	fprintf(h,"%s->msg_%s[i]=",__c_instance_prefix,iptr->Contents.name);
	fprintf(h,"%c %c;",0x0022,0x0022);
	linefeed(h);

	for (nl=0; nl < MAXNATLANG; nl++ ) {
		if ((!(sptr = iptr->Contents.messages[nl]))
		&&  (!(sptr = iptr->Contents.payload)))
			continue;
		else if ( *sptr == _UNQUOTED_STRING )
			continue;
		else	{
			indent(h,1);
			if ((iptr->Contents.style & _FRAME_TYPE ) == _RADIO_FRAME)
				fprintf(h,"%s->msg%u_%s[%u]=",__c_instance_prefix,iptr->Contents.radio,iptr->Contents.name,nl);
			else	fprintf(h,"%s->msg_%s[%u]=",__c_instance_prefix,iptr->Contents.name,nl);
			if ((iptr->Contents.style & _FRAME_TYPE ) == _RADIO_FRAME)
				fprintf(h,"%s%u_%s;",language_prefix(nl),iptr->Contents.radio,iptr->Contents.name);
			else	fprintf(h,"%s_%s;",language_prefix(nl),iptr->Contents.name);
			linefeed(h);
			}
		}
	return;		
}


private	void	generate_c_initfont(FILE * h,int margin)
{
	int	i;
	char *	fname;

	for (i=FONT_MIN; i< FONT_MAX; i++ ) {
		if (!(fname = font_name[i]))
			continue;
		else	{
			indent(h,margin);
			fprintf(h,"vfh[%u] = %s(",i,__visual_font);
			quoted_filename(h,fname);
			fprintf(h,",%u);",strlen(fname));
			linefeed(h); 
			}
		}
	return;
}

private	void	generate_c_onstart(FILE * h, int mode)
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
	fprintf(h,"%s(",__visual_palette);
		quoted_filename(h,SingConf->palette);
		fprintf(h,",%u);",strlen(SingConf->palette));
	linefeed(h);
	indent(h,2);
	fprintf(h,"cicopalette(0,0);");
	linefeed(h);
	generate_c_initfont(h,2);
	indent(h,2);
	fprintf(h,"initialise_mouse();");
	linefeed(h);
	indent(h,2);
	fprintf(h,"}");
	linefeed(h);
	return;
}

private	void	trigger_c_event( 
			FILE * h, 
			struct form_item * iptr,
			int mode,
			int margin )
{
	char	*	eptr;

	if (!( method_is_valid( iptr->Contents.events.on_event )))
		return;

	indent(h,margin);
	fprintf(h,"if ( %s &  0x%x ) {",__c_mouse_type,iptr->Contents.events.mimo );
	linefeed(h);
	if ( iptr->Contents.events.xo_event & _EVENT_IS_FUNCTION )
		activate_c_method(h,iptr->Contents.name,__method_event,iptr->Contents.events.on_event, mode ,margin);
	else	inline_c_method(h,iptr->Contents.name,__method_event,iptr->Contents.events.on_event, 1, margin);
	linefeed(h);
	indent(h,margin+1);
	fprintf(h,"}");
	linefeed(h);
	return;
}

/*	----------------------------------------------------------------------------------------	*/
/*		c _ e v e n t _ s w i t c h _ i t e m ( handle, item, mode, margin )			*/
/*	----------------------------------------------------------------------------------------	*/
/*	This function is responsible for the generation of all individual event behaviour code		*/
/*	for widgets which require event reception either in dialog box mode or the new event		*/
/*	driven mode. The mode parameter distinguishes between :						*/
/*		dialog box 	: 	true 								*/
/*	and 												*/
/*		event driven	:	false								*/
/*	In the former case the code will be generated in the switch/case fraemwork of the 256		*/
/*	event distibution of the dialog box "ongetfocus" method.					*/
/*	In the later case the code will be generated in the if else if event selection framework	*/
/*	of the event driven onevent method.								*/
/*	----------------------------------------------------------------------------------------	*/
private	void	c_event_switch_break( FILE * h, struct form_item * iptr, int margin )
{
	indent(h,margin);
	fprintf(h,"%s->%s=%u;",
			__c_instance_prefix,__c_focus_item,
			iptr->Contents.focus);
	linefeed(h);
	indent(h,margin);
	fprintf(h,"return(-1);");
	linefeed(h);
	return;
}

private	void	c_event_switch_continue( FILE * h, struct form_item * iptr, int margin )
{
	struct	form_control * fptr;
	indent(h,margin);
	fprintf(h,"%s->%s=%u;",
			__c_instance_prefix,__c_focus_item,
			iptr->Contents.focus);
	linefeed(h);
	indent(h,margin);
	if (( fptr = iptr->parent ) != (struct form_control *) 0) {
		switch (( fptr->formflags & _FORM_TYPE_FLAGS )) {
			case	_FORM_TYPE_DIALOG	:
				fprintf(h,"return(%u);",iptr->Contents.focus);
				break;
			case	_FORM_TYPE_EVENT 	:
				fprintf(h,"return(256);");
				break;
			}
		}
	else	{
		fprintf(h,"return(%u);",iptr->Contents.focus);
		}
	linefeed(h);
	return;
}

public	void	c_event_switch_item( FILE * h, struct form_item * iptr, int mode, int margin )
{
	/* invisible things can't be clicked on */
	/* ------------------------------------ */
	if ((!( iptr->Contents.w  ))
	||  (!( iptr->Contents.h  )))
		return;

	/* Explicite Event reception inhibition flag */
	/* ----------------------------------------- */
	else if (!( iptr->Contents.events.xo_event & _EVENT_IS_FOCUS ))
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

		case	_WINDOW_FRAME	:

			if (!( iptr->Contents.events.on_event )) {
				indent(h,margin++); 
				fprintf(h,"if (%s & _MIMO_UP) {",__c_mouse_type);
				linefeed(h);
				indent(h,margin); 
				fprintf(h,"%s->%s=27;",__c_instance_prefix,__c_keycode);
				linefeed(h);
				if ( mode )
					c_break(h,margin--);
				else	c_event_switch_break(h,iptr,margin--);
				c_else(h,margin++);
				if ( mode )
					c_continue(h,margin);
				else	c_event_switch_continue(h,iptr,margin);
				if (!( mode & 2 )) {
					c_endif(h,margin);
					}
				}
			else	{
				trigger_c_event(h,iptr,mode,margin);
				if ( mode )
					c_continue(h,margin);
				else	c_event_switch_continue(h,iptr,margin);
				}
			break;

		case	_TAB_FRAME	:

			indent(h,margin++); 
			fprintf(h,"if (%s & _MIMO_DOWN) {",__c_mouse_type);
			linefeed(h);
			c_call(h,C_Config.cname,__method_losefocus, 0,margin,(char*) 0 );
			indent(h,margin);
			fprintf(h,"%s->%s = %u;",__c_instance_prefix,__c_page_number,iptr->Contents.page);
			linefeed(h);
			c_call(h,C_Config.cname,__method_show, 0,margin,(char *) 0 );
			indent(h,margin--); fprintf(h,"}"); linefeed(h);
			trigger_c_event(h,iptr,mode,margin);
			if ( mode )
				c_continue(h,margin);
			else	c_event_switch_continue(h,iptr,margin);
			break;

		case	_SCROLL_FRAME	:
			activate_c_method(h,iptr->Contents.name,__method_action,"action",0,margin);
			if ( mode )
				c_continue(h,margin);
			else	c_event_switch_continue(h,iptr,margin);
			break;
	
		case	_RADIO_FRAME	:
			indent(h,margin++);
			fprintf(h,"if (%s & _MIMO_UP) {",__c_mouse_type);
			linefeed(h);
			indent(h,margin);
			fprintf(h,"%s->value_%s = %u;",__c_instance_prefix,iptr->Contents.name,iptr->Contents.radio);
			linefeed(h);
			c_call(h,C_Config.cname,__method_show, 0,margin,(char *) 0 );
			indent(h,margin--); fprintf(h,"}"); linefeed(h);
			trigger_c_event(h,iptr,mode,margin);
			if ( mode )
				c_continue(h,margin);
			else	c_event_switch_continue(h,iptr,margin);
			break;

		case	_SWITCH_FRAME	:
		case	_CHECK_FRAME	:
			indent(h,margin++);
			fprintf(h,"if (%s & _MIMO_UP) {",__c_mouse_type);
			linefeed(h);
			indent(h,margin);
			fprintf(h,"%s->value_%s += 1;",__c_instance_prefix,iptr->Contents.name);
			linefeed(h);
			indent(h,margin);
			fprintf(h,"%s->value_%s &= 1;",__c_instance_prefix,iptr->Contents.name);
			linefeed(h);
			if (!( iptr->Contents.events.xo_get_focus & _EVENT_IS_FOCUS )) {
				switch ((iptr->Contents.style&_FRAME_TYPE)) {
					case	_SWITCH_FRAME	:
						c_switch_widget(h,iptr,margin,0);
						break;
					case	_CHECK_FRAME	:
						c_check_widget(h,iptr,margin,0);
						break;
					}
				}
			indent(h,margin--); fprintf(h,"}"); linefeed(h);
			trigger_c_event(h,iptr,mode,margin);
			if ( mode )
				c_continue(h,margin);
			else	c_event_switch_continue(h,iptr,margin);
			break;

		case	_BUTTON_FRAME	:
			indent(h,margin++);
			fprintf(h,"if (%s & _MIMO_DOWN) {",__c_mouse_type);
			linefeed(h);
			c_button_widget(h,iptr,margin,2);
			indent(h,margin--); fprintf(h,"}"); 
			linefeed(h);
			indent(h,margin++);
			fprintf(h,"else if (%s & _MIMO_UP) {",__c_mouse_type);
			linefeed(h);
			c_button_widget(h,iptr,margin,0);
			indent(h,margin--); fprintf(h,"}"); 
			linefeed(h);
			trigger_c_event(h,iptr,mode,margin);
			if ( mode )
				c_continue(h,margin);
			else	c_event_switch_continue(h,iptr,margin);
			break;

		case	_EDIT_FRAME	:
			if ( iptr->Contents.datatype == _WIDGET_KONSTANT ) 
				return;

		case	_SELECT_FRAME	:
		default			:
			trigger_c_event(h,iptr,mode,margin);
			if ( mode )
				c_continue(h,margin);
			else	c_event_switch_continue(h,iptr,margin);
		}
	return;
}

private	void	generate_c_event_switch( FILE * h )
{
	struct	form_item * iptr;

	/* avoid pollution of current state if no widget selected */
	/* ------------------------------------------------------ */

	indent(h,4); fprintf(h,"if ((retcode=%s_event(%s)) == -1)",C_Config.cname,__c_instance_prefix);
	linefeed(h); c_continue(h,5);

	/* Determine Widget Selected by Event */
	/* ---------------------------------- */
	indent(h,4); fprintf(h,"switch ((%s->%s = retcode)) {",
		__c_instance_prefix,__c_focus_item);
	linefeed(h);

	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {

		c_event_switch_item( h, iptr, 1, 5 );

		}

	c_case(h,-1,5);
	c_default(h,5);
		indent(h,6);
		fprintf(h,"%s->%s=1;",__c_instance_prefix,__c_focus_item);
		linefeed(h);
		c_continue(h,5);
	indent(h,5);
	fprintf(h,"}");
	linefeed(h);
	return;
}


private	void	c_case_hotkey( FILE * h, int keycode, int margin )
{
	int	other;
	if (( keycode >= 'a' ) && ( keycode <= 'z' ))
		other = (keycode - ('a'-'A'));
	else	other = (keycode + ('a'-'A'));
	indent(h,margin);
	fprintf(h,"case 0x%x : ",(keycode|_MIMO_ALT));
	linefeed(h);
	indent(h,margin);
	fprintf(h,"case 0x%x : ",(other|_MIMO_ALT));
	linefeed(h);
	return;
}

private	void	c_widget_formtrigger( FILE * h,	struct form_item * iptr, int margin )
{
	switch ((iptr->Contents.style&_FRAME_TYPE)) {

		case	_TAB_FRAME	:

			c_case_hotkey(h,_MIMO_ALT|iptr->Contents.trigger,margin++);
			c_comment(h,iptr->Contents.name,margin);

			indent(h,margin);
			c_call(h,C_Config.cname,__method_losefocus, 0,margin,(char*) 0 );
			indent(h,margin);
			fprintf(h,"%s->%s = %u;",__c_instance_prefix,__c_page_number,iptr->Contents.page);
			linefeed(h);
			c_call(h,C_Config.cname,__method_show, 0,margin,(char *) 0 );
			break;

		case	_RADIO_FRAME	:
			c_case_hotkey(h,_MIMO_ALT|iptr->Contents.trigger,margin++);
			c_comment(h,iptr->Contents.name,margin);
			indent(h,margin);
			fprintf(h,"%s->value_%s = %u;",__c_instance_prefix,iptr->Contents.name,iptr->Contents.radio);
			linefeed(h);
			c_call(h,C_Config.cname,__method_show, 0,margin,(char *) 0 );
			break;

		case	_SWITCH_FRAME	:
		case	_CHECK_FRAME	:
			c_case_hotkey(h,_MIMO_ALT|iptr->Contents.trigger,margin);
			c_comment(h,iptr->Contents.name,margin);
			indent(h,margin);
			fprintf(h,"%s->value_%s += 1;",__c_instance_prefix,iptr->Contents.name);
			linefeed(h);
			indent(h,margin);
			fprintf(h,"%s->value_%s &= 1;",__c_instance_prefix,iptr->Contents.name);
			linefeed(h);
			break;

		case	_BUTTON_FRAME	:
			c_case_hotkey(h,_MIMO_ALT|iptr->Contents.trigger,margin);
			c_comment(h,iptr->Contents.name,margin);
			c_button_widget(h,iptr,margin,8);
			c_button_widget(h,iptr,margin,0);
			break;

		}
	indent(h,margin);
	fprintf(h,"%s->%s=%u;",
			__c_instance_prefix,__c_focus_item,
			iptr->Contents.focus);
	linefeed(h);
	if ( iptr->Contents.events.xo_event & _EVENT_IS_FUNCTION )
		activate_c_method(h,iptr->Contents.name,__method_event,iptr->Contents.events.on_event,1,margin);
	else	inline_c_method(h,iptr->Contents.name,__method_event,iptr->Contents.events.on_event,1,margin);
	c_continue(h,margin);
	return;
}

private	int	c_test_page( FILE * h,struct form_item * iptr, int margin )
{
	int	pn=0;
	if ((pn = iptr->Contents.page) != 0) {
		indent(h,margin);
		fprintf(h,"if (%s->%s == %u) {",__c_instance_prefix,__c_page_number,iptr->Contents.page);
		linefeed(h);
		}
	return(pn);
}

private	void	generate_c_trigger( FILE * h, struct form_item * iptr, int margin )
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
					generate_c_trigger(h,xptr,margin);
					break;
					}
				}
			}
		}
	else	{
		c_call(h,C_Config.cname,__method_losefocus, 0,margin,(char*) 0 );
		indent(h,margin);
		fprintf(h,"%s->%s = %u;",__c_instance_prefix,__c_page_number,iptr->Contents.page);
		linefeed(h);
		}

	c_call(h,C_Config.cname,__method_show, 0,margin,(char *) 0 );
	indent(h,margin);
	fprintf(h,"%s->%s=%u;",__c_instance_prefix,__c_focus_item,iptr->Contents.focus);
	linefeed(h);
	return;
}

private	void	c_widget_pagetrigger( FILE * h,	struct form_item * iptr, int margin )
{
	int	pn=0;

	switch ((iptr->Contents.style&_FRAME_TYPE)) {

		case	_TAB_FRAME	:

			c_comment(h,iptr->Contents.name,margin);
			indent(h,margin);
			c_call(h,C_Config.cname,__method_losefocus, 0,margin,(char*) 0 );
			indent(h,margin);
			fprintf(h,"%s->%s = %u;",__c_instance_prefix,__c_page_number,iptr->Contents.page);
			linefeed(h);
			c_call(h,C_Config.cname,__method_show, 0,margin,(char *) 0 );
			break;

		case	_RADIO_FRAME	:
			if ((pn = c_test_page(h,iptr,margin)) != 0)
				margin++;
			c_comment(h,iptr->Contents.name,margin);
			indent(h,margin);
			fprintf(h,"%s->value_%s = %u;",__c_instance_prefix,iptr->Contents.name,iptr->Contents.radio);
			linefeed(h);
			c_call(h,C_Config.cname,__method_show, 0,margin,(char *) 0 );
			break;

		case	_SWITCH_FRAME	:
		case	_CHECK_FRAME	:
			if ((pn = c_test_page(h,iptr,margin)) != 0)
				margin++;
			c_comment(h,iptr->Contents.name,margin);
			indent(h,margin);
			fprintf(h,"%s->value_%s += 1;",__c_instance_prefix,iptr->Contents.name);
			linefeed(h);
			indent(h,margin);
			fprintf(h,"%s->value_%s &= 1;",__c_instance_prefix,iptr->Contents.name);
			linefeed(h);
			break;

		case	_BUTTON_FRAME	:
			if ((pn = c_test_page(h,iptr,margin)) != 0)
				margin++;
			c_comment(h,iptr->Contents.name,margin);
			c_button_widget(h,iptr,margin,8);
			c_button_widget(h,iptr,margin,0);
			break;
		}

	indent(h,margin);
	fprintf(h,"%s->%s=%u;",__c_instance_prefix,__c_focus_item,iptr->Contents.focus);
	linefeed(h);
	if ( iptr->Contents.events.xo_event & _EVENT_IS_FUNCTION )
		activate_c_method(h,iptr->Contents.name,__method_event,iptr->Contents.events.on_event,1,margin);
	else	inline_c_method(h,iptr->Contents.name,__method_event,iptr->Contents.events.on_event,1,margin);
	c_continue(h,margin);
	if ( pn ) {
		indent(h,margin--);
		fprintf(h,"}");
		linefeed(h);
		}
	return;
}


private	void	c_detect_trigger_event( FILE * h, struct form_item * iptr, int margin)
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
			if (!( sptr = c_payload(iptr)))
				return;
			indent(h,margin);
			fprintf(h,"if (%s->trigger%u_%s",__c_instance_prefix,iptr->Contents.radio,iptr->Contents.name);
			break;

		case	_BUTTON_FRAME	:
		case	_SWITCH_FRAME	:
		case	_CHECK_FRAME	:
		case	_TAB_FRAME	:
			if (!( sptr = c_payload(iptr)))
				return;
			indent(h,margin);
			fprintf(h,"if (%s->trigger_%s",__c_instance_prefix,iptr->Contents.name);
			break;
		default			:
			return;
		}
	fprintf(h," == mb )");
	if (!( fptr ))
		fprintf(h," return(%u);",iptr->Contents.focus);
	else	{
		switch (( fptr->formflags & _FORM_TYPE_FLAGS )) {
			case	_FORM_TYPE_DIALOG	:
				fprintf(h," return(%u);",iptr->Contents.focus);
				break;

			case	_FORM_TYPE_EVENT 	:
				fprintf(h,"{");
				linefeed(h);
				c_event_switch_item(h, iptr, 0, margin );
				indent(h,margin);
				fprintf(h,"}");
				break;
			}
		}
	linefeed(h);
	return;
}

/*	-------------------------------------------------------------------------------		*/
/*	generates alt hotkey detection mechanisms for international/multilingual models 	*/
/*	-------------------------------------------------------------------------------		*/
private	void	c_detect_trigger_events( FILE * h, int margin )
{
	struct form_item * iptr;

	indent(h,margin); 
	fprintf(h,"if (%s & _MIMO_ALT) {",__c_mouse_type);
	linefeed(h);	
	indent(h,(margin+1));
	fprintf(h,"if (((mb = (%s & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');",__c_mouse_button);
	linefeed(h);
	for (	iptr=Context.Form->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
		c_detect_trigger_event(h,iptr,(margin+1));
	indent(h,(margin+1));
	fprintf(h,"return(-1);");
	linefeed(h);	
	indent(h,(margin+1));
	fprintf(h,"}");
	linefeed(h);	
	return;
}



private	void	generate_c_hotkey_switch( FILE * h, int margin )
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

				else if (!( widget_can_trigger( &iptr->Contents ) ))
					continue;

				else if (!( iptr->Contents.trigger ))
					continue;

				else if (!( compare_hotkeys( iptr->Contents.trigger, triggermap[i] )))
					continue;

				else	c_widget_pagetrigger(h,iptr,margin+1);

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

			/* Explicite Event reception inhibition flag */
			/* ----------------------------------------- */
			if (!( iptr->Contents.events.xo_event & _EVENT_IS_FOCUS ))
				continue;
			else if (!( iptr->Contents.focus ))
				continue;
			else if (!( iptr->Contents.trigger  ))
				continue;
			else	c_widget_formtrigger(h,iptr,margin);
			}
		}
	return;
}

	
public	void	drop_c_widget_saver( FILE * h, struct form_item * wptr, int margin )
{
	indent(h,margin);	
	fprintf(h,"if (%s->p_%s != (void *) 0)",
		__c_instance_prefix,wptr->Contents.name);
	linefeed(h);
	indent(h,margin+1);
	fprintf(h,"%s->p_%s = %s(%s->p_%s);",
		__c_instance_prefix,wptr->Contents.name,
		__visual_drop,
		__c_instance_prefix,wptr->Contents.name);
	linefeed(h);
	return;
}

public	void	c_widget_saver( FILE * h, struct form_item * wptr, int margin )
{
	indent(h,margin);;
	fprintf(h,"%s->s_%s=0;",__c_instance_prefix,wptr->Contents.name);
	linefeed(h);
	indent(h,margin);
	fprintf(h,"%s->p_%s=%s(",__c_instance_prefix,wptr->Contents.name,__visual_buffer);
		widget_position(h,wptr,0,0);
		widget_dimensions(h,wptr,0,0);
	fprintf(h,");");
	linefeed(h);
	return;
}

public	void	generate_c_popup( FILE * h, struct form_item * wptr, int margin )
{
	indent(h,margin);	
	fprintf(h,"if ((%s->p_%s != (void *) 0)",__c_instance_prefix,wptr->Contents.name);
	linefeed(h);
	indent(h,margin++);	
	fprintf(h,"&& (%s->s_%s == 0)) {",__c_instance_prefix,wptr->Contents.name);
	linefeed(h);
	indent(h,margin);	
	fprintf(h,"(void)%s(%s->p_%s,",__visual_get,__c_instance_prefix,wptr->Contents.name);
	widget_position(h,wptr,0,0);
	fprintf(h,");");
		linefeed(h);
		indent(h,margin);
	fprintf(h,"%s->s_%s=1;",__c_instance_prefix,wptr->Contents.name);
	linefeed(h);
	indent(h,margin);
	fprintf(h,"}");
	linefeed(h);
	return;
}

public	void	generate_c_popdown( FILE * h, struct form_item * wptr, int margin )
{
	indent(h,margin);	
	fprintf(h,"if ((%s->p_%s != (void *) 0)",__c_instance_prefix,wptr->Contents.name);
	linefeed(h);
	indent(h,margin++);	
	fprintf(h,"&& (%s->s_%s != 0)) {",__c_instance_prefix,wptr->Contents.name);
	linefeed(h);
	indent(h,margin);	
	fprintf(h,"(void)%s(%s->p_%s,",__visual_put,__c_instance_prefix,wptr->Contents.name);
	widget_position(h,wptr,0,0);
	fprintf(h,");");
		linefeed(h);
		indent(h,margin);
	fprintf(h,"%s->s_%s=0;",__c_instance_prefix,wptr->Contents.name);
	linefeed(h);
	indent(h,margin);
	fprintf(h,"}");
	linefeed(h);
	return;
}

private		void	c_generate_position_control(
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
		fprintf(h,"%s->x_%s=%u;",__c_instance_prefix,iptr->Contents.name,iptr->Contents.x+wx);
		linefeed(h);
		indent(h,1);
		fprintf(h,"%s->y_%s=%u;",__c_instance_prefix,iptr->Contents.name,iptr->Contents.y+wy);
		linefeed(h);
		indent(h,1);
		fprintf(h,"%s->w_%s=%u;",__c_instance_prefix,iptr->Contents.name,iptr->Contents.w);
		linefeed(h);
		indent(h,1);
		fprintf(h,"%s->h_%s=%u;",__c_instance_prefix,iptr->Contents.name,iptr->Contents.h);
		linefeed(h);
		}
	else	{
		indent(h,1);
		fprintf(h,"%s->x_%s=%s;",__c_instance_prefix,iptr->Contents.name,widget_x_position(iptr,1));
		linefeed(h);
		indent(h,1);
		fprintf(h,"%s->y_%s=%s;",__c_instance_prefix,iptr->Contents.name,widget_y_position(iptr,1));
		linefeed(h);
		indent(h,1);
		fprintf(h,"%s->w_%s=%s;",__c_instance_prefix,iptr->Contents.name,widget_w_dimension(iptr,1));
		linefeed(h);
		indent(h,1);
		fprintf(h,"%s->h_%s=%s;",__c_instance_prefix,iptr->Contents.name,widget_h_dimension(iptr,1));
		linefeed(h);
		}
	return;
}

public  void	generate_c_freeze( FILE * h, int margin )
{
	indent(h,margin);
	fprintf(h,"%s();",__visual_freeze);
	linefeed(h);
	return;
}

public  void	generate_c_thaw( FILE * h, struct form_item * wptr, int margin )
{
	indent(h,margin);
	fprintf(h,"%s(",__visual_thaw);
		widget_position(h,wptr,0,0);
		widget_dimensions(h,wptr,0,0);
	fprintf(h,");");
	linefeed(h);
}

public  void	export_c_form( FILE * h )
{
	struct	window_control * pwptr=(struct window_control *) 0;
	struct form_item * iptr;
	struct form_item * wptr;
	int	i;
	int	action=0;
	int	actions=6;
	int	members=0;
	int	xmembers=0;
	char *	tptr;

	C_Config.generate_program   = Context.Form->isprogram;
	C_Config.generate_overlay   = Context.Form->isoverlay;
	C_Config.page_control       = 0;

	if (!( C_Config.cname = Context.Form->identifier ))
		C_Config.cname = "dialog_box";
	else if (!( *(C_Config.cname) ))
		C_Config.cname = "dialog_box";

	set_c_form_input( Context.Form );
	set_c_form_error( Context.Form );

	status_progress(2,actions,action++);

	/* Generate Inclusions for Program */
	/* ------------------------------- */
	if ( C_Config.generate_program ) {
		C_Config.cname = "on";
		}

	/* Generate File Banner Block */
	/* -------------------------- */
	production_banner(h,_GENERATE_C,Context.Form->loadname,Context.Form->prodname);

	c_include(h,"<stdio.h>");
	c_include(h,"visual.h");

	if (( C_Config.generate_program   )
	&&  (!( C_Config.generate_overlay ))) {
		c_include(h,"cico.c");
		}

	if ( Context.Form->dependance)
		c_dependance(h,Context.Form->dependance);

	/* Instance Structure if Required */
	/* ------------------------------ */
	members = generate_c_form_structure(h,C_Config.cname);

	/* PROTOTYPES */
	/* ---------- */
	c_forms_method_forward(h,Context.Form);

	/* METHOD */
	/* ------ */
	c_forms_methods(h,Context.Form);

	/* ON CREATE */
	/* --------- */
	status_progress(2,actions,action++);

	c_oncreate_methods( h );

	if (!( C_Config.generate_program )) {
		/* init / palette / font etc */
		if ( C_Config.generate_overlay ) {
			linefeed(h);	
			fprintf(h,"public\tint\t%s_attach()",C_Config.cname);  linefeed(h);
			fprintf(h,"{"); linefeed(h);
			generate_c_onstart( h, 0 );
			indent(h,1);
			fprintf(h,"return(0);"); linefeed(h); 
			fprintf(h,"}"); linefeed(h);

			linefeed(h);	
			fprintf(h,"public\tint\t%s_attach_mode(int mode)",C_Config.cname);  linefeed(h);
			fprintf(h,"{"); linefeed(h);
			generate_c_onstart( h, 1 );
			indent(h,1);
			fprintf(h,"return(0);"); linefeed(h); 
			fprintf(h,"}"); linefeed(h);

			linefeed(h);	
			fprintf(h,"public\tint\t%s_detach()",C_Config.cname);  linefeed(h);
			fprintf(h,"{"); linefeed(h);
			generate_c_onfinish( h );
			indent(h,1);
			fprintf(h,"return(0);"); linefeed(h); 
			fprintf(h,"}"); linefeed(h);
			}

		}

	open_c_on_create( h, C_Config.cname, members );

	indent(h,1);	fprintf(h,"int i;");
	linefeed(h);
	indent(h,1);	
	c_method_instance_this (h); fprintf(h,"=(");
	c_method_instance_class(h); fprintf(h,"*)0;");
	linefeed(h);

	if ( C_Config.generate_program ) {
		/* init / palette / font etc */
		generate_c_onstart( h, 0 );
		}
	else if (!( C_Config.generate_overlay ))
		generate_c_initfont(h,1);

	/* Allocate the instance container */
	/* ------------------------------- */
	indent(h,1);
	fprintf(h,"if (!(%s = allocate( sizeof( struct %s%s ) ) ))",__c_instance_prefix,C_Config.cname,__c_instance_suffix);
	linefeed(h);
	indent(h,2); fprintf(h,"return(27);");
	linefeed(h);
	indent(h,1); fprintf(h,"else\t*cptr=%s;",__c_instance_prefix);
	linefeed(h);
	c_initialise_national_language(h,Context.Form,1);
	indent(h,1);
	fprintf(h,"%s->%s=0;",__c_instance_prefix,__c_keycode);
	linefeed(h);
	indent(h,1);
	fprintf(h,"%s->%s=1;",__c_instance_prefix,__c_focus_item);
	linefeed(h);
	indent(h,1);
	fprintf(h,"%s->%ss=%u;",__c_instance_prefix,__c_focus_item,Context.Form->focus);
	linefeed(h);

	if ( C_Config.page_control ) {
		indent(h,1);
		fprintf(h,"%s->%s=1;",__c_instance_prefix,__c_page_number);
		linefeed(h);
		}

	if ( members )
		transfer_parameters(h,1);

	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		if ( Context.Form->formflags & _MULTILINGUAL ) {
			c_national_messages(h,iptr);
			}

		if ( iptr->Contents.events.xo_create & _EVENT_IS_FOCUS ) {
			/* Generate Position and Dimensions Variables */
			c_generate_position_control( h,iptr );
			fprintf(h,"\t%s->fg_%s=%u;",__c_instance_prefix,iptr->Contents.name,iptr->Contents.h);
			linefeed(h);
			fprintf(h,"\t%s->bg_%s=%u;",__c_instance_prefix,iptr->Contents.name,iptr->Contents.h);
			linefeed(h);
			fprintf(h,"\t%s->fid_%s=%u;",__c_instance_prefix,iptr->Contents.name,iptr->Contents.font);
			linefeed(h);
			}

		if ( iptr->Contents.events.xo_hide & _EVENT_IS_POP ) {
			c_widget_saver(h,iptr,1);
			}

		switch ( ( iptr->Contents.style & _FRAME_TYPE ) ) {
			case	_WINDOW_FRAME 	:
				if (!( iptr->Contents.events.xo_create & _EVENT_IS_FOCUS ))
					c_generate_position_control( h,iptr );

				wptr = iptr;
				indent(h,1);
				fprintf(h,"%s->window_col=%u;",__c_instance_prefix,iptr->Contents.x);
				linefeed(h);
				indent(h,1);
				fprintf(h,"%s->window_row=%u;",__c_instance_prefix,iptr->Contents.y);
				linefeed(h);
				break;
			case	_TAB_FRAME	:
				indent(h,1);
				fprintf(h,"%s->focus_pages[%u]=%u;",__c_instance_prefix,iptr->Contents.page,iptr->Contents.focus);
				linefeed(h);
				break;

			case	_SCROLL_FRAME	:
				indent(h,1);
				fprintf(h,"%s->max_%s=1;",__c_instance_prefix,iptr->Contents.name);
				linefeed(h);

			case	_PROGRESS_FRAME	:
				indent(h,1);
				fprintf(h,"%s->value_%s=1;",__c_instance_prefix,iptr->Contents.name);
				linefeed(h);
				indent(h,1);
				fprintf(h,"%s->limit_%s=1;",__c_instance_prefix,iptr->Contents.name);
				linefeed(h);
				break;

			case	_FORM_FRAME	:
				indent(h,1);
				c_macro_line(h,iptr,"0");
				fprintf(h,";");
				linefeed(h);
				break;

			}
		if ( iptr->Contents.events.xo_create & _EVENT_IS_FUNCTION )
			activate_c_method(h,iptr->Contents.name,__method_create,iptr->Contents.events.on_create,0,1);
		else	inline_c_method(h,iptr->Contents.name,__method_create,iptr->Contents.events.on_create,0,1);
		}


	/* handle screen saver */
	/* ------------------- */
	if ( Context.Form->ispopup ) {
		if ( wptr ) {
			indent(h,1);
			fprintf(h,"%s->ctrlbuffer=0;",__c_instance_prefix);
			linefeed(h);
			indent(h,1);
			fprintf(h,"%s->pushbuffer=%s(",__c_instance_prefix,__visual_buffer);
			if ((( wptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME )
			&&  ( wptr->Contents.align & _A_SHADOW )) {
				fprintf(h,"%s,%s,%s+%u,%s+%u",
					widget_x_position(wptr,0),
					widget_y_position(wptr,0),
					widget_w_dimension(wptr,0),10,
					widget_h_dimension(wptr,0),10);
				}
			else	{
				widget_position(h,wptr,0,0);
				widget_dimensions(h,wptr,0,0);
				}
			fprintf(h,");");linefeed(h);
			}
		}

	fprintf(h,"\treturn(0);");	linefeed(h); 
	fprintf(h,"}"); 		linefeed(h);

	/* -------------------- */
	/*	ON _ HIDE  	*/
	/* -------------------- */
	status_progress(2,actions,action++);
	c_onhide_methods( h );
	linefeed(h);	fprintf(h,"public \tint\t%s_hide(",C_Config.cname); 
	c_method_instance_this(h); fprintf(h,")");
	linefeed(h);	fprintf(h,"{"); 
	linefeed(h);
	indent(h,1);
	fprintf(h,"int\tresult;");
	linefeed(h);

	/* ---------------------------- */
	/* Ensure THIS pointer is valid */
	/* ---------------------------- */
	indent(h,1);
	fprintf(h,"if (!( %s )) { return(0); }",__c_instance_prefix);
	linefeed(h);

	/* ----------------------------- */
	/* Store the return code for now */
	/* ----------------------------- */
	indent(h,1);
	fprintf(h,"result=%s->%s;",__c_instance_prefix,__c_keycode);
	linefeed(h);

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
		if (( iptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME)
			wptr = iptr;
		if ( iptr->Contents.events.xo_hide & _EVENT_IS_FUNCTION )
			activate_c_method(h,iptr->Contents.name,__method_hide,iptr->Contents.events.on_hide,0,1);
		else	inline_c_method(h,iptr->Contents.name,__method_hide,iptr->Contents.events.on_hide,0,1);

		if ( iptr->Contents.events.xo_hide & _EVENT_IS_POP ) {
			generate_c_popdown(h,iptr,1);
			}

		}

	/* ------------------- */
	/* handle screen saver */
	/* ------------------- */
	if ( Context.Form->ispopup ) {
		if ( wptr != (struct form_item *) 0) { 
			indent(h,1);	
			fprintf(h,"if ((%s->pushbuffer != (void *) 0)",__c_instance_prefix);
			linefeed(h);
			indent(h,1);	
			fprintf(h,"&& (%s->ctrlbuffer != 0)) {",__c_instance_prefix);
			linefeed(h);
			indent(h,2);	
			fprintf(h,"(void)%s(%s->pushbuffer,",__visual_put,__c_instance_prefix);
			widget_position(h,wptr,0,0);
			fprintf(h,");");
			linefeed(h);
			indent(h,2);
			fprintf(h,"%s->ctrlbuffer=0;",__c_instance_prefix);
			linefeed(h);
			indent(h,2);
			fprintf(h,"}");
			linefeed(h);
			}
		}
	linefeed(h);	fprintf(h,"\treturn(result);");
	linefeed(h); 	fprintf(h,"}"); 
	linefeed(h);


	/* -------------------- */
	/*	ON _ REMOVE	*/
	/* -------------------- */
	status_progress(2,actions,action++);
	c_onremove_methods( h );

	c_signature(h,C_Config.cname,__method_remove, members,0 );

	linefeed(h);
	indent(h,1);
	fprintf(h,"int\tresult;");
	linefeed(h);

	/* ---------------------------- */
	/* Ensure THIS pointer is valid */
	/* ---------------------------- */
	indent(h,1);
	fprintf(h,"if (!( %s )) { return(0); }",__c_instance_prefix);
	linefeed(h);

	/* ----------------------------- */
	/* Store the return code for now */
	/* ----------------------------- */
	indent(h,1);
	fprintf(h,"result=%s->%s;",__c_instance_prefix,__c_keycode);
	linefeed(h);

	/* ------------------------------------- */
	/* Activate Destructors in reverse order */
	/* ------------------------------------- */
	for (	iptr=Context.Form->last;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->previous )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if ( iptr->Contents.events.xo_remove & _EVENT_IS_FUNCTION )
			activate_c_method(h,iptr->Contents.name,__method_remove,iptr->Contents.events.on_remove,0,1);
		else	inline_c_method(h,iptr->Contents.name,__method_remove,iptr->Contents.events.on_remove,0,1);

		if ( iptr->Contents.events.xo_hide & _EVENT_IS_POP ) {
			drop_c_widget_saver(h,iptr,1);
			}
		
		}

	if ( members ) { transfer_parameters(h,0); }

	/* ------------------- */
	/* handle screen saver */
	/* ------------------- */
	if ( Context.Form->ispopup ) {
		if ( wptr ) {
			indent(h,1);	
			fprintf(h,"if (%s->pushbuffer != (void *) 0)",__c_instance_prefix);
			linefeed(h);
			indent(h,2);
			fprintf(h,"%s->pushbuffer = %s(%s->pushbuffer);",__c_instance_prefix,__visual_drop,__c_instance_prefix);
			linefeed(h);
			}
		}

	/* ------------------------------ */
	/* Release the instance container */
	/* ------------------------------ */
	fprintf(h,"\t%s=liberate(%s);",__c_instance_prefix,__c_instance_prefix);
	linefeed(h);

	if ( C_Config.generate_program ) {
		generate_c_onfinish(h);
		}

	linefeed(h);	fprintf(h,"\treturn(result);");
	linefeed(h); 	fprintf(h,"}"); 
	linefeed(h);

	/* -------------------- */
	/*	ON _  SHOW 	*/
	/* -------------------- */
	status_progress(2,actions,action++);
	c_onshow_methods( h );
	linefeed(h);	fprintf(h,"%s\tint\t%s_%s(",keyword_public,C_Config.cname,__method_show); 
	c_method_instance_this(h); fprintf(h,")");
	linefeed(h);	fprintf(h,"{"); 
	linefeed(h);

	c_initialise_national_language(h,Context.Form,0);

	/* ------------------- */
	/* handle screen saver */
	/* ------------------- */
	if ( Context.Form->ispopup ) {
		if ( wptr != (struct form_item *) 0) { 
			indent(h,1);	
			fprintf(h,"if ((%s->pushbuffer != (void *) 0)",__c_instance_prefix);
			linefeed(h);
			indent(h,1);	
			fprintf(h,"&& (!(%s->ctrlbuffer))) {",__c_instance_prefix);
			linefeed(h);
			indent(h,2);	
			fprintf(h,"(void)%s(%s->pushbuffer,",__visual_get,__c_instance_prefix);
			widget_position(h,wptr,0,0);
			fprintf(h,");");
			linefeed(h);
			indent(h,2);
			fprintf(h,"%s->ctrlbuffer=1;",__c_instance_prefix);
			linefeed(h);
			indent(h,2);
			fprintf(h,"}");
			linefeed(h);
			}
		}


	/* -------------------- */
	/* Ensure Screen Frozen */
	/* -------------------- */
	generate_c_freeze(h,1);

	/* -------------------------------- */
	/* Generate member Show expressions */
	/* -------------------------------- */
	for (	wptr=(struct form_item*) 0,iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if ( iptr->Contents.events.xo_show & _EVENT_IS_COND )
			continue;
		if ((!( wptr ))
		&&  (( iptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME)) {
			wptr = iptr;
			}
		generate_c_show(h,iptr,1);
		}

	/* --------------------------- */
	/* Handle window or other Thaw */	
	/* --------------------------- */
	if ( wptr != (struct form_item *) 0 ) {
		generate_c_thaw(h,wptr,1);
		indent(h,1);
		fprintf(h,"%s(",__visual_thaw);
			widget_position(h,wptr,0,0);
			widget_dimensions(h,wptr,0,0);
		fprintf(h,");");
		linefeed(h);
		}
	else if ((pwptr = connect_production_window()) != (struct window_control *) 0) {
		indent(h,1);
		fprintf(h,"%s(%u,%u,%u,%u);",__visual_thaw,pwptr->x,pwptr->y,pwptr->w,pwptr->h);
		linefeed(h);
		}

	linefeed(h);	fprintf(h,"\treturn(0);");
	linefeed(h); 	fprintf(h,"}");
	linefeed(h);

	/* -------------------- */
	/*	ON _ EVENT 	*/
	/* -------------------- */
	status_progress(2,actions,action++);
	c_onevent_methods( h );
	linefeed(h);
	linefeed(h);	
	fprintf(h,"%s\tint\t%s_%s(",keyword_public,C_Config.cname,__method_event);			linefeed(h);
	c_method_instance_this(h); fprintf(h,")");
 	fprintf(h,"{"); 										linefeed(h);	
	fprintf(h,"\tint\tmx,my,mt,mb;");								linefeed(h);

	/* ---------------------------------------------- */
	/* international / multilingual trigger detection */
	/* ---------------------------------------------- */
	if (( Context.Form->formflags & _INTERNATIONAL )
	&&  ( Context.Form->formflags & _MULTILINGUAL  )) {
		c_detect_trigger_events(h,1);
		}

	fprintf(h,"\tif (!((mt = %s) & 0x%x)) return(-1); ",__c_mouse_type,Context.Form->mimoflags);	linefeed(h);

	fprintf(h,"\tmx = %s;",__c_mouse_column);	linefeed(h);
	fprintf(h,"\tmy = %s;",__c_mouse_row);		linefeed(h);

	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else	generate_c_event(h,iptr);
		}

	linefeed(h);
	fprintf(h,"\treturn(-1);");
	linefeed(h);	fprintf(h,"}");
	linefeed(h);

	/* ---------------------------- */
	/*	ON _ LOSE FOCUS 	*/
	/* ---------------------------- */
	status_progress(2,actions,action++);
	c_onlose_methods( h );
	if ( Context.Form->pages != 0 ) {
		linefeed(h);
		linefeed(h);	fprintf(h,"%s\tint\t%s_%s(",keyword_public,C_Config.cname,__method_losefocus);
		c_method_instance_this(h); fprintf(h,")");
		linefeed(h);	fprintf(h,"{");
		linefeed(h);
		indent(h,1);	fprintf(h,"switch (%s->%s) {",
					__c_instance_prefix,__c_page_number);
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
			fprintf(h,"case %u : ",iptr->Contents.page);
			linefeed(h); 
			if ( iptr->Contents.events.xo_lose_focus & _EVENT_IS_FUNCTION )
				activate_c_method(h,iptr->Contents.name,__method_losefocus,iptr->Contents.events.on_lose_focus,0,3);
			else	inline_c_method(h,iptr->Contents.name,__method_losefocus,iptr->Contents.events.on_lose_focus,0,3);
			indent(h,3);
			fprintf(h,"break;");
			linefeed(h); 
			}
		linefeed(h); 
		indent(h,2);
		fprintf(h,"}");
	 	linefeed(h);
		c_return(h,"0",1);
		linefeed(h); 
		fprintf(h,"}");
	 	linefeed(h);
		}


	/* -------------------- */
	/*	ON _ FOCUS 	*/
	/* -------------------- */
	status_progress(2,actions,action++);
	c_onget_methods( h );
	linefeed(h);
	linefeed(h);
	fprintf(h,"%s\tint\t%s_%s(",keyword_public,C_Config.cname,__method_focus);
	c_method_instance_this(h); fprintf(h,")");
	linefeed(h);
	fprintf(h,"{");
	linefeed(h);
	indent(h,1); fprintf(h,"int retcode=0;");
	linefeed(h);

	if (!( Context.Form->focus )) { /* No focus items ! */
		indent(h,1);
		fprintf(h,"%s->%s=13;",__c_instance_prefix,__c_keycode);
		linefeed(h);
		}
	else	{	

	generate_c_event_flush(h); 
	linefeed(h);	
	indent(h,1);	fprintf(h,"while(1) {");
	linefeed(h);
	indent(h,2);	fprintf(h,"switch (%s->%s) {",__c_instance_prefix,__c_focus_item);
	linefeed(h);

	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if (!( iptr->Contents.events.xo_get_focus & _EVENT_IS_FOCUS ))
			continue;
		else	generate_c_focus(h,iptr);
		}
	linefeed(h);
	c_default(h,3);
	indent(h,4);
	fprintf(h,"%s->%s=5;",__c_instance_prefix,__c_keycode);
	linefeed(h);
	indent(h,3);
	fprintf(h,"}");
	linefeed(h);
	if (!( Context.Form->mimoflags & _MIMO_KEYBOARD )) {
		fprintf(h,"retry:");
		linefeed(h);
		}
	indent(h,2);	fprintf(h,"switch (%s->%s) {",__c_instance_prefix,__c_keycode);
	linefeed(h);
		c_case(h,0x000C,2);	/* Home	     */
			if ( C_Config.page_control ) {
				c_call(h,C_Config.cname,__method_losefocus, 0,3,(char*) 0 );
				indent(h,3);
				fprintf(h,"%s->%s=1;",__c_instance_prefix,__c_page_number);
				linefeed(h);
				}
			indent(h,3);
			fprintf(h,"%s->%s=1;",__c_instance_prefix,__c_focus_item);
			linefeed(h);
			c_call(h,C_Config.cname,__method_show, 0,3,(char*) 0 );
			c_continue(h,3);
			
		c_case(h,0x0002,2);	/* End 	     */
			if ( C_Config.page_control ) {
				c_call(h,C_Config.cname,__method_losefocus, 0,3,(char*) 0 );
				indent(h,3);
				fprintf(h,"%s->%s=%u;",__c_instance_prefix,__c_page_number,Context.Form->pages);
				linefeed(h);
				}
			indent(h,3);
			fprintf(h,"%s->%s=%u;",__c_instance_prefix,__c_focus_item,Context.Form->focus);
			linefeed(h);
			c_call(h,C_Config.cname,__method_show, 0,3,(char *) 0 );
			c_continue(h,3);

	if ( C_Config.page_control ) {
		c_case(h,3,2);	/* Page Down */
			c_call(h,C_Config.cname,__method_losefocus, 0,3,(char*) 0 );
			indent(h,3);
			fprintf(h,"if ( %s->%s < %u )",__c_instance_prefix,__c_page_number,Context.Form->pages );
			linefeed(h);
			indent(h,4);
			fprintf(h,"%s->%s++;",__c_instance_prefix,__c_page_number);
			linefeed(h);
			indent(h,3);
			fprintf(h,"else\t%s->%s=1;",__c_instance_prefix,__c_page_number);
			linefeed(h);
			indent(h,3);
			fprintf(h,"%s->%s=%s->focus_pages[%s->%s];",
					__c_instance_prefix,__c_focus_item,
					__c_instance_prefix,
					__c_instance_prefix,__c_page_number);
			linefeed(h);
			c_call(h,C_Config.cname,__method_show, 0,3,(char *) 0 );
			c_continue(h,3);
		c_case(h,0x0012,2);	/* Page Up   */
			c_call(h,C_Config.cname,__method_losefocus, 0,3,(char*) 0 );
			indent(h,3);
			fprintf(h,"if (%s->%s > 1 )",__c_instance_prefix,__c_page_number);
			linefeed(h);
			indent(h,4);
			fprintf(h,"%s->%s--;",__c_instance_prefix,__c_page_number);
			linefeed(h);
			indent(h,3);
			fprintf(h,"else\t%s->%s = %u;",__c_instance_prefix,__c_page_number,C_Config.page_control);
			linefeed(h);
			indent(h,3);
			fprintf(h,"%s->%s=%s->focus_pages[%s->%s];",
					__c_instance_prefix,__c_focus_item,
					__c_instance_prefix,
					__c_instance_prefix,__c_page_number);
			linefeed(h);
			c_call(h,C_Config.cname,__method_show, 0,3,(char *) 0 );
			c_continue(h,3);

		}
		c_case(h,256,3);
			if ((!( Context.Form->mimoflags & _MIMO_KEYBOARD ))
			&&  (!( Context.Form->formflags & _MULTILINGUAL  ))) {
				indent(h,4); fprintf(h,"if (%s & _MIMO_ALT) {",__c_mouse_type);
				fprintf(h," %s->%s=%s; goto retry; }",__c_instance_prefix,__c_keycode,__c_mouse_button);
				linefeed(h);
				}
			if ( Context.Form->formflags & _FORM_DEFAULT ) {
				if ((pwptr = connect_production_window()) != (struct window_control *) 0) {
					indent(h,4);
					fprintf(h,"if (!( %s  & _MIMO_ALT )) { ",__c_mouse_type);
					linefeed(h);
					indent(h,5);
					fprintf(h,"if (( %s <  %u )",__c_mouse_column,pwptr->x);
					linefeed(h);
					indent(h,5);
					fprintf(h,"|| ( %s <  %u )",__c_mouse_row   ,pwptr->y);
					linefeed(h);
					indent(h,5);
					fprintf(h,"|| ( %s >  %u )",__c_mouse_column,pwptr->x+pwptr->w);
					linefeed(h);
					indent(h,5);
					fprintf(h,"|| ( %s >  %u )) {",__c_mouse_row   ,pwptr->y+pwptr->h);
					linefeed(h);
					indent(h,6);
					fprintf(h,"if ( %s  & _MIMO_MOVE ) { continue; }",__c_mouse_type);
					linefeed(h);
					indent(h,6);
					fprintf(h,"else { return(256); }");
					linefeed(h);
					indent(h,6);
					fprintf(h,"}");
					linefeed(h);
					indent(h,5);
					fprintf(h,"}");
					linefeed(h);
					}
				}
			generate_c_event_switch(h);
			c_break(h,4);

		c_case(h,27,3); 
		c_case(h,13,3); 
			c_break(h,4);
		c_case(h, 9,3); 
		c_case(h, 5,3); 
			indent(h,3);
			fprintf(h,"if ( %s->%s < %s->%ss ) {",
				__c_instance_prefix,__c_focus_item,
				__c_instance_prefix,__c_focus_item);
			linefeed(h);
				indent(h,4);
				fprintf(h,"%s->%s++;",
					__c_instance_prefix,__c_focus_item);
			c_else(h,3);
				indent(h,4);
				fprintf(h,"%s->%s=1;",
					__c_instance_prefix,__c_focus_item);
				linefeed(h);
			c_endif(h,3);
			c_continue( h,3 );
		c_case(h,11,3);
			indent(h,3);
			fprintf(h,"if ( %s->%s > 1 ) {",
					__c_instance_prefix,__c_focus_item);
			linefeed(h);
				indent(h,4);
				fprintf(h,"%s->%s--;",
					__c_instance_prefix,__c_focus_item);
				linefeed(h);
			c_else( h, 3 );
				indent(h,4);
				fprintf(h,"%s->%s=%u;",
					__c_instance_prefix,__c_focus_item,
					Context.Form->focus);
				linefeed(h);
			c_endif( h, 3 );
			c_continue( h,3 );
		if ( Context.Form->mimoflags & _MIMO_INTERRUPT ) {
			generate_c_hotkey_switch(h,2);
			}
		if (!( Context.Form->formflags & _FORM_DEFAULT )) {
			indent(h,2);
			fprintf(h,"default :");
			linefeed(h);
			c_continue(h,3);
			}
		else	{
			c_case(h,0,3);
			indent(h,3);
			linefeed(h);
			c_continue(h,3);
			c_case(h,-1,3);
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
	generate_c_event_flush(h);
	c_return(h,"0",1);
	linefeed(h); fprintf(h,"}"); linefeed(h);


	status_progress(2,actions,action++);
	generate_c_main(h,C_Config.cname,members,Context.Form->focus);

	return;
}


