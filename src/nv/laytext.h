//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_layout_text_h
#define	_html_layout_text_h


#include "layitem.h"

class	html_layout_text : 	public html_layout_item, 
				public html_text_descriptor	{

public:
	html_layout_font * textfont;
	html_layout_text( html_layout_font * fptr=0 );
	void	oninit( html_layout_font * fptr );
	virtual	void	release();
	virtual	void	commit( html_output * target );
	virtual	int	usage(int minwidth,int maxwidth);
	virtual	int	locate( char * cptr );
	virtual	void	hidden( html_output * target );
private:
	int	grbytecount;
	int	effective_size;
	};


#endif	// _html_layout_text_h


