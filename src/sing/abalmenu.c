#ifndef	_abalmenu_c
#define	_abalmenu_c

#include <stdio.h>
#include "sing.h"
#include "palet.h"
#include "stdpsu.h"
#include "guimouse.h"
#include "singrel.h"
#include "singpix.h"
#include "allocate.h"
#define	_SYSTEM_IMAGES
#include "sysimage.h"
#include "stdimage.h"
#include "singlang.h"
#include "singedit.h"
#include "singprod.h"
#include "singpage.h"
#include "singpars.h"

#include "singpal.h"
#include "singbar.h"
#include "singmenu.h"
#include "singtool.h"
#include "singtext.h"
#include "singimg.h"
#include "singdesk.h"

#include "vconf.h"
#include "visual.h"
#include "singconf.h"
#include "singabal.h"

extern	char * keyword_include;
extern	char * keyword_user;
extern	char * keyword_this;

extern	char	namebuffer[];
extern	char	workbuffer[];
extern	struct	screen_control	Context;
extern	char *	font_name[];
extern	int	TargetBiosMode;
extern	int	WindowCol;
extern	int	WindowRow;

#define	_STANDARD_RGB	system_palette

#include "singtool.h"

#include "abalkeys.c"

public  void	export_abal_menu( FILE * h )
{
	char	*	fname;
	struct form_item * iptr;
	int	i;
	char	* cname;
	int	members=0;

	Abal_Config.generate_overlay = Context.Menu->isoverlay;
	Abal_Config.generate_program = Context.Menu->isprogram;

	Abal_Config.page_control       = 0;

	if (!( cname = Context.Menu->identifier ))
		cname = "menu_box";
	else if (!( *cname ))
		cname = "menu_box";

	/* Generate Inclusions for Program */
	/* ------------------------------- */
	if ( Abal_Config.generate_program ) {

		cname = "on";
		
		}

	return;
}

#endif /* _abalmenu_c */

#include "abalfile.c"


