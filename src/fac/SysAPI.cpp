// ***********************************************************************************************
// * SysAPI.cpp
// ***********************************************************************************************

#include "bda.h"
#include "FacTrace.h"

#include "CstExt.h"
#include "CstInt.h"
#include "SysAPI.h"

#if defined(BDA_WIN32)
#include <direct.h>
#include <stdio.h>
#include <io.h>

#elif defined (BDA_UNIX)
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#elif defined(BDA_TWIN16)
#include <dir.h>
#include <io.h>
#include <string.h>
#include <fcntl.h>

#endif

#include <errno.h>

#define CI_MODULE_ID 0x0004

// ****************************************************************************
// * Ces constantes proviennent de l'exécuteur (fichier pubregkey.h)
// ****************************************************************************

#define REG_MAX_KEY			      128
#define REG_CONFIG_ABAL_ROOT_KEY	"Software\\Prologue Software\\Abal Criteria\\Abal\\"
#define REG_ABAL_ENVIRON_KEY		"Abal~Environ"

// ****************************************************************************
// * Ces fonctions proviennent de l'exécuteur (fichier wexa.c)
// * avec adaptations sur les codes retour
// ****************************************************************************

#if defined(BDA_WIN32) 

/* --------------------------------------------------------------------------
 *
 * FCT GetRegistryString
 *
 *	Lit la donnée associée à une valeur dans le Registry.
 *
 *	E/ 
 *	S/ Longueur de la donnée retournée.
 *
 */
short GetRegistryString(LPCSTR Key, LPCSTR Value, LPSTR Data, long DataLength, long* pLength)
{
	HKEY	KeyHandle;
	char	FullKey[REG_MAX_KEY];
	DWORD	Type;
	DWORD	Length;
	LONG 	Res;

	Length = DataLength;

	wsprintf(FullKey, "%s%s", (LPSTR)REG_CONFIG_ABAL_ROOT_KEY, (LPSTR)Key);

	if (_strnicmp((LPSTR)Value,(LPSTR)"SYS_", 4))
		Res = RegOpenKeyEx(HKEY_CURRENT_USER, FullKey, 0, KEY_READ, &KeyHandle);	
	else
		Res = RegOpenKeyEx(HKEY_LOCAL_MACHINE, FullKey, 0, KEY_READ, &KeyHandle);	

	if (Res == ERROR_SUCCESS)
	{
		// Read the value.
		Res = RegQueryValueEx(KeyHandle, (LPCTSTR)Value, 0, &Type, (LPBYTE)Data, &Length);
		RegCloseKey(KeyHandle);
	}


	*pLength = Length;

	if (Res == ERROR_MORE_DATA)
      return ERR_SIZE;
	else if (Res != ERROR_SUCCESS)
      return ERR_KEY;

	return NO_ERRORS;
}


#endif // BDA_WIN32

// ****************************************************************************
// ****************************************************************************
// * FIN
// ****************************************************************************
// ****************************************************************************


// ****************************************************************************
// * SysMkDir
// ****************************************************************************
short SysMkDir(const char * sFileOri, unsigned short Flags)
{
MI_TRACE_DCL_TFN("SysMkDir");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN sFileOri='%s'",sFileOri));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN Flags=%04X"   ,Flags));

#if defined(BDA_WIN32) 
// --- WIN32 ----------------------------------------------------------------
if (!Portable_mkdir(sFileOri))
   ret = NO_ERRORS;
else
   {
   int InternalError = errno;
   MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN errno=%d",InternalError));
   switch(InternalError)
      {
      case EEXIST: ret = ERR_EXIST ; break;
      case ENOENT: ret = ERR_NOFILE; break;
      default:     ret = ERR_WRITE ; break;
      }
   }

#elif defined (BDA_UNIX)
// --- LINUX ---------------------------------------------------------------
mode_t mode;

mode = 0x0777;
if (!Portable_mkdir(sFileOri,mode))
   ret = NO_ERRORS;
else
   {
   int InternalError = errno;
   MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN errno=%d",InternalError));
   switch(InternalError)
      {
      case EEXIST:       ret = ERR_EXIST ; break;
      case EFAULT:       ret = ERR_WRITE ; break;
      case EACCES:       ret = ERR_ACCESS; break;
      case ENAMETOOLONG: ret = ERR_PARAM ; break;
      case ENOENT:       ret = ERR_NOFILE; break;
      case ENOTDIR:      ret = ERR_NOFILE; break;
      case ENOMEM:       ret = ERR_MEM   ; break;
      case EROFS:        ret = ERR_WRITE ; break;
      case ELOOP:        ret = ERR_PARAM ; break;
      case ENOSPC:       ret = ERR_FULL  ; break;
      default:           ret = ERR_WRITE ; break;
      }
   }

#elif defined(BDA_TWIN16)
// --- TWIN ----------------------------------------------------------------
if (!Portable_mkdir(sFileOri))
   ret = NO_ERRORS;
else
   {
   int InternalError = errno;
   MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN errno=%d",InternalError));
   switch(InternalError)
      {
      case EACCES: ret = ERR_EXIST ; break;
      case ENOENT: ret = ERR_NOFILE; break;
      default:     ret = ERR_WRITE ; break;
      }
   }

#endif
// -------------------------------------------------------------------------

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * SysRmDir
// ****************************************************************************
short SysRmDir(const char * sFileOri)
{
MI_TRACE_DCL_TFN("SysRmDir");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN sFileOri='%s'",sFileOri));

#if defined(BDA_WIN32)
// --- WIN32 ----------------------------------------------------------------
if (!Portable_rmdir(sFileOri))
   ret = NO_ERRORS;
else
   {
   int InternalError = errno;
   MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN errno=%d",InternalError));
   switch(InternalError)
      {
      case ENOTEMPTY: ret = ERR_EXIST ; break;
      case ENOENT:    ret = ERR_NOFILE; break;
      default:        ret = ERR_WRITE ; break;
      }
   }

#elif defined (BDA_UNIX)
// --- LINUX ---------------------------------------------------------------
if (!Portable_rmdir(sFileOri))
   ret = NO_ERRORS;
else
   {
   int InternalError = errno;
   MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN errno=%d",InternalError));
   switch(InternalError)
      {
      case EPERM:        ret = ERR_ACCESS; break;
      case EFAULT:       ret = ERR_WRITE ; break;
      case EACCES:       ret = ERR_ACCESS; break;
      case ENAMETOOLONG: ret = ERR_PARAM ; break;
      case ENOENT:       ret = ERR_NOFILE; break;
      case ENOTDIR:      ret = ERR_NOFILE; break;
      case ENOTEMPTY:    ret = ERR_EXIST ; break;
      case EBUSY:        ret = ERR_BUSY  ; break;
      case ENOMEM:       ret = ERR_MEM   ; break;
      case EROFS:        ret = ERR_WRITE ; break;
      case ELOOP:        ret = ERR_PARAM ; break;
      default:           ret = ERR_WRITE ; break;
      }
   }

#elif defined(BDA_TWIN16)
// --- TWIN ----------------------------------------------------------------
if (!Portable_rmdir(sFileOri))
   ret = NO_ERRORS;
else
   {
   int InternalError = errno;
   MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN errno=%d",InternalError));
   switch(InternalError)
      {
      case EACCES: ret = ERR_EXIST ; break;
      case ENOENT: ret = ERR_NOFILE; break;
      default:     ret = ERR_WRITE ; break;
      }
   }

#endif
// -------------------------------------------------------------------------

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * SysNgfUpdate
// ****************************************************************************
short SysNgfUpdate(const char * sFileOri)
{
MI_TRACE_DCL_TFN("SysNgfUpdate");
short ret = NO_ERRORS;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN sFileOri='%s'",sFileOri));

#if defined(BDA_TWIN16)

_fmode = O_NGF_LNWR;
FILE* h = fopen( sFileOri, "r+b");
if (h)
   fclose(h);
else
   ret = (errno==ENOENT) ? ERR_NOFILE : ERR_ACCESS;

#endif

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * SysGetAbalEnv
// * La fonction balaye le fichier à la recherche de l'identification de la 
// * version en supposant que *PRL@INFO* se situe avant *PRL@BUILD*.
// ****************************************************************************
short SysGetAbalEnv(const char * sVarOri, char * Buf, long LgBuf, long* pLg )
{
MI_TRACE_DCL_TFN("SysGetAbalEnv");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN LgBuf=%ld sVarOri='%s'",LgBuf,sVarOri));


// ----------------------------------------------------------------------------
// - Analyse du paramètre d'entrée
// ----------------------------------------------------------------------------

if (sVarOri[0]=='\0')
   MI_TRACE_RETURN(ERR_PARAM);

memset(Buf, ' ', (int) LgBuf);
*pLg = 0;

// ----------------------------------------------------------------------------
// - Traitement selon l'OS
// ----------------------------------------------------------------------------

#if defined(BDA_WIN32)
// --- WIN32 ----------------------------------------------------------------

char* TmpBuf = new char [LgBuf];
long  TmpLg;

if (Buf==NULL)
   MI_TRACE_RETURN(ERR_MEM);

ret = GetRegistryString(REG_ABAL_ENVIRON_KEY, "SYS_ZLIBPATH", TmpBuf, LgBuf, &TmpLg);

if ( (ret==NO_ERRORS) && (TmpLg!=0) )
   {
   *pLg = TmpLg - 1;
   memcpy(Buf,TmpBuf,*pLg);
   }

delete TmpBuf;

#elif defined (BDA_UNIX)
// --- LINUX ---------------------------------------------------------------
// en attendant que quelque chose soit implémenté sous cet OS,
// on renvoie une valeur par défaut pour la clé SYS_ZLIBPATH uniquement
//
// We know what to do now so don't fuck with this !!!!!!!!!!!! ijm
//

	const char * 	vptr;
	int	vlen;

	if (!(vptr = getenv("SYS_ZLIBPATH")))
		vptr = "/usr/share/zlibrary"; 

	if ((vlen =strlen(vptr)) >= (unsigned int)LgBuf)
		MI_TRACE_RETURN(ERR_SIZE);

	if (strcmp(sVarOri,"SYS_ZLIBPATH")==0) {
		memcpy(Buf,vptr,vlen);
		*pLg = vlen;
		ret = NO_ERRORS;
		}
	else	ret = ERR_KEY;

#elif defined(BDA_TWIN16)
// --- TWIN ----------------------------------------------------------------
// en attendant que quelque chose soit implémenté sous cet OS,
// on renvoie une valeur par défaut pour la clé SYS_ZLIBPATH uniquement
char DefBuf[] = "is\\zlibrary"; 

if (strlen(DefBuf) >= (unsigned int)LgBuf)
   MI_TRACE_RETURN(ERR_SIZE);

if (strcmp(sVarOri,"SYS_ZLIBPATH")==0)
   {
   memcpy(Buf,DefBuf,strlen(DefBuf));
   *pLg = strlen(DefBuf);
   ret = NO_ERRORS;
   }
else
   ret = ERR_KEY;

#endif
// -------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// - Fin
// ----------------------------------------------------------------------------

MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Lg=%ld",*pLg));
MI_TRACE((CI_TRA_F_DUMP,CI_MODULE_ID,TFN,"OUT Buf", Buf, *pLg));
MI_TRACE_RETURN(ret);
}

