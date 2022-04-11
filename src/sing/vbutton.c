public	int	visual_trigger_code( char * bptr, int blen )
{
	int	i;
	int	c;
	if (!( bptr ))
		return( 0 );
	for ( i=0; i < blen; i++ ) 
		if (*(bptr+i) == '&')
			break;
	if ( *(bptr+i) != '&' )
		return(0);
	else if ( (i+1) < blen ) {
		c = *(bptr+i+1);
		if ((c >= 'a') && (c <= 'z')) c -= ('a'-'A');
		return( c );
		}
	else	return(0);
}

public	void	visual_button(int atx, int aty, int nbx, int nby, int f,int fg,int bg, char * mptr, int mlen, int state)
{
	int	i;
	int	a;
	int	fh;
	int	astate=0;
	char *	sptr;
	int	flag=0;
	int	truecolour=x_conf(70);

	if ( state & _VISUAL_IMAGE ) {

		if ( truecolour ) 
			state |= _I_QUALITY;

		/* detect double payload : image|text */
		/* ---------------------------------- */
		if ((sptr = mptr) != (char *) 0)
			for ( i=0; i < mlen; i++ )
				if ( *(mptr+i) == '|' )
					flag=(i+1);		
		if ( flag ) {
			*(mptr+(flag-1)) = 0;
			sptr = (mptr+flag);
			visual_button(atx,aty,nbx,nby,f,fg,bg,mptr,(flag-1),state);
			visual_button(atx,aty,nbx,nby,f,fg,0,sptr,(mlen-flag),(state & ~_VISUAL_IMAGE)|_INHIBIT_FRAME|_TRANSPARENT);
			*(mptr+(flag-1)) = '|';
			return;
			}
		}

	if (( state & _VISUAL_EVENT )
	&&  (!( state & _INHIBIT_FRAME ))) {
		if (state & _VISUAL_PRESS)
			a = 0;
		else	a = _VISUAL_PRESS;
		/* FCH original = visual_button( atx,aty,nbx,nby,f,fg,bg,mptr,mlen,(state & _I_QUALITY) | (a|_VISUAL_FOCUS));*/
		visual_button( atx,aty,nbx,nby,f,fg,bg,mptr,mlen,(state & (_I_QUALITY | _VISUAL_IMAGE)) | (a|_VISUAL_FOCUS)); 
		visual_wait(3);
		state &= ~_VISUAL_EVENT;
		state |= _VISUAL_FOCUS;
		}
 
	if (!( f )) fh=0;
	else	{
		fh = guifontsize(f);
		fh >>= 8;
		fh &= 0x00FF;
		}
	if ((nbx > 0) && (nby > 0) && ( fh > 0 )) {

		hide();

		if ( nby >= 14 ) {
			if (!( state & _INHIBIT_FRAME )) {
				if (!( state & _VISUAL_FOCUS ))
					relief(atx,aty,nbx,nby,standard_black,standard_backwash,standard_black);
				else	relief(atx,aty,nbx,nby,standard_lolight,standard_backwash,standard_hilight);
				if (( nbx > 2 ) && ( nby > 2 )) {
					if ( state & _VISUAL_IMAGE ) {
						if ( state & _VISUAL_PRESS )
							relief(atx+1,aty+1,nbx-2,nby-2,standard_lolight,standard_backwash,standard_hilight);
						else	relief(atx+1,aty+1,nbx-2,nby-2,standard_hilight,standard_backwash,standard_lolight);
						}
					else if ( state & _VISUAL_PRESS )
						visual_concave((atx+1),(aty+1),(nbx-2),(nby-2));
					else	visual_convex ((atx+1),(aty+1),(nbx-2),(nby-2));
					}
				}
			else if (!( state & _VISUAL_IMAGE )) {
				if ( state & _VISUAL_FOCUS ) {
					relief(atx,aty,nbx-1,((nby/fh)*fh)-1,standard_lolight,standard_backwash,standard_hilight);
					relief(atx+1,aty+1,nbx-1,((nby/fh)*fh)-1,standard_hilight,transparent,standard_lolight);
					}
				else	{
					if (!( bg ))
						bg = standard_backwash;
					filzone(atx,aty,nbx,(nby/fh)*fh,bg);
					}
				}
			if ((f != 0)
			&&  (fh < nby)
			&&  (mptr != (char *) 0)) {
				if ( state & _VISUAL_IMAGE ) {
					if ( state & _VISUAL_PRESS ) {
						aty++; nby--;
						}

					if ( state & _A_BOLD )
						state = (_I_MAKEFIT | (state & _I_SPRITE));
					else	state = (_A_CENTER | (state & _I_SPRITE));
						
					if ( truecolour )
						state |= _I_QUALITY;
					if (( nbx > 8 ) && ( nby > 8 )) {
						visual_image( atx+4,aty+4,(nbx-8),(nby-8),mptr,state );
						}
					}
				else	{
					if ( state & _TRANSPARENT )
						astate = (_A_CENTER | _A_BOLD);
					else if (!( state & _INHIBIT_FRAME ))
						astate = _A_CENTER;
					else	astate = _A_LEFT;
					a = ((nby - fh)/2);
					if ( state & _VISUAL_FOCUS ) {
						if (!( state & _INHIBIT_FRAME )) {
							if (!( state & _A_SHADOW ))
								fg = standard_black;
							if (!( state & _TRANSPARENT )) {
								bg = standard_backwash;
								if (( nby > 16 ) && ( nbx > 8 )) {
									relief( atx+4,	aty+6, 
										(nbx-8), (nby-(8*2)), 
										standard_lolight, standard_backwash-1, standard_hilight);
									if ( state & _INHIBIT_FRAME ) {
										relief( atx+5,	aty+7, 
											(nbx-8), (nby-(8*2)), 
											standard_hilight, transparent, standard_lolight);
										}
									}
								}
							}
						else	bg=transparent;
						astate |= _A_BOLD;
						}
					else if ( state & _INHIBIT_FRAME ) {
						if (!( state & _A_SHADOW ))
							fg = standard_black;
						if (!( bg ))
							bg = standard_backwash;

						}
					else 	{
						if (!( state & _A_SHADOW ))
							fg = standard_black;
						bg = transparent;
						}
					if (textsizelen(f,mptr,mlen) > (nbx-8) ) {
						if (( nbx>8) && (nby > 8))
							visual_trigger(atx+4,aty+4, (nbx-8), (nby-8), f, fg, 0, mptr, mlen, ((state & 0xFF00)| astate) );
						}
					else if (( nbx > 8 ) && ( nby > (a*2)))
						visual_trigger(atx+4,aty+a, (nbx-8), (nby-(a*2)), f, fg, 0, mptr, mlen, ((state & 0xFF00)| astate) );
					}
				}
			}
		else	{
			if (!( state & _INHIBIT_FRAME )) {
				if (!( state & _VISUAL_FOCUS ))
					relief(atx,aty,nbx,nby,standard_lolight,standard_backwash,standard_hilight);
				else	relief(atx,aty,nbx,nby,standard_focus,standard_backwash,standard_focus);
				}
			else if (!( state & _VISUAL_IMAGE )) {
				if ( state & _VISUAL_FOCUS ) {
					relief(atx,aty,nbx-1,((nby/fh)*fh)-1,standard_lolight,standard_backwash,standard_hilight);
					relief(atx+1,aty+1,nbx-1,((nby/fh)*fh)-1,standard_hilight,transparent,standard_lolight);
					}
				else	{
					if (!( bg ))
						bg = standard_backwash;
					filzone(atx,aty,nbx,(nby/fh)*fh,bg);
					}
				}
			if ((nbx > 2) && (nby > 2)) {
				if (!( state & _INHIBIT_FRAME ))
					relief(atx+1,aty+1,nbx-2,nby-2,standard_black,transparent,standard_black);
				if ((nbx > 4) && (nby > 4)) {
					if (!( state & _INHIBIT_FRAME )) 
						relief(atx+2,aty+2,nbx-4,nby-4,standard_hilight,transparent,standard_lolight);
					if ((f != 0)
					&&  (fh < nby)
					&&  (mptr != (char *) 0)) {
						if ( state & _VISUAL_IMAGE ) {
							if ( state & _A_BOLD )
								state = _I_MAKEFIT;
							else	state = _A_CENTER;
							if ( truecolour )
								state |= _I_QUALITY;
							if (( nbx > 8 ) && ( nby > 8 ))
								visual_image( atx+4,aty+4,(nbx-8),(nby-8),mptr,state );
							}
						else	{
							if ( state & _TRANSPARENT )
								astate = (_A_CENTER | _A_BOLD);
							else if (!( state & _INHIBIT_FRAME ))
								astate = _A_CENTER;
							else	astate = _A_LEFT;
							a = ((nby -fh)/2);
							if ( state & _VISUAL_FOCUS ) { 
								if (!( state & _INHIBIT_FRAME )){
									if (!( state & _A_SHADOW ))
										fg = standard_black;
									bg = standard_backwash;
									visual_focus(atx,aty,nbx,nby);
									}
								astate |= _A_BOLD;
								}
							else if ( state & _INHIBIT_FRAME ) {
								if (!( state & _A_SHADOW ))
									fg = standard_black;
								if (!( bg ))
									bg = standard_backwash;
								}
							else	{
								if (!( state & _A_SHADOW ))
									fg = standard_black;
								bg = standard_backwash;
								}
							if (( nbx > 8 ) && ( nby > 8 )) {
								if ( textsizelen(f,mptr,mlen) > (nbx-8) ) 
									visual_trigger(atx+4,aty+4, (nbx-8), (nby-8), f, fg, 0, mptr, mlen, ((state & 0xFF00)| astate) );
								else	visual_trigger(atx+4,aty+a, (nbx-8), (nby-(a*2)), f, fg, 0, mptr, mlen, ((state & 0xFF00)| astate) );
								}
							}
						}
					}
				}
			}
		show(atx,aty,nbx,nby );


		}
	return;
}




