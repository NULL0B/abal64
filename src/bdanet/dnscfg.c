#ifndef	_DNSCFG_C
#define	_DNSCFG_C

#include "dnscfg.h"

PRIVATE	WORD		DnsHosts=0;
PRIVATE	BPTR		DnsHost[__DNS_MAX_HOSTS];
PRIVATE	WORD		DnsTimeOut=5;
PRIVATE	WORD		DnsRetries=5;
PRIVATE	INT		DnsRecursive=__DNS_RD;
PRIVATE	INT		DnsTransport=__URL_UDP;
PRIVATE	DNSCFGPTR	GlobalDnsConfig=(DNSCFGPTR) 0;

PRIVATE	int		copy_dns_configuration( DNSCFGPTR tptr, DNSCFGPTR sptr );

#include "dnsuser.c"

PRIVATE	INT	use_dns_configuration( DNSCFGPTR	gptr )
{
	int	i;
	int	l;
	int	n;
	for (	i=0; i < DnsHosts; i++ ) {
		liberate( DnsHost[i] );
		DnsHost[i] = (BPTR) 0;
		}
	DnsHosts = 0;
	if ((n = gptr->nbaddr) > __DNS_MAX_HOSTS )	
		n = __DNS_MAX_HOSTS;

	for (	i=0; i < n; i++ )
		dns_set_host( & gptr->address[i] );

	if ( gptr->recursive )
		DnsRecursive = 0;
	else	DnsRecursive = __DNS_RD;
	DnsTimeOut = gptr->timeout;
	DnsRetries = gptr->retries;
	switch ( gptr->transport ) {
		case	1 : DnsTransport = __URL_TCP; break;
		case	0 : DnsTransport = __URL_UDP; break;
		case	2 : DnsTransport = __URL_RAW; break;
		}
	return(0);
}

PRIVATE	INT	read_dns_configuration( DNSCFGPTR	gptr )
{
	int	i;
	int	x;
	int	v;
	int	l;
	char *	aptr;
	char *	bptr;

	for (	i=0; i < gptr->nbaddr; i++ )
		gptr->address[i] = 0L;

	for (	i=0; i < DnsHosts; i++ ) {
		if ((aptr = DnsHost[i]) != (char *) 0) {
			aptr += 5;
			bptr = (BPTR) & gptr->address[i];
			for ( x=0; x < 4; x++ ) {
				v = 0;
				while (( *aptr >= '0' ) && ( *aptr <= '9'))
					v = ((v * 10) + (*(aptr++) - '0'));
				if ( *aptr == '.' )
					aptr++;
				*(bptr +x) = v;
				}
			}
		}

	if ( DnsRecursive  == __DNS_RD )
		gptr->recursive = 0;
	else	gptr->recursive = 1;
	gptr->timeout = DnsTimeOut;
	gptr->retries = DnsRetries;
	if ( DnsTransport == __URL_TCP )
		gptr->transport = 1;
	else if ( DnsTransport ==  __URL_UDP )
		gptr->transport = 0;
	else	gptr->transport = 2;

	return(0);
}

PRIVATE	int	copy_dns_configuration( DNSCFGPTR tptr, DNSCFGPTR  sptr)
{
	int	status=118;
	int	nbaddr;
	int	i;
	if ((tptr) && (sptr)) {
		tptr->timeout = sptr->timeout;
		tptr->retries = sptr->retries;
		tptr->transport = sptr->transport;
		tptr->recursive = sptr->recursive;
		if ( tptr->nbaddr < sptr->nbaddr ) {
			nbaddr = tptr->nbaddr;
			status = 63;
			}
		else	{
			nbaddr = sptr->nbaddr;
			status = 0;
			}
		for (	i=0;
			i < nbaddr;
			i++ )
			tptr->address[i] = sptr->address[i];

		tptr->report = sptr->nbaddr;

		while ( nbaddr < tptr->nbaddr )
			tptr->address[nbaddr++]=0L;

		}
	return( status );
}

PUBLIC 	int		put_dns_configuration( DNSCFGPTR dptr )
{
	int	status=0;
	DNSCFGPTR gptr;
	if (!( dptr ))
		return( 118 );
	if ((!(gptr = GlobalDnsConfig))
	&&  (!(gptr = allocate_dns_configuration( dptr->nbaddr ))))
		return( 27 );
	else 	{
		if (gptr->nbaddr != dptr->nbaddr) {
			if (!(gptr = allocate_dns_configuration( dptr->nbaddr )))
				return( 27 );
			else	GlobalDnsConfig = liberate_dns_configuration( GlobalDnsConfig );
			}
		if ((status = copy_dns_configuration( GlobalDnsConfig=gptr, dptr )) != 0)
			return( status );
		else	return( use_dns_configuration( GlobalDnsConfig ) );
		}
}

PUBLIC	int		get_dns_configuration( DNSCFGPTR dptr )
{
	int	status;
	if (!( dptr ))
		return( 118 );
	else if (!( GlobalDnsConfig )) {
		if (!( GlobalDnsConfig = allocate_dns_configuration( DnsHosts )))
			return( 27 );
		else if ((status = read_dns_configuration( GlobalDnsConfig )) != 0)
			return( status );
		}
	return( copy_dns_configuration( dptr, GlobalDnsConfig ) );
}

#endif	/* _DNSCFG_C */
	/* --------- */







