#ifndef	_asfun_menu_c
#define	_asfun_menu_c

struct	asfun_option * 	remove_option(struct asfun_option * optr)
{
	if ( optr ) {
		liberate( optr );
		}
	return(( struct asfun_option * ) 0 );
}

struct	asfun_option * 	create_option(int style)
{
	struct asfun_option * optr;
	if (!( optr = allocate( sizeof( struct asfun_option ) ) ))
		return(optr);
	else	{
		memset(optr->value,32,_MAX_VALUE);
		optr->vlen	= 0;
		memset(optr->comment,32,_MAX_COMMENT);
		optr->clen	= 0;
		optr->slen	= 0;
		optr->x		= 
		optr->y		= 
		optr->w   	= 
		optr->h   	= 0;
		optr->grx	=
		optr->gry	= 
		optr->grw   	= 
		optr->grh   	= 0;
		optr->state	= 0;
		optr->style	= 0;
		optr->trigger	= 0;
		optr->menu	= 0;
		optr->option	= 0;
		optr->nature 	= style;
		return(optr);
		}

}

struct	asfun_menu * 	remove_menu(struct asfun_menu * mptr)
{
	int	i;
	if (mptr) {
		for (i=0; i < _MAX_OPTIONS; i++ )
			mptr->option[i] = remove_option( mptr->option[i] );
		if ((i = mptr->window) != 0) {
			mptr->window = 0;
			wsup( i );
			}
		liberate(mptr);
		}
	return( (struct	asfun_menu *) 0);
}

struct	asfun_menu *	create_menu()
{
	int	i;
	struct	asfun_menu * mptr;

	if (!( mptr = allocate( sizeof( struct asfun_menu ) ) ))
		return(mptr);
	else	{
		mptr->window=0;
		mptr->number=0;
		mptr->type=0;		/* H or V */
		mptr->escape=0;		/* escape type 1 .... 5 */
		mptr->options=0;
		mptr->lenopt=0;
		mptr->width=0;
		mptr->lencom=0;
		for (i=0; i < _MAX_OPTIONS; i++ ) { mptr->option[i] = (struct asfun_option *) 0; }
		return(mptr);
		}
}

public	void	show_option( struct asfun_option * optr )
{
	int	grx;
	int	gry;
	int	grw;
	int	grh;
	int	l,n;
	int	vl;
	if (!( optr )) 
		return;
	if ((vl = optr->vlen) > optr->slen)
		vl = optr->slen;
	for (l=0,n=0; n < vl; n++ )
		if ( optr->value[n] != ' ' )
			l = (n+1);

	if ( optr->option & _OPTION_BLANK )
		return;
	else if ( optr->option & _OPTION_SEPARATE ) {
		sprintf(asfun_stylename,"asfun/menu_separator%u",optr->nature );
		visual_element(	
			optr->grx,optr->gry,optr->grw,optr->grh,
			asfun_stylename," ",0);
		}
	else if ( optr->state ) {
		sprintf(asfun_stylename,"asfun/focus_menu_option%u",optr->nature );
		visual_element(	
			optr->grx,optr->gry,optr->grw,optr->grh,
			asfun_stylename,optr->value,l 
			);
		sl_message(1,optr->clen,optr->comment);
		}
	else if ( optr->option & _OPTION_SHADED ) {
		sprintf(asfun_stylename,"asfun/shaded_menu_option%u",optr->nature );
		visual_element(	
			optr->grx,optr->gry,optr->grw,optr->grh,
			asfun_stylename,optr->value,l
			);
		}
	else	{
		sprintf(asfun_stylename,"asfun/menu_option%u",optr->nature );
		visual_element(	
			optr->grx,optr->gry,optr->grw,optr->grh,
			asfun_stylename,optr->value,l
			);
		}
	return;
}

public	void	show_menu( struct asfun_menu * mptr )
{
	int	i;
	struct	asfun_window * wptr;
	if (!( mptr ))
		return;
	else if (!( mptr->window ))
		return;
	else if (!( wptr = Control.windows[(mptr->window-1)] ))
		return;
	else	{
		wimpl(0);
		hide();
		wvis(mptr->window);
		for (i=0; i < mptr->options; i++)
			show_option(  mptr->option[i] );
		show(wptr->grx,wptr->gry,wptr->grw,wptr->grh);
		return;
		}
}

public	void	menu_getfocus( struct asfun_menu * mptr, int option )
{
	struct asfun_option * optr;
	if (!( mptr ))
		return;
	if (!( option ))
		return;
	else if (option > mptr->options )
		return;
	else if (!( optr = mptr->option[(option-1)]))
		return;
	else	{
		optr->state = 1;
		show_menu(mptr);
		return;
		}
}

public	void	menu_losefocus( struct asfun_menu * mptr, int option )
{
	struct asfun_option * optr;
	if (!( mptr ))
		return;
	if (!( option ))
		return;
	else if (option > mptr->options )
		return;
	else if (!( optr = mptr->option[(option-1)]))
		return;
	else	{
		optr->state = 0;
		show_menu(mptr);
		return;
		}
}

public	void	hide_menu( struct asfun_menu * mptr )
{
	int	i;
	if (!( mptr ))
		return;
	else	{
		winv(mptr->window);
		return;
		}
}

public	int	is_invalid_menu_option( struct asfun_menu * mptr, int optid )
{
	struct	asfun_option * optr;
	if (!( optid ))
		return(1);
	else if ( optid > mptr->options )
		return(1);
	else if (!(optr = mptr->option[(optid-1)]))
		return(1);
	else if ( optr->option & _OPTION_BLANK )
		return(1);
	else if ( optr->option & _OPTION_SEPARATE )
		return(1);
	else	return(0);
}

public	int	is_menu_event(  struct asfun_menu * mptr, int * optid )
{
	struct	asfun_option * optr;
	struct	asfun_window * wptr;
	int	mc,ml,mb,mt;
	int	i;

	if (!( mptr->window ))
		return(0);
	else if (!( wptr = Control.windows[(mptr->window-1)] ))
		return(0);
	else	{
		mt = x_event(1); mb = x_event(2);
		ml = x_event(3); mc = x_event(4);
		if (( ml <  wptr->y )
		&&  ( mc <  wptr->x )
		&&  ( ml >= (wptr->y+wptr->h))
		&&  ( ml >= (wptr->x+wptr->w)))
			return(0);
		for (	i=0; i < mptr->options; i++ ) {
			if (!( optr = mptr->option[i] ))
				continue;
			if (( ml == optr->y )
			&&  ( mc >= optr->x )
			&&  ( mc <  (optr->x+optr->w))) {
				*optid = (i+1);
				return(mt);
				}
			}
		return(0);
		}
}



#endif	/* _asfun_menu_c */
	/* ------------- */


