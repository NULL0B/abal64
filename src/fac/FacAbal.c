// ****************************************************************************
// * FacAbal.cpp
// * BDA module
// * 
// * Pour la trace valeurs de CI_MODULE_ID :
// * 0x1000         = FacAbal
// * 0x0001, 0x0010 = Strm niveau API, fonctions internes  
// * 0x0002, 0x0020 = File niveau API, fonctions internes  
// * 0x0004, 0x0040 = Sys  niveau API, fonctions internes  
// * 
// ****************************************************************************
// * 
// * ATTENTION 
// * 
// * l'ancien code de la version russe est désactivé
// * 
// * pour le réactiver : 
// * 1°) il faut chercher la chaine __RUSSIAN_CODE__ et enlever les commentaires
// *     dans ce fichier
// * 2°) il faut rajouter les fichiers TFile, TFileAPI et TFileInc .cpp et .h
// *     au projet
// * 
// ****************************************************************************

#define CI_MODULE_ID 0x1000

#include <stdlib.h>
#include <errno.h>

#include "bda.h"
extern LPBDA_INIT rt_init;

#include "FacTrace.h"
#include "FacVer.h"

#include "CstExt.h"
#include "CstInt.h"
#include "Table.h"
#include "StrmAPI.h"
#include "FileAPI.h"
#include "SysAPI.h"
#include "toolabal.h" 

// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
// - Variables globales
// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------

BDA rt_desc;     // description de la bibliotheque

#if defined(BDA_WIN32)
HINSTANCE	dll_handle;	// handle de la DLL
HWND			g_hwnd;
#endif

TI_TABLE       g_Table[CI_TABLE_SIZE];


// ****************************************************************************
// * StrmGetFree
// * %?  numéro logique disponible
// ****************************************************************************
EXAWORD BDA_API ___StrmGetFree(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD* pNoLog = (WORD*)a[0];

ret = (EXAWORD)StrmGetFree(pNoLog);
ToolAbal_SwapBytes(pNoLog);
return ret;
}

// ****************************************************************************
// * StrmOpen
// * %   numero logique
// * $   nom de fichier
// * %   flags
// ****************************************************************************
EXAWORD BDA_API ___StrmOpen(VOID FAR PTR FAR a[])
{
MI_TRACE_DCL_TFN("StrmOpen");
EXAWORD	ret;
char* FileNameC;
WORD NoLog;
WORD wFlags;

NoLog  = ToolAbal_WORD(a[0]);
wFlags = ToolAbal_WORD(a[2]);

MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,TFN,"-- preBegin"));
FileNameC = ToolAbal_CreateStrC(1);
ret = (EXAWORD)StrmOpen(NoLog,FileNameC,wFlags);
ToolAbal_DeleteStrC(FileNameC);
MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,TFN,"-- postEnd"));
return ret;
}

// ****************************************************************************
// * StrmReadChar
// * %   numero logique
// * $?  Caractère lu
// ****************************************************************************
EXAWORD	BDA_API ___StrmReadChar(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
char* pCar   = (char*)a[1];

ret = (EXAWORD)StrmReadByte(NoLog,pCar);
return ret;
}

// ****************************************************************************
// * StrmWriteChar
// * %   numero logique
// * $   Caractère écrit
// ****************************************************************************
EXAWORD	BDA_API ___StrmWriteChar(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
char* pCar   = (char*)a[1];

ret = (EXAWORD)StrmWriteByte(NoLog,*pCar);
return ret;
}

// ****************************************************************************
// * StrmReadByte
// * %   numero logique
// * #?  Caractère lu
// ****************************************************************************
EXAWORD BDA_API ___StrmReadByte(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
char* pCar   = (char*)a[1];

ret = (EXAWORD)StrmReadByte(NoLog,pCar);
return ret;
}

// ****************************************************************************
// * StrmWriteByte
// * %   numero logique
// * #   Caractère écrit
// ****************************************************************************
EXAWORD	BDA_API ___StrmWriteByte(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
char  Car   = *(char*)a[1];

ret = (EXAWORD)StrmWriteByte(NoLog,Car);
return ret;
}

// ****************************************************************************
// * StrmReadBuf
// * StrmWriteBuf
// * StrmLnRead
// * StrmLnAppend
// * StrmLnReadSec
// * %   numero logique
// * $?  Buffer
// * %   Taille du buffer
// * %?  Taille lue
// ****************************************************************************
EXAWORD	BDA_API ___StrmReadBuf(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
WORD  LgBuf  = ToolAbal_WORD(a[2]);
char* Buf    = (char*)a[1];
WORD* pLg    = (WORD*)a[3];
long  Lg;

ret = (EXAWORD)StrmReadBuf(NoLog,Buf,(long)LgBuf,&Lg);
*pLg = (WORD)Lg;
ToolAbal_SwapBytes(pLg);
return ret;
}

// ****************************************************************************
EXAWORD	BDA_API ___StrmWriteBuf(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
WORD  LgBuf  = ToolAbal_WORD(a[2]);
char* Buf    = (char*)a[1];
WORD* pLg    = (WORD*)a[3];
long  Lg;

ret = (EXAWORD)StrmWriteBuf(NoLog,Buf,(long)LgBuf,&Lg);
*pLg = (WORD)Lg;
ToolAbal_SwapBytes(pLg);
return ret;
}

// ****************************************************************************
EXAWORD	BDA_API ___StrmLnRead(VOID FAR PTR FAR a[])
{
//MI_TRACE_DCL_TFN("StrmLnRead");
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
WORD  LgBuf  = ToolAbal_WORD(a[2]);
BYTE* Buf    = (char*)a[1];
WORD* pLg    = (WORD*)a[3];
long  Lg;

//MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,TFN,"-- preBegin"));
ret = (EXAWORD)StrmLnRead(NoLog,Buf,(long)LgBuf,&Lg);
*pLg = (WORD)Lg;
ToolAbal_SwapBytes(pLg);
//MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,TFN,"-- postEnd"));
return ret;
}

// ****************************************************************************
EXAWORD	BDA_API ___StrmLnAppend(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
WORD  LgBuf  = ToolAbal_WORD(a[2]);
char* Buf    = (char*)a[1];
WORD* pLg    = (WORD*)a[3];
long  Lg;

ret = (EXAWORD)StrmLnWrite(NoLog,Buf,(long)LgBuf,&Lg);
*pLg = (WORD)Lg;
ToolAbal_SwapBytes(pLg);
return ret;
}

// ****************************************************************************
EXAWORD	BDA_API ___StrmLnReadSec(VOID FAR PTR FAR a[])
{
MI_TRACE_DCL_TFN("StrmLnReadSec");
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
WORD  LgBuf  = ToolAbal_WORD(a[2]);
BYTE* Buf    = (char*)a[1];
WORD* pLg    = (WORD*)a[3];
long  Lg;

MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,TFN,"-- preBegin"));
ret = (EXAWORD)StrmLnReadSec(NoLog,Buf,(long)LgBuf,&Lg);
*pLg = (WORD)Lg;
ToolAbal_SwapBytes(pLg);
MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,TFN,"-- postEnd"));
return ret;
}

// ****************************************************************************
// * StrmLnReadKey
// * %   numero logique
// * $?  Buffer_1
// * %   Taille du buffer_1
// * %?  Taille lue
// * $?  Buffer_2
// * %   Taille du buffer_2
// * %?  Taille lue
// ****************************************************************************
EXAWORD	BDA_API ___StrmLnReadKey(VOID FAR PTR FAR a[])
{
MI_TRACE_DCL_TFN("StrmLnReadSec");
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
WORD  LgBuf  = ToolAbal_WORD(a[2]);
WORD  LgVal  = ToolAbal_WORD(a[5]);
BYTE* Buf    = (char*)a[1];
BYTE* Val    = (char*)a[4];
WORD* pLgBuf = (WORD*)a[3];
WORD* pLgVal = (WORD*)a[6];
long  LgLueBuf;
long  LgLueVal;

MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,TFN,"-- preBegin"));
ret = (EXAWORD)StrmLnReadKey(NoLog,Buf,(long)LgBuf,&LgLueBuf,Val,(long)LgVal,&LgLueVal);
*pLgBuf = (WORD)LgLueBuf;
*pLgVal = (WORD)LgLueVal;
ToolAbal_SwapBytes(pLgBuf);
ToolAbal_SwapBytes(pLgVal);
MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,TFN,"-- postEnd"));
return ret;
}

// ****************************************************************************
// * StrmFindBuf
// * %   numero logique
// * $?  Buffer
// * %   Taille du buffer
// * %   vrai=seek après
// ****************************************************************************
EXAWORD	BDA_API ___StrmFindBuf(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
char* Buf    = (char*)a[1];
WORD  LgBuf  = ToolAbal_WORD(a[2]);
WORD  IsAfter= ToolAbal_WORD(a[3]);

ret = (EXAWORD)StrmFindBuf(NoLog,Buf,(long)LgBuf,IsAfter);
return ret;
}

// ****************************************************************************
// * StrmFindByteInColl
// * %   numero logique
// * $?  Buffer
// * %   Taille du buffer
// * #?  octet trouvé
// * %   vrai=seek après
// ****************************************************************************
EXAWORD	BDA_API ___StrmFindByteInColl(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
char* Buf    = (char*)a[1];
WORD  LgBuf  = ToolAbal_WORD(a[2]);
WORD  IsAfter= ToolAbal_WORD(a[4]);
char* pc     = (char*)a[3];

ret = (EXAWORD)StrmFindByteInCollection(NoLog,Buf,(long)LgBuf,pc,IsAfter);
return ret;
}

// ****************************************************************************
// * StrmFindByte
// * %   numero logique
// * #   Caractère écrit
// * %   vrai=seek après
// ****************************************************************************
EXAWORD	BDA_API ___StrmFindByte(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
char  Car    = *(char*)a[1];
WORD  IsAfter= ToolAbal_WORD(a[2]);

ret = (EXAWORD)StrmFindByte(NoLog,Car,IsAfter);
return ret;
}

// ****************************************************************************
// * StrmFindChar
// * %   numero logique
// * $   Caractère écrit
// * %   vrai=seek après
// ****************************************************************************
EXAWORD	BDA_API ___StrmFindChar(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
char* pCar   = (char*)a[1];
WORD  IsAfter= ToolAbal_WORD(a[2]);

ret = (EXAWORD)StrmFindByte(NoLog,*pCar,IsAfter);
return ret;
}

// ****************************************************************************
// * StrmLnFileFormat
// * %  numero logique
// * %?  Booléen
// * %?  Booléen
// ****************************************************************************
EXAWORD	BDA_API ___StrmLnFileFormat(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog = ToolAbal_WORD(a[0]);
WORD* pIsCr    = (WORD*)a[1];
WORD* pIsCtrlz = (WORD*)a[2];

ret = (EXAWORD)StrmLnFileFormat(NoLog,pIsCr,pIsCtrlz);
ToolAbal_SwapBytes(pIsCr);
ToolAbal_SwapBytes(pIsCtrlz);
return ret;
}

// ****************************************************************************
// * StrmSeek
// * StrmLnSeek
// * %       numero logique
// * * ou %  Offset
// * %       Origine
// ****************************************************************************
EXAWORD	BDA_API ___StrmSeek(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog = ToolAbal_WORD(a[0]);
long Offset = ToolAbal_GetLongFromRtArg(1,0,TRUE);
WORD Origin = (WORD)ToolAbal_GetLongFromRtArg(2,0,TRUE);

ret = (EXAWORD)StrmSeek(NoLog,Offset,Origin);
return ret;
}

// ****************************************************************************
EXAWORD	BDA_API ___StrmLnSeek(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD NoLog = ToolAbal_WORD(a[0]);
long Offset = ToolAbal_GetLongFromRtArg(1,0,TRUE);
WORD Origin = (WORD)ToolAbal_GetLongFromRtArg(2,0,TRUE);

ret = (EXAWORD)StrmLnSeek(NoLog,Offset,Origin);
return ret;
}

// ****************************************************************************
// * StrmLnSetTab
// * StrmLnSetPad
// * StrmLnSetFormFeed
// * %  numero logique
// * %  size
// ****************************************************************************
EXAWORD	BDA_API ___StrmLnSetTab(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
WORD  LgTab  = ToolAbal_WORD(a[1]);

ret = (EXAWORD)StrmLnSetExpandTab(NoLog,LgTab);
return ret;
}

// ****************************************************************************
EXAWORD	BDA_API ___StrmLnSetPad(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
WORD  IsPad  = ToolAbal_WORD(a[1]);

ret = (EXAWORD)StrmLnSetPad(NoLog,IsPad);
return ret;
}

// ****************************************************************************
EXAWORD	BDA_API ___StrmLnSetFormFeed(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog      = ToolAbal_WORD(a[0]);
WORD  IsFormFeed = ToolAbal_WORD(a[1]);

ret = (EXAWORD)StrmLnSetFormFeed(NoLog,IsFormFeed);
return ret;
}

// ****************************************************************************
// * StrmLnGetTab
// * StrmLnGetPad
// * StrmLnGetFormFeed
// * %   numero logique
// * *?  size
// ****************************************************************************
EXAWORD	BDA_API ___StrmLnGetPad(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
WORD* pIsPad = (WORD*)a[1];

ret = (EXAWORD)StrmLnGetPad(NoLog,pIsPad);
ToolAbal_SwapBytes(pIsPad);
return ret;
}

// ****************************************************************************
EXAWORD	BDA_API ___StrmLnGetTab(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
WORD* pLg    = (WORD*)a[1];

ret = (EXAWORD)StrmLnGetExpandTab(NoLog,pLg);
ToolAbal_SwapBytes(pLg);
return ret;
}

// ****************************************************************************
EXAWORD	BDA_API ___StrmLnGetFormFeed(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog       = ToolAbal_WORD(a[0]);
WORD* pIsFormFeed = (WORD*)a[1];

ret = (EXAWORD)StrmLnGetFormFeed(NoLog,pIsFormFeed);
ToolAbal_SwapBytes(pIsFormFeed);
return ret;
}

// ****************************************************************************
// * StrmLnInfoLine
// * %         numero logique
// * *? ou %?  Offset
// * *? ou %?  size
// ****************************************************************************
EXAWORD	BDA_API ___StrmLnInfoLine(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
long Offset;
long Size;

ret = (EXAWORD)StrmLnInfoLine(NoLog,&Offset,&Size);
ToolAbal_SetLongToRtArg(1,Offset);
ToolAbal_SetLongToRtArg(2,Size);
return ret;
}

// ****************************************************************************
// * StrmTell
// * StrmFileSize
// * StrmLnTell
// * StrmLnFileSize
// * StrmLnLen
// * StrmLnMaxLen
// * StrmLnGetTab
// * %         numero logique
// * *? ou %?  Offset ou size
// ****************************************************************************
EXAWORD	BDA_API ___StrmTell(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
long Offset;

ret = (EXAWORD)StrmTell(NoLog,&Offset);
ToolAbal_SetLongToRtArg(1,Offset);
return ret;
}

// ****************************************************************************
EXAWORD	BDA_API ___StrmFileSize(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
long Size;

ret = (EXAWORD)StrmFileSize(NoLog,&Size);
ToolAbal_SetLongToRtArg(1,Size);
return ret;
}

// ****************************************************************************
EXAWORD	BDA_API ___StrmLnTell(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
long Offset;

ret = (EXAWORD)StrmLnTell(NoLog,&Offset);
ToolAbal_SetLongToRtArg(1,Offset);
return ret;
}

// ****************************************************************************
EXAWORD	BDA_API ___StrmLnFileSize(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
long Size;

ret = (EXAWORD)StrmLnFileSize(NoLog,&Size);
ToolAbal_SetLongToRtArg(1,Size);
return ret;
}

// ****************************************************************************
EXAWORD	BDA_API ___StrmLnLen(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
long Size;

ret = (EXAWORD)StrmLnLength(NoLog,&Size);
ToolAbal_SetLongToRtArg(1,Size);
return ret;
}

// ****************************************************************************
EXAWORD	BDA_API ___StrmLnMaxLen(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);
long Size;

ret = (EXAWORD)StrmLnMaxLength(NoLog,&Size);
ToolAbal_SetLongToRtArg(1,Size);
return ret;
}

// ****************************************************************************
// * StrmClose
// * StrmFlush
// * StrmGetError
// * StrmClearError
// * StrmEof
// * StrmLnAnalyse
// * StrmLnEof
// * StrmLnIsLast
// * %         numero logique
// ****************************************************************************
EXAWORD	BDA_API ___StrmClose(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD NoLog  = ToolAbal_WORD(a[0]);

ret = (EXAWORD)StrmClose(NoLog);
return ret;
}

// ****************************************************************************
EXAWORD	BDA_API ___StrmFlush(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD NoLog  = ToolAbal_WORD(a[0]);

ret = (EXAWORD)StrmSave(NoLog);
return ret;
}

// ****************************************************************************
EXAWORD	BDA_API ___StrmGetError(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);

ret = (EXAWORD)StrmGetError(NoLog);
return ret;
}

// ****************************************************************************
EXAWORD	BDA_API ___StrmClearError(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);

ret = (EXAWORD)StrmClearError(NoLog);
return ret;
}

// ****************************************************************************
EXAWORD	BDA_API ___StrmEof(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);

ret = (EXAWORD)StrmEof(NoLog);
return ret;
}

// ****************************************************************************
EXAWORD	BDA_API ___StrmLnAnalyse(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);

ret = (EXAWORD)StrmLnAnalyse(NoLog);
return ret;
}

// ****************************************************************************
EXAWORD	BDA_API ___StrmLnEof(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);

ret = (EXAWORD)StrmLnEof(NoLog);
return ret;
}

// ****************************************************************************
EXAWORD	BDA_API ___StrmLnIsLast(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
WORD  NoLog  = ToolAbal_WORD(a[0]);

ret = (EXAWORD)StrmLnIsLast(NoLog);
return ret;
}

// ****************************************************************************
// * StrmLnFindSec
// * %         numero logique
// * $         Buffer section recherchée
// * %         Longueur buffer
// * %         IsCaseSensitive
// ****************************************************************************
EXAWORD	BDA_API ___StrmLnFindSec(VOID FAR PTR FAR a[])
{
MI_TRACE_DCL_TFN("StrmLnFindSec");
EXAWORD	ret;
WORD  NoLog      = ToolAbal_WORD(a[0]);
BYTE* Buf        = (char*)a[1];
WORD  LgBuf      = ToolAbal_WORD(a[2]);
WORD  IsCaseSens = ToolAbal_WORD(a[3]);

MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,TFN,"-- preBegin"));
ret = (EXAWORD)StrmLnFindSec(NoLog,Buf,(long)LgBuf,IsCaseSens);
MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,TFN,"-- postEnd"));

return ret;
}

// ****************************************************************************
// * StrmLnFindKey
// * %         numero logique
// * $         Buffer clé recherchée
// * %         Longueur buffer
// * $?        Buffer valeur de la clé
// * %         Longueur buffer
// * %?        Taille lue
// * %         IsCaseSensitive
// ****************************************************************************
EXAWORD	BDA_API ___StrmLnFindKey(VOID FAR PTR FAR a[])
{
MI_TRACE_DCL_TFN("StrmLnFindKey");
EXAWORD	ret;
WORD  NoLog      = ToolAbal_WORD(a[0]);
BYTE* Key        = (char*)a[1];
WORD  LgKey      = ToolAbal_WORD(a[2]);
BYTE* Val        = (char*)a[3];
WORD  LgVal      = ToolAbal_WORD(a[4]);
WORD* pLgVal     = (WORD*)a[5];
WORD  IsCaseSens = ToolAbal_WORD(a[6]);
long  LgLueVal;

MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,TFN,"-- preBegin"));
ret = (EXAWORD)StrmLnFindKey(NoLog,Key,(long)LgKey,Val,(long)LgVal,&LgLueVal,IsCaseSens);
*pLgVal = (WORD)LgLueVal;
ToolAbal_SwapBytes(pLgVal);
MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,TFN,"-- postEnd"));

return ret;
}

// ****************************************************************************
// * FileGetVersion
// * $         nom de fichier
// * $?        Buffer
// * %         Longueur buffer
// * %?        Longueur lue
// ****************************************************************************
EXAWORD	BDA_API ___FileGetVersion(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
char* FileNameC;
BYTE* Buf    = (char*)a[1];
WORD  LgBuf  = ToolAbal_WORD(a[2]);
WORD* pLg    = (WORD*)a[3];
long  Lg;

FileNameC = ToolAbal_CreateStrC(0);
ret = (EXAWORD)FileGetVersion(FileNameC,Buf,(long)LgBuf,&Lg);
ToolAbal_DeleteStrC(FileNameC);
*pLg = (WORD)Lg;
ToolAbal_SwapBytes(pLg);
return ret;
}

// ****************************************************************************
// * FileCpyExt
// * $                nom de fichier source
// * $                nom de fichier destination
// * %                flags
// * * ou % ou rien   Offset
// * * ou % ou rien   Size
// ****************************************************************************
EXAWORD	BDA_API ___FileCpyExt(VOID FAR PTR FAR a[])
{
MI_TRACE_DCL_TFN("FileCpy");
EXAWORD	ret;
char* FileOriC;
char* FileDesC;
WORD  Flags  = ToolAbal_WORD(a[2]);
long Offset;
long Size;

MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,TFN,"-- preBegin"));
Offset = ToolAbal_GetLongFromRtArg(3, 0,TRUE);
Size   = ToolAbal_GetLongFromRtArg(4,(DWORD)-1,TRUE);

FileOriC = ToolAbal_CreateStrC(0);
FileDesC = ToolAbal_CreateStrC(1);

ret = (EXAWORD)FileCpy(FileOriC,FileDesC,Flags,Offset,Size);
ToolAbal_DeleteStrC(FileOriC);
ToolAbal_DeleteStrC(FileDesC);

MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,TFN,"-- postEnd"));
return ret;
}

// ****************************************************************************
// * FileCmp
// * $          nom de fichier source
// * $          nom de fichier destination
// * %          flags
// * *? ou %?   Offset en sortie
// ****************************************************************************
EXAWORD	BDA_API ___FileCmp(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
char* FileOriC;
char* FileDesC;
WORD  Flags  = ToolAbal_WORD(a[2]);
long Offset;

FileOriC = ToolAbal_CreateStrC(0);
FileDesC = ToolAbal_CreateStrC(1);

ret = (EXAWORD)FileCmp(FileOriC,FileDesC,Flags,0,-1,&Offset);
if (ret==ERR_SEEK)
   ToolAbal_SetLongToRtArg(3,Offset);

ToolAbal_DeleteStrC(FileOriC);
ToolAbal_DeleteStrC(FileDesC);
return ret;
}

// ****************************************************************************
// * FileSize
// * $          nom de fichier source
// * %          flags
// * *? ou %?   Taille en sortie
// ****************************************************************************
EXAWORD	BDA_API ___FileSize(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
char* FileOriC;
WORD  Flags  = ToolAbal_WORD(a[1]);
long Size;

FileOriC = ToolAbal_CreateStrC(0);

ret = (EXAWORD)FileSize(FileOriC,Flags,&Size);
if (ret==NO_ERRORS)
   ToolAbal_SetLongToRtArg(2,Size);

ToolAbal_DeleteStrC(FileOriC);
return ret;
}

// ****************************************************************************
// * FileIniFind
// * $          nom de fichier source
// * $          nom de section
// * %          taille du nom de section
// * $          nom de clé
// * %          taille du nom de clé
// * $          valeur
// * %          taille de la valeur
// * %?         taille lue pour la valeur
// ****************************************************************************
EXAWORD	BDA_API ___FileIniFind(VOID FAR PTR FAR a[])
{
MI_TRACE_DCL_TFN("FileIniFind");
EXAWORD	ret;
char* FileOriC;
BYTE* Sec    = (char*)a[1];
WORD  LgSec  = ToolAbal_WORD(a[2]);
BYTE* Key    = (char*)a[3];
WORD  LgKey  = ToolAbal_WORD(a[4]);
BYTE* Val    = (char*)a[5];
WORD  LgVal  = ToolAbal_WORD(a[6]);
WORD* pLgVal = (WORD*)a[7];
long  LgLueVal;

MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,TFN,"-- preBegin"));

FileOriC = ToolAbal_CreateStrC(0);
ret = (EXAWORD)FileIniFind(FileOriC, Sec, (long)LgSec, Key, (long)LgKey, Val, (long)LgVal, &LgLueVal);
ToolAbal_DeleteStrC(FileOriC);

*pLgVal = (WORD)LgLueVal;
ToolAbal_SwapBytes(pLgVal);
MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,TFN,"-- postEnd"));
return ret;
}

// ****************************************************************************
// * SysMkDir
// * $          nom de fichier source
// * %          flags
// ****************************************************************************
EXAWORD	BDA_API ___SysMkDir(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
char* FileOriC;
WORD  Flags  = ToolAbal_WORD(a[1]);

FileOriC = ToolAbal_CreateStrC(0);
ret = (EXAWORD)SysMkDir(FileOriC,Flags);
ToolAbal_DeleteStrC(FileOriC);
return ret;
}

// ****************************************************************************
// * SysRmDir
// * SysNgfUpdate
// * $          nom de fichier source
// ****************************************************************************
EXAWORD	BDA_API ___SysRmDir(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
char* FileOriC;

FileOriC = ToolAbal_CreateStrC(0);
ret = (EXAWORD)SysRmDir(FileOriC);
ToolAbal_DeleteStrC(FileOriC);
return ret;
}

// ****************************************************************************
EXAWORD	BDA_API ___SysNgfUpdate(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
char* FileOriC;

FileOriC = ToolAbal_CreateStrC(0);
ret = (EXAWORD)SysNgfUpdate(FileOriC);
ToolAbal_DeleteStrC(FileOriC);
return ret;
}

// ****************************************************************************
// * SysGetAbalEnv
// * $         nom de variable
// * $?        Buffer
// * %         Longueur buffer
// * %?        Longueur lue
// ****************************************************************************
EXAWORD	BDA_API ___SysGetAbalEnv(VOID FAR PTR FAR a[])
{
EXAWORD	ret;
char* VarNameC;
BYTE* Buf    = (char*)a[1];
WORD  LgBuf  = ToolAbal_WORD(a[2]);
WORD* pLg    = (WORD*)a[3];
long  Lg;

VarNameC = ToolAbal_CreateStrC(0);
ret = (EXAWORD)SysGetAbalEnv(VarNameC,Buf,(long)LgBuf,&Lg);
ToolAbal_DeleteStrC(VarNameC);
*pLg = (WORD)Lg;
ToolAbal_SwapBytes(pLg);
return ret;
}

// *************************************************************************
// * INITIALISATION DE LA BIBLIOTHEQUE DYNAMIQUE
// *************************************************************************




// ****************************************************************************
// * banniere
// ****************************************************************************
VOID  banniere(VOID)
{
MI_TRACE_DCL_TFN("banniere");

  MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"'%s'",Banner_GetVersionID(g_TraCtx.Line,'2') ));
#ifndef	BDA_UNIX
  Banner_DisplayBanner();
#endif
}

/* --------------------------------------------------------------------------
 *
 * FCT InitRelais
 *
 *  Initialisation de la bibliotheque dynamique.
 *
 *  E/ indicateur du type de l'appelant
 *  S/ pointeur sur la description de la bibliotheque
 *
 * Notes :
 *  Sous MS/DOS standard et Amenesik / Sologic, l'appel direct des fonctions
 *  est effectue. Ailleurs (Unix, VMS, DOS etendu et Windows), on
 *  doit passer par des fonctions d'entete de conversion des arguments.
 *  Cf. l'utilitaire BDAGEN pour generer un squelette de fonctions
 *  d'entete et de fonction InitRelais.
 *
 */
VOID FAR PTR InitRelais()
{
short i;
MI_TRACE_DCL_TFN("InitRelais");

  MI_TRACE((CI_TRA_F_WARNING,CI_MODULE_ID,TFN,"Faccess '%s'",Banner_GetVersionID(MI_TRA_LINE,Banner_GetVersionStatus())));

  // Initialisations spécifiques
  for( i=0 ; i<CI_TABLE_SIZE ; i++ )
     {
     g_Table[i].ObjMem  = NULL;
     g_Table[i].ObjStrm = NULL;
     g_Table[i].IsLine  = 0;
     }

  // Signature de la bibliotheque : ici bibliotheque standard:
  if (rt_init != (VOID FAR PTR) 0L) 
    {
    rt_init->ordinaire.signature = BDA_ORDINAIRE;
    }

  // Fonctions d'affichage de la banniere et de fermeture de la bibliotheque:
  rt_desc.banniere = banniere;
  rt_desc.fin      = (VOID (FAR PTR)(void)) StrmCloseAll;

  // Tableau de description des fonctions de la bibliotheque:
  rt_desc.reserve = (VOID FAR PTR) 0L;

  i=0;                                                                  
                                                                        //Version = 1
                                                                        //Runtime = "fac"
                                                                        //;*PRL@INFO*$3:200
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmOpen;           //% StrmOpen(%,$,%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmClose;          //% StrmClose(%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmFlush;          //% StrmFlush(%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmGetError;       //% StrmGetError(%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmClearError;     //% StrmClearError(%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmReadByte;       //% StrmReadByte(%,#?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmWriteByte;      //% StrmWriteByte(%,#)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmReadBuf;        //% StrmReadBuf(%,$?,%,%?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmWriteBuf;       //% StrmWriteBuf(%,$,%,%?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmFindByte;       //% StrmFindByte(%,#,%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmFindBuf;        //% StrmFindBuf(%,$,%,%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmFindByteInColl; //% StrmFindByteInColl(%,$,%,#?,%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmSeek;           //% StrmSeek(%,%,%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmSeek;           //% StrmSeek_BCD(%,*,%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmTell;           //% StrmTell(%,%?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmTell;           //% StrmTell_BCD(%,*?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmFileSize;       //% StrmFileSize(%,%?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmFileSize;       //% StrmFileSize_BCD(%,*?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmEof;            //% StrmEof(%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnAnalyse;      //% StrmLnAnalyse(%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnRead;         //% StrmLnRead(%,$?,%,%?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnAppend;       //% StrmLnAppend(%,$,%,%?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnSeek;         //% StrmLnSeek(%,%,%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnSeek;         //% StrmLnSeek_BCD(%,*,%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnTell;         //% StrmLnTell(%,%?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnTell;         //% StrmLnTell_BCD(%,*?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnFileSize;     //% StrmLnFileSize(%,%?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnFileSize;     //% StrmLnFileSize_BCD(%,*?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnEof;          //% StrmLnEof(%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnLen;          //% StrmLnLen(%,%?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnLen;          //% StrmLnLen_BCD(%,*?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnSetTab;       //% StrmLnSetTab(%,%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnGetTab;       //% StrmLnGetTab(%,%?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnFileFormat;   //% StrmLnFileFormat(%,%?,%?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnInfoLine;     //% StrmLnInfoLine(%,%?,%?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnInfoLine;     //% StrmLnInfoLine_BCD(%,*?,*?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnIsLast;       //% StrmLnIsLast(%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnMaxLen;       //% StrmLnMaxLen(%,%?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnMaxLen;       //% StrmLnMaxLen_BCD(%,*?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___FileGetVersion;     //% FileGetVersion($,$?,%,%?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___FileCpyExt;         //% FileCopy($,$,%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___FileCpyExt;         //% FileCopyExt($,$,%,%,%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___FileCpyExt;         //% FileCopyExt_BCD($,$,%,*,*)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___FileCmp;            //% FileComp($,$,%,%?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___FileCmp;            //% FileComp_BCD($,$,%,*?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___FileSize;           //% FileSize($,%,%?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___FileSize;           //% FileSize_BCD($,%,*?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___SysMkDir;           //% SysMkDir($,%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___SysRmDir;           //% SysRmDir($)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___SysNgfUpdate;       //% SysNgfUpd($)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnSetPad;       //% StrmLnSetPad(%,%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnGetPad;       //% StrmLnGetPad(%,%?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmGetFree;        //% StrmGetFree(%?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmReadChar;       //% StrmReadChar(%,$?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmWriteChar;      //% StrmWriteChar(%,$)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnReadSec;      //% StrmLnReadSec(%,$?,%,%?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnReadKey;      //% StrmLnReadKey(%,$?,%,%?,$?,%,%?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnFindSec;      //% StrmLnFindSec(%,$,%,%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnFindKey;      //% StrmLnFindKey(%,$,%,$?,%,%?,%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___FileIniFind;        //% FileIniFind($,$,%,$,%,$,%,%?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___SysGetAbalEnv;      //% SysGetAbalEnv($,$,%,%?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmFindChar;       //% StrmFindChar(%,$,%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnSetFormFeed;  //% StrmLnSetFormFeed(%,%)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmLnGetFormFeed;  //% StrmLnGetFormFeed(%,%?)
  rt_desc.fonction[i++] = (EXAWORD (BDA_API*)()) ___StrmFindByteInColl; //% StrmFindCharInColl(%,$,%,$?,%)
                                                                        //end
  rt_desc.nombre = i;

  MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"Faccess Fin n=%d",i));
  return((VOID FAR PTR) &rt_desc);
}

