#ifndef	_DNSVIS_C
#define	_DNSVIS_C

VOID		show_header( hptr )
DNSHEADPTR	hptr;
{
	printf("DNS Message Header\t[\n");
	printf("\tIdentity        : %u\n",hptr->identity);
	printf("\tOpCode          : %u\n",hptr->qCode);
	printf("\tResult          : %u\n",hptr->qCode);
	printf("\tFlags           : %x\n",hptr->Flags);
	printf("\tQuestions       : %u\n",hptr->Questions);
	printf("\tAnswers         : %u\n",hptr->Answers);
	printf("\tAuthorities     : %u\n",hptr->Authority);  
	printf("\tAdditional      : %u\n",hptr->Additional);
	printf("\t]\n");
	return;
}

VOID	show_record_name( nptr )
BPTR	nptr;
{
	BPTR	sptr;
	if ((nptr != (BPTR) 0)
	&& ((sptr = name2string( nptr )) != (BPTR) 0)) {
		printf("<%s> ",sptr);
		sptr = liberate_zone( sptr );
		}
	else	printf("<> ");
	return;
}

PUBLIC	VOID	show_IP_address( aptr )
	BPTR	aptr;
{
	printf(	" %u.%u.%u.%u ",
		(*(aptr + 0) & 0x00FF),
		(*(aptr + 1) & 0x00FF),
		(*(aptr + 2) & 0x00FF),
		(*(aptr + 3) & 0x00FF));
	return;
}

PUBLIC	VOID	show_ttl( ttl )
	LONG	ttl;
{
	INT	v[5];
	v[0] = (((INT) ttl) % 60);	/* Seconds */
	ttl /= 60L;
	v[1] = (((INT) ttl) % 60);	/* Minutes */
	ttl /= 60L;
	v[2] = (((INT) ttl) % 24);	/* Hours */
	ttl /= 24L;
	v[3] = (((INT) ttl) % 7 );	/* Days  */
	v[4] = (INT) (ttl / 7);	/* Weeks */
	printf(", TTL ");
	if ( v[4] ) {
		if ( v[4] == 1 )
			printf("%u Week ",v[4]);
		else	printf("%u Weeks ",v[4]);
		}
	if ( v[3] ) {
		if ( v[3] == 1 )
			printf("%u Day ",v[3]);
		else	printf("%u Days ",v[3]);
		}
	if ( v[2] ) {
		if ( v[2] == 1 )
			printf("%u Hour ",v[2]);
		else	printf("%u Hours ",v[2]);
		}
	if ( v[1] ) {
		if ( v[1] == 1 )
			printf("%u Minute ",v[1]);
		else	printf("%u Minutes ",v[1]);
		}
	if ( v[0] ) {
		if ( v[0] == 1 )
			printf("%u Second ",v[0]);
		else	printf("%u Seconds ",v[0]);
		}
	return;
}

VOID	show_dns_type( t )
INT	t;
{
		switch ( t ) {
			case	__DNS_TYPE_A	: printf("A    "); break;
			case	__DNS_TYPE_NS	: printf("NS   "); break;
			case	__DNS_TYPE_CNAME: printf("CNAM "); break;
			case	__DNS_TYPE_SOA  : printf("SOA  "); break;
			case	__DNS_TYPE_WKS  : printf("WKS  "); break;
			case	__DNS_TYPE_PTR  : printf("PTR  "); break;
			case	__DNS_TYPE_HINFO: printf("HINF "); break;
			case	__DNS_TYPE_MINFO: printf("MINF "); break;
			case	__DNS_TYPE_MX   : printf("MX   "); break;
			case	__DNS_TYPE_TXT  : printf("TXT  "); break;
			case	__DNS_QTYPE_ANY : printf("ALL  "); break;
			default			: printf("0x%04.1X",t); break;
			}
	return;
}
VOID	show_dns_class( c )
INT	c;
{
		switch ( c ) {
			case	__DNS_CLASS_IN	: printf(" IN "); break;
			case	__DNS_CLASS_CS	: printf(" CS "); break;
			case	__DNS_CLASS_CH	: printf(" CH "); break;
			case	__DNS_CLASS_HS	: printf(" HS "); break;
			case	__DNS_CLASS_ANY	: printf(" ANY"); break;
			default			: printf(" 0x%04.1X",c); break;
			}
	return;
}

PRIVATE	VOID	show_mx_record( bptr )
	BPTR	bptr;
{
	printf(" %u ",mem_getw( bptr ));
	show_record_name( (bptr + 2) );
	return;
}

PRIVATE	VOID	show_soa_record( bptr )
	BPTR	bptr;
{
	INT	l;
	INT	i;
	show_record_name( bptr  );
	l = (strlen(bptr)+1); bptr += l;
	show_record_name( bptr  );
	l = (strlen(bptr)+1); bptr += l;
	for ( i=0; i < 5; i++ ) {
		printf(" %lu",mem_getl(bptr));
		bptr += sizeof( LONG );
		}
	return;
}

PRIVATE	VOID	show_dns_typed_data( type, size, dptr )
INT		type;
INT		size;
BPTR		dptr;
{
	INT	i=0;
	show_dns_type( type );
	if (( size != 0 )
	&&  ( dptr != (BPTR) 0)) {
		switch ( type ) {
			case	__DNS_TYPE_A 	:
				show_IP_address( dptr );
				break;
			case	__DNS_TYPE_MX   :
				show_mx_record( dptr );
				break;
			case	__DNS_TYPE_SOA  :
				show_soa_record( dptr );	
				break;
			case __DNS_TYPE_MR	: /* MAIL RENAME  */
			case __DNS_TYPE_MG	: /* MAIL GROUP   */
			case __DNS_TYPE_MF	: /* MAIL FORWARD */
			case __DNS_TYPE_MD	: /* MAIL DELIVER */
			case __DNS_TYPE_MB	: /* MAIL BOX     */
			case	__DNS_TYPE_PTR 	: /* POINTER	  */
			case	__DNS_TYPE_NS  	: /* NAME SERVER  */
			case	__DNS_TYPE_CNAME: /* ALIAS	  */
				show_record_name( dptr );
				break;
			default			:
				printf("DATA:");
				for ( i=0; i < size; i++ )
					printf("0x%X ",( *(dptr++) & 0x00FF ));
			}
		}
	return;
}

VOID	show_record( rptr )
DNSRRPTR	rptr;
{
	if ( rptr != (DNSRRPTR) 0) {
		printf("\t");
		show_record_name( rptr->name );
		show_dns_class( rptr->class );
		printf(", DOB %lu",rptr->dob);
		if ( record_still_live( rptr ) )
			show_ttl( rptr->ttl );
		else	printf(", *EXPIRED* ");
		show_dns_typed_data( rptr->type, rptr->length, rptr->data );
		printf("\n");
		}
	return;
}

VOID		show_records( rptr )
DNSRRPTR	rptr;
{
	while ( rptr != (DNSRRPTR) 0 ) {
		show_record( rptr );
		rptr = rptr->next;
		}
	return;
}

VOID		show_question( qptr )
DNSQUESTPTR	qptr;
{
	BPTR		sptr;
	INT		i;

	if ( qptr != (DNSQUESTPTR) 0) {
		printf("\t");
		show_record_name( qptr->name );
		show_dns_type( qptr->type );
		show_dns_class( qptr->class );
		printf("\n");
		}
	return;
}

VOID		show_questions( qptr )
DNSQUESTPTR	qptr;
{
	while ( qptr != (DNSQUESTPTR) 0 ) {
		show_question( qptr );
		qptr = qptr->next;
		}
	return;
}

VOID	show_dns_error( ecode )
INT	ecode;
{
	switch ( ecode ) {
		case	__DNS_NO_ERROR		: 
			printf(" OK \n");
			break;
		case	__DNS_FORMAT_ERROR	: 
			printf("* * DNS FORMAT ERROR ( %u ) * *\n",ecode); 
			printf("    The name server was unable to interpret the Query.\n");
			break;
		case	__DNS_SERVER_ERROR	: 
			printf("* * DNS SERVER ERROR ( %u ) * *\n",ecode); 
			printf("    The name server was unable to process this query,\n");
			printf("    due to a problem with the name server.\n");
			break;
		case	__DNS_NAME_ERROR  	: 
			printf("* * DNS NAME ERROR ( %u ) * *\n",ecode); 
			printf("    Meaningful only for responses from an authoritative\n");
			printf("    name server, this code signifies that the domain name\n");
			printf("    referenced in the query does not exist.\n");
			break;
		case	__DNS_NOT_POSSIBLE	: 
			printf("* * DNS NOT POSSIBLE ( %u ) * *\n",ecode); 
			printf("    The name server does not support the requested\n");
			printf("    kind of query.\n");
			break;
		case	__DNS_REFUSAL		: 
			printf("* * DNS REFUSAL ( %u ) * *\n",ecode); 
			printf("    The name server refuses to perform the specified\n");
			printf("    operation for policy reasons. For example a name\n");
			printf("    server may not wish to provide the information to\n");
			printf("    the particular requester, or may not wish to perform\n");
			printf("    a particular operation (e.g zone transfer) for the\n");
			printf("    particular data.\n");
			break;
		default           		: 
			printf("* * DNS UNEXPECTED ERROR CODE ( %u ) * *\n",ecode); 
			break;

		}
	return;
}

PUBLIC	VOID		show_message( mptr, status, msg, cptr )
	DNSMSGPTR	mptr;
	INT		status;
	BPTR		msg;
	CONNECTIONPTR	cptr;
{
	URLPTR		uptr=(URLPTR) 0;
	if ( mptr->Header.Flags & __DNS_QR )
		printf("DNS Response ID %d",mptr->Header.identity);
	else	printf("DNS Request  ID %d",mptr->Header.identity);

	if ((  msg != (BPTR) 0 )
	&&  ( cptr != (CONNECTIONPTR) 0)
	&&  ((uptr = cptr->remote) != (URLPTR) 0))
		printf(", %s %s ",msg,socketname((ADDRPTR) & uptr->address[uptr->adrindex] ));

	switch ( mptr->Header.qCode ) {
		case	__DNS_QUERY   : printf(", Query   "); break;
		case	__DNS_IQUERY  : printf(", Inverse "); break;
		case	__DNS_STATUS  : printf(", Status  "); break;
		default		      : printf(", qC:0x%X",mptr->Header.qCode);  break;
		}

	if ( mptr->Header.Flags & __DNS_RD )
		printf(", RD");
	if ( mptr->Header.Flags & __DNS_RA )
		printf(", RA");
	if ( mptr->Header.Flags & __DNS_TC )
		printf(", TC");
	if ( mptr->Header.Flags & __DNS_AA )
		printf(", AA");

	show_dns_error( (mptr->Header.rCode & __DNS_RCODE) );

	if ( status & 2 )
	       printf("    Questions=%d, Answers=%d, Authority=%d, Additional=%d \n",
				mptr->Header.Questions,
				mptr->Header.Answers,
				mptr->Header.Authority,
				mptr->Header.Additional);

	if ( status & 4 ) {
		if ( mptr->Header.Questions ) {
			printf("    QUESTIONS  %d \n",mptr->Header.Questions);
			show_questions( mptr->Questions );
			}
		if ( mptr->Header.Answers   ) {
			printf("    ANSWERS    %d \n",mptr->Header.Answers  );
			show_records( mptr->Answers );
			}
		if ( mptr->Header.Authority ) {
			printf("    AUTHORITY  %d \n",mptr->Header.Authority);
			show_records( mptr->Authority );
			}
		if ( mptr->Header.Additional) {
			printf("    ADDITIONAL %d \n",mptr->Header.Additional);
			show_records( mptr->Additional );
			}
		}
	return;
}

VOID		show_data( dptr )
DNSDATAPTR	dptr;
{
	BPTR	sptr;
	INT	i;

	if ( dptr != (DNSDATAPTR) 0 ) {
		printf("\t");
		show_dns_typed_data( dptr->type, dptr->size, dptr->data );
		printf("\n");

		}
	return;
}

VOID		show_node( nptr )
DNSNODEPTR	nptr;
{

	DNSDATAPTR	dptr;

	if ( nptr != (DNSNODEPTR) 0) {
		show_record_name( nptr->name );
		show_dns_class( nptr->class );
		printf(", DOB %lu",nptr->dob);
		if ( node_still_live( nptr ) )
			show_ttl( nptr->ttl );
		else    printf(", *EXPIRED* \n");
		if ((dptr = nptr->rr) != (DNSDATAPTR) 0) {
			do	{
				show_data( dptr );
				}
			while ((dptr = dptr->next) != (DNSDATAPTR) 0);
			}
		}
	return;
}

VOID		show_soa( hptr )
DNSSOAPTR	hptr;
{
	show_record_name( hptr->name );
	show_dns_class( hptr->class );
	show_dns_type( hptr->type );
	show_record_name( hptr->host );
	show_record_name( hptr->mail );
	printf(" %lu",hptr->serial);
	printf(" %lu",hptr->refresh);
	printf(" %lu",hptr->retry);
	printf(" %lu",hptr->expire);
	printf(" %lu\n",hptr->minimum);
	return;
}

VOID		show_host( hptr )
DNSHOSTPTR	hptr;
{
	if ( hptr != (DNSHOSTPTR) 0) {
		if ( hptr->address != (BPTR) 0 ) 
			printf("\t%s\t",hptr->address);
		else	printf("\tdns://0.0.0.0/\t");
		printf(" :-) ");
		show_record_name( hptr->domain );
		printf("(-: ");
		if ( hptr->status )
			printf(" DONE\n");
		else	printf(" PENDING\n");
		}
	return;
}

VOID		show_hosts( hptr )
DNSHOSTPTR	hptr;
{
	if ( hptr != (DNSHOSTPTR) 0) {
		printf("DNS RESOLVER HOST(s) \n");
		while ( hptr != (DNSHOSTPTR) 0) {
			show_host( hptr );
			hptr = hptr->next;
			}
		}
	return;
}	

VOID		show_cache( cptr, message )
DNSCACHEPTR	cptr;
BPTR		message;
{
	INT		h,n;
	DNSNODEPTR	nptr;
	printf("DNS MEMORY : %s \n",message);
	if ( cptr != (DNSCACHEPTR) 0 )  {
		if ( cptr->Header != (DNSSOAPTR) 0) 
			show_soa( cptr->Header );
		for ( h = 0; h < DNS_HASH; h++ ) {
			if ((nptr = cptr->Table[h]) != (DNSNODEPTR) 0) {
				n = 0;
				do	{
					show_node( nptr );
					}
				while ( (nptr = nptr->next ) != (DNSNODEPTR) 0);
				}
			}

		}
	return;

}

PUBLIC	VOID		show_forward( fptr )
	DNSFWDPTR	fptr;
{
	if ( fptr != (DNSFWDPTR) 0 ) {
		printf("\tReferal id=%u, dob=%lu",fptr->identity,fptr->dob);
		show_ttl( fptr->ttl );
		printf("\n");
		}
	return;
}


#endif	/* _DNSVIS_C */
	/* --------- */


