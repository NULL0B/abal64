//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_form_node_h
#define _html_form_node_h

class	html_form_node	{

public:
	html_form_node();

	html_form_node 		* previous;
	html_basic_component 	* contents;
	html_form_node 		* next;

	};

#endif	// _html_form_node_h





