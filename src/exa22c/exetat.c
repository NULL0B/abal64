
/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1990 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXETAT - C				*/
/*		Version :	1.2d / 1.3a / 1.4a			*/
/*		Date 	:	26/04/1990				*/
/*									*/
/*----------------------------------------------------------------------*/
#include "exngf.h"
#include "exlock.h"
#include "exipc.h"
#include "exaccess.h"
#include <signal.h>

struct	lockreq {
	long	       msg_ds;	/* Message a Envoyer			*/
	long	       msg_id;	/* Sender ID				*/
	short int      msg_err;	/* Error Flag				*/
	struct exapadd AccessZone;/* Lock Details Structure		*/
	} MsgZone;		/* File Locking Structure		*/

#define LOCKLENGTH (sizeof(struct lockreq) - sizeof( long ))

#define	VRAI		1	/* True result flag			*/
#define	FAUX		0	/* False result flag			*/
#define	ECART		1	/* Adjustment Value for recieve message	*/
#define	SUCCESS		0	/* Successful result			*/
#define	FAILURE		-1	/* Function failure			*/
#define	LOCKMSGID	1L	/* Message Type ID code			*/
#define	MSGFILEID	13	/* Message file used for LOCK IPC	*/

struct	stat	FichStat;	/* File Statistics Structure		*/

int	WakeUp;			/* Indication that alarm has occured	*/

extern	int	AlarmDuree;	/* Length of Time Out Period for Alarm	*/

AlarmTrap(nbs)
int	nbs;
{
	if ( nbs == SIGALRM ) {
		WakeUp = 1;
		(void) signal(SIGALRM,AlarmTrap);
		}
	return(0);
}


void	AlarmOn()
{
	WakeUp = 0;
	(void) signal(SIGALRM,AlarmTrap);
	(void) alarm( AlarmDuree );
	return;
}

int	AlarmOff( status )
int	status;
{
	(void) signal(SIGALRM,SIG_IGN);
	(void) alarm(0);
	WakeUp = 0;
	return(status);

}

/*
 *	R E P O R T E R ( msgqueue )
 *	----------------------------
 *	Displays current status of File Access Manager
 *
 */

int 	reporter( msgqueue )
key_t	msgqueue;
{
	char	cmd[256];

	if ( interro(msgqueue) == SUCCESS ) {
		strcpy(cmd,"cat ");
		strcat(cmd,COREFILE);
		system(cmd);
		return(SUCCESS);
		}
	return(FAILURE);

}

int openqueue( msgqueue )
key_t	msgqueue;
{
	/* Attempt to Open Message File */
	/* ---------------------------- */
	return(msgget( (key_t) msgqueue , 0 ));
}

static int	interro(msgqueue)
key_t	msgqueue;
{
	int	lockqueue;

	/* Attempt to open message Queue */
	/* ----------------------------- */
	if ( (lockqueue = openqueue(msgqueue)) != FAILURE ) {

		/* Establish Lock Request Structure Infos */
		/* -------------------------------------- */
		MsgZone.AccessZone.lock_owner = getpid();
		MsgZone.AccessZone.lock_func  = COEXASTATUS;
		MsgZone.msg_ds  = LOCKMSGID;
		MsgZone.msg_id  = (long) (getpid() + ECART);
		MsgZone.msg_err = SUCCESS;

		/* Send the Lock Request */
		/* --------------------- */
		if (msgsnd(lockqueue,&MsgZone,LOCKLENGTH,0) == SUCCESS) {

			/* Establish an Alarm Call */
			/* ----------------------- */
			AlarmOn();
			
			/* Wait for Lock Response Message */
			/* ------------------------------ */
			if ( msgrcv(lockqueue,&MsgZone,LOCKLENGTH,MsgZone.msg_id,MSG_NOERROR) >= (sizeof(long) * 2 )) {
	
				/* If no Error then OK lock establised */
				/* ----------------------------------- */
				if ( (errno = MsgZone.msg_err) == SUCCESS ) {
					return( AlarmOff(SUCCESS) );
					}
				}
			return( AlarmOff(FAILURE) );
			}
		}
	else	{
		return (FAILURE);
		}

}

/*
 *	P U R G E R (msgqueue,pidpurge)
 *	-------------------------------
 *	Liberate all remaining CoExa Lock Infos for This Process
 *
 */

int 	purger(msgqueue,pidpurge)
key_t	msgqueue;
int	pidpurge;
{
	int	lockqueue;

	/* Attempt to open message Queue */
	/* ----------------------------- */
	if ( (lockqueue = openqueue(msgqueue)) != FAILURE ) {

		/* Establish Lock Request Structure Infos */
		/* -------------------------------------- */
		MsgZone.AccessZone.lock_inode = 0;
		MsgZone.AccessZone.lock_dnode = 0;
		MsgZone.AccessZone.lock_owner = pidpurge;
		MsgZone.AccessZone.lock_mode  = 0;
		MsgZone.AccessZone.lock_func  = COEXAPURGE;
		MsgZone.msg_ds  = LOCKMSGID;
		MsgZone.msg_id  = (long) (getpid() + ECART);
		MsgZone.msg_err = SUCCESS;

		/* Send the Lock Request */
		/* --------------------- */
		msgsnd(lockqueue,&MsgZone,LOCKLENGTH,0);

		/* Set Alarm Clock */
		/* --------------- */
		AlarmOn();

		/* Wait for Lock Response Message */
		/* ------------------------------ */
		if ( msgrcv(lockqueue,&MsgZone,LOCKLENGTH,MsgZone.msg_id,MSG_NOERROR) >= (sizeof(long) * 2 )) {
			return(AlarmOff(SUCCESS));	
			}
		return(AlarmOff(FAILURE));
		}
	else	{
		return(FAILURE);
		}
}

#if defined(RT_AIX) || defined(UNIXWARE) ||defined(LINUX)
/*
 *	P U R G E R (msgqueue,pidpurge)
 *	-------------------------------
 *	Liberate all remaining CoExa Lock Infos for This Process
 *
 */

int 	fpurger(msgqueue,inopurge)
key_t	msgqueue;
int	inopurge;
{
	int	lockqueue;

	/* Attempt to open message Queue */
	/* ----------------------------- */
	if ( (lockqueue = openqueue(msgqueue)) != FAILURE ) {

		/* Establish Lock Request Structure Infos */
		/* -------------------------------------- */
		MsgZone.AccessZone.lock_inode = inopurge;
		MsgZone.AccessZone.lock_dnode = 0;
		MsgZone.AccessZone.lock_owner = 0;
		MsgZone.AccessZone.lock_mode  = 0;
		MsgZone.AccessZone.lock_func  = COEXAFPURGE;
		MsgZone.msg_ds  = LOCKMSGID;
		MsgZone.msg_id  = (long) (getpid() + ECART);
		MsgZone.msg_err = SUCCESS;

		/* Send the Lock Request */
		/* --------------------- */
		msgsnd(lockqueue,&MsgZone,LOCKLENGTH,0);

		/* Set Alarm Clock */
		/* --------------- */
		AlarmOn();

		/* Wait for Lock Response Message */
		/* ------------------------------ */
		if ( msgrcv(lockqueue,&MsgZone,LOCKLENGTH,MsgZone.msg_id,MSG_NOERROR) >= (sizeof(long) * 2 )) {
			return(AlarmOff(SUCCESS));	
			}
		return(AlarmOff(FAILURE));
		}
	else	{
		return(FAILURE);
		}
}
#endif
/*
 *	L I B E R A T E ( msgqueue )
 *	----------------------------
 *
 */

int 	liberate_service( msgqueue )
key_t	msgqueue;
{
	int lockqueue;

	if ( (lockqueue = openqueue(msgqueue)) != FAILURE ) {
		/* Establish Lock Request Structure Infos */
		/* -------------------------------------- */
		MsgZone.AccessZone.lock_inode = 0;
		MsgZone.AccessZone.lock_dnode = 0;
		MsgZone.AccessZone.lock_owner = getpid();
		MsgZone.AccessZone.lock_mode  = 0;
		MsgZone.AccessZone.lock_func  = COEXAKILL;
		MsgZone.msg_ds  = LOCKMSGID;
		MsgZone.msg_id  = (long) (getpid() + ECART);
		MsgZone.msg_err = SUCCESS;

		/* Send the Lock Request */
		/* --------------------- */
		msgsnd(lockqueue,&MsgZone,LOCKLENGTH,(IPC_NOWAIT | MSG_NOERROR));
		return(SUCCESS);
		}
	else 	{
		return(FAILURE);
		}
}



int	killqueue( qid )
int	qid;
{
	if (( qid = msgget((key_t) 13, 0)) != -1 ) {
		if ( msgctl(qid,IPC_RMID,"  ") != 0 ) {
			return( FAILURE );
			}
		else	{
			return(SUCCESS);
			}
		}
	else	{
		return(FAILURE);
		}
}

