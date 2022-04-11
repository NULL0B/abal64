//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_image_h
#define	_html_image_h

#include "basic.h"

class html_image_component 	: public html_active_basic_component,
				  public html_image_descriptor {

	int	chkclick( html_logical_event * eptr );
	void	load_image();
	int			  xvalue;
	int			  yvalue;
	html_active_component 	* hostanchor;

public:
	html_basic_component * imap;
	html_image_component(int t=_HTML_TAG_IMG);
	virtual int 	onparse( html_ascii_stream * source );
	virtual int	layout ( html_layout * target );
	virtual void 	generate( html_output * target );
	virtual void	setparent( html_basic_component * member );
	virtual void	usetext( char * tptr );
	virtual void	dimensions( html_dimensions * result, int pextra=0 );
	virtual	void	ondestroy();

//	Overloading Active Component Methods
//	------------------------------------
	virtual	int 			chkevent( html_logical_event * eptr ) ;
	virtual int			getstart();
	virtual int			canfocus();
	virtual char *			getprompt();
	virtual	int			validate( standard_url * uptr, char * bptr );
	virtual void  			setactive(int status);
	virtual	int			compare( char * cptr );

	};

#endif	// _html_image_h








