#ifndef	_sing_h
#define	_sing_h

/*	------------------------------------------	*/
/*	OPTION ACTIVATION FOR VARIOUS SYSTEM PORTS	*/
/*	------------------------------------------	*/

#ifdef	UNIX
#define	__SING_FORK
#define	__SING_LDAP
#endif

#ifdef	PROLOGUE
#undef	__SING_FORK
#undef	__SING_LDAP
#endif

#ifdef	WIN32
#undef	__SING_FORK
#undef	__SING_LDAP
#endif

/*	------------------------------------------	*/
/*	------------------------------------------	*/

#include "ctrl.h"
#include "allocate.h"
#include "singname.h"
#include "singtrac.h"

#define macro_get_word(fh,rv) rv = get_word(fh)
#define macro_get_string(fh,rs) rs = get_string(fh)

#define	public	
#define	private	static

struct	image_control	{
	int	x;
	int	y;
	int	width;
	int	height;
	int	depth;
	int	type;
	int	state;
	};

#define	MAXNATLANG		 8

#define	_TEXT_TOOL		 1
#define	_CLASS_TOOL		 2
#define	FONT_MAX		10
#define	FONT_MIN		 1
#define	MAX_IDENTIFIER		64
#define	_MAX_FORM_FIELDS	32

#define	_BASICS			0x0007

#define	_AUTO_PREFIX		"Auto"
#define	_UNQUOTED_STRING	'$'
#define	_FORMAT_PREFIX		'('

#define	_DOCUMENTATION		0x0008
#define	_BASEORDER		0x0010
#define	_DEPENDANCE		0x0020
#define	_EXTENDED_EVENTS	0x0040
#define	__WIDGET_TYPE		0x0080	
#define	_METHOD_FILE		0x0100
#define	_LABEL_FRAME		0x0200
#define	_WIDGET_TRIGERS		0x0400
#define	_WIDGET_FORMAT 		0x0800
#define	_INTERNATIONAL 		0x1000
#define	_MULTILINGUAL  		0x2000

struct font_control {
	int	state;
	int	width;
	int	height;
	};

struct	standard_clipboard	{
	int	width;
	int	height;
	int	w_cell;
	int	h_cell;
	char *	storage;
	};

struct	font_context	{

	int	operation;	/* OR, SET, CPY		*/

	int	x;
	int	y;
	int	w;
	int	h;		

	int	bfw;		/* Base font width	*/
	int	bfh;		/* Base font height	*/

	int	ezx;		/* Edit zone xPos 	*/
	int	ezy;		/* Edit zone yPos  	*/
	int	ezw;		/* Edit zone width	*/
	int	ezh;		/* Edit zone height	*/
	int	ezz;		/* Edit Zone page width */

	int	twx;		/* Total Window xPos	*/
	int	twy;		/* Total Window yPos	*/
 	int	tww;		/* Total Window Width	*/
	int	twh;		/* Total Window Height	*/

	int	margin;		/* Font Cell Row Margin	*/

	struct 	standard_clipboard * clipboard;

	int	w_cell;		/* proportional fonts 	*/
	int	h_cell;		/* width and height	*/
	int	x_cursor;	/* visual editor cursor	*/
	int	y_cursor;	/* x and y position	*/	
	int	item;		/* current character  	*/
	int	page;		/* current table page 	*/
	int	font;		/* the font number	*/

	char *	fontname;	/* pointer to the name zone in the file */

	};


#include "singeve.h"
#include "singtree.h"

struct	window_control	{
				/* ------------------------------------ */
	int	style;		/* Type of Widget : Button/Edit etc	*/
	int	x;		/* Top left corner 	X		*/
	int	y;		/*		and	Y coordinates	*/
	int	w;		/* Item Size vector 	Width		*/
	int	h;		/* 	and		Height		*/
	int	colour;		/* Forground | Background		*/
	int	size;		/* Length of payload text (characters)	*/
	int	font;		/* Text Font Number			*/
	int	align;		/* 0,1,2,3 NO/LEFT,RIGHT/CENTER		*/
	int	interfaceitem;	/* is part of public interfaceitem		*/

	int	special;	/* extra function flag			*/

	struct	event_control events;

	int	datatype;	/* New widget data type code		*/
	char *	name;		/* Name of entity, Auto or Specific	*/
	char *	payload;	/* Primary text payload			*/
	char *	messages[MAXNATLANG];	/* Alternative national payloads	*/
	char *  format;		/* ABAL data format string		*/
	void *	extra;		/* Secondary Image payload		*/
				/* ------------------------------------ */
				/* The following are for Generation	*/
				/* ------------------------------------ */
	int	focus;		/* Focus ID for Event and Focus Control	*/
	int	page;		/* Page ID for Tabview control		*/
	int	radio;		/* Radio Number 			*/
				/* ------------------------------------ */
	int	adjust;		/* Indent of Tab from Frame Left Margin	*/
	int	xlimit;		/* Width  of Tab from adjusted start	*/
	int	ylimit;		/* Height of Tab from Top Edge		*/
				/* ------------------------------------ */
	int	trigger;	/* HotKey trigger to a select/execute	*/
				/* ------------------------------------ */
	char *	stylesheet;	/* Style expression 			*/
	void *	linkage;	/* File Linkage Pointer			*/
				/* ------------------------------------ */
	char *	hint;

	};

struct	zoom_control	{
	struct window_control * window;
	struct standard_image * image;
	int			colindent;
	int			rowindent;
	int			factor;
	};

struct	form_item	{
	struct window_control Contents;
	struct form_item 	* 	next;
	struct form_item 	* 	previous;
	struct treeview  	* 	treenode;
	struct form_control	*	parent; 
	int		  doctool;
	char		* document[MAXNATLANG];
	int		shitem;
	int		shatx;
	int		shaty;
	int		number;
	int		unique;
	};
	

#include "singform.h"
#include "singmod.h"
#include "vwidget.h"

struct	scroll_control	{
	int	focus;
	int	vpo;	/* virtual page offset 	*/
	int	vps;	/* virtual page size   	*/
	int	vpl;	/* virtual page limit  	*/
	int *	rpo;	/* real page offset 	*/
	int	rps;	/* real page size  	*/
	int	rpl;	/* real page limit 	*/
	int	sbp;	/* scroll bar position	*/
	};

#include "threed.h"

struct	scroller3d	{
	struct		coordinate3d * value;
	int		focus;
	int		plane;
	int		limit;
	int		max;
	};


struct	screen_control	{
	int	OutOfDate;
	int	compiling;
	int	alignment;
	int	numbering;
	int	language;
	int	imageformat;
	int	thickness;
	char *	gridbuffer;
	int	gridwidth;
	int	gridheight;
	int	gridlockw;
	int	gridlockh;
	int	usingtool;
	int	usage;
	int	style;
	int	width;
	int	height;
	int	currentfont;
	int	basefont;
	int	menufont;
	int	tinyfont;
	int	treefont;
	int	treefontwidth;
	int	treefontheight;
	int	fontheight;
	int	fontwidth;
	int	fontitem;
	int	foreground;
	int	background;
	int	lockon;
	int	transparent;
	int	ismodal;
	int	imagepathitem;
	int	dropon;

	int	AutoSave;

	struct	form_item *	UndoList;

	struct font_control   FontTable[FONT_MAX];

	struct window_control Cursor;
	struct window_control Item;
	struct window_control Tool;
	struct window_control ToolBar;
	struct window_control StatusBar;
	struct window_control ScrollBar;
	struct window_control Palette;
	struct window_control MenuBar;
	struct window_control DeskTop;
	struct window_control TreeView;
	int		      EditView;
	struct treeview *     Tree;
	struct treeview *     TreeTop;
	struct treeview *     TreeFocus;

	struct scroller3d     Scroll3d;
	
	struct scroll_control TSB;
	struct scroll_control VSB;
	struct scroll_control HSB;

	struct	tool_node	* ToolManager;
	struct	model_node	* ModelHeap; 
	struct	form_item	* Widgets;

	struct	zoom_control	* Zoom;
	struct	font_context	* FontContext;
	struct	form_control	* Form;
	struct	file_control	* File;
	struct	menu_control	* Menu;
	struct	standard_class	* Class;
	struct	camera3d 	* Camera;
	struct 	image_control  	  Image;

	int		RelativeFonts;

	char	*	paper_types;
	char	*	string_buffer;
	char	*	file_path[WIDGET_FILE_LIMIT];
	char	*	string_buffer_length;
	char	*	form_message_buffer;

	void	*	MainMenuContext;
	void	*	ThreedCursor;
	void	*	StatusObject;
	void	*	Introduction;

	};


public	char * check_payload( char * vptr );

#endif	/* _sing_h */


