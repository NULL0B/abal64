#ifndef	_DNSCFG_H
#define	_DNSCFG_H

#define	DNSCFG 		struct dns_config
#define DNSCFGPTR	DNSCFG PTR

DNSCFG		{

	int	timeout;			/* Time to timeout for message	*/
	int	retries;		/* Number otimes to send and timeout */
	int	transport;		/* 0=UDP,1=TCP			*/
	int	recursive;		/* 0=Yes, 1=No 			*/
	int	report;			/* Will indicate return info	*/
	int	nbaddr;			/* Number of address' in buffer	*/
	unsigned long address[1];	/* Buffer of address'		*/

	};


#ifndef	PUBLIC
#define	PUBLIC
#endif

PUBLIC	DNSCFGPTR	allocate_dns_configuration(int nbaddr);
PUBLIC	DNSCFGPTR	liberate_dns_configuration( DNSCFGPTR dptr );
PUBLIC	int		put_dns_configuration( DNSCFGPTR dptr );
PUBLIC	int		get_dns_configuration( DNSCFGPTR dptr );

#endif	/* _DNSCFG_H */
	/* --------- */




