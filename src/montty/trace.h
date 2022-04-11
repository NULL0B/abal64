// ****************************************************************************
// * zTrace.h
// * Trace functionnality
// ****************************************************************************
#ifndef _ZTRACE_H
#define _ZTRACE_H

// ****************************************************************************
// * TRACE and NOTRACE
// ****************************************************************************
#ifdef __cplusplus
  extern "C" {
#endif
// ----------------------------------------------------------------------------
// - BDA functions
// ----------------------------------------------------------------------------
unsigned short BdaTra_Msg   (unsigned short Level,unsigned short Id, const char * tfn, const char * mes);
unsigned short BdaTra_MsgInt(unsigned short Level,unsigned short Id, const char * tfn, const char * mes, unsigned short val);
unsigned short BdaTra_Dump  (unsigned short Level,unsigned short Id, const char * tfn, const char * mes, const char * Zone, unsigned short Lg);
#ifdef __cplusplus
  }
#endif

#ifdef TRACEON
// ****************************************************************************
// * TRACE
// ****************************************************************************

// ----------------------------------------------------------------------------
// - Constants
// - How to use trace level ?
// - ERROR     : Fatal error detection
// - WARNING   : other error detection
// - FUNCTION  : begin and end of functions
// - PARAM     : parameters
// - INFO_HIGH : important information to understand a function
// - INFO_LOW  : more detailes informations, but not always needed
// - DEBUG     : only for coding might be removed after
// ----------------------------------------------------------------------------
#define CI_TRA_F_ERROR      0x0001
#define CI_TRA_F_WARNING    0x0002
#define CI_TRA_F_FUNCTION   0x0004
#define CI_TRA_F_PARAM      0x0008
#define CI_TRA_F_INFO_HIGH  0x0010
#define CI_TRA_F_INFO_LOW   0x0020
#define CI_TRA_F_DEBUG      0x0040
#define CI_TRA_F_DUMP       0x0080

#ifdef __cplusplus
  extern "C" {
#endif
// ----------------------------------------------------------------------------
// - Internal functions
// ----------------------------------------------------------------------------
char * TraTruncString(char* s);
// (never call directly this function, use the macro "MI_TRACE")
unsigned short TraTrace(unsigned short Level,unsigned short Id, const char * tfn, const char * mes,...);

// ----------------------------------------------------------------------------
// - Variables
// ----------------------------------------------------------------------------
extern unsigned short g_IsTraOn;
// Miscellaneous buffer to display 1 line in the trace
extern char  g_TraLine[81]; 
#ifdef __cplusplus
  }
#endif

// ----------------------------------------------------------------------------
// - Macros
// - Generate a call to trace function
// ----------------------------------------------------------------------------
#define MI_TRACE_DCL_TFN(a) const char* TFN = a  
#define MI_TRACE(a) (g_IsTraOn) ? TraTrace a : 0

#else
// ****************************************************************************
// * NO TRACE
// ****************************************************************************
// ----------------------------------------------------------------------------
// - Macros
// - Generate a void operation returning 0
// ----------------------------------------------------------------------------
#define MI_TRACE_DCL_TFN(a) const char* TFN = ""
#define MI_TRACE(a) 0

#endif

// ****************************************************************************
// * TRACE and NOTRACE
// ****************************************************************************

// ----------------------------------------------------------------------------
// - Macros for begin / end trace messages
// - (assumed CI_MODULE_ID is defined at the beginning of the module 
// - (and TFN variable is declared at the beginning of the function by MI_TRACE_DCL_TFN
// ----------------------------------------------------------------------------

// First trace when entry in a function
#define MI_TRACE_BEGIN()          MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,(TFN),"-- Begin"))

// Just one message for begin and return of an empty function
#define MI_TRACE_VOID(ret)        MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,(TFN),"-- Void %d (%04Xh)",(ret),(ret)))

// return with return code in the trace
#define MI_TRACE_RETURN(ret)                                                                 \
            return                                                                           \
            (                                                                                \
	    MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,(TFN),"-- End %d %04Xh)",(ret),(ret))), \
            (ret)                                                                            \
            )


#define FUCKMI_TRACE_RETURN(ret) \
            return \
            ( \
            MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,(TFN),"-- End %d %04Xh)",(ret),(ret))), \
           (ret) \
            )

// return with return code and a message in the trace
#define MI_TRACE_RETURN_MSG(ret,msg)                                                              \
            return                                                                                \
            (                                                                                     \
            MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,(TFN),"-- End %s %d (%04Xh)",(msg),(ret),(ret))), \
            (ret)                                                                                 \
            )

#endif
