/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBCICO.H				*/
/*		Version :	2.1f      	  			*/
/*		Date 	:	30/01/1999				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXDBCICO_H
#define	_EXDBCICO_H

/*	-----------------------------------------------------------	*/
/*	REDIRECTION of STANDARD CICO FUNCTIONS to EXADB EQUIVALENTS	*/
/*	-----------------------------------------------------------	*/

#define		x_getch()	db_xgetch()
#ifndef	PROLOGUE
#define		exputch(c)	db_xputch(c)
#endif
#define		x_putch(c)	db_xputch(c)
#define		pos(x,y)	db_xpos(x,y)
#define		x_clear()	db_xclear()
#define		atb(x)		db_xatb(x)
#define		x_lin()		db_xlin()
#define		x_col()		db_xcol()
#define		foregr(f)	db_foregr(f)
#define		backgr(b)	db_backgr(b)

#ifdef WIN32
#undef initerm
#undef finterm
#endif

#define		initerm()	db_initerm()
#define		finterm(a)	db_finterm(a)
#define		x_cprintf(s)	db_xcprintf(s)

#endif	/* _EXDBCICO_H */
	/* ----------- */
