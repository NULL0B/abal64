// ***********************************************************************************************
// * FileAPI.h
// ***********************************************************************************************

#ifndef FILEAPI_H
#define FILEAPI_H

#ifdef __cplusplus
  extern "C" {
#endif

short FileGetVersion(const char * sFileOri, char * Buf, long LgBuf, long* pLg );
short FileCpy(const char * sFileOri, const char * sFileDes, unsigned short Flags, long OffsetCopy, long LgCopy);
short FileCmp(const char * sFileOri, const char * sFileDes, unsigned short Flags, long OffsetCopy, long LgCopy, long* pOffset);
short FileSize(const char * sFileOri, unsigned short Flags, long* pLg);
short FileIniFind(const char * sFileOri, unsigned char* Sec, long LgSec, unsigned char* Key, long LgKey, unsigned char* Val, long LgVal, long* pLgVal);

#ifdef __cplusplus
  }
#endif


#endif          
