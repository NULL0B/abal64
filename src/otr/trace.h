// ****************************************************************************
// * trace.h
// * Trace functionnality
// ****************************************************************************
// * 
// * Les éléments décrits sont classés par entité (structure, variables, macros,...)
// * Pour chaque entité, on trouve une compil conditionnelle selon TRACEON
// * 
// ****************************************************************************
// * 
// * Utilisation des macros optionnelles
// * 
// * Implémentation du filtre CI_MODULE_ID :
// * ---------------------------------------
// *    A l'origine, CI_MODULE_ID était conçu pour identifier les parties fonctionnelles
// *    du code regroupé dans des modules (ex pour zGr : module texte, dessin, GUI,...).
// *    ' // Fichier texte.c
// *    ' #include "trace.h"
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
// *    Dans ces 2 derniers cas, le plus simple consiste à encapsuler trace.h dans un fichier
// *    persotrace.h comme-suit :
// *    
// *    ' // Fichier persotrace.h
// *    ' #include "trace.h"
// *    ' <définitions de constantes et de macros comme ci-dessus>
// *    
// ****************************************************************************

#ifndef _TRACE_H
#define _TRACE_H

// ----------------------------------------------------------------------------
// - Constants
// ----------------------------------------------------------------------------
#define CI_TRA_F_ERROR      0x0001  // Fatal error detection
#define CI_TRA_F_WARNING    0x0002  // other error detection
#define CI_TRA_F_FUNCTION   0x0004  // begin and end of functions
#define CI_TRA_F_PARAM      0x0008  // parameters
#define CI_TRA_F_INFO_HIGH  0x0010  // important information to understand a function
#define CI_TRA_F_INFO_LOW   0x0020  // more detail informations, but not always needed
#define CI_TRA_F_DEBUG      0x0040  // only for coding
#define CI_TRA_F_DUMP       0x0080  // only for coding (could be voluminous)
#define CI_TRA_F_X          0x0100

// --- Trace State (to initialise user contexts)
#define CI_TRA_ON_OK           0x0001
#define CI_TRA_ON_FIRST_TIME   0x0002

// ----------------------------------------------------------------------------
// - Structure
// ----------------------------------------------------------------------------
#ifdef TRACEON
////// TRACEON begin /////////////////////////////////////////////////////
#ifdef __cplusplus
extern "C" {
#endif

#define CI_TRA_MAXFILE 512
#define CI_TRA_MAXBUF  1024

typedef struct
   {
   // --- Public members
   unsigned short  On;              // Trace activation
   unsigned short  FilterLevel;     // Memo of accepted levels   , from ini file 
   unsigned short  FilterId;        // Memo of accepted module ID, from ini file
   unsigned long   Timer;           // Trace activation par timer
   char            Line[CI_TRA_MAXFILE+1]; // Miscellaneous buffer for applicative usage
   // --- Private members during message writing
   char *          p;               // Pointer on pri_Buf
   void *			 Handle;          // Handle on pri_File file
   // --- Private members
	unsigned short  pri_Stream;		// Memo of stream output (file,stdout,stderr), from ini file
   unsigned short  pri_MaskId1;     // Memo of mask ID n°1       , from constant or ResetValue
   unsigned short  pri_MaskId2;     // Memo of Mask ID n°2       , from constant or ResetValue
   unsigned long   pri_Process;     // Memo of Process ID        , from system
   unsigned long   pri_TimerIni;    // activation par timer
   unsigned long   pri_TimerCur;    // activation par timer
   char            pri_Prg[5];      // Memo of Program name      , from constant or ResetValue
   char            pri_File[CI_TRA_MAXFILE+1];   // Memo of trace file name   , from ini file
   char            pri_Buf[CI_TRA_MAXBUF+1];     // To make the trace line
   } TI_TRA_CTX;



#ifdef __cplusplus
}
#endif
////// TRACEON end ///////////////////////////////////////////////////////
#else
////// TRACEOFF begin ////////////////////////////////////////////////////
#define TI_TRA_CTX  unsigned short
////// TRACEOFF end //////////////////////////////////////////////////////
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

// Use inside a MI_TRACE call to trunc a big string
char * TraTruncString(char* buf, const char* s);
char * TraStr        (char* buf, const char* s, unsigned short lg);

// (never call directly these functions, use the macros MI_TRACE and co)
unsigned short TraTrace(unsigned short Level,unsigned short Id, const char * tfn, const char * mes, ...);

// enhanced usage, contexts managed by application
unsigned short TraCtxReset( TI_TRA_CTX* pCtx, unsigned short MaskUser1, unsigned short MaskUser2, const char* pMasterKeyUser, const char* pPrgUser, unsigned short IsVerbose );
unsigned short TraCtxClone(TI_TRA_CTX* pCtx_des, const TI_TRA_CTX* pCtx_ori);
unsigned short TraCtxTrace(TI_TRA_CTX* pCtx, unsigned short Level,unsigned short Id, const char * tfn, const char * mes, ...);
unsigned short TraCtxTraceDumpLg(TI_TRA_CTX* pCtx,unsigned short Level,unsigned short Id, const char * tfn, unsigned short lgTfn, const char * mes, unsigned short lgMes, const char * Zone, unsigned short lgZone);
unsigned short TraCtxTraceMessLg(TI_TRA_CTX* pCtx,unsigned short Level,unsigned short Id, const char * tfn, unsigned short lgTfn, const char * mes, unsigned short lgMes);

// enhanced usage, ini file acceded by application
unsigned short TraGetKey(char* Value, const char* MasterKey, const char* SearchKey, unsigned short LgMax, unsigned short IsPathName);

#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------
// - Basic Macros
// - Generate a call to trace function
// ----------------------------------------------------------------------------

#ifdef TRACEON
////// TRACEON begin /////////////////////////////////////////////////////

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
#define MI_TRACE_CTX(a) (TraCtxTrace a)

////// TRACEON end ///////////////////////////////////////////////////////
#else
////// TRACEOFF begin ////////////////////////////////////////////////////

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
#define MI_TRACE_CTX(a) (void)0

////// TRACEOFF end //////////////////////////////////////////////////////
#endif

// ----------------------------------------------------------------------------
// - Optional Macros for begin / end trace messages
// - (assumed CI_MODULE_ID and TFN are defined)
// ----------------------------------------------------------------------------

// First trace when entry in a function
#define MI_TRACE_BEGIN()          MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,(TFN),"-- Begin"))
#define MI_TRACE_END()            MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,(TFN),"-- End"))

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

// return with return code in the trace
#define MI_TRACE_RETURN_W(ret)                                                                      \
            return                                                                                \
            (                                                                                     \
            MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,(TFN),"-- End %d (%04Xh)",(ret),(ret))),     \
            (ret)                                                                                 \
            )

// return with return code in the trace
#define MI_TRACE_RETURN_L(ret)                                                                      \
            return                                                                                \
            (                                                                                     \
            MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,(TFN),"-- End %ld (%08Xh)",(int)(ret),(int)(ret))),     \
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
