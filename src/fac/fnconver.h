#ifndef	_fn_convertor_h
#define	_fn_convertor_h

#define	_HOST_PROLOGUE 	0
#define	_HOST_DOS	1
#define	_HOST_UNIX	2

#define	_BACKSLASH		0x005C

#define	_CONVERT_UPPER    	0x001
#define	_CONVERT_LOWER    	0x002
#define	_CONVERT_MNEMONICS	0x008
#define	_CONVERSION_LIMIT	1024

#ifdef __cplusplus
  extern "C" {
#endif

unsigned short	fn_convertor( unsigned char* workptr, unsigned char* resultptr, unsigned short mode );

#ifdef __cplusplus
  }
#endif

#endif	/* _fn_convertor_h */

