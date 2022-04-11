#ifndef	_RESOLVER_H
#define	_RESOLVER_H

#include "basic.h"
#include "address.h"
#include "global.h"
#include "url.h"
#include "dns.h"
#include "http.h"
#include "trace.h"
#include "server.h"

#ifdef	_HTTPS_C


#define	__HTTPS_CONFIG (BPTR) "https.cfg"

#define	HTTPSTAT	struct http_connection_stats

HTTPSTAT	{
	LONG	StartUpDate;
	LONG	ConnectionCount;
	LONG	SuccessCount;
	LONG	FailureCount;
	};

#define	__HTTP_CMD_FAILURE 	0
#define	__HTTP_CMD_TRANSFER	1
#define	__HTTP_CMD_ENQUIRY 	2
#define	__HTTP_CMD_SHUTDOWN	3
#define	__HTTP_CMD_STATISTICS	4

PRIVATE	BPTR		HomePage=(BPTR) 0;
PRIVATE	BYTE		HomePath[256];
PRIVATE	HTTPSTAT	HttpStat;

#endif

#endif	/* _RESOLVER_H */
	/* ----------- */


