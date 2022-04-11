#ifndef	_DNS_C
#define	_DNS_C

#include "basic.h"
#include "address.h"
#include "global.h"
#include "url.h"
#include "files.h"
#include "dns.h"
#include "dnsmem.h"


PRIVATE	SERVICE	DnsService;
PRIVATE	INT	MessageCounter=0;

#include "dnscfg.c"

				/* ---------------------- */
#include "dnsmem.c"		/* DNS ALLOCATION MANAGER */
#ifndef	_INHIBIT_VERBOSE
#include "dnsvis.c"		/* DNS DISPLAY    MANAGER */
#endif
#include "dnsput.c"		/* DNS OUTPUT     MANAGER */
#include "dnsget.c"		/* DNS INPUT      MANAGER */
				/* ---------------------- */

#ifdef	_DNS11C

/*	Optimisation for Version 1.1c awaiting full blown server */
/*	-------------------------------------------------------- */

#define	MAX_DNS_MEMORY	40

struct	dns_optimisation {
	unsigned long	time_to_live;
	unsigned long	address_ip;
	unsigned long	last_hit;
	unsigned char 	domain_name[64];
	} DnsMemory[ MAX_DNS_MEMORY ];

VOID	initialise_dns_optimisation()
{
	int	i;
	for ( i=0; i < MAX_DNS_MEMORY; i++ ) {
		DnsMemory[i].time_to_live = 0L;
		DnsMemory[i].address_ip   = 0L;
		DnsMemory[i].last_hit     = 0L;
		DnsMemory[i].domain_name[0] = 0;
		}
	return;
}

unsigned int use_dns_optimisation(nptr, aptr, maxadr)
	char * nptr;
	ADDRPTR	aptr;
	INT	maxadr;
{
	int	i;
	int	nb=0;
	unsigned long now=time((unsigned long *)0);
	unsigned long when;
	for ( i=0; i < MAX_DNS_MEMORY; i++ ) {
		if (( DnsMemory[i].domain_name[0] )
		&&  ((when = DnsMemory[i].time_to_live))) {
			if ( when <= now )
				DnsMemory[i].domain_name[0] = 0;
			else if ( compare_domain( nptr, DnsMemory[i].domain_name ) ) {
				DnsMemory[i].last_hit = now;
				memcpy((BPTR) &aptr[nb++].sin_addr,(char *) & DnsMemory[i].address_ip,sizeof(long)); 
				if ( nb >= maxadr )
					break;
				}
			}
		}
	return( nb );
}

void add_dns_optimisation(char * nptr,unsigned char * lptr, unsigned long ttlv)
{
	int	i;
	int	n;
	unsigned char * cptr;
	int	oldest_record=0;
	
	unsigned long now=time((unsigned long *)0);
	unsigned long when;
	unsigned long least_recently_used=now;

	for ( i=0; i < MAX_DNS_MEMORY; i++ ) {
		if (!( DnsMemory[i].domain_name[0] ))
			break;
		else if ((when = DnsMemory[i].time_to_live) > now ) {
			if( when < least_recently_used ) {
				least_recently_used = when;
				oldest_record = i;
				}
			continue;
			}
		else	{
			DnsMemory[i].domain_name[0] = 0;
			break;
			}
		}


	if ( i >= MAX_DNS_MEMORY )
		i = oldest_record;

	for ( n=0,cptr=DnsMemory[i].domain_name; n < 63; n++ )
		if (!( *(cptr+n) = *(nptr +n) ))
			break;
	*(cptr+n) = 0;
	memcpy((BPTR) &DnsMemory[i].address_ip,lptr,sizeof(long)); 
	DnsMemory[i].last_hit     = now;
	DnsMemory[i].time_to_live = (now + ttlv);
	return;
}


#endif



PUBLIC 	VOID	dns_set_verbose( INT value )
{
	verbose = debug = value;
	return;
}

PUBLIC 	INT 	dns_set_recursive( aptr )
	BPTR	aptr;
{

	DnsRecursive = 0;
	while ( *aptr ) {
		switch(*(aptr++)) {
			case	'a' :
			case	'A' :	DnsRecursive |= __DNS_RA;
					continue;
			case	'd' :
			case	'D' : 	DnsRecursive |= __DNS_RD;
					continue;
			default	    :	return(30);
			}
		break;
		}
	return(0);
}

PUBLIC 	INT 	dns_set_timeout( aptr )
	BPTR	aptr;
{
	INT	mode=0;

	DnsRetries = 0;
	DnsTimeOut = 0;

	while ( *aptr ) {
		if (( *aptr >= '0' ) && ( *aptr <= '9' )) {
			if ( mode )
				DnsRetries = ((DnsRetries * 10) + ( *(aptr++) - '0' ));
			else	DnsTimeOut = ((DnsTimeOut * 10) + ( *(aptr++) - '0' ));
			}
		else if ( *aptr == ',' )
			mode++;
		else	break;
		}
	return(0);
}

PUBLIC 	INT 	dns_set_transport( aptr )
	BPTR	aptr;
{
	DnsTransport = 0;
	while ( *aptr ) {
		switch(*(aptr++)) {
			case	'v' :
			case	'V' :	DnsTransport = __URL_TCP;
					break;
			case	'd' :
			case	'D' : 	DnsTransport = __URL_UDP;
					break;
			case	'r' :
			case	'R' : 	DnsTransport = __URL_RAW;
					break;
			default	    :	return(30);
			}
		break;
		}
	return(0);
}

PUBLIC	INT	resolve_dns_class( tptr )
	BPTR 	tptr;
{

	if ( compare_tokens( tptr, "IN") != 0) 
		return(__DNS_CLASS_IN);
	else if ( compare_tokens( tptr, "CS") != 0) 
		return(__DNS_CLASS_CS);
	else if ( compare_tokens( tptr, "CH") != 0) 
		return(__DNS_CLASS_CH);
	else if ( compare_tokens( tptr, "HS") != 0) 
		return(__DNS_CLASS_HS);
	else if ( compare_tokens( tptr, "ANY") != 0) 
		return(__DNS_CLASS_ANY);
	else 	return(  0 );
}

PUBLIC	INT	resolve_type( tptr )
	BPTR 	tptr;
{

	if ( compare_tokens( tptr, "A") != 0) 
		return(	__DNS_TYPE_A );
	else if ( compare_tokens( tptr, "NS") != 0)
		return(	__DNS_TYPE_NS );
	else if ( compare_tokens( tptr, "CNAME") != 0) 
		return(	__DNS_TYPE_CNAME );
	else if ( compare_tokens( tptr, "SOA") != 0) 
		return(	__DNS_TYPE_SOA );
	else if ( compare_tokens( tptr, "WKS") != 0) 
		return(	__DNS_TYPE_WKS );
	else if ( compare_tokens( tptr, "PTR") != 0) 
		return(	__DNS_TYPE_PTR );
	else if ( compare_tokens( tptr, "HINFO") != 0) 
		return(	__DNS_TYPE_HINFO );
	else if ( compare_tokens( tptr, "MINFO") != 0) 
		return(	__DNS_TYPE_MINFO );
	else if ( compare_tokens( tptr, "MX") != 0) 
		return(	__DNS_TYPE_MX );
	else if ( compare_tokens( tptr, "TXT") != 0) 
		return(	__DNS_TYPE_TXT );
	else if ( compare_tokens( tptr, "AXFR") != 0) 
		return(	__DNS_QTYPE_AXFR );
	else if ( compare_tokens( tptr, "MAILB") != 0) 
		return(	__DNS_QTYPE_MAILB );
	else if ( compare_tokens( tptr, "ALL") != 0) 
		return(	__DNS_QTYPE_ANY );
	else	return( 0  );
}


PRIVATE	INT	dns_parser( nptr, uptr )
	BPTR	nptr;
	URLPTR	uptr;
{
	INT	status=0;
	/* Initialise(reset) Result Fields */
	/* ------------------------------- */
	uptr->base      = __DNS_PORT;
	uptr->transport = DnsTransport;

	if (!((status = parse_url_host( nptr, uptr )) & _URL_IS_HOST)) {
		strcpy( uptr->host, _LOCAL_HOST );
		status |= _URL_IS_HOST;
		}
	if (!(status & _URL_IS_PATH)) {
		strcpy( uptr->path, _LOCAL_PATH );
		status |= _URL_IS_PATH;
		}
	return( status );
}

#ifndef	_INHIBIT_VERBOSE
PRIVATE	VOID	show_client_usage(status)
INT		status;
{
	printf("Usage :\n");
	printf("\tGET 	  <domain-name>  \n");
	printf("\t      [ <domain-type>  ] { *A * | NS | CNAME | PTR | ALL }\n");
	printf("\t      [ <domain-class> ] { *IN* | CH | HS | ANY }\n");
	switch ( status ) {
		case	1 : printf("\n* * Incorrect command * *\n"); break;
		case	2 : printf("\n* * Incorrect domain  * *\n"); break;
		case 	3 : printf("\n* * Incorrect type    * *\n"); break;
		case	4 : printf("\n* * Incorrect class   * *\n"); break;
		}
	return;
}
#endif

PRIVATE	VOID		submit_operation( uptr, qname, qtype, qclass )
	URLPTR		uptr;
	BPTR		qname;
	INT		qtype;
	INT		qclass;
{
	CONNECTIONPTR	cptr=(CONNECTIONPTR) 0;
	DNSMSGPTR	request=(DNSMSGPTR) 0;
	DNSMSGPTR	response=(DNSMSGPTR) 0;
	INT		oldverbose=0;
	if ((request = allocate_for_message()) != (DNSMSGPTR) 0) {
		if ((response = allocate_for_message()) != (DNSMSGPTR) 0) {
			request->Header.identity = new_dns_message();
			if ( DnsRecursive & __DNS_RD )
				request->Header.Flags |= __DNS_RD;
			if ((request->Questions = build_question( qname, qtype, qclass )) != (DNSQUESTPTR) 0) {

				if ((cptr = client_connection( uptr )) != (CONNECTIONPTR) 0) {
#ifndef	_INHIBIT_VERBOSE
					(void) show_connection( cptr );
#endif
					oldverbose = verbose; verbose = 0;
					(void) dns_put_message( cptr, request, 0 );
#ifndef	_INHIBIT_VERBOSE
					(void) show_message( request, 6, "To" ,cptr );
#endif
#ifdef	_BEFORE_20041999
#else
					if ( await_connection( cptr, cptr->timeout ) != -1) {
#endif
						(void) dns_get_message( cptr, response );
#ifndef	_INHIBIT_VERBOSE
						(void) show_message( response, 6, "From" ,cptr );
#endif
#ifdef	_BEFORE_20041999
#else
						}
#ifndef	_INHIBIT_VERBOSE
					else	printf("Time Out !");
#endif
#endif
					verbose = oldverbose;
					cptr = close_connection( cptr );
					}
#ifndef	_INHIBIT_VERBOSE
				else	{
					printf("Host Failure : ");
					show_url( uptr );
					}
#endif
				}
			response = liberate_for_message( response );
			}
		request = liberate_for_message( request );
		}
	return;
}

PRIVATE	INT 	dns_service_client( uptr, argc, argv )
	URLPTR		uptr;
	INT		argc;
	BPTR    	argv[];
{
#ifndef	_INHIBIT_VERBOSE
	INT		argi=0;
	BPTR		qname=(BPTR) 0;
	INT 		qtype=__DNS_QTYPE_ANY;
	INT 		qclass=__DNS_CLASS_ANY;

	printf("DNS CLIENT OPERATION : \n");
	if (( argi >= argc )
	||  ( compare_tokens( argv[(argi++)], (BPTR) "GET") == 0 )) {
		show_client_usage(1);
		}
	else if ( argi >= argc )
		show_client_usage(2);
	else	{
		qname = (BPTR) argv[(argi++)];

		if (( argi < argc )
		&&  ((qtype = resolve_type( argv[(argi++)] )) == 0))
			show_client_usage(3);
		else	{
			if (( argi < argc )
			&&  ((qclass = resolve_dns_class( argv[(argi++)] )) == 0))
				show_client_usage(4);
			else	submit_operation( uptr,  qname, qtype, qclass );
			}
		}
#endif
	return(0);
}

PUBLIC	INT	initialise_dns_service()
{
	INT	status;
	strcpy(DnsService.name,__DNS_PREFIX);
	DnsService.parse  = dns_parser;
	DnsService.client = dns_service_client;
	DnsService.nature = 0;
	MessageCounter = 1;
#ifdef	_DNS11C
	initialise_dns_optimisation();
#endif
	return( add_url_service( (SERVICEPTR) & DnsService ) );

}

PUBLIC	INT	dns_add_host( hptr )
	BPTR	hptr;
{
	BPTR	nptr;
	INT	i=0;
	if ( DnsHosts >= __DNS_MAX_HOSTS )
		return(46);
	else if ( hptr == (BPTR) 0 )
		return( 30 );
	else	{
		/* DŠan cinnteachd nach eiler air aithneachadh mu thrath */
		/* ----------------------------------------------------- */
		for ( 	i=0;
			i < DnsHosts;
			i++ )
			if ( compare_tokens( hptr, DnsHost[i] ) )
				return(0);

		/* 'S e ainm sheirbhis —r a th'ann */
		/* ------------------------------- */
		if ((nptr = allocate_for_string( hptr )) == (BPTR) 0)
			return( 27 );
		else	{
			DnsHost[DnsHosts++] = nptr;
			return(0);
			}
		}
}


PRIVATE	dns_set_host( BPTR ipadr )
{
	BYTE	buffer[32];
	sprintf(buffer,"dns://%u.%u.%u.%u",
			ipadr[0],ipadr[1],ipadr[2],ipadr[3]);
	return( dns_add_host( buffer ) );
}

PRIVATE	WORD	dns_default_host()
{
	BYTE	ipadr[sizeof(long)];
	struct  hostent *hp=(struct hostent *) 0;

     	if ((hp = gethostbyname("dnshost")) == (struct hostent *) 0)
		return( __DNS_NAME_ERROR );
	else	{
		memcpy((BPTR) ipadr, (BPTR) hp->h_addr_list[0],sizeof(long));
		return( dns_set_host( (BPTR) ipadr ) );
		}

}


PUBLIC	INT	new_dns_message()
{
	INT	i = ++MessageCounter;
	return( i );
}

PUBLIC	DNSMSGPTR	ResolveDns( uptr, nptr, ntype, nclass )
	URLPTR		uptr;
	BPTR		nptr;
	INT		ntype;
	INT		nclass;
{
	DNSMSGPTR	request=(DNSMSGPTR) 0;
	DNSMSGPTR	response=(DNSMSGPTR) 0;
	CONNECTIONPTR	cptr;

	if  ((request = allocate_for_message()) != (DNSMSGPTR) 0) {
		if ((response = allocate_for_message()) != (DNSMSGPTR) 0) {
			request->Header.identity = new_dns_message();
			if ( DnsRecursive & __DNS_RD )
				request->Header.Flags |= __DNS_RD;
			if ((request->Questions = build_question( nptr, ntype, nclass )) != (DNSQUESTPTR) 0) {
				if  (( resolve_internet_host( uptr ) == 0)
				&&   ((cptr = open_connection( DnsTransport, 0, uptr )) != (CONNECTIONPTR) 0)) {
					dns_put_message( cptr, request, 0 );

/* -------------------------------------------- */
/* S'ann an seo a tha a' mhearachd DNS 		*/
/* a tha mi air a bhith a lorg fada ro fhad'.	*/
/* Nuair a chuireamaid teachdaireachd chun	*/
/* a' mhaighstir sheirbhis DNS feaumaidh sinn 	*/
/* dh'fheitheamh beagan —ine gus am faic sinn	*/
/* teachdairachd sam bith a chuireas e thugainn	*/
/* air ais. Mura h-eile c…il sam bith dhuinn	*/
/* feumaidh sinn m…ighstir eile fheuchainn neo 	*/
/* nach eil fear eile ann feumaidh sinn fios 	*/
/* thoirt air ais gus an tŠ a dh'fhoighnich 	*/
/* oirnn an obair seo dhŠanamh.			*/
/* -------------------------------------------- */
#ifdef	_BEFORE_20041999
#else
					if ( await_connection( cptr, (cptr->timeout=DnsTimeOut) ) != -1) {
#endif
						(void) dns_get_message( cptr, response );

						cptr = close_connection( cptr );

						if ((request->Header.identity != response->Header.identity)
						||  (response->Header.rCode != __DNS_NO_ERROR))
							response = liberate_for_message( response );
#ifdef	_BEFORE_20041999
#else
						}
					else	{
						cptr = close_connection( cptr );
						response = liberate_for_message( response );
						}
#endif
					}
				else 	{
					response = liberate_for_message( response );
					}
				}
			else	response = liberate_for_message( response );
			}
		request = liberate_for_message( request );
		}
	return(response);
}

PUBLIC	DNSMSGPTR	Resolver( hptr, qclass, qtype )
	DNSHOSTPTR	hptr;
	INT		qclass;
	INT		qtype;
{
	URLPTR		DnsUrl=(URLPTR) 0;
	BPTR		nptr=(BPTR) 0;
	DNSMSGPTR 	response=(DNSMSGPTR) 0;

	if ( hptr == (DNSHOSTPTR) 0)
		return( response );
	else if ( hptr->status )
		return( response );
	else	hptr->status = 1;

	if (( hptr->address != (BPTR) 0 )
	&&  ( hptr->domain  != (BPTR) 0 )
	&&  ((DnsUrl = allocate_for_url( hptr->address,0L )) != (URLPTR) 0)
	&&  ( DnsUrl->status & _URL_IS_HOST )
	&&  ((nptr = name2string( hptr->domain )) != (BPTR) 0)) {
		response = ResolveDns( DnsUrl, nptr,qtype, qclass );
		nptr = liberate_zone( nptr );
		}

	if ( DnsUrl )
		DnsUrl = liberate_for_url( DnsUrl );

	return( response );

}

PRIVATE	BPTR		extract_address( rrptr, domain, aptr, adrmax, nbaddr 
#ifdef	_DNS11C 
				, adrmode
#endif
				 )
	DNSRRPTR	rrptr;
	BPTR		domain;
	ADDRPTR		aptr;
	INT		adrmax;
	IPTR		nbaddr;
#ifdef	_DNS11C
	INT		adrmode;
#endif
{
	INT		status=78;
	BPTR		iptr=(BPTR) 0;
	DNSRRPTR	rptr;
	INT		found=0;

	if ((rptr = rrptr) != (DNSRRPTR) 0) {

		/* Scan list of answers for a suitable internet adresse record */
		/* ----------------------------------------------------------- */
		while (rptr != (DNSRRPTR) 0) {

			if  ( compare_tokens( rptr->name, domain ) ) {

				if (( rptr->type == __DNS_TYPE_CNAME )
				&&  ( rptr->data != (BPTR) 0 )) {

					/* Resolve Alias to new Name */
					/* ------------------------- */
					domain = rptr->data;
		
					/* And Retry from Top of List */
					/* -------------------------- */
					rptr = rrptr;
					}
				else if (( rptr->type == __DNS_TYPE_A )
		  		     &&  ( rptr->length == sizeof(long))
			             &&  ((iptr = rptr->data) != (BPTR) 0)) {

					if ( *nbaddr < adrmax ) {

						/* Copy address to result buffer */
						/* ----------------------------- */
#ifdef	_DNS11C
						if ( adrmode )
							add_dns_optimisation( domain, iptr, rptr->ttl );
#endif
						memcpy((BPTR) &aptr[*nbaddr].sin_addr,iptr,sizeof(long)); 
						*nbaddr += 1;

						found++;

						rptr = rptr->next;
						continue;
						}
					else	break;
					}	
				}
			else	rptr = rptr->next;
			}
		}

	if ( found ) 
		domain = (BPTR) 0;
	return( domain );
}

PRIVATE	BPTR		server_address( rptr, domain, aptr, adrmax, nbaddr )
	DNSRRPTR	rptr;
	BPTR		domain;
	ADDRPTR		aptr;
	INT		adrmax;
	IPTR		nbaddr;
{
	BPTR	nptr;
	INT	status;

	/* Feuchamaid ri faighainn se•ladh an t-seirbhis …s an 	*/
	/* teachdaireach on roinn an cois			*/
	/* ---------------------------------------------------- */
	if ((nptr = extract_address( rptr, domain, aptr, adrmax, nbaddr
#ifdef	_DNS11C
			,0	/* Do not add to optimisations */
#endif
			 )) == (BPTR) 0)

		/* Ceart   : GlŠ mhath nach eil e m•dhail */
		/* -------------------------------------- */
		return( nptr );

	else	/* Cearr   : s'dorcha mi-mhodhail */
		/* ------------------------------ */
	     if ((nptr = name2string( domain )) == (BPTR) 0)
		return( domain );
	else	{
		/* Feuchamaid nach faighamaid aireamh bhon ainm */
		/* -------------------------------------------- */
		status = TryHostByName( nptr, aptr );
		nptr = liberate_zone( nptr );
		return( ( status != 0 ? domain : nptr ) );
		}
}



PRIVATE	INT	compare_domain( aptr, bptr )
	BPTR	aptr;
	BPTR	bptr;
{
	INT	l;
	while ( strlen(bptr) > 0 ) {
		if ( compare_tokens( aptr, bptr ) )
			return(1);
		else 	{
			l = *(bptr++);
			bptr += l;
			}
		}
	return(0);
}

PRIVATE	INT		compare_hosts( aptr, bptr )
	DNSHOSTPTR	aptr;
	DNSHOSTPTR	bptr;
{
	if (aptr != (DNSHOSTPTR) 0) {
		if ( bptr == (DNSHOSTPTR) 0)
			return(0); /* A!NULL B=NULL */
		else if (( compare_tokens( aptr->address, bptr->address ) )
		     &&  ( compare_tokens( aptr->domain,  bptr->domain  ) ))
			return(1);
		else	return(0);
		}
	else if (bptr != (DNSHOSTPTR) 0)
		return( 0 );	/* A=NULL B!NULL */
	else	return( 1 );	/* BOTH=NULL	 */
}


PRIVATE	DNSHOSTPTR	learn_host_address( root, last, domain, tempaddress, nbaddr )
	DNSHOSTPTR	root;
	DNSHOSTPTR	last;
	BPTR		domain;
	ADDRPTR		tempaddress;
	INT		nbaddr;
{
	DNSHOSTPTR	hptr;
	DNSHOSTPTR	tptr;
	int	nba;
	for (nba=0; nba < nbaddr ; nba++ ) {
		/* Build a Host Records*/
		/* ------------------- */
		if ((hptr = build_host( (BPTR) 0, (ADDRPTR) & tempaddress[nba], domain )) != (DNSHOSTPTR) 0) {
			for ( tptr = root; tptr != (DNSHOSTPTR) 0; tptr = tptr->next)
				if ( compare_hosts( tptr, hptr ) )
					break;
			if ( tptr != (DNSHOSTPTR) 0)
				hptr = liberate_for_host( hptr );
			else	{
				last->next = hptr;
				last       = hptr;
				}
			}
		}
	return(last);
}

PRIVATE	DNSHOSTPTR	add_hosts( root, last, message, domain )
	DNSHOSTPTR	root;
	DNSHOSTPTR	last;
	DNSMSGPTR	message;
	BPTR		domain;
{
	DNSRRPTR	rptr;
	DNSRRPTR	gptr;
	BPTR		nptr;
	ADDRESS		tempaddress[_MAX_URL_ADDR];
	INT		nbaddr=0;

	memset( & tempaddress, 0, ( sizeof( ADDRESS ) * _MAX_URL_ADDR) );

	/* Scan Authories for Name Server Records to be used for Referal */
	/* ------------------------------------------------------------- */
	if ((rptr = message->Authority) != (DNSRRPTR) 0) {

		do	{

			/* Check for Valid NS record matching QUERY */
			/* ---------------------------------------- */
			if (( rptr->type == __DNS_TYPE_NS )
			&&  ( rptr->name != (BPTR) 0 )
			&&  ( compare_domain( rptr->name, domain ) )
			&&  ( rptr->data != (BPTR) 0 ))

				/* Localise Address in Glue Section */
				/* -------------------------------- */
				if ((nptr = server_address( 	
						message->Additional, 
						rptr->data, 
						(ADDRPTR) tempaddress,
						_MAX_URL_ADDR,
						(IPTR) & nbaddr
						)) == (BPTR) 0 )

					last = learn_host_address( root, last , domain, (ADDRPTR) tempaddress, nbaddr );

			}
		while ((rptr = rptr->next) != (DNSRRPTR) 0);
		}
	return( last );
}


PUBLIC	INT	DnsResolve( nptr , aptr, maxadr )
	BPTR	nptr;
	ADDRPTR	aptr;
	INT	maxadr;
{
	DNSHOSTPTR	Hosts=(DNSHOSTPTR) 0;
	DNSHOSTPTR	LastHost=(DNSHOSTPTR) 0;
	DNSHOSTPTR	ThisHost=(DNSHOSTPTR) 0;
	DNSMSGPTR	response=(DNSMSGPTR) 0;
	INT		status=27;
	DNSHOSTPTR	hptr=(DNSHOSTPTR) 0;
	INT		nbh;
	BPTR		domain=(BPTR) 0;
	BPTR		tempname=(BPTR) 0;
	INT		nbaddr=0;
	
	/* Establish Primary Host */
	/* ---------------------- */
	if ((!( DnsHosts ))
	&&  ((status = dns_default_host()) != 0))
		return( nbaddr );

	else if ((domain = string2name( nptr )) != (BPTR) 0) {

#ifdef	_DNS11C

		if ((nbh = use_dns_optimisation( domain, aptr, maxadr )) != 0) {
			domain = liberate_zone( domain );
			return( nbh );
			}
#endif

		for ( nbh = 0; nbh < DnsHosts; nbh++ ) {

			if ((hptr = build_host( DnsHost[nbh], (ADDRPTR) 0, domain )) == (DNSHOSTPTR) 0)
				break;
			else if (Hosts == (DNSHOSTPTR) 0)
				Hosts = hptr;
			else	LastHost->next = hptr;

			LastHost = hptr;

			}

		if ( Hosts != (DNSHOSTPTR) 0) {

			/* Perform Request while more Hosts are available */
			/* ---------------------------------------------- */
			ThisHost = Hosts;

			do	{
#ifndef	_INHIBIT_VERBOSE
				if ( verbose & 8 )
					show_hosts( Hosts );
#endif
				/* Transmit Query to current Host */
				/* ------------------------------ */
				if ((response = Resolver( ThisHost,__DNS_CLASS_IN, __DNS_TYPE_A )) != (DNSMSGPTR) 0) {
		
					/* Attempt to Extract Exact answer */
					/* ------------------------------- */
					if ((tempname = extract_address( response->Answers, ThisHost->domain, aptr, maxadr, (IPTR) & nbaddr
#ifdef	_DNS11C
						,1 /* Add to optimisations */
#endif
						 )) != (BPTR) 0)

						/* No Answers so attempt to collect new Hosts */
						/* ------------------------------------------ */
						LastHost = add_hosts( Hosts, LastHost, response, tempname );

					else	status = 0;

					/* Release the received message */
					/* ---------------------------- */
					response = liberate_for_message( response );

					if (!( status ))
						break;

					}
				}
			while (( ThisHost = ThisHost->next) != (DNSHOSTPTR) 0);

			domain = liberate_zone( domain );

			/* Liberate List of Hosts */
			/* ---------------------- */
			while (( ThisHost = Hosts ) != (DNSHOSTPTR) 0) {
				Hosts = ThisHost->next;
				ThisHost = liberate_for_host( ThisHost );
				}
			}
		}

	if (!( nbaddr ))
		if (!( TryHostByName( nptr, aptr ) ))
			nbaddr++;

	return( nbaddr );

}

PRIVATE	INT	ResolveHostReady=0;

PUBLIC	INT	InitialiseResolver()
{
	INT	status;
	if (!( ResolveHostReady )) {
		initialise_dns_memory();
		if (((status = initialise_url_services()) != 0 )
		||  ((status = initialise_dns_service() ) != 0 ))
			return( status );
		else	ResolveHostReady=1;
		}
	return(0);
}

PUBLIC	INT	ResolveHostByName( nptr, aptr )
	BPTR	nptr;
	BPTR	aptr;
{
	INT	status;
	ADDRESS	Adresse;

	if (!( ResolveHostReady ))
		if ((status = InitialiseResolver()) != 0)
			return( status );

	/* Feuch ri se•ladh aireamhail fhaighinn */
	/* ------------------------------------- */
	if (!( DnsResolve( nptr, & Adresse, 1 )))
		return( 78 );
	else	{
		memcpy( aptr,(BPTR) & Adresse.sin_addr , sizeof(long) );
		return(0);
		}
}

PUBLIC	INT	ResolveHostsByName( nptr, aptr, nbaddr )
	BPTR	nptr;		/* Name string for resolution		*/
	BPTR	aptr;		/* Buffer to store address longs	*/
	INT	nbaddr;		/* Number of longs that may be stored	*/
{
	INT	i;
	INT	status;
	ADDRESS	Adresse[_MAX_URL_ADDR];
	INT	nba=0;

#ifndef	_INHIBIT_VERBOSE
	if ( verbose & 8 )
		printf("RHsBN(%s,%u)\n",nptr,nbaddr);
#endif

	if (!( nbaddr )) 
		nbaddr = 1;

	memset( aptr, 0, (nbaddr * sizeof(long)));

	if (nbaddr > _MAX_URL_ADDR )
		nbaddr = _MAX_URL_ADDR;

	if (!( ResolveHostReady ))
		if ((status = InitialiseResolver()) != 0)
			return( 0 );

	/* Feuch ri se•ladh aireamhail fhaighinn */
	/* ------------------------------------- */
	if ((nba = DnsResolve( nptr, Adresse, nbaddr )) != 0)
		for (i=0; i < nba; i++ )
			memcpy((aptr + (i * sizeof(long))), (BPTR) & Adresse[i].sin_addr,sizeof(long)); 


#ifndef	_INHIBIT_VERBOSE
	if ( verbose & 8 )
		printf("RHsBN=>%u\n",nba);

#endif
	return( nba );
}

#ifndef	_INHIBIT_VERBOSE
PUBLIC	VOID	dns_show_usage()
{
	printf("         [ -h<dns_host_name>  ] : Set primary DNS Host \n");
	printf("         [ -r[a | d | ]       ] : Set DNS Recursivity  \n");
	printf("         [ -u[v | d | r]      ] : Set DNS Transport    \n");
	printf("         [ -w<seconds>        ] : Set Message Timeout  \n");
	return;
}

PUBLIC	VOID	dns_show_example()
{
	printf("        dns://hostname GET <domain> <type> <class> \n");
	return;
}
#endif

#endif	_DNS_C



