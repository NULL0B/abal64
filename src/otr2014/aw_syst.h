//---------------------------------------------------------------------------
// Project      : BSA-PROTECTION
// Version      : 1.0
// Author       : I.Nichiporovich (IN), V.Shimarov (VS) (Minsk)
// Creation     : 03.96
// Module       : Header file (general system interface)
//              : This module is base for all ARCANE platform representation.
//              : #define __Dos       -> MS-DOS
//              : #define __prologue  -> PROLOGUE
//              : #define __Prl3
//              : #define __Win       -> Windows 3.1 (16bit)
//              : #define WIN32       -> Win32, Windows95 (32bit)
//              : #define __WinNT     ->
// Modification :
//    07.96 [IN] -> Windows95 (32bit)
// 07.11.96 [IN] -> flag __APPLICATION is defined to separate procedures
//                  are useful for application only
//---------------------------------------------------------------------------

#ifndef  __AW_SYST_H
#define  __AW_SYST_H

#include "aw_dfns.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

// 11-10-96 05:31pm, the following string removed, is not useful
// #define ProtSFailure  "PPOTECTION FAILURE.\nReinstall the application please..."

// Error codes for Instal program and Application program

#define OK                        0   // No errors detected
#define AW_BAD_FILE_NAME        100   // File to protect not found or bad
#define AW_BAD_FILE_STRUCTURE   101   // -- "" -- has incorrect structure or bad
#define AW_BAD_SERIAL           102   // User have entered incorrect serial number
#define AW_BAD_DATA_INTEGRITY   103   // Protection data corrupts
#define AW_BAD_BIOS_NAME        104   // Application has been replaced to other computer

// --------------------------------------------------------------------------
// Following procedures are internal and provide common system support for
// utilities and protected application.
// --------------------------------------------------------------------------

BOOL FAR PASCAL ArcaneCheckBIOS(VOID);
BOOL FAR PASCAL ArcaneReadBIOS(LPSTR biosnm, LPSTR biosdt);
VOID FAR PASCAL ArcaneGetId(LPSTR IdName, LPSTR IdFirm);
BOOL FAR PASCAL ArcaneCheckIntegrity(VOID);
BOOL FAR PASCAL ArcaneGetLegalProductCode(WORD num, LPSTR buf);

VOID  FAR PASCAL ArcaneGetSerial(LPSTR serial);
VOID  FAR PASCAL ArcaneGetBIOS(LPSTR biosnm, LPSTR biosdt);
DWORD FAR PASCAL ArcaneCalcChecksum(VOID);

// --------------------------------------------------------------------------
// Following procedures are internal and is not useful in Install program and
// Application program.
// --------------------------------------------------------------------------

#ifndef __APPLICATION                                   // system access only

extern sProtData ProtData;

void             aw_to_close(char FAR * StrFrom, char FAR * StrTo);

BOOL  FAR PASCAL ArcaneUpdateBIOS(VOID);
VOID  FAR PASCAL ArcanePutId(LPSTR IdName, LPSTR IdFirm);
BOOL  FAR PASCAL ArcaneWriteData(FILE * fl);
BOOL  FAR PASCAL ArcaneReadData(FILE * fl);
VOID  FAR PASCAL ArcaneUpdateChecksum(VOID);
BOOL  FAR PASCAL ArcaneFindSignature(FILE * fl);
VOID  FAR PASCAL ArcanePutSerial(LPSTR serial);
BYTE  FAR PASCAL ArcaneSerialCheckSum(LPSTR serial);
BOOL  FAR PASCAL ArcaneCheckSerial(LPSTR serial);
BOOL  FAR PASCAL ArcanePutLegalProductCode(WORD num, LPSTR buf);
BOOL  FAR PASCAL ArcaneGetFileDate(FILE * fl, WORD * time, WORD * date);
BOOL  FAR PASCAL ArcaneSetFileDate(FILE * fl, WORD time, WORD date);
VOID  FAR PASCAL ArcanePrepareData(LPSTR code);

// --------------------------------------------------------------------------
// Following procedures are useful by Install program
// --------------------------------------------------------------------------

BOOL FAR PASCAL AW_InstallProtection(char FAR * IDName,   char FAR * IDFirm,
                char FAR * IDSerialNumber,  char FAR * File);
BOOL FAR PASCAL AW_TestProtection(char FAR * Serial);
BOOL FAR PASCAL AW_ReadProtectionData(char FAR * IDName,   char FAR * IDFirm,
                char FAR * IDSerialNumber,  char FAR * File);

#endif                                              // end system access only

// --------------------------------------------------------------------------
// Following procedures are useful by Application program
// --------------------------------------------------------------------------

BOOL FAR PASCAL AW_CheckProtection(BOOL flag);
//BOOL FAR PASCAL AW_CheckProtectionAndExit(BOOL flag);
VOID FAR PASCAL AW_GetId(LPSTR IdName, LPSTR IdFirm);
VOID FAR PASCAL AW_GetSerial(LPSTR serial);
VOID FAR PASCAL AW_FormatSerial(LPSTR outNum, LPSTR inNum, int del);
WORD FAR PASCAL AW_GetVersion(void);
// VOID FAR PASCAL AW_GetVersionASCII(LPSTR buf);


// ==========================================================================
// DOS EXTENDER START
// ==========================================================================
#ifdef dosext

BDA	desrt;				                        // description de la bibliotheque
extern BDA_INIT FAR PTR rt_init;	        // signature de la bibliotheque
extern BDA_ARG rt_arg;	               		// description des arguments

// Prototypage des fonctions :
//	- avec typage des arguments
//	- et sans typage
	      VOID FAR PTR InitRelais(VOID);
static	VOID FAR banniere(VOID);
extern	VOID rt_error(WORD);

WORD PASCAL FAR _AW_CheckProtection(void *a[]);
WORD PASCAL FAR _AW_GetId(void *a[]);
WORD PASCAL FAR _AW_GetSerial(void *a[]);
WORD PASCAL FAR _AW_FormatSerial(void *a[]);
WORD PASCAL FAR _AW_GetVersion(void);

#endif
// ==========================================================================
// DOS EXTENDER END
// ==========================================================================



#ifdef __cplusplus
}
#endif

#endif

// END OF FILE ==============================================================
