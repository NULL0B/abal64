#ifndef	_wfend_c
#define	_wfend_c

public	int	wend()
{
	int	i;
	if ( Control.status ) {
		if ( bedug )
			printf("wfend()\r\n");
		if ( Control.mode ) {
			liberatepixel();
			Control.mode = 0;
			}
		Control.implicite = Control.active = 0;
		for (i=0; i < _MAX_WINDOWS; i++ )
			remove_window( Control.windows[i] );
		terminate_style();
		Control.status = 0;
		fen_ini = 0;
		}
	return(0);
}

/* ----------- */
/* 12:%wfend() */
/* ----------- */
private EXAWORD Dll_wfend( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{ return(3); 		}
	else			{ return( wend() );	}
}

#endif	/* _wfend_c */
	/* -------- */

