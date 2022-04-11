public	void	old_visual_switch(int atx, int aty, int nbx, int nby, int f,int fg,int bg, char * mptr, int mlen, int state)
{
	int	fh;
	int	fw;
	int	bh;
	int	bw;
	int	tw;
	int	bx=0;
	int	by=0;
	if (!( f )) {
		fh = 0;
		fw = 0;
		}
	else	{
		fh = guifontsize(f);
		fw = (fh & 0x00FF);
		fh >>= 8;
		fh &= 0x00FF;
		}
	mlen = strlen(mptr);

	if ( nbx < 4 ) (nbx = fw+4);

	while ((bw = ((mlen*fw)+4)) > nbx)
		mlen--;

	bh = (fh+4);
	if ( bw < bh ) bw = bh;

	if ((nbx > 0) && (nby > 0)) {

		if ( bw > nbx )
			bw = nbx; 
	
		if ( bh > nby )
			bh = nby;

		else if (bh > fh) 
			by = ((fh - bh)/2);
		else	by = 0;
	
		if (!( bw )) { bx=0; bw = nbx; }
		if (!( bh )) { by=0; bh = nby; }

		if (( bw > 2 ) && ( bh > 2 )) {
			relief( atx+bx,aty+by,bw,bh,standard_lolight,transparent,standard_hilight);
			bx++; by++; bw -=2; bh -= 2;
			}
		if (( bw > 2 ) && ( bh > 2 )) {
			relief( atx+bx,aty+by,bw,bh,standard_lolight,transparent,standard_hilight);
			bx++; by++; bw -=2; bh -= 2;
			}
		relief( atx+bx,aty+by,bw,bh,standard_black,standard_white,standard_black);

		if (!(tw = textsizelen( f, mptr, 1 )))
			return;
		if ( state & _VISUAL_CHECK ) {
			if (( bw > 2 ) && ( bh > 2 )) {
				if ( state & _VISUAL_FOCUS )
					xfilzone( atx+bx+1,aty+by+1,bw-2,bh-2,fg|0x1000);
				else	filzone( atx+bx+1,aty+by+1,bw-2,bh-2,fg);
				}
			cicocolour(bg,0);
			}
		else	{
			if (( bw > 2 ) && ( bh > 2 )) {
				if ( state & _VISUAL_FOCUS )
					xfilzone( atx+bx+1,aty+by+1,bw-2,bh-2,bg|0x1000);
				else	filzone( atx+bx+1,aty+by+1,bw-2,bh-2,bg);
				}
			cicocolour(fg,0);
			}
		if (( mptr != (char *) 0)
		&&  ( mlen != 0 )
		&&  ( *mptr != 0 )
		&&  ((tw = textsizelen( f, mptr, mlen )) != 0)){
			if (tw < (bw -2))
				bx = ((bw-2)-tw)/2;
			else	bx = 1;
			PixelFontLat(atx+bx+1,aty+by+1,f,mptr,mlen);
			}
		}
	return;
}

public	void	visual_switch(int atx, int aty, int nbx, int nby, int f,int fg,int bg, char * mptr, int mlen, int state)
{
	char *	vptr;
	int	vlen;
	int	i;
	int	bh=nby;
	int	bw=nbx;
	int	bx=0;
	int	by=0;
	int	options=(((state & 0x00F0) >> 4) | ( state & 0x0F00));

	if (( bw > 2 ) && ( bh > 2 )) {
		relief( atx+bx,aty+by,bw,bh,standard_lolight,transparent,standard_hilight);
		bx++; by++; bw -=2; bh -= 2;
		}
	if (( bw > 2 ) && ( bh > 2 )) {
		relief( atx+bx,aty+by,bw,bh,standard_lolight,transparent,standard_hilight);
		bx++; by++; bw -=2; bh -= 2;
		}
	relief( atx+bx,aty+by,bw,bh,standard_black,standard_white,standard_black);

	vptr = mptr; vlen = mlen;
	for (i=0; i < mlen; i++) {
		if (*(mptr+i) == '|') {
			vptr = (mptr+i+1);
			vlen = (mlen-(i+1));
			mlen = i;
			break;
			}
		}
	if ( state & _VISUAL_CHECK ) {
		if (( bw > 2 ) && ( bh > 2 )) {
			if ( state & _VISUAL_FOCUS )
				xfilzone( atx+bx+1,aty+by+1,bw-2,bh-2,fg|0x1000);
			else	filzone( atx+bx+1,aty+by+1,bw-2,bh-2,fg);
			}
		visual_text(atx+bx+1,aty+by+2,bw-2,bh-2,f,bg,0,vptr,vlen,options);
		}
	else	{
		if (( bw > 2 ) && ( bh > 2 )) {
			if ( state & _VISUAL_FOCUS )
				xfilzone( atx+bx+1,aty+by+1,bw-2,bh-2,bg|0x1000);
			else	filzone( atx+bx+1,aty+by+1,bw-2,bh-2,bg);
			}
		visual_text(atx+bx+1,aty+by+2,bw-2,bh-2,f,fg,0,mptr,mlen,options);
		}
	return;
}


