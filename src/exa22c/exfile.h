/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXFILE - H				*/
/*		Version :	1.4a					*/
/*		Date 	:	12/11/1990				*/
/*									*/
/*----------------------------------------------------------------------*/

/*	Operating system dependant file access include files		*/
/*	----------------------------------------------------		*/

#ifndef	EXFILEH		/* If not already included			*/
#define	EXFILEH		/* Avoid succesive inclusions			*/

#ifdef	PROLOGUE
#include "exerrno.h"
#endif	/* PROLOGUE */

#ifdef DOS
#include <fcntl.h>
#include "exerrno.h"
#ifdef LOCKFBUG
#define XO_RDONLY O_RDWR
#else
#define	XO_RDONLY O_RDONLY
#endif
#endif	/* DOS */

#ifdef UNIX
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "exerrno.h"
#ifdef LOCKFBUG
#define XO_RDONLY O_RDWR
#else
#define	XO_RDONLY O_RDONLY
#endif
#endif	/* UNIX */

#ifdef	VMS
#include <file.h>
#define F_LOCK	0
#define	F_ULOCK	1
#define R_OK 4
#define W_OK 2
#define X_OK 1
#define F_OK 0
#define	O_SYNC	0
#endif	/* VMS */

#endif	/* ! EXFILEH	*/

