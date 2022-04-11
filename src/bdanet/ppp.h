#ifndef	_PPP_H
#define	_PPP_H

#define	__PPP_PORT	777
#define __PPP_PREFIX	"ppp:"
#define	__PPP_TRANSPORT	SOCK_DGRAM

#define	_PADDING_PROTOCOL 		0x0001
#define	_LINK_CONTROL_PROTOCOL 		0xC021
#define	_PASSWORD_AUTH_PROTOCOL 	0xC023
#define	_LINK_QUALITY_PROTOCOL 		0xC025
#define	_CHALLENGE_HAND_PROTOCOL 	0xC223

PUBLIC	INT	initialise_ppp_service();


#endif	/* _PPP_H */
	/* ------ */

