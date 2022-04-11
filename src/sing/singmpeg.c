#ifndef	_singmpeg_c
#define	_singmpeg_c

#define	_RED_MASK8	 0x0007
#define	_RED_MASK16	 0x001F
#define	_RED_MASK32	 0x00FF

#define	_GREEN_MASK8	 0x0003
#define	_GREEN_MASK16	 0x001F
#define	_GREEN_MASK32	 0x00FF

#define	_BLUE_MASK8	 0x0007
#define	_BLUE_MASK16	 0x001F
#define	_BLUE_MASK32	 0x00FF

static	int	mpegIndentValue=0;

void	mpeg_indent(FILE *h)
{
	int	i;
	for ( i=0; i < mpegIndentValue; i++ )
		fprintf(h,"  ");
	return;
}

void	mpeg_enter()
{
	mpegIndentValue++;
	return;
}

void	mpeg_leave()
{
	if ( mpegIndentValue )
		mpegIndentValue--;
	return;
}

void	mpeg_ascii_colour( char * b, int v )
{
	if ( v >= 100 )
		sprintf(b,"0.%03.1u",v);
	else if ( v >= 10 )
		sprintf(b,"0.0%02.1u",v);
	else	sprintf(b," 0.00%u",v);
	return;
}

void	mpeg_colour( int x, char * bptr )
{
	int	r=0;
	int	g=0;
	int	b=0;

	char	rs[16];
	char	bs[16];
	char	gs[16];

	int	redmask=_RED_MASK16;
	int	bluemask=_BLUE_MASK16;
	int	greenmask=_GREEN_MASK16;

	get_rgb_values(x,&r,&g,&b);	

	r = ((r*1000)/(redmask+1));
	g = ((g*1000)/(greenmask+1));
	b = ((b*1000)/(bluemask+1));

	mpeg_ascii_colour( rs, r );
	mpeg_ascii_colour( gs, g );
	mpeg_ascii_colour( bs, b );

	sprintf(bptr,"%s %s %s",rs,gs,bs);

	return;

}

void	mpeg_production( int w, int h )
{
	ProductionWindow.w = w ;
	ProductionWindow.h = h;
	return;
}


void	mpeg_translation( char * b, int x, int y, int w, int h )
{
	int	cx;
	int	cy;
	x -= (ProductionWindow.w / 2);
	cy = (ProductionWindow.h / 2);
	if ( y <= cy )
		y = ( cy - y );
	else	y = -(y - cy);
	x += (w/2);
	y -= (h/2);
	sprintf(b,"%d %d",x,y);
	return;
}

void	mpeg_translation_vector( struct window_control * r, int x, int y, int w, int h )
{
	int	cx;
	int	cy;
	x -= (ProductionWindow.w / 2);
	cy = (ProductionWindow.h / 2);
	if ( y <= cy )
		y = ( cy - y );
	else	y = -(y - cy);
	x += (w/2);
	y -= (h/2);
	r->x = x;
	r->y = y;
	return;
}

void	mpeg_translation3d( char * b, int x, int y, int w, int h, int z )
{
	int	cx;
	int	cy;
	x -= (ProductionWindow.w / 2);
	cy = (ProductionWindow.y / 2);
	if ( y <= cy )
		y = ( cy - y );
	else	y = -(y - cy);
	x += (w/2);
	y -= (h/2);
	sprintf(b,"%d %d %d",x,y,z);
	return;
}

#endif	/* _singmpeg_c */
	/* ----------- */

