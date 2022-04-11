#ifndef	_window_c
#define	_window_c

int	asfun_pixel_colour( int cicocolour )
{
	switch ( cicocolour ) {
		case	1 	: return(4);
		case	9 	: return(12);
		case	12 	: return(9);
		case	3 	: return(6);
		case	5 	: return(3);
		case	11 	: return(14);
		case	14 	: return(11);
		case	7 	: return(8);
		case	8 	: return(7);
		default	  	: return( cicocolour );
		}

}


void	cadre( int x, int y, int w , int h, int t, int r, int b, int l, int bg )
{
	hide();
	if ( bg )
		filzone(x,y,w,h,bg);
	if ( t )
		filzone(x,y,w,1,t);
	if ( r )
		filzone(x+w,y,1,h,r);
	if ( l )
		filzone(x,y,1,h,l);
	if ( b )
		filzone(x,y+h,w,1,b);
	show(x,y,w,h);
	return;
}

public	void	window_pos(struct asfun_window * wptr)
{
	pos(wptr->atlin,wptr->atcol);
	return;
}

public	void	window_paint(struct asfun_window * wptr)
{
	paint(wptr->fg,wptr->bg);
	return;
}

private	int	implicite_window(int h)
{
	struct	asfun_window * wptr;
	if (!( wptr = Control.windows[h] ))
		return(4);
	else	{
		/* Active current implicite window */
		/* ------------------------------- */
		if ( wptr->frozen )
			background_pixel_capture(wptr->storage);
		else if (!( wptr->visible ))
			background_pixel_capture(wptr->storage);
		else	foreground_pixel_capture(wptr->storage);
		use_base_font(Control.basefont);
		cicowindow(0,0,wptr->grw,wptr->grh);
		window_pos(wptr);
		window_paint(wptr);
		if ( wptr->scroll )
			enable_scroll();
		else	inhibit_scroll();
		if ( wptr->cursor )
			enable_cursor();
		else	inhibit_cursor();
		Control.capture = (h+1);
		return(0);
		}
}

public	void	clear_implicite_window()
{
	int	h;
	struct	asfun_window * wptr;
	if (!( Control.capture ))
	if ((h = Control.capture) != 0) {
		if ((wptr = Control.windows[(h-1)]) != (struct asfun_window*) 0) {
			wptr->atcol = x_col(1);
			wptr->atlin = x_lin(1);
			}
		Control.capture = 0;
		}
	cancel_pixel_capture((char *) 0);
	use_base_font(Control.basefont);
	cicowindow(0,0,Control.w,Control.h);
	return;
}

public	void	use_implicite_window()
{
	if ( Control.implicite > 0 )
		implicite_window((Control.implicite-1));
	else	clear_implicite_window();
	return;
}

int	allocate_window(struct asfun_window * wptr)
{
	sprintf(asfun_stylename,"asfun/window_filler%u",( wptr->style > 5 ? 1 : wptr->style ));
	wptr->grx = (wptr->x-1)*Control.gfw;
	wptr->gry = (wptr->y-1)*Control.gfh;
	wptr->grw = (wptr->w*Control.gfw);
	wptr->grh = (wptr->h*Control.gfh);
	if (!( wptr->storage = allocate_graphic_storage( wptr->grx, wptr->gry,wptr->grw,wptr->grh) )) 
		return(0);
	else	{
		background_pixel_capture(wptr->storage);
		visual_element(0,0,wptr->grw,wptr->grh,asfun_stylename," ",0);
		use_implicite_window();
		return(1);
		}
}

private	void	wclear(struct asfun_window * wptr, int h)
{
	if ( bedug ) printf("wclear(%u)\r\n",h);
	implicite_window(h-1);
	filzone(0,0,wptr->grw,wptr->grh,asfun_pixel_colour(wptr->bg));
	clear_implicite_window();
	use_implicite_window();
	return;	
}	

private	void	wcleos(struct asfun_window * wptr, int h)
{
	if ( bedug ) printf("wcleos:escJ(%u)\r\n",h);
	implicite_window(h-1);
	v_putch( 27 );
	v_putch( 'J');
	clear_implicite_window();
	use_implicite_window();
	return;	
}	

private	void	wcleol(struct asfun_window * wptr, int h)
{
	if ( bedug ) printf("wcleol:escL(%u)\r\n",h);
	implicite_window(h-1);
	v_putch( 27 );
	v_putch( 'K');
	clear_implicite_window();
	use_implicite_window();
	return;	
}	

private	void	winsln(struct asfun_window * wptr, int h)
{
	if ( bedug ) printf("winsln:escL(%u)\r\n",h);
	implicite_window(h-1);
	v_putch( 27 );
	v_putch( 'L');
	clear_implicite_window();
	use_implicite_window();
	return;	
}	

private	void	wdelln(struct asfun_window * wptr, int h)
{
	if ( bedug ) printf("wdelln:escM(%u)\r\n",h);
	implicite_window(h-1);
	v_putch( 27 );
	v_putch( 'M');
	clear_implicite_window();
	use_implicite_window();
	return;	
}	

private	void	wscrup(struct asfun_window * wptr, int h)
{
	int	atcol=wptr->atcol;
	int	atlin=wptr->atlin;
	if ( bedug ) printf("wscrup:escM(%u)\r\n",h);
	wptr->atcol = wptr->atlin=1;
	implicite_window(h-1);
	v_putch( 27 );
	v_putch( 'M');
	clear_implicite_window();
	wptr->atcol = atcol;
	wptr->atlin = atlin;
	use_implicite_window();
	return;	
}	

private	void	wscrdw(struct asfun_window * wptr, int h)
{
	int	atcol=wptr->atcol;
	int	atlin=wptr->atlin;
	if ( bedug ) printf("wscrdw:escL(%u)\r\n",h);
	wptr->atcol = wptr->atlin=1;
	implicite_window(h-1);
	v_putch( 27 );
	v_putch( 'L');
	clear_implicite_window();
	wptr->atcol = atcol;
	wptr->atlin = atlin;
	use_implicite_window();
	return;	
}	

private	void	winsrg(struct asfun_window * wptr, int h)
{
	return;	
}	

private	void	winslf(struct asfun_window * wptr, int h)
{
	return;	
}	

private	void	wcuron(struct asfun_window * wptr, int h)
{
	implicite_window(h-1);
	v_putch( 27 );
	v_putch( 'v');
	clear_implicite_window();
	use_implicite_window();
	return;	
}	

private	void	wcurof(struct asfun_window * wptr, int h)
{
	implicite_window(h-1);
	v_putch( 27 );
	v_putch( 'w');
	clear_implicite_window();
	use_implicite_window();
	return;	
}	

private	void	winsch(struct asfun_window * wptr, int h)
{
	implicite_window(h-1);
	v_putch( 27 );
	v_putch( 'C');
	clear_implicite_window();
	use_implicite_window();
	return;	
}	

private	void	wdelch(struct asfun_window * wptr, int h)
{
	implicite_window(h-1);
	v_putch( 27 );
	v_putch( '@');
	clear_implicite_window();
	use_implicite_window();
	return;	
}

struct	asfun_window * 	remove_window(struct asfun_window * wptr)
{
	if (wptr) {
		liberate(wptr);
		}
	return( (struct	asfun_window *) 0);
}

struct	asfun_window *	create_window()
{
	struct	asfun_window * wptr;
	if (!( wptr = allocate( sizeof( struct asfun_window ) ) ))
		return(wptr);
	else	{
		memset(wptr->titre,32,_MAX_TITLE);
		wptr->menu = wptr->list = wptr->dbox = 0;
		wptr->x  = wptr->y  =
		wptr->fg = wptr->bg =
		wptr->w  = wptr->h  = 0;
		wptr->grx	=
		wptr->gry	=
		wptr->grw	=
		wptr->grh	= 0;
		wptr->implicite = 
		wptr->visible	=
		wptr->scroll 	=
		wptr->shadow	= 
		wptr->cursor	= 0;
		wptr->border 	=
		wptr->frozen	=
		wptr->font	= 0;
		wptr->atcol	= 
		wptr->atlin	= 1;
		wptr->style	= 0;
		return(wptr);
		}
}


void	move_window( struct asfun_window * wptr, int tocol, int tolin )
{
	int	wasvisible;
	wptr->x = tocol;
	wptr->y = tolin;
	wptr->grx = ((wptr->x-1)*Control.gfw);
	wptr->gry = ((wptr->y-1)*Control.gfh);
	clear_implicite_window();
	move_pixel_capture( wptr->storage, wptr->grx, wptr->gry );
	show_windows();
	use_implicite_window();
	return;
}

void	draw_window( struct asfun_window * wptr )
{
	int	grx,gry,grw,grh;
	int	r;
	int	stylenumber;
	char *	rptr;

	if ( wptr->visible ) {

		grx = wptr->grx;
		gry = wptr->gry;
		grw = wptr->grw;
		grh = wptr->grh;

		switch ( wptr->style ) {
			case	0 :
				if ( wptr->titre[0] == ' ' ) {
					switch ( wptr->border ) {
						case	2 : 
							if (( grx >= 3 ) && ( gry >= 3))
								cadre(grx-3,gry-3,grw+6,grh+6,15,17,17,15,0);
						case	1 : 
							if ((grx >= 1 ) && ( gry >= 1 ))
								cadre(grx-1,gry-1,grw+2,grh+2,17,17,15,15,wptr->bg); 
							break;
						case	3 : 
							if ((grx >= 2 ) && (gry >= 2))
								cadre(grx-2,gry-2,grw+4,grh+4,15,17,17,15,wptr->bg); 
							break;
						}
					}
				else	{
					switch ( wptr->border ) {
						case	2 : 
							if (( grx >= Control.gfw ) && ( gry >= Control.gfh))
								cadre(grx-Control.gfw,gry-Control.gfh,grw+(Control.gfw*2),grh+(Control.gfh*2),15,17,17,15,0);
						case	1 : 
							if ((grx >= 1 ) && ( gry >= 1 ))
								cadre(grx-1,gry-1,grw+2,grh+2,17,17,15,15,wptr->bg); 
							break;
						case	3 : 
							if ((grx >= (Control.gfw/2) ) && (gry >= 2))
								cadre(grx-(Control.gfw/2),gry-(Control.gfh/2),grw+((Control.gfw/2)*2),grh+((Control.gfh/2)*2),15,17,17,15,wptr->bg); 
							break;
						}
					if ( bedug ) printf("draw_window::filzone(colour=%u)\r\n",wptr->fg);
					filzone(grx+1,gry,grw-2,Control.gfh-2,wptr->fg);		
					}
				break;
			default	 :
				if ((stylenumber = wptr->style) > 5)
					stylenumber = 1;
				if ( wptr->shadow ) {
					sprintf(asfun_stylename,"asfun/window_shadow%u",stylenumber);
					visual_element(grx-Control.gfw,gry-Control.gfh,
						grw+(Control.gfw*2),grh+(Control.gfh*2),
						asfun_stylename," ",0);
					}
				if ( wptr->border ) {
					sprintf(asfun_stylename,"asfun/window_frame%u",stylenumber);
					visual_element(grx-Control.gfw,gry-Control.gfh,
						grw+(Control.gfw*2),grh+(Control.gfh*2),
						asfun_stylename," ",0);
					sprintf(asfun_stylename,"asfun/window_inner%u",stylenumber);
					visual_element(grx-Control.gfw,gry-Control.gfh,
						grw+(Control.gfw*2),grh+(Control.gfh*2),
						asfun_stylename," ",0);
					}
				if ( wptr->lentit ) {
					sprintf(asfun_stylename,"asfun/window_title%u",stylenumber);
					visual_element(grx-Control.gfw,gry-Control.gfh,
						grw+(Control.gfw*2),grh+(Control.gfh*2),
						asfun_stylename,wptr->titre,wptr->lentit);
					}
				break;
			}
		if (!( wptr->storage ))
			return;
		else	{
			for (r=0; r < grh; r++ ) {
				if (!( rptr = connect_pixel_row( wptr->storage, r ) ))
					break;
				if (!( wptr->bg ))
					mixzone(grx,gry+r,grw,1,rptr);
				else	putzone(grx,gry+r,grw,1,rptr);
				}
			}
		}
	return;
}

private	void	display_window( struct asfun_window * wptr )
{
	
	if (!( wptr ))
		return;
	else if (!( wptr->visible ))
		return;
	else if ( wptr->menu )
		show_menu( Control.menus[(wptr->menu-1)] );
	else if ( wptr->list )
		show_list( Control.menus[(wptr->list-1)] );
	else if ( wptr->dbox )
		show_dbox( Control.menus[(wptr->dbox-1)] );
	else	draw_window( wptr );
}

private	void	show_statusbar()
{
	int	atx;
	int	aty;
	int	nby;
	int	nbx;
	int	n;
	int	i;
	if ( Control.statusbar  != 0 ) {
		atx=0; aty=((Control.statusline-1)*Control.gfh);
		nbx = (Control.nbc*Control.gfw);
		nby = Control.gfh;
		for (i=0,n=0; i < 128; i++ ) { if ( Control.statusmessage[i] != ' ' ) { n = (i+1); } }
		switch ( Control.statustype ) {
			case	0 : visual_element(atx,aty,nbx,nby,"asfun/statusbar",Control.statusmessage,n); break;
			case	1 : visual_element(atx,aty,nbx,nby,"asfun/commentbar",Control.statusmessage,n); break;
			case	2 : visual_element(atx,aty,nbx,nby,"asfun/warningbar",Control.statusmessage,n); break;
			case	3 : visual_element(atx,aty,nbx,nby,"asfun/errorbar",Control.statusmessage,n); break;
			}
		}
	return;
}

void	show_window( struct asfun_window * wptr )
{
	clear_implicite_window();
	draw_window( wptr );
	use_implicite_window();
	return;
}

private	void	show_windows()
{
	int	i;
	if ( Control.freeze ) return;
	clear_implicite_window();
	inhibit_cursor();
	inhibit_scroll();
	hide();
	if ( visual_element(0,0,Control.w,Control.h,"asfun/background"," ",0) != 0 ) {
		if (!( Control.options & 2 ))
			filzone(0,0,Control.w,Control.h,0);
		else	filzone(0,0,Control.w,Control.h,asfun_pixel_colour(Control.bg));
		}

	for (i=0; i < _MAX_WINDOWS; i++ ) {
		if ( Control.windows[i] ) {
			if ( (i+1) != Control.active ) {
				display_window( Control.windows[i] );
				}
			}
		}
	if ( Control.active )
		display_window( Control.windows[Control.active-1] );

	show_statusbar();
	show(0,0,Control.w,Control.h);
	use_implicite_window();
	return;
}

#endif	/* _window_c */
	/* --------- */

