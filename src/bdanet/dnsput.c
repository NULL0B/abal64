#ifndef	_DNSPUT_C
#define	_DNSPUT_C

PRIVATE	DNSBUFFERPTR	Transmit=(DNSBUFFERPTR) 0;

PRIVATE	VOID	dns_putb( v )
INT		v;
{
	if (Transmit->indent < Transmit->length )
		*( Transmit->buffer + (Transmit->indent++) ) = (BYTE) (v & 0x00FF);
	return;
}

PRIVATE	VOID	dns_putw( v )
INT	v;
{
	dns_putb( ((v >> 8) & 0x00FF));
	dns_putb( (v  & 0x00FF));
	return;
}

PRIVATE	VOID	dns_putl( l )
LONG l;
{
	INT i;
	i = (INT) (l >> 16);
	dns_putw( i );
	i = (INT) l;
	dns_putw( i );
	return;
}

PRIVATE	VOID	dns_put( bptr, blen )
BPTR	bptr;
INT	blen;
{
	while ( blen > 0 ) {
		dns_putb( *(bptr++) );
		blen--;
		}
	return;
}

PRIVATE	VOID	dns_put_records( nombre, rptr )
INT		nombre;
DNSRRPTR	rptr;
{
	while ( nombre ) {
		if ( rptr == (DNSRRPTR) 0 )
			break;
		if ( rptr->name != (BPTR) 0)
			dns_put(  rptr->name, strlen( rptr->name ));
		dns_putb( 0 );
		dns_putw(  rptr->type );
		dns_putw(  rptr->class );
		dns_putl(  rptr->ttl );
		dns_putw(  rptr->length );
		if ((rptr->length != 0) && ( rptr->data != (BPTR) 0 ))
			dns_put(  rptr->data, rptr->length );
		rptr = rptr->next;
		nombre--;
		}
	return;
}

PRIVATE	VOID	dns_put_questions( nombre, qptr )
INT		nombre;
DNSQUESTPTR	qptr;
{
	while ( nombre ) {
		if ( qptr == (DNSRRPTR) 0 )
			break;
		if ( qptr->name != (BPTR) 0)
			dns_put(  qptr->name, strlen( qptr->name ));
		dns_putb( 0 );
		dns_putw(  qptr->type );
		dns_putw(  qptr->class );
		qptr = qptr->next;
		nombre--;
		}
	return;
}

PRIVATE	VOID	dns_put_header( hptr )
DNSHEADPTR	hptr;
{
	dns_putw(  hptr->identity );
	dns_putw(  hptr->rCode );
	dns_putw(  hptr->Questions );
	dns_putw(  hptr->Answers   );
	dns_putw(  hptr->Authority );
	dns_putw(  hptr->Additional);
	return;
}

PRIVATE	INT	record_block_size( rptr, mptr )
DNSRRPTR	rptr;
DNSMSGPTR	mptr;
{
	INT	nombre=0;
	if ( rptr != (DNSRRPTR) 0) {
		do	{
			nombre++;
			mptr->TransferLength += (rptr->length + 11);
			if (rptr->name != (BPTR) 0) 
				mptr->TransferLength += strlen(rptr->name);
			}
		while ((rptr = rptr->next) != (DNSRRPTR) 0 );
		}
	return( nombre );
}

PUBLIC	VOID	dns_put_message( cptr, mptr, status )
CONNECTIONPTR	cptr;
DNSMSGPTR	mptr;
INT		status;
{
	DNSQUESTPTR	qptr;
	DNSRRPTR	rptr;
	INT		l=0;
	INT		bmax=0;
	mptr->TransferLength  = 12;
	mptr->Header.rCode    = status;
	mptr->Header.rCode   |= mptr->Header.Flags;
	mptr->Header.Flags    = (mptr->Header.rCode & __DNS_FLAGS);
	mptr->Header.Questions = 0;
	if ((qptr = mptr->Questions) != (DNSQUESTPTR) 0 ) {
		do	{
			mptr->Header.Questions++;
			mptr->TransferLength += 5;
			if (qptr->name != (BPTR) 0) 
				mptr->TransferLength += strlen(qptr->name);
			}
		while ((qptr = qptr->next) != (DNSQUESTPTR) 0 );
		}

	mptr->Header.Answers = record_block_size( mptr->Answers, mptr );
	mptr->Header.Authority = record_block_size( mptr->Authority, mptr );
	mptr->Header.Additional = record_block_size( mptr->Additional, mptr );
		
	if ( cptr->status & _URL_DATAGRAM )
		bmax = mptr->TransferLength;
	else	bmax = (mptr->TransferLength+2);

	if ((Transmit = allocate_for_buffer( bmax )) != (DNSBUFFERPTR) 0) {

		if (!( cptr->status & _URL_DATAGRAM ))
			dns_putw( mptr->TransferLength );

		dns_put_header( (DNSHEADPTR) &mptr->Header );
		dns_put_questions( mptr->Header.Questions, mptr->Questions );
		dns_put_records( mptr->Header.Answers, mptr->Answers );
		dns_put_records( mptr->Header.Authority, mptr->Authority );
		dns_put_records( mptr->Header.Additional, mptr->Additional );

		if ( verbose ) 
			show_message( mptr, verbose, "To", cptr  );

		if ( cptr->status & _URL_DATAGRAM )
			(VOID) udp_write( cptr->socket, Transmit->buffer,Transmit->length, cptr->remote );
		else	(VOID) tcp_write( cptr->newsocket, Transmit->buffer,Transmit->length );
		
		Transmit = liberate_for_buffer( Transmit );

		}
	return;
}

#endif	/* _DNSPUT_C */
	/* --------- */




