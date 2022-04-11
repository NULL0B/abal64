/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL++ : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1991, 1993 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	AGRMSG.C  				*/
/*		Version :	1.1a					*/
/*		Date	:	21/12/1993				*/
/*									*/
/* --------------------------------------------------------------------	*/

#ifndef	_AGRMSG_H
#define	_AGRMSG_H

#ifdef	OLD_MESSAGES
/*	--------------------------------------		*/
/*	'GESMES' Compatible message management 		*/
/*	--------------------------------------		*/

#define	MSGQTY	16

#include "agrfr.h"
#include "agruk.h"

BPTR	message_text[ MSGQTY + 2 ];

VOID	initialise_text_messages()
{
	int	x,y;
	BPTR	wptr;

#ifndef MSG_HX
	wptr = (BPTR) OuiNon;
	switch ( cico_message_language() ) {
		case	0	: wptr = (BPTR) FrDeb; break;
		case	1	: wptr = (BPTR) UkDebut; break;
		default		:
			if (*(wptr + 2) == '0')
				wptr = (BPTR) FrDeb;
			else	wptr = (BPTR) UkDebut;
			break;
		}
#else
	wptr = (BPTR) OuiNon;
	switch ( cico_message_language() ) {
		case	0	: wptr = (BPTR) FR_TALK; break;
		case	1	: wptr = (BPTR) UK_TALK; break;
		default		:
			if (*(wptr + 2) == '0')
				wptr = (BPTR) FR_TALK;
			else	wptr = (BPTR) UK_TALK;
			break;
		}
#endif

	x = 0;
	do	{
		while (  *wptr ) wptr++;
		while (!(*wptr)) wptr++;
		message_text[x++] = (BPTR) wptr;
		}
	while ( x < (MSGQTY+2) );
	return;
}
#else	/* NEW_MESSAGES */
#define	TalkPtr message_text
#define TalkWork initialise_text_messages
#include "agr21x.h"
#endif

BPTR	natmsg( nb )
WORD	nb;
{
	return((BPTR) message_text[ nb ] );
}

#endif	/* _AGRMSG_H */
	/* --------- */
