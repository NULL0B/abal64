//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_element_descriptor_h
#define _html_element_descriptor_h

class cssi_selector;

class html_element_descriptor	{

public:
	cssi_selector	  *	stylesheet;
	html_string_field *	classname;
	html_string_field *	stylename;
	html_string_field *	direction;
	html_string_field *	language;
	html_string_field *	id;
	html_string_field *	title;
#ifdef	NVV2
	html_string_field *	onfocus;
	html_string_field *	onblur;
	html_string_field *	onselect;
	html_string_field *	onchange;
	html_string_field *	onclick;
	html_string_field *	onmouseover;
#endif
	html_element_descriptor();
	void	ondestroy();
 	int	onparse( char * token, html_ascii_stream * source );
	int	onstyle( int mt );
	int	generate( html_output * target );
	int	language_check();
	char *	classification();

	static	int	set_language( char * lptr );

private:
	static	char *	national_language;

	};


#endif	// _html_element_descriptor_h


