/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1996
 *	Module  : ATR
 *	Fichier : WATR.C
 *	Version : 1.1a
 *	Date    : 30/09/96
 *	Systeme : Windows 3/NT
 *
 *	Demarrage du traducteur
 *
 *	[Code]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	10/08/96 : Debut du codage
 *	30/09/96 : Gestion de la souris et clavier
 * 24/09/97 : Si ATR est appele a partir de Idra (June....) les fenetres 
 *            windows sont neutralisees
 * 28/03/01 : (#BG) Modification de x_cprintf(): travaille sur une copie du buffer d'entrée.
 * 08/10/01 : (#BG) ATR 10: Abandon de la traduction si la cible est ouverte.
 */

#define __WINDOWS_SOURCE__		/* source pour Windows */
#include "ctWinCon.h"

#ifdef USE_LONG_NAMES // Non défini
	#include "longName.h"
#endif

/* Inclusions importees */

#include "wabaldef.h"
#include <commdlg.h>

#include "ctdiag.h"
#include "ctCarSet.h"
#include "ctdiaout.h"
#include "ctExec.h"

/* Inclusions exportees et privees */

#include "trmess.he"
#include "watr.h"
BOOL TranslateForWindows(char*);

/* Definition du fichier */

static BYTE ThF[] = __FILE__;

ctDiagnostic Diag;
ctCharSetConversion ConversionTable;


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			PRIMITIVES MINIMALES				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

void ctBeforeConsoleMain	(ctConsolePtr Console)
	{
	//if (ctDiagnosticAvailable (0))
		Console->CommandShow = SW_HIDE;
	
	}


int ctConsoleMain (ctConsolePtr Console)
	{
	int Result = CT_CLOSE_CONSOLE_IF_EMPTY;

	int AtrResult = 0;
	
	char * arg[2];

	HWND	DiagnosticReceiver = ctGetProcessDiagnosticReceiver(0);

	 
	OptIdra = ctOpenDiagnostic (&Diag, DiagnosticReceiver, "");
	/* Préparation de la conversion car Dos->Windows */
	ctPrepareConversion (&ConversionTable,/*FROM*/CT_DOS_CHARSET, /*TO*/CT_WINDOWS_CHARSET,'?');

	/* GESTION DES NOMS LONGS D'IDENTIFICATEUR */
#ifdef USE_LONG_NAMES // Non défini
	lnOpen(".", TRUE, 15, &LongNameContext);
#endif
	//OptIdra = TRUE;

	/* Lance la traduction */
	arg[0] = "atr";
	arg[1] = Console->CommandLine;

	TraductionEnCours = TRUE;
	AbortRequired = FALSE;
	
	nberr = nbwarn = 0;

	if (lstrlen(arg[1]) == 0)	AtrResult = majn(1,arg);
	else AtrResult = majn(2,arg);

	ctSetProcessResult(0,AtrResult);

	TraductionEnCours = FALSE;

	if (!OptIdra) ShowWindow(Console->WindowHandle,SW_SHOW);
	else 
		ShowWindow(Console->WindowHandle,SW_HIDE);
	
	/* Ferme la fenetre si rien a signaler */
	
	if (AbortRequired == TRUE)	
		PostMessage(Console->WindowHandle,WM_CLOSE,(WPARAM)0,(LPARAM)0);
	
	else if ((nberr == 0) && (nbwarn == 0))
	{
		if (lstrlen(arg[1]) == 0) 
			if (!OptIdra) //MessageBox(Console->WindowHandle,"Traduction terminée","watr",0);
				if (isFrench)
					ctPrintConsole(0,"Traduction terminée");
				else
					ctPrintConsole(0,"End of translation");
	}
	
	if (OptIdra) PostMessage(Console->WindowHandle,WM_CLOSE,(WPARAM)0,(LPARAM)0);
	ctCloseDiagnostic(&Diag);

	#ifdef USE_LONG_NAMES // Non défini
		lnClose(LongNameContext);
	#endif

	/* Retour sans probleme */
		
	return Result;
	}



#ifndef DLL

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			MESSAGES CAPTES					     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* --------------------------------------------------------------------------
 *
 * FCT OnWmXXXXX
 *
 *	Traitement du message WM_XXXXX ou de la commande IDM_XXXXX.
 *
 *	E/ handle de la fenetre principale de l'application
 *	   message / commande a traiter
 *	   wParam
 *	   lParam
 *	S/ retour standard de traitement de messages
 *
 * -------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------
 *
 * FCT OnWmClose
 *
 *	Traitement du message WM_CLOSE.
 *
 */
static LRESULT OnWmClose( HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam )
{
	/* Autorise la fermeture uniquement en fin de traduction */
	if (TraductionEnCours == TRUE) {
		if (isFrench)
			MessageBox(0,"Traduction interrompue",0,0);
		else
			MessageBox(0,"Translation aborted",0,0);

		AbortRequired = TRUE;
	}

	return((LRESULT)0);
}

/* --------------------------------------------------------------------------
 *
 * FCT OnWmDestroy
 *
 *	Traitement du message WM_DESTROY.
 *
 */
static LRESULT OnWmDestroy( HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam )
{
	/* Enleve le mapping des messages et commandes de la
	 * fenetre principale de l'application.
	 */
	/* Reponse par un PostQuitMessage */
	PostQuitMessage(0);

	return((LRESULT)0);
}

#else // DLL
/*
#ifdef DLL32

BOOL WINAPI DllMain(HANDLE hModule, DWORD fdwReason, LPVOID lpReserved)
{
	switch (fdwReason)
		{
		case DLL_PROCESS_ATTACH:
			return 1;

		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
			break;

		case DLL_PROCESS_DETACH:
			return 1;
		}
}

#elif DLL16

int FAR PASCAL LibMain(HINSTANCE	hInstance,
					   	  WORD		wDataSeg,
					   	  WORD		wHeapSize,
					   	  LPSTR		lpszCmdLine)
{
	// Pour warning 4.
	wDataSeg;
	wHeapSize;
	lpszCmdLine;

	// Memorisation de l'instance.
	//	hInstDLL = hInstance;

	if (wHeapSize != 0)				// Le segment data de la DLL est MOVEABLE.
		UnlockData(0);
	return 1;							// Initialisation reussie.
}


int FAR PASCAL WEP(int nParameter)
{
	// Pour warning 4.
	nParameter;

	return 1;						// Fermeture reussie.
}

#endif // DLL16
*/
#endif // DLL

/* --------------------------------------------------------------------------
 *
 * FCT Epoch
 *
 *	Change la date d'un fichier
 *
 *	E/ nom du fichier
 *	S/ rien
 *
 */
#ifdef WIN32

void Epoch(nom)
BYTE * nom;
{ HFILE h;
//  OFSTRUCT of;
  FILETIME ft;
  BOOL Temp;

	/* Ouvre le fichier */
	//h = OpenFile(nom,(LPOFSTRUCT)&of, OF_READWRITE | OF_SHARE_EXCLUSIVE);
	//if (h == (HFILE)HFILE_ERROR)	return;

	h = CreateFile(
		nom,							// pointer to name of the file 
		GENERIC_WRITE,				// access (read-write) mode 
    	FILE_SHARE_READ,			// share mode 
    	0,								// pointer to security descriptor 
    	OPEN_EXISTING,				// how to create 
    	FILE_ATTRIBUTE_NORMAL,	// file attributes 
    	0 								// handle to file with attributes to copy  
	   );	

	if (h == (HFILE)HFILE_ERROR)
		return;
	/*
			SYSTEMTIME	time;
			SetSystemTime(&time);

			SystemTimeToFileTime(&time, &ft);

	*/
			/* Change la date et heure */
			ft.dwLowDateTime  = 0L/*ft.dwLowDateTime - 111L*/;
			ft.dwHighDateTime = 0L/*ft.dwHighDateTime - 1111111L*/;
			Temp = SetFileTime((HANDLE)h,&ft,&ft,&ft);

	/* Referme le fichier */
	_lclose(h);
}


/* #BG 08/10/01 Begin */
int IsFileOpened(char * FileName)
{      
	OFSTRUCT		ofStruct;
	HFILE			hFile;

	if (OpenFile((LPCTSTR)FileName, &ofStruct, OF_EXIST) != HFILE_ERROR)
	{
		hFile = OpenFile((LPCTSTR)FileName, &ofStruct, OF_SHARE_EXCLUSIVE);

		if (hFile == HFILE_ERROR)
			return 1;
		else
			_lclose(hFile);
	}

	return 0;
}
/* #BG 08/10/01 End */

#endif



/* ------------------------------------------------------------ */

#include <stdio.h>

WORD x_kbhit (void)
	{
	return 0;
	}

WORD x_getch (void)
	{
	return 0;
	}

WORD GetNoWait (void)
	{
	return FALSE;
	}

void pos (WORD a,WORD b)
	{
	}

void x_putch (char a)
	{
	putchar(a);
	}

void x_cprintf(char * Str)
	{
	BYTE Buf[256];

	/* #BG 28/03/01 */
	strcpy(Buf, Str);

	TranslateForWindows(Buf);

	ctPrintConsole(0,Buf);
	}

void atb(WORD a)
	{}

void x_bell()
	{
	MessageBeep(-1);
	}

void x_clear()
	{
	}

void initerm(WORD a)
	{
	}

void finterm(WORD a)
	{
	}

void conf(WORD a)
	{
	}

void backgr (WORD a)
	{
	}

void foregr (WORD a)
	{
	}

