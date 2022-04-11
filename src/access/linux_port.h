/* Linux Porting header */
#ifndef LINUX_PORT_H
#define LINUX_PORT_H

#ifdef	VERSION666
//#define __USE_LARGEFILE64
//#define	__USE_FILE_OFFSET64
#endif

#ifndef UNIX
 #define UNIX
#endif
#ifndef GNU
 #define GNU
#endif
#ifndef DG
 #define DG
#endif
// #define _TRACE_

#ifndef LINT_ARGS
 #define LINT_ARGS
#endif

#define DEBUG

#ifndef LIBEXA  // to make lib for exa

#define ISLOCAL
#define ISUNXSRV
#define RSUNXSRV
#define SERV
#define ISUNIX
#else
#define ABAL_CRITERIA

#endif 		//LIBEXA

#define __USE_XOPEN

#define HANDLE_PRAGMA      1
#define HANDLE_SYSV_PRAGMA 1
#define ENT_BUFCOM_SIZE ((U32) 12)
#define OFFSET_TYPE_REQ ((U32) 8)
#define OFFSET_ERR_COM ((U32) 6)
#define LG_CTRL_COM	((U32) 2)

#ifdef ISREDIR
#error "pas de redirecteur sous unix"
#endif
      #include <sys/stat.h>
      #include <unistd.h>
      #include <errno.h>

#include <stdlib.h>  // atoi , atol ...

#include <unistd.h>  // cuserid ...
#include <stdio.h>
#include <fcntl.h>
/* Messages sous UNIX */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
/* Memoire partagee sous UNIX */
#include <sys/shm.h>
/* Signaux sous UNIX */
#include <signal.h>
/* Semaphores sous UNIX */
#include <sys/wait.h>
#include <sys/sem.h>
// ENOMEM
//////////////////////////////// headers

#ifndef HANDLE_PRAGMA
#error "no pragma supported : define: HANDLE_PRAGMA "
#endif
#ifndef HANDLE_SYSV_PRAGMA
#error "no pragma pack supported : define: HANDLE_SYSV_PRAGMA "
#endif
//#define HANDLE_PRAGMA_PACK_PUSH_POP 1 


// I tryed to put all typedef for linux here !
// !! pas de #define Xptr X *
///////////////////////////////////////////////////////////////////
typedef signed    char      S8;		/* 8 bit signed */
typedef unsigned  char      U8;		/* 8 bit unsigned */
typedef signed    short int S16;		/* 16 bit signed */
typedef unsigned  short int U16;		/* 16 bit unsigned */
typedef signed    long      S32;
typedef unsigned  long	    U32;		/* 32 bit unsigned */
typedef char           *    CPTR;
typedef	unsigned char  *    BPTR;
#define		SPTR   *

typedef S8   * S8PTR;
typedef S16  * S16PTR;
typedef S32  * S32PTR;
typedef U8   * U8PTR;
typedef U16  * U16PTR;
typedef U32  * U32PTR;
      
typedef char 		   bool;
#define BOOL               bool
typedef unsigned char 	   BYTE;
typedef char *		   LPSTR;
#define FAR
typedef long *		   LPLONG;
#define FARPROC		   LPLONG       // ??? linux ???
#define INT                int
typedef int * LPINT;
//#define LPINT		   int *
typedef BYTE *		   LPBYTE;
typedef short int	   BINAIRE;	/* Declare TYPE 15 bit word	*/
typedef unsigned short int WORD;	/* Declare TYPE 16 bit word	*/
typedef	unsigned long	   ULONG;	/* unsigned long integer	*/
typedef unsigned int       UINT;
#define	VOID               void
#define	LONG               long
typedef unsigned  int	   USINT;

typedef	unsigned short int SPTR WPTR; 	/* Unsigned short int Pointers	*/

#ifndef VPTR
typedef void * VPTR;
//#define VPTR void SPTR			/* General purpose pointer cast */
#endif

#define true  1
#define false 0
#define MAX_PATH 260
 

/* Les definitions qui suivent sont aussi dans clcriter.h dans la section 
   #ifdef ISUNIX. A verifier en cas de modifications!
*/
#ifndef NULL
#define NULL			0
#endif
#define WINAPI
#define APIENTRY 		

/////////////////////////////////////////////////////////////////////////////

// in   conctype.c
//    - ResiszeCTypes()
//   %lf doesn't exist under gcc
#define DOUBLE_FORMAT  "%f"   //   
#define LONGINT_FORMAT "%ld" 

// missing define
 CPTR CRI_CHECKSUM; 
   
/////////////////////////////////////////////////////////////////////////////
// MACROs
#define xmalloc(a,b)   malloc(b) 
#define xfree(a,b)     free(b)

#define strequ(A,B) ( strcmp(A,B)==0 )
#define xstrequ(A,B) strequ(A,B)

#define CRIsignal(A,B)        signal(A,(void*)B)
#define CRIsigprocmask(A,B,C) sigprocmask((int)A,(const sigset_t *)(B),(sigset_t *)(C))

pid_t DebugFork(void);
 
#ifdef DEBUG

//#define DBTRACE(A) __DBTRACE("%s",A)
#define DBTRACE _DBTRACE
#define _DBTRACE(A)  {\
        __DBTRACE("\n=> file : %s \n; line %u  pid : %u , DEBUG Message  :  %s \n ",__FILE__,__LINE__,getpid(),A); \
	            }
void __DBTRACEN(int len ,char * Arg , char * Mess);
#else 
#define DBTRACE(A) 
#endif

#ifdef DEBUG
#define ChildWait() sleep(15)

#define Fork() DebugFork() 			\

#else

#define Childwait()
#define Fork() fork()

#endif


/////////////////////////////////////////////////////////////////////////////
/* Linux 's special structures controls */

// PID -- MEM -- threads -- ...

// Linux_Criteria Special Globals



/////////////////////////////////////////////////////////////////////////////
// Functions prototypes
/////////////////////////////////////////////////////////////////////////////

bool  	GetCridir(char * Dir);
U32   	GetShmAdr(void);
bool 	SetShmAdr(U32 Adr);
void  	Message(char * Arg , ... );
int   	MyKill(pid_t pid , int sig );
void 	__DBTRACE(char * Arg , ...);
key_t 	DebugTest(void);
int 	pid_is_running ( pid_t pid);
key_t 	GetShmKey(void);
key_t 	SetShmKey(key_t key);


void 	U32EVL(U32,CPTR);
void 	U16EVL(U16, CPTR);
void 	U8EVL(U8, CPTR);
//
//extern void U8EV(U8 , CPTR );
#define U8EV(l, p)	U8EVL((U8)l, p)

/* Shared Mem  */

// shmget_( );
// shmat_();
// shmdt_(char* );

/* Thread   */

// pthreadcreate_();




#endif // LINUX_PORT_H


