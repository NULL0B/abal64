/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXADB - H				*/
/*		Date 	:	30/01/1999				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	EXADBH		/* Avoid multpile inclusions			*/
#define	EXADBH		/* Define to permet multiple exclusion		*/

/*	Redefinition of CICO functions for DB Windowing			*/
/*	-----------------------------------------------			*/

#ifdef WIN32
#undef initerm
#undef finterm
#else
#define	x_putch( c )		db_xputch( c )
#define	x_cprintf( sptr )	db_xcprintf( sptr )
#endif

#define	initerm()		db_initerm()
#define	finterm(Arg1)		db_finterm(Arg1)
#define	pos(lno,cno)		db_xpos(lno,cno)
#define	atb( natb )		db_xatb( natb )
#define	x_lin()			db_xlin()
#define	x_col()			db_xcol()
#define	x_clear()		db_xclear()

#endif	/* EXADBH */
