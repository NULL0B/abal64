#ifndef	_HTTPSSL_H
#define	_HTTPSSL_H

#define __HTTPS_PORT	443
#define	__HTTPS_PREFIX	"https:"
#define	__HTTPS_AGENT   "TwinHttps/1.1"
#ifdef	_HTTP_C
PRIVATE	SERVICE	HttpsService;
#endif
PUBLIC	INT	initialise_https_service();

#endif	/* _HTTPSSL_H */
	/* ---------- */

