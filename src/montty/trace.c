/** @pkg Staff.Fred.zTrace */ 

// ****************************************************************************
// * zTrace.c
// * Trace functionnality
// ****************************************************************************

// Ce code utilise les définitions suivantes
// _WIN32
// _LINUX
// __Prl

// ----------------------------------------------------------------------------
// - Headers of modules
// ----------------------------------------------------------------------------

#if defined(_WIN32)
#include <windows.h>
#endif

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#ifdef TRACEON
  #pragma message("PROLOGUE MSG: Trace ON")
#endif 

// ----------------------------------------------------------------------------
// - Constantes for internal use
// ----------------------------------------------------------------------------

#define	CI_TRA_FALSE	0
#define	CI_TRA_TRUE	1

// --- Mask of ID
//#define CI_TRA_ID_APPLI     0x8000
//#define CI_TRA_ID_ABAL      0x7F00
//#define CI_TRA_ID_Z         0x00FF

#define CI_TRA_ID_APPLI     0x8000
#define CI_TRA_ID_ABAL      0x0000
#define CI_TRA_ID_Z         0x7FFF

#define CI_TRA_ID_DEFAULT   0xFFFF

// --- Mask of level
#define CI_TRA_F_INIT       0x8000
#define CI_TRA_F_CYCLE      0x4000
#define CI_TRA_F_TIME       0x2000
#define CI_TRA_F_ID         0x1000
#define CI_TRA_F_DUMPALIGN  0x0800
#define CI_TRA_F_TIME_MILLI 0x0400
// 0x0200 free
// 0x0100 free
#define CI_TRA_F_ERROR      0x0001
#define CI_TRA_F_WARNING    0x0002
#define CI_TRA_F_FUNCTION   0x0004
#define CI_TRA_F_PARAM      0x0008
#define CI_TRA_F_INFO_HIGH  0x0010
#define CI_TRA_F_INFO_LOW   0x0020
#define CI_TRA_F_DEBUG      0x0040
#define CI_TRA_F_DUMP       0x0080

#define CI_TRA_F_DEFAULT    0x183F
#define CI_TRA_F_ERROR_OR_WARNING 0x0003

#if defined(__Prl)
#define CI_TRA_NAME     "is\\TTYtrace.txt"
#define CI_TRA_ININAME  "is\\TTYtrace.ini"

#elif defined(_LINUX)
#define CI_TRA_NAME     "/opt/prologue/bin/ttytrace.txt"
#define CI_TRA_ININAME  "/opt/prologue/bin/ttytrace.ini"

#else
#define CI_TRA_NAME     "C:\\TTYtrace.txt"
#define CI_TRA_ININAME  "C:\\TTYtrace.ini"
#endif

#define CE_TRA_MASTERKEY "[Trace]"

#ifndef TRACEON
// ----------------------------------------------------------------------------
// - Functions NOTRACE
// ----------------------------------------------------------------------------

unsigned short TraTrace     (unsigned short Level,unsigned short Id, const char * tfn, const char * mes,...){return 0;}
unsigned short BdaTra_Msg   (unsigned short Level,unsigned short Id, const char * tfn, const char * mes){return 0;}
unsigned short BdaTra_MsgInt(unsigned short Level,unsigned short Id, const char * tfn, const char * mes, unsigned short val){return 0;}
unsigned short BdaTra_Dump  (unsigned short Level,unsigned short Id, const char * tfn, const char * mes, const char * Zone, unsigned short Lg){return 0;}

#else
// ----------------------------------------------------------------------------
// - Global variables of this module
// ----------------------------------------------------------------------------
unsigned short  g_IsTraOn   = 1;
char            g_TraLine[81];

unsigned short  s_TraLevel  = 0;
unsigned short  s_TraID     = 0;
unsigned long   s_TraProcID = 0;
char            s_TraBuf[256];
char            s_TraTrunc[40];
char            s_TraFile[512];

// ----------------------------------------------------------------------------
// - Functions TRACE
// ----------------------------------------------------------------------------

// ****************************************************************************
/** TraGetProcessID 
    Returns the console number of the application

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// *   nothing
// *
// ****************************************************************************
char * TraTruncString(char* s)
{
  if (s==NULL)
    strcpy(s_TraTrunc,"<NULL>");
  else
    {
    strncpy(s_TraTrunc, s, 20);
    s_TraTrunc[20]='.';
    s_TraTrunc[21]='.';
    s_TraTrunc[22]='.';
    s_TraTrunc[23]='\0';
    }

  return s_TraTrunc;
}

// ****************************************************************************
/** TraGetProcessID 
    Returns the console number of the application

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// *   nothing
// *
// ****************************************************************************
static unsigned long TraGetProcessID(void)
{
unsigned long ProcessID = 0;

#ifdef __Prl
  _asm
    {
    mov ah,34H
    int 110
    mov ProcessID,cl
    }
#endif
  
#ifdef _WIN32
  ProcessID = GetCurrentProcessId();
#endif

#ifdef _LINUX
  // A VOIR
  ProcessID = 0;
#endif

  return ProcessID;
}

static	void	Trastrupr( char * ptr )
{
  for ( ; *ptr != 0; ptr++ ) {
  	if (( *ptr >= 'a' ) 
	&&  ( *ptr <= 'z' ))
			*ptr = ( *ptr - ('a' - 'A'));
	else if ( *ptr == '=' )
		break;
		}
		
/*  strupr(ptr); */
	return;
}


// ****************************************************************************
/** GetKey
    Read a value in zini file

 * @param Value       OUT : Value (truncated at LgMax), empty string if not found
 * @param Key         IN  : Key
 * @param LgMax       IN  : Max size for Value, including \0
 * @param IsPathName  IN  : CI_TRA_TRUE if this is a path name

 * @return: pointer on Value
 * @author ANF
 */
// * VarGlob:
// ****************************************************************************



char * GetKey(char * Value, const char* SearchKey, unsigned short LgMax, unsigned short IsPathName)
{
char str[512];
char Key[512];
char *ptr;
char *ptrSearch;
FILE *Handle;
unsigned short i;

  strcpy(Key,SearchKey);
  Trastrupr(Key);
    Value[0]='\0';

  // ---------------------------------------------------------
  // - Find the MasterKey
  // - At the end, next line is after the MasterKey
  // ---------------------------------------------------------
  Handle = fopen(CI_TRA_ININAME,"rt");
    if (!Handle)
      return Value;

  ptr = NULL;
  do 
    {
    fgets(str,512,Handle);
    if (*str!=';' && *str!='#')
      ptr = strstr(str,CE_TRA_MASTERKEY);
    } 
  while(!ptr && !feof(Handle) );

  if (feof(Handle))
    {
    fclose(Handle);
    return Value;
    }

  // ---------------------------------------------------------
  // - Find the key
  // - At the end, the key is identified 
  // - the file is closed
  // - and str contains the line 
  // ---------------------------------------------------------
  ptr = NULL;
  do 
    {
    fgets(str,512,Handle);
    Trastrupr(str);

    if (*str!=';' && *str!='#')
      {
      ptrSearch = str;

      // Saut des blancs en début
      while (*ptrSearch==' ' || *ptrSearch=='\t')
        ptrSearch++;

      // Nom de la clé
      if (!strncmp(ptrSearch,Key,strlen(Key)))
        {
        ptrSearch += strlen(Key);
        if (*ptrSearch=='=' || *ptrSearch==' ' || *ptrSearch=='\t')
          ptr = ptrSearch;
        }
      }
    } 
  while(!ptr && !feof(Handle) );

  if (feof(Handle))
    {
    fclose(Handle);
    return Value;
    }

  fclose(Handle);

  // ---------------------------------------------------------
  // - Find the value
  // - At the end, ptr points on the beginning of the value
  // ---------------------------------------------------------
  ptr = strchr(str,'=');
  if (!ptr)   
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
  if ( (IsPathName) && ((short)strlen(Value)<(short)(LgMax-1)) && (Value[strlen(Value)-1]!='\\') )
    strcat(Value,"\\");
    
  return Value;
}


// ****************************************************************************
/** TraInit 
    (TRACEON version) 
    Initialisation of the trace

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// *   s_TraLevel
// *
// ****************************************************************************


unsigned short	TraLOWORD(unsigned long l) { return( ((unsigned short)( (l) & 0x0000FFFFL ))); }
unsigned short  TraHIWORD(unsigned long l) { return( ((unsigned short)(( (l) >> 16 ) & 0x0000FFFFL))); }


static void TraInit(void)
{
char  buf[5];
unsigned short  LevelTmp = 0;
unsigned short  IsLevelBitByBit = CI_TRA_FALSE;

  // ------------------------------------------------
  // - Default init
  // ------------------------------------------------
  g_IsTraOn   = CI_TRA_FALSE;
  s_TraLevel  = CI_TRA_F_DEFAULT;
  s_TraID     = CI_TRA_ID_DEFAULT;
  s_TraProcID = TraGetProcessID();
  strcpy(s_TraFile,CI_TRA_NAME);

  // ------------------------------------------------
  // - Read ini file
  // ------------------------------------------------

  // --- Activation
  GetKey(buf, "ON", 5, CI_TRA_FALSE);
  if (buf[0]=='1')
    g_IsTraOn = CI_TRA_TRUE;
  else
    return;

  // --- Filename
  GetKey(s_TraFile, "FILE", 512, CI_TRA_FALSE);
  if (s_TraFile[0]=='\0')
    strcpy(s_TraFile,CI_TRA_NAME);

  // --- Level bit by bit
  GetKey(buf, "L_TIME", 2, CI_TRA_FALSE);
  IsLevelBitByBit |= (buf[0]!= '\0');
  if (buf[0]=='1') LevelTmp |= CI_TRA_F_TIME;

  GetKey(buf, "L_MILLI", 2, CI_TRA_FALSE);
  IsLevelBitByBit |= (buf[0]!= '\0');
  if (buf[0]=='1') LevelTmp |= (CI_TRA_F_TIME | CI_TRA_F_TIME_MILLI);

  GetKey(buf, "L_ID", 2, CI_TRA_FALSE);
  IsLevelBitByBit |= (buf[0]!= '\0');
  if (buf[0]=='1') LevelTmp|= CI_TRA_F_ID;

  GetKey(buf, "L_ALIGN", 2, CI_TRA_FALSE);
  IsLevelBitByBit |= (buf[0]!= '\0');
  if (buf[0]=='1') LevelTmp |= CI_TRA_F_DUMPALIGN;

  GetKey(buf, "L_ERROR", 2, CI_TRA_FALSE);
  IsLevelBitByBit |= (buf[0]!= '\0');
  if (buf[0]=='1') LevelTmp |= CI_TRA_F_ERROR;

  GetKey(buf, "L_WARNING", 2, CI_TRA_FALSE);
  IsLevelBitByBit |= (buf[0]!= '\0');
  if (buf[0]=='1') LevelTmp |= CI_TRA_F_WARNING;

  GetKey(buf, "L_FUNCTION", 2, CI_TRA_FALSE);
  IsLevelBitByBit |= (buf[0]!= '\0');
  if (buf[0]=='1') LevelTmp |= CI_TRA_F_FUNCTION;

  GetKey(buf, "L_PARAM", 2, CI_TRA_FALSE);
  IsLevelBitByBit |= (buf[0]!= '\0');
  if (buf[0]=='1') LevelTmp |= CI_TRA_F_PARAM;

  GetKey(buf, "L_INFO_HIGH", 2, CI_TRA_FALSE);
  IsLevelBitByBit |= (buf[0]!= '\0');
  if (buf[0]=='1') LevelTmp |= CI_TRA_F_INFO_HIGH;

  GetKey(buf, "L_INFO_LOW", 2, CI_TRA_FALSE);
  IsLevelBitByBit |= (buf[0]!= '\0');
  if (buf[0]=='1') LevelTmp |= CI_TRA_F_INFO_LOW;

  GetKey(buf, "L_DEBUG", 2, CI_TRA_FALSE);
  IsLevelBitByBit |= (buf[0]!= '\0');
  if (buf[0]=='1') LevelTmp |= CI_TRA_F_DEBUG;

  GetKey(buf, "L_DUMP", 2, CI_TRA_FALSE);
  IsLevelBitByBit |= (buf[0]!= '\0');
  if (buf[0]=='1') LevelTmp |= CI_TRA_F_DUMP;

  if (IsLevelBitByBit)
    s_TraLevel = LevelTmp;

  // --- Level in hexadecimal (if exists, clears all bit-by-bit config)
  GetKey(buf, "L_HEXA", 5, CI_TRA_FALSE);
  if (buf[0]!='\0')
    sscanf(buf,"%hX",&s_TraLevel);

  // --- Module IDs
  GetKey(buf, "ID_HEXA", 5, CI_TRA_FALSE);
  if (buf[0]!='\0')
    sscanf(buf,"%hX",&s_TraID);

  s_TraLevel |= CI_TRA_F_INIT;
}

// ****************************************************************************
/** TraTraceInit 
    (TRACEON version) 
    Trace message for initialisation of the trace

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// *   s_TraLevel
// *
// ****************************************************************************
static void TraTraceInit(void)
{
char *        pBuf; /* Pointer in s_TraBuf */
FILE *        Handle;
time_t        Time;
struct tm*    Tm;
int ret=0;

  if (!g_IsTraOn)
    return;

  // Open the trace file
  #if defined(BDA_TWIN16)
  _fmode |= O_NGF_LNWR | O_NGF_LNRD;
  #endif
  if ((Handle=fopen(s_TraFile,"a"))==NULL)
    return;  

  pBuf = s_TraBuf;

  // ---------------------------------------------
  // --- Process
  // ---------------------------------------------
  pBuf+=sprintf(pBuf,"%08lX W >>> TraceInit <<< L:%04X ID:%04X ",s_TraProcID,s_TraLevel,s_TraID);

  time(&Time);
  Tm=localtime(&Time);
  pBuf+=sprintf(pBuf,"%02d/%02d/%02d %02d:%02d:%02d ",Tm->tm_mday,Tm->tm_mon+1,Tm->tm_year-100,Tm->tm_hour,Tm->tm_min,Tm->tm_sec);

  // ---------------------------------------------
  // --- Print in file
  // ---------------------------------------------
  *pBuf++='\n';
  *pBuf++='\0';
  
  ret = fprintf(Handle,s_TraBuf);
  fclose(Handle);
}

// ****************************************************************************
/** TraDump
    (TRACEON version) 

 * @param

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// *   s_TraLevel
// *   s_TraBuf
// *
// ****************************************************************************
unsigned short TraDump( FILE* Handle, unsigned char * pBuf, const char * mes, const unsigned char * Zone, const unsigned short lgZone, const unsigned short IsAlign)
{
char *          pBufDump; /* Pointer in s_TraBuf */
int             ret=0;
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

  if (IsAlign)
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
  // --- Print title in file
  // ---------------------------------------------
  pBuf+=sprintf(pBuf,"%s \n",mes);
  fprintf(Handle,s_TraBuf);
  fflush(Handle);

  // ---------------------------------------------
  // --- Print title of dump in file
  // ---------------------------------------------
  c = (unsigned char) ((unsigned long)pBegDump) & 0x0F;
  pBufHexa = BufHexa;
  pBufHexa+=sprintf(pBufHexa,"          ");             
  for (i=0 ; i<0x10 ; i++)
    pBufHexa+=sprintf(pBufHexa," %X ",(c+i)%0x10);             

  pBuf = pBufDump;
  pBuf+=sprintf(pBuf,"%s\n",BufHexa);
  fprintf(Handle,s_TraBuf);
  fflush(Handle);

  // ---------------------------------------------
  // --- Print title of dump in file
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
      pBuf+=sprintf(pBuf,"%04X:%04X %s%s\n", TraHIWORD(((unsigned long)pBegDump)+((i/0x10)*0x10)), TraLOWORD(((unsigned long)pBegDump)+((i/0x10)*0x10)), BufHexa, BufCar );
      fprintf(Handle,s_TraBuf);
      fflush(Handle);
      pBufHexa = BufHexa;
      pBufCar  = BufCar;
      } 
    }

  // ---------------------------------------------
  // --- Close file
  // ---------------------------------------------
  fclose(Handle);
return 0;
}

// ****************************************************************************
/** TraTrace
    (TRACEON version) 

 * @param

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// *   s_TraLevel
// *   s_TraBuf
// *
// ****************************************************************************
unsigned short TraTrace(unsigned short Level,unsigned short Id, const char * tfn, const char * mes,...) 
{
char *     pBuf; 
FILE *     Handle;
int ret=0;
        
  // ---------------------------------------------
  // --- Test parameters, and initialisation
  // ---------------------------------------------

  // Init
  if (!(s_TraLevel & CI_TRA_F_INIT))
    {
    TraInit();
    if (!g_IsTraOn)
      return 0;
    TraTraceInit();
    }
    
  // Level requested
  if (!(Level & s_TraLevel))
    return 0;

  // ID requested or Error/Warning always traced
  if (!(Id & s_TraID) && !(Level & CI_TRA_F_ERROR_OR_WARNING))
    return 0;

  // Open the trace file
  #if defined(BDA_TWIN16)
  _fmode |= O_NGF_LNWR | O_NGF_LNRD;
  #endif
  if ((Handle=fopen(s_TraFile,"a"))==NULL)
    return 0;  

  pBuf = s_TraBuf;
      
  // ---------------------------------------------
  // --- Process
  // ---------------------------------------------
  pBuf+=sprintf(pBuf,"%08lX ",s_TraProcID);

  // ---------------------------------------------
  // --- Level
  // ---------------------------------------------
  if      (Level & CI_TRA_F_ERROR)
      *pBuf++='E';
  else if (Level & CI_TRA_F_WARNING)
      *pBuf++='W';
  else if (Level & CI_TRA_F_FUNCTION)
      *pBuf++='F';
  else if (Level & CI_TRA_F_PARAM)
      *pBuf++='P';
  else if (Level & CI_TRA_F_INFO_HIGH)
      *pBuf++='I';
  else if (Level & CI_TRA_F_INFO_LOW)
      *pBuf++='I';
  else if (Level & CI_TRA_F_DEBUG)
      *pBuf++='D';
  else if (Level & CI_TRA_F_DUMP)
      *pBuf++='M';
  else
      *pBuf++='?';

  *pBuf++=' ';
  
  // ---------------------------------------------
  // --- Time
  // ---------------------------------------------
  if (s_TraLevel & CI_TRA_F_TIME) 
    {
    #if defined(__Prl)
    // Date and time without milliseconds
    time_t        Time;
    struct tm*    Tm;
    time(&Time);
    Tm=localtime(&Time);
    pBuf+=sprintf(pBuf,"%02d/%02d/%02d %02d:%02d:%02d ",Tm->tm_mday,Tm->tm_mon+1,Tm->tm_year-100,Tm->tm_hour,Tm->tm_min,Tm->tm_sec);
    #endif

    #if defined(_WIN32)
    // Date and time with milliseconds
    SYSTEMTIME Tm;
    GetLocalTime( &Tm );
    if (s_TraLevel & CI_TRA_F_TIME_MILLI)
      pBuf+=sprintf(pBuf,"%02d:%02d.%03d ",Tm.wMinute,Tm.wSecond,Tm.wMilliseconds);
    else
      pBuf+=sprintf(pBuf,"%02d/%02d/%04d %02d:%02d:%02d.%03d ",Tm.wDay,Tm.wMonth,Tm.wYear,Tm.wHour,Tm.wMinute,Tm.wSecond,Tm.wMilliseconds);
    #endif

    #if defined(_LINUX)
    // Date and time without milliseconds
    time_t        Time;
    struct tm*    Tm;
    time(&Time);
    Tm=localtime(&Time);
    pBuf+=sprintf(pBuf,"%02d/%02d/%02d %02d:%02d:%02d ",Tm->tm_mday,Tm->tm_mon+1,Tm->tm_year-100,Tm->tm_hour,Tm->tm_min,Tm->tm_sec);
    #endif

    }

  // ---------------------------------------------
  // --- Id (4 first characters)
  // ---------------------------------------------
  if      (Id & CI_TRA_ID_ABAL)
      *pBuf++='L';
  else if (Id & CI_TRA_ID_Z)
      *pBuf++='Z';
  else
      *pBuf++='A';

  if (s_TraLevel & CI_TRA_F_ID)
    pBuf+=sprintf(pBuf,":%04X ",Id);
  else
    *pBuf++=' ';

  // ---------------------------------------------
  // --- Name of function
  // ---------------------------------------------
  pBuf+=sprintf(pBuf,"%s ",tfn);

  // ---------------------------------------------
  // --- Message
  // ---------------------------------------------
  if (Level & CI_TRA_F_DUMP)
    {
    if (s_TraLevel & CI_TRA_F_DUMP)
      {
      va_list            marker;
      unsigned char *    Zone;
      unsigned short     lgZone;
      unsigned short     IsAlign;

      va_start(marker, mes);
      Zone   = va_arg( marker, unsigned char*);
      lgZone = va_arg( marker, unsigned short);
      va_end( marker);
      IsAlign = (s_TraLevel&CI_TRA_F_DUMPALIGN);
      TraDump(Handle, pBuf, mes, Zone, lgZone, IsAlign );   
      }
    }
  else
    {
    pBuf+=vsprintf(pBuf,mes,(char  *)(&mes+1));
    *pBuf++='\n';
    *pBuf++='\0';
    ret = fprintf(Handle,s_TraBuf);
    fclose(Handle);
    }
  return 0;       
  }

// ****************************************************************************
/** BdaTra_Msg: ABAL API
    (TRACEON version) 
    Trace a message

 * @param Level     IN : trace level
 * @param Id       IN : module ID (4 characters)
 * @param mes      IN : Message
 
 * @return 0

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// *   nothing
// *
// ****************************************************************************
unsigned short BdaTra_Msg(unsigned short Level,unsigned short Id, const char * tfn, const char * mes)
{
TraTrace(Level,Id,tfn,mes);
return 0;
}

// ****************************************************************************
/** BdaTra_Msg: ABAL API
    (TRACEON version) 
    Trace a message and a WORD value

 * @param Level     IN : trace level
 * @param Id       IN : module ID (4 characters)
 * @param mes      IN : Message
 * @param val      IN : WORD value
 
 * @return 0

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// *   nothing
// *
// ****************************************************************************
unsigned short BdaTra_MsgInt(unsigned short Level,unsigned short Id, const char * tfn, const char * mes, unsigned short val)
{
TraTrace(Level,Id,tfn,"%s : %d (%04Xh)", mes, val, val);
return 0;
}

// ****************************************************************************
/** BdaTra_Dump: ABAL API
    (TRACEON version) 
    Trace a message and a WORD value

 * @param Level    IN : trace level
 * @param Id       IN : module ID (4 characters)
 * @param mes      IN : Message
 * @param val      IN : Zone
 * @param val      IN : Length
 
 * @return 0

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// *   nothing
// *
// ****************************************************************************
unsigned short BdaTra_Dump(unsigned short Level,unsigned short Id, const char * tfn, const char * mes, const char * Zone, unsigned short Lg)
{
Level|=CI_TRA_F_DUMP;
TraTrace( Level, Id, tfn, mes, Zone, Lg);
return 0;
}


#endif 
//TRACEON
