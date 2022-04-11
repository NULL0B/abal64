#ifndef	_wselect_c
#define	_wselect_c

public	int	wselect( int h )
{
	struct	asfun_window * wptr;
	if (!( wptr = Control.windows[(h-1)] ))
		return(2);
	else	{
		wptr->frozen=0;
		Control.active=h;
		show_windows();
		return(0);
		}
}

/* -------------- */
/* 4: %wselect(%) */
/* -------------- */
private EXAWORD Dll_wselect( VOID FAR PTR FAR pptr[] )
{
	struct	asfun_window * wptr;
	int	h;
	if (!( fen_ini	))	{ return(3); }
	h = LdfParaWord(0);
	if ((h <= 0) || ( h >= _MAX_WINDOWS))
		return(2);
	else	{
		if ( bedug ) { printf("wselect(%u)\r\n",h); }
		return( wselect( h ) );
		}
}

#endif	/* _wselect_c */
	/* ---------- */


