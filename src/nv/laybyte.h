//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_layout_byte_h
#define	_html_layout_byte_h

#include "layitem.h"


class	html_layout_byte : public html_layout_item {

public:
	int		value;
	html_layout_byte( int pvalue );
	void oninit( int pvalue );
	virtual	void	release();
	virtual	void	commit( html_output * target );
	virtual	int	usage(int minwidth,int maxwidth);
	};


#endif	// _html_layout_byte_h




