/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,2010 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXMMAPTC.C  				*/
/*		Date 	:	28/11/2010				*/
/*		Version :	3.3b       				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXMMAPTC_C
#define	_EXMMAPTC_C
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

#define	O_RDONLY 0

struct	tcode_file_handle {
	size_t		length;
	int		nature;
	int		handle;
	void * 		buffer;
	int		options;
	};	

EX_FILE_HANDLE OpenMmapFile( BPTR filename )
{
	struct	stat	mystats;
	struct	tcode_file_handle * handle = (struct tcode_file_handle *) EX_UNUSED_HANDLE;

	/* --------------------------------------------- */
	/* attempt to handle a memory map section handle */
	/* --------------------------------------------- */
	if (!( handle = allocate( sizeof( struct tcode_file_handle ) ) ))
	{
		handle = EX_UNUSED_HANDLE;
		err_val = errno  = 27;
		return((EX_FILE_HANDLE) handle);
	}

	/* ------------------------------------ */
	/* reset the handle structure to unused */
	/* ------------------------------------ */
	handle->handle = -1;
	handle->buffer = (void *) 0;
	handle->nature = 0;
	handle->options= 0;
	handle->length = (size_t) 0;

	/* ------------------------ */
	/* attempt to open the file */ 
	/* ------------------------ */
	if ((handle->handle = open( filename, O_RDONLY )) < 0)
	{
		liberate( handle );
		handle = EX_UNUSED_HANDLE;
		err_val = errno  = 40;
		return((EX_FILE_HANDLE) handle);
	}
	/* ------------------------ */
	/* attempt to stat the file */ 
	/* ------------------------ */
	if ( fstat( handle->handle, &mystats ) < 0 )
	{
		close( handle->handle );
		liberate( handle );
		handle = EX_UNUSED_HANDLE;
		err_val = errno  = 56;
		return((EX_FILE_HANDLE) handle);
	}
	else 	handle->length = mystats.st_size;

	/* ------------------------ */
	/* attempt to mmap the file */ 
	/* ------------------------ */
	if (!( handle->buffer = mmap(
			(void*) 0, 			/* no specific address	*/
			handle->length, 		/* length of file	*/
			PROT_READ,			/* read only section	*/
			MAP_SHARED,			/* shared with all 	*/
			handle->handle,			/* open file handle	*/
			(off_t) 0 ) ))			/* offset from start	*/
	{
		close( handle->handle );
		liberate( handle );
		handle = EX_UNUSED_HANDLE;
		err_val = errno  = 58;
		return((EX_FILE_HANDLE) handle);
	}
	/* ---------- */
	/* ok success */
	/* ---------- */
	else	
	{
		return((EX_FILE_HANDLE) handle);
	}
}

BPTR	ReadMmapFile( EX_FILE_HANDLE h, EXAWORD secteur, EXAWORD longeur )
{
	struct	tcode_file_handle * handle = (struct tcode_file_handle *) EX_UNUSED_HANDLE;
	if ( h == EX_UNUSED_HANDLE )
		return( (BPTR) 0 );
	else if (!(handle = (struct tcode_file_handle *) h))
		return( (BPTR) 0 );
	else if (!( handle->buffer ))
		return( (BPTR) 0 );
	else 	return(( handle->buffer + (secteur * 256) ));
}


	/* ----------- */
#endif	/* _EXMMAPTC_C */
	/* ----------- */

