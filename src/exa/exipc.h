/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXIPC - H				*/
/*		Date 	:	07.07.1988				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifdef UNIX
#include	<sys/ipc.h>
#include	<sys/msg.h>
#endif
#ifdef PROLOGUE
#include	"msg.h"
#endif
struct	talkzone {
	long		abalds;		/* Message ID Destinataire 	*/
	long		abalid;		/* This value takes a different */
					/* meaning wrt SEND or RECV	*/
					/* Send :			*/
					/* indicates the message ID to  */
					/* be used by the user module   */
					/* to return the message answer	*/
					/* Recieve :			*/
					/* Original message ID number	*/
	short int	abaler; 	/* Erreur MODULE User		*/
	EXABYTE		abaltx[2];	/* Actual Message zone		*/
};
