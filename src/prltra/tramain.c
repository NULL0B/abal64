/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*    DEFINITION DU SYSTEME D'EXPLOITATION CIBLE        		     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#define  CI_MODULE_ID   0x0001

/* Inclusions importees */
#include "bda.h"
#include "toolabal.h"
#include "trace.h"
#include "tractx.h"

// ----------------------------------------------------------------------------
// - Included C files
// ----------------------------------------------------------------------------
#include "traver.h"   // Patern definition

#define PTRC BYTE FAR PTR
#define PTRI WORD FAR PTR

BDA_GLOBAL BDA s_desrt;     // description de la bibliotheque


// ****************************************************************************
// * _BdaTra_Msg
// ****************************************************************************
#if defined (BDA_WIN32) | defined(BDA_UNIX)
WORD BDA_WINAPI _BdaTra_Msg (VOID FAR PTR FAR a[])
#elif defined(BDA_TWIN16)
WORD BDA_WINAPI _BdaTra_Msg (WORD i, WORD Level, WORD Id, const char * tfn, const char * mes)
#endif
{
#ifdef TRACEON

#if defined (BDA_WIN32) | defined(BDA_UNIX)
register WORD i;
register WORD Level;
register WORD Id;
#endif
TI_TRA_CTX*   pCtx;

//MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,"_BdaTra_Msg","-- preBegin"));
//MI_TRACE((CI_TRA_F_PARAM   ,CI_MODULE_ID,"_BdaTra_Msg","i=%04X Level=%04X Id=%04X",i,Level,Id));
//MI_TRACE((CI_TRA_F_DUMP    ,CI_MODULE_ID,"_BdaTra_Msg","tfn",tfn,5));
//MI_TRACE((CI_TRA_F_DUMP    ,CI_MODULE_ID,"_BdaTra_Msg","mes",mes,16));

#if defined (BDA_WIN32) | defined(BDA_UNIX)
i     = ToolAbal_WORD(a[0]);
Level = ToolAbal_WORD(a[1]);
Id    = ToolAbal_WORD(a[2]);
#endif

pCtx  = GetCtx(i);
//MI_TRACE((CI_TRA_F_DUMP    ,CI_MODULE_ID,"_BdaTra_Init","pCtx",pCtx,sizeof(TI_TRA_CTX) ));
//MI_TRACE((CI_TRA_F_PARAM   ,CI_MODULE_ID,"_BdaTra_Msg","On=%04X Level=%04X Id=%04X",pCtx->On,pCtx->FilterLevel,pCtx->FilterId));

if ( (pCtx->On) && (Level & pCtx->FilterLevel) && ((Level & 0x0003) || (Id & pCtx->FilterId)) )
   {
   char* tfn = ToolAbal_CreateStrC(3);
   char* mes = ToolAbal_CreateStrC(4);
   WORD ret = TraCtxTrace(pCtx,Level,Id,tfn,"%s",mes);
   ToolAbal_DeleteStrC(tfn);
   ToolAbal_DeleteStrC(mes);
   return ret;
   }

//MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,"_BdaTra_Msg","-- postEnd"));
#endif

return 0;
}

// ****************************************************************************
// * _BdaTra_Dump
// ****************************************************************************
#if defined (BDA_WIN32) | defined(BDA_UNIX)
WORD BDA_WINAPI _BdaTra_Dump (VOID FAR PTR FAR a[])
#elif defined(BDA_TWIN16)
WORD BDA_WINAPI _BdaTra_Dump (WORD i, WORD Level, WORD Id, const char * tfn, const char * mes, const char * Zone, unsigned short Lg)
#endif
{
#ifdef TRACEON
#if defined (BDA_WIN32) | defined(BDA_UNIX)
register WORD i;
register WORD Level;
register WORD Id;
char*    Zone;
WORD     Lg;
#endif
TI_TRA_CTX*   pCtx;

//MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,"_BdaTra_Dump","-- preBegin"));

#if defined (BDA_WIN32) | defined(BDA_UNIX)
i     = ToolAbal_WORD(a[0]);
Level = ToolAbal_WORD(a[1]);
Id    = ToolAbal_WORD(a[2]);
Zone  = (PTRC)a[5];
Lg    = ToolAbal_WORD(a[6]);
#endif

pCtx  = GetCtx(i);

if ( (pCtx->On) && (Level & pCtx->FilterLevel) && ((Level & 0x0003) || (Id & pCtx->FilterId)) )
   {
   char* tfn = ToolAbal_CreateStrC(3);
   char* mes = ToolAbal_CreateStrC(4);
   WORD ret = TraCtxTrace(pCtx, (WORD)(Level|CI_TRA_F_DUMP) ,Id,tfn,mes,Zone,Lg);
   ToolAbal_DeleteStrC(tfn);
   ToolAbal_DeleteStrC(mes);
   return ret;
   }

//MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,"_BdaTra_Dump","-- postEnd"));
#endif

return 0;
}

// ****************************************************************************
// * _BdaTra_Init
// ****************************************************************************
#if defined (BDA_WIN32) | defined(BDA_UNIX)
WORD BDA_WINAPI  _BdaTra_Init (VOID FAR PTR FAR a[])
#elif defined(BDA_TWIN16)
WORD BDA_WINAPI  _BdaTra_Init ( WORD i, WORD MaskUser1, WORD MaskUser2, const char* pMasterKeyUser, const char* pPrgUser )
#endif
{
#ifdef TRACEON
#if defined (BDA_WIN32) | defined(BDA_UNIX)
register WORD  i;
register WORD  MaskUser1;
register WORD  MaskUser2;
#endif
char* Key;
char* Prg;
TI_TRA_CTX*   pCtx;

#if defined (BDA_WIN32) | defined(BDA_UNIX)
i         = ToolAbal_WORD(a[0]);
MaskUser1 = ToolAbal_WORD(a[1]);
MaskUser2 = ToolAbal_WORD(a[2]);
#endif

//MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,"_BdaTra_Init","-- preBegin"));
//MI_TRACE((CI_TRA_F_PARAM   ,CI_MODULE_ID,"_BdaTra_Init","i=%04X M1=%04X M2=%04X",i,MaskUser1,MaskUser2));
//MI_TRACE((CI_TRA_F_DUMP    ,CI_MODULE_ID,"_BdaTra_Init","pMasterKeyUser",pMasterKeyUser,10));
//MI_TRACE((CI_TRA_F_DUMP    ,CI_MODULE_ID,"_BdaTra_Init","pPrgUser",pPrgUser,5));
//MI_TRACE((CI_TRA_F_DUMP    ,CI_MODULE_ID,"_BdaTra_Init","rt_arg",&rt_arg,16));

Key = ToolAbal_CreateStrC(3);
Prg = ToolAbal_CreateStrC(4);

//MI_TRACE((CI_TRA_F_DEBUG   ,CI_MODULE_ID,"_BdaTra_Init","Key '%s'",MI_TRA_TRUNC(Key)));
//MI_TRACE((CI_TRA_F_DUMP    ,CI_MODULE_ID,"_BdaTra_Init","Key",Key,10));
//MI_TRACE((CI_TRA_F_DUMP    ,CI_MODULE_ID,"_BdaTra_Init","Prg",Prg,5));

if (i!=1)
   {
   i=CreateIndex(i);
   if (i==1)
      return 1;
   }

pCtx  = GetCtx(i);
TraCtxReset( pCtx, MaskUser1, MaskUser2, Key, Prg );

ToolAbal_DeleteStrC(Key);
ToolAbal_DeleteStrC(Prg);
//MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,"_BdaTra_Init","-- postEnd"));
return i;

#else

return 0;

#endif
}

// ****************************************************************************
// * _BdaTra_End
// ****************************************************************************
#if defined (BDA_WIN32) | defined(BDA_UNIX)
WORD BDA_WINAPI  _BdaTra_End (VOID FAR PTR FAR a[])
#elif defined(BDA_TWIN16)
WORD BDA_WINAPI  _BdaTra_End (WORD i)
#endif
{
#ifdef TRACEON

#if defined (BDA_WIN32) | defined(BDA_UNIX)
WORD i;
#endif

//MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,"_BdaTra_End","-- preBegin"));

#if defined (BDA_WIN32) | defined(BDA_UNIX)
i = ToolAbal_WORD(a[0]);
#endif

DeleteIndex(i);
//MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,"_BdaTra_End","-- postEnd"));
return 1;

#else

return 0;

#endif
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*    INITIALISATION DE LA BIBLIOTHEQUE DYNAMIQUE        */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

// ****************************************************************************
// * banniere
// ****************************************************************************
VOID  banniere(VOID)
{
MI_TRACE_DCL_TFN("banniere");

  MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"'%s'",Banner_GetVersionID(g_TraCtx.Line,'2') ));
  Banner_DisplayBanner();
}

// ****************************************************************************
// *
// * FCT InitRelais
// *
// *  Initialisation de la bibliotheque dynamique.
// *
// *  E/ indicateur du type de l'appelant
// *  S/ pointeur sur la description de la bibliotheque
// *
// * Notes :
// *  Sous MS/DOS standard et Amenesik / Sologic, l'appel direct des fonctions
// *  est effectue. Ailleurs (Unix, VMS, DOS etendu et Windows), on
// *  doit passer par des fonctions d'entete de conversion des arguments.
// *  Cf. l'utilitaire BDAGEN pour generer un squelette de fonctions
// *  d'entete et de fonction InitRelais.
// *
// ****************************************************************************
#if defined (BDA_UNIX) || defined(BDA_TWIN16)
VOID FAR PTR InitRelais()
#elif defined (BDA_WIN32)
VOID FAR PTR InitRelais(WORD from)
#endif
{
MI_TRACE_DCL_TFN("InitRelais");
//MI_TRACE((CI_TRA_F_WARNING,CI_MODULE_ID,TFN,"ztra '%s'","coucou"));
InitTabTra();

// Signature de la bibliotheque : ici bibliotheque standard:
if (rt_init != (VOID FAR PTR) 0L) 
   rt_init->ordinaire.signature = BDA_ORDINAIRE;

// Fonctions d'affichage de la banniere et de fermeture de la bibliotheque:

s_desrt.banniere = banniere;
s_desrt.fin      = DeleteAll;

s_desrt.nombre = 4;

// Tableau de description des fonctions de la bibliotheque:
s_desrt.reserve = (VOID FAR PTR) 0L;

s_desrt.fonction[0] =(WORD (PASCAL FAR *)()) _BdaTra_Msg;
s_desrt.fonction[1] =(WORD (PASCAL FAR *)()) _BdaTra_Dump;
s_desrt.fonction[2] =(WORD (PASCAL FAR *)()) _BdaTra_Init;
s_desrt.fonction[3] =(WORD (PASCAL FAR *)()) _BdaTra_End;

return((VOID FAR PTR) &s_desrt);
}


