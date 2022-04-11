/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL++ : Project Maintanance 			*/
/*		----------------------------------			*/
/*									*/
/*		  Copyright (c) 1991, 1993 Amenesik / Sologic s.a.		*/
/*		  ------------------------ -------------		*/
/*									*/
/*		File	:	UTGESMES.C				*/
/*		Version :	2.1a					*/
/*		Date	:	18/08/1993				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifdef	OLD_MESSAGES

#define	MSGQTY	28

#include "stdtypes.h"
#include "utmsgfr.h"
#include "utmsguk.h"

BPTR	TalkPtr[MSGQTY];


VOID	TalkWork()
{
	INT	x,y;
	BPTR	wptr;
#ifndef MSG_HX
	wptr = (BPTR) OuiNon;
	switch ( cico_message_language() ) {
		case	0	: wptr = (BPTR) DebGesMes; break;
		case	1	: wptr = (BPTR) BegMesMan; break;
		default		:
			if (*(wptr + 2) == '0')
				wptr = (BPTR) DebGesMes;
			else	wptr = (BPTR) BegMesMan;
			break;
		}
#else
	wptr = (BPTR) OuiNon;
	switch ( cico_message_language() ) {
		case	0	: wptr = (BPTR) UTPARL; break;
		case	1	: wptr = (BPTR) UTTALK; break;
		default		:
			if (*(wptr + 2) == '0')
				wptr = (BPTR) UTPARL;
			else	wptr = (BPTR) UTTALK;
			break;
		}
#endif
	x = 0;
	do	{
		while ( *wptr != (CHAR) 0 ) { wptr++; }
		while ( *wptr == (CHAR) 0 ) { wptr++; }
		TalkPtr[x++] = (BPTR) wptr;
		}
	while ( x < MSGQTY );
	return;
}

#else
#include "stdtypes.h"
#include "ut21x.h"
#endif

