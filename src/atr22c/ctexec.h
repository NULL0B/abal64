
#ifndef __CTEXEC_H__
#define __CTEXEC_H__

/*
	Desc : ctExec.h  		Execute command
	Proj : Common tools
	Copyright (c) 1998 Amenesik / Sologic  
	
	"Portable" routine to execute a command...
	...and wait until completed.


	Modifications list :
	17/June/1998	JPH File creation.
	21/Oct/1998		JPH Add Error code.

*/

#include "ctType.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(WIN) || defined(WIN32)
#define ctProcessId	HANDLE
#else
#define ctProcessId	long
#endif

/* -------------------------------------------------- ProcessResult */

/*
	These routines are used to pass information from and to processes
	under windows (WIN16/WIN32)

	ProcessResult	==	Equivalent of Amenesik / Sologic/DOS/Unix return value
							0	OK
							>0	Error

	DiagnosticReceiver == Handle of the window that receive diagnostics


*/

void ctSetProcessResult (ctProcessId ProcessId, int ResultValue);
int  ctGetProcessResult (ctProcessId ProcessId);
void ctDelProcessResult (ctProcessId ProcessId);

void ctSetProcessDiagnosticReceiver (ctProcessId ProcessId, HWND DiagnosticReceiver);
HWND ctGetProcessDiagnosticReceiver (ctProcessId ProcessId);
void ctDelProcessDiagnosticReceiver (ctProcessId ProcessId);

void ctSetProcessInfo
		(
		ctProcessId			ProcessId,
		ctConstStr			ValueId,
		long					Value
		);
long ctGetProcessInfo
		(
		ctProcessId			ProcessId,
		ctConstStr			ValueId
		);
void ctDeleteProcessInfo
		(
		ctProcessId			ProcessId,
		ctConstStr			ValueId
		);


/* -------------------------------------------------- ctExecute */

/* Note: Error >0 are reserved for called program */
#define CT_EXECUTE_NO_ERROR			(0)
#define CT_CANNOT_EXECUTE_ERROR		(-1)	/* Cannot execute the command */
#define CT_EXECUTE_TIME_OVER_ERROR	(-2)  /* Time over for executed command */


/* ----- ExecuteOption ----- */
/* Force to wait for answer */
#define CT_EXECUTE_AND_WAIT		(0<<0)
#define CT_EXECUTE_DO_NOT_WAIT	(1<<0)
#define CT_EXECUTE_AND_WAIT_MASK	(1<<0)

/* Get and dispatch message during wait */
#define CT_NO_DISPATCH_MESSAGE		(0<<1)
#define CT_DISPATCH_MESSAGE			(1<<1)
#define CT_DISPATCH_MESSAGE_MASK		(1<<1)

/* Call command interpreter or simply a program */
#define CT_EXECUTE_NO_INTERPRETER	(0<<2)
#define CT_EXECUTE_INTERPRETER		(1<<2)
#define CT_EXECUTE_INTERPRETER_MASK	(1<<2)

/* Hide or show window */
#define CT_HIDE_WINDOW				(0<<3)
#define CT_SHOW_WINDOW				(1<<3)


/*
	Additional informations about command
*/
typedef struct ctExecuteEnvStruct ctExecuteEnv;
typedef ctExecuteEnv CT_FAR * ctExecuteEnvPtr;
struct ctExecuteEnvStruct
	{
	/* IN */
	ctConstStr		EnvironmentVariable;	/* titi=x toto=y */
	HWND				DiagnosticReceiver;	/* 0 */
	long				MaxWaitTime;			/* in millisecond */
	int				DefaultResult;			/* 0 */
	/* OUT */
	};


int ctExecute
		(
		ctConstStr			CommandLine,
		int					ExecuteOption,
		ctExecuteEnvPtr	Environment
		);
		
void ctClearExecEnvironment (ctExecuteEnvPtr Environment);


#ifdef __cplusplus
}
#endif
		
#endif /* __CTEXEC_H__ */
