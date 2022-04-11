/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1990 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXRDEF - H				*/
/*		Version : 	1.2d					*/
/*		Date 	:	20/03/1990				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	EXRDEFH
#define	EXRDEFH

/*	Gestion de la Memoire et des Chaines de caracteres		*/
/*	--------------------------------------------------		*/

#ifndef WIN32
#define		malloc(Xarg1) 			Mmalloc(Xarg1)
#define		free(Xarg1) 			Mfree(Xarg1)
#define		calloc(Xarg1,Xarg2) 		Mcalloc(Xarg1,Xarg2)
#define		memcpy(Xarg1,Xarg2,Xarg3) 	Mmemcpy(Xarg1,Xarg2,Xarg3)
#define		memcmp(Xarg1,Xarg2,Xarg3) 	Mmemcmp(Xarg1,Xarg2,Xarg3)
#define		memset(Xarg1,Xarg2,Xarg3) 	Mmemset(Xarg1,Xarg2,Xarg3)
#define		strlen(Xarg1) 			Mstrlen(Xarg1)
#endif  /* ! WIN32 */


/*	Gestion des variables d'environnement		*/
/*	-------------------------------------		*/

#ifndef	UNIX
#ifndef	VMS
#define		getenv(Xarg1)			Mgetenv(Xarg1)
#endif
#endif

	/* ------- */
#endif	/* EXRDEFH */
	/* ------- */

