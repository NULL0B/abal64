/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRJVMSG.C				*/
/*		Version :	2.1d					*/
/*		Date	:	26/01/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRJVMSG_C
#define	_TRJVMSG_C

#include "stdtypes.h"

#ifndef WIN32
#define	TalkWork initialise_text_messages
#define TalkPtr  message_text
#endif

#include "trabmsg.h"
#include "trmsg.h"

static int	TalkInited;

VOID TalkWork()
{
	WORD   x=0;

	BPTR   wptr=(BPTR)l0msg0000;

	if (TalkInited)
		return;

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
	
	TalkInited = 1;	/* WIN32 */

	return;
}

BPTR	imessage_text( nb )
WORD	nb;
{
	if (!TalkInited)
		TalkWork();
	return((BPTR) message_text[ nb ] );
}

#endif	/* _TRJVMSG_C */
	/* ---------- */


