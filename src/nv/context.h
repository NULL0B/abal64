//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_context_h
#define	_html_context_h

#include "syntax.h"

class	html_font_context	{

public:
	html_font_context( html_output * target, html_integer_field * number );
	~html_font_context();

private:
	html_integer_field	* font;
	html_output 		* context;

	};

class	html_colour_context	{

public:
	html_colour_context( 
		html_output * target, 
		html_colour_field	* t,
		html_colour_field	* b=0,
		html_colour_field	* l=0,
		html_colour_field	* d=0,
		html_colour_field	* w=0 );
	~html_colour_context();

private:
	html_colour_field	* text;
	html_colour_field	* wash;
	html_colour_field	* link;
	html_colour_field	* done;
	html_colour_field	* work;
	html_output 		* context;

	};

#endif // _html_context_h

