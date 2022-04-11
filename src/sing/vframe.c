int	visual_frame( int atx, int aty, int nbx, int nby, int style )
{
	int	bg;

	if (( nbx > 0 ) && ( nby > 0 )) {

	switch (( style & _FRAME_TYPE )) {

		case	0	:
			relief(atx,aty,nbx,nby,1,2,3);
			break;

		case	_OUTSET_FRAME :
			if ( style & _FRAME_INSIDE )
				bg = transparent;
			else if ( style & _FRAME_TRANSPARENT )
				bg = transparent;
			else	bg = standard_backwash;
			relief( atx,aty,nbx,nby,standard_hilight,bg,standard_lolight);
			if ( style & _FRAME_INSIDE)
				if (( nbx > 2 ) && ( nby > 2 )) 
					relief( atx+1,aty+1,nbx-2,nby-2,standard_backwash, transparent,standard_backwash);
			break;

		case	_INSET_FRAME  :
			if ( style & _FRAME_INSIDE )
				bg = transparent;
			else if ( style & _FRAME_TRANSPARENT )
				bg = transparent;
			else	bg = standard_backwash;
			relief( atx,aty,nbx,nby,standard_lolight,bg,standard_hilight);
			if ( style & _FRAME_INSIDE)
				if (( nbx > 2 ) && ( nby > 2 ))
					relief( atx+1,aty+1,nbx-2,nby-2,standard_backwash, transparent,standard_backwash);
			break;

		case	_RIDGE_FRAME  :
			if ( style & _FRAME_TRANSPARENT )
				bg = transparent;
			else	bg = standard_backwash;
			relief( atx,aty,nbx,nby,standard_hilight,bg,standard_lolight);
			if (( nbx > 2 ) && ( nby > 2 )) 
				relief((atx+1),(aty+1),(nbx-2),(nby-2),standard_lolight,transparent,standard_hilight);
			break;

		case	_GROOVE_FRAME :
			if ( style & _FRAME_TRANSPARENT )
				bg = transparent;
			else	bg = standard_backwash;
			relief( atx,aty,nbx,nby,standard_lolight,bg,standard_hilight);
			if (( nbx > 2 ) && ( nby > 2 )) 
				relief( (atx+1),(aty+1),(nbx-2),(nby-2),standard_hilight,transparent,standard_lolight);
			break;

		case	_MENU_FRAME :
			if (( nbx > 4 ) && ( nby > 4 )) {
				xorzone(atx+4,aty+4,nbx-4,nby-4,0x0069);
				relief( atx,aty,nbx-4,nby-4,standard_black,standard_white,standard_black);
				}
			break;

		case	_DISC_FRAME	:
		case	_CIRCLE_FRAME	:
			drawcircle(atx,aty,nbx,nby,0x0096,3);
			break;

		case	_CURSOR_FRAME :
			xorzone(atx,aty,nbx,nby,0x0069);
			break;

		case	_EDIT_FRAME :
			if ((style & 0x100) == 0x100)
				relief( atx,aty,nbx,nby,standard_black,standard_grayed,standard_black);
			else	relief( atx,aty,nbx,nby,standard_black,standard_white,standard_black);
			break;


		}
		}
	return(0);
}


