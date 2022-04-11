/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXATROPT.H				*/
/*		Date 	:	03/02/1993				*/
/*		Version :	1.4c / 2.1a				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXATROPT_H
#define	_EXATROPT_H

/*	Options de traduction	*/
/*	---------------------	*/

#define		EXOPT_DEBUG	0x0001	/* T-Code Contains Symbolic Infos */
#define		EXOPT_CLEAR	0x0002	/* Clear Screen on Entry  	  */
#define		EXOPT_AFLUSH	0x0004	/* Flush Keyboard on Entry	  */
#define		EXOPT_BFLUSH	0x0008	/* BAL 1 char exit flush OFF	  */
#define		EXOPT_CFLUSH	0x0010	/* Flush Keyboard on Exit	  */
#define		EXOPT_BAL    	0x0020	/* Segment Local Variables Static */
#define		EXOPT_OPTIMISE	0x0040	/* T-Code has been optimised	  */

#ifdef	ABAL21

/*	-----------------------------------------------------------	*/
/*	Suplimentary translation options : Header offset 86 decimal	*/
/*	-----------------------------------------------------------	*/

#define		EXOPT_VALIDPTR	0x0001	/* Validate pointer usage	*/
#define		EXOPT_REMOVEALL 0x0002	/* Liberate all useage of PTR	*/
#define		EXOPT_NOINITE   0x0004	/* Do not initialise ETENDU  	*/

	/* ------ */
#endif	/* ABAL21 */
	/* ------ */

#endif	/* _EXATROPT_H */
	/* ----------- */
