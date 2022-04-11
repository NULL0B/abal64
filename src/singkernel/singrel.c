#ifndef	_SINGREL_C
#define	_SINGREL_C

#include "singrel.h"
#include "singedit.h"
#include "visual.h"
#include "velement.c"
#include "vobject.h"
#include "vconf.c"
#include "vwait.c"
#include "vfont.c"
#include "vgetch.c"
#include "vrelief.c"
#include "vfilzone.c"
#include "vcolour.c"
#include "vline.c"
#include "vtext.c"
#include "vedit.c"
#include "vhelp.c"
#include "vconcave.c"
#include "vconvex.c"
#include "vbuffer.c"
#include "vtabpage.c"
#include "vipath.c"
#include "vimages.c"
#include "vbutton.c"
#include "varrow.c"
#include "vscroll.c"
#include "vselect.c"
#include "vswitch.c"
#include "vgraph.c"
#include "vcheck.c"
#include "vcircle.c"
#include "velipse.c"
#include "vradio.c"
#include "vtrinout.c"
#include "vmenubox.c"
#include "vpalet.c"
#include "vprogres.c"
#include "vwindow.c"
#include "vtable.c"
#include "vrotate.c"

static	int	xlimit=0;
static	int	ylimit=0;
static	int	uselimits=0;
	
public	void	visual_limits(int xl, int yl )
{
	xlimit = xl;
	ylimit = yl;
	return;
}

public	void	visual_frame( int atx, int aty, int nbx, int nby, int style )
{
	int	bg;
	int	vx,vy;

	if (( nbx > 0 ) && ( nby > 0 )) {

	/* -------------------------------------------------------------------------	*/
	/* Limits have been cancelled since the introduction of lowlevel clipping 	*/
	/* the code has been kept for posterity and things work much better without	*/
	/* especially moving widgets down to the bottom of very large print forms.	*/
	/* IJM : 16/03/2004								*/
	/* -------------------------------------------------------------------------	*/
	if ( uselimits ) {

		if ( atx < 0 ) {
			if ((atx+nbx) < 0) return;
			else	{
				nbx += atx;
				atx = 0;
				}
			}
		else if ( atx >= xlimit ) return;

		else if ( (atx+nbx) >= xlimit )
			nbx = (xlimit-atx);

		if ( aty < 0 ) {
			if ((aty+nby) < 0) return;
			else	{
				nby += aty;
				aty = 0;
				}
			}
		else if ( aty >= ylimit ) return;

		else if ( (aty+nby) >= ylimit )
			nby = (ylimit-aty);

		 }

	switch (( style & _FRAME_TYPE )) {

		case	_CHECK_FRAME :
			visual_check(atx+2,aty+2,nbx-4,nby-4,1,0,0,(char *) 0,0,1);
			break;

		case	_SWITCH_FRAME :
			visual_switch(atx+2,aty+2,nbx-4,nby-4,1,15,2,(char *) "X",1,1);
			break;
		case	_GRAPH_FRAME :
			visual_graph(atx+2,aty+2,nbx-4,nby-4,1,standard_text,standard_backwash,(char *) "visualswitch",12,0);
			break;

		case	_RADIO_FRAME :
			visual_radio(atx,aty,nbx,nby,0,0,0,(char *) 0,0,0,0);
			break;

		case	_BUTTON_FRAME :
			visual_button(atx,aty,nbx,nby,0,0,0,(char *) 0,0,0);
			break;

		case	_TAB_FRAME :
			visual_tabpage(atx,aty,nbx,nby,0,(char *) 0,0,0,2);
			break;

		case	_SCROLL_FRAME :
			visual_scrollbar(  	atx,aty,nbx,nby,
				 	1,0,0, 1,10,20,		0);
			break;

		case	_PROGRESS_FRAME :
			visual_progress(atx,aty,nbx,nby,0,0,0, 4,2, 0);
			break;

		case	_WINDOW_FRAME :
			visual_window(atx,aty,nbx,nby,0,(char *) 0,0,0);
			break;

		case	_FORM_FRAME :
			visual_table(atx,aty,nbx,nby,8,0,0,"A|B|C",(char *) 0,0,(char *) 0);
			break;

		case	_MOVE_FRAME	:
		case	_SIZE_FRAME	:
		case	_CUT_FRAME	:

			if (((vx = ( nbx/2 )) < 4)
			||  ((vy = ( nby/2 )) < 4)) {
				xorzone( atx,aty,nbx,nby, 0x0096 );
				}
			else	{
				vx = vy = 4;
				xorzone( atx,aty,nbx,vy, 0x0096 );
				xorzone( atx,aty,vx,nby, 0x0096 );
				xorzone( atx,((aty+nby)-vy),nbx,vy, 0x0096 );
				xorzone( ((atx+nbx)-vx),aty,vx,nby, 0x0096 );
				}

			break;

		case	_DISC_FRAME	:
		case	_CIRCLE_FRAME	:
			visual_circle(atx,aty,nbx,nby,0x0096,3);
			break;

		case	0	:
			relief(atx,aty,nbx,nby,1,2,3);
			break;

		case	_CURSOR_FRAME :
			xorzone(atx,aty,nbx,nby,0x0069);
			break;

		case	_OUTSET_FRAME :
			if ( style & _FRAME_INSIDE )
				bg = transparent;
			else if ( style & _FRAME_TRANSPARENT )
				bg = transparent;
			else	bg = standard_backwash;
			relief( atx,aty,nbx,nby,standard_hilight,bg,standard_lolight);
			if ( style & _FRAME_INSIDE)
				if (( nbx > 2 ) && ( nby > 2 )) 
					relief( atx+1,aty+1,nbx-2,nby-2,standard_backwash, transparent,standard_backwash);
			break;
		case	_INSET_FRAME  :
			if ( style & _FRAME_INSIDE )
				bg = transparent;
			else if ( style & _FRAME_TRANSPARENT )
				bg = transparent;
			else	bg = standard_backwash;
			relief( atx,aty,nbx,nby,standard_lolight,bg,standard_hilight);
			if ( style & _FRAME_INSIDE)
				if (( nbx > 2 ) && ( nby > 2 ))
					relief( atx+1,aty+1,nbx-2,nby-2,standard_backwash, transparent,standard_backwash);
			break;
		case	_RIDGE_FRAME  :
			if ( style & _FRAME_TRANSPARENT )
				bg = transparent;
			else	bg = standard_backwash;
			relief( atx,aty,nbx,nby,standard_hilight,bg,standard_lolight);
			if (( nbx > 2 ) && ( nby > 2 )) 
				relief((atx+1),(aty+1),(nbx-2),(nby-2),standard_lolight,transparent,standard_hilight);
			break;
		case	_GROOVE_FRAME :
			if ( style & _FRAME_TRANSPARENT )
				bg = transparent;
			else	bg = standard_backwash;
			relief( atx,aty,nbx,nby,standard_lolight,bg,standard_hilight);
			if (( nbx > 2 ) && ( nby > 2 )) 
				relief( (atx+1),(aty+1),(nbx-2),(nby-2),standard_hilight,transparent,standard_lolight);
			break;


		case	_HMENU_FRAME :
			menu(atx,aty,nbx,nby,1);
			break;

		case	_MENU_FRAME :
			menu(atx,aty,nbx,nby,2);
			break;

		case	_SELECT_FRAME :
			visual_select(atx,aty,nbx,nby,1,0,0,(struct select_control *) 0,0);
			break;

		case	_EDIT_FRAME :
			relief( atx,aty,nbx,nby,standard_black,standard_white,standard_black);
			break;


		}
		}
	return;
}

#endif	/* _SINGREL_C */
	/* ---------- */


