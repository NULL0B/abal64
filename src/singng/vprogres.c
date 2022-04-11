#ifndef	_vprogress_c
#define	_vprogress_c

public	int	visual_progress( 
	unsigned int x, 
	unsigned int y, 
	unsigned int w, 
	unsigned int h, 		/* position and dimensions of widget */
	int f,				/* font id			     */
	int fg,int bg,			/* fore and back ground colours	     */
	unsigned int l, 
	unsigned int v, 
	int o )				/* limit, value and options	     */
{
	int	ow=w;
	int	oh=h;
	unsigned int	nb;
	char	percbuf[16];
	unsigned int	fh;
	int	ty;
	int	fgc=0;
	unsigned long tmp;
	
	if ((!( w )) || (!( h ))) return(0);



	hide();
	if (!( f )) fh = 0;
	else	{
		fh = guifontsize(f);
		fh >>= 8;
		fh &= 0x00FF;
		}

	/* check for undefined colours */
	/* --------------------------- */
/*
	if (!( bg )) 		bg = standard_backwash;
	if (!( fg ))		fg = standard_text;
 */
	if (!( l ))		l = 1;
	if ( v > l )		v = l;

	tmp = ((((unsigned long) v) * 100)/l);
	nb = tmp;
	sprintf(percbuf," %u%% ",nb);
	tmp = ((((unsigned long) w) * v)/l);
	nb = tmp;

	if ( o & _A_SHADOW )  {
		fgc = standard_black;
		visual_frame(x,y,w,h,_INSET_FRAME);
		}
	else	fgc = standard_white;

	if ( nb > 0) {
		if ( nb > w ) nb = w;
		if ( o & _A_SHADOW )
			visual_frame(x+1,y+1,w-2,h-2,_OUTSET_FRAME);
		else if ( fg )
			filzone(x,y,nb,h,fg);
		w -= nb;
		if (!( o & _A_SHADOW )) {
			if ( w > 0 ) {
				if ( bg ) filzone(x+nb,y,w,h,bg);
				}
			}
		}
	else if ( o & _A_SHADOW )
		visual_frame(x+1,y+1,w-2,h-2,_OUTSET_FRAME);
	else if ( bg )
		filzone(x,y,w,h,bg);
	if ( f != 0 ) {
		if ( h > fh )
			ty=((h-fh)/2);
		else	ty=0;
		visual_text(x,y,ow,h,f,fgc,0,percbuf,strlen(percbuf),o);
		}
	show(x,y,ow,oh);
	return( 0 );
}


#endif	/* _vprogress_c */
	/* ------------ */
