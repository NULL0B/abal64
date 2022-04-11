#ifndef	_wposcur_c
#define	_wposcur_c

/* ------------------ */
/* 9: %wposcur(%,%,%) */
/* ------------------ */
public	int	wposcur( int h, int atlin, int atcol )
{
	struct	asfun_window * wptr;
	if (!( wptr = Control.windows[(h-1)] ))
		return(2);
	else	{
		wptr->atcol = atcol;
		wptr->atlin = atlin;
		if ( bedug )
			printf("wposcur(%u,%u,%u)\r\n",h,wptr->atcol,wptr->atlin);
		if (( wptr->implicite ) && ( wptr->visible ) && (!( wptr->frozen )))
			window_pos( wptr );
		return(0);
		}
}

private EXAWORD Dll_wposcur( VOID FAR PTR FAR pptr[] )
{
	int	h;
	if (!( fen_ini	))	{ return(3); }
	h = LdfParaWord(0);
	if ((h <= 0) || ( h >= _MAX_WINDOWS))
		return(2);
	else	return( wposcur( h, LdfParaWord(2), LdfParaWord(1) ));
}

#endif	/* _wposcur_c */
	/* ---------- */

