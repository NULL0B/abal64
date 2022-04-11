
#ifndef _vmethod_h
#define _vmethod_h

/*	--------------------------	*/
/*	a c c e p t _ m e t h o d 	*/
/*	--------------------------	*/
#include "visual.h"

class	accept_method : visual_container {
public:
	visual_window * Window;
	visual_tabpage * Head;
	visual_text * auto445;
	visual_text * auto446;
	visual_text * Auto665;
	visual_text * auto448;
	visual_text * auto449;
	visual_edit * Identity;
	visual_edit * ReturnType;
	visual_select * Nature;
	visual_edit * Parameters;
	visual_tabpage * Base;
	visual_text * Auto664;
	visual_edit * Order;
	visual_tabpage * BodyPage;
	visual_edit * Body;
	visual_button * Accept;
	visual_button * Cancel;
	visual_check * Public;
	visual_check * auto498;
	visual_check * Virtual;
	visual_check * Overload;
	visual_button * Editer;

	accept_method();
	~accept_method();
	void oncreate();
	virtual void onremove();
	virtual void onshow();
	virtual void onhide();
	virtual word ongetfocus();
	virtual void onlosefocus();
	virtual void onevent();
};

#endif /* _vmethod_h */
