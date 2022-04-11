/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Project Maintanance 			*/
/*		----------------------------------			*/
/*									*/
/*		  Copyright (c) 1993 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	AMAKE.H   				*/
/*		Version :	1.4c / 2.1a				*/
/*		Date	:	02/06/1993				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_AMAKE_H
#define	_AMAKE_H

/*
 *	Make File structure limit constants
 *	-----------------------------------
 *
 */

#define	STAKMAX	25
#define	RULEMAX	50
#define	MAXFIC	40
#define	MAXACT	5
#define	FINLYN	0x0027
#define	ARGMAX	25


#define	ARBRE	struct Arbre XPTR
#define	CONSTREE struct Constant XPTR
#define	LINKLIST struct LinkList XPTR
#define	RULETREE struct Rules XPTR

/*	Macro / Constants / Variables management structure	*/
/*	--------------------------------------------------	*/
struct Constant {
	BPTR name;
	BPTR value;
	CONSTREE suite;
	};

/*	File management tree structure		*/
/*	------------------------------		*/
struct	Arbre {
	BPTR	Nom;
	ARBRE	suite;
	LONG	filetime;
	};

struct	LinkList {
	BPTR		value;
	LINKLIST 	suite;
	};

/*	Makefile rules structure	*/
/*	------------------------	*/
struct	Rules {
	BPTR		Nom;
	BPTR		MakeFile;
	LINKLIST	Depend;
	LINKLIST	Action;
	RULETREE	suite;
	int		Status;
	int		Linecount;
	};

/*	Makefile source stream management	*/
/*	---------------------------------	*/
struct	Makegard {
	int	numlog;
	int	sector;
	int	indent;
	int	limit;
	int     lignes;
	BYTE	buffer[256];
	BYTE	filename[128];
	};

/*	Makefile inclusion context management 	*/
/*	-------------------------------------	*/
struct	Context {
	struct  Makegard XPTR FileKeep;
	struct	Context XPTR  FileNext;
	};

/*	Amake options internal representation value constants	*/
/*	-----------------------------------------------------	*/
#define _SILENCE 	0x0001	/* Silence is required		*/
#define	_INHIBIT_ACTION	0x0002	/* Display but do not execute	*/
#define	_IGNORE_ERRORS	0x0004	/* Ignore invocation errors	*/
#define	_PREPROCESS	0x0008	/* Preprocess to stdout		*/
#define	_DEBUG_DATE	0x0010	/* Debug Target/Depend dates	*/
#define	_ENVIRON	0x0020	/* Environment then internal	*/
#define	_DEFAULT_SUFFIX	0x0040	/* Use default suffixes		*/
#define	_TOUCH_TARGET	0x0080	/* Touch if exist else exec	*/
#define	_VERIFICATION	0x0100	/* Verification only		*/
#define	_FORCE_REBUILD	0x0200	/* Rebuild all targets		*/

#ifdef	ABAL21
#define	_RETURN_TO_USER	0x0400	/* Return Error/Result to call	*/
#endif

#define	_TARGET_OK	0x1000	/* Target ok if source error	*/

#define	_INFERENCE	0x4000	/* Check default inferences	*/

#define	UNKNOWN	0		/* Unestablished Dependancy/Rule	*/
#define	WORKING	1		/* Dependancy under evaluation		*/
#define	KNOWN	2		/* Dependancy/Rule Established		*/
#define REBUILD 0		/* Rebuild this dependant Target	*/
#define MISSING 3		/* File Does not exist			*/
#define NOBUILD 1		/* Do not rebuild this target		*/
#define	HASH_MAX 17		/* Hash value for Hashing file names	*/

#ifdef	UNIX
#define	PARSER_BUFFER_SIZE	32000
#else
#define	PARSER_BUFFER_SIZE	2048
#endif

#define	DIMAX PARSER_BUFFER_SIZE

#endif	/* _AMAKE_H */
	/* -------- */
