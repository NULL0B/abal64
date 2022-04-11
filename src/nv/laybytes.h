//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_layout_bytes_h
#define	_html_layout_bytes_h

#include "laybyte.h"

class	html_layout_bytes : public html_layout_byte {

public:
	int		count;
	html_layout_bytes( int pvalue, int pcount );
	void	oninit( int pvalue, int pcount );
	virtual	void	release();
	virtual	void	commit( html_output * target );
	virtual	int	usage(int minwidth,int maxwidth);

	};


#endif	// _html_layout_bytes_h



