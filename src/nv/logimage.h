//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_logical_image_h
#define _html_logical_image_h

#include "palette.h"

#ifndef	_SYSTEM_IMAGES

class html_row_buffer {
public:
	int	identity;
	int	columnwidth;
	html_row_buffer * prev;	
	html_row_buffer * next;
	char * pixels;
	html_row_buffer(int columns, int number);
	~html_row_buffer();
	};

class html_logical_image {
public:	
	int	loaded;
	int	rowcount;
	int	columncount;
	int *	control;
	html_row_buffer * first;
	html_row_buffer * current;
	html_row_buffer * last;
	html_logical_palette * colours;
	html_logical_image(int nbcols=0, int nbrows=0);
	~html_logical_image();
	int	seekrow(int rowid);
	void	addrow( html_row_buffer * rptr );
	html_logical_image * resize( int columns, int rows );
	void stretch( int columns, int rows );

	};

#else	// _SYSTEM_IMAGES

#include "stdpsu.h"

class	standard_image	{

public:	int		rows;
	int		columns;
	STDPSUPTR	storage;
	int 		users;
	 standard_image();
	~standard_image();

	};

class html_logical_image : public standard_image {
public:	int	loaded;
	int	rowcount;
	int	columncount;
	int *	control;
	html_logical_palette * colours;
	html_logical_image(int nbcols=0, int nbrows=0);
	~html_logical_image();
	char *	seekrow(int rowid);
	void	addrow( html_row_buffer * rptr );
	html_logical_image * resize( int columns, int rows );
	void stretch( int columns, int rows );

	};

#endif	// _SYSTEM_IMAGES
	
#endif	// _html_logical_image_h



