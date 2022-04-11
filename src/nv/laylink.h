//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_layout_link_h
#define	_html_layout_link_h

class	html_layout_link : 	public html_layout_item {

public:
	html_anchor_descriptor *	anchor;
	html_layout_font     *	textfont;

	html_layout_link( html_anchor_descriptor * lptr, int start, html_layout_font * fptr=0 );
	void		oninit( html_anchor_descriptor * lptr, int start, html_layout_font * fptr=0 );
	virtual	void	release();
	virtual	void	commit( html_output * target );
	virtual	int 	adjust(int value, int mv,int lm , int rm);
	virtual	void	hidden( html_output * target );
	virtual	int	usage(int minwidth, int maxwidth);
	int		nature;
	};


#endif	// _html_layout_anchor_h




