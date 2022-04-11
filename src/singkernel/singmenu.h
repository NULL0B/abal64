#ifndef	_singmenu_h
#define	_singmenu_h

/*	Menu Return Function Codes	*/
/*	--------------------------	*/

#include "vnatlang.h"

#define	_TOGGLE_PALETTE		0x0010		/* Ctrl P 	*/
#define	_TOGGLE_STATUSBAR	0x0013		/* Ctrl S 	*/
#define	_TOGGLE_TOOLBAR		0x0014		/* Ctrl T 	*/
#define	_TOGGLE_MENUBAR		0x0015		/* Ctrl U 	*/

/*	Option Toggles		*/
/*	--------------		*/
#define	_TOGGLE_TOOL		'TT'
#define	_TOGGLE_LOCK		'TL'
#define	_TOGGLE_GRID		'TG'
#define	_TOGGLE_IMAGE		'TI'		
#define	_TOGGLE_IDENTITY	'TN'
#define	_TOGGLE_CONSTRUCT	'TC'

/*	Form Menu 	*/
/*	---------	*/
#define	_FORM_PARA		'FF'
#define	_FORM_ORDER		'FO'		
#define	_FORM_NUMBER		'FR'	
#define	_FORM_TRIGGER		'FT'
#define	_FORM_FACE		'FZ'
#define	_FORM_UNDO		'FU'

/*	Text Editor Menu	*/
/*	----------------	*/
#define	_TEXT_FIND		'TF'
#define	_TEXT_SEARCH		'TS'

/*	Widget menu */

#define	_WIDGET_MSG 		'WM'
#define	_WIDGET_HELP 		'WH'
#define	_WIDGET_FORM 		'WR'
#define	_WIDGET_FONT		'WF'
#define	_WIDGET_TYPE		'WY'
#define	_WIDGET_ALIG		'WS'
#define	_WIDGET_BACK		'WW'
#define	_WIDGET_FORE		'WT'
#define	_WIDGET_AUTO		'WA'
#define	_WIDGET_COND		'WC'
#define	_WIDGET_COPY 		'WK'		
#define	_WIDGET_PASTE		'WP'		
#define	_WIDGET_BOLD 		'WB'		
#define	_WIDGET_SHADOW		'WD'		
#define	_WIDGET_ULINE		'WU'		
#define	_WIDGET_LOCK 		'WL'		
#define	_WIDGET_UNLOCK 		'WO'		
#define	_WIDGET_FIND   		'WX'		
#define	_WIDGET_DELETE		'WZ'

/*	File Menu		*/
/*	---------		*/
#define	_FILE_NEW		'FN'
#define	_FILE_LOAD		'FL'
#define	_FILE_DROP		'FD'
#define	_FILE_SAVE		'FS'
#define	_FILE_QSAVE		'FQ'
#define	_FILE_PRODUCE		'FP'
#define	_FILE_COMPARE		'FC'
#define	_FILE_IMPORT		'FI'
#define	_FILE_IMAGE		'FG'
#define	_FILE_MERGE		'FM'

/*	Editor Menu		*/
/*	-----------		*/
#define	_VIEW_IMAGE		'VI'
#define	_VIEW_TEXT		'VT'
#define	_EDIT_IMAGE		'EI'
#define	_EDIT_TEXT 		'ET'
#define	_EDIT_FONT 		'EF'
#define	_EDIT_PROPERTIES	'EP'
#define	_EDIT_FORM		'EM'
#define	_EDIT_DATABASE		'DB'
#define	_EDIT_TREEVIEW		'TV'
#define	_EDIT_CLASS   		'EC'
#define	_EDIT_GRAPH		'EG'
#define _EXEC_PROG		'XP'

/*	Event Method Menu	*/
/*	-----------------	*/
#define	_EVENT_ITEMDOC 		'YI'
#define	_EVENT_FORMDOC 		'YD'
#define	_EVENT_CREATE		'YC'
#define	_EVENT_REMOVE		'YR'
#define	_EVENT_SHOW  		'YS'
#define	_EVENT_HIDE  		'YH'
#define	_EVENT_FOCUS 		'YF'
#define	_EVENT_LOSE  		'YL'
#define	_EVENT_EVENT 		'YE'

#include "singalig.h"

#define	_MALIGN_LEFT		'AL'
#define	_MALIGN_CENTER		'AC'
#define	_MALIGN_JUSTIFY		'AJ'
#define	_MALIGN_RIGHT		'AR'
#define	_MALIGN_TOP		'AT'
#define	_MALIGN_MIDDLE		'AM'
#define	_MALIGN_BOTTOM		'AB'
#define	_MALIGN_NONE		'AN'

/*	IMAGE Production 	*/
/*	----------------	*/
#define	_CHOOSE_BMP		'IB'
#define	_CHOOSE_GIF		'IG'
#define	_CHOOSE_JPEG		'IJ'

/*	SOURCE Production 	*/
/*	-----------------	*/
#define	_CHOOSE_C		'LC'
#define	_CHOOSE_CPP		'LP'
#define	_CHOOSE_BAL		'LB'
#define	_CHOOSE_ABAL		'LA'
#define	_CHOOSE_HTML		'LH'
#define	_CHOOSE_JAVA		'LJ'

/*	FONT Selection 		*/
/*	--------------		*/
#define	_TEXT_FONT1		'F1'
#define	_TEXT_FONT2		'F2'
#define	_TEXT_FONT3		'F3'
#define	_TEXT_FONT4		'F4'
#define	_TEXT_FONT5		'F5'
#define	_TEXT_FONT6		'F6'
#define	_TEXT_FONT7		'F7'
#define	_TEXT_FONT8		'F8'
#define	_TEXT_FONT9		'F9'

/*	THREE D MENU SELECTION 	*/
/*	----------------------	*/
#define	__3D_CAMERA	'3C'
#define	__3D_IMAGE 	'3X'
#define	__3D_MENU	'3M'
#define	__3D_CLASS	'3K'
#define	__3D_FORM	'3A'
#define	__3D_LIBRARY	'3L'
#define	__3D_PROJECT	'3P'
#define	__3D_FILE	'3I'
#define	__3D_CALC	'3Z'
#define	__3D_FORWARD	'3F'
#define	__3D_BACK	'3B'
#define	__3D_LEFT	'3Y'
#define	__3D_RIGHT	'3R'
#define	__3D_UP		'3U'
#define	__3D_DOWN 	'3D'
#define	__3D_ALIGN	'3E'
#define	__3D_TEXT 	'3T'
#define	__3D_TRANSLATE	'3N'
#define	__3D_HELP	'3H'
#define	__3D_FILEMAN	'3Q'

/*	CLASS MENU SELECTION	*/
/*	--------------------	*/
#define	__ADD_CONSTANT		'MC'
#define	__ADD_DATA		'MD'
#define	__ADD_METHOD  		'MM'
#define	__CLASS_PROPERTIES  	'CP'

/*	Menu Menu Selection	*/
/*	-------------------	*/
#define	__MENU_OPTION		'MO'
#define	__MENU_PROPERTIES 	'MP'
#define	__MENU_SEPARATOR	'MS'


/*	ZOOM / IMAGE SELECTION	*/
/*	----------------------	*/
#define	_ZOOM_ROTATE1	'Z1'
#define	_ZOOM_ROTATE2	'Z2'
#define	_ZOOM_ROTATE3	'Z3'
#define	_ZOOM_COLOUR 	'ZZ'
#define	_ZOOM_REFLECTX	'ZX'
#define	_ZOOM_REFLECTY	'ZY'
#define	_ZOOM_CHANGE 	'ZC'
#define	_ZOOM_GREY	'ZG'
#define	_ZOOM_COPY   	'ZO'
#define	_ZOOM_PASTE  	'ZP'
#define	_ZOOM_CUT  	'ZK'


#define	_GRID_PLUS		'+'
#define	_GRID_LESS		'-'		

#define	_THICK_PLUS		'*'
#define	_THICK_LESS		'/'		

#define	_LEAVE_SING		0x1B1B
#define	_DISPLAY_REFRESH	'DR'
#define	_SCROLL_V		'SV'
#define	_SCROLL_H		'SH'

#define	_DELETE_ITEM		0x007F		/* Delete 	*/
#define	_PREVIOUS_ITEM		0x0008		/* Back	  	*/
#define	_NEXT_ITEM		0x0006		/* Forward	*/
#define	_FIRST_ITEM		0x001C		/* Home   	*/
#define	_LAST_ITEM		0x0002		/* End    	*/
#define	_USE_ITEM		0x000D		/* Enter	*/

#include "singprot.h"

#endif	/* _singmenu_h */
	/* ----------- */

