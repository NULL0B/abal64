/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXATROPT.H				*/
/*		Date 	:	22/07/2008				*/
/*		Version :	3.2b       				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_TRATROPT_H
#define	_TRATROPT_H

/*	Options de traduction	*/
/*	---------------------	*/

#define		TROPT_DEBUG	0x0001	/* T-Code Contains Symbolic Infos */
#define		TROPT_CLEAR	0x0002	/* Clear Screen on Entry  	  */
#define		TROPT_AFLUSH	0x0004	/* Flush Keyboard on Entry	  */
#define		TROPT_BFLUSH	0x0008	/* BAL 1 char exit flush OFF	  */
#define		TROPT_CFLUSH	0x0010	/* Flush Keyboard on Exit	  */
#define		TROPT_BAL    	0x0020	/* Segment Local Variables Static */
#define		TROPT_OPTIMISE	0x0040	/* T-Code has been optimised	  */
#define		TROPT_SENSITIVE 0x0080	/* Case Sensitive Name Compare	  */

/*	-----------------------------------------------------------	*/
/*	Suplimentary translation options : Header offset 86 decimal	*/
/*	-----------------------------------------------------------	*/

#define		TROPT_VALIDPTR	0x0001	/* Validate pointer usage	*/
#define		TROPT_REMOVEALL 0x0002	/* Liberate all useage of PTR	*/
#define		TROPT_NOINITE   0x0004	/* Do not initialise ETENDU  	*/


#endif	/* _TRATROPT_H */
	/* ----------- */

