#ifndef	_wgel_c
#define	_wgel_c

public	int	wgel(int h )
{
	struct	asfun_window * wptr;
	if (!( wptr = Control.windows[(h-1)] ))
		return(2);
	else	{
		wptr->frozen=1;
		return(0);
		}
}

/* ----------- */
/* 11:%wgel(%) */
/* ----------- */
private EXAWORD Dll_wgel( VOID FAR PTR FAR pptr[] )
{
	int	h;
	if (!( fen_ini	))	{ return(3); }
	h = LdfParaWord(0);
	if ((h <= 0) || ( h >= _MAX_WINDOWS))
		return(2);
	else	{
		if ( bedug ) { printf("wgel(%u)\r\n",h); }
		return( wgel(h) );
		}
}

#endif	/* _wgel_c */
	/* ------- */




