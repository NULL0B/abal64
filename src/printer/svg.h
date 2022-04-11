#ifndef	_SVG_H
#define	_SVG_H

#include	<stdio.h>
#include	<stdlib.h>
#include	"bda.h"
#include	"catcher.h"

#define	__DRIVER_NAME	"SVG"
#define	__DRIVER_DATE	"27/10/2006"
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
EXTERN	VOID rt_error(EXAWORD);

#else

	VOID FAR PTR InitRelais();
PRIVATE	VOID FAR banniere();
EXTERN	VOID rt_error();

#endif /* LINT_ARGS */


	/* ------ */
#endif	/* _SVG_H */
	/* ------ */





