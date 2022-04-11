#ifndef	_wsup_c
#define	_wsup_c

public	int	wsup(int h)
{
	struct	asfun_window * wptr;
	if (!( wptr = Control.windows[(h-1)] ))
		return(2);
	else	{
		if ( Control.implicite == h )
			Control.implicite = 0;
		if ( Control.active == h )
			Control.active = 0;
		Control.windows[(h-1)] = remove_window( wptr );
		show_windows();
		return(0);
		}
}

/* ----------- */
/* 2: %wsup(%) */
/* ----------- */
private EXAWORD Dll_wsup( VOID FAR PTR FAR pptr[] )
{
	int	h;
	if (!( fen_ini	))	{ return(3); }
	h = LdfParaWord(0);
	if ((h <= 0) || ( h >= _MAX_WINDOWS))
		return(2);
	else	{
		if ( bedug ) { 	printf("wsup(%u)\r\n",h); }
		return( wsup(h) );
		}
}

#endif	/* _wsup_c */
	/* ------- */

