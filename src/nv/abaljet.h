#ifndef	_LASERABAL_H
#define	_LASERABAL_H

#include	<stdio.h>
#include	<stdlib.h>
#include	"bda.h"
#include	"catcher.h"

#define	__LASERABAL_DATE    "18/02/2000"

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
#endif	/* _LASERABAL_H */
	/* ----------- */



