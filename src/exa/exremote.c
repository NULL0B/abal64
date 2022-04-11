/*
 *
 *		E X E C U T E U R 	A . B . A . L
 *		-------------------------------------
 *
 *		Copyright (c) 1987,2002 Amenesik / Sologic  .
 *
 *		Module  :	EXREMOTE.C
 *		Version :	4.0a
 *		Date 	:	01/12/2010
 */
#ifndef	_EXREMOTE_C
#define	_EXREMOTE_C

#include "exattach.h"
#include "exrp.c"
#include "xmlparse.h"

EXAWORD	procedure_exit_value( EXAWORD v );
EXAWORD	procedure_exit_string( EXAWORD type, BPTR value, EXAWORD length );

/*	----------------------------------------------------	*/
/*			E X R E M O T E 			*/
/*	----------------------------------------------------	*/
/*	The remote procedure call management extension for	*/
/*	Abal 4 is divided into two logical sections :		*/
/*								*/
/*	Remote Services						*/
/*								*/
/*		A remote service is identified by a standard 	*/
/*	service prefix and its actual processing is embodied 	*/
/*	or encapsulated in a dynamic linked library that is	*/
/*	to be loaded when required to satisfy the attachment	*/
/*								*/
/*	Remote Attachments					*/
/*								*/
/*		Remote Attachments are instances of usage of	*/
/*	remote services and are created for each attachment	*/
/*	instance controller by the logical attachment code	*/
/*	----------------------------------------------------	*/
#include "exurl.h"
#include "exurl.c"

/*	----------------------------------------------------	*/
/*	  R E M O T E   S E R V I C E   F U N C T I O N S	*/
/*	----------------------------------------------------	*/

static	struct	abal_remote_service * RemoteService=(struct abal_remote_service *) 0;

/*	-----------------------------------------------------------	*/
/*		    d r o p _ r e m o t e _ s e r v i c e		*/
/*	-----------------------------------------------------------	*/
/*	liberates a remote service control structure and attempts	*/
/*	to drop the corresponding dynamic linked library package.	*/
/*	-----------------------------------------------------------	*/
static	struct	abal_remote_service * drop_remote_service( struct	abal_remote_service * sptr )
{
	if ( sptr )
	{
		if ( sptr->handle ) 
			dlclose( sptr->handle );
		if ( sptr->service )
			liberate( sptr->service );
		if ( sptr->program )
			liberate( sptr->program );
		liberate( sptr );
	}
	return((struct abal_remote_service *) 0);
}

/*	-----------------------------------------------------------	*/
/*		    b u i l d _ r e m o t e _ n a m e ( )		*/
/*	-----------------------------------------------------------	*/
/*	attempts to build a system dependant remote library name.	*/
/*	-----------------------------------------------------------	*/
static	char *	build_remote_name( char * service )
{
	char	buffer[1024];
	char *	rptr;
#ifdef	ABALDEBIAN
	sprintf(buffer,"/usr/lib/abal3/lib%s.so",service);
#else
	sprintf(buffer,"/lib/lib%s.so",service);
#endif
	if (( rptr = allocate( strlen( buffer ) + 1 )) != (char *) 0)
		strcpy( rptr, buffer );
	return( rptr );
}


/*	-----------------------------------------------------------	*/
/*		    l o a d _ r e m o t e _ s e r v i c e		*/
/*	-----------------------------------------------------------	*/
/*	allocates a remote service control structure and attempts	*/
/*	to load the corresponding dynamic linked library package.	*/
/*	-----------------------------------------------------------	*/
static	struct	abal_remote_service * load_remote_service( char * service )
{
	struct	abal_remote_service * sptr;
	if (!( sptr = (struct abal_remote_service *) allocate( sizeof( struct abal_remote_service ) ) ))
		return( sptr );
	else
	{
		memset( sptr, 0, sizeof( struct abal_remote_service ) );
		sptr->exitvalue  = procedure_exit_value;
		sptr->exitstring = procedure_exit_string;
		sptr->xmlparser	 = xml_parse;
		if (!( sptr->service = allocate( strlen( service ) + 1 ) ))
			return( drop_remote_service( sptr ) );
		else	strcpy( sptr->service, service );

		if (!( sptr->program = build_remote_name( service ) ))
			return( drop_remote_service( sptr ) );
		else if (!(  sptr->handle = dlopen( sptr->program , get_dl_option() ) ))
		{
			printf("\r\nerror::dlopen(%s)::%s\r\n",sptr->program, dlerror());
			return( drop_remote_service( sptr ) );
		}
		else if (!( sptr->initialise = dlsym( sptr->handle, "create_remote_service")))
		{
			printf("\r\nerror::dlsym(%s)::%s\r\n",sptr->program, dlerror());
			return( drop_remote_service( sptr ) );
		}
		else if (!( (*sptr->initialise)( sptr ) ))
			return( drop_remote_service( sptr ) );
		else 	return( sptr );
	}
}

/*	-----------------------------------------------------------	*/
/*		r e s o l v e _ r e m o t e _ s e r v i c e		*/
/*	-----------------------------------------------------------	*/
/*	locate a named service control structure or attempt to load	*/
/*	the corresponding library.					*/
/*	-----------------------------------------------------------	*/
static	struct	abal_remote_service * resolve_remote_service( char * service )
{
	struct	abal_remote_service * sptr;
	/* ---------------------------- */
	/* scan list of loaded services */
	/* ---------------------------- */
	for (	sptr=RemoteService;
		sptr != (struct abal_remote_service *) 0;
		sptr = sptr->next )
	{
		if (!( sptr->service ))
			continue;
		else if (!( strcmp( sptr->service, service ) ))
			return( sptr );
	}
	/* ---------------------------- */
	/* attempts to load new service */
	/* ---------------------------- */
	if (!( sptr = load_remote_service( service ) ))
		return( sptr );
	else
	{
		/* --------------------------- */
		/* add to list of rpc services */
		/* --------------------------- */
		sptr->next = RemoteService;
		RemoteService = sptr;
		return( sptr );
	}
}

/*	----------------------------------------------------	*/
/*	R E M O T E   A T T A C H M E N T   F U N C T I O N S	*/
/*	----------------------------------------------------	*/

/*	----------------------------------------------------	*/
/*		l i b e r a t e _ f o r _ r e m o t e()		*/
/*	----------------------------------------------------	*/
EXREMOTEPTR	liberate_for_remote(EXREMOTEPTR rptr)
{
	liberate( rptr );
	return((EXREMOTEPTR) 0);
}

/*	----------------------------------------------------	*/
/*		a l l o c a t e _ f o r _ r e m o t e()		*/
/*	----------------------------------------------------	*/
/*	allocates a control structure for a remote program	*/
/*	this will be stored in the attachement control block	*/
/*	and will be used to access the corresponding service	*/
/*	extension for all remote operations for the program.	*/
/*	----------------------------------------------------	*/
EXREMOTEPTR	allocate_for_remote()
{
	EXREMOTEPTR	rptr;

	if (!(rptr = (EXREMOTEPTR) allocate( sizeof( EXREMOTE ) ) ))
	{
		err_val = 27;
	}
	else
	{
		err_val = 0;
		rptr->handle	= (void *) 0;
		rptr->service	= (struct abal_remote_service *) 0;
		memset(&rptr->url, 0, sizeof( struct program_url));
	}
	return( rptr );
}

/*	----------------------------------------------------	*/
/*	i s _ r e m o t e _ a t t a c h m e n t ( filename )	*/
/*	----------------------------------------------------	*/
/*	analysis of an attachement target to detect the ABAL	*/
/*	RPC service prefix "abalrpc:" and route processing.	*/
/*	Returns GOODRESULT(TRUE) if prefix is present, and	*/
/*	SOFTERROR(FALSE) if the prefix is not present.		*/
/*	----------------------------------------------------	*/
EXAWORD	is_remote_attachment( BPTR filename )
{
	struct	program_url	url;
	memset(&url,0,sizeof( struct program_url));
	if ( analyse_url( &url, filename ) != 0 )
		return( SOFTERROR );
	else if (!( url.service ))
		return( SOFTERROR );
	else	return( GOODRESULT );
}

/*	-------------------------------------------------	*/
/*	a t t a c h _ r e m o t e _ h e a d e r( attlog )	*/
/*	-------------------------------------------------	*/
/*	builds a pseudo attachment context for exectuion	*/
/*	of remote packages.					*/
/*	-------------------------------------------------	*/
EXAWORD	attach_remote_header( ATTLOGPTR attlog )
{
	int		status;
	char		buffer[4096];
	EXREMOTEPTR	rptr;
	if (!( rptr = allocate_for_remote() ))
	{
		err_val = 27;
		return( SOFTERROR );
	}
	else if ((status  = analyse_url( &rptr->url, attlog->filename )) != 0 )
	{
		liberate_for_remote( rptr );	
		err_val = status;
		return( SOFTERROR );
	}
	else if (!( rptr->service = resolve_remote_service( rptr->url.service ) ))
	{
		liberate_for_remote( rptr );	
		err_val = 27;
		return( SOFTERROR );
	}
	else if ((rptr->handle = (*rptr->service->open)( &rptr->url )) == -1 )
	{
		err_val = 222;
		return( SOFTERROR );
	}
	else if (!(attlog->procmaxid = (*rptr->service->attach)( rptr->handle, &rptr->url,"" )))
	{
		err_val = 118;
		return( SOFTERROR );
	}
	else
	{
		attlog->remote = rptr;
		return( GOODRESULT );
	}
}

/*	-------------------------------------------------	*/
/*	d e t a c h _ r e m o t e _ h e a d e r( attlog )	*/
/*	-------------------------------------------------	*/
/*	drops the remote program control context		*/
/*	-------------------------------------------------	*/
EXAWORD	detach_remote_program( ATTLOGPTR attlog )
{
	EXREMOTEPTR	rptr;
	if (( rptr = attlog->remote ) != (EXREMOTEPTR) 0)
	{
		if ( rptr->service )
		{
			(void) (*rptr->service->detach)( rptr->handle );
			(void) (*rptr->service->close)( rptr->handle );
		}
		attlog->remote = (EXREMOTEPTR) 0;
		
	}
	return(GOODRESULT);
}

/*	-------------------------------------------------	*/
/*	c a l l _ r e m o t e _ n u m b e r ( proc rptr )	*/
/*	-------------------------------------------------	*/
/*	calls a numbered remote procedure.			*/
/*	-------------------------------------------------	*/
EXAWORD	call_remote_number( EXAWORD procid, EXREMOTEPTR rptr )
{
	if ((!( rptr )) || (!( rptr->service )))
		return( SOFTERROR );
	else if (!(err_val = (*rptr->service->call)( rptr->handle, procid,(char*) 0 ) ))
		return( GOODRESULT );
	else	return( SOFTERROR );
}

/*	-------------------------------------------------	*/
/*	 c a l l _ r e m o t e _ p a r a m e t e r s ()		*/
/*	-------------------------------------------------	*/
/*	calls a numbered remote procedure with parameters	*/
/*	-------------------------------------------------	*/
EXAWORD	call_remote_parameters( EXAWORD procid, EXREMOTEPTR rptr, EXAWORD paracount, BPTR parastring )
{
	if ((!( rptr )) || (!( rptr->service )))
		return( SOFTERROR );
	else if ((err_val = (*rptr->service->parameters)( rptr->handle, paracount, parastring )) != 0 )
		return( SOFTERROR );
	else if ((err_val = (*rptr->service->call)( rptr->handle, procid,(char*) 0 )) != 0)
		return( SOFTERROR );
	else	return( GOODRESULT );
}

	/* ----------- */
#endif	/* _EXREMOTE_C */
	/* ----------- */

