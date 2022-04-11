#ifndef	_wcreat_c
#define	_wcreat_c

public	int	next_free_window()
{
	int	wid;
	for (wid=0; wid < _MAX_WINDOWS; wid++)
		if (!( Control.windows[wid] ))
			break;
	return(wid);
}

public	void	use_window_control( struct asfun_window * wptr )
{
	if (( wptr->control & CAD3 ) == CAD3) {
		wptr->border=3;
		}
	else if (( wptr->control & CAD1 ) == CAD1) {
		wptr->border=1;
		}
	else if (( wptr->control & CAD2 ) == CAD2) {
		wptr->border=2;
		}
	else	wptr->border=0;

	if (!( wptr->control & INVISIBLE ))
		wptr->visible=1;
	else	wptr->visible=0;

	if ( wptr->control & SCROLL )
		wptr->scroll=1;
	else	wptr->scroll=0;

	if ( wptr->control & CURSEUR )
		wptr->cursor=1;
	else	wptr->cursor=0;

	if ( wptr->control & OMBRE )
		wptr->shadow=1;
	else	wptr->shadow=0;
	return;
}

/* ------------------ */
/* 1: %wcreat(%? , $) */
/* ------------------ */
private EXAWORD Dll_wcreat( VOID FAR PTR FAR pptr[] )
{
	char *	wb;
	int	i;
	int	wid;
	struct	asfun_window * wptr;
	if (!( fen_ini	))	{ return(3); }
	
	if ((wid = next_free_window()) >= _MAX_WINDOWS)
		return(4);
	else if (!( wptr = create_window()))
		return(27);
	else	{
		wb = pptr[1];
		if ( GetInt16( wb ) != 0 ) { return(1); }
		wptr->y =  GetInt16( & wb[Bpos_lig] );	
		wptr->x =  GetInt16( & wb[Bpos_col] );
	
		wptr->h  =	 GetInt16( & wb[Bnb_lig]  );	
		wptr->w  =	 GetInt16( & wb[Bnb_col]  );

		wptr->atb	= wb[Batb_vid];
		if (!( wptr->fg	= wb[Batbcol_text]))	
			wptr->fg = 16;
		if (!( wptr->bg	= wb[Batbcol_fond]))
			wptr->bg = 16;

		wptr->control	=  GetInt16( & wb[Bcontrol] ); 
		wptr->lentit	=  GetInt16( & wb[Bln_tit]  );
	
		for (i=0; i< _MAX_TITLE; ++i) { wptr->titre[i] = wb[Btitre+i]; }

		for (i=0; i< _MAX_CADRE; ++i) { wptr->frame[i] = wb[Bcad_usr+i]; }

		wptr->fratb	= wb[Bcad_atb];
		wptr->frfg	= wb[Bcad_text];
		wptr->frbg	= wb[Bcad_fond];

		use_window_control( wptr );

		/* control dimensions */
		if ( i > 2 ) {
			if (((( wptr->x+wptr->w-1 ) + ( wptr->border ? 2 : 0 )) > Control.nbc )
			||  ((( wptr->y+wptr->h-1 ) + ( wptr->border ? 2 : 0 )) > Control.nbl )) {
				remove_window( wptr );
				return(1);
				}
			}
		if (!( allocate_window(wptr) )) {
			remove_window( wptr );
			return(27);			
			}
		else	{
			Control.windows[wid] = wptr;
			if ( wptr->visible ) { show_windows(); }
			wid++;
			if ( bedug ) {
				printf("wcreat(%u)\r\n",wid);
				}
			PutInt16( pptr[0], wid);
			return(0);
			}
		}
}

public	EXAWORD	wcreatc(WPTR r, WDESC_APP_PTR wa )
{
	int	i;
	int	wid;
	struct	asfun_window * wptr;
	if (!( fen_ini	))	{ return(3); }
	if ((wid = next_free_window()) >= _MAX_WINDOWS)
		return(4);
	else if (!( wptr = create_window()))
		return(27);
	else	{
		wptr->y =  wa->Apos_lig;	
		wptr->x =  wa->Apos_col;
	
		wptr->h  =	 wa->Anb_lig;	
		wptr->w  =	 wa->Anb_col;

		wptr->atb	= wa->Aatb_vid;
		if (!( wptr->fg	= wa->Aatbcol_text))	
			wptr->fg = 16;
		if (!( wptr->bg	= wa->Aatbcol_fond))
			wptr->bg = 16;

		wptr->control	=  wa->Acontrol; 
		wptr->lentit	=  wa->Aln_tit;
	
		for (i=0; i< _MAX_TITLE; ++i) { wptr->titre[i] = wa->Atitre[i]; }

		for (i=0; i< _MAX_CADRE; ++i) { wptr->frame[i] = wa->Acad_usr[i]; }

		wptr->fratb	= wa->Acad_atb;
		wptr->frfg	= wa->Acad_text;
		wptr->frbg	= wa->Acad_fond;

		if (( wptr->control & CAD3 ) == CAD3) {
			wptr->border=3;
			}
		else if (( wptr->control & CAD1 ) == CAD1) {
			wptr->border=1;
			}
		else if (( wptr->control & CAD2 ) == CAD2) {
			wptr->border=2;
			}
		else	wptr->border=0;

		if (!( wptr->control & INVISIBLE ))
			wptr->visible=1;
		else	wptr->visible=0;

		if ( wptr->control & SCROLL )
			wptr->scroll=1;
		else	wptr->scroll=0;

		if ( wptr->control & CURSEUR )
			wptr->cursor=1;
		else	wptr->cursor=0;

		if ( wptr->control & OMBRE )
			wptr->shadow=1;
		else	wptr->shadow=0;

		/* control dimensions */
		if (((( wptr->x+wptr->w-1 ) + ( wptr->border ? 2 : 0 )) > Control.nbc )
		||  ((( wptr->y+wptr->h-1 ) + ( wptr->border ? 2 : 0 )) > Control.nbl )) {
			remove_window( wptr );
			return(1);
			}
		else if (!( allocate_window(wptr) )) {
			remove_window( wptr );
			return(27);			
			}
		else	{
			Control.windows[wid] = wptr;
			if ( wptr->visible ) { show_windows(); }
			wid++;
			if ( bedug ) {
				printf("wcreat(%u)\r\n",wid);
				}
			*r = wid;
			return(0);
			}
		}

}

#endif	/* _wcreat_c */
	/* --------- */

