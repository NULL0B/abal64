#ifndef	_abalngf_h
#define	_abalngf_h

static char * abal_ngf_keyword[] = {
	(char *)	"CFILE",	/* 0x0000 */
	(char *)	"DFILE",	/* 0x0001 */
	(char *)	"RENAME",	/* 0x0002 */
	(char *)	"OPEN",		/* 0x0003 */
	(char *)	"CLOSE",	/* 0x0004 */
	(char *)	"READ",		/* 0x0005 */
	(char *)	"WRITE",	/* 0x0006 */
	(char *)	"INSERT",	/* 0x0007 */
	(char *)	"MODIF",	/* 0x0008 */
	(char *)	"DELETE",	/* 0x0009 */
	(char *)	"SEARCH",	/* 0x000A */
	(char *)	"DOWN",		/* 0x000B */
	(char *)	"UP",		/* 0x000C */
	(char *)	"ATB",		/* 0x000D */
	(char *)	"BACKSPACE",	/* 0x000E */
	(char *)	"EXTEND",	/* 0x000F */
	(char *)	"ASSIGN",	/* 0x0010 */
	(char *)	"LOAD",		/* 0x0011 */
	(char *)	"XCRI",		/* 0x0012 */
	(char *)	"CHAIN",	/* 0x0013 */
	(char *)	"KEY",		/* 0x0014 */
	(char *)	"CKEY",		/* 0x0015 */
	(char *)	"RKEY",		/* 0x0016 */
	(char *)	"FKEY",		/* 0x0017 */
	(char *)	"NKEY",		/* 0x0018 */
	(char *)	"LKEY",		/* 0x0019 */
	(char *)	"LINK",		/* 0x001A */
	(char *)	"CLINK",	/* 0x001B */
	(char *)	"LLINK",	/* 0x001C */
	(char *)	"POSIT",	/* 0x001D */
	(char *)	"COUNT",	/* 0x001E */
	(char *)	"STAT",		/* 0x001F */
	(char *)	"RECORD",	/* 0x0020 */
	(char *)	"JOIN",		/* 0x0021 */
	(char *)	"CJOIN",	/* 0x0022 */
	(char *)	"DJOIN",	/* 0x0023 */
	(char *)	"RJOIN",	/* 0x0024 */ 
	(char *)	"LJOIN",	/* 0x0025 */
	(char *)	"LFILE",	/* 0x0026 */
	(char *)	"FIND",		/* 0x0027 */
	(char *)	"FILE",		/* 0x0028 */
	(char *)	"NAME",		/* 0x0029 */
	(char *)  	"SESSION",	/* 0x002A */ 
	(char *)  	"CONSULT",	/* 0x002C */ 
	(char *)	",,,,,,,",	/* Old Collect */
	(char *)  	"COLLECT",	/* 0x002D */
#ifdef	ABALSQL
	(char *) 	"SELECT",	/* 0x002E */
	(char *)	"PREPARE",	/* 0x002F */
	(char *)	"FETCH",	/* 0x0030 */
	(char *)	"EXEC",		/* 0x0031 */
	(char *)	"KEYTYPE",	/* 0x0032 */
	(char *)	"LINKNAME",	/* 0x0033 */
	(char *)	"FILEUSER",	/* 0x0034 */
#endif
	(char *) 0
	};

	/* ---------- */
#endif	/* _abalngf_h */
	/* ---------- */


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
#define		_NGF_RUBBISH		0x002B
#define		_NGF_CONSULT		0x002C
#define		_NGF_COLLECT		0x002D

/*	SQL Extensions			*/
/*	--------------			*/
#ifdef	ABALSQL
#define		_NGF_SELECT		0x002E
#define		_NGF_PREPARE		0x002F
#define		_NGF_FETCH		0x0030
#define		_NGF_EXEC		0x0031
#define		_NGF_KEYTYPE		0x0032
#define		_NGF_LINKNAME		0x0033
#define		_NGF_FILEUSER		0x0034

#endif


