#ifndef __CTTYPE_H__
#define __CTTYPE_H__

/*
	Desc : ctType.h							Stand Alone version !
	Proj : Visual Abal / Common Tools
	Copyright (c) 1994-95 Amenesik / Sologic  

	Types for Common tools.

	Modifications list :
	15/October/1996  JPH  Create stand alone version
	23/October/96	  JPH  Add 'ctAppli.h'
	5/March/98		  JPH  Merge with current version of "full version".
	29/July/98       JPH  ct2Bytes has correct size under WIN32, Added __CT32__.
*/

#include "ctappli.h"

/* ---------- Begin of ctSystem.h ---------- */

/*
 *	Define Only one of these Symbol at a time:
 *
 *		__CT_MAC__		Macintosh systems.
 *		__CT_OS2__		OS/2 systems.
 *		__CT_WINDOWS__	Windows systems.
 *		__CT_DOS__		Dos systems.
 *		__CT_UNIX__		Unix systems.
 *
 */

/*
 *	These switches are NOT excusive !!
 *
 *		__CT_DEBUG_TERM_AVAILABLE__		WindebugTerminal (or emulation) is available
 *		__CT_DYNAMIC_CAST_AVAILABLE__		dynamic_cast functionality is available
 *
 *
 *	These switches ARE excusive !!
 *
 *		Following switches change how classes are linked for DLL.
 *		__CT_NO_OO_DLL__						// Default. Normal linking.
 *		__CT_CREATE_OO_DLL__					//	Creates an OO DLL (export classes).
 *		__CT_USE_OO_DLL__						// Uses an OO DLL (import classes).
 *
 */

/*
 *	to declare a DLL function as entry point :
 *
 *		CT_EXPORT_FUNCTION(ResultType) FunctionName (ParamType0 Param0, ...)
 *
 *
 */


/* ----- Witch system ?  ----- */

/* Borland */
#if (defined(__BORLANDC__) && defined (_Windows))
	#define __CT_WINDOWS__
	#define __CT_DEBUG_TERM_AVAILABLE__
	#define __CT_DYNAMIC_CAST_AVAILABLE__
	#ifndef EXPORT_CLAUSE
	#define EXPORT_CLAUSE   _export
	#define IMPORT_CLAUSE   _import
	#endif
#endif
#ifdef __MSDOS__
	#define __CT_DOS__
	#define __CT_DYNAMIC_CAST_AVAILABLE__
#endif
#ifdef __DEBUG
	#if __DEBUG > 0
		#define __CT_DEBUG__
	#endif
#endif
/* MS C++ */
/* Note: _MSC_VER is defined for AppStudio >= 4.0 */
#if (defined _WINDOWS || defined WIN32)
	#define __CT_WINDOWS__
	#define __CT_DEBUG_TERM_AVAILABLE__

	#ifndef EXPORT_CLAUSE
		#ifdef WIN32
			#define EXPORT_CLAUSE   __declspec( dllexport )
		#else
			#define EXPORT_CLAUSE   __export
		#endif
	#endif

	#ifndef IMPORT_CLAUSE
		#ifdef WIN32
			#define IMPORT_CLAUSE   __declspec( dllimport )
		#else
			#define IMPORT_CLAUSE   __import
		#endif
	#endif
#endif
#ifdef _DOS
	#define __CT_DOS__
#endif
#ifdef _DEBUG
	#define __CT_DEBUG__
#endif

/* Metrowerks C++ */
#ifdef __MWERKS__
#define	__CT_MAC__
#define __TEMPLATES__
#endif


#ifndef __CT_MAC__
#ifndef __CT_WINDOWS__
#ifndef __CT_UNIX__
#ifndef __CT_OS2__
	#define __CT_DOS__
#endif
#endif
#endif
#endif


/* EXPORTED : A function accessible from outside (+exported from dll) */
#ifndef EXPORT_CLAUSE
#define EXPORT_CLAUSE
#endif
#ifndef EXPORTED
#define EXPORTED  EXPORT_CLAUSE CT_FAR PASCAL
#endif

/* -------------------- Specific actions -------------------- */


/* ---------- Setting Switches ---------- */
#ifdef __TURBOC__
	#ifndef NOT_USED
		#ifdef __CT_DEBUG__
			// In this case, show usual warning (never used...)
			#define NOT_USED(TOTO)
		#else
			// In release, you should turn "code has no effect" warning off;
			#pragma warn - eff
			#define NOT_USED(TOTO) TOTO;
		#endif
	#endif
#endif


#ifdef __CT_MAC__
	/* By default always ON */
	#define __CT_DEBUG__
	#ifndef __CT_TYPE_ONLY__
	#include <ctMacLib.h>
	#endif
#endif

/*	----- Linking of classes in DLL ----- */
#ifdef __CT_CREATE_OO_DLL__
	#ifdef __CT_NO_OO_DLL__
		#error __CT_NO_OO_DLL__ incompatibled with __CT_CREATE_OO_DLL__
	#endif
	#ifdef __CT_USE_OO_DLL__
		#error __CT_USE_OO_DLL__ incompatibled with __CT_CREATE_OO_DLL__
	#endif
#else
#ifdef __CT_USE_OO_DLL__
	#ifdef __CT_NO_OO_DLL__
		#error __CT_NO_OO_DLL__ incompatibled with __CT_USE_OO_DLL__
	#endif
#else
#ifdef __CT_NO_OO_DLL__
#else
	#define __CT_NO_OO_DLL__
#endif
#endif
#endif

/*
	Usage:
		class CT_CLASS_IMPORT_EXPORT ClassName
			{
			...
			}

	Note: to be reviewed (Microsoft/Borland portability).
*/
#ifdef __CT_WINDOWS__
	#ifndef _WINDOWS_
	#include <windows.h>
	#endif

	#ifdef __CT_NO_OO_DLL__
		#define	CLASS_DCL	class
		#define	CLASS			class
		#define	CT_EXPORT
		#define	CT_EXPORT_FUNCTION(ReturnType) ReturnType
	#endif
	#ifdef __CT_CREATE_OO_DLL__
		#ifdef __BORLANDC__
			#define	CLASS_DCL				class _export
			#define	CLASS						class _export
			#define	CT_EXPORT_FUNCTION(ReturnType) 	ReturnType EXPORT_CLAUSE
			/* Borland specific */
			#ifndef _RTLDLL
				#define _BUILDRTLDLL		// force to build a DLL
			#endif
		#else
			/* Microsoft */
			#define	CLASS_DCL				class EXPORT_CLAUSE
			#define	CLASS						class EXPORT_CLAUSE
			#define	CT_EXPORT_FUNCTION(ReturnType) 	EXPORT_CLAUSE ReturnType
		#endif
		#define	CT_EXPORT					EXPORT_CLAUSE
	#endif
	#ifdef __CT_USE_OO_DLL__
		#define	CLASS_DCL				class IMPORT_CLAUSE
		#define	CLASS						class IMPORT_CLAUSE
		#define	CT_EXPORT				IMPORT_CLAUSE
		#ifdef __BORLANDC__
			#define	CT_EXPORT_FUNCTION(ReturnType) 	ReturnType
			#ifndef _BUILDRTLDLL
				#define _RTLDLL			// force to use a DLL
			#endif
		#else
			/* Microsoft */
			#define	CT_EXPORT_FUNCTION(ReturnType)	IMPORT_CLAUSE ReturnType
		#endif
	#endif
#else
	#define	CLASS_DCL	class
	#define	CLASS			class
	#define	CT_EXPORT
	#define	CT_EXPORT_FUNCTION(ReturnType) 	ReturnType
#endif

#ifdef __CT_DOS__
#endif

#ifdef __CT_OS2__
#endif

#ifdef __CT_UNIX__
#endif

#define CT_MAX_INT	0x7FFF	// Maximum signed integer
#define CT_MIN_INT	0x8000	// Minimum signed integer
#define CT_MAX_UINT	0xFFFF	// Maximum unsigned integer
#define CT_MAX_LONG	0x7FFFFFFF	// Maximum signed long
#define CT_MIN_LONG	0x80000000	// Minimum signed long
#define CT_MAX_ULONG	0xFFFFFFFF	// Maximum unsigned long

/* use CT_FAR in all pointer definitions */
#ifdef __CT_FAR__
	#define CT_FAR __CT_FAR__
#else
	#ifdef FAR
		#define CT_FAR FAR
	#else
		#define CT_FAR /**/
	#endif
#endif

/* NOT_USED signal that a function parameter is never used */
#ifndef NOT_USED
#define NOT_USED(TOTO) TOTO;
#endif

#ifdef __cplusplus
	#define CT_EXTERN_C	extern "C"
#else
	#define CT_EXTERN_C
#endif __cplusplus

/* 16 or 32 bits */
#ifdef WIN32
#define __CT32__
#endif

/* ---------- End of ctSystem.h ---------- */

/* ---------- Begin of ctType.h ---------- */

#ifndef CT_APPLICATION_NAME
#define CT_APPLICATION_NAME "CommonTools"
#endif

#ifndef CT_DYNAMIC_CAST_BASE_CLASS
#define CT_DYNAMIC_CAST_BASE_CLASS ctElement
#endif

// ---------------------------------------- Documentation macro

// THESE MACROS ARE EMPTY ON PURPOSE
#ifndef IN
#define IN
#endif
#ifndef OUT
#define OUT
#endif
#ifndef INOUT
#define INOUT
#endif
#ifndef FUNCTION
#define FUNCTION
#endif
#ifndef ABSTRACT
#define ABSTRACT
#endif
#ifndef CONSTRUCTOR
#define CONSTRUCTOR
#endif
#ifndef DESTRUCTOR
#define DESTRUCTOR
#endif

// To impose that a function is not virtual
// Ie: a function called from constructor Or destructor
#ifndef NOT_VIRTUAL
#define NOT_VIRTUAL
#endif

// THESE MACROS ARE EMPTY ON PURPOSE
// Example of use:
//
//	CT::MyFunction
// CT_MACRO DOTHIS (xxxx)
// WIN_MACRO MESSAGE_CRACERS
//

#ifndef CT
#define CT
#endif
#ifndef CT_MACRO
#define CT_MACRO
#endif
#ifndef WIN_MACRO
#define WIN_MACRO
#endif
#ifndef WIN
#define WIN
#endif
// Specific Win 16 API (Windows 3.1)
#ifndef WIN_16
#define WIN_16
#endif
// Specific Win32 API (NT & Windows 32 bits)
#ifndef WIN_32
#define WIN_32
#endif

#ifdef __CT_DEBUG__
#define CT_IF_DEBUG(Anything)		Anything
#else
#define CT_IF_DEBUG(ForgetIt)
#endif

#ifdef __CT_DEBUG__
#define STATIC
#else
#define STATIC static
#endif

// ---------------------------------------- Basic types

// A type large enought to Contains any
// simple value (int, long, pointer, character)
typedef unsigned long int ctAnySimpleValue;

typedef unsigned char     ctByte;    // One byte
#ifdef __CT32__
typedef unsigned short int ct2Bytes;  // Two bytes word
#else
typedef unsigned int      ct2Bytes;  // Two bytes word
#endif
typedef unsigned long int ct4Bytes;	 // Long words of four bytes

typedef ctByte CT_FAR *  ctBytePtr;
typedef ct2Bytes CT_FAR *  ct2BytesPtr;

// Note: The semantic of ctUInt and ctULong is really
//		unsigned int and unsigned long
//		The only reason for there existant is to have a shorter name!
typedef unsigned int 		ctUInt;
typedef unsigned long int	ctULong;

typedef int CT_FAR * 		ctIntPtr;
typedef long CT_FAR * 		ctLongPtr;
typedef ctUInt CT_FAR * 	ctUIntPtr;
typedef ctULong CT_FAR * 	ctULongPtr;


typedef char ctChar;								// C character
typedef ctChar CT_FAR * ctStr;				// zero terminated C string
typedef const ctChar CT_FAR * ctConstStr;	// zero terminated C string

typedef ctByte CT_FAR * ctByteStr;					// Memory zone (Byte string)
typedef const ctByte CT_FAR * ctConstByteStr;	// Memory zone (Byte string)

typedef void CT_FAR * ctVoidPtr;

#ifdef BOOL
#define ctBoolean BOOL
#else
typedef int ctBoolean;
#endif
typedef ctBoolean CT_FAR * ctBooleanPtr;

// Index for ctContainer, hash table etc.
// MUST BE Signed! to provide space for -1
typedef signed int ctIndex;
typedef ctIndex CT_FAR * ctIndexPtr;
#define CT_INVALID_INDEX	-1
#define CT_FIELD_OFFSET(Structure,Field)	(long)(& (((Structure CT_FAR *) 0)->Field))


// ---------------------------------------- Basic types II

#ifndef TRUE
#define TRUE (1==1)
#endif

#ifndef FALSE
#define FALSE (1==0)
#endif

#ifndef Nl
#define Nl "\n"
#endif

// Mask manipulation
#define CT_MASK_IS_SET(Value,Mask)		( ((Value)&(Mask))!=0 )		// Tests if a bit (or one among a set) is up
#define CT_MASK_IS_NOT_SET(Value,Mask)	( ((Value)&(Mask))==0 )		// Tests if a bit (or a whole set) is down
#define CT_MASK_SET(Value,Mask) 			((Value)|(Mask))           // Set a set of bits
#define CT_MASK_UNSET(Value,Mask) 		((Value)&~ (Mask))			// Unset a set of bits

// Get maximum/minimum of couple of value
#ifndef MAX
#define MAX(a,b) (((a)<(b))?(b):(a))
#define MIN(a,b) (((a)<(b))?(a):(b))
#endif

// ---------------------------------------- General Definitions

#ifdef __cplusplus

#ifndef AS_TYPE
	#include <typeinfo.h>
	#ifdef __CT_DYNAMIC_CAST_AVAILABLE__
		#define AS_TYPE(TYPE,EXPRESSION)	(dynamic_cast<TYPE> ((CT_DYNAMIC_CAST_BASE_CLASS *) EXPRESSION))
	#else
		#define AS_TYPE(TYPE,EXPRESSION)	((TYPE) (EXPRESSION))
	#endif
#endif

// Old syntax
#ifndef ASTYPE
#define ASTYPE(TYPE,EXPRESSION)	AS_TYPE(TYPE,EXPRESSION)
#endif

class ctElement;

typedef
void ctIteratedFunction
	(
	ctElement * 		Element,
	int 					ElementIndex,
	ctElement * 		NextElement,
	ctAnySimpleValue	UserParameter,
	ctBoolean & 		MustContinue
	);

#endif

/* ---------- End of ctType ---------- */

/* ---------- Begin of ctDebug.h ---------- */

// -------------------------------------------------- OutputDebugString

// define OutputDebugString
#ifdef __CT_WINDOWS__
	#ifndef __WINDOWS_H
	#include <windows.h>
	#endif
#else
	#ifdef __cplusplus
		#ifdef __CT_USE_NEW_STREAM__
			#include <iostream>
		#else
			#if !(defined(__IOSTREAM_H)||defined(_INC_IOSTREAM))
			#include <iostream.h>
			#endif
		#endif
		#include <stdio.h>
		#ifndef OutputDebugString
			#define OutputDebugString(MESSAGE) cdeb << (char *) MESSAGE;
		#endif
	#else
		#include <stdio.h>
		#ifndef OutputDebugString
			#define OutputDebugString(MESSAGE) printf("%s",(char *) MESSAGE);
		#endif
	#endif
#endif
    

// -------------------------------------------------- Trace BEFORE Main/Winmain
// Used to debug Global instance construction
extern int ctTraceBeforeMain;

#ifdef __CT_DEBUG__
	#ifdef __MAIN__
		#ifndef __CT_TRACE_BEFORE_MAIN__
			#pragma warn - pch
			int ctTraceBeforeMain = 0;
			#pragma warn . pch
		#endif
		// Else, allow extern module to initialize the value to TRUE!
	#endif

	#define TRBeforeMain(MESSAGE) if (ctTraceBeforeMain !=0)\
															{\
															OutputDebugString(MESSAGE);\
															OutputDebugString("\n");\
															}
#else
	#define TRBeforeMain(MESSAGE)
#endif

// -------------------------------------------------- ctOutputDebugString

#if (defined (__CT_OUTPUT_DEBUG_STRING_PROVIDED__))
	CT_EXTERN_C extern void	ctOutputDebugString (ctConstStr MessageStr);
#else
	#define ctOutputDebugString OutputDebugString
#endif

extern int 	ctTraceIsOn;

#define CT_SUPPRESS_OUTPUT		(0)
#define CT_UNLIMITED_OUTPUT	(-1)
#ifdef __cplusplus
void ctSetTraceLimit (long TraceLimit = CT_UNLIMITED_OUTPUT);
long ctGetTraceLimit (void);
#else
void ctSetTraceLimit (long TraceLimit);
long ctGetTraceLimit (void);
#endif

#ifdef __CT_DEBUG__
		// These macro to force important message to pass through.
	#define CT_INC_TRACE_IS_ON ctTraceIsOn++;
	#define CT_DEC_TRACE_IS_ON	ctTraceIsOn--;
#else
	#define CT_INC_TRACE_IS_ON
	#define CT_DEC_TRACE_IS_ON
#endif

// -------------------------------------------------- ODS, ODSu, ...

#ifndef ODS

#ifdef __CT_DEBUG__
	#define CT_D__(x)        {x;}
#else
	#define CT_D__(x)
#endif

#ifndef __CT_WINDOWS__
#define wsprintf sprintf
#endif

//Basic debug macros
#ifdef __CT_ODS_PREFIX__
#define ODS(x)      CT_D__ (ctOutputDebugString (__CT_ODS_PREFIX__);ctOutputDebugString (x);ctOutputDebugString ("\r\n"))
#else
#define ODS(x)      CT_D__ (ctOutputDebugString (x);ctOutputDebugString ("\r\n"))
#endif

#define ODSsz(f, s)  {\
							char szDebug[128];\
							wsprintf ((char *)szDebug, (char *)f, (char *)s);\
							ODS (szDebug);\
							}


#define ODSu(f, u)  {\
						  char szDebug[128];\
						  wsprintf ((char *)szDebug, (char *)f, (unsigned int)u);\
						  ODS (szDebug);\
						  }


#define ODSlu(f, lu) {\
							char szDebug[128]; \
							wsprintf ((char *)szDebug, (char *)f, (unsigned long)lu);\
							ODS (szDebug);\
							}

#define ODSszu(f, s, u) {\
								char szDebug[128];\
								wsprintf ((char *)szDebug, (char *)f, (char *)s, (unsigned int)u);\
								ODS (szDebug);\
								}


#define ODSszlu(f, s, lu) {\
								  char szDebug[128];\
								  wsprintf ((char *)szDebug, (char *)f, (char *)s, (unsigned long)lu);\
								  ODS (szDebug);\
								  }

// The same but without New line ...
// Note: the _ in the name is there to subjest that something follows !

#define ODS_(x)      CT_D__ (ctOutputDebugString (x))

#define ODSsz_(f, s)  {\
							char szDebug[128];\
							wsprintf ((char *)szDebug, (char *)f, (char *)s);\
							ODS_ (szDebug);\
							}


#define ODSu_(f, u)  {\
						  char szDebug[128];\
						  wsprintf ((char *)szDebug, (char *)f, (unsigned int)u);\
						  ODS_ (szDebug);\
						  }


#define ODSlu_(f, lu) {\
							char szDebug[128];\
							wsprintf ((char *)szDebug, (char *)f, (unsigned long)lu);\
							ODS_ (szDebug);\
							}

#define ODSszu_(f, s, u) {\
								char szDebug[128];\
								wsprintf ((char *)szDebug, (char *)f, (char *)s, (unsigned int)u);\
								ODS_ (szDebug);\
								}


#define ODSszlu_(f, s, lu) {\
								  char szDebug[128];\
								  wsprintf ((char *)szDebug, (char *)f, (char *)s, (unsigned long)lu);\
								  ODS_ (szDebug);\
								  }

#endif

/*
	-------------------------------------------------- Trace switches 

	These trace switches are defined as external symbols

	1) #Define CT_INI_FILE "xxx.ini" in ctAppli.h 
	2) in your code, use:
	IF_TRACE_ON(CLex,
	ODS("mes mes mes mes");
	);

	IF_TRACE_ON(CLex,
	cDeb << "mes mes mes mes" << Nl;
	);

	3) In c only projects: call ctInitTraceSwitch somewhere
	3) In cpp projects: ctInitTraceSwitch is called in 
	ctContext constructor.

	Note: Variables & ctInitTraceSwitch are defined in ctTrace.c
*/

#ifdef __CT_DEBUG__
	#define IF_TRACE_ON(CODE) if (gGlobalTrace){CODE}
	#define IF_TRACE(NAME,CODE) if (gGlobalTrace##NAME){CODE}
#else
	#define IF_TRACE_ON(CODE) 
	#define IF_TRACE(NAME,CODE)
#endif

#ifdef CT_INI_FILE
	void ctInitTraceSwitch (void);

	#ifndef CT_TRACE_EXTERN 
	#define CT_TRACE_EXTERN(DCL,INIT) extern DCL
	#endif

	CT_TRACE_EXTERN(char gGlobalTrace,0);
	CT_TRACE_EXTERN(char gGlobalTraceCLex,0);
	CT_TRACE_EXTERN(char gGlobalTraceCppLex,0);

/*
	CT_TRACE_EXTERN(XXX,0);
	CT_TRACE_EXTERN(XXX,0);
	CT_TRACE_EXTERN(XXX,0);
*/
#endif

// -------------------------------------------------- TRACE Warning & Error

/*
 *	These macro are used to trace Error & Warning message concerning a program
 *	disfunctionment as precondition failing.
 *
 *	DO NOT USE THEM TO REPORT normal debugging message or invalid "user" input.
 *
 * In futur version, these macro may abruptly abort the program
 * and/or raise an exception.
 *
 */

#if defined(__CT_DEBUG__) && defined (__cplusplus)

	#define	CT_RETURN_ERROR_VALUE_IF(Condition,Where,Message,Value)\
		if (Condition)\
			{\
			CT_INC_TRACE_IS_ON\
			cdeb << "### " << CT_APPLICATION_NAME << " - " << Where \
			<< " (" << __FILE__ << "," << __LINE__ << ")" \
			<< " - " << "Programming ERROR :" << Message << Nl;\
			CT_DEC_TRACE_IS_ON\
			return Value;\
			}
	#define	CT_RETURN_ERROR_IF(Condition,Where,Message) CT_RETURN_ERROR_VALUE_IF(Condition,Where,Message,)

	#define	CT_RETURN_WARNING_VALUE_IF(Condition,Where,Message,Value)\
		if (Condition)\
			{\
			cdeb << "!!! " << CT_APPLICATION_NAME << " - " << Where \
			<< " (" << __FILE__ << "," << __LINE__ << ")" \
			<< " - " << "Programming WARNING :" << Message << Nl;\
			return Value;\
			}
	#define	CT_RETURN_WARNING_IF(Condition,Where,Message) CT_RETURN_WARNING_VALUE_IF(Condition,Where,Message,)

	#define	CT_RETURN_ALLOCATION_ERROR_VALUE_IF(Condition,Where,Value) CT_RETURN_ERROR_VALUE_IF(Condition,Where,"Out of memory",Value)
	#define	CT_RETURN_ALLOCATION_ERROR_IF(Condition,Where) CT_RETURN_ALLOCATION_ERROR_VALUE_IF(Condition,Where,)
#else
	#define	CT_RETURN_ALLOCATION_ERROR_VALUE_IF(Condition,Where,Value)
	#define	CT_RETURN_ALLOCATION_ERROR_IF(Condition,Where)
	#define	CT_RETURN_WARNING_VALUE_IF(Condition,Where,Message,Value)
	#define	CT_RETURN_WARNING_IF(Condition,Where,Message)
	#define	CT_RETURN_ERROR_VALUE_IF(Condition,Where,Message,Value)
	#define	CT_RETURN_ERROR_IF(Condition,Where,Message)
#endif

#define CT_CHECK_CYCLE_INIT(MAXCYCLE)	unsigned int zctMaxCycleCount=MAXCYCLE
#define CT_CHECK_CYCLE(ROUTINENAME)	\
	{\
		if ((--zctMaxCycleCount)==0)\
			{ \
			ODSsz("#### ERROR - Cycling in %s",ROUTINENAME);\
			break; \
			} \
	}

/* ---------- End of ctDebug.h ---------- */

#endif // __CTTYPE_H__

