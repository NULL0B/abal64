#ifndef _EXRPS_H
#define	_EXRPS_H

/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,2010 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXRPS.H  				*/
/*		Version :	3.3b 					*/
/*		Date 	:	27/11/2010				*/
/*									*/
/*----------------------------------------------------------------------*/
/*		EXRPS	:	Abal Runtime Remote Program Server	*/
/*----------------------------------------------------------------------*/

#define	_DEFAULT_ABAL_RPS_PORT	888
#define __USE_LARGEFILE64
#define	__USE_FILE_OFFSET64

#include "exnetwork.h"
struct	remote_program_server
{
	int	useaddress;
	char *	argvzero;
	int	verbose;
	int	debug;
	int	clients;
	int	port;
	int	domain;
	int	seconds;
	char *	root;
	char *	method;
	char *	hostname;
	char *  logname;
	struct sockaddr_in address;
};

#include "exurl.h"

	/* -------- */
#endif	/* _EXRPS_H */
	/* -------- */


