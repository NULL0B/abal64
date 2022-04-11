/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1994 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBFKEY.H				*/
/*		Date 	:	09/06/1994				*/
/*		Version :	1.4e / 2.1c				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXDBFKEY_H
#define	_EXDBFKEY_H

#define	PGMFKEYPTR struct program_function_key XPTR

struct	program_function_key {
	EXABYTE		buffer[48];
	EXAWORD		length;
	PGMFKEYPTR	next;
	};

struct	program_function_keys {
	EXAWORD		keycount;
	PGMFKEYPTR	keylist;
	};

#endif	/* _EXDBFKEY_H */
	/* ----------- */

