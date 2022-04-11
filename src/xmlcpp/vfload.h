
#ifndef _vfload_h
#define _vfload_h

/*	------------------------------	*/
/*	a c c e p t _ f o n t l o a d 	*/
/*	------------------------------	*/
#include "vclass.h"
#include "visual.h"
#include "singprot.h"

#undef public

extern "C" {
struct data_accept_fontload {
		char * pFileName;
		char * pConvIso;
		};
};

class	class_accept_fontload : public class_visual_container {
public:
	class_visual_window *Auto3377_OBJ;
	class_visual_text *Auto3378_OBJ;
	class_visual_edit *FileName_OBJ;
	class_visual_select *ConvIso_OBJ;
	class_visual_button *Auto3379_OBJ;
	class_visual_button *Auto3380_OBJ;
	class_visual_button *Select_OBJ;
	class_visual_button *System_OBJ;

	struct data_accept_fontload DataInterface;

	class_accept_fontload(int px=105,int py=210,int ph=180,int pw=590,int pfg=1,int pbg=0,class_visual_font *pfontclass=(class_visual_font *)0,class_visual_container *ppere=NULL,int pfocus=1,class_visual_object *pprevious=NULL,int pmovable=1);
	~class_accept_fontload();
	int Auto3377_action();
	int Auto3379_event();
	int Auto3380_event();
	int Select_event();
	int System_event();

	int FileName_help();
	int Auto3379_help();
	int Auto3380_help();
	int Select_help();
	int System_help();

	int OnCreate();
	int OnShow();
	int OnEvent();
	int OnFocus();
	int OnHide();
	int OnRemove();
	int OnLoseFocus();
	int TransfertIn();
	int TransfertOut();
	int InitialiseStructure(
		char * pFileName,
		char * pConvIso);
	int OnCreateAndExec(
		char * pFileName,
		char * pConvIso);
	int OnExec();

	int stdinput();
};

#define public

#endif /* _vfload_h */
