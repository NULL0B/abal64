//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_cico_h
#define	_html_cico_h

#include "ctrl.h"

#define	_CICO_MOUSE	0x0100	// MOUSE HIT
#define	_CICO_TIMER	0x0101	// TIMER HIT

#define	_CICO_LINE_RAZ	_CTRL_A

#define	_CICO_LINE_FEED	_CTRL_J	
#define	_CICO_VALIDATE	_CTRL_M
#define	_CICO_REFRESH	_CTRL_L

#define	_CICO_LINE_DOWN	_CTRL_E
#define	_CICO_LINE_UP	_CTRL_K

#define	_CICO_PAGE_HOME	_HOME_KEY
#define	_CICO_PAGE_UP	_CTRL_R
#define	_CICO_PAGE_DOWN	_CTRL_C
#define	_CICO_PAGE_FOOT	_CTRL_B

#define	_CICO_LINK_HOME	_CTRL_W
#define	_CICO_LINK_UP	_SHIFT_TAB
#define	_CICO_LINK_DOWN	_CTRL_I
#define	_CICO_LINK_FOOT	_CTRL_Z

#define	_CICO_SCROLL_LEFT	0x001D
#define	_CICO_SCROLL_RIGHT	0x001E

#include "xcico.h"

#include "printer.h"


#include "scroll.h"

class	html_cico : public html_printer {

	void	curseron();
	void	curseroff();
protected:
	virtual void	proxy_status();
	int	ProxyStatus;
	void	tempo();
public:
	html_cico(int mode=0);
	~html_cico();
	virtual void	terminate();
	virtual int 	start(char * uptr=0,html_text_descriptor * tptr=0);
	virtual void	commit();
	virtual void	linefeed();
	virtual void	cleanline();
	virtual void	linewrap();
	virtual	int	ask(int c, int l, char * mptr, int mlen, int vlen, int option  );
	virtual	void	message( char * sptr );
	virtual	int	puts( char * sptr );
	virtual int 	outputbyte(int c);
	virtual int 	textcolour( html_colour * i );
	virtual int 	washcolour( html_colour * i );
	virtual int   	setanchor( html_anchor_descriptor * aptr );
	virtual	int	useevent(int e);
	virtual	int	getevent( char * cptr, int o=-1);
	virtual	int	getevent( html_logical_event * eptr );
	virtual	int	cico_function( int keycode );
	virtual	void	function_button( int i, char * msg, int mode, int hotkey );
	virtual int 	seekcolumn(int c);
	virtual void	linestart(int l, int nb, int lh=0);
	virtual void	zonestart(int l, int nb, int lh=0, int bgc=0, int lno=-1, html_logical_image * iptr=0);
	virtual void	console();
	virtual void	reset();
	virtual	int	eventline();
	virtual	int	eventcolumn();
	virtual int	eventtype();
	virtual int	eventbutton();
	virtual void	console_buttons();
	virtual void	ask_buttons();
	virtual void	validate_buttons();
	virtual void	draw_scrollbar(int m,int n);
	virtual void	draw_horizontal(int m,int n);
	virtual	int 	useop( int mode );
	virtual int	get_character();
	virtual int	test_character();
	virtual void	clear_to_end_of_line();
	virtual	void	atribut( int v );
	virtual	int	putb( int c );
	virtual void	setmaxcol( int l );
	virtual html_output * stdprinter(char * sptr);
	virtual	int	validation( char * mptr );
	virtual	void	click( int buttonid );	// 0 -> 12 : Menu 
	void	print(int c, int l, char * mptr, int mlen, int option  );
	virtual void	clear_zone(int c, int l, int w, int h, int mode );
	int	horizontal_scroll( int keycode );
	char *	FunctionText[12];
	int   	FunctionKey[12];
	int   	FunctionLength[12];
	int	output_active;
	int	firstline;
	int	lastline;
	int	draw_console;
	int	window_column;
	int	column_indent;
	int	column_limit;
	int	window_line;
	int	target_line;
	int	left_margin;

	int	scroll_count;
	int	scroll_item;
	int	scroll_step;

	int	clip_columns;
	int	testkbd;
	int	message_line;
	int	message_column;
	int	message_columns;
	static	int	cico_language;
	int	menu_line;
	int	menu_column;
	int	cico_profile;
	int	CicoAtributs;
	static	int click_tempo;	
	scrollbar hbar;
	scrollbar vbar;
	int	editcolumn;
	int	globalins;

	};

#endif	// _html_cico_h




