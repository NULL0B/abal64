/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Linker			*/
/*									*/
/*		 Copyright (c) 1990, 2003 Amenesik / Sologic  			*/
/*									*/
/*									*/
/*		File	:	LDABMSG.C				*/
/*		Version :	3.0a					*/
/*		Date	:	15/09/03				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_LDABMSG_C
#define	_LDABMSG_C

#include <stdio.h>
#include "ldmain.h"

#include "ldabmsg.h"
#include "ldmsg.h"

static int	TalkInited;

VOID TalkWork()
{
	WORD   x=0;

	BPTR   wptr=(BPTR)l0msg0000;

	switch ( cico_message_language() ) {
		case	0	: 
			wptr = (BPTR) l0stx;
#ifdef	WIN32
			IsFrench = 1;
#endif
			break;
		case	1	:
			wptr = (BPTR) l1stx;
#ifdef	WIN32
			IsFrench = 0;
#endif
			break;
		default		:
			if (*(wptr + 2) == '0') {
				wptr = (BPTR) l0stx;
#ifdef	WIN32
				IsFrench = 1;
#endif
				}
			else	{
				wptr = (BPTR) l1stx;
#ifdef	WIN32
				IsFrench = 0;
#endif
				}
			break;
		}
	for  (;x < MSGQTY;x++) {
		while   ( *wptr ) wptr++;
		while   (!(*wptr) ) wptr++;
		TalkPtr[x] = wptr;
	}

return  ;
}

BPTR	imessage_text( nb )
WORD	nb;
{
	if (!TalkInited)
		TalkWork();

	return((BPTR) message_text[ nb ] );
}

#endif	/* _LDABMSG_C */
	/* ---------- */
