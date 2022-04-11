//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_layout_frameset_h
#define _html_layout_frameset_h

class	html_layout_frameset	{

public:
	html_layout_frameset	*	host;	// Previous Table
	html_layout_frameset	*	child;	// Nested Table
	html_layout_frameset	*	next;	// For Quick Allocation 

	html_frameset_descriptor	*	frameset;
	html_frame_descriptor		*	frame;

	html_layout_line	*	framestart;

	int		information[32];
	int		infotype[32];
	int		current;
	int		nature;
	int		limit;
	int		border;

	int		left_margin;
	int		frame_width;

	html_layout_frameset(html_frameset_descriptor * dptr=0, int lmv=0, int fwv=0 );
	void	oninit(html_frameset_descriptor * dptr, int lmv, int fwv);
	int	openframe(html_frame_descriptor * dptr=0);
	int	closeframe(html_layout_line * lptr);
	int	framewidth();

private:
	void	collect_information( char * tptr );

	};


#endif	// _html_layout_frameset_h




