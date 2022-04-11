/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXESC - H				*/
/*		Version :	1.2d / 1.3a / 1.5a 			*/
/*		Date 	:	05/19/1992				*/
/*									*/
/*----------------------------------------------------------------------*/
/*	Extended tcodes for Speed optimisations				*/
/*----------------------------------------------------------------------*/
#ifndef	EXESCH
#define EXESCH

#define	_Esc_VPTG	0x10	/* Establish Local  Pointer N or $ or # or % */
#define	_Esc_VPTL	0x11	/* Establish Global Pointer N or $ or # or % */

#define	_Esc_LDGC	0x20	/* Load 8 bit integer from Global data	*/
#define	_Esc_LDLC	0x21	/* Load 8 bit integer from Local data 	*/
#define	_Esc_LDGI	0x22	/* Load 16 bit integer from Global data	*/
#define	_Esc_LDLI	0x23	/* Load 16 bit integer from Local data 	*/

#define	_Esc_STGI	0x42	/* Store Register to Global integer	*/
#define	_Esc_STLI	0x43	/* Store Register to Local Integer	*/

#ifdef ABAL32A
#define	_Esc_SPAWN	0x01	/* Creation of Parallel Process		*/
#define	_Esc_LIBER	0x02	/* Liberation of Parallel Process	*/
#endif

#ifdef	ABAL21
#define	_Esc_RTI	0x28	/* Return Error Integer value		*/
#define	_Esc_RTV	0x2C	/* Return Error Variable		*/
#define	_Esc_RTR	0x2E	/* Return Error via Register		*/
#define	_Esc_SGW 	0x70	/* Ldgo.Seg EXAWORD			*/
#define	_Esc_ETP	0x47	/* End.Proc				*/
#endif

#ifdef	VERSION666
#include "extclong.h"
#endif

#endif	/* ! EXESCH */
	/* -------- */


