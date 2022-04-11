/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXTCNGF - H				*/
/*		Date 	:	23/07/1992				*/
/*		Version :	1.4a 					*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	EXTCNGFH		/* If Not already included		*/
#define	EXTCNGFH		/* Avoid multiple inclusions		*/
/*----------------------------------------------------------------------*/
/* 		NGF Sub function codes					*/
/*----------------------------------------------------------------------*/

#define		_NGF_CFILE 		0x0000
#define		_NGF_DFILE 		0x0001
#define		_NGF_RENAME		0x0002
#define		_NGF_OPEN		0x0003
#define		_NGF_CLOSE		0x0004
#define		_NGF_READ		0x0005
#define		_NGF_WRITE		0x0006

#define		_NGF_INSERT		0x0007
#define		_NGF_MODIFY		0x0008
#define		_NGF_DELETE		0x0009
#define		_NGF_SEARCH		0x000A
#define		_NGF_DOWN		0x000B
#define		_NGF_UP  		0x000C
#define		_NGF_ATB		0x000D
#define		_NGF_BACKSPACE		0x000E
#define		_NGF_EXTEND		0x000F
#define		_NGF_ASSIGN		0x0010
#define		_NGF_LOAD		0x0011
#define		_NGF_XCRI 		0x0012
#define		_NGF_CHAIN		0x0013

/*	Codes des fonctions Multicritere	*/
/*	--------------------------------	*/

#define		_NGF_KEY		0x0014
#define		_NGF_CKEY		0x0015
#define		_NGF_RKEY		0x0016
#define		_NGF_FKEY		0x0017
#define		_NGF_NKEY		0x0018
#define		_NGF_LKEY		0x0019
#define		_NGF_LINK		0x001A
#define		_NGF_CLINK		0x001B
#define		_NGF_LLINK		0x001C
#define		_NGF_POSIT		0x001D
#define		_NGF_COUNT		0x001E
#define		_NGF_STATS		0x001F

/*	Codes des fonctions Base de donnees	*/
/*	-----------------------------------	*/

#define		_NGF_RECORD		0x0020
#define		_NGF_JOIN		0x0021
#define		_NGF_CJOIN		0x0022
#define		_NGF_DJOIN		0x0023
#define		_NGF_RJOIN		0x0024
#define		_NGF_LJOIN		0x0025
#define		_NGF_LFILE		0x0026


/*	Recherche catalogue Volume	*/
/*	--------------------------	*/

#define		_NGF_FIND		0x0027


/*	Dump of current executer core	*/
/*	-----------------------------	*/
#define		_NGF_FILE		0x0028

/* 	Return Assign Infos		*/
/*	-------------------		*/
#define		_NGF_NAME		0x0029

/* CRITERIA TRANSACTION SESSION */
/* ----------------------------	*/
#define		_NGF_SESSION		0x002A
#define		_NGF_COLLECT		0x002B

/*	SQL Extensions			*/
/*	--------------			*/
#ifdef	ABALSQL
#define		_NGF_SELECT		0x002C
#define		_NGF_PREPARE		0x002D
#define		_NGF_FETCH		0x002E
#define		_NGF_EXEC		0x002F
#define		_NGF_KEYTYPE		0x0030
#define		_NGF_LINKNAME		0x0031
#define		_NGF_FILEUSER		0x0032
#endif

	/* -------- */
#endif	/* EXTCNGFH */
	/* -------- */
