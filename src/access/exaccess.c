/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXACCESS.C				*/
/*		Date 	:	01/12/2010				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_exaccess_c
#define	_exaccess_c

#ifdef	VERSION666
#define __USE_LARGEFILE64
#define	__USE_FILE_OFFSET64
#endif

#include <syslog.h>	/* system log facilities			*/

#include "portage.h"
#include "exlock.h"	/* Lock message interface definitions		*/
#include "exaccess.h"	/* Version redefinitions Diffusion or Test	*/
#include <string.h>	/* system log facilities			*/


#define true   1
#define false  0

#define	VRAI		1	/* True result flag			*/
#define	FAUX		0	/* False result flag			*/
#define	ECART		1	/* Adjustment Value for recieve message	*/
#define	FAILURE		-1    	/* Function failure			*/
#define	MSGFILEID	13	/* Message file used for LOCK IPC	*/
#define	LOCKMSGID	1L	/* Message Type ID code			*/

//-------------------------------------------------------
static struct	stat	FichStat;	/* File Statistics Structure		*/

static int	lockflag=FAUX;		/* Initialisation status		*/

//-------------------------------------------------------
//---------------------------------------------------------------

struct	lockreq {
	long	       msg_ds;	/* Message a Envoyer			*/
	long	       msg_id;	/* Sender ID				*/
	short int      msg_err;	/* Error Flag				*/
	struct exapadd AccessZone;/* Lock Details Structure		*/
	} MsgZone;		/* File Locking Structure		*/

#define LOCKLENGTH (sizeof(struct lockreq) - sizeof( long ))

// typedef char bool;
//---------------------------------------------------------------

static	void	exaccess_failure( mptr, fptr, errval )
	char *	mptr;
	char *	fptr;
	int	errval;
{
	char	msgbuffer[256];
	int	level=LOG_CRIT;
	sprintf(msgbuffer,"access: %s: %s failure : %u",mptr,fptr, errval);
	syslog( level,"%s", msgbuffer );
	return;
}

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

char	CwdBuffer[1024];

static	int	check_queue_access()
{
	if (( lockflag  == FAUX )
	||  ( lockqueue == -1   )) 
	{
		if ( InitQueue() == FAILURE ) {
			return(0);
			}
		lockflag = VRAI;
	}
	return(1);
}

int	Access( nomfic , perm , mode )

char *		nomfic;		/* Nom du Fichier a controller 		*/
int		perm;		/* Permission requise d'access		*/
int		mode;		/* 0 => Shared , 1 = Exclusive		*/

{
#ifdef	NOACCESS
	return( SUCCESS );
#endif
	/* Test for File Existance (normal Unix Procedure) */
	/* ----------------------------------------------- */
	if (!( perm )) { perm  = F_OK; }
	if ( access( nomfic , perm ) != SUCCESS ) 	{	return( FAILURE ); 	}
	else						{	return( SUCCESS );	}

	/* Check for Co-Executeur Lock manager active and Ready */
	/* ---------------------------------------------------- */
	if (!( check_queue_access() )) return( FAILURE );

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

		if ( *nomfic == '/' )
	                strcpy(MsgZone.AccessZone.lock_name,nomfic);
		else	sprintf(MsgZone.AccessZone.lock_name,"%s/%s",getcwd(CwdBuffer,1024),nomfic);

		if ( strlen(MsgZone.AccessZone.lock_name) >= MAXLOCKNAME ) {
			errno = 30;
			return(FAILURE);
			}

		/* Send the Lock Request */
		/* --------------------- */
		if (msgsnd(lockqueue,&MsgZone,LOCKLENGTH,0) == SUCCESS) {
		
			/* Wait for Lock Response Message */
			/* ------------------------------ */
			if ((USINT) msgrcv(lockqueue,&MsgZone,LOCKLENGTH,MsgZone.msg_id,MSG_NOERROR) >=(USINT) (sizeof(long) * 2 )) {

				/* If no Error then OK lock establised */
				/* ----------------------------------- */
				if ( (errno = MsgZone.msg_err) == SUCCESS ) 
				    {
					return(SUCCESS);
				    }
		     					      	      
				}
			else	{
				/* Erreur de reception de message */
				/* ------------------------------ */
				exaccess_failure("reservation", "msgrcv", errno );
				}
			}
		else	{
			/* Erreur de expedition de message */
			/* ------------------------------- */
			exaccess_failure("reservation", "msgsnd", errno );

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

void	liberlox( nomfic )
char *	nomfic;
{
	
#ifdef	ABAL_TCPIP
	unsigned	char	lnom[65];
	if ( fn_parser( fnom, lnom, 1 ) != 0 )
		return;
#endif

	/* Check for Co-Executeur Lock manager active and Ready */
	/* ---------------------------------------------------- */
	if (!( check_queue_access() )) return;

	/* Read File Statistics */
	/* -------------------- */
	if ( stat(nomfic,&FichStat) == SUCCESS ) {

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

		if ( *nomfic == '/' )
	                strcpy(MsgZone.AccessZone.lock_name,nomfic);
		else	sprintf(MsgZone.AccessZone.lock_name,"%s/%s",getcwd(CwdBuffer,1024),nomfic);

		if ( strlen(MsgZone.AccessZone.lock_name) >= MAXLOCKNAME ) {
			errno = 30;
			return;
			}

		/* Send the Lock Request */
		/* --------------------- */
		while ( msgsnd(lockqueue,&MsgZone,LOCKLENGTH,0) != SUCCESS ) {
			exaccess_failure("release", "msgsnd", errno );
			sleep( 1 );
			}

		/* Wait for Lock Response Message */
		/* ------------------------------ */
		while ( (USINT) msgrcv(lockqueue,&MsgZone,LOCKLENGTH,MsgZone.msg_id,MSG_NOERROR) < (USINT) (sizeof(long) * 2 )) {
			exaccess_failure("release", "msgrcv", errno );
			sleep(1);
			}
		}
	return;

}

/*
 *	U N L I N K L O X ( File_Name )
 *	-------------------------------
 *	Exclusive Locks the File (if it can),
 *	Deletes It (if it can) 
 *	then Releases the Lock  and returns SUCCESS
 *	otherwise returns FAILURE
 *
 */

int 	unlinklox( nomfic )
char *	nomfic;
{
	int	status;

	/* Check for Co-Executeur Lock manager active and Ready */
	/* ---------------------------------------------------- */
	if (!( check_queue_access() )) return( FAILURE );
	
	if ((status = Access(nomfic,O_RDWR,VRAI)) != SUCCESS)
		return(FAILURE);
	else	{
		if ( unlink(nomfic) < 0 )
			status = FAILURE;
		else	status = SUCCESS;

		MsgZone.AccessZone.lock_mode  = 0;
		MsgZone.AccessZone.lock_func  = COEXACLOSE;
		MsgZone.msg_ds  = LOCKMSGID;
		MsgZone.msg_id  = (long) (getpid() + ECART);
		MsgZone.msg_err = SUCCESS;

		/* Send the Lock Request */
		/* --------------------- */
		while ( msgsnd(lockqueue,&MsgZone,LOCKLENGTH,0) != SUCCESS ) {
			exaccess_failure("unlink", "msgsnd", errno );
			sleep( 1 );
			}

		/* Wait for Lock Response Message */
		/* ------------------------------ */
		while ( (USINT) msgrcv(lockqueue,&MsgZone,LOCKLENGTH,MsgZone.msg_id,MSG_NOERROR) < (USINT) (sizeof(long) * 2 )) {
			exaccess_failure("unlink", "msgrcv", errno );
			sleep(1);
			}

		return( status );
		}

}


/*
 *	R E N A M E L O X ( Old Name, New Name )
 *	----------------------------------------
 *	Attempts to lock the source file and then to rename it as 
 *	the target file, then releasing the lock.
 */

int 	renamelox( sname, tname )
char *	sname;
char *	tname;
{

	/* Check for Co-Executeur Lock manager active and ready */
	/* ---------------------------------------------------- */
	if (!( check_queue_access() )) 	return((errno=56));

	/* Check and complete the full path name */
	/* ------------------------------------- */
	if ( *sname == '/' )
                strcpy(MsgZone.AccessZone.lock_name,sname);
	else	sprintf(MsgZone.AccessZone.lock_name,"%s/%s",getcwd(CwdBuffer,1024),sname);

	if ( strlen(MsgZone.AccessZone.lock_name) >= MAXLOCKNAME ) {
		return((errno = 30));
		}

	if ( stat(MsgZone.AccessZone.lock_name,&FichStat) != SUCCESS )
		return((errno=40));

	/* Establish Lock Request Structure Infos */
	/* -------------------------------------- */
	MsgZone.AccessZone.lock_inode = FichStat.st_ino;
	MsgZone.AccessZone.lock_dnode = FichStat.st_dev;
	MsgZone.AccessZone.lock_owner = getpid();
	MsgZone.AccessZone.lock_mode  = COEXAEXCLUSIVE;

	/* Attempt to rename the file */
	/* -------------------------- */
	MsgZone.AccessZone.lock_func  = COEXARFILE;
	if ( *tname == '/' )
                strcpy(MsgZone.AccessZone.lock_name,tname);
	else	sprintf(MsgZone.AccessZone.lock_name,"%s/%s",getcwd(CwdBuffer,1024),tname);

	if ( strlen(MsgZone.AccessZone.lock_name) >= MAXLOCKNAME ) {
		return((errno = 30));
		}

	MsgZone.msg_ds  = LOCKMSGID;
	MsgZone.msg_id  = (long) (getpid() + ECART);
	MsgZone.msg_err = SUCCESS;

	/* Send the Lock Request */
	/* --------------------- */
	while ( msgsnd(lockqueue,&MsgZone,LOCKLENGTH,0) != SUCCESS ) {
		exaccess_failure("rfile", "msgsnd", errno );
		sleep( 1 );
		}

	/* Wait for Lock Response Message */
	/* ------------------------------ */
	while ( (USINT) msgrcv(lockqueue,&MsgZone,LOCKLENGTH,MsgZone.msg_id,MSG_NOERROR) < (USINT) (sizeof(long) * 2 )) {
		exaccess_failure("rfile", "msgrcv", errno );
		sleep(1);
		}

	if ( (errno = MsgZone.msg_err) == SUCCESS ) 
		return( SUCCESS );
	else	return( errno  );

}

/*
 *	C R E A T E L O X P E R M ( File_Name, lockmode, fileperm )
 *	-----------------------------------------------------------
 *	Tests for existance of a file returning error 41 if true.
 *	Otherwise creates the file and locks it as required.
 *
 */

int 	createloxperm( nomfic, mode,fileperm )
char *	nomfic;
int	mode;
int	fileperm;
{
	/* Check for Co-Executeur Lock manager active and ready */
	/* ---------------------------------------------------- */
	if (!( check_queue_access() )) return( FAILURE );
		
	MsgZone.AccessZone.lock_inode = getuid();
	MsgZone.AccessZone.lock_dnode = getgid();
	MsgZone.AccessZone.lock_owner = getpid();
	MsgZone.AccessZone.lock_mode  = ((mode == VRAI) ? COEXAEXCLUSIVE : COEXASHARELOCK );
	MsgZone.AccessZone.lock_mode  |= (fileperm << COEXALOCKSHIFT); 
	MsgZone.AccessZone.lock_func  = COEXACFILE;
	if ( *nomfic == '/' )
                strcpy(MsgZone.AccessZone.lock_name,nomfic);
	else	sprintf(MsgZone.AccessZone.lock_name,"%s/%s",getcwd(CwdBuffer,1024),nomfic);

	if ( strlen(MsgZone.AccessZone.lock_name) >= MAXLOCKNAME ) {
		errno = 30;
		return(FAILURE);
		}

	MsgZone.msg_ds  = LOCKMSGID;
	MsgZone.msg_id  = (long) (getpid() + ECART);
	MsgZone.msg_err = SUCCESS;

	/* Send the Lock Request */
	/* --------------------- */
	while ( msgsnd(lockqueue,&MsgZone,LOCKLENGTH,0) != SUCCESS ) {
		exaccess_failure("cfile", "msgsnd", errno );
		sleep( 1 );
		}

	/* Wait for Lock Response Message */
	/* ------------------------------ */
	while ( (USINT) msgrcv(lockqueue,&MsgZone,LOCKLENGTH,MsgZone.msg_id,MSG_NOERROR) < (USINT) (sizeof(long) * 2 )) {
		exaccess_failure("cfile", "msgrcv", errno );
		sleep(1);
		}

	if ( (errno = MsgZone.msg_err) == SUCCESS ) 
		return( SUCCESS );
	else	return( FAILURE );

}

/*
 *	C R E A T E L O X ( File_Name, mode )
 *	-------------------------------------
 *	Tests for existance of a file returning error 41 if true.
 *	Otherwise creates the file and locks it as required.
 *
 */

int 	createlox( nomfic, mode )
char *	nomfic;
int	mode;
{
	return( createloxperm( nomfic, mode, 0666 ) );
}



/*
 *	D E L E T E L O X ( File_Name )
 *	-------------------------------
 *	Tests for file usage, returns error 44 if true.
 *	Otherwise deletes the file.
 *
 */

int 	deletelox( nomfic )
char *	nomfic;
{
	int	mode=VRAI;

	/* Check for Co-Executeur Lock manager active and Ready */
	/* ---------------------------------------------------- */
	if (!( check_queue_access() )) return( FAILURE );
	
	MsgZone.AccessZone.lock_inode = 0;
	MsgZone.AccessZone.lock_dnode = 0;
	MsgZone.AccessZone.lock_owner = getpid();
	MsgZone.AccessZone.lock_mode  = 0;
	MsgZone.AccessZone.lock_mode  = ((mode == VRAI) ? COEXAEXCLUSIVE : COEXASHARELOCK );
	MsgZone.AccessZone.lock_func  = COEXADFILE;
	if ( *nomfic == '/' )
                strcpy(MsgZone.AccessZone.lock_name,nomfic);
	else	sprintf(MsgZone.AccessZone.lock_name,"%s/%s",getcwd(CwdBuffer,1024),nomfic);

	if ( strlen(MsgZone.AccessZone.lock_name) >= MAXLOCKNAME ) {
		errno = 30;
		return(FAILURE);
		}

	MsgZone.msg_ds  = LOCKMSGID;
	MsgZone.msg_id  = (long) (getpid() + ECART);
	MsgZone.msg_err = SUCCESS;

	/* Send the Lock Request */
	/* --------------------- */
	while ( msgsnd(lockqueue,&MsgZone,LOCKLENGTH,0) != SUCCESS ) {
		exaccess_failure("dfile", "msgsnd", errno );
		sleep( 1 );
		}

	/* Wait for Lock Response Message */
	/* ------------------------------ */
	while ( (USINT) msgrcv(lockqueue,&MsgZone,LOCKLENGTH,MsgZone.msg_id,MSG_NOERROR) < (USINT) (sizeof(long) * 2 )) {
		exaccess_failure("dfile", "msgrcv", errno );
		sleep(1);
		}

	if ( (errno = MsgZone.msg_err) == SUCCESS ) 
		return( SUCCESS );
	else	return( FAILURE );

}


/*
 *	M A T B ( fnom , Ex , C , Wr )
 *	------------------------------
 *	Modifies CoExa Locking Infos for This File
 *
 */
int	matb( nomfic , exflag , cflag , wrflag)
char *  nomfic;
WORD	exflag;
WORD	cflag;
WORD	wrflag;
{
	/* Check for Co-Executeur Lock manager active and Ready */
	/* ---------------------------------------------------- */
	if (!( check_queue_access() )) return( FAILURE );

	/* Read File Statistics */
	/* -------------------- */
	if ( stat(nomfic,&FichStat) == SUCCESS ) {

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

		if ( *nomfic == '/' )
	                strcpy(MsgZone.AccessZone.lock_name,nomfic);
		else	sprintf(MsgZone.AccessZone.lock_name,"%s/%s",getcwd(CwdBuffer,1024),nomfic);

		if ( strlen(MsgZone.AccessZone.lock_name) >= MAXLOCKNAME ) {
			errno = 30;
			return(FAILURE);
			}

		/* Send the Lock Request */
		/* --------------------- */
		if (msgsnd(lockqueue,&MsgZone,LOCKLENGTH,0) == SUCCESS) {
		
			/* Wait for Lock Response Message */
			/* ------------------------------ */
			if ( (USINT) msgrcv(lockqueue,&MsgZone,LOCKLENGTH,MsgZone.msg_id,MSG_NOERROR) >= (USINT)(sizeof(long) * 2 )) {

				/* If no Error then OK lock establised */
				/* ----------------------------------- */
				if ( (errno = MsgZone.msg_err) == SUCCESS ) {
					return(SUCCESS);
					}
				}
			else	{
				exaccess_failure("matb", "msgrcv", errno );
				}
			}
		else	{
			exaccess_failure("matb", "msgsnd", errno );
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
	char *	eptr;
	return;

	/* Check for Co-Executeur Lock manager active and Ready */
	/* ---------------------------------------------------- */
	if (!( check_queue_access() )) return;

	if ( lockqueue == -1 )	return;

	/* Establish Lock Request Structure Infos */
	/* -------------------------------------- */
	MsgZone.AccessZone.lock_inode = 0;
	MsgZone.AccessZone.lock_dnode = 0;
	MsgZone.AccessZone.lock_owner = getpid();

	if (!( eptr = getenv("ACCESSPURGE")))
		MsgZone.AccessZone.lock_mode  = 0;
	else if (( *eptr >= '0' ) && ( *eptr <= '9'))
		MsgZone.AccessZone.lock_mode  = (*eptr - '0' );
	else	MsgZone.AccessZone.lock_mode  = 0;

	MsgZone.AccessZone.lock_func  = COEXAPURGE;
	MsgZone.msg_ds  = LOCKMSGID;
	MsgZone.msg_id  = (long) (getpid() + ECART);
	MsgZone.msg_err = SUCCESS;
        strcpy(MsgZone.AccessZone.lock_name," ");
	/* Send the Lock Request */
	/* --------------------- */
	while ( msgsnd(lockqueue,&MsgZone,LOCKLENGTH,0) != SUCCESS ) {
		exaccess_failure("purge", "msgsnd", errno );
		sleep(1);
		}

	if (!( MsgZone.AccessZone.lock_mode )) {

		/* Wait for Lock Response Message */
		/* ------------------------------ */
		while ( (USINT) msgrcv(lockqueue,&MsgZone,LOCKLENGTH,MsgZone.msg_id,MSG_NOERROR) < (USINT) (sizeof(long) * 2 )) {
			exaccess_failure("purge", "msgrcv", errno );
			sleep(1);
			}

		}
	return;

}


int	access_process_number()
{
	/* Check for Co-Executeur Lock manager active and Ready */
	/* ---------------------------------------------------- */
	if (!( check_queue_access() )) return( 0 );

	/* Establish Lock Request Structure Infos */
	/* -------------------------------------- */
	MsgZone.AccessZone.lock_inode = 0;
	MsgZone.AccessZone.lock_dnode = 0;
	MsgZone.AccessZone.lock_owner = getpid();
	MsgZone.AccessZone.lock_mode  = GETPROCESS;
	MsgZone.AccessZone.lock_func  = GETPROCESS;
	MsgZone.msg_ds  = LOCKMSGID;
	MsgZone.msg_id  = (long) (getpid() + ECART);
	MsgZone.msg_err = SUCCESS;

	/* Send the Lock Request */
	/* --------------------- */
	if (msgsnd(lockqueue,&MsgZone,LOCKLENGTH,0) == SUCCESS) {
		
		/* Wait for Lock Response Message */
		/* ------------------------------ */
		if ((USINT) msgrcv(lockqueue,&MsgZone,LOCKLENGTH,MsgZone.msg_id,MSG_NOERROR) >=(USINT) (sizeof(long) * 2 )) {

			/* If no Error then OK process id */
			/* ------------------------------ */
			return( MsgZone.msg_err );
	     					      	      
			}
		else	{
			exaccess_failure("process", "msgrcv", errno );
			}
		}
	else	{
		exaccess_failure("process", "msgsnd", errno );
		}

	return(0);
}

	/* ----------- */
#endif	/* _exaccess_c */
	/* ----------- */

