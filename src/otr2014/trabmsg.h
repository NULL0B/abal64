/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 2003 Amenesik / Sologic  		*/
/*									*/
/*									*/
/*		File	:	TRABMSG.H				*/
/*		Version :	2.1d					*/
/*		Date	:	18/01/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRABMSG_H
#define	_TRABMSG_H

#define	TalkWork initialise_text_messages	
#define	TalkPtr  message_text			

VOID	TalkWork( VOID );
BPTR	imessage_text( WORD );

#endif	/* _TRABMSG_H */
	/* -------- */
