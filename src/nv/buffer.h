//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_buffer_descriptor_h
#define	_html_buffer_descriptor_h

class html_buffer_block	{

public:
	html_buffer_block * previous;
	html_buffer_block * next;
	int		  iread;
	int		  iwrite;
	int		  buffer[64];

	html_buffer_block();
	int	puttextbyte(int c);
	int	gettextbyte();
private:
	};

class html_buffer_descriptor {

public:	
	html_buffer_block * first;
	html_buffer_block * last;
	html_buffer_block * current;

	html_buffer_descriptor();
	int	puttextbyte(int c);
	int	gettextbyte();
	int	firsttextbyte();
	void	release();

	};

#endif 	// _html_buffer_descriptor_h



