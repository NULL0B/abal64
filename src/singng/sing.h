#ifndef	_sing_h
#define	_sing_h

/*	------------------------------------------	*/
/*	OPTION ACTIVATION FOR VARIOUS SYSTEM PORTS	*/
/*	------------------------------------------	*/

#ifdef	UNIX
#define	__SING_FORK
#ifdef	SYSTEM_LDAP
#define	__SING_LDAP
#endif
#endif

#ifdef	PROLOGUE
#undef	__SING_FORK
#undef	__SING_LDAP
#endif

#ifdef	WIN32
#undef	__SING_FORK
#undef	__SING_LDAP
#ifndef P3D32
#define P3D32
#endif
#define EXAWORD unsigned long
#endif

/*	------------------------------------------	*/
/*	------------------------------------------	*/

#include "ctrl.h"
#include "allocate.h"
#include "singname.h"
#include "singtrac.h"
#include "singstyle.h"

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

#include "singnatl.h"

#define	_MAX_ROLLBACK		100
#define	_TEXT_TOOL		 1
#define	_CLASS_TOOL		 2
#define	FONT_MAX		11
#define	FONT_MIN		 1
#define	MAX_IDENTIFIER		64
#include "vform.h"

#define	_BASICS			0x0007
#ifndef	WIN32
#define	_SING_STYLESHEET	"/home/abal3/style/sing.css"
#else
#define	_SING_STYLESHEET	"sing.css"
#endif

#define	_AUTO_PREFIX		"Auto"
#define	_UNQUOTED_STRING	'$'
#define	_FORMAT_PREFIX		'('
#define	_MIMO_WIDGETS		4

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

	struct	event_control * events;
	struct	event_control  abal_events;
	struct	event_control  c_events;

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
	char *	stylesheet;	/* Style expression : for show		*/
	char *	stylefocus;	/* Style expression : for focus		*/
	char *	stylepress;	/* Style expression : for focus		*/
	void *	linkage;	/* File Linkage Pointer			*/
				/* ------------------------------------ */
	char *	hint;
	char *	hmessages[MAXNATLANG];	/* Alternative national hints	*/

	int	interfacenumber;
	int	access;			/* Public or Private		*/
	int	cursor;			/* Edit cursor */
	int	wResize;
	int	hResize;
	int	radiogroup;		/* Radio group number calculated during production */
	int	hash;			/* for speed searching */
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
	int		ismember;	/* For widget collection move lock and other functions */
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
	int	fgrgb[3];
	int	background;
	int	bgrgb[3];
	int	lockon;
	int	transparent;
	int	ismodal;
	int	imagepathitem;
	int	sourcepathitem;
	int	dropon;
	int	AutoSave;

	struct	form_item *	UndoList;

	struct font_control   FontTable[FONT_MAX+1];

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
	int		      DataView;
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
	int		string_buffer_length;
	char	*	form_message_buffer;

	int		MenuActive;
	int		BarActive;
	void	*	MainMenuContext;
	void	*	ThreedCursor;
	void	*	StatusObject;
	void	*	Introduction;
	void	*	VisualShell;

	int		widgetstyle;
	int		MakeFormFit;

	void	*	CopiedMethod;
	void	*	CopiedMember;
	struct	form_item * TemplateWidget;

	int		rollback;
	int		lockroll;
	int		natlang;
	int		usestyle;
	char *		FontList;
	char *		FontLabelList;
	char *		TestData;
	int		TestDataSize;
	int		UseTestData;

	void	*	WidgetCursor;
	int		WidgetCursorX;
	int		WidgetCursorY;

	int		gridtype;	/* ZERO : None, 1 : Desktop, 2: Window */
	int		BalOrAbal;	/* 0 : ABAL, 1 : BAL */
	int		nested;		/* Nested Loading or Not */
	int		defaultimagetype;
	int		radioshowall;
	int		ResizeBy;
	int		hideimage;
	};

public	char * 	join_strings( char * aptr, char * bptr );
public	char * 	check_payload( char * vptr );
public	void 	charger_context_file_path();
public	char *	allocation_object_production();
public	char *	allocation_source_production();
public	char *	allocation_forms_folder();
public	char *	use_temporary_directory( char * );
public	char *	use_binary_directory( char * );

#endif	/* _sing_h */



