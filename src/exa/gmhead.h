#define	EXABYTE	unsigned char
#define	EXAWORD	unsigned short int
#define ELIM_MAX 16

#ifdef DOS
#ifndef WIN32
#define	XPTR	far *
#endif /* WIN32 */
#define	READPERM 0
#define CREATPERM 1
#define WRITEPERM 1
#endif /* DOS */

#ifdef PRL
#define	XPTR	far *
#define	READPERM 0
#define WRITEPERM 1
#define CREATPERM 1
#endif

#ifdef UNX
#include <sys/types.h>
#include <fcntl.h>
#define	XPTR	*
#define	READPERM O_RDONLY
#define WRITEPERM O_RDWR
#define CREATPERM 0666
#endif

#ifdef VMS
#define	XPTR	*
#include <file.h>
#define	READPERM O_RDONLY
#define WRITEPERM O_RDWR
#define CREATPERM 0666
#endif

#define	BPTR	EXABYTE XPTR
#define	WPTR	EXAWORD XPTR

#ifdef	DOS
#define	CHEMINSEP 0x005C
#endif

#ifdef	PRL
#define	CHEMINSEP 0x005C
#endif

#ifdef	UNX
#define	CHEMINSEP '/'
#endif

#ifdef	VMS
#define	CHEMINSEP ']'
#endif

