
/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXACCESS - C				*/
/*		Date 	:	11/10/1989				*/
/*									*/
/*----------------------------------------------------------------------*/
#include "exngf.h"	/* Standard file definitions			*/
#include "exlock.h"	/* Lock message interface definitions		*/
#include "exipc.h"	/* Standard message definitions			*/
#include "exaccess.h"	/* Version redefinitions Diffusion or Test	*/

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
#define	FAILURE		-1    	/* Function failure			*/
#define	LOCKMSGID	1L	/* Message Type ID code			*/
#define	MSGFILEID	13	/* Message file used for LOCK IPC	*/

struct	stat	FichStat;	/* File Statistics Structure		*/

int	lockqueue;		/* Message File ID			*/
int	lockflag;		/* Initialisation status		*/


int	InitQueue()
{
	key_t	msgidentif;
	char *  msgenv;

	/* Establish Message File ID Key */
	/* ----------------------------- */
	msgidentif = (key_t) MSGFILEID;
	if ((msgenv = (char *) getenv( "ACCESSQ" )) != (char *) 0) {
		msgidentif = (key_t) 0;
		while ( *msgenv != (char) 0 ) {
			if (( *msgenv >= '0' ) && ( *msgenv <= '9' )) {
				msgidentif *= (key_t) 10;
				msgidentif += (key_t) ( *msgenv - '0');
				msgenv++;
				}
			else	{
				break;
				}
			}
		}
	/* Attempt to Open Message File */
	/* ---------------------------- */
	lockqueue = msgget( (key_t) msgidentif , 0 );
	if ( lockqueue == FAILURE ) {
		errno = 667;
		return (FAILURE);
		}

	return(SUCCESS);
}

/*
 *	A C C E S S  ( Nom_du_fichier , Permission_d'access )
 *	-----------------------------------------------------
 *	Control d'access aux fichiers UNIX
 *
 *	Returns :	SUCCESS == 0
 *		:	FAILURE == -1	and errno == error code
 */

int	Access( nomfic , perm , mode )

char *		nomfic;		/* Nom du Fichier a controller 		*/
int		perm;		/* Permission requise d'access		*/
int		mode;		/* 0 => Shared , 1 = Exclusive		*/

{

	/* Test for File Existance (normal Unix Procedure) */
	/* ----------------------------------------------- */
	if ( access( nomfic , perm ) != SUCCESS ) {
		/* Error Unix d'access */
		/* ------------------- */
		return (FAILURE);
		}

	/* Check for Co-Executeur Lock manager active and Ready */
	/* ---------------------------------------------------- */
	if ( lockflag  == FAUX ) {
		if ( InitQueue() == FAILURE ) {
			return(FAILURE);
			}
		lockflag = VRAI;
		}

	/* Read File Statistics */
	/* -------------------- */
	if ( stat(nomfic,&FichStat) == SUCCESS ) {

		/* Establish Lock Request Structure Infos */
		/* -------------------------------------- */
		MsgZone.AccessZone.lock_inode = FichStat.st_ino;
		MsgZone.AccessZone.lock_dnode = FichStat.st_dev;
		MsgZone.AccessZone.lock_owner = getpid();
		MsgZone.AccessZone.lock_mode  = ((mode == VRAI) ? COEXAEXCLUSIVE : COEXASHARELOCK );
		MsgZone.AccessZone.lock_func  = COEXAOPEN;
		MsgZone.msg_ds  = LOCKMSGID;
		MsgZone.msg_id  = (long) (getpid() + ECART);
		MsgZone.msg_err = SUCCESS;

		/* Send the Lock Request */
		/* --------------------- */
		if (msgsnd(lockqueue,&MsgZone,LOCKLENGTH,0) == SUCCESS) {
		
			/* Wait for Lock Response Message */
			/* ------------------------------ */
			if ( msgrcv(lockqueue,&MsgZone,LOCKLENGTH,MsgZone.msg_id,MSG_NOERROR) >= (sizeof(long) * 2 )) {

				/* If no Error then OK lock establised */
				/* ----------------------------------- */
				if ( (errno = MsgZone.msg_err) == SUCCESS ) {
					return(SUCCESS);
					}
				}
			}
		}

	/* Error Return */
	/* ------------ */
	return (FAILURE);

}

/*
 *	L I B E R L O X ( File_Name )
 *	-----------------------------
 *	Liberate the CoExa Locking Infos for This File
 *
 */

void	liberlox( fnom )
char *	fnom;
{

#ifdef	ABAL_TCPIP
	unsigned	char	lnom[65];
	if ( fn_parser( fnom, lnom, 1 ) != 0 )
		return;
#endif

	/* Check for Co-Executeur Lock manager active and Ready */
	/* ---------------------------------------------------- */
	if ( lockflag  == FAUX ) {
		if ( InitQueue() == FAILURE ) {
			return;
			}
		lockflag = VRAI;
		}

	/* Read File Statistics */
	/* -------------------- */
	if ( stat(fnom,&FichStat) == SUCCESS ) {

		/* Establish Lock Request Structure Infos */
		/* -------------------------------------- */
		MsgZone.AccessZone.lock_inode = FichStat.st_ino;
		MsgZone.AccessZone.lock_dnode = FichStat.st_dev;
		MsgZone.AccessZone.lock_owner = getpid();
		MsgZone.AccessZone.lock_mode  = 0;
		MsgZone.AccessZone.lock_func  = COEXACLOSE;
		MsgZone.msg_ds  = LOCKMSGID;
		MsgZone.msg_id  = (long) (getpid() + ECART);
		MsgZone.msg_err = SUCCESS;

		/* Send the Lock Request */
		/* --------------------- */
		while ( msgsnd(lockqueue,&MsgZone,LOCKLENGTH,0) != SUCCESS )
			sleep( 1 );

		/* Wait for Lock Response Message */
		/* ------------------------------ */
		while ( msgrcv(lockqueue,&MsgZone,LOCKLENGTH,MsgZone.msg_id,MSG_NOERROR) < (sizeof(long) * 2 ))
			sleep(1);

		}
	return;

}

#ifdef RT_AIX
/*
 *	L I B E R F I L E ( File_Name )
 *	-----------------------------
 *	Liberate the CoExa Locking Infos for This File for every process
 *
 */

void	liberfile( fnom )
char *	fnom;
{

#ifdef	ABAL_TCPIP
	unsigned	char	lnom[65];
	if ( fn_parser( fnom, lnom, 1 ) != 0 )
		return;
#endif

	/* Check for Co-Executeur Lock manager active and Ready */
	/* ---------------------------------------------------- */
	if ( lockflag  == FAUX ) {
		if ( InitQueue() == FAILURE ) {
			return;
			}
		lockflag = VRAI;
		}

	/* Read File Statistics */
	/* -------------------- */
	if ( stat(fnom,&FichStat) == SUCCESS ) {

		/* Establish Lock Request Structure Infos */
		/* -------------------------------------- */
		MsgZone.AccessZone.lock_inode = FichStat.st_ino;
		MsgZone.AccessZone.lock_dnode = FichStat.st_dev;
		MsgZone.AccessZone.lock_owner = 0;
		MsgZone.AccessZone.lock_mode  = 0;
		MsgZone.AccessZone.lock_func  = COEXAFPURGE;
		MsgZone.msg_ds  = LOCKMSGID;
		MsgZone.msg_id  = (long) (getpid() + ECART);
		MsgZone.msg_err = SUCCESS;

		/* Send the Lock Request */
		/* --------------------- */
		while ( msgsnd(lockqueue,&MsgZone,LOCKLENGTH,0) != SUCCESS )
			sleep( 1 );

		/* Wait for Lock Response Message */
		/* ------------------------------ */
		while ( msgrcv(lockqueue,&MsgZone,LOCKLENGTH,MsgZone.msg_id,MSG_NOERROR) < (sizeof(long) * 2 ))
			sleep(1);

		}
	return;

}

#endif

/*
 *	M A T B ( fnom , Ex , C , Wr )
 *	------------------------------
 *	Modifies CoExa Locking Infos for This File
 *
 */

EXAWORD	matb( fnom , exflag , cflag , wrflag)
BPTR  fnom;
EXAWORD	exflag;
EXAWORD	cflag;
EXAWORD	wrflag;
{
	/* Check for Co-Executeur Lock manager active and Ready */
	/* ---------------------------------------------------- */
	if ( lockflag  == FAUX ) {
		if ( InitQueue() == FAILURE ) {
			return(FAILURE);
			}
		lockflag = VRAI;
		}

	/* Read File Statistics */
	/* -------------------- */
	if ( stat(fnom,&FichStat) == SUCCESS ) {

		/* Establish Lock Request Structure Infos */
		/* -------------------------------------- */
		MsgZone.AccessZone.lock_inode = FichStat.st_ino;
		MsgZone.AccessZone.lock_dnode = FichStat.st_dev;
		MsgZone.AccessZone.lock_owner = getpid();
		MsgZone.AccessZone.lock_mode  = (exflag==1? COEXAEXCLUSIVE : COEXASHARELOCK);
		MsgZone.AccessZone.lock_func  = COEXACHANGE;
		MsgZone.msg_ds  = LOCKMSGID;
		MsgZone.msg_id  = (long) (getpid() + ECART);
		MsgZone.msg_err = SUCCESS;

		/* Send the Lock Request */
		/* --------------------- */
		if (msgsnd(lockqueue,&MsgZone,LOCKLENGTH,0) == SUCCESS) {
		
			/* Wait for Lock Response Message */
			/* ------------------------------ */
			if ( msgrcv(lockqueue,&MsgZone,LOCKLENGTH,MsgZone.msg_id,MSG_NOERROR) >= (sizeof(long) * 2 )) {

				/* If no Error then OK lock establised */
				/* ----------------------------------- */
				if ( (errno = MsgZone.msg_err) == SUCCESS ) {
					return(SUCCESS);
					}
				}
			}

		}
	return(FAILURE);

}

/*
 *	P U R G E L O X ( )
 *	-------------------
 *	Liberate all remaining CoExa Lock Infos for This Process
 *
 */

void	PurgeLox( )
{
	/* Check for Co-Executeur Lock manager active and Ready */
	/* ---------------------------------------------------- */
	if ( lockflag  == FAUX ) {
		if ( InitQueue() == FAILURE ) {
			return;
			}
		lockflag = VRAI;
		}

	/* Establish Lock Request Structure Infos */
	/* -------------------------------------- */
	MsgZone.AccessZone.lock_inode = 0;
	MsgZone.AccessZone.lock_dnode = 0;
	MsgZone.AccessZone.lock_owner = getpid();
	MsgZone.AccessZone.lock_mode  = 0;
	MsgZone.AccessZone.lock_func  = COEXAPURGE;
	MsgZone.msg_ds  = LOCKMSGID;
	MsgZone.msg_id  = (long) (getpid() + ECART);
	MsgZone.msg_err = SUCCESS;

	/* Send the Lock Request */
	/* --------------------- */
	while ( msgsnd(lockqueue,&MsgZone,LOCKLENGTH,0) != SUCCESS )
		sleep(1);

	/* Wait for Lock Response Message */
	/* ------------------------------ */
	while ( msgrcv(lockqueue,&MsgZone,LOCKLENGTH,MsgZone.msg_id,MSG_NOERROR) < (sizeof(long) * 2 ))
		sleep(1);

	return;

}

/*
 *	P U R G E P I D ( )
 *	-------------------
 *	Liberate all remaining CoExa Lock Infos for a Process (for SuperUSer)
 *
 */

void	PurgePid(purgepid)
pid_t purgepid;
{
	/* Check for Co-Executeur Lock manager active and Ready */
	/* ---------------------------------------------------- */
	if ( lockflag  == FAUX ) {
		if ( InitQueue() == FAILURE ) {
			return;
			}
		lockflag = VRAI;
		}

	/* Establish Lock Request Structure Infos */
	/* -------------------------------------- */
	MsgZone.AccessZone.lock_inode = 0;
	MsgZone.AccessZone.lock_dnode = 0;
	MsgZone.AccessZone.lock_owner = purgepid;
	MsgZone.AccessZone.lock_mode  = 0;
	MsgZone.AccessZone.lock_func  = COEXAPURGE;
	MsgZone.msg_ds  = LOCKMSGID;
	MsgZone.msg_id  = (long) (getpid() + ECART);
	MsgZone.msg_err = SUCCESS;

	/* Send the Lock Request */
	/* --------------------- */
	while ( msgsnd(lockqueue,&MsgZone,LOCKLENGTH,0) != SUCCESS )
		sleep(1);

	/* Wait for Lock Response Message */
	/* ------------------------------ */
	while ( msgrcv(lockqueue,&MsgZone,LOCKLENGTH,MsgZone.msg_id,MSG_NOERROR) < (sizeof(long) * 2 ))
		sleep(1);

	return;

}


