//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_input_h
#define	_html_input_h

#include "basic.h"

class html_input_component 	: public html_active_basic_component, 
				  public html_input_descriptor {
	void	load_image();
public:

//	Overloading Basic  Component Methods
//	------------------------------------
	html_input_component(int t=_HTML_TAG_INPUT);
	virtual	void	ondestroy();
	virtual int 	onparse( html_ascii_stream * source );
	virtual void 	generate( html_output * target );
	virtual int	layout ( html_layout * target );
	virtual void	setparent( html_basic_component * member );
	virtual void	getparameters( standard_url * uptr );
	virtual void	dimensions( html_dimensions * result, int pextra=0 );
	virtual void	usetext( char * tptr );

//	Overloading Active Component Methods
//	------------------------------------
	virtual	int			getevent( html_output * target, int topline );
	virtual	int 			chkevent( html_logical_event * eptr ) ;
	virtual int			getstart();
	virtual char *			getprompt();
	virtual	int			canfocus();
	virtual	int			validate( standard_url * uptr, char * bptr );
	virtual void  			setactive(int status);
	};

#endif	// _html_input_h


