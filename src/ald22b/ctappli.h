#ifndef __CTAPPLI_H__
#define __CTAPPLI_H__

/*
	Desc : ctAppli.h						Application specific header
	Proj : Visual Abal / Common Tools
	Copyright (c) 1994-95 Amenesik / Sologic  

	
	Place here application specific definitions:
	-	Application name
	-	Flag to force a specific behavior (far etc.)

	Note: This file is the first file to be included!

	Modifications list :
	23/October/1996  JPH  Create file
*/


#ifndef CT_APPLICATION_NAME
#define CT_APPLICATION_NAME "wald32"
#endif

#ifndef CT_DYNAMIC_CAST_BASE_CLASS
//#define CT_DYNAMIC_CAST_BASE_CLASS ctElement
#endif

// Uncomment next line to add a "~" prefix before each "ODS" line.
// #define __CT_ODS_PREFIX__ "~"

// Uncomment next line if you provide your own ctOutputDebugString
//#define __CT_OUTPUT_DEBUG_STRING_PROVIDED__

// Uncomment next line if you use Trace16/Trace32 Application
#define __CT_USE_TRACE__
#ifdef __CT_USE_TRACE__
#define __CT_OUTPUT_DEBUG_STRING_PROVIDED__
#endif

// Uncomment next line if you compile ctAnsStr.cpp (i.e. with Microsoft compiler)
//#define __CT_ANSI_STRING_PROVIDED__


#ifndef CT_INI_FILE
// Uncomment/change next line to read (trace) preference automatically
// (see ctContext.cpp)
#define CT_INI_FILE "wald32.ini"
#endif

#endif // __CTAPPLI_H__

