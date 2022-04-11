private	int	rounding_factor=8;

public	int	set_rounding_factor(int v)
{
	int	r=rounding_factor;
	rounding_factor = v;
	return(r);
}	

private	void	rounded_relief( int x, int y, int w ,int h, int hl, int ll )
{
	drawcircle(x,y,20,20,hl,4);
	if ( w > 20 ) {
		filzone(x+10,y		,(w-20),1,hl);
		filzone(x+10,(y+(h-1))	,(w-20),1,ll);
		drawcircle(x+(w-20),y,20,20,ll,5);
		}
	if ( h > 20 ) {
		filzone(x,	y+10,1,	(h-20),hl);
		filzone(x+(w-1),y+10,1,	(h-20),ll);
		drawcircle(x,y+(h-20),20,20,hl,6);
		}
	if (( w > 20 ) && ( h > 20 )) {
		drawcircle(x+(w-20),y+(h-20),20,20,ll,7);
		}
	return;
}

public	void visual_rounded_frame( int x, int y, int w, int h, int pixel)
{
#ifdef WIN32

	/* passe par rgraph */
	rounded_frame(x,y,w,h,pixel);

#else

	int	v;
	v = ( w > h ? h : w );
	if ( rounding_factor )
		v /= rounding_factor;
	if (!( v )) {
		relief (x,y,w,h,pixel,0,pixel); 
		}
	else	{
		filzone(x+(v/2),y,(w - v),1,pixel);
		drawcircle(x,y,v,v,pixel,4);
		filzone(x,y+(v/2),1,(h-v),pixel);
		drawcircle(x+(w-v),y,v,v,pixel,5);
		filzone(x+(w-1),y+(v/2),1,(h-v),pixel);
		drawcircle(x,y+(h-v),v,v,pixel,6);
		filzone(x+(v/2),(y+(h-1)),(w - v),1,pixel);
		drawcircle(x+(w-v),y+(h-v),v,v,pixel,7);
		}
	return;

#endif
}

public	void visual_rounded_fill( int x, int y, int w, int h, int pixel)
{
#ifdef WIN32

	/* passe par rgraph */
	rounded_filzone(x,y,w,h,pixel);

#else

	int	v;
	v = ( w > h ? h : w );
	if ( rounding_factor )
		v /= rounding_factor;
	if (!( v )) {
		relief (x,y,w,h,pixel,0,pixel); 
		}
	else	{
		filzone(x+(v/2),y,(w - v),h,pixel);
		drawcircle(x,y,v,v,pixel,8);
		filzone(x,y+(v/2),w,(h-v),pixel);
		drawcircle(x+(w-v),y,v,v,pixel,9);
		drawcircle(x,y+(h-v),v,v,pixel,10);
		drawcircle(x+(w-v),y+(h-v),v,v,pixel,11);
		}
	return;

#endif
}

#ifdef	ABAL32A
public	void vconvexed(int x, int y, int w, int h, int pixel )
{
	int	cumul;
	int	p=0;
	int	n=0;
	int	d=0;
	int	v=255;
	int	colourmaped = get_pixel_format();
	if ((!( colourmaped )) && ( h > 0 )) {
		if ( pixel ) { filzone(x,y,w,h,pixel); }
		cumul = (255*100); d = (cumul/h);
		for (	n=0; n < h; n++ ) {
			v = ((cumul/100) & 0x00FF);
			p = (0x80000000 | (v << 16) | (v << 8) | v );
			shadzone(x,y+n,w,1,p);
			if ( cumul > d ) { cumul -= d; }
			else		 { cumul  = 0; }
			}
		}
	return;
}

public	void hconvexed(int x, int y, int w, int h, int pixel )
{
	int	cumul;
	int	p=0;
	int	n=0;
	int	d=0;
	int	v=255;
	int	colourmaped = get_pixel_format();
	if ((!( colourmaped )) && ( w > 0 )) {
		if ( pixel ) { filzone(x,y,w,h,pixel); }
		cumul = (255*100); d = (cumul/w);
		for (	n=0; n < w; n++ ) {
			v = ((cumul/100) & 0x00FF);
			p = (0x80000000 | (v << 16) | (v << 8) | v );
			shadzone(x+n,y,1,h,p);
			if ( cumul > d ) { cumul -= d; }
			else		 { cumul  = 0; }
			}
		}
	return;

}

public	void vconcaved(int x, int y, int w, int h, int pixel )
{
	int	cumul=0;
	int	p=0;
	int	n=0;
	int	d=0;
	int	v=0;
	int	colourmaped = get_pixel_format();
	if ((!( colourmaped )) && ( h > 0 )) {
		if ( pixel ) { filzone(x,y,w,h,pixel); }
		d = ((255*100)/h);
		for (	n=0; n < h; n++ ) {
			v = ((cumul/100) & 0x00FF);
			p = (0x80000000 | (v << 16) | (v << 8) | v );
			shadzone(x,y+n,w,1,p);
			cumul += d; 
			}
		}
	return;

}

public	void hconcaved(int x, int y, int w, int h, int pixel )
{
	int	cumul=0;
	int	p=0;
	int	n=0;
	int	d=0;
	int	v=0;
	int	colourmaped = get_pixel_format();
	if ((!( colourmaped )) && ( w > 0 )) {
		if ( pixel ) { filzone(x,y,w,h,pixel); }
		d = ((255*100)/w);
		for (	n=0; n < w; n++ ) {
			v = ((cumul/100) & 0x00FF);
			p = (0x80000000 | (v << 16) | (v << 8) | v );
			shadzone(x+n,y,1,h,p);
			cumul += d; 
			}
		}
	return;

}
#endif

public	void relieved(int atx, int aty, int nbx, int nby, int pixel )
{
#ifdef	ABAL32A
	int	colourmaped = get_pixel_format();
	if (!( colourmaped )) {
		shadzone(atx,aty,nbx,1,(pixel&0x00FF));
		shadzone(atx,aty,1,nby,(pixel&0x00FF));
		shadzone((atx+nbx-1),aty,1,nby,(pixel >> 8));
		shadzone(atx,(aty+nby-1),nbx,1,(pixel >> 8));
		}
	return;
#endif
}


public	void visual_filzone(int x, int y, int w, int h, int pixel,int mode )
{
	int	colourmaped = get_pixel_format();
	switch ( mode  & 0x00FF ) {
		case	0 : 	filzone(x,y,w,h,pixel); 
				break;
		case	16	:
				if (!( colourmaped )) {
#ifndef WIN32
/* #BGI 01/08/06 A VOIR: Définition de shadzone? */
				 	shadzone (x,y,w,h,pixel);
#endif
					break;
					}
				else	{
					pixel &= 0x00FF;
					xfilzone(x,y,w,h,pixel);
					break;
					}

		case	1 : 	relief (x,y,w,h,pixel,0,pixel); 
				break;
		case	2 : 	
			if (!( mode & 256 ))
				drawcircle(x,y,w,h,pixel,0); 
			else	visual_elipse(x,y,w,h,pixel,0);
			break;
		case	3 :
			if (!( mode & 256 ))
			 	drawcircle(x,y,w,h,pixel,1);
			else 	visual_elipse(x,y,w,h,pixel,1);
			break;
		case	4 :	visual_convex(x,y,w,h);		break;
		case	5 :	vertical_convex(x,y,w,h);	break;
		case	6 :	visual_concave(x,y,w,h);	break;
		case	7 :	vertical_concave(x,y,w,h);	break;
		case	8 :	filzone(x,y,w,h,(pixel >> 8)); 
				relief (x,y,w,h,(pixel&0x0FF),0,(pixel & 0x00FF)); 
				break;
		case	9 :
			if (!( mode & 256 )) {
				drawcircle(x,y,w,h,(pixel >> 8),1);
			 	drawcircle(x,y,w,h,(pixel & 0x00FF),0); 
				}
			else	{
				visual_elipse(x,y,w,h,(pixel >> 8),1);
			 	visual_elipse(x,y,w,h,(pixel & 0x00FF),0); 
				}
				break;
		case	10 :	if ((w > 2) && (h > 2))
					visual_convex(x+1,y+1,w-2,h-2);
				relief (x,y,w,h,standard_hilight,0,standard_lolight);
				break;
		case	11 :	if ((w > 2) && (h > 2))
					visual_concave(x+1,y+1,w-2,h-2);
				relief (x,y,w,h,standard_hilight,0,standard_lolight);
				break;
		case	12 :	if ((w > 2) && (h > 2))
					xfilzone(x+1,y+1,w-2,h-2,pixel);
				break;
		case	13 :	visual_rounded_frame(x,y,w,h,pixel);
				break;
		case	14 :	visual_rounded_fill(x,y,w,h,pixel);
				break;
		case	15	:
			 	xrelief (x,y,w,h,pixel,0,pixel); 
				break;
		case	17 	:
				drawcircle(x,y,w,h,pixel,17); 
				break;
#ifdef	ABAL32A
		case	18	:
				vconvexed(x,y,w,h,pixel);
				break;
		case	19	:
				hconvexed(x,y,w,h,pixel);
				break;
		case	20	:
				vconcaved(x,y,w,h,pixel);
				break;
		case	21	:
				hconcaved(x,y,w,h,pixel);
				break;
		case	22	:
				relieved(x,y,w,h,pixel);
				break;
		case	23	:
				drawcircle(x,y,w,h,pixel,23);
				break;
		case	24	:
				drawcircle(x,y,w,h,pixel,24);
				break;
		case	25	:
				drawcircle(x,y,w,h,pixel,25);
				break;

#endif
		}
	return;
}

