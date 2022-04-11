/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1990 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBAFUN - H				*/
/*		Date 	:	01/02/1990				*/
/*		Version :	1.4a 					*/
/*									*/
/*----------------------------------------------------------------------*/
/* This module Contains the Prototype of functions for ASFUN usage	*/
/*----------------------------------------------------------------------*/
#ifndef	EXDBAFUNH
#define	EXDBAFUNH

/*	ASFUN	FONCTIONS FENETRES	*/
/*	-----	------------------	*/
#ifndef	UNIX
EXAWORD	asfun_winit( EXABYTE , EXABYTE , EXABYTE , EXABYTE , EXABYTE );
EXAWORD	asfun_wcreat( );
VOID	asfun_wsup( );
EXAWORD	asfun_wselect( EXAWORD );
EXAWORD 	asfun_winv( EXAWORD );
EXAWORD 	asfun_wvis( EXAWORD );
EXAWORD 	asfun_wwrite( EXAWORD , EXAWORD , BPTR );
EXAWORD 	asfun_wfgen( EXAWORD , EXAWORD );
EXAWORD 	asfun_wposcur( EXAWORD , EXAWORD , EXAWORD );
EXAWORD 	asfun_watb( EXAWORD , EXABYTE , EXABYTE , EXABYTE );
EXAWORD 	asfun_wimpl( EXAWORD );
EXAWORD 	asfun_wgel( EXAWORD );
EXAWORD 	asfun_wsetatb(EXAWORD,EXABYTE,EXABYTE,EXABYTE,EXAWORD,EXAWORD,EXAWORD,EXAWORD);
EXAWORD	asfun_wfend();
EXAWORD	asfun_dbactive();
#else
EXAWORD	asfun_winit();
EXAWORD	asfun_wcreat();
VOID	asfun_wsup();
EXAWORD	asfun_wselect();
EXAWORD 	asfun_winv();
EXAWORD 	asfun_wvis();
EXAWORD 	asfun_wwrite();
EXAWORD 	asfun_wfgen();
EXAWORD 	asfun_wposcur();
EXAWORD 	asfun_watb();
EXAWORD 	asfun_wimpl();
EXAWORD 	asfun_wgel();
EXAWORD 	asfun_wsetatb();
EXAWORD	asfun_wfend();
EXAWORD	asfun_dbactive();
#endif

#endif	/* ! EXDBAFUNH */
	/* ----------- */


