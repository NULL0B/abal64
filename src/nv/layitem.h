//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_layout_item_h
#define	_html_layout_item_h


class	html_layout_item	{

public:
	html_layout_item *	previous;
	html_layout_item *	next;
	int			rowindent;	// For Font Manager etc
	int			colindent;	// For Screen Oositioning
	int			coladjust;	// For Centering Etc

	html_layout_item();
	void		oninit();
	virtual	void	release();
	virtual	void	commit( html_output * target );
	virtual	int	usage(int minwidth, int maxwidth);
	virtual	int 	adjust(int value, int mv, int lm , int rm );
	virtual	int 	locate(char * cptr);
	virtual	void	hidden( html_output * target );
	};


#endif	// _html_layout_item_h



