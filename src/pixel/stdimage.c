#ifndef	_stdimage_c
#define	_stdimage_c

int	image_error=0;
int	colourmapping=1;
int	pixelsize=1;


void	standard_image_quality(int ps, int cm )
{
	pixelsize = ps;
	colourmapping=cm;
	return;
}


#ifdef	_PRLSYSGR_IMAGES

struct standard_image * drop_image( struct standard_image * iptr );
struct standard_image * load_image( char * filename );
struct standard_image * clone_image( char * filename );


struct standard_image * image_loader( char * filename )
{
	struct standard_image * iptr;
	if (!( iptr = clone_image( filename ) ))
		iptr = load_image( filename );
	return( iptr );
}

#else

struct standard_image * local_drop_image( struct standard_image * iptr )
{
	if ( iptr ) {
		if ( iptr->storage )
			liberate_pixel_storage( iptr->storage );
		if ( iptr->palette )
			liberate( iptr->palette );
		iptr = liberate( iptr );
		}
	return( iptr );
}

struct standard_image * local_allocate_image( int columns, int rows, int dath, int scaled )
{
	struct standard_image * iptr;
	int	c;
	int	r;
	int	pixelsize;
	int	colourmaped;
	int	dpi;
	char * rptr;
	if (!( iptr= allocate( sizeof (struct standard_image ) ) ))
		return(iptr);
	else	{
		pixelsize 	= get_pixel_size();
		colourmaped 	= get_pixel_format();
		iptr->users=0;
		iptr->columns = columns;
		iptr->rows = rows;
		iptr->users++;
		iptr->storage = (void *) 0;
		iptr->palette = (char *) 0;
		iptr->format  = 0;
		iptr->name = (char *) 0;
		if ((!( columns )) || (!( rows )))
			return( iptr );
		if (!( scaled )) {
			dpi = gethqfont(); sethqfont(75);
			}
		iptr->storage = allocate_graphic_storage(
				 0,0, 
				(iptr->columns = columns),
				(iptr->rows = rows)      );
		if (!( scaled )) {
			sethqfont(dpi);
			}
		if (iptr->storage) {
			for (r=0; r < iptr->rows; r++ ) {
				if (!(rptr = connect_pixel_row( iptr->storage,r )))
					break;
				else if ( colourmaped ) 
					memset(rptr,dath,(iptr->columns*pixelsize));
				else if (!( dath ))
					memset(rptr,dath,(iptr->columns*pixelsize));
				else	{
					for ( c=0; c < iptr->columns; c++ )
						put_palette_pixel( (rptr + (c * pixelsize)), dath );
					}
				}
			return( iptr );
			}
		else	return((iptr = local_drop_image(iptr)));
		}
}
	

static struct standard_image * true_colour_image( struct standard_image * iptr )
{
	int	r;
	int	c;
	int	p;
	int	ps;
	char *	pptr;
	char *	sptr;
	char *	tptr;
	struct	standard_image * jptr;
	ps = get_pixel_size();

	if (!( iptr ))
		return( iptr );
	else if ( get_pixel_format() )
		return( iptr );
	else if ( iptr->format == ps )
		return( iptr );
	else if (!(pptr = iptr->palette ))
		return( iptr );
	else if (!( jptr = local_allocate_image( iptr->columns, iptr->rows, 0, 0 ) ))
		return( iptr );
	else	{
		for (r=0; r < iptr->rows; r++ ) {
			if (!(sptr = connect_pixel_row( iptr->storage,r )))
				break;
			else if (!( tptr = connect_pixel_row( jptr->storage,r )))
				break;
			for (c=0; c < iptr->columns; c++ ) {
				p = (*(sptr++) & 0x00FF); p *= 4;
				put_logical_pixel(tptr,(*(pptr + p) & 0x00FF),(*(pptr + p + 1) & 0x00FF),(*(pptr + p + 2) & 0x00FF));
				tptr += ps;
				}				
			}
		local_drop_image( iptr );
		jptr->format = ps;
		return( jptr );
		}
}

struct standard_image * named_local_image_loader( char * filename )
{
	FILE	*	handle;
	int		status=0;
	char		signature[16];
	struct standard_image * iptr=(struct standard_image *) 0;

	image_error = 0;

	// Ensure the file exists
	// ----------------------
	if ( !filename || (*filename=='\0')) {
		image_error = 40;
		return((struct standard_image *) 0);
		}

	if ((handle = fopen( filename, "rb")) == (FILE*) 0) {
		image_error = 40;
		return((struct standard_image *) 0);
		}
	else	{
		
		fread(signature,16,1,handle);

		fclose( handle );

#ifdef	_standard_gif_h
		if (( signature[0] == 'G' )
		&&  ( signature[1] == 'I' )
		&&  ( signature[2] == 'F' )) {
			return( gif_loader(filename) );
			}
#endif

#ifdef	_standard_bmp_h
		if (( signature[0] == 'B' )
		&&  ( signature[1] == 'M' )) {
			return( true_colour_image( bmp_loader(filename) ) );
			}
#endif

#ifdef	_standard_png_h
		if ( png_tester( signature, 0, 8 ) ) {
			return( png_loader(filename) );
			}
#endif

#ifdef	_standard_ico_h
		if (( signature[0] == 0 )
		&&  ( signature[1] == 0 )
		&&  ( signature[2] == 1 )
		&&  ( signature[3] == 0 )) {
			return( ico_loader(filename) );
			}
#endif

#ifdef	_standard_jpeg_h
		if (( signature[6] == 'J' )
		&&  ( signature[7] == 'F' )
		&&  ( signature[8] == 'I' )
		&&  ( signature[9] == 'F' )) {
			return( true_colour_image( jpeg_loader(filename) ) );
			}

	/* ------------------------------------------------------------ */
	/* Correction required when the file has been prefixed with a 	*/
	/* Photoshop prefix record					*/
 	/* Version 1.1a.1.01 IJM 17/09/2001				*/
	/* ------------------------------------------------------------ */
		else if (( (signature[0] & 0x00FF) == 0x00FF )
		     &&  ( (signature[1] & 0x00FF) == 0x00D8 )
		     &&  ( (signature[2] & 0x00FF) == 0x00FF )) {
			return( true_colour_image( jpeg_loader(filename) ) );
			}
	/* ------------------------------------------------------------ */

#endif
		else	{
			image_error = 56;
			return((struct standard_image *) 0);
			}

		}
}

/*	-------------------------------------------------	*/
/*	This stub has been added to preserve the filename 	*/
/*	with the image structure. this allows use of name	*/
/*	by scaled vector graphics production code		*/
/*	-------------------------------------------------	*/
struct standard_image * local_image_loader( char * filename )
{
	struct standard_image * iptr=(struct standard_image *) 0;
	if (!( filename ))
		return( iptr );
	else if (!( iptr = named_local_image_loader( filename )))
		return(iptr);
	else if (!( iptr->name = allocate( strlen( filename ) + 1 ) ))
		return( iptr );
	else	{
		strcpy( iptr->name, filename );
		return( iptr );
		}
}

#endif	/* _PRLSYSGR_IMAGES */

struct	resolved_image {
	char	*	name;
	int		number;
	struct standard_image * image;
	struct resolved_image * next;
	struct resolved_image * previous;
	};

static	struct resolved_image * iHeap=(struct resolved_image*) 0;
static	int			iHeapCount=0;

int	image_heap_count()	{	return( iHeapCount );	}

static	void	release_heap_item( struct resolved_image * rptr )
{
	rptr->image = local_drop_image(rptr->image);
	rptr->name  = liberate( rptr->name );
	rptr        = liberate( rptr );
	return;
}

void	release_images()
{
	struct resolved_image * rptr;
	while ((rptr = iHeap) != (struct resolved_image *) 0) {
		iHeap = rptr->next,
		release_heap_item( rptr );
		}
	return;
}

int	heapcompare( char * aptr, char * bptr )
{
	while (( *aptr != 0 ) && ( *bptr != 0))
		if ( *(aptr++) != *(bptr++) )
			return(0);
	
	if ( *aptr  != *bptr )
		return(0);
	else	return(1);
}

struct standard_image * resolve_image_by_number( int number )
{
	struct resolved_image * rptr;
	for (	rptr=iHeap;
		rptr != (struct resolved_image *) 0;
		rptr = rptr->next )
		if ( rptr->number == number )
			return( rptr->image );
	return((struct standard_image *) 0);
}

char *	resolve_imagename_by_number( int number )
{
	struct resolved_image * rptr;
	for (	rptr=iHeap;
		rptr != (struct resolved_image *) 0;
		rptr = rptr->next )
		if ( rptr->number == number )
			return( rptr->name );
	return((char *) 0);
}


/*	correction for visual drop image 28/06/2008 : IJM */
int	imageheap_drop_item( char * nptr )
{
	struct resolved_image * rptr;
	for (	rptr=iHeap;
		rptr != (struct resolved_image *) 0;
		rptr = rptr->next ) {
		if ( heapcompare( rptr->name, nptr ) ) {
			if (!( rptr->previous )) {
				if ((iHeap = rptr->next) != (struct resolved_image *) 0)
					iHeap->previous = (struct resolved_image *) 0;
				}
			else if (!( rptr->next ))
				rptr->previous->next = (struct resolved_image *) 0;
			else	{
				rptr->next->previous = rptr->previous;
				rptr->previous->next = rptr->next;
				}
			release_heap_item( rptr );
			return(1);
			}
		}
	return(0);
}


struct standard_image * resolve_image( char * nptr, int nlen )
{
	struct standard_image * iptr;
	struct resolved_image * rptr;
	char		      * iname;
	int			i;
	int			llenuse;
	for (	rptr=iHeap;
		rptr != (struct resolved_image *) 0;
		rptr = rptr->next ) {
		if ( heapcompare( rptr->name, nptr ) ) {
			return( rptr->image );
			}
		}
	if ((iname = allocate( nlen+1 )) != (char *) 0) {
		for (llenuse=0,i=0; i < nlen; i++ ) {
			if (!( *(nptr+i) ))
				break;
			else if ( *(nptr+i) > ' ' )
				llenuse = (i+1);
			}
		nlen = llenuse;
		for (i=0; i < nlen; i++ )  {
			if (!( *(nptr+i) ))	break;
			else			*(iname+i) = *(nptr+i);
			}
		*(iname+i) = 0;
		if (( iptr = local_image_loader( iname )) != (struct standard_image *) 0) {
			if (( rptr = allocate( sizeof( struct resolved_image ))) != (struct resolved_image *) 0) {
				rptr->number=++iHeapCount;
				rptr->name = iname;
				rptr->image= iptr;
				if ((rptr->next = iHeap) != (struct resolved_image*) 0 )
					iHeap->previous = rptr;
				rptr->previous = (struct resolved_image *) 0;
				iHeap      = rptr;
				return( iptr );
				}
			iptr = local_drop_image(iptr);
			}
		iname = liberate( iname );
		}
	return( (struct standard_image *) 0);
}



#endif	/* _stdimage_c */


