#ifndef	_fn_parser_h
#define	_fn_parser_h

#define	_FNP_NETWORK_NAME	1
#define	_FNP_DEVICE_NAME	2
#define	_FNP_PATH_NAME		4
#define	_FNP_FILE_NAME		8
#define	_FNP_EXTENSION		16
#define	_FNP_PASSWORD		32
#define	_FNP_VERSION		64

#define	_NO_EXTENSION _FNP_NETWORK_NAME | _FNP_DEVICE_NAME | _FNP_PATH_NAME | _FNP_FILE_NAME

EXAWORD	fn_parser( BPTR sptr, BPTR rptr, EXAWORD mode );

#endif  /* _fn_parser_h */



