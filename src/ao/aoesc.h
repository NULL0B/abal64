/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic S.A.		*/
/*									*/
/*		Module  :	EXESC - H				*/
/*		Date 	:	02/09/1988				*/
/*									*/
/*----------------------------------------------------------------------*/
/*	Extended tcodes for Speed optimisations				*/
/*----------------------------------------------------------------------*/

#define	_Esc_VPTG	0x10	/* Establish Local  Pointer N or $ or # or % */
#define	_Esc_VPTL	0x11	/* Establish Global Pointer N or $ or # or % */

#define	_Esc_LDGC	0x20	/* Load 8 bit integer from Global data	*/
#define	_Esc_LDLC	0x21	/* Load 8 bit integer from Local data 	*/
#define	_Esc_LDGI	0x22	/* Load 16 bit integer from Global data	*/
#define	_Esc_LDLI	0x23	/* Load 16 bit integer from Local data 	*/

#define	_Esc_STGI	0x42	/* Store Register to Global integer	*/
#define	_Esc_STLI	0x43	/* Store Register to Local Integer	*/

#ifdef	VERSION666
#include "aotclong.h"
#endif


