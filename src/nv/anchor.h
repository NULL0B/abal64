//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_anchor_h
#define	_html_anchor_h

#define	_DEBUG_ANCHOR_ZONE

#include "complex.h"

class html_anchor_component 	: public html_active_collection_component,
				  public html_anchor_descriptor {
public:

//	Overloading Basic  Component Methods
//	------------------------------------
	html_anchor_component(int t=_HTML_TAG_A);
	virtual	void	ondestroy();
	virtual int	layout ( html_layout * target );
	virtual int 	onparse( html_ascii_stream * source );
	virtual void 	generate( html_output * target );
	virtual	void	usetext( char * tptr );
	virtual void	setparent( html_basic_component * member );

//	Overloading Active Component Methods
//	------------------------------------
	virtual	int 			chkevent( html_logical_event * eptr ) ;
	virtual char *			getprompt();
	virtual int			getstart();
	virtual	int			validate( standard_url * uptr, char * bptr );
	virtual void  			setactive(int status);
	virtual	int			compare( char * cptr );

#ifdef	_DEBUG_ANCHOR_ZONE
	static	int	debug;
#endif

	};

#endif	// _html_anchor_h





