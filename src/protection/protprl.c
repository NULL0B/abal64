/*
	Desc : protprl.c
	Copyright (c) 2005 Amenesik / Sologic  
	Implementation de la protection
*/

#include <windows.h>
#include <stdio.h>
#include <lm.h>

/* ---------------------------------------------------------------------------- */
/*		Codes retours de la protection					*/
/* ---------------------------------------------------------------------------- */
#define	CPTCP_OK						0		/*  pas d'erreur					*/
#define	CPTCP_INVALID_LICENCE	1		/* la licence n'est pas ou plus valide			*/
#define	CPTCP_INVALID_PARAM		2		/* un des paramètres est invalide (pointeur nul)	*/
#define	CPTCP_PATH_NOT_FOUND		3		/* le chemin des outils de protection n'a pas pu être	*/
													/* lu dans la base de registre du poste			*/
#define	CPTCP_FOPEN_ERR			4		/* erreur d'ouverture du fichier contenant les licences */
#define	CPTCP_MALLOC_ERROR		5		/* erreur d'allocation mémoire				*/
#define	CPTCP_READ_ERROR			6		/* erreur de lecture du fichier contenant les licences	*/
#define	CPTCP_CRYPT_ERROR			7		/* erreur de décryptage d'un code			*/
#define	CPTCP_COMPUTER_ID_ERR	8		/* erreur de calcul de l'identifiant machine		*/

/* ---------------------------------------------------------------------------- */
/*		Definition des Codes produits					*/
/* ---------------------------------------------------------------------------- */
#define	PROTCODE_IDRA			20		/* Wabal	 */
#define	PROTCODE_OTR			21		/* Otr    */
#define  PROTCODE_BDANET		31		/* bdanet */
#define	PROT_COMPANY			"Amenesik / Sologic  "

/* ---------------------------------------------------------------------------- */
/*		Pour la lecture de la registry					*/
/* ---------------------------------------------------------------------------- */
#define	ROOT_KEY						"HKEY_LOCAL_MACHINE"
#define	PROT_PROLOGUE_REG_KEY	"SOFTWARE\\Amenesik / Sologic  \\Common"
#define	PROT_PROLOGUE_VALUE		"cptcp_path"

/* ---------------------------------------------------------------------------- */
/*		Declaration des fonctions de la protection			*/
/* ---------------------------------------------------------------------------- */
int (*ProtInit) (long* chk);
int (*ProtCheck) (int ProductCode, char* ProductVers, char* ProductName, char* CompanyName, BOOL bVerbose, int* nbAccess);

static char		ThF[] = "1mxztplk";	/* 1=protection testée 0=protection nontestée */
static HANDLE	TseProtMutex      = NULL;


// ********************************************************************************************************
// * ValideProt
// * Validation de la protection en fonction du code produit
// * 
// * retour: 0=OK, n=erreur
// * 
// ********************************************************************************************************
int ValideProt(int ProductCode, char* ProductVers, char* ProductName, BOOL bVerbose, int* pNbAccess)
{
	HKEY				rkey;				/* Handle registry */
	char				lProtPath[_MAX_PATH+1];
	char				lCurrentDir[_MAX_PATH+1];
	unsigned long	llgProtPath	= _MAX_PATH+1;
	HINSTANCE		HdleLib		= NULL;
	long				lnbSecond	= 0;
	long				a		= 0;
	long				b		= 0;
	BOOL				lVerbose	= FALSE;


#ifdef PATCHPROT
	if (ThF[0] == '0')	
	{
		return 0;
	}
#endif

	// ------------------------------------------------------------------------------
	// Recherche du chemin de la protection dans la base de registres
	// ------------------------------------------------------------------------------

	memset(lProtPath, 0x00, _MAX_PATH+1);

	if (RegOpenKeyEx((HKEY)HKEY_LOCAL_MACHINE, PROT_PROLOGUE_REG_KEY, 0, KEY_QUERY_VALUE, &rkey) != ERROR_SUCCESS)
		return 1 ;

	if (RegQueryValueEx(rkey, PROT_PROLOGUE_VALUE, NULL, NULL, lProtPath, &llgProtPath) != ERROR_SUCCESS)
	{
		RegCloseKey(rkey);
		return 2;
	}

	RegCloseKey(rkey);

	if (!*lProtPath)
		return 3;

	// ------------------------------------------------------------------------------
	// Positionnement du repertoire courant a celui de la protection pour charger
	// correctement les differentes DLL associes a cette derniere
	// ------------------------------------------------------------------------------
	memset(lCurrentDir, 0x00, _MAX_PATH+1);
	if (!GetCurrentDirectory(_MAX_PATH+1, lCurrentDir))
		return 4;

	if (lProtPath[llgProtPath-1] != '\\')
		strcat(lProtPath, "\\");

	if (!SetCurrentDirectory(lProtPath))
		return 5;

	// ------------------------------------------------------------------------------
	// Chargement de la DLL de protection
	// ------------------------------------------------------------------------------
	strcat(lProtPath, "cptcp_lib.dll");

	if ( (HdleLib = LoadLibrary(lProtPath)) == NULL)
	{
		SetCurrentDirectory(lCurrentDir);
		return 6;
	}

	ProtInit = (int (*) (long *chk))
		GetProcAddress(HdleLib, "cptcp_init");

	ProtCheck= (int (*) (int ProductCode, char* ProductVers, char* ProductName, char* CompanyName, BOOL bVerbose, int* pNbAccess))
		GetProcAddress(HdleLib, "cptcp_check");

	if ( (ProtInit == NULL) || (ProtCheck == NULL))
	{
		FreeLibrary(HdleLib);
		SetCurrentDirectory(lCurrentDir);
		return 7;
	}

	// ------------------------------------------------------------------------------
	// Initialisation de la protection
	// ------------------------------------------------------------------------------
	lnbSecond = GetTickCount();
	a = lnbSecond;
	if (ProtInit(&lnbSecond) != CPTCP_OK)
	{
		FreeLibrary(HdleLib);
		SetCurrentDirectory(lCurrentDir);
		return 8;
	}

	/* Verification de la valeur controle */
	b = a ^ 987324L;
	a = b & 1256895L;
	b = a / 11;
	a = b * 9;
	if (a != lnbSecond)
	{
		FreeLibrary(HdleLib);
		SetCurrentDirectory(lCurrentDir);
		return 9;
	}

	// ------------------------------------------------------------------------------
	// Verification de la protection
	// ------------------------------------------------------------------------------
	//#BG 04/12/06: On obtient une erreur sous VMWare (Win2003 en particulier)
	// lors du 1er appel à cette fonction après CWinApp::OpenDocumentFile()!?!?
	// Un 2ème appel est correct!?!?
	if (ProtCheck(ProductCode, ProductVers, ProductName, PROT_COMPANY, bVerbose /*Diags:O, Erreurs:N*/, pNbAccess) != CPTCP_OK)
	{
		// Nouvel essai!
		*pNbAccess = 1;
		if (ProtCheck(ProductCode, ProductVers, ProductName, PROT_COMPANY, bVerbose /*Diags:O, Erreurs:O*/, pNbAccess) != CPTCP_OK)
		{
			FreeLibrary(HdleLib);
			SetCurrentDirectory(lCurrentDir);
			return 10;
		}
	}


	// ------------------------------------------------------------------------------
	// Verif du nombre d'acces
	// ------------------------------------------------------------------------------
	if (!pNbAccess)
	{
		FreeLibrary(HdleLib);
		SetCurrentDirectory(lCurrentDir);
		return 11;
	}

	// ------------------------------------------------------------------------------
	// Accepté
	// ------------------------------------------------------------------------------
	FreeLibrary(HdleLib);
	SetCurrentDirectory(lCurrentDir);
	return 0;
}

// ********************************************************************************************************
// * ValideNbAccessByLaunch
// * Validation du nombre d'accès
// * 
// * retour: 0=OK, n=erreur
// * 
// ********************************************************************************************************
int ValideNbAccessByLaunch(char* ProductName, int NbAccess)
{
#ifdef PATCHPROT
	if (ThF[0] == '0')	
	{
		return 0;
	}
#endif

	if (NbAccess == 0)
		return 1;

	else if (NbAccess == 1)
	{
		// Config monoposte, alors on verifie.
		// Execution dans console TSE, on a pas le droit, on remonte l'erreur.
		if (GetSystemMetrics(SM_REMOTESESSION) != 0)
			return 2;
	}

	else
	{
		// Mode TSE
		if(GetSystemMetrics(SM_REMOTESESSION) != 0)
		{
			// Execution dans console TSE.
			// Recherche d'une session dispo.
			int i = 0;
			char tnm[_MAX_PATH];
			BOOL RunOk = FALSE;
			
			while((i < NbAccess) && (!RunOk))
			{
				sprintf(tnm, "Global\\%s_MUTEX_%i", ProductName, i);
				if ((TseProtMutex=CreateMutex(0, FALSE, tnm)) != NULL)
				{
					if(WaitForSingleObject(TseProtMutex, 0) == WAIT_OBJECT_0)
						RunOk = TRUE;
					else
					{
						CloseHandle(TseProtMutex);
						TseProtMutex = NULL;
					}
				}
				i++;
			}

			if (!RunOk)
				return 3;
		}
	}

	return 0;
}

// ********************************************************************************************************
// * FreeNbAccess
// ********************************************************************************************************
void FreeNbAccess(void)
{
	if (TseProtMutex)
	{
		CloseHandle(TseProtMutex);
		TseProtMutex=NULL;
	}
}