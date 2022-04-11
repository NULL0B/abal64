#ifndef _TRTYPE_H
#define _TRTYPE_H

#include <string.h>

/*	Data Type Constant Definitions		*/
/*	------------------------------		*/

#define	_TYPE_INT8  	0x0000
#define	_TYPE_INT16  	0x0001
#define	_TYPE_NUMERIC	0x0002
#define	_TYPE_STRING	0x0003
#define	_TYPE_INT32 	0x0005
#define	_TYPE_INT64 	0x0006
#define	_TYPE_BASIC 	0x0007 
#define	_TYPE_PARAMETER	0x0008
#define	_TYPE_DEFINED	0x0010
#define	_TYPE_SECOND	0x0020
#define	_TYPE_FIRST	0x0040
#define	_TYPE_OVERLAY	0x0080
#define	_TYPE_COMPLEX	(_TYPE_STRING | _TYPE_DEFINED)
#define	_TYPE_SPECIAL	0xFF00
#define	_TYPE_VIRTUAL	0x3F00
#define	_TYPE_EXTENDED	0x4000
#define	_TYPE_POINTER	0x9000
#define	_TYPE_MEMBER 	0xA000
#define	_TYPE_MBPTR  	0xB000

#define	_SIZE_INT8  	1
#define	_SIZE_INT16  	2
#define	_SIZE_NUMERIC	8
#define	_SIZE_STRING	15
#define	_SIZE_INT32 	4
#define	_SIZE_INT64 	8

#ifdef	otr64
#define	_TYPE_INT	_TYPE_INT64
#define	_SIZE_INT	_SIZE_INT64
#else
#ifdef	otr32
#define	_TYPE_INT	_TYPE_INT32
#define	_SIZE_INT	_SIZE_INT32
#else
#define	_TYPE_INT	_TYPE_INT16
#define	_SIZE_INT	_SIZE_INT16
#endif
#endif

#define	_MAX_NUMERIC	12

#define	NDX1st		_TYPE_FIRST
#define	NDX2nd		_TYPE_SECOND

#define	_TYPE_WRITABLE 	0x0001
#define	_TYPE_QUESTION	0x0004

/*		-------------------					*/
/*		T C O D E _ T Y P E					*/
/*		-------------------					*/

#define	TCTYPPTR struct tcode_type XPTR

struct	tcode_type {
					/* ---------------------------- */
	WORD	type;			/* Tcode Data Type 		*/
	WORD	size;			/* unit size of item		*/
	WORD	first;			/* First dimension		*/
	WORD	second;			/* Second dimension		*/
	VPTR	class;			/* Class of structured item     */
					/* ---------------------------- */
	};

#endif	/* _TRTYPE_H */
	/* --------- */

