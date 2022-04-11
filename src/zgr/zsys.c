// ****************************************************************************
// * zSys.c
// * System module
// ****************************************************************************

// PHL For testing CVS
#define  CI_MODULE_ID   0x0001

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

#if defined(BDA_TWIN16)
#include <dir.h>
#endif

#if defined(BDA_WIN32)
#include <direct.h> // for zsysutil.c
#endif

#if defined(BDA_UNIX)
#include <stdlib.h> // for zsyssys.c
#endif

#include "jstdpsu.h"
#include "jguipix.h"
#include "jguimou.h"
#include "jmouse.h"
#include "jimage.h"
#include "zext.h"
#include "zint.h"
#include "zintctx.h"

#if defined(BDA_WIN32)
#include "wincicoapi.h"
#include "utilzgrmain.h"
#endif

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
// - Macros
// ----------------------------------------------------------------------------
#if defined(BDA_WIN32)
#define Portable_getenv(a)  ((char*)( IsUtilActivated() ? Getenv_from_exa((a)) : 0))

#elif defined(BDA_UNIX)
#define Portable_getenv(a)  (getenv((a)))

#else
#define Portable_getenv(a)  (0)

#endif

// ----------------------------------------------------------------------------
// - Included C files
// ----------------------------------------------------------------------------
#include "zsysglob.c"
#include "zsyspupo.c"
#include "zsyssys.c"
#include "zsysutil.c"

