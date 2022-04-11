#ifndef	_DNS_H
#define	_DNS_H

#define __DNS_PORT	53
#define	__DNS_PREFIX	"dns:"

#define	__DNS_PRIMARY	"dns://000.000.000.000\0"
#define	__DNS_MAX_HOSTS	10

/*	--------------------------	*/
/*	DNS RESSOURCE RECORD TYPES	*/
/*	--------------------------	*/

#define	__DNS_TYPE_A		1	/* ADDRESS			*/
#define	__DNS_TYPE_NS		2	/* NAME SERVER			*/
#define	__DNS_TYPE_MD		3	/* OBSOLETE MAIL DELIVER  	*/
#define	__DNS_TYPE_MF		4	/* OBSOLETE MAIL FORWARD  	*/
#define	__DNS_TYPE_CNAME	5	/* CANONICAL NAME		*/
#define	__DNS_TYPE_SOA  	6	/* START OF AUTHORITY		*/
#define	__DNS_TYPE_MB		7	/* EXPERIMENTAL MAIL BOX  	*/
#define	__DNS_TYPE_MG		8	/* EXPERIMENTAL MAIL GROUP	*/
#define	__DNS_TYPE_MR		9	/* EXPERIMENTAL MAIL ALIAS 	*/
#define	__DNS_TYPE_NULL		10	/* EXPERIMENTAL NULL DATA 	*/
#define	__DNS_TYPE_WKS  	11	/* WELL KNOWN SERVICE		*/
#define	__DNS_TYPE_PTR  	12	/* POINTER			*/
#define	__DNS_TYPE_HINFO	13	/* HOST INFORMATION		*/
#define	__DNS_TYPE_MINFO	14	/* MAIL INFORMATION		*/
#define	__DNS_TYPE_MX   	15	/* MAIL EXCHANGE		*/
#define	__DNS_TYPE_TXT  	16	/* TEXT				*/

#define	__DNS_QTYPE_AXFR	252	/* REQUEST FOR TRANSFER		*/
#define	__DNS_QTYPE_MAILB	253	/* REQUEST FOR MAIL TRANSFER	*/
#define	__DNS_QTYPE_ANY 	255	/* ANY / ALL TYPES		*/

#define	__DNS_CLASS_IN	1
#define	__DNS_CLASS_CS	2
#define	__DNS_CLASS_CH	3
#define	__DNS_CLASS_HS	4
#define	__DNS_CLASS_ANY	255


#define	__DNS_OPCODE	0x7800		/* Opcode extraction mask	*/
#define	__DNS_QUERY	0
#define	__DNS_IQUERY	1
#define	__DNS_STATUS	2

#define	__DNS_QR      	0x8000		/* Query or Response		*/
#define	__DNS_AA	0x0400		/* Authoritative Answer		*/
#define	__DNS_TC	0x0200		/* Truncation			*/
#define	__DNS_RD	0x0100		/* Recursion Desired (query)	*/
#define	__DNS_RA	0x0080		/* Recursion Available (reply)	*/

#define	__DNS_FLAGS	(__DNS_QR | __DNS_AA | __DNS_TC | __DNS_RD | __DNS_RA )

#define	__DNS_ZERO	0x0070		/* Reserved and must be Zero	*/

#define	__DNS_RCODE	0x000F		/* Response Code             	*/
#define	__DNS_NO_ERROR		0x0000	/* No error condition		*/
#define	__DNS_FORMAT_ERROR	0x0001	/* Unable to understand msg	*/
#define	__DNS_SERVER_ERROR	0x0002	/* Name server Failure     	*/
#define	__DNS_NAME_ERROR  	0x0003	/* Inexistant Domain Name  	*/
#define	__DNS_NOT_POSSIBLE	0x0004	/* Does not offer this service	*/
#define	__DNS_REFUSAL		0x0005	/* Refused to honour service	*/

#define	__DNS_MESSAGE_ERROR	0x1000	/* Zero length message received */
#define	__DNS_MEMORY_ERROR	0x1001	/* Allocation Failure  for msg  */
#define	__DNS_RECEIVE_ERROR	0x1002	/* Cannot receive all message   */

#define		DNS_HASH 23

#define	DNSBUFFER		struct dns_buffer
#define	DNSHEAD			struct dns_header_record
#define	DNSQUEST		struct dns_question_record
#define	DNSRR  			struct dns_ressource_record
#define	DNSNODE			struct dns_name_node
#define	DNSDATA			struct dns_record
#define	DNSHOST			struct dns_host
#define	DNSMSG 			struct dns_message
#define	DNSCACHE  		struct dns_cache
#define	DNSCONTEXT		struct dns_context
#define	DNSSOA			struct dns_soa
#define DNSRCV			struct dns_receive
#define DNSFWD			struct dns_forward

#define	DNSHEADPTR		DNSHEAD PTR
#define	DNSQUESTPTR		DNSQUEST PTR
#define	DNSRRPTR		DNSRR PTR
#define	DNSNODEPTR		DNSNODE PTR
#define	DNSDATAPTR		DNSDATA PTR
#define	DNSMSGPTR		DNSMSG PTR
#define	DNSCACHEPTR		DNSCACHE PTR
#define	DNSCONTEXTPTR		DNSCONTEXT PTR
#define	DNSSOAPTR		DNSSOA PTR
#define	DNSHOSTPTR		DNSHOST PTR
#define	DNSBUFFERPTR		DNSBUFFER PTR
#define	DNSRCVPTR		DNSRCV PTR
#define	DNSFWDPTR		DNSFWD PTR

DNSBUFFER	{
	BPTR	buffer;
	INT	length;
	INT	indent;
	};

DNSHOST		{
	INT	status;
	BPTR	address;
	BPTR	domain;
	BPTR	next;
	};

DNSHEAD 	{
	INT	identity;
	INT	qCode;
	INT	rCode;
	INT	Flags;
	INT	Questions;
	INT	Answers;
	INT	Authority;
	INT	Additional;
	};

DNSQUEST	{
	BPTR		name;
	INT		type;
	INT		class;
	DNSQUESTPTR	next;
	};

DNSRR		{
	BPTR		name;
	INT		type;
	INT		class;
	LONG		ttl;
	LONG		dob;
	INT		length;
	BPTR		data;
	INT		nature;
	DNSRRPTR	next;
	};

DNSNODE		{
	BPTR		name;
	INT		class;
	LONG		ttl;
	LONG		dob;
	DNSDATAPTR	rr;
	DNSNODEPTR	next;
	DNSNODEPTR	prev;
	};

DNSDATA	{
	INT		type;
	DNSDATAPTR	next;
	INT		size;
	BYTE		data[4];
	};


DNSMSG	{
	INT		TransferLength;
	DNSHEAD		Header;
	DNSQUESTPTR 	Questions;
	DNSRRPTR 	Answers;
	DNSRRPTR 	Authority;
	DNSRRPTR 	Additional;
	};

DNSSOA	{
	BPTR		name;
	INT		class;
	INT		type;
	BPTR		host;
	BPTR		mail;
	LONG		dob;
	LONG		serial;
	LONG		ttl;
	LONG		refresh;
	LONG		retry;
	LONG		expire;
	LONG		minimum;
	};

DNSCACHE	{
	DNSSOAPTR	Header;
	INT		Locked;
	INT		Distribution[DNS_HASH];
	DNSNODEPTR	Table[DNS_HASH];
	};

DNSCONTEXT	{
	BPTR		Master;
	DNSCACHEPTR	Authority;
	DNSCACHEPTR	Cache;
	BYTE		Origin[256];
	INT		CacheHits;
	INT		CacheMiss;
	};


DNSRCV	{
	INT		identity;
	INT		usage;
	INT		status;
	DNSMSGPTR	message;
	VPTR		connection;
	};

DNSFWD	{
	LONG		ttl;
	LONG		dob;
	INT		identity;
	VPTR		url;
	VPTR		connection;
	DNSMSGPTR	message;
	DNSRCVPTR	reason;
	DNSFWDPTR	next;
	DNSFWDPTR	previous;
	};
	
#ifdef	_DNS_C
PUBLIC	INT	recursive=(__DNS_RD | __DNS_RA);
#else
EXTERN	INT	recursive;
#endif

PUBLIC	INT	resolve_dns_class( BPTR );
PUBLIC	INT	resolve_dns_type( BPTR );
PUBLIC	INT	initialise_dns_service( VOID );
PUBLIC	INT	dns_add_host( BPTR );
PUBLIC	INT	dns_set_recursive( BPTR );
PUBLIC 	INT 	dns_set_timeout( BPTR );

#endif	/* _DNS_H */
	/* ------ */


