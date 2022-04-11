#ifndef	_vscroll_c
#define	_vscroll_c

public	void	arrow_button( int atx,int aty, int nbx, int nby, int type )
{
	visual_frame(atx,aty,nbx,nby,_OUTSET_FRAME);
	switch ( type ) {
		case	_ARROW_UP     :
		case	_ARROW_DOWN   :
		case	_ARROW_LEFT   :
		case	_ARROW_RIGHT  :
		case	_ARROW_HSLIDE :
			visual_convex(atx,aty,nbx-1,nby);
			break;
		case	_ARROW_VSLIDE :	
			vertical_convex(atx,aty,nbx-1,nby);
		case	_ARROW_FOCUS	:
			visual_arrow(atx+1,aty+1,nbx-2,nby-2,standard_black,type);
			return;
		}
	visual_arrow(atx+1,aty+1,nbx-2,nbx-2,standard_black,type);
	return;
}

public	int visual_scrollbar(
	unsigned int atx, unsigned int aty, 
	unsigned int nbx, unsigned int nby, 
	int f, int fg, int bg, 
	unsigned int item, unsigned int limit, unsigned int total, 
	int style )
{
	unsigned int	fh;
	unsigned int	fw;
	unsigned int	fratx=atx;
	unsigned int	fraty=aty;
	unsigned int	bh=0;
	unsigned int	by=0;
	unsigned long 	tmp;
	unsigned int	tmpw;

/*
 *	printf("scrollbar(%u,%u,%u,%u)(%u,%u,%u)\n",atx,aty,nbx,nby,item,limit,total);
 */

	if ( total < limit )	
		style &= 3;

	if (( item+limit ) > total ) {
		if ( limit < total ) 
			item = (total-limit);
		else	item=0;
		}
	if (( nbx > 4 ) && ( nby > 4 )) {

		hide();

		/* display the slider trough then adjust to inside */
		/* ----------------------------------------------- */
		relief( atx,aty,nbx,nby,standard_lolight,standard_lomid,standard_hilight);
		atx++, aty++, nbx-=2, nby-=2;
		relief( atx,aty,nbx,nby,standard_lolight,transparent,standard_hilight);	
		if ( style & 4 )
			relief( atx,aty,nbx,nby,standard_lolight,transparent,standard_hilight);
		atx++, aty++, nbx-=2, nby-=2;

		/* Calculate font sizes */
		/* -------------------- */
		if (!( f )) fh = 0;
		else	{
			fw = guifontsize(f);
			fh = (( fw >> 8) & 0x00FF);
			fw &= 0x00FF;
			}


		if ( nby > nbx ) {

			/* Its Vertical So ....... */

			/* check for top button */
			/* -------------------- */
			if ( style & _A_LEFT) {
				arrow_button(atx,aty,nbx,nbx,_ARROW_UP);
				aty += nbx;
				nby -= nbx;
				if ( style & 0x800 ) {
					item += nbx;
					limit+= nbx;
					}										
				}

 			/* check for bottom button */
			/* ----------------------- */
			if ( style & _A_RIGHT ) {
				nby -= nbx;
				arrow_button(atx,aty+nby,nbx,nbx,_ARROW_DOWN);
				if ( style & 0x800 )
					limit += nbx;
				}

			if (( style & 4 ) && ( nbx > 2 ))
				xfilzone( (atx+(nbx/2)-1),aty+1,1,(nby-2),standard_loblack);

			/* validate data relations and clip/limit */
			/* -------------------------------------- */
			if ( limit > total )  	total = limit;
			if ( item > total  )	item = total;

			/* Calculate Slider Height */
			/* ----------------------- */
			if (!( style & 0x800 )) {
				if ( total != 0 )
					tmp = ((((unsigned long) limit)*nby)/total);
				else	tmp = 0;
		
				if (!(bh = tmp))	bh = fh;
				else if ( bh > nby )	bh = nby;

				/* Calculate Slider Position */
				/* ------------------------- */
				if (!( tmpw = (total-limit) )) tmpw = 1;
				if ( tmpw != 0 )
					tmp = ((((unsigned long) item)*(nby-bh))/tmpw);
				else	tmp = 0;
				by = tmp;
				}
			else	{
				by = item;
				bh = limit;
				}
		
			if ( bh < fh ) bh = fh;

			if ( (by+bh) > nby )  {
				if ( nby > bh )
					by = (nby - bh);
				else	by = 0;
				}
			if ( (aty+by+bh) > ( aty+nby ) )
				bh = ((aty+nby) - (aty+by));

			if (!( bh )) bh = 10;

			if ( bh >= 14 ) {
				filzone(atx,aty+by,nbx-1,bh,standard_backwash);
				arrow_button(atx,aty+by,nbx,bh,(style & 4  ?  _ARROW_VSLIDE : ( style & 0x100 ? _ARROW_FOCUS : 0)));
				}
			else if ((bh > 0 ) && ( nbx > 0 )) {
				relief( atx,aty+by,nbx,bh,standard_hilight,standard_backwash,standard_lolight);
				}
			}
		else	{

			/* Its Horizontal So .... */

			/* check for top button */
			/* -------------------- */
			if ( style & _A_LEFT ) {
				arrow_button(atx,aty,nby,nby,_ARROW_LEFT);
				atx += nby;
				nbx -= nby;
				if ( style & 0x800 ) {
					item += nby;
					limit+= nby;
					}										
				}

 			/* check for bottom button */
			/* ----------------------- */
			if ( style & _A_RIGHT ) {
				nbx -= nby;
				arrow_button(atx+nbx,aty,nby,nby,_ARROW_RIGHT);
				if ( style & 0x800 )
					limit+= nby;
				}

			if (( style & 4 ) && ( nbx > 2 ))
				xfilzone( atx+1,aty+(nby/2)-1,(nbx-2),1,standard_loblack);

			/* Calculate Slider Width */
			/* ---------------------- */
			/* validate data relations and clip/limit */
			/* -------------------------------------- */
			if ( limit > total )  	total = limit;
			if ( item > total  )	item = total;

			if (!( style & 0x800 )) {
				if ( total != 0 )
					tmp = ((((unsigned long) limit)*nbx)/total);
				else	tmp = 0;
		
				if (!(bh = tmp))	bh = fw;
				else if ( bh > nbx )	bh = nbx;

				/* Calculate Slider Position */
				/* ------------------------- */
				if (!( tmpw = (total-limit) )) tmpw = 1;
				if ( tmpw != 0 )
					tmp = ((((unsigned long) item)*(nbx-bh))/tmpw);
				else	tmp = 0;
				by = tmp;
				}
			else	{
				by = item;
				bh = limit;
				}

			if ( bh < fh ) bh = fh;

			if ( (by+bh) > nbx ) {
				if( nby > bh )
					 by = (nby -bh);
				else	by = 0;
				}
			if ((atx+by+bh) > ( atx+nbx))
				bh = ((atx+nbx)-(atx+by));

			if (!( bh )) bh = 10;

			if ( bh >= 14 ) {
				filzone(atx+by,aty,bh,nby-1,standard_backwash);
				arrow_button(atx+by,aty,bh,nby,(style & 4  ?  _ARROW_HSLIDE : ( style & 0x100 ? _ARROW_FOCUS : 0)));
				}
			else if ((bh > 0 ) && ( nbx > 0 )) {
				relief( atx+by,aty,bh,nby,standard_hilight,standard_backwash,standard_lolight);
				}
			}
		show(fratx,fraty,nbx+4,nby+4);
		}
	return(by);

}

#endif 	/* _vscroll_c */

