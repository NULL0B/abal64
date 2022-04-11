public	void	visual_check(int atx, int aty, int nbx, int nby, int f,int fg,int bg, char * mptr, int mlen, int state)
{
	int	fh;
	int	fw;
	int	bh;
	int	bw;
	int	by;
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

	bw = (fw*2);

	if ((bh = bw) > fh)
		bw = bh = fh;

	if ((nbx > 0) && (nby > 0)) {

		if ( bw > nbx )
			bw = nbx; 
	
		if ( bh > nby ) {
			bh = nby;
			by = 0;
			}
		else 	by = ((nby - bh)/2);
	
		if (!( bw )) { bw = nbx; }
		if (!( bh )) { by=0; bh = nby; }

		if (( bw > 2 ) && ( bh > 2 )) {
			relief( atx,aty+by,bw,bh,standard_lolight,transparent,standard_hilight);
			by++; bw -=2; bh -= 2;
			}
		if (( bw > 2 ) && ( bh > 2 )) {
			relief( atx+1,aty+by,bw,bh,standard_lolight,transparent,standard_hilight);
			by++; bw -=2; bh -= 2;
			}
		if (( bw > 0 ) && ( bh > 0 ))
			relief( atx+2,aty+by,bw,bh,standard_black,standard_white,standard_black);

		if (( state & _VISUAL_CHECK )
		&&  (( bw > 4 ) && ( bh > 4 ))) {
			filzone( atx+4,aty+by+2,bw-4,bh-4,standard_black);
			}

		if ( nbx > (fw*3) ) {
			if (( mlen > 0 ) && ( mptr != (char *) 0)) {
				if ( state & _VISUAL_FOCUS )
					visual_trigger(atx+bw+fw /* (fw*3) */, aty+by, nbx-(fw*3), nby, f,standard_title,transparent,    mptr, mlen,((state & 0xFF00)| _A_LEFT) );
				else if ( state & 8 )
					visual_trigger(atx+bw+fw /* (fw*3) */, aty+by, nbx-(fw*3), nby, f,standard_grayed,transparent, mptr, mlen,((state & 0xFF00)| _A_LEFT) );
				else	visual_trigger(atx+bw+fw /* (fw*3) */, aty+by, nbx-(fw*3), nby, f,standard_black,transparent, mptr, mlen,((state & 0xFF00)| _A_LEFT) );
				}
			}
		}
	return;
}







