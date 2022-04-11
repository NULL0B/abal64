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
#include "stdmem.h"


PUBLIC	VOID	psu_put_next ( root, linkage  )
	BPTR	root;
	BPTR	linkage;
{
	if ( linkage == (BPTR) 0) 
		memset( root, 0, 5 );
	else	{
		*(root++) = _PSU_VALIDPTR;
		*((BPTR PTR) root) = linkage;
		}
	return;
}

PUBLIC	VOID	psu_put_atcol( root, value )
	BPTR	root;
	WORD	value;
{
	root += _PSU_AT_COLUMN;
	*((WPTR) root) = value;
	return;
}

PUBLIC	VOID	psu_put_atrow( root, value )
	BPTR	root;
	WORD	value;
{
	root += 	_PSU_AT_ROW;
	*((WPTR) root) = value;

	return;
}

PUBLIC	VOID	psu_put_nbcol( root, value )
	BPTR	root;
	WORD	value;
{
	root += 	_PSU_COLUMNS;
	*((WPTR) root) = value;
	return;
}

PUBLIC	VOID	psu_put_nbrow( root, value )
	BPTR	root;
	WORD	value;
{
	root += 	_PSU_ROWS;
	*((WPTR) root) = value;
	return;
}

PUBLIC	BPTR	psu_get_next ( root )
	BPTR	root;
{
	if ( *(root++) != _PSU_VALIDPTR )
		return((BPTR) 0 );
	else 	return( *((BPTR PTR) root) );
}

PUBLIC	WORD	psu_get_atcol( root )
	BPTR	root;
{
	root += _PSU_AT_COLUMN;
	return( *((WPTR) root)  );
}

PUBLIC	WORD	psu_get_atrow( root )
	BPTR	root;
{
	root += 	_PSU_AT_ROW;
	return( *((WPTR) root)  );
}

PUBLIC	WORD	psu_get_nbcol( root )
	BPTR	root;
{
	root += 	_PSU_COLUMNS;
	return( *((WPTR) root)  );
}

PUBLIC	WORD	psu_get_nbrow( root )
	BPTR	root;
{
	root += 	_PSU_ROWS;
	return( *((WPTR) root)  );
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
		*( root + (((atrow * nbcol) + atcol) + _PSU_STORAGE)) = (BYTE) value;
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
			*(root++) = value;
		}
	return;
}

PUBLIC	VOID	psu_get_pixels( root, atcol, atrow, nbcol, buffer )
	BPTR	root;
	WORD	atcol;
	WORD	atrow;
	WORD	nbcol;
	BPTR	buffer;
{
	WORD	colmax;
	if ( root != (BPTR) 0 ) {
		colmax = psu_get_nbcol( root );
		root += (((atrow * colmax) + atcol) + _PSU_STORAGE);
		for (; nbcol != 0; nbcol-- )
			*(buffer++) = *(root++);
		}
	return;
}

PUBLIC	BPTR	psu_get_buffer( root, atrow )
	BPTR	root;
	WORD	atrow;
{
	WORD	colmax;
	if ( root != (BPTR) 0 ) {
		colmax = psu_get_nbcol( root );
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

		while ((current = psptr->root) != (BPTR) 0) {
			psptr->root = psu_get_next( current );
			current = liberate( current );
			}

		psptr = liberate( psptr );
		}
	return( psptr );
}		

PUBLIC	BPTR	allocate_for_psu(itemsize,atcol,atrow,nbcol,nbrow)
	WORD	itemsize;
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

PUBLIC	STDPSUPTR	allocate_pixel_storage( psptr )
	STDPSUPTR	psptr;
{
	BPTR		previous=(BPTR) 0;
	BPTR		current=(BPTR) 0;
        WORD		item;
	WORD		rows;
	WORD		itemsize;
	WORD		totalrows;
	WORD		currentrow;

        for ( totalrows=StorageHeight,currentrow=StorageAtRow,item=0;
	      item < StorageItems; item++ ) {
                if ( totalrows < StorageRows )
       	                rows = totalrows;
       	        else	rows = StorageRows;
                itemsize = ((StorageWidth * rows) + _PSU_STORAGE );

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
	WORD		status;

	/* -------------------------------- */
	/* Allocate Pixel Storage Controler */
	/* -------------------------------- */
	if ((psptr = allocate_for_pixels()) != (STDPSUPTR) 0) {

		StorageWidth  = grnbcol;
		StorageHeight = grnbrow;
		StorageAtCol  = gratcol;
		StorageAtRow  = gratrow;

		/* ---------------------------------- */
		/* Calculate Pixel Buffers Descriptor */
		/* ---------------------------------- */
		status = calcbuff( (WPTR) (& StorageWidth) );

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
	WORD		status;

	/* -------------------------------- */
	/* Allocate Pixel Storage Controler */
	/* -------------------------------- */
	if ((psptr = allocate_for_pixels()) != (STDPSUPTR) 0) {

		/* ---------------------------------- */
		/* Calculate Pixel Storage Descriptor */
		/* ---------------------------------- */
		status = calczone( atcol, atlin, nbcol, nblin,(WPTR) (& StorageWidth) );

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

PUBLIC	VOID		background_pixel_capture( psptr )
	STDPSUPTR	psptr;
{
	userware(StorageWidth,StorageHeight,psptr->root);
	return;
}

PUBLIC	VOID		foreground_pixel_capture( psptr )
	STDPSUPTR	psptr;
{
	shareware(StorageWidth,StorageHeight,StorageAtCol,StorageAtRow,psptr->root);
	return;
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
	BPTR	storage;
	
	if (( psptr != (STDPSUPTR) 0)
	&&  ((current = psptr->root) != (BPTR) 0)) {
		do	{
			atcol = psu_get_atcol( current );
			atrow = psu_get_atrow( current );
			nbcol = psu_get_nbcol( current );
			nbrow = psu_get_nbrow( current );
		        putzone(atcol,atrow,nbcol,nbrow,(current + _PSU_STORAGE));
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
	BPTR	storage;
	
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
	BPTR	storage;
	
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
	BPTR	storage;
	
	if (( psptr != (STDPSUPTR) 0)
	&&  ((current = psptr->root) != (BPTR) 0)) {
		do	{
			atcol = psu_get_atcol( current );
			atrow = psu_get_atrow( current );
			nbcol = psu_get_nbcol( current );
			nbrow = psu_get_nbrow( current );
		        getzone(atcol,atrow,nbcol,nbrow,(current + _PSU_STORAGE));
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
	if (((bptr = psptr->current) != (BPTR) 0)
	&&  ( psptr->seeksize != 0 )
	&&  ( atrow >= psptr->seekbase )
	&&  ( atrow < (psptr->seekbase + psptr->seeksize)))
		psu_get_pixels( bptr, atcol, (atrow - psptr->seekbase), nbcol, buffer );
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
		psu_get_pixels( bptr, atcol, atrow, nbcol, buffer );
		}
	return(0);
}

PUBLIC	BPTR		connect_pixel_row( psptr, atrow )
	STDPSUPTR	psptr;
	WORD		atrow;
{
	BPTR		bptr;
	WORD		SeekBase;
	if (((bptr = psptr->current) != (BPTR) 0)
	&&  ( psptr->seeksize != 0 )
	&&  ( atrow >= psptr->seekbase )
	&&  ( atrow < (psptr->seekbase + psptr->seeksize)))
		return( psu_get_buffer(bptr, (atrow - psptr->seekbase) ));
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
		return( psu_get_buffer( bptr, atrow ) );
		}
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
	if (((bptr = psptr->current) != (BPTR) 0)
	&&  ( psptr->seeksize != 0 )
	&&  ( atrow >= psptr->seekbase )
	&&  ( atrow < (psptr->seekbase + psptr->seeksize)))
		psu_put_pixels( bptr, atcol, (atrow - psptr->seekbase), nbcol, pixel );
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
		psu_put_pixels( bptr, atcol, atrow, nbcol, pixel );
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


