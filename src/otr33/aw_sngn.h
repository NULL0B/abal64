//---------------------------------------------------------------------------
// Project      : BSA-PROTECTION
// Version      : 1.0
// Author       : V.Shimarov (VS) (Minsk)
// Creation     : 03.96
// Modification :
// Module       : Header file (serial number generation)
//---------------------------------------------------------------------------

#ifndef  __AW_SNGEN_H
#define  __AW_SNGEN_H

#include "aw_dfns.h"
#include "aw_dfns2.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward definitions of functions used by ARCANE utilities */

#ifdef __Win
BOOL FAR PASCAL ArcaneSerNumGeneration(HANDLE, char *);
BOOL FAR PASCAL ArcaneSerNumAnalysis  (HANDLE, char *);
#endif

#ifdef __Win
long FAR PASCAL WndProc (HWND, WORD, WORD, LONG) ;
#endif

#ifdef prologue
void  word_convert(unsigned, char *);
#endif

int   WrongProductCode    (char *, int,  char, char, char *);
int   CountSerialNumber   (char *, char *, char *, char *, char *, char *);
int   get_cur_date(char *, char *);
void  AW_to_Wide (char *, char *, int);
int   RestoreSerialNumber (char *, char *, char *, char *, char *, char *);
int   convert_date(char *, char *, char *);
void  count_date  (char *, char *);

#ifdef _Win
int   ReportSerialNumber(HWND, int, int, int, int);
void  PrintSerNumber    (HWND, int);
long  OpenAWFile(HWND, HANDLE, char *, int, const char *, DWORD);
//void  AW_to_Close(char *, char *);
#endif

#ifdef __cplusplus
}
#endif

#endif

// END OF FILE ==============================================================
