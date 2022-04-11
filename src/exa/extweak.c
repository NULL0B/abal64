/*----------------------------------------------------------------------*/
/*                                                                      */
/*	E X E C U T E U R    A . B . A . L                                   */
/*	-------------------------------------                                */
/*                                                                      */
/*		Copyright (c) 2006 Amenesik / Sologic S.A.                                  */
/*                                                                      */
/*	   Module  :	extweak.c                                             */
/*	   Date 	:	16/09/2005                                               */
/*                                                                      */
/*----------------------------------------------------------------------*/
#ifndef	_EXTWEAK_C
#define	_EXTWEAK_C

#include "extrace.h"

#define  _PRN_ORIEN		10
#define  _PRN_ALIGN		11
#define  _PRN_FORMAT		12
#define  _PRN_DPI			13


EXAWORD	tweak( EXAWORD item, BPTR buffer, EXAWORD buflen )
{
EXAWORD status;

	switch ( item ) 
		{
		case 1: /*essai ecriture*/
			memcpy(buffer,"coucou",buflen);
			break;

		case  _PRN_ORIEN :
		case  _PRN_ALIGN :
		case  _PRN_FORMAT :
		case  _PRN_DPI :
#ifdef UNIX		
			/* Réservés Windows */
			err_val = 56;
			return( SOFTERROR );
#endif			
			break;
		}

return( GOODRESULT );
}

#endif	/* _EXTWEAK_C */

