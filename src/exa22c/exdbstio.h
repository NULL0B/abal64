#ifndef	_EXDBSTIO_H
#define	_EXDBSTIO_H


/*	--------------------------------------------------------	*/
/*	Logical : TRUE / FALSE Functions				*/
/*	--------------------------------------------------------	*/
/*	valid_stream_handle( virtual_handle )				*/
/*	ll_stream_open( virtual_handle, filename )			*/
/*	ll_stream_create( virtual_handle, filename )			*/
/*	ll_stream_read( virtual_handle, sector, buffer, length )	*/
/*	ll_stream_write( virtual_handle )				*/
/*	--------------------------------------------------------	*/

/*	--------------------------------------------------------	*/
/*	VOID Functions							*/
/*	--------------------------------------------------------	*/
/*	ll_stream_close( virtual_handle )				*/
/*	ll_stream_unlink( filename )					*/
/*	--------------------------------------------------------	*/

#define	valid_stream_handle( vh ) ( DebugSymbols->Stream[vh].handle != EX_UNUSED_HANDLE ? VRAI : FAUX )

#ifndef	UNIX

static	EXAWORD	ll_stream_open( EXAWORD, BPTR );
static	EXAWORD	ll_stream_create( EXAWORD, BPTR );
static	EXAWORD	ll_stream_read( EXAWORD, EXAWORD, BPTR, EXAWORD );
static	VOID	ll_stream_write( EXAWORD );
static	VOID	ll_stream_close( EXAWORD );
static	VOID	ll_stream_unlink( BPTR );

#else

static	EXAWORD	ll_stream_open();
static	EXAWORD	ll_stream_create();
static	EXAWORD	ll_stream_read();
static	VOID	ll_stream_write();
static	VOID	ll_stream_close();
static	VOID	ll_stream_unlink();

#endif	/* UNIX */

#endif	/* _EXDBSTIO_H */
	/* ----------- */

