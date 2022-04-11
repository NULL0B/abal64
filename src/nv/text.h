//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_text_h
#define	_html_text_h

#include "basic.h"
#include "textdesc.h"

//	-------------------------------------
//	H T M L _ T E X T _ C O M P O N E N T
//	-------------------------------------

class html_text_component 	: public html_basic_component, 
				  public html_text_descriptor 		{

public:
	html_text_component(int t=_HTML_TAG_TEXT);
	virtual int addtext( int c );
	virtual void	ondestroy();
	virtual int	layout ( html_layout * target );
	virtual int	ontrace( html_output * target );
	virtual int	closemember( int nature, int n);
	virtual void	dimensions( html_dimensions * result, int pextra=0 );


	int	bytecount;
	int	linecount;
private:
	int	lastbyte;
	int	textclosed;
	};

//	--------------------------------
//	H T M L _ T E X T _ O U T P U T
//	--------------------------------

class	html_text_output : public html_output,
				  html_text_descriptor {

public:
	html_text_output( int cellwidth );
	virtual	int	outputbyte(int c);
	virtual int	width();
	int		maxwidth;
	int		curwidth;
	};
	
#endif	// _html_text_h






