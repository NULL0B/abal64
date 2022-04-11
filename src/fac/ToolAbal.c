// ****************************************************************************
// * ToolAbal.cpp
// * BDA module
// ****************************************************************************

#define  CI_MODULE_ID   0x0001

#include <stdlib.h>
#include <string.h>

/* Inclusions importees */
#include "wdef.h"
#include "pubsbda.h"
#include "pubwbda.h"
#include "trace.h"

#include "ToolAbal.h"

// ===============================================
// =========================================================
// ===================================================================
// =============================================================================
// = Fonctions internes
// =============================================================================
// ===================================================================
// =========================================================
// ===============================================

// ****************************************************************************
// * bcdtoi
// * Conversion BCD en Word
// * (source IJM, utilisé dans l'exécuteur)
// * 
// * Entree: unsigned char *  cp  Pointer to BCD String to convert
// *         unsigned int len     Maximum length of string
// * Retour: valeur sur un word
// * 
// ****************************************************************************
signed int  bcdtoi(unsigned char * cp,unsigned int len)
{
register signed int x;
unsigned int y;
unsigned int bcd,nib;
unsigned char negcopy[12];

if ( (((unsigned int) *cp) & 0x00F0 ) == 0x0040 ) 
  { 
  for (x=0; x < (int)len; x++ )
    negcopy[x] = (*(cp++) ^ 0x00FF);
  cp = negcopy;
  }

x = 0; nib = 1; y = 0;
while ( nib > 0 ) {
  if ( nib == 1 ) {
    if ( len > 0 ) { bcd = (unsigned int) *(cp++); len--; }
    else { nib = 0; continue; }
    switch ( bcd & 0x00F0 ) {
      case 0x00B0 : y = 1; nib = 2; break;
      case 0x00C0 : nib = 2; break;
      case 0x00F0 :
      case 0x00A0 :   nib = 0; break;
      default     :   x *= 10; x += (( bcd & 0x00F0 ) >> 4 );
          nib = 2; break;
      }
    }
  else {
    switch ( bcd & 0x000F ) {
      case 0x000F :
      case 0x000A :   nib = 0; break;
      default     : x *= 10; x += ( bcd & 0x000F );
          nib = 1; break;

      }
    }
  }
if ( y == 1 ) { x = -x; }
return(x);
}

// ****************************************************************************
// * bcdtol
// * Conversion BCD en DWord
// * (source IJM, utilisé dans l'exécuteur)
// * 
// * Entree: unsigned char *  cp  Pointer to BCD String to convert
// *         unsigned int len     Maximum length of string
// * Retour: valeur sur un word
// * 
// ****************************************************************************
signed long bcdtol(unsigned char * cp,unsigned int len)
{
register signed long x;
unsigned long y;
unsigned long bcd,nib;
unsigned char negcopy[12];

if ( (((unsigned long) *cp) & 0x00F0 ) == 0x0040 ) 
  { 
  for (x=0; x < (long)len; x++ )
    negcopy[x] = (*(cp++) ^ 0x00FF);
  cp = negcopy;
  }

x = 0; nib = 1; y = 0;
while ( nib > 0 ) {
  if ( nib == 1 ) {
    if ( len > 0 ) { bcd = (unsigned long) *(cp++); len--; }
    else { nib = 0; continue; }
    switch ( bcd & 0x00F0 ) {
      case 0x00B0 : y = 1; nib = 2; break;
      case 0x00C0 : nib = 2; break;
      case 0x00F0 :
      case 0x00A0 :   nib = 0; break;
      default     :   x *= 10; x += (( bcd & 0x00F0 ) >> 4 );
          nib = 2; break;
      }
    }
  else {
    switch ( bcd & 0x000F ) {
      case 0x000F :
      case 0x000A :   nib = 0; break;
      default     : x *= 10; x += ( bcd & 0x000F );
          nib = 1; break;

      }
    }
  }
if ( y == 1 ) { x = -x; }
return(x);
}

// ****************************************************************************
// * ltobcd
// * Conversion DWord en BCD
// * (source IJM, utilisé dans l'exécuteur)
// * 
// * Sortie: unsigned char *  cp  Pointer to BCD String to convert
// * Entree: unsigned int len     Maximum length of string
// *         valeur sur un word
// * Retour  0 si erreur, 1 si OK
// ****************************************************************************
WORD  ltobcd( unsigned char * bcdptr , unsigned int bcdlen , long longvalue )
{
  register unsigned long y;
  long   x;
  unsigned long flag;
  unsigned long bcd,nib;

/* Detect Special Case which causes Problems */
/* ----------------------------------------- */
if ( longvalue == 0x80000000L) {  

  /* Special Case longvalue = -2,147,483,648 */
  /* --------------------------------------- */

  if ( bcdlen < 6 )     { return(0);   }

  *(bcdptr++) = (BYTE) 0x00B2; *(bcdptr++) = (BYTE) 0x0014;
  *(bcdptr++) = (BYTE) 0x0074; *(bcdptr++) = (BYTE) 0x0083;
  *(bcdptr++) = (BYTE) 0x0064; *(bcdptr++) = (BYTE) 0x008F;
  bcdlen -= 6;

  while ( bcdlen > 0 )  { *(bcdptr++) = (BYTE) 0x00FF; bcdlen--; }
  return(1);

  }

/* Detect Negative values and Establish BCD Sign Nibble */
/* ---------------------------------------------------- */
if ( ((WORD) longvalue & 0x80000000L) != 0 ) { 
  bcd = 0x00B0; longvalue = -longvalue ;
  }
else  { 
  bcd = 0x00C0; 
  }

/* Enter LONG VALUE Conversion mechanism */
/* ------------------------------------- */
nib = 2;
if ( longvalue != 0L ) {

  x = 1000000000L; flag = 0;
  while (( x >= 1L ) && (bcdlen > 0)) {
    y = ( longvalue / x );
    if ( y != 0 ) { 
      if ( nib == 1 ) { 
        bcd = (y << 4); nib = 2; 
        }
      else  {
        bcd |= y; nib = 1; *(bcdptr++) = (BYTE) bcd;
        bcdlen--; bcd = 0x00FF;
        if ( bcdlen == 0 ) { break; }
        }
      longvalue %= x; flag = 1; x /= 10L; 
      }
    else  {
      if ( flag == 0 ) { x /= 10L; }
      else  {
        if ( nib == 1 ) { bcd = (y << 4); nib = 2; }
        else  {
          bcd |= y; nib = 1; *(bcdptr++) = (BYTE) bcd;
          bcdlen--; bcd = 0x00FF;
          if ( bcdlen == 0 ) { break; }
          }
        longvalue %= x; flag = 1; x /= 10L; 
        }
      }
    }

  /* Test for BCD result overflow */
  /* ---------------------------- */
  if ( x >= 1 ) { return(0); }

  /* Establish Last Waiting Digit */
  /* ---------------------------- */
  if (( bcdlen > 0 ) && ( nib == 2)) {
    *(bcdptr++) = (BYTE) (bcd | 0x000F); bcdlen--;
    }
  }
else  { *(bcdptr++) = (BYTE) 0x00C0; bcdlen--; }

/* Pad too end of String with Bcd Filler Bytes */
/* ------------------------------------------- */
while ( bcdlen > 0 ) { *(bcdptr++) = (BYTE) 0x00FF; bcdlen--; }

return(1);

}

// ===============================================
// =========================================================
// ===================================================================
// =============================================================================
// = Fonctions externes
// =============================================================================
// ===================================================================
// =========================================================
// ===============================================

// ****************************************************************************
// * ToolAbal_ConvertAbalWord
// * This function exchanges order of bytes for 16-bit value and return the word
// * USAGE: 
// *  --> a rt_arg value is a %
// *  Do not call directly, but by the macro 'ToolAbal_WORD' depending on OS
// *  WIN32 : forbidden (swap is perfomed by executor before calling a BDA)
// *  UNIX  : mandatory (swap is not perfomed by executor)
// *  1°) Call this function before using in a C function 
// * 
// * IN/OUT : pointer on a word
// * return : the swaped value
// ****************************************************************************
WORD ToolAbal_ConvertAbalWord( BYTE* wptr)
{ return ( (*wptr<<8) | *(wptr+1) ); }

// ****************************************************************************
// * ToolAbal_SwapBytes
// * This function exchanges order of bytes for 16-bit value
// * USAGE:
// *  --> a rt_arg value is a %?. Change the byte order directly in rt_arg struct
// *  1°) Call this function before using in a C function 
// *  2°) Call again after returning in executor to retrieve ABAL format
// * 
// * IN/OUT : pointer on a word
// * return : the swaped value
// ****************************************************************************
WORD ToolAbal_SwapBytes(WORD * pwNumb)
{
BYTE  bWork = ((BYTE)((*pwNumb) & 0xff)); // LOBYTE
((BYTE *)pwNumb)[0] = ((BYTE)((*pwNumb) >> 8)); // HIBYTE
((BYTE *)pwNumb)[1] = bWork;
return *pwNumb;
}

// ****************************************************************************
// * ToolAbal_GetLongFromRtArg
// * This function analyses tr_arg (#,%,bcd) and converts it in a long
// * USAGE:
// *  --> a rt_arg value is a #,%,*,#?,%?,*?
// *  1°) Call this function before using in a C function 
// * 
// * IN : index in rt_arg
// * IN : default value if convertion fails
// * IN : Signed/unsigned values (for byte or word evaluation)
// * return : long result value
// ****************************************************************************
DWORD ToolAbal_GetLongFromRtArg(WORD iRtArg, DWORD DefaultValue, BOOL IsSigned)
{
DWORD  ret;

//MI_TRACE_DCL_TFN("ToolAbal_GetLongFromRtArg");

//MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"rt_arg.c=%u , i=%u",rt_arg.c,iRtArg));
//MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"rt_arg.t=%04X",rt_arg.t[iRtArg]));
//MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"rt_arg.l=%u",rt_arg.l[iRtArg]));
//MI_TRACE((CI_TRA_F_DUMP,CI_MODULE_ID,TFN,"rt_arg.v",rt_arg.v[iRtArg],rt_arg.l[iRtArg]));

if( rt_arg.c > iRtArg )
   switch( rt_arg.t[iRtArg] )
      {
      case TYPE_DIESE:    
      case TYPE_DIESE | MODIFIABLE:    
         if (IsSigned)
            ret = *(char*)rt_arg.v[iRtArg]; 
         else
            ret = *(BYTE*)rt_arg.v[iRtArg]; 
      break;

      case TYPE_POURCENT:
         if (IsSigned)
            ret = (short)ToolAbal_WORD(rt_arg.v[iRtArg]);
         else
            ret = ToolAbal_WORD(rt_arg.v[iRtArg]); 
      break;

      case TYPE_INT32	:
         if (IsSigned)
            ret = (int)ToolAbal_WORD(rt_arg.v[iRtArg]);
         else
            ret = ToolAbal_WORD(rt_arg.v[iRtArg]); 
      break;

      case TYPE_INT64	:
         if (IsSigned)
            ret = (long long)ToolAbal_WORD(rt_arg.v[iRtArg]);
         else
            ret = ToolAbal_WORD(rt_arg.v[iRtArg]); 
      break;

      case TYPE_POURCENT | MODIFIABLE:    
         if (IsSigned)
            ret = (short)ToolAbal_SwapBytes((WORD*)rt_arg.v[iRtArg]); 
         else
            ret = ToolAbal_SwapBytes((WORD*)rt_arg.v[iRtArg]); 
      break;

      case TYPE_BCD:      
      case TYPE_BCD | MODIFIABLE:    
         ret = bcdtol( (BYTE*)rt_arg.v[iRtArg], rt_arg.l[iRtArg] ); 
         break;

      default:            
         ret = DefaultValue;             
         break;
      }
else
  ret = DefaultValue;

//MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"ret=%08lX %lu",ret,ret));
return ret;
}

// ****************************************************************************
// * ToolAbal_SetLongToRtArg
// * This function analyses tr_arg and converts a long in #,%,bcd 
// * USAGE:
// *  --> a rt_arg value is a #?,%?,*?
// *  1°) Call this function after returning in executor to retrieve ABAL format
// * 
// * IN : index in rt_arg
// * IN : long value
// * return : TRUE if OK, else FALSE
// ****************************************************************************
BOOL ToolAbal_SetLongToRtArg(WORD iRtArg, DWORD dwValue)
{
//MI_TRACE_DCL_TFN("ToolAbal_SetLongToRtArg");

//MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"rt_arg.c=%u , i=%u",rt_arg.c,iRtArg));
//MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"rt_arg.t=%04X",rt_arg.t[iRtArg]));
//MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"rt_arg.l=%u",rt_arg.l[iRtArg]));
//MI_TRACE((CI_TRA_F_DUMP,CI_MODULE_ID,TFN,"rt_arg.v avant",rt_arg.v[iRtArg],rt_arg.l[iRtArg]));

BOOL ret = TRUE;

if (rt_arg.c <= iRtArg) 
   return FALSE;

switch(rt_arg.t[iRtArg]) 
   { 
   case TYPE_POURCENT | MODIFIABLE: 
      *(WORD *)rt_arg.v[iRtArg] = (WORD)dwValue; 
      ToolAbal_SwapBytes((WORD*)rt_arg.v[iRtArg]); 
      break;

   case TYPE_DIESE | MODIFIABLE:    
      *(BYTE *)rt_arg.v[iRtArg] = (BYTE)dwValue; 
      break;

   case TYPE_BCD | MODIFIABLE:      
      ret = ltobcd((BYTE*)rt_arg.v[iRtArg],(WORD)rt_arg.l[iRtArg],dwValue);
      break;
   };

//MI_TRACE((CI_TRA_F_DUMP,CI_MODULE_ID,TFN,"rt_arg.v apres",rt_arg.v[iRtArg],rt_arg.l[iRtArg]));
return ret;
}

// ****************************************************************************
// * ToolAbal_CreateStrC
// * Create a copy of a C-string from a string in ABAL format in rt_arg
// * (must be deleted by ToolAbal_DeleteStrC)
// * USAGE:
// *  --> a rt_arg value is a $,$?
// *  1°) Call this function before using in a C function if you use a C-string convention
// * 
// * IN : index in rt_arg
// * return : pointer on the copy or NULL if failure
// ****************************************************************************
char * ToolAbal_CreateStrC(unsigned int iRtArg)
{
//MI_TRACE_DCL_TFN("ToolAbal_CreateStrC");
//MI_TRACE((CI_TRA_F_DUMP    ,CI_MODULE_ID,TFN,"rt_arg",&rt_arg,16));
//MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"rt_arg.c=%u , i=%u",rt_arg.c,iRtArg));
//MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"rt_arg.t=%04X",rt_arg.t[iRtArg]));
//MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"rt_arg.l=%u",rt_arg.l[iRtArg]));
//MI_TRACE((CI_TRA_F_DUMP,CI_MODULE_ID,TFN,"rt_arg.v avant",rt_arg.v[iRtArg],rt_arg.l[iRtArg]));

if (  ( rt_arg.c > iRtArg )
   && (rt_arg.t[iRtArg] & TYPE_CHAINE)
   )
   {
   register short wLen = rt_arg.l[iRtArg];
   char *   pAbalStr   = (char*)rt_arg.v[iRtArg];
   char *   sCstr;

   while ( (--wLen>=0) && (pAbalStr[wLen] == ' ') );
   wLen++;

   sCstr = (char*) malloc(wLen+1);
   if (sCstr && wLen)
      memcpy(sCstr, pAbalStr, wLen);
   sCstr[wLen] = '\0';
   return sCstr;
   }
else
   return NULL;
}

// ****************************************************************************
// * ToolAbal_DeleteStrC
// * Delete a copy of a C-string created by ToolAbal_CreateStrC
// * IN : pointer on the copy
// ****************************************************************************
void ToolAbal_DeleteStrC(char * sCstr)
{
  free(sCstr);
}


