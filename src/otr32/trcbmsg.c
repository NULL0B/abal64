/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRCBMSG.C				*/
/*		Version :	2.1d					*/
/*		Date	:	26/01/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRCBMSG_C
#define	_TRCBMSG_C

#include "stdtypes.h"

#define	TalkWork initialise_text_messages
#define TalkPtr  message_text

#include "ctr21x.h"	/* New generated message file */
#include "trmsg.h"

BPTR	imessage_text( nb )
WORD	nb;
{
	return((BPTR) message_text[ nb ] );
}

#endif	/* _TRCBMSG_C */
	/* ---------- */

