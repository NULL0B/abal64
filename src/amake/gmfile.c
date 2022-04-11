#include "stdtypes.h"
#include "allocate.h"
#include "gmhead.h"
#include "gmfile.h"
#include "gmrdef.h"

#define	BLOCK	256

#ifdef	UNIX
BPTR	ConstValue();
BPTR	Substitute();
#else
BPTR	ConstValue(BPTR);
BPTR	Substitute(BPTR);
#endif

#ifdef	PRL
BYTE	tempname[256];
#endif

EXTERN	WORD	Echo;

#define	FILECTRL	struct gmcontext XPTR

/*	Inclusion of Access compatibillity if Required	*/
/*	---------------------------------------------- 	*/

#ifndef	COEXA
WORD	Access(a1,a2,a3)
BPTR	a1;
WORD	a2;
WORD	a3;
{
	WORD	ahandle;

	if ( *a1 == '$' ) {
		if ((a1 = (BPTR) Substitute((BPTR) a1 )) == (BPTR) 0) {
			return(-1);
			}
		}
/*	Remove UNIX definition for VMS Access decision 	*/
/*	---------------------------------------------	*/
#ifdef	VMS
#undef	UNIX
#endif

#ifdef  UNIX
	/* UNIX offers the function access() */
	/* --------------------------------- */
	return(access(a1,0));
#else
	/* Other systems must simulate Access */
	/* ---------------------------------- */
	if ((ahandle = open ( a1 , READPERM )) != 0xFFFF ) {
		close (ahandle);
		return (0);
		}
	return(-1);
#endif

/*	Restore UNIX definition after VMS Access decision 	*/
/*	------------------------------------------------	*/
#ifdef	VMS
#define	UNIX
#endif
}

void	liberlox(a1)
BPTR	a1;
{
	return;
}
#endif

BYTE	SubsBuffer[128];		/* Substitution Work Zone	*/

/*
 *	Performs Filename Variable and Path Substitution
 *	------------------------------------------------
 */

BPTR	Substitute( nfic )
BPTR	nfic;
{
	WORD	i;
	BYTE	c;
	BPTR	sptr;

	i = 0;

	while ( *(nfic + i) != ')' ) { i++; }
	c = *(nfic + i + 1);
	*(nfic + i + 1) = (BYTE) 0;
	if ((sptr = ConstValue((BPTR) nfic)) != (BPTR) 0) {
		strcpy((BPTR) SubsBuffer, (BPTR) sptr);
		*(nfic + i + 1) = c;
		strcpy((BPTR) &(SubsBuffer[strlen((BPTR)SubsBuffer)]),(BPTR) (nfic + i + 1));
		return((BPTR) SubsBuffer);
		}
	return((BPTR) 0);
	
}

/*
 *	Source file opening and control structure Initialisation
 *
 */

WORD	whoops;

FILECTRL gm_open( nfic )
BPTR nfic;
{
	FILECTRL lptr;
	
	if ( *nfic == '$' ) {
		if ((nfic = (BPTR) Substitute((BPTR) nfic )) == (BPTR) 0) {
			return((FILECTRL) 0);
			}
		}
	
	/* Attempt Allocation of Control structure */
	/* --------------------------------------- */
	if ((lptr = (FILECTRL) allocate (sizeof(struct gmcontext) )) != (FILECTRL) 0 ) {

		/* Attempt to establish Exclusive Access rights */
		/* -------------------------------------------- */
		if ( Access (nfic,0,1) == 0 ) {

			/* Attempt allocation for Filename storage */
			/* --------------------------------------- */
			if ((lptr->filename = (BPTR) allocate ( strlen(nfic) + 2 )) != (BPTR) 0 ) {

				/* Perform FileName storage */
				/* ------------------------ */
				strcpy ((BPTR) lptr->filename ,(BPTR) nfic );

				/* Attempt buffer Allocation */
				/* ------------------------- */
				if ((lptr->buffer = (BPTR) allocate( BLOCK )) != (BPTR) 0) { 

					/* Attempt to open file now !! */
					/* --------------------------- */
					if ((lptr->nlog = open( nfic , READPERM )) != 0xFFFF ) {

						/* Initialise control structure */
						/* ---------------------------- */
						lptr->indent = 0;

						lptr->sector = 0;

						/* Attempt to Load Initial Block */
						/* ----------------------------- */
						if ((lptr->maxind = read (lptr->nlog,lptr->buffer,BLOCK)) > 0) {

							/* Adjust Sector Position */
							/* ---------------------- */
							lptr->sector++;

							/* SUCCESS file open */
							/* ----------------- */
							return( lptr );
							}
						/* Close the file */
						/* -------------- */
						close ( lptr->nlog );
						}

					/* Liberate the buffer */
					/* ------------------- */
					liberate ( lptr->buffer );
					}

				/* Liberate the filename */
				/* --------------------- */
				liberate ( lptr->filename );	
				}

			/* Liberate Exclusive reservation */
			/* ------------------------------ */
			liberlox (nfic);	
			}

		/* Liberate control structure */
		/* -------------------------- */
		liberate ( (BPTR) lptr );
		}

	/* Error : Unable to perform complete file opening */
	/* ----------------------------------------------- */
	return( (FILECTRL) 0 );
}

void	gm_close( lptr )
struct  gmcontext XPTR lptr;
{
	/* Close low level file */
	/* -------------------- */
	close ( lptr->nlog );

	/* Liberate buffer */
	/* --------------- */
	liberate ( lptr->buffer );

	/* Liberate exclusive reservation */
	/* ------------------------------ */
	liberlox ( lptr->filename );

	/* Liberate filename storage zone */
	/* ------------------------------ */
	liberate ( lptr->filename );

	/* Liberate control structure */
	/* -------------------------- */
	liberate ( (BPTR) lptr );
	return;
}


WORD	gm_getch( lptr ) 
FILECTRL	lptr;
{
	/* Check for End of Block */
	/* ---------------------- */
	if ( lptr->indent >= lptr->maxind ) {

		/* Attempt to Load Next Block */
		/* -------------------------- */
		if ((lptr->maxind = read (lptr->nlog,lptr->buffer,BLOCK)) == 0) {

			/* Failure End of File */
			/* ------------------- */
			return( 0 );
			}

		/* Adjust Sector Position */
		/* ---------------------- */
		lptr->sector++;

		/* Reset Buffer index */
		/* ------------------ */
		lptr->indent = 0;
		}
	/* Return the current character */
	/* ---------------------------- */
	if ( Echo != 0 ) {
		llmf_co(lptr->buffer[lptr->indent]);
		}
	return( lptr->buffer[lptr->indent++] );

}

void	gm_finline( lptr )
FILECTRL	lptr;
{
	WORD	c;
	do	{
		if ((c = gm_getch( lptr )) == 0x001A) {
			c = 0;
			}
		}
	while ((c != 0) && (c != 0x000A));
	return;
}

BYTE	wordzone[256];

BPTR gm_getw( lptr )
FILECTRL lptr;
{
	WORD i,c;
	WORD openquote;

	i = 0; openquote = 0;

	while ( i < 255 ) {
		switch ((c = gm_getch(lptr))) {
			case 0x000D	: continue;
			case 0x001A	:
			case 0   	: if ( i == 0 ) 
						return((BPTR) 0); 
			case ' ' 	:
			case 9	 	:
			case 0x0A	: if ( i == 0 ) 
						continue;
					  if ( openquote == 0 ) {
						wordzone[i] = 0;
						return( (BPTR) wordzone );
						}
					  wordzone[i++] = c;
					  continue;
			case 0x0022	: /* Quote Character */
					  /* --------------- */
					  if ( openquote ) {
						openquote = 0;
						wordzone[i++] = c;
						wordzone[i++] = 0;
						return((BPTR) wordzone );
						}
					  else	{
						openquote = 1;
						}
			default		: wordzone[i++] = c;
					  continue;
			}
		}
	wordzone[i] = 0;
	return( (BPTR) wordzone );
}


/*
 *	Output file management Functions
 *	--------------------------------
 */

FILECTRL gm_creat( nfic )
BPTR	nfic;
{
	FILECTRL lptr;
	
	/* Perform Path Substitution */
	/* ------------------------- */
	if ( *nfic == '$' ) {
		if ((nfic = (BPTR) Substitute((BPTR) nfic )) == (BPTR) 0) {
			return((FILECTRL) 0);
			}
		}

	/* Attempt Allocation of Control structure */
	/* --------------------------------------- */
	if ((lptr = (FILECTRL) allocate (sizeof(struct gmcontext) )) != (FILECTRL) 0 ) {

		/* Attempt allocation for Filename storage */
		/* --------------------------------------- */
		if ((lptr->filename = (BPTR) allocate ( strlen(nfic) + 1 )) != (BPTR) 0 ) {

			/* Perform FileName storage */
			/* ------------------------ */
			strcpy ((BPTR) lptr->filename ,(BPTR) nfic );

			/* Attempt buffer Allocation */
			/* ------------------------- */
			if ((lptr->buffer = (BPTR) allocate( BLOCK )) != (BPTR) 0) { 

				/* Attempt to open file now !! */
				/* --------------------------- */
				if ((lptr->nlog = open( nfic , WRITEPERM )) != 0xFFFF ) {

					/* Close it Quick */
					/* -------------- */
					close ( lptr->nlog );

					/* Now Delete it */
					/* ------------- */
					unlink ( nfic );

					}

				/* Attempt to create the file */
				/* -------------------------- */
				if ((lptr->nlog = creat ( nfic , CREATPERM )) != 0xFFFF ) {

					/* Initialise control structure */
					/* ---------------------------- */
					lptr->indent = 0;

					/* Initialise Sector Value */
					/* ----------------------- */
					lptr->sector = 0;

					/* SUCCESS file open */
					/* ----------------- */
					return( lptr );

					}

				/* Liberate the buffer */
				/* ------------------- */
				liberate ( lptr->buffer );
				}

			/* Liberate the filename */
			/* --------------------- */
			liberate ( lptr->filename );	
			}

		/* Liberate control structure */
		/* -------------------------- */
		liberate ( (BPTR) lptr );
		}

	/* Error : Unable to perform complete file opening */
	/* ----------------------------------------------- */
	return( (FILECTRL) 0 );
}

void	OutFlush( lptr )
FILECTRL	lptr;
{
#ifndef	UNIX

	/* Fill to End of Buffer with Ctrl Z */
	/* --------------------------------- */
	while ( lptr->indent < BLOCK ) {
		lptr->buffer[lptr->indent++] = 0x001A;
		}
#endif
	/* Write Current Buffer Contents if needed */
	/* --------------------------------------- */
	if ( lptr->indent > 0 ) { 

		/* Perform Buffer flush Write operation */
		/* ------------------------------------ */
		(void) write ( lptr->nlog , lptr->buffer , lptr->indent );

		/* Adjust Sector Position */
		/* ---------------------- */
		lptr->sector++;

		}


	/* Close the File and Return */
	/* ------------------------- */
	gm_close( lptr );
	return;

}

WORD	gm_putch( lptr , c )
FILECTRL	lptr;
WORD		c;
{
	/* Check for Block Write needed */
	/* ---------------------------- */
	if ( lptr->indent == BLOCK ) {

		/* Attempt Block Write */
		/* ------------------- */
		if ( write ( lptr->nlog , lptr->buffer , BLOCK) != BLOCK ) {
			return(0xFFFF);
			}

		/* Adjust Sector Position */
		/* ---------------------- */
		lptr->sector++;

		/* Reset Buffer index */
		/* ------------------ */
		lptr->indent = 0;
		}

	/* Put Character onto Output buffer Stream */
	/* --------------------------------------- */
	lptr->buffer[lptr->indent++] = (BYTE) c;
	return(0);
}



