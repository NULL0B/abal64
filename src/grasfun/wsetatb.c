#ifndef	_wsetatb_c
#define	_wsetatb_c

public	int	wsetatb(int h, int a, int fg, int bg, int atx, int aty, int nbc, int nbl )
{
	struct	asfun_window * wptr;
	if (!( wptr = Control.windows[(h-1)] ))
		return(2);
	else	{
		return(0);
		}
}

/* ---------------------------- */
/* 13:%wsetatb(%,#,#,#,%,%,%,%) */
/* ---------------------------- */
private EXAWORD Dll_wsetatb( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{ return(3); }
	else			{ return(wsetatb(LdfParaWord(0),0,0,0,0,0,0,0)); }
}

#endif	/* _wsetatb_c */
	/* ---------- */










