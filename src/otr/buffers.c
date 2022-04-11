/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1992 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	BUFFERS.C				*/
/*		Version :	1.1a					*/
/*		Date	:	13/10/1992				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_BUFFERS_C
#define _BUFFERS_C
#ifndef	ABAL_EXA
#ifndef VERBALISE
#define VERBALISE
#endif
#endif
#include <stdio.h>		/* Standard IO handling routines	*/
#include <fcntl.h>		/* File open mask definitions		*/
#include <errno.h>		/* Error return definitions		*/
#include <string.h>		/* Error return definitions		*/
#include "aplus.h"		/* Include standard definitions		*/
#include "memory.h"
#include "struct.h"
#include "trapping.h"
#include "abal.h"
#include "allocate.h"
#include "options.h"
#include "buffers.h"

static	WORD	GarbageReady=0;
static	WORD	MessageReady=0;

#ifndef	SEEK_SET
#define	SEEK_SET 0
#endif
#ifndef	O_BINARY
#define	O_BINARY 0
#endif

#ifdef	ABAL_EXA
#ifndef	ABAL_OTR
extern	WORD	simcbd;
#endif
#endif

#define	OPTIMISED_SWAP

#include "fileseek.c"

VPTR		zalloc( WORD );

static	WORD	local_garbage()
{
	return( 0 );
}

static	WORD	local_message()
{
	return( 0 );
}

VOID	set_swap_garbage( gptr )
	WORD		(*gptr)();
{
	if (!(BufferControl.garbage = gptr ))
		BufferControl.garbage	= local_garbage;
	return;
}		

VOID	set_swap_message( mptr )
	WORD		(*mptr)();
{
	if (!(BufferControl.message = mptr ))
		BufferControl.message	= local_message;
	return;
}		


WORD	initialise_buffer_control( filename, buffer_size, max_buffers, min_buffers )
BPTR	filename;
WORD	buffer_size;
WORD	max_buffers;
WORD	min_buffers;
{
#ifndef	ABAL_EXA
	if ((BufferControl.swapname  = (BPTR) allocate_for_string( filename )) == (BPTR) 0)
		return( -1 );
#else
	BufferControl.swapname  = (BPTR) filename;
#endif
	BufferControl.garbage	= local_garbage;
	BufferControl.message	= local_message;
	GarbageReady = 1;
	MessageReady = 1;
	BufferControl.oldest   	= (BCNODEPTR) 0;
	BufferControl.newest   	= (BCNODEPTR) 0;
	BufferControl.usage    	= 0;
	BufferControl.swaphandle= -1;
	BufferControl.swapnode  = 0L;
	BufferControl.handles   = 0;
	BufferControl.maxhandles= 0;
	BufferControl.maxswapnode = 0;
	BufferControl.options   = _AUTO_SWAP_OUT;
#ifndef	SLOW_SPEED
	BufferControl.HandleHeap  = (BUFFERHANDLE) 0;
#endif
#ifdef	PROLOGUE_LIB_SEEK_BUG
	BufferControl.textsize 	= 256;
#else
	BufferControl.textsize 	= buffer_size;
#endif
	BufferControl.limit     = max_buffers;	
	BufferControl.lowlimit	= min_buffers;

	return(0);

}

void	set_maximum_swap_buffers( nb_buffers )
WORD	nb_buffers;
{
	BufferControl.limit = nb_buffers;
	return;
}

void	liberate_buffer_controller()
{
	BCNODEPTR	bcnode;
	BUFFERHANDLE	handle;
	WORD		bugger;
#ifndef	ABAL_EXA
#ifdef	VERBALISE
	if ( Options.Verbose & 16 ) {
		sysprintf("swap buffers  : %d\n",BufferControl.usage);
		sysprintf("swap nodes    : %d\n",BufferControl.maxswapnode);
		sysprintf("user handles  : %d\n",BufferControl.maxhandles );
		}
#endif
#endif
	while (((bcnode = BufferControl.oldest) != (BCNODEPTR) 0 ) && ( BufferControl.usage != 0)) {
		BufferControl.oldest = bcnode->next;
		free( bcnode );
		BufferControl.usage--;
		}

	if ( BufferControl.swaphandle != -1 ) {
		close(BufferControl.swaphandle);
		unlink(BufferControl.swapname);
		}

#ifndef	ABAL_EXA
	free( BufferControl.swapname );
#endif
	BufferControl.swapname = (BPTR) 0;

#ifndef	SLOW_SPEED
	while (( handle = BufferControl.HandleHeap ) != (BUFFERHANDLE) 0) {
		BufferControl.HandleHeap = (BUFFERHANDLE) BufferControl.HandleHeap->bcnode;
		free( handle );
		}
#endif
	return; 	

}

long	get_next_swap_node()
{
	long	adresse;

#ifdef	OPTIMISED_SWAP
	long	tempadr;

	/* Seek to Current Next swap node */
	/* ------------------------------ */
	if ((adresse = lseek(BufferControl.swaphandle,BufferControl.swapnode,SEEK_SET)) != -1L) {

#ifdef	ABAL_EXA
#ifndef	ABAL_OTR
		simcbd = 0x2060;
#endif
#endif
		/* Collect Swap node linkage value from the file */
		/* --------------------------------------------- */
		if (read(BufferControl.swaphandle,(BPTR) &tempadr, sizeof( long )) != sizeof( long )) {
#ifdef	ABAL_EXA
			/* FIX for PROLOGUE ABAL EXA */
			return( adresse );
#else
			/* Error Swap node linkage not found */
			/* --------------------------------- */
			return( -1L );
#endif
			}
		else	{

			/* Check for Terminal Swap Node */
			/* ---------------------------- */
			if ( tempadr != -1L ) {

				BufferControl.swapnode = tempadr;
				}
			else	{
				/* Adjust for terminal node */
				/* ------------------------ */
				BufferControl.swapnode += BufferControl.textsize;

				/* Seek to new terminal node */
				/* ------------------------- */
				if (lseek(BufferControl.swaphandle,BufferControl.swapnode,SEEK_SET) == -1L)
					return( -1L );
#ifdef	ABAL_EXA
#ifndef	ABAL_OTR
				simcbd = 0x20A0;
#endif
#endif

				/* Establish terminal node marker */
				/* ------------------------------ */
				if ( write(BufferControl.swaphandle,(BPTR) &tempadr,sizeof( long )) != sizeof( long ))
					return( 0 );

				BufferControl.maxswapnode++;
				}
			}
		}
#else
	adresse = BufferControl.swapnode;
	BufferControl.swapnode += BufferControl.textsize;
#endif
	return( adresse );
}

WORD	free_swap_node( adresse )
long	adresse;
{
#ifdef	OPTIMISED_SWAP
	if ( lseek(BufferControl.swaphandle,adresse,SEEK_SET) == -1L ) 
		return( 0 );
#ifdef	ABAL_EXA
#ifndef	ABAL_OTR
		simcbd = 0x20A0;
#endif
#endif
	if ( write(BufferControl.swaphandle,(BPTR) & BufferControl.swapnode, sizeof( long )) != sizeof( long ))
		return( 0 );
	BufferControl.swapnode = adresse;
#endif
	return(1);

}

void	reset_node_usage( bcnode )
BCNODEPTR	bcnode;
{
	if ( bcnode != (BCNODEPTR) 0 ) {
		bcnode->user     = (BUFFERHANDLE) 0;
		memset((BPTR) bcnode->text , 0 , BufferControl.textsize );
		}
	return;

}

BCNODEPTR	allocate_buffer_control_node()
{
	BCNODEPTR	bcnode;

	if ((bcnode = (BCNODEPTR) zalloc( (sizeof( struct buffer_control_node ) + (BufferControl.textsize-1)) )) != (BCNODEPTR) 0) {
		bcnode->next     = (BCNODEPTR) 0;
		bcnode->previous = (BCNODEPTR) 0;
		reset_node_usage( bcnode );
		}
	return( bcnode );

}

WORD	swap_buffer_text_out( bcnode )
BCNODEPTR	bcnode;
{
	long	swap_adresse;
	WORD	result;

	/* Check for file exists */
	/* --------------------- */
	if ( BufferControl.swaphandle == -1 ) {
#ifndef	ABAL_EXA
#ifdef	VERBALISE
		if ( Options.Verbose & 16 ) {
			sysprintf("swap buffers  : %d\n",BufferControl.usage);
			sysprintf("swap file     : %s\n",BufferControl.swapname );
			}
		if ( Options.Pannel ) 
			draw_buffer_count( BufferControl.usage );

		if (( BufferControl.swaphandle = open( BufferControl.swapname,(O_RDWR | O_TRUNC | O_CREAT | O_BINARY),0666)) == -1)
			return( 0 );
#endif
#else	/* ABAL_EXA */
#ifdef	ABAL_OTR
		if (( BufferControl.swaphandle = open( BufferControl.swapname,(O_RDWR | O_TRUNC | O_CREAT | O_BINARY),0666)) == -1)
			return( 0 );
#else
		if (( BufferControl.swaphandle = open( (BPTR) BufferControl.swapname, 2, 0)) != MOINS_UN ) {
			close(  BufferControl.swaphandle  );
			unlink( BufferControl.swapname );
			}
		if (( BufferControl.swaphandle = creat( (BPTR) BufferControl.swapname, 2)) == MOINS_UN ) {
			return( 0 );
			}
#endif
		if ( MessageReady )
		(void) BufferControl.message(0);
#endif

		if ( lseek(BufferControl.swaphandle, 0L, SEEK_SET) == -1L ) {
			return( 0 );
			}

		BufferControl.swapnode = -1L;
#ifdef	ABAL_EXA
#ifndef	ABAL_OTR
		simcbd = 0x20A0;
#endif
#endif
		if ( write(BufferControl.swaphandle,(BPTR) &BufferControl.swapnode,sizeof( long )) != sizeof( long )) {
			if ( MessageReady )
			(void) BufferControl.message(1);
			return( 0 );
			}
		BufferControl.swapnode = 0L;
		BufferControl.maxswapnode = 1;
		}

	/* Get file offset for SWAP OUT */
	/* ---------------------------- */
	if ((swap_adresse = get_next_swap_node()) == -1L ) {
		if ( MessageReady )
		(void) BufferControl.message(2);
		return( 0 );
		}

	/* Position to file swap node */
	/* -------------------------- */
	if ( lseek(BufferControl.swaphandle, swap_adresse , SEEK_SET ) == -1L ) {
		if ( MessageReady )
		(void) BufferControl.message(3);
		return( 0 );
		}

#ifdef	ABAL_EXA
#ifndef	ABAL_OTR
		simcbd = 0x20A0;
#endif
#endif
	/* Attempt to WRITE for SWAP OUT */
	/* ----------------------------- */
	if ((result = write(BufferControl.swaphandle, (BPTR) bcnode->text,BufferControl.textsize)) == BufferControl.textsize ) {

		/* Set current users swap node identifier */
		/* -------------------------------------- */
		bcnode->user->swapnode = swap_adresse;

		/* Disconnect node from user */
		/* ------------------------- */
		bcnode->user->bcnode   = (BCNODEPTR) 0;
		bcnode->user           = (BUFFERHANDLE) 0;

		}
	else 	{
		if ( MessageReady )
			(void) BufferControl.message(4);
		if ( MessageReady )
			(void) BufferControl.message(result);
		}

	/* Return result of SWAP OUT operation */
	/* ----------------------------------- */
	return( result );
	
}

WORD	swap_buffer_text_in(handle, bcnode )
BUFFERHANDLE	handle;
BCNODEPTR	bcnode;
{
	WORD	result;
	long	adresse;

	/* Position to swapped out node */
	/* ---------------------------- */
	if (lseek(BufferControl.swaphandle,(adresse = handle->swapnode),SEEK_SET) == -1L)
		return( 0 );

#ifdef	ABAL_EXA
#ifndef	ABAL_OTR
		simcbd = 0x2060;
#endif
#endif
	/* Attempt to read in from swap zone */
	/* --------------------------------- */
	if ((result = read(BufferControl.swaphandle,(BPTR) bcnode->text,BufferControl.textsize)) == BufferControl.textsize) {

		/* liberate this swap node */
		/* ----------------------- */
		if (free_swap_node( handle->swapnode ) == 0)
			return( 0 );

		/* Validate the user handle */
		/* ------------------------ */
		handle->swapnode = SWAPPED_IN;

		/* And attach to the buffer control node */
		/* ------------------------------------- */
		handle->bcnode   = bcnode;
		bcnode->user 	 = handle;

		}

	return ( result );

}


BCNODEPTR	oldest_buffer_control_node()
{
	BCNODEPTR	bcnode;

	/* Pick up oldest buffer control node */
	/* ---------------------------------- */
	if ((bcnode = BufferControl.oldest) != (BCNODEPTR) 0 ) {
		
		/* Check for occupied and must be swapped out */
		/* ------------------------------------------ */
		if ( bcnode->user != (BUFFERHANDLE) 0) {

			/* Save current contents to SWAP file */
			/* ---------------------------------- */
			if ( swap_buffer_text_out( bcnode ) != BufferControl.textsize ) {
				if ( MessageReady )
				(void) BufferControl.message(60);
				return( (BCNODEPTR) 0 );
				}

			}

		/* If not a unique buffer */
		/* ---------------------- */
		if ( bcnode->next != (BCNODEPTR) 0 ) {

			/* Remove from old end and add to new end */
			/* -------------------------------------- */
			BufferControl.oldest    = bcnode->next;
			bcnode->next->previous  = (BCNODEPTR) 0;
			bcnode->previous  	= BufferControl.newest;
			BufferControl.newest	= bcnode;
			bcnode->previous->next  = bcnode;
			bcnode->next            = (BCNODEPTR) 0;

			}

		}

	return( bcnode );
	
}

BCNODEPTR	get_next_buffer_control_node()
{
	BCNODEPTR	bcnode;

	/* Test if buffers have been allocated */
	/* ----------------------------------- */
	if ( BufferControl.oldest != (BCNODEPTR) 0)

		/* Check for released buffer is pending */
		/* ------------------------------------ */
		if (BufferControl.oldest->user == (BUFFERHANDLE) 0)

			/* Re-Use Released buffer */
			/* ---------------------- */
			return( oldest_buffer_control_node() );		

	/* Check for buffer limit reached */
	/* ------------------------------ */
	if (BufferControl.usage >= BufferControl.limit )

		/* Return least recently used buffer */
		/* --------------------------------- */
		return( oldest_buffer_control_node() );

	/* Attempt to allocate a new buffer control node */
	/* --------------------------------------------- */
	if ((bcnode = allocate_buffer_control_node()) == (BCNODEPTR) 0) {

		/* Establish buffer limit */
		/* ---------------------- */
		BufferControl.limit = BufferControl.usage;

		/* Return least recently used buffer */
		/* --------------------------------- */
		return( oldest_buffer_control_node() );

		}


	/* Establish  previous in double linked list */
	/* ----------------------------------------- */
	if ((bcnode->previous = BufferControl.newest) != (BCNODEPTR) 0)
		bcnode->previous->next = bcnode;

	/* Establish end of chain */
	/* ---------------------- */
	bcnode->next     = (BCNODEPTR) 0;
		
	/* Identify new must recently used */
	/* ------------------------------- */
	BufferControl.newest = bcnode;	

	/* Establish root of next available if not yet set */
	/* ----------------------------------------------- */
	if ( BufferControl.oldest == (BCNODEPTR) 0)
		BufferControl.oldest = bcnode;	

	/* Adjust current buffer count */
	/* --------------------------- */
	BufferControl.usage++;

	/* Return control node */
	/* ------------------- */
	return( bcnode ) ;

}

VPTR	revalidate_buffer( handle )
BUFFERHANDLE	handle;
{
	BCNODEPTR	bcnode;

	/* Ensure valid handle pointer */
	/* --------------------------- */
	if ( handle != (BUFFERHANDLE) 0 ) {

		/* Ensure buffer handle is still active */
		/* ------------------------------------ */
		if ( handle->swapnode != SWAPPED_IN ) {

			/* Attempt to collect a buffer to satisfy request */
			/* ---------------------------------------------- */
			if ((bcnode = oldest_buffer_control_node()) == (BCNODEPTR) 0)
				return( (VPTR) 0 );

			/* Attempt to refresh the buffer from swap file */
			/* -------------------------------------------- */		
			if ( swap_buffer_text_in(handle, bcnode ) != BufferControl.textsize )
				return( (VPTR) 0 );


			}

		if ( handle->bcnode != (BCNODEPTR) 0) 

			/* Return the pointer to the text area */
			/* ----------------------------------- */
			return((VPTR) handle->bcnode->text );


		}

	return( (VPTR) 0 );
}

#ifndef	SLOW_SPEED
void	release_handle( handle )
BUFFERHANDLE	handle;
{
	handle->bcnode = (BCNODEPTR) BufferControl.HandleHeap;
	BufferControl.HandleHeap     = handle;
	return;
}

BUFFERHANDLE	allocate_for_handle()
{
	BUFFERHANDLE	handle;
	if (( handle = BufferControl.HandleHeap ) == (BUFFERHANDLE) 0)
		return( (BUFFERHANDLE) zalloc( sizeof( struct user_buffer_handle ) ));
	else	{
		BufferControl.HandleHeap = (BUFFERHANDLE) BufferControl.HandleHeap->bcnode;
		return( handle );
		}

}
 
#endif

void	release_buffer( handle )
BUFFERHANDLE	handle;
{

	if ( handle != (BUFFERHANDLE) 0 ) {

		if ( handle->swapnode != SWAPPED_IN ) 
			free_swap_node( handle->swapnode );

		if ( handle->bcnode != (BCNODEPTR) 0 ) {

			/* Check if not already the oldest */
			/* ------------------------------- */
			if ( handle->bcnode->previous != (BCNODEPTR) 0) {

				/* ------------------------------------- */
				/* Establish as OLDEST : Next to be used */	
				/* ------------------------------------- */

				/* Check if newest will be released */
				/* -------------------------------- */
				if ((handle->bcnode->previous->next = handle->bcnode->next) == (BCNODEPTR) 0)

					/* Establish NEW newest buffer node */
					/* -------------------------------- */
					BufferControl.newest = handle->bcnode->previous;

				else
					handle->bcnode->next->previous = handle->bcnode->previous;

				handle->bcnode->previous = (BCNODEPTR) 0;
				handle->bcnode->next = BufferControl.oldest;
				BufferControl.oldest->previous = handle->bcnode;
				BufferControl.oldest = handle->bcnode;

				} 
			handle->swapnode = SWAPPED_IN;
			reset_node_usage( handle->bcnode );
			handle->bcnode   = (BCNODEPTR) 0;

			}

		/* Liberate memory */
		/* --------------- */
#ifndef	SLOW_SPEED
		release_handle( handle );
#else
		free( handle );
#endif
		}

}

WORD	remove_buffer_control_node()
{

	BCNODEPTR	bcnode;

	/* Test for Low water mark reached hence Error */
	/* ------------------------------------------- */
	if ( BufferControl.usage  <= BufferControl.lowlimit ) {
		if ( MessageReady )
			(void) BufferControl.message(90);
		return( MOINS_UN );
		}

	/* Pick up oldest buffer control node */
	/* ---------------------------------- */
	if ((bcnode = BufferControl.oldest) != (BCNODEPTR) 0 ) {
		
		/* Check for occupied and must be swapped out */
		/* ------------------------------------------ */
		if ( bcnode->user != (BUFFERHANDLE) 0) 

			/* Save current contents to SWAP file */
			/* ---------------------------------- */
			if ( swap_buffer_text_out( bcnode ) != BufferControl.textsize ) {
				if ( MessageReady )
					(void) BufferControl.message(91);
				return( MOINS_UN );
				}

		/* If not a unique buffer */
		/* ---------------------- */
		if ( bcnode->next != (BCNODEPTR) 0 ) {

			/* Remove from old end and add to new end */
			/* -------------------------------------- */
			BufferControl.oldest    = bcnode->next;
			bcnode->next->previous  = (BCNODEPTR) 0;

			}

		/* Liberate the Control Node */
		/* ------------------------- */
		free( bcnode );

		/* Adjust handles book-keeping */
		/* --------------------------- */
		if ( BufferControl.handles )
			BufferControl.handles--;
		}

	/* Establish Swap Condition for Next */
	/* --------------------------------- */
	BufferControl.usage--;
	BufferControl.limit = BufferControl.usage;
	if ( MessageReady )
		(void) BufferControl.message(69);

	return( VRAI );

}

void	inhibit_auto_swap_out()
{
	BufferControl.options &= ~ _AUTO_SWAP_OUT;
	return;
}

void	restart_auto_swap_out()
{
	BufferControl.options |=  _AUTO_SWAP_OUT;
	return;
}



/*	
 *	Z A L L O C ( nb )
 *	------------------
 *	Attempts to allocate memory via MALLOC for all required allocation
 *	requests. If MALLOC fails then it attempts to liberate buffers
 *	to allow MALLOC to satisy the request
 *
 */

VPTR	zalloc( WORD nb )
{
	VPTR	lptr;
	WORD	this_time;

	this_time = 1;

	/* Attempt to allocate a buffer via MALLOC */
	/* --------------------------------------- */
	while ( 1 ) {

		if (( lptr = (VPTR) malloc( nb )) != (VPTR) 0 ) {

			/* Initialise zone requested */
			/* ------------------------- */
			memset((BPTR) lptr , 0 , nb );

			/* Return pointer to caller */
			/* ------------------------ */
			return( lptr );
			}

		if ((GarbageReady)
		&&  ( BufferControl.garbage() != 0 ))
			continue;

		if (!( BufferControl.options & _AUTO_SWAP_OUT ))  {
			if ( MessageReady )
				(void) BufferControl.message(30);
			return( (BPTR)  0);
			}

		/* Attempt to reduce number of active buffers */
		/* ------------------------------------------ */
		if ( remove_buffer_control_node( ) == MOINS_UN ) {
			if ( MessageReady )
				(void) BufferControl.message(31);

			/* Indicate Malloc Failure */
			/* ----------------------- */
			return( (VPTR) 0 );
			}
#ifndef	ABAL_EXA
#ifdef	VERBALISE
		if ( Options.Pannel )
			draw_buffer_count( BufferControl.usage );
/*		else if ( Options.Verbose & 16 )
			sysprintf("Swap buffers count( %u : %u )\n",BufferControl.usage,this_time++ );
 */
#endif
#endif

		}
		

}

BUFFERHANDLE	allocate_buffer()
{
	BCNODEPTR	bcnode;
	BUFFERHANDLE	handle;

#ifndef	SLOW_SPEED

	/* Attempt to allocate user visible buffer reference structure */
	/* ----------------------------------------------------------- */
	if ((handle = allocate_for_handle()) == (BUFFERHANDLE) 0) {
		if ( MessageReady )
			(void) BufferControl.message(70);
		return( handle );
		}

#else
	if ((handle = (BUFFERHANDLE) zalloc( sizeof( struct user_buffer_handle ) )) == (BUFFERHANDLE) 0)
		return( handle );
#endif

	/* Attempt to collect a buffer control node item */
	/* --------------------------------------------- */
	if ((bcnode = get_next_buffer_control_node()) == (BCNODEPTR) 0) {
		if ( MessageReady )
			(void) BufferControl.message(71);
		free( handle );
		return( (BUFFERHANDLE) 0 );
		}

	/* Establish the current node user */
	/* ------------------------------- */
	bcnode->user      = handle;

	/* Collect buffer from control node and activate */
	/* --------------------------------------------- */
	handle->bcnode   = bcnode;
	handle->swapnode = SWAPPED_IN;

	/* Adjust book-keeping information */
	/* ------------------------------- */ 
	BufferControl.handles++;
	if ( BufferControl.handles > BufferControl.maxhandles )
		BufferControl.maxhandles = BufferControl.handles;

	/* Return Buffer identifier to user */
	/* -------------------------------- */
	return( handle );

}


#endif	/* _BUFFERS_C */
	/* ---------- */
