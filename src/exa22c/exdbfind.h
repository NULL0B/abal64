/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1994 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBFIND.H  				*/
/*		Date 	:	17/10/1994				*/
/*		Version :	2.1c					*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXDBFIND_H
#define	_EXDBFIND_H

#define	FINDPTR	struct exadb_finder XPTR

struct	finder_found	{
	EXAWORD	type;
	EXAWORD	block;
	EXAWORD	offset;
	};

struct	exadb_finder	{
	struct	finder_found 	selection;
	FINDPTR			next;
	FINDPTR			previous;
	};

VOID	find_correspondance( CORRESPTR  );

#endif	/* _EXDBFIND_H */
	/* ----------- */

