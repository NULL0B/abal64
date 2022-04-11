/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1994 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXGESMES-C				*/
/*		Version :	1.4d	/ 2.1b 				*/
/*		Date 	:	08/11/1994				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_GESMES_C
#define	_GESMES_C

/*	Messages de l'executeur et moniteur ABAL norme GESMES 		*/
/*	-----------------------------------------------------		*/
/*	A partir du 17/05/1989 les messages de l'executeur et Moniteur	*/
/*	sont compatible GESMES pour permettre la traduction en langue	*/
/*	du pays. L'ordre d'apparition des messages est essentielle et	*/
/*	ne doit pas etre changee.					*/
/*	--------------------------------------------------------------	*/
/*	A partir du 07/04/1994 les messages de l'executeur et Moniteur  */
/*	sont bilingues d'origine dans les binaires. Les messages de	*/
/*	langue francaise sont presents d'abord puis les messages en	*/
/*	langue anglaise suivent.					*/
/*	--------------------------------------------------------------	*/

#ifdef	ABAL14

/*	Dedicated executeur T-Code file Name Zone	*/
/*	-----------------------------------------	*/

EXAWORD		CryptCode;

static	char	Dedicate[]   ="*DED*\0\0                            \0";

#endif

/*	Messages and Message Management Functions	*/
/*	-----------------------------------------	*/

#ifndef	ABAL21
#include "ex14x.h"		/* Prior to ABAL 2.1b	07/04/1994	*/
#else
#ifdef	DEBUGGER
#include "exadb21x.h"		/* Messages EXADB >= 2.1b 07/04/1994	*/
#else
#include "exa21x.h"		/* Messages EXA   >= 2.1b 07/04/1994	*/
#endif
#endif


/*	Dedication Management and Functions	*/
/*	-----------------------------------	*/
 
#ifdef	ABAL14

#ifndef	UNIX
BPTR	exa_crypt( EXAWORD	,BPTR	,EXAWORD ,EXAWORD );
#else
BPTR	exa_crypt( );
#endif

#ifdef DOS
/* Only to know is EXA is dedicated */
/* -------------------------------- */
BPTR	IsDedicated()
{
	BPTR	wptr;
	EXAWORD	x;

	/* Establish pointer to Dedicated Zone */
	/* ----------------------------------- */
	wptr = (BPTR) Dedicate; wptr += 5;

	/* Collect Decryption Code and Check 0   */
	/* ------------------------------------- */
	x = Tcodeword( (wptr) );

	return((x == 0) ? (BPTR) 0 : wptr);
}
#endif



/*	Evaluation of Dedicated file name	*/
/*	---------------------------------	*/
BPTR	dedicated()
{
	BPTR	wptr;
	EXAWORD	x;
	EXAWORD	fi;

	/* Establish pointer to Dedicated Zone */
	/* ----------------------------------- */
	wptr = (BPTR) Dedicate; wptr += 5;

	/* Collect Decryption Code and Check 0   */
	/* ------------------------------------- */
	CryptCode = Tcodeword( (wptr) );

	if ( CryptCode == 0 ) {

		/* Normal non-dedicated Executeur */
		/* ------------------------------ */
		return( (BPTR) 0 );
		}
	else	{
		/* Dedicated Executeur  DeCrypt the Zone */
		/* ------------------------------------- */
		(void) exa_crypt(1990 , (BPTR) wptr , 31 , 0);
		CryptCode = Tcodeword( (wptr) ); wptr += 2;
#ifdef	UNIX
		for ( fi = 0; fi < 29; fi++ )
			if ( *(wptr + fi) == ' ' )
				*(wptr + fi) = 0;

#endif
		return( (BPTR) wptr  );
		}
}

#endif
#endif	/* _GESMES_C */
	/* --------- */
