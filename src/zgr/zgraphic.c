// ****************************************************************************
// * zGraphic.c
// * Graphic module
// ****************************************************************************

#define  CI_MODULE_ID   0x0002

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

#include "zext.h"
#include "zint.h"
#include "zintctx.h"
#include "jimage.h"
#include "jguipix.h"

// ----------------------------------------------------------------------------
// - Headers of modules
// ----------------------------------------------------------------------------
#include "ztrace.h"
#include "zglobal.h"
#include "zglobctx.h"
#include "zsys.h"
#include "ztools.h"
#include "zgraphic.h"
#include "vthobbmp.h"
#include "vthologi.h"
#include "jguimou.h"

// ----------------------------------------------------------------------------
// - Included C files
// ----------------------------------------------------------------------------
#include "zgraglob.c"
#include "zgraimg.c"
#include "zgradraw.c"


