/**********************************/
/*          TFileInc.h            */
/* Support of text files handling */
/*            v.1.00              */
/**********************************/
#ifndef TFILEINC_H
#define TFILEINC_H

// Снять знак комментария для отладочного режима:
//#define  DEBUG_MIX_CPP_VER
// TList::dwFmax_buf - new variable (only in this version)

#if defined (BDA_WIN32)
#include <io.h>
#include <sys\types.h>
#include <sys\stat.h>

#elif defined (BDA_UNIX)
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#elif defined (BDA_TWIN16)
#include <io.h>
#endif

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <errno.h>

// ----------------------------------------------------------------------------------
// - Specific-OS constants for I/O functions
// ----------------------------------------------------------------------------------
#if defined(BDA_WIN32)

#elif defined (BDA_UNIX)

#define O_BINARY  0
#define O_TEXT    0

#elif defined(BDA_TWIN16)

#define CREATE_NEW          1
#define CREATE_ALWAYS       2
#define OPEN_EXISTING       3
#define OPEN_ALWAYS         4
#define TRUNCATE_EXISTING   5

// for open, create
// Permissions are not implemented in Twin and are ignored (cf doc CRTL_052.doc)
#define S_IREAD    0000400
#define S_IWRITE   0000200

#else
#error PROLOGUE MSG: OS inconnu
#endif

// ----------------------------------------------------------------------------------
// - Multi-OS constants
// ----------------------------------------------------------------------------------
#define S_IRW   (S_IREAD|S_IWRITE)

// Max length of a line in a text file:
#define MAX_LINE_LENGTH  65535

// Length of end of line sequence:
#define EOL_LEN  2

#define MAX_BUF_LEN    65000
#define MAX_PRL_TLIST  16384

// Nb of messages in gsErrMsgs[]
#define NB_ERR_MSGS    18

// ----------------------------------------------------------------------------------
// - Types
// ----------------------------------------------------------------------------------
enum cmp_type {cmp_none=2,cmp_less=-1,cmp_equal=0,cmp_greater=1};
typedef cmp_type (*pmCmpFuncType)(void * pItem1,void * pItem2,void * pData);
typedef int (*PMQSort)(const void * pItem1,const void * pItem2);
typedef void (*pmPrnFncType)(char *, DWORD);


////////////////////////////////////////////////
// Marker for fixation the point in the list: //
////////////////////////////////////////////////
struct SListMarker {
////////////////////
  DWORD dwPoint;
  DWORD dwIdx;

  SListMarker(DWORD dwItem=0,DWORD dwItemIdx=0);
  ~SListMarker();
  void SetMarker(DWORD dwItem,DWORD dwItemIdx);
};

////////////////////////
// TList class flags: //
////////////////////////
#define SET_MAXSZ_LIM_FLAG   (FFlags.bitIsMaxSizeLimited = 1)
#define RESET_MAXSZ_LIM_FLAG (FFlags.bitIsMaxSizeLimited = 0)
#define IS_MAXSZ_LIM_FLAG    (FFlags.bitIsMaxSizeLimited == 1)

#define SET_FREEMEM_FLAG    (FFlags.bitDoFreeMemory = 1)
#define RESET_FREEMEM_FLAG  (FFlags.bitDoFreeMemory = 0)
#define IS_FREEMEM_FLAG     (FFlags.bitDoFreeMemory == 1)

#define TLIST_SAFETY_MASK        0x3
#define TSORTEDLIST_SAFETY_MASK  0x7
//////////////////////////////
// TSortedList class flags: //
//////////////////////////////
#define SET_LIST_SORTED     (FFlags.bitIsListSorted = 1)
#define RESET_LIST_SORTED   (FFlags.bitIsListSorted = 0)
#define IS_LIST_SORTED      (FFlags.bitIsListSorted == 1)

////////////////////////
struct STListFlagsType {
  DWORD bitIsMaxSizeLimited : 1;
  DWORD bitDoFreeMemory     : 1;
  DWORD bitIsListSorted     : 1;
  DWORD reserved            : 29;
};

/////////////
class TList {
/////////////
private:
//////////
protected:
//////////
  DWORD dwFcount;
  DWORD dwFlen;
  DWORD dwFstep;
  DWORD * pFitems;
  pmPrnFncType pmFprint;
  STListFlagsType FFlags;
  DWORD dwFmax_len;
  DWORD dwFmax_buf;

  virtual DWORD FAllocNew();
  virtual void  FSqueezeList();
  virtual DWORD FFindMarkForw(SListMarker * pMarker,BOOL fromFindBack);
  virtual DWORD FFindMarkBack(SListMarker * pMarker,BOOL fromFindForw);
  virtual DWORD FIndexOf( void * pItem,DWORD dwI,BOOL isForw );
  void FZeroingItem();
///////
public:
///////
  DWORD dwLast;
  void * pVal;
  pmCmpFuncType pmFcompare;
  void * pFdata;

#if defined(BDA_WIN32)
  TList(DWORD dwStep=10,DWORD dwMaxSz = (DWORD)-1,pmCmpFuncType pmCmpFunc=NULL);
#elif defined(BDA_UNIX)
  TList(DWORD dwStep=10,DWORD dwMaxSz = (DWORD)-1,pmCmpFuncType pmCmpFunc=NULL);
#elif defined(BDA_TWIN16)
  TList(DWORD dwStep=10,DWORD dwMaxSz = MAX_PRL_TLIST,pmCmpFuncType pmCmpFunc=NULL);
#else
#error PROLOGUE MSG: OS inconnu
#endif

  TList(const TList& pFrom);
//  TList(void){}
  ~TList();
  virtual DWORD GetMax();
  virtual DWORD SetMax(DWORD dwMaxLen,DWORD dwMaxBuf,BOOL boolDoFreeMemory);
  virtual DWORD ResetMax();
  virtual BOOL SetFreeMemState(BOOL boolDoFreeMemory);
  virtual BOOL IsFreeMemSet();
  virtual DWORD GetFreeQuant();
  virtual DWORD GetItems( DWORD dwIdx, BOOL DoSetLibError=FALSE );
  virtual void * SetItems( DWORD dwIdx, void * pItem );
  virtual DWORD GetStep();
  virtual DWORD SetStep( DWORD dwStep );
  virtual DWORD GetCount();
  virtual DWORD GetLen();
  virtual DWORD Add( void * pItem );
  virtual DWORD AddN( void * pItem, DWORD dwCount );
  virtual DWORD Insert( DWORD dwIdx, void * pItem );
  virtual DWORD InsertN( DWORD dwIdx, void * pItem, DWORD dwCount );
  virtual DWORD Delete( DWORD dwIdx );
  virtual DWORD DelLast();
  virtual DWORD GetLast();
  virtual DWORD SetLast(void * pItem);
  virtual DWORD Next(void * pItem,DWORD dwIdx=(DWORD)-1);
  virtual DWORD Prev(void * pItem,DWORD dwIdx=(DWORD)-1);
  virtual void Clear();
  virtual void CleanUp();
  virtual void FreeScalarMembers();
  virtual void FreeVectorMembers();
  virtual DWORD IndexOf( void * pItem,DWORD dwBegIdx=0,
                         BOOL isForw=TRUE,BOOL useCmpFunc=FALSE );
  virtual DWORD IndexOfCust(void * pItem,DWORD dwIdx,BOOL isForw,pmCmpFuncType pmCmpFunc);
  virtual void * GetItemsAdr(DWORD dwIdx);
  virtual SListMarker * SetMarker(DWORD dwIdx,SListMarker * pMarker=NULL);
  virtual DWORD RefreshMarker(SListMarker * pMarker,BOOL isForw);
  virtual void FreeMarker(SListMarker * pMarker);
  virtual void SaveToFile( char * sFname,DWORD dwBufLen=100 );
  virtual void PrintItem( char * sBuf, DWORD dwIdx );
  virtual pmPrnFncType SetPrint( pmPrnFncType pmPrint );
  virtual pmCmpFuncType SetCmpFunc( pmCmpFuncType pmCmpFunc );
  virtual void SetData(void * pData);
  virtual void SwapItems(DWORD dwIdx1,DWORD dwIdx2);
  virtual void MakeLRUshift(DWORD dwIdx);
  virtual void AddLRUmemb(void * pItem);
}; // TList

/////////////////////////
// Working procedures: //
/////////////////////////
int MinI(int varFirst,int varSecond);
int MaxI(int varFirst,int varSecond);
DWORD MinDW(DWORD varFirst,DWORD varSecond);
DWORD MaxDW(DWORD varFirst,DWORD varSecond);

cmp_type DWcmp(DWORD dwItem1,DWORD dwItem2);
cmp_type INTcmp(int iItem1,int iItem2);

#define  MAX_ERROR_IDX  NOT_TEXTFILE_ERR

extern DWORD gdwLastErrNumb; // General TextFile Lib error state
extern DWORD gdwWinErr;        // WinAPI error number
extern DWORD gdwLibErrNumb;    // MixLib100 error number
extern DWORD gdwRTLerr;        // RTL error number
extern char * gsErrMsgs[NB_ERR_MSGS];

extern DWORD gdwVersion; // Version of the Lib

#define IS_ERR_STATE  (gdwLastErrNumb != NO_ERRORS)

void ResetLibError();
void LibError(DWORD dwLibErr);
void ResetErrorState();
void SetErrorState(DWORD dwErrIdx);
void ResetLastWinErr();
void SetLastWinErr();
void ResetRTLerr();
short int SetRTLerr(DWORD dwRTLerr);
DWORD GetErrorNumb();
void GetErrorMsg(char * sErrMsg);
void FormMixLibErrMsg(char * sErrMsgCurr);
void FormRTLerror(char * sErrMsgCurr);
void FormOSerror(char * sErrMsgCurr);

BOOL IsExistingFile(char * sFileName);
void* Portable_memcpy(void*,const void*,DWORD);
void* Portable_memset(void*,int,DWORD);
void* Portable_memmove(void *, const void *, DWORD);
void* Portable_realloc(void* ,DWORD);
int Portable_read(int ,void* ,DWORD);
int Portable_write(int ,void* ,DWORD);
int Portable_chmod (char *filename, int pmode);

#endif // TFILEINC_H
