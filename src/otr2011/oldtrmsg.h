/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRMSG.H					*/
/*		Version :	2.1d					*/
/*		Date	:	18/01/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRMSG_H
#define	_TRMSG_H

#define	imessage_text(a) otr_message_text(a)
#define initialise_text_messages initialise_otr_messages

#ifndef	UNIX
BPTR	imessage_text( WORD );
#else
BPTR	otr_message_text();
#endif	/* UNIX */

#endif	/* _TRMSG_H */
	/* -------- */
