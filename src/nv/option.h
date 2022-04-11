//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_option_h
#define	_html_option_h

#include "text.h"

class html_option_descriptor {
public:
	html_boolean_field *selected;
	html_string_field * value;
	html_option_descriptor();
	void	ondestroy();
	};

class html_option_component 	: public html_text_component,
				  public html_option_descriptor 	{
public:
	html_option_component(int t=_HTML_TAG_OPTION);
	virtual	void	ondestroy();
	virtual int 	onparse( html_ascii_stream * source );
	virtual void 	generate( html_output * target );
	virtual int 	addtext( int c );
	virtual int 	ontrace( html_output * target );
	virtual int 	closemember(int c, int n);

// Correction 20/11/1998-1.1b : IJM ( function member added )
	virtual void	getparameters( standard_url * uptr );
// End of Correction 20/11/1998-1.1b : IJM ( code replacment )

	void	getparameter( standard_url * uptr, char * nptr );
	int	workcheck;

private:
	int	endofoption;
	};


#endif	// _html_option_h


