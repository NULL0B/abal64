#ifndef	_wfgen_c
#define	_wfgen_c

public	int	wfgen(int h, int f)
{
	struct	asfun_window * wptr;
	
	if (!( wptr = Control.windows[(h-1)] ))
		return(2);
	else	{
		switch ( f ) {
			case	1 : wclear(wptr,h); return(0);
			case	2 : wcleos(wptr,h); return(0);
			case	3 : wcleol(wptr,h); return(0);
			case	4 : winsln(wptr,h); return(0);
			case	5 : wdelln(wptr,h); return(0);
			case	6 : wscrup(wptr,h); return(0);
			case	7 : wscrdw(wptr,h); return(0);
			case	8 : winsrg(wptr,h); return(0);
			case	9 : winslf(wptr,h); return(0);
			case	10: wcuron(wptr,h); return(0);
			case	11: wcurof(wptr,h); return(0);
			case	12: winsch(wptr,h); return(0);
			case	13: wdelch(wptr,h); return(0);
			default	  :		  return(4);
			}
		}
}

/* -------------- */
/* 7: %wfgen(%,%) */
/* -------------- */
private EXAWORD Dll_wfgen( VOID FAR PTR FAR pptr[] )
{
	int	h;
	if (!( fen_ini	))	{ return(3); }
	h = LdfParaWord(0);
	if ((h <= 0) || ( h >= _MAX_WINDOWS))
		return(2);
	else	{
		if ( bedug ) { printf("wfgen(%u)\r\n"); }
		return( wfgen(h,LdfParaWord(1)) );
		}
}

#endif	/* _wfgen_c */
	/* -------- */

