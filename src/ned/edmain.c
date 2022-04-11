#ifndef	_edmain_c
#define	_edmain_c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "ed.h"
#include "edmsg.h"
#include "ednoy.h"
#include <signal.h>
#ifndef	UNIX
#include "allocate.c"
#endif

#ifndef	VERSION666
static  char	VersionStatus[16]=
	{ 'V','E','R','S','I','O','N','_','S','T','A','T','U','S',':','2' };
static	char 	LaPaterne[20] = { '*','P','R','L','@','I','N','F','O','*','#',6,ved,ied,red,'0','0','3',0 };
#else
static  char	VersionStatus[16]=
	{ 'V','E','R','S','I','O','N','_','S','T','A','T','U','S',':','2' };
static	char 	LaPaterne[20] = { '*','P','R','L','@','I','N','F','O','*','#',6,ved,ied,red,'0','0','3',0 };
#endif
static	char *	LaPointeur=(char*)0;
static	char 	LaVersion[10];

#include "edmouse.c"
#include "edbann.c"
#include "edstub.c"

int	panic(int s)
{
	if ( s == SIGKILL )	
		s = SIGTERM;
	else if ((txtchg) &&  (!( confirme_lose() ))) return(1);
	editorOnQuit();
	editorOnHide();
	editorOnRemove();
	exit(s);
	return(1);
}

int	control_fork()			{	return(fork());	}
void	system_failure( char * mptr)	{	return;		}
int	test_initialise_hardware()	{	return(1);	}

/*
 *	M A I N ( argc, argv )
 *	----------------------
 *
 *	AED startup with command line from system shell or prompt.
 *
 */

extern	int UseEdMain;
int	main(int argc, BYTE XPTR  argv[])
{					/* main */
	ChnFic	*p,*q;
	BYTE comtmp[255];
	BYTE XPTR paed;
	SWORD	argi;
	BYTE XPTR argp;


	if (Xsetjmp(Ed_Exit) != 0) {
		return( editorOnRemove(0) );
		}
	else	UseEdMain=UseEdExit = 1;

	switch ( editorOnCreate(argc, argv ) ) {
		case	0 : 
			banniere();
			return( editorOnRemove(1) ); 
		case   -1 : return( editorOnRemove(0) ); /* failure */
		}
	initialise_editor_mouse();
	editorOnMain();
	(void) editorOnShow();
	(void) editorOnExec();
	(void) editorOnHide();
	terminate_editor_mouse();

	return( editorOnRemove(1) );

}

#endif	/* _edmain_c */

