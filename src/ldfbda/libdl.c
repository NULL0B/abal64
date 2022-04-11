#ifndef	_libdl_c
#define	_libdl_c

/*	-----------------------------------------------------------	*/
/*	IJM : 06/09/2005						*/
/*	-----------------------------------------------------------	*/
/*	This file is an implementation of the Linux Dynamic Loading	*/
/*	mechanisms for the HPUX/RISC platform of the Post Office	*/
/*	of the BENIN.							*/
/*	-----------------------------------------------------------	*/

#include <dl.h>
#include <malloc.h>

#define	public
#define	private	static

struct	dynamic_library {
	int	status;
	shl_t	handle;
	char *	name;
	};

private	char *	dl_error_message = "no error";

/*	------------------------	*/
/*	d l c l o s e ( handle )	*/
/*	------------------------	*/
public	void		dlclose( void * hptr )
{
	struct	dynamic_library * dptr=(struct	dynamic_library *) hptr;
	if ( dptr ) {
		if ( dptr->handle != NULL )
			shl_unload( dptr->handle );
		if ( dptr->name )
			free( dptr->name );
		free( dptr );
		}
	return;
}

/*	----------------------------	*/
/*	d l o p e n ( nptr, option )	*/
/*	----------------------------	*/
public	void * dlopen( char * nptr, int option )
{
	struct	dynamic_library * dptr;
	if (!(dptr =  malloc( sizeof( struct dynamic_library ) )))
		return( dptr );
	else	{
		dptr->status = -1;
		dptr->handle = (shl_t) 0;
		dptr->name   = (char *) 0;
		if (!( dptr->name = malloc( strlen( nptr ) + 1 ) )) {
			dl_error_message = "allocation failure";
			dlclose( dptr );
			return((void *) 0);
			}
		else	strcpy( dptr->name, nptr );
		if ((dptr->handle = shl_load(dptr->name,BIND_IMMEDIATE|BIND_VERBOSE,0L)) != NULL)
			return((void *)dptr);
		else	{
			dl_error_message = "shl load failure";
			dlclose( dptr );
			return((void *) 0);
			}

		}
}

/*	----------------	*/
/*	d l e r r o r ()	*/
/*	----------------	*/
public	char *	dlerror()
{
	return(dl_error_message);
}

/*	------------------------	*/
/*	d l s y m ( hptr, nptr )	*/
/*	------------------------	*/
public	void *	dlsym( void * hptr, char * nptr )
{
	struct	dynamic_library * dptr=(struct	dynamic_library *) hptr;
	void *	rptr=(void *) 0;
	if (!( hptr )) {
		dl_error_message = "null handle";
		return((void *) 0);
		}
	else if (!( nptr )) {
		dl_error_message = "null symbol";
		return((void *) 0);
		}
	else if (!( shl_findsym( &dptr->handle, nptr, (short) TYPE_PROCEDURE, &rptr ))) {
		return(rptr);
		}
	else	{
		dl_error_message = "unknown symbol";
		return((void *) 0);
		}
}


#endif	/* _libdl_c */
	/* -------- */


