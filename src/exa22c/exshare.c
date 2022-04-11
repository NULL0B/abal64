/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXSHARE - C				*/
/*		Date 	:	22/06/1989				*/
/*									*/
/*----------------------------------------------------------------------*/
#include "exngf.h"
#include "exlock.h"
#include "exipc.h"

struct	lockreq {
	long	       msg_ds;	/* Message a Envoyer			*/
	long	       msg_id;	/* Sender ID				*/
	short int      msg_err;	/* Error Flag				*/
	struct exapadd AbalLock;/* Lock Details Structure		*/
	} MsgLock;		/* File Locking Structure		*/

#define LOCKLENGTH (sizeof(struct lockreq) - sizeof( long ))

struct	stat	AbalStat;	/* File Statistics Structure		*/

int	lockqueue;		/* Message File ID			*/

UBINAIR etatlox( fid , perm )
UBINAIR	fid;
UBINAIR	perm;

{

	int lres;

	/* Check for Co-Executeur Lock manager active and Ready */
	/* ---------------------------------------------------- */
	if ( lockqueue == -1 ) {
		lockqueue = msgget( (key_t) 13 , 0 );
		if ( lockqueue == -1 ) {
			close ( fid );
			errno = 58;
			return( SOFTERROR  );
			}
		}

	/* Read File Statistics */
	/* -------------------- */
	if ( stat(fidname , &AbalStat) == 0 ) {

		/* Establish Lock Request Structure Infos */
		/* -------------------------------------- */
		MsgLock.AbalLock.lock_inode = AbalStat.st_ino;
		MsgLock.AbalLock.lock_dnode = AbalStat.st_dev;
		MsgLock.AbalLock.lock_owner = getpid();
		MsgLock.AbalLock.lock_mode  = ( ((perm & 2 ) != 0) ? EXCLUSIVE : SHARELOCK );
		MsgLock.AbalLock.lock_func  = EXAOPEN;
		MsgLock.msg_ds  = 1L;
		MsgLock.msg_id  = (long) (getpid() + 1);
		MsgLock.msg_err = 0;

	/* Send the Lock Request */
	/* --------------------- */
	if (msgsnd(lockqueue,&MsgLock,LOCKLENGTH,0) == 0 ) {
		
		/* Wait for Lock Response Message */
		/* ------------------------------ */
		lres = msgrcv(lockqueue,&MsgLock,LOCKLENGTH,MsgLock.msg_id,MSG_NOERROR);

		/* Check for ErroCode has at least been returned */
		/* --------------------------------------------- */
		if ( lres > (sizeof(long) *2 )) {
			/* If no Error then OK lock establised */
			/* ----------------------------------- */
			if ( (err_val = MsgLock.msg_err) == 0 ) {
				return( 1 );
				}
			errno = err_val;
			}
		}
	}
	err_val = errno;

	/* Close the file for Error Return */
	/* ------------------------------- */
	close( fid ); return(SOFTERROR);

}

void	liberlox( fnom )
EXBPTR	fnom;
{

	/* Read File Statistics */
	/* -------------------- */
	if ( stat(fnom , &AbalStat) == 0 ) {

		/* Establish Lock Request Structure Infos */
		/* -------------------------------------- */
		MsgLock.AbalLock.lock_inode = AbalStat.st_ino;
		MsgLock.AbalLock.lock_dnode = AbalStat.st_dev;
		MsgLock.AbalLock.lock_owner = getpid();
		MsgLock.AbalLock.lock_mode  = 0;
		MsgLock.AbalLock.lock_func  = EXACLOSE;
		MsgLock.msg_ds  = 1L;
		MsgLock.msg_id  = (long) (getpid() + 1);
		MsgLock.msg_err = 0;

		/* Send the Lock Request */
		/* --------------------- */
		msgsnd(lockqueue,&MsgLock,LOCKLENGTH,0);

		/* Wait for Lock Response Message */
		/* ------------------------------ */
		msgrcv(lockqueue,&MsgLock,LOCKLENGTH,MsgLock.msg_id,MSG_NOERROR);

		}
	return;

}
