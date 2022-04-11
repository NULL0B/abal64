/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * The contents of this file are subject to the Netscape Public License
 * Version 1.0 (the "NPL"); you may not use this file except in
 * compliance with the NPL.  You may obtain a copy of the NPL at
 * http://www.mozilla.org/NPL/
 *
 *   distributed under the NPL is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the NPL
 * for the specific language governing rights and limitations under the
 * NPL.
 *
 * The Initial Developer of this code under the NPL is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1998 Netscape Communications Corporation.  All Rights
 * Reserved.
 */

/*-----------------------------------------------------------------------------
    xp_core.h
    Cross-Platform Core Types
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
	XP_PRL              XP_IS_PRL         XP_PRL_ARG(X)  Amenesik / Sologic   added these

	defined iff         always defined    defined to nothing
	on that platform    as 0 or 1         or X

	Also Bool, Int32, Int16, Int, Uint32, Uint16, Uint, and nil
	And TRUE, FALSE, ON, OFF, YES, NO
-----------------------------------------------------------------------------*/

#ifndef _XP_Core_
#define _XP_Core_


#define prologue 1

#ifndef	XP_PRL
#define XP_PRL
#endif

#ifndef	PROLOGUE
#define PROLOGUE
#endif

#ifndef	XP_IS_PRL
#define XP_IS_PRL 1
#endif

#define XP_PRL_ARG(x) x
#undef  XP_CPLUSPLUS
#define XP_IS_CPLUSPLUS 0

#define XP_REQUIRES_FUNCTIONS

/*
	language macros
	
	If C++ code includes a prototype for a function *compiled* in C, it needs to be
	wrapped in extern "C" for the linking to work properly. On the Mac, all code is
	being compiled in C++ so this isn't necessary, and Unix compiles it all in C. So
	only Windows actually will make use of the defined macros.
*/

#define XP_BEGIN_PROTOS 
#define XP_END_PROTOS

/* simple common types */

#include "prtypes.h"
typedef int Bool;
typedef int XP_Bool;


#define BOOL Bool
#define MIN(a,b) (((a)<(b))?(a):(b))

#ifndef FALSE
#define FALSE 0
#endif

/* disable the TRUE redefinition warning
 * TRUE is defined by windows.h in the MSVC
 * development environment, and creates a
 * nasty warning for every file.  The only
 * way to turn it off is to disable all
 * macro redefinition warnings or to not
 * define TRUE here
 */
#ifndef TRUE
#define TRUE !FALSE
#endif

#define YES 1
#define NO 0

#define ON 1
#define OFF 0

#ifndef nil
#define nil 0
#endif

#ifndef NULL
#define NULL 0
#endif

#define TRACEMSG(msg)

#define _INT16
#define _UINT16
#define _INT32
#define _UINT32

/* function classifications */

#define PUBLIC
#define MODULE_PRIVATE
#define PRIVATE static

/* common typedefs */
typedef struct _XP_List XP_List;

/* standard system headers */


#include <assert.h>
#include <ctype.h>

#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <stddef.h>
#include <stdio.h>
/* #include <stdlib.h> */
#include <string.h>
#include <time.h>

#endif /* _XP_Core_ */

