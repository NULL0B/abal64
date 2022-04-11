#ifndef	_URL_H
#define	_URL_H

#define	SERVICE		struct url_service
#define	SERVICENODE	struct url_service_node
#define	SERVICELIST	struct url_service_list
#define	URL		struct url_descriptor
#define	SERVICEPTR	SERVICE PTR
#define	SERVICENODEPTR	SERVICENODE PTR
#define	SERVICELISTPTR	SERVICELIST PTR
#define	URLPTR		URL PTR

#include "connect.h"

#define	_MAX_HEADERS	 32
#define	_MAX_URL_HOST	256
#define	_MAX_URL_OBJECT	512
#define	_MAX_LABEL	 63
#define	_MAX_URL_ADDR	 16

SERVICE	{
	INT	nature;				/* Allocated / Static 	*/
	BYTE	name[_MAX_LABEL];		/* Name of the service	*/
	INT  	(PTR parse) (BPTR,URLPTR);	/* Service Parser	*/
	INT  	(PTR client) (URLPTR,INT,BPTR);	/* Service Operation	*/
	};

SERVICENODE	{
	SERVICEPTR	contents;		/* This Service		*/
	SERVICENODEPTR	next;			/* Next List Node	*/
	SERVICENODEPTR	previous;		/* Previous List Node	*/
	};

SERVICELIST	{
	INT		services;		/* Number of services	*/
	SERVICENODEPTR	first;			/* First Service Item	*/
	SERVICENODEPTR	last;			/* Last Service Item	*/
	};


URL	{
	INT 		status;			/* Status of Descriptor	*/
	INT		transport;		/* TCP/VC or UDP/DG	*/
	SERVICEPTR	service;		/* Attributed Service	*/
	INT 		port;			/* Service Port		*/
	INT 		base;			/* Default Base Port	*/
	LONG		explicite;		/* Explicite IP Address	*/
	BPTR		althost;		/* Alternative HostName	*/
	BYTE		host[_MAX_URL_HOST];	/* Service Host		*/
	BYTE		path[_MAX_URL_OBJECT];	/* Object Name		*/
	INT		maxadr;			/* Number of Address	*/
	INT		adrindex;		/* Current Connected	*/
	ADDRESS	        address[_MAX_URL_ADDR];	/* URL IP Address Table	*/
	INT		headers;		/* Addition fieldcount	*/
	BPTR		header[_MAX_HEADERS];	/* Addition Mime Fields	*/
	};

#define	_INVALID_URL_SERVICE	 	0x0010
#define	_INVALID_URL_HOST		0x0020
#define	_INVALID_URL_PATH		0x0040

#define	_URL_IS_SERVICE	 	 	0x0001
#define	_URL_IS_HOST		 	0x0002
#define	_URL_IS_PATH		 	0x0004

#define	_INVALID_URL			0x00F0

#define	_URL_RESOLVED			0x0100
#define	_URL_SOCKET  			0x0200
#define	_URL_BOUND   			0x0400
#define	_URL_CONNECT 			0x0800
#define	_URL_LISTEN  			0x1000
#define	_URL_ACCEPT  			0x2000
#define	_URL_DATAGRAM			0x4000
#define	_URL_COPY    			0x8000

#define	__URL_TCP			SOCK_STREAM
#define	__URL_UDP			SOCK_DGRAM
#define	__URL_RAW			SOCK_RAW

PUBLIC	INT	verify_url( URLPTR, ADDRPTR );
PUBLIC	VOID	normalise_url( BPTR );
PUBLIC	VOID	localise_url( BPTR );

PUBLIC	INT	initialise_url_services();
PUBLIC	INT	add_url_service( SERVICEPTR );

PUBLIC	URLPTR	allocate_for_url( BPTR,LONG );
PUBLIC	URLPTR	copy_url( URLPTR );
PUBLIC	BPTR	interpret_url( URLPTR );
PUBLIC	VOID	url_copy_object( URLPTR, URLPTR );


PUBLIC	INT	parse_url( BPTR, URLPTR );
PUBLIC	INT	service_url( URLPTR, INT, BPTR[] );
PUBLIC	INT	default_service_client( URLPTR, INT, BPTR[] );

PUBLIC	URLPTR	liberate_for_url( URLPTR );

PUBLIC	INT	drop_url_service( BPTR );
PUBLIC	INT	liberate_url_services();

PUBLIC	VOID	show_url( URLPTR );
PUBLIC	INT 	parse_url_host( BPTR, URLPTR );
PUBLIC	WORD	url_set_alt_host( URLPTR, BPTR );
PUBLIC	WORD	url_set_alt_header( URLPTR, BPTR );

#endif  /* _URL_H */
	/* ------ */






































































































































