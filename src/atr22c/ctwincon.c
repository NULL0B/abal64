
/*
	Desc : ctWinCon.c  		Window's Console
	Proj : Common tools
	Copyright (c) 1997 Amenesik / Sologic  

	16/32 Windows library to get "console" behavior.
	Using "ctPrint" and "ctScan".

	Modifications list :
	9/December/1997	JPH File creation, from freeware source.
*/

#include "ctWinCon.h"

#include <stdio.h>
#include <stdarg.h>

#ifndef CT_CONSOLE_CLASS_NAME
#define CT_CONSOLE_CLASS_NAME		CT_APPLICATION_NAME
#endif


ctConsolePtr GlobalConsole = 0;
ctConstStr GlobalConsoleClassName = CT_CONSOLE_CLASS_NAME;

long FAR PASCAL _export ctConsoleWndProc 
			(
			HWND		hwnd, 
			UINT		message, 
			WPARAM	wParam,
			LPARAM	lParam
			);
			
void pPrintConsole (ctConsolePtr Console, ctConstStr Str);
void pForceCRLF (ctStr StrTo, ctConstStr StrFrom, int MaxLength);
void pMakeRoomForString (ctConsolePtr Console, ctConstStr Str);
			
int PASCAL WinMain 
			(
			HINSTANCE	Instance, 
			HINSTANCE	PreviousInstance,
			LPSTR			CommandLine, 
			int			CommandShow
			)
		{
		ctConsoleInfo	Console;

		WPARAM			Result = 0;
		WNDCLASS	*		WindowClass = 0;
		MSG				Msg;
		ctConsoleExtra	ConsoleExtra;
		BOOL				KeepOpened = FALSE;
		HGDIOBJ			hFont = 0;

		if (!GlobalConsole)
			GlobalConsole = &Console;

		Console.Instance = Instance;
		Console.PreviousInstance = PreviousInstance;
		Console.CommandLine = CommandLine;
		Console.CommandShow = CommandShow;

		Console.WindowHandle = 0;
		Console.WindowName = CT_APPLICATION_NAME;
		Console.WindowStyle = WS_OVERLAPPEDWINDOW;
		Console.EditHandle = 0;
		Console.EditStyle =
					WS_CHILD | WS_VISIBLE | 
					WS_BORDER | ES_LEFT | ES_MULTILINE |
					WS_HSCROLL | WS_VSCROLL |
					ES_AUTOHSCROLL | ES_AUTOVSCROLL
					;
		Console.PrintCount = 0;

		WindowClass = &Console.WindowClass;
	
		if (!PreviousInstance) 
			{
			WindowClass->style         = CS_HREDRAW | CS_VREDRAW;
			WindowClass->lpfnWndProc   = ctConsoleWndProc;
			WindowClass->cbClsExtra    = 0;
			WindowClass->cbWndExtra    = sizeof(ctConsoleExtra);
			WindowClass->hInstance		= Instance;
			WindowClass->hIcon         = LoadIcon (NULL, IDI_APPLICATION);
			WindowClass->hCursor       = LoadCursor (NULL, IDC_ARROW);
			WindowClass->hbrBackground = GetStockObject (WHITE_BRUSH);
			WindowClass->lpszMenuName  = NULL;
			WindowClass->lpszClassName = GlobalConsoleClassName;

			ctBeforeConsoleMain(&Console);

			if (!RegisterClass (WindowClass))
				{
				ODSsz_("### %s - ERROR - Cannot register class",CT_APPLICATION_NAME);
				ODS(GlobalConsoleClassName);
				}
			}
		
		if (Console.WindowHandle == 0)
			{
			Console.WindowHandle = CreateWindow 
				(
				GlobalConsoleClassName,	/*Register classname */ 
				Console.WindowName,
				Console.WindowStyle,
				CW_USEDEFAULT, CW_USEDEFAULT,
				GetSystemMetrics (SM_CXSCREEN) / 2,
				GetSystemMetrics (SM_CYSCREEN) / 2,
				NULL, NULL, 
				Instance, 
				NULL
				);
				
			if (Console.EditHandle == 0)
				{
				Console.EditHandle = CreateWindow 
					(
					"edit",						// pointer to registered class name
					NULL,							// pointer to window name
					Console.EditStyle,		// window style
					0, 0, 0, 0,					// coordinate x,y,w,h
					Console.WindowHandle,	// handle to parent or owner window
					(HMENU) 1,					// handle to menu or child-window identifier
					Instance,					// handle to application instance
					NULL							// pointer to window-creation data
					); 

				hFont = GetStockObject(SYSTEM_FIXED_FONT);
				SendMessage(Console.EditHandle,WM_SETFONT,(WPARAM) hFont, (LPARAM) 0);

				}
			ConsoleExtra.EditHandle = Console.EditHandle;
			ctSetConsoleExtra(Console.WindowHandle,&ConsoleExtra);
			}

		ShowWindow (Console.WindowHandle, Console.CommandShow);
		UpdateWindow (Console.WindowHandle);


		switch (ctConsoleMain(&Console))
			{
			case CT_CLOSE_CONSOLE:
				KeepOpened = FALSE;
				break;

			case CT_CLOSE_CONSOLE_IF_EMPTY:
				KeepOpened = (Console.PrintCount > 0);
				break;

			case CT_KEEP_CONSOLE_OPENED:
			default:
				KeepOpened = TRUE;
			}

		if (KeepOpened)
			{
			/* Keep window open (allow cut/past and reading) */

			if (IsWindowVisible(Console.WindowHandle))
				{
				// Wait until close

				while (GetMessage (&Msg, NULL, 0, 0))
					{
					TranslateMessage (&Msg) ;
					DispatchMessage (&Msg) ;
					}
				Result = Msg.wParam;
				}
			}

		/*ctAfterMain(&Console);*/

		if (GlobalConsole == &Console)
			GlobalConsole = 0;

		return Result;
		}


int ctParseArgument 
			(
			IN		ctConstStr	CommandLine, 
			OUT	ctStr			ArgBuffer,
			INOUT	int			ArgBufferLength,
			OUT	ctStr			ArgV[], 
			IN		int			MaxArgV,
			IN		int *			ArgC,
			IN		ctConstStr	ArgZeroValue,
			IN		int			ParseOption
			)
	{
	/*
		Parse command line into an array of pointer and a buffer.
		
		returns:
			 0			OK.
			 <0		Error
			 >0		Warning
			 
		
		Usage:
		
			Note:
				If not zero, ArgZeroValue is copied in Arg[0]
				
		
			char 		Buffer[MAX_BUFFER];
			ctStr		ArgV[MAX_POINTER];
			int		ArgC;
			
			
			Err = ctParseArgument
					(
					"-a1111 /b'cc cc'dd  'f:dddd'",
					Buffer,
					MAX_BUFFER,
					ArgV,
					MAX_POINTER,
					&ArgC,
					0,
					0
					);

		==> after call
			ArgC = 3 			
			Buffer = -a1111 /b'cc cc'dd  'f:dddd'\0-a1111\0/b'cc cc'dd\0f:dddd'\0\0
			ArgV[0],[1],[2],[3]
		
	*/
	
	/*
		Rules
	*/
	#define MUST_STORE_QUOTE(Option) ((Option & CT_STORE_QUOTE_IN_ARGUMENT_MASK)==CT_STORE_QUOTE_IN_ARGUMENT)
	
	int	Result = -1;
	int	BufferIndex = 0;
	int	i;
	
	if (CommandLine && ArgC)
		{
		int 			CommandLg =0;
		char			Car = 0;
		char			QuoteOpened = 0;
		ctBoolean	PreviousIsWhite = FALSE;
		ctBoolean	MustStore;

		*ArgC = 0;
		
		// Simplify test in rest of code
		if (ArgV)
			{
			for (i=0;i<MaxArgV;i++)
				ArgV[i]=0;
			}
		else
			{
			MaxArgV = 0;
			}

		// Simplify test in rest of code
		if (ArgBuffer && ArgBufferLength)
			{
			ArgBuffer[0] = '\0';		// initialize
			ArgBufferLength--;		// keep space for ending '\0';
			}
		else
			{
			ArgBufferLength = -1;
			MaxArgV = -1;	// Cannot have pointer if no buffer!
			}


		Result = 0;

		if (MaxArgV)
			{
			ArgV[0] = ArgBuffer;
			}

		if (ArgZeroValue)
			{
			if (ArgBufferLength >0)
				{
				// Must copy string at start of buffer
				int Len = strlen(ArgZeroValue);
			
				Len = MIN (Len, ArgBufferLength);
			
				strncpy(ArgBuffer,ArgZeroValue,Len);
				ArgBuffer[Len]='\0';
				
				ArgBuffer += (Len+1);
				ArgBufferLength -= (Len+1);
	
				if (MaxArgV>=1)
					{
					ArgV[1] = ArgBuffer;
					}			
				}
			*ArgC = 1;
			}

		/*
			Loop until end of string.
			Note: last character ('\0') is processed too
		*/	
		PreviousIsWhite = TRUE;		/* No argument started yet */
		do
			{
			Car = *CommandLine++;
			MustStore = TRUE;
			
				
			if ((Car == ' ') || (Car == '\t') || (Car == '\0'))	//----- White
				{
				if (!QuoteOpened)
					{
					MustStore = FALSE;

					if (!PreviousIsWhite)
						{
						PreviousIsWhite = TRUE;

						// End of current argument
						(*ArgC)++;

						// Start new argument
						if (BufferIndex <ArgBufferLength)
							{
							// Start a new substring
							ArgBuffer[++BufferIndex]='\0';
							}
						else
							;

						if ((*ArgC) < MaxArgV)
							{
							ArgV[*ArgC] = &ArgBuffer[BufferIndex];
							}
						else
							;
						}
					else
						{
						// Previous is white, keep searching 
						// for non white character.
						}
					}
				else
					{
					// Quote opened
					//	space inside quoted argument ==> as normal char
					PreviousIsWhite = FALSE;
					}
				}
			else 
				{
				// Non white.
				PreviousIsWhite = FALSE;
				if ((Car == '\'')	 || (Car == '"'))				//----- Quote ' and "
					{
					if (QuoteOpened == 0)
						{
						// starting quote
						MustStore = MUST_STORE_QUOTE(ParseOption);
						QuoteOpened = Car;
						}
					else if (QuoteOpened == Car)
						{
						// Ending quote
						MustStore = MUST_STORE_QUOTE(ParseOption);
						QuoteOpened = 0;
						}
					else
						;
					//else
					//	' inside " or vice-versa	
					}
				else if (Car== '\\')								//----- Escape \' and \"
					{
					/*
					Escape characters:

					\"		--> "
					\'		--> '

					*/
					// Test next char
					if (*CommandLine == QuoteOpened)
						{
						// Skip the escape
						Car = QuoteOpened;
						CommandLine++;
						}
					}
				}

			if (MustStore && (BufferIndex < ArgBufferLength))
				{
				ArgBuffer[BufferIndex++] = Car;
				ArgBuffer[BufferIndex]='\0';
				}

			}
		while (Car);
		
		/*
			Must end with two \0.
		*/
		if ((BufferIndex+1) < ArgBufferLength)
			ArgBuffer[++BufferIndex] = '\0';
		else if ((BufferIndex>0) && ArgBufferLength)
			ArgBuffer[--BufferIndex] = '\0';
		// else
		//		Buffer too small (or not existing)
			
		} // CommandLine , Buffer & Argcount

	
	return Result;
	}



void ctPrintConsole (ctConsolePtr Console, ctConstStr Format, ...)
	{
	#define CT_MAX_CONSOLE_PRINT_BUFFER 256

	ctChar	Buffer [CT_MAX_CONSOLE_PRINT_BUFFER];			
	va_list	ap;
	
	if (!Console)
		Console = GlobalConsole;

	/* Add buffer to edit ... */
	if (Format)
		{
		va_start(ap,Format);
		vsprintf(Buffer,Format,ap);
		va_end(ap);
		pPrintConsole(Console,Buffer);
		}
	else
		{
		ODS("### ERROR - ctPrintConsole - Null format");
		}	
	}

 
void ctPrintDefaultConsole (ctConstStr Format, ...)
	{

	ctChar			Buffer [CT_MAX_CONSOLE_PRINT_BUFFER];			
	va_list			ap;
	
	ctConsolePtr	Console = GlobalConsole;

	/* Add buffer to edit ... */
	/* Add buffer to edit ... */
	if (Format)
		{
		va_start(ap,Format);
		vsprintf(Buffer,Format,ap);
		va_end(ap);
		pPrintConsole(Console,Buffer);
		}
	else
		{
		ODS("### ERROR - ctPrintDefaultConsole - Null format");
		}
	}


 void pPrintConsole (ctConsolePtr Console, ctConstStr Str)
	{
	/*
		print Str on console
		replacing '\n' by '\r\n'.
	*/
	ctChar	Buffer [CT_MAX_CONSOLE_PRINT_BUFFER];			


ODS_(Str);

	/* Add buffer to edit ... */
	if (Console)
		{
		(Console->PrintCount)++;
		pForceCRLF(Buffer,Str,CT_MAX_CONSOLE_PRINT_BUFFER);
		
		/*
				EM_SETREADONLY message
				EM_SETTABSTOPS 
		*/
		
		pMakeRoomForString(Console,Buffer);
		
		SendMessage
			(
			Console->EditHandle, EM_REPLACESEL,
		   (WPARAM) FALSE,	// fCanUndo
			(LPARAM) Buffer 	// Replacement string
   		);	 
		}
	else
		{
		ODS_("Null console:");
		ODS(Buffer);
		}
	}



void pForceCRLF (ctStr StrTo, ctConstStr StrFrom, int MaxLength)
	{
	/*
		Scan string, replacing end of line ('\n', '\r', ...)
		by CR+LF \r\n.
	*/
	int Car = 0;
	#ifdef __CT_DEBUG__
	ctStr StrToBegin = StrTo;
	#endif
	
	if ((MaxLength >0) && StrFrom && StrTo)
		{
		while (MaxLength >1)
			{
			Car = *StrFrom++;
			
			switch (Car)
				{
				case '\r':
					if (*StrFrom == '\n')
						StrFrom++;
						
					if (MaxLength>2)
						{
						*StrTo++='\r';
						*StrTo++='\n';
						MaxLength-=2;
						}
					else
						MaxLength=0;	// Force to get out
					break;
						
				case '\n':
					if (*StrFrom == '\r')
						StrFrom++;
						
					if (MaxLength>2)
						{
						*StrTo++='\r';
						*StrTo++='\n';
						MaxLength-=2;
						}
					else
						MaxLength=0;	// Force to get out
					break;

				case '\0':
					MaxLength = 0;
					break;
					
				default:
					*StrTo++ = Car;
					MaxLength--;
				}
			}
			
		*StrTo = '\0';
		}	
	}
	
void pMakeRoomForString (ctConsolePtr Console, ctConstStr Str)
 	{

	long 	LimitText = 0;
	long 	LastCharacter = 0;
	int	StringLength =strlen(Str);
	long	DeleteCount = 0;
	ctBoolean Changed = FALSE;
	
	LimitText = SendMessage
		(
		Console->EditHandle, EM_GETLIMITTEXT,
	   (WPARAM) 0,			
		(LPARAM) 0 
		);	 
			
	SendMessage
		(
		Console->EditHandle, EM_GETSEL,
	   (WPARAM) 0,			
		(LPARAM) &LastCharacter 
		);	 
///Debug LimitText = 300;
			
	while ((StringLength + LastCharacter) > LimitText)
		{
		//delete line before line 3!
		DeleteCount	= SendMessage
			(
			Console->EditHandle, EM_LINEINDEX,
		   (WPARAM) 3,
			(LPARAM) 0 
			);	 
			
		if (DeleteCount>0)
			{
			Changed = TRUE;
			LastCharacter-=DeleteCount;
			SendMessage
				(
				Console->EditHandle, EM_SETSEL,
			   (WPARAM) 0,
				(LPARAM) DeleteCount 	
				);	 
			SendMessage
				(
				Console->EditHandle, EM_REPLACESEL,
			   (WPARAM) FALSE,	// fCanUndo
				(LPARAM) "" 	// Replacement string
				);	 
			}
		else
			{
			break;
			}
		}		
		
	if (Changed)
		{	
		//Restore selection
		SendMessage
			(
			Console->EditHandle, EM_SETSEL,
		   (WPARAM) LastCharacter,
			(LPARAM) LastCharacter 	
			);

//MessageBox(0,"cc","cc",0);
		}	 
	}



long FAR PASCAL _export ctConsoleWndProc 
			(
			HWND		hwnd, 
			UINT		message, 
			WPARAM	wParam,
			LPARAM	lParam
			)
		{
		ctConsolePtr 			Console = (ctConsolePtr) GetWindowLong(hwnd,0);
		ctConsoleExtra			Extra;

		switch (message)
			{
			case WM_CREATE:
				return 0 ;

			case WM_SETFOCUS:
				ctGetConsoleExtra(hwnd,&Extra);
				SetFocus (Extra.EditHandle);
				return 0 ;

			case WM_SIZE: 
				ctGetConsoleExtra(hwnd,&Extra);
				MoveWindow 
					(
					Extra.EditHandle, 
					0, 
					0, 
					LOWORD (lParam),
					HIWORD (lParam), TRUE
					) ;
				return 0 ;

			case WM_COMMAND :
				if (wParam == 1 && HIWORD (lParam) == EN_ERRSPACE)
					MessageBox 
					(
					hwnd,
					"Memory overflow for output.",
					CT_APPLICATION_NAME, MB_OK | MB_ICONSTOP
					);
				else
					{
					#ifdef __CT_DEBUG__
					int wNotifyCode = HIWORD(wParam); // notification code 
					int wID = LOWORD(wParam);         // item, control, or accelerator identifier 
					HWND hwndCtl = (HWND) lParam;      // handle of control 

//					ODSu_("ctWinConsole::WinProc NotifyCode:%x",wNotifyCode);
//					ODSu_(" wId:%x",wID);
//					ODSlu_(" hwndCtl:%lx",hwndCtl);
					#endif
					}
				return 0 ;

			case WM_DESTROY :
				PostQuitMessage (0) ;
				return 0 ;
			}
		return DefWindowProc (hwnd, message, wParam, lParam) ;
		}



void ctGetConsoleExtra
		(
		HWND					WindowHandle,
		ctConsoleExtraPtr	Extra
		)
	{
	int		i;
	WORD *	ExtraWord = (WORD *) Extra;
	
	if (WindowHandle && Extra)
		{
		for (i=0;i<sizeof(ctConsoleExtra);i+=2)
			*ExtraWord++ = GetWindowWord(WindowHandle,i);
		}
	}



void ctSetConsoleExtra
		(
		HWND					WindowHandle,
		ctConsoleExtraPtr	Extra
		)
	{
	int		i;
	WORD *	ExtraWord = (WORD *) Extra;
	
	if (WindowHandle && Extra)
		{
		for (i=0;i<sizeof(ctConsoleExtra);i+=2)
			SetWindowWord(WindowHandle,i,*ExtraWord++);
		}
	}




void ctShowConsole (ctConsolePtr Console, ctBoolean MustShow)
	{
	if (!Console)
		Console = GlobalConsole;

	if (MustShow)
		Console->CommandShow = SW_SHOW;
	else
		Console->CommandShow = SW_HIDE;
	
	if (Console->WindowHandle)
		{
		ShowWindow (Console->WindowHandle, Console->CommandShow);
		}
	}

ctBoolean ctIsConsoleShown (ctConsolePtr Console)
	{
	ctBoolean Result = FALSE;

	if (!Console)
		Console = GlobalConsole;

	if (Console->WindowHandle)
		{
		Result = IsWindowVisible(Console->WindowHandle);
		}
	else
		{
		Result = (Console->CommandShow == SW_SHOW);
		}

	return Result;
	}

