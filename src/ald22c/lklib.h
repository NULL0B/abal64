#ifndef __LKLIB_H__
#define __LKLIB_H__

/*------------------------------------------------------------- LKLIB.HE ------
 *
 *	Editeur de liens A.B.A.L.	-   Copyright Amenesik / Sologic s.a. (c) 1993
 *
 *			Declaration des variables publiques 
 *			Declaration des variables et procs. externes
 *
 *			      Creation 2.0 le 07/04/1993
 *
 * Revisions :
 *	
 *
 *---------------------------------------------------------------------------*/

#ifdef _LKLIB
#undef PRIMITIVE
#define PRIMITIVE
#endif

#ifndef	LONG
#define	LONG unsigned long
#endif

#ifdef LINT_ARGS

	PRIMITIVE VOID LibDiffRepFic(BYTE XPTR * , BYTE XPTR * , BYTE XPTR * );
	PRIMITIVE VOID LibMakeReper	
		(
		IN	BYTE XPTR *		Nrep, 
		OUT	BYTE XPTR *		Dnom
		);
	PRIMITIVE BOOL LibInitArg(BYTE XPTR * , BYTE XPTR * );
	PRIMITIVE BOOL LibNextOpt(BYTE XPTR * XPTR * , BYTE XPTR * );
	PRIMITIVE BOOL LibCmpBib(BYTE XPTR * , BYTE XPTR * );
	// YT : bad case
	//PRIMITIVE VOID LibGetNomfic(BYTE XPTR * , BYTE XPTR * , BYTE XPTR * , BYTE XPTR * );
	PRIMITIVE VOID LibGetNomFic 
		(
		IN		BYTE XPTR * PathFile, 
		OUT	BYTE XPTR * Buffer, 
		IN		BYTE XPTR * Extension, 
		IN		BYTE XPTR * DestinationFullPath
		);

PRIMITIVE LONG LibBinToLong( WORD );

	// Added JPH
	char * XstrCpySize(char * To, char * From, int MaxLength);

#else 	/* LINT_ARGS */

	PRIMITIVE VOID LibDiffRepFic();
	PRIMITIVE VOID LibMakeReper();
	PRIMITIVE BOOL LibInitArg();
	PRIMITIVE BOOL LibNextOpt();
	PRIMITIVE BOOL LibCmpBib();
	PRIMITIVE VOID LibGetNomfic();
	PRIMITIVE LONG LibBinToLong();

	// Added JPH
	char * XstrCpySize();

#endif  /* LINT_ARGS */

#endif  /* __LKLIB_H__ */






