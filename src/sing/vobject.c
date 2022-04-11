#ifndef	_VOBJECT_C
#define	_VOBJECT_C

#include <stdio.h>

#if defined(WIN32)
#include "bda.h"
#ifndef	BPTR
#define	BPTR BYTE FAR PTR
#endif
#ifndef	WPTR
#define	WPTR WORD FAR PTR
#endif
#ifndef	LPTR
#define	LPTR LONG FAR PTR
#endif
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "wincicoapi.h"
char *confgetenv( const char *varname );
#endif

#ifdef WIN32
#include "rgraphapi.h" //FCH
#include "fnparser.h" //FCH
#include "visual.h" //FCH
#else
#include "vcico.h"
#endif
#include "palet.h"
#include "guimouse.h"
#include "valign.h"

#ifdef WIN32
#include "vobjapi.h"
#else
#include "singpix.h"
#endif

#include "valloc.c"

#define	_SYSTEM_IMAGES
#include "sysimage.h"
#include "stdimage.h"

#define	public
#define	private	static

int	err_val=0;

#include "vmouse.c"
#ifndef WIN32
#include "visual.h"
#endif
#include "vobject.h"

extern	vgapalette( char * pptr, int i, int j );
void	put_palette();

#include "vconf.c"

private	int	_national_language=0;	/* default english */

public	int	national_language()	{	return( _national_language );	}

int	transparent=0;
int	standard_black		=_DEFAULT_GUI_BLACK;
int	standard_lolight	=_DEFAULT_GUI_DARK_LOW;
int	standard_lomid		=_DEFAULT_GUI_DARK;
int	standard_backwash	=_DEFAULT_GUI_NEUTRAL;
int	standard_himid		=_DEFAULT_GUI_LIGHT;
int	standard_hilight	=_DEFAULT_GUI_LIGHT_HIGH;
int	standard_white		=_DEFAULT_GUI_WHITE;
int	standard_text		=_DEFAULT_GUI_FG_TITLE;
int	standard_title		=_DEFAULT_GUI_BG_TITLE;
int	standard_focus		=_DEFAULT_GUI_FOCUS;
int	standard_grayed		=_DEFAULT_GUI_GRAYED;

#ifdef WIN32
#include "vtype.c"
#include "vprod.c"
#endif
#include "vview.c"
#include "vbuffer.c"
#include "vtrinout.c"
#include "vfont.c"
#include "vwait.c"
#include "vgetch.c"
#include "vcolour.c"
#include "vrelief.c"
/* #include "vcircle.c" */
#include "velipse.c"
#include "vtext.c"
#include "vedit.c"
#include "vhelp.c"
#include "vconcave.c"
#include "vconvex.c"
#include "varrow.c"
#include "vbutton.c"
#include "vselect.c"
#include "vscroll.c"
#include "vwindow.c"
#include "vprogres.c"
#include "vtabpage.c"
#include "vipath.c"
#include "vpalet.c"
#include "vframe.c"
#include "vinit.c"
#include "vterm.c"
#include "vfilzone.c"
#include "vimages.c"
#include "vcheck.c"
#include "vswitch.c"
#include "vgraph.c"
#include "vradio.c"
/* #include "vline.c" */
#include "vtable.c"
#include "vrotate.c"
#ifdef WIN32
IJM/BG 3/8/2006  il ne faut plus mettre ceci ici il faut le mettre dans audio  
IJM/BG 3/8/2006  il ne faut plus mettre ceci ici il faut le mettre dans audio 
IJM/BG 3/8/2006  il ne faut plus mettre ceci ici il faut le mettre dans audio  
#include "vsound.c"
IJM/BG 3/8/2006  il ne faut plus mettre ceci ici il faut le mettre dans audio
IJM/BG 3/8/2006  il ne faut plus mettre ceci ici il faut le mettre dans audio
IJM/BG 3/8/2006  il ne faut plus mettre ceci ici il faut le mettre dans audio
IJM/BG 3/8/2006  il ne faut plus mettre ceci ici il faut le mettre dans audio
#endif

#endif	/* _VOBJECT_C */

