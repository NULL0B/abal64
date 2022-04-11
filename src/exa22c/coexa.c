/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	COEXA - C				*/
/*		Date 	:	11/07/1989				*/
/*									*/
/*----------------------------------------------------------------------*/

#include "exuser.h"		/* Include header file		*/
#include <signal.h>		/* Include Signal Definitions	*/

extern	int	user_main();	/* Principale user entry point	*/
extern	int	user_init();	/* User initialisation function */
void		user_abal();	/* Prototype Renvoi du resultat */

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
		msgid = msgctl(msgid,IPC_RMID," Void ");
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
	(void) ExUserExit( msgid , 15 );
	exit(0);
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

int	activate_service( msgqueue )
key_t	msgqueue;
{
	int	mserr;			/* Local Error Variable		*/
	char *  aptr;			/* Arguament Evaluation ptr	*/
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
			(void) msgctl( msgid,IPC_RMID,msgwork);
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
	if ( msgid == -1) 			{ return(3); }

	/*	Generation of Child process	*/
	/*	---------------------------	*/

	switch ( fork() ) {
		case 0 		:	break;
		case -1		:	return( ExUserExit(msgid,4) ); 
		default		:	return(0);
		}

	/*	Arrival here means we are ALL systems GO	*/
	/*	----------------------------------------	*/

	/*	Establish Signal Trap		*/
	/*	---------------------		*/

	(void) signal( SIGTERM , ExUserKill );

	/* 	Enter Message processing Loop	*/
	/*	----------------------------- 	*/

while (	1 ) {

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

		/* Establish the Error Code to be returned */
		/* --------------------------------------- */
		(*(msgwork)).ipc_err = (short int) mserr; 

		/* Send the Answer message to Calling Process */
		/* ------------------------------------------ */
		(void) user_abal(longeur);

		/* Test for child Process */
		/* ---------------------- */
		if ( msparam.opt & Q_FORK ) {

			/* Liberate child worker */
			/* --------------------- */
			return(0);
			}
		}
	}
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
