//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_form_h
#define	_html_form_h

#include "complex.h"

class html_form_descriptor {
public:
	html_url_field		*action;
	html_string_field 	*method;
	html_string_field 	*enctype;
	
	html_form_descriptor();
	void		ondestroy();

	};

class	html_form_node;

class html_form_component 	: public html_collection_component,
				  public html_form_descriptor {
	html_form_node 		* firstinput;
	html_form_node 		* lastinput;
public:
	int			  working;

	html_form_component(int t=_HTML_TAG_FORM);
	virtual	void	ondestroy();
	virtual int 	onparse( html_ascii_stream * source );
	virtual void 	generate( html_output * target );
	virtual int	addmember( html_basic_component * member );
	virtual void	getparameters( standard_url * uptr );
	virtual	int	validate( standard_url * uptr, char * bptr );
	virtual void	setparent( html_basic_component * member );
	void		reset();
	};
#endif	// _html_form_h


