
char	rowbuffer[8192];	/* optimisation row buffer */

extern	int	verbose;

int	_SCALE_FACTOR=_DEFAULT_SCALE_FACTOR;	/* these two are defined as */
int	_ROUND_FACTOR=_DEFAULT_ROUND_FACTOR;	/* 10 and 0 in vimage.h	    */

#define	CheckHorizontalFace { \
	if ( tlx < blx ) { \
		if (( bry <= margins.y )  \
		||  ( brx <= margins.x )  \
		||  ( tlx >= edge.x    )  \
		||  ( tly >= edge.y    )) \
			return;		  \
		} \
	else 	{ \
		if (( try >= edge.y    )   \
		||  ( trx <= margins.x )   \
		||  ( blx >= edge.x    )   \
		||  ( bly <= margins.y  )) \
			return;		   \
		} \
	}

#define	CheckVerticalFace { \
	if ( bry > bly ) {  \
		if (( bry <= margins.y )	\
		||  ( brx <= margins.x )	\
		||  ( tlx >= edge.x    )	\
		||  ( tly >= edge.y    ))	\
			return;			\
		}				\
	else	{				\
		if (( try >= edge.y    )	\
		||  ( trx <= margins.x )	\
		||  ( blx >= edge.x    )	\
		||  ( bly <= margins.y  ))	\
			return;			\
		}				\
	}


#define	draw_face(tlc,tll,trc,trl,blc,bll,brc,brl,d,i) { 	\
	if ((tll == trl) && ( bll == brl )) 			\
		draw_hface(tlc,tll,trc,trl,blc,bll,brc,brl,d,i);\
	else if ((tlc == blc) && ( trc == brc ))		\
		draw_vface(tlc,tll,trc,trl,blc,bll,brc,brl,d,i);\
	}


/*
 *	DRAW HFACE ( tl, tr, bl, br, colour, image )
 *	--------------------------------------------
 *
 *	the coordinates tl,tr,bl and br are all composed of x and y factors.
 *
 *	This function, like its vertical counterpart DRAW VFACE below,
 *	performs the application of the double gradient resulting from
 *	the calculation of the gradient between right hand x factors
 *	and of the gradient between left hand x factors. These gradients
 *	are used to control the start of each horizontal line and its length.
 *
 */

#define	RoundUp(v) ((v / _SCALE_FACTOR ) /* + ( v & _ROUND_FACTOR ? 1 : 0 ) */ )

PRIVATE	VOID	draw_hface( 
	int	tlx, int tly, int trx, int try, 
	int 	blx, int bly, int brx, int bry, 
	int 	dath,
	struct standard_image * image
	)
{
	int	m;
	int	p;
	int	n;
	int	tw,th;
	int	left_gradient,right_gradient;
	int	cxr,rxr;
	int	r,ir,fr,nr,lr;
	int	c,ic,fc,nc,lc;
	char *	bptr;
	register int colourmaped;
	register int pixelsize;

	colourmaped = get_pixel_format();
	pixelsize   = get_pixel_size();

	/* 1) Ensure Face is at least partially visible */
	/* -------------------------------------------- */
	CheckHorizontalFace;

	if ( verbose )	
		printf("\r\ndraw_hface( %d,%d  %d,%d  %d,%d  %d,%d );\r\n",
				tlx,tly,trx,try,
				blx,bly,brx,bry );

	/* Check for and avoid empty images */
	/* -------------------------------- */
	if (( image ) &&  ((!( image->rows )) || (!( image->columns ))))
		image = (struct standard_image *) 0;

	/* 2a) Calculate target zone height */
	/* -------------------------------- */
	th = ((bly - tly)+1);
		
	/* 3) Calculate Left Edge Gradient */
	/* ------------------------------- */
	if (( blx - tlx ))
		left_gradient = ((((blx-tlx)+1)* _SCALE_FACTOR )/th);
	else	left_gradient = 0;

	/* 4) Calculate Right Edge Gradient */
	/* -------------------------------- */
	if (( brx - trx ))
		right_gradient = ((((brx-trx)+1)* _SCALE_FACTOR )/th);
	else	right_gradient = 0;

	/* 5) Calculate Initial/Final/Total Row */
	/* ------------------------------------ */
	if ((ir = tly) < margins.y) {
		lr = (margins.y -ir);
		ir = margins.y;
		}
	else	lr = 0;

	fr = (bly > edge.y    ? edge.y    : bly );
	nr = ((fr - ir) + 1);

	/* 6) For Rows : with image or colour */
	/* ---------------------------------- */
	if ( image ) {

		if ( verbose )
			printf("hface : format=%u, width=%u,height=%u, pixelsize=%u, pixelformat=%u\r\n",image->format,image->columns,image->rows,pixelsize,colourmaped);

		/* Calculate source/target extraction ratio for rows */
		/* ------------------------------------------------- */
		rxr = ((image->rows* _SCALE_FACTOR )/th);

		for ( 	r=0; r < nr; r++ ) {
			
			/* calculate initial and final columns */
			/* ----------------------------------- */
			if ( left_gradient ) {
				n = ((r+lr) * left_gradient);
				ic = (tlx + RoundUp(n));
				}
			else	ic = tlx;

			if ( right_gradient) {
				n = ((r+lr)*right_gradient);
				fc = (trx + RoundUp(n));
				}
			else	fc = trx;

			/* connect to row of pixels */
			/* ------------------------ */
			n = ((r+lr)*rxr);
			if (!( bptr = connect_pixel_row(
					image->storage,
					RoundUp(n)
					) ))
				break;

			/* calculate columnwise extraction ratio */
			/* ------------------------------------- */
			if (!(( fc - ic )+1))
				cxr = (image->columns *  _SCALE_FACTOR );
			else	cxr = ((image->columns *  _SCALE_FACTOR ) / ((fc-ic)+1));

			/* apply margin and edge clipping now */
			/* ---------------------------------- */
			if ( ic < margins.x ) 	{
				lc = (margins.x-ic);
				ic = margins.x;
				}
			else	lc=0;

			if ( fc > edge.x    )
				fc = edge.x;

			if ((nc = ((fc-ic)+1)) > 0) {

				for (	c=0; c < nc; c++ ) {
					/* calculate source column for pixel transfer */
					/* ------------------------------------------ */
					n = ((c+lc)*cxr);
					if ( colourmaped )
						rowbuffer[c] = *(bptr + RoundUp(n));
					else	{
						n = RoundUp(n);
						n *= pixelsize;
						m = (c*pixelsize);
						for (p=0; p < pixelsize; p++ ) {
							rowbuffer[m+p] = *(bptr+n+p);
							}
						}
					}
				if ( verbose > 1 )
					printf("putzone( %d,%d,%d,1,rowbuffer);\r\n",ic,r+ir,nc);
				if (!( dath ))
					mixzone( ic,r+ir,nc,1,rowbuffer);
				else	putzone( ic,r+ir,nc,1,rowbuffer);
				}
			}

		}
	else	{
		/* Fill rows with colour */
		for ( 	r=0,lr=(ir - tly);
			r < nr;
			r++ ) {
			n = ((r+lr)*left_gradient);
			if ((ic = (tlx + RoundUp(n))) < margins.x)
				ic = margins.x;
			n = ((r+lr)*right_gradient);
			if ((fc = (trx + RoundUp(n))) > edge.x)
				fc = edge.x;
			if ((nc = ((fc - ic)+1)) > 0 ) {
				if ( verbose > 1 )
					printf("filzone( %d,%d,%d,1,%d);\n",ic,ir+r,nc,dath);
				if ( dath != 0 )
					filzone( ic,ir+r,nc,1,dath );
				}
			}
		}
					
	return;
}


/*
 *	DRAW VFACE ( tl, tr, bl, br, colour, image )
 *	--------------------------------------------
 *
 *	the coordinates tl,tr,bl and br are all composed of x and y factors.
 *
 *	This function, like its horizontal counterpart DRAW HFACE above,
 *	performs the application of the double gradient resulting from
 *	the calculation of the gradient between upper edge y factors
 *	and of the gradient between lower edge y factors. These gradients
 *	are used to control the start of each vertical line and its height.
 *
 */

PRIVATE	VOID	draw_vface( 
	int	tlx, int tly, int trx, int try, 
	int 	blx, int bly, int brx, int bry, 
	int 	dath,
	struct standard_image * image
	)
{
	int	m,n,p;
	int	tw,th;
	int	top_gradient,bottom_gradient;
	int	cxr,rxr;
	int	r,ir,fr,nr,lr;
	int	c,ic,fc,nc,lc;
	char *	bptr;

	register int colourmaped;
	register int pixelsize;

	colourmaped = get_pixel_format();
	pixelsize   = get_pixel_size();

	if ( verbose  )
		printf("\ndraw_vface( %d,%d  %d,%d  %d,%d  %d,%d );\n",
				tlx,tly,trx,try,
				blx,bly,brx,bry );

	/* 1) Ensure Face is at least partially visible */
	/* -------------------------------------------- */
	CheckVerticalFace;

	/* Check for and avoid empty images */
	/* -------------------------------- */
	if (( image ) &&  ((!( image->rows )) || (!( image->columns ))))
		image = (struct standard_image *) 0;

	/* 2a) Calculate target zone width */
	/* ------------------------------- */
	tw = ((brx - blx)+1);
		
	/* 3) Calculate Top Edge Gradient */
	/* ------------------------------ */
	if ((try - tly))
		top_gradient = ((((try-tly)+1)* _SCALE_FACTOR )/tw);
	else	top_gradient = 0;

	/* 4) Calculate Bottom Edge Gradient */
	/* --------------------------------- */
	if ((bry -bly ))
		bottom_gradient = ((((bry-bly)+1)* _SCALE_FACTOR )/tw);
	else	bottom_gradient = 0;

	/* 5) Calculate Initial/Final/Total Col */
	/* ------------------------------------ */
	if ((ic = tlx) < margins.x) {
		lc = (margins.x -ic);
		ic = margins.x;
		}
	else	lc=0;
	fc = (trx > edge.x    ? edge.x    : trx );
	nc = ((fc - ic) + 1);

	/* 6) For Cols : with image or colour */
	/* ---------------------------------- */
	if ( image ) {

		/* Calculate source/target extraction ratio for cols */
		/* ------------------------------------------------- */
		cxr = ((image->columns* _SCALE_FACTOR )/tw);

		for ( 	c=0; c < nc; c++ ) {
			
			/* calculate initial and final rows */
			/* -------------------------------- */
			if ( top_gradient ) {
				n = ((c+lc)*top_gradient);
				ir = (tly + RoundUp(n));
				}
			else	ir = tly;

			if ( bottom_gradient) {
				n = ((c+lc)*bottom_gradient);
				fr = (bly + RoundUp(n));
				}
			else	fr = bly;

			/* calculate row_wise extraction ratio */
			/* ----------------------------------- */
			if (!((fr-ir)+1))
				rxr = (image->rows *  _SCALE_FACTOR );
			else	rxr = ((image->rows *  _SCALE_FACTOR ) / ((fr-ir)+1));

			/* apply margin and edge clipping now */
			/* ---------------------------------- */
			if ( ir < margins.y ) {
				lr = (margins.y - ir);
			 	ir = margins.y;
				}
			else	lr=0;
			if ( fr > edge.y    )	fr = edge.y;

			if ((nr = ((fr-ir)+1)) > 0) {

				for (	r=0; r < nr; r++ ) {
	
					/* connect to row of pixels */
					/* ------------------------ */
					n = ((r+lr)*rxr);
					if (!( bptr = connect_pixel_row(
							image->storage,
							RoundUp(n)
							) ))
						break;

					/* calculate source column for pixel transfer */
					/* ------------------------------------------ */
					n = ((c+lc)*cxr);
					if ( colourmaped )
						rowbuffer[r] = *(bptr + RoundUp(n));
					else	{
						n = RoundUp(n);
						n *= pixelsize;
						m = (r*pixelsize);
						for (p=0; p < pixelsize; p++ )
							rowbuffer[m+p] = *(bptr+n+p);
						}
					}
				if ( verbose > 1 )
					printf("putzone( %d,%d,1,%d,rowbuffer);\n",c+ic,ir,nr);
				if (!( dath ))
					mixzone( c+ic,ir,1,nr,rowbuffer);
				else	putzone( c+ic,ir,1,nr,rowbuffer);
				}
			}

		}
	else	{
		/* Fill rows with colour */
		for ( 	c=0,lc=(ic - tlx);
			c < nc;
			c++ ) {
			n = ((c+lc)*top_gradient);
			if ((ir = (tly + RoundUp(n))) < margins.y)
				ir = margins.y;
			n = ((c+lc)*bottom_gradient);
			if ((fr = (bly + RoundUp(n))) > edge.y)
				fr = edge.y;
			if ((nr = ((fr - ir)+1)) > 0) {
				if ( verbose > 1 )
					printf("filzone( %d,%d,1,%d,%d);\n",ic+c,ir,nr,dath);
				if ( dath != 0 )
					filzone( ic+c,ir,1,nr,dath );
				}
			}
		}
					
	return;
}



