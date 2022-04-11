// ****************************************************************************
// * banner.h
// * Patern functionnality
// ****************************************************************************
#ifndef _BANNER_H
#define _BANNER_H

#ifdef __cplusplus
  extern "C" {
#endif
int	Banner_DisplayBanner(void);
char  Banner_GetVersionStatus(void);
char  Banner_GetVersionItem( int i );
char* Banner_GetVersionID( char * Dst, char VersionStatus );
char* Banner_GetBuild( char * Dst );
char* Banner_GetDate( char * Dst );
char* Banner_GetOriginalFilename( char * Dst );
char* Banner_GetProductName( char * Dst );
char* Banner_GetInternalName( char * Dst );
char* Banner_GetComment( char * Dst );
char* Banner_GetCopyright( char * Dst );
#ifdef __cplusplus
  }
#endif

#endif
