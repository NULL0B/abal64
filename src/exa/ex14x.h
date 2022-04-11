#ifndef	MSG_HX

/*	Messages d'identification EXA ou EXADB		*/
/*	--------------------------------------		*/

#define	MSGERREUR	13

#include "exmsgfr.h"
#include "exmsguk.h"

BPTR	TalkPtr[MSGQTY];

void	TalkWork()
{
	EXAWORD	x;
	BPTR	wptr;

	wptr = (BPTR) OuiNon;
	if (*(wptr +2) == '0' )
		wptr = (BPTR) debgesmes;
	else	wptr = (BPTR) begmesman;

	x = 0;
	do	{
		while ( *wptr != (EXABYTE) 0 ) { wptr++; }
		while ( *wptr == (EXABYTE) 0 ) { wptr++; }
		TalkPtr[x++] = (BPTR) wptr;
		}
	while ( x < MSGQTY );
	return;
}

#else

#include "exmsg.c"

#endif
