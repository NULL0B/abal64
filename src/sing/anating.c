int			frametype=3;
int			celltype=4;
int			celledit=5;
unsigned	char *	bytes;
unsigned 	char  	symbols[12];
int			pc=0;
int			zid=0;
int			zones[10][100];
int			labels=0;
int			labelpos[4][100];
unsigned 	char *	labelval[100];
int			fontheight=24;
int			fontwidth=10;
void	ZDI_FRAMEGR(int atcol,int atlin, int nbcol, int nblin, char * mptr)
{
	return;
}

void	ZDI_CADREGR(FILE * h, int atcol,int atlin, int nbcol, int nblin, int dx, int dy, int type )
{
	int	gx,gy;
	int	gnx,gny;
	printf("ZDI_CADRE(%u,%u,%u,%u)\r\n",atcol,atlin,nbcol,nblin);
	gx = ((atcol-1)*fontwidth)+dx;
	gnx = ((nbcol*fontwidth)-(dx*2));
	if (!( atlin ))
		gy = dy;
	else	gy = ((atlin-1)*fontheight)+dy;
	
	gny = ((nblin*fontheight)-(dy*2));
	if ( type == 0 ) {
		gny -= 12;
		fprintf(h,"\tVisualFill(%u,%u,%u,%u,%u,%u)\r\n",gx,gy,gnx,gny,0x1400,12);
		}
	else	{
		fprintf(h,"\tVisualZone(%u,%u,%u,%u,%u)\r\n",gx,gy,gnx,gny,type);

/*
 *		if (dx == 0 ) {
 *			VisualImage(gx+2,gy+2,gnx-4,gny-4,BACKWASH,Len$(BACKWASH),512+4)
 *			}
 *		else	{
 *			VisualImage(gx+2,gy+2,gnx-4,gny-4,BACKFILL,Len$(BACKFILL),512+4)
 *			}
 */
		}
	return;
}

void	ZDI_LABELGR(int atcol, int atlin, int item )
{
	return;
}

char *	substr( char * sptr, int slen, int offset, int length )
{
	return( sptr );
}


int	index( char * sptr, int slen, int v )
{
	int	i;
	for ( 	i=0; i < slen; i++ )
		if (( *(sptr+i) & 0x00FF) == ( v & 0x00FF ))
			return( (i+1) );
	return( 0 );
}


void	ouvre(int c, int l)
{
	zid += 1;
	zones[1][zid] = c;
	zones[2][zid] = l;
	zones[3][zid] = c;
	zones[4][zid] = l;
	zones[5][zid] = (fontwidth/2);
	zones[6][zid] = (fontheight/2);
	zones[7][zid] = celltype;
	return;
}

int	fermv(int c, int l) 
{
	int	z;
	z = zid;
	while ( z != 0 ) {
		if ( zones[7][z] != celledit ) {
			if ( zones[1][z] == pc ) {
				zones[4][z] = ((l - zones[2][z] )+1);
				break;
				}
			}
		z -= 1;
		}
	return(z);

}

int	fermh(int c, int l)
{
	int	z;
	z = zid;
	while ( z != 0 ) {
		if ( zones[7][z] != celledit ) {
			if ( zones[2][z] == l ) {
				if ( zones[3][z] == zones[1][z] ) {
					zones[3][z] = ((c - zones[1][z] )+1);
					break;
					}
				}
			}
		z -= 1;
		}
	return(z);
}

void	backlabel(int c, int l,int nbcol )
{
	int	x;
	x = (c-1);
	while ( x > 0 ) {
		if ( index(symbols, 12,  *(bytes + x +(l*nbcol)) ) != 0 ) {
			x += 1;
			break;
			}
		else	{
			x -= 1;
			}
		}
	if ( x == 0 ) {
		x = 1;	
		}
	while (1) {
		if ( *(bytes + x +(l*nbcol)) != ' ' ) {
			if (index(symbols, 12, *(bytes + x +(l*nbcol))) == 0 ) {
				break;
				}
			}
		if ( x < nbcol ) {
			x += 1;
			}
		else	{
			break;
			}
		}
	if ( x < c ) {
		if ( labels < 100 ) {
			labels += 1;
			labelpos[1][labels] = x;
			labelpos[2][labels] = l;
			labelpos[3][labels] = (c-x);
			labelpos[4][labels] = 0;
			labelval[labels] = substr( (bytes +(l*nbcol)), nbcol,x,(c-x));
			}
		}
	return;

}

void	banalyse(FILE * h, int atcol, int atlin, int nbcol, int nblin, unsigned char * mptr, int ombre, int cadre )
{
	int	z;
	int		i,j,l,c,x,y,pc,t;

	bytes = mptr;
	symbols[0]  = 	218; 	symbols[1]  = 	194;
	symbols[2]  = 	191;	symbols[3]  = 	195;
	symbols[4]  = 	197;	symbols[5]  = 	180;
	symbols[6]  = 	192;	symbols[7]  = 	193;
	symbols[8]  = 	217;	symbols[9]  = 	58 ;
	symbols[10] = 	179;	symbols[11] = 	46 ;
	zid = 0; labels = 0;

	if ( *mptr == 217 ) {
		*mptr = 218;
		*(mptr+(nblin*nbcol)-1) = 217;
		}

	ZDI_FRAMEGR(atcol,atlin,nbcol,nblin,mptr);

	if ( zid == 0 ) {
		if ( cadre != 0 ) {
			zid = 1;
			zones[1][zid]=1;
			zones[2][zid]=1;
			zones[3][zid]=nbcol;
			zones[4][zid]=nblin;
			zones[5][zid]=0;
			zones[6][zid]=0;
			zones[7][zid]=frametype;
			}
		}

	if ( ombre != 0 ) {
		for ( z = 0; z < 10; z++ ) {
			zones[z][zid+1] = zones[z][zid];
			}
		zones[1][zid] += 1;
		zones[2][zid] += 1;
		zones[7][zid]=0;
		zid += 1;
		}

	for ( l=0; l < nblin; l++ ) {

		for ( c=0; c < nbcol; c++ ) {

			t = index(symbols, 12, *(bytes+c+(l*nbcol)));

			switch (t) {

				case	1		: /** Haut a Gauche 	*/
					ouvre(c,l);
					break;

				case	2 		: /** Haut Mileu	*/
					z = fermh(c,l);
					ouvre(c,l);
					break;

				case	3		: /** Coin Haut Droit	*/
					z = fermh(c,l);
					break;

				case	4 		: /** Mileu Gauche	*/
					pc = c;
					z = fermv(c,l);
					ouvre(c,l);
					break;

				case	5 		: /** Le centre		*/
					z = fermh(c,l);
					if ( z == 0 ) 	{	break;  	}
					pc = zones[1][z];
					z = fermv(c,l);
					ouvre(c,l);
					break;

				case	6		: /** Mileu Droit	*/
					pc = c;
					z = fermv(c,l);
					z = fermh(c,l);
					break;

				case	7		: /** Coin Bas Gauche	*/
					pc = c;
					z = fermv(c,l);
					break;

				case	8		: /** Milieu Bas	*/
					/* ;fermh(c,l); */
					pc = c;
					z= fermv(c,l);
					break;

				case	9		: /** Coin Bas Doit	*/
					z = fermh(c,l);
					if ( z == 0 ) 	{	break;  	}
					pc = zones[1][z];
					z = fermv(c,l);
					break;

				case	10		: /** Fin de libell‚	*/
					backlabel(c,l,nbcol);
					break;

				case	11		: /** Trait verticale on ignore  */
					backlabel(c,l,nbcol);
					break;

				}
			}
		c = 1;
		while ( c <= nbcol ) {
			if ( index(symbols, 12, *(bytes+c+((l+1)*nbcol))) == 12 ) {
				zid += 1;
				zones[1][zid] = c;
				zones[2][zid] = (l+1);
				zones[3][zid] = c;
				zones[4][zid] = (l+1);
				zones[5][zid] = 1;
				zones[6][zid] = 1;
				zones[7][zid] = celledit;
				while ( c <= nbcol ) {
					if (index(symbols, 12, *(bytes+(c-1)+((l+1)*nbcol))) == 12) {
						c += 1;
						}
					else	{
						break;
						}
					}
				zones[3][zid] = ((c - zones[1][zid] )+1);
				if ( zones[3][zid] > 1 )
					zones[4][zid] = 1;
				else	{
					if ( c == 1 ) {
						zones[4][zid] = 1;
						}
					else	{
						if ( *(bytes+(c-1)+((l+1)*nbcol)) == ' ') {
							zones[4][zid] = 1;
							}
						else	{
							zid -= 1;
							}
						}
					}
				}
			c += 1;
			}
		}
	for (	z =  1;
		z <= zid;
		z++ ) {
		ZDI_CADREGR(h,atcol+zones[1][z],atlin+zones[2][z],zones[3][z],zones[4][z],zones[5][z],zones[6][z],zones[7][z]);
		}

	for (	z = 0;
		z < labels;
		z++ ) {
		ZDI_LABELGR(atcol,atlin,z);
		}
	return;
}

int	detect(unsigned char * bytes, int atcol, int atlin, int nbcol ,int nblin )
{
	int	c;
	int	l;
	ouvre(atcol,atlin);
	for (	c=(atcol+1); c < nbcol; c++ ) {
		switch (index(symbols, 12, *(bytes+c+(atlin*nbcol)))) {
			case	3 : /* Haut a Droite */
				break;
			default	  :
				continue;
			}
		break;
		}
	if ( c > nbcol )
		c--;
	zones[3][zid] = ((c - zones[1][zid] )+1);

	for (	l=(atlin+1); l < nblin; l++ ) {
		switch (index(symbols, 12, *(bytes+c+(l*nbcol)))) {
			case	9 : /** Droite Bas 	*/
				zones[4][zid] = ((l - zones[2][zid] )+1);
				break;
			default	  :
				continue;
			}
		break;
		}
	return;
}

void	analyse(FILE * h, int atcol, int atlin, int nbcol, int nblin, unsigned char * mptr, int ombre, int cadre )
{
	int	z;
	int		i,j,l,c,x,y,pc,t;
	atcol -= 1;
	/* ecran = mptr; */
	bytes = mptr;
	symbols[0]  = 	218; 	symbols[1]  = 	194;
	symbols[2]  = 	191;	symbols[3]  = 	195;
	symbols[4]  = 	197;	symbols[5]  = 	180;
	symbols[6]  = 	192;	symbols[7]  = 	193;
	symbols[8]  = 	217;	symbols[9]  = 	58 ;
	symbols[10] = 	179;	symbols[11] = 	46 ;
	zid = 0; labels = 0;

	if ( *mptr == 217 ) {
		*mptr = 218;
		*(mptr+(nblin*nbcol)-1) = 217;
		}

	ZDI_FRAMEGR(atcol,atlin,nbcol,nblin,mptr);

	if ( zid == 0 ) {
		if ( cadre != 0 ) {
			zid = 1;
			zones[1][zid]=1;
			zones[2][zid]=1;
			zones[3][zid]=nbcol;
			zones[4][zid]=nblin;
			zones[5][zid]=0;
			zones[6][zid]=0;
			zones[7][zid]=frametype;
			}
		}

	if ( ombre != 0 ) {
		for ( z = 0; z < 10; z++ ) {
			zones[z][zid+1] = zones[z][zid];
			}
		zones[1][zid] += 1;
		zones[2][zid] += 1;
		zones[7][zid]=0;
		zid += 1;
		}

	for ( l=0; l < nblin; l++ ) {

		for ( c=0; c < nbcol; c++ ) {

			switch ((t = index(symbols, 12, *(bytes+c+(l*nbcol))))) {
				case	1 : /* HAG */
					detect(bytes,c,l,nbcol,nblin);
					continue;
				default		:
					continue;
				}
			}
		c = 1;
		while ( c <= nbcol ) {
			if ( index(symbols, 12, *(bytes+c+(l*nbcol))) == 12 ) {
				zid += 1;
				zones[1][zid] = c;
				zones[2][zid] = l;
				zones[3][zid] = c;
				zones[4][zid] = l;
				zones[5][zid] = 1;
				zones[6][zid] = 1;
				zones[7][zid] = celledit;
				while ( c <= nbcol ) {
					if (index(symbols, 12, *(bytes+(c-1)+(l*nbcol))) == 12) {
						c += 1;
						}
					else	{
						break;
						}
					}
				zones[3][zid] = ((c - zones[1][zid] )+1);
				if ( zones[3][zid] > 1 )
					zones[4][zid] = 1;
				else	{
					if ( c == 1 ) {
						zones[4][zid] = 1;
						}
					else	{
						if ( *(bytes+(c-1)+(l*nbcol)) == ' ') {
							zones[4][zid] = 1;
							}
						else	{
							zid -= 1;
							}
						}
					}
				}
			c += 1;
			}
		}
	for (	z =  1;
		z <= zid;
		z++ ) {
		ZDI_CADREGR(h,atcol+zones[1][z],atlin+zones[2][z],zones[3][z],zones[4][z],zones[5][z],zones[6][z],zones[7][z]);
		}
	for (	z = 0;
		z < labels;
		z++ ) {
		ZDI_LABELGR(atcol,atlin,z);
		}
	return;
}




