#ifndef	_exsoap_c
#define	_exsoap_c

#include "exnetwork.h"
#include "exurl.h"
#include "exsoap.h"
#include "exhttp.h"
#include "xmlparse.h"
#include "soapapp.h"
#include "exvtype.h"

struct	soap_rpc_context
{
	char		*	wsdlname;
	struct	xml_tag *	document;
	struct	xml_tag *	response;
	int			methods;
	int			version;	
	int			paracount;
	char		*	parameters;
	struct program_url	url;
};

static	int	(*setexitvalue)(int) = (void *) 0;
static	int	(*setexitstring)(int,char *, int) = (void *) 0;
static	int	(*gxmlparser)( char *, struct xml_relay *, void *) = (void *) 0;

/*	----------------------------------------------------------	*/
/*		s e t _ e x i t _ c o n n e c t i o n			*/
/*	----------------------------------------------------------	*/
void	set_exit_connection( void * v, void * s )
{
	setexitvalue = v;
	setexitstring = s;
	return;
}

/*	----------------------------------------------------------	*/
/*		 e x i t _ r e m o t e _ v a l u e			*/
/*	----------------------------------------------------------	*/
static	int	exit_remote_value( char * sptr, int bytes )
{
	if (!( setexitvalue ))
		return(118);
	else
	{
		(*setexitvalue)( rpc_parse_hex_value( &sptr, bytes ) );
		return(0);
	}
}

/*	----------------------------------------------------------	*/
/*		 e x i t _ r e m o t e _ s t r i n g			*/
/*	----------------------------------------------------------	*/
static	int	exit_remote_string( char * sptr, int type )
{
	char	buffer[8192];
	int		length;
	length = atoi(sptr);

	if (!( sptr = rpc_parse_parameter( sptr )))
		return( 33 );
	else
	{
		rpc_parse_hex_string(buffer, &sptr, length );
		if (!( setexitstring ))
			return(118);
		else if (!( (*setexitstring)( type,buffer, length ) ))
			return( 34 );
		else	return( 0 );
	}
}

/*	----------------------------------------------------------	*/
/*			s e t _ x m l _ p a r s e r			*/
/*	----------------------------------------------------------	*/
void	set_xml_parser( void * v )
{
	gxmlparser = v;
	return;
}

/*	----------------------------------------------------------	*/
/*			t r y _ u n l i n k				*/
/*	----------------------------------------------------------	*/
static	void	try_unlink( char * filename )
{
	unlink( filename );
}

/*	----------------------------------------------------------	*/
/*		o p e n _ p r o g r a m _ c l i e n t			*/
/*	----------------------------------------------------------	*/
void *	open_program_client( struct program_url * url )
{
	struct	soap_rpc_context * cptr;
	if (!( cptr = (struct soap_rpc_context *) allocate( sizeof(struct soap_rpc_context) ) ))
		return( cptr );
	else
	{
		memset( cptr, 0, sizeof(struct soap_rpc_context));
		return( cptr );
	}
}

/*	----------------------------------------------------------	*/
/*			x m l _ t a g _ c o u n t			*/
/*	----------------------------------------------------------	*/
static	int	xml_tag_count( struct xml_tag * dptr, char * nptr )
{
	int	tags=0;
	struct	xml_tag * tptr;
	for (	tptr = dptr;
		tptr != (struct xml_tag *) 0;
		tptr = tptr->next )
		if (!( tptr->name ))
			continue;
		else if (!( strcmp( tptr->name, nptr ) ))
			tags++;
	return( tags );
}

/*	----------------------------------------------------------	*/
/*		w s d l _ m e t h o d _ c o u n t			*/
/*	----------------------------------------------------------	*/
static	int	wsdl_method_count( struct xml_tag * dptr )
{
	return( xml_tag_count( dptr->first_tag, "wsdl:portType" ) );
}

/*	----------------------------------------------------------	*/
/*		a t t a c h _ p r o g r a m _ c l i e n t		*/
/*	----------------------------------------------------------	*/
int	attach_program_client( void * h, struct program_url * url, char * xptr  )
{
	struct	soap_rpc_context * cptr;
	char *	tempname;

	if (!( cptr = h ))	
		return( 0 );
	else	cptr->wsdlname = (void *) liberate( cptr->wsdlname );

	memcpy(&cptr->url,url,sizeof( struct program_url));

	if (!( cptr->wsdlname = http_tempname()))
		return( 0 );
	else if ( http_get( url->host, url->port, url->program, cptr->wsdlname ) > 200 )
		return( 0 );
	else if (!( cptr->document = xml_parse_file( cptr->wsdlname, gxmlparser ) ))
	{
		try_unlink( cptr->wsdlname );
		cptr->wsdlname = (void *) liberate( cptr->wsdlname );
		return( 0 );
	}
	else
	{
		try_unlink( cptr->wsdlname );
		return(( cptr->methods =  wsdl_method_count( cptr->document )));
	}
}

/*	----------------------------------------------------------	*/
/*	      c a l l _ p r o g r a m _ p a r a m e t e r s		*/
/*	----------------------------------------------------------	*/
int	call_program_parameters( void * h, int argc, char * argv )
{
	struct	soap_rpc_context * cptr;
	if (!( cptr = h ))
		return( 118 );
	else if (!( cptr->document ))
		return( 78 );
	else
	{
		cptr->paracount  = argc;
		cptr->parameters = argv;
		return(0);
	}
}

/*	----------------------------------------------------------	*/
/*		e x i t _ p r o g r a m _ c l i e n t			*/
/*	----------------------------------------------------------	*/
int	exit_program_client( void * h )
{
	char	*	rptr;
	char	*	sptr;
	struct	xml_tag * mptr;
	struct	soap_rpc_context * cptr;
	if (!( cptr = h ))
		return( 118 );
	else if (!( cptr->document ))
		return( 78 );
	else if (!( cptr->response ))
		return(0);
	else if (!( mptr = locate_method_node( cptr->response ) ))
		return(0);
	else if (!( strcmp( mptr->name, "tns:Fault" ) ))
	{
		/* handle fault */
		/* ------------ */
		if (!( mptr->first_tag ))
			return( 118 );
		else if (!( mptr->first_tag->next ))
			return( 118 );
		else if (!( mptr->first_tag->next->data ))
			return( 118 );
		else	return( atoi( mptr->first_tag->next->data ) );
	}
	else
	{
		/* handle result : step over other values */
		for (	mptr = mptr->first_tag;
			mptr != (struct xml_tag *) 0;
			mptr = mptr->next )
			if (!( strcmp( mptr->name, "r53" ) ))
				break;
		if (!( mptr ))
			return( 118 );
		else if (!( rptr = mptr->data ))
			return( 118 );
		while (( *rptr == '\n' )
		   ||  ( *rptr == '\r' )
		   ||  ( *rptr == '\t' )
		   ||  ( *rptr == ' ' ))
			rptr++;
		if (!( sptr = rpc_parse_parameter( rptr )))
			return( 332 );
		else
		{
			switch ( *rptr )
			{
			case	'B'	: return( exit_remote_value( sptr, 1 ) );
			case	'W'	: return( exit_remote_value( sptr, 2 ) );
			case	'L'	: return( exit_remote_value( sptr, 4 ) );
#ifdef	ABAL64
			case	'H'	: return( exit_remote_value( sptr, 8 ) );
#endif
			case	'N'	: return( exit_remote_string( sptr, VARB_BCD ));

			case	'S'	: return( exit_remote_string( sptr, VARB_STR ));
			default		: return( 0 );
			}
		}
	}
}

/*	----------------------------------------------------------	*/
/*		     e n d _ p r o g r a m _ c a l l			*/
/*	----------------------------------------------------------	*/
/*	called when exiting the "call_program_client" to ensure		*/
/*	clean up of parameter information.				*/
/*	----------------------------------------------------------	*/
static	int	end_program_call( struct soap_rpc_context * cptr, int status )
{
	cptr->parameters = (char *) 0;
	cptr->paracount  = 0;
	cptr->response   = drop_xml_document( cptr->response );
	return( status );
}

/*	----------------------------------------------------------	*/
/*		c a l l _ p r o g r a m _ c l i e n t			*/
/*	----------------------------------------------------------	*/
int	call_program_client( void * h, int procid , char * pptr )
{
	int	status;
	char	buffer[256];
	char *	tempname1;
	char *	tempname2;
	struct	soap_rpc_context * cptr;
	if (!( cptr = h ))	
		return( end_program_call(cptr,  118 ));
	else if (!( cptr->document ))
		return( end_program_call(cptr,  78 ));
	else if (!( tempname1 = http_tempname()))
		return( end_program_call(cptr, 27));
	else if (!( tempname2 = http_tempname()))
		return( end_program_call(cptr, 27));
	else if ((status = generate_request_message( tempname1, procid+1, cptr->url.host,cptr->url.program, cptr->parameters, cptr->paracount )) != 0)
		return( end_program_call(cptr,  status ));
	else if ((status = http_post( cptr->url.host, cptr->url.port, cptr->url.program, tempname1,tempname2 )) > 200 )
	{
		try_unlink( tempname1 );
		return( end_program_call(cptr,  status ));
	}
	else if (!( cptr->response = xml_parse_file( tempname2, gxmlparser) ))
	{
		try_unlink( tempname1 );
		try_unlink( tempname2 );
		tempname1 = liberate( tempname1 );
		tempname2 = liberate( tempname2 );
		return( end_program_call(cptr, 30));
	}
	else	
	{
		try_unlink( tempname1 );
		try_unlink( tempname2 );
		status = exit_program_client( h );
		return( end_program_call(cptr,  status ) );
	}
}

/*	----------------------------------------------------------	*/
/*		d e t a c h _ p r o g r a m _ c l i e n t		*/
/*	----------------------------------------------------------	*/
int	detach_program_client( void * h )
{
	struct	soap_rpc_context * cptr;
	if (!( cptr = h ))	
		return( 118 );
	if ( cptr->document )
		cptr->document = drop_xml_document( cptr->document );
	return(0);
}

/*	----------------------------------------------------------	*/
/*		 c l o s e _ p r o g r a m _ c l i e n t		*/
/*	----------------------------------------------------------	*/
void *	close_program_client( void * h )
{
	struct	soap_rpc_context * cptr;
	if (( cptr = h ) != (struct	soap_rpc_context *) 0)
	{
		/* drop the xml document */
		if ( cptr->document )
			cptr->document = drop_xml_document( cptr->document );
		liberate( cptr );
	}
	return((void*)0);
}

#endif	/* _exsoap_c */
	/* --------- */










