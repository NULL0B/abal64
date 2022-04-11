#include <stdio.h>
int	echo=0;
struct	fme	{
	int	height;
	int	width;	
	int	bytes;
	int	reserved[2];
	char *	buffer;
	};

struct	fmf	{
	char	symbolicname[16];
	int	totalsize;
	int	cellheight;
	int	cellwidth;
	int	reserved[4];
	int	offsets[256];
	struct	fme items[256];
	};




char	basefontbuffer[256];

void	*	malloc(int);
void		free( void *);

void	*	allocate( int n )
{
	return( malloc(n) );
}

void	*	liberate( void * vptr )
{
	free( vptr );
	return(0);
}

void	storebit( char * bptr, int c, int l, int w, int v )
{
	*(bptr + ((l*w)+c)) = v;
	return;
}

void	showbit( char * bptr, int c, int l, int w )
{
	if ( *(bptr + ((l*w)+c)) != 0 )
		printf("*");
	else	printf(".");
	return;
}

struct fmf * drop_symbolic_font( struct fmf * fptr )
{	
	int	i;
	char * 	cptr;
	if (!( fptr ))
		return( fptr );

	for (i=0; i < 256; i++ )  {
		
		if (!( cptr = fptr->items[i].buffer ))
			continue;
		else	fptr->items[i].buffer = liberate( fptr->items[i].buffer );

		}

	fptr = liberate( fptr );

	return(0);
}

void	show_symbolic_font( struct fmf * fptr )
{	
	int	i,c,r,w,h;
	char *	cptr;
	printf("\nCell Dimensions H=%u, W=%u, Total Size=%u \n",
		fptr->cellheight,
		(w=fptr->cellwidth),
		fptr->totalsize);

	for (i=0; i < 256; i++ )  {
		
		printf("\nCharacter 0x00%x at 0x%x : ",
			(i&0x00FF),
			fptr->offsets[(i&0x00FF)]);

		if ( i > 32 )
			printf(" (%c) \n",(i&0x00FF));
		else	printf(" ( ) \n");

		if (!( cptr = fptr->items[i].buffer ))
			continue;

		for ( r=0; r < fptr->items[i].height; r++ ) {
			if (!(w=fptr->items[i].width))
				w = fptr->cellwidth;
			for ( c=0; c < w; c++ )
				showbit( cptr, c,r,w );
			printf("\n");
			}

		}


	return;
}

int	extractint( char * bptr )
{
	return( ( 
		 (* bptr    & 0x00FF) +
		((*(bptr+1) & 0x00FF) << 8 )
		)
		);
}


char * loadfontfile( char * nptr )
{
	FILE	* handle;
	int	status = 0;
	char *	textfontbuffer=(char *) 0;
	int	textfontsize=0;
	int	textfontheight=0;
	int	textfontwidth=0;
	int	special=0;

	if ((handle = fopen( nptr, "rb")) != (FILE *) 0) {
		if ( fread(basefontbuffer,256,1,handle) == 1 ) {
			textfontsize = extractint( (basefontbuffer+16) );
			if ((textfontbuffer = allocate( textfontsize )) != (char *) 0 ) {
				memcpy( textfontbuffer, basefontbuffer, 256 );
				if ( fread((textfontbuffer+256),(textfontsize - 256),1,handle) != 1 )
					textfontbuffer = liberate( textfontbuffer );
				}
			}
		fclose( handle );
		}
	return(textfontbuffer);
}

struct fmf *	load_symbolic_font( char * nptr )
{
	int	bits;
	struct fmf *	fptr=(struct fmf*)0;
	char	   *	textfontbuffer=(char *) 0;
	char	   *	iptr;
	char	   *	cptr;
	int	v,l,i,o,c,r,h,w,n;
	if (!(textfontbuffer = loadfontfile( nptr )))
		return( fptr );

	else if (!(fptr = allocate( sizeof( struct fmf ) )))
		return( fptr );

	for (i=0; i < 16; i++ )
		if (!( fptr->symbolicname[i] = *(textfontbuffer + i)))
			break;

	// Read header fields
	// ------------------
	fptr->totalsize=32+512;
	fptr->cellheight=extractint( (textfontbuffer+18) );
	fptr->cellwidth= extractint( (textfontbuffer+20) );

	// Read and expand individual character cell information
	// -----------------------------------------------------
	for (	iptr=(textfontbuffer+32),i=0; 
		i < 256; 
		i++ 	) {

		// Calculate character position
		// ----------------------------
		o = extractint(iptr); iptr+= 2;

		cptr = (textfontbuffer+o);

		fptr->offsets[i] = o;

		// Collect character height and width
		// ----------------------------------
		h = fptr->items[i].height = extractint(cptr); cptr += 2;
		w = fptr->items[i].width  = extractint(cptr); cptr += 2;

		fptr->items[i].bytes=0;

		// Collect these two and keep just in case
		// ---------------------------------------
		fptr->items[i].reserved[0] = extractint(cptr); cptr += 2;
		fptr->items[i].reserved[1] = extractint(cptr); cptr += 2;


		// Check cell dimensions
		// ---------------------
		if (!( h )) {
			h = fptr->items[i].height = fptr->cellheight;
			}
		if (!( w )) {
			w = fptr->items[i].width = fptr->cellwidth;
			}

		// Calculate the bit image requirements
		// ------------------------------------
		bits = (fptr->items[i].height * fptr->items[i].width);

		// Allocate for bit storage
		// ------------------------
		if (!(fptr->items[i].buffer = allocate(bits))) {
			// Allocation error for character data
			textfontbuffer = liberate( textfontbuffer);
			return( drop_symbolic_font( fptr ) );
			}
		
		fptr->items[i].bytes = (8 + ((bits / 8) + (bits % 8 ? 1 : 0)));

		for (n=0; n < bits; n++)
			*(fptr->items[i].buffer + n) = 0;

		r = 0x080;

		v = (*(cptr++) & 0x00FF);

		for (	r=0x0080,l=0; 
			l < h; 
			l++ 	) {
			for ( c=0; c < w; c++ ) {
				storebit(fptr->items[i].buffer,
					c,l,w,(v&r));
				r >>= 1;
				if (!( r )) {
					r = 0x0080;
					v = (*(cptr++) & 0x00FF);
					}
				}
			}

		fptr->totalsize += fptr->items[i].bytes;
		}
	
	// Release the file buffer version of the font
	// -------------------------------------------
	textfontbuffer = liberate( textfontbuffer);

	// Return the symbolic expanded version
	// ------------------------------------
	return( fptr );

}

char * storeint( char * rptr, int v )
{
	*(rptr++) = (v & 0x00FF);
	*(rptr++) = ((v >> 8) & 0x00FF);
	return( rptr );
}

void	save_symbolic_font( char * nptr, struct fmf * fptr )
{
	FILE		*	handle;
	char		*	rptr=(char *) 0;
	char		*	cptr=(char *) 0;
	int		l,i,o,n,c,r,w,h;
	char		*	textfontbuffer;
	if (!(rptr = allocate( fptr->totalsize )))
		return;

	textfontbuffer = rptr;

	// Save font name field
	// --------------------
	for (i=0; i < 16; i++ )
		if (!(*(rptr+i) = fptr->symbolicname[i]))
			break;
	for (; i < 16; i++ )
		*(rptr+i) = 0;
	rptr += 16;

	// Save font header size fields
	// ----------------------------
	rptr = storeint(rptr,fptr->totalsize);
	rptr = storeint(rptr,fptr->cellheight);
	rptr = storeint(rptr,fptr->cellwidth);
	rptr = storeint(rptr,0);
	rptr = storeint(rptr,0);
	rptr = storeint(rptr,0);
	rptr = storeint(rptr,0);
	rptr = storeint(rptr,0);

	// Calculate and Save character offset table entries
	// -------------------------------------------------
	for (o=32+512, i=0; i < 256; i++ ) {
		fptr->offsets[i] = o;
		rptr = storeint(rptr, o );
		o += fptr->items[i].bytes;
		}

	// Save character entries
	// ----------------------
	for (i=0; i < 256; i++) {

		// Save character size fields
		// --------------------------
		rptr = ( fptr->offsets[i] + textfontbuffer);
		rptr = storeint( rptr, (h =fptr->items[i].height) );
		rptr = storeint( rptr, (w =fptr->items[i].width ) );
		rptr = storeint( rptr, 0 );
		rptr = storeint( rptr, 0 );

		if ((!( h )) 
		||  (!( w ))) {
			for (n=0; n < fptr->items[i].bytes; n++ )
				*(rptr++) = 0;
			}
		else	{
			// Store character compressed data bits
			// ------------------------------------
			cptr = fptr->items[i].buffer;
			for (n=0,r=0x0080,l=0; l < h; l++ ) {
				for (c=0; c < w; c++ ) {
					if ( *(cptr++) )
						n |= r;
					r >>= 1;
					if (!( r )) {
						*(rptr++) =n;
						r = 0x0080;
						n = 0;
						}
					}
				}
			if ( r != 0x0080 )
				*(rptr++) =n;
			}
		}

	// Write font buffered infor to the file
	// -------------------------------------
	if ((handle = fopen( nptr, "wb" )) != (FILE *) 0) {
		fwrite( textfontbuffer, 1, fptr->totalsize, handle );
		fclose(handle);
		}

	fptr = liberate( fptr );

	textfontbuffer = liberate( textfontbuffer);

	return(fptr);
}	


void	doit( char * nptr )
{	
	struct fmf 	*	fptr=(struct fmf*)0;

	if (!(fptr = load_symbolic_font( nptr )))
		return;
	else	{
		printf("\nFont File : %s\n",nptr);
		show_symbolic_font( fptr );

	/*	save_symbolic_font( nptr, fptr );	*/

		fptr = drop_symbolic_font( fptr );

		return;
		}

}


void	operation( char * nptr )
{
	if ( *nptr != '-' )
		doit(nptr);

}



int	main( int argc, char * argv[] )
{
	int	argi;
	
	if ( argc == 1 )
		printf("\n   Font Manager File Fix Utility : Version 1.1a.0.02\n   Provisoire du 29/01/2001\n   Copyright (c) 2001,2006 Amenesik / Sologic \n\n   { [-wfilename] [-ffilename] } \n");
	else for ( argi=1; argi < argc; argi++ )
		operation( argv[argi] );
	return(0);
}


