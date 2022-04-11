#ifndef	_vmakefit_c
#define	_vmakefit_c

#define	RoundUp(v) ((v / _DEFAULT_SCALE_FACTOR ) /* + ( v & _DEFAULT_ROUND_FACTOR ? 1 : 0 ) */ )

private	char *	rowbuffer=(char *) 0;
private	int	rowbufsize=0;

private	char *	get_rowbuffer( int width, int pixelsize )
{
	if ( pixelsize )
		width *= pixelsize;

	if ( width > rowbufsize ) {
		if ( rowbuffer ) {  
			liberate( rowbuffer );
			rowbuffer  = (char *) 0; 
			}
		rowbufsize = 0;
		}
	if ((!( rowbuffer )) 
	&&  (!( rowbuffer = allocate( ((rowbufsize=width)+1) )  )) ) 
		rowbufsize = 0;
	return( rowbuffer );
}

public	void	istretch_columns( char * tptr, int tw, char * sptr, int sw, int pixelsize )
{
	int	nc = (tw / sw);
	int	missing = (tw - (nc*sw));
	int	sc;
	int	tc;
	int	v;
	int	x;
	int	when;
	int	previous=0;
	int	p;
	char *	pptr;
	if ( missing ) 
		if (!(when = ( tw / missing )))
			when = 1;

	if ( pixelsize  < 2 ) {

	for (	tc=0,sc=0; sc < sw; sc++ ) {
		v = *(sptr++);
		nc = (tw / sw);
		if ( missing ) {
			if (((tc+nc)/when) > previous) {
				nc++;
				missing--;
				}
			}
		for ( x=0; x < nc; x++, tc++ ) {
			if ( tc < tw ) 
				*(tptr+tc) = v;
			else	return;
			}
		if ( missing ) {
			previous = (tc/when);
			}
		}
		}
	else	{
		for (	tc=0,sc=0; sc < sw; sc++ ) {
			pptr = (sptr + (sc*pixelsize));
			nc = (tw / sw);
			if ( missing ) {
				if (((tc+nc)/when) > previous) {
					nc++;
					missing--;
					}
				}
			for ( x=0; x < nc; x++, tc++ ) {
				if ( tc < tw ) {
					for ( p=0; p < pixelsize; p++ ) {
						*(tptr+(tc*pixelsize)+p) = *(pptr+p);
						}
					}
				else	return;
				}
			if ( missing ) {
				previous = (tc/when);
				}

			}
		}
	return;
}

public	void	isquash_columns( char * tptr, int tw, char * sptr, int sw, int pixelsize )
{
	int	tc;
	int	p;

	if (  pixelsize < 2 ) {
	for (	tc=0; tc < tw; tc++ )
		*(tptr + tc) = *( sptr + ((tc * sw)/tw));
		}
	else	{
		for (	tc=0; tc < tw; tc++ )
			for ( p=0; p < pixelsize; p++ )
				*(tptr + (tc*pixelsize)+p) = *( sptr + ((( tc * sw)/tw) * pixelsize) + p);

		}
	return;
}


public 	void	istretch_rows(
	int	atx,	int 	aty, 
	int 	tw, 	int 	th,
	struct standard_image * iptr,
	int options, 	char  *	tptr,
	int pixelsize
	)
{
	int	sh=iptr->rows;
	int	sw=iptr->columns;
	int	nr = (th / sh);
	int	missing = (th - (nr*sh));
	int	r=0;
	int	srow;
	int	trow;
	char *	sptr;
	int	when=0;
	int	previous=0;

	if ( missing ) 
		if (!(when = ( th / missing )))
			when = 1;

	/* source row count is smallest so use as control */ 
	/* ---------------------------------------------- */
	for ( srow=0,trow=0; srow < sh; srow++ ) {

		if (!( sptr = connect_pixel_row( iptr->storage,srow ) ))
			break;
		else if ( tw > sw ) {
			istretch_columns( tptr, tw, sptr, sw,pixelsize );
			}
		else if ( tw < sw ) {
			isquash_columns( tptr, tw, sptr, sw,pixelsize );
			}
		else if ( pixelsize < 2 ) {
			memcpy(tptr,sptr,tw);
			}
		else 	memcpy(tptr,sptr,(tw*pixelsize));

		nr = (th / sh);
		if ( missing ) {
			if (((trow+nr)/when) > previous) {
				nr++;
				missing--;
				}
			}

		/* repeat it through target rows */
		/* ----------------------------- */
		if ( options & _I_SPRITE ) {
			for ( r=0; r < nr; r++,trow++ ) { 
				if ( trow < th ) {
					if (!( pixelsize ))
					mixzone8(atx,aty+trow,tw,1,(tptr+(r&1)));
					else	mixzone(atx,aty+trow,tw,1,(tptr+((r&1)?pixelsize:0)));
					}
				else	break;
				}
			}
		else	{
			for ( r=0; r < nr; r++, trow++ ) { 
				if (trow < th ) {
					if (!( pixelsize ))
					putzone8(atx,aty+trow,tw,1,(tptr+(r&1)));
					else	putzone(atx,aty+trow,tw,1,(tptr+((r&1)?pixelsize:0)));
					}
				else	break;
				}
			}
		if ( missing ) {
			previous = (trow/when);
			}
		}
	return;
}

public	void	isquash_rows(
	int	atx,	int 	aty, 
	int 	tw, 	int 	th,
	struct standard_image * iptr,
	int options,	char * tptr,
	int pixelsize
	)
{
	int	trow;
	int	sh=iptr->rows;
	int	sw=iptr->columns;
	char *	sptr;

	/* target row count is smallest so use as control */ 
	/* ---------------------------------------------- */
	for ( trow=0; trow < th; trow++ ) {

		if (!( sptr = connect_pixel_row( iptr->storage,((trow * sh)/th) ) ))
			break;

		else if ( tw > sw ) {
			istretch_columns( tptr, tw, sptr, sw, pixelsize );
			}
		else if ( tw < sw ) {
			isquash_columns( tptr, tw, sptr, sw, pixelsize );
			}
		else if ( pixelsize < 2 ) {
		 	memcpy(tptr,sptr,tw);
			}
		else 	memcpy(tptr,sptr,(tw*pixelsize));

		if (!( pixelsize )) {
		if ( options & _I_SPRITE )
			mixzone8(atx,aty+trow,tw,1,tptr);
		else	putzone8(atx,aty+trow,tw,1,tptr);
		}
		else	{
			if ( options & _I_SPRITE )
				mixzone(atx,aty+trow,tw,1,tptr);
			else	putzone(atx,aty+trow,tw,1,tptr);
			}

		}
	return;
}

#ifdef FCH_____________________________________
public	void	FCH____imakefit(
	int	atx,	int 	aty, 
	int 	tw, 	int 	th,
	struct standard_image * iptr,
	int options
	)
{
	unsigned int	trow=0;
	char	*	sptr=(char *) 0;
	char	*	tptr=(char *) 0;
	int		pixelsize;
	int		colourmaped;
	
	/* ensure legal values and stuff */
	/* ----------------------------- */
	if (!( iptr ))
		return;
	pixelsize = iptr->format;
	colourmaped = get_pixel_format();

	if ((!( tw )) || (!( th ))) 
 		return;
	if ((!( iptr )) || (!( iptr->rows )) || (!( iptr->columns )))
		return;
	else if (!(tptr = get_rowbuffer(tw,pixelsize)))
		return;
	else if ( th > iptr->rows ) {
		istretch_rows(atx,aty,tw,th,iptr,options,tptr,pixelsize);
		}
	else if ( iptr->rows > th ) {
		isquash_rows( atx,aty,tw,th,iptr,options,tptr,pixelsize);
		}
	else	{

		for ( trow=0; trow < (unsigned int)th; trow ++ ) {
			if (!( sptr = connect_pixel_row( iptr->storage,trow ) ))
				break;
			else if ( tw > iptr->columns ) {
				istretch_columns( tptr, tw, sptr, iptr->columns, pixelsize );
				}
			else if ( tw > iptr->columns ) {
				isquash_columns( tptr, tw, sptr, iptr->columns, pixelsize );
				}
			else if (!( pixelsize )) {
			 	memcpy(tptr,sptr,tw);
			if ( options & _I_SPRITE )
				mixzone8(atx,aty+trow,tw,1,tptr);
			else	putzone8(atx,aty+trow,tw,1,tptr);
			}
			else 	{
				memcpy(tptr,sptr,(tw*pixelsize));
				if ( options & _I_SPRITE )
					mixzone(atx,aty+trow,tw,1,tptr);
				else	putzone(atx,aty+trow,tw,1,tptr);
				}
			}
		}
	return;
}

public	void	FCH____ibestfit(
		int atx, int aty, int tw, int th,
		struct standard_image * iptr, int options )
{
	int	xh=0;
	int	xw=0;
	int		pixelsize;
	int		colourmaped;

	if ((!( tw )) || (!( th ))) 
 		return;
	if ((!( iptr )) || (!( iptr->rows )) || (!( iptr->columns )))
		return;

	pixelsize = iptr->format;
	colourmaped = get_pixel_format();

	if ( iptr->rows > iptr->columns ) {
		if (((iptr->rows*10) / iptr->columns) != (( th * 10) / tw )) {
			if ( ((iptr->columns*10) / tw) < ( (iptr->rows*10) / th ) ) {
				if ((xw = (tw - ((iptr->columns*th)/iptr->rows))) < 0)
					xw = 0;
				}
			else if ((xh = (th - ((tw * iptr->rows)/iptr->columns))) < 0)
				xh=0;

			}
		}
	else if (((iptr->columns*10) / iptr->rows) != ( (tw*10) / th )) {
		if ( ((iptr->columns*10) / tw) > ( (iptr->rows*10) / th ) ) {
			if ((xw = ( tw - ((iptr->columns*th)/iptr->rows))) < 0)
				xw = 0;
			}
		else if ((xh = ( th - ((tw * iptr->rows)/iptr->columns))) < 0)
			xh = 0;
		}

	imakefit(atx+(xw/2),aty+(xh/2),tw-xw,th-xh,iptr,options);
	return;
}
#endif
 
/*
**************************************************************************************************
* imakefit
**************************************************************************************************
*/
public	void	imakefit(
	int	atx,	int 	aty, 
	int 	tw, 	int 	th,
	struct standard_image * iptr,
	int options
	)
{
int		ix;
int		iy;
WORD*		tabx;
WORD*		taby;
unsigned long tmp;
int		IsNewLine;
int		pixelsize;
union 
	{ 
	BYTE* b;
	WORD* w;
	unsigned int * l;
	} rptr, rptrOri;

pixelsize = iptr->format;
if (!pixelsize)
	pixelsize = 1;

if ((!( tw )) || (!( th ))) 
 	return;
if ((!( iptr )) || (!( iptr->rows )) || (!( iptr->columns )))
	return;

/*
--------------------------------------------------------------
- Cas particulier sans mise à l'échelle algo rapide
--------------------------------------------------------------
*/
if ((tw == iptr->columns) && (th == iptr->rows))
	{
	for (iy=0 ; iy < th; iy++ )
		{
      rptrOri.b = connect_pixel_row( iptr->storage, iy);
		if (rptrOri.b)
			{
			if ( options & _I_SPRITE )
				mixzone( atx, aty+iy, tw, 1, rptrOri.b );
			else
				putzone( atx, aty+iy, tw, 1, rptrOri.b );
			}
		}
	return;
	}

/*
--------------------------------------------------------------
- Allocations en fonction des tailles trouvées
--------------------------------------------------------------
*/
rptr.b = allocate( tw*pixelsize );
if (!rptr.b)
   return;

tabx = allocate( tw*sizeof(WORD) );
if (!tabx)
   {
   liberate(rptr.b);
   return;
   }

taby = allocate( th*sizeof(WORD) );
if (!taby)
   {
   liberate(rptr.b);
   liberate(tabx);
   return;
   }

/*
--------------------------------------------------------------
- Calcul de la mise à l'échelle en x et y
--------------------------------------------------------------
*/
for (ix=0 ; ix<tw ; ix++)
   {
   tmp = (unsigned long)ix * (unsigned long)iptr->columns / (unsigned long)tw; 
   tabx[ix] = (WORD) tmp;
   }

for (iy=0 ; iy<th ; iy++)
   {
   tmp = (unsigned long)iy * (unsigned long)iptr->rows / (unsigned long)th; 
   taby[iy] = (WORD) tmp;
   }
   
/*
--------------------------------------------------------------
- Affichage
--------------------------------------------------------------
*/
for (iy=0 ; iy < th; iy++ )
   {
	/*
   -- Fabrication d'une nouvelle ligne
      Si la ligne est identique à celle utilisée par l'itération précédente, on garde 
      Sinon, on en refabrique une nouvelle
	*/
   IsNewLine = ((iy==0) || (taby[iy-1]!=taby[iy]));
         
   if (IsNewLine)
      {
      rptrOri.b = connect_pixel_row( iptr->storage, taby[iy]);
      if (rptrOri.b)
         {
			switch(pixelsize)
				{
				case 1:
					for( ix=0 ; ix<tw ; ix++)
						rptr.b[ix] = rptrOri.b[tabx[ix]];
					break;

				case 2:
					for( ix=0 ; ix<tw ; ix++)
						rptr.w[ix] = rptrOri.w[tabx[ix]];
					break;

				case 4:
					for( ix=0 ; ix<tw ; ix++)
						rptr.l[ix] = rptrOri.l[tabx[ix]];
					break;
				}
         }
      }
   
	/*   
   --- Affichage de la ligne courante
	*/
   if (rptrOri.b)
		{
		if ( options & _I_SPRITE )
	      mixzone( atx, aty+iy, tw, 1, rptr.b );
		else
	      putzone( atx, aty+iy, tw, 1, rptr.b );
		}
   }

/*
--------------------------------------------------------------
- Libérations
--------------------------------------------------------------
*/
liberate(rptr.b);
liberate(tabx);
liberate(taby);
}

/*
**************************************************************************************************
* ibestfit
**************************************************************************************************
*/
public	void	ibestfit(
		int atx, int aty, int tw, int th,
		struct standard_image * iptr, int options )
{
int xPrint;
int yPrint;
int cxPrint;
int cyPrint;
	
if ((!( tw )) || (!( th ))) 
 	return;
if ((!( iptr )) || (!( iptr->rows )) || (!( iptr->columns )))
	return;

cyPrint = iptr->rows * tw / iptr->columns;
if (cyPrint > th)
	{
   cxPrint = iptr->columns * th / iptr->rows;
   cyPrint = th;
	}
else
   cxPrint = tw;   

xPrint = (cxPrint < tw) ? atx + (tw - cxPrint) / 2 : atx ;
yPrint = (cyPrint < th) ? aty + (th - cyPrint) / 2 : aty ;

imakefit(xPrint, yPrint, cxPrint, cyPrint, iptr, options);
}
 
/*
**************************************************************************************************
* visual_makefit
**************************************************************************************************
*/
public	void	visual_makefit( int atx,int aty, int nbx, int nby , void * vptr, int w,int h )
{
	struct standard_image 	image;
	image.rows    = h;
	image.columns = w;
	image.storage = vptr;
	image.users   = 1;
	image.palette = (char *) 0;
	if ( get_pixel_format() )
		image.format = 0;
	else	image.format  = get_pixel_size();
	imakefit( atx, aty, nbx, nby, &image, 0);
	return;
}

public	void	visual_bestfit( int atx,int aty, int nbx, int nby , void * vptr, int w,int h )
{
	struct standard_image 	image;
	image.rows    = h;
	image.columns = w;
	image.storage = vptr;
	image.users   = 1;
	image.palette = (char *) 0;
	if ( get_pixel_format() )
		image.format = 0;
	else	image.format  = get_pixel_size();
	ibestfit( atx, aty, nbx, nby, &image, 0);
	return;
}


/*
**************************************************************************************************
* visual_makefit
**************************************************************************************************
*/
public	void	visual_makefit_buffer( int atx,int aty, int nbx, int nby , STDPSUPTR vptr )
{
	struct standard_image 	image;
	image.rows    = vptr->descriptor[1];
	image.columns = vptr->descriptor[0];
	image.storage = vptr;
	image.users   = 1;
	image.palette = NULL;
	image.format  = vptr->descriptor[6];
	imakefit( atx, aty, nbx, nby, &image, 0);
}

#endif	/* _vmakefit_c */


