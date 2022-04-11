#define	ABAL_EXA

#ifdef	ABAL_CRITERIA

#include "stdtypes.h"
#define EX_FILE_HANDLE		long
#define EX_UNUSED_HANDLE	0xFFFFFFFFL
#define EX_FAILURE		0L
#include "exadsqcr.h"

#ifndef UNIX
extern VPTR Mmalloc( unsigned int );
extern VOID Mfree( VPTR );
extern VPTR Mmemcpy( VPTR , VPTR , unsigned int );
extern BPTR Mstrcpy( BPTR , BPTR );
extern VPTR Mmemset( VPTR , unsigned int , unsigned int );
extern unsigned int Mstrlen( BPTR );
#endif

extern unsigned short int err_val;
extern long fidseek;

#define lseek(a,b,c) 	(fidseek = b)
#define	creat(a,b) 	EeEad_create(a,b,(WPTR) & err_val )
#define	open(a,b,c)  	EeEad_open(a,b,(WPTR) & err_val )
#define	close(a)	EeEad_close(a)
#define	unlink(a)	EeEad_unlink(a)
#define extend(a,b)	EeEad_extend(a,b)


EXAWORD read(handle,buffer,blen)
EX_FILE_HANDLE handle;
BPTR buffer;
EXAWORD blen;
{ EXALONG	oldpos = fidseek;
  EXAWORD	result;
  	
	result = EeEad_read( handle, buffer, blen );
	if ((result == 0) || (result == 48))
		return((EXAWORD)(fidseek - oldpos));
	else   	return(0xFFFF);
}

EXAWORD write(handle,buffer,blen)
EX_FILE_HANDLE handle;
BPTR buffer;
EXAWORD blen;
{ EXALONG	oldpos = fidseek;
  EXAWORD	result;

	result = EeEad_write( handle, buffer, blen );
	if (result == 0)	return((EXAWORD)(fidseek - oldpos));
	else 		  	return(0xFFFF);
}

#else	/* ! ABAL_CRITERIA */

#include "stdtypes.h"
#define EX_UNUSED_HANDLE	-1
#define EX_FAILURE		0xFFFF
#define EX_FILE_HANDLE		EXAWORD

#ifndef UNIX
extern VPTR Mmalloc( unsigned int );
extern VOID Mfree( VPTR );
extern VPTR Mmemcpy( VPTR , VPTR , unsigned int );
extern BPTR Mstrcpy( BPTR , BPTR );
extern VPTR Mmemset( VPTR , unsigned int , unsigned int );
extern unsigned int Mstrlen( BPTR );

long	lseek( EXAWORD, long, EXAWORD);
EXAWORD	read( EXAWORD, BPTR, EXAWORD );
EXAWORD	write( EXAWORD, BPTR, EXAWORD);
EXAWORD	creat( BPTR, EXAWORD );
EXAWORD	close( EXAWORD );
EXAWORD	unlink( BPTR );
EXAWORD	extend( EXAWORD , EXAWORD);
#endif

#endif	/* ABAL_CRITERIA */

#include "buffers.c"

