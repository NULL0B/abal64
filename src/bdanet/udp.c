
#ifndef	_UDP_C
#define	_UDP_C

PUBLIC 	INT	udp_write( handle, bptr, blen, aptr )
	INT		handle;
	BPTR		bptr;
	INT		blen;
	URLPTR 		aptr;
{
	return((blen = sendto( handle, bptr, blen , 0, (ADDRPTR)& aptr->address[aptr->adrindex], sizeof( ADDRESS ))));
}

PUBLIC	INT	udp_read( handle, bptr, blen, aptr)
	INT	handle;
	BPTR	bptr;
	INT	blen;
	URLPTR 	aptr;
{
	INT	alen=sizeof( ADDRESS );
	return((blen = recvfrom( handle, bptr, blen , 0,(ADDRPTR)& aptr->address[aptr->adrindex], (IPTR) & alen )));
}

PUBLIC	INT	udp_peek( handle, aptr )
	INT	handle;
	URLPTR 	aptr;
{
	INT	alen=sizeof( ADDRESS );
	BYTE	buffer[16];
	return(recvfrom( handle,(BPTR) buffer, 16, MSG_PEEK,(ADDRPTR) & aptr->address[aptr->adrindex], (IPTR) & alen ));
}

#endif	/* _UDP_C */
	/* ------ */




