#ifndef	_vrelief_c
#define	_vrelief_c

void	relief(int atx,int aty, int nbx, int nby, int hl, int bg, int ll )
{
	if ( bg != transparent )
		filzone(atx,aty,nbx,nby,bg);
	filzone(atx,aty,nbx,1,hl);
	filzone(atx,aty,1,nby,hl);
	filzone((atx+nbx-1),aty,1,nby,ll);
	filzone(atx,(aty+nby-1),nbx,1,ll);
	return;
}

void	xrelief(int atx,int aty, int nbx, int nby, int hl, int bg, int ll )
{
	if ( bg != transparent )
		xfilzone(atx,aty,nbx,nby,bg);
	xfilzone(atx,aty,nbx,1,hl);
	xfilzone(atx,aty,1,nby,hl);
	xfilzone((atx+nbx-1),aty,1,nby,ll);
	xfilzone(atx,(aty+nby-1),nbx,1,ll);
	return;
}

void	relief_frame( int atx, int aty, int nbx, int nby, int style )
{
	int	bg;

	if (( nbx > 0 ) && ( nby > 0 )) {

	switch (( style & _FRAME_TYPE )) {

		case	_OUTSET_FRAME :
			relief( atx,aty,nbx,nby,standard_hilight,transparent,standard_lolight);
			break;

		case	_INSET_FRAME  :
			relief( atx,aty,nbx,nby,standard_lolight,transparent,standard_hilight);
			break;

		case	_RIDGE_FRAME  :
			relief( atx,aty,nbx,nby,standard_hilight,transparent,standard_lolight);
			if (( nbx > 2 ) && ( nby > 2 )) 
				relief((atx+1),(aty+1),(nbx-2),(nby-2),standard_lolight,transparent,standard_hilight);
			break;

		case	_GROOVE_FRAME :
			transparent = transparent;
			relief( atx,aty,nbx,nby,standard_lolight,transparent,standard_hilight);
			if (( nbx > 2 ) && ( nby > 2 )) 
				relief( (atx+1),(aty+1),(nbx-2),(nby-2),standard_hilight,transparent,standard_lolight);
			break;

		}
	}
	return;
}
#endif	/* _vrelief_c */



