#ifndef	_LJII_H
#define	_LJII_H

#include	<stdio.h>
#include	<stdlib.h>
#include	"bda.h"
#include	"catcher.h"

#define	__DRIVER_NAME	"LJII"
#define	__DRIVER_DATE	"19/02/2000"
#define __DRIVER_MAJOR 	'1'
#define __DRIVER_MINOR 	'1'
#define __DRIVER_INDEX 	'a'

#define	PRIVATE	static
#define	PUBLIC	
#define	EXTERN	extern

BDA	desrt;				/* library description */
EXTERN BDA_INIT FAR PTR rt_init;	/* library signing */
EXTERN BDA_ARG rt_arg;			/* arguments description */

#ifdef LINT_ARGS

	VOID FAR PTR InitRelais(VOID);
PRIVATE	VOID FAR banniere(VOID);
EXTERN	VOID rt_error(WORD);

#else

	VOID FAR PTR InitRelais();
PRIVATE	VOID FAR banniere();
EXTERN	VOID rt_error();

#endif /* LINT_ARGS */


	/* ----------- */
#endif	/* _LJII_H */
	/* ----------- */




