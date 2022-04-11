#ifndef	_vreflect_c
#define	_vreflect_c

private int	visual_reflect_h( STDPSUPTR storage )
{
	char	*	tptr;
	char	*	bptr;
	int		lr,lg,lb;
	int		rr,rg,rb;
	int		tr;
	int		br;
	int		nc;
	int		nr;
	int		pixel;
	int		colourmaped;
	int		pixelsize;
	int		rows;
	int		columns;

	if (!( storage ))	
		return(118);

	else if (!( columns = storage->descriptor[0] ))
		return(102);

	else if (!( rows = storage->descriptor[1] ))
		return(102);


	pixelsize   = get_pixel_size();
	colourmaped = get_pixel_format();

	for ( 	nr=(rows/2),
		tr=0,br=(rows-1); 
		nr != 0; nr--,tr++,br-- ) {
		if (!(tptr = connect_pixel_row( storage, tr )))
			break;
		else if (!(bptr = connect_pixel_row( storage, br )))
			break;
		for (	nc=0; nc < columns; nc++ ) {
			if ( colourmaped ) {
				pixel = *(tptr+nc);
				*(tptr+nc) = *(bptr+nc);
				*(bptr+nc) = pixel;
				}
			else	{
				get_logical_pixel((tptr + (nc*pixelsize)),&lr,&lg,&lb);
				get_logical_pixel((bptr + (nc*pixelsize)),&rr,&rg,&rb);
				put_logical_pixel((bptr + (nc*pixelsize)),lr,lg,lb);
				put_logical_pixel((tptr + (nc*pixelsize)),rr,rg,rb);
				/* 
					lp = get_physical_pixel(tptr,nc);
					rp = get_physical_pixel(bptr,nc);
					put_physical_pixel(bptr+(nc*pixelsize),lp);
					put_physical_pixel(tptr+(nc*pixelsize),rp);
				*/
				}
			}
		}
	return(0);
}

private	int	visual_reflect_v( STDPSUPTR storage )
{
	char	*	bptr;
	int		lc;
	int		rc;
	int		lr,lg,lb;
	int		rr,rg,rb;
	int		nr;
	int		nc;
	int		pixel;
	int		colourmaped;
	int		pixelsize;
	int		rows;
	int		columns;

	if (!( storage ))	
		return(118);

	else if (!( columns = storage->descriptor[0] ))
		return(102);

	else if (!( rows = storage->descriptor[1] ))
		return(102);


	pixelsize   = get_pixel_size();
	colourmaped = get_pixel_format();

	
	for ( 	nr=0;
		nr < rows;
		nr++ ) {
		if (!(bptr = connect_pixel_row( storage, nr )))
			break;
		for (	nc=(columns/2),
			lc=0,rc=(columns-1);
			nc != 0;
			lc++,nc--,rc--) {
			if ( colourmaped ) {
				pixel = *(bptr+lc);
				*(bptr+lc) = *(bptr+rc);
				*(bptr+rc) = pixel;
				}
			else	{
				get_logical_pixel((bptr + (lc*pixelsize)),&lr,&lg,&lb);
				get_logical_pixel((bptr + (rc*pixelsize)),&rr,&rg,&rb);
				put_logical_pixel((bptr + (rc*pixelsize)),lr,lg,lb);
				put_logical_pixel((bptr + (lc*pixelsize)),rr,rg,rb);
				/*
					lp = get_physical_pixel(bptr,lc);
					rp = get_physical_pixel(bptr,rc);
					put_physical_pixel(bptr+(rc*pixelsize),lp);
					put_physical_pixel(bptr+(lc*pixelsize),rp);
				*/
				}

			}
		}
	return(0);

}

private	int	visual_hue( STDPSUPTR storage, int r, int g, int b )
{
	char	*	bptr;
	int		lc;
	int		rc;
	int		lr,lg,lb;
	int		rr,rg,rb;
	int		nr;
	int		nc;
	int		pixel;
	int		colourmaped;
	int		pixelsize;
	int		rows;
	int		columns;

	if (!( storage ))	
		return(118);

	else if (!( columns = storage->descriptor[0] ))
		return(102);

	else if (!( rows = storage->descriptor[1] ))
		return(102);

	else if ((colourmaped = get_pixel_format()) != 0 )
		return( 56 );

	pixelsize   = get_pixel_size();
	
	for ( 	nr=0;
		nr < rows;
		nr++ ) {
		if (!(bptr = connect_pixel_row( storage, nr )))
			break;
		for (	nc=0; nc < columns; nc++ ) {
			get_logical_pixel((bptr + (nc*pixelsize)),&lr,&lg,&lb);
			lr = ((lr & 0x00FF) + (r  & 0x00FF));
			lg = ((lg & 0x00FF) + (g  & 0x00FF));
			lb = ((lb & 0x00FF) + (b  & 0x00FF));
			put_logical_pixel((bptr + (nc*pixelsize)),lr,lg,lb);
			}
		}
	return(1);

}

#endif	/* _vreflect_c */
	/* ----------- */

