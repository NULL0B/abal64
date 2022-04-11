// ****************************************************************************
// * zsoAbal.c
// * BDA module
// ****************************************************************************

#define  CI_MODULE_ID   0x0001

/* Inclusions importees */
#include "wdef.h"
#include "pubsbda.h"
#include "pubwbda.h"

// ----------------------------------------------------------------------------
// - Headers of modules
// ----------------------------------------------------------------------------
#include "banner.h"
#include "ztrace.h"
#include "zsoext.h"
#include "zsotxt.h"
#include "zsosys.h"
#include "zsogui.h"

// ----------------------------------------------------------------------------
// - Included C files
// ----------------------------------------------------------------------------
#include "zsover.h"

#define PTRC BYTE FAR PTR
#define PTRI WORD FAR PTR

BDA_GLOBAL BDA s_desrt;     // description de la bibliotheque

// *************************************************************************
// * Fonctions internes
// *************************************************************************

// --------------------------------------------------------------------------
// AbalWord
// --------------------------------------------------------------------------
static WORD AbalWord( BYTE* wptr)
{ return(((*wptr<<8) | *(wptr+1))); }

static void AbalWordPtr( BYTE* a, BYTE* wptr)
{
  *a     = *(wptr+1);
  *(a+1) = *wptr;
}

// *************************************************************************
// * Adaptation Linux
// *************************************************************************

// --------------------------------------------------------------------------
// zsoGui
// --------------------------------------------------------------------------

WORD  BDA_WINAPI  _BdaGui_zStatusMouse(VOID FAR PTR FAR a[])
{ return BdaGui_zStatusMouse( (PTRC)a[0]); }

WORD  BDA_WINAPI  _BdaGui_zInitMouse(VOID FAR PTR FAR a[])
{ return BdaGui_zInitMouse( (PTRC)a[0]); }

WORD  BDA_WINAPI  _BdaGui_zShowMouse(VOID FAR PTR FAR a[])
{ return BdaGui_zShowMouse(); }

WORD  BDA_WINAPI  _BdaGui_zHideMouse(VOID FAR PTR FAR a[])
{ return BdaGui_zHideMouse(); }

WORD  BDA_WINAPI  _BdaGui_zPrintVar(VOID FAR PTR FAR a[])
{ return BdaGui_zPrintVar(AbalWord(a[0]), AbalWord(a[1]), AbalWord(a[2]), (PTRC)a[3] ); }

WORD  BDA_WINAPI  _BdaGui_zPrintItem(VOID FAR PTR FAR a[])
{ return BdaGui_zPrintItem(AbalWord(a[0]), AbalWord(a[1]), AbalWord(a[2]), (PTRC)a[3], (PTRC)a[4], AbalWord(a[5]), AbalWord(a[6]), 0 ); }

WORD  BDA_WINAPI  _BdaGui_zWinScroll(VOID FAR PTR FAR a[])
{ return BdaGui_zWinScroll(AbalWord(a[0]), AbalWord(a[1]), AbalWord(a[2]), AbalWord(a[3]), AbalWord(a[4]), AbalWord(a[5]) ); }

WORD BDA_WINAPI  _BdaGui_zzzshadow(VOID FAR PTR FAR a[])
{ return BdaGui_zzzshadow(AbalWord(a[0]), AbalWord(a[1]), AbalWord(a[2]) ); }

WORD BDA_WINAPI  _BdaGui_zzshadow(VOID FAR PTR FAR a[])
{ return BdaGui_zzshadow(AbalWord(a[0]), AbalWord(a[1]), AbalWord(a[2]), AbalWord(a[3]) ); }

WORD BDA_WINAPI  _BdaGui_MoveWindow(VOID FAR PTR FAR a[])
{ return BdaGui_MoveWindow(AbalWord(a[0]), AbalWord(a[1]) ); }

// --------------------------------------------------------------------------
// zsoSys
// --------------------------------------------------------------------------

WORD BDA_WINAPI  _BdaSys_zPush(VOID FAR PTR FAR a[])
{return BdaSys_zPush(AbalWord(a[0]), AbalWord(a[1]), AbalWord(a[2]), AbalWord(a[3]), AbalWord(a[4]) ); }

WORD BDA_WINAPI  _BdaSys_zPop(VOID FAR PTR FAR a[])
{return BdaSys_zPop(); }

WORD BDA_WINAPI  _BdaSys_zInit(VOID FAR PTR FAR a[])
{return BdaSys_zInit( (PTRC)a[0] ); }

WORD BDA_WINAPI  _BdaSys_zEnd(VOID FAR PTR FAR a[])
{return BdaSys_zEnd(); }

WORD BDA_WINAPI  _BdaSys_zHide(VOID FAR PTR FAR a[])
{return BdaSys_zHide(0); }

WORD BDA_WINAPI  _BdaSys_zShow(VOID FAR PTR FAR a[])
{return BdaSys_zShow(0,AbalWord(a[0]), AbalWord(a[1]), AbalWord(a[2]), AbalWord(a[3])); }

WORD BDA_WINAPI  _BdaSys_zWait(VOID FAR PTR FAR a[])
{return BdaSys_zWait(); }

WORD BDA_WINAPI  _BdaSys_zRleCompress(VOID FAR PTR FAR a[])
{return BdaSys_zRleCompress( (PTRC)a[0], (PTRC)a[1], AbalWord(a[2]) ); }

WORD BDA_WINAPI  _BdaSys_zRleDecompress(VOID FAR PTR FAR a[])
{return BdaSys_zRleDecompress( (PTRC)a[0], (PTRC)a[1], AbalWord(a[2]) ); }

WORD BDA_WINAPI  _BdaSys_zFind(VOID FAR PTR FAR a[])
{return BdaSys_zFind( (PTRC)a[0], (PTRC)a[1], AbalWord(a[2]), AbalWord(a[3]) ); }

WORD BDA_WINAPI  _BdaSys_zTab2Seq(VOID FAR PTR FAR a[])
{return BdaSys_zTab2Seq( AbalWord(a[0]), AbalWord(a[1]), (PTRC)a[2], (PTRC)a[3], (PTRC)a[4], AbalWord(a[5]), AbalWord(a[6]), (PTRC)a[7], (PTRC)a[8], AbalWord(a[9])); }

WORD BDA_WINAPI  _BdaSys_zIndex(VOID FAR PTR FAR a[])
{return BdaSys_zIndex( (PTRC)a[0], *(CHAR*)a[1], AbalWord(a[2]), AbalWord(a[3]) ); }

WORD BDA_WINAPI  _BdaSys_zOem2Ansi(VOID FAR PTR FAR a[])
{return BdaSys_zOem2Ansi( (PTRC)a[0], AbalWord(a[1]) ); }

WORD BDA_WINAPI  _BdaSys_zAnsi2Oem(VOID FAR PTR FAR a[])
{return BdaSys_zAnsi2Oem( (PTRC)a[0], AbalWord(a[1]) ); }

WORD BDA_WINAPI  _BdaSys_AnalAsfun(VOID FAR PTR FAR a[])
{
  SWORD s3 = AbalWord(a[3]);
  SWORD s4 = AbalWord(a[4]);
  SWORD s5 = AbalWord(a[5]);
  SWORD s6 = AbalWord(a[6]);
  SWORD s7 = AbalWord(a[7]);
  WORD  r = BdaSys_AnalAsfun( (PTRC)a[0], AbalWord(a[1]), AbalWord(a[2]), &s3, &s4, &s5, &s6, &s7 );
  AbalWordPtr( a[3], (BYTE*)&s3);
  AbalWordPtr( a[4], (BYTE*)&s4);
  AbalWordPtr( a[5], (BYTE*)&s5);
  AbalWordPtr( a[6], (BYTE*)&s6);
  AbalWordPtr( a[7], (BYTE*)&s7);
  return r;
}

WORD BDA_WINAPI  _BdaSys_CptCharInString(VOID FAR PTR FAR a[])
{ return BdaSys_CptCharInString( (PTRC)a[0], AbalWord(a[1]), (PTRC)a[2] ); }

WORD BDA_WINAPI  _BdaSys_TransformBadCar(VOID FAR PTR FAR a[])
{ return BdaSys_TransformBadCar( AbalWord(a[0]), (PTRC)a[1] ); }

WORD BDA_WINAPI  _BdaSys_Zadrs(VOID FAR PTR FAR a[])
{ return BdaSys_Zadrs( (PTRC)a[0] ); }

// --------------------------------------------------------------------------
// zsoTxt
// --------------------------------------------------------------------------

WORD  BDA_WINAPI  _BdaTxt_zPrint(VOID FAR PTR FAR a[])
{return BdaTxt_zPrint( AbalWord(a[0]), (PTRC)a[1], 0, 0 ); }

WORD  BDA_WINAPI  _BdaTxt_zPrintXYWithSeq(VOID FAR PTR FAR a[])
{return BdaTxt_zPrintXYWithSeq( AbalWord(a[0]), AbalWord(a[1]), AbalWord(a[2]), (PTRC)a[3] ); }

// --------------------------------------------------------------------------
// zsoZac
// n'existe plus, on utilise la BDA d'accès fichier
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Test
// --------------------------------------------------------------------------
WORD BDA_WINAPI  _BdaAba_Test1(WORD toto)
{
MI_TRACE_DCL_TFN("Tst1");
MI_TRACE_RETURN(0);
}

// *************************************************************************
// * INITIALISATION DE LA BIBLIOTHEQUE DYNAMIQUE
// *************************************************************************

/* --------------------------------------------------------------------------
 *
 * FCT InitRelais
 *
 *  Initialisation de la bibliotheque dynamique.
 *
 *  E/ indicateur du type de l'appelant
 *  S/ pointeur sur la description de la bibliotheque
 *
 * Notes :
 *  Sous MS/DOS standard et Amenesik / Sologic, l'appel direct des fonctions
 *  est effectue. Ailleurs (Unix, VMS, DOS etendu et Windows), on
 *  doit passer par des fonctions d'entete de conversion des arguments.
 *  Cf. l'utilitaire BDAGEN pour generer un squelette de fonctions
 *  d'entete et de fonction InitRelais.
 *
 */
VOID FAR PTR InitRelais()
{
MI_TRACE_DCL_TFN("InitRelais");

  MI_TRACE((CI_TRA_F_WARNING,CI_MODULE_ID,TFN,"z '%s'",Banner_GetVersionID(MI_TRA_LINE,Banner_GetVersionStatus())));

  // Signature de la bibliotheque : ici bibliotheque standard:
  if (rt_init != (VOID FAR PTR) 0L) {
    rt_init->ordinaire.signature = BDA_ORDINAIRE;
  }

  // Fonctions d'affichage de la banniere et de fermeture de la bibliotheque:


  s_desrt.banniere = 0;
  s_desrt.fin = (VOID (FAR PTR)(void)) 0L;

  s_desrt.nombre = 122;

  // Tableau de description des fonctions de la bibliotheque:
  s_desrt.reserve = (VOID FAR PTR) 0L;

  s_desrt.fonction[0]   = (WORD (FAR PTR)())_BdaSys_zInit;  
  s_desrt.fonction[1]   = (WORD (FAR PTR)())_BdaGui_zInitMouse; 
  s_desrt.fonction[2]   = (WORD (FAR PTR)())_BdaGui_zShowMouse; 
  s_desrt.fonction[3]   = (WORD (FAR PTR)())_BdaGui_zHideMouse; 
  s_desrt.fonction[4]   = (WORD (FAR PTR)())BdaSys_EmptyFunction; 
  s_desrt.fonction[5]   = (WORD (FAR PTR)())_BdaGui_zStatusMouse; 
  s_desrt.fonction[6]   = (WORD (FAR PTR)())BdaSys_EmptyFunction; 
  s_desrt.fonction[7]   = (WORD (FAR PTR)())_BdaGui_zzzshadow; //zxp only (zzzshadow)
  s_desrt.fonction[8]   = (WORD (FAR PTR)())_BdaSys_zRleCompress; 
  s_desrt.fonction[9]   = (WORD (FAR PTR)())_BdaSys_zRleDecompress;  
  s_desrt.fonction[10]  = (WORD (FAR PTR)())BdaSys_EmptyFunction;  
  s_desrt.fonction[11]  = (WORD (FAR PTR)())BdaSys_EmptyFunction;  
  s_desrt.fonction[12]  = (WORD (FAR PTR)())BdaSys_EmptyFunction;  
  s_desrt.fonction[13]  = (WORD (FAR PTR)())BdaSys_EmptyFunction;  
  s_desrt.fonction[14]  = (WORD (FAR PTR)())_BdaTxt_zPrint;  
  s_desrt.fonction[15]  = (WORD (FAR PTR)())_BdaTxt_zPrintXYWithSeq;  
  s_desrt.fonction[16]  = (WORD (FAR PTR)())_BdaSys_zHide;  
  s_desrt.fonction[17]  = (WORD (FAR PTR)())_BdaSys_zShow;  
  s_desrt.fonction[18]  = (WORD (FAR PTR)())_BdaSys_zWait;  
  s_desrt.fonction[19]  = (WORD (FAR PTR)())_BdaSys_AnalAsfun; //zxp only (zwanal)
  s_desrt.fonction[20]  = (WORD (FAR PTR)())_BdaSys_zEnd;  
  s_desrt.fonction[21]  = (WORD (FAR PTR)())_BdaSys_Zadrs; //zxp only (z_adrs)
  s_desrt.fonction[22]  = (WORD (FAR PTR)())_BdaSys_zPush; 
  s_desrt.fonction[23]  = (WORD (FAR PTR)())_BdaSys_zPop;  
  s_desrt.fonction[24]  = (WORD (FAR PTR)())_BdaGui_MoveWindow; //zxp only (zzwmove)
  s_desrt.fonction[25]  = (WORD (FAR PTR)())_BdaGui_zzshadow; //zxp only (zzshadow)
  s_desrt.fonction[26]  = (WORD (FAR PTR)())_BdaGui_zWinScroll;
  s_desrt.fonction[27]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //_BdaZac_init
  s_desrt.fonction[28]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //_BdaZac_open
  s_desrt.fonction[29]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //_BdaZac_nextline  
  s_desrt.fonction[30]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //_BdaZac_prevline  
  s_desrt.fonction[31]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //_BdaZac_firstline 
  s_desrt.fonction[32]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //_BdaZac_lastline  
  s_desrt.fonction[33]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //_BdaZac_close 
  s_desrt.fonction[34]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //_BdaZac_create  
  s_desrt.fonction[35]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //_BdaZac_write 
  s_desrt.fonction[36]  = (WORD (FAR PTR)())_BdaGui_zPrintVar; 
  s_desrt.fonction[37]  = (WORD (FAR PTR)())_BdaGui_zPrintItem; 
  s_desrt.fonction[38]  = (WORD (FAR PTR)())_BdaSys_TransformBadCar; //zxp only (zprintran)
  s_desrt.fonction[39]  = (WORD (FAR PTR)())_BdaSys_zTab2Seq; 
  s_desrt.fonction[40]  = (WORD (FAR PTR)())_BdaSys_CptCharInString; //zxp only (zstring_cpt)
  s_desrt.fonction[41]  = (WORD (FAR PTR)())_BdaSys_zFind; 
  s_desrt.fonction[42]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //_BdaZac_read  
  s_desrt.fonction[43]  = (WORD (FAR PTR)())_BdaSys_zIndex;
  s_desrt.fonction[44]  = (WORD (FAR PTR)())_BdaSys_zOem2Ansi; 
  s_desrt.fonction[45]  = (WORD (FAR PTR)())_BdaSys_zAnsi2Oem; 
  s_desrt.fonction[46]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaSys_zWinHelp;
  s_desrt.fonction[47]  = (WORD (FAR PTR)())BdaSys_EmptyFunction;  
  s_desrt.fonction[48]  = (WORD (FAR PTR)())BdaSys_EmptyFunction;  
  s_desrt.fonction[49]  = (WORD (FAR PTR)())BdaSys_EmptyFunction;  
  s_desrt.fonction[50]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaGui_zMesVal;  
  s_desrt.fonction[51]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaGui_zMesErr; 
  s_desrt.fonction[52]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaGui_zMesYesNo;  
  s_desrt.fonction[53]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaGui_zMesYesNoCancel;  
  s_desrt.fonction[54]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaGui_zButton;  
  s_desrt.fonction[55]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaGui_zSmallButton;  
  s_desrt.fonction[56]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaGui_zF1Button; 
  s_desrt.fonction[57]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaGui_zListVertScrollBar;  
  s_desrt.fonction[58]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaGui_zLisFicScrollBar; 
  s_desrt.fonction[59]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaGui_zFrame; 
  s_desrt.fonction[60]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaGui_zWindow;  
  s_desrt.fonction[61]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaTxt_zFont; 
  s_desrt.fonction[62]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaGui_zCheck; 
  s_desrt.fonction[63]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaGui_zRadio; 
  s_desrt.fonction[64]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaTxt_zStatusXY; 
  s_desrt.fonction[65]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaTxt_zStatusDraw; 
  s_desrt.fonction[66]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaTxt_zStatus;  
  s_desrt.fonction[67]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaGui_zMouseCursor;  
  s_desrt.fonction[68]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaGui_zAskCursor;  
  s_desrt.fonction[69]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaImg_zButtonBitmap;  
  s_desrt.fonction[70]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaImg_zBitmap; 
  s_desrt.fonction[71]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaSys_zWinImpl; 
  s_desrt.fonction[72]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaImg_zDllBitmapLoad;  
  s_desrt.fonction[73]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaImg_zDllBitmapFree;  
  s_desrt.fonction[74]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaGui_zListHoriScrollBar;  
  s_desrt.fonction[75]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaSys_zAppliAlone;  
  s_desrt.fonction[76]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaSys_zChDir;  
  s_desrt.fonction[77]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaImg_zBmpLoad;  
  s_desrt.fonction[78]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaImg_zBmpFree;  
  s_desrt.fonction[79]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaImg_zButtonBmp;  
  s_desrt.fonction[80]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaImg_zBmp; 
  s_desrt.fonction[81]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaSys_zWinVersion;  
  s_desrt.fonction[82]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaGui_zWinClear; 
  s_desrt.fonction[83]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaGui_zListTitle;  
  s_desrt.fonction[84]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaGui_zWinMove; 
  s_desrt.fonction[85]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaGui_zWinMoveable; 
  s_desrt.fonction[86]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaGui_zTabview; 
  s_desrt.fonction[87]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaSys_zGetMaxy; 
  s_desrt.fonction[88]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaTxt_zFontChoose; 
  s_desrt.fonction[89]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaTxt_zFontCreate; 
  s_desrt.fonction[90]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaTxt_zFontDelete; 
  s_desrt.fonction[91]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaGui_zWinTitle; 
  s_desrt.fonction[92]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaTxt_zPrintL;  
  s_desrt.fonction[93]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaImg_getcolor;  
  s_desrt.fonction[94]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaImg_color; 
  s_desrt.fonction[95]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaImg_brush; 
  s_desrt.fonction[96]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaImg_pen; 
  s_desrt.fonction[97]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaImg_point; 
  s_desrt.fonction[98]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaImg_line;  
  s_desrt.fonction[99]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaImg_rectangle; 
  s_desrt.fonction[100] = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaImg_roundrect;  
  s_desrt.fonction[101] = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaImg_ellipse;  
  s_desrt.fonction[102] = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaImg_arc;  
  s_desrt.fonction[103] = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaImg_trapez; 
  s_desrt.fonction[104] = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaTxt_zPrintXYWithoutSeq; 
  s_desrt.fonction[105] = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaImg_zBmp2; 
  s_desrt.fonction[106] = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaSys_zWinNbBits;
  s_desrt.fonction[107] = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaTxt_zDefaultFont;
  s_desrt.fonction[108] = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaSys_zRGBColor;
  s_desrt.fonction[109] = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaSys_zDefaultColor;
  s_desrt.fonction[110] = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaGui_zVaButton;
  s_desrt.fonction[111] = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaSys_zWinSetStack;
  s_desrt.fonction[112] = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaSys_zSystemMenu;
  s_desrt.fonction[113] = (WORD (FAR PTR)())BdaSys_EmptyFunction;
  s_desrt.fonction[114] = (WORD (FAR PTR)())BdaSys_EmptyFunction; // _BdaTra_Msg;
  s_desrt.fonction[115] = (WORD (FAR PTR)())BdaSys_EmptyFunction; // _BdaTra_MsgInt;

  s_desrt.fonction[116] = (WORD (FAR PTR)())_BdaAba_Test1;
  s_desrt.fonction[117] = (WORD (FAR PTR)())_BdaAba_Test1;
  s_desrt.fonction[118] = (WORD (FAR PTR)())_BdaAba_Test1;

  s_desrt.fonction[119] = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaSys_ManageLoadgo;
  s_desrt.fonction[120] = (WORD (FAR PTR)())BdaSys_EmptyFunction; // ZGR BdaImg_ScreenSaver;
  s_desrt.fonction[121] = (WORD (FAR PTR)())BdaSys_EmptyFunction; // _BdaTra_Dump;

  return((VOID FAR PTR) &s_desrt);

}


