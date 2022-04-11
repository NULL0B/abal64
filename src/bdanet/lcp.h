#ifndef	_LCP_H
#define	_LCP_H


/*	LCP Commands/Messages		*/
/*	---------------------		*/

#define	_LCP_CONFIGURE_REQUEST	0x01
#define	_LCP_CONFIGURE_ACK	0x02
#define	_LCP_CONFIGURE_NAK	0x03
#define	_LCP_CONFIGURE_REJECT	0x04
#define	_LCP_TERMINATE_REQUEST	0x05
#define	_LCP_TERMINATE_ACK	0x06
#define	_LCP_CODE_REJECT	0x07
#define	_LCP_PROTOCOL_REJECT	0x08
#define	_LCP_ECHO_REQUEST	0x09
#define	_LCP_ECHO_REPLY		0x0A
#define	_LCP_DISCARD_REQUEST	0x0B

/*	Configuration Option Constants		*/
/*	------------------------------		*/

#define	_LCP_OPTION_RESERVED	0x00
#define	_LCP_OPTION_MRU		0x01	/* Maximum Receive Unit 	*/
#define	_LCP_OPTION_AUTHENTITY	0x03	/* Password Authentification	*/
#define	_LCP_OPTION_QUALITY	0x04	/* Quality Control Protocol	*/
#define	_LCP_OPTION_MAGIC	0x05	/* Magic Number 		*/
#define	_LCP_OPTION_PROTOCOMP	0x07	/* Protocol Field Compression	*/
#define	_LCP_OPTION_ADDRCOMP	0x08	/* Address/Control Compression	*/


#endif	/* _LCP_H */
	/* ------ */

