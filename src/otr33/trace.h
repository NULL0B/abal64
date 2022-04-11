// ****************************************************************************
// * Trace.h
// * Trace functionnality
// ****************************************************************************
// * 
// * Implémentation du filtre CI_MODULE_ID :
// * ---------------------------------------
// *    A l'origine, CI_MODULE_ID était conçu pour identifier des parties fonctionnelles
// *    du code regroupés dans des modules (ex pour zGr : module texte, dessin, GUI,...).
// *    ' // Fichier Texte.c
// *    ' #include "Trace.h"
// *    ' #define CI_MODULE_ID 0x0010
// * 
// *    Pour la TTY, CI_MODULE_ID a un rôle plus dynamique, puisqu'il identifie le port
// *    passé en paramètre à une API. A titre d'exemple, voici le code permettant de différencier
// *    les ports (a == n° de port de 0 à 8).
// *    ' #ifdef TRACEON
// *    ' #define MI_TRACE_DCL_MODULE_ID(a)    const unsigned short CI_MODULE_ID = (1<<(a))
// *    ' #define MI_TRACE_DCL_MODULE_ID_ALL() const unsigned short CI_MODULE_ID = CI_TRA_ID_MASK_2
// *    ' #else
// *    ' #define MI_TRACE_DCL_MODULE_ID(a)    const unsigned short CI_MODULE_ID = 0
// *    ' #define MI_TRACE_DCL_MODULE_ID_ALL() const unsigned short CI_MODULE_ID = 0
// *    ' #endif
// * 
// *    Ce principe a été appliqué à Mbase32 pour différencier les types d'appel (Isam, SQ, BD,...).
// *    ' // Définition de 'a'
// *    ' #define C_FF    0
// *    ' .../...
// *    ' #define C_ISAM  4
// *    ' 
// *    ' <idem tty>
// *    
// *    Dans ces 2 derniers cas, le plus simple consiste à encapsuler Trace.h dans un fichier
// *    PersoTrace.h comme-suit :
// *    
// *    ' // Fichier PersoTrace.h
// *    ' #include "Trace.h"
// *    ' <définitions de constantes et de macros comme ci-dessus>
// *    
// ****************************************************************************

#ifndef _TRACE_H
#define _TRACE_H

// ----------------------------------------------------------------------------
// - Constants
// - ERROR     : Fatal error detection
// - WARNING   : other error detection
// - FUNCTION  : begin and end of functions
// - PARAM     : parameters
// - INFO_HIGH : important information to understand a function
// - INFO_LOW  : more detail informations, but not always needed
// - DEBUG     : only for coding
// - DUMP      : only for coding (could be voluminous)
// ----------------------------------------------------------------------------
#define CI_TRA_F_ERROR      0x0001
#define CI_TRA_F_WARNING    0x0002
#define CI_TRA_F_FUNCTION   0x0004
#define CI_TRA_F_PARAM      0x0008
#define CI_TRA_F_INFO_HIGH  0x0010
#define CI_TRA_F_INFO_LOW   0x0020
#define CI_TRA_F_DEBUG      0x0040
#define CI_TRA_F_DUMP       0x0080

// ----------------------------------------------------------------------------
// - Structure
// ----------------------------------------------------------------------------
#ifdef TRACEON

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
   {
   // Public members
   unsigned short  On;
   unsigned short  FilterLevel;
   unsigned short  FilterId;
   char            Line[81];
   // Private members
   unsigned short  pri_MaskId1;     // Memo of mask ID n°1       , from constant or ResetValue
   unsigned short  pri_MaskId2;     // Memo of Mask ID n°2       , from constant or ResetValue
   unsigned long   pri_Process;     // Memo of Process ID        , from system
   char            pri_Prg[5];      // Memo of Program name      , from constant or ResetValue
   char            pri_File[512];   // Memo of trace file name   , from ini file
   char            pri_Buf[256];    // To make the trace line
   } TI_TRA_CTX;

#ifdef __cplusplus
}
#endif

#else
#define TI_TRA_CTX  unsigned short
#endif

// ----------------------------------------------------------------------------
// - Variables
// ----------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

extern TI_TRA_CTX g_TraCtx;

#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------
// - Functions
// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif
// (never call directly these functions, use the macros MI_TRACE and co)
unsigned short TraTrace(unsigned short Level,unsigned short Id, const char * tfn, const char * mes,...); 

unsigned short TraCtxTrace(TI_TRA_CTX* pCtx,unsigned short Level,unsigned short Id, const char * tfn, const char * mes,...);
unsigned short TraCtxReset(TI_TRA_CTX* pCtx,unsigned short MaskUser1, unsigned short MaskUser2, const char* pMasterKeyUser, const char* pPrgUser );

// Use inside a MI_TRACE call to trunc a big string
char * TraTruncString(char* buf, const char* s);
char * TraStr        (char* buf, const char* s, unsigned short lg);

#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------
// - Basic Macros
// - Generate a call to trace function
// ----------------------------------------------------------------------------
#ifdef TRACEON

// --- macros utilisables dans un MI_TRACE
#define MI_TRA_LINE         g_TraCtx.Line
#define MI_TRA_TRUNC(a)     TraTruncString(g_TraCtx.Line,(a))
#define MI_TRA_TRUNCLG(a,b) TraStr(g_TraCtx.Line,(a),(b))

// --- déclaration du nom de fonction TFN
#if defined(__GNUC__)
#define MI_TRACE_DCL_TFN(a) const char* TFN __attribute__ ((unused)) = a  
#else
#define MI_TRACE_DCL_TFN(a) const char* TFN = a  
#endif

// --- Message de trace
#define MI_TRACE(a) ((g_TraCtx.On) ? TraTrace a : 0)

#else
// TRACE INACTIVE les macros ne font rien

// --- macros utilisables dans un MI_TRACE
#define MI_TRA_LINE         (void)0
#define MI_TRA_TRUNC(a)     (void)0
#define MI_TRA_TRUNCLG(a,b) (void)0

// --- déclaration du nom de fonction TFN
#if defined(__GNUC__)
#define MI_TRACE_DCL_TFN(a) const char* TFN __attribute__ ((unused)) = "" 
#else
#define MI_TRACE_DCL_TFN(a) const char* TFN = ""
#endif

// --- Message de trace
#define MI_TRACE(a) (void)0

#endif

// ----------------------------------------------------------------------------
// - Macros for begin / end trace messages
// - (assumed CI_MODULE_ID and TFN are defined)
// ----------------------------------------------------------------------------

// First trace when entry in a function
#define MI_TRACE_BEGIN()          MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,(TFN),"-- Begin"))

// Just one message for begin and return of an empty function
#define MI_TRACE_VOID(ret)                                                                        \
            return                                                                                \
            (                                                                                     \
            MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,(TFN),"-- Void %d (%04Xh)",(ret),(ret))),    \
            (ret)                                                                                 \
            )


// return with return code in the trace
#define MI_TRACE_RETURN(ret)                                                                      \
            return                                                                                \
            (                                                                                     \
            MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,(TFN),"-- End %d (%04Xh)",(ret),(ret))),     \
            (ret)                                                                                 \
            )

// return with return code and a message in the trace
#define MI_TRACE_RETURN_MSG(ret,msg)                                                              \
            return                                                                                \
            (                                                                                     \
            MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,(TFN),"-- End %s %d (%04Xh)",(msg),(ret),(ret))), \
            (ret)                                                                                 \
            )

#endif
