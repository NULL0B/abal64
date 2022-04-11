//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_layout_image_h
#define	_html_layout_image_h



class	html_layout_image : 	public html_layout_item {

public:
	html_image_descriptor * image;
	int			line;
	int			lines;
	int			columns;
	int			pixels;
	html_layout_font *	textfont;
	html_layout_item * 	alignptr;

	html_layout_image( 
			html_image_descriptor * dptr, 
			int atline,
			int oflines,
			int cwidth,
			int pwidth,
			html_layout_font * fptr, html_layout_item * aptr=0);

	virtual	void	commit( html_output * target );
	virtual	int	usage(int minwidth,int maxwidth);
	void		oninit(
		html_image_descriptor * dptr, 
		int atline,
		int oflines,
		int cwidth,
		int pwidth,
		html_layout_font * fptr,html_layout_item *  aptr );
	virtual	void	release();
	virtual	int 	adjust(int value, int mv, int lm, int rm);

	};


#endif	// _html_layout_image_h





