//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_textarea_h
#define	_html_textarea_h

#include "complex.h"
#include "text.h"

class html_textarea_component 	: public html_active_collection_component, 
				  public html_textarea_descriptor {
public:

//	Overloading Basic  Component Methods
//	------------------------------------
	html_textarea_component(int t=_HTML_TAG_TEXTAREA);
	virtual	void	ondestroy();
	virtual int 	onparse( html_ascii_stream * source );
	virtual void 	generate( html_output * target );
	virtual int	layout ( html_layout * target );
	virtual void	setparent( html_basic_component * member );
	virtual int 	addtext( int c );
	virtual int 	addmember( html_basic_component * member );
	virtual void	getparameters( standard_url * uptr );
	virtual void	dimensions( html_dimensions * result, int pextra=0 );

//	Overloading Active Component Methods
//	------------------------------------
	virtual	int			getevent( html_output * target, int topline );
	virtual	int 			chkevent( html_logical_event * eptr ) ;
	virtual int			getstart();
	virtual char *			getprompt();
	virtual void  			setactive(int status);


// 	These methods OVERLOAD methods of SELECT/INPUT DESCRIPTOR
// 	---------------------------------------------------------
	virtual int		getfirstbyte(int id);
	virtual int		getnextbyte();

	html_text_component * 	current;
	int			editline;
	int			editpage;
	int			characters;
	};

#endif	// _html_textarea_h


