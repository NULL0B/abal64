//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_font_image_h
#define _html_font_image_h

#include "psu.h"
#include "descript.h"
#include "textdesc.h"
#include "colour.h"

class	cssi_selector;

class	html_font_image : public html_logical_image {

	void	commit_to_image();
	void	usecatcher();

	int	catching;
	int	psucounter;
	int	psulinecounter;

public:	
	html_font_image(int fid, int gfw, int gfh, int nbcol, int bfw, cssi_selector * sptr );
	void	oninit( int nbcol );
	void	terminate();
	void	putch(int c);
	void	puttoken(char * tptr);
	int	put_text( html_text_descriptor * dptr,	html_colour * colour, html_colour * bgcolour );
	static	html_font_image * builder( int number, int nbcol, int bfw, cssi_selector * sptr  );
	static	void adjust_dimensions( html_dimensions * dptr, int fontid );
	int 	rule( html_rule_descriptor * rptr );
	long	rowadjust();
	long	coladjust();
	int	psufontwidth;
	int	psuwidth;
	int	psuheight;
	int	psucolumns;
	int	calibrator;
	STDPSU * catcher;

	int	psufont;

	};

#endif	// _html_font_image_h



