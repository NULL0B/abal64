/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1995 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXLDF.C   				*/
/*		Version :	2.1d           				*/
/*		Date 	:	09/03/1995				*/
/*									*/
/*----------------------------------------------------------------------*/
/*									*/
/*	Rewrite of EXLDF.C in order to allow dynamic libraries to 	*/
/*	be efficiently used in overlay objects.				*/
/*									*/
/*	Dynamic libraries are now to be managed in a centralised	*/
/*	manner by the executeur in order that the previously		*/
/*	shared library mechanism may be completed by a new private	*/
/*	library mechanism.						*/
/*									*/
/*	The following operations are required :				*/
/*									*/
/*		Libraries [PUBLIC/PRIVATE]  across CHAIN  operations	*/
/*		Libraries [PUBLIC/PRIVATE]  across LOADGO operations	*/
/*		Libraries [PUBLIC/PRIVATE]  across ATTACH operations	*/
/*									*/
/*	The terms PUBLIC and PRIVATE refer to the nature of the		*/
/*	library, BIBMATH is a LIBRARY and will react equally well	*/
/*	PUBLIC or PRIVATE. ASFUN is a SERVICE library and could well	*/
/*	be a shared resource accross programs (LOADGO/CHAIN/ATTACH)	*/
/*	IMAGEPCX is a STRICT hardware service and must be PUBLIC in	*/
/*	all cases.							*/
/*----------------------------------------------------------------------*/

#ifndef	_EXLDF_C
#define	_EXLDF_C

#include	"exldf.h"
#include 	"exptr.h"



#endif	/* _EXLDF_C */
	/* -------- */


