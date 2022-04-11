/** @pkg Staff.Fred.zLook */ 
// ****************************************************************************
// * zLook.c
// * Look module
// ****************************************************************************

#define CI_MODULE_ID 0x0040

#if defined(__linux__) || defined(UNIX)
#include "wdef.h"
#else
#if defined(BDA_ABAL2)
#include "wdef.h"
#else
#include "bda.h"
#endif
#endif

#include <string.h>
#include <stdio.h>

#include "jstdpsu.h"
#include "jguipix.h"
#include "zext.h"
#include "zint.h"
#include "zintctx.h"

#if defined(BDA_WIN32)
// Extrait de rgraphapi.h
// on ne peut pas utiliser cet include car il y a conflit avec jguipix.h
// sur des définitions de protoypes
int	load_palette_byexa(char * bptr);
int	put_palette_byexa();
#endif

// ----------------------------------------------------------------------------
// - Headers of modules
// ----------------------------------------------------------------------------
#include "ztrace.h"
#include "zglobal.h"
#include "zglobctx.h"
#include "jimage.h"
#include "ztools.h"
#include "zlook.h"
#include "jguipix.h"

// ----------------------------------------------------------------------------
// - Included C files
// ----------------------------------------------------------------------------
#include "zlooskin.c"
#include "zloopal.c"
#include "zloocomp.c"

