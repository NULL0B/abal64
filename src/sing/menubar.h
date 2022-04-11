
#ifndef _menubar_h
#define _menubar_h

/*	------------------------	*/
/*	m a i n _ m e n u b a r 	*/
/*	------------------------	*/
#include "visual.h"

class	main_menubar : visual_container {
public:
	visual_fill * Auto7127;
	visual_frame * Auto7139;
	visual_button * Auto7138;
	visual_button * FileTrigger;
	visual_frame * Auto7145;
	visual_button * Auto7147;
	visual_button * ViewTrigger;
	visual_button * EventTrigger;
	visual_button * OptionTrigger;

	main_menubar();
	~main_menubar();
	void oncreate();
	virtual void onremove();
	virtual void onshow();
	virtual void onhide();
	virtual word ongetfocus();
	virtual void onlosefocus();
	virtual void onevent();
};

#endif /* _menubar_h */
