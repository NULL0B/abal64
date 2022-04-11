//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_output_h
#define	_html_output_h

#include "colour.h"
#include "descript.h"
#include "border.h"
#include "event.h"

class	cssi_selector;

class	html_output {

public:	
	html_output();
	~html_output();
	static  int     isgui;
	virtual void	terminate();
	virtual int	outputbyte( int c );
	virtual	int	putb( int c );
	virtual	int	puts( char * sptr );
	virtual	void	message( char * sptr );
	virtual int	checkpage(int n);
	virtual void	linefeed();
	virtual void	linestart(int l, int nb, int lh=0);
	virtual void	zonestart(int l, int nb, int lh=0, int bgc=0, int lno=-1,html_logical_image * iptr=0);
	virtual void	cleanline();
	virtual void	linewrap();
	virtual int	enter( int n );
	virtual int	leave( int n );
	virtual	void	reset();
	virtual	int	width();
	virtual	int	height();
	virtual int 	start(char * uptr=0,html_text_descriptor * tptr=0);
	virtual void	commit();
	virtual	int	useevent(int e);
	virtual	int	getevent( char * c, int o=-1);
	virtual	int	getevent( html_logical_event * eptr );
	virtual	int	ask(int c, int l, char * mptr, int mlen, int vlen, int option  );
	virtual int	cico_function( int i );
	virtual int 	setanchor( html_anchor_descriptor * aptr );
	virtual void	draw_scrollbar(int m, int n);
	virtual void	draw_horizontal(int m, int n);
	virtual	int 	useop( int mode );
	virtual int 	seekcolumn(int c);
	virtual int	getcolumn();
	virtual int	getwidth();
	virtual int	setfont( int i );
	virtual void	setmaxline( int l );
	virtual void	setmaxcol( int l );
	virtual int	textcolour( html_colour * i );
	virtual int	washcolour( html_colour * i );
	virtual int	linkcolour( html_colour * i );
	virtual int	donecolour( html_colour * i );
	virtual int	workcolour( html_colour * i );
	virtual void	putimage( html_logical_image * iptr, int line, int columns,int bgwash, border_descriptor * bptr=0  );

	virtual	void	printscreen();
	virtual int	fontwidth  ();
	virtual int	fontheight ();
	virtual int	pixelwidth ();
	virtual int	pixelheight();
	virtual	void	atribut( int v );
	virtual void	configure(int item, int value);
	virtual html_output * stdprinter( char * sptr );

	virtual int	usestyle(cssi_selector * sptr);

	static	html_output * stdoutput;
	static	void	stdmessage(char * sptr);
	static  int	stdinput(int o=-1);
	static  int	stdconfigure(int i, int v);
	virtual void	putsymbol( int v, int b=0 );
	virtual	int	validation( char * mptr );
	virtual void	textout(html_text_descriptor * tptr=0);

	html_anchor_descriptor *anchor;
	html_logical_image     *background;
	int			font;

	html_colour		text;
	html_colour		wash;
	html_colour		link;
	html_colour		done;
	html_colour		work;

	int	omaxline;
	static	int	profile;

	};

#endif	// _html_output_h




