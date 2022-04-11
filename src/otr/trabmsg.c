/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 2003 Amenesik / Sologic  		*/
/*									*/
/*									*/
/*		File	:	TRABMSG.C				*/
/*		Version :	2.1d					*/
/*		Date	:	26/01/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRABMSG_C
#define	_TRABMSG_C

#include "stdtypes.h"

#ifdef UNIX
#define	TalkWork initialise_text_messages
#define TalkPtr  message_text
#endif

#include "trabmsg.h"
#include "trmsg.h"

static int	TalkInited;

/*	--------	*/
/*	TalkWork	*/
/*	--------	*/
VOID TalkWork()
{
	WORD   x=0;

	BPTR   wptr=(BPTR)l0msg0000;

	if (TalkInited)
		return;

#ifndef WIN32
	switch ( cico_message_language() ) 
	{
	case	0	: 
		wptr = (BPTR) l0stx;
		break;
	case	1	:
		wptr = (BPTR) l1stx;
		break;
	default		:
		if   ( *(wptr + 2) == '0' )
			wptr   = (BPTR) l0stx;
		else	wptr = (BPTR) l1stx;
		break;
	}
#else
	if   ( *(wptr + 2) == '0' ) 
	{
		wptr   = (BPTR) l0stx;
		IsFrench = 1;
	}
	else 
	{
		wptr = (BPTR) l1stx;
		IsFrench = 0;
	}
#endif

	for  (;x < MSGQTY;x++) 
	{
		while   ( *wptr ) wptr++;
		while   (!(*wptr) ) wptr++;
		TalkPtr[x] = wptr;
	}
	TalkInited = 1;	

	return;
}

/*	-------------	*/
/*	imessage_text	*/
/*	-------------	*/
BPTR	imessage_text( nb )
WORD	nb;
{
	if (!(TalkInited))
		TalkWork();

	return((BPTR) message_text[ nb ] );
}

	/* ---------- */
#endif	/* _TRABMSG_C */
	/* ---------- */
