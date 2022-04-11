/*----------------------------------------------------------------------*/
/*									*/
/*		---------------------------------------			*/
/*		  Copyright (c) 1989,1993 Amenesik / Sologic s.a.			*/
/*		---------------------------------------			*/
/*		Project		:	ABAL MAKE			*/
/*		Module		:	UTFILE.C			*/
/*		Version		:	1.4c / 2.1a			*/
/*		Date		:	21/07/1993			*/
/*		---------------------------------------			*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_UTFILE_C
#define	_UTFILE_C

#include "stdtypes.h"
#define	ALSMID "utfile"
#include "allocate.h"
#include "utdef.h"
#include "amake.h"
#include "utfile.h"

struct	Makegard filegard;

struct	Context XPTR StakBase;

BYTE	tempname[128];

int	llmf_open();
int	llmf_close();

EXTERN	BPTR	SearchName();
EXTERN	VOID	mf_eder();
EXTERN	int	getchwatch;

int	GetchCtrl;

#ifndef	PRL
int	llmf_read( nlog , sector , buffer , xfer )
int	nlog;
int	sector;
BPTR	buffer;
int	xfer;
{
	lseek( nlog , ((long) sector) * 256L , SEEK_SET );
	return(read(nlog,buffer,xfer));

}
#endif

#ifndef	UNIXXXXX
int	Access(nomfic,mode,share)
BPTR	nomfic;
int	mode;
int	share;
{
	return(0);
}
VOID	liberlox(nomfic)
BPTR	nomfic;
{
	return;
}
VOID	PurgeLox()
{
	return;
}
#endif

int	mf_close( nlog )
int	nlog;
{
	/* Liberate file from ACCESS */
	/* ------------------------- */
	liberlox((BPTR) filegard.filename );
	
	/* Close sytem file handle */
	/* ----------------------- */
	return(llmf_close(nlog));
}



int	Existance( nomfic , mode , share )
BPTR nomfic;
int	mode;
int	share;
{
	int	nlog;

	/* Research in Qwick find Table */
	/* ---------------------------- */
	if ( QwikFinder((BPTR) nomfic) == 0)
		return(0);

	/* File Not Known So Open and Close it */
	/* ----------------------------------- */ 
	if ( (nlog = llmf_open(nomfic,READPERM)) != -1 ) {
		mf_close( nlog );
		return(0);
		}

	/* Existance Denied */
	/* ------------- */
	return(-1);
}

/*	Save current context for !INCLUDE	*/
/*	---------------------------------	*/
int	PushContext()
{
	struct Context XPTR lbase;
	struct Makegard XPTR lfile;

	/* Attempt to Allocate stack node structure */
	/* ---------------------------------------- */
	if (( lbase = (struct Context XPTR) allocate( sizeof( struct Context ) )) != (struct Context XPTR) 0 ) {

		/* Attempt to Allocate current file context buffer */
		/* ----------------------------------------------- */
		if (( lfile = (struct Makegard XPTR) allocate( sizeof( struct Makegard ) )) != (struct Makegard XPTR) 0 ) {
		
			/* Copy current file context to Storage Zone */
			/* ----------------------------------------- */
			memcpy ((BPTR) lfile, (BPTR) &filegard , sizeof( struct Makegard ));
			
			/* Perform stack list insertion */
			/* ---------------------------- */
			lbase->FileNext = StakBase;
			lbase->FileKeep = lfile;
			StakBase = lbase;	
			return ( 0 );

			}
		else	{
			/* Liberate dur to Allocation error */
			/* -------------------------------- */
			liberate( (BPTR) lbase );
			}
		}
	return(-1);
}

/*	Restore last context for end of !INCLUDE	*/
/*	----------------------------------------	*/
int	PopContext()
{
	struct	Context XPTR lptr;

	/* Check for something on the stack */
	/* -------------------------------- */
	if ( StakBase != (struct Context XPTR) 0 ) {

		mf_close( filegard.numlog );

		/* Copy current file context to Storage Zone */
		/* ----------------------------------------- */
		memcpy ((BPTR) &filegard, (BPTR) StakBase->FileKeep , sizeof( struct Makegard ));

		lptr = StakBase->FileNext;

		/* Liberate POPED context */
		/* ---------------------- */
		liberate((BPTR) StakBase->FileKeep );
		liberate((BPTR) StakBase );
		StakBase = lptr;
		return (0);

		}
	else	{
		return(-1);
		}
}

VOID	establish_trace_info( lrule )
RULETREE	lrule;
{
	int	l;
	if ((lrule->MakeFile = (BPTR) allocate((l = (strlen((BPTR) filegard.filename) + 1)))) != (BPTR) 0) {
		memcpy( (BPTR) lrule->MakeFile , (BPTR) filegard.filename, l );
		lrule->Linecount = filegard.lignes;
		}
	return;

}


int	xmf_open( fnom )
BPTR	fnom;
{
	if ( Access(fnom,0,1) == 0 ) {

		/* Save file name */
		/* -------------- */
		memcpy( (BPTR) filegard.filename , (BPTR) fnom , ( strlen( (BPTR) fnom ) + 1) );

		/* Initialise File context and read first block */
		/* -------------------------------------------- */
		GetchCtrl = 0;
		filegard.numlog = llmf_open(fnom,READPERM);
		filegard.sector = 0;
		filegard.limit  = llmf_read(filegard.numlog,filegard.sector,(BPTR) filegard.buffer,256);
		filegard.sector = 1;
		filegard.indent = 0;
		filegard.lignes = 1;
		return(filegard.numlog);

		}
	else	{
		return(-1);
		}

}

int	mf_open( fnom )
BPTR fnom;
{
	WORD	l;
	BYTE	fnomb[256];
	int	result;

	if (( result = xmf_open( (BPTR) fnom )) != -1 )
		return( result );
	if (( l = fn_parser((BPTR) fnom, (BPTR) fnomb, 0x0010 )) != 0)
		return( result );
	strcpy((BPTR) fnomb, (BPTR) fnom );
	l = strlen( (BPTR) fnomb );
	fnomb[l++] = '.';
	fnomb[l++] = 'm';
	fnomb[l++] = 'f';
	fnomb[l++] = 0;
	return( xmf_open( (BPTR) fnomb ) ); 
}	

int	mf_getch()
{
	if ( filegard.indent >= filegard.limit ) {
		filegard.limit  = llmf_read(filegard.numlog,filegard.sector,(BPTR) filegard.buffer,256);
		filegard.sector += 1;
		filegard.indent = 0;
		}
	if ( filegard.indent < filegard.limit ) {
		return( filegard.buffer[filegard.indent++]);
		}
	else	{
		if ( PopContext() == 0 ) {
			return( mf_getch() );
			}
		else	{
			return(0);
			}
		}

}

int	z_getch()
{
	BYTE	token[65];
	int	tokdex;
	int	mode;
	int	c;
	mode = 0;
	while ( 1 ) {
		if ( GetchCtrl == 0 ) {
			switch ( (c = mf_getch()) ) {
				case  0 	:
				case  -1	:
				case 0x001A	: 
					if ( getchwatch != 0 ) {
						mf_message((BPTR) " <EOF> ");
						}
					if ( PopContext() == 0 ) {
						continue;
						}
					return(0);
				case 0x000A	: filegard.lignes++;
						  if ( mode == 0 ) {
							if ( getchwatch != 0 ) {
								llmf_co( c );
								}
							return(c);
							}
						  mode = 0; continue;
				case '#'	: mode = 1; continue;
				default 	: if ( mode == 0 ) {
							if ( getchwatch != 0 ) {
								llmf_co( c );
								}
							return(c);
							}
				}
			}
		else	{
			switch ( (c = mf_getch()) ) {
				case 0		:
				case -1		:
				case 0x001A	: 
					if ( getchwatch != 0 ) {
						mf_message((BPTR) " <EOF> ");
						}
					if ( PopContext() == 0 ) {
						continue;
						}
					return(0);
				case '!'	: 
					if ( getchwatch != 0 ) {
						llmf_co( c );
						}
					return( c );
				}
			}
		}
}

WORD	not_white_space()
{
	WORD	c;
	while (1) {
		switch ((c = mf_getch())) {
			case 0x0009 :
			case ' '    :
				continue;
			default	    :
				return( c );
			}
		}
}		

/*
 *	M F _ E D E R ( error_value )
 *	-----------------------------
 *	Makefile error messages (all systemes)
 *
 */

#ifndef	PRL
long	FileStamp( pathname )
BPTR	pathname;
{
	int	lerr;

#ifdef	DOS

	BYTE	ldta[512];
	
	/* Attempt to read Disk info for file */
	/* ---------------------------------- */
	if ( exadosfirst( (BPTR) ldta , (BPTR) pathname ) == 0 ) {
		return( *((long far *) (& ldta[0x0016] )) );
		}
	return(-1L);

#endif
#ifdef UNIX
	struct stat stampstat;
	if ( stat( pathname , &stampstat ) == 0 ) {
		return( (long) stampstat.st_mtime );
		}
	else	{
		mf_message((BPTR) "amake: Cannot stat: ");
		mf_message((BPTR) pathname );
		mf_eder((lerr = errno));
		return( -1L );
		}
#endif
	return(0L);

}
#endif

VOID	DecimalWord( x )
int	x;
{
	int	n;
	int	f;

	if ( x == 0 ) { 
		llmf_co('0'); 
		}
	else	{
		for (f = 0, n = 10000; n > 0; n /= 10 ) {
			if ((( x / n ) > 0 ) || ( f != 0)) {
				llmf_co((( x / n) | 0x0030));
				f = 1;
				}
			x %= n;
			}
		}
	return;
}

VOID	print_trace_info()
{
	mf_message((BPTR) filegard.filename );
	llmf_co('(');
	DecimalWord( filegard.lignes );
	llmf_co(')');
	return;
}

VOID	warning(lRule)
RULETREE	lRule;
{
	mf_message((BPTR) lRule->MakeFile );
	llmf_co('(');
	DecimalWord( lRule->Linecount );
	llmf_co(')');	
	return;
}

/*	Display makefile region after error message		*/
/*	-------------------------------------------		*/
VOID	ou_eder()
{
	utline();
	return;
}

/*	Initialise include file stack manager	*/
/*	-------------------------------------	*/
int	InitFiles()
{
	StakBase = (struct Context XPTR) 0;
	return(0);
}

/*	Liberate Stacked up Include file context	*/
/*	----------------------------------------	*/
VOID	FreeFiles()
{
	struct Context XPTR	lptr;
	
	/* while more files stacked */
	/* ------------------------ */
	while ( StakBase != (struct Context XPTR) 0 ) {
		lptr = StakBase->FileNext;
		liberate((BPTR) StakBase->FileKeep );
		liberate((BPTR) StakBase );
		StakBase = lptr;
		}

	/* Ensure all files are xliberated */
	/* ------------------------------ */
	PurgeLox();
	return;

}


#endif	/* _UTFILE_C */
	/* --------- */

