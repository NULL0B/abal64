#ifndef	_swcreat_c
#define	_swcreat_c

/* 61:%swcreat(%?,%,%,%,%,.) */
int	swcreatc(r, plig,pcol,nlig,ncol,style,control,tptr)
WPTR	r;
int	plig;
int	pcol;
int	nlig;
int	ncol;
int	control;
int	style;
char *  tptr;
{
	int	i;
	int	wid;
	struct	asfun_window * wptr;
	if (!( fen_ini	))	{	return(3); 	}
	if ((wid = next_free_window()) >= _MAX_WINDOWS)
		return(4);
	else if (!( wptr = create_window()))
		return(27);
	else	{
		wptr->y = plig;
		wptr->x = pcol;
		wptr->h = nlig;
		wptr->w = ncol;
	
		wptr->style    	= style;
		wptr->control 	= control;
		wptr->fg 	= 0;
		wptr->bg 	= 7;
		wptr->lentit	= 0;
		for (i=0; i< _MAX_TITLE ; ++i) { 	
			if (!( *tptr ))
				wptr->titre[i] = ' '; 
			else	wptr->titre[i] = *(tptr++);
			}
		for (i=0; i< _MAX_CADRE; ++i) { wptr->frame[i] = ' '; }

		wptr->fratb	= 0;
		wptr->frfg	= 15;
		wptr->frbg	= 1;

		if (( wptr->control & CAD3 ) == CAD3) {
			wptr->border=3;
			}
		else if (( wptr->control & CAD1 ) == CAD1) {
			wptr->border=1;
			}
		else if (( wptr->control & CAD2 ) == CAD2) {
			wptr->border=2;
			}
		else if (wptr->style)
			wptr->border=4;
		else 	wptr->border=0;

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
	
		if (((( wptr->x+wptr->w-1 ) + ( wptr->border ? 2 : 0 )) > Control.nbc )
		||  ((( wptr->y+wptr->h-1 ) + ( wptr->border ? 2 : 0 )) > Control.nbl )) {
			remove_window( wptr );
			return(1);
			}
		if (!( allocate_window(wptr) )) {
			remove_window(wptr);
			return(27);			
			}
		else	{
			Control.windows[wid] = wptr;
			if ( wptr->visible ) { show_windows(); }
			wid++;
			*r = wid;
			return(0);
			}
		}

}

private EXAWORD Dll_swcreat( VOID FAR PTR FAR pptr[] )
{
	char *	tptr;
	int	tlen;
	int	i;
	int	wid;
	struct	asfun_window * wptr;
	if (!( fen_ini	))	{	return(3); 	}
	if ((wid = next_free_window()) >= _MAX_WINDOWS)
		return(4);
	else if (!( wptr = create_window()))
		return(27);
	else	{
		wptr->y = LdfParaWord(1);
		wptr->x = LdfParaWord(2);
		wptr->h = LdfParaWord(3);
		wptr->w = LdfParaWord(4);
	
		wptr->style    	= 1;
		wptr->control 	= 6;
		wptr->fg 	= 0;
		wptr->bg 	= 7;
		wptr->lentit	= 0;
		for (i=0; i< _MAX_TITLE ; ++i) { wptr->titre[i] = ' '; }

		if ( LdfValidPara(5) ) {
			wptr->style = LdfParaWord(5);
			if ( LdfValidPara(6) ) {
				wptr->control = LdfParaWord(6);
				if ( LdfValidPara(7) ) {
					tptr = LdfParaPtr(7);
					tlen = LdfParaLen(7);
					if ((wptr->lentit = tlen) > _MAX_TITLE)
						wptr->lentit = _MAX_TITLE;
					for (i=0; i< _MAX_TITLE; ++i) { 
						if ( i < tlen )
							wptr->titre[i] = *(tptr+i);
						else	wptr->titre[i] = ' ';
						}
					}
				}
			}

		for (i=0; i< _MAX_CADRE; ++i) { wptr->frame[i] = ' '; }

		wptr->fratb	= 0;
		wptr->frfg	= 15;
		wptr->frbg	= 1;

		if (( wptr->control & CAD3 ) == CAD3) {
			wptr->border=3;
			}
		else if (( wptr->control & CAD1 ) == CAD1) {
			wptr->border=1;
			}
		else if (( wptr->control & CAD2 ) == CAD2) {
			wptr->border=2;
			}
		else if (wptr->style)
			wptr->border=4;
		else 	wptr->border=0;

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
	
		if (((( wptr->x+wptr->w-1 ) + ( wptr->border ? 2 : 0 )) > Control.nbc )
		||  ((( wptr->y+wptr->h-1 ) + ( wptr->border ? 2 : 0 )) > Control.nbl )) {
			remove_window( wptr );
			return(1);
			}
		if (!( allocate_window(wptr) )) {
			remove_window(wptr);
			return(27);			
			}
		else	{
			Control.windows[wid] = wptr;
			if ( wptr->visible ) { show_windows(); }
			wid++;
			if ( bedug ) {
				printf("swcreat(%u,%u,%u)\r\n",wid,wptr->style,wptr->control);
				}
			PutInt16( pptr[0], wid);
			return(0);
			}
		}
}

#endif	/* _swcreat_c */
	/* ---------- */

