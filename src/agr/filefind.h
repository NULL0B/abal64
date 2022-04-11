/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990,1992 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	FILEFIND.H				*/
/*		Version :	1.1a					*/
/*		Date	:	01/12/1992				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_FILEFIND_H
#define	_FILEFIND_H

#ifndef	UNIX

#define	WILD_FIND

WORD	FFile( BPTR, BPTR );
WORD	NFile( BPTR );

#endif

#endif	/* _FILEFIND_H */
	/* ----------- */
