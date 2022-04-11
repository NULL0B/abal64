#define	DEBUG
/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Linker			*/
/*									*/
/*		 Copyright (c) 1990, 2003 Amenesik / Sologic  			*/
/*									*/
/*									*/
/*		File	:	LDERRORS.H				*/
/*		Version :	3.0a					*/
/*		Date	:	15/09/03				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_LDERRORS_H
#define	_LDERRORS_H

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#include <string.h>		

#include "ldmain.h"
#include "lderrors.h"
#include "ldabmsg.h"

#ifdef WIN32
#include "woldmess.h"
#include "ldtrace.h"

extern int OptIdra;
#endif

BYTE		ErrorBuffer[256];

WORD	issue_error( nbmsg, mptr )
WORD	nbmsg;
BPTR	mptr;
{

#ifdef WIN32
   char Message[512];

	if (OptIdra) {
		sprintf(Message, "%s : %s", imessage_text(nbmsg), mptr);
		ctOutputErrorDiagnostic2(0, NULL, 0, 0, Message, NULL);
	}
	else {
		sprintf(Message, "\r\n%s : %s : %s", imessage_text(2), imessage_text(nbmsg), mptr);
		x_cprintf(Message);
	}
#else
	printf("%s: %s : %s\n", imessage_text(2), imessage_text(nbmsg), mptr);
#endif

	return(0);
}

WORD	issue_warning( nbmsg, mptr, level )
WORD	nbmsg;
BPTR	mptr;
WORD	level;
{

#ifdef WIN32
   char Message[512];

	if (OptIdra) {
		sprintf(Message, "%s : %s", imessage_text(nbmsg), mptr);
		ctOutputWarningDiagnostic2(level, NULL, 0, 0, Message, NULL);
	}
	else {
		sprintf(Message, "\r\n%s%u : %s : %s", imessage_text(3), level, imessage_text(nbmsg), mptr);
		x_cprintf(Message);
	}
#else
	printf("%s: %s : %s\n", imessage_text(3), imessage_text(nbmsg), mptr);
#endif

	return(0);
}

WORD	issue_message( nbmsg, mptr )
WORD	nbmsg;
BPTR	mptr;
{
#ifdef WIN32
	char Message[512];

	if (nbmsg)
		sprintf(Message, "%s : %s", imessage_text(nbmsg), mptr);
	else
		sprintf(Message, "\r\n%s", mptr);

	if (OptIdra)
		ctOutputMessageDiagnostic2(Message, NULL);
	else
		x_cprintf(Message);
#else
	if (nbmsg)
		printf("%s : %s\n", imessage_text(nbmsg), mptr);
	else
		printf("%s\n", mptr);
#endif

	return(0);
}


#endif 	/* _LDERRORS_H */
	/* ----------- */





