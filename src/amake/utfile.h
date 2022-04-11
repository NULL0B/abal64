/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Project Maintanance 			*/
/*		----------------------------------			*/
/*									*/
/*		  Copyright (c) 1991 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	UTFILE.H				*/
/*		Version :	1.4b					*/
/*		Date	:	15/11/1991				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_UTFILE_H
#define	_UTFILE_H

#ifndef	UTFICHH
#define	UTFICHH
#ifdef DOS
#define	READPERM 0
#define CREATPERM 1
#define WRITEPERM 1
#endif

#ifdef PRL
#define	READPERM 0
#define WRITEPERM 1
#define CREATPERM 1
#endif

#ifndef VMS
#ifdef UNIX
#include <fcntl.h>
#define	READPERM O_RDONLY
#define WRITEPERM O_RDWR
#define CREATPERM 0666
#endif
#endif

#ifdef VMS
#include <file.h>
#define	READPERM O_RDONLY
#define WRITEPERM O_RDWR
#define CREATPERM 0666
#endif
#endif

#endif	/* _UTFILE_H */
	/* --------- */

