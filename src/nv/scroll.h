//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_scrollbar_h
#define _scrollbar_h


class	scrollbar	{

public:	scrollbar();
	void	calibrate( int ws, int ts, int bs );
	void	positionbar(int offset); // set position from item position
	void	positionitem(int offset);// set item from bar position
	void	announce();
	int	buttonsize;		// size of each button 
	int	windowsize;		// size of the window view port
	int	totalsize;		// total size of item to scroll
	int	position;		// current scroll bar position
	int	dimension;		// size of scroll bar
	int	zonesize;		// total size of scroll bar zone
	int	item;			// Last external item

	};

#endif	// _scrollbar_h


