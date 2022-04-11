#ifndef	_exlock_c
#define	_exlock_c
/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1990 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXLOCK - C				*/
/*		Version :	1.2d / 1.3a / 1.4a			*/
/*		Date 	:	07/11/1990				*/
/*									*/
/*----------------------------------------------------------------------*/
#include "portage.h"
#include "exuser.h"		/* Message definition header		*/
#include "exlock.h"		/* Lock definition header		*/
#include <sys/ioctl.h>

#define	_USE_SYSLOG
#ifdef	_USE_SYSLOG
#include <syslog.h>
#endif

/*
 *	Adjustment of Message Start with respect to Structure 
 *	-----------------------------------------------------
 *
 */

#ifdef	x8086
#define	MsgIndent (sizeof(int) - sizeof(short int))
#endif

#ifndef	MsgIndent  
#define	MsgIndent	0
#endif

#include <stdio.h>		/* FILE pointer declarations		*/
#include <errno.h>

unsigned short int err_val;	/* Global System Error Variable		*/
extern	int	   UserMode;	/* User Arguament Flags			*/
extern	int	   Permission;	/* Installation success flag		*/
int		   auto_kill_zero=1;
int		   enforce_validity_checking=1;

void	set_mode_fast(int v)
{
	if ( v ) 
		auto_kill_zero = 0;
	else	auto_kill_zero = 1;
	return;
}

int	get_mode_fast()	{	return(( auto_kill_zero ? 0 : 1 )); 	}

struct exapadd Request;		/* Global Structure			*/

struct	lokpadd {
	struct exapadd lock_info; /* Lock Informations			*/
	int    lock_ctrl;	  /* Number of access by same process	*/
	struct lokpadd *fwdptr;	  /* Liste Forward Pointer		*/
	struct lokpadd *bakptr;	  /* Liste Back Wards Pointer		*/
	};

int	lock_compt;		/* Number of Lock Structures		*/
struct	lokpadd * lock_liste;	/* Pointer to Liste of Locked Files	*/


int pid_is_running (pid)
pid_t 	pid;
{
	if (!(pid))
		return(1);
	else if (!( kill(pid,0)))
		return(1);
	else 	return(0);
}

/*
 *	U S E R _ I N I T ( message_parameter_structure_pointer )
 *	---------------------------------------------------------
 *	Allows initialisation of the message manager parameter structure
 *	and initialisation of the AutoMate's own Variables
 *	(Called from MAIN() before IPC MSG FILE creation and before FORK()
 */

int user_init( mptr )
struct ipc_param * mptr;
{
	/* Message Parameter Initialisations */
	/* --------------------------------- */
	(*(mptr)).key = 13;		/* Message file Key value	*/
	(*(mptr)).max = sizeof(struct exapadd);	/* Maximum communication length	*/
	(*(mptr)).id  = 1L;		/* Automate recieve ID value	*/
	(*(mptr)).perm = 0;		/* Automate recieve permissions	*/
	(*(mptr)).opt = 0;		/* Automate child semaphore	*/

	/* Lock Management Initialisations */
	/* ------------------------------- */
	lock_liste = (struct lokpadd * ) 0;	/* Rest Lock Liste Pointer */
	lock_compt = 0;				/* Zero Lock Liste Counter */

	return(0);
}

void Suivi()
{
	int	lll;
	struct	lokpadd * wptr;
	printf("\nLock Liste Status : ");
	wptr = lock_liste; lll = 0;
	while ( wptr != (struct lokpadd *) 0 ) {
		lll++;
		printf("\n((%d)) (",lll);
		printf("X= %d, M= %d, O= %d , I= %d, D= %d )",wptr->lock_ctrl,wptr->lock_info.lock_mode,wptr->lock_info.lock_owner,wptr->lock_info.lock_inode,wptr->lock_info.lock_dnode);
		wptr = wptr->fwdptr;
		}
	printf("\n");
	return;
}


/*	-------------------------------------------------------		*/
/*	A B A L   3 . 1 a   P R O C E S S   M A N A G E M E N T 	*/
/*	-------------------------------------------------------		*/

#define	MAX_ACCESS_PROCESS 1000

static	int	ProcessLimit=0;
static	int	ProcessTable[MAX_ACCESS_PROCESS];

/*	----------------------------------	*/
/*	Allocation of a new Process Number	*/
/*	----------------------------------	*/

int	access_get_process()
{
	int	i;

	/* detect already allocated */
	/* ------------------------ */
	for ( i=0; i <= ProcessLimit; i++ )
		if ( ProcessTable[i]  == Request.lock_owner )
			return(i);

	/* allocate a new process number */
	/* ----------------------------- */
	for ( i=0; i < MAX_ACCESS_PROCESS; i++ ) {
		if (!( ProcessTable[i] )) {
			ProcessTable[i] = Request.lock_owner;
			if ( i > ProcessLimit )
				ProcessLimit = i;
			return(i);
			}
		}
	return(-1);
}

/*	-----------------------------------	*/
/*	Restitution of a new Process Number	*/
/*	-----------------------------------	*/

int	access_drop_process()
{
	int	i;
	for ( i=0; i < ProcessLimit; i++ ) {
		if ( ProcessTable[i] == Request.lock_owner ) {
			ProcessTable[i] = 0;
			return(0);
			}
		}
	return(-1);
}


/*	---------------------------------	*/
/*	Initialise Process Number Manager 	*/
/*	---------------------------------	*/

int	access_init_process()
{
	int	i;
	for ( i=0; i < MAX_ACCESS_PROCESS; i++ )
		ProcessTable[i] = 0;
	return(0);
}

#ifdef	COEXAMPURGE

#ifndef	MSG_EXCEPT
#define	MSG_EXCEPT (MSG_NOERROR*2)
#endif

int	purge_blocked_messages()
{
	int	n=0;

	MsgZone = ( struct ipc_zone *) malloc( mslng );

	/* Establish Lock Request Structure Infos */
	/* -------------------------------------- */
	MsgZone->AccessZone.lock_inode = 0;
	MsgZone->AccessZone.lock_dnode = 0;
	MsgZone->AccessZone.lock_owner = 0;
	MsgZone->AccessZone.lock_mode  = 0;
	MsgZone->AccessZone.lock_func  = 0;
	MsgZone->msg_ds  = LOCKMSGID;
	MsgZone->msg_id  = LOCKMSGID;
	MsgZone->msg_err = 0;

	/* Wait for Lock Response Message */
	/* ------------------------------ */
	while ( msgrcv(globalQid,MsgZone,LOCKLENGTH,LOCKMSGID,MSG_NOERROR| MSG_EXCEPT) > 0) {

		n++;

		printf("message %06.1u pid=%06.1u type=",n,MsgZone->AccessZone.lock_owner);

		switch ( MsgZone->AccessZone.lock_func ) {

			case MSGQSIZE  :
				printf("SET QUEUE SIZE( %u )",MsgZone->AccessZone.lock_inode );
				break;

			case SPEXARFILE :
			case DCEXARFILE :
				printf("RFILE(%s",MsgZone->AccessZone.lock_name);
				switch ( (MsgZone->AccessZone.lock_mode & COEXALOCKTYPE)) {
					case 1 : printf(",SHARED)");    	break;
					case 2 : printf(",EXCLUSIVE)"); 	break;
					default: printf(",ERROR)");	break;
					}
				break;
			case SPEXACFILE :
			case DCEXACFILE :
				printf("CFILE(%s",MsgZone->AccessZone.lock_name);
				switch ( (MsgZone->AccessZone.lock_mode & COEXALOCKTYPE) ) {
					case 1 : printf(",SHARED)");    	break;
					case 2 : printf(",EXCLUSIVE)"); 	break;
					default: printf(",ERROR)");	break;
					}
				break;
			case SPEXADFILE :
			case DCEXADFILE :
				printf("DFILE(%s)",MsgZone->AccessZone.lock_name);
				break;

			case SPEXAOPEN :
			case DCEXAOPEN : 
				printf("OPEN(");
				switch ( (MsgZone->AccessZone.lock_mode & COEXALOCKTYPE) ) {
					case 1 : printf("SHARED)");    	break;
					case 2 : printf("EXCLUSIVE)"); 	break;
					default: printf("ERROR)");	break;
					}
				break;
			case SPEXACLOSE:
			case DCEXACLOSE: printf("CLOSE"); break;
			case SPEXAPURGE:
			case DCEXAPURGE: printf("PURGE"); break;
			case SPEXACHANGE:
			case DCEXACHANGE:
				printf("CHANGE(");
				switch ( (MsgZone->AccessZone.lock_mode & COEXALOCKTYPE) ) {
					case 1 : printf("SHARED)");    	break;
					case 2 : printf("EXCLUSIVE)"); 	break;
					default: printf("ERROR)");	break;
					}
				break;
			case SPEXASTATUS :
			case DCEXASTATUS : printf("STATUS"); 		break;
			case SPEXAKILL   :
			case DCEXAKILL   : printf("KILL"); 		break;
			case GETPROCESS  : printf("GETPROCESS"); 	break;
			case DROPPROCESS : printf("DROPPROCESS"); 	break;
			default          : printf("UNKNOWN(%04d)",MsgZone->AccessZone.lock_func);
	

			}
		printf("\n");
		}
	return( n );
}

#endif	/* COEXAMPURGE */

int	AllowTrace=0;
char *	CoExaTraceName=(char *) 0;
FILE *	CoExaTrace=(FILE *) 0;

int	access_open_trace()
{
	if (!( AllowTrace ))
		return(0);
	else if (!( CoExaTrace )) {
		if (!( CoExaTraceName ))
			return(0);
		else if (!( CoExaTrace = fopen(CoExaTraceName,"w") ))
			return(0);
		}
	return(1);
}

void	access_write_trace( char * mptr )
{
	if (!( mptr ))
		return;

	if (!( access_open_trace() ))
		return;

	if (!( CoExaTrace ))
		return;

	fprintf(CoExaTrace,"%s\n",mptr);
	return;
}

void	access_request_trace()
{
	if (!( access_open_trace() ))
		return;

	fprintf(CoExaTrace,"ACCESS (F=");
	switch ( Request.lock_func ) {

		case MSGQSIZE  :
			fprintf(CoExaTrace,"SET QUEUE SIZE( %u )",Request.lock_inode );
			break;

		case SPEXACFILE :
		case DCEXACFILE :
			fprintf(CoExaTrace,"CFILE(%s",Request.lock_name);
			switch ( (Request.lock_mode & COEXALOCKTYPE) ) {
				case 1 : fprintf(CoExaTrace,",SHARED)");    	break;
				case 2 : fprintf(CoExaTrace,",EXCLUSIVE)"); 	break;
				default: fprintf(CoExaTrace,",ERROR)");	break;
				}
			break;
		case SPEXARFILE :
		case DCEXARFILE :
			fprintf(CoExaTrace,"RFILE(%s",Request.lock_name);
			switch ( (Request.lock_mode & COEXALOCKTYPE) ) {
				case 1 : fprintf(CoExaTrace,",SHARED)");    	break;
				case 2 : fprintf(CoExaTrace,",EXCLUSIVE)"); 	break;
				default: fprintf(CoExaTrace,",ERROR)");	break;
				}
			break;

		case SPEXADFILE :
		case DCEXADFILE :
			fprintf(CoExaTrace,"DFILE(%s)",Request.lock_name);
			break;

		case SPEXAOPEN :
		case DCEXAOPEN : 
			fprintf(CoExaTrace,"OPEN(%s)",Request.lock_name);
			switch ( (Request.lock_mode & COEXALOCKTYPE) ) {
				case 1 : fprintf(CoExaTrace,"SHARED)");    	break;
				case 2 : fprintf(CoExaTrace,"EXCLUSIVE)"); 	break;
				default: fprintf(CoExaTrace,"ERROR)");	break;
				}
			break;

		case SPEXACLOSE:
		case DCEXACLOSE:
			fprintf(CoExaTrace,"CLOSE(%s)",Request.lock_name); 
			break;

		case SPEXAPURGE:
		case DCEXAPURGE: 
			fprintf(CoExaTrace,"PURGE"); 
			break;

		case SPEXACHANGE:
		case DCEXACHANGE:
			fprintf(CoExaTrace,"CHANGE(%s)",Request.lock_name);
			switch ( ( Request.lock_mode & COEXALOCKTYPE ) ) {
				case 1 : fprintf(CoExaTrace,"SHARED)");    	break;
				case 2 : fprintf(CoExaTrace,"EXCLUSIVE)"); 	break;
				default: fprintf(CoExaTrace,"ERROR)");	break;
				}
			break;
		case SPEXASTATUS :
		case DCEXASTATUS : fprintf(CoExaTrace,"STATUS"); 		break;
		case SPEXAKILL   :
		case DCEXAKILL   : fprintf(CoExaTrace,"KILL"); 		break;
		case GETPROCESS  : fprintf(CoExaTrace,"GETPROCESS"); 	break;
		case DROPPROCESS : fprintf(CoExaTrace,"DROPPROCESS"); 	break;
		default          : fprintf(CoExaTrace,"UNKNOWN(%04d)",Request.lock_func);


		}

	fprintf(CoExaTrace,",O=%d, I=%d, D=%d ) : ",Request.lock_owner,Request.lock_inode,Request.lock_dnode);

	return;
}

void	access_close_trace()
{
	if (!( AllowTrace ))
		return;
	if (!(CoExaTrace ))
		return;
	fclose( CoExaTrace );
	CoExaTrace = (FILE *) 0;
	return;
}

int	access_trace_name(char * nptr)
{
	int	level=0;

	if (!( nptr  )) return(AllowTrace);
	if (!( *nptr )) return(AllowTrace);

	access_close_trace();

	if ( CoExaTraceName ) {
		free( CoExaTraceName );
		CoExaTraceName = (char *) 0;
		AllowTrace = 0;
		}

	if ( *nptr == '-' ) return( AllowTrace );

	if ( *nptr == '+' ) {
		nptr++;
		level++;
		if (!( *nptr )) nptr = "/tmp/accesstrace";
		}

	if (!( CoExaTraceName = malloc( strlen( nptr ) + 1 ) ))
		return((AllowTrace=0));
	else	{
		strcpy(CoExaTraceName,nptr);
		return((AllowTrace=(level+1)));
		}
}

void	dbaccess_write_trace( char * message )
{
	if ( AllowTrace > 1 ) {
		access_write_trace(message);
		}
}


static	int	access_alert( struct lokpadd * wptr, char * mptr )
{
	char	message[1024];

	if (!( wptr )) 	return(0);

	sprintf(message,"alert(%s,file=%s,pid=%u,inode=%lu,dnode=%lu,sh=%u,nb=%u)",
		(mptr ? mptr : "\0"),
		wptr->lock_info.lock_name,
		wptr->lock_info.lock_owner,
		wptr->lock_info.lock_inode,
		wptr->lock_info.lock_dnode,
		wptr->lock_info.lock_mode,
		wptr->lock_ctrl );

	access_write_trace( "(*)" );
	access_write_trace( message );

#ifdef	_USE_SYSLOG
	syslog(LOG_CRIT,message);
#else
	if ( UserMode & 1 ) {
		printf("%s\n",message);
		}
#endif
	return(0);
}

static	int	file_exists(struct lokpadd * wptr)
{
	struct	stat	fstat;
	if ( wptr->lock_info.lock_name[0] != '/' )
		return(1);
	else if ( stat(wptr->lock_info.lock_name,&fstat) != SUCCESS )
		return(0);
	else	return(1);
}

/*	-------------------------------------------------	*/
/*	c h e c k _ r e c o r d _ v al i d i t y ( wptr )	*/
/*	-------------------------------------------------	*/
/*	It appears that certain files are being declared	*/
/*	for reservation with access but are being deleted	*/
/*	using RM or other system file deletion means and	*/
/*	this without access being aware. This leaves a 		*/
/*	file reservation record with redundant and even		*/
/*	conflictual information. The Inode may have been	*/
/*	recycled for use by another file and may result		*/
/*	in error 44 being returned for unlocked files.		*/
/*	-------------------------------------------------	*/

static	int	check_record_validity(struct lokpadd * wptr)
{
	struct	stat	fstat;

	if (!( enforce_validity_checking )) {
		return(1); /* not required so ok */
		}
	else if ( wptr->lock_info.lock_name[0] != '/' ) {
		/* --------------------------------------------- */
		/* old type access request with no full pathname */
		/* file validity checking is impossible so avoid */
		/* --------------------------------------------- */
		return( 1 ); /* pretend ok */
		}
	else if ( stat(wptr->lock_info.lock_name,&fstat) != SUCCESS )
		return( access_alert(wptr, "incorrect file" ) );

	else if ( fstat.st_dev != Request.lock_dnode )
		return( access_alert(wptr, "incorrect dnode" ) );

	else if ( fstat.st_ino != Request.lock_inode )
		return( access_alert(wptr, "incorrect inode" ) );

	else if (!( kill(wptr->lock_info.lock_owner,0) ))
		return(1); /* record is valid */
	else	return( access_alert(wptr, "incorrect process" ) );
}

static	struct lokpadd * access_drop_lock( struct lokpadd * wptr )
{
	struct	lokpadd * fptr;

	/* -------------- */
	/* avoid problems */
	/* -------------- */
	if (!( wptr ))	return( wptr );

	/* ---------------------- */
	/* unlink the lock record */
	/* ---------------------- */
	if ((fptr = wptr->fwdptr) !=  (struct lokpadd *) 0 )
		fptr->bakptr = wptr->bakptr;

	if ( wptr->bakptr !=  (struct lokpadd *) 0 )
		wptr->bakptr->fwdptr = wptr->fwdptr;
	else 	lock_liste = wptr->fwdptr; 

	/* ----------------------- */
	/* release the lock record */
	/* ----------------------- */
	free (wptr);
	
	/* ------------------------------ */
	/* return the next record pointer */
	/* ------------------------------ */
	return( fptr );
}

int	access_unlock_file()
{
	struct	lokpadd * wptr;
	struct	lokpadd * hptr;
	int	x;
	int	status;

	x = 0; status = -1;

	for (	wptr = lock_liste;
		wptr != (struct lokpadd *) 0;
		wptr = wptr->fwdptr ) {

		/* Check for File Identifier and Owner Matching */
		/* -------------------------------------------- */
		if (( wptr->lock_info.lock_inode == Request.lock_inode ) 
		&&  ( wptr->lock_info.lock_dnode == Request.lock_dnode )
		&&  ( wptr->lock_info.lock_owner == Request.lock_owner )) {

			/* Decrement Entry Usage control Counter */
			/* ------------------------------------- */
			if ( wptr->lock_ctrl ) wptr->lock_ctrl--;

			/* Zero means we can liberate it now */
			/* --------------------------------- */
			if (!( wptr->lock_ctrl ))
				wptr = access_drop_lock( wptr );
						
			/* Indicate Sucessful Close Operation */
			/* ---------------------------------- */
			if ( UserMode & 1 ) { Suivi(); }
			break;
			}
		}
	return(0);
}

int	access_change_lock()
{
	struct	lokpadd * wptr;
	struct	lokpadd * hptr;
	int	x;
	int	status;
	
	/* ------------------------------------ */
	/* Initialise Table management pointers */
	/* ------------------------------------ */
	wptr = lock_liste; hptr = (struct lokpadd * ) 0;

	/* ---------------------- */
	/* While not end of Liste */
	/* ---------------------- */
	while ( wptr != (struct lokpadd *) 0 ) {

		/* ----------------------------------------- */
		/* Check for File Unique identifier Matching */
		/* ----------------------------------------- */
		if (( wptr->lock_info.lock_inode == Request.lock_inode ) 
		&&  ( wptr->lock_info.lock_dnode == Request.lock_dnode )) {

			/* -------------------- */
			/* Check for Same Owner */
			/* -------------------- */
			if ( wptr->lock_info.lock_owner == Request.lock_owner ) {

				/* -------------------------------- */
				/* Test for Exclusive Requested	    */
				/* -------------------------------- */
				if ( (Request.lock_mode & COEXALOCKTYPE) == COEXAEXCLUSIVE ) {

					/* ----------------------- */
					/* Check for Unique Access */
					/* ----------------------- */
					if ( wptr->lock_ctrl > 1 ) {
						/* -------------------------------------- */
						/* Exclusivity Refused : multiple Sharing */
						/* -------------------------------------- */
						return(44);
						}
					else	{
						/* ------------------------------------- */
						/* Exclusivity Possible : Unique Access  */
						/* But First Check for Exclusive already */
						/* ------------------------------------- */
						if ( (wptr->lock_info.lock_mode & COEXALOCKTYPE) == COEXAEXCLUSIVE ) {
							/* ------------------------------*/
							/* Already Exclusive OK no error */
							/* ----------------------------- */
							return(0);
							}
						else	{
							/* ------------------------------------ */
							/* SHARED MODE Check for Others	        */
							/* Keep Current pointer and Rescan List */
							/* for other process shared locks which */
							/* will cause refusal of request        */
							/* ------------------------------------ */
							if ( hptr == (struct lokpadd *) 0) {
								hptr = wptr;
								wptr = wptr->fwdptr;
								continue;
								}
							else	{
								/* Whoops fragmented Table */
								/* ----------------------- */
								return(44);
								}
							}
						}				
					}
				else	{
					/* Shared mode requested : Easy Do it now */
					/* -------------------------------------- */
					wptr->lock_info.lock_mode = COEXASHARELOCK;
					return(0);
					}
				}
			else	{
				/* File Match Found But Different Owner */
				/* Check for EXCLUSIVE or SHARED modes  */
				/* ------------------------------------ */
				if ( (Request.lock_mode & COEXALOCKTYPE) == COEXAEXCLUSIVE ) {
					/* Exclusive Request Refused since */
					/* File is already shared 	   */
					/* ------------------------------- */
					return(44);
					}
				else	{
					/* OK we can continue the list scanning */
					/* ------------------------------------ */
					wptr = wptr->fwdptr;
					continue;
					}
				}
			}
		else	{
			/* ------------------------------ */
			/* File Not Matching So Seek Next */
			/* ------------------------------ */
			wptr = wptr->fwdptr;
			continue;
			}
		}
	/* ----------------------------------------------------------- */
	/* Arrival here means the file has not been declared for COEXA */
	/* or no one else is sharing the file so Exclusivity Granted   */
	/* ----------------------------------------------------------- */
	if ( hptr == (struct lokpadd *) 0 ) {
		/* File Not Declared Open */
		/* ---------------------- */
		return(42);
		}
	else	{
		/* OK for Exclusive request */
		/* ------------------------ */
		hptr->lock_info.lock_mode = COEXAEXCLUSIVE;
		return(0);
		}
}

int	access_lock_file()
{
	struct	lokpadd * wptr;
	struct	lokpadd * hptr;
	int	x;
	int	status;
	
	/* --------------------------------------------- */
	/* Check for Network Device Node (NFS) 		 */
	/* --------------------------------------------- */
	x = 0; status = -1; wptr = lock_liste; hptr = wptr;

	while ( wptr != (struct lokpadd *) 0 ) {

		/* Check for File Unique identifier Matching */
		/* ----------------------------------------- */
		if (( wptr->lock_info.lock_inode == Request.lock_inode ) 
		&&  ( wptr->lock_info.lock_dnode == Request.lock_dnode )) {

			/* Check for Same Owner */
			/* -------------------- */
			if ( wptr->lock_info.lock_owner == Request.lock_owner ) {

				/* Test for Exlusive Requested	    */
				/* -------------------------------- */
				if ( (Request.lock_mode & COEXALOCKTYPE) == COEXAEXCLUSIVE ) {
					status = 0; /* Denied */
					}
				else if ( (wptr->lock_info.lock_mode & COEXALOCKTYPE) == COEXAEXCLUSIVE ) {
					status = 0; /* Shared Rejected */
					}
				else	{ /* Shared Accepted */
					wptr->lock_ctrl = wptr->lock_ctrl + 1;
					status = 1;
					}
				break;
				}
			else	{
				/* Not the Same Owner */
				/* ------------------ */
				if ( (Request.lock_mode & COEXALOCKTYPE) == COEXAEXCLUSIVE ) {
	
					/* Exclusivity Demanded Rejected */
					/* ----------------------------- */
					status = 0;
					break;
					}

				/* Test for Already held EXCLUSIVE */
				/* ------------------------------- */
				if ( (wptr->lock_info.lock_mode & COEXALOCKTYPE) == COEXAEXCLUSIVE ) {
					/* Shared Mode Demanded Rejected */
					/* ----------------------------- */
					status = 0;
					break;
					}

				/* ---------------------------------------- */
				/* Arrival Here Means We Can Share the File */
				/* But First we must check to See if there  */
				/* is another record in the Liste for this  */
				/* File for This process	CONTINUE    */
				/* ---------------------------------------- */
				hptr = wptr;
				wptr = wptr->fwdptr;
				}
			}
		else	{
			/* ------------------------------ */
			/* File Not Matching So Seek Next */
			/* ------------------------------ */
			hptr = wptr;
			wptr = wptr->fwdptr;
			}
		}
	switch ( status ) {
		case 1 :
			/* Succesful Completion nothing to Do */
			/* ---------------------------------- */
			if ( UserMode & 1 ) { Suivi(); 	}
			return(0);

		case 0 :
			/* Exclusive/Share Request Failure */
			/* ------------------------------- */
			if (!( wptr )) 	return(44);
			
			/* Ensure Rejection Reason is Valid */
			/* -------------------------------- */
			else if ( check_record_validity(wptr) )
				return(44);

			else	{
				/* The Rejection is not Valid so Replace */
				/* ------------------------------------- */
				wptr->lock_ctrl = 1;
				memcpy(&wptr->lock_info,&Request,sizeof(struct exapadd));
				if ( UserMode & 1 ) { Suivi(); }
				return(0);
				}
		case -1:
			/* Succesful completion add to List */
			/* -------------------------------- */
			wptr = (struct lokpadd *) malloc ( sizeof(struct lokpadd) );
			if ( wptr == (struct lokpadd *) 0 ) { status = 0; }
			else	{
				if ( hptr != (struct lokpadd *) 0 ) {
					hptr->fwdptr = wptr;
					}
				else	{
					lock_liste = wptr;
					}
				wptr->bakptr = hptr;
				wptr->fwdptr = (struct lokpadd *) 0;
				wptr->lock_ctrl = 1;
				memcpy(&wptr->lock_info,&Request,sizeof(struct exapadd));
				status = 1;
				}
			if ( UserMode & 1 ) { Suivi(); }
			return(0);
		}
	return(56);
}

int	access_rename_file()
{
	struct	lokpadd * wptr;

	/* Scan list of records to find matching record */
	/* -------------------------------------------- */
	for (	wptr = lock_liste;
		wptr != (struct lokpadd *) 0;
		wptr = wptr->fwdptr  )
		if (( wptr->lock_info.lock_inode == Request.lock_inode ) 
		&&  ( wptr->lock_info.lock_dnode == Request.lock_dnode )
		&&  ( wptr->lock_info.lock_owner == Request.lock_owner ))
			break;

	/* unknown source file */
	/* ------------------- */
	if (!( wptr )) {
		dbaccess_write_trace("file not locked");
		return( 40 );
		}
	/* detect presence of target */
	/* ------------------------- */
	else if ( access(Request.lock_name,F_OK) == 0 )  {
		dbaccess_write_trace("file exists");
		return( 41 );
		}
	/* attempt to rename the file */
	/* -------------------------- */
	else if ( rename( wptr->lock_info.lock_name, Request.lock_name ) != SUCCESS ) {
		dbaccess_write_trace("rename failure");
		return( 42 );
		}
	/* store the new name record */
	/* ------------------------- */
	else	{
		strcpy( wptr->lock_info.lock_name, Request.lock_name );
		return( 0 );
		}
}

int	access_create_file()
{
	struct	stat	fstat;
	int	h;
	int	cmode;

	if (!(cmode = (Request.lock_mode >> COEXALOCKSHIFT)))
		cmode = 0666;

	if ( access(Request.lock_name,F_OK) == 0) {
		dbaccess_write_trace("file exists");
		return( 41 );
		}
	else if((h=creat(Request.lock_name,cmode)) < 0) {
 		dbaccess_write_trace( "creat failure" );
		return( errno );
		}
	else	{
		dbaccess_write_trace("unlink ok");
		close(h);
		if ( stat(Request.lock_name,&fstat) != SUCCESS ) {
	 		dbaccess_write_trace( "stat failure" );
			return(errno);
			}
		else	{
			dbaccess_write_trace("stat ok");
			if (( Request.lock_inode != 0 ) && ( Request.lock_dnode != 0 )) {
				chown(Request.lock_name,Request.lock_inode,Request.lock_dnode);
				}
			Request.lock_inode = fstat.st_ino;
			Request.lock_dnode = fstat.st_dev;
			chmod( Request.lock_name,cmode); 
			return( access_lock_file() );
			}
		}
}

int	access_delete_file()
{
	int	status;
	struct	stat	fstat;
	if ( stat(Request.lock_name,&fstat) != SUCCESS ) {
		dbaccess_write_trace("file not found");
		return(40);
		}
	else	{
		dbaccess_write_trace("file found");
		Request.lock_inode = fstat.st_ino;
		Request.lock_dnode = fstat.st_dev;
		if ((status = access_lock_file()) != 0) {
			dbaccess_write_trace("unable to lock file");
			return( status );
			}
		else	{
			if ( unlink(Request.lock_name) != SUCCESS )
				dbaccess_write_trace( "unlink failure" );
			else	dbaccess_write_trace("unlink ok");
			return( access_unlock_file() );
			}
		}
}

int	access_report_status( int status )
{
	char buffer[256];
	if (!( status ))
		access_write_trace("OK");
	else 	{
		sprintf(buffer,"ERR(%u)",status);
		access_write_trace( buffer );
		}
	return( status );
}


int	access_stat_correction()
{
	int	status;
	struct	stat	fstat;

	/* assume ok if not full pathname */
	/* ------------------------------ */
	if ( Request.lock_name[0] != '/' )
		return(0);

	else if ( stat(Request.lock_name,&fstat) != SUCCESS ) {
		dbaccess_write_trace("stat correction failure");
		return(40);
		}
	else	{
		Request.lock_inode = fstat.st_ino;
		Request.lock_dnode = fstat.st_dev;
		return(0);
		}
}


/*
 *	U S E R _ M A I N ( message_text_pointer , message_id_number )
 *	--------------------------------------------------------------
 *	This function is called by the message manager to honour the
 *	received message function request
 */

int ll_user_main()
{                                                                                 
	struct	lokpadd * wptr;
	struct	lokpadd * hptr;
	int	running=0;
	int	status;
	int	x;
	int	statistix=0;
	FILE	* CoExaCore;
        char tempBuf[250];

	if ( UserMode & 1 ) {
		printf("\nACCESS (F=");
		switch ( Request.lock_func ) {

			case MSGQSIZE  :
				printf("SET QUEUE SIZE( %u )",Request.lock_inode );
				break;

			case SPEXARFILE :
			case DCEXARFILE :
				printf("RFILE(%s",Request.lock_name);
				switch ( (Request.lock_mode & COEXALOCKTYPE) ) {
					case 1 : printf(",SHARED)");    	break;
					case 2 : printf(",EXCLUSIVE)"); 	break;
					default: printf(",ERROR)");	break;
					}
				break;

			case SPEXACFILE :
			case DCEXACFILE :
				printf("CFILE(%s",Request.lock_name);
				switch ( (Request.lock_mode & COEXALOCKTYPE) ) {
					case 1 : printf(",SHARED)");    	break;
					case 2 : printf(",EXCLUSIVE)"); 	break;
					default: printf(",ERROR)");	break;
					}
				break;

			case SPEXADFILE :
			case DCEXADFILE :
				printf("DFILE(%s)",Request.lock_name);
				break;

			case SPEXAOPEN :
			case DCEXAOPEN : 
				printf("OPEN(");
				switch ( (Request.lock_mode & COEXALOCKTYPE) ) {
					case 1 : printf("SHARED)");    	break;
					case 2 : printf("EXCLUSIVE)"); 	break;
					default: printf("ERROR)");	break;
					}
				break;
			case SPEXACLOSE:
			case DCEXACLOSE: printf("CLOSE"); break;
			case SPEXAPURGE:
			case DCEXAPURGE: printf("PURGE"); break;
			case SPEXACHANGE:
			case DCEXACHANGE:
				printf("CHANGE(");
				switch ( (Request.lock_mode & COEXALOCKTYPE) ) {
					case 1 : printf("SHARED)");    	break;
					case 2 : printf("EXCLUSIVE)"); 	break;
					default: printf("ERROR)");	break;
					}
				break;
			case SPEXASTATUS :
			case DCEXASTATUS : printf("STATUS"); 		break;
			case SPEXAKILL   :
			case DCEXAKILL   : printf("KILL"); 		break;
			case GETPROCESS  : printf("GETPROCESS"); 	break;
			case DROPPROCESS : printf("DROPPROCESS"); 	break;
			default          : printf("UNKNOWN(%04d)",Request.lock_func);
	

			}

		printf(",O=%d, I=%d, D=%d )",Request.lock_owner,Request.lock_inode,Request.lock_dnode);

		}

	switch ( Request.lock_func ) {

#ifdef	COEXAMPURGE
		case COEXAMPURGE:	return( purge_blocked_messages() );
#endif
		case MSGQSIZE  :	return( set_queue_size(Request.lock_inode) );

		case GETPROCESS :	return( access_get_process() );

		case DROPPROCESS:	return( access_drop_process() );

		/* 	--------------------	*/
		/*	File Create and Lock	*/
		/* 	--------------------	*/

		case DCEXACFILE	:	if ( Permission != SUCCESS ) { return(666); }

		case SPEXACFILE	:	return( access_create_file() );


		/* 	--------------------	*/
		/*	File Rename and Lock	*/
		/* 	--------------------	*/

		case DCEXARFILE	:	if ( Permission != SUCCESS ) { return(666); }

		case SPEXARFILE	:	return( access_rename_file() );


		/* 	----------------------		*/
		/*	File Delete and Unlock		*/
		/* 	----------------------		*/

		case DCEXADFILE	:	if ( Permission != SUCCESS ) { return(666); }

		case SPEXADFILE :	return( access_delete_file() );


		/* 	---------	*/
		/*	File Lock 	*/
		/* 	---------	*/

		case DCEXAOPEN :	if ( Permission != SUCCESS ) { return(666); }

		case SPEXAOPEN :	
			if ((status = access_stat_correction()) != 0)
				return( status );
			else	return( access_lock_file() );

		/* 	-----------	*/
		/*	File UnLock	*/
		/* 	-----------	*/
		case SPEXACLOSE:
		case DCEXACLOSE:
			if ((status = access_stat_correction()) != 0)
				return( status );
			return( access_unlock_file()  );


		/* 	----------	*/
		/*	File Purge 	*/
		/* 	----------	*/

		case DCEXAPURGE :
		case SPEXAPURGE :
			access_drop_process();
			wptr = lock_liste;

			while ( wptr != (struct lokpadd *) 0 ) {

				/* Check for Same Owner */
				/* -------------------- */
				if (( ! Request.lock_owner )
				||  ( wptr->lock_info.lock_owner == Request.lock_owner )) {
					if (!( wptr = access_drop_lock( wptr )))
						break;
					}
				else	wptr = wptr->fwdptr;
				}

			/* This may inhibit return messages */
			/* -------------------------------- */
			set_queue_silence( Request.lock_mode );
			return(0);

		/*	--------------------------------------		*/
		/*	Modification of Current Opening Method		*/
		/*	Change mode : Exclusive , or Shared 		*/
		/*	--------------------------------------		*/
		case DCEXACHANGE :
		case SPEXACHANGE :

			if ((status = access_stat_correction()) != 0)
				return( status );
			else	return( access_change_lock() );

		/*	---------------------------------------------	*/
		/*	Output statistics to Standard COEXA CORE file 	*/
		/*	---------------------------------------------	*/
		case DCEXASTATUSF :
		case SPEXASTATUSF :
			auto_kill_zero = 0;

		case DCEXASTATUS  :
		case SPEXASTATUS  :

			access_trace_name(Request.lock_name);

			/* Attempt to open or Create Core File */
			/* ----------------------------------- */
			if (!( CoExaCore = fopen("/tmp/accesscore","w"))) 
				return(errno);
 
			/* Core File Header       */
			/* ----------------	  */
			fprintf(CoExaCore, "\n| File Access Manager Status: Pid:%d, Msg key: 0x%x, Qsize: %u",getpid(),getqid(),get_queue_size());
			fprintf(CoExaCore, "\n|------------------------------------------------------------------------------|");
			fprintf(CoExaCore, "\n| I node  | D node  | P.I.D. | Mode(N) |            file name                  |");
			fprintf(CoExaCore, "\n|------------------------------------------------------------------------------|");
			statistix=0;	

			/* While not end of Liste */
			/* ---------------------- */
			wptr = lock_liste;
			while ( wptr != (struct lokpadd *) 0 ) {

				if (!( running = pid_is_running(wptr->lock_info.lock_owner) )) {
					sprintf(tempBuf,"REDUNDANT");
			    		}

				else if (!( running = file_exists(wptr) )) {
					sprintf(tempBuf,"DESTROYED");
			    		}

				else	{              
			    	        /* Display Mode and, if Shared, Count */
					/* ---------------------------------- */
					statistix++;
					if ( (wptr->lock_info.lock_mode  & COEXALOCKTYPE)== COEXAEXCLUSIVE ) {
						sprintf(tempBuf,"EXCLUSIVE");
						}
					else	{
						sprintf(tempBuf,"SHARE(%2ld)",wptr->lock_ctrl);
						}
					}
				/* Output File and Owner details */
				/* ----------------------------- */
				fprintf(CoExaCore,"\n|%9ld|%9ld|%8ld|%9s|%s",
					wptr->lock_info.lock_inode,wptr->lock_info.lock_dnode,
					wptr->lock_info.lock_owner,
			                tempBuf,
					wptr->lock_info.lock_name );

				if (!( running )) {
					access_alert( wptr, tempBuf );
					wptr = access_drop_lock( wptr );
					}
				else	wptr = wptr->fwdptr;

				}
			/* Close the core file */  
			/* ------------------- */
			fprintf(CoExaCore,"\n|------------------------------------------------------------------------------|");
			fprintf(CoExaCore, "\n| File Access Manager Status: %u, Pid:%d, Msg key: 0x%x, Qsize: %u, Nb: %u",auto_kill_zero,getpid(),getqid(),get_queue_size(),statistix);
			if (( AllowTrace ) && ( CoExaTraceName )) {
				fprintf(CoExaCore, "\n| Tracing Requests to file  : %s ",CoExaTraceName);
				}
			fprintf(CoExaCore,"\n|------------------------------------------------------------------------------|\n");
			fclose(CoExaCore);
			return(0);

case DCEXAKILL :
case SPEXAKILL :
		access_close_trace();
		(void) ExUserKill(15);
		exit(0);
		
		/*	------------------------------------------------------------	*/
		/*	All other commands are Reserved for Extension and Return 56	*/
		/*	------------------------------------------------------------	*/
		default	     :	
			if ( UserMode & 1 ) {
				printf("\nUnknown function request #%d\n",Request.lock_func);
				}
			return( 56 );
		}

}


int user_main( msgptr , msgrcvid )
char * msgptr;	
long msgrcvid;
{                                                                                 
	/* Duplicate in Lock Structure */
	/* --------------------------- */
	int	wtf=MsgIndent;
#ifdef	ABAL64
	wtf += sizeof(int);
#endif
	memcpy( &Request , (msgptr+wtf) , sizeof(struct exapadd) ); 

	access_request_trace();

	return( access_report_status( ll_user_main() ) );
}

#endif  /* _exlock_c */
	/* --------- */




