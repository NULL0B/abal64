#ifndef	_SOAPAPP_C
#define	_SOAPAPP_C

/*	----------------------------------------------------------	*/
/*	This file provides a collection of functions offering full	*/
/*	SOAP XML parsing and production services for the new Abal 	*/
/*	SOAP RPC mechanisms of Abal 4.					*/
/*	The XML parser is a derivation of the standard XML parser	*/
/*	already available within the abal runtime EXA since 3.2b	*/
/*	----------------------------------------------------------	*/

#include "exnetwork.h"
#include "exurl.h"
#include "xmlparse.h"
#include "soapapp.h"
#include "allocate.h"

int   rpc_parse_hex_value( char ** sptr,int bytes );

/*	----------------------------------------------------------	*/
/*		s o a p _ x m l _ o p e n _ t a g 			*/
/*	----------------------------------------------------------	*/
static	int	soap_xml_open_tag(struct xml_application * xptr,char * nptr)
{
	struct	xml_tag * tptr;
	struct	soap_application * sptr;

	if (!( sptr = xptr->payload[0] ))
		return(0);

	/* allocate tag structure */
	/* ---------------------- */
	if (!( tptr = allocate( sizeof( struct xml_tag ) ) ))
		return( -1 );
	else	memset( tptr, 0, sizeof( struct xml_tag ) );

	/* allocate for tag name storage */
	/* ----------------------------- */
	if (!( tptr->name = allocate( strlen( nptr ) + 1 ) ))
	{
		liberate( tptr );
		return( -1 );
	}
	else	strcpy( tptr->name, nptr );

	/* add this node to tree */
	/* --------------------- */
	if (!( tptr->parent = sptr->current ))
		sptr->document = tptr;
	else 
	{
		if (!(tptr->previous = sptr->current->last_tag))
			sptr->current->first_tag = tptr;
		else	sptr->current->last_tag->next = tptr;
		sptr->current->last_tag= tptr;
	}
	sptr->current = tptr;
	return(0);
}

/*	----------------------------------------------------------	*/
/*		      s o a p _ x m l _ a t b _ n a m e			*/
/*	----------------------------------------------------------	*/
static	int	soap_xml_atb_name(struct xml_application * xptr,char * nptr)
{
	struct	xml_atb * aptr;
	struct	xml_tag * tptr;

	struct	soap_application * sptr;

	if (!( sptr = xptr->payload[0] ))
		return(0);

	/* avoid operation if no current tag */
	/* --------------------------------- */
	if (!( tptr = sptr->current ))
		return( 0 );

	/* allocate atb structure */
	/* ---------------------- */
	if (!( aptr = allocate( sizeof( struct xml_atb ) ) ))
		return( -1 );
	else	memset( aptr, 0, sizeof( struct xml_atb ) );

	/* allocate for atb name storage */
	/* ----------------------------- */
	if (!( aptr->name = allocate( strlen( nptr ) + 1 ) ))
	{
		liberate( aptr );
		return( -1 );
	}
	else	strcpy( aptr->name, nptr );

	if (!( aptr->previous = tptr->last_atb ))
		tptr->first_atb = aptr;
	else	tptr->last_atb->next = aptr;
	tptr->last_atb = aptr;
	return(0);
}

/*	----------------------------------------------------------	*/
/*		     s o a p _ x m l _ a t b _ v a l u e		*/
/*	----------------------------------------------------------	*/
static	int	soap_xml_atb_value(struct xml_application * xptr,char * nptr)
{
	struct	xml_atb * aptr;
	struct	xml_tag * tptr;
	struct	soap_application * sptr;

	if (!( sptr = xptr->payload[0] ))
		return(0);

	/* avoid operation if no current tag or atb */
	/* ---------------------------------------- */
	if (!( tptr = sptr->current ))
		return( 0 );
	else if (!( aptr = tptr->last_atb ))
		return( 0 );

	/* allocate for atb value storage */
	/* ------------------------------ */
	if (!( aptr->value = allocate( strlen( nptr ) + 1 ) ))
	{
		liberate( aptr );
		return( -1 );
	}
	else	strcpy( aptr->value, nptr );

	return(0);
}

struct	xml_data_manager
{
	int	used;
	int	max;
	char *	buffer;
} XmlData = { 0, 0, (char *) 0 };

/*	----------------------------------------------------------	*/
/*		   s o a p _ x m l _ c l o s e _ t a g			*/
/*	----------------------------------------------------------	*/
static	int	soap_xml_close_tag(struct xml_application * xptr)
{
	struct	xml_tag * tptr;
	struct	soap_application * sptr;
	if (!( sptr = xptr->payload[0] ))
		return(0);
	else if (( tptr = sptr->current ) != (struct xml_tag *) 0)
	{
		if (( XmlData.used ) && ( XmlData.buffer ))
		{
			if (( tptr->value = allocate( XmlData.used+1 )) != (char *) 0)
				strcpy( tptr->value ,XmlData.buffer );
			liberate( XmlData.buffer );
			memset( &XmlData, 0, sizeof( struct xml_data_manager ));
		}
		sptr->current = tptr->parent;
	}
	return(0);
}

/*	----------------------------------------------------------	*/
/*			a d d _ s o a p _ d a t a			*/
/*	----------------------------------------------------------	*/
static	void	soap_add_data( int a )
{
	char	* 	wptr;
	if (!( XmlData.buffer ))
	{
		if (!( XmlData.buffer = allocate( XmlData.max = 1024 )))
			return;
		else	XmlData.used = 0;
	}
	else if (( XmlData.used +2 ) > XmlData.max )
	{
		XmlData.max += 1024;
		if (!( wptr = allocate( XmlData.max = 1024 )))
			return;
		else
		{
			strcpy(wptr, XmlData.buffer);
			liberate( XmlData.buffer );
			XmlData.buffer = wptr;
		}
	}
	*(XmlData.buffer+XmlData.used++) = (a & 0x00FF);
	*(XmlData.buffer+XmlData.used) = 0;
	return;
}


/*	----------------------------------------------------------	*/
/*	  s o a p _ x m l _ p u n c t u a t i o n _ h a n d l e r	*/
/*	----------------------------------------------------------	*/
static	int	soap_xml_punctuation_handler(struct xml_application * xptr, int a )
{
	soap_add_data( a );
	return(0);
}

/*	----------------------------------------------------------	*/
/*		s o a p _ x m l _ s p a c e _ h a n d l e r		*/
/*	----------------------------------------------------------	*/
static	int	soap_xml_space_handler(struct xml_application * xptr, int a )
{
	soap_add_data( a );
	return(0);
}

/*	----------------------------------------------------------	*/
/*		s o a p _ x m l _ t o k e n _ h a n d l e r		*/
/*	----------------------------------------------------------	*/
static	int	soap_xml_token_handler(struct xml_application * xptr, char * tptr )
{
	while ( *tptr )
		soap_add_data( *(tptr++) );
	return(0);
}

/*	----------------------------------------------------------	*/
/*		s o a p _ x m l _ e r r o r _ h a n d l e r		*/
/*	----------------------------------------------------------	*/
static	int	soap_xml_error_handler(struct xml_application * xptr, int a, int b)
{
	return(48);
}

/*	----------------------------------------------------------	*/
/*			x m l _ p a r s e _ f i le			*/
/*	----------------------------------------------------------	*/
struct xml_tag * xml_parse_file( char * filename, void * vptr )
{
	int	(*xmlparser)( char *, struct xml_relay *, void *) = vptr;
	struct xml_relay descriptor =
	{
		soap_xml_open_tag,
		soap_xml_atb_name,
		soap_xml_atb_value,
		soap_xml_space_handler,		
		soap_xml_token_handler,		
		soap_xml_punctuation_handler,	
		soap_xml_close_tag,
		soap_xml_error_handler
	};

	struct	soap_application application = 
	{
		(struct xml_tag *) 0,
		(struct xml_tag *) 0
	};

	if (!( xmlparser ))
		return((struct xml_tag *) 0);
	else
	{
		(*xmlparser)( filename, &descriptor, &application );
		return( application.document );
	}
}

/*	----------------------------------------------------------	*/
/*	     g e n e r a t e _ r e s p o n s e _ m e s s a g e		*/
/*	----------------------------------------------------------	*/
int	generate_response_message( char * filename, char * methodname, char * host, char * object, char * result )
{
	FILE * fh;
	int	methodnumber=0;
	if (!( fh = fopen( filename, "w" ) ))
		return(46);
	else	
	{
		if ( *methodname == 'p' )
			methodname++;
		methodnumber = atoi( methodname );
		fprintf(fh,"<?xml version='1.0' encoding='ISO-8859-1'?>\n");
		fprintf(fh,"<SOAP-ENV:Envelope xmlns:SOAP-ENV='http://schemas.xmlsoap.org/soap/encoding/'");
		fprintf(fh," xmlns:tns='http://%s%s'>\n",host,object);
		fprintf(fh,"<SOAP-ENV:Body>\n");	
		fprintf(fh,"<tns:p%uOut ",methodnumber);	
		fprintf(fh," xmlns:tns='http://%s%s'>\n",host,object);
		fprintf(fh,"<r53>%s</r53>\n",result);	
		fprintf(fh,"</tns:p%uOut>\n",methodnumber);	
		fprintf(fh,"</SOAP-ENV:Body>\n");	
		fprintf(fh,"</SOAP-ENV:Envelope>\n");
		fclose(fh);
		return(0);
	}
}

/*	----------------------------------------------------------	*/
/*	       g e n e r a t e _ f a u l t _ m e s s a g e		*/
/*	----------------------------------------------------------	*/
int	generate_fault_message( char * filename, char * methodname, char * host, char * object, char * result )
{
	FILE * fh;
	int	methodnumber=0;
	if (!( fh = fopen( filename, "w" ) ))
		return(46);
	else	
	{
		fprintf(fh,"<?xml version='1.0' encoding='ISO-8859-1'?>\n");
		fprintf(fh,"<SOAP-ENV:Envelope xmlns:SOAP-ENV='http://schemas.xmlsoap.org/soap/encoding/'");
		fprintf(fh," xmlns:tns='http://%s%s'>\n",host,object);
		fprintf(fh,"<SOAP-ENV:Body>\n");	
		fprintf(fh,"<tns:%s ",methodname);	
		fprintf(fh," xmlns:tns='http://%s%s'>\n",host,object);
		fprintf(fh,"<message>ERROR</message>\n");	
		fprintf(fh,"<value>%s</value>\n",result);	
		fprintf(fh,"</tns:%s>\n",methodname);	
		fprintf(fh,"</SOAP-ENV:Body>\n");	
		fprintf(fh,"</SOAP-ENV:Envelope>\n");
		fclose(fh);
		return(0);
	}
}

/*	----------------------------------------------------------	*/
/*	     g e n e r a t e _ r e q u e s t _ m e s s a g e		*/
/*	----------------------------------------------------------	*/
int	generate_request_message( char * filename, int procid , char * host, char * object, char * parameters, int paracount )
{
	char	buffer[8192];
	char	*	sptr;
	char	*	wptr;
	int	length;
	int	argi;
	FILE *	fh;
	if (!( fh = fopen( filename, "w") ))
		return( 46 );
	{
		fprintf(fh,"<?xml version='1.0' encoding='ISO-8859-1'?>\n");
		fprintf(fh,"<SOAP-ENV:Envelope xmlns:SOAP-ENV='http://schemas.xmlsoap.org/soap/encoding/'");
		fprintf(fh," xmlns:tns='http://%s%s'>\n",host,object);
		fprintf(fh,"<SOAP-ENV:Body>\n");	
		if (!( parameters ))		
		{
			fprintf(fh,"<tns:p%uIn ",procid);	
			fprintf(fh," xmlns:tns='http://%s%s'/>\n",host,object);
		}
		else
		{
			fprintf(fh,"<tns:p%uIn ",procid);	
			fprintf(fh," xmlns:tns='http://%s%s'>\n",host,object);
			for ( wptr=parameters,argi=0; argi < paracount; argi++ )
			{
				if (!( sptr = rpc_parse_parameter( wptr )))
					break;
				switch ( *wptr )
				{
				case	'B'	:
					fprintf(fh,"<v%u>%u</v%u>\n",
						argi+1,
						rpc_parse_hex_value( &sptr, 1 ),
						argi+1 );
					wptr = sptr;
					continue;

				case	'W'	:
					fprintf(fh,"<v%u>%u</v%u>\n",
						argi+1,
						rpc_parse_hex_value( &sptr, 2 ),
						argi+1 );
					wptr = sptr;
					continue;
				case	'L'	:
					fprintf(fh,"<v%u>%u</v%u>\n",
						argi+1,
						rpc_parse_hex_value( &sptr, 4 ),
						argi+1 );
					wptr = sptr;
					continue;
				case	'H'	:
					fprintf(fh,"<v%u>%u</v%u>\n",
						argi+1,
						rpc_parse_hex_value( &sptr, 8 ),
						argi+1 );
					wptr = sptr;
					continue;
				case	'N'	:
				case	'S'	:
					length = atoi(sptr);
					/* step over length */
					if (!( sptr = rpc_parse_parameter( sptr )))
					{
						break;
					}
					/* step over value */
					else if (!( wptr = rpc_parse_parameter( sptr )))
					{
						break;
					}
					else
					{
						fprintf(fh,"<v%u>%s</v%u>\n",argi+1,sptr,argi+1);	
						continue;
					}
				}
				break;
			}
			fprintf(fh,"</tns:p%uIn>\n",procid);	
		}
		fprintf(fh,"</SOAP-ENV:Body>\n");	
		fprintf(fh,"</SOAP-ENV:Envelope>\n");
		fclose(fh);
		return( 0 );
	}
}

/*	----------------------------------------------------------	*/
/*		    l o c a t e _ m e t h o d _ n o d e			*/
/*	----------------------------------------------------------	*/
struct	xml_tag * locate_method_node( struct xml_tag * document )
{
	if (!( document ))
		return((char *) 0);
	else if (!( document->name ))
		return((struct xml_tag *) 0);
	else if ( strcmp( document->name, "SOAP-ENV:Envelope" ) )
		return((struct xml_tag *) 0);
	else if (!( document = document->first_tag ))
		return((struct xml_tag *) 0);
	else if (!( document->name ))
		return((struct xml_tag *) 0);
	else if ( strcmp( document->name, "SOAP-ENV:Body" ) )
		return((struct xml_tag *) 0);
	else if (!( document = document->first_tag ))
		return((struct xml_tag *) 0);
	else	return( document );
}

/*	----------------------------------------------------------	*/
/*		  e x t r a c t _ m e t h o d _ n a m e			*/
/*	----------------------------------------------------------	*/
char *	extract_method_name( struct xml_tag * document )
{
	char *	nptr;
	char *	wptr;
	if (!( document ))
		return((char *) 0);
	else if (!( nptr = document->name ))
		return((char *) 0);
	else
	{
		/* --------------------------- */
		/* step over name space prefix */
		/* --------------------------- */
		wptr = nptr;
		while ( *wptr != 0 ) 
		{
			if ( *wptr == ':' )
				break;
			else	wptr++;
		}
		if ( *wptr != ':' )
			return( nptr );
		else	return( wptr+1 );
	}
}

/*	----------------------------------------------------------	*/
/*		    l o c a t e _ m e t h o d _ n a m e			*/
/*	----------------------------------------------------------	*/
char *	locate_method_name( struct xml_tag * document )
{
	if (!( document = locate_method_node( document )))
		return( (char *) 0 );
	else 	return( extract_method_name( document ) );
}

/*	----------------------------------------------------------	*/
/*		   d r o p _ x m l _ d o c u m e n t			*/
/*	----------------------------------------------------------	*/
struct	xml_tag * drop_xml_document( struct xml_tag * dptr )
{
	struct	xml_tag * tptr;
	struct	xml_atb * aptr;
	if ( dptr )
	{
		while ((tptr = dptr->first_tag) != (struct xml_tag *) 0)
		{
			dptr->first_tag = tptr->next;
			tptr = drop_xml_document( tptr );
		}
		while ((aptr = dptr->first_atb) != (struct xml_atb *) 0)
		{
			dptr->first_atb = aptr->next;
			if ( aptr->name )
				liberate( aptr->name );
			if ( aptr->value )
				liberate( aptr->value );
			liberate( aptr );
		}
		if ( dptr->name )
			liberate( dptr->name );
		liberate( dptr );
	}
	return((struct xml_tag *) 0);
}


	/* ---------- */
#endif	/* _SOAPAPP_C */
	/* ---------- */

