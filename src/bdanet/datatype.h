#ifndef	_DATATYPE_H
#define	_DATATYPE_H

#ifdef  ____FAR_DATA
#define	PTR	far *
#else
#define	PTR	*
#endif

#define	BYTE 		unsigned char
#ifdef	VERSION666
#define	WORD 		unsigned long  int
#else
#define	WORD 		unsigned short int
#endif
#define INT  		int
#define VOID 		void
#define LONG 		unsigned long

#define	PUBLIC
#define PRIVATE static
#define	EXTERN	extern

#define	BPTR 		BYTE PTR
#define	WPTR 		WORD PTR
#define	IPTR 		INT PTR

#if defined(UNIX)
/* sous Winows redefinition par rapport à includes Windows */
#define	LPTR 		LONG PTR
#endif
#define	VPTR 		VOID PTR

#endif	/* _DATATYPE_H */
	/* ----------- */


