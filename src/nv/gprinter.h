//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_gprinter_h
#define _html_gprinter_h

#include "fprinter.h"
#include "lo.h"
#include "glo.h"
#include "psu.h"

class	html_gprinter : public html_fprinter {

	int	CatchingPixels;
	int	OutputReady;
	int	BuffersReady;
	int	LineUsed;
	int	PrintFontWidth;
	int	PrintFontHeight;
	int	PrintPixelWidth;
	int	PrintPixelHeight;
	int	PrintResolution;
	
	html_output *	holdoutput;
	int		holdlinks;
	int		holdgui;
	int		fontholder;
	gui_laser * 	device;
	char	  *	rowbuffer;
	STDPSU    * 	bodywork;
	STDPSU    * 	headfoot;
	char	  *	lastmessage;

	int	checkbuffers();
	int	usebuffer( STDPSU * catcher );
	int	dropbuffer( STDPSU * catcher );
	void	flushbuffer( STDPSU * catcher );
	void	flushmessages();
	void	usecolour();

public:	
	html_gprinter(char * filename,int bfw, int bfh, int dpi);

	virtual void	terminate();
	virtual void	commit();
	virtual void	putch(int c);
	virtual void	linestart(int l, int nb, int lh=0);
	virtual void	putsymbol( int v );
	virtual void	putimage( html_logical_image * iptr, int line, int columns,int bgwash, border_descriptor * bptr=0  );

	virtual	void	allow_abandon();
	virtual void	page_header(int option=0);
	virtual	void	page_footer();
	virtual	void	atribut( int v );
	virtual void	message( char * sptr );
	virtual int	getevent( char * sptr, int o=-1);
	virtual	void	closure();
	virtual int	fontwidth  ();
	virtual int	fontheight ();
	virtual int	pixelwidth ();
	virtual int	pixelheight();
	virtual int 	seekcolumn(int c);
	virtual	void	initialisation();
	virtual int	textcolour( html_colour * i );
	virtual int	washcolour( html_colour * i );
	virtual int	start(char * uptr=0,html_text_descriptor * tptr=0);

	static	int	PrintFont;
	static	int	PrintMode;
	int	GuiAtributs;

	};

#endif	// _html_gprinter_h


