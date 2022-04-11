//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_gui_h
#define	_html_gui_h

#include "cico.h"
#include "symbol.h"
#include "psu.h"
#include "menu.h"

//	--------------------------------------------------------------------
//	The graphical user interface
//	is to use a bufferised smoothing mechanism for the page contents
//	output. This will cost a bit more memory but will look an awful
//	lot better : especially when multiple nested tables with background
//	images and colors are to rendered !
//
//	IJM : 16/02/2000
//
//	--------------------------------------------------------------------

#define	_GUI_MAGNIFY _MENU_CODE_ZOOM
#define	_GUI_PALETTE _MENU_CODE_PALETTE
#define	_GUI_INHIBIT _MENU_CODE_INHIBIT
#define	_MAX_GUI_FONTS	32

class	html_gui : public html_cico {

	int	MouseDownColumn;
	int	MouseDownLine;
	int	MouseIsDown;
	char *	GuiFonts[_MAX_GUI_FONTS];
#ifdef	_NV11F
	char	SetMouseBuffer[1024+16];
#endif
	int	GuiDefault;
	int	GuiOptions;
	int	GuiInitMode;
	int	GuiBaseFont;
	int	GuiMenuFont;
	int	GuiCellWidth;
	int	GuiCellHeight;
	int	GuiMenuNormal;
	int	GuiMenuActive;
	int	GuiMenuTriger;
	int	GuiHighLight;
	int	GuiLowLight;
	int	GuiDarkLight;
	int	GuiBackGround;
	int	GuiScrollBar;
	int	GuiMargin;
	int	GuiCurserIsOn;
	int 	guicurseron();
	int 	guicurseroff();
	void	relief_zone(int atc, int atr, int nbc, int nbr, int invert );
	void	framed_zone(int atc, int atr, int nbc, int nbr, int dath );
	void	use_mouse_event();
	void	draw_status_bar();
	void	palette_buttons();
	int	mouseover(int tc, int tl, int nc, int nl );

	STDPSU    * 	GuiLineWork;
	int		GuiLineWorking;
	int		GuiWorkingLine;
	void		move_vertical  ( int sbp, int sbh );
	void		move_horizontal( int sbp, int sbw );
	void		draw_arrow( int atcol, int atlin, int nbcol, int nblin, int type );
	int		button_frame();
protected:
	virtual void	proxy_status();

public:
	html_gui(int mode);
	~html_gui();
	virtual void	terminate();

	virtual	void	function_button( int i, char * msg, int mode, int hotkey );
	virtual void	console();
	virtual void	console_buttons();
	virtual void	ask_buttons();
	virtual void	validate_buttons();
	virtual void	draw_scrollbar(int m,int n);
	virtual void	draw_horizontal(int m,int n);
	virtual int	get_character();
	virtual	void	atribut( int v );
	virtual int	test_character();
	virtual	int	cico_function( int keycode );
	virtual void	linestart(int l, int nb, int lh=0);
	virtual void	zonestart(int l, int nb, int lh=0, int bgc=0, int lno=-1, html_logical_image * iptr=0);
	virtual	int	eventline();
	virtual	int	eventcolumn();
	virtual	void	loadfont(int number, char * filename );
	virtual int	fontwidth  ();
	virtual int	fontheight ();
	virtual int	pixelwidth ();
	virtual int	pixelheight();
	virtual int	textcolour( html_colour * i );
	virtual int	washcolour( html_colour * i );
	virtual void	clear_to_end_of_line();
	virtual html_output * stdprinter(char * sptr);
	virtual	int	ask(int c, int l, char * mptr, int mlen, int vlen, int option  );
	
	virtual void	putimage( html_logical_image * iptr, int line, int columns, int bgwash,border_descriptor * bptr=0  );

	virtual int 	start(char * uptr=0,html_text_descriptor * tptr=0);
	virtual void	commit();
	virtual int 	seekcolumn(int c);
	virtual	void	message( char * sptr );
	virtual	int 	puts( char * message );
	virtual void	putsymbol( int v, int b=0 );
	virtual void	putgener(int v , int length );
	virtual	void	printscreen();
	virtual void	configure(int item, int value);
	virtual int	usestyle(cssi_selector * sptr);
	virtual	int	getevent( html_logical_event * eptr );
	virtual void	reset();
	virtual	void	click( int buttonid );	// 0 -> 12 : Menu 
	virtual void	textout(html_text_descriptor * tptr=0);
	virtual void	clear_zone(int c, int l, int w, int h, int mode );

static	void	resize_magnification(int zw=0, int zh=0, int zf=0);

static	int	GuiQuality;

private:
	int	palette_manager();
	void	showmouse();
	void	hidemouse();
	void	MagnifyOn();
	void	MagnifyOff();
	int	GuiMouseColumns;
	int	GuiMouseRows;
	int	GuiMouseColumn;
	int	GuiMouseLine;
	int	active;
	char	* RatZone;
	char	* WaitZone;
	int	GuiWhichCurser;
	html_logical_image * RatShape;
	html_logical_image * RatWait;
	html_logical_image * LogoImage;
	int	GuiMaxColumns;
	int	GuiMaxRows;
	int	GuiPixelWidth;
	int	GuiPixelHeight;
	int	GuiFontWidth;
	int	GuiFontHeight;
	int	MenuFontWidth;
	int	MenuFontHeight;

static	int	GuiMagnify;
static	int	GuiMagFactor;
static	int	GuiMagWidth;
static	int	GuiMagHeight;
static	char *	GuiMagZone;


	void	move_while_down();
	int	mouse_is_up();

	// Vertical scrollbar box frame and bar control
	// --------------------------------------------
	void	draw_scrollbox(int gratcol, int gratlin, int grnbcol, int grnblin );
	int	ScrollBarLine;
	int	ScrollBarHeight;

	// Horizontal scrollbar box frame and bar control
	// ----------------------------------------------
	int	ScrollBarColumn;
	int	ScrollBarWidth;


	// Scroll bar movement control 
	// ---------------------------
	int	ScrollMoving;

	int	GuiAtributs;
	int	GuiArrow[8][4];
	int	UseMixel;
	int	MixelCol;
	int	MixelLin;
	int	NewMixelCol;
	int	NewMixelLin;

#ifdef	_NV11F
	void	use_mouse_image( html_logical_image * iptr );
#endif
	};

#endif	// _html_gui_h




