/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1990 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDAEMON - C				*/
/*		Version : 	2.1d					*/
/*		Date 	:	22/12/1995				*/
/*									*/
/*----------------------------------------------------------------------*/
#include <stdio.h>
#include <signal.h>
#include "exuser.h"
#include <sys/stat.h>

extern	int	errno;
#ifdef	BSD
#include <sys/file.h>
#include <sys/ioctl.h>
#endif

#define SUCCESS 0
#define FAILURE -1
#define	VRAI	1
#define	FAUX	0

#define	QF_SPAWN	1
#define	QF_QUEUE	2
#define	QF_PURGE	4
#define	QF_STATUS	8
#define	QF_LIBER	16
#define QF_RECUPER	32
#define QF_KILLQUEUE	64
#define	QF_SILENCE	128
#define QF_FPURGE	256

/*
 *	Prototypes of external and internal functions 
 *	---------------------------------------------
 */

int	activate_service();
int 	liberate_service();
int 	purger();
int 	reporter();
void	SessDetatch();
int	fpurger();


extern	int	UserMode;

static	char 	daemonid[]="go";

struct	stat	statwork;

#define	CONTROLFORM "/**/\0\0\0\0\0\0\0\0                                /**/"
#define	CONTROLNODE 8
#define	CONTROLUNIT 4

static	unsigned char	ControlZone[]=CONTROLFORM;
	char	initargs[256];

	char	checkid[256];

	int	Permission;

	int	AlarmDuree;

long	AbalLong( lptr )
unsigned char * lptr;
{
	long	lwork;
	int	x;

	for (x=3, lwork=0; x >=0; x--) { 
		lwork = ((lwork << 8) | ((long) *(lptr + x)));
		}
	return( lwork );
}

void	ErrorMsg(nptr,xptr,msgqueue,mode)
char	*	nptr;
char	*	xptr;
key_t		msgqueue;
int		mode;
{

	if ((mode & QF_SILENCE) == 0) {
		fprintf(stderr,"%s %s:",nptr,xptr); 
		if ( errno != 0 ) 	{
			perror("");
			}
		else	{
			fprintf(stderr," communication error ");
			}
		if ( msgqueue != 0 ) 	{
			fprintf(stderr," message queue %d\n",msgqueue);
			}
		else	{
			fprintf(stderr,"\n");
			}
		}
	return;

}

/*
 *	Entry point from operating system or (EXEC)
 *	-------------------------------------------
 *
 */

main(argc,argv)
int	argc;
char	*argv[];
{
	int	y;
	int	i,x;
	int	mode;
	char  * wptr;
	key_t	msgqueue;
	int	pidpurge;
	int	initspawn;
	char *  Xargv[4];
	int	inopurge;

	/* Check for Daemon Args provided : Banner if None */
	/* ----------------------------------------------- */
	if ( argc < 2 ) 
	{
		fprintf(stderr, "\n   File access manager Version 5.1.0 ");
		fprintf(stderr, "\n   Copyright (c) 2022 Amenesik / Sologic \n");
		exit(0);
	}

	/* Initialise all Variables */
	/* ------------------------ */
	i = 1; mode =0;	
	initspawn = FAUX; 
	checkid[0] = (char) 0;
	msgqueue = 13;	pidpurge   = 0;
	UserMode = 0;	AlarmDuree = 5; 

	/* Analyse Command line arguaments */
	/* ------------------------------- */

	while ( i < argc ) {
		wptr = argv[i++];
		while ( *wptr != (char) 0 ) {
			switch ( *(wptr++) ) {
				case 's' :	mode |= QF_SILENCE;
						continue;
				case 'v' :	UserMode |= 1;
						continue;
				case 'k' :	mode |= QF_KILLQUEUE;
				case ' ' :
				case '-' :	continue;
				case 'l' :	mode |= QF_LIBER;
						continue;
				case 'r' :	mode |= QF_RECUPER;
						continue;
				case 'I' :	initspawn = VRAI;
				case 'i' :	strcpy(checkid,wptr);
						wptr += strlen(wptr);
						mode |= QF_SPAWN;
						continue;
				case 'q' :	mode |= QF_QUEUE;
						msgqueue = atoi(wptr);
						wptr += strlen(wptr);
						continue;
				case 'p' :	mode |= QF_PURGE;
						pidpurge = atoi(wptr);
						wptr += strlen(wptr);
						continue;
				case 'f' :	mode |= QF_FPURGE;
						inopurge = atoi(wptr);
						wptr += strlen(wptr);
						continue;
				case 't' :	mode |= QF_STATUS;
						continue;
				case 'a' :	AlarmDuree = atoi(wptr);
						wptr += strlen(wptr);
						continue;
				default  :	fprintf(stderr,"\n   %s: Option unrecognised : %s\n",argv[0],argv[--i]);
						exit(0);

				}
			}

		}
	
	/* Analyse options requested */
	/* ------------------------- */
	if ( mode & QF_KILLQUEUE ) {
		if ( killqueue( msgqueue ) != SUCCESS ) {
			ErrorMsg(argv[0]," -k",msgqueue,mode);
			}

		}

	/* Check for disactivation required */
	/* -------------------------------- */
	if ( mode & QF_LIBER ) {
		if ( liberate_service( msgqueue ) != SUCCESS ) {
			ErrorMsg(argv[0]," -l",msgqueue,mode);
			}
		} 	

	/* Check for Startup required */
	/* -------------------------- */
	if ( mode & QF_SPAWN ) {

		/* Check for Initialisation key matchs */
		/* ----------------------------------- */
		if ( strcmp(checkid,daemonid) == 0 ) {

			/* -------------------------------------- */
			/* Test here for legality of Installation */
			/* -------------------------------------- */

			Permission = SUCCESS;


			/* -------------------------------------- */
			/* Check for INODE == 0 : Version de Test */
			/* -------------------------------------- */
			if ( AbalLong(&ControlZone[CONTROLNODE]) != 0L ) {

				/* -------------------------------------- */
				/* 1) perform stat() on argv[0]		  */
				/* -------------------------------------- */
					if ( stat(argv[0],&statwork) == 0 ) {

						/* ------------------------------------------ */
						/* Compare INODE and DNODE for correspondance */
						/* ------------------------------------------ */
						if ((AbalLong(&ControlZone[CONTROLNODE]) != statwork.st_ino) || (AbalLong(&ControlZone[CONTROLUNIT]) != statwork.st_dev)) {
							Permission = FAILURE;
							}
						}
					else	{
						Permission = FAILURE;
						}

					}

			/* ------------------------------------------------ */
			/* Arrival here means Initialisation OK : do EXUSER */
			/* ------------------------------------------------ */
			return( activate_service( msgqueue ) );

			}
		else	{
			if (( mode & QF_RECUPER ) == 0 ) {
				/* Arrival Here means we must detatch and Execute */
				/* ---------------------------------------------- */
				if (openqueue(msgqueue) != FAILURE) {
					ErrorMsg(argv[0]," -i",msgqueue,mode);
					exit(0);
					}
				}
			/* Check execution possible */
			/* ------------------------ */
			if ( access( argv[0] , 1 ) == -1 ) {
				ErrorMsg(argv[0]," -i",0,mode);
				exit(2);
				}

			/* Prepare Xargv */
			/* ------------- */
			Xargv[0] = argv[0];

			/* Detatch Parent */
			/* -------------- */
			(void) SessDetatch(initspawn);
		
			/* Prepare Spawning args */
			/* --------------------- */
			if ( initspawn == VRAI ) {
				strcpy( initargs , "-I");
				}
			else	{
				strcpy( initargs , "-i");
				}
			strcat( initargs , daemonid );
			Xargv[1] = initargs;
			x = strlen(initargs);
			Xargv[2] = (char * ) 0;
			Xargv[3] = (char * ) 0;

			/* Check for Message Queue Modified */
			/* -------------------------------- */
			if ( mode & QF_QUEUE ) {
				sprintf(&initargs[x+2],"-q%d",msgqueue);
				Xargv[2] = &initargs[x+2];
				}
			/* Launch the Daemon */
			/* ----------------- */
			execl(Xargv[0],Xargv[0],Xargv[1],Xargv[2],Xargv[3]);

			/* Whoops what went wrong ? */
			/* ------------------------ */
			exit(2);

			}
		
		}

	/* Check for status reporting */
	/* -------------------------- */
	if ( mode & QF_STATUS ) {
		if ( reporter( msgqueue ) != SUCCESS ) {
			ErrorMsg(argv[0]," -t",msgqueue,mode);
			}
		}

	/* Check for Purge required  */
	/* ------------------------  */
	if ( mode & QF_PURGE ) {
		if ( purger( msgqueue , pidpurge ) != SUCCESS ) {
			ErrorMsg(argv[0]," -p",msgqueue,mode);
			}
		}
	/* Check for File Purge required  */
	/* ------------------------  */
	if ( mode & QF_FPURGE ) {
		if ( fpurger( msgqueue , inopurge ) != SUCCESS ) {
			ErrorMsg(argv[0]," -f",msgqueue,mode);
			}
		}


	return(0);

}

void	Politesse()
{
	(void) alarm(10);
	(void) wait((int *) 0);
	(void) alarm(0);
	return;
}

void	SessDetatch(i)
int	i;
{
	int	fd;

	if ( i  == FAUX )  {	/* Not an init spawned Process */
#ifdef SIGTTOU		 
		signal(SIGTTOU , SIG_IGN);
#endif
#ifdef SIGTTIN		 
		signal(SIGTTIN , SIG_IGN);
#endif
#ifdef SIGTSTP
		signal(SIGTSTP , SIG_IGN);
#endif
		/* If Parent then Wait till Death of Child then Exit */
		/* ------------------------------------------------- */
		if ( fork() != 0 ) { Politesse(); exit(0); }

#ifdef	BSD
		setpgrp(0,getpid());
		if ((fd = open("/dev/tty",O_RDWR)) >= 0 ) {
			ioctl(fd,TIOCNOTTY, 0);
			close(fd);
			}
		else	{ exit(2); }
#else
		/* Lose Controlling terminal and set process group */
		/* ----------------------------------------------- */
		setpgrp();

		/* If Parent then Wait till Death of Child then Exit */
		/* ------------------------------------------------- */
		if ( fork() != 0 ) { Politesse(); exit(0); }

#endif


		}

	/* Close All Files !!! */
	/* ------------------- */
#if defined(UNIXWARE) ||defined(LINUX)
	for ( fd = 0; fd < 1024   ; fd++ ) { close(fd); }
#else
	for ( fd = 0; fd < _NFILE ; fd++ ) { close(fd); }
#endif
	
	/* Set Root Directory , File Permissions then Return */
	/* ------------------------------------------------- */
	chdir("/");	umask(0);	return;

}
