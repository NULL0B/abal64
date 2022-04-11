/*
 *	Copyright (c) 1990 Amenesik / Sologic s.a.
 *	--------------------------------
 *
 *	Messages compatibles GESMES pour GENMAKE
 *	----------------------------------------
 *
 *	01/04/1991	Version 1.1b
 *	----------	------------
 */

#ifdef	OLD_MESSAGES

#define	MSGQTY	55
#include "gmmsgfr.h"
#include "gmmsguk.h"
BPTR	TalkPtr[MSGQTY];
VOID	TalkWork()
{
	INT	x,y;
	BPTR	wptr;
#ifndef MSG_HX
	wptr = (BPTR) OuiNon;
	switch ( cico_message_language() ) {
		case	0	: wptr = (BPTR) DebGesMan; break;
		case	1	: wptr = (BPTR) BegMesMan; break;
		default		:
			if (*(wptr + 2) == '0')
				wptr = (BPTR) DebGesMan;
			else	wptr = (BPTR) BegMesMan;
			break;
		}
#else
	wptr = (BPTR) OuiNon;
	switch ( cico_message_language() ) {
		case	0	: wptr = (BPTR) gmparl; break;
		case	1	: wptr = (BPTR) gmtalk; break;
		default		:
			if (*(wptr + 2) == '0')
				wptr = (BPTR) gmparl;
			else	wptr = (BPTR) gmtalk;
			break;
		}
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
#else
#include "gm21x.h"
#endif



