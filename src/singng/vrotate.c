#ifndef	_vrotate_c
#define	_vrotate_c

public	int	vrotate180( STDPSUPTR storage )
{
	char	*	tptr;
	char	*	bptr;
	int		tr;
	int		br;
	int		nc;
	int		nr;
	int		lc,rc;
	int		pixel;
	int		columns;
	int		rows;
	int		p;
	int	pixelsize;
	if (!( columns = storage->descriptor[0] ))
		return(102);

	else if (!( rows = storage->descriptor[1] ))
		return(102);

	pixelsize = storage->descriptor[6];

	for ( 	nr=(rows/2),
		tr=0,br=(rows-1); 
		nr != 0; nr--,tr++,br-- ) {
		if (!(tptr = connect_pixel_row( storage, tr )))
			break;
		else if (!(bptr = connect_pixel_row( storage, br )))
			break;
		for (	nc=columns,
			lc=0,rc=(columns-1);
			nc != 0;
			lc++,nc--,rc--) {
			for ( p=0; p < pixelsize; p++ ) {
				pixel = *(tptr+(rc*pixelsize)+p);
				*(tptr+(rc*pixelsize)+p) = *(bptr+(lc*pixelsize)+p);
				*(bptr+(lc*pixelsize)+p) = pixel;
				}
			}
		}
	return(0);
}

public	int	vrotate( WORD mode, STDPSUPTR rptr, STDPSUPTR mptr )
{
	char	**optr;
	int	tr,tc,sr,sc;
	char	*sptr;
	char	*tptr;
	WORD 	scol;
	WORD 	srow;
	int	pixelsize;
	int	p;

	if (!( scol = mptr->descriptor[0] ))
		return(102);
	else if (!( srow = mptr->descriptor[1] ))	
		return(102);
	else if (!( optr = (char **) allocate( scol * sizeof( void * ))))
		return(27);
	
	pixelsize = mptr->descriptor[6];

	/* Initialise Optimisation buffer */
	/* ------------------------------ */
	for (tr=0; tr < scol; tr++ )
		*(optr + tr) = connect_pixel_row( rptr, tr );

	/* For each row in the initial image */
	/* --------------------------------- */
	if ( mode  ) {

		for (	sr=0,tc=(srow-1); sr < srow; sr++,tc-- ) {

			/* Connect to the image pixel row */
			/* ------------------------------ */
			if (!(sptr = connect_pixel_row( mptr, sr )))
				break;
			for (	sc=0; sc < scol; sc++ ) {
				if (!( tptr = *(optr + sc) ))
					break;
				for ( p=0; p < pixelsize; p++ )
					*(tptr + (tc*pixelsize) + p) = *(sptr + (sc*pixelsize)+p);
				}
			}
		}
	else 	{
		for (	sr=0,tc=0; sr < srow; sr++,tc++ ) {
			/* Connect to the image pixel row */
			/* ------------------------------ */
			if (!(sptr = connect_pixel_row( mptr, sr )))
				break;
			for (	sc=0,tr=(scol-1);
				sc < scol; sc++,tr-- ) {
				if (!( tptr = *(optr + tr) ))
					break;
				for ( p=0; p < pixelsize; p++ )
					*(tptr + (tc*pixelsize) + p) = *(sptr + (sc*pixelsize)+p);
				}
			}
		}

	(void) liberate( optr );
	return(0);
}

#endif	/* _vrotate_c */
	/* ---------- */

