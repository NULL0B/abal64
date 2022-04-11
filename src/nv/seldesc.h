//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------

#ifndef _html_select_descriptor_h
#define _html_select_descriptor_h

class html_select_descriptor : public html_input_descriptor {
public:
	html_boolean_field		*multiple;
	html_select_descriptor(int t=_HTML_INPUT_SELECT);
	void		ondestroy();

	};

#endif // _html_select_descriptor_h


