//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	
//			for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_basic_h
#define	_html_basic_h

#include "colour.h"
#include "syntax.h"
#include "align.h"
#include "layout.h"

#include "pending.h"

class html_active_component;


class html_basic_component : public virtual html_element_descriptor	{

public:	
	int 			member_type;
	html_basic_component * 	previous;
	html_basic_component * 	next;
	html_basic_component * 	parent;

	html_basic_component(int t=-1);

	virtual void	ondestroy();
	virtual int	onparse( html_ascii_stream * source );
	virtual int	addmember( html_basic_component * member );
	virtual void	setparent( html_basic_component * member );
	virtual void	setbase( standard_url * uptr, int mode=0 );
	virtual int	addtext(int c);
	virtual void	usetext( char * tptr );
	virtual void	getparameters( standard_url * uptr );
	virtual int	closemember(int c, int n);
	virtual	void 	prefix(html_layout * target);
	virtual void	adjust(int nature, long number);
	virtual int	layout ( html_layout * target );
	virtual int	ontrace( html_output * target );
	virtual void	generate( html_output * target );
	virtual void	dimensions( html_dimensions * result, int pextra=0 );
	virtual void    setpending( html_pending_image * pptr );
	virtual	html_basic_component * 	addactive( html_active_component * aptr );
	virtual char 	* getbase();

	static 	int 	default_text_type;

	};

#include "active.h"

class	html_active_basic_component : 	public html_basic_component,
					public html_active_component {

public:
	html_active_basic_component(int t=-1);
	virtual html_basic_component * 	getbasic();
	virtual int			getnature();

	};


#endif	/* _html_basic_h */




