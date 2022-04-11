// ****************************************************************************
// * zGui.c 
// * GUI module
// ****************************************************************************

#define  CI_MODULE_ID   0x0004

#include "wdef.h"

#include <string.h>

#include "mouse.h" // from mouse.obj
#include "jstdpsu.h"
#include "jguipix.h"
#include "jguimou.h"
#include "zext.h"
#include "zint.h"
#include "zintctx.h"

// ----------------------------------------------------------------------------
// - Headers of modules
// ----------------------------------------------------------------------------
#include "ztrace.h"
#include "zglobal.h"
#include "zglobctx.h"
#include "zlook.h"
#include "zsys.h"
#include "ztext.h"
#include "zgui.h"
#include "vthobbmp.h"
#include "vthologi.h"
#include "vgrhold.h"

// -----------------------------------------------------------------------------
// - Included C files
// -----------------------------------------------------------------------------
#include "zguiglob.c"
#include "zguibut.c"
#include "zguictrl.c"
#include "zguicurs.c"
#include "zguiinme.c"
#include "zguilist.c"
#include "zguimsgb.c"
#include "zguiwin.c"

