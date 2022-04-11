//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_layout_line_h
#define	_html_layout_line_h

class	html_layout_line	{

public:
	html_layout_line *	previous;	// Pointer to Previous Line
	html_layout_line *	next;		// Pointer to Next Line

	html_layout_item *	first;		// Pointer to First Event
	html_layout_item *	last;		// Pointer to Last  Event

	int			identity;	// Line Number;
	int			height;		// Line Height in Pixels;

	html_logical_image *	imagedata;	// Potential Back ground

	html_layout_line();
	void	oninit();
	void	release();
	void	commit( html_output * target, int atline );
	void	additem( html_layout_item * iptr );
	void	closeline( int minwidth, int maxwidth, int alignment, int oldlm=0, int oldrm=0 );
	int	usage( int minwidth, int maxwidth, int opmode=1 );
	int	occupied( int minwidth, int maxwidth );
	int	check( int tokenlen, int minwidth , int maxwidth );
	int	locate( char * cptr );
	int	seekcolumn( int lmargin, int minwidth, int maxwidth );
	};


#endif	// _html_layout_line_h




