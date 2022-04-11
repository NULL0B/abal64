//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_printer_h
#define	_html_printer_h

#include <stdio.h>
#include "output.h"

class	html_printer : public html_output {

public:	
	html_printer();
	virtual void	terminate();

	virtual int 	start(char * uptr=0,html_text_descriptor * tptr=0);
	virtual	int	outputbyte( int c );
	virtual	int	putb( int c );
	virtual	int	puts( char * sptr );
	virtual void	linefeed();
	virtual void	cleanline();
	virtual void	linewrap();
	virtual int	enter( int n );
	virtual int	leave( int n );
	virtual	int	width();
	virtual int	getwidth();
	virtual	int	height();
	virtual int 	seekcolumn(int c);
	virtual int	getcolumn();
	virtual void	putimage( html_logical_image * iptr, int line, int columns, int bgwash, border_descriptor * bptr );

protected:
	int	tabulation;
	int	column;
	int	line;
	int	columns;
	int	lines;

	};


#endif	// _html_printer_h






