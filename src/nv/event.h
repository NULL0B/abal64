//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_event_h
#define _html_event_h

class	html_logical_event	{

public:
	int	column;			// Column Information
	int	row;			// Line or Row Information
	int	nature; 		// Type of Event Click etc
	int	parameter;		// Button Identifier
	void	* host; 	// Anchor Hosts for Server Image Map
	int	basewidth;		// Base Font Width
	int	baseheight;		// Base Font Height
	html_logical_event();
	};


#endif	// _html_event_h






