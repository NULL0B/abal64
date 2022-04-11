public 	void	build_text(struct form_item * iptr )
{
	int			l,i,v,f;
	char	*		tptr;
	f = iptr->Contents.font;
	if ( iptr->Contents.w < Context.FontTable[f].width)
		iptr->Contents.w = Context.FontTable[f].width;
	if ( iptr->Contents.h < Context.FontTable[f].height)
		iptr->Contents.h = Context.FontTable[f].height;
	l = ((iptr->Contents.w/Context.FontTable[f].width)*
	     (iptr->Contents.h/Context.FontTable[f].height));
		
	if ((tptr = allocate((l+1))) != (char *) 0) {
		for (v='a',i=0; i < l; i++ ) {
			*(tptr+i) = v++;
			if ( v > 'z') v = 'a';
			}
		*(tptr+l) = 0;
		iptr->Contents.payload = tptr;
		iptr->Contents.size    = l;
		}
	return;
}

public 	void	resize_text(
			struct form_item * iptr,
			int	width, 
			int	height 
			)
{
	int	fh;
	int	fw;
	int	f;
	int	mr;
	int	tw;
	int	tlen;
	char * tptr;
	if      (!( tptr = iptr->Contents.payload ))	return;
	else if (!( tlen = iptr->Contents.size    ))	return;
	else if (!( f = iptr->Contents.font       ))	return;
	else if (!(fw = guifontsize(f)   	    ))	return;
	else if (!(fh =(fw >> 8)         	    ))	return;
	else	fw &= 0x00FF;

	iptr->Contents.w = width;
	iptr->Contents.h = height;
	mr = (iptr->Contents.h / fh);

	while ( tlen ) {
		if ((tw = textsizelen( f, tptr, tlen )) <= width)
			break;
		else if (tw < (mr * width))
			break;
		else	tlen--;
		}
	*( tptr+tlen) = 0;
	iptr->Contents.size = tlen;
	return;
}

public	int 	draw_text(int topx,int topy,struct form_item * iptr,int editing)
{
	int	fg;
	int	bg;

	if (!( iptr->Contents.payload ))
		return(0);

	fg = (iptr->Contents.colour&0x00FF);
	bg = (iptr->Contents.colour>>8);

	visual_text( topx+iptr->Contents.x, topy+iptr->Contents.y,
			iptr->Contents.w, iptr->Contents.h, iptr->Contents.font,fg,bg,
			iptr->Contents.payload, iptr->Contents.size, iptr->Contents.align);
	
	return(0);
}

public	int 	draw_frame_text(int topx,int topy,struct form_item * iptr,int editing)
{
	int	fg;
	int	bg;
	int	fh;

	if (!( iptr->Contents.payload ))
		return(0);

	if (!( fh = (guifontsize(iptr->Contents.font) >> 8)))
		fh =16;
	if ( fh > iptr->Contents.h )
		fh = iptr->Contents.h;
	fg = (iptr->Contents.colour&0x00FF);
	bg = (iptr->Contents.colour>>8);

	visual_text( topx+iptr->Contents.x, topy+iptr->Contents.y,
			iptr->Contents.w, fh, iptr->Contents.font,fg,bg,
			iptr->Contents.payload, iptr->Contents.size, iptr->Contents.align );
	return(0);
}

public	int 	edit_text(int topx,int topy,struct window_control* dptr)
{
	if (!( dptr->payload ))
		return(0);

	return( visual_edit( topx+dptr->x, topy+dptr->y,
			dptr->w, dptr->h, dptr->font,
			dptr->payload, dptr->size ) );

}

public	int 	zoom_text(struct window_control* dptr)
{
	return( edit_text( Context.DeskTop.x,Context.DeskTop.y,dptr ) );
}

