/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXADBDEF - H				*/
/*		Version :	1.4a					*/
/*		Date 	:	20/12/1990				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	EXADBDEFH		/* If not already included		*/
#define EXADBDEFH		/* Avoid multiple inclusions		*/
				/* ------------------------------------ */

#define		IDB_ASM		0x0001		/* Assembleur Liste	*/
#define		IDB_TALK	0x0002		/* Dialogue Mode	*/
#define		IDB_LID		0x0004		/* Liste Extension	*/
#define		IDB_MID		0x0008		/* Map Extension	*/

#ifdef  VMS
/*	The list file is in STREAM-LF format which requires EX		*/
/*	------------------------------------------------------		*/
#define MPOSTE
#define	XO_LISTE	2			/* Open Arg : EX ! WR	*/
#define	XC_LISTE	2			/* cree Arg : EX ! WR	*/
#endif

#ifdef	PROLOGUE
/*	The list file may be shared by several processes		*/
/*	------------------------------------------------		*/
#define	XO_LISTE	0			/* Open Arg : ! EX ! WR	*/
#define	XC_LISTE	0			/* cree Arg : ! EX ! WR	*/
#endif

#ifndef	PROLOGUE
#ifndef	VMS
#define	XO_LISTE	(O_BINARY | O_RDONLY)	/* Open Arg : ReadOnly 	    */
#define	XC_LISTE	0666			/* cree Arg : Comme il peut */
#endif
#endif

#endif	/* ! EXADBDEFH */
	/* ----------- */

