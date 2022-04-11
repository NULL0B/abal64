#ifndef	_mduse_c
#define	_mduse_c

public	EXAWORD	md_use(int mid, int optid, char * menchx, char * optchx, char * optval, char *optexit, int nesting);

public	EXAWORD	ll_md_use(int mid, int optid, char * menchx, char * optchx, char * optval, char *optexit, int nesting)
{
	EXAWORD	status=0;
	int	event;
	int	i;
	struct	asfun_menu *	mptr;
	struct	asfun_option *	optr;
	if (!( mid )) {
		if ( Control.nested[nesting] != 0 ) {
			if (!(mptr = Control.menus[(Control.nested[nesting]-1)]))
				return(40);
			else if (!( optid = Control.choice[nesting] ))
				return(1);
			}	
		else	return(1);
		}
	else	{
		if ((mid == 0) || (mid > _MAX_MENUS))
			return(1);
		else if (!(mptr = Control.menus[(mid-1)]))
			return(40);
		}
	if (( optid == 0 ) || ( optid > mptr->options ))
		return(1);
	else 	{
		show_menu( mptr );
		if (!( mid )) {
			mid = Control.nested[nesting];
			if ( Control.nested[(nesting+1)] ) {
				switch ((status = md_use( 0, 0, menchx,optchx, optval, optexit,(nesting+1) ))) {
					case	_ESC_CLEAR_ALL	:
						md_inv(mid);
					case	_ESC_NO_CLEAR	:
						if (!( nesting ))
							return(0);
						else	return( status );
					case	_ESC_TO_TOP	:
						if ( nesting ) { return(status ); }
					case	_ESC_ONE_LEVEL	:
						break;
					case	0 :
						/* Selection Performed */
						/* ------------------- */
						if ( *optchx )  
							return(0); 
					default	:
						break;
					}
				}
			}
		Control.nested[nesting] = mid;
		while (1) {
			menu_getfocus(mptr,optid);
			event = x_getch();
			menu_losefocus(mptr,optid);
			switch ( event ) {

				case	27 :
					/* Escape Key Inhibited */
					/* -------------------- */
					if ( mptr->escape == _ESC_INHIBITED )
						continue;

					/* Prepare Escape Return */
					/* --------------------- */
					*menchx = mid;	*optchx = 0;
					
					/* Escape to program leaving menus */
					/* ------------------------------- */
					if (mptr->escape == _ESC_NO_CLEAR ) {
						if (!( nesting ))
							return(0);
						else	return( mptr->escape );
						}
					else	{
						md_inv(mid);
						}
					/* Top level will exit */
					/* ------------------- */
					if (!( nesting )) 
						return(0);
					else	return( mptr->escape );

				case	 8 :
					if ( mptr->type == _HMENU ) {
						do	{
							if ( optid > 1 )
								optid--;
							else	optid = mptr->options;
							}
						while (is_invalid_menu_option(mptr,optid));
						}
					continue;
				case	 6 :
					if ( mptr->type == _HMENU ) {
						do	{	
							if ( optid < mptr->options )
								optid++;
							else	optid = 1;
							}
						while (is_invalid_menu_option(mptr,optid));
						}
					continue;
				case	 5 :
					if ( mptr->type == _VMENU ) {
						do	{
							if ( optid < mptr->options )
								optid++;
							else	optid = 1;
							}
						while (is_invalid_menu_option(mptr,optid));
						}
					continue;
				case	11 :
					if ( mptr->type == _VMENU ) {
						do	{
							if ( optid > 1 )
								optid--;
							else	optid = mptr->options;
							}
						while (is_invalid_menu_option(mptr,optid));
						}
					continue;
				case    13 :
				default	   :
				case   256 :
					if (  event == 256 ) {
						if ( is_menu_event(mptr,&optid) != 32 )
							continue;
						}
					else if ( event != 13 ) {
						for (i=0; i < mptr->options; i++ ) {
							if (!( optr = mptr->option[i] ))
								continue;
							else if ( optr->trigger == event )
								break;
							}
						if ( i < mptr->options )
							optid = (i+1);
						else	continue;
						}

					if (!( optr = mptr->option[(optid-1)] ))
						continue;

					else if ( optr->menu ) {
						Control.choice[nesting] = optid;
						switch ((status = md_use( optr->menu, optr->option, menchx,optchx, optval, optexit,(nesting+1) ))) {
							case	_ESC_CLEAR_ALL	:
								md_inv(mid);
							case	_ESC_NO_CLEAR	:
								if (!( nesting ))
									return(0);
								else	return( status );
							case	_ESC_TO_TOP	:
								if ( nesting ) { return(status ); }
							case	_ESC_ONE_LEVEL	:
								continue;
							case	0 :
								/* Selection Performed */
								/* ------------------- */
								if ( *optchx )  
									return(0); 
							default	:
								continue;
							}
						}
					else	{
						/* Menu Option Selection */
						/* --------------------- */
						*menchx = mid;
						*optchx = optid;
						Control.choice[nesting] = optid;
						for (i=0; i < mptr->lenopt; i++) {
							if ( optr->value[i] == '&' )
								continue;
							else	*(optval++) = optr->value[i];
							}
						return(md_choice(optr,nesting));
						}
				}
			}
		}
	return(0);
}

private	void	clear_menu_path(int mid, int optid)
{
	int	i;

	if (!( mid ))
		return;
	else	{
		for (i=0; i < 16; i++ ) {
			if (!( Control.nested[i] ))
				break;
			else if ( Control.nested[i] == mid ) {
				memset(Control.nested,0,16);
				memset(Control.choice,0,16);
				break;
				}
			}
		return;
		}
}

public	EXAWORD	md_use(int mid, int optid, char * menchx, char * optchx, char * optval, char *optexit, int nesting)
{
	int	status;
	clear_implicite_window();
	status = ll_md_use( mid,optid,menchx,optchx,optval,optexit, nesting );
	use_implicite_window();
	return( status );
}

public	EXAWORD	enter_md_use(int mid, int optid, char * menchx, char * optchx, char * optval, char *optexit, int nesting)
{
	clear_menu_path(mid,optid);
	return( md_use( mid,optid,menchx,optchx,optval,optexit, nesting ) );
}

#endif	/* _mduse_c */
	/* -------- */

