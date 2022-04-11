
/*
	Desc : ctExec.c  		Execute command
	Proj : Common tools
	Copyright (c) 1998 Amenesik / Sologic  
	
	"Portable" routine to execute a command...
	...and wait until complete.


	Modifications list :
	17/June/1998	JPH File creation.
	1/Sept/98		JPH Add 'CT_EXECUTE_INTERPRETER' support
	19/Oct/1998		JPH Add a cleanup mechanism
	21/Oct/1988		JPH Add error codes.
*/


#include "ctExec.h"
#include <stdlib.h>
#include <stdio.h>

#define BUG_WITH_ATR_ERRNO_NOT_FOUND

#ifdef WIN32
#ifndef BUG_WITH_ATR_ERRNO_NOT_FOUND
#include <errno.h>
#endif
#include <process.h>
#endif


/*
	Implementation note:
	
	Cannot always fullfill all demands.
	
	I.e. if not possible to wait for answer AND 
		to provide for a command line interpreter,
		==> choose to wait for answer!
	
	
*/

#ifdef WIN32

#define CT_PROCESS_ROOT_KEY	" \\Amenesik / Sologic  \\ct\\Process"
#define CT_DATE_STAMP_KEY		"DateStamp"
#define CT_RESULT_KEY			"Result"
#define CT_DIAG_HD_KEY			"DiagHd"

#define CT_TRACE_ROOT_KEY		" \\Amenesik / Sologic  \\ct\\Trace"
#define CT_TRACE_EXECUTE_VAL	"ctExecute"
//#define CT_TRACE_CREATION_VAL				"ctInclude object creation"
//#define CT_TRACE_DESTRUCTION_VAL			"ctInclude object destruction"
//#define CT_TRACE_PARSING_VAL				"File parsing"

#else
#define PROCESS_INI	"PProcess.ini"
#define CT_INI			"ct.ini"
#endif

#define MAX_KEY 150

#define	MUST_WAIT(Option)					((Option &CT_EXECUTE_AND_WAIT_MASK)==CT_EXECUTE_AND_WAIT)
#define	MUST_CALL_INTERPRETER(Option)	((Option &CT_EXECUTE_INTERPRETER_MASK)==CT_EXECUTE_INTERPRETER)
#define	MUST_DISPATCH_MESSAGE(Option)	((Option &CT_DISPATCH_MESSAGE_MASK)==CT_DISPATCH_MESSAGE)

#ifdef __CT_DEBUG__
ctBoolean gGlobalTraceExecute = FALSE;
ctBoolean gGlobalTraceIsInited = FALSE;

static void pInitTrace(void);
static void pInitTrace(void)
{
	if (!gGlobalTraceIsInited)
	{
#ifdef WIN32
		{
			LONG 		Res;
			ctChar	FullKey[MAX_KEY];
			HKEY		KeyHandle;
			ctChar	ValueAsStr[15];
			long		ValueLength;
			DWORD		Type;
			DWORD		dw;
			
			// Default value.
			gGlobalTraceExecute = 0;

			sprintf(FullKey,"%s", CT_TRACE_ROOT_KEY);

			// Open the key.
			Res = RegOpenKeyEx(HKEY_CURRENT_USER, FullKey, 0, KEY_READ, &KeyHandle);	
 			if (Res == ERROR_SUCCESS)
			{
				// Read the value.
				ValueLength = sizeof(ValueAsStr);
				Res = RegQueryValueEx(KeyHandle, CT_TRACE_EXECUTE_VAL, 0, &Type, (LPBYTE)ValueAsStr, &ValueLength);
				if (Res == ERROR_SUCCESS)
					gGlobalTraceExecute = atoi(ValueAsStr);
				else
					// Set the value.
					Res = RegSetValueEx(KeyHandle, CT_TRACE_EXECUTE_VAL, 0, REG_SZ, "0", 1);
				// Close the key.
				RegCloseKey(KeyHandle);
			}
			else
			{
				// Create the Key.
				Res= RegCreateKeyEx(HKEY_CURRENT_USER,	FullKey, 0, REG_NONE, REG_OPTION_VOLATILE, KEY_ALL_ACCESS, 0, &KeyHandle, &dw);	
 
				if (Res == ERROR_SUCCESS)
				{
					// Set the value.
					Res = RegSetValueEx(KeyHandle, CT_TRACE_EXECUTE_VAL, 0, REG_SZ, "0", 1);
					// Close the key.
					RegCloseKey(KeyHandle);
				}
			}
		}
#else
		{
			char Buffer[20];

			gGlobalTraceExecute = GetPrivateProfileInt("Trace",CT_TRACE_EXECUTE_VAL,0,CT_INI);
			sprintf(Buffer,"%d",gGlobalTraceExecute);
			WritePrivateProfileString("Trace",CT_TRACE_EXECUTE_VAL,Buffer,CT_INI");
		}
#endif

		gGlobalTraceIsInited = TRUE;
	}
}

#endif




#ifdef WIN32
int pExecuteWin32
		(
		ctConstStr			CommandLine,
		int					ExecuteOption,
		ctExecuteEnvPtr	Environment
		);

int pWaitEndOfProcessDispatching
		(
		int					ExecuteOption,
		HWND					ProcessHandle,
		DWORD					TotalWait,
		DWORD					ProcessTimeOut
		);
#endif

int pExecuteOtherSystem
		(
		ctConstStr			CommandLine,
		int					ExecuteOption,
		ctExecuteEnvPtr	Environment
		);
		

void pCleanUpIfNeeded (void);
		
		
int ctExecute
		(
		ctConstStr			CommandLine,
		int					ExecuteOption,
		ctExecuteEnvPtr	Environment
		)
	{
	/*
		returns:
			<0		==> Error
			
			>=0	==> Value returned by called program.
	
	*/
	static ctExecuteEnv DefaultEnvironment;
	
	if (!Environment)
		{
		Environment = &DefaultEnvironment;
		ctClearExecEnvironment(Environment);
		}
	
	
	#ifdef WIN32
	return pExecuteWin32(CommandLine,ExecuteOption,Environment);
	#else
	return pExecuteOtherSystem(CommandLine,ExecuteOption,Environment);
	#endif
	}

int pExecuteOtherSystem
		(
		ctConstStr			CommandLine,
		int					ExecuteOption,
		ctExecuteEnvPtr	Environment
		)
	{
	int Result = 0;
	
	Result = system(CommandLine);
	
	#ifndef BUG_WITH_ATR_ERRNO_NOT_FOUND
	#ifdef WIN32
	if ((Result==0) && (errno == ENOENT))
		{
		Result = CT_CANNOT_EXECUTE_ERROR;
		}
	#endif
	#endif
	
	return Result;
	}

int ctGetProcessResult (ctProcessId ProcessId)
	{
	return ctGetProcessInfo (ProcessId, CT_RESULT_KEY);
	}


HWND ctGetProcessDiagnosticReceiver (ctProcessId ProcessId)
	{
	return (HWND) ctGetProcessInfo (ProcessId, CT_DIAG_HD_KEY);
	}		


long ctGetProcessInfo
		(
		ctProcessId			ProcessId,
		ctConstStr			Key
		)
	{
	long		Result = 0;

	if (!ProcessId)
		ProcessId = (ctProcessId) _getpid();

#ifdef WIN32
		{
		LONG 		Res;
		ctChar	FullKey[MAX_KEY];
		HKEY		KeyHandle;
		ctChar	ValueAsStr[15];
		long		ValueLength;
		
		sprintf(FullKey,"%s\\%s\\%ld", CT_PROCESS_ROOT_KEY, Key, ProcessId);

		Res = RegOpenKeyEx(HKEY_CURRENT_USER, FullKey, 0, KEY_READ, &KeyHandle);	
 
		if (Res == ERROR_SUCCESS)
			{
			ValueLength = sizeof(ValueAsStr);
			Res = RegQueryValue(KeyHandle, 0, ValueAsStr, &ValueLength);
			RegCloseKey(KeyHandle);
				
			sscanf(ValueAsStr,"%ld",&Result);	
			}
		}
#else
		{
			ctChar	SubKey[MAX_KEY];

			sprintf(SubKey,"%ld",ProcessId);
			
			Result = GetPrivateProfileInt(Key, SubKey, PROCESS_INI);	
		}
#endif
	
	return Result;
	}


void ctDeleteProcessInfo
		(
		ctProcessId			ProcessId,
		ctConstStr			Key
		)
	{

	if (!ProcessId)
		ProcessId = (ctProcessId) _getpid();

	#ifdef WIN32
		{
		ctChar	FullKey[MAX_KEY];
		LONG 		Res;
				
		sprintf(FullKey, "%s\\%s\\%ld", CT_PROCESS_ROOT_KEY, Key, ProcessId);
			
		Res = RegDeleteKey(HKEY_CURRENT_USER, FullKey);	
		}
	#else
	
	#endif
	
	}


void ctDelProcessDiagnosticReceiver (ctProcessId ProcessId)
	{
	ctDeleteProcessInfo (ProcessId, CT_DIAG_HD_KEY);
	}


void ctDelProcessResult (ctProcessId ProcessId)
	{
	ctDeleteProcessInfo (ProcessId, CT_RESULT_KEY);
	}


void ctSetProcessInfo
		(
		ctProcessId			ProcessId,
		ctConstStr			Key,
		long					Value
		)
	{
	ctChar	ValueAsStr[15];
	
	pCleanUpIfNeeded();

	if (!ProcessId)
		ProcessId = (ctProcessId) _getpid();

	sprintf(ValueAsStr,"%ld",Value);

	#ifdef WIN32
		{
		LONG 		Res;
		ctChar	FullKey[MAX_KEY];
		HKEY		KeyHandle;
		DWORD		dw;
				
		sprintf(FullKey, "%s\\%s\\%ld", CT_PROCESS_ROOT_KEY, Key, ProcessId);

		Res= RegCreateKeyEx(HKEY_CURRENT_USER, FullKey, 0, REG_NONE, REG_OPTION_VOLATILE, KEY_ALL_ACCESS, 0, &KeyHandle, &dw);	
 
		if (Res == ERROR_SUCCESS)
			{
			Res = RegSetValue(KeyHandle, "", REG_SZ, ValueAsStr, strlen(ValueAsStr));	
			RegCloseKey(KeyHandle);
			}
		}
	#else
		{
			ctChar	SubKey[MAX_KEY];

			sprintf(SubKey,"%ld",ProcessId);
			
			BOOL	Res = WritePrivateProfileString
				(
				Key,				// pointer to section name 
	   		SubKey,			// pointer to key name 
	    		ValueAsStr,		// pointer to string to add 
	    		PROCESS_INI 	// pointer to initialization filename 
	   		);	
		}
	#endif
	}



void ctSetProcessResult (ctProcessId ProcessId, int ResultValue)
	{
	if (!ProcessId)
		ProcessId = (ctProcessId) _getpid();

	ctSetProcessInfo (ProcessId, CT_RESULT_KEY, ResultValue);

	#ifdef __CT_DEBUG__
	pInitTrace();
	#endif

	IF_TRACE(Execute,
		ODSlu_("ctExecute - Process =%lx ", ProcessId);
		ODSu(" Result=%d", ResultValue);
		);
	}


void ctSetProcessDiagnosticReceiver (ctProcessId ProcessId, HWND DiagnosticReceiver)
	{
	ctSetProcessInfo (ProcessId, CT_DIAG_HD_KEY, (long) DiagnosticReceiver);
	}		



void ctClearExecEnvironment(ctExecuteEnvPtr Environment)
	{
	if (Environment)
		{
		Environment->EnvironmentVariable=0;
		Environment->DiagnosticReceiver=0;
		Environment->MaxWaitTime=-1;
		Environment->DefaultResult=0;
		}
	}

#ifdef WIN32
int pWaitEndOfProcessDispatching
		(
		int					ExecuteOption,
		HWND					ProcessHandle,
		DWORD					TotalWait,
		DWORD					ProcessTimeOut
		)
	{
	/*
		Wait end of process dispatching messages on the way...
		
		return TRUE if normal end (process ended).
		
		------------------------------------------------------------
		
		This routine is made for Idra and other application
		that must treat Diagnostic messages...
		Child process issues SendMessage that must be processed
		(otherwise a deadlock occurs).
		
		
	*/
	ctBoolean		Result = FALSE;				// Ok
	long				Res = 0;
	MSG 				Msg;

	while (1)
		{
		Res = WaitForSingleObject
				(
				ProcessHandle,			
    			ProcessTimeOut 		
   			);

		if (Res == WAIT_OBJECT_0)
			{
			/*
				Process is over
			*/
			Result = TRUE;
			break;
			}
		else
			{
			/*
				Not over,
				
				Message to Treat ?
			*/
		
			if (
				MUST_DISPATCH_MESSAGE(ExecuteOption) 
				&& PeekMessage(&Msg,0,0,0,PM_REMOVE)
				)
				{
				/*
					Treat all pending messages
				*/
				do
					{
					TranslateMessage(&Msg);
					DispatchMessage(&Msg);
					}
				while (PeekMessage(&Msg,0,0,0,PM_REMOVE));
				}
			else 
				{
				/*
					No message to treat
					--> Other process was NOT blocked
					--> Can decrement total wait !
				*/
				if (TotalWait !=0xFFFFFFFF)
					{
					if (TotalWait > ProcessTimeOut)
						{
						TotalWait -= ProcessTimeOut;
						}
					else
						{
						/*
							Time is over - failure ! 
						*/
						break;
						}
					}
				}
			}
		}
	
	return Result;
	}
#endif



#ifdef WIN32
int pExecuteWin32
		(
		ctConstStr			CommandLine,
		int					ExecuteOption,
		ctExecuteEnvPtr	Environment
		)
	{
	int 						Result = CT_CANNOT_EXECUTE_ERROR;
	ctBoolean 				MustWait = MUST_WAIT(ExecuteOption);
	PROCESS_INFORMATION	ProcessInformation;
	STARTUPINFO				si;
	HWND						ProcessId = 0;
	long						Res = 0;

	#define	MAX_COMMAND_LINE	(800)
	char						CommandBuffer[MAX_COMMAND_LINE];

	// Initialize the STARTUPINFO structure.
	memset(&si, 0, sizeof(si));
	si.cb = sizeof(si);
	si.dwFlags = STARTF_USESHOWWINDOW;
	
	if (ExecuteOption & CT_SHOW_WINDOW)
		si.wShowWindow = SW_SHOW;
	else
		si.wShowWindow = SW_HIDE;
		
		
	if (MUST_CALL_INTERPRETER(ExecuteOption))
		{
		/*
			prepend "command /c" before the command line
		*/
		BOOL IsNT = FALSE;
		BOOL Is95 = FALSE;

		#ifdef WIN32
		OSVERSIONINFO VersionInformation;

		VersionInformation.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

		if	(
			GetVersionEx(&VersionInformation)
			)
			{
			if (VersionInformation.dwPlatformId == VER_PLATFORM_WIN32_NT)
				IsNT = TRUE;
			else if (VersionInformation.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
				Is95 = TRUE;
			}
   	#endif


		if (IsNT)
			{
			GetSystemDirectory
				(
				CommandBuffer,		// address of buffer for system directory 
				MAX_COMMAND_LINE	// size of directory buffer 
				);
			strncat(CommandBuffer,"\\cmd.exe /c",MAX_COMMAND_LINE-strlen(CommandBuffer)-1);
			}
		else
			strcpy(CommandBuffer,"c:\\command.com /c");

		strncat(CommandBuffer,CommandLine,MAX_COMMAND_LINE-strlen(CommandBuffer)-1);
		CommandBuffer[MAX_COMMAND_LINE-1]='\0';
		CommandLine = &CommandBuffer[0];
		}
		
	#ifdef __CT_DEBUG__
	pInitTrace();
	#endif
	
	IF_TRACE(Execute,
	ODS_("ctExecute - Command >");
	ODS_(CommandLine);
	ODS("< ");
	);

	Res = CreateProcess
		(
    	0,								// pointer to name of executable module 
    	(LPTSTR) CommandLine,	// pointer to command line string
    	0,								// pointer to process security attributes 
    	0,								// pointer to thread security attributes 
    	FALSE,						// handle inheritance flag 
    	NORMAL_PRIORITY_CLASS | CREATE_SUSPENDED,		// creation flags 
    	(LPTSTR) Environment->EnvironmentVariable,	// pointer to new environment block 
    	0,								// pointer to current directory name 
    	&si,							// pointer to STARTUPINFO 
    	&ProcessInformation 		// pointer to PROCESS_INFORMATION  
	   );	

	if (Res)
		{
		/* Initialize process result & diag receiver before continuing */

		ProcessId = (ctProcessId) ProcessInformation.dwProcessId;

		IF_TRACE(Execute,
			{
			char Buffer[_MAX_PATH];
			DWORD Res = GetCurrentDirectory
								(
								sizeof(Buffer),	// size, in characters, of directory buffer 
								Buffer 	// address of buffer for current directory 
								);			

			ODSlu("--> pId =%lx",ProcessId);
			/*
			ODSlu("ctExecute - HThread   = %lx",(long) ProcessInformation.hThread);
			ODSlu("ctExecute - ProcessId = %lx",(long) ProcessInformation.dwProcessId);
			ODSlu("ctExecute - ThreadId  = %lx",(long) ProcessInformation.dwThreadId);
			*/
			ODS_("ctExecute - CurrentDirectory >");
			ODS_(Buffer);
			ODS("<");
			}
			);


		ctSetProcessResult(ProcessId,Environment->DefaultResult);
		if (Environment->DiagnosticReceiver)
			{
			ctSetProcessDiagnosticReceiver
				(ProcessId,(HWND)Environment->DiagnosticReceiver);
			}
		
		Res = ResumeThread(ProcessInformation.hThread);
				
		if (MustWait)
			{
			DWORD Milliseconds = INFINITE;

			if (Environment->MaxWaitTime != -1)
				Milliseconds = Environment->MaxWaitTime;

			#define PROCESS_TIME_SLICE  10
			if (
				pWaitEndOfProcessDispatching 
					(
					ExecuteOption,
					ProcessInformation.hProcess,			// handle of object to wait for  
					Milliseconds,
					PROCESS_TIME_SLICE
					)
				)
				{
				/*
					Properly ended !
				*/
				Result = ctGetProcessResult(ProcessId);
				}
			else
				{
				IF_TRACE(Execute,
				ODSlu("--> Stop waiting for process - Error %ld",(long) GetLastError());
				);
				if ((ExecuteOption & CT_SHOW_WINDOW)==0)
					{
						TerminateProcess
						(
					(HANDLE) ProcessInformation.hThread,	// handle to the process 
   					(UINT) 0 	// exit code for the process  
					   );
					}
				Result = CT_EXECUTE_TIME_OVER_ERROR;
				}
			ctDelProcessResult(ProcessId);
			if (Environment->DiagnosticReceiver)
				{
				ctDelProcessDiagnosticReceiver(ProcessId);
				}
			}
		else
			{
			Result = CT_EXECUTE_NO_ERROR;
			}
		}
	else
		{
		IF_TRACE(Execute,
			ODSlu("--> Cannot create process - Error %ld",(long) GetLastError());
			);
		}

	return Result;
	}

#endif


void pCleanUpIfNeeded	(void)
	{
	static ctBoolean	OnceDone = FALSE;
	
	if (!OnceDone)
		{
		OnceDone = TRUE;

		#define DUMMY_PID	((ctProcessId) 1)	// Not Zero!
	
		/*
			Purpose of this function is:
			-	to clean up the registry to avoid
				"old" unused keys.
			
		*/
	
	#ifdef WIN32
		{
		SYSTEMTIME	SystemTime;
		WORD			Day = 0;

		GetLocalTime(&SystemTime);
		
		Day = (WORD) ctGetProcessInfo (DUMMY_PID, CT_DATE_STAMP_KEY);
		
		if (Day != SystemTime.wDay)
			{
			ctChar	Key[MAX_KEY];
			LONG 		Res;

			// Different Stamp
			// Write new value
			
			ctSetProcessInfo (DUMMY_PID, CT_DATE_STAMP_KEY, SystemTime.wDay);
			// Delete Result & Info key
			
				
			sprintf(Key, "%s\\%s", CT_PROCESS_ROOT_KEY, CT_RESULT_KEY);
			
			Res = RegDeleteKey
				(
				HKEY_CURRENT_USER,	// handle of open key 
				Key						// address of name of subkey to open 
				);	
			sprintf(Key, "%s\\%s", CT_PROCESS_ROOT_KEY, CT_DIAG_HD_KEY);
			
			Res = RegDeleteKey
				(
				HKEY_CURRENT_USER,	// handle of open key 
				Key						// address of name of subkey to open 
				);	
			}
		}
	//#else
	#endif
		}
	}

