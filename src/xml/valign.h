
#ifndef _valign_h
#define _valign_h

/*	----------------------------------------------	*/
/*	a c c e p t _ c a m e r a _ a l i g n m e n t 	*/
/*	----------------------------------------------	*/
#include "visual.h"

class	accept_camera_alignment : visual_container {
public:
	visual_window * Auto1575;
	visual_text * Auto1581;
	visual_frame * Auto1576;
	visual_button * Auto1583;
	visual_radio * Primary;
	visual_button * Auto1585;
	visual_radio * Primary;
	visual_radio * Primary;

	accept_camera_alignment();
	~accept_camera_alignment();
	void oncreate();
	virtual void onremove();
	virtual void onshow();
	virtual void onhide();
	virtual word ongetfocus();
	virtual void onlosefocus();
	virtual void onevent();
};

#endif /* _valign_h */
