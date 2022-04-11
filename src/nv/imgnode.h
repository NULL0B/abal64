//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_image_node_h
#define _html_image_node_h

class	html_image_node	{

public:
	html_image_node 	* previous;
	html_image_node 	* next;
	html_logical_image 	* pixels;
	standard_url		* ressource;
	int			  users;
	html_image_node();
	~html_image_node();
	int	compare( char * sptr );
	};


#endif	// _html_image_node_h


