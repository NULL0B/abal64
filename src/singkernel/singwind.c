public	int 	edit_message(int topx,int topy,struct window_control* dptr)
{
	int	holdh;
	int	f;
	int	fh;
	int	status;
	if (!( dptr ))
		return(0);
	else if (!( f = dptr->font ))
		return(0);
	else if (!( fh = Context.FontTable[f].height))
		return(0);
	else	{
		holdh = dptr->h;
		dptr->h = fh;
		status = edit_text( topx+4, topy+4, dptr );
		dptr->h = holdh;
		return( status );
		}

}

public 	void	build_title(struct form_item * iptr, char * mptr )
{
	int			l,i,v,f;
	char	*		tptr;

	f = iptr->Contents.font;

	if ( iptr->Contents.w < (Context.FontTable[f].width*4))
		iptr->Contents.w = (Context.FontTable[f].width*4);

	if ( iptr->Contents.h < (Context.FontTable[f].height * 2))
		iptr->Contents.h = (Context.FontTable[f].height*2);

	l = ((iptr->Contents.w/Context.FontTable[f].width)-2);
		
	if ((tptr = allocate((l+1))) != (char *) 0) {
		if (!( mptr )) {
			for (v='a',i=0; i < l; i++ ) {
				*(tptr+i) = v++;
				if ( v > 'z') v = 'a';
				}
			*(tptr+l) = 0;
			iptr->Contents.payload = tptr;
			iptr->Contents.size    = l;
			}
		else	{
			for ( i=0; i < l; i++ )
				if (!( *(tptr+i) = *(mptr+i) ))
					break;
			*(tptr+i) = 0;
			iptr->Contents.payload = tptr;
			iptr->Contents.size    = i;
			}
		}
	return;
}

public	void	draw_window(int topx,int topy,struct form_item * iptr,int focus)
{
	struct form_control * fptr;
	int	v;
	int	natlang=-1;
	int	oldlang=-1;
	if (!( iptr ))
		return;
	if (((fptr = iptr->parent) != (struct form_control*) 0)
	&&  (fptr->formflags & _MULTILINGUAL )) {
		v = _WINDOW_LANG_BUTTON;
		oldlang = visual_national_language((natlang = fptr->natlang));
		}
	else	{
		v = 0;
		natlang=-1;
		}

	switch ( iptr->Contents.style & _FRAME_TYPE ) {
		case	_WINDOW_FRAME 	:
			visual_window( 	topx+iptr->Contents.x,topy+iptr->Contents.y,
					iptr->Contents.w,iptr->Contents.h,
					iptr->Contents.font,check_payload(iptr->Contents.payload),iptr->Contents.size,
				((iptr->Contents.align&_A_SHADOW)| v |
				((iptr->Contents.align&_A_BOLD) ? 1 : 0 ) | 
				((iptr->Contents.align&_A_LINE) ? 2 : 0 ) )
				);
			if ( natlang != -1 ) {
				(void) visual_national_language(oldlang);
				}
			return;
		case	_TAB_FRAME 	:
			visual_tabpage( topx+iptr->Contents.x,topy+iptr->Contents.y,
					iptr->Contents.w,iptr->Contents.h,
					iptr->Contents.font,check_payload(iptr->Contents.payload),
					iptr->Contents.size, iptr->Contents.adjust, focus );
			return;
		default			:
			return;
		}
}


