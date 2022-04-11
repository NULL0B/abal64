#ifndef	_TRUSER_H
#define	_TRUSER_H

#ifdef	DLL

#define	USING_DLL

#ifndef	UNIX
	EXAWORD	translator_initialisation( BPTR );
	EXAWORD	translator_termination( VOID );
	VOID	translator_identification( VOID );
	VOID	translate_byte( EXAWORD );
#else
	EXAWORD	translator_initialisation();
	EXAWORD	translator_termination();
	VOID	translator_identification();
	VOID	translate_byte();
#endif

#define	_TRUSER_INITIALISE	0
#define	_TRUSER_LIBERATE	1
#define	_TRUSER_LINE		2
#define _TRUSER_OPTIONS		3
#define	_TRUSER_FILE		4

#ifdef	FILESC   

static	EXAWORD	DllStatus=MOINS_UN;
static	EXABYTE	DllDescriptor[256];
static	EXAWORD	DllParameters=0;
static	BPTR	DllPointers[10];
static	EXAWORD	DllLengths[10];
static	EXABYTE	DllTypes[10];

#endif

#endif	/* DLL	  */
	/* ------ */

#endif	/* _TRUSER_H */
	/* --------- */


