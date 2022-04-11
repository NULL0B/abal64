
#include "valign.h"

private	int	trigger_format=_A_LINE;
private	int	trigger_colour=31;

public	void	trigger_conf( int a, int b )
{
	trigger_colour = b;
	switch ( a ) {
		case	0 : trigger_format = 0; break;
		case	1 : trigger_format = _A_BOLD; break;
		case	2 : trigger_format = _A_LINE; break;
		default	  : trigger_format = 0;
		}
	return;
}

public	void	visual_trigger(int x,int y, int w, int h, int f, int fg, int bg,char * mptr, int mlen, int options )
{
	int	needh;
	int	yy=y+h;
	int	wordend=0;
	int	fw;
	int	fh;
	int	tw;
	int	mw;
	int	u=0;
	int	i=0;
	int	c;
 	int	trim=0;
	int	a=0;

	cicocolour(fg,0);

	/* Handle CICO atributs */
	/* -------------------- */
	if ( options & _A_BOLD  ) a |= _PIXELCO_BOLD;
	if ( options & _A_LINE  ) a |= _PIXELCO_ULINE;
	if ( options & _A_SHADOW) a |= _PIXELCO_SHADOW;
	if ( options & _A_BAR   ) a |= _PIXELCO_OLINE;
	if ( options & _A_STRIKE) a |= _PIXELCO_STRIKE;

	/* Collect and Validate font information */
	/* ------------------------------------- */
	fw = guifontsize(f); fh =(fw >> 8); fw &= 0x00FF;

	if ((!( fw )) || (!( fh ))) return;

	/* Remove Space Prefix */
	/* ------------------- */
	while ( mlen ) {
		if ( *mptr != ' ') break;
		else	{ mlen--; mptr++; }
		}

	if (!(tw = textsizelen(f,mptr,mlen))) {
		textalign(x,y,w,h,f,mptr,mlen,options);
		return;
		}
	else if ( tw > w) {

		/* Check if line splitting is possible */
		/* ----------------------------------- */
		if (tw < (mw =(w * (h/fh)))) {

			needh = (((tw / w)+(tw % w?1:0))*fh);
			y += ((h-needh)/2);

			/* Lets cut it up to do it */
			/* ----------------------- */
			while ( mlen != 0 ) {
				for (wordend=0,i=0; i < mlen; i++ ) {
					if ( *(mptr+i) == ' ' )
						wordend = (i+1);
					else if ((tw = textsizelen( f, mptr, i )) < w )
						continue;
					else	break;
					}
				if ( i == mlen ) 
					wordend = mlen;
				else if (!( wordend )) {
					if (i>1) {
						wordend = (i-1);
						/* mlen=0; */
						}
		 			else	return;
					}
				visual_trigger(x,y,w,fh,f,fg,bg,mptr,wordend,options );
				if (!( mlen )) return;
				y += fh;
				if ( (y+fh) > yy ) break;
				mptr += wordend;
				mlen -= wordend;
				/* remove preceeding white space */
				/* ----------------------------- */
				while ( mlen ) {
					if ( *mptr != ' ') break;
					else	{ mlen--; mptr++; }
					}
				}		
			return;
			}
		}
	else	y += ((h - fh)/2);

	/* Calculate Possible Size */
	/* ----------------------- */
	while (1) {
		if ((tw = textsizelen( f, mptr, mlen )) < w )
			break;
		else if (!( mlen ))
			return;
		else	{
			mlen--;
			trim++;
			}
		}
	switch (( options & 0x0007)) {
		case	_A_LEFT		:
			break;

		case	_A_RIGHT	:
			if ( tw < w )
				x += (w - tw);
			break;

		case	_A_CENTER	:
			if ( tw  < w )
				x += ((w - tw)/2);
			break;
		}

	cicocolour(fg,(u=0));

	if (!( options & ( _A_LINE | _A_BOLD ) ))
		options = trigger_format;

	(void) cicoatribut( a );

	while ( mlen ) {
		if ((c = *(mptr++)) == _HOTKEY_TRIGGER ) {
			c = *(mptr++);
			if ( trim ) mlen++;
			if ( mlen >= 2 )
				mlen -= 2;
			else	mlen--;
			if ( options & _A_LINE )
				cicoatribut(a | (u = _PIXELCO_ULINE));
			else if ( options & _A_BOLD )
				cicoatribut(a | (u = _PIXELCO_BOLD));
			else 	{
				if (!( bg ))
					bg = trigger_colour;
				if ( bg == fg )
					bg = standard_black;

				u = (_PIXELCO_ULINE | _PIXELCO_BOLD);
				cicocolour(bg,0);
				}
			}
		else	{
			mlen--;
			if ( u ) {
				if (u == (_PIXELCO_ULINE | _PIXELCO_BOLD) )
					cicocolour(fg,(u=0));
				else	cicoatribut(a |( u = 0));
				}
			}
		x = PixelFontCat( x, y, f, c );
		}		
	cicoatribut((u = 0));
	return;	
}


public	void	visual_text(int x,int y, int w, int h, int f, int fg, int bg,char * mptr, int mlen, int options )
{
	int	needh;
	int	yy=y+h;
	int	mw=0;
	int	wordend=0;
	int	v,i,l,n;
	int	fw,fh;
	int	tl=0;
	int	tw=0;
	int	nbs=0;
	int	spw=0;
	int	ya=0;
	int	a=0;
	int	ha=-1;

	/* collect and test font characteristics */
	/* ------------------------------------- */
	if (!( f ))	return;
	else	{
		if (!( fw = guifontsize(f) )) return;
		fh =(fw >> 8); 	
		fw &= 0x00FF;
		if (!( fh )) return;
		}
	
	/* Establish full background */
	/* ------------------------- */
	if ( bg != 0 ) filzone(x,y,w,h,bg);

	/* set up foreground colour */
	/* ------------------------ */
	cicocolour(fg,0);

	/* Handle CICO atributs */
	/* -------------------- */
	if ( options & _A_BOLD  ) a |= _PIXELCO_BOLD;
	if ( options & _A_LINE  ) a |= _PIXELCO_ULINE;
	if ( options & _A_SHADOW) a |= _PIXELCO_SHADOW;
	if ( options & _A_BAR   ) a |= _PIXELCO_OLINE;
	if ( options & _A_STRIKE) a |= _PIXELCO_STRIKE;

	ha = cicoatribut( a );

	/* Test for alignment required */
	/* --------------------------- */
	if (( options & 0x0007) == _A_NONE ) {

		for (	i=0,v=0,l = (h/fh),n = (w/fw);
			i < l;
			i++ ) {
			if ( n > mlen ) n = mlen;
			PixelFontLat( x, y+(fh*i), f, (mptr+v),n );
			v += n;	mlen -= n;
			if (!( mlen )) break;
			}
		}
	else if (!(tw = textsizelen(f,mptr,mlen))) {
		textalign(x,y,w,h,f,mptr,mlen,(options & 0x0007));
		ha = cicoatribut( ha );
		return;
		}
	else	{
		/* if ( fh < h ) y += ((h-fh)/2); */

		/* remove leading white space */
		/* -------------------------- */
		if (!( options & _A_SPACE )) {
			while ( mlen != 0) { if ( *mptr != ' ' ) break; else { mptr++; mlen--; } }
			}

		/* remove trailing white space */
		/* --------------------------- */
		for ( i=0,tl=0; i < mlen; i++ ) { if (!( *(mptr+i) )) break;  else if ( *(mptr+i) != ' ' )  tl = (i+1); }

		mlen = tl;

		if ((tw = textsizelen(f,mptr,mlen)) > w) {

			/* Check if line splitting is possible */
			/* ----------------------------------- */
			if (tw < (mw =(w * (h/fh)))) {

				needh = (((tw / w)+(tw % w?1:0))*fh);
				y += ((h-needh)/2);

				/* Lets cut it up to do it */
				/* ----------------------- */
				while ( mlen != 0 ) {
					/* -------------------------------------------- */
					/* detect longest collection of whole words 	*/
					/* which can fit inside the zone		*/
					/* -------------------------------------------- */
					for (wordend=0,i=0; i < mlen; i++ ) {
						if ( *(mptr+i) == ' ' )
							wordend = (i+1);
						else if ((tw = textsizelen( f, mptr, i+1/*FCH longueur et non indice*/ )) < w )
							continue;
						else	break;
						}
					if ( i == mlen ) 
						wordend = mlen;
					else if (!( wordend )) {
						if (i>1) {
							wordend = (i-1);
							/* mlen=0; */
							}
		 				else	{
							a = cicoatribut( ha );
							return;
							}
						}
					visual_text(x,y,w,fh,f,fg,bg,mptr,wordend,options );
					if (!( mlen )) {
						a = cicoatribut( ha );
						return;
						}
					y += fh;
					if ( (y+fh) > yy ) break;
					mptr += wordend;
					mlen -= wordend;
					/* remove preceeding white space */
					/* ----------------------------- */
					while ( mlen ) {
						if ( *mptr != ' ') break;
						else	{ mlen--; mptr++; }
						}
					}		
				a = cicoatribut( ha );
				return;
				}
			}
		else	y += ((h - fh)/2);

		/* Test for alignment required */
		/* --------------------------- */
		switch (( options & 0x0007)) {
			case	_A_LEFT		:
				while ((tl)
				&&     ((tw = textsizelen( f, mptr, tl )) > w))
					tl--;
				if ( tl != 0 ) {
					PixelFontLat( x, y, f, mptr,tl );
					}
				break;
			case	_A_RIGHT	:
				while ((tl)
				&&     ((tw = textsizelen( f, mptr, tl )) > w)) {
					tl--;
					mptr++;
					}
				if ( tl ) {
					PixelFontLat( x+(w-tw), y, f, mptr,tl );
					}
				break;

			case	_A_CENTER	:
				while ((tl) 
				&&     ((tw = textsizelen( f, mptr, tl )) > w))
					tl--;
				if ( tl )  {
					PixelFontLat( x+((w-tw)/2), y, f, mptr,tl );
					}
				break;

			case	_A_JUSTIFY	:
				while ((tl)
				&&     ((tw = textsizelen( f, mptr, tl )) > w)) {
					tl--;
					}
				if ( tl ) {
					
					for ( nbs=0,i=0; i < tl; i++ ) {
						if ( *(mptr+i) == ' ')
							nbs++;
						}
					if ( nbs )
						spw = ((w-tw)/nbs);
					else	spw=0;
					for ( i=0; i < tl; i++ ) {
						x = PixelFontLat(x,y,f,(mptr+i),1);
						if ( *(mptr+i) == ' ' )
							x += spw;
						}

					}
				break;
			}

		}

	/* restore previous atributs */
	/* ------------------------- */
	a = cicoatribut( ha );
	return;
}



