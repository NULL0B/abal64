/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		  Copyright (c) 1989,1991 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	AOGESMES.C  				*/
/*		Version :	1.4a					*/
/*		Date	:	24/09/1991				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_AOGESMES_C
#define	_AOGESMES_C


#ifdef	_AO_C

#ifdef	OLD_MESSAGES
#define	MSGQTY	38
#include "aomsgfr.h"
#include "aomsguk.h"
BPTR	TalkPtr[MSGQTY];
void	TalkWork()
{
	int	x,y;
	BPTR	wptr;
#ifndef MSG_HX
	wptr = (BPTR) OuiNon;
	if ( *(OuiNon + 2) == '0' )
		wptr = (BPTR) DebGesMes;
	else	wptr = (BPTR) BegMesMan;
#else
	wptr = (BPTR) OuiNon;
	if ( *(OuiNon + 2) == '0' )
		wptr = (BPTR) aoparl;
	else	wptr = (BPTR) aotalk;
#endif

	x = 0;
	do	{
		while ( *wptr != (char) 0 ) { wptr++; }
		while ( *wptr == (char) 0 ) { wptr++; }
		TalkPtr[x++] = (BPTR) wptr;
		}
	while ( x < MSGQTY );
	return;
}

#else	/* NEW_MESSAGES */
#include "ao21x.h"
#endif

#else	/* ! _AO_C */
	/* ------- */

extern	BPTR	TalkPtr[1];

#endif


#endif	/* _AOGESMES_C */
	/* ----------- */

