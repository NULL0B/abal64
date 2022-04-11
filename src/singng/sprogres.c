#ifndef	_sprogress_c
#define	_sprogress_c

public	int	StyledProgress( 
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

	if (!( l ))		l = 1;
	if ( v > l )		v = l;

	tmp = ((((unsigned long) v) * 100)/l);
	nb = tmp;
	sprintf(percbuf," %u%% ",nb);
	tmp = ((((unsigned long) w) * v)/l);
	nb = tmp;

	visual_element(x,y,w,h,"progresstray"," ",0);
	visual_element(x,y,w,h,"progressframe"," ",0);

	if ( nb > 0) {
		if ( nb > w ) nb = w;
		visual_element(x,y,nb,h,"progressfill"," ",0);
		w -= nb;
		if ( w > 0 )
			visual_element(x+nb,y,w,h,"progresswipe"," ",0);
		}
	else	visual_element(x,y,w,h,"progresswipe"," ",0);

	visual_element(x,y,ow,h,"progresslabel",percbuf,strlen(percbuf));
	show(x,y,ow,oh);
	return( 0 );
}


#endif	/* _sprogress_c */
	/* ------------ */

