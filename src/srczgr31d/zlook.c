/** @pkg Staff.Fred.zLook */ 
// ****************************************************************************
// * zLook.c
// * Look module
// ****************************************************************************

#define CI_MODULE_ID 0x0040

#include "wdef.h"

#include <string.h>
#include <stdio.h>

#include "jstdpsu.h"
#include "jguipix.h"
#include "zext.h"
#include "zint.h"
#include "zintctx.h"

// ----------------------------------------------------------------------------
// - Headers of modules
// ----------------------------------------------------------------------------
#include "ztrace.h"
#include "zglobal.h"
#include "zglobctx.h"
#include "jimage.h"
#include "ztools.h"
#include "zlook.h"

// ----------------------------------------------------------------------------
// - Included C files
// ----------------------------------------------------------------------------
#include "zlooskin.c"
#include "zloopal.c"
#include "zloocomp.c"

