//---------------------------------------------------------------------------
// Project      : BSA-PROTECTION
// Version      : 1.0
// Author       : I.Nichiporovich (IN), V.Shimarov (VS) (Minsk)
// Creation     : 03.96
// Module       : Header file (general definitions)
//              : This module is base for all ARCANE platform representation.
//              : #define __Dos       -> MS-DOS
//              : #define __prologue  -> PROLOGUE
//              : #define __Prl3
//              : #define __Win       -> Windows 3.1 (16bit)
//              : #define WIN32       -> Win32, Windows95 (32bit)
//              : #define __WinNT     ->
// Modification :
//    07.96 [IN] -> Windows95 (32bit)
// 14.10.96 [IN] -> new method of legal product codes checking
//               field legalCode in the protect data added
//---------------------------------------------------------------------------

#ifndef  __AW_DFNS_H
#define  __AW_DFNS_H

#include "aw_flag.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef  WINDOWS
#ifndef __Win
#define __Win
#endif
#endif

#ifdef  prologue
#ifndef __Prl3
#define __Prl3
#endif
#endif

#ifdef  __Prl3
#ifndef prologue
#define prologue
#endif
#endif

#if (defined(__Win) | defined(WIN32) | defined(__WinNT))
#include <windows.h>
#endif

// Generals types definiton (MSDOS and PROLOGUE only) ------------------------
#if (defined(__Dos) | defined (__Prl3)) | defined (dosext)

#ifndef INT
#define INT     int
#endif

#ifndef UINT
#define UINT    unsigned int
#endif

#ifndef WORD
#define WORD    unsigned int
#endif

#ifndef DWORD
#define DWORD   unsigned long
#endif

#ifndef BYTE
#define BYTE    unsigned char
#endif

#ifndef BOOL
#define BOOL    int
#endif

#ifndef LONG
#define LONG    long
#endif

#ifndef FAR
#define FAR     far
#endif

#ifndef VOID
#define VOID    void
#endif

#ifndef LPSTR
#define LPSTR   unsigned char FAR *
#endif

#ifndef LPWORD
#define LPWORD  WORD FAR *
#endif

#ifndef LPBYTE
#define LPBYTE  BYTE FAR *
#endif

#ifndef LPDWORD
#define LPDWORD DWORD FAR *
#endif

#ifndef LPVOID
#define LPVOID  VOID FAR *
#endif

#ifndef PASCAL
#define PASCAL  pascal
#endif

#endif
// End general types definition --------------------------------------


// Define FAR keyword for 32bit compilers
#ifdef WIN32
#ifdef FAR
#undef FAR
#endif
#define	FAR
#endif

#pragma pack(1)

typedef struct {

  char   signat[ProtSignLength];

  WORD   version;

  char   biosnm[ProtBsnmLength];
  char   biosdt[ProtBsdtLength];

  char   serial[ProtNmbrLength];
  char   reserv[ProtRsrvLength];
  char   IdName[ProtNameLength];
  char   IdFirm[ProtNameLength];

  char   legalCode[ProtCodeNumber][5]; // Legal product codes [IN] 10-13-96

  DWORD  checksum;   // Must be the last field of the structure!

} sProtData;

#pragma pack()

#define ProtXORKey    0x28		 // Protection code of the scripted data

// Product code positions in the serial number
#define AW_POS0       0
#define AW_POS1       5
#define AW_POS2       10
#define AW_POS3       15
#define AW_POS4       16


#ifdef __cplusplus
}
#endif

#endif

// END OF FILE ==============================================================
