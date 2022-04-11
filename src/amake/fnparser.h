
#ifndef	FNPARSERH
#define	FNPARSERH

/*	Basic definitions for fn_parser calls		*/
/*	-------------------------------------		*/
#define	_NETWORK_NODE_NAME	0x0001
#define	_DEVICE_NAME		0x0002
#define	_PATH_NAME		0x0004
#define	_FILE_NAME		0x0008
#define	_FILE_EXTENSION		0x0010
#define	_FILE_PASSWORD		0x0020
#define	_FILE_VERSION		0x0040
#define	_FILE_UPPER_CASE	0x0100

/*	Composite definitions for fn_parser calls	*/
/*	-----------------------------------------	*/
#define	_FILEPART_ONLY		0x0078
#define	_PATHPART_ONLY		0x0007
#define	_SYSTEM_SUPPLIMENT	0x0060
#define	_NO_EXTENSION		0x000F
#define	_ENTIRE_FILE_SPEC	0x007F

#endif
