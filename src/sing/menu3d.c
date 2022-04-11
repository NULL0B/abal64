#ifndef	_menu3d_c
#define	_menu3d_c

char	*	menu_message( struct menu_control * mptr )
{
	if ( mptr ) {
		if ( mptr->identifier )
			return( mptr->identifier );
		else if ( mptr->loadname )
			return( mptr->loadname );
		else if ( mptr->prodname )
			return( mptr->prodname );
		}
	return("[menu]");
}

public	struct menu_control *	liberate_Menu(struct menu_control * mptr)
{
	if ( mptr  != (struct menu_control *) 0) {

		if ( mptr->prodname )
			mptr->prodname = liberate( mptr->prodname );

		if ( mptr->dependance )
			mptr->dependance = liberate( mptr->dependance );

		if ( mptr->construction )
			mptr->construction = liberate( mptr->construction );

		if ( mptr->document )
			mptr->document = liberate( mptr->document );

		if ( mptr->loadname )
			mptr->loadname = liberate( mptr->loadname );

		if ( mptr->hint )
			mptr->hint = liberate( mptr->hint );

		if ( mptr->service )
			mptr->service = liberate( mptr->service );

		if ( mptr->iname )
			mptr->iname = liberate( mptr->iname );

		if ( mptr->image )
			mptr->image = local_drop_image( mptr->image );

		if ( mptr->shadow )
			mptr->shadow = local_drop_image( mptr->shadow );

		}
	return((struct menu_control *) 0);
}

public	struct menu_control *	allocate_Menu( char * nptr)
{
	struct menu_control * mptr;

	if (!( mptr = allocate( sizeof( struct menu_control ) ) ))
		return(mptr);
	else if (!( mptr->treenode = allocate_for_treeview())) {
		liberate( mptr );
		return((struct menu_control *) 0);
		}

	mptr->host      = (void *) 0;
	mptr->first 	= 
	mptr->last 	= 
	mptr->current   = (struct menu_option *) 0;
	mptr->doctool   = _TEXT_TOOL;
	mptr->document  =
	mptr->dependance=
	mptr->construction=
	mptr->prodname  =
	mptr->loadname  =
	mptr->hint	=
	mptr->service	=
	mptr->identifier=
	mptr->iname	= (char *) 0;
	mptr->image	=
	mptr->shadow	= (void *) 0;
	mptr->isprogram = 0;
	mptr->isoverlay	= 0;
	mptr->language    = production_language();
	mptr->font	= 1;
	mptr->style	= 0;
	mptr->x		=
	mptr->y		=
	mptr->w		=
	mptr->h		= 0;
	mptr->maxwidth  = 
	mptr->nature	= 
	mptr->state	=
	mptr->members	=
	mptr->storage	= 0;

	if (!( nptr ))
		return( mptr );
	else if (!( mptr->loadname = allocate_string( nptr ) ))
		return( liberate_Menu( mptr ) );
	else	return( mptr );

}
	
public	struct menu_option *	liberate_Option(struct menu_option * optr )
{

	if ( optr != (struct menu_option *) 0) {
		if ( optr->document )
			optr->document = liberate( optr->document );
		if ( optr->label )
			optr->label = liberate( optr->label );
		if ( optr->hint )
			optr->hint = liberate( optr->hint );
		if ( optr->service )
			optr->service = liberate( optr->service );
		if ( optr->linkage )
			optr->linkage = liberate( optr->linkage );

		optr = liberate( optr );

		}
	return( optr );
}


public	struct menu_option *	allocate_Option()
{
	struct menu_option * optr;

	if (!( optr = allocate( sizeof( struct menu_option ) ) ))
		return(optr);

	optr->previous	=
	optr->next	= (struct menu_option  *) 0;
	optr->parent	= (struct menu_control *) 0;
	optr->doctool   = _TEXT_TOOL;
	optr->document  =
	optr->label	=
	optr->hint	=
	optr->service	=
	optr->linkage	= (char *) 0;
	optr->hotkey	=
	optr->result	=
	optr->state	=
	optr->x		=
	optr->y		= 0;

	return( optr );
}

private	void	add_new_option(	struct menu_control * mptr,
				struct 	menu_option * optr )
{
	optr->parent = mptr;
	if (!(optr->previous = mptr->last))
		mptr->first  = optr;
	else	mptr->last->next = optr;
	mptr->current = mptr->last = optr;
	return;
}

private	void	menu_Image(struct menu_control * mptr)
{
	struct standard_image * iptr;
	int		r;
	char	*	sptr;

	if (( iptr = mptr->image ) != (struct standard_image *) 0) {
		if ((iptr->rows    != mptr->h)
		|   (iptr->columns != mptr->w))
			iptr = local_drop_image( iptr );
		mptr->image = (struct standard_image *) 0;
		}

	if ((!( iptr ))
	&&  (!( iptr = local_allocate_image( mptr->w, mptr->h,0,0 ) )))
		return;

	else	mptr->image = iptr;

	for (	r=0; r < mptr->h; r++ ) {
		if (!( sptr = connect_pixel_row( iptr->storage, r ) ))
			break;
		else 	getzone(Context.DeskTop.x+mptr->x,(Context.DeskTop.y+mptr->y+r),mptr->w,1,sptr);
		}
	mptr->savestamp = time((long *) 0);
	return;
}

public	struct menu_control *	load_Menu(char * nptr, int automatic)
{
	FILE	*	h;
	char	*	loadname;
	char	*	sptr;
	char	*	vptr;
	int		o;
	struct	menu_control * mptr;
	struct	menu_option  * optr;

	if (!( automatic & 4 ))
		sprintf(namebuffer,"%s.men",nptr);
	else	{
		strcpy(namebuffer,nptr);
		automatic &= ~4;
		}

	if (!( loadname = allocate_string( namebuffer ) ))
		return((struct menu_control *) 0);
		
	if (!( automatic & 1 )) {
		if ( accept_form_load(&loadname) == 27 ) {
			draw_console();
			loadname = liberate( loadname );
			return((struct menu_control *) 0);
			}
		status_message(loadname,3);
		}

	if ((h = fopen(loadname,"rb")) != (FILE *) 0) {

		if (!( mptr = allocate_Menu(loadname))) {
			fclose(h);
			loadname = liberate( loadname );
			return(mptr);
			}


		if (!( automatic & 2 ))
			status_message(mptr->loadname,3);

		if ((!(sptr = get_string(h)))
		||  (!( string_compare(sptr, "MENU" )))
		||  (!(vptr = get_string(h)))) {
			fclose(h);
			incorrect_filetype(loadname);
			loadname = liberate( loadname );
			return(mptr);
			}
		else	{

			if ((o = get_word(h)) & 2) {

				mptr->identifier = get_string(h);
				mptr->isprogram  = get_word(h);
				mptr->isoverlay  = get_word(h);

				}

			mptr->prodname = get_string(h);
			mptr->loadname = get_string(h);
			mptr->hint = get_string(h);
			mptr->service = get_string(h);
			mptr->iname = get_string(h);

			mptr->x = get_word(h);
			mptr->y = get_word(h);
			mptr->w = get_word(h);
			mptr->h = get_word(h);

			mptr->language = get_word(h);
			mptr->font = get_word(h);
			mptr->style = get_word(h);
			mptr->nature = get_word(h);
	
			if (o & 8 )
				mptr->dependance = get_string(h);
			else	mptr->dependance = (char *) 0;

			if (o & 0x0010 ) {
				mptr->doctool  = get_word(h);
				mptr->document = get_string(h);
				}
			else	{
				mptr->doctool  = _TEXT_TOOL;
				mptr->document = (char *) 0;
				}
			while ( get_word(h) != 0 ) {
				if (!( optr = allocate_Option() ))
					break;
				else	{
					add_new_option(mptr, optr);
					optr->label	= get_string(h);
					optr->hint	= get_string(h);
					optr->service	= get_string(h);
					optr->linkage	= get_string(h);
					optr->hotkey	= get_word(h);
					optr->result	= get_word(h);
					optr->state	= get_word(h);
					if ( o & 4 ) {
						optr->x = get_word(h);
						optr->y = get_word(h);
						optr->w = get_word(h);
						optr->h = get_word(h);
						}

					if (o & 0x0010 ) {
						optr->doctool  = get_word(h);
						optr->document = get_string(h);
						}
					else	{
						optr->doctool  = _TEXT_TOOL;
						optr->document = (char *) 0;
						}
					}
				}

			if ( sptr ) sptr = liberate( sptr );
			if ( vptr ) vptr = liberate( vptr );

			}

		fclose(h);
		loadname = liberate( loadname );
		return(mptr);

		}
	else	{
		if (!( automatic & 1 ))
			draw_console();
		if (!( automatic & 2 )) {
			sprintf(namebuffer,"error:%s.men",nptr);
			status_message(namebuffer,3);
			}
		loadname = liberate( loadname );
		return((struct menu_control *) 0);
		}

}

public	int 	save_Menu(struct menu_control * mptr,int automatic)
{
	FILE	*	h;
	struct 	menu_option * optr;

	if (!( mptr ))
		return(0);

	if (!( mptr->loadname )) {
		if (!(mptr->loadname = allocate_string( "new.men" ) ))
			return(27);
		}

	if (!( automatic )) {
		if ( accept_form_save(&mptr->loadname) == 27 ) {
			draw_console();
			return(0);
			}
		else	status_message(mptr->loadname,3);
		}

	if ((h = open_production_target(mptr->loadname,1)) != (FILE *) 0) {

		status_message(mptr->loadname,3);

		put_string(h,"MENU");
		put_string(h,LaPaterne);

		put_word(h,0x001F);

		put_string(h,mptr->identifier);
		put_word(h,mptr->isprogram);
		put_word(h,mptr->isoverlay);

		put_string(h,mptr->prodname);
		put_string(h,mptr->loadname);
		put_string(h,mptr->hint);
		put_string(h,mptr->service);
		put_string(h,mptr->iname);

		put_word(h,mptr->x);
		put_word(h,mptr->y);
		put_word(h,mptr->w);
		put_word(h,mptr->h);

		put_word(h,mptr->language);
		put_word(h,mptr->font);
		put_word(h,mptr->style);
		put_word(h,mptr->nature);

		put_string(h,mptr->dependance );
		put_word(h,mptr->doctool);
		put_string(h,mptr->document );

		for (	optr=mptr->first;
			optr != (struct menu_option *) 0;
			optr = optr->next ) {

			put_word(h,1);
			put_string(h,optr->label);
			put_string(h,optr->hint);
			put_string(h,optr->service);
			put_string(h,optr->linkage);
			put_word(h,optr->hotkey);
			put_word(h,optr->result);
			put_word(h,optr->state);
			put_word(h,optr->x);
			put_word(h,optr->y);
			put_word(h,optr->w);
			put_word(h,optr->h);
			put_word(h,optr->doctool);
			put_string(h,optr->document );
			}


		put_word(h,0);
		put_word(h,0);
		put_word(h,0);
		put_word(h,0);
		put_word(h,0);


		close_production_target( h, mptr->loadname );

		if (!( automatic ))
			draw_console();


		}
	return(0);
}

public	void			draw_Menu(struct menu_control * mptr)
{
	struct 	menu_option * optr;
	int	fh,fw,f;
	int	maxw=0;
	int	totw=0;
	int	totm=0;
	int	l;
	/* we need a menu and a font */
	if (!( mptr ))			return;
	else if (!( f = mptr->font ))	return;

	fh = guifontsize(f);	
	fw = (fh & 0x00FF);
	fh >>= 8;	
	fh &= 0x00FF;

	/* calculate widths */
	/* ---------------- */
	for ( 	maxw=0,totw=0,totm=0,optr=mptr->first; 
		optr != (struct menu_option *) 0; 
		optr = optr->next, totm++ ) {
		if (!( optr->label ))
			continue;
		else if ((l= strlen(optr->label)) > maxw)
			maxw = l;
		if ( mptr->nature & 1 ) {
			optr->x = fw;
			optr->y = ((totm+1)*fh);
			optr->w = (totw*fw);
			optr->h = fh;
			}
		else	{
			optr->x = ((totw+1)*fw);
			optr->y = fh;
			optr->w = (totw*fw);
			optr->h = fh;
			}

		totw += (l+2);
		}
		 
	mptr->maxwidth = maxw;

	if ( mptr->nature & 1 ) {
		/* vertical */
		mptr->w = ((maxw+2)*fw);
		mptr->h = ((totm+2)*fh);
		menu(	Context.DeskTop.x+mptr->x, 
			Context.DeskTop.y+mptr->y,
			mptr->w,mptr->h, 2 );
		}
	else	{
		mptr->w = ((totw+2) * fw);
		mptr->h = (fh*3);
		menu(	Context.DeskTop.x+mptr->x, 
			Context.DeskTop.y+mptr->y,
			mptr->w,mptr->h, 1 );
		}


	for ( 	optr=mptr->first; 
		optr != (struct menu_option *) 0; 
		optr = optr->next ) {
		if (!( optr->label ))
			continue;
		else	option(	Context.DeskTop.x+mptr->x+optr->x,
				Context.DeskTop.y+mptr->y+optr->y,
				mptr->font,
				optr->label,
				( mptr->nature & 1 ? maxw : strlen(optr->label) ),
				0,0);

		}
	return;
}

private	void		edit_MenuProperties(struct menu_control * mptr)
{
	int	status;
	if (!( mptr ))
		return;

	status  = accept_menu_properties(
		&mptr->loadname,
		&mptr->identifier,
		&mptr->x,
		&mptr->y,
		&mptr->service,
		&mptr->nature,
		&mptr->hint,
		&mptr->prodname,
		&mptr->language,
		&mptr->font,
		&mptr->style
		);
	return;
}

private	void			edit_MenuOption(struct menu_control * mptr)
{
	int	status;
	struct 	menu_option * optr;
	if ((!( mptr ))
	||  (!(optr= mptr->current )))
		return;
	status  = option_properties(
		&optr->x,
		&optr->y,
		&optr->label,
		&optr->hint,
		&optr->service,
		&optr->linkage,
		&optr->result,
		&optr->hotkey
		);
	return;
}

private	void			add_MenuOption(struct menu_control * mptr)
{
	struct 	menu_option * optr;
	if (!( mptr ))
		return;
	if (!( optr = allocate_Option() ))
		return;
	else if (!( optr->label = allocate_string( "new" ) )) {
		(void) liberate_Option( optr );
		return;
		}
	else	{
		add_new_option(mptr, optr);
		return;
		}
}

private	void			drop_MenuOption(struct menu_control * mptr)
{
	if ((!( mptr ))
	||  (!( mptr->current )))
	return;
}

private	void	show_MenuOption( struct menu_control * mptr )
{
	struct 	menu_option * optr;
	if (!( mptr ))
		return;
	else if (!( optr = mptr->current ))
		return;
	else if (!( optr->label ))
		return;
	else	{
		option(	Context.DeskTop.x+mptr->x+optr->x,
			Context.DeskTop.y+mptr->y+optr->y,
			mptr->font,
			optr->label,
			( mptr->nature & 1 ? mptr->maxwidth : strlen(optr->label) ),
			2,0);
		return;
		}

}

private	void	hide_MenuOption( struct menu_control * mptr )
{
	struct 	menu_option * optr;
	if (!( mptr ))
		return;
	else if (!( optr = mptr->current ))
		return;
	else if (!( optr->label ))
		return;
	else	{
		option(	Context.DeskTop.x+mptr->x+optr->x,
			Context.DeskTop.y+mptr->y+optr->y,
			mptr->font,
			optr->label,
			( mptr->nature & 1 ? mptr->maxwidth : strlen(optr->label) ),
			0,0);
		return;
		}
}

public	int 	edit_Menu( struct menu_control ** mmptr, int mode )
{
	struct	menu_control * mptr;
	int	event;
	if (!( mmptr ))
		return(0);
	else	mptr = *mmptr;

	if ((!( mptr ))
	&&  (!( mptr = allocate_Menu((char *) 0) )))
		return( 0 );
	else	{
		Context.Menu = mptr;	
		use_menu_tools();
		add_menu_menu();
		draw_console();
		}


	while (1) {

		show_MenuOption(mptr);
		while (((event = mimo_getch())   == 256)
		&&     ((event = handle_event()) == 256));
		hide_MenuOption(mptr);

		switch ( event ) {

			case	_EDIT_GRAPH	:
				menu_Image(mptr);
				break;

			case	_EVENT_ITEMDOC 		:
				if (!( mptr->current ))
					continue;
				else	{
					visual_text_editor( & mptr->current->document );
					draw_console();
					continue;
					}

			case	_EVENT_FORMDOC		:
				visual_text_editor( & mptr->document );
				draw_console();
				continue;

			case	__MENU_SEPARATOR	:
			case	__MENU_OPTION		:
			case	CTRL_A			:
				add_MenuOption(mptr);
				draw_console();
				continue;

			case	0x007F			:
				drop_MenuOption(mptr);
				draw_console();
				continue;

			case	_EDIT_PROPERTIES	:
			case	CTRL_I			:
				edit_MenuOption(mptr);
				draw_console();
				continue;

			case	__MENU_PROPERTIES 	:
				edit_MenuProperties(mptr);
				draw_console();
				continue;

			case	_FILE_PRODUCE	:
				export_Menu(mptr,0);
				draw_console();
				continue;

			case	_FILE_COMPARE	:
				compare_Files(mptr->prodname,(char *) 0);
				draw_console();
				continue;

			case	_FILE_SAVE		:
				save_Menu(mptr,0);
				draw_console();
				continue;

			case	_FILE_LOAD		:
				mptr = load_Menu(mptr->prodname,0);
				draw_console();
				continue;

			case	_LEAVE_SING		:
				break;

			case	_FIRST_ITEM	:
				mptr->current = mptr->first;
				draw_console();
				continue;

			case	11		:
			case	_PREVIOUS_ITEM	:
				if ( mptr->current->previous ) {
					mptr->current = mptr->current->previous;
					draw_console();
					}
				continue;

			case	5		:
			case	_NEXT_ITEM	:
				if ( mptr->current->next ) {
					mptr->current = mptr->current->next;
					draw_console();
					}
				continue;

			case	_LAST_ITEM	:
				mptr->current = mptr->last;
				draw_console();
				continue;

			default				:
				continue;
			}
		break;
		}

	Context.Menu = (struct menu_control *) 0;
	drop_menu_menu();
	drop_tool_manager();
	*mmptr = mptr;
	return(event);
}

public	int	document_Menu( 
			FILE * handle,
			struct menu_control * mptr,
			int automatic , int report
			)
{
	struct menu_option * optr;

	if ( mptr->document )
		html_paragraph( handle, mptr->document );

	for ( 	optr=mptr->first; 
		optr != (struct menu_option *) 0; 
		optr = optr->next ) {

		if ( optr->document )
			html_paragraph( handle,optr->document );

		}

	return(1);
}

public	int	select_TreeMenu( struct menu_control * mptr )
{
	select_TreeHost( mptr->host );
	return(0);
}

#endif	/* _menu3d_c */

