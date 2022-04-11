// ***********************************************************************************************
// * SysAPI.h
// ***********************************************************************************************

#ifndef SYSAPI_H
#define SYSAPI_H

#ifdef __cplusplus
  extern "C" {
#endif

short SysMkDir(const char * sFileOri, unsigned short Flags);
short SysRmDir(const char * sFileOri);
short SysNgfUpdate(const char * sFileOri);
short SysGetAbalEnv(const char * sVarOri, char * Buf, long LgBuf, long* pLg );

#ifdef __cplusplus
  }
#endif


#endif          
