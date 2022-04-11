//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_quote_component_h
#define _html_quote_component_h

class	html_quote_descriptor	{
public:
	html_string_field	* cite;
	html_quote_descriptor();
	void		ondestroy();

	};

class	html_quote_component :	public	html_collection_component,
					html_quote_descriptor	{
public:
	html_quote_component(int t);
	virtual	void	ondestroy();
	virtual	int 	onparse( html_ascii_stream * source );
	virtual	void 	generate( html_output * target );
	virtual	int 	layout( html_layout * target );

	};


#endif	// _html_quote_component_h


