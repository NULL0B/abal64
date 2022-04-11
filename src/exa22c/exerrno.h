/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXERRNO.H  				*/
/*		Version :	1.4a / 2.1a				*/
/*		Date 	:	04/08/1992				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	EXERRNOH
#define	EXERRNOH

#ifndef PROLOGUE

#include <errno.h>

#else

extern	 EXAWORD    errno;

#define  EZERO      0
#define  EPERM      1
#define  ESRCH      3
#define  EINTR      4
#define  EIO        5
#define  ENXIO      6
#define  E2BIG      7
#define  ENOEXEC    8
#define  ECHILD    10
#define  EAGAIN    11
#define  ENOMEM    12
#define  EFAULT    14
#define  ENOTBLK   15
#define  EBUSY     16
#define  ENODEV    19
#define  ENOTDIR   20
#define  EISDIR    21
#define  ENOTTY    25
#define  ETXTBSY   26
#define  EFBIG     27
#define  ESPIPE    29
#define  EACCES    30
#define  EROFS     30
#define  EMLINK    31
#define  EPIPE     32
#define  EDOM      33
#define  ERANGE    34
#define  EUCLEAN   35
#define  EDEADLOCK 36
#define  ENOENT    40
#define  EEXIST    41
#define  EOPEN	   43
#define  ENOPAR	   44
#define	 EBLOC	   45
#define  ENOSPC    46
#define	 EBADK	   47
#define  ECATF	   49
#define  EBADF     50
#define  ENFILE    51
#define  EMFILE    51
#define  EINVAL    53
#define	 EFONC 	   56
#define  EXDEV     80

#endif	/* !PROLOGUE */
	/* --------- */
#endif	/* EXERRNOH  */
	/* --------- */

