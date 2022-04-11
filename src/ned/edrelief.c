#ifndef	_vrelief_c
#define	_vrelief_c

#include "palet.h"

static void	relief_box(int atx,int aty, int nbx, int nby, int hl, int bg, int ll )
{
	if ( bg !=  0 )
		filzone(atx,aty,nbx,nby,bg);
	filzone(atx,aty,nbx,1,hl);
	filzone(atx,aty,1,nby,hl);
	filzone((atx+nbx-1),aty,1,nby,ll);
	filzone(atx,(aty+nby-1),nbx,1,ll);
	return;
}

void	relief_line(int atx, int aty, int nbx, int style )
{
	int	rbg=_DEFAULT_GUI_NEUTRAL;
	int	rhl=_DEFAULT_GUI_LIGHT;
	int	rll=_DEFAULT_GUI_DARK;

	switch ( style ) {
		case	2 :
		case	3 :
			filzone(atx,aty,nbx,1,rhl);
			filzone(atx,aty+1,nbx,1,rll);
			break;
		case	1 :
		case	4 :
			filzone(atx,aty,nbx,1,rll);
			filzone(atx,aty+1,nbx,1,rhl);
			break;
		case	0 :
		case	5 :
			filzone(atx,aty,nbx,1,_DEFAULT_GUI_BLACK);
		}
	return;
}

static void	relief_frame(int atx,int aty, int nbx, int nby, int style )
{
	int	rbg=_DEFAULT_GUI_NEUTRAL;
	int	rhl=_DEFAULT_GUI_LIGHT;
	int	rll=_DEFAULT_GUI_DARK;

	switch ( style ) {
		case	1 :
			relief_box(atx,aty,nbx,nby,rhl,rbg,rll);
			break;
		case	2 :
			relief_box(atx,aty,nbx,nby,rll,rbg,rhl);
			break;
		case	3 :
			relief_box(atx,aty,nbx,nby,rhl,rbg,rll);
			relief_box(atx+2,aty+2,nbx-4,nby-4,rll,0,rhl);
			break;
		case	4 :
			relief_box(atx,aty,nbx,nby,rll,rbg,rhl);
			relief_box(atx+2,aty+2,nbx-4,nby-4,rhl,0,rll);
			break;

		case	5 :
			relief_box(atx,aty,nbx,nby,_DEFAULT_GUI_BLACK,_DEFAULT_GUI_WHITE,_DEFAULT_GUI_BLACK);
			break;
		}
}

#endif	/* _vrelief_c */



