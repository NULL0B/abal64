public	void	visual_radio(int atx, int aty, int nbx, int nby, int f,int fg,int bg, char * mptr, int mlen, int storage, int value )
{
	int	fh;
	int	fw;
	int	bh;
	int	bw;
	int	by;
	if (!( f )) {
		fh = 32;
		fw = 32;
		}
	else	{
		fh = guifontsize(f);
		if ((fw = (fh & 0x00FF)) > nbx) { return; }
		fh >>= 8;
		fh &= 0x00FF;
		if ( fh > nby ) { return; }
		}

	bw = (fw*2);

	if ((bh = bw) > fh)
		bw = bh = fh;

	if ((nbx > 0) && (nby > 0)) {

		if ( bw > nbx )
			bw = nbx; 
	
		if ( bw > nby ) {
			bw = nby;
			by = 0;
			}
		else if ((by = ((nby - bw)/2)) < 0)
			by = 0;
	
		if (!( bw )) { bw = nby; }
		if (!( bh )) { by=0; bh = nby; }

		drawcircle( atx,(aty+by),bw,bw,standard_black,1);
		if ( bw > 2 )
			drawcircle( atx+1,(aty+by)+1,bw-2,bw-2,standard_white,1);

		if (( storage == value  ) && ( bw > 6 )) {
			drawcircle( atx+3,(aty+by)+3,bw-6,bw-6,standard_black,1);
			}

		if ( nbx > (fw*3) ) {
			if (( mlen > 0 ) && ( mptr != (char *) 0)) {
				if ( f )
					visual_trigger(atx+(fw*3), (aty+by), nbx-(fw*3), nby, f,fg,transparent, mptr, mlen,((value & 0xFF00)| _A_LEFT) );
				}
			}
		}
	return;
}



