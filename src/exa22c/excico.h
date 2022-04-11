/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1990 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXHEAD - C				*/
/*		Date 	:	22/08/1990				*/
/*		Version :	1.4a					*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXCICO_H
#define	_EXCICO_H

/*	------------------------------------------			*/
/*	Communication variables for CICO interface			*/
/*	------------------------------------------			*/
#include "abalcico.h"

#ifdef	ABAL21
#ifndef	DEBUGGER
#define	x_getch() mimo_getch()
#define	x_kbhit() mimo_kbhit()
/* #define	opb()	  mimo_kbhit() */
#else
EXAWORD	mimo_getch();
EXAWORD	mimo_kbhit();
/* #define	opb()	  mimo_kbhit() */
#endif
#endif

/*	----------------------------------- ------------------------	*/
/*	CICO function prototype definitions (PRLCICO,IXCICO,DOSCICO)	*/
/*	----------------------------------- ------------------------	*/
#ifndef	_EXPROTO_H
EXAWORD		x_kbhit();	/* Test for keyboard hard int	*/
EXAWORD		x_getch();	/* Wait for keyboard character	*/
EXAWORD		conf();		/* Collect system configuration	*/
EXAWORD		x_col();	/* Collect current column value	*/
EXAWORD		x_lin();	/* Collect current line value	*/
VOID		x_putch();	/* Output character via CICO	*/
VOID		x_cprintf();	/* Output string via CICO	*/
VOID		pos();		/* Position curser		*/
VOID		backgr();	/* Establish background colour	*/
VOID		foregr();	/* Establish foreground colour	*/
VOID		x_atb();	/* Establish screen atribut	*/ 
#ifdef	WIN32
#define	initerm E_initerm
#define	finterm E_finterm
VOID		initerm(void);	/* Initialise CICO subsystem	*/
VOID		finterm(EXAWORD);	/* Liberate CICO subsystem	*/
#else
VOID		initerm();	/* Initialise CICO subsystem	*/
VOID		finterm();	/* Liberate CICO subsystem	*/
#endif
VOID		modterm();	/* Pre-init modify CICO state	*/
EXAWORD		x_redir();	/* Redirect CICO to user	*/
VOID		x_bstart();	/* Start output bufferisation	*/
VOID		x_bflush();	/* Commit output bufferisation	*/
EXAWORD		lcfo();		/* Read function key value	*/
EXAWORD		prfo();		/* Establish function key value	*/
#endif	/* _EXPROTO_H */

#endif	/* _EXCICO_H */
	/* --------- */
