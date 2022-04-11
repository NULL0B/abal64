#ifndef	_wwrite_c
#define	_wwrite_c

public	int	wwrite(int h, int mlen, char * mptr )
{
	struct	asfun_window * wptr;
	if (!( wptr = Control.windows[(h-1)] ))
		return(2);
	else	{
		implicite_window(h-1);
		for ( ; mlen > 0; mlen-- )
			v_putch( *(mptr++) & 0x00FF );
		clear_implicite_window();
		use_implicite_window();
		return(0);
		}
}

/* ----------------- */
/* 3: %wwrite(%,%,$) */
/* ----------------- */
private EXAWORD Dll_wwrite( VOID FAR PTR FAR pptr[] )
{
	int	mlen;
	char *	mptr;
	int	h;
	if (!( fen_ini	))	{ return(3); }
	h = LdfParaWord(0);
	if ((h <= 0) || ( h >= _MAX_WINDOWS))
		return(2);
	else	{
		mlen = LdfParaWord(1);
		mptr = LdfParaPtr(2);
		if ( bedug ) { 
			printf("wwrite(%u,%u)\r\n",h,mlen);
			}
		return( wwrite( h, mlen, mptr ) );
		}
}

#endif	/* _wwrite_c */
	/* --------- */

