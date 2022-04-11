/* -------------------------------------------------------------------- */
/* 									*/
/* 	Project :	ABAL PROJECT MAINTENANCE			*/
/* 			------------------------			*/
/* 									*/
/* 	File    :	SYSTEMD.C					*/
/* 	Date    :	01/03/1990					*/
/* 	Version :	1.4a      					*/
/* 	Auther  :	I.J.Marshall					*/
/* 									*/
/* -------------------------------------------------------------------- */

#ifdef	UNIX
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h> 
#endif

#include "systemd.h"

struct	LocalWindow {
	WORD TopLine;
	WORD BottomLine;
	WORD nbline;
	WORD nbcolumn;
	WORD LastLine;
	WORD LastColumn;
	} ScreenContext;

#ifdef	UNIX
WORD	systemr()
{
	return(0);
}

WORD	systeme( cmdptr )
BPTR	cmdptr;
{
	return( system( cmdptr ) );
}
#endif

void	Position(WORD  c, WORD l)
{
	x_putch(0x001B); 	x_putch('f');
	x_putch(0x001F+c);	x_putch(0x001F+l);
	return;
}

#ifndef	PRL

#define	_STREAM_CICO	0
#define	_STREAM_UNKNOWN	1
#define	_STREAM_SYSTEM	2

WORD	StreamStatus;
BYTE	TestPattern[9];
BYTE	RecvPattern[9];
WORD	RecvIndex;

struct	cico_status {
	VOID	(*signal)();
	WORD	started;
	WORD	escape_f;
	WORD	escape_count;
	WORD	escape_flag;
	} cico = {
		0,0,0,0,0
		};

#ifndef	UNIX
void	CicoOutPut( BYTE );
#else
void	CicoOutPut();
#endif

void	StreamIdentityCico()
{
	StreamStatus  = _STREAM_CICO;
	cico.started  = 0;
	cico.escape_f = 0;
	cico.escape_flag = 0;
	cico.escape_count = 0;
	return;
}

void	check_identity( c )
BYTE	c;
{
	WORD	x;

	if (( RecvPattern[RecvIndex] = c ) == TestPattern[RecvIndex] ) {
		RecvIndex++;
		if ( RecvIndex == 8 ) 
			StreamIdentityCico();
		return;
		}

	StreamStatus = _STREAM_SYSTEM;
	for ( x = 0; x < RecvIndex; x++ ) 
		CicoOutPut( RecvPattern[x] );
	CicoOutPut( c );
	return;	
}

void	StreamIdentityUnknown()
{

	memcpy((BPTR) TestPattern , (BPTR) "69293939" , 8 );
	RecvIndex    = 0;
	StreamStatus = _STREAM_UNKNOWN;
	return;

}

static	WORD	CalculateContext()
{
	ScreenContext.LastLine = conf(1);
	ScreenContext.LastColumn = conf(2);
	ScreenContext.nbcolumn   = 1;
	ScreenContext.nbline     = ScreenContext.TopLine;
	return(0);
}

WORD	EstablishContext(topline,bottomline,restart)
WORD	topline;
WORD	bottomline;
WORD	restart;
{

	if (( ScreenContext.TopLine != topline ) || (ScreenContext.BottomLine != bottomline) || (restart & 1)) {
		ScreenContext.BottomLine = bottomline;
		ScreenContext.TopLine    = topline;
		if ( topline > bottomline ) {
			return(7);
			}
		CalculateContext();
		StreamIdentityCico();
		}
	Position(ScreenContext.nbcolumn,ScreenContext.nbline);
	return(0);
}

void	PerformScroll()
{
	Position(1,ScreenContext.TopLine);
	x_putch(0x001B); x_putch('M');
	Position(1,ScreenContext.BottomLine);
	if ( ScreenContext.BottomLine < ScreenContext.LastLine ) {
		x_putch(0x001B); x_putch('L');
		Position(1,ScreenContext.BottomLine);
		x_putch(0x001B); x_putch('K');
		Position(1,ScreenContext.BottomLine);
		}
	return;
}

void	system_stream( c )
BYTE	c;
{

	switch ( c ) {
		case 0x000D :
			ScreenContext.nbcolumn = 1;
			return;

		case 0x000A :

			/* NL requires preceeding CR for CICO format */
			/* ----------------------------------------- */	
			x_putch(0x000D);
		
			ScreenContext.nbcolumn = 1;
			if ( ScreenContext.nbline < ScreenContext.BottomLine ) {
				ScreenContext.nbline++;
				x_putch(c);
				}
			else	{
				PerformScroll();
				}
			return;

		case 0x0009 :
			do	{
				CicoOutPut(' ');
				}
			while (((ScreenContext.nbcolumn - 1) % 8 ) != 0);
			return;

		default :
			if (ScreenContext.nbcolumn > ScreenContext.LastColumn ) {
				ScreenContext.nbcolumn = 1;
				if ( ScreenContext.nbline < ScreenContext.BottomLine ) {
					ScreenContext.nbline++;
					x_putch(0x000D); x_putch(0x000A);
					}
				else	{
					PerformScroll();
					}
				}
			x_putch(c);
			ScreenContext.nbcolumn++;
			if (( ScreenContext.nbcolumn == ScreenContext.LastColumn ) && ( ScreenContext.nbline == ScreenContext.LastLine )) {
				ScreenContext.nbcolumn++;
				}
		}
	return;

}

void	establish_escape_count( c )
BYTE	c;
{
	switch ( c ) {
		case 'f' : cico.escape_f = 2; break;
		case 's' :
		case 'r' : cico.escape_count = 1; break;
		default  : cico.escape_count = 0; break;
		}
	return;
}

void	cico_stream( c )
BYTE	c;
{
	/* Check for collection of curser position */
	/* --------------------------------------- */
	if ( cico.escape_f ) {

		cico.escape_f--;

		/* Check for collection of column number */
		/* ------------------------------------- */
		if ( cico.escape_f ) {
			ScreenContext.nbcolumn = ( c - 0x001F );
			}
		else	{
			/* Collecting line number */
			/* ---------------------- */
			ScreenContext.nbline = ((ScreenContext.BottomLine - ScreenContext.TopLine) + ( c - 0x001F ));
			c = (BYTE) (ScreenContext.nbline + 0x001F);
			}

		x_putch( c );
		return;
		}

	if ( cico.escape_count ) {
		x_putch( c );
		cico.escape_count--;
		return;
		}
	if ( cico.escape_flag ) {
		establish_escape_count( c );
		x_putch(0x001B );
		x_putch( c );
		return;
		}

	if ( c == 0x001B ) {
		cico.escape_flag = 1;
		return;
		}

	system_stream( c );
}



/*
 *	C I C O  O U T P U T ( c )
 *	--------------------------
 *	Performs Raw to Cico Format Conversion with Protected zone
 *	scroll management
 */

void	CicoOutPut( c )
BYTE	c;
{
	if (!( cico.started )) {
		if ( c == 10 ) return;
		cico.started=1;
		if ( cico.signal ) {
			(*cico.signal)();
			CalculateContext();
			}
		Position(ScreenContext.nbcolumn,ScreenContext.nbline);
		}				
	system_stream( c );

}

#endif

#ifdef	UNIX
 
/*
 *	P I P E S U R V E I L L A N C E ( Pipe_Handle )
 *	-----------------------------------------------
 *	Performs pipe read to recieve and interprete redirected
 *	child standard output
 *
 */
int	PipeSurveillance( pipe_handle, worker )
int	pipe_handle;
int	worker;
{
	int	status=0;
	int	local_errno=0;
	BYTE	buffer[16];
	int 	nb_in_buf;
	WORD	x;
	BYTE	LastByte;

	/* Enter surveillance loop */
	/* ----------------------- */
	while ((nb_in_buf = read(pipe_handle,buffer,16)) > 0) {
		
		/* Analyse recieved data */
		/* --------------------- */
		for (x = 0; x < nb_in_buf; x++) {

			/* Send the character out via Cico */
			/* ------------------------------- */
			CicoOutPut((LastByte = buffer[x]));

			}

		}			

	if ( cico.started ) {
		if (LastByte != 0x000A) CicoOutPut(0x000A);
		}

	/* handle child death and return */
	/* ----------------------------- */
	if ( waitpid( worker, &status ,0 ) != worker )
		local_errno = 34; 
	else if ( WIFEXITED(status) ) {
		local_errno = WEXITSTATUS(status);
		}
	else	local_errno = 56;
	return(local_errno);
}

/*
 *	S Y S T E M D ( command_pointer, top_line , bottom_line )
 *	---------------------------------------------------------
 *	This function executes the command provided and receives
 *	the output on the line standard output, which will be
 *	formated in the screen zone defined by topline and bottomline
 *
 */

WORD	systemd(cmdptr,topline,bottomline,restart)
BPTR	cmdptr;
WORD	topline;
WORD	bottomline;
WORD	restart;
{
	int 	local_errno;
	int 	child_id;
	int 	Original_Stdio;
	int 	Original_Stderr;
	int 	Pipe_Handles[2];
	int 	Child_Stdio;

	/* Establish Screen Context */
	/* ------------------------ */
	if ((local_errno = EstablishContext(topline,bottomline,restart)) != 0 ) {

	
		/* Return Local Error Value */
		/* ------------------------ */
		return( local_errno );

		}

	/* Ensure not an empty command line */
	/* -------------------------------- */
	if ( strlen((BPTR) cmdptr ) == 0 ) {
		return(0);
		}

	/* Duplicate Current STDIO Handle for Parent */
	/* ----------------------------------------- */
	if ((Original_Stdio = dup( STDIO )) != -1) {
		
		/* Duplicate Current STDIO Handle for Parent */
		/* ----------------------------------------- */
		if ((Original_Stderr = dup( STDERR )) != -1) {
		
			/* Create a PIPE to receive child's Output   */
			/* ---------------------------------------   */
			if ( pipe( Pipe_Handles ) != -1 ) {

				/* Close our current STDIO channel */
				/* ------------------------------- */
				if ( close( STDIO ) != -1 ) {
				
					/* Establish Child's new STDIO channel */
					/* ----------------------------------- */
					if ((Child_Stdio = dup(Pipe_Handles[1])) != -1) {
					
						/* Close our current STDERR channel */
						/* -------------------------------- */
						if ( close( STDERR ) != -1 ) {
						
							/* Establish Child's new STDERR channel */
							/* ------------------------------------ */
							if ((Child_Stdio = dup(Pipe_Handles[1])) != -1) {

								signal(SIGCHLD,SIG_DFL);
						
								/* Generate a child worker for Independance */
								/* ---------------------------------------- */
								switch ((child_id = fork())) {
							
									case  0	:	/* Child Worker 	*/
											/* -------------------- */
											/* Execute Syteme Command and Return */
											/* --------------------------------- */
											if ((local_errno = system( cmdptr )) != 0)
												local_errno=1;
											exit( local_errno );
								
									case -1	:	/* Error during fork	*/
											/* -------------------- */
											local_errno = 5;
											break;
									default :
								
										/* Parent Process arrives Here to manage returns from PIPE */
										/* ------------------------------------------------------- */	
										/* Close Childs STDIO and Restore Previous STDIO Channel   */
										/* ------------------------------------------------------- */
										(void) close( STDIO );
										(void) dup( Original_Stdio ); 
										(void) close( STDERR);
										(void) dup( Original_Stderr ); 
										(void) close( Original_Stdio );
										(void) close( Original_Stderr);
										(void) close( Pipe_Handles[1] );
									
										/* Perform Pipe Surveilance and Reception */
										/* -------------------------------------- */
										local_errno = PipeSurveillance(Pipe_Handles[0],child_id);
							
									} /* Switch */
								} /* Create Child STDERR */
						else	{
							
								/* Recover Original Stder Channel at FID 2 */
								/* --------------------------------------- */
								(void) dup(Original_Stderr);

								/* Establish Local Error Code */
								/* -------------------------- */
								local_errno = 4;
								}

							}
						else	{
							/* Establish Local Error Code */
							/* -------------------------- */
							local_errno = 3;
							}

						/* Close down both end of pipe */
						/* --------------------------- */
						(void) close(Pipe_Handles[0]);
						(void) close(Pipe_Handles[1]);
						}
					}
				else	{
					/* Establish Local Error Code */
					/* -------------------------- */
					local_errno = 2;
					}
				}

			}
			/* Close Secondary STDIO channel */
			/* ----------------------------- */
			(void) close(Original_Stdio);
			}
		else	{
			/* Establish Local Error Code */
			/* -------------------------- */
			local_errno = 1;
			}
	StreamIdentityCico();
	return(local_errno);

}

VOID	signal_system_d( void * v )	{	cico.signal = v;	}

#else	/* (DOS or PROLOGUE) not UNIX */
	/* -------------------------- */

WORD	systemd(cmdptr,topline,bottomline,restart)
BPTR	cmdptr;
WORD	topline;
WORD	bottomline;
WORD	restart;
{
	WORD	local_errno;
	WORD	stdio_status;

	/* Establish Screen Context */
	/* ------------------------ */
	if ((local_errno = EstablishContext(topline,bottomline,restart)) != 0 ) {
	
		/* Return Local Error Value */
		/* ------------------------ */
		return( local_errno );

		}

	/* Ensure not an empty command line */
	/* -------------------------------- */
	if ( strlen((BPTR) cmdptr ) == 0 ) {
		return(0);
		}

#ifdef	DOS
	/* Dos version requires function relay adresse */
	/* ------------------------------------------- */
	establish_relay( CicoOutPut );
#endif

#ifndef PRL3
	/* Redirect STDOUT to be received by this proces */
	/* --------------------------------------------- */
	stdio_status = redirect_stdout();

#endif
	/* Attempt to execute the specified system command */
	/* ----------------------------------------------- */
	local_errno = systeme( cmdptr );
#ifndef PRL3
	/* Test for successful redirection */
	/* ------------------------------- */
	if ( stdio_status == 0 ) {

		/* Restore original STDOUT channel */
		/* ------------------------------- */
		recover_stdout();
		}
#endif
#ifdef	DOS
	StreamIdentityCico();
#endif

	/* Return systeme error to caller */
	/* ------------------------------ */
	return( local_errno );

}

#endif
