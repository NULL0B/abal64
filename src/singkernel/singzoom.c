#define	_ZOOM_BACKTAB	0
#define	_ZOOM_TAB	9
#define	_ZOOM_PAGEDOWN	3
#define	_ZOOM_PAGEUP	18


private	struct standard_image * ZoomClipBoard=(struct standard_image *) 0;
public	void	zoom_data( struct zoom_control * zptr );


private	void	zoom_xorzone(
		struct zoom_control * zptr, 
		int atx, int aty, int nbx, int nby, int p )
{
	struct window_control* dptr;
	int	r;
	int	c;
	int	zf;
	int	rowindent;
	int	colindent;
	char *	rptr;
	int	border;
	if ((zf   = zptr->factor) < 2 )
		border = 0;
	else	border = 1;
	dptr      = zptr->window;
	colindent = zptr->colindent;
	rowindent = zptr->rowindent;
	for (	r=0;
		r < nby;
		r++	) {
		for (	c=0;
			c<nbx;
			c++	) {
			xorzone(dptr->x+(((c+atx)*zf)+border),
				dptr->y+(((r+aty)*zf)+border),
				(zf-border),(zf-border),
				p);
			}
		}
	return;
}

private	void	zoom_filzone(
		struct zoom_control * zptr, 
		int atx, int aty, int nbx, int nby, int p )
{
	struct window_control* dptr;
	int	iw;
	int	r;
	int	c;
	int	zf;
	int	rowindent;
	int	colindent;
	char *	rptr;
	int	border;
	if ((zf   = zptr->factor) < 2 )
		border = 0;
	else	border = 1;
	dptr      = zptr->window;
	colindent = zptr->colindent;
	rowindent = zptr->rowindent;
	hide();
	for (	r=0,iw=zptr->image->columns;
		r < nby;
		r++	) {
		if (!(rptr = connect_pixel_row(
			zptr->image->storage,
			(r+aty+rowindent))))
			break;
		for (	c=0;
			c<nbx;
			c++	) {
			if ( (c+atx+colindent) >= iw )
				break;
			else	{
				*(rptr+c+atx+colindent) = p;
				filzone(dptr->x+(((c+atx)*zf)+border),
					dptr->y+(((r+aty)*zf)+border),
					(zf-border),(zf-border),
					p);
				}
			}
		}
	show(0,0,0,0);
	return;
}

public	void	zoomfill(int atx, int aty, int nbx, int nby, int p )
{
	zoom_filzone(Context.Zoom,atx,aty,nbx,nby,p);
}

public	void	zoomxor(int atx, int aty, int nbx, int nby, int p )
{
	zoom_xorzone(Context.Zoom,atx,aty,nbx,nby,p);
}

private	void	zoom_relief(struct zoom_control * zptr, int atx,int aty, int nbx, int nby, int hl, int bg, int ll )
{
	if ( bg != transparent )
		zoom_filzone(zptr,atx,aty,nbx,nby,bg);
	zoom_filzone(zptr,atx,aty,nbx,1,hl);
	zoom_filzone(zptr,atx,aty,1,nby,hl);
	zoom_filzone(zptr,(atx+nbx-1),aty,1,nby,ll);
	zoom_filzone(zptr,atx,(aty+nby-1),nbx,1,ll);
	return;
}

private	int	zoom_put_pixel(struct zoom_control * zptr, int x, int y )
{
	int	atx,aty;
	int	p;
	int	button;
	int	zf;
	button = visual_event(2);
	p = (button == _MIMO_LEFT ? Context.foreground : Context.background );
	if (!( zf = zptr->factor)) zf = 1;
	atx = (Context.Item.x/zf);
	aty = (Context.Item.y/zf);
	zoom_filzone(zptr,atx,aty,1,1,p);
	return(256);
}

private	void	replace_around(
	struct standard_image * iptr,
	unsigned int	atx,
	unsigned int	aty,
	unsigned int	oldcolour,
	unsigned int	newcolour )
{
	unsigned int	inx=atx;
	unsigned int	fnx=atx;
	unsigned char	*	bptr;

	if (!( bptr = connect_pixel_row( iptr->storage, aty ) )) {
		return;
		}

	else if ( *(bptr+atx) != oldcolour ) {
		return;
		}

	/* Find left margin on this row */
	/* ---------------------------- */
	for (	inx = atx; inx != 0; inx-- )
		if ( *(bptr+inx) != oldcolour )
			break;
		
	/* step over if not matching */
	/* ------------------------- */
	if ( *(bptr+inx) != oldcolour ) inx++;

	/* scan till end, replacing until not matching */
	/* ------------------------------------------- */
	for ( fnx = inx; fnx < iptr->columns; fnx++ ) {
		if ( *(bptr+fnx) != oldcolour )
			break;
		else	*(bptr+fnx) = newcolour;
		}

	if ( aty > 0 ) {

		if (!( bptr = connect_pixel_row( iptr->storage, (aty-1) ) )) {
			return;
			}

		/* scan till end, replacing until not matching */
		/* ------------------------------------------- */
		for ( atx = inx; atx < fnx; atx++ )
			if ( *(bptr+atx) == oldcolour )
				replace_around( iptr,atx,aty-1,oldcolour,newcolour );

		}

	if (( aty+1 ) < iptr->rows ) {

		if (!( bptr = connect_pixel_row( iptr->storage, (aty+1) ) )) {
			return;
			}

		/* scan till end, replacing until not matching */
		/* ------------------------------------------- */
		for ( atx = inx; atx < fnx; atx++ )
			if ( *(bptr+atx) == oldcolour )
				replace_around( iptr,atx,aty+1,oldcolour,newcolour );

		}
	return;

}


private	unsigned int	zoom_put_pixels(struct zoom_control * zptr, unsigned int x, unsigned int y )
{
	int	oldcolour;
	int	newcolour;
	unsigned int	atx,aty;
	unsigned int	p;
	unsigned int	button;
	unsigned int	zf;
	unsigned char *	rptr;
	if (!( zf = zptr->factor)) zf = 1;
	atx = (Context.Item.x/zf);
	aty = (Context.Item.y/zf);
	button = visual_event(2);
	if ((rptr = connect_pixel_row(
		zptr->image->storage,
		(aty+zptr->rowindent))) !=(char *) 0) {
		if ((oldcolour = (*(rptr + atx + zptr->colindent) & 0x00FF))
		!=  (newcolour = (button == _MIMO_LEFT ? Context.foreground : Context.background ) )) {
			replace_around( 
				zptr->image, 
				(atx+zptr->colindent),
				(aty+zptr->rowindent),
				oldcolour, newcolour );
			draw_console();
			}
		}
	return(256);
}

private	int	zoom_get_pixel(struct zoom_control * zptr, int x, int y )
{
	int	atx,aty;
	char *	rptr;
	int	zf;
	if (!( zf = zptr->factor)) zf = 1;
	atx = (x/zf);
	aty = (y/zf);
	if ((rptr = connect_pixel_row(
		zptr->image->storage,
		(aty+zptr->rowindent))) !=(char *) 0) {
		switch (visual_event(2)) {
			case	_MIMO_LEFT	:
				Context.foreground = *(rptr + atx + zptr->colindent );
				break;
			default			:
				Context.background = *(rptr + atx + zptr->colindent );
				break;
			}
		draw_ToolBar();
		}
	return(256);
}

public	void	zoom_circle(struct zoom_control * zptr, int atx, int aty, int width, int height, int p, int mode )
{
	int	x;
	int	y;
	int	yy;
	int	n;
	int	nb;
	int	nx=0;
	int	rr;
	int	radius;
	int	elipse;

	if ( width > height )
		radius = (height/2);
	else	radius = (width/2);

	rr = (radius*radius);
	
	atx += (width/2);
	aty += (height/2);

	for ( 	y=(radius-1); y > 0; y-- ) {
		yy = (y*y);
		x  = (radius-y);
		while (1) {
			if ((n=((x*x) + yy)) < rr) {
				x++;
				continue;
				}
			else if ( n > rr )
				x--;
			break;
			}
		if ( mode ) {
			zoom_filzone(zptr,atx-x,aty-y,x*2,1,p);
			zoom_filzone(zptr,atx-x,aty+(y-1),x*2,1,p);
			}
		else	{
			if ((nb=(x-nx)) <= 0) {
				nb=1;
				nx--;
				}

			/* Left Upper then lower */
			zoom_filzone(zptr,atx-x,aty-y,nb,1,p);
			zoom_filzone(zptr,atx-x,aty+(y-1),nb,1,p);

			zoom_filzone(zptr,atx+nx,aty-y,nb,1,p);
			zoom_filzone(zptr,atx+nx,aty+(y-1),nb,1,p);

			nx=x;
			}
		}
	return;

}

public	int	zoom_function(struct zoom_control * zptr, int style)
{
	struct window_control* dptr;
	struct	standard_image * iptr;
	int	atx,aty,nbx,nby;
	int	p;
	int	t;
	int	button;
	int	bg,fg;
	int	zf;

	button = visual_event(2);

	if (!( zf = zptr->factor)) zf = 1;

	if ( style == _LINE_FRAME ) {
		p = (button == _MIMO_LEFT ? Context.foreground : Context.background );
		atx = (Context.Item.x/zf);
		aty = (Context.Item.y/zf);
		nbx = (Context.Item.w/zf)+1;
		nby = (Context.Item.h/zf)+1;
		drawline(atx,aty,nbx,nby,Context.thickness,p,zoomfill);
		return(256);
		}

	if (Context.Item.w > Context.Item.x ) {
		atx = Context.Item.x;
		nbx = (Context.Item.w - Context.Item.x);
		}
	else	{
		atx = Context.Item.w;
		nbx = (Context.Item.x - Context.Item.w);
		}
	if (Context.Item.h > Context.Item.y ) {
		aty = Context.Item.y;
		nby = (Context.Item.h - Context.Item.y);
		}
	else	{
		aty = Context.Item.h;
		nby = (Context.Item.y - Context.Item.h);
		}
	atx /= zf;	aty /= zf;
	nbx /= zf;	nby /= zf;
	nbx++; nby++;

	if (button  != _MIMO_LEFT )
		style |= _FRAME_TRANSPARENT;

	switch (( style & _FRAME_TYPE )) {
		case	_OUTLINE_FRAME	:
			p = (button == _MIMO_LEFT ? Context.foreground : Context.background );
			zoom_relief( zptr, atx,aty,nbx,nby, p, transparent,p );
			break;
		case	_FILL_FRAME	:
			p = (button == _MIMO_LEFT ? Context.foreground : Context.background );
			zoom_filzone( zptr, atx,aty,nbx,nby, p );
			break;

		case	_OUTSET_FRAME :
			if ( style & _FRAME_INSIDE )
				bg = transparent;
			else if ( style & _FRAME_TRANSPARENT )
				bg = transparent;
			else	bg = standard_backwash;
			zoom_relief(zptr, atx,aty,nbx,nby,standard_hilight,bg,standard_lolight);
			if ( style & _FRAME_INSIDE)
				if (( nbx > 2 ) && ( nby > 2 )) 
					zoom_relief(zptr, atx+1,aty+1,nbx-2,nby-2,standard_backwash, transparent,standard_backwash);
			break;
		case	_INSET_FRAME  :
			if ( style & _FRAME_INSIDE )
				bg = transparent;
			else if ( style & _FRAME_TRANSPARENT )
				bg = transparent;
			else	bg = standard_backwash;
			zoom_relief(zptr, atx,aty,nbx,nby,standard_lolight,bg,standard_hilight);
			if ( style & _FRAME_INSIDE)
				if (( nbx > 2 ) && ( nby > 2 ))
					zoom_relief(zptr, atx+1,aty+1,nbx-2,nby-2,standard_backwash, transparent,standard_backwash);
			break;
		case	_RIDGE_FRAME  :
			if ( style & _FRAME_TRANSPARENT )
				bg = transparent;
			else	bg = standard_backwash;
			zoom_relief(zptr, atx,aty,nbx,nby,standard_hilight,bg,standard_lolight);
			if (( nbx > 2 ) && ( nby > 2 )) 
				zoom_relief(zptr,(atx+1),(aty+1),(nbx-2),(nby-2),standard_lolight,transparent,standard_hilight);
			break;
		case	_GROOVE_FRAME :
			if ( style & _FRAME_TRANSPARENT )
				bg = transparent;
			else	bg = standard_backwash;
			zoom_relief(zptr, atx,aty,nbx,nby,standard_lolight,bg,standard_hilight);
			if (( nbx > 2 ) && ( nby > 2 )) 
				zoom_relief(zptr, (atx+1),(aty+1),(nbx-2),(nby-2),standard_hilight,transparent,standard_lolight);
			break;

		case	_EDIT_FRAME :
			zoom_relief(zptr, atx,aty,nbx,nby,standard_black,standard_white,standard_black);
			break;

		case	_DISC_FRAME	:
			p = (button == _MIMO_LEFT ? Context.foreground : Context.background );
			zoom_circle(zptr, atx,aty,nbx,nby,p,1);
			break;
		case	_CIRCLE_FRAME	:
			p = (button == _MIMO_LEFT ? Context.foreground : Context.background );
			zoom_circle(zptr, atx,aty,nbx,nby,p,0);
			break;
		}
	return(256);

}

private	void	zoom_cursor_on(struct zoom_control * zptr, int mode)
{
	struct window_control* dptr;
	int	atx,aty,nbx,nby;
	int	p;
	int	t;
	int	button;
	int	bg,fg;
	int	zf;
	dptr = zptr->window;
	if (!( zf = zptr->factor)) zf = 1;
	if ( Context.Item.style == _LINE_FRAME ) {
		atx = (Context.Item.x/zf);
		aty = (Context.Item.y/zf);
		nbx = (Context.Item.w/zf)+1;
		nby = (Context.Item.h/zf)+1;
		drawline(atx,aty,nbx,nby,Context.thickness,0x0077,zoomxor);
		return;
		}
	if (Context.Item.w > Context.Item.x ) {
		atx = Context.Item.x;
		nbx = (Context.Item.w - Context.Item.x);
		}
	else	{
		atx = Context.Item.w;
		nbx = (Context.Item.x - Context.Item.w);
		}
	if (Context.Item.h > Context.Item.y ) {
		aty = Context.Item.y;
		nby = (Context.Item.h - Context.Item.y);
		}
	else	{
		aty = Context.Item.h;
		nby = (Context.Item.y - Context.Item.h);
		}
	atx /= zf;	aty /= zf;
	nbx /= zf;	nby /= zf;
	nbx++; nby++;

	atx *= zf;	aty *= zf;
	nbx *= zf;	nby *= zf;
	atx += dptr->x; aty += dptr->y;
	if ( Context.Item.style == _CIRCLE_FRAME ) 
		visual_frame(atx,aty,nbx,nby,_CIRCLE_FRAME);
	else if ( Context.Item.style == _DISC_FRAME ) 
		visual_frame(atx,aty,nbx,nby,_CIRCLE_FRAME);
	else	visual_frame(atx,aty,nbx,nby,_CUT_FRAME);
	return;
}

private void zoom_cursor_off(struct zoom_control * zptr, int mode)
{
	zoom_cursor_on(zptr,mode);
	return;
}


public	void	zoom_selection( int atx, int aty, int tox, int toy, int mode )
{
	Context.Item.w = tox;
	Context.Item.x = atx;
	Context.Item.h = toy;
	Context.Item.y = aty;
	if ( mode )
		Context.Item.style = _CUT_FRAME;
	else	Context.Item.style = -1;
	return;
}

private	show_zoom_event(struct zoom_control * zptr, int x,int y)
{
	int	t;
	int	zf;
	int	nbx;
	int	nby;
	char	buffer[64];

	if (!( zf = zptr->factor)) zf = 1;

	x = (x/zf); y = (y/zf);
	x += zptr->colindent;
	y += zptr->rowindent;
	if ( Context.Item.style == -1 ) {
		sprintf(buffer,"%u,%u",x,y);
		}
	else	{
		if ((nbx = (Context.Item.x/zf)) > x) {
			t = nbx;
			nbx=x;
			x =t;
			}
		if ((nby = (Context.Item.y/zf)) > y) {
			t = nby;
			nby=y;
			y =t;
			}
		sprintf(buffer,"%u,%u ... %u,%u",
			nbx,nby,((x-nbx)+1),((y-nby)+1));
		}
	status_message(buffer,1);	
}

private	void	zoom_vsb(struct zoom_control * zptr )
{
	int	zf;
	if (!( zf = zptr->factor)) zf = 1;
	if (zptr->window->h < zptr->image->rows) {
		visual_scrollbar(zptr->window->x+(zptr->window->w*zf),zptr->window->y,zptr->window->xlimit,(zptr->window->h*zf),
			Context.basefont,0,0, 
			zptr->rowindent,zptr->window->h,zptr->image->rows,((zptr->window->focus & 1 ? 0x0100 : 0) | _A_CENTER) );
		}
	return;
}

private int zoom_VSB_action( struct zoom_control * zptr ) {
	int aty=visual_event(6);
	int toy=visual_event(6);
	int	zf;
	if (!( zf = zptr->factor)) zf = 1;
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (zptr->window->y+zptr->window->xlimit)) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		zptr->rowindent -= 1;
		if (zptr->rowindent < 0) 
			zptr->rowindent = 0;
		zoom_data(zptr);
		return(-1);
		}
	if ( visual_event(6) > (zptr->window->y+((zptr->window->h*zf)-zptr->window->xlimit))) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		zptr->rowindent += 1;
		if (zptr->rowindent > (zptr->image->rows-(zptr->window->h*zf))) 
			zptr->rowindent = (zptr->image->rows-(zptr->window->h*zf));
		zoom_data(zptr);
		return(-1);
		}

	zptr->window->focus = 1;
	zoom_vsb(zptr);
	do 	{
		while(visual_getch() != 256);
		aty = zptr->rowindent;
		zptr->rowindent = (((visual_event(6) - (zptr->window->y+zptr->window->xlimit)) * zptr->image->rows) / ((zptr->window->h*zf) - (2 * zptr->window->xlimit)));
		if (zptr->rowindent < 0) 
			zptr->rowindent = 0;
		else if (zptr->rowindent > (zptr->image->rows-zptr->window->h)) 
			zptr->rowindent = (zptr->image->rows-zptr->window->h);
		if (zptr->rowindent != aty) {
			zoom_data(zptr);
			}
		}
	while (visual_event(1) != _MIMO_UP);
	zptr->window->focus = 0;
	zoom_vsb(zptr);
	return(1);
}

private	void	zoom_hsb(struct zoom_control * zptr )
{
	int	zf;
	if (!( zf = zptr->factor)) zf = 1;
	if (zptr->window->w < zptr->image->columns) {
		visual_scrollbar(zptr->window->x,zptr->window->y+(zptr->window->h*zf),(zptr->window->w*zf),zptr->window->ylimit,
			Context.basefont,0,0, 
			zptr->colindent,zptr->window->w,zptr->image->columns, ((zptr->window->focus & 2 ? 0x0100 : 0) | _A_CENTER) );
		}
	return;
}

private int zoom_HSB_action(struct zoom_control * zptr)
{
	int atx=visual_event(7);
	int tox=visual_event(7);
	int	zf;
	if (!( zf = zptr->factor)) zf = 1;
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }

	if ( visual_event(7) < (zptr->window->x+zptr->window->ylimit) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		zptr->colindent -= 1;
		if (zptr->colindent < 0) 
			zptr->colindent = 0;
		zoom_data(zptr);
		return(-1);
		}
	if ( visual_event(7) > (zptr->window->x+((zptr->window->w*zf)-zptr->window->ylimit)) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		zptr->colindent += 1;
		if (zptr->colindent > (zptr->image->columns-(zptr->window->w*zf))) 
			zptr->colindent = (zptr->image->columns-(zptr->window->w*zf));
		zoom_data(zptr);
		return(-1);
		}

	zptr->window->focus = 2;
	zoom_hsb(zptr);
	do 	{
		while(visual_getch() != 256);
		atx = zptr->colindent;
		zptr->colindent = (((visual_event(7) - (zptr->window->x+zptr->window->ylimit)) * zptr->image->columns) / ((zptr->window->w*zf) - (2 * zptr->window->ylimit)));
		if (zptr->colindent < 0) 
			zptr->colindent = 0;
		else if (zptr->colindent > (zptr->image->columns-zptr->window->w)) 
			zptr->colindent = (zptr->image->columns-zptr->window->w);
		if (zptr->colindent != atx) {
			zoom_data(zptr);
			}
		}
	while (visual_event(1) != _MIMO_UP);
	zptr->window->focus = 0;
	zoom_hsb(zptr);
	return(1);
}

public	int	is_ZoomEvent(struct zoom_control * zptr, int x, int y )
{
	int	frame_type;
	int	xv,yv;
	int	t;
	int	zf;
	if (!( zf = zptr->factor)) zf = 1;
	if (( x >= zptr->window->x ) 
	&&  ( y >= zptr->window->y )
	&&  ( x < (zptr->window->x+((zptr->window->w*zf)+zptr->window->xlimit))) 
	&&  ( y < (zptr->window->y+((zptr->window->h*zf)+zptr->window->ylimit)))) {

		x -= zptr->window->x;
		y -= zptr->window->y;

		if ((t = visual_event(1)) == _MIMO_DOWN) {

			if ( x > (zptr->window->w*zf))
				return( zoom_VSB_action( zptr ) );
			else if ( y > (zptr->window->h*zf))
				return( zoom_HSB_action( zptr ) );
			}

		show_zoom_event(zptr,x,y);

		switch ( t ) {

			case	_MIMO_MOVE	:
				return(256);

			case	_MIMO_DOWN	:
				Context.Item.w = Context.Item.x = x;
				Context.Item.h = Context.Item.y = y;

			case	_MIMO_WHILE_DOWN:

				if ( Context.Item.style == -1 ) {
					Context.Item.w = Context.Item.x = x;
					Context.Item.h = Context.Item.y = y;
					if ((Context.Item.style = Context.style) == _PIPE_FRAME) 
						zoom_get_pixel(zptr,Context.Item.x,Context.Item.y);
					else if ((Context.Item.style = Context.style) == _POUR_FRAME) 
						zoom_put_pixels(zptr,Context.Item.x,Context.Item.y);
					else if ((Context.Item.style = Context.style) != _PEN_FRAME) 
						zoom_cursor_on(zptr,0);
					else	zoom_put_pixel(zptr,Context.Item.x,Context.Item.y);
					}
				else if ((Context.Item.style = Context.style) == _PIPE_FRAME) 
					zoom_get_pixel(zptr,Context.Item.x,Context.Item.y);
				else if ((Context.Item.style = Context.style) == _POUR_FRAME) 
					zoom_put_pixels(zptr,Context.Item.x,Context.Item.y);
				else if ( Context.Item.style == _PEN_FRAME ) {
					zoom_put_pixel(zptr,(Context.Item.x=x),(Context.Item.y=y));
					}
				else	{
					zoom_cursor_off(zptr,1);
					Context.Item.w = x;
					Context.Item.h = y;
					zoom_cursor_on(zptr,1);
					}
				return(256);

			case	_MIMO_UP  	:
			case	_MIMO_CLICK	:
				if ( Context.Item.style == -1 ) {
					Context.Item.w = Context.Item.x = x;
					Context.Item.h = Context.Item.y = y;
					if ((Context.Item.style = Context.style) == _PIPE_FRAME) 
						zoom_get_pixel(zptr,Context.Item.x,Context.Item.y);
					else if ((Context.Item.style = Context.style) == _POUR_FRAME) 
						zoom_put_pixels(zptr,Context.Item.x,Context.Item.y);
					else if ((Context.Item.style = Context.style) == _PEN_FRAME) {
						zoom_put_pixel(zptr,(Context.Item.x),(Context.Item.y));
						Context.Item.style = -1;
						return(256);
						}
					}
				else if ( Context.Item.style == _PIPE_FRAME ) {
					Context.Item.style = -1;
					return(256);
					}
				else if ( Context.Item.style == _POUR_FRAME ) {
					Context.Item.style = -1;
					return(256);
					}
				else if ( Context.Item.style == _PEN_FRAME ) {
					zoom_put_pixel(zptr,(Context.Item.x=x),(Context.Item.y=y));
					Context.Item.style = -1;
					return(256);
					}
				else if ( Context.Item.style != _CUT_FRAME ) {
					zoom_cursor_off(zptr,0);
					Context.Item.w = x;
					Context.Item.h = y;
					}
				else	{
					Context.Item.w = x;
					Context.Item.h = y;
					}
				frame_type = Context.Item.style;
				Context.Item.style = -1;
				if ( frame_type == _MOVE_FRAME ) {
					if ( Context.Item.w > Context.Item.x ) {
						xv = ( Context.Item.w - Context.Item.x );
						if ( Context.Item.h > Context.Item.y ) {
							yv = ( Context.Item.h - Context.Item.y );
							if ( xv > yv )
								return( _ZOOM_BACKTAB );
							else	return( _ZOOM_PAGEUP );
							}
						else	{
							yv = ( Context.Item.y - Context.Item.h );
							if ( xv > yv )
								return(_ZOOM_BACKTAB );
							else	return(_ZOOM_PAGEDOWN );
							}
						}
					else	{
						xv = ( Context.Item.x - Context.Item.w );
						if ( Context.Item.h > Context.Item.y ) {
							yv = ( Context.Item.h - Context.Item.y );
							if ( xv > yv )
								return( _ZOOM_TAB );
							else	return( _ZOOM_PAGEUP );
							}
						else	{
							yv = ( Context.Item.y - Context.Item.h );
							if ( xv > yv )
								return( _ZOOM_TAB );
							else	return( _ZOOM_PAGEDOWN);
							}
						}
					return( 256 );
					}
				else if ( frame_type != _CUT_FRAME ) {
					return( zoom_function(zptr,frame_type) );
					}
				else	return( 256 );
			}

		}
	return(256);
}

public	void	zoom_frame( struct zoom_control * zptr )
{
	struct window_control* 	dptr;
	struct standard_image* 	iptr;
	int 			iw;
	int			ih;
	int			zf;
	int			x;
	int			vsbw=0;
	int			hsbh=0;

	filzone(Context.DeskTop.x,Context.DeskTop.y,Context.DeskTop.w,Context.DeskTop.h,Context.background);

	if (!( zptr ))
		return;

	else if (!( dptr = zptr->window ))
		return;
	else if (!( iptr = zptr->image ))
		return;
	else	{
		iw   = iptr->columns;
		ih   = iptr->rows;
		if (!( zf   = zptr->factor )) zf = 1;
		}

	dptr->x = dptr->y = dptr->w = dptr->h = 0; dptr->focus = 0;
	dptr->xlimit 	  = dptr->ylimit = 0;

	/* Check for horizontal scoll bar needed */
	/* ------------------------------------- */
	if (( iptr->columns * zf ) > Context.DeskTop.w ) {
		dptr->ylimit = (Context.fontwidth*2);
		if (( iptr->rows * zf ) > (Context.DeskTop.h-dptr->ylimit))
			dptr->xlimit = (Context.fontwidth*2);
		}
	else if (( iptr->rows * zf ) > Context.DeskTop.h) {
		dptr->xlimit = (Context.fontwidth*2);
		if (( iptr->columns * zf ) > (Context.DeskTop.w-dptr->xlimit) )
			dptr->ylimit = (Context.fontwidth*2);
		}

	/* Check for vertical scoll bar needed */
	/* ----------------------------------- */
	if (( iptr->rows * zf ) > Context.DeskTop.h ) {
		dptr->ylimit = (Context.fontwidth*2);
		}
	else	dptr->ylimit = 0;

	if ((dptr->w = ((Context.DeskTop.w-dptr->xlimit) / zf)) > iw)
		dptr->w = iw;

	if ((dptr->h = ((Context.DeskTop.h-dptr->ylimit) / zf)) > ih)
		dptr->h = ih;

	if (!( dptr->xlimit ))
		dptr->x = ((Context.DeskTop.w - (dptr->w*zf)) / 2);
	else	{
		dptr->x = 0;
		}

	if (!( dptr->ylimit ))
		dptr->y = ((Context.DeskTop.h - (dptr->h*zf)) / 2);
	else	{
		dptr->y = 0;
		}

	dptr->x += Context.DeskTop.x;
	dptr->y += Context.DeskTop.y;
	draw_grid(dptr->x, dptr->y, dptr->w, dptr->h, zf, _EDIT_FRAME );
	return;
}

public	void	zoom_data( struct zoom_control * zptr )
{
	struct window_control* dptr;
	struct	standard_image * iptr;
	int	colindent;
	int	rowindent;
	int	zf;
	char	* bptr;
	int	r;
	int	c;
	int	border;
	if (!( zptr ))
		return;
	else	{
		dptr = zptr->window;
		iptr = zptr->image;
		if (!(zf   = zptr->factor)) zf = 1;
		if ( zf < 2 )
			border = 0;
		else	border = 1;
		colindent = zptr->colindent;
		rowindent = zptr->rowindent;
		}
	hide();
	for ( r=0; r < dptr->h; r++ ) {
		if (!(bptr = connect_pixel_row(iptr->storage,(r+rowindent) ))) {
			if (!( border ))
				filzone(dptr->x,dptr->y+r,dptr->w,1,_DEFAULT_GUI_WHITE);
			else	{
				for (c=0; c < dptr->w; c++ )
					filzone(dptr->x+((c*zf)+border),dptr->y+((r*zf)+border),(zf-border),(zf-border),_DEFAULT_GUI_WHITE);
				}
			}
		else	{
			if (!( border ))
				putzone(dptr->x,dptr->y+r,dptr->w,1,(bptr + colindent));

			else	{
				for (c=0; c < dptr->w; c++ )
					filzone(dptr->x+((c*zf)+border),dptr->y+((r*zf)+border),(zf-border),(zf-border),*(bptr+(c+colindent)));
				}
			}
		}
	zoom_hsb(zptr);
	zoom_vsb(zptr);
	show (	dptr->x, dptr->y, (dptr->w*zf)+dptr->xlimit, (dptr->h*zf)+dptr->ylimit );
	return;
}

public	void	refresh_ZoomWindow()
{
	if ( Context.Zoom ) {
		zoom_frame(Context.Zoom);
		zoom_data(Context.Zoom);
		}
	return;
}

/*	Rotation : 2 : Rotation of 180 degrees 	*/

private	int	image_rotation2( struct zoom_control * zptr )
{
	struct	standard_image * iptr;

	if (!( zptr )) 				return(0);
	else if (!( iptr = zptr->image ))	return(0);

	vrotate180( iptr->storage );

	return(1);
}

/*	Rotation : 1 and 3 : Rotation of 90  degrees 	*/

private	int	image_rotation1( struct zoom_control * zptr, int mode )
{
	struct	standard_image * iptr;
	struct	standard_image * rptr;

	if (!( zptr )) 	
		return(0);
	else if (!( iptr = zptr->image ))
		return(0);
#ifdef	PROLOGUE
	if ( iptr->columns > 16000 )
		return(0);
#endif
	if (!( rptr = local_allocate_image( iptr->rows, iptr->columns,0,0) ))
		return(0);

	if ( vrotate(( mode == _ZOOM_ROTATE1 ? 1 : 0 ), 
			rptr->storage, iptr->storage ) != 0) {
		local_drop_image( rptr );
		return(27);
		}

	zptr->image = rptr;

	local_drop_image( iptr );

	return(1);
}

/*	Rotation : 1 and 3 : Rotation of 90  degrees 	*/

private	int	image_reflect_h( struct zoom_control * zptr )
{
	char	*	tptr;
	char	*	bptr;
	int		tr;
	int		br;
	int		nc;
	int		nr;
	int		pixel;
	struct	standard_image * iptr;

	if (!( zptr )) 				return(0);
	else if (!( iptr = zptr->image ))	return(0);

	for ( 	nr=(iptr->rows/2),
		tr=0,br=(iptr->rows-1); 
		nr != 0; nr--,tr++,br-- ) {
		if (!(tptr = connect_pixel_row( iptr->storage, tr )))
			break;
		else if (!(bptr = connect_pixel_row( iptr->storage, br )))
			break;
		for (	nc=0; nc < iptr->columns; nc++ ) {
			pixel = *(tptr+nc);
			*(tptr+nc) = *(bptr+nc);
			*(bptr+nc) = pixel;
			}
		}
	return(1);

}

private	int	image_zap_colour( struct zoom_control * zptr )
{
	char	*	tptr;
	int		nc;
	int		nr;
	struct	standard_image * iptr;

	if (!( zptr )) 				return(0);
	else if (!( iptr = zptr->image ))	return(0);

	for ( 	nr=0;
		nr < iptr->rows;
		nr++ ) {
		if (!(tptr = connect_pixel_row( iptr->storage, nr )))
			break;
		for (	nc=0; nc < iptr->columns; nc++ )
			if ( *(tptr+nc) == Context.background )
				*(tptr+nc) = Context.foreground;
		}
	return(1);

}

private	int	image_grey_colour( struct zoom_control * zptr )
{
	char	*	tptr;
	int		nc;
	int		nr;
	struct	standard_image * iptr;

	if (!( zptr )) 				return(0);
	else if (!( iptr = zptr->image ))	return(0);

	for ( 	nr=0;
		nr < iptr->rows;
		nr++ ) {
		if (!(tptr = connect_pixel_row( iptr->storage, nr )))
			break;
		for (	nc=0; nc < iptr->columns; nc++ )
			*(tptr+nc) = rgb_to_grey( *(tptr+nc) );

		}
	return(1);

}

private	int	image_reflect_v( struct zoom_control * zptr )
{
	char	*	bptr;
	int		lc;
	int		rc;
	int		nr;
	int		nc;
	int		pixel;
	struct	standard_image * iptr;

	if (!( zptr )) 				return(0);
	else if (!( iptr = zptr->image ))	return(0);

	for ( 	nr=0;
		nr < iptr->rows;
		nr++ ) {
		if (!(bptr = connect_pixel_row( iptr->storage, nr )))
			break;
		for (	nc=(iptr->columns/2),
			lc=0,rc=(iptr->columns-1);
			nc != 0;
			lc++,nc--,rc--) {
			pixel = *(bptr+lc);
			*(bptr+lc) = *(bptr+rc);
			*(bptr+rc) = pixel;
			}
		}
	return(1);

}

private	void	zstretch_rows(
	struct standard_image * rptr,
	struct standard_image * iptr
	)
{
	int	th=rptr->rows;
	int	tw=rptr->columns;
	int	sh=iptr->rows;
	int	sw=iptr->columns;
	int	nr = (th / sh);
	int	missing = (th - (nr*sh));
	int	r=0;
	int	srow;
	int	trow;
	char *	sptr;
	char *	tptr;
	int	when=0;
	int	previous=0;
	int	pixelsize=1;

	if ( missing ) 
		if (!(when = ( th / missing )))
			when = 1;

	/* source row count is smallest so use as control */ 
	/* ---------------------------------------------- */
	for ( srow=0,trow=0; srow < sh; srow++ ) {

		if (!( sptr = connect_pixel_row( iptr->storage,srow ) ))
			break;

		if (!( tptr = connect_pixel_row( rptr->storage,trow ) ))
			break;

		else if ( tw > sw ) {
			istretch_columns( tptr, tw, sptr, sw, pixelsize );
			}
		else if ( tw < sw ) {
			isquash_columns( tptr, tw, sptr, sw, pixelsize );
			}
		else 	memcpy(tptr,sptr,tw);

		nr = (th / sh);
		if ( missing ) {
			if (((trow+nr)/when) > previous) {
				nr++;
				missing--;
				}
			}

		/* repeat it through target rows */
		/* ----------------------------- */
		sptr = tptr; trow++;
		for ( r=1; r < nr; r++ ) { 
			if (trow >= th )
				break;
			else if (!( tptr = connect_pixel_row( rptr->storage,trow++ ) ))
				break;
			else	memcpy(tptr,sptr,tw);
			}

		if ( missing ) {
			previous = (trow/when);
			}
		}
	return;
}

private	void	zsquash_rows(
	struct standard_image * rptr, struct standard_image * iptr
	)
{
	int	trow;
	int	th=rptr->rows;
	int	tw=rptr->columns;
	int	sh=iptr->rows;	
	int	sw=iptr->columns;
	char *	sptr;
	char *	tptr;
	int	pixelsize=1;

	/* target row count is smallest so use as control */ 
	/* ---------------------------------------------- */
	for ( trow=0; trow < th; trow++ ) {
		if (!( sptr = connect_pixel_row( iptr->storage,((trow * sh)/th) ) ))
			break;
		else if (!( tptr = connect_pixel_row( rptr->storage,trow ) ))
			break;
		else if ( tw > sw )
			istretch_columns( tptr, tw, sptr, sw, pixelsize );
		else if ( tw < sw )
			isquash_columns( tptr, tw, sptr, sw, pixelsize );

		else 	memcpy(tptr,sptr,tw);
		}
	return;
}

private	void	image_makefit(
	struct	standard_image * rptr,
	struct	standard_image * iptr )
{
	char *	tptr;
	char *	sptr;
	int	trow;
	int	tw;
	int	pixelsize=1;

	if ((!( rptr->rows )) || (!( rptr->columns )))
		return;
	else if ( rptr->rows > iptr->rows )
		zstretch_rows( rptr,iptr );
	else if ( iptr->rows > rptr->rows )
		zsquash_rows( rptr,iptr );
	else	{
		for ( tw=rptr->columns,trow=0; trow < rptr->rows; trow++ ) {
			if (!( sptr = connect_pixel_row( iptr->storage,trow ) ))
				break;
			else if (!( tptr = connect_pixel_row( rptr->storage,trow ) ))
				break;
			else if ( tw > iptr->columns ) {
				istretch_columns( tptr, rptr->columns, sptr, iptr->columns,pixelsize );
				}
			else if ( tw > iptr->columns ) {
				isquash_columns( tptr, rptr->columns, sptr, iptr->columns,pixelsize );
				}
			else 	memcpy(tptr,sptr,tw);
			}
		}
	return;
}

private	void	image_copy_paste( struct zoom_control * zptr, int function )
{
	struct window_control* dptr;
	int	atx;
	int	aty;
	int	nbx;
	int	nby;	
	int	r;
	int	zf;
	struct	standard_image * iptr;
	char	* sptr;
	char	* tptr;
	int	colindent;
	int	rowindent;
	if (!(zf = zptr->factor)) zf = 1;
	dptr      = zptr->window;
	colindent = zptr->colindent;
	rowindent = zptr->rowindent;

	if ( Context.Item.x > Context.Item.w ) {
		atx = (Context.Item.w/zf);
		nbx = (((Context.Item.x-Context.Item.w)/zf)+1);
		}
	else	{
		atx = (Context.Item.x/zf);
		nbx = (((Context.Item.w-Context.Item.x)/zf)+1);
		}
	if ( Context.Item.y > Context.Item.h ) {
		aty = (Context.Item.h/zf);
		nby = (((Context.Item.y-Context.Item.h)/zf)+1);
		}
	else	{
		aty = (Context.Item.y/zf);
		nby = (((Context.Item.h-Context.Item.y)/zf)+1);
		}


	switch ( function ) {

		case	_ZOOM_COPY	:

			/*
			printf("\ncopy %u,%u %u,%u \n",atx,aty,nbx,nby);
			*/
			if (!( iptr = local_allocate_image( nbx, nby,0, 0 ) ))
				break;

			for (r=0; r < nby; r++ ) {
				if (!( sptr = connect_pixel_row( zptr->image->storage, r+aty+rowindent ) ))
					break;
				else if (!( tptr = connect_pixel_row( iptr->storage, r ) ))
					break;
				memcpy( tptr, (sptr+atx+colindent), nbx );
				}

			if ( ZoomClipBoard != (struct standard_image *) 0 ) {
				ZoomClipBoard = local_drop_image( ZoomClipBoard );
				}
			ZoomClipBoard = iptr;
			zoom_cursor_off(zptr,0);
			break;

		case	_ZOOM_PASTE	:
			if (!( iptr = ZoomClipBoard ))
				break;
			else if (!(nby = iptr->rows))
				break;
			else if (!(nbx = iptr->columns))
				break;
			/*
			printf("\npaste at  %u,%u %u,%u \n",atx,aty,nbx,nby);
			*/
			for (r=0; r < nby; r++ ) {
				if (!( tptr = connect_pixel_row( zptr->image->storage, r+aty+rowindent ) ))
					break;
				else if (!( sptr = connect_pixel_row( iptr->storage, r ) ))
					break;
				memcpy( (tptr+atx+colindent), sptr, nbx );
				}
			zoom_data( zptr );
			zoom_cursor_off(zptr,0);
			break;
		}
	return;
}

private	int	image_dimensions( struct zoom_control * zptr )
{
	int	lwidth;
	int	lheight;
	int	makefit;
	struct	standard_image * iptr;
	struct	standard_image * rptr;
	char *	tptr;
	char *	sptr;
	int	r,xc;
	if (!( zptr )) 				return(0);
	else if (!( iptr = zptr->image ))	return(0);

	lwidth = iptr->columns;
	lheight= iptr->rows;
	makefit= 0;

	if ( accept_image_dimensions( &lwidth, &lheight, &makefit ) == 27 )
		return(0);
	else if (!( lwidth ))
		return(0);
	else if (!( lheight ))
		return(0);
	else if (!( rptr = local_allocate_image( lwidth, lheight,0,0) ))
		return(0);
	else if (!( makefit )) {
		if ( iptr->columns > rptr->columns )
			xc = rptr->columns;
		else	xc = iptr->columns;
		for (	r=0;
			r < rptr->rows;
			r++ ) {
			if (!( tptr = connect_pixel_row( rptr->storage, r ) ))
				break;
			memset( tptr, Context.background, rptr->columns);
			if (( r < iptr->rows ) 
			&&  (( sptr = connect_pixel_row( iptr->storage, r )) != (char *) 0))
				memcpy( tptr,sptr,xc);
			}
		}
	else	image_makefit( rptr, iptr );
		
	zptr->image = rptr;
	local_drop_image( iptr );
	return(1);
}


public	int	image_reset( struct standard_image * iptr)
{
	int	r;
	char *  rptr;
	if (!( iptr ))
		return(0);
	for (	r=0; r < iptr->rows; r++ ) {
		if (!( rptr = connect_pixel_row( iptr->storage, r ) ))
			break;
		else	memset(rptr,Context.background,iptr->columns);
		}
	return(1);
}

public	int	edit_Image(char * payload, struct standard_image ** extra )
{
	struct	zoom_control	Zoom;
	struct 	window_control	Window;
	int	e;
	int	adjust;
	int	newindent;
	if (!( extra ))
		return(0);
	if (!( Zoom.image = *extra))
		return(0);
	else	{
		Zoom.window = &Window;
		Zoom.factor = 4;
		Zoom.colindent = 0;
		Zoom.rowindent = 0;
		}

	Context.Item.style = -1;

	add_zoom_editor_menu();

	zoom_frame(&Zoom);

	if (( Window.w != 0) && (Window.h != 0)) {
	
		add_zoom_editor_menu();

		/* Recalculate the Visible portion */
		if (( Context.FontContext ) 
		&&  ( Context.Item.style != -1 )) {
			while ( Context.Item.w > Window.w ) {
				if ( Context.Item.x > (Window.w/4) ) {
					Context.Item.x -= (Window.w/4); 
					Context.Item.w -= (Window.w/4); 
					Zoom.colindent += (Window.w/4);
					if (( Zoom.colindent + Window.w ) > Zoom.image->columns) {
						newindent = (Zoom.image->columns - Window.w);
						adjust = Zoom.colindent - newindent;
						Context.Item.x += adjust; 
						Context.Item.w += adjust;
						Zoom.colindent = newindent;
						break;
						}
					}
				else	break;
				}
			while ( Context.Item.h > Window.h ) {
				if ( Context.Item.y > (Window.h/4) ) {
					Context.Item.y -= (Window.h/4); 
					Context.Item.h -= (Window.h/4); 
					Zoom.rowindent += (Window.h/4);
					if (( Zoom.rowindent + Window.h ) > Zoom.image->rows) {
						Zoom.rowindent = (Zoom.image->rows - Window.h);
						break;
						}
					}
				else	break;
				}
			}
		Context.Zoom = &Zoom;

		use_image_tools();
		draw_console();

		if (( Context.FontContext ) 
		&&  ( Context.Item.style != -1 )) {
			Context.Item.x *= Zoom.factor;
			Context.Item.y *= Zoom.factor;
			Context.Item.w *= Zoom.factor;
			Context.Item.h *= Zoom.factor;
 			zoom_cursor_on(&Zoom,0);
			}


		while (1) {
			if (((e = visual_getch()) == 256)
			&&  ((e = handle_event()) == 256))
				continue;

			switch (e) {
				case	27	:
				case	13	:
					draw_console();
				case	_LEAVE_SING :
					break;

				case	_ZOOM_COPY	:
				case	_ZOOM_PASTE	:
					image_copy_paste( &Zoom,e );
					continue;

				case	'*'	:
					if ( Zoom.factor < 64 ) {
						Zoom.factor *= 2;
						zoom_frame( &Zoom );
						Zoom.colindent = Zoom.rowindent = 0;
						zoom_data( &Zoom );
						}
					continue;
				case	'/'	:
					if ( Zoom.factor > 1 ) {
						Zoom.factor /= 2;
						zoom_frame( &Zoom );
						Zoom.colindent = Zoom.rowindent = 0;
						zoom_data( &Zoom );
						}
					continue;
					
				case	CTRL_B	: /* bot right */
					if ((Zoom.colindent = (Zoom.image->columns - Window.w)) < 0)
						Zoom.colindent = 0;
					if ((Zoom.rowindent = (Zoom.image->rows - Window.h)) < 0)
						Zoom.rowindent = 0;
					zoom_data( &Zoom );
					continue;

				case	CTRL_L	:
				case	0x001C	: /* Top LEft */
					if ((Zoom.colindent != 0) || (Zoom.rowindent != 0)) {
						Zoom.colindent = Zoom.rowindent = 0;
						zoom_data( &Zoom );
						}
					continue;

				case	CTRL_K	: /* Line Up */
					if ( Zoom.rowindent > 0 ) {
						Zoom.rowindent--;
						zoom_data( &Zoom );
						}
					continue;

				case	CTRL_H	: /* column left */
					if ( Zoom.colindent > 0 ) {
						Zoom.colindent--;
						zoom_data( &Zoom );
						}
					continue;


				case	_ZOOM_BACKTAB	:
					if ( Zoom.colindent != 0) {
						if ( Zoom.colindent > (Window.w/2) )
							Zoom.colindent -= (Window.w/2);
						else	Zoom.colindent =  0;
						zoom_data( &Zoom );
						}
					continue;

				case	CTRL_F	: /* column right */
					if (( Zoom.colindent + Window.w ) < Zoom.image->columns) {
						Zoom.colindent++;
						zoom_data( &Zoom );
						}	
					continue;

				case	_ZOOM_TAB		:
					Zoom.colindent += (Window.w/2);
					if (( Zoom.colindent + Window.w ) > Zoom.image->columns)
						Zoom.colindent = (Zoom.image->columns - Window.w);
					zoom_data( &Zoom );
					continue;

				case	 CTRL_E	: /* line down */
					if (( Zoom.rowindent + Window.h ) < Zoom.image->rows ) {
						Zoom.rowindent++;
						zoom_data( &Zoom );
						}
					continue;

				case	_ZOOM_PAGEDOWN	:
					Zoom.rowindent += (Window.h/2);
					if (( Zoom.rowindent + Window.h ) > Zoom.image->rows)
						Zoom.rowindent = (Zoom.image->rows - Window.h);
					zoom_data( &Zoom );
					continue;

				case	_ZOOM_PAGEUP	:
					if ( Zoom.rowindent != 0) {
						if ( Zoom.rowindent > (Window.h/2) )
							Zoom.rowindent -= (Window.h/2);
						else	Zoom.rowindent =  0;
						zoom_data( &Zoom );
						}
					continue;
						
				case	_ZOOM_ROTATE2	:
					if ( image_rotation2(&Zoom) )
						draw_console();
					continue;

				case	_ZOOM_ROTATE1	:
				case	_ZOOM_ROTATE3	:
					if ( image_rotation1(&Zoom,e) )
						draw_console();
					continue;

				case	_ZOOM_REFLECTX	:
					if ( image_reflect_h(&Zoom) )
						draw_console();
					continue;

				case	_ZOOM_GREY  	:
					if ( image_grey_colour(&Zoom) )
						draw_console();
					continue;

				case	_ZOOM_COLOUR	:
					if ( image_zap_colour(&Zoom) )
						draw_console();
					continue;

				case	_ZOOM_REFLECTY	:
					if ( image_reflect_v(&Zoom) )
						draw_console();
					continue;

				case	_ZOOM_CHANGE 	:
					if ( image_dimensions(&Zoom) )
						draw_console();
					continue;


				case	_EDIT_IMAGE	:
					if ( treeview_is_active())
						break;
					else	continue;

				case	_EXEC_PROG	:
				case	_VIEW_TEXT	:
				case	_VIEW_IMAGE	:
				case	_EDIT_TEXT 	:
				case	_EDIT_TREEVIEW	:
				case	_EDIT_FORM	:
				case	_EDIT_GRAPH	:
				case	_EDIT_FONT	:
					break;
				case	_FILE_NEW	:
					if ( image_reset(Zoom.image) )
						draw_console();
					continue;
				case	_FILE_LOAD	:
					image_load(payload,extra);
					Zoom.image = *extra;
					zoom_frame(&Zoom);
					draw_console();
					continue;

				case	_FILE_QSAVE 	:
					image_save(payload,Zoom.image,QUICK);
					continue;
				case	_FILE_SAVE 	:
				case	_FILE_IMAGE	:
				case	_FILE_PRODUCE	:
					image_save(payload,Zoom.image,0);
					continue;

				default		:
					if (!( Context.FontContext )) 
						continue;
					else if ((e >= 'A') && (e <='Z'))
						break;
					else if ((e >= 'a') && (e <='z'))
						break;
					else if ((e >= '0') && (e <='9'))
						break;
					else	continue;
				}
			break;
			}

		if (( Context.FontContext ) 
		&&  ( Context.Item.style != -1 )) 
			zoom_cursor_off(&Zoom,0);

		*extra = Zoom.image;

		Context.Zoom = (struct zoom_control *) 0;
		drop_tool_manager();
		drop_zoom_editor_menu();
		return( e );

		}	
	else	return(0);
}


