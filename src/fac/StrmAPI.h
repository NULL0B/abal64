// ***********************************************************************************************
// * StrmAPI.h
// ***********************************************************************************************

#ifndef STREAMAPI_H
#define STREAMAPI_H

#ifdef __cplusplus
  extern "C" {
#endif

void  StrmCloseAll(void);

short StrmGetFree(WORD* pNoLog);
short StrmOpen(WORD NoLog, char * sFileName, WORD wFlags);
short StrmClose(WORD NoLog);
short StrmSave(WORD NoLog);
short StrmWriteByte(WORD NoLog, BYTE Car);
short StrmReadByte(WORD NoLog, BYTE* pCar);
short StrmWriteBuf(WORD NoLog, const BYTE* Buf, long LgBuf, long* pLg);
short StrmReadBuf(WORD NoLog, BYTE* Buf, long LgBuf, long* pLg);
short StrmFindByte(WORD NoLog, BYTE Car, BOOL SeekAfter);
short StrmFindBuf(WORD NoLog, const BYTE* Buf, long LgBuf, BOOL SeekAfter);
short StrmFindByteInCollection(WORD NoLog, const BYTE* Buf, long LgBuf, unsigned char* pc, BOOL SeekAfter);
short StrmSeek(WORD NoLog, long Offset, WORD Origin);
short StrmTell(WORD NoLog, long* pOffset );
short StrmFileSize(WORD NoLog, long* pSize);
short StrmGetError(WORD NoLog);
short StrmClearError(WORD NoLog);
short StrmEof(WORD NoLog);

short StrmLnAnalyse(WORD NoLog);
short StrmLnWrite(WORD NoLog, const BYTE* Buf, long LgBuf, long* pLg);
short StrmLnRead(WORD NoLog, BYTE* Buf, long LgBuf, long* pLg);
short StrmLnSeek(WORD NoLog, long Offset, WORD Origin);
short StrmLnTell(WORD NoLog, long* pOffset);
short StrmLnFileSize(WORD NoLog, long* pLines);
short StrmLnLength(WORD NoLog, long* pSizeLines);
short StrmLnMaxLength(WORD NoLog, long* pSize);
short StrmLnEof(WORD NoLog);
short StrmLnSetExpandTab(WORD NoLog, WORD LgTab);
short StrmLnGetExpandTab(WORD NoLog, WORD* pLgTab);
short StrmLnSetPad(WORD NoLog, WORD IsPad);
short StrmLnGetPad(WORD NoLog, WORD* pIsPad);
short StrmLnSetFormFeed(WORD NoLog, WORD IsFormFeed);
short StrmLnGetFormFeed(WORD NoLog, WORD* pIsFormFeed);
short StrmLnFileFormat(WORD NoLog, WORD* pIsCr, WORD* pIsCtrlz );
short StrmLnIsLast(WORD NoLog);
short StrmLnInfoLine(WORD NoLog, long* pOffset, long* pSize);
short StrmLnReadSec(WORD NoLog, BYTE* Buf, long LgBuf, long* pLg);
short StrmLnFindSec(WORD NoLog, BYTE* Buf, long LgBuf, short IsCaseSens);
short StrmLnReadKey(WORD NoLog, BYTE* Buf, long LgBuf, long* pLgBuf, BYTE* Val, long LgVal, long* pLgVal);
short StrmLnFindKey(WORD NoLog, BYTE* Key, long LgKey, BYTE* Val, long LgVal, long* pLgVal, short IsCaseSens);

#ifdef __cplusplus
  }
#endif


#endif          
