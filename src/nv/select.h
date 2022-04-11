//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_select_h
#define	_html_select_h

#include "option.h"
#include "complex.h"

class html_select_component 	: public html_active_collection_component, 
				  public html_select_descriptor {

	void	select_option( int value );
	void	reset_selection();
	void	scroll_up(int bid, int hid );
	void	scroll_down(int bid, int hid );


public:

	html_option_component * current;

//	Overloading Basic  Component Methods
//	------------------------------------
	html_select_component(int t=_HTML_TAG_SELECT);
	virtual	void	ondestroy();
	virtual int 	onparse( html_ascii_stream * source );
	virtual void 	generate( html_output * target );
	virtual int	layout ( html_layout * target );
	virtual void	setparent( html_basic_component * member );
	virtual void	getparameters( standard_url * uptr );
	virtual int	addmember( html_basic_component * member );
	virtual int	closemember(int c, int n);
	virtual void	dimensions( html_dimensions * result, int pextra=0 );

//	Overloading Active Component Methods
//	------------------------------------
	virtual	int			getevent( html_output * target, int topline );
	virtual	int 			chkevent( html_logical_event * eptr ) ;
	virtual int			getstart();
	virtual char *			getprompt();
	virtual void  			setactive(int status);


	// These methods OVERLOAD methods of SELECT/INPUT DESCRIPTOR
	virtual int		getfirstbyte(int id);
	virtual int		getnextbyte();

	int	members;
	};

#endif	// _html_select_h





