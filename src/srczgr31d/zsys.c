// ****************************************************************************
// * zSys.c
// * System module
// ****************************************************************************

// PHL For testing CVS
#define  CI_MODULE_ID   0x0001

#include "wdef.h"

#include <string.h>

#if defined(BDA_TWIN16)
#include <dir.h>
#endif

#include "jstdpsu.h"
#include "jguipix.h"
#include "jguimou.h"
#include "jmouse.h"
#include "jimage.h"
#include "zext.h"
#include "zint.h"
#include "zintctx.h"

// ----------------------------------------------------------------------------
// - Headers of modules
// ----------------------------------------------------------------------------
#include "ztrace.h"
#include "zglobal.h"
#include "zglobctx.h"
#include "vthologi.h" // for zSysSys
#include "vgrhold.h"  // for zSysSys
#include "zgui.h"     // for zSysSys
#include "zlook.h"
#include "ztools.h"
#include "ztext.h"
#include "zsys.h"


// ----------------------------------------------------------------------------
// - Constants
// ----------------------------------------------------------------------------
#define C_RLE 0xFE

// ----------------------------------------------------------------------------
// - Included C files
// ----------------------------------------------------------------------------
#include "zsysglob.c"
#include "zsyspupo.c"
#include "zsyssys.c"
#include "zsysutil.c"

