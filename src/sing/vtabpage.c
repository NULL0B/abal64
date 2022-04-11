void	visual_tabpage(
	 	int atx, int aty, int nbx, int nby, 
		int f, char * mptr,int mlen, 
		int msgx, int state 
		)
{
	int	fh;
	int	fw;
	int	tabing=0;
	int	tlen;
	int	i;
	int	fg;
	int	bg;
	int	ty=0;

	int	a=0;
	int	ha=-1;

	/* Handle CICO atributs */
	/* -------------------- */
	if ( state & _A_BOLD  ) a |= _PIXELCO_BOLD;
	if ( state & _A_LINE  ) a |= _PIXELCO_ULINE;
	if ( state & _A_SHADOW) a |= _PIXELCO_SHADOW;

	ha = cicoatribut( a );

	if (!( mptr ))
		mptr = "TAB";

	if (!( f )) {
		fw = 10;
		if ((fh = (nby-8)) > 24)
			fh = 24;
		else if ( fh <= 0 )
			fh = 1;
		}
	else	{
		fh = guifontsize(f);
		fw = (fh & 0x00FF);
		fh >>= 8;
		fh &= 0x00FF;
		}

	/* Ensure Legal dimensions */
	/* ----------------------- */
	if ((nbx > 0) && (nby > 0)) {
		if ( nby > (fh + 8)) {
			nby -= (fh+8);
			aty += (fh+8);
			tabing = (fh+8);
			for (i=0,tlen=0; i < mlen; i++ )
				if (( *(mptr+i) != ' ' )
				&&  ( *(mptr+i) != _HOTKEY_TRIGGER ))
					tlen = (i+1);

			}
		else	{
			tlen = mlen;
			tabing = 0;
			}
		if ( state & _VISUAL_FOCUS ) {
			/* Draw black frame */
			/* ---------------- */
			relief(atx,aty,nbx,nby,standard_black,standard_backwash,standard_black);
			}
		if ((nbx > 2) && (nby > 2)) {
			if ( state & _VISUAL_FOCUS ) {
				if ( state & 0x0010 ) 
					visual_concave(atx+1,aty+1,nbx-2,nby-2);
				else if ( state & 0x0020 ) 
					visual_convex(atx+1,aty+1,nbx-2,nby-2);
				else	relief(atx+1,aty+1,nbx-2,nby-2,standard_himid,transparent,standard_lomid);
				}
			if ((nbx > 4) && (nby > 4)) {
				if ( state & _VISUAL_FOCUS ) {
					if (!( state & 0x0030 ))
						relief(atx+2,aty+2,nbx-4,nby-4,standard_hilight,transparent,standard_lolight); 
					fg = standard_title;
					bg = standard_backwash;
					}
				else	{
					fg = standard_black;
					bg = standard_backwash;
					}
				if (!( tabing )) {
					if ((nbx > 9) && ( fh > 0 ) && ((nby-8) > fh)) {
						relief(atx+3,aty+3,nbx-7,fh+2,standard_hilight,transparent,standard_hilight); 
						filzone(atx+4,aty+4,nbx-9,fh,bg);
						if (( f != 0 )
						&&  ( mptr != (char *) 0 )) {
							cicocolour(fg,0);
							PixelFontSat(atx+6,aty+4,f,mptr);
							}
						}
					}
				/* This draws the normal Tab ! */
				/* --------------------------- */
				else	{
					aty -= tabing;
					nbx  = (textsizelen(f,mptr,tlen) +( fw * 2));
					atx += msgx;
					if ( state & _VISUAL_FOCUS ) {
						visual_concave(atx,aty,nbx,tabing);
						ty = 2;
						}
					else	{
						visual_convex (atx,aty,nbx,tabing);
						ty=0;
						}
					filzone( atx+(nbx-1),aty,1,tabing,standard_lolight);
					if (( f != 0 )
					&&  ( mptr != (char *) 0 )) {
						ty += ((tabing - fh)/2);
						cicocolour(fg,0);
						visual_trigger(atx+fw,aty+ty,(nbx-2),fh,f,fg,0,mptr,tlen,(state & 0xFF00) |_A_LEFT);
						}
					}
				}
			}
		}

	a = cicoatribut( ha );

	return;
}






