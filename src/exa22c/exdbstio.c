#ifndef	_EXDBSTIO_C
#define	_EXDBSTIO_C
#ifdef AIX_VERS
#ifdef SPARC
#ifndef SEEK_SET
#define SEEK_SET 0
#endif
#endif /* SPARC */
#endif /* AIX_VERS */
/*
 *	This file is included by EXDBSTR.C to provide low level
 *	direct sector file access for EXADB
 *
 */

static	EXAWORD	ll_stream_open( vhandle, buffer )
EXAWORD		vhandle;
BPTR		buffer;
{
	DebugSymbols->Stream[vhandle].handle = open( (BPTR) buffer, OPENRW );
	return( valid_stream_handle( vhandle ));
}

static	VOID	ll_stream_unlink( nomfic )
BPTR		nomfic;
{
	unlink((BPTR) nomfic);
	return;
}

static	EXAWORD	ll_stream_create( vhandle, buffer )
EXAWORD		vhandle;
BPTR		buffer;
{
	DebugSymbols->Stream[vhandle].handle = creat( (BPTR) buffer, CREATRW );
	return( valid_stream_handle( vhandle ) );
}

static	VOID	ll_stream_close( vhandle )
EXAWORD		vhandle;
{
	if ( valid_stream_handle( vhandle ) ) {
		(void) close( DebugSymbols->Stream[vhandle].handle );
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
	&&  ((status = read( DebugSymbols->Stream[vhandle].handle, buffer, longueur )) != 0))
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
		write( DebugSymbols->Stream[vhandle].handle, (BPTR) DebugSymbols->Stream[vhandle].buffer, DebugSymbols->Stream[vhandle].offset );
	return;
}
#endif	/* _EXDBSTIO_C */
	/* ----------- */

