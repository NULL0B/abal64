#ifndef	_HTTPABAL_H
#define	_HTTPABAL_H

#include	<stdio.h>
#include	<stdlib.h>
#include	"bda.h"

#define	__HTTPABAL_DATE    	"10/06/2021"
#define	_BDANET_DLL_FUNCTION	37
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


	/* ----------- */
#endif	/* _HTTPABAL_H */
	/* ----------- */


