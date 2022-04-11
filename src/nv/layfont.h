//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_layout_font_h
#define	_html_layout_font_h

class	html_layout_font	{

public:
	int	size;
	html_colour	colour;
	html_colour	bgcolour;
	html_colour	holder;
	html_colour	control;
	int	users;
	html_layout_font * stack;
	html_layout_font * next;

	html_layout_font( int s, html_colour * c, html_colour * b );
	void	oninit( int s, html_colour * c, html_colour * b );
	void	release();
	void	commit( html_output * target );
	void	highlight( html_output * target );
	void	lowlight( html_output * target );
	void	restore( html_output * target );
	void	hidden( html_output * target );
	int	height();
private:
	static	int	fontinfo[8][2];
	int		active;
	};

#endif	// _html_layout_font_h





