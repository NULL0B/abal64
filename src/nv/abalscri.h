//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_abal_script_h
#define _html_abal_script_h

#include "stdscri.h"

class	abal_script_parser : public standard_script_parser {

public:
	abal_script_parser( html_text_descriptor * source, html_based_component * hptr );

	virtual	int	ispunctuation( int c );
	virtual void	operation( html_ascii_stream * target );
	virtual	int	usepunctuation( int c );
	virtual	int	usetoken( char * token );
	virtual	void	linefeed();
private:
	html_ascii_stream * output;
	int	state;

	};



#endif	// _html_abal_script_h



