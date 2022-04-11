#define ABAL_EXA
#define ABAL_OTR
#ifdef UNIX
#define _FILESEEK_C	/* Inhibits use of FILESEEK alternative (large) */
#endif
#ifdef DOS
#define _FILESEEK_C	/* Inhibits use of FILESEEK alternative (large) */
#endif
#include "buffers.c"

