#ifndef	_watcb_c
#define	_watb_c

public	int	watb(int h, int a, int fg, int bg )
{
	struct	asfun_window * wptr;

	if (!( wptr = Control.windows[(h-1)] ))
		return(2);
	else	{
		wptr->atb = a;
		wptr->fg  = fg;
		wptr->bg  = bg;
		if ((wptr->visible) && (!( wptr->frozen )))
			window_paint(wptr);
		return(0);
		}
}

/* ----------------- */
/* 8: %watb(%,#,#,#) */
/* ----------------- */
private EXAWORD Dll_watb( VOID FAR PTR FAR pptr[] )
{
	int	h;
	if (!( fen_ini	))	{ return(3); }
	h = LdfParaWord(0);
	if ((h <= 0) || ( h >= _MAX_WINDOWS))
		return(2);
	else	{
		if ( bedug ) {
			printf("watb(%u)\r\n",h);
			}
		return( watb( h, LdfParaWord(1), LdfParaWord(2), LdfParaWord(3) ));
		}
}


#endif	/* _watb_c */
	/* ------- */

