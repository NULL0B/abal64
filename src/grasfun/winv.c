#ifndef	_winv_c
#define	_winv_c

public	int	winv(int h)
{
	struct	asfun_window * wptr;
	if (!( wptr = Control.windows[(h-1)] ))
		return(2);
	else if (!( wptr->visible ))
		return(0);
	else	{
		wptr->visible=0;
		show_windows();
		return(0);
		}
}

/* ----------- */
/* 5: %winv(%) */
/* ----------- */
private EXAWORD Dll_winv( VOID FAR PTR FAR pptr[] )
{
	struct	asfun_window * wptr;
	int	h;
	if (!( fen_ini	))	{ return(3); }
	h = LdfParaWord(0);
	if ((h <= 0) || ( h >= _MAX_WINDOWS))
		return(2);
	else	{
		if ( bedug ) { printf("winv(%u)\r\n",h); }
		return( winv(h) );
		}
}

#endif	/* _winv_c */
	/* ------- */



