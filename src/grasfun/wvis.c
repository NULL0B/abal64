
#ifndef	_wvis_c
#define	_wvis_c

public	int	wvis(int h)
{
	struct	asfun_window * wptr;
	if (!( wptr = Control.windows[(h-1)] ))
		return(2);
	else	{
		wptr->frozen=0;
		wptr->visible=1;
		clear_implicite_window();
		draw_window(wptr);
		use_implicite_window();
		return(0);
		}
}

/* ----------- */
/* 6: %wvis(%) */
/* ----------- */
private EXAWORD Dll_wvis( VOID FAR PTR FAR pptr[] )
{
	struct	asfun_window * wptr;
	int	h;
	if (!( fen_ini	))	{ return(3); }
	h = LdfParaWord(0);
	if ((h <= 0) || ( h >= _MAX_WINDOWS))
		return(2);
	else	{
		if ( bedug ) { printf("wvis(%u)\r\n",h); }
		return( wvis(h) );
		}
}

#endif	/* _wvis_c */
	/* ------- */

