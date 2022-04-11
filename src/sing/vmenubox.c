#ifndef	_menubox_c
#define	_menubox_c

public	void	menu( int atx, int aty, int nbx, int nby, int style )
{
	switch ( style ) {
		case	1	:
			visual_convex( atx,aty,nbx,nby );
			break;

		case	2	:
			if (( nbx > 4 ) && ( nby > 4 )) {
				relief( atx,aty,nbx,nby,
					standard_hilight,standard_backwash,standard_lolight);
				visual_concave( atx+2,aty+2,nbx-4,nby-4 );
				}
			break;

		case	0	:
		default		:
			if (( nbx > 4 ) && ( nby > 4 )) {
				xorzone(atx+4,aty+4,nbx-4,nby-4,0x0069);
				relief( atx,aty,nbx-4,nby-4,standard_black,standard_white,standard_black);
				}
		}
	return;
}
	
public	void	option( int atx, int aty, int f, char * mptr, int mlen, int state, int align )
{
	int	fh,fw;
	if (!( mptr ))	return;
	if (!( f ))	return;
	else	{
		fh = guifontsize(f);	
		fw = (fh & 0x00FF);
		fh >>= 8;	
		fh &= 0x00FF;
		if ( state & 2 )
			visual_text(atx, aty, (mlen * fw), fh, f,standard_white,standard_title, mptr, mlen,align);
		else	visual_text(atx, aty, (mlen * fw), fh, f,standard_black,standard_white, mptr, mlen,align);
		return;
		}
}

#endif	/* _menubox_c */

