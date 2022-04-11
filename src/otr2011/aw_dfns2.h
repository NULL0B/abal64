//---------------------------------------------------------------------------
// Project      : BSA-PROTECTION
// Version      : 1.0
// Author       : I.Nichiporovich (IN), V.Shimarov (VS) (Minsk)
// Creation     : 03.96
// Modification :
// Module       : Header file (general definitions)
//              : This module is base for all ARCANE platform representation.
//              : #define __Dos       -> compiling for MS-DOS
//              : #define prologue    -> compiling for PROLOGUE
//              : #define __Prl3
//              : #define __Win       -> compiling for MS WINDOWS
//---------------------------------------------------------------------------

#ifndef  __AW_DFNS2_H
#define  __AW_DFNS2_H

#include "aw_flag.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ProtOnlyDigits       0
#define ProtLettersDigits    1

#define PrintWithUserInfo    1
#define PrintWithoutUserInfo 0

#define ProtPrCodeLength     5

#define ProtReqNumbLength   12
#define ProtReqTypeLength    1
#define ProtDateLength       8
#define ProtNCopiesLength    4

typedef struct {

  char   ProductCode   [ProtPrCodeLength+1];
  char   RequestNumber [ProtReqNumbLength+1+5];
  char   RequestType;
  char   ProtDate      [ProtDateLength+1];
  char   ProtNCopies   [ProtNCopiesLength+1];

  char   ProtSerial    [ProtNmbrLength+6];

} sRequestData;

#define AWM_IDPRCODE    4010
#define AWM_IDRNUM      4011
#define AWM_IDNCOPIES   4012
#define AWM_IDRDATE     4013
#define AWM_IDRTYPE1    4014
#define AWM_IDRTYPE2    4015
#define AWM_IDRTYPE3    4016
#define AWM_IDREP1      4017
#define AWM_IDREP2      4018
#define AWM_IDREP3      4019

#define IDS_FILTERSTRING 1

#ifdef __Win

#define AskIfToExit { int retc; 					\
  retc =  MessageBox(NULL,						\
		     "Do you want to exit and close ARCANE window?",    \
		     "ARCANE: EXIT", 					\
		     MB_SYSTEMMODAL | MB_YESNO | MB_ICONQUESTION);      \
  if(retc == IDYES) PostQuitMessage(0);  }

#endif

#ifdef __cplusplus
}
#endif

#endif

// END OF FILE ==============================================================
