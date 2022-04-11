#ifndef	_DNSERV_C
#define	_DNSERV_C

#include "http.h"
#include "url.h"
#include "internet.h"
#include "dns.h"
#include "httpsock.c"
#include "httpfile.c"
#include "url.c"
#include "httpcnx.c"
#include "dnsmem.c"
#include "dnsvis.c"
#include "dnsget.c"
#include "dnsput.c"
#include "dns.c"

PRIVATE	INT	read_configuration( BPTR );

#define	MAX_CLIENTS	13
#define	BUFSIZ		2048

PRIVATE	DNSFWDPTR	PendingRequests=(DNSFWDPTR) 0;

PUBLIC	DNSCONTEXTPTR	DnsManager=(DNSCONTEXTPTR) 0;

BPTR		ServerName=(BPTR) 0;
BPTR  		TraceName=(BPTR) 0;
BYTE		ServerIdentity[256];
INT		PrivateServer=0;
BYTE 		PrivateIdentity[256];
INT		ConnectionCounter=0;

/*
 *	--------------------------------------------------------------------
 *	D N S _ S E R V E R _ B A N N E R ()
 *	--------------------------------------------------------------------
 *	This function simply display visual identification information
 *	concerning this module, date, version etc.
 *	--------------------------------------------------------------------
 */

VOID	dns_server_banner()
{
	printf("   dns: Domain Name Server  Version %s \n",__HTTP_VERSION);
	printf("   Provisoire du %s \n",__HTTP_DATE);
	printf("   Copyright (C) 1997 Amenesik / Sologic \n");
	return;
}

/*
 *	--------------------------------------------------------------------
 *	R E P O R T _ F A I L U R E ( mptr )
 *	--------------------------------------------------------------------
 *	This function is called to report failure during the DNS module
 *	startup routines to inform the caller of the reason for failure.
 *	--------------------------------------------------------------------
 */

INT	report_failure( mptr )
BPTR mptr;
{
	if ( trace_active ) {
		trace_puts(ServerIdentity);
		trace_puts(":error: "); trace_puts(mptr); trace_putw(errno);
		trace_line();
		terminate_trace();
		}
	printf("%s:error: %s (%d) \n",ServerIdentity,mptr,errno);
	if ( errno )
		return( errno );
	else	return( 1 );
}

/*
 *	----------------------------------------------------
 *	R E P O R T _ A L L O C A T I O N _ F A I L U R E ()
 *	----------------------------------------------------
 *	This function provides the advisory role of informing the
 *	occurance of allocation failure conditions. This will not
 *	disturb the state of the DNS but may lead however to 
 *	in exact results. The caller has the resonsibillity of
 *	reacting to the nature of the gravity of the situation.
 */

VOID	report_allocation_failure()
{
	report_failure( "Memory Allocation Failure" );
	return;
}

/*
 *	--------------------------------------------------------------------
 *	P R I V A T I S E ( nptr )
 *	--------------------------------------------------------------------
 *	This function is called in order to restrict the usage of the DNS
 *	for administrative reasons.
 *	--------------------------------------------------------------------
 */

INT	privatise( nptr )
BPTR 	nptr;
{
	BPTR sptr;
	struct  hostent  PTR hp=(struct hostent PTR) 0;
	struct  sockaddr_in MyAddress;

	if ( verbose )
		printf("dns:(%s).private\n",nptr);

	if (( *nptr >= '0' ) && ( *nptr <= '9' ))
		MyAddress.sin_addr.s_addr = inet_addr( nptr );
	else if ((hp = gethostbyname(nptr)) == (struct hostent *) 0)
		return( 1 );
	else	memcpy((BPTR) &MyAddress.sin_addr,(BPTR)hp->h_addr_list[0],hp->h_length);

	if ((sptr = socketname((ADDRPTR) &MyAddress)) != (BPTR) 0) {
		strcpy(PrivateIdentity,sptr);
		PrivateServer = 1;
		}
	return( 0 );
}

/*
 *	--------------------------------------------------------------------
 *	C O M P A R E _ A D D R E S S ( aptr, bptr )
 *	--------------------------------------------------------------------
 *	Compares the two provided address strings and returns 1, OK, if they
 *	match and 0, FAILURE, if they are different.
 *	--------------------------------------------------------------------
 */

INT	compare_address( aptr, bptr )
BPTR  aptr;
BPTR  bptr;
{
	while (( *aptr ) && ( *bptr )) {
		if (( *aptr == ':' ) && ( *bptr == ':' ))
			return(1);
		else if ( *(aptr++) != *(bptr++) )
			return(0);
		}
	if ( *(aptr++) != *(bptr++) )
		return(0);
	else	return(1);
}

/*
 *	--------------------------------------------------------------------
 *	A U T H O R I S E D _ A C C E S S ( cptr )
 *	--------------------------------------------------------------------
 *	Applies privatisation restriction to ensure no messages are received
 *	from other clients than that to which it has been dedicated.
 *	--------------------------------------------------------------------
 */

INT	authorised_access( cptr )
BPTR 	cptr;
{
	if ( verbose )
		printf("%s.verification(%s)",ServerIdentity,cptr);
	if ( compare_address( cptr, PrivateIdentity ) ) {
		if ( verbose )
			printf(" : Accepted\n");
		return( 1 );
		}
	else	{
		if ( verbose )
			printf(" : Rejected\n");
		return( 0 );
		}
}

/*
 *	--------------------------------------------------------------------
 *	L O C A T E _ B Y _ N A M E _ S E R V E R (record,name,type,class)
 *	--------------------------------------------------------------------
 *	This function performs <doain-name> to <ip-address> resolution via 
 *	the local resolver ( ie via a remote <dns-host> ) .
 *	This function is probably redundant due to the elaboration of the
 *	flat state controlled recursive mechanism.
 *	--------------------------------------------------------------------
 *	**RED**		called from "remote_request()"
 *	--------------------------------------------------------------------
 */

DNSMSGPTR	locate_by_name_server( sptr, qname, qtype, qclass )
DNSRRPTR	sptr;
BPTR		qname;
INT		qtype;
INT		qclass;
{
	BPTR		rname=(BPTR) 0;
	DNSMSGPTR	response=(DNSMSGPTR) 0;
	URL		RemoteUrl;
	BYTE		buffer[48];
	BPTR	aptr;
	if (( sptr != (DNSRRPTR) 0 )
	&&  ((aptr = sptr->data) != (BPTR) 0)) {
		sprintf(buffer,"%s//%u.%u.%u.%u/",
			__DNS_PREFIX,
			( *(aptr + 0) & 0x00FF),
			( *(aptr + 1) & 0x00FF),
			( *(aptr + 2) & 0x00FF),
			( *(aptr + 3) & 0x00FF));

		if (( parse_url( buffer, (URLPTR) & RemoteUrl ) == 0 )
		&&  ( RemoteUrl.status & _URL_IS_HOST )
		&&  ((rname = name2string( qname )) != (BPTR) 0)) {
			response = ResolveDns((URLPTR) & RemoteUrl, rname, qtype, qclass );
			rname    = liberate_zone( rname );
			}
		}
	return( response );
}

DNSNODEPTR	locate_record( BPTR, INT );

/*
 *	--------------------------------------------------------------------
 *	D R O P _ H A S H E D _ N O D E ( cache, node, name )
 *	--------------------------------------------------------------------
 *	This function is called to remove an out of date cached record from
 *	the hashed list of cached records.
 *	--------------------------------------------------------------------
 */

DNSNODEPTR	drop_hashed_node( cptr, nptr, qname )
DNSCACHEPTR	cptr;
DNSNODEPTR	nptr;
BPTR		qname;
{
	INT	h=0;

	if ( nptr != (DNSNODEPTR)  0) {

		if ( cptr != (DNSCACHEPTR) 0) {

			if ( qname != (BPTR)       0) {

				while ( *qname )
					h += *(qname++);
				h %= DNS_HASH;

				if ( cptr->Table[h] != (DNSNODEPTR) 0) {
					if ( nptr->prev == (DNSNODEPTR) 0 )
						cptr->Table[h] = nptr->next;
					else 	nptr->prev->next = nptr->next;
					if ( nptr->next != (DNSNODEPTR) 0 )
						nptr->next->prev = nptr->prev;
					}
				if ( cptr->Distribution[h] )
					cptr->Distribution[h] -= 1;
				}
		
			}
		nptr->next = (DNSNODEPTR) 0;
		nptr->prev = (DNSNODEPTR) 0;
		nptr = liberate_for_node( nptr );
		}
	
	return( nptr );

}


/*
 *	--------------------------------------------------------------------
 *	L O C A T E _ H A S H E D _ R E C O R D ( cache, name, class )
 *	--------------------------------------------------------------------
 *	This function is called upon to locate a record matching the provided
 *	<name-class> criteria amongst the provided collection of hashed
 *	records.
 *	If a match is found it is the callers responsibillity to ensure the
 *	validaty of the record by checking the expiry date.
 *	--------------------------------------------------------------------
 */

DNSNODEPTR	locate_hashed_record( cptr, qname, qclass )
DNSCACHEPTR	cptr;
BPTR		qname;
INT		qclass;
{
	DNSNODEPTR	rptr=(DNSNODEPTR) 0;
	BPTR		hptr;
	INT		h=0;
	INT		status=0;
	if (( cptr != (DNSCACHEPTR) 0)
	&&  ((hptr = qname) != (BPTR) 0)) {


		while ( *hptr )
			h += *(hptr++);
		h %= DNS_HASH;

		if ((rptr = cptr->Table[h]) != (DNSNODEPTR) 0) {
			do	{
				if ( compare_tokens( rptr->name, qname ) )
					if ((qclass == __DNS_CLASS_ANY )
					||  (rptr->class == qclass ))
						break;
				}
			while ((rptr = rptr->next) != (DNSNODEPTR) 0);
			}
		}
	return( rptr );
}

/*
 *	--------------------------------------------------------------------
 *	L O C A T E _ A U T H O R I T Y _ R E C O R D ( name, class )
 *	--------------------------------------------------------------------
 *	This function provides for localisation of ressource records from
 *	within the authoratitive data region only. This will be called
 *	by the configuration loading/refresh routines in order to localise
 *	the master record for the addition of data sections or for the
 *	application of consistancy checking.
 *	--------------------------------------------------------------------
 */

DNSNODEPTR	locate_authority_record( qname, qclass )
BPTR		qname;
INT		qclass;
{
	return( locate_hashed_record( DnsManager->Authority, qname, qclass ) );
}

/*
 *	---------------------------------------------------------------------
 *		   L O C A T E _ R E C O R D ( QNAME, QCLASS )
 *	---------------------------------------------------------------------
 *	This function is responsible for the retrieval of Ressource
 *	Records for all subsequent function clients.
 *	The provided <domain-name> QNAME and <domain-class> QCLASS
 *	parameters will be used to localise an exact match, unless of
 *	course the wild class is specified. 
 *	the Cache region will be investigated first, and upon failure
 *	The Authoritive region will be investigated.
 *	In either case if a record is located then it will be subjected
 *	to validity checking, which in the case of authoritive records
 *	will provoke the reloading of master file information upon expiry.
 *	Expired Cache records will be ignored and removed since it is 
 *	reasonable to assume that information available in the cache may
 *	be reconstructed from information in the Authoritive section, and
 *	if this is not the case than the expiration is perfectly valid.
 *	---------------------------------------------------------------------
 */

DNSNODEPTR	locate_record( qname, qclass )
BPTR		qname;
INT		qclass;
{
	DNSNODEPTR	nptr=(DNSNODEPTR) 0;
	LONG		ttl;

	/* ----------------------------------------- */
	/* Ensure valid <domain-name> string pointer */
	/* ----------------------------------------- */
	if ( qname != (BPTR) 0 ) {

		/* Search in Cache */
		/* --------------- */
		if ((nptr = locate_hashed_record( DnsManager->Cache, qname, qclass )) != (DNSNODEPTR) 0) {
			if ( node_still_live( nptr ) )
				return( nptr );
			else 	nptr = drop_hashed_node( DnsManager->Cache, nptr, qname );
			}

		/* Ensure Authoritive Zone still Valid */
		/* ----------------------------------- */
		if (( DnsManager->Authority->Header != (DNSSOAPTR) 0)
		&&  (!( zone_still_live( DnsManager->Authority->Header ) )))
			(void) refresh_configuration();

		/* Search in Authority */
		/* ------------------- */
		if (((nptr = locate_hashed_record( DnsManager->Authority, qname, qclass )) != (DNSNODEPTR) 0)
		&&  ( DnsManager->Authority       != (DNSCACHEPTR) 0)
		&&  ( DnsManager->Authority->Header != (DNSSOAPTR) 0)
		&&  ((ttl = DnsManager->Authority->Header->minimum) > nptr->ttl ))
			nptr->ttl = ttl;

		}

	/* ------------------------------- */
	/* nptr ! NULL ? Success : Failure */
	/* ------------------------------- */
	return( nptr );
	
}

/*
 *	--------------------------------------------------------------------
 *	C O P Y _ R E C O R D ( tptr, sptr )
 *	--------------------------------------------------------------------
 *	This function simply duplicates the source RR fields in the target RR
 *	which must both be valid record pointers.
 *	The source record is consequently liberated since it is no longer
 *	required.
 *	--------------------------------------------------------------------
 */

#include "dnsfile.c"

/*
 *	--------------------------------------------------------------------
 *	S T O R E _ R E C O R D _ D A T A ( nptr, rptr )
 *	--------------------------------------------------------------------
 *	This function is called in order to store the data provided by the
 *	ressource record RR (rptr) as data of the domain node nptr.
 *	This requires the allocation of a new DNSDATA structure into which
 *	the relevant RR fields are copied. The new structure is pushed onto 
 *	the list of existing data records. The source RR is not liberated.
 *	This function will return the standard "Allocation Failure" code 27
 *	if it is unable to allocate for the storage of the data.
 *	--------------------------------------------------------------------
 */

INT		store_record_data( nptr, rptr )
DNSNODEPTR	nptr;
DNSRRPTR	rptr;
{
	DNSDATAPTR	dptr;
	if (( rptr != (DNSRRPTR) 0)
	&&  ( rptr->length     > 0)) {
		if ((dptr = allocate_for_data( rptr->length )) != (DNSDATAPTR) 0) {
			memcpy(dptr->data,rptr->data,(dptr->size = rptr->length));
			if ( rptr->ttl  > nptr->ttl )
				nptr->ttl = rptr->ttl;
			dptr->type = rptr->type;
			dptr->next = nptr->rr;
			nptr->rr   = dptr;
			}
		else	return(27);
		}
	return( 0 );

}


/*
 *	--------------------------------------------------------------------
 *	B U I L D _ H A S H E D _ N O D E ( cache, name, class )
 *	--------------------------------------------------------------------
 *	This function is called in order to add a new domain record to the
 *	indicated hashed collection of records. This requires allocation of
 *	a new domain node DNSNODE which will be returned to the caller for
 *	use upon completion. A NULL node pointer indicates allocation failure.
 *	--------------------------------------------------------------------
 */

DNSNODEPTR	build_hashed_node( cptr, name, class )
DNSCACHEPTR	cptr;
BPTR		name;
INT		class;
{
	DNSNODEPTR	nptr;
	INT		h=0;
	if ((nptr = allocate_for_node()) != (DNSNODEPTR) 0) {
		if ((nptr->name = allocate_for_string( name )) != (BPTR) 0) {
			nptr->class = class;
			while ( *name )
				h += *(name++);
			h %= DNS_HASH;
			if ((nptr->next = cptr->Table[h]) != (DNSNODEPTR) 0)
				nptr->next->prev = nptr;
			cptr->Table[h] = nptr;
			cptr->Distribution[h] += 1;
			}
		else	nptr = liberate_for_node( nptr );
		}
	return( nptr );
}

/*
 *	--------------------------------------------------------------------
 *	C A C H E _ R E C O R D ( cptr )
 *	--------------------------------------------------------------------
 *	This function is called in order to add the information provided by
 *	the source RR (xptr) to the CACHE hashed collection of domain records.
 *	This may involve the allocation of a new domain node and will also
 *	require the allocation of a new domain data container.
 *	This function will return the standard "Allocation Failure" code 27
 *	if it is unable to allocate for the storage of the node or the data.
 *	--------------------------------------------------------------------
 */

INT 		cache_record( xptr )
DNSRRPTR	xptr;
{
	DNSNODEPTR	rptr;

	if (( xptr != (DNSRRPTR) 0 )
	&&  ( xptr->ttl > 0L       )) {

		if ((DnsManager->Cache == (DNSCACHEPTR) 0)
	        &&  ((DnsManager->Cache = allocate_for_cache()) == (DNSCACHEPTR) 0))
			return( 27 );
		/* ---------------------------------- */
		/* Try and locate an identical record */
		/* ---------------------------------- */
		if (((rptr = locate_hashed_record( DnsManager->Cache, xptr->name, xptr->class )) != (DNSNODEPTR) 0)
		||  ((rptr = build_hashed_node( DnsManager->Cache, xptr->name, xptr->class )) != (DNSNODEPTR) 0))
			return( store_record_data( rptr, xptr ) );

		}
	return(0);
}

/*
 *	--------------------------------------------------------------------
 *	C A C H E _ R E C O R D S ( rptr )
 *	--------------------------------------------------------------------
 *	Called in order to perform the integration of a list of RR's into
 *	the CACHE, by routines receiving messages from co-operating dommain
 *	name systems.
 *	This function will return the standard "Allocation Failure" code 27
 *	if allocation failure is encountered during the operation.
 *	--------------------------------------------------------------------
 */

INT		cache_records( rptr )
DNSRRPTR	rptr;
{
	INT	status=0;
	while (rptr != (DNSRRPTR) 0) {
		if ((status = cache_record( rptr )) != 0 )
			break;
		else	rptr = rptr->next;
		}
	return(status);
}
	
/*
 *	--------------------------------------------------------------------
 *	C A C H E _ M E S S A G E ( message )
 *	--------------------------------------------------------------------
 *	This function performs the integration of all RR's of a message to
 *	the local CACHE.
 *	This function will return the standard "Allocation Failure" code 27
 *	if allocation failure is encountered during the operation.
 *	--------------------------------------------------------------------
 */

INT		cache_message( mptr )
DNSMSGPTR	mptr;
{
	INT	status=0;
	if ( mptr != (DNSMSGPTR) 0 )
		if ((status = cache_records( mptr->Answers )) == 0)
			if ((status = cache_records( mptr->Authority )) == 0)
				status = cache_records( mptr->Additional );
	return( status );
}

/*
 *	--------------------------------------------------------------------
 *	V A L I D A T E _ A U T H O R I T Y ()
 *	--------------------------------------------------------------------
 *	Called simply to ensure that the authoritative control structures
 *	have been correctly allocated and are available for use.
 *	This function will return the standard "Allocation Failure" code 27
 *	if allocation failure is encountered during the operation.
 *	--------------------------------------------------------------------
 */

INT	validate_authority()
{
	if ((DnsManager->Authority == (DNSCACHEPTR) 0)
        &&  ((DnsManager->Authority = allocate_for_cache()) == (DNSCACHEPTR) 0))
		return( 27 );
	else	return( 0 );
}

/*
 *	--------------------------------------------------------------------
 *	A U T H O R I T I V E _ R E C O R D ( xptr )
 *	--------------------------------------------------------------------
 *	This function is responsible for the addition of authoritive data
 *	to the authoritive zones.
 *	This function will return the standard "Allocation Failure" code 27
 *	if allocation failure is encountered during the operation.
 *	--------------------------------------------------------------------
 */
INT 		authoritive_record( xptr )
DNSRRPTR	xptr;
{
	DNSNODEPTR	rptr;
	INT		status;

	if (( xptr != (DNSRRPTR) 0 )
	&&  ( xptr->ttl > 0L       )) {

		if ((status = validate_authority()) != 0)
			return( status );

		/* ---------------------------------- */
		/* Try and locate an identical record */
		/* ---------------------------------- */
		if (((rptr = locate_hashed_record( DnsManager->Authority, xptr->name, xptr->class )) != (DNSNODEPTR) 0)
		||  ((rptr = build_hashed_node( DnsManager->Authority, xptr->name, xptr->class )) != (DNSNODEPTR) 0))
			return( store_record_data( rptr, xptr ) );

		}
	return(0);
}

/*
 *	--------------------------------------------------------------------
 *	L O C A T E _ R E C O R D _ D A T A ( dptr, type )
 *	--------------------------------------------------------------------
 *	This function will be called in order to locate specific types of
 *	domain node data amongst the domain node records. The wild type ANY
 *	is honoured and if a match is found then a pointer to the data record
 *	will be returned otherwise a NULL pointer will issue.
 *	--------------------------------------------------------------------
 */

DNSDATAPTR	locate_record_data( dptr, dtype )
DNSDATAPTR	dptr;
INT		dtype;
{
	while ( dptr != (DNSDATAPTR) 0) {
		if (( dtype == __DNS_QTYPE_ANY)
		||  ( dptr->type == dtype ))
			break;
		else	dptr = dptr->next;
		}
	return( dptr );
}
/*
 *	--------------------------------------------------------------------
 *	R E S O L V E _ A L I A S ( response, field, name, class )
 *	--------------------------------------------------------------------
 *	This function will be called during the preparation of a response
 *	and performs the necessary transmission of CNAME records to the 
 *	result fields in order to inform the client of the exact operations
 *	to be performed.
 *	--------------------------------------------------------------------
 */

DNSNODEPTR	resolve_alias( response, rtype, qname, qclass )
DNSMSGPTR	response;
INT		rtype;
BPTR		qname;
INT		qclass;
{
	DNSNODEPTR	nptr;
	DNSDATAPTR	dptr;
	DNSRRPTR	rptr;

	/* ------------------------------------------------------- */
	/* Attempt to locate an RR matching current <domain/class> */
	/* ------------------------------------------------------- */
	while ((nptr = locate_record( qname, qclass )) != (DNSNODEPTR) 0) {

		/* ------------------------------------------------- */
		/* Attempt to locate an ALIAS type entry for this RR */
		/* ------------------------------------------------- */
		if ((dptr = locate_record_data( nptr->rr, __DNS_TYPE_CNAME )) == (DNSDATAPTR) 0)

			/* -------------------------------------- */
			/* Success : this is not an ALIAS type RR */
			/* -------------------------------------- */
			break;

		/* -------------------------------------- */
		/* Use the Alias Information and continue */
		/* -------------------------------------- */
		else	{
			if ((rtype) && (response != (DNSMSGPTR) 0)) {
				if ((rptr = build_record( nptr, dptr )) != (DNSRRPTR) 0) {
					switch ( rtype ) {
						case	1 :
							rptr->next = response->Answers;
							response->Answers = rptr;
							break;
						case	2 :
							rptr->next = response->Additional;
							response->Additional = rptr;
							break;
						}
					}
				}
			qname = dptr->data;
			}
		}

	/* ----------------------------------------- */
	/* Success if nptr ! NULL, otherwise failure */
	/* ----------------------------------------- */
	return( nptr );
}

/*
 *	--------------------------------------------------------------------
 *	R E S O L V E _ S E R V E R( name, class )
 *	--------------------------------------------------------------------
 *	This function is called in order to locate specific NS type records 
 *	for the provided <domain-class> criteria. Aliasing is honoured but
 *	not transmitted since it will not be required by the client.
 *	The function returns a pointer to the domain node which contains
 *	NS type records or a NULL pointer if none exist.
 *	--------------------------------------------------------------------
 */

DNSNODEPTR	resolve_server( qname, qclass )
BPTR		qname;
INT		qclass;
{
	DNSNODEPTR	nptr;
	DNSDATAPTR	dptr;

	/* ------------------------------------------------------- */
	/* Attempt to locate an RR matching current <domain/class> */
	/* ------------------------------------------------------- */
	while ((nptr = locate_record( qname, qclass )) != (DNSNODEPTR) 0) {

		/* ------------------------------------------------- */
		/* Attempt to locate an ALIAS type entry for this RR */
		/* ------------------------------------------------- */
		if ((dptr = locate_record_data( nptr->rr, __DNS_TYPE_CNAME )) != (DNSDATAPTR) 0)

			/* -------------------------------------- */
			/* Use the Alias Information and continue */
			/* -------------------------------------- */
			qname = dptr->data;
		
		else 	{
			if ((dptr = locate_record_data( nptr->rr, __DNS_TYPE_NS)) == (DNSDATAPTR) 0)
				nptr = (DNSNODEPTR) 0;

			/* -----------------------------*/
			/* This is not an ALIAS type RR */
			/* -----------------------------*/
			break;
			}

		}

	/* ----------------------------------------- */
	/* Success if nptr ! NULL, otherwise failure */
	/* ----------------------------------------- */
	return( nptr );
}

/*
 *	--------------------------------------------------------------------
 *	R E S O L V E _ A D D R E S S ( response, field, name, class )
 *	--------------------------------------------------------------------
 *	Whilst resolving and transmitting alias' this function adds address
 *	type RR information during the construction of a response.
 *	--------------------------------------------------------------------
 */

DNSRRPTR	resolve_address( response, rtype, qname, qclass )
DNSMSGPTR	response;
INT		rtype;
BPTR		qname;
INT		qclass;
{
	DNSNODEPTR	nptr;
	DNSDATAPTR	dptr;
	DNSRRPTR	rptr=(DNSRRPTR) 0;
	DNSRRPTR	xptr=(DNSRRPTR) 0;

	if (((nptr = resolve_alias( response, rtype, qname, qclass )) != (DNSNODEPTR) 0)
	&&  ((dptr = locate_record_data( nptr->rr, __DNS_TYPE_A )) != (DNSDATAPTR) 0)) {
		do	{
			if ((xptr = build_record( nptr, dptr )) != (DNSRRPTR) 0) {
				xptr->next = rptr;
				rptr = xptr;
				}
			}
		while ((dptr = locate_record_data( dptr->next, __DNS_TYPE_A )) != (DNSDATAPTR) 0);
		}
	return( rptr );

}

/*
 *	-----------------------------------------------------------
 *	R E S O L V E _ C A N O N I C A L _ N A M E ( name, class )
 *	-----------------------------------------------------------
 *	As itds name implies this function returns the resolved 
 *	canonical name of the provided <domain-class>
 *	Failure may be signaled by a NULL string pointer which will be
 *	due to either circular or incomplete information.
 *	-----------------------------------------------------------
 */

PRIVATE	BPTR	resolve_canonical_name( qname, qclass )
	BPTR	qname;
	INT	qclass;
{
	DNSNODEPTR	nptr;
	DNSDATAPTR	dptr;

	while (((nptr  = locate_record( qname, qclass )) != (DNSNODEPTR) 0)
	&&     ((dptr  = locate_record_data( nptr->rr, __DNS_TYPE_CNAME )) != (DNSDATAPTR) 0)
	&&     ((qname = dptr->data) != (BPTR) 0));

	return( qname );

}

/*
 *	--------------------------------------------------------------------
 *	L O C A T E _ H O S T S ( qname, qclass )
 *	--------------------------------------------------------------------
 *	This function builds a list of host control records to be used by
 *	the recursive referal mechanism during the forwarding of messages
 *	to DNS co-server hosts.
 *	--------------------------------------------------------------------
 */

PRIVATE	DNSHOSTPTR	locate_hosts( qname, qclass )
	BPTR		qname;
	BPTR		qclass;
{
	DNSHOSTPTR	hosts=(DNSHOSTPTR) 0;
	INT		l=0;
	DNSNODEPTR	nptr=(DNSNODEPTR) 0;
	DNSDATAPTR	dptr=(DNSDATAPTR) 0;
	DNSHOSTPTR	hptr=(DNSHOSTPTR) 0;
	DNSRRPTR	aptr=(DNSRRPTR) 0;
	DNSRRPTR	xptr=(DNSRRPTR) 0;
	ADDRESS		TempAddress;
	BPTR		dname;

	/* ---------------------------------------- */
	/* Resolve Canonical Name for this <DOMAIN> */
	/* ---------------------------------------- */
	if ((dname = resolve_canonical_name( qname, qclass )) != (BPTR) 0)

	   while ( hosts == (DNSHOSTPTR) 0 ) {

		/* -------------------------------------------------- */
		/* Attempt to locate an HOST record for <domain.name> */
		/* -------------------------------------------------- */
		if (((nptr = locate_record( qname, qclass )) != (DNSNODEPTR) 0)
		&&  ((dptr = locate_record_data( nptr->rr, __DNS_TYPE_NS)) != (DNSDATAPTR) 0)) {

			/* ---------------------------------------- */
			/* Collect all Name servers for this Record */
			/* ---------------------------------------- */
			do	{
				/* ------------------------------------------------------- */
				/* We must now attempt to resolve the address of this host */
				/* ------------------------------------------------------- */
				if ((aptr = resolve_address( (DNSMSGPTR) 0, 0, dptr->data, nptr->class )) != (DNSRRPTR) 0) {
	
					while ((xptr = aptr) != (DNSRRPTR) 0) {
						aptr = aptr->next;
						if (( xptr->data != (BPTR) 0)
						&&  (xptr->length >= 4 )) {
							memcpy((BPTR) &TempAddress.sin_addr,xptr->data,4);
							if ((hptr = build_host((BPTR) 0,(ADDRPTR) &TempAddress, dname )) != (DNSHOSTPTR) 0) {
								if ( verbose )
									show_host( hptr );
								hptr->next = hosts;
								hosts      = hptr;
								}
							}
						xptr = liberate_for_record( xptr );
						}
					}
				}
			while ((dptr = locate_record_data( dptr->next, __DNS_TYPE_NS )) != (DNSDATAPTR) 0);
			}
		else	{
			/* Step up to next DOMAIN level */
			/* ---------------------------- */
			if ((l = *(qname++)) != 0)
			 	qname += l;

			else 	/* Domain Name Root Finished so Nothing */
				/* ------------------------------------ */
				break;
			}
		}

	/* Return List (may be empty) */
	/* -------------------------- */
	return( hosts );
}



/*
 *	--------------------------------------------------------------------
 *	R E M O T E _ R E Q U E S T ( hosts, domain, class, type )
 *	--------------------------------------------------------------------
 *	Performs iterative referal to the list of hosts provided requesting
 *	response to the question comprising the name, class and type.
 *	**RED**	This is now redundant since the new recursive management
 *	system no performs parrallel request/response operation rather than
 *	the top-down sequential method provided here.
 *	--------------------------------------------------------------------
 */

DNSMSGPTR	remote_request( aptr, qname, qclass, qtype )
DNSRRPTR	aptr;		/* The list of Server Address' to try 	*/
BPTR		qname;		/* The <domain-name> to be resolved	*/
INT		qclass;		/* The <domain-class> of the question	*/
INT		qtype;		/* the <domain-data-type> required	*/
{
	DNSRRPTR	rptr=(DNSRRPTR) 0;
	DNSMSGPTR	response=(DNSMSGPTR) 0;

	/* Try all address' in the list */
	/* ---------------------------- */
	while ( aptr != (DNSRRPTR) 0 ) {

		if ((response = locate_by_name_server( aptr, qname, qclass, qtype )) != (DNSRRPTR) 0)
			break;
		else	aptr = aptr->next;

		}
	return( response );

}




/*
 *	--------------------------------------------------------------------
 *	R E S O L V E _ B Y _ S E R V E R ( response, name, type, class 
 *					    <domain-node>, <ns-rr> )
 *	--------------------------------------------------------------------
 *	This function will be called in order to establish the list of
 *	host DNS servers which could be useful to the client for the
 *	elaboration of the answer to their problem.
 *	--------------------------------------------------------------------
 */

INT		resolve_by_server( response, qname, qtype, qclass, nptr, dptr )
DNSMSGPTR	response;
BPTR		qname;
INT		qtype;
INT		qclass;
DNSNODEPTR	nptr;
DNSDATAPTR	dptr;
{
	DNSMSGPTR	resultmsg=(DNSMSGPTR) 0;
	DNSRRPTR	rptr=(DNSRRPTR) 0;
	DNSRRPTR	aptr=(DNSRRPTR) 0;
	DNSRRPTR	xptr=(DNSRRPTR) 0;
	DNSRRPTR	rrptr=(DNSRRPTR) 0;

	/* ------------------------------------------------------ */
	/* Arrival here : we have located the address of at least */
	/* one authoritive name server for the current partial    */
	/* domain name name. 					  */
	/* We must construct a list !!				  */
	/* ------------------------------------------------------ */
	do	{
		if ((xptr = build_record( nptr, dptr)) != (DNSRRPTR) 0) {
			xptr->next = rptr;
			rptr = xptr;
			}
		}
	while ((dptr = locate_record_data( dptr->next, __DNS_TYPE_NS )) != (DNSDATAPTR) 0);

	/* ---------------------------------------------------- */
	/* Test for Iterative Recursion to be performed now ! 	*/
	/* **RED** This code is now redundant since the new   	*/
	/* Recursivity mechanism provides for parrallel	      	*/
	/* transmission and reception in order to cater for   	*/
	/* requests received correlating to the referal 	*/
	/* ---------------------------------------------------- */
	if (( response->Header.Flags & (__DNS_RA | __DNS_RD))
	==  ( __DNS_RA | __DNS_RD))  {

		/* ------------------------------------------------------ */
		/* The original message has REQUESTED recursive activity  */
		/* and has also been ACCEPTED by the SERVER !!!!!!!!!!!!  */
		/* so the list of name servers may now be interrogated    */
		/* with respect to the original/aliased <domain-name> for */
		/* which we have no authoritive record.     		  */
		/* ------------------------------------------------------ */
		rrptr = rptr;

		do	{

			/* ---------------------------------------------- */
			/* We must first locate the address of the Server */
			/* ---------------------------------------------- */
			if ((aptr = resolve_address(response, 0, rptr->data, rptr->class )) != (DNSRRPTR) 0) {

				/* ----------------------------- */
				/* And then forward the question */
				/* ----------------------------- */
				resultmsg = remote_request( aptr, qname, qclass, qtype );

				/* ------------------------------ */
				/* Release Address of Name Server */
				/* ------------------------------ */
				aptr = liberate_records( aptr );

				if ( resultmsg != (DNSMSGPTR) 0 ) {

					/* --------------------------------------------------- */
					/* We must now cache eventual response from the server */
					/* --------------------------------------------------- */
					(VOID) cache_message( resultmsg );

					/* Release Answers */
					/* --------------- */
					resultmsg = liberate_for_message( resultmsg );

					/* Release Name Server List */
					/* ------------------------ */
					rrptr = liberate_records( rrptr );

					/* -------------------------- */
					/* Indicate Recursive : RETRY */
					/* -------------------------- */
					return( 2 );

					}
				}

			}
		while ((rptr = rptr->next) != (DNSRRPTR) 0);

		/* ----------------------- */
		/* Release list of servers */
		/* ----------------------- */
		rrptr = liberate_records( rrptr );

		/* Indicate FAILURE */
		/* ---------------- */
		return( 0 );

		}
	else	{
		/* ------------------------------------------------------- */
		/* The original message did not request recursive activity */
		/* so we must inform the client of the name servers which  */
		/* should be of assistance for the resolution of the name  */
		/* in the AUTHORITY section of the response.		   */
		/* ------------------------------------------------------- */
		xptr = rptr;
		do	{

			/* ------------------------------------------------------- */
			/* NB we must also provide the appropriate address info in */
			/* the ADDITIONAL section of the response.		   */
			/* ------------------------------------------------------- */
			if ((aptr = resolve_address(response, 2, xptr->data, xptr->class )) != (DNSRRPTR) 0) {
				aptr->next = response->Additional;
				response->Additional = aptr;
				}

			}
		while ((xptr = xptr->next) != (DNSRRPTR) 0);

		/* ------------------------------------------------- */
		/* Add list of Name servers to the AUTHORITY section */
		/* ------------------------------------------------- */
		xptr = rptr;

		while ( xptr->next != (DNSRRPTR) 0 )
			xptr = xptr->next;

		xptr->next = response->Authority;
		response->Authority = rptr;

		/* -------------------------------------------- */
		/* Indicate a kind of Success for this question */
		/* -------------------------------------------- */
		return( 1 ); 

		}
}

/*
 *	--------------------------------------------------------------------
 *	R E S O L V E _ P A R T I A L ( response, name, type, class )
 *	--------------------------------------------------------------------
 *	No exact <domain-class> has been found or the type required is
 *	unknown so the <domain-name> must be scanned towards the root in
 *	order to localise a 'higher domain' authority to be consulted for
 *	the elaboration of an exact response.
 *	--------------------------------------------------------------------
 */

INT		resolve_partial( response, qname, qtype, qclass )
DNSMSGPTR	response;
BPTR		qname;
INT		qtype;
INT		qclass;
{
	INT		n=0;
	BPTR		name=(BPTR) 0;
	DNSNODEPTR	nptr=(DNSNODEPTR) 0;
	DNSDATAPTR	dptr=(DNSDATAPTR) 0;

	/* ------------------------------------------------- */
	/* No RR for this <domain/class> so ... we must step */
	/* up the <domain-name> trying to find a name server */
	/* record which is authoritive for the higher level  */
	/* domain in order to resolve the question           */
	/* ------------------------------------------------- */
	name = qname;

	while (1) {

		if ((n = *name) == 0 )

			/* ------------------------------ */
			/* We cannot locate a name server */
			/* for this <domain-name> FAILURE */
			/* ------------------------------ */
			return( 0 );

		else 	{
			/* Step to next sub-domain */
			/* ----------------------- */
			name += (n + 1);

			/* Try to locate a NAME Server Type Record */
			/* --------------------------------------- */
			if (((nptr = resolve_server( name, qclass )) != (DNSNODEPTR) 0)
			&&  ((dptr = locate_record_data( nptr->rr, __DNS_TYPE_NS )) != (DNSDATAPTR) 0))
				break;
			}
		}


	return( resolve_by_server( response, qname, qclass, qtype, nptr, dptr ) );

}

/*
 *	--------------------------------------------------------------------
 * 	R E S O L V E _ R E S P O N S E ( response, name, type, class )
 *	--------------------------------------------------------------------
 *	This function is called by the question analysis routines in order to
 *	try an elaborate either an exact response, information which may be
 *	helpful in the elaboration of a response, or a definite name error
 *	condition.
 *	--------------------------------------------------------------------
 */

INT 		resolve_response( response, qname, qtype, qclass )
DNSMSGPTR	response;
BPTR		qname;
INT		qtype;
INT		qclass;
{

	DNSNODEPTR	nptr=(DNSNODEPTR) 0;
	DNSDATAPTR	dptr=(DNSDATAPTR) 0;
	DNSRRPTR	aptr=(DNSRRPTR) 0;
	DNSRRPTR	rptr=(DNSRRPTR) 0;
	DNSRRPTR	rrptr=(DNSRRPTR) 0;
	DNSRRPTR	xptr=(DNSRRPTR) 0;


/* ------------------------------------------------------------------------- */
/* This is an iterative algorithm which will continue for one of two reasons */
/* 	1 ) A CNAME has been resolved to provide an alternative QNAME	     */
/*	2 ) A remote request to a name server has furnished new information  */
/* ------------------------------------------------------------------------- */

 while ( 1 ) {

	rptr = (DNSRRPTR) 0;	/* Must be reset in case of iteration */

	/* ------------------------------------------------------------ */
	/* Attempt to locate a Ressource Record for This <domain/class> */
	/* ------------------------------------------------------------ */
	if ((nptr = locate_record( qname, qclass )) == (DNSNODEPTR) 0) {

		/* Attempt to locate via a partial Domain Name */
		/* ------------------------------------------- */
		switch ( resolve_partial( response, qname, qclass, qtype ) ) {

			case	0 :	
				/* No Partial Response : Absolute Failure */
				/* -------------------------------------- */
				return( 0 );

			case	1 :
				/* Name Server Success : ! Recursive : Return */
				/* ------------------------------------------ */
				return( 1 );
			}
		}

	else	{

		/* ------------------------------------------------------- */
		/* Arrival here : We have located a Ressource Record which */
		/* matches for <domain/class> and must now handle the type */
		/* required by the question, and available in  the record  */
		/* ------------------------------------------------------- */

		if ( qtype == __DNS_QTYPE_ANY ) {
	
			/* --------------------------------------------- */
			/* The question requires any/all types of record */
			/* so a list of all types available must be sent */
			/* back in the response to this question.	 */
			/* --------------------------------------------- */
			if ((dptr = nptr->rr) != (DNSDATAPTR) 0) {

				do	{
					if ((rptr = build_record( nptr, dptr )) != (DNSRRPTR) 0) {
						rptr->next = response->Answers;
						response->Answers = rptr;
						}
					}
				while ((dptr = dptr->next) != (DNSDATAPTR) 0);
				}

			/* And Indicate a Potential kind of Success */
			/* ---------------------------------------- */
			return( ( rptr != (DNSRRPTR) 0 ? 1 : 0 ) );

			}
		else	{
			/* ----------------------------------------------- */
			/* The question requires a specific type of record */
			/* which must be saught amongst those available.   */
			/* ----------------------------------------------- */
			if ((dptr = locate_record_data( nptr->rr, qtype )) != (DNSDATAPTR) 0) {

				/* ------------------------------------------ */
				/* This algorithm allows multiple occurances  */
				/* ------------------------------------------ */
				do	{
					if ((rptr = build_record( nptr, dptr )) != (DNSRRPTR) 0) {
						rptr->next = response->Answers;
						response->Answers = rptr;
						}
					}
				while ((dptr = locate_record_data( dptr->next, qtype )) != (DNSDATAPTR) 0);

				/* Return SUCCESS */
				/* -------------- */
				return( ( rptr != (DNSRRPTR) 0 ? 1 : 0 ) );

				}
						
			else if ((dptr = locate_record_data( nptr->rr, __DNS_TYPE_CNAME)) != (DNSDATAPTR) 0) {

				/* ----------------------------------------------- */
				/* The CNAME type record may be used and resolved  */
				/* in order to find the correct type of response   */
				/* required by the original question.		   */
				/* ----------------------------------------------- */
				if ((rptr = build_record( nptr, dptr )) != (DNSRRPTR) 0) {
					rptr->next = response->Answers;
					response->Answers = rptr;
					}
				qname = dptr->data;
				}

			else if ((dptr = locate_record_data( nptr->rr, __DNS_TYPE_NS )) == (DNSDATAPTR) 0) {

				/* -------------------------------------------- */
				/* Failure no NAME server is available in order */
				/* to forward the request since we do not have  */
				/* the type of data required by the request     */
				/* -------------------------------------------- */
				/* Attempt to locate via a partial Domain Name */
				/* ------------------------------------------- */
				switch ( resolve_partial( response, qname, qclass, qtype ) ) {

					case	0 :	
						/* No Partial Response : Absolute Failure */
						/* -------------------------------------- */
						return( 0 );

					case	1 :
						/* Name Server Success : ! Recursive : Return */
						/* ------------------------------------------ */
						return( 1 );
					}
				}
			else	{
				switch ( resolve_by_server( response, qname, qclass, qtype, nptr, dptr ) ) {

					case	0 :	
						/* No Partial Response : Absolute Failure */
						/* -------------------------------------- */
						return( 0 );

					case	1 :
						/* Name Server Success : ! Recursive : Return */
						/* ------------------------------------------ */
						return( 1 );
					}
				}
			}
		}
	}


}

/*
 *	--------------------------------------------------------------------
 *	R E S O L V E _ Q U E S T I O N ( qptr, response )
 *	--------------------------------------------------------------------
 *	This function is called in order to elaborate a response to a
 *	question received in a query message.
 *	--------------------------------------------------------------------
 */

INT		resolve_question( qptr, response )
DNSQUESTPTR	qptr;
DNSMSGPTR	response;
{
	DNSRRPTR	rptr;
	INT		status=__DNS_SERVER_ERROR;
	struct  hostent *hp=(struct hostent *) 0;
	BPTR	nptr=(BPTR) 0;

	if ( resolve_response(response, qptr->name, qptr->type, qptr->class ) != 0) {
		DnsManager->CacheHits++;
		status = __DNS_NO_ERROR;
		}
	else	{
		DnsManager->CacheMiss++;
		if ((nptr = name2string( qptr->name )) == (BPTR) 0)
			status = __DNS_SERVER_ERROR;
	     	else if ((hp = gethostbyname(nptr)) == (struct hostent *) 0)
			status = __DNS_NAME_ERROR;
		else if ((rptr = allocate_for_record()) != (DNSRRPTR) 0) {
			rptr->next = response->Answers;
			response->Answers = rptr;
			if ((rptr->name = allocate_for_string( qptr->name )) != (BPTR) 0) {
				rptr->type   = qptr->type;
				rptr->class  = qptr->class;
				rptr->ttl    = 0L;
				if ((rptr->data = (BPTR) allocate_zone( 4 )) != (BPTR) 0) {
					rptr->length = 4;
					memcpy((BPTR) rptr->data, (BPTR) hp->h_addr_list[0],4);
					status = __DNS_NO_ERROR;
					}
				}
			}
		if ( nptr != (BPTR) 0 )
			nptr = liberate_zone( nptr );

		}
	return( status );
}

/*
 *	--------------------------------------------------------------------
 *	D N S _ O P E R A T I O N ( query, response )
 *	--------------------------------------------------------------------
 *	This function submits the various questions present in a query
 *	message for elaboration of response information.
 *	--------------------------------------------------------------------
 */

PRIVATE	DNSMSGPTR	dns_operation( query, response )
	DNSMSGPTR	query;
	DNSMSGPTR	response;
{
	DNSQUESTPTR	qptr;
	INT		status = (__DNS_AA | __DNS_NO_ERROR );
	response->Header.identity = query->Header.identity;
	response->Header.Flags = query->Header.Flags;
	if ( recursive & __DNS_RA )
		response->Header.Flags |= __DNS_RA;
	response->Questions = query->Questions;
	query->Questions = (DNSQUESTPTR) 0;
	if ((qptr = response->Questions) != (DNSQUESTPTR) 0)
		while (( qptr != (DNSQUESTPTR) 0)
		&&     ((status = resolve_question( qptr, response )) == __DNS_NO_ERROR))
			qptr = qptr->next;

	return( response );
}

/*
 *	--------------------------------------------------------------------
 *	R E M O V E _ P E N D I N G ( request )
 *	--------------------------------------------------------------------
 *	This function will be called in order to remove the provided
 *	message(pending reception of referal reply) from the list of
 *	message pending reply.
 *	--------------------------------------------------------------------
 */

PRIVATE	VOID		remove_pending( request )
	DNSFWDPTR	request;
{
	if ( request->previous != (DNSFWDPTR) 0 )
		request->previous->next = request->next;
	else	PendingRequests = request->next;
	if ( request->next != (DNSFWDPTR) 0)
		request->next->previous = request->previous;
	return;
}

/*
 *	--------------------------------------------------------------------
 *	E X T R A C T _ R E S P O N S E ( rcvptr )
 *	--------------------------------------------------------------------
 *	This function is called in order to extract a response to a query
 *	from the data base. It will be called when recursive operation has
 *	not been requested, or has been ihibited by the configuration of the
 *	DNS server, or when a response is known to exist upon reception of
 *	replies to forwarded referals in recursive flat-state mode.
 *	--------------------------------------------------------------------
 */

DNSRCVPTR	extract_response( rcvptr )
DNSRCVPTR	rcvptr;
{
	DNSMSGPTR	response; /* Output or Sent    Response Message */
	DNSMSGPTR	query;    /* Output or Sent    Response Message */
	CONNECTIONPTR	connection;

	/* -------------------------------------------- */
	/* Collect and Validate Received Message Fields */
	/* -------------------------------------------- */
	if ((rcvptr == (DNSRCVPTR) 0)
	||  (rcvptr->status)
	||  ((query = rcvptr->message) == (DNSMSGPTR) 0)
	||  ((connection = rcvptr->connection) == (CONNECTIONPTR) 0))
		return( rcvptr );
	else	rcvptr->status = 1;

	/* ----------------------------------- */
	/* Handle Request Received From Client */
	/* ----------------------------------- */
	if ((response = allocate_for_message()) != (DNSMSGPTR) 0) {

		/* ------------------------------------- */
		/* Prepare Non Recursive Response Header */
		/* ------------------------------------- */
		response->Header.identity = query->Header.identity;
		response->Header.Flags    = query->Header.Flags;
		if ( recursive & __DNS_RA )
			response->Header.Flags   |= __DNS_RA;
		response->Questions       = query->Questions;

		/* --------------------- */
		/* Analyse all questions */
		/* --------------------- */
		while ( query->Questions != (DNSQUESTPTR) 0) {
			(void) resolve_question( query->Questions, response );
			query->Questions = query->Questions->next;
			}	
	
		/* --------------------------- */
		/* Transmit Response to Client */
		/* --------------------------- */
		dns_put_message( connection, response, __DNS_QR );

		response = liberate_for_message( response );

		}
	else	dns_put_message( connection, query, (__DNS_QR | __DNS_AA | __DNS_SERVER_ERROR ));

	/* Liberate Received Request and Return */
	/* ------------------------------------ */
	return((rcvptr = liberate_for_reception( rcvptr )));

}


/*
 *	--------------------------------------------------------------------
 *	L O C A T E _ R E S P O N S E ( name, class, type )
 *	--------------------------------------------------------------------
 *	This function is called in order to detect the presence of an exact
 *	response in the domain name data base. The function will return a
 *	logical value of 1 to indicate an exact response is possible.
 *	--------------------------------------------------------------------
 */

INT		locate_response( qname, qclass, qtype )
BPTR		qname;
INT		qclass;
INT		qtype;
{
	DNSNODEPTR	nptr;
	DNSDATAPTR	dptr;

	while ( (nptr = locate_record( qname, qclass )) != (DNSNODEPTR) 0) {
		if ( qtype == __DNS_QTYPE_ANY )
			return(1);
		else if ((dptr = locate_record_data( nptr->rr, qtype )) != (DNSDATAPTR) 0)
			return(1);
		else if ((dptr = locate_record_data( nptr->rr, __DNS_TYPE_CNAME )) == (DNSDATAPTR) 0)
			break;
		else	qname = dptr->data;
		}
	return(0);
}

/*
 *	------------------------------------------------------------------
 *		D E T E C T _ N A M E _ E R R O R ( response )
 *	------------------------------------------------------------------
 *	This function scans the list of messages pending reception of a
 *	reply from othe DNS hosts. If this message is the last then the
 *	original client/co-server must be informed of the name-error
 *	condition. The received message state is checked prior to the
 *	list scan since this function may have been called by the garbage
 *	collector which eliminates expired pending messages.
 *	------------------------------------------------------------------
 */

PRIVATE	VOID		detect_name_error( response )
	DNSRCVPTR	response;
{
	DNSFWDPTR	request;

	/* ----------------------------------------------- */
	/* Ensure valid REASON that has not been fulfilled */
	/* ----------------------------------------------- */
	if (( response == (DNSRCVPTR) 0 )
	||  ( response->status          ))
		return;

	/* ------------------------------------------------ */
	/* Scan List of Messages Pending Reception of Reply */
	/* ------------------------------------------------ */
	else if ((request = PendingRequests) != (DNSFWDPTR) 0) {
		do	{
			/* ---------------------------------- */
			/* Test for Identical Message Numbers */
			/* ---------------------------------- */
			if ( request->identity == response->identity )
				break;
			}
		while ((request = request->next) != (DNSFWDPTR) 0);
		}	

	/* ------------------------------------- */
	/* if no other messages pending for this */
	/* ------------------------------------- */
	if ( request == (DNSFWDPTR) 0 ) {

		/* -------------------------------------------- */
		/* Send NAME ERROR back to the CLIENT/CO-SERVER */
		/* -------------------------------------------- */
		response->status++;
		dns_put_message( response->connection, response->message, (__DNS_QR | __DNS_AA | __DNS_NAME_ERROR ));
		}
	return;
}

/*
 *	--------------------------------------------------------------------
 *		R E S O L V E _ R E Q U E S T ( request )
 *	--------------------------------------------------------------------
 *	This function is called upon reception of an identified reply to a
 *	referal for assistance message in order to attempt to resolve the
 *	original client question(reason) for the referal.
 *	If this is the final reply of a referal group then a NAME ERROR
 *	condition will be called upon to be detected and expediated.
 *	--------------------------------------------------------------------
 */

PRIVATE	DNSFWDPTR	resolve_request( request )
	DNSFWDPTR	request;
{
	DNSRCVPTR	reason;
	DNSMSGPTR	query;
	DNSQUESTPTR	qptr;

	if ( request != (DNSFWDPTR) 0 ) {
		
		/* ---------------------------------- */
		/* Remove This Item from Pending List */
		/* ---------------------------------- */
		remove_pending( request );

		/* ----------------------------------------- */ 
		/* Ensure valid,unanswered REASON (QUESTION) */
		/* ----------------------------------------- */ 
		if (((reason = request->reason) != (DNSRCVPTR) 0)
		&&  (!(reason->status))
		&&  ((query    = reason->message) != (DNSMSGPTR) 0)
		&&  ((qptr     = query->Questions) != (DNSQUESTPTR) 0)) {

			/* ---------------------------------------------- */
			/* Attempt to Resolve Answer from new information */
			/* ---------------------------------------------- */
			if ( locate_response( qptr->name, qptr->class, qptr->type ) != 0)
				request->reason = extract_response( reason );
			else	detect_name_error( reason );
			}

		/* ------------------------- */
		/* Release this Pending Item */
		/* ------------------------- */
		request = liberate_for_forward( request );	
		}

	return( request );
}

/*
 *	--------------------------------------------------------------------
 *		I N T E G R A T E _ R E S P O N S E ( rcvptr )
 *	--------------------------------------------------------------------
 *	The message received by the DNS is a REPLY to a message that had been
 *	forwarded to another DNS Host. The information supplied must be  used
 *	to update the local cache (under expiration control) and the message
 *	must be matched with a message pending reception of a reply. In the
 *	case that the message received provides an answer then an new attempt
 *	may be made to resolve the initial reason(question) for this forward
 *	referal event in order to be able to communicate a result to the
 *	original client/co-server system.
 *	--------------------------------------------------------------------
 */

DNSRCVPTR	integrate_response( rcvptr )
DNSRCVPTR	rcvptr;
{
	DNSMSGPTR	response;
	CONNECTIONPTR	connection;
	CONNECTIONPTR	cptr;
	DNSFWDPTR	request=(DNSFWDPTR) 0;

	/* -------------------------------------------- */
	/* Collect and Validate Received Message Fields */
	/* -------------------------------------------- */
	if ((rcvptr == (DNSRCVPTR) 0)
	||  ((connection = rcvptr->connection) == (CONNECTIONPTR) 0)
	||  ((response = rcvptr->message) == (DNSMSGPTR) 0))
		return( rcvptr );

	
	/* -------------------------------------------------------------- */
	/* Scan the list of forwarded messages pending reception of Reply */
	/* -------------------------------------------------------------- */
	if ((request = PendingRequests) != (DNSFWDPTR) 0) {
		do	{
			/* ---------------------------------- */
			/* Test for Identical Message Numbers */
			/* ---------------------------------- */
			if (( request->message != (DNSMSGPTR) 0 )
			&&  ( request->message->Header.identity == response->Header.identity ))
				break;
			}
		while ((request = request->next) != (DNSFWDPTR) 0);
		}	


	/* ----------------------------------------- */
	/* Add all received information to the Cache */
	/* ----------------------------------------- */
	if ( cache_message( response ) == 0 ) {

		if ( verbose )
			show_cache( DnsManager->Cache, "Cache" );

		/* ---------------------------------------- */
		/* Attempt to Resolve the Original Question */
		/* ---------------------------------------- */
		request = resolve_request( request );

		}

	else	report_allocation_failure();


	/* ----------------------------- */
	/* Release This received Message */
	/* ----------------------------- */
	return((rcvptr = liberate_for_reception( rcvptr )));

}

/*
 *	---------------------------------------------------------------------
 *			F L U S H _ F O R W A R D ()
 *	---------------------------------------------------------------------
 *	This function performs 'time to live' verification for messages
 *	which have been forwarded to other DNS hosts for assistance for
 *	recursive operation. Forwarded Messages are time stamped with
 *	their date(time) of birth and will be allowed to live (waiting for
 *	an answer from the host) until their 'time to live' value has expired.
 *	At this point the host is considered to be 'down' since no message
 *	has been returned. A retry mechanism will need to be implemented to
 *	retry the host in case the message has been simply lost.
 *	---------------------------------------------------------------------
 */	

PRIVATE	VOID		flush_forward()
{
	DNSFWDPTR	fptr;
	DNSFWDPTR	ffptr;

	/* ------------------------------------- */
	/* While more forwarded messages pending */
	/* ------------------------------------- */
	if ((fptr = PendingRequests) != (DNSFWDPTR) 0) {
		if ( verbose )
			printf("DNS REFERALS \n");
		do	{

			/* ------------------------------------------------- */
			/* Position next message pointer in case the current */
			/* is out of date !!!				     */
			/* ------------------------------------------------- */
			ffptr = fptr->next;

			if ( verbose )
				show_forward( fptr );

			/* --------------------------- */
			/* Test if message has expired */
			/* --------------------------- */
			if (!( forward_still_live( fptr ) )) {

				/* -------------------------- */
				/* First remove from the list */
				/* -------------------------- */
				remove_pending( fptr );

				/* ---------------------------------------- */
				/* If this is the last message for a reason */
				/* then the client must be informed of the  */
				/* subsequent error condition 		    */
				/* ---------------------------------------- */
				detect_name_error( fptr->reason );

				/* ---------------------------------- */
				/* Then liberate this pending message */
				/* ---------------------------------- */
				fptr = liberate_for_forward( fptr );
				}
			}
		while (( fptr = ffptr) != (DNSFWDPTR) 0 );
		}
	return;	
}

/*
 *	---------------------------------------------------------------------
 *	    F O R W A R D _ M E S S A G E ( received, message, host )
 *	---------------------------------------------------------------------
 *	This function expedits a message to be forwarded to another DNS
 *	host for assistance. A Forward Control Event is created, time stamped
 *	and placed on the list of Events pending message reception.
 *	---------------------------------------------------------------------
 */

PRIVATE	VOID		forward_message( rcvptr, message, host )
	DNSRCVPTR	rcvptr;
	DNSMSGPTR	message;
	DNSHOSTPTR	host;
{
	DNSFWDPTR	fptr=(DNSFWDPTR) 0;

	/* --------------------------------------------------- */
	/* Allocate a Forward Control Structure (time stamped) */
	/* --------------------------------------------------- */
	if ((fptr = allocate_for_forward()) != (DNSFWDPTR) 0) {

		/* ----------------------------------- */
		/* Store Message, and allocate for URL */
		/* ----------------------------------- */
		fptr->message = message;
		if ((fptr->url = allocate_for_url( host->address,0L )) == (URLPTR) 0)
			fptr = liberate_for_forward( fptr );

		/* ------------------------------------------------------- */
		/* Attmpt to Establish connection with the host (DG or VC) */
		/* ------------------------------------------------------- */
		else if ((fptr->connection = establish_connection( rcvptr->connection, fptr->url )) == (CONNECTIONPTR) 0) 
			fptr = liberate_for_forward( fptr );

		else	{
			/* --------------------------------------------- */
			/* Ensure that the 'reason' usage count has been */
			/* increased in order to avoid destruction       */
			/* --------------------------------------------- */
			if ((fptr->reason  = rcvptr) != (DNSRCVPTR) 0) {
				rcvptr->usage++;
				fptr->identity = rcvptr->identity;
				}

				
			/* -------------------------------- */
			/* Send out the Message to the Host */
			/* -------------------------------- */
			dns_put_message( fptr->connection, fptr->message, 0 );
			host->status++;
			if ( verbose ) 	show_host( host );

			/* ----------------------------------------------- */
			/* Add Forwarded Message to Pending Reception List */
			/* ----------------------------------------------- */
			if ((fptr->next = PendingRequests) != (DNSFWDPTR) 0)
				PendingRequests->previous = fptr;
			PendingRequests = fptr;
			}
		}
	return;
}


/*
 *	------------------------------------------------------------
 *	F O R W A R D _ R E Q U E S T ( reason, hosts, class, type )
 *	------------------------------------------------------------
 *	This function will be called during recursive operation and
 *	will perform request referal ( forwarding ) to each of the
 *	members of the host list.
 *	------------------------------------------------------------
 */

PRIVATE	VOID		forward_request( reason, hosts, qclass, qtype )
	DNSRCVPTR	reason;
	DNSHOSTPTR	hosts;
	INT		qclass;
	INT		qtype;
{
	DNSHOSTPTR	hptr=(DNSHOSTPTR) 0;
	DNSMSGPTR	message=(DNSMSGPTR) 0;

	/* ------------------------------------------------- */
	/* Stamp this Reason Message with a unique ID Number */
	/* ------------------------------------------------- */
	reason->identity = NewMessageIdentity();

	/* --------------------------- */
	/* Perform Until no more Hosts */
	/* --------------------------- */
	while (( hptr = hosts) != (DNSHOSTPTR) 0 ) {

		hosts = hptr->next;

		/* -------------------------- */
		/* Build a message to be sent */
		/* -------------------------- */
		if ((message = allocate_for_message()) != (DNSMSGPTR) 0) {

			/* Establish Recursive Flag if Allowed by Options */
			/* ---------------------------------------------- */
			if ( recursive & __DNS_RD )
				message->Header.Flags |= __DNS_RD;

			/* --------------------------------- */
			/* Build a Question for This Message */
			/* --------------------------------- */
			if ((message->Questions = domain_question( hptr->domain, qclass, qtype )) != (DNSQUESTPTR) 0)

				/* ------------------------------- */
				/* Forward the Message to the Host */
				/* ------------------------------- */
				forward_message( reason, message, hptr );

				/* -------------------------------- */
				/* Otherwise release unused message */
				/* -------------------------------- */
			else	message = liberate_for_message( message );
			}
		hptr = liberate_for_host( hptr );
		}

	return;
}
/*
 *	------------------------------------------------------------
 *	R E C U R S I V E _ R E S P O N S E ( rcvptr )
 *	------------------------------------------------------------
 *	This function will be called in order to elaborate a response
 *	to the query received using the state-oriented recursive
 *	mechanism if referal is required.
 *	------------------------------------------------------------
 */

DNSRCVPTR	recursive_response( rcvptr )
DNSRCVPTR	rcvptr;
{
	DNSMSGPTR	response; /* Output or Sent    Response Message */
	DNSMSGPTR	query;    /* Output or Sent    Response Message */
	DNSQUESTPTR	qptr;
	CONNECTIONPTR	connection;
	DNSHOSTPTR	hptr=(DNSHOSTPTR) 0;

	/* -------------------------------------------- */
	/* Collect and Validate Received Message Fields */
	/* -------------------------------------------- */
	if ((rcvptr == (DNSRCVPTR) 0)
	||  ((query = rcvptr->message) == (DNSMSGPTR) 0)
	||  ((connection = rcvptr->connection) == (CONNECTIONPTR) 0)
	||  ((qptr = query->Questions) == (DNSQUESTPTR) 0))
		return( rcvptr );

	/* Attempt to locate an exact response to avoid recursive overhead */
	/* --------------------------------------------------------------- */
	else if ( locate_response( qptr->name, qptr->class, qptr->type ) != 0 )
		extract_response( rcvptr );

	/* Attempt to locate hosts providing authority for the domain */
	/* ---------------------------------------------------------- */
	else if ((hptr = locate_hosts( qptr->name, qptr->class)) != (DNSHOSTPTR) 0)
	 	forward_request( rcvptr, hptr, qptr->class, qptr->type );

	/* Otherwise simply indicate DOMAIN NAME ERROR */
	/* ------------------------------------------- */
	else	dns_put_message( connection, query, (__DNS_QR | __DNS_AA | __DNS_NAME_ERROR ));

	return((rcvptr = liberate_for_reception( rcvptr )));

}

/*
 *	------------------------------------------------------------
 *	P R O C E S S _ M E S S A G E ( rcvptr )
 *	------------------------------------------------------------
 *	As its name implies this function will be called in order to
 *	perform the required processing of a all messages recieved
 *	by the domain name system server.
 *	Messages fall into the following two distint categories :
 *
 *		1) 	Client Requests
 *
 *			These will have been sent by client resolvers
 *			or by other co-operating servers performing
 *			recursive referal. Messages of this type will
 *			require that an eventual response or error condition
 *			be return to the sender.
 *
 *		2)	Referal Responses
 *
 *			These messages will have been sent by co-operating
 *			servers in response to recursive referal requests
 *			sent by this server. Messages of this type will be
 *			integrated into the CACHE section of the data base
 *			and in tha case of a relevent referal source being
 *			found an eventual response or error condition may
 *			be returned.
 *			
 *	------------------------------------------------------------
 */

PRIVATE	DNSRCVPTR	process_message( rcvptr )
	DNSRCVPTR	rcvptr;
{
	DNSMSGPTR	message;  /* Output or Sent    Response Message */

	/* -------------------------------------------- */
	/* Collect and Validate Received Message Fields */
	/* -------------------------------------------- */
	if ((rcvptr == (DNSRCVPTR) 0)
	||  ((message = rcvptr->message) == (DNSMSGPTR) 0))
		return( rcvptr );

	/* ---------------------------------------------------- */
	/* Differentiate between REQUESTS  from CLIENTS and ..	*/
	/*			 RESPONSES from SERVERS		*/
	/* ---------------------------------------------------- */
	if ( message->Header.Flags & __DNS_QR )

		/* -------------------------------------------- */
		/* Handle Response Received From another Server */
		/* -------------------------------------------- */
		return( integrate_response( rcvptr ) );

	/* ------------------------------------------------------ */
	/* If Recursive activity has not been requested OK : Easy */
	/* ------------------------------------------------------ */
	else if ( message->Header.Flags & __DNS_RD )

		/* -------------------------------------- */
		/* Initiate Potential Recursive Operation */
		/* -------------------------------------- */
		return( recursive_response( rcvptr ) );

	else

		/* ------------------------------- */
		/* Perform Non-Recursive Operation */
		/* ------------------------------- */
		return( extract_response( rcvptr ) );

}

/*
 *	------------------------------------------------------------
 *	D N S _ I N I T I A L I S A T I O N ( master_file )
 *	------------------------------------------------------------
 *	This function will be called upon DSN module startup in order
 *	to ensure that the internal control structures have been
 *	correctly initialised and constructed.
 *	The master file name provided will not be loaded by this 
 *	function. It will simply be established as the source for
 *	the configuration loading functions.
 *	------------------------------------------------------------
 */

INT 	dns_initialisation( master_file )
BPTR	master_file;
{
	INT	status=0;

	initialise_dns_memory();
	PendingRequests = (DNSFWDPTR) 0;
	if ((DnsManager = allocate_for_context(master_file)) == (DNSCONTEXTPTR) 0)
		return( 27 );
	else if ((status = InitialiseUrlServices()) != 0 )
		return( status );
	else	return( InitialiseDns() );

}

/*
 *	------------------------------------------------------------
 *	D N S _ L I B E R A T I O N ( status )
 *	------------------------------------------------------------
 *	This function will be called to ensure the correct liberation
 *	of the internal structures required by the DNS. It will return
 *	the status value provided by its caller.
 *	------------------------------------------------------------
 */

INT	dns_liberation( status )
INT	status;
{
	DNSFWDPTR	fptr;

	/* Ensure Pending Response/Requests have been cleared */
	/* -------------------------------------------------- */
	while ((fptr = PendingRequests) != (DNSFWDPTR) 0) {
		PendingRequests = fptr->next;
		fptr = liberate_for_forward( fptr );
		}

	/* Release DNS Data Base Management Mechanism */
	/* ------------------------------------------ */
	DnsManager = liberate_for_context( DnsManager );

	/* Release all Pre-Allocation Queues */
	/* --------------------------------- */
	liberate_dns_memory();

	/* And return Provided Status */
	/* -------------------------- */
	return( status );
}

/*
 *	------------------------------------------------------------
 *	D N S _ S E R V E R _ O P E R A T I O N ( pptr : <port>
 *						  nptr : <host>
 *						  hptr : <file> )
 *	------------------------------------------------------------
 *	This function will be called in order to start and perform
 *	Domain Name System Operation.
 *	The parameters provided will be used to establish :
 *		1) <port> The TCPIP service port number to be
 *			  used by the service.
 *		2) <host> The client/host to which the server must
 *			  be dedicated for adminstrative reasons.
 *		3) <file> The name of the file which is to be used
 *			  to load the master configuration of the
 *			  domain nam data base.
 *	------------------------------------------------------------
 */

INT	dns_server_operation( pptr, nptr, hptr )
BPTR  pptr;
BPTR  nptr;
BPTR  hptr;
{
	CONNECTIONPTR	SocketHandle=(CONNECTIONPTR) 0;
	URLPTR		ServerUrl=(URLPTR) 0;
	INT		packetsize=0;
	INT		status=0;
	BPTR		irqptr=(BPTR) 0;
	ADDRESS		hisaddr;
	DNSRCVPTR	rcvptr=(DNSRCVPTR) 0;

	/* --------------------------------- */
	/* Initialise DNS Management Context */
	/* --------------------------------- */
	if ((status = dns_initialisation(hptr)) != 0)
		return( dns_liberation( status ) );

	strcpy(ServerIdentity,"dns:initialisation");

	if ( verbose ) dns_server_banner();

	if ( TraceName != (BPTR) 0 )
		activate_trace( TraceName );

	/* -------------------------------------------------- */
	/* Establish operational scope PUBLIC or PRIVATE=name */
	/* -------------------------------------------------- */
	if ((ServerName = nptr) == (BPTR) 0)
		ServerName = "public";
	else if ((status = privatise( ServerName )) != 0)
		return( dns_liberation( report_failure( "Privatisation Failure" )));

	sprintf(ServerIdentity,"dns:(%s)",ServerName);

	set_port_address( pptr );

	/* ------------------------------------- */
	/* Prepare Address Package of Connection */
	/* ------------------------------------- */
	if ((ServerUrl = allocate_for_url( "dns://0.0.0.0/",0L )) == (URLPTR) 0)
		return( dns_liberation( report_failure( "URL Failure" )));

	/* ----------------------------------------------- */
	/* Attempt to Open the Type of Connection Required */
	/* ----------------------------------------------- */
	if ((SocketHandle = open_connection(DnsTransport,(PortAddress == 0 ? __DNS_PORT : PortAddress),	ServerUrl )) != (CONNECTIONPTR) 0) {

		/* ------------------------------------ */
		/* Attempt to Load Master Configuration */
		/* ------------------------------------ */
		if  ( load_configuration() == 0 ) {

			/* --------------------------------------------- */
			/* Failure to load Master Configuration is FATAL */
			/* --------------------------------------------- */
			SocketHandle = close_connection( SocketHandle );
			ServerUrl    = liberate_for_url( ServerUrl );
			return( dns_liberation( report_failure( "authoratitive configuration failure" )));
			}

		else if ( verbose ) {
			show_cache( DnsManager->Authority, "Authority" );
			show_cache( DnsManager->Cache, "Cache" );
			}
		
		/* ---------------------------------------- */
		/* Enter Operational Loop Awaiting Messages */
		/* ---------------------------------------- */
		while (1) {

			if (( rcvptr = receive_message( SocketHandle, 3 )) == (DNSRCVPTR) 0)
				/* Garbage Collector */
				/* ----------------- */
				flush_forward();
			else
				/* Present the Message for Processing */
				/* ---------------------------------- */
				if ((rcvptr = process_message( rcvptr )) != (DNSRCVPTR) 0)

					/* --------------------------------------- */
					/* Release and Ignore the Spurious Message */
					/* --------------------------------------- */
					rcvptr = liberate_for_reception( rcvptr );



			}

		/* --------------------- */
		/* Closure of Connection */
		/* --------------------- */
		SocketHandle = close_connection( SocketHandle );
		ServerUrl    = liberate_for_url( ServerUrl );

		}

	/* ---------------------------- */
	/* Liberation of DNS Controller */
	/* ---------------------------- */
	return(dns_liberation(0));
}


/*
 *	------------------------------------------------------------
 *	D N S _ S E R V E R _ U S A G E ( nptr )
 *	------------------------------------------------------------
 *	This function simply provides visual information relating
 *	to the command line options and parameters expected by this
 *	the DNS module.
 *	------------------------------------------------------------
 */

VOID	dns_server_usage( nptr )
BPTR 	nptr;
{
	printf("\n Usage %s \n",nptr);
	printf("         [ -a<address>         ] : Set IP Address to use         \n");
	printf("         [ -s<socket>          ] : Used by INETD                 \n");
	printf("         [ -p<port_number>     ] : Set HTTP port number          \n");
	printf("         [ -n<dns_server_name> ] : Set Server Identificaction    \n");
	printf("         [ -v                  ] : Activate Information Messages \n");
	printf("         [ -d                  ] : Activate Debug       Messages \n");
	printf("         [ -r[a | d | ]        ] : Inhibit DNS Recursive         \n");
	printf("         [ -u                  ] : Inhibit DNS UDP (use TCP)     \n");
	printf("         [ -t<trace_filename>  ] : Activate Tracing to file      \n");
	printf("         <configuration>         : Server Memory                 \n");
	return;
}


#endif	/* _DNSERV_C */
	/* --------- */

