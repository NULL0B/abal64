#ifdef ABAL_CRITERIA
#include "exadsqcr.h"
#endif

#ifdef PROLOGUE
#include "exproprl.h"
#endif

#ifdef WIN16
#include "exprow16.h"
#else
#ifdef WIN32
#include "exprow32.h"
#else
#ifdef DOS
#include "exprodos.h"
#endif
#endif
#endif
#ifdef	USEIT
#include "noprotos.h"
#else
#include "exprotos.h"
#endif

