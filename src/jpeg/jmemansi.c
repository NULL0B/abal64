#ifdef	PROLOGUE

#define	USE_ALSM_LBSM

/* ------------------------------------------------------------ */
/* This may be activated to allow all ALSM LBSM tracing to file */
/* #define	TRACE_ALSM_LBSM 				*/
/* ------------------------------------------------------------ */

#ifdef		TRACE_ALSM_LBSM
#undef		TRACE_ALSM_LBSM
#endif

#endif	

/*
 * jmemansi.c
 *
 * Copyright (C) 1992-1994, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file provides a simple generic implementation of the system-
 * dependent portion of the JPEG memory manager.  This implementation
 * assumes that you have the ANSI-standard library routine tmpfile().
 * Also, the problem of determining the amount of memory available
 * is shoved onto the user.
 */

#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
#include "jmemsys.h"		/* import the system-dependent declarations */

#ifndef HAVE_STDLIB_H		/* <stdlib.h> should declare malloc(),free() */
extern void * malloc JPP((size_t size));
extern void free JPP((void *ptr));
#endif

#ifndef SEEK_SET		/* pre-ANSI systems may not define this; */
#define SEEK_SET  0		/* if not, assume 0 is correct */
#endif



#ifdef	USE_ALSM_LBSM

#include "catcher.h"

#ifdef	TRACE_ALSM_LBSM
FILE	*	prl_thandle=(FILE *) 0;
void	prl_topen()
{
	if (!( prl_thandle ))
		prl_thandle = fopen( "jpeg.trc", "w" );
	return;
}

void	prl_twrite(char * sptr)
{
	if ( prl_thandle )
		fprintf(prl_thandle,"%s\n",sptr);
	return;
}

void	prl_tclose()
{
	if ( prl_thandle )  {
		fclose( prl_thandle );
		prl_thandle = (FILE *) 0;
		}
	return;
}
#endif

void	*	pralloc( int );
void		pree( void * );
void	*	pralsm( int nombre )
{
	void	* vptr;
#ifdef	TRACE_ALSM_LBSM
	int	vcs;
	int	vip;
	_asm	{
		mov	ax,word ptr [bp][+4]
		mov	vcs,ax
		mov	ax,word ptr [bp][+2]
		mov	vip,ax
		};
#endif
	if ((vptr = pralloc(nombre)) == (char *) 0) {
#ifdef	TRACE_ALSM_LBSM
		if ( prl_thandle )  {
			fprintf( prl_thandle, "pralloc::exception(27)\n" );
			prl_tclose();
			}
#endif
		throw_exception( 27 );
		}

#ifdef	TRACE_ALSM_LBSM
	if ( prl_thandle ) 
		fprintf( prl_thandle, "%lu = pralsm(%u) from %04.1X:%04.1X \n",vptr,nombre,vcs,vip );
#endif
	return( vptr );
}

void		prlbsm( void * vptr)
{
#ifdef	TRACE_ALSM_LBSM
	if ( prl_thandle ) 
		fprintf( prl_thandle, "prlbsm(%lu)\n",vptr);
#endif
	pree( vptr );
}

#endif


/*
 * Memory allocation and freeing are controlled by the regular library
 * routines malloc() and free().
 */

GLOBAL void *
jpeg_get_small (j_common_ptr cinfo, size_t sizeofobject)
{
#ifdef	USE_ALSM_LBSM
#ifdef	TRACE_ALSM_LBSM
	if ( prl_thandle ) 
		fprintf( prl_thandle, "getsmall(%u)\n",sizeofobject);
#endif
	return( pralsm( sizeofobject ) );
#else
	return( (void *) malloc(sizeofobject));
#endif
}

GLOBAL void
jpeg_free_small (j_common_ptr cinfo, void * object, size_t sizeofobject)
{
#ifdef	USE_ALSM_LBSM
#ifdef	TRACE_ALSM_LBSM
	if ( prl_thandle ) 
		fprintf( prl_thandle, "freesmall(%lu)\n",object);
#endif
	prlbsm( object );
#else
  	free(object);
#endif
}

/*
 * "Large" objects are treated the same as "small" ones.
 * NB: although we include FAR keywords in the routine declarations,
 * this file won't actually work in 80x86 small/medium model; at least,
 * you probably won't be able to process useful-size images in only 64KB.
 */

GLOBAL void FAR *
jpeg_get_large (j_common_ptr cinfo, size_t sizeofobject)
{
#ifdef	USE_ALSM_LBSM
#ifdef	TRACE_ALSM_LBSM
	if ( prl_thandle ) 
		fprintf( prl_thandle, "getlarge(%u)\n",sizeofobject);
#endif
	return( (void FAR *) pralsm( sizeofobject ) );
#else
	return( (void FAR *) malloc(sizeofobject) );
#endif
}

GLOBAL void
jpeg_free_large (j_common_ptr cinfo, void FAR * object, size_t sizeofobject)
{
#ifdef	USE_ALSM_LBSM
#ifdef	TRACE_ALSM_LBSM
	if ( prl_thandle ) 
		fprintf( prl_thandle, "freelarge(%lu)\n",object);
#endif
	prlbsm( object );
#else
	free(object);
#endif
}


/*
 * This routine computes the total memory space available for allocation.
 * It's impossible to do this in a portable way; our current solution is
 * to make the user tell us (with a default value set at compile time).
 * If you can actually get the available space, it's a good idea to subtract
 * a slop factor of 5% or so.
 */

#ifndef DEFAULT_MAX_MEM		/* so can override from makefile */
#define DEFAULT_MAX_MEM		2000000L /* default: one megabyte */
static	long	DefaultMaxMem=DEFAULT_MAX_MEM;
#endif

/*
 * This may be called when required in order to increase the
 * memory check limit 
 *
 */

GLOBAL void	jinit_max_to_use( long max_to_use )
{
	DefaultMaxMem = (max_to_use * 1000L);
	return;
}

GLOBAL long
jpeg_mem_available (j_common_ptr cinfo, long min_bytes_needed,
		    long max_bytes_needed, long already_allocated)
{
  return cinfo->mem->max_memory_to_use - already_allocated;
}


/*
 * Backing store (temporary file) management.
 * Backing store objects are only used when the value returned by
 * jpeg_mem_available is less than the total space needed.  You can dispense
 * with these routines if you have plenty of virtual memory; see jmemnobs.c.
 */


METHODDEF void
read_backing_store (j_common_ptr cinfo, backing_store_ptr info,
		    void FAR * buffer_address,
		    long file_offset, long byte_count)
{
  if (fseek(info->temp_file, file_offset, SEEK_SET)) {
    ERREXIT(cinfo, JERR_TFILE_SEEK);
	}
  if (JFREAD(info->temp_file, buffer_address, byte_count)
      != (size_t) byte_count)
    ERREXIT(cinfo, JERR_TFILE_READ);
}


METHODDEF void
write_backing_store (j_common_ptr cinfo, backing_store_ptr info,
		     void FAR * buffer_address,
		     long file_offset, long byte_count)
{
  if (fseek(info->temp_file, file_offset, SEEK_SET)) {
    ERREXIT(cinfo, JERR_TFILE_SEEK);
	}
  if (JFWRITE(info->temp_file, buffer_address, byte_count)
      != (size_t) byte_count)
    ERREXIT(cinfo, JERR_TFILE_WRITE);
}


METHODDEF void
close_backing_store (j_common_ptr cinfo, backing_store_ptr info)
{
  fclose(info->temp_file);
  /* Since this implementation uses tmpfile() to create the file,
   * no explicit file deletion is needed.
   */
}


/*
 * Initial opening of a backing-store object.
 *
 * This version uses tmpfile(), which constructs a suitable file name
 * behind the scenes.  We don't have to use info->temp_name[] at all;
 * indeed, we can't even find out the actual name of the temp file.
 */

GLOBAL void
jpeg_open_backing_store (j_common_ptr cinfo, backing_store_ptr info,
			 long total_bytes_needed)
{
  if ((info->temp_file = fopen("tmpfile","w")) == NULL)
    ERREXITS(cinfo, JERR_TFILE_CREATE, "");
  info->read_backing_store = read_backing_store;
  info->write_backing_store = write_backing_store;
  info->close_backing_store = close_backing_store;
}


/*
 * These routines take care of any system-dependent initialization and
 * cleanup required.
 */

GLOBAL long
jpeg_mem_init (j_common_ptr cinfo)
{
  return(DefaultMaxMem);	/* default for max_memory_to_use */
}

GLOBAL void
jpeg_mem_term (j_common_ptr cinfo)
{
  /* no work */
	return;
}



