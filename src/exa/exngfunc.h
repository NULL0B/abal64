/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXWORK.H  				*/
/*		Date 	:	12/11/1992				*/
/*		Version :	1.4c / 2.1a				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXNGFUNC_H
#define	_EXNGFUNC_H

/*	NGF Function Prototypes		*/
/*	-----------------------		*/

EXAWORD ngf_assign( EXAWORD, BPTR, EXAWORD, EXAWORD, BPTR, EXAWORD, EXAWORD );


/*	NGF Macros			*/
/*	----------			*/

#define	assign_printer(h,n,l) ngf_assign( h,n,l,0x0057,(BPTR) 0, 0, 0)




	/* ----------- */
#endif	/* _EXNGFUNC_H */
	/* ----------- */

