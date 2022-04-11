#ifndef	_BASIC_H
#define _BASIC_H

#ifdef	PROLOGUE /*FCH*/
#ifndef	____SMALL
#define	____FAR_DATA
#endif
#endif

#define	__BASIC_VERSION	"1.1a"
#define	__BASIC_DATE	"12/09/1997"

#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>

#ifdef WIN32
#include <io.h>
#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include "bdanettrace.h"
#ifdef	SYSTEM_SSL
/* 
Rappel pour utiliser openssl sous windows:
Intaller (voir www.openssl.org/related/binaries.html)
Ajouter le chemin dans VC (Tools/Options/Directories) pour includes et lib
Dans le projet, ajouter ssleay32MTd.lib ou ssleay32MT.lib pour debug et release 
*/
#include <openssl\ssl.h> 
#endif
#endif

#ifdef	UNIX
#define	_HTTP_SEMAPHORES 6
#include <sys/types.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
# include <sys/ipc.h>
# include <sys/sem.h>
#ifdef	SYSTEM_SSL
#include <openssl/ssl.h>
#endif
#else
#ifdef  PROLOGUE 
#include ".\include\sys\types.h"
#include ".\include\netdb.h"
#include ".\include\sys\socket.h"
#include ".\include\netinet\in.h"
unsigned long inet_addr( char * );
#endif
#endif

#define	allocate(n) malloc(n)
#define	liberate(p) free(p)

#ifdef	UNIX
#include <memory.h>
#include <time.h>
#else
extern	void *   	allocate( unsigned int );
extern	void   		liberate( void * );
extern  long   time( long *);
#endif

#ifdef	PROLOGUE
#define	MAX_NAME_LENGTH	320
#else
#define	MAX_NAME_LENGTH	4096
#endif
#define	MAX_BUFFER_SIZE 8192

#ifdef	UNIX
/*	------------------------------		*/
/*	child worker control structure		*/
/*	------------------------------		*/
struct	child_control	{
	int	worker;
	int	socket;
	void *	object;
	struct	child_control *	previous;
	struct	child_control *	next;
	};
#endif

#endif	/* _BASIC_H */
	/* -------- */

