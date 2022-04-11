#ifndef	_DNSMEM_H
#define	_DNSMEM_H

PUBLIC	BPTR		allocate_for_address(ADDRPTR);
PUBLIC	BPTR		string2name(BPTR);
PUBLIC	BPTR		name2string(BPTR);

PUBLIC	DNSBUFFERPTR	liberate_for_buffer( DNSBUFFERPTR );
PUBLIC	DNSBUFFERPTR	allocate_for_buffer( INT );

PUBLIC	DNSQUESTPTR	liberate_for_question( DNSQUESTPTR );
PUBLIC	DNSQUESTPTR	allocate_for_question();
PUBLIC	DNSQUESTPTR	build_question(BPTR,INT,INT);
PUBLIC	DNSQUESTPTR	domain_question(BPTR,INT,INT);

PUBLIC	DNSRRPTR	liberate_for_record(DNSRRPTR);
PUBLIC	DNSRRPTR	allocate_for_record();
PUBLIC	DNSRRPTR	build_record( DNSNODEPTR,DNSDATAPTR);
PUBLIC	DNSRRPTR	duplicate_record( DNSRRPTR);
PUBLIC	DNSRRPTR	liberate_records( DNSRRPTR );

PUBLIC	DNSMSGPTR	liberate_for_message( DNSMSGPTR	);
PUBLIC	DNSMSGPTR	allocate_for_message( );

PUBLIC	DNSDATAPTR	liberate_for_data( DNSDATAPTR );
PUBLIC	DNSDATAPTR	allocate_for_data( INT );

PUBLIC	DNSNODEPTR	liberate_for_node(DNSNODEPTR);
PUBLIC	DNSNODEPTR	allocate_for_node();

PUBLIC	DNSSOAPTR	liberate_for_soa(DNSSOAPTR);
PUBLIC	DNSSOAPTR	allocate_for_soa();

PUBLIC	DNSCACHEPTR	liberate_for_cache(DNSCACHEPTR);
PUBLIC	DNSCACHEPTR	allocate_for_cache();

PUBLIC	DNSCONTEXTPTR	liberate_for_context(DNSCONTEXTPTR);
PUBLIC	DNSCONTEXTPTR	allocate_for_context(BPTR);

PUBLIC	DNSHOSTPTR	liberate_for_host(DNSHOSTPTR);
PUBLIC	DNSHOSTPTR	allocate_for_host();
PUBLIC	DNSHOSTPTR	build_host(BPTR,ADDRPTR,BPTR);

PUBLIC	DNSRCVPTR	liberate_for_reception( DNSRCVPTR );
PUBLIC	DNSRCVPTR	allocate_for_reception( CONNECTIONPTR );
PUBLIC	DNSRCVPTR	receive_message( CONNECTIONPTR, INT );

PUBLIC	DNSFWDPTR	liberate_for_forward( DNSFWDPTR	);
PUBLIC	DNSFWDPTR	allocate_for_forward();

PUBLIC 	BPTR	mem_putw(BPTR,INT);
PUBLIC 	BPTR	mem_putl(BPTR,LONG);
PUBLIC 	INT	mem_getw(BPTR);
PUBLIC 	LONG	mem_getl(BPTR);


#endif	/* _DNSMEM_H */
	/* --------- */

