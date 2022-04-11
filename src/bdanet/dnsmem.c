#ifndef	_DNSMEM_C
#define	_DNSMEM_C

PRIVATE	struct dns_allocation_control {
	DNSQUESTPTR	qptr;
	DNSRRPTR	rptr;
	DNSNODEPTR	nptr;
	} QuickAlloc;

PUBLIC	VOID	initialise_dns_memory()
{
	QuickAlloc.qptr = (DNSQUESTPTR) 0;
	QuickAlloc.rptr = (DNSRRPTR) 0;
	QuickAlloc.nptr = (DNSNODEPTR) 0;
	return;
}

PUBLIC	VOID	liberate_dns_memory()
{
	DNSQUESTPTR	qptr;
	DNSRRPTR	rptr;
	DNSNODEPTR	nptr;

	while ((qptr = QuickAlloc.qptr) != (DNSQUESTPTR) 0) {
		QuickAlloc.qptr = qptr->next;
		qptr = liberate_zone( qptr );
		}
	while ((rptr = QuickAlloc.rptr) != (DNSRRPTR) 0) {
		QuickAlloc.rptr = rptr->next;
		rptr = liberate_zone( rptr );
		}
	while ((nptr = QuickAlloc.nptr) != (DNSNODEPTR) 0) {
		QuickAlloc.nptr = nptr->next;
		nptr = liberate_zone( nptr );
		}
	return;
}


/*
 *	Communication Transmission/Reception Buffer : DNSBUFFER
 *	-------------------------------------------------------
 *
 */

PUBLIC	DNSBUFFERPTR	liberate_for_buffer( bptr )
	DNSBUFFERPTR	bptr;
{
	if ( bptr != (DNSBUFFERPTR) 0 ) {
		if ( bptr->buffer != (BPTR) 0 )
			bptr->buffer = liberate_zone( bptr->buffer );
		bptr = liberate_zone( bptr );
		}
	return( bptr );
}

PUBLIC	DNSBUFFERPTR	allocate_for_buffer( n )
	INT		n;
{
	DNSBUFFERPTR	bptr;

	if ((bptr = (DNSBUFFERPTR) allocate_zone( sizeof( DNSBUFFER ) )) != (DNSBUFFERPTR) 0) {
		bptr->length = n;
		bptr->indent = 0;
		if ((bptr->buffer = (BPTR) allocate_zone( n )) == (BPTR) 0)
			bptr = liberate_for_buffer( bptr );
		}
	return( bptr );
}

PUBLIC	BPTR	name2string( nptr )
	BPTR	nptr;
{
	BPTR 	tptr;
	BPTR 	sptr;
	INT	nlen;
	
	if ((nptr != (BPTR) 0)
	&&  ((sptr = (BPTR) allocate_zone( (strlen(nptr) + 6) )) != (BPTR) 0)) {
		tptr = sptr;
		while ((nlen = *(nptr++)) != 0) {
			while (nlen) {
				*(tptr++) = *(nptr++);
				nlen--;
				}
			if ( *nptr )
				*(tptr++) = '.';
			else	break;
			}
		*(tptr++) = 0;
		}
	return( sptr );
}

PUBLIC	BPTR	string2name( sptr )
	BPTR	sptr;
{
	BPTR 	tptr;
	BPTR 	nptr;
	INT	nlen;
	if ((sptr != (BPTR) 0)
	&&  ((nptr = (BPTR) allocate_zone( (strlen(sptr) + 6))) != (BPTR) 0)) {
		tptr = nptr;
		while (*sptr) {
			for (nlen=0;;nlen++)
				if ((*(sptr+nlen) == 0) || (*(sptr+nlen) == '.'))
					break;
			if ( nlen ) {
				*(tptr++) = nlen;
				while (nlen) {
					*(tptr++) = *(sptr++);
					nlen--;
					}
				if ( *sptr == '.' ) sptr++;
				}
			else	break;
			}
		*(tptr++) = 0;
		}
	return( nptr );
}

PUBLIC	VOID		replace_name( rptr, nptr )
	DNSRRPTR	rptr;
	BPTR		nptr;
{
	BPTR	sptr;
	if ((sptr = allocate_for_string( nptr )) != (BPTR) 0 ) {
		rptr->name = liberate_zone( rptr->name );
		rptr->name = sptr;
		}
	return;
}

PUBLIC	DNSQUESTPTR	liberate_for_question(qptr)
	DNSQUESTPTR	qptr;
{
	if ( qptr != (DNSQUESTPTR) 0 ) {
		if ( qptr->name != (BPTR) 0 )
			qptr->name = liberate_zone( qptr->name );
		qptr->next = QuickAlloc.qptr;
		QuickAlloc.qptr = qptr;
		qptr = (DNSQUESTPTR) 0;
		}
	return( qptr );
}

PUBLIC	DNSQUESTPTR	allocate_for_question()
{
	DNSQUESTPTR	qptr;

	if ((qptr = QuickAlloc.qptr) != (DNSQUESTPTR) 0)
		QuickAlloc.qptr = qptr->next;
	else if ((qptr = (DNSQUESTPTR) allocate_zone( sizeof( DNSQUEST ) )) == (DNSQUESTPTR) 0)
		return( qptr );

	qptr->type      = 0;
	qptr->class     = 0;
	qptr->next      = (DNSQUESTPTR) 0;
	qptr->name 	= (BPTR) 0;

	return( qptr );
}

PUBLIC	DNSQUESTPTR	build_question(sptr,type,class)
	BPTR		sptr;
	INT		type;
	INT		class;
{
	DNSQUESTPTR	qptr;
	if ((qptr = allocate_for_question()) != (DNSQUESTPTR) 0) {
		qptr->type      = type;
		qptr->class     = class;
		if ((qptr->name = string2name( sptr )) == (BPTR) 0)
			qptr = liberate_for_question( qptr );
		}
	return( qptr );
}

PUBLIC	DNSQUESTPTR	domain_question(domain,type,class)
	BPTR		domain;
	INT		type;
	INT		class;
{
	DNSQUESTPTR	qptr;
	if ((qptr = allocate_for_question()) != (DNSQUESTPTR) 0) {
		qptr->type      = type;
		qptr->class     = class;
		if ((qptr->name = allocate_for_string( domain )) == (BPTR) 0)
			qptr = liberate_for_question( qptr );
		}
	return( qptr );
}

PUBLIC	DNSRRPTR	liberate_for_record(rptr)
	DNSRRPTR	rptr;
{
	if ( rptr != (DNSRRPTR) 0 ) {
		if ( rptr->name != (BPTR) 0 )
			rptr->name = liberate_zone( rptr->name );
		if ( rptr->data != (BPTR) 0 )
			rptr->data = liberate_zone( rptr->data );
		rptr->next = QuickAlloc.rptr;
		QuickAlloc.rptr = rptr;
		rptr = (DNSRRPTR) 0;
		}
	return( rptr );
}

PUBLIC	DNSRRPTR	allocate_for_record()
{
	DNSRRPTR	rptr;
	if ((rptr = QuickAlloc.rptr) != (DNSRRPTR) 0)
		QuickAlloc.rptr = rptr->next;
	else if ((rptr = (DNSRRPTR) allocate_zone( sizeof( DNSRR ) )) == (DNSRRPTR) 0)
		return( rptr );

	rptr->name   = (BPTR) 0;
	rptr->type   = 0;
	rptr->class  = 0;
	rptr->ttl    = 0;
	rptr->dob    = time((LPTR) 0);
	rptr->length = 0;
	rptr->data   = (BPTR) 0;
	rptr->nature = 0;
	rptr->next   = (DNSRRPTR) 0;

	return( rptr );
}

PUBLIC	DNSRRPTR	build_record( nptr, dptr )
	DNSNODEPTR	nptr;
	DNSDATAPTR	dptr;
{
	DNSRRPTR	rptr=(DNSRRPTR) 0;
	LONG		elapsed;
	
	if ((nptr != (DNSNODEPTR) 0)
	&&  (dptr != (DNSDATAPTR) 0)) {
		if ((rptr = allocate_for_record()) != (DNSRRPTR) 0) {
			if ((rptr->name = allocate_for_string( nptr->name )) != (BPTR) 0) {
				rptr->class = nptr->class;
				rptr->type  = dptr->type;
				rptr->ttl   = nptr->ttl;
				if ((elapsed = (time((LPTR) 0) - nptr->dob)) > nptr->ttl )
					rptr->ttl = 0L;
				else	rptr->ttl = (nptr->ttl - elapsed);
				if ((rptr->length = dptr->size) != 0) {
					if ((rptr->data = allocate_zone( rptr->length )) != (BPTR) 0)
						memcpy( rptr->data, dptr->data, rptr->length );
					else	rptr = liberate_for_record( rptr );
					}
				}
			else	rptr = liberate_for_record( rptr );
			}
		}
	return( rptr );
}


PUBLIC	DNSRRPTR	duplicate_record( sptr )
	DNSRRPTR	sptr;
{
	DNSRRPTR	rptr;
	LONG	elapsed;

	if ((rptr = allocate_for_record()) != (DNSRRPTR) 0) {
		rptr->type   = sptr->type;
		rptr->class  = sptr->class;
		rptr->ttl    = sptr->ttl;
		if ((elapsed = (time((LPTR) 0) - sptr->dob)) > sptr->ttl )
			rptr->ttl = 0L;
		else	rptr->ttl = (sptr->ttl - elapsed);
		if ((rptr->name   = allocate_for_string( sptr->name )) == (BPTR) 0)
			rptr = liberate_for_record( rptr );
		else	{
			rptr->length = sptr->length;
			if ((rptr->data = allocate_zone( rptr->length )) == (BPTR) 0)
				rptr = liberate_for_record( rptr );
			else	memcpy( rptr->data, sptr->data, rptr->length );
			}
		}
	return( rptr );
}			

PUBLIC	DNSRRPTR	liberate_records( sptr )
	DNSRRPTR	sptr;
{
	DNSRRPTR	rptr;
	while ((rptr = sptr ) != (DNSRRPTR) 0) {
		sptr = rptr->next;
		rptr = liberate_for_record( rptr );
		}
	return( sptr );
}

PUBLIC	DNSMSGPTR	liberate_for_message( mptr )
	DNSMSGPTR	mptr;
{
	DNSQUESTPTR	qptr;
	DNSRRPTR	rptr;

	if ( mptr != (DNSMSGPTR) 0) {
		while ((qptr = mptr->Questions) != (DNSQUESTPTR) 0) {
			mptr->Questions = qptr->next;
			qptr = liberate_for_question( qptr );
			}
		mptr->Answers = liberate_records( mptr->Answers );
		mptr->Authority = liberate_records( mptr->Authority );
		mptr->Additional = liberate_records( mptr->Additional );
		mptr = liberate_zone( mptr );
		}
	return( mptr );
}

PUBLIC	DNSDATAPTR	liberate_for_data( nptr )
	DNSDATAPTR	nptr;
{
	if ( nptr != (DNSDATAPTR) 0 ) 
		nptr = liberate_zone( nptr );
	return( nptr );
}

PUBLIC	DNSDATAPTR	allocate_for_data( n )
	INT		n;
{
	DNSDATAPTR	nptr;
	if ((nptr = (DNSDATAPTR) allocate_zone( (sizeof( DNSDATA ) + (n - 4)) )) != (DNSDATAPTR) 0) {
		nptr->type=0;
		nptr->next = (DNSDATAPTR) 0;
		nptr->size = n;
		memset(nptr->data,0,n);
		}
	return( nptr );
}

PUBLIC	DNSNODEPTR	liberate_for_node(nptr)
	DNSNODEPTR	nptr;
{
	DNSDATAPTR	dptr;
	if ( nptr != (DNSNODEPTR) 0 ) {
		if ( nptr->name != (BPTR) 0) 
			nptr->name = liberate_zone( nptr->name );
		while ((dptr = nptr->rr) != (DNSDATAPTR) 0) {
			nptr->rr = dptr->next;
			dptr = liberate_for_data( dptr );
			}
		nptr->next = QuickAlloc.nptr;
		QuickAlloc.nptr = nptr;
		nptr = (DNSRRPTR) 0;
		}
	return( nptr );
}

PUBLIC	DNSNODEPTR	allocate_for_node()
{
	DNSNODEPTR	nptr;
	if ((nptr = QuickAlloc.nptr) != (DNSNODEPTR) 0)
		QuickAlloc.nptr = nptr->next;
	else if ((nptr = (DNSNODEPTR) allocate_zone( sizeof( DNSNODE ) )) == (DNSNODEPTR) 0)
		return( nptr );

	nptr->name=(BPTR) 0;
	nptr->class=0;
	nptr->ttl=0L;
	nptr->dob=time((LPTR) 0);
	nptr->rr = (DNSDATAPTR) 0;
	nptr->next = (DNSNODEPTR) 0;
	nptr->prev = (DNSNODEPTR) 0;
	return( nptr );
}

PUBLIC	VOID		reset_header( hptr )
	DNSHEADPTR	hptr;
{
	hptr->identity		= 0;
	hptr->qCode		= 0;
	hptr->rCode		= 0;
	hptr->Flags		= 0;
	hptr->Questions		= 0;
	hptr->Answers		= 0;
	hptr->Authority  	= 0;
	hptr->Additional	= 0;
	return;
}

PUBLIC	DNSMSGPTR	allocate_for_message()
{
	DNSMSGPTR	mptr;
	if ((mptr = (DNSMSGPTR) allocate_zone( sizeof( DNSMSG ) )) != (DNSMSGPTR) 0) {
		mptr->TransferLength = 0;
		reset_header( (DNSHEADPTR) & mptr->Header );
		mptr->Questions  = (DNSQUESTPTR) 0;
		mptr->Answers    = (DNSRRPTR) 0;
		mptr->Authority  = (DNSRRPTR) 0;
		mptr->Additional = (DNSRRPTR) 0;
		}
	return( mptr );
}

PUBLIC	DNSSOAPTR	liberate_for_soa(hptr)
	DNSSOAPTR	hptr;
{
	if ( hptr != (DNSSOAPTR) 0) {
		if ( hptr->name != (BPTR) 0) 
			hptr->name = liberate_zone( hptr->name );
		if ( hptr->host != (BPTR) 0) 
			hptr->host = liberate_zone( hptr->host );
		if ( hptr->mail != (BPTR) 0) 
			hptr->mail = liberate_zone( hptr->mail );
		hptr = liberate_zone( hptr );
		}
	return( hptr );
}

PUBLIC	DNSCACHEPTR	liberate_for_cache(cptr)
	DNSCACHEPTR	cptr;
{
	INT		i=0;
	DNSNODEPTR	nptr=(DNSNODEPTR) 0;
	DNSNODEPTR	xptr=(DNSNODEPTR) 0;
	if (cptr != (DNSCACHEPTR) 0) {
		for ( i= 0; i < DNS_HASH; i++ ) {
			if ((nptr = cptr->Table[i]) != (DNSNODEPTR) 0) {
				do	{
					xptr = nptr->next;
					nptr = liberate_for_node( nptr );
					}
				while ((nptr = xptr) != (DNSNODEPTR) 0);
				}
			}
		if ( cptr->Header != (DNSSOAPTR) 0 )
			cptr->Header = liberate_for_soa( cptr->Header );

		cptr = liberate_zone( cptr );
		}
	return( cptr );
}

PUBLIC	DNSCACHEPTR	allocate_for_cache()
{
	INT		i=0;
	DNSCACHEPTR	cptr=(DNSCACHEPTR) 0;
	if ((cptr = (DNSCACHEPTR) allocate_zone( sizeof( DNSCACHE ) )) != (DNSCACHEPTR) 0) {
		for ( i= 0; i < DNS_HASH; i++ ) {
			cptr->Table[i] = (DNSNODEPTR) 0;
			cptr->Distribution[i]  = 0;
			}
		cptr->Locked = 0;
		cptr->Header = (DNSSOAPTR) 0;
		}
	return	( cptr );
}

PUBLIC	DNSCONTEXTPTR	liberate_for_context(cptr)
	DNSCONTEXTPTR	cptr;
{
	if ( cptr != (DNSCONTEXTPTR) 0 ) {
		cptr->Authority = liberate_for_cache( cptr->Authority );
		cptr->Cache = liberate_for_cache( cptr->Cache );
		cptr->Master = liberate_zone( cptr->Master );
		cptr = liberate_zone( cptr );
		}
	return( cptr );
}

PUBLIC	DNSSOAPTR	allocate_for_soa()
{
	DNSSOAPTR	hptr;
	if ((hptr = (DNSSOAPTR) allocate_zone( sizeof( DNSSOA ) )) != (DNSSOAPTR) 0) {
		hptr->name		= (BPTR) 0;
		hptr->class		= 0;
		hptr->type		= 0;
		hptr->dob		= time((LPTR) 0);
		hptr->host        	= (BPTR) 0;
		hptr->mail        	= (BPTR) 0;
		hptr->ttl		= 0L;
		hptr->serial		= 0L;
		hptr->refresh		= 0L;
		hptr->retry		= 0L;
		hptr->expire		= 0L;
		hptr->minimum		= 0L;
		}
	return( hptr );
}

PUBLIC	DNSHOSTPTR	liberate_for_host(hptr)
	DNSHOSTPTR	hptr;
{
	if ( hptr != (DNSHOSTPTR) 0 ) {
		if (hptr->address != (BPTR) 0)
			hptr->address = liberate_zone( hptr->address );
		if (hptr->domain != (BPTR) 0 )
			hptr->domain = liberate_zone( hptr->domain );
		hptr = liberate_zone( hptr );
		}
	return( hptr );
}

PUBLIC	DNSHOSTPTR	allocate_for_host()
{
	DNSHOSTPTR	hptr;
	if ((hptr = (DNSHOSTPTR) allocate_zone( sizeof( DNSHOST) )) != (DNSHOSTPTR) 0) {
		hptr->address = (BPTR) 0;
		hptr->domain  = (BPTR) 0;
		hptr->next    = (BPTR) 0;
		hptr->status  = 0;
		}
	return( hptr );
}

PUBLIC	BPTR	allocate_for_address( address )
	ADDRPTR	address;
{
	BPTR	aptr=(BPTR) 0;
	BYTE	buffer[32];
	if ( address == (ADDRPTR) 0 )
		return( aptr );
	else	{
		aptr = (BPTR) &address->sin_addr;
		sprintf(buffer,"%s//%u.%u.%u.%u",
			__DNS_PREFIX,
			( *(aptr + 0) & 0x00FF),
			( *(aptr + 1) & 0x00FF),
			( *(aptr + 2) & 0x00FF),
			( *(aptr + 3) & 0x00FF));
		return( allocate_for_string( buffer ) );
		}
}

PUBLIC	DNSHOSTPTR	build_host(name, address, domain )
	BPTR		name;
	ADDRPTR		address;
	BPTR		domain;
{
	DNSHOSTPTR	hptr;
	if ((hptr = allocate_for_host()) == (DNSHOSTPTR) 0)
		return( hptr );
	else if ((domain != (BPTR) 0)
	     &&  ((hptr->domain = allocate_for_string( domain )) == (BPTR) 0))
		return((hptr = liberate_for_host( hptr )));
	else if (( name != (BPTR) 0 )
	     &&  ((hptr->address = allocate_for_string( name )) != (BPTR) 0))
		return( hptr );
	else if ((address != (ADDRPTR) 0)
	     && ((hptr->address = allocate_for_address( address )) != (BPTR) 0))
		return( hptr );
	else	return((hptr = liberate_for_host( hptr )));
}

PUBLIC	DNSCONTEXTPTR	allocate_for_context(master_file)
	BPTR		master_file;
{
	DNSCONTEXTPTR	cptr=(DNSCONTEXTPTR) 0;
	if ( master_file != (BPTR) 0 ) {
		if ((cptr = (DNSCONTEXTPTR) allocate_zone( sizeof( DNSCONTEXT ) )) != (DNSCONTEXTPTR) 0) {
			cptr->Authority = (DNSCACHEPTR) 0;
			cptr->Cache     = (DNSCACHEPTR) 0;
			cptr->Origin[0] = 0;
			cptr->CacheHits = 0;
			cptr->CacheMiss = 0;
			cptr->Master    = (BPTR) 0;
			if (( cptr->Master = allocate_for_string( master_file )) == (BPTR) 0)
				cptr = liberate_for_context( cptr );
			}
		}
	return( cptr );
}

PUBLIC	DNSRCVPTR	liberate_for_reception( rptr )
	DNSRCVPTR	rptr;
{
	if ( rptr != (DNSRCVPTR) 0 ) {
		if ( rptr->usage != 0 )
			rptr->usage--;
		if (!( rptr->usage )) {
			rptr->message    = liberate_for_message( rptr->message );
			rptr->connection = liberate_for_connection( rptr->connection );
			rptr = liberate_zone( rptr );
			}
		else	rptr = (DNSRCVPTR) 0;
		}
	return( rptr );
}

PUBLIC	DNSRCVPTR	allocate_for_reception( cptr )
	CONNECTIONPTR	cptr;
{
	DNSRCVPTR	rptr=(DNSRCVPTR) 0;
	if ( cptr != (CONNECTIONPTR) 0 ) {
		if ((rptr = (DNSRCVPTR) allocate_zone( sizeof( DNSRCV ) )) != (DNSRCVPTR) 0) {
			rptr->identity = 0;
			rptr->status = 0;
			rptr->usage = 1;
			rptr->message = (DNSMSGPTR) 0;
			rptr->connection = (CONNECTIONPTR) 0;
			if (((rptr->message = allocate_for_message()) == (DNSMSGPTR) 0)
			||  ((rptr->connection = copy_connection( cptr )) == (CONNECTIONPTR) 0))
				rptr = liberate_for_reception( rptr );
			}
		}
	return( rptr );
}

PUBLIC	DNSFWDPTR	liberate_for_forward( fptr )
	DNSFWDPTR	fptr;
{
	if ( fptr != (DNSFWDPTR) 0 ) {
		fptr->message    = liberate_for_message( fptr->message );
		fptr->url        = liberate_for_url( fptr->url );
		fptr->connection = liberate_for_connection( fptr->connection );
		fptr->reason     = liberate_for_reception( fptr->reason );
		fptr = liberate_zone( fptr );
		}
	return( fptr );

}

PUBLIC	DNSFWDPTR	allocate_for_forward()
{
	DNSFWDPTR	fptr;
	if ((fptr = (DNSFWDPTR) allocate_zone( sizeof( DNSFWD ) )) != (DNSFWDPTR) 0) {
		fptr->dob    	 	= time((LPTR) 0);
		fptr->ttl		= 10L;
		fptr->identity	 	= 0;
		fptr->url		= (URLPTR) 0;
		fptr->connection	= (CONNECTIONPTR) 0;
		fptr->message		= (DNSMSGPTR) 0;
		fptr->reason		= (DNSRCVPTR) 0;
		fptr->next		= (DNSFWDPTR) 0;
		fptr->previous		= (DNSFWDPTR) 0;
		}
	return( fptr );
}

INT		record_still_live( rptr )
DNSRRPTR	rptr;
{
	LONG	elapsed;

	/* ------------------------ */
	/* Recalculate 'TimeToLive' */
	/* ------------------------ */
	if ((elapsed = (time((LPTR) 0) - rptr->dob)) > rptr->ttl )
		rptr->ttl = 0L;
	else	{
		rptr->ttl = (rptr->ttl - elapsed);
		rptr->dob += elapsed;
		}

	/* -------------------------------------------------- */
	/* If Record has Not Expired  Then OK Record is Valid */
	/* -------------------------------------------------- */
	if ( rptr->ttl > 0 )
		return( 1 );
	else	return( 0 );
}

INT		node_still_live( nptr )
DNSNODEPTR	nptr;
{
	LONG	elapsed;

	/* ------------------------ */
	/* Recalculate 'TimeToLive' */
	/* ------------------------ */
	if ((elapsed = (time((LONG *)0) - nptr->dob)) > nptr->ttl )
		nptr->ttl = 0L;
	else	{
		nptr->ttl = (nptr->ttl - elapsed);
		nptr->dob += elapsed;
		}

	/* -------------------------------------------------- */
	/* If Record has Not Expired  Then OK Record is Valid */
	/* -------------------------------------------------- */
	if ( nptr->ttl > 0L )
		return( 1 );
	else	return( 0 );
}

INT		zone_still_live( hptr )
DNSSOAPTR	hptr;
{
	LONG	elapsed;

	/* ------------------------ */
	/* Recalculate 'TimeToLive' */
	/* ------------------------ */
	if ((elapsed = (time((LPTR) 0) - hptr->dob)) > hptr->ttl )
		hptr->ttl = 0L;
	else	{
		hptr->ttl = (hptr->ttl - elapsed);
		hptr->dob += elapsed;
		}

	/* ---------------------------------------------------- */
	/* If Record has Not Expired  Then OK Soa Zone is Valid */
	/* ---------------------------------------------------- */
	if ( hptr->ttl > 0L )
		return( 1 );
	else	return( 0 );
}

INT		forward_still_live( hptr )
DNSFWDPTR	hptr;
{
	LONG	elapsed;

	/* ------------------------ */
	/* Recalculate 'TimeToLive' */
	/* ------------------------ */
	if ((elapsed = (time((LPTR) 0) - hptr->dob)) > hptr->ttl )
		hptr->ttl = 0L;
	else	{
		hptr->ttl = (hptr->ttl - elapsed);
		hptr->dob += elapsed;
		}

	/* ---------------------------------------------------- */
	/* If Record has Not Expired  Then FWD Request is Valid */
	/* ---------------------------------------------------- */
	if ( hptr->ttl > 0L )
		return( 1 );
	else	return( 0 );
}

PUBLIC 	INT	mem_getw(buffer)
	BPTR	buffer;
{
	 INT	v;
	v = *(buffer++);
	v <<= 8; v &= 0xFF00;
	v |= (*(buffer++) & 0x00FF);
	return( (v & 0xFFFF) );
}

PUBLIC 	LONG	mem_getl(buffer)
	BPTR	buffer;
{
	LONG	r;
	INT	v;
	v = mem_getw(buffer);
	r = (( LONG) v << 16);
	v = mem_getw((buffer+2));
	r += (( LONG) v);
	return( r );
}

PUBLIC 	BPTR	mem_putw(buffer, v )
	BPTR	buffer;
	INT  	v;
{
	*(buffer++) = ((v >> 8) & 0x00FF);
	*(buffer++) = (v  & 0x00FF);
	return( buffer );
}

PUBLIC 	BPTR	mem_putl(buffer, l )
	BPTR	buffer;
	LONG l;
{
	INT i;
	i = (INT) (l >> 16);
	buffer = mem_putw(buffer, i );
	i = (INT) l;
	buffer = mem_putw(buffer, i );
	return;
}


#endif	/* _DNSMEM_C */
	/* --------- */


