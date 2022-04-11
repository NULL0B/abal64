/*----------------------------------------------------------------------*/
/*									*/
/*		---------------------------------------			*/
/*		  Copyright (c) 1989,1990 Amenesik / Sologic s.a.			*/
/*		---------------------------------------			*/
/*		Project		:	ABAL MAKE			*/
/*		Module		:	GMHEAD-H			*/
/*		Version		:	1.1a				*/
/*		Date		:	20/02/1990			*/
/*		---------------------------------------			*/
/*									*/
/*----------------------------------------------------------------------*/


#define	ELIMINMAX	32
#define SEARCHMAX	32

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

#ifdef UNIX
#include <sys/types.h>
#include <fcntl.h>
#define	READPERM O_RDONLY
#define WRITEPERM O_RDWR
#define CREATPERM 0666
#endif

#ifdef VMS
#include <file.h>
#define	READPERM O_RDONLY
#define WRITEPERM O_RDWR
#define CREATPERM 0666
#define unlink(a) delete(a)
#define Access(a,b,c) GmAccess(a,b,c)
#endif

#ifdef	DOS
#define	CHEMINSEP 0x005C
#endif

#ifdef	PRL
#define	CHEMINSEP 0x005C
#endif

#ifdef	UNIX
#define	CHEMINSEP '/'
#endif

#ifdef	VMS
#define	CHEMINSEP ']'
#endif

#ifdef	UNIX
WORD	fn_parser();
#else
WORD	fn_parser( BPTR , BPTR , WORD );
#endif

