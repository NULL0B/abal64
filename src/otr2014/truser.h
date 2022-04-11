#ifndef	_TRUSER_H
#define	_TRUSER_H

#ifdef	DLL

#define	USING_DLL

#ifndef	UNIX
#else
	WORD	translator_initialisation();
	WORD	translator_termination();
	VOID	translator_identification();
	VOID	translate_byte();
#endif

#define	_TRUSER_INITIALISE	0
#define	_TRUSER_LIBERATE	1
#define	_TRUSER_LINE		2
#define _TRUSER_OPTIONS		3
#define	_TRUSER_FILE		4

#ifdef	FILESC   

static	WORD	DllStatus=MOINS_UN;
static	BYTE	DllDescriptor[256];
static	WORD	DllParameters=0;
static	BPTR	DllPointers[10];
static	WORD	DllLengths[10];
static	BYTE	DllTypes[10];

#endif

#endif	/* DLL	  */
	/* ------ */

#endif	/* _TRUSER_H */
	/* --------- */


