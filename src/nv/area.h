//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_area_h
#define	_html_area_h

#include "basic.h"
#include "areadesc.h"

class html_area_component 	: public html_active_basic_component,
				  public html_area_descriptor {
	int	chkrect( html_logical_event * eptr ); 
	int	chkcircle( html_logical_event * eptr ); 
	int	chkpoly( html_logical_event * eptr );

public:
	html_area_component(int t=_HTML_TAG_AREA);
	virtual int 	onparse( html_ascii_stream * source );
	virtual void 	generate( html_output * target );
	virtual int	layout ( html_layout * target );
	virtual void	setparent( html_basic_component * member );
	virtual	void	ondestroy();

//	Overloading Active Component Methods
//	------------------------------------
	virtual	int 			chkevent( html_logical_event * eptr ) ;
	virtual char *			getprompt();
	virtual	int			validate( standard_url * uptr, char * bptr );
	virtual void  			setactive(int status);
	virtual int			getstart();
	virtual	int			compare( char * cptr );
	};

#endif // _html_area_h


