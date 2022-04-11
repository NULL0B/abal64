#ifndef	_vframe_h
#define	_vframe_h 

struct	select_control	{
	int	current;
	int	limit;
	int  *	result;
	char *	storage;
	char **	messages;
	int  *	itemreel;
	};

#ifdef __cplusplus	/* GWB le 05/06/207 */
extern "C" {
#endif

public	struct	select_control * parse_selection(char * message, int * item );

#ifdef __cplusplus	/* GWB le 05/06/207 */
}
#endif

#define	_VFILL_MASK		0x031F

#define	_FILL_FRAME		0
#define	_OUTSET_FRAME		1
#define	_INSET_FRAME		2
#define	_RIDGE_FRAME		3
#define	_GROOVE_FRAME		4
#define	_EDIT_FRAME		5
#define	_TEXT_FRAME		6
#define	_IMAGE_FRAME		7
#define	_LINE_FRAME		8
#define	_BUTTON_FRAME		9
#define	_WINDOW_FRAME		10
#define	_TAB_FRAME		11

#define	_CHECK_FRAME		12
#define	_RADIO_FRAME		13
#define	_SELECT_FRAME		14
#define	_FORM_FRAME		15

#define	_SCROLL_FRAME		16
#define	_PROGRESS_FRAME		17

#define	_SWITCH_FRAME		18
#define	_GRAPH_FRAME		19
#define	_DATA_FRAME		20
#define	_CUT_FRAME		21
#define	_MOVE_FRAME		22
#define	_MENU_FRAME		23
#define	_SIZE_FRAME		24
#define	_CURSOR_FRAME		25
#define	_CIRCLE_FRAME		26
#define	_DISC_FRAME		27
#define	_PEN_FRAME		28
#define	_PIPE_FRAME		29
#define	_POUR_FRAME		30
#define	_OUTLINE_FRAME		31
#define	_TABLE_FRAME		32
#define	_HMENU_FRAME		33

#define	_TITLE_FRAME		0x0040
#define	_FRAME_TYPE		0x003F
#define	_FRAME_NOHIDE		0x1000
#define	_FRAME_TRANSPARENT	0x0100
#define	_FRAME_INSIDE		0x0200
#define	_ALLOCATED_EXTRA	0x2000

#define	_VARIABLE_FRAME		0
#define	_OBJECT_FRAME		1
#define	_VISUAL_FRAME		2
#define	_SIFILE_FRAME		3
#define	_MCFILE_FRAME		4
#define	_VMEMORY_FRAME		5
#define	_SQFILE_FRAME		6
#define	_DBFILE_FRAME		7

#define	AbalGetWord( bptr ) (((*((BPTR)bptr) & 0x00FF) << 8) | ( *(((BPTR)bptr)+1) & 0x00FF))
#define	AbalPutWord( bptr, v ) { \
	*((BPTR)bptr)     = (v >> 8); \
	*(((BPTR)bptr)+1) = (v & 0x00FF); \
	}

#define	standard_loblack   	(standard_black | (standard_lolight << 8))
#define	standard_miblack   	(standard_lolight | (standard_lomid << 8))
#define	standard_hiblack   	(standard_lomid | (standard_backwash << 8))
#define	standard_lowhite  	(standard_himid | (standard_backwash << 8))
#define	standard_miwhite  	(standard_hilight | (standard_himid << 8))
#define	standard_hiwhite  	(standard_white | (standard_hilight << 8))

#endif	/* _vframe_h */

