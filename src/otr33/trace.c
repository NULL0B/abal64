// ****************************************************************************
// * Trace.c
// * Trace functionnality
// ****************************************************************************
// * 
// * Comment utiliser la trace (configuration, analyse) :
// * ----------------------------------------------------
// *    Voir le document Trace.htm
// * 
// * Comment implémenter la trace dans du code :
// * -------------------------------------------
// *    Pour identifier l'OS cîble, il faut utiliser les définitions suivantes
// *    _WIN32
// *    __linux__   (spécification POSIX)
// *    __Prl
// * 
// *    Certains paramètres sont personnalisables :
// *    . la clé du fichier de config
// *    . les masques de MODULE_ID
// *    . le nom du programme
// *    Il y a 2 méthodes possibles :
// * 
// *    1) A la compilation, en encapsulant ce fichier dans un fichier 'PersoTrace.c' comme-suit :
// *        ' // Trace for Perso appli  
// *        ' #define CE_TRA_MASTERKEY    "[MyOwnTrace]"
// *        ' #define CI_PRG_ID           "zLib"
// *        ' #define CI_TRA_ID_MASK_1    0x7F00
// *        ' #define CI_TRA_ID_MASK_2    0x00FF
// *        ' #include "Trace.c"
// * 
// *    2) A l'exécution, en appelant la macro MI_TRA_RESET
// *        les nouveaux paramètres seront pris en compte lors du prochain appel de la trace.
// * 
// ****************************************************************************

#ifndef TRACEON
// ****************************************************************************
// * TRACEOFF
// ****************************************************************************

#if defined(__linux__)
  #warning PROLOGUE: Trace OFF
#else
  #pragma message("PROLOGUE MSG: Trace OFF")
#endif

#define TI_TRA_CTX  unsigned short
TI_TRA_CTX  g_TraCtx;

unsigned short TraTrace(unsigned short Level,unsigned short Id, const char * tfn, const char * mes,...) 
{return 0;}

unsigned short TraCtxReset( TI_TRA_CTX* pCtx, const char* pMasterKeyUser, const char* pPrgUser, unsigned short MaskUser1, unsigned short MaskUser2 )
{return 0;}

unsigned short TraCtxTrace( TI_TRA_CTX* pCtx,unsigned short Level,unsigned short Id, const char * tfn, const char * mes,...) 
{return 0;}

char * TraTruncString(char* s)
{return 0;}

char * TraStr(char* s, unsigned short lg)
{return 0;}

#else
// ****************************************************************************
// * TRACEON
// ****************************************************************************

#if defined   (_WIN32)
  #pragma message("PROLOGUE MSG: Trace ON for Win32")
#elif defined(__linux__)
  #warning PROLOGUE: Trace ON for Linux
#elif defined (__Prl)
  #pragma message("PROLOGUE MSG: Trace ON for Twin16")
#else
  #error PROLOGUE ERROR: OS not supported by trace
#endif

// ----------------------------------------------------------------------------
// - Headers of modules
// ----------------------------------------------------------------------------

#if defined(_WIN32)
#include <windows.h>

#elif defined(__linux__)
#include <unistd.h>
#include <sys/timeb.h>
#endif

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

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

// --- no comment...
#define CI_TRA_FALSE       0
#define CI_TRA_TRUE        1

// --- Mask of Trace State
#define CI_TRA_ON_OK           0x0001
#define CI_TRA_ON_FIRST_TIME   0x0002

// --- Mask of level
// 0x8000 free
// 0x4000 free
#define CI_TRA_F_TIME       0x2000
#define CI_TRA_F_ID         0x1000
#define CI_TRA_F_DUMPALIGN  0x0800
#define CI_TRA_F_TIME_MILLI 0x0400
#define CI_TRA_F_PRG        0x0200

#define CI_TRA_F_ERROR      0x0001
#define CI_TRA_F_WARNING    0x0002
#define CI_TRA_F_FUNCTION   0x0004
#define CI_TRA_F_PARAM      0x0008
#define CI_TRA_F_INFO_HIGH  0x0010
#define CI_TRA_F_INFO_LOW   0x0020
#define CI_TRA_F_DEBUG      0x0040
#define CI_TRA_F_DUMP       0x0080
// niveau non documenté inférieur au dump !
#define CI_TRA_F_X          0x0100

#define CI_TRA_F_ERROR_OR_WARNING 0x0003

// --- Path for ini file and trace file by default
#define CI_TRA_ININAME_WORKING_DIR   "prltrace.ini"

#if defined(__Prl)
#define CI_TRA_NAME                  "is\\prltrace.txt"
#define CI_TRA_ININAME_DEFAULT_DIR   "is\\prltrace.ini"

#elif defined(__linux__)
#define CI_TRA_NAME                  "/opt/prologue/bin/prltrace.txt"
#define CI_TRA_ININAME_DEFAULT_DIR   "/opt/prologue/bin/prltrace.ini"

#elif defined(_WIN32)
#define CI_TRA_NAME                  "C:\\prltrace.txt"
#define CI_TRA_ININAME_DEFAULT_DIR   "C:\\prltrace.ini"

#endif

// ----------------------------------------------------------------------------
// - Context type
// ----------------------------------------------------------------------------
typedef struct
   {
   // --- Public members
   unsigned short  On;              // Trace activation
   unsigned short  FilterLevel;     // Memo of accepted levels   , from ini file 
   unsigned short  FilterId;        // Memo of accepted module ID, from ini file
   char            Line[81];        // Miscellaneous buffer for applicative usage
   // --- Private members
   unsigned short  pri_MaskId1;     // Memo of mask ID n°1       , from constant or ResetValue
   unsigned short  pri_MaskId2;     // Memo of Mask ID n°2       , from constant or ResetValue
   unsigned long   pri_Process;     // Memo of Process ID        , from system
   char            pri_Prg[5];      // Memo of Program name      , from constant or ResetValue
   char            pri_File[512];   // Memo of trace file name   , from ini file
   char            pri_Buf[256];    // To make the trace line
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
#define TraLOWORD(l) ( ((unsigned short)( (l) & 0x0000FFFFL )))
#define TraHIWORD(l) ( ((unsigned short)(( (l) >> 16 ) & 0x0000FFFFL)))


// ----------------------------------------------------------------------------
// - Trace functions
// ----------------------------------------------------------------------------
static  void  Trastrupr( char * ptr );
static unsigned long TraGetProcessID(void);
static unsigned short GetKey(char* Value, const char* MasterKey, const char* SearchKey, unsigned short LgMax, unsigned short IsPathName);
static void TraInit(TI_TRA_CTX* pCtx, const char* pSetMasterKey, const char* pSetPrg, unsigned short SetMask1, unsigned short SetMask2, unsigned short IsReset );
static void TraMessageInit(TI_TRA_CTX* pCtx, const char* pMasterKey, unsigned short IsReset );
static int TraDateTime( char* pBuf, unsigned short IsMilli);

char * TraTruncString(char* buf, const char* s);
char * TraStr(char* buf, const char* s, unsigned short lg);
unsigned short TraCtxReset(TI_TRA_CTX* pCtx,unsigned short MaskUser1, unsigned short MaskUser2, const char* pMasterKeyUser, const char* pPrgUser );
unsigned short TraCtxTrace(TI_TRA_CTX* pCtx,unsigned short Level,unsigned short Id, const char * tfn, const char * mes,...);
unsigned short TraTrace(unsigned short Level,unsigned short Id, const char * tfn, const char * mes,...);


// ****************************************************************************
// * Trastrupr 
// *    strupr until '=' is found
// ****************************************************************************
static  void  Trastrupr( char * ptr )
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
// * TraTruncString 
// *    Display a string with test on adress and truncation if exceeds 20 car
// *
// * VarGlob:
// *   nothing
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
// *    Display a string with test on adress and max valid length
// *
// * VarGlob:
// *   nothing
// ****************************************************************************
char * TraStr(char* buf, const char* s, unsigned short lg)
{
  if (s==NULL)
    strcpy(buf,"<NULL>");
  else
    {
    lg = (lg>80) ? 80 : lg;
    strncpy(buf, s, lg);
    buf[lg]='\0';
    buf[77]='.';
    buf[78]='.';
    buf[79]='.';
    buf[80]='\0';
    }
  return buf;
}

// ****************************************************************************
// * TraGetProcessID 
// *    Returns a unic ID to identify an application (OS depending)
// *
// * VarGlob:
// *   nothing
// ****************************************************************************
static unsigned long TraGetProcessID(void)
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

#elif defined(__linux__)
  ProcessID = getpid();

#else
  ProcessID = 0;
#endif

  return ProcessID;
}

// ****************************************************************************
// * GetKey
// *    Read a value in ini file
// * 
// *  Value       OUT : Value (truncated at LgMax), empty string if not found
// *  SearchKey   IN  : MasterKey
// *  SearchKey   IN  : Key
// *  LgMax       IN  : Max size for Value, including \0
// *  IsPathName  IN  : CI_TRA_TRUE if the value is a path name
// *
// *  RETURN          : CI_TRA_TRUE if value found
// * 
// * VarGlob:
// *  nothing
// ****************************************************************************
static unsigned short GetKey(char* Value, const char* MasterKey, const char* SearchKey, unsigned short LgMax, unsigned short IsPathName)
{
char str[512];
char Key[512];
char *ptr;
char *ptrSearch;
FILE *Handle;
unsigned short i;
unsigned short IsNextKey;

  strcpy(Key,SearchKey);
  Trastrupr(Key);
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
    fgets(str,512,Handle);
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
    fgets(str,512,Handle);
    Trastrupr(str);

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
      case '\n': Value[i]='\0'  ; break;
      default:   Value[i]=ptr[i]; break;
      }
    }
  Value[i] = '\0';

  // ---------------------------------------------------------
  // - Add a slash if it is a path
  // ---------------------------------------------------------
  #if defined(__linux__)
  if ( (IsPathName) && ((short)strlen(Value)<(short)(LgMax-1)) && (Value[strlen(Value)-1]!='/') )
    strcat(Value,"/");
  
  #else
  if ( (IsPathName) && ((short)strlen(Value)<(short)(LgMax-1)) && (Value[strlen(Value)-1]!='\\') )
    strcat(Value,"\\");
  #endif
    
  return CI_TRA_TRUE;
}

// ****************************************************************************
// * TraInit 
// *    Initialisation of the trace
// *
// * VarGlob:
// *   g_IsTraOn     OUT
// *   s_TraPrg      OUT
// *   s_TraProcID   OUT
// *   s_TraLevel    OUT
// *   s_TraID       OUT
// *   s_TraFile     OUT
// *   s_TraPrgUser  IN
// *
// ****************************************************************************
static void TraInit(TI_TRA_CTX* pCtx, const char* pSetMasterKey, const char* pSetPrg, unsigned short SetMask1, unsigned short SetMask2, unsigned short IsReset )
{
char  buf[5];
unsigned short  LevelTmp = 0;
unsigned short  IsLevel = CI_TRA_FALSE;

// ------------------------------------------------
// - Default static init
// ------------------------------------------------
pCtx->On   = 0;
pCtx->FilterLevel  = CI_TRA_F_ERROR_OR_WARNING;
pCtx->FilterId     = 0xFFFF;
pCtx->pri_Process  = TraGetProcessID();

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
GetKey(buf, pSetMasterKey, "ON", 5, CI_TRA_FALSE);
if (buf[0]=='1')
   pCtx->On = CI_TRA_ON_OK;
else
   {
   pCtx->Line[0] = buf[0];   
   return;
   }

// --- Trace file name
if (!GetKey(pCtx->pri_File, pSetMasterKey, "FILE", 512, CI_TRA_FALSE))
   strcpy(pCtx->pri_File,CI_TRA_NAME);

// --- IDs
if (GetKey(buf, pSetMasterKey, "MASK_ID", 5, CI_TRA_FALSE))
   sscanf(buf,"%hX",&pCtx->FilterId);

// --- Level bit by bit
IsLevel |= GetKey(buf, pSetMasterKey, "VISU_TIME", 2, CI_TRA_FALSE);
if (buf[0]=='1') LevelTmp |= CI_TRA_F_TIME;

IsLevel |= GetKey(buf, pSetMasterKey, "VISU_MILLI", 2, CI_TRA_FALSE);
if (buf[0]=='1') LevelTmp |= (CI_TRA_F_TIME | CI_TRA_F_TIME_MILLI);

IsLevel |= GetKey(buf, pSetMasterKey, "VISU_PRG", 2, CI_TRA_FALSE);
if (buf[0]=='1') LevelTmp|= CI_TRA_F_PRG;

IsLevel |= GetKey(buf, pSetMasterKey, "VISU_ID", 2, CI_TRA_FALSE);
if (buf[0]=='1') LevelTmp|= CI_TRA_F_ID;

IsLevel |= GetKey(buf, pSetMasterKey, "VISU_ALIGN", 2, CI_TRA_FALSE);
if (buf[0]=='1') LevelTmp |= CI_TRA_F_DUMPALIGN;

IsLevel |= GetKey(buf, pSetMasterKey, "L_ERROR", 2, CI_TRA_FALSE);
if (buf[0]=='1') LevelTmp |= CI_TRA_F_ERROR;

IsLevel |= GetKey(buf, pSetMasterKey, "L_WARNING", 2, CI_TRA_FALSE);
if (buf[0]=='1') LevelTmp |= CI_TRA_F_WARNING;

IsLevel |= GetKey(buf, pSetMasterKey, "L_FUNCTION", 2, CI_TRA_FALSE);
if (buf[0]=='1') LevelTmp |= CI_TRA_F_FUNCTION;

IsLevel |= GetKey(buf, pSetMasterKey, "L_PARAM", 2, CI_TRA_FALSE);
if (buf[0]=='1') LevelTmp |= CI_TRA_F_PARAM;

IsLevel |= GetKey(buf, pSetMasterKey, "L_INFO_HIGH", 2, CI_TRA_FALSE);
if (buf[0]=='1') LevelTmp |= CI_TRA_F_INFO_HIGH;

IsLevel |= GetKey(buf, pSetMasterKey, "L_INFO_LOW", 2, CI_TRA_FALSE);
if (buf[0]=='1') LevelTmp |= CI_TRA_F_INFO_LOW;

IsLevel |= GetKey(buf, pSetMasterKey, "L_DEBUG", 2, CI_TRA_FALSE);
if (buf[0]=='1') LevelTmp |= CI_TRA_F_DEBUG;

IsLevel |= GetKey(buf, pSetMasterKey, "L_DUMP", 2, CI_TRA_FALSE);
if (buf[0]=='1') LevelTmp |= CI_TRA_F_DUMP;

IsLevel |= GetKey(buf, pSetMasterKey, "L_X", 2, CI_TRA_FALSE);
if (buf[0]=='1') LevelTmp |= CI_TRA_F_X;

if (IsLevel)
   pCtx->FilterLevel = LevelTmp;

// --- Validity test
pCtx->On = (pCtx->FilterLevel && pCtx->FilterId) ? CI_TRA_ON_OK : 0;

if (!pCtx->On)
   return;

TraMessageInit(pCtx,pSetMasterKey,IsReset);
}

// ****************************************************************************
// * TraMessageInit 
// *    Trace message for initialisation of the trace
// *
// * VarGlob:
// *   pCtx          IN
// *   s_TraPrg      IN
// *   s_TraProcID   IN
// *   s_TraLevel    IN
// *
// ****************************************************************************
static void TraMessageInit(TI_TRA_CTX* pCtx, const char* pMasterKey, unsigned short IsReset)
{
char *        pBuf; /* Pointer in s_TraBuf */
FILE *        Handle;
time_t        Time;
struct tm*    Tm;
int ret=0;
#if defined(__Prl)
int _fSavemode;
#endif

#if defined(__Prl)
_fSavemode = _fmode;
_fmode = O_NGF_LNWR | O_NGF_LNRD;
#endif
Handle=fopen(pCtx->pri_File,"a");
#if defined(__Prl)
_fmode = _fSavemode;
#endif
if (Handle==NULL)
   return;  

pBuf = pCtx->pri_Buf;

// ---------------------------------------------
// --- Process
// ---------------------------------------------
pBuf+= sprintf(pBuf,"%08lX W >>> %s <<< %s L=%04X ID=(%04X,%04X,%04X) K='%s' ",
                   pCtx->pri_Process         , 
                   pCtx->pri_Prg             ,
                   (IsReset) ? "(reset)" : "",
                   pCtx->FilterLevel         , 
                   pCtx->FilterId            ,
                   pCtx->pri_MaskId1         ,
                   pCtx->pri_MaskId2         ,
                   pMasterKey                );

time(&Time);
Tm=localtime(&Time);
pBuf+=sprintf(pBuf,"%02d/%02d/%02d %02d:%02d:%02d ",Tm->tm_mday,Tm->tm_mon+1,Tm->tm_year-100,Tm->tm_hour,Tm->tm_min,Tm->tm_sec);

// ---------------------------------------------
// --- Print in file
// ---------------------------------------------
*pBuf++='\n';
*pBuf++='\0';

ret = fprintf(Handle,pCtx->pri_Buf);
fclose(Handle);
}

// ****************************************************************************
// * TraDateTime
// *
// *  pBuf     IN  : pointer inside s_TraBuf (line to trace)
// *  IsMilli  IN  : True=Display only ss.ms False=Display Date and Time
// *
// * VarGlob:
// *   nothing
// ****************************************************************************
static int TraDateTime( char* pBuf, unsigned short IsMilli)
{
int NbCar = 0;

#if defined(__Prl)
// --- Twin: Date and time without milliseconds
time_t        Time;
struct tm*    Tm;
time(&Time);
Tm=localtime(&Time);

NbCar = sprintf(pBuf,"%02d/%02d/%02d %02d:%02d:%02d ",Tm->tm_mday,Tm->tm_mon+1,Tm->tm_year-100,Tm->tm_hour,Tm->tm_min,Tm->tm_sec);

#elif defined(_WIN32)
// --- Windows: Date and time with milliseconds
SYSTEMTIME Tm;
GetLocalTime( &Tm );

if (IsMilli)
   NbCar = sprintf(pBuf,"%02d.%03d ",Tm.wSecond,Tm.wMilliseconds);
else
   NbCar = sprintf(pBuf,"%02d/%02d/%04d %02d:%02d:%02d.%03d ",Tm.wDay,Tm.wMonth,Tm.wYear,Tm.wHour,Tm.wMinute,Tm.wSecond,Tm.wMilliseconds);

#elif defined(__linux__)
// --- Linux: Date and time with milliseconds
struct timeb  Timeb;
struct tm*    Tm;
ftime(&Timeb);
Tm=localtime(&Timeb.time);

if (IsMilli)
   NbCar = sprintf(pBuf,"%02d.%03d ",Tm->tm_sec,Timeb.millitm);
else
   NbCar = sprintf(pBuf,"%02d/%02d/%02d %02d:%02d:%02d.%03d ",Tm->tm_mday,Tm->tm_mon+1,Tm->tm_year-100,Tm->tm_hour,Tm->tm_min,Tm->tm_sec,Timeb.millitm);

#endif

return NbCar;
}

// ****************************************************************************
// * TraDump
// *
// *  pCtx     IN
// *  Handle   IN  : handle on the trace file
// *  pBuf     IN  : pointer inside s_TraBuf (line to trace)
// *  mes      IN  : title of the dump trace
// *  Zone     IN  : dump zone
// *  lgZone   IN  : size of zone
// *
// * VarGlob:
// *   s_TraBuf      IN/OUT
// *
// ****************************************************************************
static void TraDump( const TI_TRA_CTX* pCtx, FILE* Handle, unsigned char * pBuf, const char * mes, const unsigned char * Zone, const unsigned short lgZone)
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

pBufDump = pBuf;

// ---------------------------------------------
// --- Print title and title of dump in file
// ---------------------------------------------
pBuf+=sprintf(pBuf,"%s \n",mes);
fprintf(Handle,"%s",pCtx->pri_Buf);

c = (unsigned char) ((unsigned long)pBegDump) & 0x0F;
pBufHexa = BufHexa;
pBufHexa+=sprintf(pBufHexa,"          ");             
for (i=0 ; i<0x10 ; i++)
   pBufHexa+=sprintf(pBufHexa," %X ",(c+i)%0x10);             

pBuf = pBufDump;
pBuf+=sprintf(pBuf,"%s\n",BufHexa);
fprintf(Handle,"%s",pCtx->pri_Buf);
fflush(Handle);

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
      pBuf = pBufDump;
      pBuf+=sprintf(pBuf,"%04X:%04X ", TraHIWORD(((unsigned long)pBegDump)+((i/0x10)*0x10)), TraLOWORD(((unsigned long)pBegDump)+((i/0x10)*0x10)) );
      pBuf+=sprintf(pBuf,"%s", BufHexa);
      pBuf+=sprintf(pBuf,"%s\n", BufCar );
      fprintf(Handle,"%s",pCtx->pri_Buf);
      fflush(Handle);
      pBufHexa = BufHexa;
      pBufCar  = BufCar;
      } 
   }
}

// ****************************************************************************
// * TraCtxReset
// *   If necessary, it is possible to initialise settings at execution time
// *   using this function. The ini file will be red at next call to TraTrace
// *   and settable parameters can be changed.
// *
// * VarGlob:
// *   s_TraLevel          OUT
// *   g_IsTraOn           OUT
// *   s_TraMasterKeyUser  OUT
// *   s_TraPrgUser        OUT
// *   s_TraIdMaskUser1    OUT
// *   s_TraIdMaskUser2    OUT
// *
// ****************************************************************************
unsigned short TraCtxReset( TI_TRA_CTX* pCtx, unsigned short MaskUser1, unsigned short MaskUser2, const char* pMasterKeyUser, const char* pPrgUser )
{
// --- Applicative or default Context
if (pCtx==NULL)
  pCtx = &g_TraCtx;

// --- Force to read again the ini file
TraInit( pCtx, (pMasterKeyUser!=NULL)        ? pMasterKeyUser : CE_TRA_MASTERKEY  , 
               (pPrgUser!=NULL)              ? pPrgUser       : CI_PRG_ID         , 
               (unsigned short) ((MaskUser1) ? MaskUser1      : CI_TRA_ID_MASK_1) , 
               (unsigned short) ((MaskUser2) ? MaskUser2      : CI_TRA_ID_MASK_2) ,
               CI_TRA_TRUE );

return 1;
}

// ****************************************************************************
// * TraCtxTrace
// *
// * pCtx    IN/OUT: Pointer on a trace context (if NULL, default context is used)
// * Level     IN  : level
// * Id        IN  : Module ID 
// * tfn       IN  : origin of the message (typically, name of the calling function)
// * mes       IN  : string message (cf sysprintf)
// * ...       IN  : optional arguments (cf sysprintf)
// *
// * VarGlob:
// *  all      IN / OUT (at initialisation)
// *
// ****************************************************************************
unsigned short TraCtxTrace(TI_TRA_CTX* pCtx,unsigned short Level,unsigned short Id, const char * tfn, const char * mes,...) 
{
char *     pBuf; 
FILE *     Handle;
#if defined(__Prl)
int _fSavemode;
#endif

// ---------------------------------------------
// --- Applicative or default Context
// ---------------------------------------------
if (pCtx==NULL)
    pCtx = &g_TraCtx;

// ---------------------------------------------
// --- Test parameters, and initialisation
// ---------------------------------------------

// Init
if (pCtx->On & CI_TRA_ON_FIRST_TIME)
   {
   TraInit(pCtx, CE_TRA_MASTERKEY, CI_PRG_ID, CI_TRA_ID_MASK_1, CI_TRA_ID_MASK_2, CI_TRA_FALSE);
   if (!pCtx->On)
      return 1;
   }
 
// Level requested
if ( !( (Level&pCtx->FilterLevel) && ((Level&CI_TRA_F_ERROR_OR_WARNING) || (Id&pCtx->FilterId)) )  )
   return 1;

// Open the trace file
#if defined(__Prl)
_fSavemode = _fmode;
_fmode = O_NGF_LNWR | O_NGF_LNRD;
#endif
Handle=fopen(pCtx->pri_File,"a");
#if defined(__Prl)
_fmode = _fSavemode;
#endif
if (Handle==NULL)
   return 1;  

pBuf = pCtx->pri_Buf;
   
// ---------------------------------------------
// --- Process
// ---------------------------------------------
pBuf+=sprintf(pBuf,"%08lX ",pCtx->pri_Process);

// ---------------------------------------------
// --- Level
// ---------------------------------------------
*pBuf++= (Level & CI_TRA_F_ERROR)   ? 'E' :
         (Level & CI_TRA_F_WARNING) ? 'W' :
         (Level & CI_TRA_F_FUNCTION)? 'F' :
         (Level & CI_TRA_F_PARAM)   ? 'P' :
         (Level & CI_TRA_F_X)       ? 'x' :
         'I';
*pBuf++= ' ';

// ---------------------------------------------
// --- Time
// ---------------------------------------------
if (pCtx->FilterLevel & CI_TRA_F_TIME)
   pBuf+=TraDateTime( pBuf, (unsigned short)(pCtx->FilterLevel & CI_TRA_F_TIME_MILLI) );

// ---------------------------------------------
// --- Id (prg Id, mask, and exact value)
// ---------------------------------------------
if (pCtx->FilterLevel & CI_TRA_F_PRG) 
   {
   pBuf+=sprintf(pBuf,pCtx->pri_Prg);
   *pBuf++= '_';
   *pBuf++= (Id & pCtx->pri_MaskId2) ? '2' :
           (Id & pCtx->pri_MaskId1) ? '1' :
           '0';

   if (pCtx->FilterLevel & CI_TRA_F_ID)
    pBuf+=sprintf(pBuf,":%04X ",Id);
   else
    *pBuf++=' ';
   }

// ---------------------------------------------
// --- Name of function
// ---------------------------------------------
pBuf+=sprintf(pBuf,"%s ",tfn);

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
      lgZone = va_arg( marker, unsigned short);
      va_end( marker);
      TraDump(pCtx, Handle, pBuf, mes, Zone, lgZone );   
      }
   }
else
   {
   pBuf+=vsprintf(pBuf,mes,(char  *)(&mes+1));
   *pBuf++='\n';
   *pBuf++='\0';
   fprintf(Handle,"%s",pCtx->pri_Buf);
   }

fclose(Handle);
return 1;       
}

// ****************************************************************************
// * TraTrace
// *
// * Level     IN  : level
// * Id        IN  : Module ID 
// * tfn       IN  : origin of the message (typically, name of the calling function)
// * mes       IN  : string message (cf sysprintf)
// * ...       IN  : optional arguments (cf sysprintf)
// *
// * VarGlob:
// *  all      IN / OUT (at initialisation)
// *
// ****************************************************************************
unsigned short TraTrace(unsigned short Level,unsigned short Id, const char * tfn, const char * mes,...) 
{
char *       pBuf; 
FILE *       Handle;
TI_TRA_CTX * pCtx = &g_TraCtx;
#if defined(__Prl)
int _fSavemode;
#endif

// ---------------------------------------------
// --- Test parameters, and initialisation
// ---------------------------------------------

// Init
if (pCtx->On & CI_TRA_ON_FIRST_TIME)
   {
   TraInit(pCtx, CE_TRA_MASTERKEY, CI_PRG_ID, CI_TRA_ID_MASK_1, CI_TRA_ID_MASK_2, CI_TRA_FALSE);
   if (!pCtx->On)
      return 1;
   }
 
// Level requested
if ( !( (Level&pCtx->FilterLevel) && ((Level&CI_TRA_F_ERROR_OR_WARNING) || (Id&pCtx->FilterId)) )  )
   return 1;

// Open the trace file
#if defined(__Prl)
_fSavemode = _fmode;
_fmode = O_NGF_LNWR | O_NGF_LNRD;
#endif
Handle=fopen(pCtx->pri_File,"a");
#if defined(__Prl)
_fmode = _fSavemode;
#endif
if (Handle==NULL)
   return 1;  

pBuf = pCtx->pri_Buf;
   
// ---------------------------------------------
// --- Process
// ---------------------------------------------
pBuf+=sprintf(pBuf,"%08lX ",pCtx->pri_Process);

// ---------------------------------------------
// --- Level
// ---------------------------------------------
*pBuf++= (Level & CI_TRA_F_ERROR)   ? 'E' :
         (Level & CI_TRA_F_WARNING) ? 'W' :
         (Level & CI_TRA_F_FUNCTION)? 'F' :
         (Level & CI_TRA_F_PARAM)   ? 'P' :
         (Level & CI_TRA_F_X)       ? 'x' :
         'I';
*pBuf++= ' ';

// ---------------------------------------------
// --- Time
// ---------------------------------------------
if (pCtx->FilterLevel & CI_TRA_F_TIME)
   pBuf+=TraDateTime( pBuf, (unsigned short)(pCtx->FilterLevel & CI_TRA_F_TIME_MILLI) );

// ---------------------------------------------
// --- Id (prg Id, mask, and exact value)
// ---------------------------------------------
if (pCtx->FilterLevel & CI_TRA_F_PRG) 
   {
   pBuf+=sprintf(pBuf,pCtx->pri_Prg);
   *pBuf++= '_';
   *pBuf++= (Id & pCtx->pri_MaskId2) ? '2' :
           (Id & pCtx->pri_MaskId1) ? '1' :
           '0';

   if (pCtx->FilterLevel & CI_TRA_F_ID)
    pBuf+=sprintf(pBuf,":%04X ",Id);
   else
    *pBuf++=' ';
   }

// ---------------------------------------------
// --- Name of function
// ---------------------------------------------
pBuf+=sprintf(pBuf,"%s ",tfn);

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
      lgZone = va_arg( marker, unsigned short);
      va_end( marker);
      TraDump(pCtx, Handle, pBuf, mes, Zone, lgZone );   
      }
   }
else
   {
   pBuf+=vsprintf(pBuf,mes,(char  *)(&mes+1));
   *pBuf++='\n';
   *pBuf++='\0';
   fprintf(Handle,"%s",pCtx->pri_Buf);
   }

fclose(Handle);
return 1;       
}

#endif /*TRACEON*/