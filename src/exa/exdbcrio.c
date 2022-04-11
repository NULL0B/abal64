#ifndef	_EXDBSTIO_C
#define	_EXDBSTIO_C

/*
 *	This file is included by EXDBSTR.C to provide low level
 *	direct sector file access for EXADB using CRITERIA
 *
 */
//#BG#include "exadsqcr.h"
#include "pubexma.h"

#ifdef	VERSION666
typedef	unsigned long long LSEEKTYPE;
#else
typedef	unsigned long LSEEKTYPE;
#endif

extern LSEEKTYPE fidseek;
#define lseek(a,b,c) 	(fidseek = b)


EXAWORD xxread(handle,buffer,blen)
EX_FILE_HANDLE handle;
BPTR buffer;
EXAWORD blen;
{ 
	LSEEKTYPE	oldpos = fidseek;
	EXAWORD	result;
  	
	result = EeEad_read( handle, buffer, blen );
	if ((result == 0) || (result == 48))
		return((EXAWORD)(fidseek - oldpos));
	else   	return(EXDB_FFFF);
}

EXAWORD xxwrite(handle,buffer,blen)
EX_FILE_HANDLE handle;
BPTR buffer;
EXAWORD blen;
{
	LSEEKTYPE	oldpos = fidseek;
	EXAWORD	result;
  	
	result = EeEad_write( handle, buffer, blen );
	if (result == 0)	return((EXAWORD)(fidseek - oldpos));
	else   			return(EXDB_FFFF);
}




static	EXAWORD	ll_stream_open( vhandle, buffer )
EXAWORD		vhandle;
BPTR		buffer;
{ EXAWORD err;
  EX_FILE_HANDLE h;
//#BG 20/08/20 En fait 0_RDONLY (cf define ds exdbstre.c) !
	h = EeEad_open(buffer,OPENRW, &err);
	if (err) h = EX_UNUSED_HANDLE;
	DebugSymbols->Stream[vhandle].handle = h;
	return( valid_stream_handle( vhandle ));
}

static	VOID	ll_stream_unlink( nomfic )
BPTR		nomfic;
{
	EeEad_unlink((BPTR) nomfic);
	return;
}

static	EXAWORD	ll_stream_create( vhandle, buffer )
EXAWORD		vhandle;
BPTR		buffer;
{ EXAWORD err;
  EX_FILE_HANDLE h;

	h = EeEad_create(buffer,CREATRW,&err);
	if (err) h = EX_UNUSED_HANDLE;

	DebugSymbols->Stream[vhandle].handle = h;
	return( valid_stream_handle( vhandle ) );
}

static	VOID	ll_stream_close( vhandle )
EXAWORD		vhandle;
{
	if ( valid_stream_handle( vhandle ) ) {
		(void) EeEad_close( DebugSymbols->Stream[vhandle].handle );
		stream_reset( vhandle );
		}
	return;
}

static	EXAWORD	ll_stream_read( vhandle, secteur, buffer, longueur )
EXAWORD		vhandle;
EXAWORD		secteur;
BPTR		buffer;
EXAWORD		longueur;
{
	EXALONG	seekpos;
	EXAWORD	status;
#ifndef	OPTIMISEUR
	simcbd = 0x2060;
#endif
	if (( valid_stream_handle( vhandle ) )
	&&  ( lseek( DebugSymbols->Stream[vhandle].handle,( seekpos = (((long)secteur) * 256)), SEEK_SET) != -1L )
	&&  ((status = xxread( DebugSymbols->Stream[vhandle].handle, buffer, longueur )) != 0))
		return( status );
	else	return( 0 );
}

static	VOID	ll_stream_write( vhandle )
EXAWORD		vhandle;
{
	EXALONG	seekpos;
#ifndef	OPTIMISEUR
	simcbd = 0x20A0;
#endif
	if (( valid_stream_handle( vhandle ) )
	&&  ( lseek( DebugSymbols->Stream[vhandle].handle,( seekpos = (((long) DebugSymbols->Stream[vhandle].secteur) * 256)), SEEK_SET) != -1L ))
		xxwrite( DebugSymbols->Stream[vhandle].handle, (BPTR) DebugSymbols->Stream[vhandle].buffer, DebugSymbols->Stream[vhandle].offset );
	return;
}
#endif	/* _EXDBSTIO_C */
	/* ----------- */

