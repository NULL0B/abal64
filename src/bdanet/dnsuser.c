#ifndef	_DNSUSER_C
#define	_DNSUSER_C

#include "dnscfg.h"

PUBLIC	DNSCFGPTR	liberate_dns_configuration( DNSCFGPTR dptr )
{
	if ( dptr ) 
		liberate( dptr );
	return((DNSCFGPTR) 0);
}

PUBLIC	DNSCFGPTR	allocate_dns_configuration(int nbaddr)
{
	DNSCFGPTR	dptr;

	if (!( nbaddr )) nbaddr++;
	
	if ((dptr = (DNSCFGPTR) allocate( 
		(sizeof( DNSCFG ) + ((nbaddr - 1) * sizeof( unsigned long )))
		)) != (DNSCFGPTR) 0) {
		dptr->report=dptr->timeout=dptr->retries=dptr->transport=dptr->recursive=0;
		for ( 	dptr->nbaddr=0; 
			dptr->nbaddr < nbaddr;
			dptr->nbaddr++ ) 
			dptr->address[dptr->nbaddr] = 0L;
		}
	return( dptr );
}

#ifndef	_DNSCFG_C

PUBLIC	int		get_dns_configuration( DNSCFGPTR dptr )
{
	// This stub function will build the system descriptor
	// and call the system function but for now ....
	return( 56 );
}

PUBLIC 	int		put_dns_configuration( DNSCFGPTR dptr )
{
	// This stub function will build the system descriptor
	// and call the system function but for now ....
	return( 56 );
}

PUBLIC	int	resolve_hosts_by_name(
	char *  nptr,
	char *  aptr,
	int	nbaddr)	
{
	// This stub function will build the system descriptor
	// and call the system function but for now ....
	return(56);
}
#endif

#endif	/* _DNSUSER_C */

