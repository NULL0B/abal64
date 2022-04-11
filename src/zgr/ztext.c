// ****************************************************************************
// * zText.c
// * TEXT module
// ****************************************************************************

#define  CI_MODULE_ID   0x0008

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
#include "grapil.h"
#include "zext.h"
#include "zint.h"
#include "zintctx.h"

#if defined(BDA_WIN32)
// Extrait de rgraphapi.h
// on ne peut pas utiliser cet include car il y a conflit avec jguipix.h
// sur des définitions de prototypes
int	standard_load_font_with_fid( int fid, char * fontname ); /*FCH22082005 compatibility ZGR */
int	standard_drop_font( int fontid );
int	guifontsize(int id);
int	guifontsize_without_linespacing(int id); /*FCH22082005 compatibility ZGR */
int	guifontoffset(int id); /*FCH22082005 compatibility ZGR */
int	loadguifont_os_dependant(int id, char * bptr, int blen);
#endif

// ----------------------------------------------------------------------------
// - Headers of modules
// ----------------------------------------------------------------------------
#include "zlook.h"
#include "ztrace.h"
#include "zglobal.h"
#include "zglobctx.h"
#include "vthologi.h"
#include "ztools.h"
#include "zsys.h"
#include "ztext.h"

// ----------------------------------------------------------------------------
// - Included C files
// ----------------------------------------------------------------------------

#include "ztexfont.c"
#include "ztexprin.c"
#include "ztexsta.c"
#include "ztexfgbg.c"

