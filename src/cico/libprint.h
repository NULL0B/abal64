#ifndef	_libprint_h
#define	_libprint_h

#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>

#if unix || M_XENIX

#include <fcntl.h>
#include <unistd.h>
#include <termio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <utmp.h>

#ifdef NEW_TEMPO

#ifdef AIX_VERS
#if !defined(UNIXWARE) && !defined(SPARC) && !defined(AVIION) && !defined(LINUX)
#include <sys/time.h>
#endif
#else  /* AIX_VERS */
#ifdef LINUX
#include <sys/time.h>
#else
#include <sys/itimer.h>
#endif
#endif /* AIX_VERS */

#endif /* NEW_TEMPO */

#endif /* unix || M_XENIX */

#ifdef vms
#include <unixio.h>
#include <file.h>
#include <types.h>
#endif /* vms */

#define UPDATE	"$Date: 2006/07/28 11:40:44 $"

#define ALSMID "libprint"
#include "allocate.h"

#ifdef CICO_BDA
//#include "bda_std.h"
#endif /* fin CICO_BDA */

#ifdef ASFCICO
#include "asfcico.h"
#endif /* ASFCICO */

#include "_type.h"
#include "_cico.h"
#include "cico.h"

#include "ixconst.h"
#include "ixlo.h"

#include "exerrcodes.h"

#endif	/* _libprint_h */

