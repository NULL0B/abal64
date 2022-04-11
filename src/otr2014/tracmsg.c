/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRACMSG.C				*/
/*		Version :	2.1d					*/
/*		Date	:	26/01/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRACMSG_C
#define	_TRCBMSG_C

#include "stdtypes.h"
#include "trmsg.h"

#define	TalkWork initialise_text_messages
#define TalkPtr  message_text

#include "atc21x.h"	/* New generated message file */

BPTR	imessage_text( nb )
WORD	nb;
{
	return((BPTR) message_text[ nb ] );
}

#endif	/* _TRACMSG_C */
	/* ---------- */

