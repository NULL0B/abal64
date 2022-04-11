private	int	getash(unsigned char * bptr)
{
	int	v=0;
	v  = ((*(bptr++) & 0x00FF) << 8);
	v |= (*(bptr++) & 0x00FF);
	return(v);
}

private	unsigned long	getal (unsigned char * bptr)
{
	unsigned long	v=0;
	v  = ((*(bptr++) & 0x00FF) << 24);
	v |= ((*(bptr++) & 0x00FF) << 16);
	v |= ((*(bptr++) & 0x00FF) <<  8);
	v |= (*(bptr++) & 0x00FF);
	return(v);
}

private	void	putash(unsigned char * bptr,int v)
{
	*(bptr++) = ((v & 0xFF00) >> 8);
	*(bptr++) = (v & 0x00FF);
	return;
}

private	void	putal (unsigned char * bptr, long v)
{
	*(bptr++) = ((v & 0xFF000000) >> 24);
	*(bptr++) = ((v & 0x00FF0000) >> 16);
	*(bptr++) = ((v & 0x0000FF00) >>  8);
	*(bptr++) = (v & 0x0000000FF);
	return;
}


private	void	putmsh(short int * bptr, int v)	{ *bptr = v; return; }
private	void	putml (long  int * bptr, long v){ *bptr = v; return; }

private	int	getmsh(short int * bptr) { return( *bptr ); }
private	long	getml (long  int * bptr) { return( *bptr ); }

private	void	graphbar(int atx, int aty, int nbx, int nby, int fg )
{
	if ( nbx < 2 ) 
		filzone(atx,aty,nbx,nby,fg);
	else	relief(atx,aty,nbx,nby,standard_black,fg,standard_black);
}

private	void	bytegraph(int atx, int aty, int nbx, int nby, int f,int fg,int bg, unsigned char * vptr, int nbv, int state)
{
	unsigned char maxv=0;
	unsigned char minv=0xFF;
	int	extra;
	int	i;
	int	itw;
	int	span;
	if ( nbv > nbx ) {	nbv = nbx; itw = 1;	}
	else		 { 	itw = (nbx / nbv);	}

	for (i=0; i < nbv; i++ ) {
		if ( *(vptr+i) > maxv)		maxv = *(vptr+i);
		else if ( *(vptr+i) < minv )	minv = *(vptr+i);
		}

	if ( minv > maxv ) 		return;
	if (!( span = (maxv-minv) )) 	return;

	if ( span > nby ) {
		span = nby;
		extra = 0;
		}
	else	{
		extra = (nby - span);
		}
	for (i=0; i < nbv; i++ ) {
		if ((maxv = (*(vptr+i)-minv)) > span)
			maxv = span;
		if ( maxv )
			graphbar( atx,aty+(span-maxv),itw,maxv+extra,fg);
		atx+= itw;
		}
	return;
}


private	void	wordgraph(int atx, int aty, int nbx, int nby, int f,int fg,int bg, unsigned char * vptr, int nbv, int state)
{
	unsigned short maxv=0;
	unsigned short minv=0xFFFF;
	int	extra;
	int	i;
	int	itw;
	int	span;
	unsigned short	s=0;
	if ( nbv > nbx ) {	nbv = nbx; itw = 1;	}
	else		 { 	itw = (nbx / nbv);	}

	for (i=0; i < nbv; i++ ) {
		s = getash((vptr+(i*2)));
		if ( s > maxv)		maxv = s;
		else if ( s < minv )	minv = s;
		}

	if ( minv > maxv ) 		return;
	if (!( span = (maxv-minv) )) 	return;

	if ( span > nby ) {
		span = nby;
		extra = 0;
		}
	else	{
		extra = (nby -span);
		}
	for (i=0; i < nbv; i++ ) {
		s = getash((vptr+(i*2)));
		if ((maxv = (s-minv)) > span)
			maxv = span;
		if ( maxv )
			graphbar( atx,aty+(span-maxv),itw,maxv+extra,fg);
		atx+= itw;
		}
	return;
}

private	void	longgraph(int atx, int aty, int nbx, int nby, int f,int fg,int bg, unsigned char  * vptr, int nbv, int state)
{
	unsigned long l=0;
	unsigned long maxv=0;
	unsigned long minv=0xFFFFFFFFL;
	unsigned long v=0;
	int	extra=0;
	int	i;
	int	itw;
	int	span=0;
	if ( nbv > nbx ) {	nbv = nbx; itw = 1;	}
	else		 { 	itw = (nbx / nbv);	}

	for (i=0; i < nbv; i++ ) {
		l = getal((vptr+(i*4)));
		if ( l > maxv)		maxv = l;
		else if ( l < minv )	minv = l;
		}

	if ( minv > maxv ) {
 		return;
		}
	if (!( span = (maxv-minv) )) {
		return;
		}
	if ( span > nby ) {
		span = nby;
		extra = 0;
		}
	else	{
		extra = (nby -span);
		}

	for (i=0; i < nbv; i++ ) {
		l = getal((vptr+(i*4)));
		if ((v = (l-minv)) > span)
			v = span;
		if ( v )
			graphbar(atx,aty+(span-v),itw,v+extra,fg);
		atx+= itw;
		}
	return;
}

public	void	visual_graph(int atx, int aty, int nbx, int nby, int f,int fg,int bg, void * vptr, int nbv, int state)
{
	int	i;
	long	l;
	void	* wptr;

	if ( (!( nbx )) || (!( nby )) || (!( nbv )) ) return;

	filzone( atx,aty,nbx,nby, bg );

	if (!( vptr ))	return;


	switch ( state & 3 ) {
		case	0 : /* bytes */
			bytegraph(atx,aty,nbx,nby,f,fg,bg,(unsigned char *)vptr,nbv,state&3);
			break;
		case	1 : /* words */
			/*
			if ( state & 4 ) {
				for ( wptr=vptr,i=0; i < nbv; i++ ) {
					i = getash(wptr); putmsh(wptr,i);
					wptr = (((unsigned char *) wptr)+2);
					}							
				}
			*/
			wordgraph(atx,aty,nbx,nby,f,fg,bg,(unsigned short *)vptr,nbv,state&3);
			/*
			if ( state & 4 ) {
				for ( wptr=vptr,i=0; i < nbv; i++ ) {
					i = getmsh(wptr); putash(wptr,i);
					wptr = (((unsigned char *) wptr)+2);
					}							
				}
			*/
			break;
		case 	2 : /* longs */
			/*
			if ( state & 4 ) {
				for ( wptr=vptr,i=0; i < nbv; i++ ) {
					l = getal(wptr); putml(wptr,l);
					wptr = (((unsigned char *) wptr)+4);
					}							
				}
			*/
			longgraph(atx,aty,nbx,nby,f,fg,bg,(unsigned long *)vptr,nbv,state&3);
			/*
			if ( state & 4 ) {
				for ( wptr=vptr,i=0; i < nbv; i++ ) {
					l = getml(wptr); putal(wptr,l);
					wptr = (((unsigned char *) wptr)+4);
					}							
				}
			*/
			break;
		}
	return;
}

