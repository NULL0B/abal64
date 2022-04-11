//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_layout_zone_h
#define	_html_layout_zone_h

#include "laybyte.h"

class	html_layout_zone : public html_layout_byte {

	static	int	borderbyte[81];	// 9 by 9 integer matrix

public:
	int		lsymbol;
	int		msymbol;
	int		rsymbol;
	int		option;
	int		count;
	int 		nombre;
	html_layout_item * alignptr;
	html_logical_image * background;
	html_layout_zone( int pvalue, int pcount,int ls, int ms, int rs, int o, int nb=-1, html_logical_image * iptr=0, html_layout_item * cptr=0 );
	void	oninit( int pvalue, int pcount,int ls, int ms, int rs, int o, int nb=-1, html_logical_image * iptr=0, html_layout_item * cptr=0  );
	virtual	int 	adjust(int value, int mv, int lm , int rm );
	virtual	void	release();
	virtual	void	commit( html_output * target );
	virtual	int	usage(int minwidth,int maxwidth);

	};


#endif	// _html_layout_zone_h

