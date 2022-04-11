#ifndef	_xsd_c
#define	_xsd_c

#include "xmlparse.h"
#include "xsd.h"

static	int	xsd_open_tag(char * sptr );
static	int	xsd_token(char * sptr );
static	int	xsd_atb_name(char * sptr );
static	int	xsd_atb_value(char * sptr );
static	int	xsd_white_space(int c );
static	int	xsd_punctuation(int c );
static	int	xsd_close_tag();

static	struct	xml_relay xsdrelay = {
		xsd_open_tag,
		xsd_atb_name,
		xsd_atb_value,
		xsd_white_space,
		xsd_token,
		xsd_punctuation,
		xsd_close_tag,
		xsd_failure
		};

static	struct	xsd_control	{
	int	icount;
	int	acount;
	int	offset;
	struct 	xsd_schema * schema;
	struct	xsd_element* working;
	int	heap[1024];
	char *	atbn;
	char *	buffer[2048];
	} XsdStack = { 0,0,0, (struct xsd_schema *) 0, (struct xsd_element *) 0 };


static	struct	xsd_type 	* allocate_xsd_type()
{
	struct	xsd_type 	* tptr;
	if (!( tptr = allocate( sizeof ( struct xsd_type ) ) ))
		return( tptr );
	else	{
		tptr->nature = 0;
		tptr->detail = (struct xsd_list *) 0;
		tptr->name   = (char *) 0;
		tptr->previous = tptr->next = (struct xsd_type*) 0;
		if (!( tptr->previous = XsdStack.schema->tlast ))
			XsdStack.schema->tfirst = tptr;
		else 	XsdStack.schema->tlast->next = tptr;
		XsdStack.schema->tlast = tptr;
		return( tptr );
		}
}

static	struct	xsd_type *	locate_type( char * name )
{
	struct	xsd_type * tptr=(struct xsd_type* )0;
	if (!( XsdStack.schema ))
		return( tptr );
	else	{
		for ( 	tptr=XsdStack.schema->tfirst;
			tptr != (struct xsd_type *) 0;
			tptr = tptr->next ) {
			if (!( tptr->name ))
				continue;
			else if ( compare( tptr->name, name ) )
				return( tptr );
			}
		if (!( tptr = allocate_xsd_type() ))
			return( tptr );
		else if (!( tptr->name = allocate_string( name )))
			return((struct xsd_type *) 0);
		else	return( tptr );
		}
}

static	int	xsd_open_tag(char * sptr )
{
	struct	xsd_element 	* eptr;
	struct	xsd_type 	* tptr;
	int	i;
	for ( i=0; i < _xsd_max; i++ ) 
		if (!( compare( sptr, xsd_keywords[i] ) ))
			continue;
		else	break;
	if ( i < _xsd_max ) {
		XsdStack.acount=0;
		XsdStack.offset=0;
		XsdStack.heap[XsdStack.icount++] = i;
		switch (i) {
			case	_xsd_schema	:

				if ( XsdStack.schema )
					return( 81 );
				else if (!( XsdStack.schema = allocate( sizeof ( struct xsd_schema ) ) ))
					return( 27 );
				else	{
					XsdStack.schema->name = (char *) 0;
					XsdStack.schema->efirst = 
					XsdStack.schema->elast  = (struct xsd_element *) 0;
					XsdStack.schema->tfirst = 
					XsdStack.schema->tlast  = (struct xsd_type *) 0;
					return(0);
					}

			case	_xsd_element	:
 
				if (!( XsdStack.schema ))
					return( 30 );
				if (!( eptr = allocate( sizeof ( struct xsd_element ) ) ))
					return( 27 );
				else	{
					eptr->type = (struct xsd_type *) 0;
					eptr->name = (char *) 0;
					eptr->previous = eptr->next = (struct xsd_element*) 0;
					if ( XsdStack.heap[(XsdStack.icount-2)] == _xsd_schema ) {
						if (!( eptr->previous = XsdStack.schema->elast ))
							XsdStack.schema->efirst = eptr;
						else 	XsdStack.schema->elast->next = eptr;
						XsdStack.schema->elast = eptr;
						return( 0 );
						}
					else	{
						XsdStack.working = eptr;
						return(0);
						}
					}

			case	_xsd_complexType	:

				if (!( XsdStack.schema ))
					return( 30 );
				else if (!( tptr = allocate_xsd_type() ))
					return( 27 );
				else	return( 0 );

			}
		return(0);
		}
	else	return(78);
}


static	int	xsd_token(char * sptr )
{
	strcpy((XsdStack.buffer+XsdStack.offset),sptr);
	XsdStack.offset += strlen( sptr );
	return(0);
}


static	int	xsd_atb_name(char * sptr )
{
	if ( XsdStack.atbn ) {
		liberate( XsdStack.atbn );
		XsdStack.atbn = (char *) 0;
		}
	if (!( XsdStack.atbn = allocate_string( sptr ) ))
		return(27);
	else	return(0);
}


static	int	xsd_atb_value(char * sptr )
{
	struct	xsd_element 	* eptr;
	char			* nptr;
	int			  i;
	if (!( i = XsdStack.icount ))
		return(30);
	else if (!( nptr = XsdStack.atbn ))
	 	return(41);
	else	{
		if ( compare( nptr, "name" ) ) {
			liberate( nptr );
			XsdStack.atbn = (char *) 0;
			switch ( XsdStack.heap[(i-1)] ) {

				case	_xsd_element	:
					if ( XsdStack.heap[(i-2)] == _xsd_schema )
						eptr = XsdStack.schema->elast;
					else	eptr = XsdStack.working;
					if (!( eptr ))
						return(55);
					else if ( eptr->name )
						return(31);
					else if (!( eptr->name = allocate_string( sptr )))
						return(27);
					else	return(0);

				case	_xsd_complexType	:
					if ((!( XsdStack.schema ))
					||  (!( XsdStack.schema->tlast  )))
						return(55);
					else if ( XsdStack.schema->tlast->name )
						return(31);
					else if (!( XsdStack.schema->tlast->name = allocate_string( sptr )))
						return(27);
					else	return(0);
				}					

			}
		else if ( compare( nptr, "type" ) ) {
			liberate( nptr );
			XsdStack.atbn = (char *) 0;
			switch ( XsdStack.heap[(i-1)] ) {
				case	_xsd_element	:
					if ( XsdStack.heap[(i-2)] == _xsd_schema )
						eptr = XsdStack.schema->elast;
					else	eptr = XsdStack.working;
					if (!( eptr ))
						return(55);
					else if (!( eptr->type = locate_type( sptr )))
						return(27);
					else	return(0);
				}

			}
		else	{
			liberate( nptr );
			XsdStack.atbn = (char *) 0;
			}
		}
	return(0);
}


static	int	xsd_white_space(int c )
{
	XsdStack.buffer[XsdStack.offset++]=c;
	XsdStack.buffer[XsdStack.offset]=0;
	return(0);
}


static	int	xsd_punctuation(int c )
{
	XsdStack.buffer[XsdStack.offset++]=c;
	XsdStack.buffer[XsdStack.offset]=0;
	return(0);
}


static	int	xsd_close_tag()
{
	if (!( XsdStack.icount ))	return(41);
	else	XsdStack.icount--;
	switch ( XsdStack.heap[XsdStack.icount] ) {
		case	_xsd_element	:
			if ( XsdStack.heap[XsdStack.icount-1] != _xsd_schema )
				XsdStack.working = (struct xsd_element *) 0;
			break;

		}
	return(0);
}

void	xsd_show()
{
	struct	xsd_element 	* eptr;
	struct	xsd_type 	* tptr;
	if (!( XsdStack.schema ))
		return;

	printf("\r\nElements \r\n");
	for ( 	eptr=XsdStack.schema->efirst;
		eptr != (struct xsd_element *) 0;
		eptr = eptr->next ) {
		if (!( eptr->name ))
			continue;
		else if (!( tptr = eptr->type )) 
			printf("xsd_element  %s\r\n",eptr->name);
		else 	printf("xsd_element %s %s\r\n",tptr->name,eptr->name);
		}
/*
	printf("\r\nTypes \r\n");
	for ( 	tptr=XsdStack.schema->tfirst;
		tptr != (struct xsd_type *) 0;
		tptr = tptr->next ) {
		if (!( tptr->name ))
			continue;
		else	printf("xsd_type %s\r\n",tptr->name);
		}
 */
	return;
}






#endif	/* _xsd_c */
	/* ------ */


