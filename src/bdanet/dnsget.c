#ifndef	_DNSGET_C
#define	_DNSGET_C

PRIVATE	DNSBUFFERPTR	Receive=(DNSBUFFERPTR) 0;

PRIVATE	INT	dns_getb()
{
	if ( Receive->indent < Receive->length )
		return( ( *( Receive->buffer + (Receive->indent++) ) & 0x00FF ) );
	else	return( 0 );
}

PRIVATE	INT	dns_getw()
{
	 INT	v;
	v = dns_getb();
	v <<= 8; v &= 0xFF00;
	v |= dns_getb();
	return( (v & 0xFFFF) );
}

PRIVATE	LONG	dns_getl()
{
	LONG	r;
	INT	v;
	v = dns_getw();
	r = (( LONG) v << 16);
	v = dns_getw();
	r += (( LONG) v);
	return( r );
}

PRIVATE	INT	dns_get( bptr, blen )
BPTR		bptr;
INT		blen;
{
	while ( blen > 0 ) {
		*(bptr++) = dns_getb();
		blen--;
		}
	return( blen );
}

PRIVATE	INT 	dns_get_header( mptr )
DNSMSGPTR	mptr;
{
	BPTR	zptr;

	mptr->Header.identity 	  = dns_getw();
	mptr->Header.rCode    	  = dns_getw();
	mptr->Header.Questions   = dns_getw();
	mptr->Header.Answers     = dns_getw();
	mptr->Header.Authority   = dns_getw();
	mptr->Header.Additional  = dns_getw();
	mptr->Header.Flags 	  = (mptr->Header.rCode & __DNS_FLAGS);
	mptr->Header.qCode 	  = ((mptr->Header.rCode & __DNS_OPCODE) >> 11);
	return((mptr->Header.rCode 	 &= 0x000F));
}

PRIVATE	INT	resolve_compression( nptr, offset, nombre )
BPTR		nptr;
INT		offset;
INT		nombre;
{
	INT	nlen=0;
	BPTR	bptr;
	if ( Receive->buffer != (BPTR) 0 ) {
		bptr = (Receive->buffer + offset);
		while ( (nlen = (*(nptr++) = *(bptr++))) != 0) {
			if ( nlen > 63 ) {
				nptr--;
				nlen = (((nlen & 0x003F) << 8) + (*(bptr++) & 0x00FF));
				return( resolve_compression( nptr, nlen, nombre ) );
				}
			else	{
				nombre++;
				while ((nombre < 256) && ( nlen )) {
					*(nptr++) = *(bptr++);
					nombre++;
					nlen--;
					}
				}
			}
		}
	return( nombre );
}

BPTR	dns_get_name()
{
	BPTR 	nptr;
	BYTE	Buffer[256];
	INT	nombre=0;
	INT	nlen;
	nptr = Buffer;
	while ((nombre < 256) 
	&&     (( *(nptr++) = nlen = dns_getb()) != 0)) {
		/* ------------------------------------ */
		/*    Detect Name Compression Marker    */
		/*    ------------------------------ 	*/
		/* Since domain name components are     */
		/* limited to 63 bytes then a length    */
		/* byte which exceeds this value is     */
		/* a compression flag which indicates   */
		/* that the next byte must be read and  */
		/* combined with the current legal bits */
		/* to provide an offset INTo the input  */
		/* buffer at which the rest of the name */
		/* may be found				*/
		/* ------------------------------------ */
		if ( nlen > 63 ) {
			nptr--;
			nlen = (((nlen & 0x003F) << 8) + (dns_getb() & 0x00FF));
			nombre = resolve_compression( nptr, nlen, nombre );
			break;
			}
		else	{
			/* Normal uncompressed name component */
			/* ---------------------------------- */
			nombre++;
			while ((nombre < 256) && ( nlen )) {
				*(nptr++) = dns_getb();
				nombre++;
				nlen--;
				}
			}
		}
	if ( nombre < 256 ) {
		Buffer[nombre] = 0;
		if ((nptr = (BPTR) allocate_zone( (nombre+1) )) != (BPTR) 0) {
			strcpy( nptr, Buffer );
			return( nptr );
			}
		}
	return( (BPTR) 0 );
}

DNSQUESTPTR	dns_get_questions( nombre )
INT		nombre;
{
	DNSQUESTPTR	pptr=(DNSQUESTPTR) 0;
	DNSQUESTPTR	qptr;
	BPTR		nptr;
	INT		nlen;
	while ( nombre ) {
		if ((qptr = allocate_for_question()) == (DNSQUESTPTR) 0)
			break;
		qptr->next = pptr;
		pptr = qptr;
		qptr->name = dns_get_name();
		qptr->type  = dns_getw();
		qptr->class = dns_getw();
		nombre--;
		}
	return( qptr );
}

PRIVATE	DNSRRPTR	dns_get_record_mx( rptr )
	DNSRRPTR	rptr;
{
	INT	preference;
	BPTR	exchange;
	BPTR	xptr;
	preference = dns_getw();
	if ((exchange = dns_get_name()) != (BPTR) 0) {
		if ((rptr->data = allocate_zone( (rptr->length = (strlen(exchange) + 3)) )) != (BPTR) 0) {
			xptr = mem_putw((xptr = rptr->data),  preference );
			strcpy( xptr, exchange );
			}
		exchange = liberate_zone( exchange );
		}
	return( rptr );
}

PRIVATE	DNSRRPTR	dns_get_record_soa( rptr )
	DNSRRPTR	rptr;
{
	BPTR	mname=(BPTR) 0;
	BPTR	rname=(BPTR) 0;
	BPTR	xptr;
	INT	i;

	if ((mname = dns_get_name()) != (BPTR) 0) {
		if ((rname = dns_get_name()) != (BPTR) 0) {
			if ((rptr->data = allocate_zone((rptr->length = (strlen(mname)+strlen(rname) + 2 + ( 5 * sizeof( LONG ) ))) )) != (BPTR) 0) {
				strcpy((xptr = rptr->data), mname );
				xptr += (strlen(mname) + 1);
				strcpy( xptr, rname );
				xptr += (strlen(rname) + 1);
				for ( i = 0; i < 5; i++ )
	 				xptr = mem_putl( xptr, dns_getl() );
				}
			else	rptr->length = 0;
			rname = liberate_zone( rname );
			}
		mname = liberate_zone( mname );
		}
	return( rptr );
}

PRIVATE	VOID		dns_get_domain( rptr )
	DNSRRPTR	rptr;
{	
	/* -------------------------------------------- */
	/* This is necessary in order to allow the name */
	/* present in the data to be decompressed !!!!! */
	/* -------------------------------------------- */
	if ((rptr->data = dns_get_name()) != (BPTR) 0)
		rptr->length = strlen( rptr->data ) + 1;
	return;
}

DNSRRPTR	dns_get_records(nombre )
INT		nombre;
{
	DNSRRPTR	pptr=(DNSRRPTR) 0;
	DNSRRPTR	rptr;
	while ( nombre ) {
		if ((rptr = allocate_for_record()) == (DNSRRPTR) 0)
			break;
		rptr->next = pptr;
		pptr = rptr;
		if ((rptr->name = dns_get_name(  )) == (BPTR ) 0)
			break;
		rptr->type   = dns_getw(  );
		rptr->class  = dns_getw(  );
		rptr->ttl    = dns_getl(  );
		if ((rptr->length = dns_getw(  )) != 0) {
			switch ( rptr->type ) {

				/* EXPERIMENTAL TYPES */
				/* ------------------ */
				case __DNS_TYPE_MB	: /* MAIL BOX     */
				case __DNS_TYPE_MR	: /* MAIL RENAME  */
				case __DNS_TYPE_MG	: /* MAIL GROUP   */
				case __DNS_TYPE_MF	: /* MAIL FORWARD */
				case __DNS_TYPE_MD	: /* MAIL DELIVER */
					dns_get_domain( rptr );
					break;

				/* OFFICIAL TYPES */
				/* -------------- */
				case __DNS_TYPE_CNAME :
				case __DNS_TYPE_NS    :
				case __DNS_TYPE_PTR   :
					dns_get_domain( rptr );
					break;
				case __DNS_TYPE_MX    :
					if ((rptr = dns_get_record_mx( rptr )) == (DNSRRPTR) 0)
						return( rptr );
					else	break;
				case __DNS_TYPE_SOA   :
					if ((rptr = dns_get_record_soa( rptr )) == (DNSRRPTR) 0)
						return( rptr );
					else	break;
				default		      :
					/* --------------------------------------------- */
					/* Other types require simple collection of Data */
					/* --------------------------------------------- */
					if ( (rptr->data   = (BPTR) allocate_zone( rptr->length )) != (BPTR) 0)
						dns_get( rptr->data, rptr->length );
				}
			}
		nombre--;
		}
	return( rptr );
}


PUBLIC 	INT	dns_get_message( cptr, mptr )
	CONNECTIONPTR	cptr;
	DNSMSGPTR	mptr;
{

	if ( cptr->status & _URL_DATAGRAM ) {


		/* An ann uine as motha a bhith a'feitheamh */
		/* ---------------------------------------- */
		if ( cptr->timeout != 0 ) {




			}
		if ((Receive = allocate_for_buffer( 512 )) == (DNSBUFFERPTR) 0)
			return( 27 );
		else 	{
			if ((Receive->length = udp_read( 
						cptr->socket, 
						Receive->buffer, 
						Receive->length,
						cptr->remote)) <= 0) {
				Receive = liberate_for_buffer( Receive );
				return( 31 );
				}
			else	mptr->TransferLength = 512;
			}
		}
	else	{
		if ((mptr->TransferLength = tcp_readw( cptr->newsocket )) == 0)
			return( 31 );
		else if ((Receive = allocate_for_buffer( mptr->TransferLength  )) == (DNSBUFFERPTR) 0)
			return( 27 );
		else	Receive->length = tcp_read( cptr->newsocket, Receive->buffer, Receive->length );
		}

	dns_get_header( mptr );

	if ( mptr->Header.Questions )
		mptr->Questions = dns_get_questions( mptr->Header.Questions );
	else	mptr->Questions = (DNSQUESTPTR) 0;

	if ( mptr->Header.Answers )
		mptr->Answers = dns_get_records( mptr->Header.Answers );
	else	mptr->Answers = (DNSRRPTR) 0;

	if ( mptr->Header.Authority )
		mptr->Authority = dns_get_records( mptr->Header.Authority );
	else	mptr->Authority = (DNSRRPTR) 0;

	if ( mptr->Header.Additional )
		mptr->Additional = dns_get_records( mptr->Header.Additional );
	else	mptr->Additional = (DNSRRPTR) 0;

	if ( verbose )
		show_message( mptr, verbose, "From", cptr );

	Receive = liberate_for_buffer( Receive );

	return( mptr->Header.rCode );
}


PUBLIC	DNSRCVPTR	receive_message( cptr, timeout )
	CONNECTIONPTR	cptr;
	INT		timeout;
{
	DNSRCVPTR	rcvptr=(DNSRCVPTR) 0;

	if ((cptr = accept_connection( cptr, timeout )) == (CONNECTIONPTR) 0)
		return( rcvptr );
	else if ((rcvptr = allocate_for_reception(cptr)) == (DNSRCVPTR) 0)
		return( rcvptr );
	else if ( dns_get_message( rcvptr->connection, rcvptr->message ) == 0 )
		return( rcvptr );
	else	return((rcvptr = liberate_for_reception( rcvptr )));

}



#endif	/* _DNSGET_C */
	/* --------- */

