#ifndef	_wimpl_c
#define	_wimpl_c

public	int	wimpl(int h)
{
	struct	asfun_window * wptr;
	int	status;

	if ( h == 0 ) {

		/* Cancel current implicite window */
		/* ------------------------------- */
		if (!(h = Control.implicite ))
			return(0);
		else 	{
			if (!( wptr = Control.windows[(h-1)] ))
				return(4);
			else	{
				wptr->implicite=0;
				clear_implicite_window();
				Control.implicite = 0;
				return(0);
				}
			}
		}
	else if (!( wptr = Control.windows[(h-1)] ))
		return(2);
	else if (!( status = implicite_window((h - 1) ) )) {
		wptr->implicite=1;
		Control.implicite=h;
		}
	return(status);
}

/* ------------ */
/* 10:%wimpl(%) */
/* ------------ */
private EXAWORD Dll_wimpl( VOID FAR PTR FAR pptr[] )
{
	int	h;
	if (!( fen_ini	))	{ return(3); }
	h = LdfParaWord(0);
	if ((h < 0) || ( h >= _MAX_WINDOWS))
		return(2);
	else	{
		if ( bedug ) { 	printf("wimpl(%u)\r\n",h); }
		return( wimpl( h ) );
		}
}

#endif	/* _wimpl_c */
	/* -------- */

