//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_stdtypes_h
#define _stdtypes_h

#ifndef	VOID
#define	VOID	void
#endif

#ifndef	PTR
#ifdef	UNIX
#define	PTR	    *
#define	FAR
#else
#define	FAR far
#define	PTR	FAR *
#endif
#endif

#ifndef	PIXIBYTE
#define PIXIBYTE char
#endif

#ifndef	WORD
#define WORD unsigned short int
#endif

#ifndef	EXAWORD
#ifdef	ABAL64
#define EXAWORD unsigned long long int
#else
#ifdef	VERSION666
#define EXAWORD unsigned long int
#else
#define EXAWORD WORD
#endif
#endif
#endif

#ifndef	LONG
#define LONG unsigned long
#endif

#ifndef	VPTR
#define	VPTR	VOID PTR
#endif

#ifndef	BPTR
#define	BPTR	PIXIBYTE PTR
#endif

#ifndef	WPTR
#define	WPTR	WORD PTR
#endif

#ifndef	LPTR
#define	LPTR	LONG PTR
#endif

#ifndef	PUBLIC
#define	PUBLIC
#endif

#ifndef	PRIVATE
#define	PRIVATE static
#endif

#ifndef	EXTERN
#define	EXTERN extern
#endif


#endif	// _stdtypes_h


