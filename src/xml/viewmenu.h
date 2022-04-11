
#ifndef _viewmenu_h
#define _viewmenu_h

/*	------------------------------------	*/
/*	s t a n d a r d _ v i e w _ m e n u 	*/
/*	------------------------------------	*/
#include "visual.h"
#include "singmenu.h"

class	standard_view_menu : visual_container {
public:
	visual_fill * Auto1605;
	visual_button * Auto1607;
	visual_button * Auto1609;
	visual_button * Auto1610;
	visual_button * Auto1611;
	visual_button * Auto1612;
	visual_button * Auto1629;
	visual_button * Auto1631;
	visual_button * Auto1613;
	visual_button * Auto1614;

	standard_view_menu();
	~standard_view_menu();
	void oncreate();
	virtual void onremove();
	virtual void onshow();
	virtual void onhide();
	virtual word ongetfocus();
	virtual void onlosefocus();
	virtual void onevent();
};

#endif /* _viewmenu_h */
