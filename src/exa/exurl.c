#ifndef	_EXURL_C
#define	_EXURL_C

static 	char *	url_allocate_string( char * sptr )
{
	char *	rptr;
	if (!( sptr ))
		return((char *) 0);
	else if (!( rptr = allocate( strlen( sptr ) + 1 ) ))
		return( rptr );
	else	return( strcpy( rptr, sptr ) );
}

int	analyse_url( struct program_url * uptr, char * sptr )
{
	char *	wptr=sptr;
	char 	buffer[8192];
	int	i;
	int	phase=0;
	struct	servent *	service;

	/* ---------------------------------- */
	/* collect and convert service prefix */
	/* ---------------------------------- */
	if (( i = extract_portion( buffer, &wptr, ":" )) > 0 )
	{
		if (!( uptr->service = url_allocate_string( buffer ) ))
			return( 27 );
		else if (!( uptr->port = exatoi( buffer, strlen(buffer)) ))
		{
			if (!( service = getservbyname( buffer,"tcp" )))
				return(30);
			else	uptr->port = ntohs(service->s_port);
		}
		wptr++;
	}		
	if (( *wptr == '/' ) && ( *(wptr+1) == '/' ))
		wptr += 2;
	if (( i = extract_portion( buffer, &wptr, "/" )) > 0 )
		if (!( uptr->host = url_allocate_string( buffer ) ))
			return( 27 );

	if (( i = extract_portion( buffer, &wptr, "#" )) > 0 )
	{
		if (!( uptr->program = url_allocate_string( buffer ) ))
			return( 27 );
		else if (( i = extract_portion( buffer, &wptr, "?" )) > 0 )
		{
			if (!( uptr->procedure = url_allocate_string( buffer ) ))
				return( 27 );
			else if (!( uptr->parameters = url_allocate_string( wptr ) ))
				return( 27 );
		}
		else if (!( uptr->procedure = url_allocate_string( wptr ) ))
			return( 27 );
	}
	else if (( i = extract_portion( buffer, &wptr, "?" )) > 0 )
	{
		if (!( uptr->program = url_allocate_string( buffer ) ))
			return( 27 );
		else if (!( uptr->parameters = url_allocate_string( wptr ) ))
			return( 27 );
	}
	else if (!( uptr->program = url_allocate_string( wptr ) ))
		return( 27 );

	return( 0 );
}

	/* -------- */
#endif	/* _EXURL_C */
	/* -------- */

