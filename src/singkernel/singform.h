#ifndef	_form_control_h
#define	_form_control_h

#include "singpage.h"
#include "stdpsu.h"

long	time(long *);

#define	_FORM_CONSTANTS  	0x8000
#define	_FORM_COMMANDLINE	0x4000
#define	_FORM_MULTILINGUAL	0x2000
#define	_FORM_INTERNATIONAL	0x1000
#define	_FORM_DEFAULT		0x0800
#define	_FORM_UP		0x0400
#define	_FORM_DOWN		0x0200
#define	_FORM_RC 		0x0100
#define	_FORM_TAB 		0x0080
#define	_FORM_PAGE_DOWN		0x0040
#define	_FORM_PAGE_UP		0x0020
#define	_FORM_ESC		0x0010

#define	_FORM_TYPE_DIALOG	0
#define	_FORM_TYPE_EVENT	1
#define	_FORM_TYPE_SCROLL	2
#define	_FORM_TYPE_PAGE		3

#define	_FORM_TYPE_FLAGS	7

struct	buffer_control	{
	STDPSUPTR	value;		/* Pointer to the buffer PSU VALUE   */
	int		width;		/* total width of buffer 	     */
	int		height;		/* total height of buffer image	     */
	int		x;		/* x offset into buffer for H scroll */
	int		y;		/* y offset into buffer for V scroll */
	};

struct	abal_options	{
	int	flags;
	int	values;
	int	diezemem;
	int	diezefiles;
	int	diezestack;
	int	diezeheap;
	int	tokensize;
	int	labelsize;
	char *	pragmafile;
	};

struct	forms_method	{
	struct	forms_method * previous;
	struct	forms_method * next;
	char *	name;			/* name of method	*/
	int	type;			/* abal data type 	*/
	int	number;			/* identififcation 	*/
	char *	klass;			/* suplement for type 	*/
	char *	signature;		/* parameters		*/
	char *	text;			/* code of method	*/
	struct form_control * parent;
	};

struct	form_control	{

	int	method_count;

	struct	forms_method * StandardInput;
	struct	forms_method * StandardError;

	struct	forms_method * rootmethod;
	struct	forms_method * lastmethod;

	int	member_count;

	struct	forms_data_member * rootmember;
	struct	forms_data_member * lastmember;

	char *	loadname;
	char *	prodname;

	int	doctool;
	char *	document[MAXNATLANG];

	int	isprogram;
	int	isoverlay;
	int	ispopup;

	int	formflags;
	int	mimoflags;

	int	natlang;

	int	language;
	int	display;

	int	outofdate;

	int	font;
	int	gridlock;
	int	gridsize;
	int	foreground;
	int	background;
	int	thickness;
	int	using;

	long	savestamp;
	long	loadstamp;

	char *	identifier;
	char *	construction;
	char *	dependance;

	struct standard_image *    image;

	struct form_item *  first;
	struct form_item *  current;
	struct form_item *  last;
	struct form_item *  active;
	struct form_item *  top;

	struct abal_options abal;

	int	items;
	int	pages;
	int	focus;
	int	page_number;
	int	objects;
	int	argvlen;
	int	argvcount;
	int	isdynamic;

	char *	stylesheet;
	char *	clearscreen;

	struct	page_manager printout;

	struct	buffer_control Buffer;
	struct	treeview *	treenode;
	void		 *	host;
	};


public	struct form_control * liberate_Form(struct form_control *  fptr);
public	struct form_control * allocate_Form( char * nptr );
public 	struct form_control * load_Form(struct form_control * fptr, char * nptr,int reset, int automatic );

public	int FormEditorOnExec(struct form_control ** ffptr);
public	int FormEditorOnGetFocus(struct form_control ** ffptr);
public	int FormEditorOnLoseFocus(struct form_control ** ffptr);
public	int FormEditorOnUseEvent(struct form_control ** ffptr,int event);

public	char		    * get_widget_class( int wid );
public	struct form_item    * validate_Widget( struct form_control * fptr, char * nptr );
public	struct form_item    * allocate_Widget(struct form_control * fptr);
public	struct form_item    * liberate_Widget(struct form_item * wptr );

#endif	/* _form_control_h */

