#ifndef _EX_TRACE_H_
#define _EX_TRACE_H_

#include "trace.h"

#define ID_WEXA			0x0001	// 1 << 0
#define ID_MA2			0x0002	// 1 << 1
#define ID_WBF			0x0004	// 1 << 2
#define ID_ALLOC		0x0008	// 1 << 3
#define ID_BASMESS		0x0010	// 1 << 4
#define ID_OTHER		0x0020	// 1 << 5
#define ID_TMP1			0x0040	// 1 << 6
#define ID_TMP2			0x0080	// 1 << 7
#define ID_GIGO_VERB	0x0100	// 1 << 8
#define ID_GIGO			0x0200	// 1 << 9
#define ID_CICO_VERB    0x0400	// 1 << 10
#define ID_CICO			0x0800	// 1 << 11
#define ID_CICO_IMP		0x1000	// 1 << 12
#define ID_ASFUN		0x2000	// 1 << 13
#define ID_ASSIGN		0x4000	// 1 << 14
#define ID_KERNEL		0x8000	// 1 << 15

#define ID_FULL			0xFFFF

#if defined(TRACEABAL)
////// TRACEABAL begin /////////////////////////////////////////////////////

#define MI_TRACTX_RESET(pCtx,mu1,mu2,pKey,pPrg,IsVerb)						TraCtxReset( (pCtx),(mu1),(mu2),(pKey),(pPrg), (IsVerb) ) 
#define MI_TRACTX_MESSLG(pCtx,Level,Id,tfn,lgTfn,mes,lgMes)             (((pCtx)->On) ? TraCtxTraceMessLg((pCtx),(Level),(Id),(tfn),(lgTfn),(mes),(lgMes)) : 0)
#define MI_TRACTX_DUMPLG(pCtx,Level,Id,tfn,lgTfn,mes,lgMes,Zone,lgZone) (((pCtx)->On) ? TraCtxTraceDumpLg((pCtx),(Level),(Id),(tfn),(lgTfn),(mes),(lgMes),(Zone),(lgZone)) : 0)

////// TRACEABAL end ///////////////////////////////////////////////////////
#else
////// TRACEABAL OFF begin /////////////////////////////////////////////////

#define MI_TRACTX_RESET(pCtx,mu1,mu2,pKey,pPrg)									(void)0
#define MI_TRACTX_MESSLG(pCtx,Level,Id,tfn,lgTfn,mes,lgMes)             (void)0
#define MI_TRACTX_DUMPLG(pCtx,Level,Id,tfn,lgTfn,mes,lgMes,Zone,lgZone) (void)0

////// TRACEABAL OFF end ///////////////////////////////////////////////////
#endif

#endif

