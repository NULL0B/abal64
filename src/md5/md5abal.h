#ifndef	_md5abal_h
#define _md5abal_h

#include	<stdio.h>
#include	<stdlib.h>
#include	"bda.h"

#define	_DRIVER_DLL_MD5INIT	0
#define	_DRIVER_DLL_MD5FILE	1
#define	_DRIVER_DLL_MD5STRING	2
#define	_DRIVER_DLL_MD5RESULT	3

#define	__DRIVER_NAME	"MD5"
#define	__DRIVER_DATE	"09/02/2005"
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

#endif	/* _md5abal_h	*/









