/*
 *	------------------	----------------------------
 *	Project	: JavAbal	Compiler and Virtual Machine	
 *	------------------	----------------------------
 *	Date	: 18/09/97
 *	------------------	----------------------------
 */

#ifndef	_STDPSU_H
#define _STDPSU_H

#if defined(WIN32)

#include <windows.h>
#define PUBLIC
#define EXTERN
#define PTR *
typedef void * VPTR;
typedef unsigned char *  BPTR;

#else
#include "stdtypes.h"
#endif

#include "sysfile.h"

/* 	---------------------------------------------------------------------
 **	from PSU.ASM	I.J. Marshall	10/09/1997	PIXEL_STORAGE_UNIT
 **	---------------------------------------------------------------------
 **	Reworked	I.J.Marshall	04/08/1999	For NV Graphic Print
 **	---------------------------------------------------------------------
 **	Modified 	I.J.Marshall	16/02/2000	Commit Pixel Storage
 **							has been added for 
 **							GUI Smoothing of NV
 **	---------------------------------------------------------------------
 **	This file provides the description of the multiple buffering mechanism
 **	implemented in the form of the ABAL++ class :
 **
 **		"pixel_storage_unit" 
 **
 **	Instances of this class are of variable length depending upon the
 **	quantity of pixel data required for storage. 
 **	They will all be at very least : 
 **
 **		((SIZEOF pixel_storage_unit ) - 1)
 **
 **	and are normally 
 **
 **		((SIZEOF pixel_storage_unit ) - 1) + (rowcount * columncount)
 **	
 **	---------------------------------------------------------------------
 **
 **	The current ABAL++ description of this class, in terms of its data 
 **	members only,  can be seen below :
 **
 **	class pixel_storage_unit
 **
 **		Public pixel_storage_unit Pointer NextBuffer
 **		Private Dcl AtColumn%
 **		Private Dcl AtRow%
 **		Public Dcl Columns%
 **		Public Dcl Rows%
 **		Private Dcl Storage$=1
 **
 **	endclass pixel_storage_unit
 **	
 **	---------------------------------------------------------------------
 **	The full description of this class, including its Methods, may be
 **	found in the ABAL++ Class File PIXELCC.AS
 **	---------------------------------------------------------------------
 **
 **	---------------------------------------------------------------------
 **	* * * * * 	V E R Y   I M P O R T A N T		* * * * * * *
 **	---------------------------------------------------------------------
 **	NB if any more data members are to be added then the following 'C'
 **	constants will need to be adjusted in order to reflect the true
 **	structure of instances of this class. 
 **	---------------------------------------------------------------------
 */

#define	_PSU_VALIDPTR			 1

#define	_PSU_NEXT_BUFFER_CHECK 		 0
#define	_PSU_NEXT_BUFFER		 1
#define	_PSU_AT_COLUMN			 5
#define	_PSU_AT_ROW    		    	 7
#define	_PSU_COLUMNS   		    	 9
#define	_PSU_ROWS      		    	11
#define	_PSU_STORAGE   		    	13

#if !defined(_STRUCPSU_H_)	/* GWB le 12/09/2007 voir strucpsu.h */
#define _STRUCPSU_H_		/* GWB le 12/09/2007 */
#define	STDPSU		struct standard_pixel_storage
#define	STDPSUPTR	STDPSU PTR

STDPSU	{
	WORD	descriptor[8];
	BPTR	root;
	BPTR	current;
	WORD	seekbase;
	WORD	seeksize;
	};
#endif		/* GWB le 12/09/2007 */

PUBLIC	STDPSUPTR	allocate_graphic_storage( WORD, WORD, WORD, WORD );
PUBLIC	STDPSUPTR	allocate_textual_storage( WORD, WORD, WORD, WORD );
PUBLIC	STDPSUPTR	allocate_shadow_storage( STDPSUPTR );
PUBLIC	STDPSUPTR	liberate_pixel_storage( STDPSUPTR );
PUBLIC	STDPSUPTR	liberate_process_storage( STDPSUPTR );
PUBLIC	STDPSUPTR	allocate_process_storage( WORD,WORD, VPTR );
PUBLIC	BPTR 		resolve_pixel_storage( STDPSUPTR );
PUBLIC	VOID		background_pixel_capture( STDPSUPTR );
PUBLIC	VOID		foreground_pixel_capture( STDPSUPTR );
PUBLIC	VOID		cancel_pixel_capture( STDPSUPTR	 );
PUBLIC	VOID		commit_pixel_storage( STDPSUPTR, WORD, WORD );
PUBLIC	VOID		reset_pixel_row( STDPSUPTR, WORD, WORD, WORD, WORD );
PUBLIC	WORD		collect_pixel_row( STDPSUPTR, WORD, WORD, WORD, BPTR);
PUBLIC	BPTR		connect_pixel_row( STDPSUPTR, WORD );
PUBLIC	VOID		capture_pixel_storage( STDPSUPTR psptr );
PUBLIC	VOID		refresh_pixel_storage( STDPSUPTR psptr );

EXTERN	int		testware(void);
EXTERN	int		userware(int, int, void *);
EXTERN	int		hardware(void);

EXTERN	void *		check_psu( void * );


	/* ------------ */
#endif	/* _STDPSU_H	*/
	/* ------------ */



