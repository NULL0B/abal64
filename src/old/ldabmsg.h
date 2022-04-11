/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Linker			*/
/*									*/
/*		 Copyright (c) 1990, 2003 Amenesik / Sologic  			*/
/*									*/
/*									*/
/*		File	:	LDABMSG.H					*/
/*		Version :	3.0a					*/
/*		Date	:	18/01/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_LDABMSG_H
#define	_LDABMSG_H

#define	TalkWork initialise_text_messages
#define	TalkPtr  message_text

VOID	TalkWork( VOID );
BPTR	imessage_text( WORD );

#endif	/* _LDABMSG_H */
	/* -------- */
