/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1997 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBPRC - C				*/
/*		Version : 	1.4a / 2.1a 					*/
/*		Date 	:	24/03/1997				*/
/*									*/
/*----------------------------------------------------------------------*/
#define	EXDBPROCC		/* Declare source identity		*/
#include "excode.h"		/* Definitions relative aux procedures	*/
#include "extype.h"

#ifdef ABALEXU
#define	db_xputch( c ) z_putch( c )
#endif

#ifdef	DEBUGGER
#include "exadb.h"
#endif
#include "exproto1.h"

struct	GestProc {
	EXABYTE 	ProcName[8];	/* Procedure Name			*/
	EXAWORD	ProcCtrl;	/* Procedure offset into Table		*/
	};

struct GestProc PTR PrcNbase; /* Procedure Names Table Pointer 	*/

EXAWORD	PrcNfois;		/* Procedure Name Counter		*/

BPTR	sectptr;		/* Sector Work pointer			*/
EXAWORD	Pindent;		/* indent into Sector			*/
EXAWORD	sectdex;		/* Sector Count value			*/

EXTERN	EXAWORD	adr_npr;	/* Secteur des Noms des Procedures	*/


EXABYTE	PrcGetc()
{
	/* Check for Sector end */
	/* -------------------- */
	if ( Pindent >= TCODEBLOCK ) {
		if ( SectRead(TcodeFileHandle,sectptr,TCODEBLOCK,(adr_npr + sectdex)) == MOINS_UN) {
			return(' ');
			}
		sectdex++; Pindent = 0;
		}
	return( (EXABYTE) *(sectptr + Pindent++));
}

VOID	LibNomProc()
{
	liberate( PrcNbase );
	return;
}

EXAWORD	InitNomProc()
{
	EXAWORD	workdex;
	EXAWORD	x,y;

	/* Allocate Work Sector Pointer */
	/* ---------------------------- */
	if ( (sectptr = (BPTR) allocate(TCODEBLOCK)) == (BPTR) 0) {
		err_val = ABAL_MEMORY; return(MOINS_UN);
		}
	
	/* Read in First Sector of Table of Names */
	/* -------------------------------------- */
	if ( SectRead(TcodeFileHandle,sectptr,TCODEBLOCK,adr_npr) == MOINS_UN ) {
		liberate( sectptr ); return(MOINS_UN);
		}

	/* Collect Count of procedure Names */
	/* -------------------------------- */
	
	PrcNfois = Tcodeword( sectptr ); Pindent = WORDSIZE; 
	sectdex = 1; workdex = 0;

	/* Allocate Table of Procedure Names */
	/* --------------------------------- */

	if ( ( PrcNbase = (struct GestProc PTR) allocate( ( PrcNfois * sizeof( struct GestProc ) ) )) == (struct GestProc PTR) 0) {
		liberate( sectptr ); err_val = ABAL_MEMORY; return(MOINS_UN);
		}

	/* Initialise the Procedure Name Table */
	/* ----------------------------------- */
	while ( workdex < PrcNfois ) {

		/* Transfer Procedure Name Loop */
		/* ---------------------------- */
		for ( x = 0 ; x < 8; x++ ) {
			(*(PrcNbase + workdex)).ProcName[x] = (EXABYTE) PrcGetc(); 
			}
		/* Collect Control ID of Procedure */
		/* ------------------------------- */
		(*(PrcNbase + workdex)).ProcCtrl = ((EXAWORD) PrcGetc());
		(*(PrcNbase + workdex)).ProcCtrl |= (((EXAWORD) PrcGetc()) << 8);

		/* Count controlled Skip of Arg Types */
		/* ---------------------------------- */
		y = ((EXAWORD) PrcGetc());
		y |= (((EXAWORD) PrcGetc()) << 8);
		while ( y > 0 ) { (VOID) PrcGetc(); y--; } 

		workdex++;
		}
	liberate( sectptr );
	return(0);
}

EXAWORD	ProcNumb( prcptr  )
BPTR	prcptr;
{
	EXAWORD	x,y;
	x = 0; 
	while ( x < PrcNfois ) {	
		y = 0;
		while ( y < 8 ) {
			if ( *(prcptr + y) == (EXABYTE) 0 ) {
				if ( (*(PrcNbase +x)).ProcName[y] == ' ' ) {
					y = 8; continue;
					}
				else	{ break; }
				}
			if ( (*(PrcNbase + x)).ProcName[y] != toupper( *(prcptr + y) ) ) { break; }
			y++;
			}
		if ( y == 8 ) { return(( (*(PrcNbase + x)).ProcCtrl / 16 ) ); }
		x++;
		}
	return( MOINS_UN);
}

VOID AffProcName( procoff )
EXAWORD	procoff;
{

	EXAWORD	x,y;
	x = 0;
	while ( x < PrcNfois ) {
		if ((*(PrcNbase + x)).ProcCtrl == procoff ) {
			for ( y = 0; y < 8; y++) {
				db_xputch( (*(PrcNbase + x)).ProcName[y] );
				}
			return;
			}
		x++;
		}
	db_xputch('&'); showword( procoff , 4 );
	return;
}

EXAWORD	ProcNamePtr( procoff , NomPtr )
EXAWORD	procoff;
BPTR	NomPtr;
{
	EXAWORD	x,y;
	x = 0;
	while ( x < PrcNfois ) {
		if ((*(PrcNbase + x)).ProcCtrl == procoff ) {
			for ( y = 0; y < 8; y++) {
				if ( (*(PrcNbase + x)).ProcName[y] == ' ' ) {
					break;
					}
				*(NomPtr++) = (*(PrcNbase + x)).ProcName[y];
				}
			*(NomPtr++) = (EXABYTE) 0; return(0);
			}
		x++;
		}
	*(NomPtr++) = (EXABYTE) 0; return(MOINS_UN);
}
