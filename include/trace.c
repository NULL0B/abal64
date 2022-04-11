// ****************************************************************************
// * Trace.c
// * Fonctionnalité de trace
// ****************************************************************************
// * 
// * Comment utiliser la trace (configuration, analyse) :
// * ----------------------------------------------------
// *    Voir le document Trace.htm
// * 
// * Comment implémenter la trace dans du code :
// * -------------------------------------------
// *    Pour identifier l'OS cîble, il faut utiliser les définitions suivantes
// *    _WIN32      (spécification VC)
// *    __linux__   (spécification POSIX)
// *    __Prl       (spécifications TwinSDK) 
// *	  UNIX	    (for unix ports)
// *    PROLOGUE3   (norme pour EXA)
// * 
// *    Certains paramètres sont personnalisables :
// *    . CE_TRA_MASTERKEY                     la clé de section dans le fichier de config
// *    . CI_TRA_ID_MASK_1 et CI_TRA_ID_MASK_2 les masques de MODULE_ID
// *    . CI_PRG_ID                            le nom du programme
// * 
// *    Pour personnaliser ces paramètres, il y a 2 méthodes possibles :
// * 
// *    1) A la compilation, en encapsulant ce fichier dans un fichier 'PersoTrace.c' comme-suit :
// *        ' // Trace for Perso appli  
// *        ' #define CE_TRA_MASTERKEY    "[MyOwnTrace]"
// *        ' #define CI_PRG_ID           "MyId"
// *        ' #define CI_TRA_ID_MASK_1    0x7F00
// *        ' #define CI_TRA_ID_MASK_2    0x00FF
// *        ' #include "trace.c"
// * 
// *    2) A l'exécution, en appelant la macro MI_TRA_RESET avec des valeurs dynamiques
// *        les nouveaux paramètres seront pris en compte lors du prochain appel de la trace.
// * 
// ****************************************************************************

#ifdef PROLOGUE3
#define __Prl
#endif

#ifndef TRACEON
// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
// *** TRACEOFF
// *** Fonctions vides. Aucun code n'est implémenté.
// ****************************************************************************
// ****************************************************************************
// ****************************************************************************

#define TI_TRA_CTX  unsigned short

TI_TRA_CTX  g_TraCtx;

char * TraTruncString(char* s)
{return 0;}

char * TraStr(char* s, unsigned short lg)
{return 0;}

unsigned short TraGetKey(char* Value, const char* MasterKey, const char* SearchKey, unsigned short LgMax, unsigned short IsPathName)
{return 0;}

unsigned short TraCtxClone(TI_TRA_CTX* pCtx_des, const TI_TRA_CTX* pCtx_ori)
{return 0;}

unsigned short TraCtxReset( TI_TRA_CTX* pCtx, unsigned short MaskUser1, unsigned short MaskUser2, const char* pMasterKeyUser, const char* pPrgUser, unsigned short IsVerbose )
{return 0;}
                                             
unsigned short TraCtxTrace(TI_TRA_CTX* pCtx, unsigned short Level,unsigned short Id, const char * tfn, const char * mes, ...)
{return 0;}

unsigned short TraTrace   ( unsigned short Level,unsigned short Id, const char * tfn, const char * mes, ...)
{return 0;}

unsigned short TraCtxTraceDumpLg(TI_TRA_CTX* pCtx,unsigned short Level,unsigned short Id, const char * tfn, unsigned short lgTfn, const char * mes, unsigned short lgMes, const char * Zone, unsigned short lgZone)
{return 0;}

unsigned short TraCtxTraceMessLg(TI_TRA_CTX* pCtx,unsigned short Level,unsigned short Id, const char * tfn, unsigned short lgTfn, const char * mes, unsigned short lgMes)
{return 0;}

#else

// ----------------------------------------------------------------------------
// - Headers of modules
// ----------------------------------------------------------------------------

#if defined(_WIN32)
#include <windows.h>

#elif defined(__linux__) || defined(UNIX)
#include <unistd.h>
#include <sys/timeb.h>
#endif

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

// Note sur O_NGF_LNRD et O_NGF_LNWR pour __Prl
// Ces symboles sont tirés du fichier fcntl.h de TwinSDK
// #define O_NGF_LNRD 0x0010
// #define O_NGF_LNWR 0x0020

// ----------------------------------------------------------------------------
// - Constants optionally redefinable at compilation time
// ----------------------------------------------------------------------------

// --- MasterKey  (max defined by CI_TRA_MAXKEY)
#ifndef CE_TRA_MASTERKEY
#define CE_TRA_MASTERKEY "[ABAL]"
#endif

// --- Program ID (always 4 char)
#ifndef CI_PRG_ID
#define CI_PRG_ID        "ABAL" 
#endif

// --- Mask of Module ID
#ifndef CI_TRA_ID_MASK_1
#define CI_TRA_ID_MASK_1    0x0000
#endif

#ifndef CI_TRA_ID_MASK_2
#define CI_TRA_ID_MASK_2    0x0000
#endif

// ----------------------------------------------------------------------------
// - Constantes for internal use
// ----------------------------------------------------------------------------

// --- Path for ini file and trace file by default
#define CI_TRA_ININAME_WORKING_DIR   "prltrace.ini"

#if defined(__Prl)
#define CI_TRA_NAME                  "is\\prltrace.txt"
#define CI_TRA_ININAME_DEFAULT_DIR   "is\\prltrace.ini"

#elif defined(__linux__) || defined(UNIX)
#define CI_TRA_NAME                  "/opt/prologue/bin/prltrace.txt"
#define CI_TRA_ININAME_DEFAULT_DIR   "/opt/prologue/bin/prltrace.ini"

#elif defined(_WIN32)
#define CI_TRA_NAME                  "C:\\prltrace.txt"
#define CI_TRA_ININAME_DEFAULT_DIR   "C:\\prltrace.ini"

#endif

// --- Mask of Trace State
#define CI_TRA_ON_OK           0x0001
#define CI_TRA_ON_FIRST_TIME   0x0002

// --- Mask of level
// 0x8000 free
#define CI_TRA_F_THREAD     0x4000
#define CI_TRA_F_TIME       0x2000
#define CI_TRA_F_ID         0x1000
#define CI_TRA_F_DUMPALIGN  0x0800
#define CI_TRA_F_TIME_MILLI 0x0400
#define CI_TRA_F_PRG        0x0200

#define CI_TRA_F_X          0x0100 // niveau non documenté inférieur au dump (ex: TCode dans exa) !
#define CI_TRA_F_DUMP       0x0080
#define CI_TRA_F_DEBUG      0x0040
#define CI_TRA_F_INFO_LOW   0x0020
#define CI_TRA_F_INFO_HIGH  0x0010
#define CI_TRA_F_PARAM      0x0008
#define CI_TRA_F_FUNCTION   0x0004
#define CI_TRA_F_WARNING    0x0002
#define CI_TRA_F_ERROR      0x0001

#define CI_TRA_F_ERROR_OR_WARNING 0x0003

// --- Divers
#define CI_TRA_FALSE       0
#define CI_TRA_TRUE        1

#define CI_TRA_MAXFILE		512
#define CI_TRA_MAXBUF		1024

#define CI_TRA_STDOUT		1
#define CI_TRA_STDERR		2

// --- Message d'init fait à la lecture de la config
#define CI_TRA_INIT_ISOUTPUT	0x0001
#define CI_TRA_INIT_ISRESET	0x0020

// ----------------------------------------------------------------------------
// - Context type
// ----------------------------------------------------------------------------
typedef struct
   {
   // --- Public members
   unsigned short  On;              // Trace activation
   unsigned short  FilterLevel;     // Memo of accepted levels   , from ini file 
   unsigned short  FilterId;        // Memo of accepted module ID, from ini file
   char            Line[CI_TRA_MAXFILE+1]; // Miscellaneous buffer for applicative usage
   // --- Private members during message writing
	char *          p;               // Pointer on pri_Buf
	FILE *			 Handle;          // Handle on pri_File file
   // --- Private members
	unsigned short  pri_Stream;		// Memo of stream output (file,stdout,stderr), from ini file
   unsigned short  pri_MaskId1;     // Memo of mask ID n°1       , from constant or ResetValue
   unsigned short  pri_MaskId2;     // Memo of Mask ID n°2       , from constant or ResetValue
   unsigned long   pri_Process;     // Memo of Process ID        , from system
   unsigned long   pri_Thread;      // Memo of Thread  ID        , from system
   char            pri_Prg[5];      // Memo of Program name      , from constant or ResetValue
   char            pri_File[CI_TRA_MAXFILE+1];   // Memo of trace file name   , from ini file
   char            pri_Buf[CI_TRA_MAXBUF+1];     // To make the trace line
   } TI_TRA_CTX;

// ----------------------------------------------------------------------------
// - Global Variable
// ----------------------------------------------------------------------------
TI_TRA_CTX  g_TraCtx = 
   {
   // Values to be sure to go inside trace at first time
   CI_TRA_ON_FIRST_TIME , // pub_On
   0xFFFF               , // pub_FilterLevel
   0xFFFF               , // pub_FilterId
   // other values not need an initial values
   };


// ----------------------------------------------------------------------------
// - Utility macros
// ----------------------------------------------------------------------------

// Divers
#define TraLOWORD(l) ( ((unsigned short)( (l) & 0x0000FFFFL )))
#define TraHIWORD(l) ( ((unsigned short)(( (l) >> 16 ) & 0x0000FFFFL)))
#define TraMAX(a,b)  (((a) > (b)) ? (a) : (b))
#define TraMIN(a,b)  (((a) < (b)) ? (a) : (b))

// ----------------------------------------------------------------------------
// - Utility macros for output
// ----------------------------------------------------------------------------

#if defined(_WIN32) && defined (WEXADBDLL)
// --- VERUE WEXADBDLL ---
// Cas de la trace avec OutputDebugString :
// Une appli ne peut pas se debugger elle-même. Or c'est ce qui se passe 
// quand Wabal appelle la dll Wexadb...
// Pour que Wabal recevoir les messages de l'AT en cours de debug dans sa fenêtre de trace, 
// on utilise une fonction de callback fournie par Wabal. Cette fonction écrit directement
// dans la fenêtre de trace de Wabal.

typedef int (__stdcall * T_OUTPUT_DEBUG)( const char* );
T_OUTPUT_DEBUG TraWexadbOut = 0;
#endif

// Ouverture du fichier 
#if defined(_WIN32) && defined (WEXADBDLL) // --- VERUE WEXADBDLL ---
BOOL WINAPI IsDebuggerPresent(VOID);

#define Tra_OUTPUT_OPEN_OR_RETURN(ret)\
if (!pCtx->pri_Stream)\
	{\
	pCtx->Handle=fopen(pCtx->pri_File,"a");\
	if (pCtx->Handle==NULL) return (ret);\
	}\
else\
	if (!TraWexadbOut && !IsDebuggerPresent()) return (ret);

#elif defined(_WIN32) // ------------------------------
BOOL WINAPI IsDebuggerPresent(VOID);

#define Tra_OUTPUT_OPEN_OR_RETURN(ret)\
if (!pCtx->pri_Stream)\
	{\
	pCtx->Handle=fopen(pCtx->pri_File,"a");\
	if (pCtx->Handle==NULL) return (ret);\
	}\
else\
	if (!IsDebuggerPresent()) return (ret);

#elif defined(__linux__) || defined(UNIX) // --------

#define Tra_OUTPUT_OPEN_OR_RETURN(ret)\
if (!pCtx->pri_Stream)\
	{\
	pCtx->Handle=fopen(pCtx->pri_File,"a");\
	if (pCtx->Handle==NULL) return (ret);\
	}

#else  // -------------------------------------------

#define Tra_OUTPUT_OPEN_OR_RETURN(ret)\
if (!pCtx->pri_Stream)\
	{\
	int _fSavemode;\
	_fSavemode = _fmode;\
	_fmode = O_NGF_LNWR | O_NGF_LNRD | 0x0080 /*O_SHARE*/ ;\
	pCtx->Handle=fopen(pCtx->pri_File,"a");\
	_fmode = _fSavemode;\
	if (pCtx->Handle==NULL)	return (ret);\
	}

#endif

// Ecriture du message
#if defined(_WIN32) && defined (WEXADBDLL) // --- VERUE WEXADBDLL ---

#define Tra_OUTPUT_BUF()\
switch(pCtx->pri_Stream)\
	{\
	case CI_TRA_STDOUT:  if (TraWexadbOut) TraWexadbOut(pCtx->pri_Buf); OutputDebugString(pCtx->pri_Buf); break;\
	case CI_TRA_STDERR:  if (TraWexadbOut) TraWexadbOut(pCtx->pri_Buf); OutputDebugString(pCtx->pri_Buf); break;\
	default:             fputs(pCtx->pri_Buf,pCtx->Handle);	      break;\
	}

#elif defined(_WIN32) // --------------------------------------------------

#define Tra_OUTPUT_BUF()\
switch(pCtx->pri_Stream)\
	{\
	case CI_TRA_STDOUT:  OutputDebugString(pCtx->pri_Buf);         break;\
	case CI_TRA_STDERR:  OutputDebugString(pCtx->pri_Buf);         break;\
	default:             fputs(pCtx->pri_Buf,pCtx->Handle);	      break;\
	}

#elif defined(__linux__) || defined(UNIX) // -----------------------------

#define Tra_OUTPUT_BUF()\
switch(pCtx->pri_Stream)\
	{\
	case CI_TRA_STDOUT:  printf("%s",pCtx->pri_Buf);               break;\
	case CI_TRA_STDERR:  printf("%s",pCtx->pri_Buf);               break;\
	default:             fprintf(pCtx->Handle,"%s",pCtx->pri_Buf);	break;\
	}

#else  // ---------------------------------------------------------------

#define Tra_OUTPUT_BUF()\
switch(pCtx->pri_Stream)\
	{\
	case CI_TRA_STDOUT:  printf("%s",pCtx->pri_Buf);               break;\
	case CI_TRA_STDERR:  printf("%s",pCtx->pri_Buf);               break;\
	default:             fprintf(pCtx->Handle,"%s",pCtx->pri_Buf);	break;\
	}

#endif

// Flush
#define Tra_OUTPUT_FLUSH()	if (!pCtx->pri_Stream) fflush(pCtx->Handle)

// Fermeture du fichier
#define Tra_OUTPUT_CLOSE()	if (!pCtx->pri_Stream) fclose(pCtx->Handle)


// ----------------------------------------------------------------------------
// - Trace functions
// ----------------------------------------------------------------------------

// Use inside a MI_TRACE call to trunc a big string
char *         TraTruncString(char* buf, const char* s);
char *         TraStr(char* buf, const char* s, unsigned short lg);

// (never call directly these functions, use the macros MI_TRACE and co)
unsigned short TraTrace(unsigned short Level,unsigned short Id, const char * tfn, const char * mes, ...);

// enhanced usage
unsigned short TraCtxReset( TI_TRA_CTX* pCtx, unsigned short MaskUser1, unsigned short MaskUser2, const char* pMasterKeyUser, const char* pPrgUser, unsigned short IsVerbose );
unsigned short TraCtxClone(TI_TRA_CTX* pCtx_des, const TI_TRA_CTX* pCtx_ori);
unsigned short TraCtxTrace(TI_TRA_CTX* pCtx, unsigned short Level,unsigned short Id, const char * tfn, const char * mes, ...);
unsigned short TraCtxTraceDumpLg(TI_TRA_CTX* pCtx,unsigned short Level,unsigned short Id, const char * tfn, unsigned short lgTfn, const char * mes, unsigned short lgMes, const char * Zone, unsigned short lgZone);
unsigned short TraCtxTraceMessLg(TI_TRA_CTX* pCtx,unsigned short Level,unsigned short Id, const char * tfn, unsigned short lgTfn, const char * mes, unsigned short lgMes);

// ****************************************************************************
// * mystrupr 
// * strupr until '=' is found
// *   ptr : IN/OUT string
// ****************************************************************************
static  void  mystrupr( char * ptr )
{
for ( ; *ptr != 0; ptr++ ) 
   {
   if ((*ptr >='a') && (*ptr<='z'))
      *ptr = ( *ptr - ('a' - 'A'));
   else if ( *ptr == '=' )
           break;
   }
return;
}

// ****************************************************************************
// * myGetProcessID 
// * Returns an ID to identify an application (OS depending)
// ****************************************************************************
static unsigned long myGetProcessID(void)
{
unsigned long ProcessID = 0;

#if defined(__Prl)
  {
  unsigned char TwinProcessID;
  _asm
    {
    mov ah,34H
    int 110
    mov TwinProcessID,cl
    }
  ProcessID = TwinProcessID;
  }

#elif defined(_WIN32)
  ProcessID = GetCurrentProcessId();

#elif defined(__linux__) || defined(UNIX)
  ProcessID = getpid();

#else
  ProcessID = 0;
#endif

  return ProcessID;
}

// ****************************************************************************
// * myGetThreadID 
// * Returns an ID to identify a thread in a Windows application (OS depending)
// ****************************************************************************
static unsigned long myGetThreadID(void)
{
unsigned long ThreadID = 0;

#if defined(__Prl)
	// Nothing to do

#elif defined(_WIN32)
  ThreadID = GetCurrentThreadId();

#elif defined(__linux__) || defined(UNIX)
	// Nothing to do

#else
  ThreadID = 0;
#endif

  return ThreadID;
}

// ****************************************************************************
// * TraGetKey
// * Read a value in the ini file
// * 
// *  Value       OUT : Value (truncated at LgMax), empty string if not found
// *  SearchKey   IN  : MasterKey
// *  SearchKey   IN  : Key
// *  LgMax       IN  : Max size for Value, including \0
// *  IsPathName  IN  : CI_TRA_TRUE if the value is a path name
// *
// *  RETURN          : CI_TRA_TRUE if value found
// ****************************************************************************
unsigned short TraGetKey(char* Value, const char* MasterKey, const char* SearchKey, unsigned short LgMax, unsigned short IsPathName)
{
char str[CI_TRA_MAXFILE];
char Key[CI_TRA_MAXFILE];
char *ptr;
char *ptrSearch;
FILE *Handle;
unsigned short i;
unsigned short IsNextKey;

  strcpy(Key,SearchKey);
  mystrupr(Key);
  Value[0]='\0';

  // ---------------------------------------------------------
  // - Find the MasterKey
  // - At the end, next line is after the MasterKey
  // ---------------------------------------------------------
  Handle = fopen(CI_TRA_ININAME_WORKING_DIR,"rt");
  if (!Handle)
     {
     Handle = fopen(CI_TRA_ININAME_DEFAULT_DIR,"rt");
     if (!Handle)
        return CI_TRA_FALSE;
     }

  ptr = NULL;
  do 
    {
    fgets(str,CI_TRA_MAXFILE,Handle);
    if (*str!=';' && *str!='#')
      ptr = strstr(str,MasterKey);
    } 
  while(!ptr && !feof(Handle) );

  if (!ptr)
    {
    fclose(Handle);
    return CI_TRA_FALSE;
    }

  // ---------------------------------------------------------
  // - Find the key
  // - At the end, the key is identified 
  // - the file is closed
  // - str contains the line 
  // - ptr points after the key
  // ---------------------------------------------------------
  ptr = NULL;
  IsNextKey = CI_TRA_FALSE;

  do 
    {
    fgets(str,CI_TRA_MAXFILE,Handle);
    mystrupr(str);

    ptrSearch = str;

    // Saut des blancs en début
    while (*ptrSearch==' ' || *ptrSearch=='\t')
      ptrSearch++;

    // On atteint la MasterKey suivante
    IsNextKey = (*ptrSearch==MasterKey[0]);

    if (!IsNextKey && *str!=';' && *str!='#' && *str!='/' && *str!='*')
      {
      // Nom de la clé
      if (!strncmp(ptrSearch,Key,strlen(Key)))
        {
        ptrSearch += strlen(Key);
        if (*ptrSearch=='=' || *ptrSearch==' ' || *ptrSearch=='\t')
          ptr = ptrSearch;
        }
      }
    } 
  while(!ptr && !IsNextKey && !feof(Handle) );

  if ( feof(Handle) || IsNextKey )
    {
    fclose(Handle);
    return CI_TRA_FALSE;
    }

  fclose(Handle);

  // ---------------------------------------------------------
  // - Find the value
  // - At the end, ptr points on the beginning of the value
  // ---------------------------------------------------------
  ptr = strchr(ptr,'=');
  if (!ptr)
    return CI_TRA_FALSE;

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
      case '\r': Value[i]='\0'  ; break; /* FCH24082005 pb 0x0D sous linux */
      case '\n': Value[i]='\0'  ; break;
      default:   Value[i]=ptr[i]; break;
      }
    }
  Value[i] = '\0';

  // Remove spaces at end of value
  i=strlen(Value);
  if (i!=0)
    {
    i--;
    while ((Value[i]==' ') && (i!=0))
      {
      Value[i]='\0';
      i--;
      }
    }
   

  // ---------------------------------------------------------
  // - Add a slash at the end if it is a path
  // ---------------------------------------------------------
  #if defined(__linux__) || defined(UNIX)
  if ( (IsPathName) && ((short)strlen(Value)<(short)(LgMax-1)) && (Value[strlen(Value)-1]!='/') )
    strcat(Value,"/");
  
  #else
  if ( (IsPathName) && ((short)strlen(Value)<(short)(LgMax-1)) && (Value[strlen(Value)-1]!='\\') )
    strcat(Value,"\\");
  #endif
    
  return CI_TRA_TRUE;
}

// ****************************************************************************
// * CtxMessageInit 
// * Trace message for initialisation of the trace
// * 
// *   pCtx         IN
// *   pMasterKey   IN : name of MasterKey
// *   FlagDisplay  IN : indicate if it is a CtxReset or normal init
// ****************************************************************************
static short CtxMessageInit(TI_TRA_CTX* pCtx, const char* pMasterKey, unsigned short FlagDisplay)
{
char *        pBuf; /* Pointer in s_TraBuf */
time_t        Time;
struct tm*    Tm;

if ( !(FlagDisplay & CI_TRA_INIT_ISOUTPUT))
	return 1;

Tra_OUTPUT_OPEN_OR_RETURN(1);

pBuf = pCtx->pri_Buf;

// ---------------------------------------------
// --- Process
// ---------------------------------------------
pBuf+= sprintf(pBuf,"%05lu W >>> %s <<< %s Key='%s' Levels=%04X IDs=(%04X,%04X,%04X) ",
                   pCtx->pri_Process         , 
                   pCtx->pri_Prg             ,
                   (FlagDisplay & CI_TRA_INIT_ISRESET) ? "(reset)" : "",
                   pMasterKey                ,
                   pCtx->FilterLevel         ,
                   pCtx->FilterId            ,
                   pCtx->pri_MaskId1         ,
                   pCtx->pri_MaskId2         );

time(&Time);
Tm=localtime(&Time);
pBuf+=sprintf(pBuf,"%02d/%02d/%02d %02d:%02d:%02d ",Tm->tm_mday,Tm->tm_mon+1,Tm->tm_year-100,Tm->tm_hour,Tm->tm_min,Tm->tm_sec);

// ---------------------------------------------
// --- Print in file
// ---------------------------------------------
*pBuf++='\n';
*pBuf++='\0';
Tra_OUTPUT_BUF();
Tra_OUTPUT_CLOSE();
return 1;
}

// ****************************************************************************
// * CtxInit 
// * Initialisation of the trace context reading the ini file
// * 
// *   pCtx          IN/OUT
// *   pSetMasterKey IN : Section to read
// *   pSetPrg       IN : Prg label 
// *   SetMask1      IN : Mask for ID
// *   SetMask2      IN : Mask for ID
// *   FlagDisplay   IN : indicate if it is a CtxReset or normal init
// ****************************************************************************
static void CtxInit(TI_TRA_CTX* pCtx, const char* pSetMasterKey, const char* pSetPrg, unsigned short SetMask1, unsigned short SetMask2, unsigned short FlagDisplay )
{
char  buf[5];
unsigned short  LevelTmp = 0;
unsigned short  IsLevel = CI_TRA_FALSE;

// ------------------------------------------------
// - Default static init
// ------------------------------------------------
pCtx->On           = 0;
pCtx->FilterLevel  = CI_TRA_F_ERROR_OR_WARNING;
pCtx->FilterId     = 0xFFFF;
pCtx->pri_Process  = myGetProcessID();
pCtx->pri_Thread   = myGetThreadID();

// ------------------------------------------------
// - Default dynamic init
// ------------------------------------------------
strncpy(pCtx->pri_Prg,pSetPrg,5);
pCtx->pri_Prg[4] = '\0';

pCtx->pri_MaskId1 = SetMask1;
pCtx->pri_MaskId2 = SetMask2;

// ------------------------------------------------
// - Read ini file
// ------------------------------------------------

// --- Activation
TraGetKey(buf, pSetMasterKey, "ON", 5, CI_TRA_FALSE);
if (buf[0]=='1')
   pCtx->On = CI_TRA_ON_OK;
else
   {
   pCtx->Line[0] = buf[0];   
   return;
   }

// --- Trace file name
if (!TraGetKey(pCtx->pri_File, pSetMasterKey, "FILE", CI_TRA_MAXFILE, CI_TRA_FALSE))
   strcpy(pCtx->pri_File,CI_TRA_NAME);

if ( !strcmp(pCtx->pri_File,"stdout"))
	pCtx->pri_Stream = CI_TRA_STDOUT;
else if ( !strcmp(pCtx->pri_File,"stderr"))
	pCtx->pri_Stream = CI_TRA_STDERR;
else
	pCtx->pri_Stream = 0;

// --- IDs
if (TraGetKey(buf, pSetMasterKey, "MASK_ID", 5, CI_TRA_FALSE))
   sscanf(buf,"%hX",&pCtx->FilterId);

// --- Levels
if (TraGetKey(buf, pSetMasterKey, "MASK_L", 5, CI_TRA_FALSE))
	{
	// All levels in a hexa value
   sscanf(buf,"%hX",&pCtx->FilterLevel);
	}
else
	{
	// Levels bit by bit
	IsLevel |= TraGetKey(buf, pSetMasterKey, "VISU_TIME", 2, CI_TRA_FALSE);
	if (buf[0]=='1') LevelTmp |= CI_TRA_F_TIME;

	IsLevel |= TraGetKey(buf, pSetMasterKey, "VISU_MILLI", 2, CI_TRA_FALSE);
	if (buf[0]=='1') LevelTmp |= (CI_TRA_F_TIME | CI_TRA_F_TIME_MILLI);

	IsLevel |= TraGetKey(buf, pSetMasterKey, "VISU_PRG", 2, CI_TRA_FALSE);
	if (buf[0]=='1') LevelTmp|= CI_TRA_F_PRG;

	IsLevel |= TraGetKey(buf, pSetMasterKey, "VISU_ID", 2, CI_TRA_FALSE);
	if (buf[0]=='1') LevelTmp|= CI_TRA_F_ID;

	IsLevel |= TraGetKey(buf, pSetMasterKey, "VISU_ALIGN", 2, CI_TRA_FALSE);
	if (buf[0]=='1') LevelTmp |= CI_TRA_F_DUMPALIGN;

	IsLevel |= TraGetKey(buf, pSetMasterKey, "VISU_THREAD", 2, CI_TRA_FALSE);
	if (buf[0]=='1') LevelTmp |= CI_TRA_F_THREAD;

	IsLevel |= TraGetKey(buf, pSetMasterKey, "L_ERROR", 2, CI_TRA_FALSE);
	if (buf[0]=='1') LevelTmp |= CI_TRA_F_ERROR;

	IsLevel |= TraGetKey(buf, pSetMasterKey, "L_WARNING", 2, CI_TRA_FALSE);
	if (buf[0]=='1') LevelTmp |= CI_TRA_F_WARNING;

	IsLevel |= TraGetKey(buf, pSetMasterKey, "L_FUNCTION", 2, CI_TRA_FALSE);
	if (buf[0]=='1') LevelTmp |= CI_TRA_F_FUNCTION;

	IsLevel |= TraGetKey(buf, pSetMasterKey, "L_PARAM", 2, CI_TRA_FALSE);
	if (buf[0]=='1') LevelTmp |= CI_TRA_F_PARAM;

	IsLevel |= TraGetKey(buf, pSetMasterKey, "L_INFO_HIGH", 2, CI_TRA_FALSE);
	if (buf[0]=='1') LevelTmp |= CI_TRA_F_INFO_HIGH;

	IsLevel |= TraGetKey(buf, pSetMasterKey, "L_INFO_LOW", 2, CI_TRA_FALSE);
	if (buf[0]=='1') LevelTmp |= CI_TRA_F_INFO_LOW;

	IsLevel |= TraGetKey(buf, pSetMasterKey, "L_DEBUG", 2, CI_TRA_FALSE);
	if (buf[0]=='1') LevelTmp |= CI_TRA_F_DEBUG;

	IsLevel |= TraGetKey(buf, pSetMasterKey, "L_DUMP", 2, CI_TRA_FALSE);
	if (buf[0]=='1') LevelTmp |= CI_TRA_F_DUMP;

	IsLevel |= TraGetKey(buf, pSetMasterKey, "L_X", 2, CI_TRA_FALSE);
	if (buf[0]=='1') LevelTmp |= CI_TRA_F_X;

	if (IsLevel)
		pCtx->FilterLevel = LevelTmp;
	}

// --- Validity test
pCtx->On = (pCtx->FilterLevel && pCtx->FilterId) ? CI_TRA_ON_OK : 0;

if (!pCtx->On)
   return;

CtxMessageInit(pCtx,pSetMasterKey,FlagDisplay);
}

// ****************************************************************************
// * CtxDateTime
// * Write date and time in the buffer, depending on filter level (OS dependant) 
// *
// *   pCtx     IN/OUT(p)
// ****************************************************************************
static void CtxDateTime( TI_TRA_CTX* pCtx)
{

#if defined(__Prl)
// --- Twin: Date and time without milliseconds
time_t        Time;
struct tm*    Tm;
time(&Time);
Tm=localtime(&Time);

pCtx->p += sprintf(pCtx->p,"%02d/%02d/%02d %02d:%02d:%02d ",Tm->tm_mday,Tm->tm_mon+1,Tm->tm_year-100,Tm->tm_hour,Tm->tm_min,Tm->tm_sec);

#elif defined(_WIN32)
// --- Windows: Date and time with milliseconds
SYSTEMTIME Tm;
GetLocalTime( &Tm );

if (pCtx->FilterLevel & CI_TRA_F_TIME_MILLI)
   pCtx->p += sprintf(pCtx->p,"%02d.%03d ",Tm.wSecond,Tm.wMilliseconds);
else
   pCtx->p += sprintf(pCtx->p,"%02d/%02d/%04d %02d:%02d:%02d.%03d ",Tm.wDay,Tm.wMonth,Tm.wYear,Tm.wHour,Tm.wMinute,Tm.wSecond,Tm.wMilliseconds);

#elif defined(__linux__) || defined(UNIX)
// --- Linux: Date and time with milliseconds
struct timespec Timeb;
struct tm*    Tm;
clock_gettime(CLOCK_REALTIME,&Timeb);
Tm=localtime(&Timeb.tv_sec);

if (pCtx->FilterLevel & CI_TRA_F_TIME_MILLI)
   pCtx->p += sprintf(pCtx->p,"%02d.%03lu ",Tm->tm_sec,Timeb.tv_nsec);
else
   pCtx->p += sprintf(pCtx->p,"%02d/%02d/%02d %02d:%02d:%02d.%03lu ",Tm->tm_mday,Tm->tm_mon+1,Tm->tm_year-100,Tm->tm_hour,Tm->tm_min,Tm->tm_sec,Timeb.tv_nsec);

#endif
}

// ****************************************************************************
// * CtxDump
// * Dump a zone in the trace file
// * 
// *  pCtx     IN/OUT(p)
// *  mes      IN  : title of the dump trace
// *  lgMes    IN  : size of mes
// *  Zone     IN  : dump zone
// *  lgZone   IN  : size of zone
// ****************************************************************************
static void CtxDump( TI_TRA_CTX* pCtx, const char * mes, unsigned short lgMes, const unsigned char * Zone, unsigned short lgZone)
{
char *          pBufDump; /* Pointer in s_TraBuf */
char            BufHexa[64];
char            BufCar [17];
char *          pBufHexa;
char *          pBufCar;
unsigned short  i;
unsigned char   c;

const unsigned char *  pBegZone;
const unsigned char *  pEndZone;
const unsigned char *  pBegDump;
const unsigned char *  pEndDump;
const unsigned char *  p;

pBegZone = Zone;
pEndZone = Zone + lgZone -1;

if (pCtx->FilterLevel & CI_TRA_F_DUMPALIGN)
   {
   pBegDump = (const unsigned char *) ((unsigned long) pBegZone / 0x10 * 0x10);
   pEndDump = (const unsigned char *) ((unsigned long) pEndZone / 0x10 * 0x10 + 0x0F);
   }
else
   {
   pBegDump = pBegZone;
   pEndDump = (const unsigned char *) ((unsigned long) pBegZone + (lgZone-1) / 0x10 * 0x10 + 0x0F);
   }

pBufDump = pCtx->p;

// ---------------------------------------------
// --- Print title and title of dump in file
// ---------------------------------------------
for (i=0 ; i<lgMes ; i++)
	*pCtx->p++ = mes[i];
*pCtx->p++ = '\n';
*pCtx->p++ = '\0';
Tra_OUTPUT_BUF();

c = (unsigned char) ((unsigned long)pBegDump) & 0x0F;
pBufHexa = BufHexa;
pBufHexa+=sprintf(pBufHexa,"          ");             
for (i=0 ; i<0x10 ; i++)
   pBufHexa+=sprintf(pBufHexa," %X ",(c+i)%0x10);             

pCtx->p  = pBufDump;
pCtx->p += sprintf(pCtx->p, "%s\n", BufHexa);
Tra_OUTPUT_BUF();
Tra_OUTPUT_FLUSH();

// ---------------------------------------------
// --- Print dump in file
// ---------------------------------------------

pBufHexa = BufHexa;
pBufCar  = BufCar;

for (p=pBegDump , i=0 ; p<=pEndDump ; p++ , i++)
   {
   if ( (p<pBegZone) || (p>pEndZone))
      {
      pBufHexa+=sprintf(pBufHexa,"   ");             
      pBufCar +=sprintf(pBufCar ," ");             
      }
   else
      {
      pBufHexa+=sprintf(pBufHexa,"%02X ",*p);             
      pBufCar +=sprintf(pBufCar ,"%c", ((*p<'\x20') || (*p>'\x7F')) ? '.' : *p );             
      }

   if (i%0x10==0x0F)
      {
      pCtx->p = pBufDump;
      pCtx->p += sprintf(pCtx->p, "%04X:%04X ", TraHIWORD(((unsigned long)pBegDump)+((i/0x10)*0x10)), TraLOWORD(((unsigned long)pBegDump)+((i/0x10)*0x10)) );
      pCtx->p += sprintf(pCtx->p, "%s", BufHexa);
      pCtx->p += sprintf(pCtx->p, "%s\n", BufCar );
		Tra_OUTPUT_BUF();
		Tra_OUTPUT_FLUSH();
      pBufHexa = BufHexa;
      pBufCar  = BufCar;
      } 
   }
}

// ****************************************************************************
// * CtxHeader
// * Open the trace file, and write the header of a trace message in the buffer
// *
// *  pCtx     IN/OUT(p)
// *  Level    IN 
// *  Id       IN
// ****************************************************************************
static short CtxHeader( TI_TRA_CTX* pCtx, unsigned short Level, unsigned short Id)
{
// ---------------------------------------------
// --- Test parameters, and initialisation
// ---------------------------------------------

// Level requested
if ( !( (Level&pCtx->FilterLevel) && ((Level&CI_TRA_F_ERROR_OR_WARNING) || (Id&pCtx->FilterId)) )  )
   return 1;

Tra_OUTPUT_OPEN_OR_RETURN(1);

pCtx->p = pCtx->pri_Buf;
   
// ---------------------------------------------
// --- Process
// ---------------------------------------------
pCtx->p += sprintf(pCtx->p, "%05lu ", pCtx->pri_Process);

// ---------------------------------------------
// --- Level
// ---------------------------------------------
*pCtx->p++ = (Level & CI_TRA_F_ERROR)   ? 'E' :
             (Level & CI_TRA_F_WARNING) ? 'W' :
             (Level & CI_TRA_F_FUNCTION)? 'F' :
             (Level & CI_TRA_F_PARAM)   ? 'P' :
             (Level & CI_TRA_F_X)       ? 'x' :
             'I';
*pCtx->p++ = ' ';

// ---------------------------------------------
// --- Time
// ---------------------------------------------
if (pCtx->FilterLevel & CI_TRA_F_TIME)
   CtxDateTime( pCtx );

// ---------------------------------------------
// --- Id (prg Id, mask, and exact value)
// ---------------------------------------------
if (pCtx->FilterLevel & CI_TRA_F_PRG) 
   {
   pCtx->p   += sprintf(pCtx->p,"%s", pCtx->pri_Prg);

	if (pCtx->pri_MaskId1 && pCtx->pri_MaskId2)
		{
		*pCtx->p++ = '_';
		*pCtx->p++ = (Id & pCtx->pri_MaskId2) ? '2' :
						 (Id & pCtx->pri_MaskId1) ? '1' :
						 '0';
		}

   if (pCtx->FilterLevel & CI_TRA_F_ID)
    pCtx->p += sprintf(pCtx->p, ":%04X ", Id);
   else
    *pCtx->p++ = ' ';
   }

// ---------------------------------------------
// --- Thread
// ---------------------------------------------
if (pCtx->FilterLevel & CI_TRA_F_THREAD)
	pCtx->p += sprintf(pCtx->p, "%04X ", (unsigned short)pCtx->pri_Thread);

return 0;
}

// ****************************************************************************
// * TraTruncString 
// * write a string with test on adress and truncation if exceeds 20 car
// ****************************************************************************
char * TraTruncString(char* buf, const char* s)
{
  if (s==NULL)
    strcpy(buf,"<NULL>");
  else
    {
    strncpy(buf, s, 20);
    buf[20]='.';
    buf[21]='.';
    buf[22]='.';
    buf[23]='\0';
    }
  return buf;
}

// ****************************************************************************
// * TraStr 
// * write a string with test on adress and max valid length
// ****************************************************************************
char * TraStr(char* buf, const char* s, unsigned short lg)
{
  if (s==NULL)
    strcpy(buf,"<NULL>");
  else
    {
    lg = (lg>CI_TRA_MAXFILE) ? CI_TRA_MAXFILE : lg;
    strncpy(buf, s, lg);
    buf[lg]='\0';
    buf[CI_TRA_MAXFILE-3]='.';
    buf[CI_TRA_MAXFILE-2]='.';
    buf[CI_TRA_MAXFILE-1]='.';
    buf[CI_TRA_MAXFILE]='\0';
    }
  return buf;
}

// ****************************************************************************
// * TraCtxReset
// * If necessary, it is possible to initialise settings at execution time
// * using this function. The ini file will be red at next call to TraTrace
// * and settable parameters can be changed.
// * 
// *   pCtx           IN/OUT
// *   pMasterKeyUser IN : Section to read
// *   pPrgUser       IN : Prg label 
// *   MaskUser1      IN : Mask for ID
// *   MaskUser2      IN : Mask for ID
// *   IsVerbose		 IN : Display a message
// ****************************************************************************
unsigned short TraCtxReset( TI_TRA_CTX* pCtx, unsigned short MaskUser1, unsigned short MaskUser2, const char* pMasterKeyUser, const char* pPrgUser, unsigned short IsVerbose )
{
unsigned short Flag = (IsVerbose) ? CI_TRA_INIT_ISOUTPUT | CI_TRA_INIT_ISRESET : CI_TRA_INIT_ISRESET;

// --- Force to read again the ini file
CtxInit( pCtx, (pMasterKeyUser!=NULL)        ? pMasterKeyUser : CE_TRA_MASTERKEY  , 
               (pPrgUser!=NULL)              ? pPrgUser       : CI_PRG_ID         , 
               (unsigned short) ((MaskUser1) ? MaskUser1      : CI_TRA_ID_MASK_1) , 
               (unsigned short) ((MaskUser2) ? MaskUser2      : CI_TRA_ID_MASK_2) ,
               Flag );

return 1;
}

// ****************************************************************************
// * TraCtxClone
// * Initialisation of a new context from an initiale contexte (for threads)
// * 
// *   pCtx_ori      IN
// *   pCtx_des      OUT
// ****************************************************************************
unsigned short TraCtxClone(TI_TRA_CTX* pCtx_des, const TI_TRA_CTX* pCtx_ori)
{
if (!pCtx_ori || !pCtx_des)
	return 1;

pCtx_des->On          = pCtx_ori->On;
pCtx_des->FilterLevel = pCtx_ori->FilterLevel;
pCtx_des->FilterId    = pCtx_ori->FilterId;   
memset(pCtx_des->Line, 0, CI_TRA_MAXFILE); // not cloned
pCtx_des->p           = 0; // not cloned
pCtx_des->Handle      = 0; // not cloned
pCtx_des->pri_Stream  = pCtx_ori->pri_Stream;
pCtx_des->pri_MaskId1 = pCtx_ori->pri_MaskId1;
pCtx_des->pri_MaskId2 = pCtx_ori->pri_MaskId2;
pCtx_des->pri_Process = pCtx_ori->pri_Process;
pCtx_des->pri_Thread  = myGetThreadID(); // not cloned
strcpy(pCtx_des->pri_Prg , pCtx_ori->pri_Prg);
strcpy(pCtx_des->pri_File, pCtx_ori->pri_File);
memset(pCtx_des->pri_Buf, 0, CI_TRA_MAXBUF); // not cloned
return 0;
}

// ****************************************************************************
// * TraCtxTrace
// * Trace with context
// *
// * pCtx    IN/OUT: Pointer on a trace context (if NULL, default context is used)
// * Level     IN  : level
// * Id        IN  : Module ID 
// * tfn       IN  : origin of the message (typically, name of the calling function)
// * mes       IN  : string message (cf printf)
// * ...       IN  : optional arguments (cf printf)
// ****************************************************************************
unsigned short TraCtxTrace(TI_TRA_CTX* pCtx,unsigned short Level,unsigned short Id, const char * tfn, const char * mes,...) 
{
// ---------------------------------------------
// --- Init
// ---------------------------------------------
if (!pCtx)
	return 1;

if (pCtx->On & CI_TRA_ON_FIRST_TIME)
   {
   CtxInit(pCtx, CE_TRA_MASTERKEY, CI_PRG_ID, CI_TRA_ID_MASK_1, CI_TRA_ID_MASK_2, CI_TRA_INIT_ISOUTPUT);
   if (!pCtx->On)
      return 1;
   }
 
// ---------------------------------------------
// --- Header
// ---------------------------------------------
if (CtxHeader( pCtx, Level, Id))
	return 1;

// ---------------------------------------------
// --- Name of function
// ---------------------------------------------
if (tfn)
	pCtx->p += sprintf(pCtx->p, "%s ", tfn);

	// ---------------------------------------------
	// --- Message
	// ---------------------------------------------
	if (Level & CI_TRA_F_DUMP)
   	{
   		if (pCtx->FilterLevel & CI_TRA_F_DUMP)
      		{
      			va_list            marker;
      			unsigned char *    Zone;
      			unsigned short     lgZone;

      			va_start(marker, mes);
      			Zone   = va_arg( marker, unsigned char*);
      			lgZone = va_arg( marker, unsigned int);
      			va_end( marker);
      			CtxDump(pCtx, mes, (unsigned short) strlen(mes), Zone, lgZone );   
      		}
   	}
	else
   	{
   		sprintf(pCtx->p, mes,(char  *)(&mes+1));
   		strcat(pCtx->p,"\n");
	
		Tra_OUTPUT_BUF();
	}
	Tra_OUTPUT_CLOSE();
	return 1;       
}

// ****************************************************************************
// * TraTrace
// * Trace with implicit g_TraCtx global variable
// *
// * Level     IN  : level
// * Id        IN  : Module ID 
// * tfn       IN  : origin of the message (typically, name of the calling function)
// * mes       IN  : string message (cf printf)
// * ...       IN  : optional arguments (cf printf)
// *
// * VarGlob:
// *  g_TraCtx IN / OUT
// *
// ****************************************************************************
unsigned short TraTrace(unsigned short Level,unsigned short Id, const char * tfn, const char * mes,...) 
{
TI_TRA_CTX * pCtx = &g_TraCtx;

// ---------------------------------------------
// --- Init
// ---------------------------------------------
if (pCtx->On & CI_TRA_ON_FIRST_TIME)
   {
   CtxInit(pCtx, CE_TRA_MASTERKEY, CI_PRG_ID, CI_TRA_ID_MASK_1, CI_TRA_ID_MASK_2, CI_TRA_INIT_ISOUTPUT);
   if (!pCtx->On)
      return 1;
   }


	 
// ---------------------------------------------
// --- Header
// ---------------------------------------------
if (CtxHeader( pCtx, Level, Id))
	return 1;

// ---------------------------------------------
// --- Name of function
// ---------------------------------------------
if (tfn)
	pCtx->p += sprintf(pCtx->p, "%s ",tfn);

	// ---------------------------------------------
	// --- Message
	// ---------------------------------------------
	if (Level & CI_TRA_F_DUMP)
	{
		if (pCtx->FilterLevel & CI_TRA_F_DUMP)
		{
     	 		va_list            marker;
     			unsigned char *    Zone;
      			unsigned short     lgZone;

      			va_start(marker, mes);
      			Zone   = va_arg( marker, unsigned char*);
      			lgZone = va_arg( marker, unsigned int);
      			va_end( marker);
      			CtxDump(pCtx, mes, (unsigned short) strlen(mes), Zone, lgZone );   
      		}
   	}
	else
	{
		sprintf(pCtx->p, mes,(char  *)(&mes+1));
		strcat(pCtx->p,"\n");
		Tra_OUTPUT_BUF();
   	}
	Tra_OUTPUT_CLOSE();
	return 1;       
}

// ****************************************************************************
// * TraCtxTraceMessLg
// * Trace with context adaptated for ABAL (mes+length)
// *
// * pCtx    IN/OUT: Pointer on a trace context (if NULL, default context is used)
// * Level     IN  : level
// * Id        IN  : Module ID 
// * tfn       IN  : origin of the message (typically, name of the calling function)
// * mes       IN  : string message (cf printf)
// * ...       IN  : optional arguments (cf printf)
// *
// * VarGlob:
// *  all      IN / OUT (at initialisation)
// *
// ****************************************************************************
unsigned short TraCtxTraceMessLg(TI_TRA_CTX* pCtx,unsigned short Level,unsigned short Id, const char * tfn, unsigned short lgTfn, const char * mes, unsigned short lgMes) 
{
unsigned short i;

// ---------------------------------------------
// --- Init
// ---------------------------------------------
if (!pCtx)
	return 1;

if (pCtx->On & CI_TRA_ON_FIRST_TIME)
   {
   CtxInit(pCtx, CE_TRA_MASTERKEY, CI_PRG_ID, CI_TRA_ID_MASK_1, CI_TRA_ID_MASK_2, CI_TRA_INIT_ISOUTPUT);
   if (!pCtx->On)
      return 1;
   }
 
// ---------------------------------------------
// --- Header
// ---------------------------------------------
if (CtxHeader( pCtx, Level, Id))
	return 1;

// ---------------------------------------------
// --- Name of function
// ---------------------------------------------
if (tfn)
	{
	for (i=0 ; i<lgTfn ; i++)
		*pCtx->p++ = tfn[i];
	*pCtx->p++ = ' ';
	}

// ---------------------------------------------
// --- Message
// ---------------------------------------------
for (i=0 ; i<lgMes ; i++)
	*pCtx->p++ = mes[i];
*pCtx->p++ = '\n';
*pCtx->p++ = '\0';

Tra_OUTPUT_BUF();
Tra_OUTPUT_CLOSE();
return 1;       
}

// ****************************************************************************
// * TraCtxTraceDumpLg
// * Trace with context adaptated for ABAL (mes+length)
// *
// * pCtx    IN/OUT: Pointer on a trace context (if NULL, default context is used)
// * Level     IN  : level
// * Id        IN  : Module ID 
// * tfn       IN  : origin of the message (typically, name of the calling function)
// * mes       IN  : string message (cf printf)
// * ...       IN  : optional arguments (cf printf)
// *
// * VarGlob:
// *  all      IN / OUT (at initialisation)
// *
// ****************************************************************************
unsigned short TraCtxTraceDumpLg(TI_TRA_CTX* pCtx,unsigned short Level,unsigned short Id, const char * tfn, unsigned short lgTfn, const char * mes, unsigned short lgMes, const char * Zone, unsigned short lgZone) 
{
unsigned short i;

// ---------------------------------------------
// --- Init
// ---------------------------------------------
if (!pCtx)
	return 1;

if (pCtx->On & CI_TRA_ON_FIRST_TIME)
   {
   CtxInit(pCtx, CE_TRA_MASTERKEY, CI_PRG_ID, CI_TRA_ID_MASK_1, CI_TRA_ID_MASK_2, CI_TRA_INIT_ISOUTPUT);
   if (!pCtx->On)
      return 1;
   }

// ---------------------------------------------
// --- Header
// ---------------------------------------------
if (CtxHeader( pCtx, Level, Id))
	return 1;

// ---------------------------------------------
// --- Name of function
// ---------------------------------------------
if (tfn)
	{
	for (i=0 ; i<lgTfn ; i++)
		*pCtx->p++ = tfn[i];
	*pCtx->p++ = ' ';
	}

// ---------------------------------------------
// --- Dump
// ---------------------------------------------
CtxDump(pCtx, mes, lgMes, Zone, lgZone );   

Tra_OUTPUT_CLOSE();
return 1;       
}

#endif	/* TRACE ON   */

