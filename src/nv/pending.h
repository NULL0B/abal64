//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_pending_h
#define _html_pending_h

#define	_PENDING_BMP		1
#define	_PENDING_GIF		2
#define	_PENDING_JPG		3
#define	_PENDING_UNKNOWN	0

#include "imgnode.h"

class	html_pending_image	{

public:	html_pending_image( int n=0, int r=0 );

	html_pending_image * 	next;

	html_image_node    *    node;
	int			type;
	int			ready;
	int			flags;
	static		int	solo;
	int			remote;
	};


#endif	// _html_pending_h



