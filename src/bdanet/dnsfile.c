
BYTE	DefaultDomain[256];
LONG	DefaultTTL;
WORD	DefaultClass;
BYTE	TempToken[256];

PRIVATE	BPTR	parse_white_space( bptr )
BPTR		bptr;
{
	/* Skip over white space */
	/* --------------------- */
	while (( *bptr ) && ( *bptr == ' ')) bptr++;

	/* Detect and skip over comment */
	/* ---------------------------- */
	if ( *bptr == ';' )
		while ( *bptr )
			bptr++;

	/* Return pointer */
	/* -------------- */
	return( bptr );
}

PRIVATE	BPTR	parse_token( sptr, rptr )
BPTR		sptr;
BPTR		rptr;
{
	INT	max=256;
	while ((max) 	&& (*sptr) 
			&& (*sptr != ' ') 
			&& (*sptr != ')') 
			&& (*sptr != '(')) {
		*(rptr++) = *(sptr++);
		max--;
		}

	*(rptr++) = 0;
	if ( max )
		return( parse_white_space( sptr ) );
	else	return( (BPTR) 0 );
}

LONG	parselong( sptr )
BPTR	sptr;
{
	LONG	templong=0L;

	while ((*sptr) && (*sptr >= '0') && (*sptr <= '9')) {
		templong *= 10;
		templong += ((LONG)(*(sptr++) -'0'));
		}
	return( templong );
}

PRIVATE	INT	control_entry( token, bptr )
BPTR		token;
BPTR		bptr;
{
	INT	tlen=0;
	BPTR  holdorigin=(BPTR) 0;
	INT	status=0;

	if ( compare_tokens( token, "$ORIGIN" ) != 0 ) {

		/* Collect <domain-name> to be used as new ORIGIN */
		/* ---------------------------------------------- */
		if ((bptr = parse_token( bptr, TempToken )) == (BPTR) 0)
			return( 27 );
		else 	{
			strcpy( DnsManager->Origin, TempToken );
			return( 0 );
			}
		}

	else if ( compare_tokens( token, "$INCLUDE" ) != 0 ) {

		/* Collect <filename> to be included */
		/* --------------------------------- */
		if ((bptr = parse_token( bptr, TempToken )) == (BPTR) 0)
			return( 27 );
		else if ((holdorigin = allocate_for_string( DnsManager->Origin )) == (BPTR) 0)
			return( 27 );
		else	{
			status = read_configuration( TempToken );
			strcpy( DnsManager->Origin, holdorigin );
			holdorigin = liberate_zone( holdorigin );
			return( status );
			}
		}
	else	return( 30 );

}

INT	check_relative_domain()
{
	/* Check Other strings for absolute/relative */
	/* ----------------------------------------- */
	if ( TempToken[ (strlen(TempToken)-1) ] != '.' ) {

		/* Relative Domain Name (without '.') */
		/* ---------------------------------- */
		if ( DnsManager->Origin[0] == 0 )

			/* Error ORIGIN NOT SPECIFIED */
			/* -------------------------- */
			return( 33 );

		else 	{
			/* Concatenate with ORIGIN */
			/* ----------------------- */
			strcat( TempToken, "." );
			strcat( TempToken, DnsManager->Origin );
			}
		}
	return( 0 );
}


INT		parse_soa( hptr, bptr )
DNSSOAPTR	hptr;
BPTR		bptr;
{
	INT	error_status=0;
	if ((bptr = parse_token( bptr, TempToken )) == (BPTR) 0)
		return( 63 );
	else if ((error_status = check_relative_domain()) != 0)
		return( error_status );
	else if ((hptr->host = string2name( TempToken )) == (BPTR ) 0)
		return( 27 );
	else if ((bptr = parse_token( bptr, TempToken )) == (BPTR) 0)
		return( 63 );
	else if ((error_status  = check_relative_domain()) != 0)
		return( error_status );
	else if ((hptr->mail = string2name( TempToken )) == (BPTR ) 0)
		return( 27 );
	if ((bptr = parse_token( bptr, TempToken )) == (BPTR) 0)
		return( 63 );
	else	hptr->serial = parselong( TempToken );
	if ((bptr = parse_token( bptr, TempToken )) == (BPTR) 0)
		return( 63 );
	else	hptr->refresh = parselong( TempToken );
	if ((bptr = parse_token( bptr, TempToken )) == (BPTR) 0)
		return( 63 );
	else	hptr->retry = parselong( TempToken );
	if ((bptr = parse_token( bptr, TempToken )) == (BPTR) 0)
		return( 63 );
	else	hptr->expire = parselong( TempToken );
	if ((bptr = parse_token( bptr, TempToken )) == (BPTR) 0)
		return( 63 );
	else	hptr->minimum = parselong( TempToken );
	hptr->ttl = hptr->refresh;
	return( 0 );

}

/*
 *	A N A L Y S E _ L I N E ( handle , buffer )
 *	-------------------------------------------
 *	This function analyses a line read from a DNS master file.
 *	Upon succesful completion the function will return ZERO
 *	otherwise an error code will be returned indicating the
 *	nature of the failure.
 *
 *	Possible Errors :	63	Exceeded Maximum Token Size (256)
 *				27	Memory Allocation Failure
 *				3x	Various types of syntax error.
 *
 *	SYNTAX
 *	------
 * 	
 *	[ <domain-name> | <whitespace> ] [ <class> | <ttl> ] <type> <data>
 *
 *	Optional items will default to tha last value for the relevent item.
 *
 */

PRIVATE	INT	analyse_line( handle, buffer )
INT	handle;		/* This is needed to be able to read another line */
			/* in case of left brace '(' read next line	  */
BPTR	buffer;		/* Line buffer to be analysed (null terminated)   */
{
	DNSSOAPTR	hptr=(DNSSOAPTR) 0;
	DNSRRPTR	rptr=(DNSRRPTR) 0;
	DNSRRPTR	xptr=(DNSRRPTR) 0;
	BPTR		bptr=(BPTR) 0;
	BPTR		sptr=(BPTR) 0;
	LONG		inetaddr=0L;
	INT		error_status=0;

	/* Collect <domain-name> Token (white space remove after) */
	/* ------------------------------------------------------ */
	if ((bptr = parse_token( buffer, TempToken )) == (BPTR) 0)

		/* This happens when the token is too long */
		/* --------------------------------------- */
		return( 63 );


	/* Analyse <domain-name> Token */
	/* --------------------------- */
	switch ( TempToken[0] ) {

		case	0	:
			/* An empty domain name implies the previous name */
			/* ---------------------------------------------- */
			if ( DefaultDomain[0] == 0 )
				return( 31 );
			strcpy( TempToken, DefaultDomain );
			break;

		case	'$'	:

			/* The Dollar Prefix implies a Control Keyword */
			/* ------------------------------------------- */
			return( control_entry( TempToken, bptr ) );

		case	'@'	:

			/* The AT sign implies the current Domain Origin */
			/* --------------------------------------------- */
			if ( DnsManager->Origin[0] == 0 )
				return( 32 );
			strcpy( TempToken, DnsManager->Origin );
			break;

		default		:
			
			if ((error_status = check_relative_domain()) != 0)
				return( error_status );
		}

	/* Allocate a new resource record */
	/* ------------------------------ */
	if ((rptr = allocate_for_record()) == (DNSRRPTR) 0)

		/* Allocation Failure */
		/* ------------------ */
		return(27);

	/* Convert <domain-name> string to <domain-name> name */
	/* -------------------------------------------------- */
	else if ((rptr->name = string2name( TempToken )) == (BPTR) 0) {

		/* Allocation Failure */
		/* ------------------ */
		rptr = liberate_for_record( rptr );
		return(27);

		}

	else	/* Establish Default for other Records */
		/* ----------------------------------- */
		strcpy( DefaultDomain, TempToken );

	/* Analyse until record type found or ERROR occurs */
	/* ----------------------------------------------- */
	while ((!( rptr->type   )) &&  (!( error_status ))) {

		/* Collect a Token for analysis */
		/* ---------------------------- */
		if ((bptr = parse_token( bptr, TempToken )) == (BPTR) 0)
			error_status = 63;
			
		/* The actual record TYPE will preceed its DATA */
		/* -------------------------------------------- */
		else if ((rptr->type = resolve_type( TempToken )) != 0 )
			error_status = 0;

		/* It may be the TTL value, or the CLASS value */
		/* ------------------------------------------- */
		else if ((TempToken[0] >= '0') && (TempToken[0] <= '9')) {

			if ((rptr->ttl = parselong( TempToken )) > 0L )
				DefaultTTL = rptr->ttl;

			/* Establish Default TTL */
			/* --------------------- */
			DefaultTTL = rptr->ttl;

			}

		/* It may be the CLASS mnemonic */
		/* ---------------------------- */
		else if ((rptr->class = resolve_dns_class( TempToken )) != 0 )
			DefaultClass = rptr->class;

		else 	/* Syntax error */
			/* ------------ */
			error_status = 30;

		}

	/* Ensure no error has occured */
	/* --------------------------- */
	if (!( error_status )) {

		if ( rptr->class == 0 )
			rptr->class = DefaultClass;

		if ( rptr->ttl == 0L )
			rptr->ttl = DefaultTTL;


		/* Collect Type Specific Record DATA */
		/* --------------------------------- */
		switch ( rptr->type ) {

			case	__DNS_TYPE_A		:

				if ((bptr = parse_token( bptr, TempToken )) == (BPTR) 0)
					error_status = 63;
				else	{
					inetaddr = inet_addr( TempToken );
					if ((rptr->data = (BPTR) allocate_zone((rptr->length = 4))) == (BPTR) 0)
						error_status = 27;
					else 	memcpy(rptr->data,(BPTR) & inetaddr, rptr->length);
					}
				break;

			case	__DNS_TYPE_CNAME 	:
			case	__DNS_TYPE_NS		:
			case	__DNS_TYPE_PTR		:

				if ((bptr = parse_token( bptr, TempToken )) == (BPTR) 0)
					error_status = 63;
				else if ((error_status = check_relative_domain()) != 0);
				else if ((rptr->data = string2name( TempToken )) == (BPTR ) 0)
					error_status = 27;
				else	rptr->length = (strlen( rptr->data ) + 1);
				break;

			case	__DNS_TYPE_SOA		:

				if ((error_status = validate_authority()) == 0) {
					if ((hptr = allocate_for_soa()) == (DNSSOAPTR) 0)
						error_status = 27;
					else if ((error_status = parse_soa( hptr, bptr )) != 0)
						hptr = liberate_for_soa( hptr );
					else	{
						hptr->name  = rptr->name;
						rptr->name  = (BPTR) 0;
						hptr->class = rptr->class;
						hptr->type  = rptr->type;
						if (DnsManager->Authority->Header == (DNSSOAPTR) 0) {
							DnsManager->Authority->Header = hptr;
							rptr = liberate_for_record( rptr );
							return( 0 );
							}
						else	{
							hptr = liberate_for_soa( hptr );
							error_status = 42;
							}
						}
					}
				break;


			case	__DNS_TYPE_HINFO	:
			case	__DNS_TYPE_MX		:
			case	__DNS_TYPE_WKS		:
			default				:
				error_status = 56;
			}

		if (!( error_status )) {

			/* The record is correct and may be Stored */
			/* --------------------------------------- */
			rptr->nature = 1;
		
			if ( debug )
				show_record( rptr );

			error_status = authoritive_record( rptr );

			}
		}

	/* Release the Record Structure before return with error value */
	/* ----------------------------------------------------------- */
	rptr = liberate_for_record( rptr );
	return(error_status);
}

PRIVATE	INT	read_configuration( nptr )
BPTR		nptr;
{
	INT		handle=0;
	INT		llen=0;
	INT		status=27;
	BPTR		linebuffer=(BPTR) 0;

	/* Attempt to allocate a standard line buffer */
	/* ------------------------------------------ */
	if ((linebuffer = allocate_zone( MAX_NAME_LENGTH )) != (BPTR) 0) {

		/* Attempt to Open the Configuration Master File */
		/* --------------------------------------------- */
		if ((handle = FileOpen( nptr, O_RDONLY )) >= 0 ) {

			if ( verbose )
				printf("DNS Master File : %s \n",nptr);

			/* Reset Record Default Values */
			/* --------------------------- */
			DefaultDomain[0] = 0; DefaultClass = 0; DefaultTTL = 0L;

			/* Read until End of File */
			/* ---------------------- */
			while ((llen = FileGetLine( handle, linebuffer, MAX_NAME_LENGTH )) != 0) {

				/* Avoid Empty Lines */
				/* ----------------- */
				if ( *linebuffer == 0 )
					continue;
				else if ((status = analyse_line( handle, linebuffer )) != 0)
					break;
				}

			/* Close File and Release Line Buffer */
			/* ---------------------------------- */
			FileClose( handle ); linebuffer = liberate_zone( linebuffer );

			/* Indicate Success */
			/* ---------------- */
			if (status )
				if ( verbose )
					printf("* * Master Configuration Failure : Error Code : %u : File %s * *\n",status,nptr);

			}
		else	{
			if ( verbose )
				printf("* * Master Configuration Failure : File Not Found  %s * *\n",nptr);
			/* Release Allocated Line Buffer */
			/* ----------------------------- */
			linebuffer = liberate_zone( linebuffer );
			status = 40;
			}
		}
	else	{
		if ( verbose )
			printf("* * Master Configuration Failure : Memory Allocation : File %s * *\n",nptr);
		status = 27;
		}
	return( status );
}

PRIVATE	VOID	refresh_time_to_live( cptr )
DNSCACHEPTR	cptr;
{
	DNSNODEPTR	rptr;
	INT		i=0;
	if ( cptr != (DNSCACHEPTR) 0 ) {
		for ( i= 0; i < DNS_HASH; i++) {
			if ((rptr = cptr->Table[i]) != (DNSNODEPTR) 0) {
				do	{
					if (!( node_still_live( rptr ))) {
						rptr->ttl = 360L;
						rptr->dob = time((LPTR) 0);
						}
					}
				while ((rptr = rptr->next) != (DNSNODEPTR) 0);
				}
			}
		}
	return;
}



PUBLIC	INT	load_configuration()
{
	DNSCACHEPTR	cache=(DNSCACHEPTR) 0;
	DNSCACHEPTR	oldcache=(DNSCACHEPTR) 0;

	/* Avoid Recursive Entry */
	/* --------------------- */
	if (( DnsManager->Authority != (DNSCACHEPTR) 0)
	&&  ( DnsManager->Authority->Locked ))
		return( 0 );

	/* Attempt to allocate a Working Cache */
	/* ----------------------------------- */
	else if ((cache = allocate_for_cache()) == (DNSCACHEPTR) 0) {
		if (DnsManager->Authority != (DNSCACHEPTR) 0) {
			refresh_time_to_live( DnsManager->Authority );
			return( 1 );
			}
		else	return( 0 );
		}
	else	{
		oldcache = DnsManager->Authority;
		DnsManager->Authority = cache;
		cache->Locked = 1;
		}


	/* Perform ReRead of Master Authority File (Keeping Cache) */
	/* ------------------------------------------------------- */
	if ( read_configuration( DnsManager->Master ) == 0 ) {

		/* Liberate Previous ZONE */
		/* ---------------------- */
		oldcache = liberate_for_cache( oldcache );

		DnsManager->Authority->Locked = 0;

		return( 1 );

		}

	/* Release anthing read in before error */
	/* ------------------------------------ */
	if ( cache != (DNSCACHEPTR) 0 )
		cache = liberate_for_cache( cache );

	/* And restitute the previous condition */
	/* ------------------------------------ */
	if ((DnsManager->Authority = oldcache) != (DNSCACHEPTR) 0) {
		refresh_time_to_live( oldcache );
		oldcache->Locked = 0;
		return( 1 );
		}
	else	/* Signal Failure if caller requires */
		/* --------------------------------- */
		return(0);

}

PUBLIC	INT	request_refresh( hptr )
DNSSOAPTR	hptr;
{
	/* Must Request Refresh from Primary Host */
	/* -------------------------------------- */
	return(0);
}


PUBLIC	INT	refresh_configuration()
{
	DNSSOAPTR	hptr;
	if (DnsManager->Authority == (DNSCACHEPTR) 0)
		return( load_configuration() );
	else if ((hptr = DnsManager->Authority->Header) == (DNSSOAPTR) 0)
		return( load_configuration() );
	else if ( strlen(hptr->host) == 0 )
		return( load_configuration() );
	else 	{
		if ( request_refresh(hptr) == 0)
			hptr->ttl = hptr->retry;
		return( 0 );
		}
}


