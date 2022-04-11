//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_object_component_h
#define _html_object_component_h

#include "complex.h"

class	html_object_descriptor {

public:	
	html_string_field 	* type;
	html_string_field	* data;
	html_string_field	* classid;
	html_string_field	* codebase;
	html_string_field	* codetype;
	html_string_field	* archive;
	html_string_field	* standby;
	html_boolean_field	* declare;

	html_object_descriptor();
	void		ondestroy();

	};


class	html_object_component	:	
		public html_collection_component,
		public html_object_descriptor {

public:
	html_object_component(int t=_HTML_TAG_OBJECT);
	virtual	void	ondestroy();
	virtual	int 	layout( html_layout * target );
	virtual	int 	onparse( html_ascii_stream * source );
	virtual	void 	generate( html_output * target );


};

#endif	// _html_object_component_h


