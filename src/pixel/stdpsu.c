/*
 *	--------------------	----------------------------
 *	Project	: JavAbal	Compiler and Virtual Machine	
 *		: NvGrPrl	Amenesik / Sologic Graphical Navigator
 *	--------------------	----------------------------
 *	Date	: 18/09/1997
 *		: 04/08/1999
 *	--------------------	----------------------------
 */
#ifndef	_STDPSU_C
#define _STDPSU_C

#include "stdpsu.h"

#if defined(WIN32)
#include "allocate.h"
#include "pixelapi.h"
#include "sysfile.h"
#else
#include "stdmem.h"
#endif

#if defined(UNIX) || defined(WIN32)
#else
#define	_MF_TWIN24_
#endif
#ifdef	_MF_TWIN24_
VPTR	mf_liberate_psu( VPTR );
VPTR	mf_allocate_psu( WORD, WORD );
#endif


#ifdef UNIX
static	char	SystemFileName[256];

PUBLIC	char	*	sysfilename( char * nptr )
{
	int	i;
	for ( i=0; *(nptr+i) != 0; i++ ) 
#ifndef	UNIX
		if ((SystemFileName[i] = *(nptr+i)) == '/')
			SystemFileName[i] = '\\';
#else
		if ((SystemFileName[i] = *(nptr+i)) == '\\')
			SystemFileName[i] = '/';
#endif
	SystemFileName[i++] = 0;
	return( SystemFileName );
}
#endif

#ifdef	UNIX
#ifdef	HPUX
#define	EVENBOUND
#endif
#endif

#ifdef	EVENBOUND

static	void	psu_put_ptr ( unsigned char * p, void * v)
{
	unsigned long int l = (unsigned long) v;
	*(p++) = (l & 0x00FF);
	*(p++) = ((l >> 8) & 0x00FF);	
	*(p++) = ((l >>16) & 0x00FF);	
	*(p++) = ((l >>24) & 0x00FF);	
}

static	void * psu_get_ptr ( unsigned char * p )
{
	unsigned long  int v=0;
	v  = ( *(p++) & 0x00FF );
	v |= ( (*(p++) & 0x00FF) << 8 );
	v |= ( (*(p++) & 0x00FF) << 16);
	v |= ( (*(p++) & 0x00FF) << 24);
	return( v );
}

static	void	psu_put_word( unsigned char * p, unsigned short int v )
{
	*(p++) = (v & 0x00FF);
	*(p++) = ((v >> 8) & 0x00FF);	
}

static	unsigned short int psu_get_word( unsigned char * p )
{
	unsigned short int v=0;
	v  = ( *(p++) & 0x00FF );
	v |= ( (*(p++) & 0x00FF) << 8 );
	return( v );
}

#else
/*	--------------		*/
/*	NOT EVEN BOUND		*/
/*	--------------		*/
#define	psu_put_word( p, v ) *((WORD PTR) p) = v
#define	psu_get_word( p )    *((WORD PTR) p) 
#define	psu_put_ptr( p, v ) *((BPTR PTR) p) = v
#define	psu_get_ptr( p )    *((BPTR PTR) p)
#endif

PUBLIC	VOID	psu_put_next ( root, linkage  )
	BPTR	root;
	BPTR	linkage;
{
	if ( linkage == (BPTR) 0) 
		memset( root, 0, 5 );
	else	{
		*(root++) = _PSU_VALIDPTR;
		psu_put_ptr( root,linkage );
		}
	return;
}


PUBLIC	VOID	psu_put_atcol( root, value )
	BPTR	root;
	WORD	value;
{
	root += _PSU_AT_COLUMN;
	psu_put_word( (root), (value) );
	return;
}

PUBLIC	VOID	psu_put_atrow( root, value )
	BPTR	root;
	WORD	value;
{
	root += 	_PSU_AT_ROW;
	psu_put_word( (root), (value) );
	return;
}

PUBLIC	VOID	psu_put_nbcol( root, value )
	BPTR	root;
	WORD	value;
{
	root += 	_PSU_COLUMNS;
	psu_put_word( (root), (value) );
	return;
}

PUBLIC	VOID	psu_put_nbrow( root, value )
	BPTR	root;
	WORD	value;
{
	root += 	_PSU_ROWS;
	psu_put_word( (root), (value) );
	return;
}

PUBLIC	BPTR	psu_get_next ( root )
	BPTR	root;
{
	if ( *(root++) != _PSU_VALIDPTR )
		return((BPTR) 0 );
	else 	return( psu_get_ptr( (root) ) );
}

PUBLIC	WORD	psu_get_atcol( root )
	BPTR	root;
{
	root += _PSU_AT_COLUMN;
	return( psu_get_word( (root) ) );
}

PUBLIC	WORD	psu_get_atrow( root )
	BPTR	root;
{
	root += 	_PSU_AT_ROW;
	return( psu_get_word( (root) ) );
}

PUBLIC	WORD	psu_get_nbcol( root )
	BPTR	root;
{
	root += 	_PSU_COLUMNS;
	return( psu_get_word( (root) ) );
}

PUBLIC	WORD	psu_get_nbrow( root )
	BPTR	root;
{
	root += 	_PSU_ROWS;
	return( psu_get_word( (root) ) );
}


PUBLIC	VOID	psu_put_pixel ( root, atcol, atrow, value )
	BPTR	root;
	WORD	atcol;
	WORD	atrow;
	WORD	value;
{
	WORD	nbcol;
	if ( root != (BPTR) 0 ) {
		nbcol = psu_get_nbcol( root );
		*( root + (((atrow * nbcol) + atcol) + _PSU_STORAGE)) = (PIXIBYTE) value;
		}
	return;
}

PUBLIC	VOID	psu_put_pixels( root, atcol, atrow, nbcol, value )
	BPTR	root;
	WORD	atcol;
	WORD	atrow;
	WORD	nbcol;
	WORD	value;
{
	WORD	colmax;
	if ( root != (BPTR) 0 ) {
		colmax = psu_get_nbcol( root );
		root += (((atrow * colmax) + atcol) + _PSU_STORAGE);
		for (; nbcol != 0; nbcol-- )
			*(root++) = (PIXIBYTE)value;
		}
	return;
}

PUBLIC	VOID	psu_get_pixels( root, atcol, atrow, nbcol, buffer,  pixelsize )
	BPTR	root;
	WORD	atcol;
	WORD	atrow;
	WORD	nbcol;
	BPTR	buffer;
	WORD	pixelsize;
{
	WORD	i;
	WORD	colmax;
	if ( root != (BPTR) 0 ) {
		colmax = psu_get_nbcol( root );
		root += (((atrow * (colmax*pixelsize)) + (atcol*pixelsize)) + _PSU_STORAGE);
		for (; nbcol != 0; nbcol-- )
			for (i=0; i < pixelsize; i++ )
				*(buffer++) = *(root++);
		}
	return;
}

PUBLIC	BPTR	psu_get_buffer( root, atrow, pixelsize )
	BPTR	root;
	int 	atrow;
	int	pixelsize;
{
	int 	colmax;
	if ( root != (BPTR) 0 ) {
		colmax = (psu_get_nbcol( root )*pixelsize);
		root += ((atrow * colmax) + _PSU_STORAGE);
		}
	return( root );
}

PUBLIC	VOID	psu_commit_zone( root, topcol, toprow, atcol, atrow, nbcol, nbrow )
	BPTR	root;
	WORD	topcol;
	WORD	toprow;
	WORD	atcol;
	WORD	atrow;
	WORD	nbcol;
	WORD	nbrow;
{
	BPTR	work;
	WORD	colmax;
	WORD	rowmax;
	if ((work = root) != (BPTR) 0 ) {
		colmax = psu_get_nbcol( root );
		rowmax = psu_get_nbrow( root );
		while ( nbrow > 0 ) {
			if ( atrow >= rowmax ) {
				if ((root = psu_get_next( root )) == (BPTR) 0)
					break;
				else	{
					atrow -= rowmax;
					rowmax = psu_get_nbrow( root );
					colmax = psu_get_nbcol( root );
					}
				}
			work = (root + ((atrow * colmax) + atcol + _PSU_STORAGE));
			putzone(topcol,toprow,nbcol,1,work);
			nbrow--; atrow++; toprow++; 
			}
		}
	return;
}

PUBLIC 	BPTR		resolve_pixel_storage(psptr)
	STDPSUPTR	psptr;
{
	if ( psptr != (STDPSUPTR) 0)
		return( psptr->root );
	else	return( (BPTR) 0 );
}

PUBLIC 	STDPSUPTR	liberate_pixel_storage(psptr)
	STDPSUPTR	psptr;
{
	BPTR	current;

	if ( psptr != (STDPSUPTR) 0) {

#ifdef	_MF_TWIN24_

		if ( psptr->root )
			psptr->root = mf_liberate_psu( psptr->root );

#else	/* ! _MF_TWIN24_ */

		while ((current = psptr->root) != (BPTR) 0) {
			psptr->root = psu_get_next( current );
			current = liberate( current );
			}
#endif
		psptr = liberate( psptr );
		}
	return( psptr );
}		

PUBLIC	BPTR	allocate_for_psu(itemsize,atcol,atrow,nbcol,nbrow)
	int 	itemsize;
	WORD	atcol;
	WORD	atrow;
	WORD	nbcol;
	WORD	nbrow;
{
	BPTR	root;
	if ((root = (BPTR) allocate( itemsize )) != (BPTR) 0) {
		psu_put_next ( root, (BPTR) 0 );
		psu_put_atcol( root, atcol    );
		psu_put_atrow( root, atrow    );
		psu_put_nbcol( root, nbcol    );
		psu_put_nbrow( root, nbrow    );
		}
	return( root );
}

#define	StorageWidth	psptr->descriptor[0]
#define	StorageHeight	psptr->descriptor[1]
#define	StorageItems	psptr->descriptor[2]
#define	StorageRows  	psptr->descriptor[3]
#define	StorageAtCol	psptr->descriptor[4]
#define	StorageAtRow	psptr->descriptor[5]
#define	StoragePixel	psptr->descriptor[6]

#ifdef	_MF_TWIN24_

PUBLIC	STDPSUPTR	allocate_pixel_storage( psptr )
	STDPSUPTR	psptr;
{
	psptr->root = mf_allocate_psu( StorageWidth, StorageHeight );
	return( psptr );
}

#else	/* ! _MF_TWIN24_ */

PUBLIC	STDPSUPTR	allocate_pixel_storage( psptr )
	STDPSUPTR	psptr;
{
	BPTR		previous=(BPTR) 0;
	BPTR		current=(BPTR) 0;
        WORD		item;
	WORD		rows;
	unsigned int	itemsize;
	WORD		totalrows;
	WORD		currentrow;
	WORD		pixelsize=StoragePixel;

        for ( totalrows=StorageHeight,currentrow=StorageAtRow,item=0;
	      item < StorageItems; item++ ) {
                if ( totalrows < StorageRows )
       	                rows = totalrows;
       	        else	rows = StorageRows;
                itemsize = (((StorageWidth*pixelsize) * rows) + _PSU_STORAGE );

		/* Allocate Current Buffer */
		/* ----------------------- */
		if ((current = allocate_for_psu(itemsize,
						StorageAtCol,
						currentrow,
						StorageWidth,
						rows )) == (BPTR) 0)
			return( liberate_pixel_storage( psptr ) );
		else if ( psptr->root == (BPTR) 0 )
			psptr->root = current;
		else	psu_put_next( previous, current );
		previous = current;
                totalrows -= rows;
                currentrow += rows;
		}
	return( psptr );
}

#endif

PUBLIC	STDPSUPTR	allocate_for_pixels()
{
	STDPSUPTR	pptr;
	WORD		i;
	if ((pptr = (STDPSUPTR) allocate( sizeof( STDPSU ) )) != (STDPSUPTR) 0) {
		for (i=0; i < 8; i++ )
			pptr->descriptor[i]=0;
		pptr->root = (BPTR) 0;
		pptr->current = (BPTR) 0;
		pptr->seekbase = 0;
		pptr->seeksize = 0;
		}
	return( pptr );
}		

PUBLIC	STDPSUPTR	allocate_graphic_storage( gratcol, gratrow, grnbcol, grnbrow )
	WORD		gratcol;
	WORD		gratrow;
	WORD		grnbcol;
	WORD		grnbrow;
{
	STDPSUPTR	psptr=(STDPSUPTR) 0;
#if !defined(UNIX) && !defined(WIN32)
	WORD		status;
#endif

	/* -------------------------------- */
	/* Allocate Pixel Storage Controler */
	/* -------------------------------- */
	if ((psptr = allocate_for_pixels()) != (STDPSUPTR) 0) {

		StorageWidth  = grnbcol;
		StorageHeight = grnbrow;
		StorageAtCol  = gratcol;
		StorageAtRow  = gratrow;
#if defined(UNIX) || defined(WIN32)
		StorageItems  = 1;
		StorageRows   = grnbrow;		
		StoragePixel  = get_pixel_size();
#else
		/* ---------------------------------- */
		/* Calculate Pixel Buffers Descriptor */
		/* ---------------------------------- */
		status = calcbuff( (WORD PTR) (& StorageWidth) );
#endif
		/* ------------------------------------------------ 	*/
		/* Bidh fiosrachadh a leanas ann 'descriptor' a-nis 	*/
		/* ------------------------------------------------ 	*/
		/*	descriptor[0]	= de cho fad 's a tha loighne	*/
		/*	descriptor[1]   = cia mheud loighnichean ann	*/
		/*	descriptor[2]   = an aireamh buphraichean  	*/
		/*			  uile gu leir			*/
		/*	descriptor[3]   = cia mheud  loighnichean 	*/
		/*			  anns gach 'buffer'		*/
		/*	descriptor[4]   = aireamh an toiseach cuilbh	*/
		/*	descriptor[5]   = aireamh an toiseach loighne 	*/
		/* ---------------------------------------------------- */
		psptr = allocate_pixel_storage( psptr );

#ifdef	_MF_TWIN24_

		psu_put_atcol( psptr->root, gratcol    );
		psu_put_atrow( psptr->root, gratrow    );

#endif

		}
	return( psptr );
}

PUBLIC	STDPSUPTR	allocate_shadow_storage( psptr )
	STDPSUPTR	psptr;
{
	if ( psptr == (STDPSUPTR) 0 )
		return( psptr );
	else 	return( 
			allocate_graphic_storage(
				StorageAtCol,
				StorageAtRow,
				StorageWidth,
				StorageHeight)
			);
}


PUBLIC	STDPSUPTR	allocate_textual_storage( atcol, atlin, nbcol, nblin )
	WORD		atcol;
	WORD		atlin;
	WORD		nbcol;
	WORD		nblin;
{
	STDPSUPTR	psptr=(STDPSUPTR) 0;
#if !defined(UNIX) && !defined(WIN32)
	WORD		status;
#endif

	/* -------------------------------- */
	/* Allocate Pixel Storage Controler */
	/* -------------------------------- */
	if ((psptr = allocate_for_pixels()) != (STDPSUPTR) 0) {

#if defined(UNIX) || defined(WIN32)
		StorageWidth  = nbcol;
		StorageHeight = nblin;
		StorageAtCol  = atcol;
		StorageAtRow  = atlin;
		StorageItems  = 1;
		StorageRows   = nblin;		
		StoragePixel  = get_pixel_size();
#else
		/* ---------------------------------- */
		/* Calculate Pixel Storage Descriptor */
		/* ---------------------------------- */
		status = calczone( atcol, atlin, nbcol, nblin,(WORD PTR) (& StorageWidth) );
#endif
		/* ------------------------------------------------ 	*/
		/* Bidh fiosrachadh a leanas ann 'descriptor' a-nis 	*/
		/* ------------------------------------------------ 	*/
		/*	descriptor[0]	= de cho fad 's a tha loighne	*/
		/*	descriptor[1]   = cia mheud loighnichean ann	*/
		/*	descriptor[2]   = an aireamh buphraichean  	*/
		/*			  uile gu leir			*/
		/*	descriptor[3]   = an aireamh loighnichean 	*/
		/*			  anns gach 'buffer'		*/
		/*	descriptor[4]   = aireamh an toiseach cuilbh	*/
		/*	descriptor[5]   = aireamh an toiseach loighne 	*/
		/* ---------------------------------------------------- */
		psptr = allocate_pixel_storage( psptr );

		}
	return( psptr );

}

PUBLIC	STDPSUPTR	liberate_process_storage( psptr )
	STDPSUPTR	psptr;
{
	if ( psptr )
		psptr = liberate( psptr );

	return((STDPSUPTR) 0 );
}

PUBLIC	STDPSUPTR	allocate_process_storage( nbcol, nblin, sysptr )
	WORD		nbcol;
	WORD		nblin;
	VPTR		sysptr;
{
	STDPSUPTR	psptr=(STDPSUPTR) 0;
	WORD		status;

	/* -------------------------------- */
	/* Allocate Pixel Storage Controler */
	/* -------------------------------- */
	if ((psptr = allocate_for_pixels()) != (STDPSUPTR) 0) {

		/* ---------------------------------- */
		/* Calculate Pixel Storage Descriptor */
		/* ---------------------------------- */
		status = calczone( 0, 0, nbcol, nblin,(WORD PTR) (& StorageWidth) );

		/* ------------------------------------------------ 	*/
		/* Bidh fiosrachadh a leanas ann 'descriptor' a-nis 	*/
		/* ------------------------------------------------ 	*/
		/*	descriptor[0]	= de cho fad 's a tha loighne	*/
		/*	descriptor[1]   = cia mheud loighnichean ann	*/
		/*	descriptor[2]   = an aireamh buphraichean  	*/
		/*			  uile gu leir			*/
		/*	descriptor[3]   = an aireamh loighnichean 	*/
		/*			  anns gach 'buffer'		*/
		/*	descriptor[4]   = aireamh an toiseach cuilbh	*/
		/*	descriptor[5]   = aireamh an toiseach loighne 	*/
		/* ---------------------------------------------------- */
		psptr->root = sysptr;

		}
	return( psptr );

}

PUBLIC	VOID		background_pixel_capture( psptr )
	STDPSUPTR	psptr;
{
#if defined(UNIX) || defined(WIN32)
	/* since the low level uses a linear buffer resolve it now */
	/* ------------------------------------------------------- */
	userware(StorageWidth,StorageHeight,(psptr->root+_PSU_STORAGE));
#else
	userware(StorageWidth,StorageHeight,psptr->root);
#endif
	return;
}

PUBLIC	VOID		foreground_pixel_capture( psptr )
	STDPSUPTR	psptr;
{
#if defined(UNIX) || defined(WIN32)
	/* since the low level uses a linear buffer resolve it now */
	/* ------------------------------------------------------- */
	shareware(StorageWidth,StorageHeight,StorageAtCol,StorageAtRow,(psptr->root+_PSU_STORAGE));
#else
	shareware(StorageWidth,StorageHeight,StorageAtCol,StorageAtRow,psptr->root);
#endif
	return;
}

PUBLIC	VOID		move_pixel_capture( psptr, atcol, atrow )
	STDPSUPTR	psptr;
	WORD		atcol;
	WORD		atrow;
{
	if (!( psptr ))
		return;
	else	{
		StorageAtCol = atcol;
		StorageAtRow = atrow;
		moveware(atcol,atrow);
		return;
		}
}


PUBLIC	VOID		cancel_pixel_capture( psptr )
	STDPSUPTR	psptr;
{
	hardware();
	return;
}

PUBLIC	VOID		commit_pixel_zone( psptr, atcol, atrow, nbcol, nbrow )
	STDPSUPTR	psptr;
	WORD		atcol;
	WORD		atrow;
	WORD		nbcol;
	WORD		nbrow;
{
	BPTR	bptr;
	WORD	TargetRow;
	WORD	TargetCol;
	if ((bptr = psptr->root) != (BPTR) 0) {
		TargetRow = StorageAtRow + atrow;
		TargetCol = StorageAtCol + atcol;
		while ( atrow >= StorageRows ) {
			atrow -= StorageRows;
			if ((bptr = psu_get_next( bptr )) == (BPTR) 0)
				return;
			}
		psu_commit_zone( bptr, TargetCol, TargetRow, atcol, atrow, nbcol, nbrow );
		}
	return;
}

PUBLIC	VOID		refresh_pixel_storage( psptr )
	STDPSUPTR	psptr;
{
	BPTR	current;
	WORD	atcol;
	WORD	atrow;
	WORD	nbcol;
	WORD	nbrow;
	
	if (( psptr != (STDPSUPTR) 0)
	&&  ((current = psptr->root) != (BPTR) 0)) {
#ifdef	_MF_TWIN24_
		atcol = psu_get_atcol( current );
		atrow = psu_get_atrow( current );
#endif
		do	{
#ifdef	_MF_TWIN24_
#else	/* ! _MF_TWIN24_ */
			atcol = psu_get_atcol( current );
			atrow = psu_get_atrow( current );
#endif
			nbcol = psu_get_nbcol( current );
			nbrow = psu_get_nbrow( current );
		        putzone(atcol,atrow,nbcol,nbrow,(current + _PSU_STORAGE));
#ifdef	_MF_TWIN24_
			atrow += nbrow;
#endif
			}
		while ((current = psu_get_next( current )) != (BPTR) 0);
		}
	return;

}

PUBLIC	VOID		commit_pixel_storage( psptr, atcol, atrow )
	STDPSUPTR	psptr;
	WORD		atcol;
	WORD		atrow;
{
	BPTR	current;
	WORD	nbcol;
	WORD	nbrow;
	
	if (( psptr != (STDPSUPTR) 0)
	&&  ((current = psptr->root) != (BPTR) 0)) {
		do	{
			nbcol = psu_get_nbcol( current );
			nbrow = psu_get_nbrow( current );
		        putzone(atcol,atrow,nbcol,nbrow,(current + _PSU_STORAGE));
			atrow += nbrow;
			}
		while ((current = psu_get_next( current )) != (BPTR) 0);
		}
	return;

}

PUBLIC	VOID		mixin_pixel_storage( psptr )
	STDPSUPTR	psptr;
{
	BPTR	current;
	WORD	atcol;
	WORD	atrow;
	WORD	nbcol;
	WORD	nbrow;
	
	if (( psptr != (STDPSUPTR) 0)
	&&  ((current = psptr->root) != (BPTR) 0)) {
		do	{
			atcol = psu_get_atcol( current );
			atrow = psu_get_atrow( current );
			nbcol = psu_get_nbcol( current );
			nbrow = psu_get_nbrow( current );
		        mixzone(atcol,atrow,nbcol,nbrow,(current + _PSU_STORAGE));
			}
		while ((current = psu_get_next( current )) != (BPTR) 0);
		}
	return;

}

PUBLIC	VOID		capture_pixel_storage( psptr )
	STDPSUPTR	psptr;
{
	BPTR	current;
	WORD	atcol;
	WORD	atrow;
	WORD	nbcol;
	WORD	nbrow;
	
	if (( psptr != (STDPSUPTR) 0)
	&&  ((current = psptr->root) != (BPTR) 0)) {
#ifdef	_MF_TWIN24_
		atcol = psu_get_atcol( current );
		atrow = psu_get_atrow( current );
#endif
		do	{
#ifdef	_MF_TWIN24_
#else	/* ! _MF_TWIN24_ */
			atcol = psu_get_atcol( current );
			atrow = psu_get_atrow( current );
#endif
			nbcol = psu_get_nbcol( current );
			nbrow = psu_get_nbrow( current );
		        getzone(atcol,atrow,nbcol,nbrow,(current + _PSU_STORAGE));
#ifdef	_MF_TWIN24_
			atrow += nbrow;
#endif
			}
		while ((current = psu_get_next( current )) != (BPTR) 0);
		}
	return;

}

PUBLIC	WORD		PsuStorageWidth( psptr )
	STDPSUPTR	psptr;
{
	return( StorageWidth );
}

PUBLIC	WORD		PsuStorageHeight( psptr )
	STDPSUPTR	psptr;
{
	return( StorageHeight );
}

PUBLIC	VOID	store_pixel_value( psptr, atcol, atrow, value )
	STDPSUPTR	psptr;
	WORD		atcol;
	WORD		atrow;
	WORD		value;
{
	BPTR		bptr;
	WORD		SeekBase;
	if (!( psptr ))
		return;
	if (((bptr = psptr->current) != (BPTR) 0)
	&&  ( psptr->seeksize != 0 )
	&&  ( atrow >= psptr->seekbase )
	&&  ( atrow < (psptr->seekbase + psptr->seeksize)))
		psu_put_pixel( bptr, atcol, (atrow - psptr->seekbase), value );
	else if ((bptr = psptr->root) != (BPTR) 0) {
		SeekBase = 0;
		while ( atrow >= StorageRows ) {
			atrow -= StorageRows;
			SeekBase += StorageRows; 
			if ((bptr = psu_get_next( bptr )) == (BPTR) 0)
				return;
			}
		psptr->current = bptr;
		psptr->seekbase = SeekBase;
		psptr->seeksize = StorageRows;
		psu_put_pixel( bptr, atcol, atrow, value );
		}
	return;
}

PUBLIC	WORD		collect_pixel_row( psptr, atcol, atrow, nbcol, buffer )
	STDPSUPTR	psptr;
	WORD		atcol;
	WORD		atrow;
	WORD		nbcol;
	BPTR		buffer;
{
	BPTR		bptr;
	WORD		SeekBase;
	if (!( psptr ))
		return(0);
	if (((bptr = psptr->current) != (BPTR) 0)
	&&  ( psptr->seeksize != 0 )
	&&  ( atrow >= psptr->seekbase )
	&&  ( atrow < (psptr->seekbase + psptr->seeksize)))
		psu_get_pixels( bptr, atcol, (atrow - psptr->seekbase), nbcol, buffer, StoragePixel );
	else if ((bptr = psptr->root) != (BPTR) 0) {
		SeekBase = 0;
		while ( atrow >= StorageRows ) {
			atrow -= StorageRows;
			SeekBase += StorageRows; 
			if ((bptr = psu_get_next( bptr )) == (BPTR) 0)
				return(0);
			}
		psptr->current = bptr;
		psptr->seekbase = SeekBase;
		psptr->seeksize = StorageRows;
		psu_get_pixels( bptr, atcol, atrow, nbcol, buffer, StoragePixel );
		}
	return(0);
}

PUBLIC	BPTR		connect_pixel_row( psptr, atrow )
	STDPSUPTR	psptr;
	WORD		atrow;
{
	BPTR		bptr;
	WORD		SeekBase;
	if (!( psptr ))
		return((BPTR) 0);
	if (((bptr = psptr->current) != (BPTR) 0)
	&&  ( psptr->seeksize != 0 )
	&&  ( atrow >= psptr->seekbase )
	&&  ( atrow < (psptr->seekbase + psptr->seeksize)))
		return( psu_get_buffer(bptr, (atrow - psptr->seekbase), StoragePixel ));
	else if ((bptr = psptr->root) != (BPTR) 0) {
		SeekBase = 0;
		while ( atrow >= StorageRows ) {
			atrow -= StorageRows;
			SeekBase += StorageRows; 
			if ((bptr = psu_get_next( bptr )) == (BPTR) 0)
				return((BPTR) 0);
			}
		psptr->current = bptr;
		psptr->seekbase = SeekBase;
		psptr->seeksize = StorageRows;
		return( psu_get_buffer( bptr, atrow, StoragePixel ) );
		}
	return((BPTR) 0);
}

PUBLIC	VOID	reset_pixel_row( psptr, atrow, atcol, nbcol, pixel )
	STDPSUPTR	psptr;
	WORD	atrow;
	WORD	atcol;
	WORD	nbcol;
	WORD	pixel;
{
	BPTR		bptr;
	WORD		SeekBase;
	if (!( psptr ))
		return;
	if (((bptr = psptr->current) != (BPTR) 0)
	&&  ( psptr->seeksize != 0 )
	&&  ( atrow >= psptr->seekbase )
	&&  ( atrow < (psptr->seekbase + psptr->seeksize)))
		psu_put_pixels( bptr, atcol, (atrow - psptr->seekbase), nbcol, pixel, StoragePixel );
	else if ((bptr = psptr->root) != (BPTR) 0) {
		SeekBase = 0;
		while ( atrow >= StorageRows ) {
			atrow -= StorageRows;
			SeekBase += StorageRows; 
			if ((bptr = psu_get_next( bptr )) == (BPTR) 0)
				return;
			}
		psptr->current = bptr;
		psptr->seekbase = SeekBase;
		psptr->seeksize = StorageRows;
		psu_put_pixels( bptr, atcol, atrow, nbcol, pixel, StoragePixel );
		}
	return;
}

#undef	StorageWidth	
#undef	StorageHeight
#undef	StorageItems	
#undef	StorageRows  
#undef	StorageAtCol	
#undef	StorageAtRow	

	/* ------------ */
#endif	/* _STDPSU_C	*/
	/* ------------ */


