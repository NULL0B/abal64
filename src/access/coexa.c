/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic 			*/
/*									*/
/*		Module  :	COEXA - C				*/
/*		Date 	:	11/07/1989				*/
/*									*/
/*----------------------------------------------------------------------*/
#include "portage.h"
#include "exuser.h"		/* Include header file		*/
#include <signal.h>		/* Include Signal Definitions	*/

#include <syslog.h>
#include <errno.h>
#include "exlock.h"

extern	int	user_main();	/* Principale user entry point	*/
extern	int	user_init();	/* User initialisation function */
static void	user_abal();	/* Prototype Renvoi du resultat */
/*
 *	Standard communication structure
 *	--------------------------------
 */

struct	ipc_zone {
	long		ipc_ref;	/* Message ID number		*/
	long		ipc_exp;	/* Sender PID code		*/
	short int	ipc_err;	/* Result error value		*/
	char		ipc_data[2];	/* Message data zone		*/
	};

static	struct ipc_zone * msgwork;	/* Message Buffer Pointer	*/

static	struct  ipc_param msparam;	/* Parameter zone for IPC's 	*/

int	msgid,mslng;		/* 
				 * Message file handle and 	
				 * Message transfer length
				 */

int	UserMode;		/* Options received (Verbose etc)	*/

int	getqid() 
{
	return(msparam.key);
}

/*
 *	ExUserExit ( msgid , status )
 *	------------------------------
 *	Routine d'evacuation due aux erreurs graves
 *
 */

int	ExUserExit( msgid , xkod )
int	msgid, xkod;
{
	if ( msgid > 0 ) {
		msgid = msgctl(msgid,IPC_RMID, (struct msqid_ds *)" Void ");
		}
	return( xkod );
}

/*	
 *	E X U S E R K I L L ( sigid )
 *	-----------------------------
 *	Recieves the SOFTWARE TERMINATION signal from a prompt KILL
 *	and Exits gracefully !!!
 */

void ExUserKill( sigid )
int	sigid;
{
	standard_log_signal(sigid,"normal");
	(void) ExUserExit( msgid , 15 );
	exit(0);
}

/*	---------------------------------------		*/
/*	This function allows dynamic Q resizing		*/
/*	---------------------------------------		*/

static	int	globalQid=0;

int	get_queue_size()
{
	struct	msqid_ds	buf;
	if ( msgctl ( globalQid, IPC_STAT, &buf) != 0 )
		return( 0 );
	else 	return( buf.msg_qbytes );
}

int	set_queue_size(int newsize)
{
	struct	msqid_ds	buf;
	if ( msgctl ( globalQid, IPC_STAT, &buf) != 0 )
		return( errno );
	else if ( newsize <= buf.msg_qbytes )
		return(0);
	else 	{
		buf.msg_qbytes = newsize;
		if ( msgctl ( globalQid, IPC_SET, &buf) != 0 )
			return( errno );
		else	return( 0 );
		}
}


static	void	access_init_signals()
{
	standard_init_signals("access","ACSIGNAL");
	(void) signal(SIGTERM,ExUserKill);
	return;
}

void	set_queue_silence(mode)
int	mode;
{
	if (mode & 1)
		msparam.opt |= Q_SILENCE;
	else	msparam.opt &= ~Q_SILENCE;
	return;
}

/*
 *	M A I N ( argc , argv )
 *	-----------------------
 *	The routine main will perform the message file initialisation,
 *	generation of the resident child process and then terminate.
 *	The resident child process will Monitor the message file for
 *	incoming requests which will be passed to the user routine
 *	named 'USERMAIN'
 */

int	activate_service( msgqueue, memsize )
key_t	msgqueue;
int	memsize;
{
	int	mserr;			/* Local Error Variable		*/
	int	longeur;		/* Message Length Recieved	*/
	
	/* Perform User Initialisation */
	/* --------------------------- */
	if ( user_init(&msparam) == -1 ) 	{ return(1); }

	msparam.key = msgqueue;

	/* Calculate Message Buffer Length */
	/* ------------------------------- */
	mslng   = msparam.max + (sizeof( long ) * 2) + sizeof(short int);

	/* Allocate Message Buffer */
	/* ----------------------- */
	msgwork = ( struct ipc_zone *) malloc( mslng );

	if ( msgwork == (struct ipc_zone *) 0 ) { return(2); }

	/* Open and or Create Message File */
	/* ------------------------------- */
	msgid = msgget(msparam.key, 0666 );

	/* Test for Already Existant */
	/* ------------------------- */
	if ( msgid != -1 ) {

		/* Check for Option Auto Flush */
		/* --------------------------- */
		if ( msparam.opt & Q_FLUSH ) {

			/* Flush the File and Remove It */
			/* ---------------------------- */
			(void) msgctl( msgid,IPC_RMID, (struct msqid_ds *)msgwork);
			msgid = -1;
			}
		}

	/* Check for Creation Required */
	/* --------------------------- */
	if ( msgid == -1 ) {
		msgid = msgget(msparam.key, 0666 | IPC_CREAT);
		}

	/* Check for Errors due to OPEN or CREATE */
	/* -------------------------------------- */
	if ((globalQid = msgid) == -1) 			{ return(3); }

	/* Adjust Memory Size */
	/* ------------------ */
	if ( memsize ) {
		set_queue_size( memsize );
		}

	/*	Generation of Child process	*/
	/*	---------------------------	*/
	
	if (!( UserMode & 1 )) {
		/* --------------------------------- */
		/* not verbalising in forground mode */
		/* --------------------------------- */
		switch ( fork() ) {
			case 0 		:	break;
			case -1		:	return( ExUserExit(msgid,4) ); 
			default		:	return(0);
			}
		}

	/*	Arrival here means we are ALL systems GO	*/
	/*	----------------------------------------	*/

	/*	Establish Signal Trap		*/
	/*	---------------------		*/
	access_init_signals();

	/* 	Enter Message processing Loop	*/
	/*	----------------------------- 	*/

	/*	Initialise Process Control	*/
	/*	--------------------------	*/

	access_init_process();

	standard_log_signal(0,"startup");

	while (	1 ) {

		set_queue_silence(0);

		if ( (longeur = msgrcv(msgid,msgwork,mslng,msparam.id,msparam.perm)) != -1 ) {

			/* Test for Generation of Child workers	*/
			/* ------------------------------------	*/
			if ( msparam.opt & Q_FORK) {

				/* Yes generate child workers	*/
				/* --------------------------   */
				switch ( fork() ) {
					case 0 		:	break;
					case -1		:	return( ExUserExit(msgid,4) ); 
					default		:	continue;
					}
				}

			/* Pass Control to the User Function */
			/* --------------------------------- */	
			mserr = user_main( (*(msgwork)).ipc_data , (*(msgwork)).ipc_ref );

			if (!( msparam.opt & Q_SILENCE )) {

				/* Establish the Error Code to be returned */
				/* --------------------------------------- */
				(*(msgwork)).ipc_err = (short int) mserr; 

				/* Send the Answer message to Calling Process */
				/* ------------------------------------------ */
				(void) user_abal(longeur);
				}

			/* Test for child Process */
			/* ---------------------- */
			if ( msparam.opt & Q_FORK ) {

				/* Liberate child worker */
				/* --------------------- */
				return(0);
				}
			}
		}
	standard_log_signal(0,"shutdown");
	return(ExUserExit(msgid,5));
}

/*
 *	U S E R _ A B A L (   )
 *	-----------------------
 *	This function allows the User to return information to ABAL
 */

static void	user_abal(longeur)
int	longeur;
{
	long	tmp;
	tmp = (*(msgwork)).ipc_ref;
	(*(msgwork)).ipc_ref = (*(msgwork)).ipc_exp;
	(*(msgwork)).ipc_exp = tmp;
	(void) msgsnd( msgid , msgwork , longeur , MSG_NOERROR );
	return;
}


