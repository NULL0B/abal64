//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_area_descriptor_h
#define	_html_area_descriptor_h



class html_area_descriptor : public html_active_descriptor {

public:

	html_shape_field	* shape;
	html_string_field	* coords;
	html_url_field		* href;
	html_string_field	* alt;
	html_boolean_field	* nohref;

	html_area_descriptor();
	void	ondestroy();

	};

#endif	// _html_area_descriptor_h


