#ifndef	_sscroll_c
#define	_sscroll_c

private	int StyleScrollBar(
	unsigned int x, unsigned int y, 
	unsigned int w, unsigned int h, 
	int f, int fg, int bg, 
	unsigned int item, unsigned int limit, unsigned int total, 
	int style )
{
	int	ix=x,iy=y,iw=w,ih=h;
	int	b1=0;
	int	b2=0;
	int	vv;
	style_visual_freeze();
	if ( w > h ) {
		/* horizontal scroll bar */
		/* --------------------- */
		visual_element( x,y,w,h, "hscrolltray", " ",0);
		visual_element( x,y,w,h, "hscrollframe", " ",0);
		if ( style & _A_LEFT) {
			visual_element( x,y,h,h, "scrollleft", " ",0 );
			b1 = h;
			}
		if ( style & _A_RIGHT) {
			visual_element( (x+(w-h)),y,h,h, "scrollright", " ",0 );
			b2 = h;
			}
		x += b1;
		w -= (b1+b2);
		if ( w > 0 ) {
			if ( total > limit ) {
				x += ((item * w)/total);
				vv = ((limit* w)/total);
				/* ------------------------------------------------------------- */
				/* corrected to ensure scroll bar visible 3.2a.0.14 : 20 09 2007 */
				/* ------------------------------------------------------------- */
				if ( vv < 10 ) vv = 10;
				if ( vv > 0 ) {
					if ( style & 0x0100 )
						visual_element( x,y,vv,h, "hscrollfocus", " ",0 );
					else	visual_element( x,y,vv,h, "hscrollbar", " ",0 );
					}
				else if ( style & 0x0100 )
					visual_element( x,y,10,h, "hscrollfocus", " ",0 );
				else	visual_element( x,y,10,h, "hscrollbar", " ",0 );
				}
			else if ( style & 0x0100 )
				visual_element( x,y,w,h, "hscrollfocus", " ",0 );
			else	visual_element( x,y,w,h, "hscrollbar", " ",0 );
			}
		}
	else	{
		/* vertical scroll bar */
		/* ------------------- */
		visual_element( x,y,w,h, "vscrolltray", " ",0);
		visual_element( x,y,w,h, "vscrollframe", " ",0);
		if ( style & _A_LEFT) {
			visual_element( x,y,w,w, "scrollup", " ",0 );
			b1 = w;
			}
		if ( style & _A_RIGHT) {
			visual_element( x,(y+(h-w)),w,w, "scrolldown", " ",0 );
			b2 = w;
			}
		y += b1;
		h -= (b1+b2);
		if ( h > 0 ) {
			if ( total > limit ) {
				y += ((item * h)/total);
				vv = ((limit* h)/total);
				/* ------------------------------------------------------------- */
				/* corrected to ensure scroll bar visible 3.2a.0.14 : 20 09 2007 */
				/* ------------------------------------------------------------- */
				if ( vv < 10 ) vv = 10;
				if ( vv > 0 ) {
					if ( style & 0x0100 )
						visual_element( x,y,w,vv, "vscrollfocus", " ",0);
					else	visual_element( x,y,w,vv, "vscrollbar", " ",0);
					}
				else if ( style & 0x0100 )
					visual_element( x,y,w,10, "vscrollfocus", " ",0);
				else	visual_element( x,y,w,10, "vscrollbar", " ",0);
				}
			else if ( style & 0x0100 )
				visual_element( x,y,w,h, "vscrollfocus", " ",0);
			else	visual_element( x,y,w,h, "vscrollbar", " ",0);
			}
		}
	visual_thaw( ix,iy,iw,ih);
	return 0;

}

private	int StyleSelectBar(
	unsigned int x, unsigned int y, 
	unsigned int w, unsigned int h, 
	int f, int fg, int bg, 
	unsigned int item, unsigned int limit, unsigned int total, 
	int style )
{
	int	ix=x,iy=y,iw=w,ih=h; 
	int	b1=0;
	int	b2=0;
	int	vv;

	style_visual_freeze();

	/* vertical scroll bar */
	/* ------------------- */
	if (!(use_default_style(visual_select_framescroll)))	
		visual_element( x,y,w,h, "selectframe", " ",0);
	else	visual_element( x,y,w,h, "selectframescroll", " ",0);

	if ( style & _A_LEFT) {
		visual_element( x,y,w,w, "selectup", " ",0 );
		b1 = w;
		}
	if ( style & _A_RIGHT) {
		visual_element( x,(y+(h-w)),w,w, "selectdown", " ",0 );
		b2 = w;
		}
	y += b1;
	h -= (b1+b2); 
//	y -= 2; nsi1206

	if ( h > 0 ) {
		if ( total > limit ) {

//			y += ((item * h)/total); 
//			if ((vv = ((limit* h)/total)) > 0) 
			// Correction sur le deplacement et la taille de la barre d'ascenseur			
//nsi1206 deb
			vv = (h/total);
//			vv = ((limit* h)/total); // La barre de l'ascenseur proportionnelle au nombre des éléments affichés dans la liste
			if (vv <= (w/2)) 
				vv = (w/2);		
			
			if (!(item)) 
				y = (iy + b1);
			else	y += (((h-vv)*(item+1))/total);

			if ((y+vv) > (iy+b1+h))
				y = (ih-b2);
//nsi1206 fin
			if ( style & 0x0100 )
				visual_element( x,y,w,vv, "selectgrip", " ",0);
			else	visual_element( x,y,w,vv, "selectbar", " ",0);
			}
		else if ( style & 0x0100 )
			visual_element( x,y,w,h, "selectgrip", " ",0);
		else	visual_element( x,y,w,h, "selectbar", " ",0);
		}

	style_visual_thaw( ix,iy,iw,ih);
	return 0;

}

#endif	/* _sscroll_c */
	/* ---------- */


