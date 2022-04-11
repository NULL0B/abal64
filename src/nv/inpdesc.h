//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------

#ifndef _html_input_descriptor_h
#define _html_input_descriptor_h

#include "language.h"
#include "vector.h"

class html_input_descriptor : public 	html_active_descriptor,
			      public 	html_image_data		{
public:
	html_input_field		*type;
	html_string_field		*name;
	html_string_field		*value;
	html_string_field		*accept;
	html_boolean_field		*checked;
	html_boolean_field		*disabled;
	html_boolean_field		*readonly;
	html_integer_field		*size;
	html_integer_field		*maxlength;
	html_url_field			*src;
	html_string_field		*usemap;
	html_horizontal_alignment	*align;
	html_layout_vector		*control;
	int				selected;
	int				ismultiple;
	int				realwidth;
	html_input_descriptor(int t=_HTML_INPUT_TEXT);
	void	ondestroy();
	};


class html_textarea_descriptor : public html_input_descriptor {
public:
	html_integer_field		*rows;
	html_integer_field		*cols;
	html_textarea_descriptor(int t=_HTML_INPUT_TEXTAREA);
	void	ondestroy();

	};

#endif // _html_input_descriptor_h









