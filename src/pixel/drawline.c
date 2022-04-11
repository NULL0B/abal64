extern	void	filzone(int,int,int,int,int);

static	void	northeast(int fromx,int fromy, int tox, int toy, int thick, int colour, int (* output)() )
{
	int	l,c;
	long	nl=((fromy-toy)+1);
	long	nc=((tox-fromx)+1);
	int	nbc=0,nbl=0;
	long	lg,cg;
	long	lc,cc;
	if ( nc > nl ) {
		for (	l=0,lg=((nc*100)/nl),lc=100;	l < nl;	l++ ) {
			if ( lc >= 100 ) {
				(output)(fromx,fromy-l,(nbc = (lc/100)),thick,colour);
				fromx += nbc;
				lc %= 100;
				}
			lc += lg;
			}
		if ( lc >= 100 ) 
			(output)(fromx,fromy-l,(nbc = (lc/100)),thick,colour);
		}
	else	{
		for (	c=0,cg=((nl*100)/nc),cc=100;	c <nc;	c++ ) {
			if ( cc >= 100 ) {
				nbl = (cc/100);
				fromy -= nbl;
				(output)(fromx+c,fromy,thick,nbl,colour);
				cc %= 100;
				}
			cc += cg;
			}
		if ( cc >= 100 )
			(output)(fromx+c,fromy,thick,(nbl = (cc/100)),colour);
		}

}

static	void	southeast(int fromx,int fromy, int tox, int toy, int thick, int colour, int (*output)())
{
	int	l,c;
	long	nl=((toy-fromy)+1);
	long	nc=((tox-fromx)+1);
	int	nbc=0,nbl=0;
	long	lg,cg;
	long	lc,cc;
	if ( nc > nl ) {
		for (	l=0,lg=((nc*100)/nl),lc=100;l < nl;l++ ) {
			if ( lc >= 100 ) {
				(output)(fromx,fromy+l,(nbc = (lc/100)),thick,colour);
				fromx += nbc;
				lc %= 100;
				}
			lc += lg;
			}
		if ( lc >= 100 ) 
			(output)(fromx,fromy+l,(nbc = (lc/100)),thick,colour);
		}
	else	{
		for (	c=0,cg=((nl*100)/nc),cc=100;c < nc;c++ ) {
			if ( cc >= 100 ) {
				(output)(fromx+c,fromy,thick,(nbl = (cc/100)),colour);
				fromy += nbl;
				cc %= 100;
				}
			cc += cg;
			}
		if ( cc >= 100 ) 
			(output)(fromx+c,fromy,thick,(nbl = (cc/100)),colour);
		}

	return;
}

static	void	lldrawline(int fromx,int fromy, int tox, int toy, int thick, int colour, int (*output)(int,int,int,int,int) )
{
	if (!( output ))
		output = filzone;

	if ( fromx == tox ) {
		/* simple vertical */
		(output)( fromx,(toy > fromy ?fromy:toy),thick,((fromy > toy ?(fromy-toy):(toy-fromy))+1),colour);
		}
	else if ( fromy == toy ) {
		/* simple horizontal */
		(output)( (fromx>tox?tox:fromx),fromy,((fromx > tox?(fromx-tox):(tox-fromx))+1),thick,colour);
		}
	else if ( fromx < tox ) {
		if ( fromy < toy )
			southeast(fromx,fromy,tox,toy,thick,colour,output);
		else	northeast(fromx,fromy,tox,toy,thick,colour,output);
		}
	else if ( fromy < toy )
		northeast(tox,toy,fromx,fromy,thick,colour,output);
	else	southeast(tox,toy,fromx,fromy,thick,colour,output);

	return;
}

int drawline(int fx,int fy,int tx,int ty,int thick ,int pixel)
{
	lldrawline(fx,fy,tx,ty,thick,pixel,filzone);
	return(0);
}


