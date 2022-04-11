/** @pkg Staff.Fred.zGuiList */ 

// ****************************************************************************
// * zTools.c
// * Included in GUI module
// * Tools (no API in this file, just internal functions)
// ****************************************************************************
#define  CI_MODULE_ID   0x0020

#if defined(__linux__) || defined(UNIX)
#include "wdef.h"
#else
#if defined(BDA_ABAL2)
#include "wdef.h"
#else
#include "bda.h"
#endif
#endif

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#if defined (BDA_TWIN16)
#include <prladr.h> // for _adr_LecIps
#include <dir.h>
#elif defined (BDA_WIN32)
#include "utilzgrmain.h"
#endif

#include "jstdpsu.h"
#include "zext.h"
#include "zint.h"
#include "zintctx.h"
#include "ztrace.h"
#include "ztools.h"
#include "zglobctx.h"

// ****************************************************************************
/** allocate (name out of conventions because of use by external obj from Jamie)
    EXPORTED TO ALL MODULE 

 * @param see malloc

 * @return: see malloc
 
 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
VOID FAR PTR allocate( int nb )
{
MI_TRACE_DCL_TFN("allocate");
VOID FAR PTR Adr;

  gCptAlloc++;
  Adr = malloc( nb );
  MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"%08lX (%u)", (LONG)Adr, nb));
  return( Adr );
}

// ****************************************************************************
/** callocate (name out of conventions because of use by external obj from Jamie)
    EXPORTED TO ALL MODULE 

 * @param see calloc

 * @return: see calloc
 
 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
VOID FAR PTR callocate( int nb, int size )
{
MI_TRACE_DCL_TFN("callocate");
VOID FAR PTR Adr;

  gCptAlloc++;
  Adr = calloc( nb, size );
  MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"%08lX (%u)", (LONG)Adr, nb*size));
  return( Adr );
}

// ****************************************************************************
/** liberate (name out of conventions because of use by external obj from Jamie)
    EXPORTED TO ALL MODULE
    free and clear the pointer

 * @param see free

 * @return: see free

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
VOID FAR PTR liberate(VOID FAR PTR vptr )
{
MI_TRACE_DCL_TFN("liberate");
  gCptAlloc--;
  MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"%08lX", (LONG)vptr));
  if ( vptr )
     free( vptr );
  return((VOID FAR PTR) 0);
}

// ****************************************************************************
/** abalputword: - internal function, puts a word in Abal format
    Abal uses reversed byte order

 * @return: nothing

 * @author ANF
 
 */
// * VarGlob: 
// ****************************************************************************
VOID ToolsAbalPutWord( WORD FAR PTR Out, WORD In )
{
unsigned char* digit;
digit = (unsigned char*)Out;

digit[0] = (unsigned char)(In >> 8);
digit[1] = (unsigned char)(In & 0x00FF);   

 // *(CHAR FAR PTR)( ((CHAR FAR PTR)Out) + 1) = (CHAR) (In & 0x00FF);
 // *(CHAR FAR PTR)Out = (CHAR) (In >> 8);
}

// ****************************************************************************
/** ToolsExtractInt: - 

 * @return: nothing

 * @author ANF
 
 */
// * VarGlob: 
// ****************************************************************************
WORD ToolsExtractInt( BYTE FAR PTR bptr )
{
  return( ( 
     (* bptr    & 0x00FF) +
    ((*(bptr+1) & 0x00FF) << 8 )
    )
    );
}

// ****************************************************************************
/** ToolsNormalizeRectangle: 
 * @param x       IN/OUT : rectangle
 * @return nothing
 * @author VAP
 */
// ****************************************************************************
VOID ToolsNormalizeRectangle(PTI_RECTANGLE rect){
  WORD temp;
  if(rect->x1>rect->x2){
    temp=rect->x1;
    rect->x1=rect->x2;
    rect->x2=temp;
  }
  if(rect->y1>rect->y2){
    temp=rect->y1;
    rect->y1=rect->y2;
    rect->y2=temp;
  }
}

// ****************************************************************************
/** ToolsMakeRectangle: 
 * @param x       IN : point
 * @param x       IN : size
 * @param x       OUT: normalised rectangle
 * @return nothing
 * @author VAP
 */
// ****************************************************************************
VOID ToolsMakeRectangle(PTI_RECTANGLE rect, const PTI_POINT topleft,const PTI_SIZE size){
  rect->x1=topleft->x;
  rect->y1=topleft->y;
  rect->x2=topleft->x+size->cx;
  rect->y2=topleft->y+size->cy;
}

// ****************************************************************************
/** ToolsVoidRectangle: 
 * @param rect    OUT: normalised void rectangle
 * @return nothing
 * @author VAP
 */
// ****************************************************************************
VOID ToolsVoidRectangle(PTI_RECTANGLE rect){
  rect->x1=0;
  rect->y1=0;
  rect->x2=0;
  rect->y2=0;
}

// ****************************************************************************
/** ToolsGetHeight: 
 * @param x       IN : normalised rectangle
 * @return height value
 * @author VAP
 */
// ****************************************************************************
WORD ToolsGetHeight(const PTI_RECTANGLE rect){
  return rect->y2-rect->y1;
}

// ****************************************************************************
/** ToolsGetWidth: 
 * @param x       IN : normalised rectangle
 * @return width value
 * @author VAP
 */
// ****************************************************************************
WORD ToolsGetWidth(const PTI_RECTANGLE rect){
  return rect->x2-rect->x1;
}

VOID ToolsMoveRectangle(PTI_POINT a,PTI_RECTANGLE rect){
    rect->x2=a->x+rect->x2-rect->x1;
    rect->y2=a->y+rect->y2-rect->y1;
    rect->x1=a->x;
    rect->y1=a->y;
}

// ****************************************************************************
/** ToolsIncreaseRectangle:           
 * @param x       IN/OUT : normalised rectangle
 * @param x       IN     : normalised rectangle
 * @return nothing
 * @author FCH
 */
// ****************************************************************************
VOID ToolsIncreaseRectangle(PTI_RECTANGLE Dest, const PTI_RECTANGLE New)
{

if ((Dest->x1==Dest->x2) && (Dest->y1==Dest->y2))
  {
  Dest->x1 = New->x1;
  Dest->y1 = New->y1;
  Dest->x2 = New->x2;
  Dest->y2 = New->y2;
  }
else
  {   
  if (Dest->x1 > New->x1)   Dest->x1 = New->x1;
  if (Dest->y1 > New->y1)   Dest->y1 = New->y1;
  if (Dest->x2 < New->x2)   Dest->x2 = New->x2;
  if (Dest->y2 < New->y2)   Dest->y2 = New->y2;
  }
}                                    

// ****************************************************************************
/** ToolsInitMemory: 
 * @param x       IN : rectangle
 * @return width value
 * @author VAP
 */
// ****************************************************************************
VOID ToolsInitMemory( PTI_MEMORY pStorage )
{
  pStorage->Ptr = NULL;
  pStorage->Size = 0;
  pStorage->IsDyn= FALSE;
}

// ****************************************************************************
/** ToolsReinitMemory: 
 * @param x       IN : rectangle
 * @return width value
 * @author VAP
 */
// ****************************************************************************
VOID ToolsReinitMemory( PTI_MEMORY pStorage )
{
  if (pStorage->IsDyn && pStorage->Ptr)
    liberate(pStorage->Ptr);
  ToolsInitMemory( pStorage );
}

// ****************************************************************************
/** ToolsAllocMemory: 
 * @param x       IN : rectangle
 * @return width value
 * @author VAP
 */
// ****************************************************************************
WORD ToolsAllocMemory( PTI_MEMORY pStorage, WORD Size )
{
  ToolsReinitMemory( pStorage );
  pStorage->Ptr = allocate(Size);
  if (pStorage->Ptr)
    {
    pStorage->Size = Size;
    pStorage->IsDyn= TRUE;
    return TRUE;
    }
return FALSE;
}

// ****************************************************************************
/** ToolsGetZiniKey
    Read a value in zini file

 * @param Value       OUT : Value (truncated at LgMax), empty string if not found
 * @param Key         IN  : Key
 * @param LgMax       IN  : Max size for Value, including \0
 * @param IsPathName  IN  : TRUE if this is a path name

 * @return: pointer on Value
 * @author ANF
 */
// * VarGlob:
// ****************************************************************************
char FAR * ToolsGetZiniKey(char FAR * Value, char FAR * Key, WORD LgMax, WORD IsPathName)
{
#if defined(BDA_WIN32)
/////////////////////////////////
// Sous Windows, 
// le z.ini n'est plus utilisé, on lit les varenv de l'exécuteur

  char* p;
  Value[0]='\0';

  p = Getenv_from_exa(Key);
  if (!p || *p=='\0')
	  return Value;

  strncpy(Value,p,LgMax);
  Value[LgMax-1]='\0';

  // ---------------------------------------------------------
  // - Add a slash if it is a path
  // ---------------------------------------------------------
  if ( (IsPathName) && (strlen(Value)<LgMax-1) && (Value[strlen(Value)-1]!=CI_CHAR_SLASH) )
    strcat(Value,CI_STRING_SLASH);
    
  return Value;


#else
/////////////////////////////////
// Sous Twin et Useit,
// le z.ini est utilisé

  char str[CI_ZINI_MAXLINE];
  char *ptr;
  FILE *Handle;
  WORD i;

  Value[0]='\0';

  // ---------------------------------------------------------
  // - Find the key
  // ---------------------------------------------------------
  Handle = fopen(CI_ZINI_FILENAME,"rt");
  if (!Handle)
    return Value;

  do 
    {
    fgets(str,CI_ZINI_MAXLINE,Handle);
    } while(!strstr(str,Key) && !feof(Handle));
  if (feof(Handle))
    {
    fclose(Handle);
    return Value;
    }
  fclose(Handle);

  // ---------------------------------------------------------
  // - Find the value
  // ---------------------------------------------------------
  ptr = strchr(str,'=');
  if (!ptr)   // Incorrect string
    return Value;

  do ptr++;
  while ((*ptr==' ') || (*ptr=='\t'));

  // ---------------------------------------------------------
  // - Copy the value
  // ---------------------------------------------------------
  for (i=0 ; i<strlen(ptr) && i<LgMax-1 ; i++)
    {
    switch(ptr[i])
      {
      case '\t': Value[i]=' '   ; break;
      case '\n': Value[i]='\0'  ; break;
      default:   Value[i]=ptr[i]; break;
      }
    }
  Value[i] = '\0';

  // ---------------------------------------------------------
  // - Add a slash if it is a path
  // ---------------------------------------------------------
  if ( (IsPathName) && (strlen(Value)<LgMax-1) && (Value[strlen(Value)-1]!=CI_CHAR_SLASH) )
    strcat(Value,CI_STRING_SLASH);
    
  return Value;

/////////////////////////////////
#endif
}

// ****************************************************************************
/* ToolsFindFile - internal function, seeks for a file with the given name.
   Priority for find:
   1) in environment path (given in parameter)
   2) in current directory
   3) in zlibrary folder of the current disk

 * @param AbsoluteFilename      OUT : absolute filename if file found
 * @param Filename              IN  : File name
 * @param EnvPathname           IN  : Environment Path name

 * @return: CE_OK if file found, CE_ERR otherwise

 * @author ANF
 
 */
// * VarGlob:
// ****************************************************************************
WORD ToolsFindFile( char * AbsoluteFilename, const char * Filename, const char * EnvPathname)
{
MI_TRACE_DCL_TFN("FindFile");
FILE *        Handle;
char tmppath[2*CI_MAXPATH];

#if defined (BDA_TWIN16) 
WORD LgPath;
WORD NoIps;
WORD NbIps;
int  ret;
#endif

AbsoluteFilename[0] = '\0';

// -------------------------------------------
// 1) 
// File localisation in CI_ZINI_LOOKPATH_NAME
// only if defined in zini
// -------------------------------------------
if ( (EnvPathname!=NULL) && (EnvPathname[0]!='\0' ))
  {
  strcpy(tmppath, EnvPathname);
  strcat(tmppath, Filename);

  MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"in %s '%s'",CI_ZINI_LOOKPATH_NAME, tmppath));
  Handle = fopen(tmppath,"rb");
  if (Handle)
    { 
    fclose(Handle);
    strcpy(AbsoluteFilename, tmppath);
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"found"));
    return CE_OK;
    }
  }

#if defined(BDA_WIN32)
//////////////////////////////
// Windows
// -------------------------------------------
// 2) et 3)
// File localisation in current folder 
// File localisation in CI_ZINI_ZLIBPATH_NAME 
// -------------------------------------------
if (FindFile_from_exa( CI_ZINI_ZLIBPATH_NAME, Filename, tmppath ))
   {
   strcpy(AbsoluteFilename, tmppath);
   MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"found"));
   return CE_OK;
	}

#else
//////////////////////////////
// Twin et Useit
// -------------------------------------------
// 2)
// File localisation in current folder 
// -------------------------------------------
#if defined(BDA_TWIN16)
_getcurdir(tmppath, CI_MAXPATH);
#else
getcwd(tmppath, CI_MAXPATH);
#endif

strncat(tmppath, Filename, CI_MAXPATH);
tmppath[CI_MAXPATH-1]='\0';

MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"in %s '%s'","curdir", Filename));

Handle = fopen(tmppath,"rb");
if (Handle)
{
  fclose(Handle);
  strcpy(AbsoluteFilename, tmppath);
  MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"found"));
  return CE_OK;
}

// -------------------------------------------
// 3) Try other chance
// File localisation in CI_ZINI_ZLIBPATH_NAME 
// only if defined in zini
// -------------------------------------------
if ((g_pApp->PathZlib[0]!='\0' ))
  {
  strcpy(tmppath, g_pApp->PathZlib);
  strncat(tmppath, Filename, CI_MAXPATH);
  tmppath[CI_MAXPATH-1]='\0';
  
  MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"in %s '%s'",CI_ZINI_ZLIBPATH_NAME, tmppath));
  Handle = fopen(tmppath,"rb");
  if (Handle)
    { 
    fclose(Handle);
    strcpy(AbsoluteFilename, tmppath);
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"found"));
    return CE_OK;
    }
  }
//////////////////////////////
#endif // 2) et 3)


#if defined(BDA_TWIN16) 
// -------------------------------------------
// 4) Try other chance FOR TWIN
// File localisation in TUC folders
// -------------------------------------------
ret = _adr_LecIps(tmppath, 0, &LgPath, 0, &NbIps );
MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"NbTUC=%d", NbIps));

for ( NoIps=1 ; NoIps<=NbIps ; NoIps++)
  {
  ret = _adr_LecIps(tmppath, CI_MAXPATH, &LgPath, NoIps, &NbIps );
  if (ret==0)
    {
    strncat(tmppath, Filename, CI_MAXPATH);
    tmppath[CI_MAXPATH-1]='\0';
    
    MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"in %s '%s'",CI_DEFAULT_RUNTIME_PATH, tmppath));
    Handle = fopen(tmppath,"rb");
    if (Handle)
      { 
      fclose(Handle);
      strcpy(AbsoluteFilename, tmppath);
      MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"found"));
      return CE_OK;
      }
    }
  }
#elif defined(BDA_UNIX)
// -------------------------------------------
// 4) Try other chance FOR LINUX
// File localisation in default runtime path
// -------------------------------------------
strcpy(tmppath, CI_DEFAULT_RUNTIME_PATH);
strncat(tmppath, Filename, CI_MAXPATH);
tmppath[CI_MAXPATH-1]='\0';

MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"in '%s'", tmppath));
Handle = fopen(tmppath,"rb");
if (Handle)
   { 
   fclose(Handle);
   strcpy(AbsoluteFilename, tmppath);
   MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"found"));
   return CE_OK;
   }

#endif

// -------------------------------------------
// Nothing found
// -------------------------------------------
return CE_ERR;      
}

