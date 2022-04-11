//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_list_descriptor_h
#define _html_list_descriptor_h

class html_list_descriptor : public virtual html_element_descriptor 	{
public:
	html_uppercase_field	*type;
	html_integer_field	*start;
	html_boolean_field	*compact;
	int			started;
	int			aligned;

	html_list_descriptor();
	void		ondestroy();
	};


#endif	// _html_list_descriptor_h




