#ifndef _EXMPEGS_H
#define	_EXMPEGS_H

/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,2010 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXMPEGS.H  				*/
/*		Version :	3.3b 					*/
/*		Date 	:	27/11/2010				*/
/*									*/
/*----------------------------------------------------------------------*/
/*		EXMPEGS	:	Abal Runtime Remote Program Server	*/
/*----------------------------------------------------------------------*/

#define	_DEFAULT_ABAL_MPEGS_PORT	888
#define __USE_LARGEFILE64
#define	__USE_FILE_OFFSET64

#include <stdio.h>
#include <stdlib.h>			
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>			
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <openssl/ssl.h>
#include <errno.h>
#include <signal.h>

struct	remote_mpeg_server
{
	int	verbose;
	int	clients;
	int	port;
	int	domain;
	int	seconds;
	char *	root;
};

struct	mpeg_url	
{
	int	port;		/* either determined by the service analysis or behind ':' */
	char *	host;		/* between "//" and "/" after service and before object	   */ 
	char *	mpeg;	/* after the host or port over ride			   */
	char *	parameters;	/* beyond and including the '?'				   */
	char *	procedure;	/* beyond and including the '#'				   */
};


	/* -------- */
#endif	/* _EXMPEGS_H */
	/* -------- */


