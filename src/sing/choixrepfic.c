/* -------------------------------------------------------------- */
/* GWB le 13/06/2006 : fenetre de choix de fichier ou repertoires */
/* -------------------------------------------------------------- */
#include "allocate.h"
#ifdef WIN32
#define __WINDOWS_SOURCE__		/* source pour Windows */
#define WIN1632
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include "sing.h"
#include "singabal.h"
#include "Shlobj.h"
#include "wabaldef.h"
#include "pubregkey.h"
#include "pubectx.h"
#include "vobjapi.h"
#include "singprot.h"
#include "fnparser.h"
#endif

#ifdef WIN32
int CALLBACK BrowseNotify(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
	char	Rep [256];

	switch (uMsg)
	{
	case BFFM_INITIALIZED:
		if (lpData) SendMessage(hwnd,BFFM_SETSELECTION,TRUE,lpData);
		break;

	case BFFM_SELCHANGED:
		if (!SHGetPathFromIDList ((LPITEMIDLIST) lParam, Rep))
			SendMessage (hwnd,BFFM_ENABLEOK,0,0);
		break;

	default:
		return(0);
	}

	return(1);
}
#endif

int ChoixRepPlus(char *path, char *libelle)
{
int i;
char crep[MAX_PATH]="\0";

if (ChoixRep(crep,libelle))
	{
	for (i=strlen(path);(i) && (path[i]<=' ');i--);
	if (path[i]>' ') i++;
	path[i]=0;
	if (i) strcat(path,";");
	strcat(path,crep);
	return(1);
	};
return(0);
}


int ChoixRep(char *path, char *libelle)
{
#ifdef WIN32
	char	Rep [MAX_PATH];
	LPMALLOC alloc;
	BOOL bSuccess;
	LPITEMIDLIST pidl;
	BROWSEINFO bi;


	bi.hwndOwner = GetMainWindowHandle();	/* fenetre parent */
	bi.pidlRoot = NULL;
	bi.pszDisplayName = NULL;
	bi.lpszTitle = libelle;
	bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_USENEWUI;
	bi.lpfn = BrowseNotify;
	if (strlen(path)) 
		bi.lParam = (long)path;
	else
		bi.lParam=(long)0;

	pidl = SHBrowseForFolder(&bi);
	bSuccess = SHGetPathFromIDList(pidl, Rep);
	
	// Desallouer pidl

	if (SHGetMalloc(&alloc) == NOERROR)
	{		
		if (bi.pidlRoot)
		{
			alloc->lpVtbl->Free(alloc,(LPITEMIDLIST)bi.pidlRoot);
		}

		alloc->lpVtbl->Free(alloc,pidl);
		alloc->lpVtbl->Release (alloc);
	}


	if (bSuccess)
	{
		strcpy(path,Rep);
		return (1);
	}
	else
		return (0);

#else
return(0);
#endif
}

#ifdef WIN32
int ChoixFic(char **result,int type_fic,char *origine)
{
OPENFILENAME desc_open;
char *dup_WidgetFileNames, *a;
char *WidgetFileNamesDescription,*b,*c;
int i,j;
char szFile[MAX_PATH] = "\0",InitPath[MAX_PATH]="\0",ShortName[MAX_PATH],ShortPath[MAX_PATH];
BOOL Result;
char svcwd[MAX_PATH];

getcwd(svcwd,MAX_PATH);	/* sauvegarde repertoire courant */

switch (visual_national_language(-1))
	{
	case 0:
		WidgetFileNamesDescription=allocate_string(en_WidgetFileNamesDescription);
	    desc_open.lpstrTitle = "Choose a File";
		break;

	case 1:
		WidgetFileNamesDescription=allocate_string(fr_WidgetFileNamesDescription);
		desc_open.lpstrTitle = "Choisir un fichier";
		break;

	default:
		WidgetFileNamesDescription=allocate_string(en_WidgetFileNamesDescription);
	    desc_open.lpstrTitle = "Choose a File";
		break;
	};
b=WidgetFileNamesDescription;

dup_WidgetFileNames=allocate_string(WidgetFileNames);
a=dup_WidgetFileNames;

if ((desc_open.lpstrFilter=allocate(strlen(WidgetFileNames)+strlen(WidgetFileNamesDescription)+16))==0)
	return(27);
c=(char *)desc_open.lpstrFilter;

for (i=0;i<WIDGET_FILE_LIMIT;i++)
	{
	if (strchr(a,'|')) *strchr(a,'|')=0;
	if (strchr(b,'|')) *strchr(b,'|')=0;
	strcpy(c,b);
	c+=strlen(c)+1;
	strcpy(c,a);
	if (i==type_fic)     desc_open.lpstrDefExt = c;
	a+=strlen(a)+1;
	b+=strlen(b)+1;
	c+=strlen(c)+1;
	};
strcpy(c,"\0");	/* ajoute un double 0 en fin de chaine */




if (Context.file_path[type_fic]==0) charger_context_file_path();

	desc_open.lStructSize=sizeof(OPENFILENAME);
    desc_open.hwndOwner         = GetMainWindowHandle();	/* fenetre parent */
    desc_open.hInstance         = GetInstanceHandle();

    desc_open.lpstrCustomFilter = NULL;
    desc_open.nMaxCustFilter    = 0;
    desc_open.nFilterIndex      = type_fic+1;
    desc_open.lpstrFile         = szFile;
    desc_open.nMaxFile          = sizeof(szFile);
    desc_open.lpstrFileTitle    = NULL;
    desc_open.nMaxFileTitle     = 0;

	if ((origine) && (strlen(origine)))
		{
		InitPath[0]=0;
		fn_parser( origine, InitPath, 0x0007 );
		desc_open.lpstrInitialDir=InitPath;
		fn_parser( origine, szFile, 0x0008 );
		}
	else
		desc_open.lpstrInitialDir=NULL;

	if (!InitPath[0]) desc_open.lpstrInitialDir   = Context.file_path[type_fic];

    desc_open.nFileOffset       = 0;
    desc_open.nFileExtension    = 0;

    desc_open.lCustData         = 0L;
	desc_open.lpfnHook 		   = NULL;
	desc_open.lpTemplateName    = NULL;
    desc_open.Flags             = OFN_SHOWHELP | OFN_EXPLORER;

    Result=GetOpenFileName(&desc_open);

	chdir(svcwd);	/* restaure repertoire courant */
	liberate(WidgetFileNamesDescription);
	liberate(dup_WidgetFileNames);
	liberate((char *)desc_open.lpstrFilter);


	i=0;
	if (Context.file_path[type_fic])
		{
		GetShortPathName(desc_open.lpstrFile,ShortName,sizeof(ShortName));
		GetShortPathName(Context.file_path[type_fic],ShortPath,sizeof(ShortPath));
		if (!strnicmp(ShortPath,ShortName,strlen(ShortPath)))
			{
				/* compter les antislach pour savoir quoi garder */
			for (j=1,i=(int)strlen(ShortPath)+1;i<(int)strlen(ShortName);i++)
				if (ShortName[i]=='\\') j++;
			i=strlen(desc_open.lpstrFile);
			while ((j) && (i))
				{
				i--;
				while ((i) && (desc_open.lpstrFile[i]!='\\')) i--;
				if (desc_open.lpstrFile[i]=='\\') j--;
				};
			if (!j) i++;
			};
		};

	if ((Result) && ((*result=allocate_string(&desc_open.lpstrFile[i]))!=0)) return(0);
	
	return(27);
}
