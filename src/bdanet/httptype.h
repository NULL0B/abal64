#ifndef	_HTTPTYPE_H
#define	_HTTPTYPE_H

#ifdef  ____FAR_DATA
#define	PTR	far *
#else
#define	PTR	*
#endif

#define	BYTE 		unsigned char
#define	WORD 		unsigned short int
#define INT  		int
#define VOID 		void
#define LONG 		unsigned long

#define	PUBLIC
#define PRIVATE static

#define	BPTR 		BYTE PTR
#define	WPTR 		WORD PTR
#define	IPTR 		INT PTR
#define	LPTR 		LONG PTR
#define	VPTR 		VOID PTR
#define	ADDRESS		struct sockaddr_in 
#define	ADDRPTR		ADDRESS PTR

#endif	/* _HTTPTYPE_H */
	/* ----------- */

