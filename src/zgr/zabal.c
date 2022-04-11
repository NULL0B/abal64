// ****************************************************************************
// * zAbal.c
// * BDA module
// ****************************************************************************

#define  CI_MODULE_ID   0x0001

#if defined(__linux__) || defined(UNIX)
#include "wdef.h"
#include "pubsbda.h"
#include "pubwbda.h"
#else
#if defined(BDA_ABAL2)
#include "wdef.h"
#include "pubsbda.h"
#include "pubwbda.h"
#else
#include "bda.h"
extern LPBDA_INIT rt_init;
#endif
#endif

#include "zext.h"
#include "zint.h"

// ----------------------------------------------------------------------------
// - Headers of modules
// ----------------------------------------------------------------------------
#include "banapi.h"
#include "ztrace.h"
#include "jguipix.h"
#include "zglobal.h"

#ifdef OLD_FASHIONED_WITH_ZAC
#include "zac.h"
#endif

#include "ztext.h"
#include "zgui.h"
#include "zgraphic.h"
#include "zsys.h"

// ----------------------------------------------------------------------------
// - Included C files
// ----------------------------------------------------------------------------
#include "zxpgrver.h"

#include "zabaglob.c"

#if defined	(BDA_UNIX)
#include "jlinuxaccess.c"
#endif

#include "zabahead.c"

